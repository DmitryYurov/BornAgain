// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FitKernel/src/FitSuitePrintObserver.cpp
//! @brief     Implements class FitSuitePrintObserver.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FitSuitePrintObserver.h"
#include "FitSuite.h"


FitSuitePrintObserver::FitSuitePrintObserver(int print_every_nth)
    : IFitObserver(print_every_nth)
{
	m_last_call_time = boost::posix_time::second_clock::local_time();
}

void FitSuitePrintObserver::update(FitSuite *fit_suite)
{
    m_fit_suite = fit_suite;

    printIterationHeader();
    printWallTime();
    printParameters();

    if(fit_suite->isLastIteration()) {
        printFitResults();
    }
}

void FitSuitePrintObserver::printIterationHeader()
{
    std::cout << "FitPrintObserver::update() -> Info."
              << " NCall:" << m_fit_suite->getNCalls()
              << " NStrategy:" << m_fit_suite->getNStrategy()
              << " Chi2:" << std::scientific << std::setprecision(8)
              << m_fit_suite->getFitObjects()->getChiSquaredValue() << std::endl;
}

void FitSuitePrintObserver::printWallTime()
{
    boost::posix_time::time_duration diff = boost::posix_time::microsec_clock::local_time() -
            m_last_call_time;
    std::cout << "Wall time since last call:"
              << std::fixed << std::setprecision(2)
              << diff.total_milliseconds()/1000. << " sec." <<std::endl;
    m_last_call_time = boost::posix_time::microsec_clock::local_time();
}

void FitSuitePrintObserver::printParameters()
{
    m_fit_suite->getFitParameters()->printParameters();
}

void FitSuitePrintObserver::printFitResults()
{
    std::cout << "This was the last iteration." << std::endl;
    m_fit_suite->printResults();
    boost::posix_time::time_duration  diff = boost::posix_time::second_clock::local_time() -
            m_start_time;
    std::cout << "Total time spend: "
              << std::fixed << std::setprecision(2)
              << diff.total_milliseconds()/1000. << " sec." <<std::endl;
}
