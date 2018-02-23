// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/InstrumentItems.h
//! @brief     Defines InstrumentItems classes
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef INSTRUMENTITEMS_H
#define INSTRUMENTITEMS_H

#include "SessionItem.h"

class BackgroundItem;
class BeamItem;
class DetectorItem;
class MaskContainerItem;
class GroupItem;
class Instrument;

class BA_CORE_API_ InstrumentItem : public SessionItem
{
public:
    static const QString P_IDENTIFIER;
    static const QString P_BEAM;
    static const QString P_BACKGROUND;

    QStringList translateList(const QStringList& list) const override;

    BeamItem* beamItem() const;
    BackgroundItem* backgroundItem() const;
    GroupItem* backgroundGroup();

    virtual std::unique_ptr<Instrument> createInstrument() const = 0;

protected:
    explicit InstrumentItem(const QString& modelType);
};

class BA_CORE_API_ SpecularInstrumentItem : public InstrumentItem
{
public:
    static const QString P_ALPHA_AXIS;

    SpecularInstrumentItem();

    std::unique_ptr<Instrument> createInstrument() const override;
};

class BA_CORE_API_ Instrument2DItem : public InstrumentItem
{
public:
    virtual ~Instrument2DItem();

    static const QString P_DETECTOR;

    DetectorItem* detectorItem() const;
    GroupItem* detectorGroup();

    void setDetectorGroup(const QString& modelType);

    void clearMasks();

    void importMasks(MaskContainerItem* maskContainer);

    std::unique_ptr<Instrument> createInstrument() const override;

protected:
    explicit Instrument2DItem(const QString& modelType);
};

class BA_CORE_API_ GISASInstrumentItem : public Instrument2DItem
{
public:
    GISASInstrumentItem();
};

class BA_CORE_API_ OffSpecInstrumentItem : public Instrument2DItem
{
public:
    static const QString P_ALPHA_AXIS;

    OffSpecInstrumentItem();
};

#endif // INSTRUMENTITEMS_H