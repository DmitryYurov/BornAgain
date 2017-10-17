// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/FitWidgets/FitSuiteManager.cpp
//! @brief     Implements class FitSuiteManager
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "FitSuiteManager.h"
#include "RunFitManager.h"
#include "GUIFitObserver.h"
#include "JobItem.h"
#include "IntensityDataItem.h"

FitSuiteManager::FitSuiteManager(QObject* parent)
    : QObject(parent)
    , m_runFitManager(new RunFitManager(this))
    , m_observer(new GUIFitObserver)
{
    connect(m_observer.get(), &GUIFitObserver::plotsUpdate, this, &FitSuiteManager::onPlotsUpdate);
    connect(m_runFitManager, &RunFitManager::fittingError, this, &FitSuiteManager::fittingError);
}

void FitSuiteManager::setItem(JobItem* item)
{
    m_jobItem = item;
}

void FitSuiteManager::startFitting()
{
    if (!m_jobItem)
        return;

}

RunFitManager* FitSuiteManager::runFitManager()
{
    return m_runFitManager;
}

std::shared_ptr<GUIFitObserver> FitSuiteManager::fitObserver()
{
    return m_observer;
}

void FitSuiteManager::onStopFittingRequest()
{
    m_runFitManager->interruptFitting();
}

void FitSuiteManager::onPlotsUpdate()
{
    m_jobItem->intensityDataItem()->setRawDataVector(m_observer->simulationData());
    m_observer->finishedPlotting();
}
