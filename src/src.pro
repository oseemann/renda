SOURCES += \
   main.cpp \
   renderer.cpp \
   app.cpp \
   options.cpp \

HEADERS += \
   renderer.h \
   app.h \
   options.h

TEMPLATE = app
CONFIG += \
   warn_on \
	thread \
	qt \
   debug_and_release \
   debug \

TARGET = renda
DESTDIR = ../bin

QT += webkit network
QMAKE_CXXFLAGS_DEBUG += -Wall

CONFIG -= release

# vim settings:
# vim:ts=3:sw=3:sts=3:expandtab:cindent:tw=80
