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
#include <iostream>
#include <getopt.h>
#include <stdlib.h>

#include "options.h"

QString
Options::usage(
   void
)
{
   return "Usage: renda [-w width] [-h maxheight] [-p filename] -i filename URL\n\
Options:\n\
  -i filename     Filename of the rendered image to store\n\
  -p filename     Filename of the rendered pdf to store\n\
  -w width        Width of the viewport (browser window) in pixel\n\
                  Default: 1024\n\
  -h maxheight    Max height of the viewport (browser window)\n\
                  Default: no limit\n\
\n\
Example usage:\n\
  renda -i google.png http://www.google.com/\n\
\n\
";
}

Options::Options(
   int argc,
   char **argv
)
{
   this->read(argc, argv);
   this->check();
   this->print();
}

void
Options::read(
   int argc,
   char **argv
)
{
   extern int optind;
   int c = 0;

   /* default values */
   this->width = 1024;
   this->maxheight = 0; /* no limit */

   while((c = getopt(argc, argv, "i:p:w:h:")) != -1) {
      switch(c) {
      case 'i':
         this->imageFilename = QString(optarg);
         break;
      case 'p':
         this->printFilename = QString(optarg);
         break;
      case 'w':
         this->width = atoi(optarg);
         break;
      case 'h':
         this->maxheight = atoi(optarg);
         break;
      case '?':
         throw OptionException("argument problem");
      default:
         throw OptionException("Unknown or ");
      }
   }

   /* when getopt returned -1 all options have been processed and the
    * regular arguments can be accessed. The external variable optind
    * indicates the argv index of the first non-option argument */
   if (optind < argc) {
      if (argv[optind] != NULL) {
         this->url = QUrl(argv[optind]);
      } else {
         throw OptionException("Invalid Argument");
      }
   } else {
      throw OptionException("No URL given");
   }

}

void
Options::check(
   void
)
{
   if (!this->url.isValid()) {
      throw OptionException("Invalid URL");
   }

   if ((this->imageFilename.length() < 1) && 
       (this->printFilename.length() < 1)) {
      throw OptionException("Either image or print filename is required, or both.");
   }

   if (this->width > 32768) {
      this->width = 32768;
   }

   if (this->maxheight > 32768) {
      this->maxheight = 32768;
   }
}

void
Options::print(
   void
)
{
   std::cout
      << "Image output: "
      << this->imageFilename.toStdString()
      << std::endl;

   std::cout
      << "Print output: "
      << this->printFilename.toStdString()
      << std::endl;

   std::cout
      << "Window width: "
      << this->width
      << "px"
      << std::endl;

   std::cout
      << "Max image height: "
      << this->maxheight
      << "px"
      << std::endl;
}

OptionException::OptionException(
   QString message
)
{
   this->message = message; 
}

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
