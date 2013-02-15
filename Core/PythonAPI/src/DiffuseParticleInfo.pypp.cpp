// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
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
#include "Simulation.h"
#include "Transform3D.h"
#include "Units.h"
#include "Types.h"
#include "DiffuseParticleInfo.pypp.h"

namespace bp = boost::python;

struct DiffuseParticleInfo_wrapper : DiffuseParticleInfo, bp::wrapper< DiffuseParticleInfo > {

    virtual ::DiffuseParticleInfo * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->DiffuseParticleInfo::clone(  );
        }
    }
    
    ::DiffuseParticleInfo * default_clone(  ) const  {
        return DiffuseParticleInfo::clone( );
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

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ICompositeSample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ICompositeSample::getCompositeSample( );
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

    virtual void print_structure(  ) {
        if( bp::override func_print_structure = this->get_override( "print_structure" ) )
            func_print_structure(  );
        else{
            this->ISample::print_structure(  );
        }
    }
    
    void default_print_structure(  ) {
        ISample::print_structure( );
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

    virtual ::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ICompositeSample::size(  );
        }
    }
    
    ::size_t default_size(  ) const  {
        return ICompositeSample::size( );
    }

};

void register_DiffuseParticleInfo_class(){

    bp::class_< DiffuseParticleInfo_wrapper, bp::bases< ParticleInfo >, boost::noncopyable >( "DiffuseParticleInfo", bp::no_init )    
        .def( 
            "clone"
            , (::DiffuseParticleInfo * ( ::DiffuseParticleInfo::* )(  ) const)(&::DiffuseParticleInfo::clone)
            , (::DiffuseParticleInfo * ( DiffuseParticleInfo_wrapper::* )(  ) const)(&DiffuseParticleInfo_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getHeightRange"
            , (double ( ::DiffuseParticleInfo::* )(  ) const)( &::DiffuseParticleInfo::getHeightRange ) )    
        .def( 
            "getNumberPerMeso"
            , (double ( ::DiffuseParticleInfo::* )(  ) const)( &::DiffuseParticleInfo::getNumberPerMeso ) )    
        .def( 
            "scaleAbundance"
            , (void ( ::DiffuseParticleInfo::* )( double ) )( &::DiffuseParticleInfo::scaleAbundance )
            , ( bp::arg("factor") ) )    
        .def( 
            "scaleNumberPerMeso"
            , (void ( ::DiffuseParticleInfo::* )( double ) )( &::DiffuseParticleInfo::scaleNumberPerMeso )
            , ( bp::arg("factor") ) )    
        .def( 
            "setHeightRange"
            , (void ( ::DiffuseParticleInfo::* )( double ) )( &::DiffuseParticleInfo::setHeightRange )
            , ( bp::arg("height_range") ) )    
        .def( 
            "setNumberPerMeso"
            , (void ( ::DiffuseParticleInfo::* )( double ) )( &::DiffuseParticleInfo::setNumberPerMeso )
            , ( bp::arg("n") ) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( DiffuseParticleInfo_wrapper::* )(  ) )(&DiffuseParticleInfo_wrapper::default_areParametersChanged) )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( DiffuseParticleInfo_wrapper::* )(  ) const)(&DiffuseParticleInfo_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "getCompositeSample"
            , (::ICompositeSample * ( ::ICompositeSample::* )(  ) )(&::ICompositeSample::getCompositeSample)
            , (::ICompositeSample * ( DiffuseParticleInfo_wrapper::* )(  ) )(&DiffuseParticleInfo_wrapper::default_getCompositeSample)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getCompositeSample"
            , (::ICompositeSample const * ( ::ICompositeSample::* )(  ) const)(&::ICompositeSample::getCompositeSample)
            , (::ICompositeSample const * ( DiffuseParticleInfo_wrapper::* )(  ) const)(&DiffuseParticleInfo_wrapper::default_getCompositeSample)
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( DiffuseParticleInfo_wrapper::* )(  ) const)(&DiffuseParticleInfo_wrapper::default_printParameters) )    
        .def( 
            "print_structure"
            , (void ( ::ISample::* )(  ) )(&::ISample::print_structure)
            , (void ( DiffuseParticleInfo_wrapper::* )(  ) )(&DiffuseParticleInfo_wrapper::default_print_structure) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( DiffuseParticleInfo_wrapper::* )(  ) )(&DiffuseParticleInfo_wrapper::default_setParametersAreChanged) )    
        .def( 
            "size"
            , (::size_t ( ::ICompositeSample::* )(  ) const)(&::ICompositeSample::size)
            , (::size_t ( DiffuseParticleInfo_wrapper::* )(  ) const)(&DiffuseParticleInfo_wrapper::default_size) );

}
