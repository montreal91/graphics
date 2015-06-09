TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    point.h \
    square.h

SOURCES += \
    main.cpp \
    point.cpp \
    square.cpp


LIBS += \
    -lglut \
    -lGLU \
    -lGL

INCLUDEPATH += "/usr/include/SFML/"
DEPENDPATH += "/usr/include/SFML/"

TARGET = speedometer

QMAKE_CXXFLAGS += -std=c++11 -fpermissive
