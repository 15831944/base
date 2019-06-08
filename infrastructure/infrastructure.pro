TARGET       = t2l_infrastructure
TEMPLATE     = lib
CONFIG      += staticlib
#######################################################################################
CONFIG += c++11

INCLUDEPATH += ./include
INCLUDEPATH += ../../infrastructure/command_registry
INCLUDEPATH += ../../infrastructure/command_registry_ex

SOURCES     += ./*.cpp
HEADERS     += ./*.h

QT += widgets

CONFIG(debug, debug|release) {
     DEFINES += DEBUG
}
else {
     DEFINES += NDEBUG
}

