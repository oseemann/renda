#include <iostream>
#include <getopt.h>
#include <stdlib.h>

#include "options.h"

Options::Options(
   int argc,
   char **argv
)
{
   int c = 0;

   while((c = getopt(argc, argv, "u:i:p:")) != -1) {
      switch(c) {
      case 'i':
         this->imageFilename = QString(optarg);
         std::cout << "Image: " << this->imageFilename.toStdString() << std::endl;
         break;
      case 'p':
         this->printFilename = QString(optarg);
         std::cout << "Print: " << this->printFilename.toStdString() << std::endl;
         break;
      case 'u':
         this->url = QString(optarg);
         std::cout << "URL: " << this->url.toStdString() << std::endl;
         break;
      default:
         throw OptionException();
      }
   }
}

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
