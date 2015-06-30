// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      StandardSamples/CoreShellParticleBuilder.h
//! @brief     Defines class CoreShellParticleBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef CORESHELLPARTICLEBUILDER_H
#define CORESHELLPARTICLEBUILDER_H

#include "ISampleBuilder.h"

//! @class CoreShellParticleBuilder
//! @ingroup standard_samples
//! @brief Builds sample: Core Shell Nanoparticles (IsGISAXS example #11)

class BA_CORE_API_ CoreShellParticleBuilder : public ISampleBuilder
{
public:
    CoreShellParticleBuilder();
    ISample *buildSample() const;
};

#endif // CORESHELLPARTICLEBUILDER_H