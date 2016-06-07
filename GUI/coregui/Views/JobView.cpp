// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/JobView.cpp
//! @brief     Implements class JobView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "JobView.h"
#include "JobViewDocks.h"
#include "JobQueueData.h"
#include "TestView.h"
#include "JobSelectorWidget.h"
#include "JobOutputDataWidget.h"
#include "JobModel.h"
#include "projectmanager.h"
#include "JobRealTimeWidget.h"
#include "projectmanager.h"
#include "mainwindow.h"
#include "progressbar.h"
#include "GUIHelpers.h"
#include "FitActivityPanel.h"
#include "JobMessagePanel.h"
#include "JobActivityStatusBar.h"
#include "JobViewActivities.h"
#include <QFrame>
#include <QDockWidget>
#include <QAbstractItemView>
#include <QStatusBar>
#include <QMenu>
#include <QCursor>
#include <QDebug>

class JobViewPrivate
{
public:
    JobViewPrivate(MainWindow *mainWindow);

    Manhattan::ProgressBar *progressBar() { return m_mainWindow->progressBar(); }
    JobModel *jobModel() { return m_mainWindow->jobModel(); }

    JobActivityStatusBar *m_jobActivityStatusBar;
    MainWindow *m_mainWindow;
};


JobViewPrivate::JobViewPrivate(MainWindow *mainWindow)
    : m_jobActivityStatusBar(0)
    , m_mainWindow(mainWindow)
{
}


JobView::JobView(MainWindow *mainWindow)
    : m_docks(new JobViewDocks(this))
    , m_jobActivityStatusBar(new JobActivityStatusBar(mainWindow))
    , m_mainWindow(mainWindow)
{
    setObjectName("JobView");
    m_docks->initViews(mainWindow->jobModel());

    connectSignals();
}

QStringList JobView::getActivityStringList()
{
    QStringList result = QStringList() << QStringLiteral("Job View Activity")
        << QStringLiteral("Real Time Activity") << QStringLiteral("Fitting Activity");
    return result;
}

void JobView::updateGlobalProgressBar(int progress)
{
    Q_ASSERT(m_mainWindow->progressBar());
    if(progress<0 || progress >= 100) {
        m_mainWindow->progressBar()->setFinished(true);
        m_mainWindow->progressBar()->hide();
    } else {
        m_mainWindow->progressBar()->show();
        m_mainWindow->progressBar()->setFinished(false);
        m_mainWindow->progressBar()->setValue(progress);
    }
}

void JobView::onFocusRequest(JobItem *item)
{
    m_docks->jobSelector()->makeJobItemSelected(item);
    emit focusRequest(MainWindow::JOB);
}

void JobView::resetToDefaultLayout()
{
    setTrackingEnabled(false);
    QList<QDockWidget *> dockWidgetList = dockWidgets();
    foreach (QDockWidget *dockWidget, dockWidgetList) {
        dockWidget->setFloating(false);
        removeDockWidget(dockWidget);
    }

    addDockWidget(Qt::LeftDockWidgetArea, m_docks->dock(JobViewFlags::JOB_LIST_DOCK));
    addDockWidget(Qt::RightDockWidgetArea, m_docks->dock(JobViewFlags::REAL_TIME_DOCK));
    addDockWidget(Qt::RightDockWidgetArea, m_docks->dock(JobViewFlags::FIT_PANEL_DOCK));
    addDockWidget(Qt::BottomDockWidgetArea, m_docks->dock(JobViewFlags::JOB_MESSAGE_DOCK));

    foreach (QDockWidget *dockWidget, dockWidgetList)
        dockWidget->show();

    setTrackingEnabled(true);

    setActivity(JobViewFlags::JOB_VIEW_ACTIVITY);
//    setActivity(FITTING_ACTIVITY);
}

