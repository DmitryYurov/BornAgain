// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/VectorItem.h
//! @brief     Defines class VectorItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef VECTORITEM_H
#define VECTORITEM_H

#include "SessionItem.h"
#include "Vectors3D.h"

class BA_CORE_API_ VectorItem : public SessionItem
{

public:
    static const QString P_X;
    static const QString P_Y;
    static const QString P_Z;
    VectorItem();

    kvector_t getVector() const;

private:
    void updateLabel();
};

#endif // VECTORITEM_H

