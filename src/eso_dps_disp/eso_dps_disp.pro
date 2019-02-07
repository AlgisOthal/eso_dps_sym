ROOT_DIR= $$PWD/../
include( ../common.pri )

CONFIG += c++11
CONFIG += qt
QT += core

#-------------

TEMPLATE = app
DESTDIR = $${BIN_PATH}

#-------------

SOURCES += \
    main.cpp

HEADERS += \
    defines.h
