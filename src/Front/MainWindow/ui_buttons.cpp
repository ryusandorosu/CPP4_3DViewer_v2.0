#include "mainwindow.h"

void MainWindow::on_toolButton_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("*"));
  ui->widget->openFile(fileName);

  ui->file_name->setText(fileName);
  statusBarUpdate();

  sliderSetup();  //сброс параметров при загрузке новой модели
}

void MainWindow::on_pushButton_Scale_clicked() {
  double scaleFactor = ui->scaleEdit->text().toDouble();
  if (scaleFactor <= 0) {
    QMessageBox::warning(this, "Ошибка", "Масштаб должен быть больше нуля");
    ui->scaleEdit->clear();
  } else {
    ui->widget->scaleChange(scaleFactor);
  }
}

void MainWindow::on_pushButton_Edge_clicked() {
  int edgeSize = ui->edge_thickness_edit->text().toInt();
  if (edgeSize <= 0) {
    QMessageBox::warning(this, "Ошибка", "Масштаб должен быть больше нуля");
    ui->edge_thickness_edit->clear();
  } else {
    ui->widget->edgeThickness = edgeSize;
    ui->widget->update();
  }
}

void MainWindow::on_pushButton_Vertex_clicked() {
  int vertexSize = ui->vertex_thickness_edit->text().toInt();
  if (vertexSize <= 0) {
    QMessageBox::warning(this, "Ошибка", "Масштаб должен быть больше нуля");
    ui->edge_thickness_edit->clear();
  } else {
    ui->widget->verticleSize = vertexSize;
    ui->widget->update();
  }
}
