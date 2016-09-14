// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Minimizer/BasicMinimizer.cpp
//! @brief     Implements class BasicMinimizer.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "BasicMinimizer.h"
#include "ROOTMinimizerFunction.h"
#include "Math/Minimizer.h"
#include "FitParameter.h"
#include "FitSuiteParameters.h"
#include "MinimizerResultsHelper.h"


BasicMinimizer::BasicMinimizer(const MinimizerInfo &minimizerInfo)
    :  m_minimizerInfo(minimizerInfo)
    , m_status(false)
{

}

BasicMinimizer::~BasicMinimizer()
{

}

void BasicMinimizer::minimize()
{
    propagateOptions();
    m_status = rootMinimizer()->Minimize();
}

std::string BasicMinimizer::minimizerName() const
{
    return m_minimizerInfo.name();
}

std::string BasicMinimizer::algorithmName() const
{
    return m_minimizerInfo.algorithmName();
}

void BasicMinimizer::setParameter(size_t index, const FitParameter *par)
{
    bool success;
    if (par->isFixed()) {
        success = rootMinimizer()->SetFixedVariable((int)index, par->getName().c_str(),
                                                    par->getValue());

    }

    else if (par->hasLowerAndUpperLimits()) {
        success = rootMinimizer()->SetLimitedVariable((int)index, par->getName().c_str(),
                                                      par->getValue(), par->getStep(),
                                                      par->getLowerLimit(),
                                                      par->getUpperLimit());
    }

    else if (par->hasLowerLimit() && !par->hasUpperLimit()) {
        success = rootMinimizer()->SetLowerLimitedVariable((int)index, par->getName().c_str(),
                                                           par->getValue(), par->getStep(),
                                                           par->getLowerLimit());
    }

    else if (par->hasUpperLimit() && !par->hasLowerLimit()) {
        success = rootMinimizer()->SetUpperLimitedVariable((int)index, par->getName().c_str(),
                                                           par->getValue(), par->getStep(),
                                                           par->getUpperLimit());
    }

    else if (!par->hasUpperLimit() && !par->hasLowerLimit() && !par->isFixed()) {
        success = rootMinimizer()->SetVariable((int)index, par->getName().c_str(), par->getValue(),
                                               par->getStep());
    }

    else {
        throw std::runtime_error("BasicMinimizer::setParameter() -> Error! Unexpected parameter.");
    }

    if( !success ) {
        std::ostringstream ostr;
        ostr << "BasicMinimizer::setParameter() -> Error! Can't set minimizer's fit parameter";
        ostr << "Index:" << index << " name '" << par->getName() << "'";
        throw std::runtime_error(ostr.str());
    }
}

void BasicMinimizer::setParameters(const FitSuiteParameters &parameters)
{
    size_t index(0);
    for (auto par: parameters)
        setParameter(index++, par );

    if( (int)parameters.size() != fitParameterCount())  {
        std::ostringstream ostr;
        ostr << "BasicMinimizer::setParameters() -> Error! Unconsistency in fit parameter number: ";
        ostr << "fitParameterCount = " << fitParameterCount();
        ostr << "parameters.size = " << parameters.size();
        throw std::runtime_error(ostr.str());
    }
}

void BasicMinimizer::setChiSquaredFunction(IMinimizer::function_chi2_t fun_chi2, size_t nparameters)
{
    m_chi2_func.reset(new ROOTMinimizerChiSquaredFunction(fun_chi2, (int)nparameters));
    if( !isGradientBasedAgorithm() ) rootMinimizer()->SetFunction(*m_chi2_func);
}

void BasicMinimizer::setGradientFunction(IMinimizer::function_gradient_t fun_gradient, size_t nparameters, size_t ndatasize)
{
    m_gradient_func.reset(new ROOTMinimizerGradientFunction(fun_gradient, nparameters, ndatasize));
    if( isGradientBasedAgorithm() ) rootMinimizer()->SetFunction(*m_gradient_func);
}

std::vector<double> BasicMinimizer::getValueOfVariablesAtMinimum() const
{
    std::vector<double > result;
    result.resize(fitParameterCount(), 0.0);
    std::copy(rootMinimizer()->X(), rootMinimizer()->X()+fitParameterCount(), result.begin());
    return result;
}

std::vector<double> BasicMinimizer::getErrorOfVariables() const
{
    std::vector<double > result;
    result.resize(fitParameterCount(), 0.0);
    if(rootMinimizer()->Errors() != 0 ) {
        std::copy(rootMinimizer()->Errors(), rootMinimizer()->Errors()+fitParameterCount(), result.begin());
    }
    return result;
}

std::string BasicMinimizer::reportResults() const
{
    MinimizerResultsHelper reporter;
    return reporter.reportResults(this);
}

std::string BasicMinimizer::statusToString() const
{
    return (m_status ? std::string("Minimum found") : std::string("Error in solving"));
}

bool BasicMinimizer::providesError() const
{
    return rootMinimizer()->ProvidesError();
}

std::map<std::string, std::string> BasicMinimizer::statusMap() const
{
    std::map<std::string, std::string> result;
    result["Status"] = statusToString();

    if(providesError()) {
        result["ProvidesError"] = "Provides parameters error and error matrix";
    } else {
        result["ProvidesError"] = "Doesn't provide error calculation";
    }

    result["MinValue"] = to_string_scientific(rootMinimizer()->MinValue());

    return result;
}

void BasicMinimizer::propagateResults(FitSuiteParameters &parameters)
{
    // sets values and errors found
    parameters.setValues(getValueOfVariablesAtMinimum());
    parameters.setErrors(getErrorOfVariables());

    // sets correlation matrix
    if(providesError()) {
        FitSuiteParameters::corr_matrix_t matrix;
        matrix.resize(fitParameterCount());

        for(size_t i=0; i<(size_t)fitParameterCount(); ++i) {
            matrix[i].resize(fitParameterCount(), 0.0);
            for(size_t j=0; j<(size_t)fitParameterCount(); ++j) {
                matrix[i][j] = rootMinimizer()->Correlation(i,j);
            }
        }
        parameters.setCorrelationMatrix(matrix);
    }
}

//! Returns number of fit parameters defined (i.e. dimension of the function to be minimized).

int BasicMinimizer::fitParameterCount() const
{
    return rootMinimizer()->NDim();
}

BasicMinimizer::root_minimizer_t *BasicMinimizer::rootMinimizer()
{
    return const_cast<root_minimizer_t *>(static_cast<const BasicMinimizer*>(this)->rootMinimizer());
}
