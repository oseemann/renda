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
