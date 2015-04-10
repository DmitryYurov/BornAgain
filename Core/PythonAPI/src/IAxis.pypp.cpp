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
#include "IAxis.pypp.h"

namespace bp = boost::python;

struct IAxis_wrapper : IAxis, bp::wrapper< IAxis > {

    IAxis_wrapper(::std::string const & name )
    : IAxis( name )
      , bp::wrapper< IAxis >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::IAxis * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual bool contains( double value ) const  {
        if( bp::override func_contains = this->get_override( "contains" ) )
            return func_contains( value );
        else{
            return this->IAxis::contains( value );
        }
    }
    
    bool default_contains( double value ) const  {
        return IAxis::contains( value );
    }

    virtual ::IAxis * createClippedAxis( double arg0, double arg1 ) const  {
        if( bp::override func_createClippedAxis = this->get_override( "createClippedAxis" ) )
            return func_createClippedAxis( arg0, arg1 );
        else{
            return this->IAxis::createClippedAxis( arg0, arg1 );
        }
    }
    
    ::IAxis * default_createClippedAxis( double arg0, double arg1 ) const  {
        return IAxis::createClippedAxis( arg0, arg1 );
    }

    virtual ::IAxis * createDoubleBinSize(  ) const  {
        if( bp::override func_createDoubleBinSize = this->get_override( "createDoubleBinSize" ) )
            return func_createDoubleBinSize(  );
        else{
            return this->IAxis::createDoubleBinSize(  );
        }
    }
    
    ::IAxis * default_createDoubleBinSize(  ) const  {
        return IAxis::createDoubleBinSize( );
    }

    virtual ::size_t findClosestIndex( double value ) const {
        bp::override func_findClosestIndex = this->get_override( "findClosestIndex" );
        return func_findClosestIndex( value );
    }

    virtual ::Bin1D getBin( ::size_t index ) const {
        bp::override func_getBin = this->get_override( "getBin" );
        return func_getBin( index );
    }

    virtual ::std::vector< double > getBinBoundaries(  ) const  {
        if( bp::override func_getBinBoundaries = this->get_override( "getBinBoundaries" ) )
            return func_getBinBoundaries(  );
        else{
            return this->IAxis::getBinBoundaries(  );
        }
    }
    
    ::std::vector< double > default_getBinBoundaries(  ) const  {
        return IAxis::getBinBoundaries( );
    }

    virtual ::std::vector< double > getBinCenters(  ) const  {
        if( bp::override func_getBinCenters = this->get_override( "getBinCenters" ) )
            return func_getBinCenters(  );
        else{
            return this->IAxis::getBinCenters(  );
        }
    }
    
    ::std::vector< double > default_getBinCenters(  ) const  {
        return IAxis::getBinCenters( );
    }

    virtual double getMax(  ) const {
        bp::override func_getMax = this->get_override( "getMax" );
        return func_getMax(  );
    }

    virtual double getMin(  ) const {
        bp::override func_getMin = this->get_override( "getMin" );
        return func_getMin(  );
    }

    virtual ::size_t getSize(  ) const {
        bp::override func_getSize = this->get_override( "getSize" );
        return func_getSize(  );
    }

    virtual double operator[]( ::size_t index ) const {
        bp::override func___getitem__ = this->get_override( "__getitem__" );
        return func___getitem__( index );
    }

    virtual void print( ::std::ostream & ostr ) const {
        bp::override func_print = this->get_override( "print" );
        func_print( boost::ref(ostr) );
    }

    PyObject* m_pyobj;

};

