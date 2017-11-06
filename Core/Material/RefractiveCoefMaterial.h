// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Material/RefractiveCoefMaterial.h
//! @brief     Defines class RefractiveCoefMaterial.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2017
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke, D. Yurov
//
// ************************************************************************** //

#ifndef REFRACTIVECOEFMATERIAL_H_
#define REFRACTIVECOEFMATERIAL_H_

#include "MagneticMaterialImpl.h"
#include "Material.h"

//! Material implementation based on refractive coefficiencts (valid for one wavelength value only)
//! @ingroup materials

class BA_CORE_API_ RefractiveCoefMaterial : public MagneticMaterialImpl
{
public:
    friend BA_CORE_API_ Material HomogeneousMaterial(const std::string&, complex_t, kvector_t);

    friend BA_CORE_API_ Material HomogeneousMaterial(const std::string&, double, double,
                                                         kvector_t);

    friend BA_CORE_API_ Material HomogeneousMaterial();

    virtual ~RefractiveCoefMaterial();

    //! Returns pointer to a copy of material
    virtual RefractiveCoefMaterial* clone() const override;

    //! Returns refractive index
    //! For this particular implementation returned value does not depend
    //! on passed wavelength
    virtual complex_t refractiveIndex(double wavelength) const override;

    //! Returns squared refractive index.
    //! For this particular implementation returned value does not depend
    //! on passed wavelength.
    virtual complex_t refractiveIndex2(double wavelength) const override;

    //! Returns underlying material data
    virtual complex_t materialData() const override;

    //! Returns (\f$ \pi/\lambda^2 \f$ - sld), sld (in \f$nm^{-2}\f$) being the scattering length density.
    //! If the wavelength associated with passed wavevector is different from the one
    //! associated with refractive coefficients used during the object construction,
    //! provided result is inconsistent.
    virtual complex_t scalarSubtrSLD(const WavevectorInfo& wavevectors) const override;

    //! Prints object data
    virtual void print(std::ostream &ostr) const override;

private:
    RefractiveCoefMaterial(const std::string& name, double delta, double beta,
                           kvector_t magnetization);

    double m_delta; //!< \f$\delta\f$ coefficient for refractive index \f$n = 1 - \delta + i \beta\f$
    double m_beta; //!< \f$\beta\f$ coefficient for refractive index \f$n = 1 - \delta + i \beta\f$
};

#endif /* REFRACTIVECOEFMATERIAL_H_ */
