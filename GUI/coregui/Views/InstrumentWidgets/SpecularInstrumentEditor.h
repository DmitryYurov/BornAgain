// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/InstrumentWidgets/SpecularInstrumentEditor.h
//! @brief     Defines class SpecularInstrumentEditor
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef SPECULARINSTRUMENTEDITOR_H_
#define SPECULARINSTRUMENTEDITOR_H_

#include "SessionItemWidget.h"

class SpecularInstrumentItem;
class SpecularBeamEditor;
class EnvironmentEditor;
class PolarizationAnalysisEditor;
class ColumnResizer;
class QVBoxLayout;

class BA_CORE_API_ SpecularInstrumentEditor : public SessionItemWidget
{
    Q_OBJECT

public:
    SpecularInstrumentEditor(QWidget* parent = nullptr);

protected:
    void subscribeToItem();

private:
    SpecularInstrumentItem* instrumentItem();
    ColumnResizer* m_columnResizer;
    SpecularBeamEditor* m_beamEditor;
    EnvironmentEditor* m_environmentEditor;
    PolarizationAnalysisEditor* m_polarizationAnalysisEditor;
};

#endif /* SPECULARINSTRUMENTEDITOR_H_ */
