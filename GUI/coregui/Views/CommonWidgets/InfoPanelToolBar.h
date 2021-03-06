// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/CommonWidgets/InfoPanelToolBar.h
//! @brief     Defines class InfoPanelToolBar
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef INFOPANELTOOLBAR_H
#define INFOPANELTOOLBAR_H

#include "StyledToolBar.h"

class QAction;

//! Toolbar for InfoPanel with collapse/expand buttons.

class BA_CORE_API_ InfoPanelToolBar : public QToolBar
{
    Q_OBJECT

public:
    explicit InfoPanelToolBar(QWidget* parent = nullptr);

signals:
    void expandButtonClicked();
    void closeButtonClicked();

public slots:
    void setExpandStatus(bool status);

protected slots:
    void onExpandButtonClicked();

private:
    QAction* m_expandAction;
    QAction* m_closeAction;
    bool m_expanded;
};

#endif // INFOPANELTOOLBAR_H
