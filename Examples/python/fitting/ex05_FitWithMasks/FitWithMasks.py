"""
Two parameter fit of cylinders without interference.
Real data contains rectangular mask to simulate and fit only the area inside the mask.
"""

import numpy
from matplotlib import pyplot as plt
import matplotlib
import math
from bornagain import *

plt.ion()
fig = plt.figure(figsize=(10.24, 7.68))
fig.canvas.draw()


def get_sample(radius=5*nanometer, height=10*nanometer):
    """
    Build the sample representing cylinders and pyramids on top of
    substrate without interference.
    """
    m_air = HomogeneousMaterial("Air", 0.0, 0.0)
    m_substrate = HomogeneousMaterial("Substrate", 6e-6, 2e-8)
    m_particle = HomogeneousMaterial("Particle", 6e-4, 2e-8)

    cylinder_ff = FormFactorCylinder(radius, height)
    cylinder = Particle(m_particle, cylinder_ff)

    particle_layout = ParticleLayout()
    particle_layout.addParticle(cylinder)

    air_layer = Layer(m_air)
    air_layer.addLayout(particle_layout)

    substrate_layer = Layer(m_substrate, 0)
    multi_layer = MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)
    return multi_layer


def get_simulation():
    """
    Create and return GISAXS simulation with beam and detector defined
    """
    simulation = GISASSimulation()
    simulation.setDetectorParameters(100, -1.0*degree, 1.0*degree, 100, 0.0*degree, 2.0*degree, True)
    simulation.setBeamParameters(1.0*angstrom, 0.2*degree, 0.0*degree)
    return simulation


def create_real_data():
    """
    Generating "real" data by adding noise to the simulated data. Sample parameters are set to
    radius = 10*nanometer, lattice_constant=20*nanometer
    This parameters we will try to find later during the fit
    """
    sample = get_sample(5.0*nanometer, 10.0*nanometer)

    simulation = get_simulation()
    simulation.setSample(sample)

    simulation.runSimulation()
    real_data = simulation.getIntensityData()

    # spoiling simulated data with the noise to produce "real" data
    noise_factor = 0.1
    for i in range(0, real_data.getAllocatedSize()):
        amplitude = real_data[i]
        sigma = noise_factor*math.sqrt(amplitude)
        noisy_amplitude = GenerateNormalRandom(amplitude, sigma)
        if noisy_amplitude < 0.0:
            noisy_amplitude = 0.0
        real_data[i] = noisy_amplitude
    return real_data


class DrawObserver(IFitObserver):
    """
    class which draws fit progress every nth iteration.
    It has to be attached to fit_suite via AttachObserver command
    """
    def __init__(self, draw_every=10):
        IFitObserver.__init__(self, draw_every)

    def plot(self, data, title, nplot, min=1, max=1e6):
        plt.subplot(2, 2, nplot)
        plt.subplots_adjust(wspace=0.2, hspace=0.2)
        im = plt.imshow(data.getArray(),
                        norm=matplotlib.colors.LogNorm(min, max),
                        extent=[-1.0, 1.0, 0, 2.0])
        plt.colorbar(im)
        plt.title(title)

    def update(self, fit_suite):
        fig.clf()
        self.plot(fit_suite.getRealData(), "\"Real\" data", 1)
        self.plot(fit_suite.getSimulationData(), "Simulated data", 2)
        self.plot(fit_suite.getChiSquaredMap(), "Chi2 map", 3, min=0.001, max=1.0)

        plt.subplot(2, 2, 4)
        plt.title('Parameters')
        plt.axis('off')
        plt.text(0.01, 0.85, "Iteration  " + str(fit_suite.getNCalls()))
        plt.text(0.01, 0.75, "Chi2       " + str(fit_suite.getFitObjects().getChiSquaredValue()))
        fitpars = fit_suite.getFitParameters()
        for i in range(0, fitpars.size()):
            plt.text(0.01, 0.55 - i*0.1, str(fitpars[i].getName()) + " " + str(fitpars[i].getValue())[0:5] )

        plt.draw()
        plt.pause(0.01)


