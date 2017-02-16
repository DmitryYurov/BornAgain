// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/JobWidgets/IntensityProjectionsWidget.h
//! @brief     Defines class IntensityProjectionsWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef JOBPROJECTIONSWIDGET_H
#define JOBPROJECTIONSWIDGET_H

#include "SessionItemWidget.h"

class IntensityDataCanvas;
class ProjectionCanvas;
class QSplitter;
class IntensityDataItem;
class ProjectionContainerItem;

namespace Manhattan { class MiniSplitter; }

//! A common widget to display color map (IntensityDataCanvas) and properties
//! (IntensityDataPropertyWidget) of intensity data item.

class BA_CORE_API_ JobProjectionsWidget : public SessionItemWidget
{
    Q_OBJECT

public:
    JobProjectionsWidget(QWidget* parent = 0);

    void setItem(SessionItem* jobItem);

private:
    IntensityDataItem* intensityDataItem();
    ProjectionContainerItem* createProjectionContainer(IntensityDataItem* intensityItem);

    IntensityDataCanvas* m_intensityCanvas;
    ProjectionCanvas* m_projectionCanvas;
    QSplitter* m_splitter;
};

#endif // JOBPROJECTIONSWIDGET_H
