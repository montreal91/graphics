TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    sierpinski.h

SOURCES += \
    main.cpp \
    sierpinski.cpp

LIBS += -lglut
LIBS += -lGLU
LIBS += -lGL

TARGET = serpinsky

QMAKE_CXXFLAGS += -fpermissive -std=c++11
