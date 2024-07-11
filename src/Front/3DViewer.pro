QT       += core gui opengl
include(resources/QTGifimage/src/gifimage/qtgifimage.pri)

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
    ../Back/parser.cc \
    ../Controller/controller.cc \
    main.cc \
    GLView/glview.cc \
    GLView/file_opening.cc \
    GLView/transformation.cc \
    MainWindow/mainwindow.cc \
    MainWindow/defaults.cc \
    MainWindow/settings.cc \
    MainWindow/setup.cc \
    MainWindow/ui_bonuses.cc \
    MainWindow/ui_buttons.cc \
    MainWindow/ui_comboboxes.cc \
    MainWindow/ui_sliders.cc

HEADERS += \
    ../Back/parser.h \
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
