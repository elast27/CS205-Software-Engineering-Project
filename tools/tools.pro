TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QT += quick
RESOURCES += qml.qrc
SOURCES += \
        main.cpp \
        locationfinder.cpp

HEADERS += \
        locationfinder.h

LIBS += -pthread

INCLUDEPATH +=  ../googletest-master                                   \
                ../googletest-master/googletest                        \
                ../googletest-master/googletest/include                \
                ../googletest-master/googletest/include/gtest

SOURCES += ../googletest-master/googletest/src/gtest-all.cc\

