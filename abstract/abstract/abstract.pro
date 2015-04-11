TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    vector.h\
    point.h\
    geomobject.h

SOURCES += \
    main.cpp \
    vector.cpp \
    point.cpp

LIBS += -lglut
LIBS += -lGLU
LIBS += -lGL

TARGET = abstract

QMAKE_CXXFLAGS += -fpermissive -std=c++11
