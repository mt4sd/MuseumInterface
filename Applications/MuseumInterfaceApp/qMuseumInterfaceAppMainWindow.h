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

#ifndef __qMuseumInterfaceAppMainWindow_h
#define __qMuseumInterfaceAppMainWindow_h

// MuseumInterface includes
#include "qMuseumInterfaceAppExport.h"
class qMuseumInterfaceAppMainWindowPrivate;

// Slicer includes
#include "qSlicerMainWindow.h"

class Q_MUSEUMINTERFACE_APP_EXPORT qMuseumInterfaceAppMainWindow : public qSlicerMainWindow
{
  Q_OBJECT
public:
  typedef qSlicerMainWindow Superclass;

  qMuseumInterfaceAppMainWindow(QWidget *parent=0);
  virtual ~qMuseumInterfaceAppMainWindow();

public slots:
  void on_HelpAboutMuseumInterfaceAppAction_triggered();

protected:
  qMuseumInterfaceAppMainWindow(qMuseumInterfaceAppMainWindowPrivate* pimpl, QWidget* parent);

private:
  Q_DECLARE_PRIVATE(qMuseumInterfaceAppMainWindow);
  Q_DISABLE_COPY(qMuseumInterfaceAppMainWindow);
};

#endif
