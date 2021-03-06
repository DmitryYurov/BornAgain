// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/CylindersAndPrismsBuilder.cpp
//! @brief     Implements class CylindersAndPrismsBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "CylindersAndPrismsBuilder.h"
#include "MaterialFactoryFuncs.h"
#include "BornAgainNamespace.h"
#include "FormFactorCylinder.h"
#include "FormFactorPrism3.h"
#include "Layer.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "ParticleLayout.h"
#include "RealParameter.h"
#include "Units.h"

CylindersAndPrismsBuilder::CylindersAndPrismsBuilder()
{}

MultiLayer* CylindersAndPrismsBuilder::buildSample() const
{
    MultiLayer* multi_layer = new MultiLayer();

    Material air_material = HomogeneousMaterial("Air", 0., 0.);
    Material substrate_material = HomogeneousMaterial("Substrate", 6e-6, 2e-8);
    Material particle_material = HomogeneousMaterial("Particle", 6e-4, 2e-8);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);

    ParticleLayout particle_layout;

    FormFactorCylinder ff_cylinder(5.0, 5.0);
    Particle cylinder(particle_material, ff_cylinder);

    FormFactorPrism3 ff_prism3(10.0, 5.0);
    Particle prism3(particle_material, ff_prism3);

    particle_layout.addParticle(cylinder, 0.5);
    particle_layout.addParticle(prism3, 0.5);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}
