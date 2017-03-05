#-------------------------------------------------
#
# Project created by S. V. Paulauskas 2015-06-18T08:37:50
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtofcalc
TEMPLATE = app

INCLUDEPATH=include

SOURCES += source/main.cpp\
    source/MainWindow.cpp \
    source/PhotonDialog.cpp \
    source/Mass.cpp \
    source/MassWarningDialog.cpp

HEADERS += include/MainWindow.hpp \
    include/PhotonDialog.hpp \
    include/Mass.hpp \
    include/Tokenizer.hpp \
    include/MassWarningDialog.hpp

FORMS += forms/MainWindow.ui \
    forms/PhotonDialog.ui \
    forms/MassWarningDialog.ui

DISTFILES += share/masses.dat
