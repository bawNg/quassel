/***************************************************************************
 *   Copyright (C) 2009 by the Quassel Project                             *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) version 3.                                           *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef CORECONNECTIONSTATUSWIDGET_H
#define CORECONNECTIONSTATUSWIDGET_H

#include <QWidget>

#include "ui_coreconnectionstatuswidget.h"

#include "coreconnection.h"

class CoreConnectionStatusWidget : public QWidget {
  Q_OBJECT

public:
  CoreConnectionStatusWidget(CoreConnection *connection, QWidget *parent = 0);

  inline CoreConnection *coreConnection() const { return _coreConnection; }

public slots:
  void update();
  void updateLag(int msecs);

private slots:
  void connectionStateChanged(CoreConnection::ConnectionState);
  void progressRangeChanged(int min, int max);

private:
  Ui::CoreConnectionStatusWidget ui;

  CoreConnection *_coreConnection;
};

#endif // CORECONNECTIONSTATUSWIDGET_H
