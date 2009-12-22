SOURCES += main.cpp \
 renderer.cpp \
 app.cpp \
 options.cpp
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt \
 debug_and_release \
 debug
TARGET = renda
DESTDIR = ../bin
HEADERS += renderer.h \
 app.h \
 options.h

QT += webkit network
QMAKE_CXXFLAGS_DEBUG += -Wall

CONFIG -= release

