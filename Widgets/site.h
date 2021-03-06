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

#ifndef SITE_H
#define SITE_H

#include <QObject>
#include <QHash>
#include "content.h"

class QMainWindow;
class QXmlStreamReader;
class Content;
class Menu;
class Site : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle)

public:
    Site() {}
    Site(QObject *) {}
    Site(QMainWindow *win, QString filename);

    QString theme() {return m_theme;}
    void setTheme(QString theme) {m_theme = theme;}

    QString title() {return m_title;}
    void setTitle(QString title);

    QString publisher() {return m_publisher;}
    void setPublisher(QString publisher) {m_publisher = publisher;}

    QString author() {return m_author;}
    void setAuthor(QString author) {m_author = author;}

    QString keywords() {return m_keywords;}
    void setKeywords(QString keywords) {m_keywords = keywords;}

    QString description() {return m_description;}
    void setDescription(QString desc) {m_description = desc;}

    QString copyright() {return m_copyright;}
    void setCopyright(QString copyright) {m_copyright = copyright;}

    QList<Content *> pages() {return m_pages;}
    void addPage(Content *content) {m_pages.append(content);}
    void removePage(Content *content) {m_pages.removeOne(content);}

    QList<Content *> posts() {return m_posts;}
    void addPost(Content *content) {m_posts.append(content);}
    void removePost(Content *content) {m_posts.removeOne(content);}

    QList<Menu *> menus() {return m_menus;}
    void addMenu(Menu *menu) {m_menus.append(menu);}
    void removeMenu(Menu *menu) {m_menus.removeOne(menu);}
    void removeAllMenus() {m_menus.clear();}
    QString sourcePath() {return m_sourcePath;}
    QString deployPath() {return m_deployPath;}
    QString filename() {return m_filename;}

    void load();
    void loadPages();
    void loadPosts();
    void loadMenus();
    void save();
    void saveMenus();
    QString createTemporaryContent(ContentType type);
    void loadContent(Content *content, QXmlStreamReader *stream);

    void addAttribute(QString attName, QString value) {m_attributes.insert(attName, value);}
    QHash<QString,QString> attributes() {return m_attributes;}

private:
    QMainWindow *m_win;
    QString m_filename;
    QString m_sourcePath;
    QString m_deployPath;
    QString m_theme;
    QString m_author;
    QString m_title;
    QString m_description;
    QString m_copyright;
    QString m_keywords;
    QString m_publisher;
    QList<Content *> m_pages;
    QList<Content *> m_posts;
    QList<Menu *> m_menus;
    QHash<QString,QString> m_attributes;
};

#endif // SITE_H
