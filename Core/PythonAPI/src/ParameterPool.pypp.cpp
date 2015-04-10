// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "ParameterPool.pypp.h"

namespace bp = boost::python;

struct ParameterPool_wrapper : ParameterPool, bp::wrapper< ParameterPool > {

    ParameterPool_wrapper( )
    : ParameterPool( )
      , bp::wrapper< ParameterPool >(){
        // null constructor
    m_pyobj = 0;
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

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_ParameterPool_class(){

    { //::ParameterPool
        typedef bp::class_< ParameterPool_wrapper, bp::bases< ICloneable >, std::auto_ptr< ParameterPool_wrapper >, boost::noncopyable > ParameterPool_exposer_t;
        ParameterPool_exposer_t ParameterPool_exposer = ParameterPool_exposer_t( "ParameterPool", bp::init< >() );
        bp::scope ParameterPool_scope( ParameterPool_exposer );
        { //::ParameterPool::addParameter
        
            typedef bool ( ::ParameterPool::*addParameter_function_type)( ::std::string const &,::RealParameterWrapper ) ;
            
            ParameterPool_exposer.def( 
                "addParameter"
                , addParameter_function_type( &::ParameterPool::addParameter )
                , ( bp::arg("name"), bp::arg("par") ) );
        
        }
        { //::ParameterPool::clear
        
            typedef void ( ::ParameterPool::*clear_function_type)(  ) ;
            
            ParameterPool_exposer.def( 
                "clear"
                , clear_function_type( &::ParameterPool::clear ) );
        
        }
        { //::ParameterPool::clone
        
            typedef ::ParameterPool * ( ::ParameterPool::*clone_function_type)(  ) const;
            typedef ::ParameterPool * ( ParameterPool_wrapper::*default_clone_function_type)(  ) const;
            
            ParameterPool_exposer.def( 
                "clone"
                , clone_function_type(&::ParameterPool::clone)
                , default_clone_function_type(&ParameterPool_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ParameterPool::cloneWithPrefix
        
            typedef ::ParameterPool * ( ::ParameterPool::*cloneWithPrefix_function_type)( ::std::string const & ) const;
            
            ParameterPool_exposer.def( 
                "cloneWithPrefix"
                , cloneWithPrefix_function_type( &::ParameterPool::cloneWithPrefix )
                , ( bp::arg("prefix") )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ParameterPool::getParameter
        
            typedef ::RealParameterWrapper ( ::ParameterPool::*getParameter_function_type)( ::std::string const & ) const;
            
            ParameterPool_exposer.def( 
                "getParameter"
                , getParameter_function_type( &::ParameterPool::getParameter )
                , ( bp::arg("name") ) );
        
        }
        { //::ParameterPool::setMatchedParametersValue
        
            typedef int ( ::ParameterPool::*setMatchedParametersValue_function_type)( ::std::string const &,double ) ;
            
            ParameterPool_exposer.def( 
                "setMatchedParametersValue"
                , setMatchedParametersValue_function_type( &::ParameterPool::setMatchedParametersValue )
                , ( bp::arg("wildcards"), bp::arg("value") ) );
        
        }
        { //::ParameterPool::setParameterValue
        
            typedef bool ( ::ParameterPool::*setParameterValue_function_type)( ::std::string const &,double ) ;
            
            ParameterPool_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type( &::ParameterPool::setParameterValue )
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::ParameterPool::size
        
            typedef ::size_t ( ::ParameterPool::*size_function_type)(  ) const;
            
            ParameterPool_exposer.def( 
                "size"
                , size_function_type( &::ParameterPool::size ) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( ParameterPool_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            ParameterPool_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&ParameterPool_wrapper::default_transferToCPP) );
        
        }
    }

}
