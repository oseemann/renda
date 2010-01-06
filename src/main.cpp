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
#include "app.h"

int main(int argc, char *argv[]) {
   int ret = 0;
   try {
      RenderApplication app(argc, argv);
      ret = app.run();
   } catch(OptionException e) {
      std::cout << "Error: " << e.getMessage().toStdString() << std::endl;
      std::cout << Options::usage().toStdString();
      ret = 1;
   }
   return ret;
}
