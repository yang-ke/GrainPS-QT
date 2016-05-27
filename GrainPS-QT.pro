#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T19:06:23
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_FILE = icon.rc

TARGET = GrainPS-QT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    generateqrcodedlg.cpp \
    manager.cpp \
    globalconfig.cpp \
    inimanager.cpp \
    sqlmanager.cpp \
    sqlstr.cpp

HEADERS  += mainwindow.h \
    generateqrcodedlg.h \
    manager.h \
    globalconfig.h \
    inimanager.h \
    sqlmanager.h \
    sqlstr.h

FORMS    += mainwindow.ui \
    generateqrcodedlg.ui

RESOURCES += \
    gps.qrc

DISTFILES += \
    icon.rc
