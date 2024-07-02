QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix:!macx {
    message("Building for Linux")
    LIBS += -lGLU
}

macx {
    message("Building for macOS")
    LIBS += -framework OpenGL -framework GLUT
}

SOURCES += \
    ../Back/fileReaderPlus.cc \
    ../Controller/controller.cc \
    main.cpp \
    GLView/glview.cpp \
    GLView/file_opening.cpp \
    GLView/transformation.cpp \
    MainWindow/mainwindow.cpp \
    MainWindow/defaults.cpp \
    MainWindow/settings.cpp \
    MainWindow/setup.cpp \
    MainWindow/transformation.cpp \
    MainWindow/ui_buttons.cpp \
    MainWindow/ui_comboboxes.cpp \
    MainWindow/ui_common.cpp

HEADERS += \
    ../Back/fileReaderPlus.h \
    ../Back/matrix_transformation.h \
    ../Back/model_facade.h \
    ../Controller/controller.h \
    observer.h \
    GLView/glview.h \
    MainWindow/mainwindow.h

FORMS += \
    MainWindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Cute_Elephant.obj \
    Cute_Elephant.obj \
    cuberubik.obj \
    webtrcc.obj
