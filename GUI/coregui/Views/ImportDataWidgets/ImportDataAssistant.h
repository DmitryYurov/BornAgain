// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ImportDataWidgets/ImportDataAssistant.h
//! @brief     Defines class ImportDataAssistant
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef IMPORTDATAASSISTANT_H
#define IMPORTDATAASSISTANT_H

#include "WinDllMacros.h"
#include <QString>

template <class T> class OutputData;
class RealDataItem;
class GISASInstrumentItem;

//! The ImportDataAssistant class provides utility methods to import data files.

class BA_CORE_API_ ImportDataAssistant
{
public:
    OutputData<double>* importData(QString& baseNameOfLoadedFile);

    static OutputData<double>* createSimplifiedOutputData(const OutputData<double>& data);

    static bool hasSameDimensions(const GISASInstrumentItem* instrumentItem,
                                  const RealDataItem* realDataItem);

    static bool hasSameDimensions(const GISASInstrumentItem* instrumentItem,
                                  const RealDataItem* realDataItem, QString& message);

    static void realDataShape(const RealDataItem* realData, int& nx, int& ny);

    static void detectorShape(const GISASInstrumentItem* instrumentItem, int& nx, int& ny);

    static void setInstrumentShapeToData(GISASInstrumentItem* instrumentItem,
                                         const RealDataItem* realDataItemItem);
};

#endif // IMPORTDATAASSISTANT_H
