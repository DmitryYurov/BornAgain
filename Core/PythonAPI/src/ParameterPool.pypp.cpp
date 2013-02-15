// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "__call_policies.pypp.hpp"
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
#include "ParameterPool.pypp.h"

namespace bp = boost::python;

struct ParameterPool_wrapper : ParameterPool, bp::wrapper< ParameterPool > {

    ParameterPool_wrapper( )
    : ParameterPool( )
      , bp::wrapper< ParameterPool >(){
        // null constructor
    
    }

    virtual ::ParameterPool * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->ParameterPool::clone(  );
        }
    }
    
    ::ParameterPool * default_clone(  ) const  {
        return ParameterPool::clone( );
    }

    static void registerParameter( ::ParameterPool & inst, ::std::string const & name, unsigned int parpointer ){
        inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
    }

};

void register_ParameterPool_class(){

    bp::class_< ParameterPool_wrapper, bp::bases< ICloneable >, boost::noncopyable >( "ParameterPool", bp::init< >() )    
        .def( 
            "addParameter"
            , (bool ( ::ParameterPool::* )( ::std::string const &,::RealParameterWrapper ) )( &::ParameterPool::addParameter )
            , ( bp::arg("name"), bp::arg("par") ) )    
        .def( 
            "clear"
            , (void ( ::ParameterPool::* )(  ) )( &::ParameterPool::clear ) )    
        .def( 
            "clone"
            , (::ParameterPool * ( ::ParameterPool::* )(  ) const)(&::ParameterPool::clone)
            , (::ParameterPool * ( ParameterPool_wrapper::* )(  ) const)(&ParameterPool_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "cloneWithPrefix"
            , (::ParameterPool * ( ::ParameterPool::* )( ::std::string const & ) const)( &::ParameterPool::cloneWithPrefix )
            , ( bp::arg("prefix") )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "fixRatioBetweenParameters"
            , (int ( ::ParameterPool::* )( ::std::string const &,::std::string const &,double ) )( &::ParameterPool::fixRatioBetweenParameters )
            , ( bp::arg("to_change"), bp::arg("source"), bp::arg("ratio") ) )    
        .def( 
            "getParameter"
            , (::RealParameterWrapper ( ::ParameterPool::* )( ::std::string const & ) const)( &::ParameterPool::getParameter )
            , ( bp::arg("name") ) )    
        .def( 
            "registerParameter"
            , (void (*)( ::ParameterPool &,::std::string const &,unsigned int ))( &ParameterPool_wrapper::registerParameter )
            , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) )    
        .def( 
            "setMatchedParametersValue"
            , (int ( ::ParameterPool::* )( ::std::string const &,double ) )( &::ParameterPool::setMatchedParametersValue )
            , ( bp::arg("wildcards"), bp::arg("value") ) )    
        .def( 
            "setParameterValue"
            , (bool ( ::ParameterPool::* )( ::std::string const &,double ) )( &::ParameterPool::setParameterValue )
            , ( bp::arg("name"), bp::arg("value") ) )    
        .def( 
            "size"
            , (::size_t ( ::ParameterPool::* )(  ) const)( &::ParameterPool::size ) )    
        .def( bp::self_ns::str( bp::self ) );

}
