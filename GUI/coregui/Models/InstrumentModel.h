// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/InstrumentModel.h
//! @brief     Defines class InstrumentModel
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef INSTRUMENTMODEL_H
#define INSTRUMENTMODEL_H

#include "SessionModel.h"

class InstrumentItem;

class BA_CORE_API_ InstrumentModel : public SessionModel
{
    Q_OBJECT

public:
    explicit InstrumentModel(QObject *parent = nullptr);
    ~InstrumentModel() override;

    InstrumentModel* createCopy(SessionItem* parent = nullptr) override;
    QVector<SessionItem*> nonXMLData() const override;

    InstrumentItem *instrumentItem();
};

#endif // INSTRUMENTMODEL_H
