// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      StandardSamples/SimulationRegistry.cpp
//! @brief     Implement class SimulationRegistry.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "SimulationRegistry.h"
#include "StandardSimulations.h"


SimulationRegistry::SimulationRegistry()
{
    registerItem("BasicGISAS",
                 StandardSimulations::BasicGISAS,
                 "Basic GISAS simulation with the detector phi[0,2], theta[0,2]");

    registerItem("BasicGISAS00",
                 StandardSimulations::BasicGISAS00,
                 "Basic GISAS for polarization studies");

    registerItem("MiniGISAS",
                 StandardSimulations::MiniGISAS,
                 "GISAS simulation with small 25x25 detector and phi[-2,2], theta[0,2]");

    registerItem("MiniGISAS_v2",
                 StandardSimulations::MiniGISAS_v2,
                 "GISAS simulation with small 25x25 detector and phi[-1,1], theta[0,]");

    registerItem("MiniGISASBeamDivergence",
                 StandardSimulations::MiniGISASBeamDivergence,
                 "GISAS simulation with small detector and beam divergence");

    registerItem("MiniGISASDetectorResolution",
                 StandardSimulations::MiniGISASDetectorResolution,
                 "GISAS simulation with small detector and detector resolution");

    registerItem("GISASWithMasks",
                 StandardSimulations::GISASWithMasks,
                 "GISAS simulation with small detector and various masks");

    registerItem("MaxiGISAS",
                 StandardSimulations::MaxiGISAS,
                 "GISAS simulation with large detector to test performance");

    registerItem("MaxiGISAS00",
                 StandardSimulations::MaxiGISAS00,
                 "GISAS simulation with large detector to test performance");

    registerItem("IsGISAXSSimulation1",
                 StandardSimulations::IsGISAXSSimulation1,
                 "Typical IsGISAXS simulation with the detector theta[-1,1], phi[0,2]");

    registerItem("IsGISAXSSimulation2",
                 StandardSimulations::IsGISAXSSimulation2,
                 "Typical IsGISAXS simulation with the detector theta[0,1], phi[0,2]");

    // polarization

    registerItem(
        "polmagcylinders2", StandardSimulations::PolarizedDWBAMagCylinders2,
        "Polarized DWBA with non-zero magnetic field");

    // rectangular detectors

    registerItem("RectDetectorGeneric",
                 StandardSimulations::RectDetectorGeneric,
                 "Rectangular detector with generic alignment");

    registerItem("RectDetectorPerpToSample",
                 StandardSimulations::RectDetectorPerpToSample,
                 "Rectangular detector with generic alignment");

    registerItem("RectDetectorPerpToDirectBeam",
                 StandardSimulations::RectDetectorPerpToDirectBeam,
                 "Rectangular detector with generic alignment");

    registerItem("RectDetectorPerpToReflectedBeam",
                 StandardSimulations::RectDetectorPerpToReflectedBeam,
                 "Rectangular detector with generic alignment");

    registerItem("RectDetectorPerpToReflectedBeamDpos",
                 StandardSimulations::RectDetectorPerpToReflectedBeamDpos,
                 "Rectangular detector with generic alignment");
}


GISASSimulation *SimulationRegistry::createSimulation(const std::string& name)
{
    GISASSimulation *result = createItem(name);
    return result;
}


