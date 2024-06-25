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
  } else
    ui->widget->scaleChange(scaleFactor);
}

void MainWindow::on_scaleEdit_returnPressed() {
  on_pushButton_Scale_clicked();
}

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
