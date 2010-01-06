/*
 *  This file is part of Renda.
 *
 *  Renda is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Renda is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Renda.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright (C) 2010, Oliver Seemann
 */
#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <QtWebKit>
#include <QUrl>

#include "options.h"

class Renderer
   : public QObject
{
   Q_OBJECT

public:
   Renderer(Options &options);
   ~Renderer();
signals:
   void finished();

private slots:
   void render();

private:
   QWebPage *page;
   Options *options;
};

#endif /* __RENDERER_H__ */

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
