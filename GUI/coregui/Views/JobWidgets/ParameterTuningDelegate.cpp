// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/JobWidgets/ParameterTuningDelegate.cpp
//! @brief     Implements class ParameterTuningDelegate
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "ParameterTuningDelegate.h"
#include "GUIHelpers.h"
#include "ParameterTreeItems.h"
#include "ParameterTuningModel.h"
#include "ModelPath.h"
#include "SessionModel.h"
#include <QDebug>
#include <QPainter>
#include <QPaintDevice>
#include <QApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QStyleOptionSlider>
#include <QAbstractItemModel>
#include <QRect>
#include <QItemSelectionModel>
#include <QHBoxLayout>
#include <QDoubleSpinBox>
#include <cmath>
#include <limits>
#include <iostream>


namespace {
//const double maximum_doublespin_value(1e+20);
const double maximum_doublespin_value(20000.0);
//const double minimum_doublespin_value(0.0);
}

ParameterTuningDelegate::SliderData::SliderData()
    : m_smin(0)
    , m_smax(100)
    , m_rmin(0.0)
    , m_rmax(0.0)
    , m_range_factor(100.0)
{

}

void ParameterTuningDelegate::SliderData::setRangeFactor(double range_factor)
{
    m_range_factor = range_factor;
}

void ParameterTuningDelegate::SliderData::setItemLimits(const AttLimits &item_limits)
{
    m_item_limits = item_limits;
}

int ParameterTuningDelegate::SliderData::value_to_slider(double value)
{
    double dr(0);
    if(value == 0.0) {
        dr = 1.0*m_range_factor/100.;
    } else {
        dr = std::abs(value)*m_range_factor/100.;
    }
    m_rmin = value - dr;
    m_rmax = value + dr;

    if(m_item_limits.hasLowerLimit() && m_rmin < m_item_limits.getLowerLimit())
        m_rmin = m_item_limits.getLowerLimit();

    if(m_item_limits.hasUpperLimit() && m_rmax > m_item_limits.getUpperLimit())
        m_rmax = m_item_limits.getUpperLimit();

    return m_smin + (value - m_rmin)*(m_smax-m_smin)/(m_rmax-m_rmin);
}

double ParameterTuningDelegate::SliderData::slider_to_value(int slider)
{
    return m_rmin + (slider - m_smin)*(m_rmax-m_rmin)/(m_smax - m_smin);
}


ParameterTuningDelegate::ParameterTuningDelegate(QObject *parent)
    : QItemDelegate(parent)
    , m_valueColumn(1)
    , m_slider(0)
    , m_valueBox(0)
    , m_contentWidget(0)
    , m_contentLayout(0)
{

}

void ParameterTuningDelegate::paint(QPainter *painter,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index) const
{
    if (index.column() == m_valueColumn) {

        if(!index.parent().isValid()) return;

        QVariant prop_value = index.model()->data(index, Qt::EditRole);
        if(prop_value.isValid()) {
            int type = GUIHelpers::getVariantType(prop_value);
            if (type == QVariant::Double) {
                double value = prop_value.toDouble();
                QString text(QString::number(value));

                QStyleOptionViewItem myOption = option;
                myOption.displayAlignment = Qt::AlignLeft | Qt::AlignVCenter;

                drawDisplay(painter, myOption, myOption.rect, text);
                drawFocus(painter, myOption, myOption.rect);
                return;
            }
        }
    }
    QItemDelegate::paint(painter, option, index);
}


