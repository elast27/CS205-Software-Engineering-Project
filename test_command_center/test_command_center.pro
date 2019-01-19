#-------------------------------------------------
#
# Project created by QtCreator 2018-04-19T17:27:11
#
#-------------------------------------------------

QT       += widgets testlib
QT += location
QT += positioning
QT += widgets
CONFIG += c++11
CONFIG += mobility
MOBILITY += location

QT       -= gui

TARGET = tst_test_command_centertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        tst_test_command_centertest.cpp \
         ../command_center/director.cpp \
         ../command_center/erp.cpp \
         ../command_center/controller.cpp \
         ../publicQML/person.cpp \
        ../first_respondersQML/ems.cpp \
        ../first_respondersQML/swat.cpp \
        ../first_respondersQML/firstresponder.cpp \
        ../first_respondersQML/firefighter.cpp \
        ../first_respondersQML/police.cpp \
        ../toolsQML/locationfinder.cpp


HEADERS += ../command_center/director.h \
    ../command_center/erp.h \
    ../command_center/controller.h \
    ../publicQML/person.h \
    ../first_respondersQML/ems.h \
    ../first_respondersQML/swat.h \
    ../first_respondersQML/firstresponder.h \
    ../first_respondersQML/firefighter.h \
    ../first_respondersQML/police.h \
    ../toolsQML/locationfinder.h


