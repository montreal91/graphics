TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    speedometer.h\
    point.h

SOURCES += \
    main.cpp \
    speedometer.cpp \
    point.cpp

LIBS += -lglut
LIBS += -lGLU
LIBS += -lGL

TARGET = speedometer

QMAKE_CXXFLAGS += -fpermissive -std=c++11
