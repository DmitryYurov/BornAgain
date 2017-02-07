// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/BeamAngleItems.cpp
//! @brief     Implements class BeamAngleItems
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "BeamAngleItems.h"
#include "Distributions.h"
#include "GUIHelpers.h"
#include "Units.h"

BeamInclinationAngleItem::BeamInclinationAngleItem()
    : BeamDistributionItem(Constants::BeamInclinationAngleType)
{
    register_distribution_group();

    SessionItem *valueItem = getGroupItem(P_DISTRIBUTION)->getItem(DistributionNoneItem::P_VALUE);
    valueItem->setLimits(RealLimits::limited(0.0, 90.0));
    valueItem->setDecimals(3);
    valueItem->setValue(0.2);

    initDistributionItem();
}

//! Returns beam inclination angle. In the case of distribution applied, returns its mean.

double BeamInclinationAngleItem::inclinationAngle() const
{
    std::unique_ptr<IDistribution1D> domainDistr = createDistribution1D();
    if(domainDistr)
        return Units::rad2deg(domainDistr->getMean());
    else
        return getGroupItem(P_DISTRIBUTION)->getItemValue(DistributionNoneItem::P_VALUE).toDouble();
}

std::unique_ptr<IDistribution1D> BeamInclinationAngleItem::createDistribution1D() const
{
    if(auto distItem = dynamic_cast<DistributionItem *>(getGroupItem(P_DISTRIBUTION)))
        return distItem->createDistribution(Units::degree);

    return {};
}

// -------------------------------------------------------------------------- //

BeamAzimuthalAngleItem::BeamAzimuthalAngleItem()
    : BeamDistributionItem(Constants::BeamAzimuthalAngleType)
{
    register_distribution_group();

    SessionItem *valueItem = getGroupItem(P_DISTRIBUTION)->getItem(DistributionNoneItem::P_VALUE);
    valueItem->setLimits(RealLimits::limited(-90.0, 90.0));
    valueItem->setDecimals(3);
    valueItem->setValue(0.0);

    initDistributionItem();
}

//! Returns beam azimuthal angle. In the case of distribution applied, returns its mean.

double BeamAzimuthalAngleItem::azimuthalAngle() const
{
    std::unique_ptr<IDistribution1D> domainDistr = createDistribution1D();
    if(domainDistr)
        return Units::rad2deg(domainDistr->getMean());
    else
        return getGroupItem(P_DISTRIBUTION)->getItemValue(DistributionNoneItem::P_VALUE).toDouble();
}

std::unique_ptr<IDistribution1D> BeamAzimuthalAngleItem::createDistribution1D() const
{
    if(auto distItem = dynamic_cast<DistributionItem *>(getGroupItem(P_DISTRIBUTION)))
        return distItem->createDistribution(Units::degree);

    return {};
}
