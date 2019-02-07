BUILD_DIR= $$PWD/build
include( ../common.pri )

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#-------------

TEMPLATE = app

#-------------

SOURCES += main.cpp
