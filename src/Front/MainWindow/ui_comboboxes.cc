#include "mainwindow.h"

void MainWindow::on_comboBox_projection_activated(int index) {
  if (index == 0) {
    ui->widget->projection_mode = glView::Central;
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->projection_mode = glView::Parallel;
    ui->widget->update();
  }
}

void MainWindow::on_comboBox_typeLine_activated(int index) {
  if (index == 0) {
    ui->widget->line_mode = glView::Solid;
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->line_mode = glView::Dashed;
    ui->widget->update();
  }
}

void MainWindow::on_comboBox_typeVertex_activated(int index) {
  if (index == 0) {
    ui->widget->vertex_mode = glView::Empty;
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->vertex_mode = glView::Circle;
    ui->widget->update();
  } else if (index == 2) {
    ui->widget->vertex_mode = glView::Square;
    ui->widget->update();
  }
}
