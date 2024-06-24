#include "mainwindow.h"

#include "../GLView/glview.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setWindowTitle("3DViewer_v2.0");
  connectSetup();
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_toolButton_clicked() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("*"));
  ui->widget->openFile(fileName);

  ui->file_name->setText(fileName);
  statusBarUpdate();

  sliderSetup();  //сброс параметров при загрузке новой модели
}

/* --- setup begin --- */

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

/* --- setup  end  --- */

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
