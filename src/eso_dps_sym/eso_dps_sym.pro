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
    char_attributes.h \
    enum.h \
    base_skill.h \
    skills.h \
    dps_sym.h \
    rotation_prepare.h \
    base_buff.h \
    buffs.h

SOURCES += \
    char_attributes.cpp \
    base_skill.cpp \
    skills.cpp \
    dps_sym.cpp \
    rotation_prepare.cpp \
    base_buff.cpp \
    buffs.cpp

