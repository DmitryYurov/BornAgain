// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/JobWidgets/JobPropertiesWidget.h
//! @brief     Defines class JobPropertiesWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef JOBPROPERTIESWIDGET_H
#define JOBPROPERTIESWIDGET_H

#include "SessionItemWidget.h"

class JobItem;
class QTextEdit;
class QTabWidget;
class ComponentEditor;

//! The JobPropertiesWidget class holds component editor for JobItem. Part of JobSelectorWidget,
//! resides at lower left corner of JobView.

class BA_CORE_API_ JobPropertiesWidget : public SessionItemWidget
{
    Q_OBJECT
public:
    enum ETabId { JOB_PROPERTIES, JOB_COMMENTS };
    explicit JobPropertiesWidget(QWidget* parent = nullptr);

    QSize sizeHint() const { return QSize(64, 256); }
    QSize minimumSizeHint() const { return QSize(64, 64); }

protected:
    void subscribeToItem();
    void unsubscribeFromItem();
    void contextMenuEvent(QContextMenuEvent *);

private slots:
    void onTextChanged();

private:
    void updateItem();
    JobItem* jobItem();

    QTabWidget* m_tabWidget;
    ComponentEditor* m_componentEditor;
    QTextEdit* m_commentsEditor;
    bool m_block_update;
};

#endif // JOBPROPERTIESWIDGET_H
