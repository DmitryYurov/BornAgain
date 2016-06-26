// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/InstrumentItem.h
//! @brief     Declares class InstrumentItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef INSTRUMENT_ITEM_H
#define INSTRUMENT_ITEM_H

#include "SessionItem.h"

class BeamItem;
class DetectorItem;

class BA_CORE_API_ InstrumentItem : public SessionItem
{
public:
    explicit InstrumentItem();

    BeamItem *getBeamItem() const;

    DetectorItem *getDetectorItem() const;
};

#endif
