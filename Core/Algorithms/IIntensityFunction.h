// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/inc/IIntensityFunction.h
//! @brief     Defines and implements the interface class IIntensityFunction
//!            and its child classes IntensityFunctionLog, IntensityFunctionSqrt
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef IINTENSITYFUNCTION_H
#define IINTENSITYFUNCTION_H

#include <cmath>


//! @class IIntensityFunction
//! @ingroup algorithms_internal
//! @brief Interface for applying arbitrary function to the measured intensity

class BA_CORE_API_ IIntensityFunction
{
public:
    virtual ~IIntensityFunction() {}
    virtual IIntensityFunction *clone() const=0;

    virtual double evaluate(double value) const=0;
};


//! @class IntensityFunctionLog
//! @ingroup algorithms_internal
//! @brief Algorithm for applying log function to the measured intensity

class BA_CORE_API_ IntensityFunctionLog : public IIntensityFunction
{
public:
    virtual ~IntensityFunctionLog() {}
    virtual IntensityFunctionLog *clone() const {
        return new IntensityFunctionLog(); }
    virtual double evaluate(double value) const {
        return (value > 0 ? std::log(value) : 0); }
};


//! @class IntensityFunctionSqrt
//! @ingroup algorithms_internal
//! @brief Algorithm for applying sqrt function to the measured intensity

class BA_CORE_API_ IntensityFunctionSqrt : public IIntensityFunction
{
public:
    virtual ~IntensityFunctionSqrt() {}
    virtual IntensityFunctionSqrt *clone() const {
        return new IntensityFunctionSqrt(); }
    virtual double evaluate(double value) const {
        return (value > 0 ? std::sqrt(value) : 0); }
};

#endif // IINTENSITYFUNCTION_H