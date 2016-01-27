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
#include "FTDecayFunction1DVoigt.pypp.h"

namespace bp = boost::python;

struct FTDecayFunction1DVoigt_wrapper : FTDecayFunction1DVoigt, bp::wrapper< FTDecayFunction1DVoigt > {

    FTDecayFunction1DVoigt_wrapper(FTDecayFunction1DVoigt const & arg )
    : FTDecayFunction1DVoigt( arg )
      , bp::wrapper< FTDecayFunction1DVoigt >(){
        // copy constructor
        m_pyobj = 0;
    }

    FTDecayFunction1DVoigt_wrapper(double omega, double eta )
    : FTDecayFunction1DVoigt( omega, eta )
      , bp::wrapper< FTDecayFunction1DVoigt >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FTDecayFunction1DVoigt * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FTDecayFunction1DVoigt::clone(  );
        }
    }
    
    ::FTDecayFunction1DVoigt * default_clone(  ) const  {
        return FTDecayFunction1DVoigt::clone( );
    }

    virtual double evaluate( double q ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( q );
        else{
            return this->FTDecayFunction1DVoigt::evaluate( q );
        }
    }
    
    double default_evaluate( double q ) const  {
        return FTDecayFunction1DVoigt::evaluate( q );
    }

    virtual double getEta(  ) const  {
        if( bp::override func_getEta = this->get_override( "getEta" ) )
            return func_getEta(  );
        else{
            return this->FTDecayFunction1DVoigt::getEta(  );
        }
    }
    
    double default_getEta(  ) const  {
        return FTDecayFunction1DVoigt::getEta( );
    }

    PyObject* m_pyobj;

};

void register_FTDecayFunction1DVoigt_class(){

    { //::FTDecayFunction1DVoigt
        typedef bp::class_< FTDecayFunction1DVoigt_wrapper, bp::bases< IFTDecayFunction1D >, std::auto_ptr< FTDecayFunction1DVoigt_wrapper > > FTDecayFunction1DVoigt_exposer_t;
        FTDecayFunction1DVoigt_exposer_t FTDecayFunction1DVoigt_exposer = FTDecayFunction1DVoigt_exposer_t( "FTDecayFunction1DVoigt", "1 dimensional Voigt decay function in reciprocal space.", bp::init< double, double >(( bp::arg("omega"), bp::arg("eta") )) );
        bp::scope FTDecayFunction1DVoigt_scope( FTDecayFunction1DVoigt_exposer );
        { //::FTDecayFunction1DVoigt::clone
        
            typedef ::FTDecayFunction1DVoigt * ( ::FTDecayFunction1DVoigt::*clone_function_type)(  ) const;
            typedef ::FTDecayFunction1DVoigt * ( FTDecayFunction1DVoigt_wrapper::*default_clone_function_type)(  ) const;
            
            FTDecayFunction1DVoigt_exposer.def( 
                "clone"
                , clone_function_type(&::FTDecayFunction1DVoigt::clone)
                , default_clone_function_type(&FTDecayFunction1DVoigt_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FTDecayFunction1DVoigt::evaluate
        
            typedef double ( ::FTDecayFunction1DVoigt::*evaluate_function_type)( double ) const;
            typedef double ( FTDecayFunction1DVoigt_wrapper::*default_evaluate_function_type)( double ) const;
            
            FTDecayFunction1DVoigt_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::FTDecayFunction1DVoigt::evaluate)
                , default_evaluate_function_type(&FTDecayFunction1DVoigt_wrapper::default_evaluate)
                , ( bp::arg("q") ) );
        
        }
        { //::FTDecayFunction1DVoigt::getEta
        
            typedef double ( ::FTDecayFunction1DVoigt::*getEta_function_type)(  ) const;
            typedef double ( FTDecayFunction1DVoigt_wrapper::*default_getEta_function_type)(  ) const;
            
            FTDecayFunction1DVoigt_exposer.def( 
                "getEta"
                , getEta_function_type(&::FTDecayFunction1DVoigt::getEta)
                , default_getEta_function_type(&FTDecayFunction1DVoigt_wrapper::default_getEta) );
        
        }
    }

}
