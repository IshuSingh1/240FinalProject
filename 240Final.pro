TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Board.cpp \
    Type.cpp \
    Human.cpp \
    Monster.cpp \
    Apples.cpp

HEADERS += \
    world.h \
    Board.h \
    Type.h \
    Human.h \
    Monster.h \
    Apples.h
