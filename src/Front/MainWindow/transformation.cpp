#include "mainwindow.h"

void MainWindow::on_horizontalSlider_X_rotation_valueChanged(int value) {
  ui->label_X->setNum(value);
  ui->widget->turnX(ui->label_X->text().toDouble());
}
void MainWindow::on_horizontalSlider_Y_rotation_valueChanged(int value) {
  ui->label_Y->setNum(value);
  ui->widget->turnY(ui->label_Y->text().toDouble());
}
void MainWindow::on_horizontalSlider_Z_rotation_valueChanged(int value) {
  ui->label_Z->setNum(value);
  ui->widget->turnZ(ui->label_Z->text().toDouble());
}

void MainWindow::on_horizontalSlider_X_moving_valueChanged(int value) {
  ui->label_X_move->setNum(value);
  ui->widget->shiftX(ui->label_X_move->text().toDouble());
}
void MainWindow::on_horizontalSlider_Y_moving_valueChanged(int value) {
  ui->label_Y_move_->setNum(value);
  ui->widget->shiftY(ui->label_Y_move_->text().toDouble());
}
void MainWindow::on_horizontalSlider_Z_moving_valueChanged(int value) {
  ui->label_Z_move->setNum(value);
  ui->widget->shiftZ(ui->label_Z_move->text().toDouble());
}

void MainWindow::linesSizeSliderChanged(int value) {
  ui->widget->edgeThickness = value;
  ui->widget->update();
}

void MainWindow::vertexSizeSliderChanged(int value) {
  ui->widget->verticleSize = value;
  ui->widget->update();
}
