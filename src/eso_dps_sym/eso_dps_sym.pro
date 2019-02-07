ROOT_DIR= $$PWD/../
include( ../common.pri )

CONFIG += console plugin c++11
CONFIG -= app_bundle
CONFIG -= qt

#-------------

TEMPLATE = lib
DESTDIR = $${LIB_PATH}

#-------------

HEADERS += \
    char_attributes.h

SOURCES += \
    char_attributes.cpp

