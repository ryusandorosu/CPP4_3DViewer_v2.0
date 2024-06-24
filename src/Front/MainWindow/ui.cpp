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

void MainWindow::on_comboBox_projection_activated(int index) {  // bonus 1
  if (index == 0) {
    ui->widget->projectionMode = 0; // central
    ui->widget->update();
  } else if (index == 1) {
    ui->widget->projectionMode = 1; // parallel
    ui->widget->update();
  }
}