QWidget *ParameterTuningDelegate::createEditor(QWidget *parent,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &index) const
{
    if (index.column() == m_valueColumn) {
        if(index.parent().isValid() == false) return nullptr;

        double value = index.model()->data(index, Qt::EditRole).toDouble();

        m_currentItem = static_cast<ParameterItem*>(ParameterTuningModel::toSourceIndex(index).internalPointer());

        AttLimits limits = m_currentItem->getLinkedItem()->limits();

        // initializing value box
        m_valueBox = new QDoubleSpinBox();
        m_valueBox->setKeyboardTracking(false);
        m_valueBox->setFixedWidth(80);
        m_valueBox->setDecimals(m_currentItem->getLinkedItem()->decimals());
        m_valueBox->setSingleStep(1./std::pow(10.,m_currentItem->getLinkedItem()->decimals()-1));

        if(limits.hasLowerLimit()) {
            m_valueBox->setMinimum(limits.getLowerLimit());
        } else {
            m_valueBox->setMinimum(-maximum_doublespin_value);
        }

        if(limits.hasUpperLimit()) {
           m_valueBox->setMaximum(limits.getUpperLimit());
        } else {
            m_valueBox->setMaximum(maximum_doublespin_value);
        }

        m_valueBox->setValue(value);
        connect(m_valueBox, SIGNAL(valueChanged(double)),this, SLOT(editorValueChanged(double)));

        // initializing slider
        m_slider = new QSlider(Qt::Horizontal);
        m_slider->setFocusPolicy(Qt::StrongFocus);
        m_slider->setTickPosition(QSlider::NoTicks);
        m_slider->setTickInterval(1);
        m_slider->setSingleStep(1);
        m_slider_data.setItemLimits(limits);
        m_slider->setRange(m_slider_data.m_smin, m_slider_data.m_smax);

        updateSlider(value);

        m_contentWidget = new QWidget(parent);
        m_contentLayout = new QHBoxLayout(parent);
        m_contentLayout->setMargin(0);
        m_contentLayout->setSpacing(0);
        m_contentLayout->addWidget(m_valueBox);
        m_contentLayout->addWidget(m_slider);

        // FIXME CHECK
        // This mapping seems to be necessary only in the case when ModelTuningDelegate is active,
        // when item changes its value from outside. It never happens it seems, so mapper
        // is not necessary.
        // If one outcomment code below, the time life of ModelTuningDelegate will make application
        // crash during the fitting. Check this again and remove commented.
//        m_currentItem->mapper()->setOnValueChange(
//                      [this](){
//              m_valueBox->setValue(m_currentItem->value().toDouble());
//        }, this);

        m_contentWidget->setLayout(m_contentLayout);

        return m_contentWidget;
    } else {
        return QItemDelegate::createEditor(parent, option, index);
    }
}


void ParameterTuningDelegate::updateSlider(double value) const
{
    disconnect(m_slider, SIGNAL(valueChanged(int)),this, SLOT(sliderValueChanged(int)));

    m_slider->setValue(m_slider_data.value_to_slider(value));

    connect(m_slider, SIGNAL(valueChanged(int)),this, SLOT(sliderValueChanged(int)));
}


void ParameterTuningDelegate::sliderValueChanged(int position)
{
    disconnect(m_valueBox, SIGNAL(valueChanged(double)),this, SLOT(editorValueChanged(double)));

    double value = m_slider_data.slider_to_value(position);
    m_valueBox->setValue(value);

    connect(m_valueBox, SIGNAL(valueChanged(double)),this, SLOT(editorValueChanged(double)));
    emitSignals(value);
}


void ParameterTuningDelegate::editorValueChanged(double value)
{
    qDebug() << "ModelTuningDelegate::editorValueChanged " << value;
    disconnect(m_slider, SIGNAL(valueChanged(int)),this, SLOT(sliderValueChanged(int)));

    updateSlider(value);

    connect(m_slider, SIGNAL(valueChanged(int)),this, SLOT(sliderValueChanged(int)));
    emitSignals(value);
}


void ParameterTuningDelegate::setEditorData(QWidget *editor,
                                        const QModelIndex &index) const
{
    if (index.column() == m_valueColumn) {
        //as using custom widget, doing nothing here
    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}


void ParameterTuningDelegate::setModelData(QWidget *editor,
                                       QAbstractItemModel *model,
                                       const QModelIndex &index) const
{
    if (index.column() == m_valueColumn) {

        model->setData(index, m_valueBox->value());

    } else {
        QItemDelegate::setModelData(editor, model, index);
    }
}


void ParameterTuningDelegate::emitSignals(double value)
{
    if(m_currentItem) {
        m_currentItem->setValue(value);
        m_currentItem->propagateValueLink();
        emit currentLinkChanged(m_currentItem);
    }
}

void ParameterTuningDelegate::setSliderRangeFactor(double value)
{
    m_slider_data.setRangeFactor(value);
}