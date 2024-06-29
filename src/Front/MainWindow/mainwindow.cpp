#include "mainwindow.h"
#include "setup.cpp"
#include "transformation.cpp"
#include "ui.cpp"

//#include "../GLView/glview.h"
//#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setWindowTitle("3DViewer_v2.0");
  connectSetup();
  defaultColors();
}

MainWindow::~MainWindow() { delete ui; }
