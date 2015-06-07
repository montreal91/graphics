
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += point.h
HEADERS += vector.h

SOURCES += main.cpp
SOURCES += point.cpp
SOURCES += vector.cpp

LIBS += -lglut
LIBS += -lGLU
LIBS += -lGL

TARGET = vector

QMAKE_CXXFLAGS += -std=c++11
