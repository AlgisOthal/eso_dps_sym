ROOT_DIR= $$PWD/../
include( ../common.pri )

CONFIG += c++11
CONFIG += qt
QT += core widgets gui printsupport

#-------------

TEMPLATE = app
DESTDIR = $${BIN_PATH}

#-------------

LIBS += \
    -L$${LIB_PATH} \
    -leso_dps_sym \

SOURCES += \
    main.cpp \
    qcustomplot/qcustomplot.cpp \
    plot_painter.cpp \
    form_dpssym.cpp

HEADERS += \
    defines.h \
    qcustomplot/qcustomplot.h \
    plot_painter.h \
    form_dpssym.h

FORMS += \
    form_dpssym.ui
