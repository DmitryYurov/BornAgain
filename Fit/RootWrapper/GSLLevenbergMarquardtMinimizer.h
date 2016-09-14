// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Minimizer/GSLLevenbergMarquardtMinimizer.h
//! @brief     Declares class GSLLevenbergMarquardtMinimizer.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef GSLLEVENBERGMARQUARDTMINIMIZER_H
#define GSLLEVENBERGMARQUARDTMINIMIZER_H

#include "BasicMinimizer.h"
namespace BA_ROOT { namespace Math { class GSLNLSMinimizer; } }

//! @class GSLLevenbergMarquardtMinimizer
//! @ingroup fitting_internal
//! @brief Wrapper for GSL Levenberg-Marquardt minimizer.
//! http://www.gnu.org/software/gsl/manual/html_node/Nonlinear-Least_002dSquares-Fitting.html

class BA_CORE_API_ GSLLevenbergMarquardtMinimizer : public BasicMinimizer {
public:
    GSLLevenbergMarquardtMinimizer();
    ~GSLLevenbergMarquardtMinimizer();

    //!< Sets tolerance on the function value at the minimum.
    //! Default value is 0.01.
    void setTolerance(double value);
    double tolerance() const;

    //! Sets minimizer internal print level.
    //! Default value is 0 (silent).
    void setPrintLevel(int value);
    int printLevel() const;

    //! Sets maximum number of iterations. This is an internal minimizer setting which has
    //! no direct relation to the number of objective function calls (e.g. numberOfIteraction=5
    //! might correspond to ~100 objective function calls).
    void setMaxIterations(int value);
    int maxIterations() const;

    std::string statusToString() const;
    std::map<std::string, std::string> statusMap() const;

protected:
    virtual bool isGradientBasedAgorithm() { return true; }
    void propagateOptions();
    const root_minimizer_t* rootMinimizer() const;

private:
    std::unique_ptr<BA_ROOT::Math::GSLNLSMinimizer> m_gsl_minimizer;
};

#endif