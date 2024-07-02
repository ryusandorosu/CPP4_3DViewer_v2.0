#include "mainwindow.h"
#include "settings.cpp"
#include "setup.cpp"
#include "transformation.cpp"
#include "ui_buttons.cpp"
#include "ui_comboboxes.cpp"
#include "ui_common.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setWindowTitle("3DViewer_v2.0");
  connectSetup();
  defaultColors();
  loadSettings(); // not here
}

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
}
