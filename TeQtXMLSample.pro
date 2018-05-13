#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T11:02:50
#
#-------------------------------------------------

QT       += core gui xml
CONFIG += c++1z

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeQtXMLSample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    employee.cpp \
    addemployeedialog.cpp

HEADERS  += mainwindow.hpp \
    employee.hpp \
    addemployeedialog.hpp

FORMS    += mainwindow.ui \
    addemployeedialog.ui

RESOURCES += \
    res.qrc
