// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/inc/FormFactorDecoratorTransformation.h
//! @brief     Defines and implements class FormFactorDecoratorTransformation.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke 
//
// ************************************************************************** //

#ifndef FORMFACTORDECORATORTRANSFORMATION_H
#define FORMFACTORDECORATORTRANSFORMATION_H

#include "IFormFactorDecorator.h"
#include "ITransform3D.h"

//! Equip a Formfactor with a rotation.

class FormFactorDecoratorTransformation : public IFormFactorDecorator
{
 public:
    //! Constructor, setting formfactor and rotation.
    FormFactorDecoratorTransformation(
        IFormFactor *p_form_factor, Geometry::ITransform3D *transform)
        : IFormFactorDecorator(p_form_factor)
        , mp_transform(transform)
        , mp_inverse_transform(0)
    {
        setName("FormFactorDecoratorTransformation");
        mp_inverse_transform =
            new Geometry::ITransform3D(mp_transform->inverse());
    }

    virtual ~FormFactorDecoratorTransformation()
    {
        delete mp_transform;
        delete mp_inverse_transform;
    }

    virtual FormFactorDecoratorTransformation *clone() const
    {
        Geometry::ITransform3D *p_new_transform =
            new Geometry::ITransform3D(*mp_transform);
        return new FormFactorDecoratorTransformation(
            mp_form_factor->clone(), p_new_transform);
    }

    virtual complex_t evaluate(
        const cvector_t& k_i, const Bin1DCVector& k_f_bin,
        double alpha_i, double alpha_f) const;
    // --> inline implementation below <--

    virtual int getNumberOfStochasticParameters() const
    { return mp_form_factor->getNumberOfStochasticParameters(); }

 protected:
    Geometry::ITransform3D *mp_transform;
    Geometry::ITransform3D *mp_inverse_transform;
};


// -----------------------------------------------------------------------------
// Inline implementations
// -----------------------------------------------------------------------------

inline complex_t FormFactorDecoratorTransformation::evaluate(
    const cvector_t& k_i, const Bin1DCVector& k_f_bin,
    double alpha_i, double alpha_f) const
{
    cvector_t new_ki =
        mp_inverse_transform->transformed(k_i);
    cvector_t new_kf_lower =
        mp_inverse_transform->transformed(k_f_bin.m_q_lower);
    cvector_t new_kf_upper =
        mp_inverse_transform->transformed(k_f_bin.m_q_upper);
    Bin1DCVector new_kf_bin(new_kf_lower, new_kf_upper);
    return mp_form_factor->evaluate(new_ki, new_kf_bin, alpha_i, alpha_f);
}

#endif // FORMFACTORDECORATORTRANSFORMATION_H
