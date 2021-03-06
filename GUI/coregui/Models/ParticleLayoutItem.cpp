// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/ParticleLayoutItem.cpp
//! @brief     Implements class ParticleLayoutItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "ParticleLayoutItem.h"
#include "BornAgainNamespace.h"
#include "ComboProperty.h"
#include "InterferenceFunctionItems.h"
#include "Lattice2DItems.h"
#include <QDebug>

namespace
{

//! Returns true if name is related to 2D interference functions.
bool isInterference2D(const QString& name)
{
    if (name == Constants::InterferenceFunction2DLatticeType
        || name == Constants::InterferenceFunction2DParaCrystalType
        || name == Constants::InterferenceFunctionFinite2DLatticeType
        || name == Constants::InterferenceFunctionHardDiskType)
        return true;
    return false;
}

//! Returns true if name is related to 2D interference functions.
bool isLattice2D(SessionItem* item)
{
    return dynamic_cast<Lattice2DItem*>(item) ? true : false;
}

const QString density_tooltip =
    "Number of particles per square nanometer (particle surface density).\n "
    "Should be defined for disordered and 1d-ordered particle collections.";
const QString weight_tooltip =
    "Weight of this particle layout.\n"
    "Should be used when multiple layouts define different domains in the sample.";
} // namespace

const QString ParticleLayoutItem::P_TOTAL_DENSITY =
    QString::fromStdString(BornAgain::TotalParticleDensity);
const QString ParticleLayoutItem::P_WEIGHT = QString::fromStdString(BornAgain::Weight);
const QString ParticleLayoutItem::T_PARTICLES = "Particle Tag";
const QString ParticleLayoutItem::T_INTERFERENCE = "Interference Tag";

ParticleLayoutItem::ParticleLayoutItem() : SessionGraphicsItem(Constants::ParticleLayoutType)
{
    setToolTip(QStringLiteral("A layout of particles"));

    addProperty(P_TOTAL_DENSITY, 0.01)->setToolTip(density_tooltip);
    getItem(P_TOTAL_DENSITY)->setDecimals(10);
    addProperty(P_WEIGHT, 1.0)->setToolTip(weight_tooltip);

    registerTag(T_PARTICLES, 0, -1,
                QStringList() << Constants::ParticleType << Constants::ParticleCoreShellType
                              << Constants::ParticleCompositionType << Constants::MesoCrystalType
                              << Constants::ParticleDistributionType);
    setDefaultTag(T_PARTICLES);
    registerTag(T_INTERFERENCE, 0, 1,
                QStringList() << Constants::InterferenceFunction1DLatticeType
                              << Constants::InterferenceFunction2DLatticeType
                              << Constants::InterferenceFunction2DParaCrystalType
                              << Constants::InterferenceFunctionFinite2DLatticeType
                              << Constants::InterferenceFunctionHardDiskType
                              << Constants::InterferenceFunctionRadialParaCrystalType);

    mapper()->setOnChildrenChange([this](SessionItem*) {
        updateDensityAppearance();
        updateDensityValue();
    });

    mapper()->setOnAnyChildChange([this](SessionItem* item) {
        if (isLattice2D(item) || (item && isLattice2D(item->parent())))
            updateDensityValue();
    });
}

//! Disables/enables total density property, depending on type of interference function.
//! Two dimensional interference calculates density automatically, so property should
//! be disabled.

void ParticleLayoutItem::updateDensityAppearance()
{
    getItem(P_TOTAL_DENSITY)->setEnabled(true);
    if (auto interferenceItem = getItem(T_INTERFERENCE))
        if (isInterference2D(interferenceItem->modelType()))
            getItem(P_TOTAL_DENSITY)->setEnabled(false);
}

//! Updates the value of TotalSurfaceDensity on lattice type change.

void ParticleLayoutItem::updateDensityValue()
{
    if (auto interferenceItem = getItem(T_INTERFERENCE)) {
        if (interferenceItem->isTag(InterferenceFunction2DLatticeItem::P_LATTICE_TYPE)) {
            auto& latticeItem = interferenceItem->groupItem<Lattice2DItem>(
                InterferenceFunction2DLatticeItem::P_LATTICE_TYPE);
            double area = 0.0;
            try {
                area = latticeItem.unitCellArea();
            } catch (const std::exception&) {
                // nothing to do here; new exception will be caught during job execution
            }
            setItemValue(P_TOTAL_DENSITY, area == 0.0 ? 0.0 : 1.0 / area);
        } else if (interferenceItem->isTag(InterferenceFunctionHardDiskItem::P_DENSITY)) {
            double density =
                interferenceItem->getItemValue(InterferenceFunctionHardDiskItem::P_DENSITY)
                    .toDouble();
            setItemValue(P_TOTAL_DENSITY, density);
        }
    }
}
