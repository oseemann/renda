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
#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include <QString>
#include <QUrl>

class OptionException {
public:
   OptionException(QString message);
   QString getMessage() { return message; }
private:
   QString message;
};

class Options {
public:
   Options(int argc, char **argv);
   QString getImageFilename() { return imageFilename; }
   QString getPrintFilename() { return printFilename; }
   QUrl getUrl() { return url; }
   int getWidth() { return width; }
   int getMaxHeight() { return maxheight; }
   static QString usage(void);
private:
   void read(int argc, char **argv);
   void check();
   void print();
   QString imageFilename;
   QString printFilename;
   QUrl url;
   int width;
   int maxheight;
};

#endif /* __OPTIONS_H__ */

/* vim settings:
 * vim:autoindent:filetype=c:syntax=c
 * vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
 * vim:formatoptions=croql
 */
