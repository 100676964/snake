TEMPLATE = app
TARGET = snakegame

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    Node.cpp \
    Snake.cpp \
    coordinates.cpp \
    screen.cpp

HEADERS += \
    Node.h \
    Snake.h \
    coordinates.h \
    screen.h



