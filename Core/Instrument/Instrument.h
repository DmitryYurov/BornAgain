// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Instrument/Instrument.h
//! @brief     Declares class Instrument.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "IParameterized.h" // inheriting from
#include "Beam.h"
#include "IDetector2D.h"
#include <memory>

template<class T> class OutputData;
class IAxis;
class IResolutionFunction2D;
class SimulationElement;

//! @class Instrument
//! @ingroup simulation_internal
//! @brief Assembles beam, detector and their relative positions wrt the sample.

class BA_CORE_API_ Instrument : public IParameterized
{
public:
    Instrument();
    Instrument(const Instrument& other);
    Instrument& operator=(const Instrument& other);

    virtual ~Instrument();

    //! Returns the beam data
    Beam getBeam() const { return m_beam; }

    //! Sets the beam data
    void setBeam(const Beam& beam);

    //! Sets the beam wavelength and incoming angles
    void setBeamParameters(double wavelength, double alpha_i, double phi_i);

    //! Sets the beam's intensity
    void setBeamIntensity(double intensity);

    //! Sets the beam's polarization according to the given Bloch vector
    void setBeamPolarization(const kvector_t bloch_vector);

    //! Returns the beam's intensity
    double getBeamIntensity() const;

    //! Returns the detector data
    const IDetector2D* getDetector() const;
    IDetector2D* getDetector();

    //! Returns a detector axis
    const IAxis& getDetectorAxis(size_t index) const;

    //! Returns the detector's dimension
    size_t getDetectorDimension() const;

    //! Sets the detector (axes can be overwritten later)
    void setDetector(const IDetector2D& detector);

    //! Sets detector parameters using axes of output data
    void matchDetectorAxes(const OutputData<double>& output_data);

    //! Sets detector parameters using angle ranges
    void setDetectorParameters(size_t n_x, double x_min, double x_max,
                               size_t n_y, double y_min, double y_max);

    //! Sets detector parameters using axes
    void setDetectorAxes(const IAxis& axis0, const IAxis& axis1);

    //! Sets detector resolution function
    void setDetectorResolutionFunction(IResolutionFunction2D* p_resolution_function);
    void setDetectorResolutionFunction(const IResolutionFunction2D& p_resolution_function);

    //! Sets the polarization analyzer characteristics of the detector
    void setAnalyzerProperties(const kvector_t direction, double efficiency,
                               double total_transmission=1.0);

    //! apply the detector resolution to the given intensity map
    void applyDetectorResolution(OutputData<double>* p_intensity_map) const;

    //! Returns clone of the intensity map with detector resolution applied,
    //! axes of map will be in requested units
    OutputData<double>* getDetectorIntensity(
        const OutputData<double>& data,
        IDetector2D::EAxesUnits units_type=IDetector2D::DEFAULT) const;

#ifndef SWIG
    //! Create a vector of SimulationElement objects according to the beam, detector and its mask
    std::vector<SimulationElement> createSimulationElements();
#endif

    //! Adds parameters from local pool to external pool and recursively calls its direct children.
    virtual std::string addParametersToExternalPool(
        std::string path, ParameterPool* external_pool, int copy_number = -1) const;

    //! init detector with beam settings
    void initDetector();

protected:
    virtual void print(std::ostream& ostr) const;

    //! Registers some class members for later access via parameter pool
    virtual void init_parameters() {}

    std::unique_ptr<IDetector2D> mP_detector;
    Beam m_beam; // TODO -> pointer
};

#endif // INSTRUMENT_H