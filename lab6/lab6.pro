TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    difderivative.cpp \
    runge.cpp \
    alignment.cpp

HEADERS += \
    difderivative.h \
    runge.h \
    alignment.h
