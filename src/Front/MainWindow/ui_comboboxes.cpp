#include "mainwindow.h"

void MainWindow::on_comboBox_projection_activated(int index) {
  if (index == 0) {
    ui->widget->projection_mode_ = glView::Central;
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->projection_mode_ = glView::Parallel;
    ui->widget->update();
  }
}

void MainWindow::on_comboBox_typeLine_activated(int index) {
  if (index == 0) {
    ui->widget->line_mode_ = glView::Solid;
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->line_mode_ = glView::Dashed;
    ui->widget->update();
  }
}

void MainWindow::on_comboBox_typeVertex_activated(int index) {
  if (index == 0) {
    ui->widget->vertex_mode_ = glView::Empty;
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->vertex_mode_ = glView::Circle;
    ui->widget->update();
  } else if (index == 2) {
    ui->widget->vertex_mode_ = glView::Square;
    ui->widget->update();
  }
}
