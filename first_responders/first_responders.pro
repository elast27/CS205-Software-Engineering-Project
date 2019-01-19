TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        ems.cpp \
        swat.cpp \
        firstresponder.cpp \
        firefighter.cpp \
        police.cpp

HEADERS += \
        ems.h \
        swat.h \
        firstresponder.h \
        firefighter.h \
        police.h

LIBS += -pthread

INCLUDEPATH +=  ../googletest-master                                   \
                ../googletest-master/googletest                        \
                ../googletest-master/googletest/include                \
                ../googletest-master/googletest/include/gtest

SOURCES += ../googletest-master/googletest/src/gtest-all.cc\


