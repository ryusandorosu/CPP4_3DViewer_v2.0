#include "mainwindow.h"

/* buttons */

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

void MainWindow::on_background_color_button_clicked() {
  selectAndSetColor(ui->widget->backgroundColor, ui->graphics_background_color);
}

/* combo boxes */

void MainWindow::on_comboBox_projection_activated(int index) {  // bonus 1.1
  if (index == 0) {
    ui->widget->projection_mode_ = glView::Central;
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->projection_mode_ = glView::Parallel;
    ui->widget->update();
  }
}

void MainWindow::on_comboBox_typeLine_activated(int index) {  // bonus 1.2
  if (index == 0) {
    ui->widget->line_mode_ = glView::Solid;
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->line_mode_ = glView::Dashed;
    ui->widget->update();
  }
}

void MainWindow::on_comboBox_typeVertex_activated(int index) {  // bonus 1.2
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

/* other */

void MainWindow::selectAndSetColor(QColor& targetColor, QGraphicsView* targetLabel) {
  QColorDialog dialog;
  dialog.setOption(QColorDialog::ShowAlphaChannel);

  if (dialog.exec() == QDialog::Accepted) {
    QColor color = dialog.selectedColor();
    if (color.isValid()) {
      targetColor = color;
      QString qss =
          QString(
              "background-color: %1;\nborder:1px solid;\n border-color: black;")
              .arg(color.name());
      targetLabel->setStyleSheet(qss);
      ui->widget->update();
    }
  }
}
