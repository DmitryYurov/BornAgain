// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Simulation.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "Simulation.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "InterferenceFunctionNone.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Lattice.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "Crystal.h"
#include "ParticleDecoration.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "ParticleInfo.h"
#include "DiffuseParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Transform3D.h"
#include "Units.h"
#include "Types.h"
#include "Experiment.pypp.h"

namespace bp = boost::python;

struct Experiment_wrapper : Simulation, bp::wrapper< Simulation > {

    Experiment_wrapper( )
    : Simulation( )
      , bp::wrapper< Simulation >(){
        // null constructor
    
    }

    virtual ::Simulation * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->Simulation::clone(  );
        }
    }
    
    ::Simulation * default_clone(  ) const  {
        return Simulation::clone( );
    }

    virtual void normalize(  ) {
        if( bp::override func_normalize = this->get_override( "normalize" ) )
            func_normalize(  );
        else{
            this->Simulation::normalize(  );
        }
    }
    
    void default_normalize(  ) {
        Simulation::normalize( );
    }

    virtual void runExperiment(  ) {
        if( bp::override func_runExperiment = this->get_override( "runExperiment" ) )
            func_runExperiment(  );
        else{
            this->Simulation::runSimulation(  );
        }
    }
    
    void default_runExperiment(  ) {
        Simulation::runSimulation( );
    }

    virtual void runExperimentElement( ::size_t index ) {
        if( bp::override func_runExperimentElement = this->get_override( "runExperimentElement" ) )
            func_runExperimentElement( index );
        else{
            this->Simulation::runSimulationElement( index );
        }
    }
    
    void default_runExperimentElement( ::size_t index ) {
        Simulation::runSimulationElement( index );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_Experiment_class(){

    bp::class_< Experiment_wrapper, bp::bases< Simulation >, boost::noncopyable >( "Experiment", bp::init< >() )    
        .def( 
            "clone"
            , (::Simulation * ( ::Simulation::* )(  ) const)(&::Simulation::clone)
            , (::Simulation * ( Experiment_wrapper::* )(  ) const)(&Experiment_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "normalize"
            , (void ( ::Simulation::* )(  ) )(&::Simulation::normalize)
            , (void ( Experiment_wrapper::* )(  ) )(&Experiment_wrapper::default_normalize) )    
        .def( 
            "runExperiment"
            , (void ( ::Simulation::* )(  ) )(&::Simulation::runSimulation)
            , (void ( Experiment_wrapper::* )(  ) )(&Experiment_wrapper::default_runExperiment) )    
        .def( 
            "runExperimentElement"
            , (void ( ::Simulation::* )( ::size_t ) )(&::Simulation::runSimulationElement)
            , (void ( Experiment_wrapper::* )( ::size_t ) )(&Experiment_wrapper::default_runExperimentElement)
            , ( bp::arg("index") ) )    
        .def( 
            "setDetectorParameters"
            , (void ( ::Simulation::* )( ::size_t,double,double,::size_t,double,double,bool ) )( &::Simulation::setDetectorParameters )
            , ( bp::arg("n_phi"), bp::arg("phi_f_min"), bp::arg("phi_f_max"), bp::arg("n_alpha"), bp::arg("alpha_f_min"), bp::arg("alpha_f_max"), bp::arg("isgisaxs_style")=(bool)(false) ) )    
        .def( 
            "setDetectorParameters"
            , (void ( ::Simulation::* )( ::DetectorParameters const & ) )( &::Simulation::setDetectorParameters )
            , ( bp::arg("params") ) )    
        .def( 
            "smearIntensityFromZAxisTilting"
            , (void ( ::Simulation::* )(  ) )( &::Simulation::smearIntensityFromZAxisTilting ) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( Experiment_wrapper::* )(  ) )(&Experiment_wrapper::default_areParametersChanged) )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( Experiment_wrapper::* )(  ) const)(&Experiment_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( Experiment_wrapper::* )(  ) const)(&Experiment_wrapper::default_printParameters) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( Experiment_wrapper::* )(  ) )(&Experiment_wrapper::default_setParametersAreChanged) );

}
