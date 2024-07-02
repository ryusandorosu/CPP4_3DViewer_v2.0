#include "mainwindow.h"

void MainWindow::sliderDefaultSetup() {
  ui->scaleEdit->setText("1");
  ui->horizontalSlider_X_rotation->setValue(0);
  ui->horizontalSlider_Y_rotation->setValue(0);
  ui->horizontalSlider_Z_rotation->setValue(0);
  ui->horizontalSlider_X_moving->setValue(0);
  ui->horizontalSlider_Y_moving->setValue(0);
  ui->horizontalSlider_Z_moving->setValue(0);

  // ui->comboBox_typeLine->activated(0);    // solid
  // ui->edge_thickness_edit->setText("1");

  // ui->comboBox_typeVertex->activated(0);  // empty
  // ui->vertex_thickness_edit->setText("5");
}

void MainWindow::connectSetup() {
  // scale
  connect(ui->scaleEdit, &QLineEdit::returnPressed, this, &MainWindow::on_scaleEdit_returnPressed);

  // edge parameters
  connect(ui->edge_thickness_edit, &QLineEdit::returnPressed, this, &MainWindow::on_edgeEdit_returnPressed);

  // verticle parameters
  connect(ui->vertex_thickness_edit, &QLineEdit::returnPressed, this, &MainWindow::on_vertexEdit_returnPressed);
}

void MainWindow::statusBarUpdate() {
  int vertexCount = ui->widget->vertexCountReturn();
  int edgeCount = ui->widget->indexesCountReturn();

  QString vertexCountStr = QString::number(vertexCount);
  QString edgeCountStr = QString::number(edgeCount);

  ui->statusBar->showMessage(tr("Vertices: %1 | Edges: %2").arg(vertexCountStr).arg(edgeCountStr));
}

void MainWindow::defaultColors() {
  // Background
  ui->widget->backgroundColor = QColor(64, 64, 64);
  QColor backgroundDefaultColor = ui->widget->backgroundColor;
  QString backgroundQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(backgroundDefaultColor.name());
  ui->graphics_background_color->setStyleSheet(backgroundQSS);

  // Edges
  ui->widget->edgeColor = QColor(0, 0, 0);
  QColor edgeDefaultColor = ui->widget->edgeColor;
  QString edgeQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(edgeDefaultColor.name());
  ui->graphics_color_edges->setStyleSheet(edgeQSS);

  // Verticles
  ui->widget->verticleColor = QColor(255, 0, 0);
  QColor verticleDefaultColor = ui->widget->verticleColor;
  QString verticleQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(verticleDefaultColor.name());
  ui->graphics_verticles_color->setStyleSheet(verticleQSS);
}