def run_fitting():
    """
    main function to run fitting
    """
    simulation = get_simulation()
    sample = get_sample()
    simulation.setSample(sample)

    real_data = create_real_data()

    fit_suite = FitSuite()
    # fit_suite.setMinimizer("GSLLMA")
    # fit_suite.setMinimizer("Minuit2", "Fumili")

    # Here we are settings masks to the detector plane to simulate image which looks like a Pac-Man
    # from ancient arcade game

    # mask all detector (put mask=True to all detector channels to
    simulation.maskAll()

    # set mask to simulate pacman's head
    simulation.addMask(Ellipse(0.0*deg, 1.0*deg, 0.5*deg, 0.5*deg), False)

    # set mask for pacman's eye
    simulation.addMask(Ellipse(0.11*deg, 1.25*deg, 0.05*deg, 0.05*deg), True)

    # set mask for pacman's mouth
    points = [[0.0*deg, 1.0*deg], [0.5*deg, 1.2*deg], [0.5*deg, 0.8*deg], [0.0*deg, 1.0*deg]]
    simulation.addMask(Polygon(points), True)

    # giving pacman something to eat
    simulation.addMask(Rectangle(0.45*deg, 0.95*deg, 0.55*deg, 1.05*deg), False)
    simulation.addMask(Rectangle(0.61*deg, 0.95*deg, 0.71*deg, 1.05*deg), False)
    simulation.addMask(Rectangle(0.75*deg, 0.95*deg, 0.85*deg, 1.05*deg), False)

    # other mask's shapes are possible too
    # simulation.removeMasks()
    # simulation.addMask(Ellipse(0.11*deg, 1.25*deg, 1.0*deg, 0.5*deg, 45.0*degree), True) # rotated ellipse
    # simulation.addMask(Line(-1.0*deg, 0.0*deg, 1.0*deg, 2.0*deg), True)
    # simulation.addMask(HorizontalLine(1.0*deg), False)
    # simulation.addMask(VerticalLine(0.0*deg), False)



    # masking example: two excluded rectangles on the plot
    # IntensityDataFunctions.addRectangularMask(real_data, -0.1*degree, 0.1*degree, 0.1*degree, 0.2*degree)  # x1,y1,x2,y2
    # IntensityDataFunctions.addRectangularMask(real_data, -0.1*degree, 1.0*degree, 0.1*degree, 1.2*degree)  # x1,y1,x2,y2

    # another mask example: one big square with two excluded areas on it
    # IntensityDataFunctions.addRectangularMask(real_data, -0.6*degree, 0.0*degree, 0.6*degree, 1.5*degree, True)
    # IntensityDataFunctions.addRectangularMask(real_data, -0.1*degree, 0.1*degree, 0.1*degree, 0.2*degree)
    # IntensityDataFunctions.addEllipticMask(real_data, 0.0*degree, 1.2*degree, 0.3*degree, 0.2*degree)

    fit_suite.addSimulationAndRealData(simulation, real_data)

    fit_suite.initPrint(10)

    draw_observer = DrawObserver(draw_every=10)
    fit_suite.attachObserver(draw_observer)

    # setting fitting parameters with starting values
    fit_suite.addFitParameter("*/FormFactorCylinder/radius", 6.*nanometer, AttLimits.limited(4., 8.), 0.01*nanometer)
    fit_suite.addFitParameter("*/FormFactorCylinder/height", 9.*nanometer, AttLimits.limited(8., 12.), 0.01*nanometer)

    # running fit
    fit_suite.runFit()


    print "Fitting completed."
    fit_suite.printResults()
    print "chi2:", fit_suite.getMinimizer().getMinValue()
    fitpars = fit_suite.getFitParameters()
    for i in range(0, fitpars.size()):
        print fitpars[i].getName(), fitpars[i].getValue(), fitpars[i].getError()


if __name__ == '__main__':
    run_fitting()

    plt.ioff()
    plt.show()

