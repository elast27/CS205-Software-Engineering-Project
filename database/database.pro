TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle


QT += core                # this should be added
QT += sql                 # this should be added
QT += location
QT += positioning
QT += widgets
CONFIG += c++11
CONFIG += mobility
MOBILITY += location


SOURCES += \
        main.cpp \
    controller_db.cpp \
    person_db.cpp \
    firstresponder_db.cpp

HEADERS += \
    controller_db.h \
    person_db.h \
    firstresponder_db.h


