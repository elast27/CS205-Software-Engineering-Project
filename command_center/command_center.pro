QT += quick
QT += location
QT += positioning
QT += widgets
CONFIG += c++11
CONFIG += mobility
CONFIG += console
MOBILITY += location

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    director.cpp \
    erp.cpp \
    controller.cpp \
    ../publicQML/person.cpp \
    ../first_respondersQML/ems.cpp \
    ../first_respondersQML/swat.cpp \
    ../first_respondersQML/firstresponder.cpp \
    ../first_respondersQML/firefighter.cpp \
    ../first_respondersQML/police.cpp \
    ../toolsQML/locationfinder.cpp

HEADERS += director.h \
    erp.h \
    controller.h \
    ../publicQML/person.h \
    ../first_respondersQML/ems.h \
    ../first_respondersQML/swat.h \
    ../first_respondersQML/firstresponder.h \
    ../first_respondersQML/firefighter.h \
    ../first_respondersQML/police.h \
    ../toolsQML/locationfinder.h


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =
symbian:TARGET.CAPABILITY += NetworkServices Location

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -pthread
