// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ImportDataWidgets/RealDataMaskWidget.h
//! @brief     Defines class RealDataMaskWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef REALDATAMASKWIDGET_H
#define REALDATAMASKWIDGET_H

#include "SessionItemWidget.h"

class SessionItem;
class MaskEditor;
class IntensityDataItem;
class QAction;
class MaskContainerItem;

//! The RealDataMaskWidget class provides mask editing for RealDataItem on ImportDataView.

class BA_CORE_API_ RealDataMaskWidget : public SessionItemWidget
{
    Q_OBJECT

public:
    RealDataMaskWidget(QWidget* parent = 0);

    QList<QAction*> actionList();

protected:
    void subscribeToItem();
    void unsubscribeFromItem();

private:
    IntensityDataItem* intensityDataItem();
    MaskContainerItem* maskContainer(IntensityDataItem* intensityData);

    MaskEditor* m_maskEditor;
};

#endif // REALDATAMASKWIDGET_H

