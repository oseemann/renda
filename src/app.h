#ifndef __APP_H__
#define __APP_H__

#include <QApplication>
#include "options.h"

class RenderApplication
   : public QApplication
{
public:
   RenderApplication(int argc, char **argv);
   ~RenderApplication();
   int run();
private:
   Options *options;
};

#endif /* __APP_H__ */

/* vim settings:
 * vim:autoindent:filetype=c:syntax=cpp
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */

