#include "mainwindow.h"

void MainWindow::sliderSetup() {
  ui->scaleEdit->setText("1");
  ui->horizontalSlider_X_rotation->setValue(0);
  ui->horizontalSlider_Y_rotation->setValue(0);
  ui->horizontalSlider_Z_rotation->setValue(0);
  ui->horizontalSlider_X_moving->setValue(0);
  ui->horizontalSlider_Y_moving->setValue(0);
  ui->horizontalSlider_Z_moving->setValue(0);
}

void MainWindow::connectSetup() {
  connect(ui->scaleEdit, &QLineEdit::returnPressed, this, &MainWindow::on_scaleEdit_returnPressed);
}

void MainWindow::statusBarUpdate() {
  int vertexCount = ui->widget->vertexCountReturn();
  int edgeCount = ui->widget->indexesCountReturn();

  QString vertexCountStr = QString::number(vertexCount);
  QString edgeCountStr = QString::number(edgeCount);

  ui->statusBar->showMessage(tr("Vertices: %1 | Edges: %2").arg(vertexCountStr).arg(edgeCountStr));
}