void register_IAxis_class(){

    { //::IAxis
        typedef bp::class_< IAxis_wrapper, std::auto_ptr< IAxis_wrapper >, boost::noncopyable > IAxis_exposer_t;
        IAxis_exposer_t IAxis_exposer = IAxis_exposer_t( "IAxis", bp::init< std::string const & >(( bp::arg("name") )) );
        bp::scope IAxis_scope( IAxis_exposer );
        { //::IAxis::clone
        
            typedef ::IAxis * ( ::IAxis::*clone_function_type)(  ) const;
            
            IAxis_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::IAxis::clone) )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IAxis::contains
        
            typedef bool ( ::IAxis::*contains_function_type)( double ) const;
            typedef bool ( IAxis_wrapper::*default_contains_function_type)( double ) const;
            
            IAxis_exposer.def( 
                "contains"
                , contains_function_type(&::IAxis::contains)
                , default_contains_function_type(&IAxis_wrapper::default_contains)
                , ( bp::arg("value") ) );
        
        }
        { //::IAxis::createClippedAxis
        
            typedef ::IAxis * ( ::IAxis::*createClippedAxis_function_type)( double,double ) const;
            typedef ::IAxis * ( IAxis_wrapper::*default_createClippedAxis_function_type)( double,double ) const;
            
            IAxis_exposer.def( 
                "createClippedAxis"
                , createClippedAxis_function_type(&::IAxis::createClippedAxis)
                , default_createClippedAxis_function_type(&IAxis_wrapper::default_createClippedAxis)
                , ( bp::arg("arg0"), bp::arg("arg1") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IAxis::createDoubleBinSize
        
            typedef ::IAxis * ( ::IAxis::*createDoubleBinSize_function_type)(  ) const;
            typedef ::IAxis * ( IAxis_wrapper::*default_createDoubleBinSize_function_type)(  ) const;
            
            IAxis_exposer.def( 
                "createDoubleBinSize"
                , createDoubleBinSize_function_type(&::IAxis::createDoubleBinSize)
                , default_createDoubleBinSize_function_type(&IAxis_wrapper::default_createDoubleBinSize)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IAxis::findClosestIndex
        
            typedef ::size_t ( ::IAxis::*findClosestIndex_function_type)( double ) const;
            
            IAxis_exposer.def( 
                "findClosestIndex"
                , bp::pure_virtual( findClosestIndex_function_type(&::IAxis::findClosestIndex) )
                , ( bp::arg("value") ) );
        
        }
        { //::IAxis::getBin
        
            typedef ::Bin1D ( ::IAxis::*getBin_function_type)( ::size_t ) const;
            
            IAxis_exposer.def( 
                "getBin"
                , bp::pure_virtual( getBin_function_type(&::IAxis::getBin) )
                , ( bp::arg("index") ) );
        
        }
        { //::IAxis::getBinBoundaries
        
            typedef ::std::vector< double > ( ::IAxis::*getBinBoundaries_function_type)(  ) const;
            typedef ::std::vector< double > ( IAxis_wrapper::*default_getBinBoundaries_function_type)(  ) const;
            
            IAxis_exposer.def( 
                "getBinBoundaries"
                , getBinBoundaries_function_type(&::IAxis::getBinBoundaries)
                , default_getBinBoundaries_function_type(&IAxis_wrapper::default_getBinBoundaries) );
        
        }
        { //::IAxis::getBinCenters
        
            typedef ::std::vector< double > ( ::IAxis::*getBinCenters_function_type)(  ) const;
            typedef ::std::vector< double > ( IAxis_wrapper::*default_getBinCenters_function_type)(  ) const;
            
            IAxis_exposer.def( 
                "getBinCenters"
                , getBinCenters_function_type(&::IAxis::getBinCenters)
                , default_getBinCenters_function_type(&IAxis_wrapper::default_getBinCenters) );
        
        }
        { //::IAxis::getMax
        
            typedef double ( ::IAxis::*getMax_function_type)(  ) const;
            
            IAxis_exposer.def( 
                "getMax"
                , bp::pure_virtual( getMax_function_type(&::IAxis::getMax) ) );
        
        }
        { //::IAxis::getMin
        
            typedef double ( ::IAxis::*getMin_function_type)(  ) const;
            
            IAxis_exposer.def( 
                "getMin"
                , bp::pure_virtual( getMin_function_type(&::IAxis::getMin) ) );
        
        }
        { //::IAxis::getName
        
            typedef ::std::string ( ::IAxis::*getName_function_type)(  ) const;
            
            IAxis_exposer.def( 
                "getName"
                , getName_function_type( &::IAxis::getName ) );
        
        }
        { //::IAxis::getSize
        
            typedef ::size_t ( ::IAxis::*getSize_function_type)(  ) const;
            
            IAxis_exposer.def( 
                "getSize"
                , bp::pure_virtual( getSize_function_type(&::IAxis::getSize) ) );
        
        }
        { //::IAxis::operator[]
        
            typedef double ( ::IAxis::*__getitem___function_type)( ::size_t ) const;
            
            IAxis_exposer.def( 
                "__getitem__"
                , bp::pure_virtual( __getitem___function_type(&::IAxis::operator[]) )
                , ( bp::arg("index") ) );
        
        }
        { //::IAxis::print
        
            typedef void ( IAxis_wrapper::*print_function_type)( ::std::ostream & ) const;
            
            IAxis_exposer.def( 
                "print"
                , print_function_type( &IAxis_wrapper::print )
                , ( bp::arg("ostr") ) );
        
        }
        { //::IAxis::setName
        
            typedef void ( ::IAxis::*setName_function_type)( ::std::string ) ;
            
            IAxis_exposer.def( 
                "setName"
                , setName_function_type( &::IAxis::setName )
                , ( bp::arg("name") ) );
        
        }
        IAxis_exposer.def( bp::self != bp::self );
        IAxis_exposer.def( bp::self_ns::str( bp::self ) );
        IAxis_exposer.def( bp::self == bp::self );
    }

}
