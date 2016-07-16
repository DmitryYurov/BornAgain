// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Samples/ParticleCoreShell.h
//! @brief     Declares ParticleCoreShell.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PARTICLECORESHELL_H
#define PARTICLECORESHELL_H

#include "IParticle.h"

//! @ParticleCoreShell
//! @ingroup samples
//! @brief A particle with a core/shell geometry

class BA_CORE_API_ ParticleCoreShell : public IParticle
{
public:
    ParticleCoreShell(const class Particle& shell, const class Particle& core,
            kvector_t relative_core_position=kvector_t(0.0, 0.0, 0.0));
    virtual ~ParticleCoreShell();
    virtual ParticleCoreShell *clone() const;

    //! Returns a clone with inverted magnetic fields
    virtual ParticleCoreShell *cloneInvertB() const;

    //! Calls the ISampleVisitor's visit method
    virtual void accept(ISampleVisitor *visitor) const;

    //! Sets the refractive index of the ambient material (which influences its scattering power)
    virtual void setAmbientMaterial(const IMaterial& material);
    virtual const IMaterial* getAmbientMaterial() const;

    //! Create a form factor for this particle with an extra scattering factor
    virtual IFormFactor *createTransformedFormFactor(const IRotation* p_rotation,
                                                     kvector_t translation) const;

    //! Returns the core particle
    const class Particle *getCoreParticle() const;

    //! Returns the shell particle
    const class Particle *getShellParticle() const;

protected:
    void addAndRegisterCore(const class Particle &core, kvector_t relative_core_position);
    void addAndRegisterShell(const class Particle &shell);

    ParticleCoreShell();
    class Particle *mp_shell;
    class Particle *mp_core;
};

#endif // PARTICLECORESHELL_H
