#include "mainwindow.h"

void MainWindow::connectSetup() {
  // scale
  connect(ui->scaleEdit, &QLineEdit::returnPressed, this,
          &MainWindow::on_scaleEdit_returnPressed);

  // edge parameters
  connect(ui->edge_thickness_edit, &QLineEdit::returnPressed, this,
          &MainWindow::on_edgeEdit_returnPressed);

  // verticle parameters
  connect(ui->vertex_thickness_edit, &QLineEdit::returnPressed, this,
          &MainWindow::on_vertexEdit_returnPressed);

  // gif recording
  connect(ui->gif_button, &QPushButton::clicked, this,
          &MainWindow::on_gif_button_clicked);
  connect(&timer_for_gif, &QTimer::timeout, this, &MainWindow::create_screen);
}

void MainWindow::statusBarUpdate() {
  int vertexCount = ui->widget->vertexCountReturn();
  int edgeCount = ui->widget->indexesCountReturn();

  QString vertexCountStr = QString::number(vertexCount);
  QString edgeCountStr = QString::number(edgeCount);

  ui->statusBar->showMessage(
      tr("Vertices: %1 | Edges: %2").arg(vertexCountStr).arg(edgeCountStr));
}
