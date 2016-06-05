"""
Working with sample parameters
"""

from __future__ import print_function
import matplotlib
from matplotlib import pyplot as plt
import bornagain as ba
from bornagain import degree, angstrom, nanometer


def get_sample():
    """
    Returns a sample with uncorrelated cylinders and prisms on a substrate.
    Parameter set is fixed.
    """
    # defining materials
    m_air = ba.HomogeneousMaterial("Air", 0.0, 0.0)
    m_substrate = ba.HomogeneousMaterial("Substrate", 6e-6, 2e-8)
    m_particle = ba.HomogeneousMaterial("Particle", 6e-4, 2e-8)

    # collection of particles
    cylinder_ff = ba.FormFactorCylinder(5*nanometer, 5*nanometer)
    cylinder = ba.Particle(m_particle, cylinder_ff)
    prism_ff = ba.FormFactorPrism3(5*nanometer, 5*nanometer)
    prism = ba.Particle(m_particle, prism_ff)
    particle_layout = ba.ParticleLayout()
    particle_layout.addParticle(cylinder, 0.5)
    particle_layout.addParticle(prism, 0.5)
    interference = ba.InterferenceFunctionNone()
    particle_layout.addInterferenceFunction(interference)

    # air layer with particles and substrate form multi layer
    air_layer = ba.Layer(m_air)
    air_layer.addLayout(particle_layout)
    substrate_layer = ba.Layer(m_substrate, 0)
    multi_layer = ba.MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)
    return multi_layer


def get_simulation():
    """
    Create and return GISAXS simulation with beam and detector defined
    """
    simulation = ba.GISASSimulation()
    simulation.setDetectorParameters(100, -1.0*degree, 1.0*degree,
                                     100, 0.0*degree, 2.0*degree)
    simulation.setBeamParameters(1.0*angstrom, 0.2*degree, 0.0*degree)
    return simulation


def run_simulations():
    """
    Runs simulations for the sample with different sample parameters.
    """

    sample = get_sample()
    print("The tree structure of the sample")
    sample.printSampleTree()

    print("The sample contains following parameters ('name':value)")
    sample.printParameters()

    simulation = get_simulation()

    results = []

    # simulation #1
    # initial sample is used
    simulation.setSample(sample)
    simulation.runSimulation()
    results.append(simulation.getIntensityData())

    # simulation #2
    # one sample parameter (cylinder height) is changed using exact parameter name
    sample.setParameterValue(
        "/MultiLayer/Layer0/ParticleLayout/Particle0/Cylinder/Height",
        10.0*nanometer)

    simulation.setSample(sample)
    simulation.runSimulation()
    results.append(simulation.getIntensityData())

    # simulation #3
    # all parameters matching criteria will be changed (cylinder height in this case)
    sample.setParameterValue("*/Cylinder/Height", 100.0*nanometer)
    simulation.setSample(sample)
    simulation.runSimulation()
    results.append(simulation.getIntensityData())

    # simulation #4
    # all parameters which are matching criteria will be changed
    sample.setParameterValue("*/Cylinder/Height", 10.0*nanometer)
    # set ba.FormFactorPrism3/half_side and ba.FormFactorPrism3/height to 10 nm
    sample.setParameterValue("*/Prism3/*", 10.0*nanometer)
    simulation.setSample(sample)
    simulation.runSimulation()
    results.append(simulation.getIntensityData())

    return results


def draw_results(results):
    """
    Draw results of several simulations on canvas
    """
    plt.figure(1)
    for nplot, hist in enumerate(results):
        plt.subplot(2, 2, nplot+1)
        plt.imshow(
            hist.getArray(),
            norm=matplotlib.colors.LogNorm(1, hist.getMaximum()),
            extent=[hist.getXmin()/degree, hist.getXmax()/degree,
                    hist.getYmin()/degree, hist.getYmax()/degree])

    plt.show()


if __name__ == '__main__':
    results = run_simulations()
    draw_results(results)