void JobView::setActivity(int activity)
{
    if(activity == JobViewFlags::JOB_VIEW_ACTIVITY) {
        m_docks->dock(JobViewFlags::JOB_LIST_DOCK)->show();
        m_docks->dock(JobViewFlags::REAL_TIME_DOCK)->hide();
        m_docks->dock(JobViewFlags::FIT_PANEL_DOCK)->hide();
        m_docks->dock(JobViewFlags::JOB_MESSAGE_DOCK)->hide();
    }

    else if(activity == JobViewFlags::REAL_TIME_ACTIVITY) {
        m_docks->dock(JobViewFlags::JOB_LIST_DOCK)->hide();
        m_docks->dock(JobViewFlags::REAL_TIME_DOCK)->show();
        m_docks->dock(JobViewFlags::FIT_PANEL_DOCK)->hide();
        m_docks->dock(JobViewFlags::JOB_MESSAGE_DOCK)->hide();
        m_docks->jobRealTimeWidget()->updateCurrentItem();
    }

    else if(activity == JobViewFlags::FITTING_ACTIVITY) {
        m_docks->dock(JobViewFlags::JOB_LIST_DOCK)->hide();
        m_docks->dock(JobViewFlags::REAL_TIME_DOCK)->show();
        m_docks->dock(JobViewFlags::FIT_PANEL_DOCK)->show();
        m_docks->dock(JobViewFlags::JOB_MESSAGE_DOCK)->show();
        m_docks->jobRealTimeWidget()->updateCurrentItem();
        m_docks->fitActivityPanel()->updateCurrentItem();
    }

    else {
        throw GUIHelpers::Error("JobView::setActivity -> Error. Unknown activity");
    }

    emit activityChanged(activity);
}

void JobView::onToggleJobListRequest()
{
    qDebug() << "JobView::onToggleJobListRequest()";
    //m_d->m_dockWidgets[JOB_LIST_DOCK]->setHidden(!m_d->m_dockWidgets[JOB_LIST_DOCK]->isHidden());
    m_docks->jobWidget(JobViewFlags::JOB_LIST_DOCK)->setHidden(!m_docks->jobWidget(JobViewFlags::JOB_LIST_DOCK)->isHidden());
}

//! creates global dock menu
void JobView::onDockMenuRequest()
{
    QMenu *menu = createPopupMenu();
    menu->exec(QCursor::pos());
    delete menu;
}

void JobView::showEvent(QShowEvent *)
{
    if(isVisible())
        m_jobActivityStatusBar->show();
}

void JobView::hideEvent(QHideEvent *)
{
    if(isHidden())
        m_jobActivityStatusBar->hide();
}


void JobView::connectSignals()
{
    Q_ASSERT(m_mainWindow->progressBar());
    Q_ASSERT(m_mainWindow->jobModel());
    connect(this, SIGNAL(resetLayout()), this, SLOT(resetToDefaultLayout()));
    connect(m_mainWindow->jobModel(), SIGNAL(globalProgress(int)),
            this, SLOT(updateGlobalProgressBar(int)));
    connect(m_mainWindow->jobModel(), SIGNAL(focusRequest(JobItem *)),
            this, SLOT(onFocusRequest(JobItem *)));
    connect(m_mainWindow->progressBar(), SIGNAL(clicked()),
            m_mainWindow->jobModel()->getJobQueueData(), SLOT(onCancelAllJobs()));

    // global statusBar notifies JobView about changes in the activity
    connect(m_jobActivityStatusBar, SIGNAL(changeActivityRequest(int)),
            this, SLOT(setActivity(int)));
    connect(m_jobActivityStatusBar, SIGNAL(toggleJobListRequest()),
            this, SLOT(onToggleJobListRequest()));
    connect(m_jobActivityStatusBar, SIGNAL(dockMenuRequest()),
            this, SLOT(onDockMenuRequest()));

    // JobView notifies others about changes in the activity
    connect(this, SIGNAL(activityChanged(int)),
            m_jobActivityStatusBar, SLOT(onActivityChanged(int)));
    connect(this, SIGNAL(activityChanged(int)),
            m_docks->jobOutputDataWidget(), SLOT(onActivityChanged(int)));
}
