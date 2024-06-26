#ifndef CPP4_3DVIEWER_V2_0_2_SRC_FRONT_MAINWINDOW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_FRONT_MAINWINDOW_MAINWINDOW_H_

#include <locale.h>

#include <QFileDialog>
#include <QMainWindow>
#include <QtWidgets>

#include "../GLView/glview.h"
#include "ui_mainwindow.h"

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
  /* ui: buttons */
  void on_toolButton_clicked();
  void on_pushButton_Scale_clicked();
  void on_pushButton_Edge_clicked();  // bonus 1.2
  void on_pushButton_Vertex_clicked();  // bonus 1.2
  void on_background_color_button_clicked();  // bonus 1.3
  void on_color_edges_button_clicked();       // bonus 1.2
  void on_color_verticles_button_clicked();   // bonus 1.2

  void selectAndSetColor(QColor& targetColor, QGraphicsView* targetLabel);  // bonus 1.2, 1.3

  /* ui: reacting to enter */
  void on_scaleEdit_returnPressed() { on_pushButton_Scale_clicked(); };
  void on_edgeEdit_returnPressed() { on_pushButton_Edge_clicked(); };
  void on_vertexEdit_returnPressed() { on_pushButton_Vertex_clicked(); };

  /* ui: combo boxes */
  void on_comboBox_projection_activated(int index); // bonus 1.1
  void on_comboBox_typeLine_activated(int index);   // bonus 1.2
  void on_comboBox_typeVertex_activated(int index);   // bonus 1.2

  /* transformation */
  void on_horizontalSlider_X_rotation_valueChanged(int value);
  void on_horizontalSlider_Y_rotation_valueChanged(int value);
  void on_horizontalSlider_Z_rotation_valueChanged(int value);

  void on_horizontalSlider_X_moving_valueChanged(int value);
  void on_horizontalSlider_Y_moving_valueChanged(int value);
  void on_horizontalSlider_Z_moving_valueChanged(int value);

 private:
  Ui::MainWindow *ui;
  glView mView;
  QString settingsFile = "settings.conf"; // bonus 1.4

  /* setup */
  void sliderSetup();
  void connectSetup();
  void statusBarUpdate();
  void defaultColors(); // bonus 1.2, 1.3

  /* settings */
  void saveSettings();  // bonus 1.4
  //void loadSettings();  // bonus 1.4
};
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_FRONT_MAINWINDOW_MAINWINDOW_H_
