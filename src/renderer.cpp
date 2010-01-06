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
#include <QPainter>
#include <QPrinter>
#include <iostream>

#include "renderer.h"

Renderer::Renderer(
   Options &options
)
{
   this->page = new QWebPage(NULL);
   QWebFrame *frame = this->page->mainFrame();
   connect(this->page, SIGNAL(loadFinished(bool)), this, SLOT(render()));
   this->options = &options;

   /* set default size of of the screen.
    * use a mininum height of 100 pixel, so very short pages (e.g. only one
    * word) don't look so lost */
   this->page->setViewportSize(QSize(this->options->getWidth(), 100));
   /* we don't need any scrollbars */
   frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
   frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);

   std::cout << "Loading " << options.getUrl().toString().toStdString() << std::endl;
   frame->load(options.getUrl());
}

Renderer::~Renderer() {
   delete this->page;
}

void
Renderer::render(
   void
)
{
   int maxheight = this->options->getMaxHeight();
   QSize contentSize = this->page->mainFrame()->contentsSize();

   std::cout << "Content Size: "
             << contentSize.width() << "x" << contentSize.height()
             << std::endl;
   if (contentSize.height() > maxheight && maxheight > 0) {
      contentSize.setHeight(maxheight);
   }
   /* Pages taller than 32k pixel do not properly render with QT4.4 and 4.5, the
    * app segfaults or runs ridiculously long (minutes), whereas pages with less
    * than 32k pixels height typically render in seconds or less.
    * Therefore put a hard limit to 32k. */
   if (contentSize.height() > 32768) {
      contentSize.setHeight(32768);
   }

   this->page->setViewportSize(contentSize);
   QSize viewPortSize = this->page->viewportSize();
   std::cout << "Viewport Size: "
             << viewPortSize.width() << "x" << viewPortSize.height()
             << std::endl;

   if (this->options->getImageFilename().length() > 0) {
      std::cout << "Rendering" << std::endl;
      QImage image(viewPortSize, QImage::Format_ARGB32);
      QPainter painter(&image);
      this->page->mainFrame()->render(&painter);
      painter.end();

      std::cout << "Saving as PNG" << std::endl;
      image.save(options->getImageFilename(), "PNG");
   }

   if (this->options->getPrintFilename().length() > 0) {
      std::cout << "Printing to PDF" << std::endl;
      QPrinter printer(QPrinter::HighResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName(this->options->getPrintFilename());
      this->page->mainFrame()->print(&printer);
   }

   std::cout << "Done" << std::endl;
   emit finished();
}

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
