#-------------------------------------------------
#
# Project created by QtCreator 2016-03-18T12:40:30
#
#-------------------------------------------------

QT       += core gui\
             xml \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = translate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    receiveosc.cpp

HEADERS  += mainwindow.h \
    receiveosc.h \
    oscpkt.hh \
    udp.hh

FORMS    += mainwindow.ui
