#ifndef CPP4_3DVIEWER_V2_0_2_SRC_FRONT_MAINWINDOW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_FRONT_MAINWINDOW_MAINWINDOW_H_

#include <locale.h>

#include <QFileDialog>
#include <QMainWindow>
#include <QtWidgets>

#include "../GLView/glview.h"
#include "../resources/QtGifImage/include/gifimage/qgifimage.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  /* ui: buttons */
  void on_openButton_clicked();

  void on_pushButton_Scale_clicked();
  void on_pushButton_Edge_clicked();
  void on_pushButton_Vertex_clicked();

  void on_background_color_button_clicked();
  void on_color_edges_button_clicked();
  void on_color_verticles_button_clicked();

  void on_reset_values_button_clicked();

  void on_bmp_button_clicked();
  void on_jpeg_button_clicked();
  void on_gif_button_clicked();

  void selectAndSetColor(QColor& targetColor, QGraphicsView* targetLabel);

  void create_screen();
  void save_gif();

  /* ui: buttons - reacting to enter */
  void on_scaleEdit_returnPressed() { on_pushButton_Scale_clicked(); };
  void on_edgeEdit_returnPressed() { on_pushButton_Edge_clicked(); };
  void on_vertexEdit_returnPressed() { on_pushButton_Vertex_clicked(); };

  /* ui: combo boxes */
  void on_comboBox_projection_activated(int index);
  void on_comboBox_typeLine_activated(int index);
  void on_comboBox_typeVertex_activated(int index);

  /* ui: sliders - transformation */
  void on_horizontalSlider_X_rotation_valueChanged(int value);
  void on_horizontalSlider_Y_rotation_valueChanged(int value);
  void on_horizontalSlider_Z_rotation_valueChanged(int value);

  void on_horizontalSlider_X_moving_valueChanged(int value);
  void on_horizontalSlider_Y_moving_valueChanged(int value);
  void on_horizontalSlider_Z_moving_valueChanged(int value);

 private:
  Ui::MainWindow* ui;
  glView mView;
  QString settingsFile = "settings.conf";

  /* git recording */
  bool flag_record = false;
  double elapsedTime = 0;
  QVector<QImage> mkr_image;  // The vector for storing frames
  QTimer timer_for_gif;

  /* setup */
  void connectSetup();
  void statusBarUpdate();

  /* defaults */
  void defaultSliders();
  void defaultColors();
  void defaultSettings();

  /* settings */
  void saveSettings();
  void loadSettings();
};
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_FRONT_MAINWINDOW_MAINWINDOW_H_
