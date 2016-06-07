

// fix SWIG warning 509, certain C++ overloads create ambiguities in Python
%ignore ParticleLayout::addInterferenceFunction(IInterferenceFunction *);
%ignore ParticleLayout::addInterferenceFunction(const IInterferenceFunction *);
%ignore MesoCrystal::MesoCrystal(IClusteredParticles*, IFormFactor*);
%ignore MesoCrystal::MesoCrystal(const IClusteredParticles*, const IFormFactor*);
%ignore Instrument::setDetectorResolutionFunction(IResolutionFunction2D*);
%ignore Instrument::setDetectorResolutionFunction(const IResolutionFunction2D*);


// used to return numpy array
/*
%ignore Histogram1D::getBinCenters() const;
%ignore Histogram1D::getBinValues() const;
%ignore Histogram1D::getBinErrors() const;
*/
// need to fix SWIG error, PI2 multiply defined
%ignore Units::PI2;


// problems with BasicVector3D.h
namespace Geometry {

    %ignore BasicVector3D<std::complex<double> >::complex() const;
    %ignore BasicVector3D<std::complex<double> >::angle(const BasicVector3D<std::complex<double> >&) const;
    %ignore BasicVector3D<std::complex<double> >::perp2(const BasicVector3D<std::complex<double> >&) const;
    %ignore BasicVector3D<std::complex<double> >::sin2Theta() const;
    %ignore BasicVector3D<std::complex<double> >::cosTheta() const;
    %ignore BasicVector3D<std::complex<double> >::theta() const;
    %ignore BasicVector3D<std::complex<double> >::phi() const;
    %ignore BasicVector3D<std::complex<double> >::rotated(double, const BasicVector3D<std::complex<double> >&) const;
    %ignore BasicVector3D<std::complex<double> >::rotatedX(double) const;
    %ignore BasicVector3D<std::complex<double> >::rotatedY(double) const;
    %ignore BasicVector3D<std::complex<double> >::rotatedZ(double) const;

    %ignore BasicVector3D<std::complex<double> >::cross(const BasicVector3D<std::complex<double> >&) const;
    %ignore BasicVector3D<std::complex<double> >::perp(const BasicVector3D<std::complex<double> >&) const;

    %ignore BasicVector3D<double>::rotated(double, const BasicVector3D<double>&) const;
    %ignore BasicVector3D<double>::rotatedX(double) const;
    %ignore BasicVector3D<double>::rotatedY(double) const;
    %ignore BasicVector3D<double>::rotatedZ(double) const;


}


// need this to play nicely with ctypes
%ignore ISampleBuilder::registerParameter(const std::string &, double*, const AttLimits&);
%ignore ISampleBuilder::registerParameter(const std::string &, double*);
%ignore IParameterized::addParametersToExternalPool(std::string, ParameterPool*, int) const;
%ignore IParameterized::addParametersToExternalPool(std::string, ParameterPool*) const;
%ignore ISampleBuilder::addParametersToExternalPool(std::string, ParameterPool*, int) const;
%ignore ISampleBuilder::addParametersToExternalPool(std::string, ParameterPool*) const;

// ignored to avoid error (todo: check whether this is really necessary)
%ignore Crystal::getTransformedLattice(const IRotation *) const;



// taken from dev-tools/python-bindings/settings_fit.py
%ignore FitSuite::setOptions(const FitOptions&);
%ignore FitSuite::getOptions();