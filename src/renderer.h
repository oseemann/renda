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
   void renderToBuffer();

private:
   QWebPage *page;
};

#endif /* __RENDERER_H__ */

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
