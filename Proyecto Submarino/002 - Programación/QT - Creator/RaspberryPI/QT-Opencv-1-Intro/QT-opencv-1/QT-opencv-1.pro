#-------------------------------------------------
#
# Project created by QtCreator 2018-02-05T21:43:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT-opencv-1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += /usr/local/include/
INCLUDEPATH += /home/aldo/raspi/sysroot/usr/include/

LIBS += -L/home/aldo/raspi/sysroot/usr/lib/arm-linux-gnueabihf/ -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio
LIBS += -L/home/aldo/raspi/sysroot/usr/lib/
#LIBS += -L/home/aldo/raspi/sysroot/usr/lib -lwiringPi

CONFIG += link_pkgconfig
CONFIG += c++11 console
CONFIG   -= app_bundle

#PKGCONFIG += opencv


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mat2qimage.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

INSTALLS        = target
target.files    = widgettest
target.path     = /home/pi
