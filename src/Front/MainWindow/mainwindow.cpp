#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setWindowTitle("3DViewer_v2.0");
  connectSetup();
  defaultSettings();

  QString settingsPath = QCoreApplication::applicationDirPath() + "/" + settingsFile;
  if (QFile::exists(settingsPath)) {
    loadSettings();
  }
}

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
}
