#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <locale.h>

#include <QFileDialog>
#include <QMainWindow>
#include <QtWidgets>

#include "glview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_toolButton_clicked();
  void on_horizontalSlider_X_rotation_valueChanged(int value);
  void on_horizontalSlider_Y_rotation_valueChanged(int value);
  void on_horizontalSlider_Z_rotation_valueChanged(int value);
  void on_horizontalSlider_X_moving_valueChanged(int value);
  void on_horizontalSlider_Y_moving_valueChanged(int value);
  void on_horizontalSlider_Z_moving_valueChanged(int value);

  void on_pushButton_Scale_clicked();
  void on_scaleEdit_returnPressed();  // реагирует на энтер

 private:
  Ui::MainWindow *ui;
  glView mView;

  void sliderSetup(); // setup begins here
  void connectSetup();
  void statusBarUpdate();
};
#endif  // MAINWINDOW_H
