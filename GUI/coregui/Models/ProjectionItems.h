// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/ProjectionItems.h
//! @brief     Defines items related to projections over color map.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef PROJECTIONITEMS_H
#define PROJECTIONITEMS_H

#include "SessionItem.h"

//! A container to hold ProjectionItems, intended to store projections of color map on X, Y axes.

class BA_CORE_API_  ProjectionContainerItem : public SessionItem
{
public:
    ProjectionContainerItem();
};

#endif
