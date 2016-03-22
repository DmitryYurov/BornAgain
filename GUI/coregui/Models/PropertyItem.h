// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/BeamItem.h
//! @brief     Defines class BeamItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PROPERTYITEM_H
#define PROPERTYITEM_H

#include "SessionItem.h"

class BA_CORE_API_ PropertyItem : public SessionItem
{

public:
    PropertyItem();

//    bool setData(int column, const QVariant &data);
};

#endif
