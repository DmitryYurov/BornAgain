// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Parametrization/RealParameterWrapper.cpp
//! @brief     Implements class RealParameterWrapper.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "IParameterized.h"
#include <sstream>

RealParameterWrapper::RealParameterWrapper(
    IParameterized* parent, double* par, const AttLimits& limits)
    : m_parent(parent)
    , m_data(par)
    , m_limits(limits)
{
    if(par && !m_limits.isInRange(getValue())) {
        std::ostringstream message;
        message << "RealParameterWrapper::RealParameterWrapper() -> Error. "
                << "Initial value " << getValue() << " is out of bounds "
                << limits << std::endl;
        throw Exceptions::OutOfBoundsException(message.str());
    }
}

RealParameterWrapper::RealParameterWrapper(const RealParameterWrapper& other )
{
    m_parent = other.m_parent;
    m_data = other.m_data;
    m_limits = other.m_limits;
}

RealParameterWrapper& RealParameterWrapper::operator=(const RealParameterWrapper& other)
{
    if( this !=& other )  {
        RealParameterWrapper tmp(other);
        tmp.swapContent(*this);
    }
    return *this;
}

void RealParameterWrapper::setValue(double value)
{
    checkNull();
    if(value != *m_data) {
        if(m_limits.isInRange(value) && !m_limits.isFixed()) {
            *m_data = value;
            m_parent->onChange();
        } else {
            throw Exceptions::OutOfBoundsException("Value not in range");
        }
    }
}

void RealParameterWrapper::swapContent(RealParameterWrapper& other)
{
    std::swap(this->m_parent, other.m_parent);
    std::swap(this->m_data, other.m_data);
    std::swap(this->m_limits, other.m_limits);
}
