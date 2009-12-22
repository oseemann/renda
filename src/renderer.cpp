#include <QPainter>
#include <QPrinter>
#include <iostream>

#include "renderer.h"

Renderer::Renderer(
   Options &options
)
{
   page = new QWebPage(NULL);
   QWebFrame *frame = page->mainFrame();
   connect(page, SIGNAL(loadFinished(bool)), this, SLOT(renderToBuffer()));
   /* set default size of of the screen */
   page->setViewportSize(QSize(1024, 100));
   std::cout << "Loading " << options.getUrl().toStdString() << std::endl;
   frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
   frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
   frame->load(options.getUrl());
}

Renderer::~Renderer() {
   delete page;
}

void
Renderer::renderToBuffer(
   void
)
{
   QSize contentSize = page->mainFrame()->contentsSize();
   std::cout << "contentSize: " << contentSize.width() << "x" << contentSize.height() << std::endl;
   if (contentSize.height() > 32768) {
      contentSize.setHeight(32768);
   }
   page->setViewportSize(contentSize);
   QSize viewPortSize = page->viewportSize();
   std::cout << "viewportSize: " << viewPortSize.width() << "x" << viewPortSize.height() << std::endl;
   QImage image(viewPortSize, QImage::Format_ARGB32);
   QPainter painter(&image);
   std::cout << "Rendering.." << std::endl;
   page->mainFrame()->render(&painter);
   painter.end();
   std::cout << "Saving.." << std::endl;
   image.save("/tmp/a.png", "PNG");
   std::cout << "Done!" << std::endl;
   emit finished();
}

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
