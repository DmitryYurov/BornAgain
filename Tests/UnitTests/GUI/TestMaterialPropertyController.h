#include "google_test.h"
#include <QtTest>
#include "MaterialPropertyController.h"
#include "MaterialModel.h"
#include "SampleModel.h"
#include "LayerItem.h"
#include "MaterialItem.h"
#include "ExternalProperty.h"
#include "MaterialItemUtils.h"

class TestMaterialPropertyController : public ::testing::Test
{
public:
    ~TestMaterialPropertyController();
};

TestMaterialPropertyController::~TestMaterialPropertyController() = default;

TEST_F(TestMaterialPropertyController, test_ControllerForLayer)
{
    MaterialModel materialModel;
    auto mat1 = materialModel.addMaterial("name1", 1.0, 2.0);
    materialModel.addMaterial("name2", 3.0, 4.0);

    SampleModel sampleModel;
    auto layer = sampleModel.insertNewItem(Constants::LayerType);

    int property_changed(0);
    layer->mapper()->setOnPropertyChange(
        [&property_changed](const QString& name) {
            if (name == LayerItem::P_MATERIAL)
                ++property_changed;
        },
        this);

    MaterialPropertyController controller;
    controller.setModels(&materialModel, &sampleModel);
    EXPECT_EQ(property_changed, 0);

    // changing name of MaterialItem in MaterialModel, looking for MaterialProperty change
    mat1->setItemName("newname");
    //    EXPECT_EQ(property_changed, 1);
    ExternalProperty property
        = layer->getItemValue(LayerItem::P_MATERIAL).value<ExternalProperty>();
    EXPECT_EQ(property.identifier(), mat1->getIdentifier());
    EXPECT_EQ(property.text(), mat1->itemName());
    EXPECT_EQ(property.color(), mat1->getColor());

    // changing color of MaterialItem
    ExternalProperty colorProperty = MaterialItemUtils::colorProperty(QColor(Qt::red));
    mat1->setItemValue(MaterialItem::P_COLOR, colorProperty.variant());
    //    EXPECT_EQ(property_changed, 2);
    property = layer->getItemValue(LayerItem::P_MATERIAL).value<ExternalProperty>();
    EXPECT_EQ(property.identifier(), mat1->getIdentifier());
    EXPECT_EQ(property.text(), mat1->itemName());
    EXPECT_EQ(property.color(), mat1->getColor());
    EXPECT_EQ(property.color(), QColor(Qt::red));

    // removing material from the model, property should become undefined
    materialModel.removeRows(0, 1, QModelIndex());
    //    EXPECT_EQ(property_changed, 3);
    property = layer->getItemValue(LayerItem::P_MATERIAL).value<ExternalProperty>();
    EXPECT_TRUE(property.isValid() == false);
}

//! Test MaterialProperty update in sample items when working on model clone.

TEST_F(TestMaterialPropertyController, test_ControllerInEditorContext)
{
    MaterialModel materialModel;
    auto mat1 = materialModel.addMaterial("name1", 1.0, 2.0);
    auto mat2 = materialModel.addMaterial("name2", 1.0, 2.0);
    auto mat3 = materialModel.addMaterial("name3", 1.0, 2.0);

    SampleModel sampleModel;
    auto layer1 = sampleModel.insertNewItem(Constants::LayerType);
    auto layer2 = sampleModel.insertNewItem(Constants::LayerType);
    auto layer3 = sampleModel.insertNewItem(Constants::LayerType);

    MaterialPropertyController controller;
    controller.setModels(&materialModel, &sampleModel);

    layer1->setItemValue(LayerItem::P_MATERIAL,
                         MaterialItemUtils::materialProperty(*mat1).variant());
    layer2->setItemValue(LayerItem::P_MATERIAL,
                         MaterialItemUtils::materialProperty(*mat2).variant());
    layer3->setItemValue(LayerItem::P_MATERIAL,
                         MaterialItemUtils::materialProperty(*mat3).variant());

    // Making copy of material model
    std::unique_ptr<MaterialModel> materialsCopy(materialModel.createCopy());
    auto mat1copy = dynamic_cast<MaterialItem*>(
        materialsCopy->itemForIndex(materialsCopy->index(0, 0, QModelIndex())));
    auto mat2copy = dynamic_cast<MaterialItem*>(
        materialsCopy->itemForIndex(materialsCopy->index(1, 0, QModelIndex())));
    auto mat3copy = dynamic_cast<MaterialItem*>(
        materialsCopy->itemForIndex(materialsCopy->index(2, 0, QModelIndex())));
    EXPECT_EQ(mat1->getColor(), mat1copy->getColor());
    EXPECT_EQ(mat1->itemName(), mat1copy->itemName());
    EXPECT_EQ(mat1->getIdentifier(), mat1copy->getIdentifier());
    EXPECT_EQ(mat2->getColor(), mat2copy->getColor());
    EXPECT_EQ(mat2->itemName(), mat2copy->itemName());
    EXPECT_EQ(mat2->getIdentifier(), mat2copy->getIdentifier());
    EXPECT_EQ(mat3->itemName(), mat3copy->itemName());
    EXPECT_EQ(mat3->getIdentifier(), mat3copy->getIdentifier());

    // Removing mat2 from the copy
    materialsCopy->removeRows(1, 1, QModelIndex());
    mat1copy = dynamic_cast<MaterialItem*>(
        materialsCopy->itemForIndex(materialsCopy->index(0, 0, QModelIndex())));
    mat3copy = dynamic_cast<MaterialItem*>(
        materialsCopy->itemForIndex(materialsCopy->index(1, 0, QModelIndex())));
    EXPECT_EQ(mat1->getColor(), mat1copy->getColor());
    EXPECT_EQ(mat1->itemName(), mat1copy->itemName());
    EXPECT_EQ(mat3->getColor(), mat3copy->getColor());
    EXPECT_EQ(mat3->itemName(), mat3copy->itemName());

    // changing mat3
    mat3copy->setItemName("name3changed");

    // copying back to original model
    materialModel.clear();
    materialModel.initFrom(materialsCopy.get(), 0);
    materialModel.modelLoaded();

    // layer2 should have undefined material property
    ExternalProperty property
        = layer2->getItemValue(LayerItem::P_MATERIAL).value<ExternalProperty>();
    EXPECT_TRUE(property.isValid() == false);

    // layer3 should have different MaterialProperty name
    property = layer3->getItemValue(LayerItem::P_MATERIAL).value<ExternalProperty>();
    EXPECT_EQ(property.text(), QString("name3changed"));
}