#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include <QString>

class OptionException { };

class Options {
public:
   Options(int argc, char **argv);
   QString getImageFilename() { return imageFilename; }
   QString getPrintFilename() { return printFilename; }
   QString getUrl() { return url; }
private:
   QString imageFilename;
   QString printFilename;
   QString url;
};

#endif /* __OPTIONS_H__ */

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
