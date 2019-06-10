TARGET     = t2l_naray
CONFIG    += staticlib
TEMPLATE   = lib
#######################################################################################
CONFIG += c++11

INCLUDEPATH += ./include
INCLUDEPATH += ../base/include
INCLUDEPATH += ../geogebra

SOURCES += ./*.cpp
HEADERS += ./*.h

