#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T09:07:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AndrasAmoba
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    tictactoetablemodel.cpp

HEADERS  += mainwindow.h \
    controller.h \
    tictactoetablemodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    andrasamoba.qrc
