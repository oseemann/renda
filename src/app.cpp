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
#include "app.h"
#include "renderer.h"

RenderApplication::RenderApplication(
   int argc,
   char **argv
) : QApplication(argc, argv)
{
   this->options = new Options(argc, argv);
}

RenderApplication::~RenderApplication()
{
   delete options;
}

int
RenderApplication::run(
   void
)
{
   Renderer *render = new Renderer(*options);
   QObject::connect(render, SIGNAL(finished()), this, SLOT(quit()));
   int ret = this->exec();
   delete render;
   return ret;
}

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
