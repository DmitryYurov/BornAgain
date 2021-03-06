// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Fit/Minimizer/FunctionTestPlanFactory.h
//! @brief     Defines class FunctionTestPlanFactory
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef FUNCTIONTESTPLANFACTORY_H
#define FUNCTIONTESTPLANFACTORY_H

#include "MinimizerTestPlan.h"
#include "IFactory.h"

//! Factory to generate plans for fitting objective functions.

class FunctionTestPlanFactory : public IFactory<std::string, MinimizerTestPlan>
{
public:
    FunctionTestPlanFactory();
};

#endif //   FUNCTIONTESTPLANFACTORY_H
