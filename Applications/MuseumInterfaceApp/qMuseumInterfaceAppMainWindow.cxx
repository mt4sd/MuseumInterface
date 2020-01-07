/*==============================================================================

  Copyright (c) Kitware, Inc.

  See http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware, Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// MuseumInterface includes
#include "qMuseumInterfaceAppMainWindow.h"
#include "qMuseumInterfaceAppMainWindow_p.h"

// Qt includes
#include <QDesktopWidget>

// Slicer includes
#include "qSlicerApplication.h"
#include "qSlicerAboutDialog.h"
#include "qSlicerMainWindow_p.h"
#include "qSlicerModuleSelectorToolBar.h"

//-----------------------------------------------------------------------------
// qMuseumInterfaceAppMainWindowPrivate methods

qMuseumInterfaceAppMainWindowPrivate::qMuseumInterfaceAppMainWindowPrivate(qMuseumInterfaceAppMainWindow& object)
  : Superclass(object)
{
}

//-----------------------------------------------------------------------------
qMuseumInterfaceAppMainWindowPrivate::~qMuseumInterfaceAppMainWindowPrivate()
{
}

//-----------------------------------------------------------------------------
void qMuseumInterfaceAppMainWindowPrivate::init()
{
  Q_Q(qMuseumInterfaceAppMainWindow);
  this->Superclass::init();
}

//-----------------------------------------------------------------------------
void qMuseumInterfaceAppMainWindowPrivate::setupUi(QMainWindow * mainWindow)
{
  qSlicerApplication * app = qSlicerApplication::application();

  //----------------------------------------------------------------------------
  // Add actions
  //----------------------------------------------------------------------------
  QAction* helpAboutSlicerAppAction = new QAction(mainWindow);
  helpAboutSlicerAppAction->setObjectName("HelpAboutMuseumInterfaceAppAction");
  helpAboutSlicerAppAction->setText("About " + app->applicationName());

  //----------------------------------------------------------------------------
  // Calling "setupUi()" after adding the actions above allows the call
  // to "QMetaObject::connectSlotsByName()" done in "setupUi()" to
  // successfully connect each slot with its corresponding action.
  this->Superclass::setupUi(mainWindow);

  //----------------------------------------------------------------------------
  // Configure
  //----------------------------------------------------------------------------
  mainWindow->setWindowIcon(QIcon(":/Icons/Medium/DesktopIcon.png"));

  QPixmap logo(":/LogoFull.png");
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
  qreal dpr = sqrt(qApp->desktop()->logicalDpiX()*qreal(qApp->desktop()->logicalDpiY()) / (qApp->desktop()->physicalDpiX()*qApp->desktop()->physicalDpiY()));
  logo.setDevicePixelRatio(dpr);
#endif
  this->LogoLabel->setPixmap(logo);

  // Hide the toolbars
  this->MainToolBar->setVisible(false);
  //this->ModuleSelectorToolBar->setVisible(false);
  this->ModuleToolBar->setVisible(false);
  this->ViewToolBar->setVisible(false);
  this->MouseModeToolBar->setVisible(false);
  this->CaptureToolBar->setVisible(false);
  this->ViewersToolBar->setVisible(false);
  this->DialogToolBar->setVisible(false);

  // Hide the menus
  this->menubar->setVisible(false);
  this->FileMenu->setVisible(false);
  this->EditMenu->setVisible(false);
  this->ViewMenu->setVisible(false);
  this->LayoutMenu->setVisible(false);
  this->HelpMenu->setVisible(false);

  // Hide the modules panel
  //this->PanelDockWidget->setVisible(false);
  this->PanelDockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
  this->DataProbeCollapsibleWidget->setCollapsed(true);
  this->DataProbeCollapsibleWidget->setVisible(false);
  this->StatusBar->setVisible(false);
}

//-----------------------------------------------------------------------------
// qMuseumInterfaceAppMainWindow methods

//-----------------------------------------------------------------------------
qMuseumInterfaceAppMainWindow::qMuseumInterfaceAppMainWindow(QWidget* windowParent)
  : Superclass(new qMuseumInterfaceAppMainWindowPrivate(*this), windowParent)
{
  Q_D(qMuseumInterfaceAppMainWindow);
  d->init();
  showFullScreen();
}

//-----------------------------------------------------------------------------
qMuseumInterfaceAppMainWindow::qMuseumInterfaceAppMainWindow(
  qMuseumInterfaceAppMainWindowPrivate* pimpl, QWidget* windowParent)
  : Superclass(pimpl, windowParent)
{
  // init() is called by derived class.
}

//-----------------------------------------------------------------------------
qMuseumInterfaceAppMainWindow::~qMuseumInterfaceAppMainWindow()
{
}

//-----------------------------------------------------------------------------
void qMuseumInterfaceAppMainWindow::on_HelpAboutMuseumInterfaceAppAction_triggered()
{
  qSlicerAboutDialog about(this);
  about.setLogo(QPixmap(":/Logo.png"));
  about.exec();
}
