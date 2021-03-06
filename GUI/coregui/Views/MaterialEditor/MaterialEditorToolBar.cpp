// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/MaterialEditor/MaterialEditorToolBar.cpp
//! @brief     Implements class MaterialEditorToolBar
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "MaterialEditorToolBar.h"
#include "MaterialItem.h"
#include "MaterialModel.h"
#include <QAction>
#include <QItemSelectionModel>
#include <QListView>
#include <QMenu>
#include <QVariant>

namespace {
const int toolbar_icon_size = 32;
}

MaterialEditorToolBar::MaterialEditorToolBar(MaterialModel* materialModel, QWidget* parent)
    : QToolBar(parent)
    , m_materialModel(materialModel)
    , m_selectionModel(nullptr)
    , m_newMaterialAction(nullptr)
    , m_cloneMaterialAction(nullptr)
    , m_removeMaterialAction(nullptr)
{
    setIconSize(QSize(toolbar_icon_size, toolbar_icon_size));
    setProperty("_q_custom_style_disabled", QVariant(true));

    m_newMaterialAction = new QAction(QStringLiteral("Add new material"), parent);
    m_newMaterialAction->setIcon(QIcon(":/images/toolbar32dark_newitem.svg"));
    m_newMaterialAction->setToolTip(QStringLiteral("Add new material"));
    connect(m_newMaterialAction, &QAction::triggered,
            this, &MaterialEditorToolBar::onNewMaterialAction);
    addAction(m_newMaterialAction);

    m_cloneMaterialAction = new QAction(QStringLiteral("Clone material"), parent);
    m_cloneMaterialAction->setIcon(QIcon(":/images/toolbar32dark_cloneitem.svg"));
    m_cloneMaterialAction->setToolTip(QStringLiteral("Clone selected material"));
    connect(m_cloneMaterialAction, &QAction::triggered,
            this, &MaterialEditorToolBar::onCloneMaterialAction);
    addAction(m_cloneMaterialAction);

    m_removeMaterialAction = new QAction(QStringLiteral("Remove selected material"), parent);
    m_removeMaterialAction->setIcon(QIcon(":/images/toolbar32dark_remove.svg"));
    m_removeMaterialAction->setToolTip(QStringLiteral("Remove selected material"));
    connect(m_removeMaterialAction, &QAction::triggered,
            this, &MaterialEditorToolBar::onRemoveMaterialAction);
    addAction(m_removeMaterialAction);
}

void MaterialEditorToolBar::setSelectionModel(QItemSelectionModel* selectionModel)
{
    m_selectionModel = selectionModel;
}

void MaterialEditorToolBar::onCustomContextMenuRequested(const QPoint& point)
{
    QListView* listView = qobject_cast<QListView*>(sender());
    Q_ASSERT(listView);
    QMenu menu;
    initItemContextMenu(menu);
    menu.exec(listView->mapToGlobal(point));
}

void MaterialEditorToolBar::onNewMaterialAction()
{
    m_materialModel->addRefractiveMaterial("unnamed", 0.0, 0.0); // vacuum
}

void MaterialEditorToolBar::onCloneMaterialAction()
{
    auto selected = m_selectionModel->currentIndex();

    if (selected.isValid())
        m_materialModel->cloneMaterial(selected);
}

void MaterialEditorToolBar::onRemoveMaterialAction()
{
    Q_ASSERT(m_materialModel);
    Q_ASSERT(m_selectionModel);

    auto selected = m_selectionModel->currentIndex();

    if (selected.isValid())
        m_materialModel->removeRows(selected.row(), 1, selected.parent());
}

void MaterialEditorToolBar::initItemContextMenu(QMenu& menu)
{
    menu.addAction(m_newMaterialAction);
    menu.addAction(m_cloneMaterialAction);
    menu.addSeparator();
    menu.addAction(m_removeMaterialAction);
}
