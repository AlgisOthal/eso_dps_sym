ROOT_DIR= $$PWD/../
include( ../common.pri )

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#-------------

TEMPLATE = app
DESTDIR = $${BIN_PATH}

#-------------

