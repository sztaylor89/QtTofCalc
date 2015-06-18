#-------------------------------------------------
#
# Project created by QtCreator 2015-06-18T08:37:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtofcalc
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    PhotonDialog.cpp \
    TofCalculator.cpp

HEADERS  += MainWindow.hpp \
    PhotonDialog.hpp \
    TofCalculator.hpp

FORMS    += MainWindow.ui \
    PhotonDialog.ui
