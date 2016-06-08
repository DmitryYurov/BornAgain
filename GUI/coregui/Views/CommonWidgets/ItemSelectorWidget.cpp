// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/CommonWidgets/ItemSelectorWidget.cpp
//! @brief     Implements class ItemSelectorWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "ItemSelectorWidget.h"
#include "SessionModel.h"
#include "SessionItem.h"
#include <QListView>
#include <QVBoxLayout>
#include <QDebug>

namespace {
const int widget_minimum_size_hint = 64;
const int widget_size_hint = 128;
}

ItemSelectorWidget::ItemSelectorWidget(QWidget *parent)
    : QWidget(parent)
    , m_listView(new QListView(this))
    , m_model(0)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);

    layout->addWidget(m_listView);
    setLayout(layout);

    m_listView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(m_listView, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(onCustomContextMenuRequested(const QPoint &)));

}

QSize ItemSelectorWidget::sizeHint() const
{
    return QSize(widget_size_hint, widget_size_hint*4);
}

QSize ItemSelectorWidget::minimumSizeHint() const
{
    return QSize(widget_minimum_size_hint, widget_minimum_size_hint);
}

void ItemSelectorWidget::setModel(SessionModel *model)
{
    if(model == m_model)
        return;

    disconnectModel();
    m_model = model;
    connectModel();
}

void ItemSelectorWidget::setItemDelegate(QAbstractItemDelegate *delegate)
{
    m_listView->setItemDelegate(delegate);
}

QItemSelectionModel *ItemSelectorWidget::selectionModel()
{
    return m_listView->selectionModel();
}

void ItemSelectorWidget::onSelectionChanged(const QItemSelection &selected, const QItemSelection &)
{
    QModelIndexList indexes = selected.indexes();
    SessionItem *selectedItem(0);
    if(indexes.size()) {
        selectedItem = m_model->itemForIndex(indexes.back());
        qDebug() << "ItemSelectorWidget::onSelectionChanged" << selectedItem->displayName();
    }
    emit selectionChanged(selectedItem);
}

void ItemSelectorWidget::onCustomContextMenuRequested(const QPoint &point)
{
    qDebug() << "ItemSelectorWidget::onCustomContextMenuRequested(const QPoint &point)";
    emit contextMenuRequest(m_listView->mapToGlobal(point), m_listView->indexAt(point));
}

void ItemSelectorWidget::connectModel()
{
    if(!m_model)
        return;

    m_listView->setModel(m_model);

    connect(m_listView->selectionModel(),
            SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)),
            this,
            SLOT(onSelectionChanged(const QItemSelection&, const QItemSelection&)),
            Qt::UniqueConnection
    );

}

void ItemSelectorWidget::disconnectModel()
{
    m_listView->setModel(0);
    m_model = 0;
}
