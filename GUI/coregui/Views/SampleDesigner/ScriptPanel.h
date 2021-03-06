// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/SampleDesigner/ScriptPanel.h
//! @brief     Defines class SampleDesigner
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef SCRIPTPANEL_H
#define SCRIPTPANEL_H

#include "InfoPanel.h"

class SampleModel;
class InstrumentModel;
class PySampleWidget;

//! Resides at the bottom of SampleView and displays a Python script.

class BA_CORE_API_ ScriptPanel : public InfoPanel
{
    Q_OBJECT

public:
    explicit ScriptPanel(QWidget* parent = nullptr);

    void setSampleModel(SampleModel* sampleModel);
    void setInstrumentModel(InstrumentModel* instrumentModel);

private:
    PySampleWidget* m_pySampleWidget;
};

#endif // SCRIPTPANEL_H
