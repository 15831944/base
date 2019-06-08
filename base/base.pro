TARGET       = base
TEMPLATE     = lib
CONFIG      += staticlib
#######################################################################################
CONFIG += c++11

SOURCES     += ./src/*.cpp
HEADERS     += ./include/*.h

INCLUDEPATH += ./include
INCLUDEPATH += ../../boost
