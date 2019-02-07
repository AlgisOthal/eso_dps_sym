ROOT_DIR= $$PWD/../
include( ../common.pri )

CONFIG += c++11
CONFIG += qt
QT += core

#-------------

TEMPLATE = app
DESTDIR = $${BIN_PATH}

#-------------

LIBS += \
    -L$${LIB_PATH} \
    -leso_dps_sym \

SOURCES += \
    main.cpp

HEADERS += \
    defines.h
