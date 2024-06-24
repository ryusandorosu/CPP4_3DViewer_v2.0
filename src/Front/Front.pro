QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    glview.cpp \
    ../Back/fileReaderPlus.cc \
    ../Controller/controller.cc \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    glview.h \
    observer.h \
    ../Back/fileReaderPlus.h \
    ../Back/matrix_transformation.h \
    ../Back/model_facade.h \
    ../Controller/controller.h \
    mainwindow.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Cute_Elephant.obj \
    Cute_Elephant.obj \
    cuberubik.obj \
    webtrcc.obj
