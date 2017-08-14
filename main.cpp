/****************************************************************************
** Copyright (C) 2017 Olaf Japp
**
** This file is part of FlatSiteBuilder.
**
**  FlatSiteBuilder is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  FlatSiteBuilder is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with FlatSiteBuilder.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include "mainwindow.h"
#include "site.h"
#include "content.h"
#include "section.h"
#include "row.h"
#include "column.h"
#include "text.h"
#include "image.h"
#include <QApplication>
#include <QStyleFactory>
#include <QTest>

int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("FlatSiteBuilder");
    QCoreApplication::setApplicationVersion("1.0");

    a.setStyle(QStyleFactory::create("Fusion"));
    a.setStyleSheet("QPushButton:hover { color: #45bbe6 }");
    QPalette p = a.palette();

    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::WindowText, Qt::white);
    p.setColor(QPalette::Base, QColor(64, 66, 68));
    p.setColor(QPalette::AlternateBase, QColor(53,53,53));
    p.setColor(QPalette::ToolTipBase, Qt::white);
    p.setColor(QPalette::ToolTipText, Qt::black);
    p.setColor(QPalette::Text, Qt::white);
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::ButtonText, Qt::white);
    p.setColor(QPalette::BrightText, Qt::red);
    p.setColor(QPalette::Highlight, QColor("#45bbe6"));
    p.setColor(QPalette::HighlightedText, Qt::black);
    p.setColor(QPalette::Disabled, QPalette::Text, Qt::darkGray);
    p.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::darkGray);
    p.setColor(QPalette::Link, QColor("#bbb"));
    a.setPalette(p);

    MainWindow w;
    w.show();

    return a.exec();
}