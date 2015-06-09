
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    color.h \
    point.h \
    ring.h \
    application.h

SOURCES += \
    main.cpp \
    color.cpp \
    point.cpp \
    ring.cpp \
    application.cpp


LIBS += \
    -lglut \
    -lGLU \
    -lGL

LIBS += -L"/usr/lib/i386-linux-gnu"
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "/usr/include/SFML/"
DEPENDPATH += "/usr/include/SFML/"

TARGET = circle

QMAKE_CXXFLAGS += -std=c++11
