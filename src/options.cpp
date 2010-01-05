#include <iostream>
#include <getopt.h>
#include <stdlib.h>

#include "options.h"

QString Options::usage(
   void
)
{
   return "Usage: renda [-i|-p] url\
Options:\
  -i filename    Filename of the image to store\
  -p filename    Filename of the pdf to store\
";
}

Options::Options(
   int argc,
   char **argv
)
{
   extern int optind;
   int c = 0;

   while((c = getopt(argc, argv, "i:p:")) != -1) {
      switch(c) {
      case 'i':
         this->imageFilename = QString(optarg);
         std::cout
            << "Image output: "
            << this->imageFilename.toStdString()
            << std::endl;
         break;
      case 'p':
         this->printFilename = QString(optarg);
         std::cout
            << "Print output: "
            << this->printFilename.toStdString()
            << std::endl;
         break;
      default:
         throw OptionException();
      }
   }

   /* when getopt returned -1 all options have been processed and the
    * regular arguments can be accessed. The external variable optind
    * indicates the argv index of the first non-option argument */
   if (optind < argc) {
      if (argv[optind] != NULL) {
         this->url = QString(argv[optind]);
      } else {
         throw OptionException();
      }
   } else {
      throw OptionException();
   }
}

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
