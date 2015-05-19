// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/DomainSimulationBuilder.cpp
//! @brief     Implements class DomainSimulationBuilder
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "DomainSimulationBuilder.h"
#include "SampleModel.h"
#include "InstrumentModel.h"
#include "Instrument.h"
#include "InstrumentItem.h"
#include "MultiLayer.h"
#include "MultiLayerItem.h"
#include "BeamItem.h"
#include "DomainObjectBuilder.h"
#include "TransformToDomain.h"
#include "GUIHelpers.h"
#include <QDebug>
#include <boost/scoped_ptr.hpp>


//! Creates domain simulation from sample and instrument models for given names
//! of MultiLayer and Instrument
Simulation *DomainSimulationBuilder::getSimulation(SampleModel *sampleModel,
                                                   const QString &sample_name,
                                                   InstrumentModel *instrumentModel,
                                                   const QString &instrument_name)
{
    Q_ASSERT(sampleModel);
    Q_ASSERT(instrumentModel);
    MultiLayerItem *sampleItem = sampleModel->getMultiLayerItem(sample_name);
    InstrumentItem *instrumentItem = instrumentModel->getInstrumentItem(instrument_name);
    return getSimulation(sampleItem, instrumentItem);
}

//! Creates domain simulation from sample and instrument models. First sample and first instrument
//! in the model will be used, if there are more than one.
Simulation *DomainSimulationBuilder::getSimulation(SampleModel *sampleModel,
                                                   InstrumentModel *instrumentModel)
{
    return getSimulation(sampleModel, QString(), instrumentModel, QString());
}

//! Creates domain simulation from sample and instrument items.
Simulation *DomainSimulationBuilder::getSimulation(MultiLayerItem *sampleItem,
                                                   InstrumentItem *instrumentItem)
{
    if(!sampleItem || !instrumentItem) {
        QString message("DomainSimulationBuilder::getSimulation() -> Error. Either MultiLayerItem "
                        " or InstrumentItem is not defined.");
        throw GUIHelpers::Error(message);
    }

    DomainObjectBuilder builder;

    Simulation *result = new Simulation;
    boost::scoped_ptr<MultiLayer> multilayer(builder.buildMultiLayer(*sampleItem));
    boost::scoped_ptr<Instrument> instrument(builder.buildInstrument(*instrumentItem));

    result->setSample(*multilayer);
    result->setInstrument(*instrument);

    TransformToDomain::addDistributionParametersToSimulation(*instrumentItem->getBeamItem(),
                                                             result);
    return result;
}
