TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    point.h \
    clock.h

SOURCES += \
    main.cpp \
    clock.cpp \
    point.cpp

LIBS += \
    -lglut \
    -lGLU \
    -lGL

TARGET = speedometer

QMAKE_CXXFLAGS += -fpermissive -std=c++11
