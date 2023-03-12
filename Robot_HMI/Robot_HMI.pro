#-------------------------------------------------
#
# Project created by QtCreator 2022-03-13T10:56:16
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robot_HMI
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qsixface.cpp \
    fullmode.cpp \
    manumode.cpp \
    simplemode.cpp \
    networkservice.cpp \
    setupmode.cpp \
    calibrationsetup.cpp \
    lightsetup.cpp \
    speedsetup.cpp \
    messagebox.cpp \
    randomsetup.cpp

HEADERS += \
        mainwindow.h \
    qsixface.h \
    fullmode.h \
    manumode.h \
    simplemode.h \
    networkservice.h \
    setupmode.h \
    calibrationsetup.h \
    lightsetup.h \
    speedsetup.h \
    messagebox.h \
    randomsetup.h

FORMS += \
        mainwindow.ui \
    fullmode.ui \
    manumode.ui \
    simplemode.ui \
    setupmode.ui \
    calibrationsetup.ui \
    lightsetup.ui \
    speedsetup.ui \
    messagebox.ui \
    randomsetup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/project/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

INCLUDEPATH += /home/lolita/opencv-4.5.4-for-raspi/install-opencv/include/opencv4
LIBS += /home/lolita/opencv-4.5.4-for-raspi/install-opencv/lib/libopencv*.so
