// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/FitWidgets/RealDataWidget.cpp
//! @brief     Implements class RealDataWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "RealDataWidget.h"
#include <QDebug>
#include <QVBoxLayout>



RealDataWidget::RealDataWidget(QWidget *parent)
    : QWidget(parent)
{

    QColor bgColor(255,255,255,255);
    QPalette palette;
    palette.setColor(QPalette::Background, bgColor);
    setAutoFillBackground(true);
    setPalette(palette);


    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->setMargin(0);
    vlayout->setSpacing(0);
    //vlayout->addWidget(m_treeView);
    //vlayout->addStretch();
    this->setLayout(vlayout);

}