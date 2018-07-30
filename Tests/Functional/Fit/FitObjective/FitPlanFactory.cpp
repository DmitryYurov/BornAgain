// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Fit/FitObjective/FitPlanFactory.cpp
//! @brief     Implements class FitPlanFactory
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "FitPlanFactory.h"
#include "FitPlanCases.h"
#include "AdjustMinimizerPlan.h"

FitPlanFactory::FitPlanFactory()
{
    registerItem("CylindersInBAPlan", create_new<CylindersInBAPlan>);
    registerItem("CylindersInBAEasyPlan", create_new<CylindersInBAEasyPlan>);
    registerItem("CylindersInBAResidualPlan", create_new<CylindersInBAResidualPlan>);
    registerItem("RectDetPlan", create_new<RectDetPlan>);
    registerItem("AdjustMinimizerPlan", create_new<AdjustMinimizerPlan>);
    registerItem("MultiPatternPlan", create_new<MultiPatternPlan>);
    registerItem("SpecularPlan", create_new<SpecularPlan>);
}
