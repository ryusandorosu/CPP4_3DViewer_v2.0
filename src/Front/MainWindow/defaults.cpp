#include "mainwindow.h"

void MainWindow::defaultSliders() {
  double scaleDefault = 1;
  ui->scaleEdit->setText(QString::number(scaleDefault));
  ui->widget->setScale(scaleDefault);

  double defaultValue = 0;
  ui->horizontalSlider_X_rotation->setValue(defaultValue);
  ui->horizontalSlider_Y_rotation->setValue(defaultValue);
  ui->horizontalSlider_Z_rotation->setValue(defaultValue);
  ui->horizontalSlider_X_moving->setValue(defaultValue);
  ui->horizontalSlider_Y_moving->setValue(defaultValue);
  ui->horizontalSlider_Z_moving->setValue(defaultValue);

  ui->widget->setTurnX(defaultValue);
  ui->widget->setTurnY(defaultValue);
  ui->widget->setTurnZ(defaultValue);
  ui->widget->setShiftX(defaultValue);
  ui->widget->setShiftY(defaultValue);
  ui->widget->setShiftZ(defaultValue);
}

void MainWindow::defaultSettings() {
  defaultSliders();
  defaultColors();
  
  glView::ProjectionMode projectionDefault = glView::Central;
  ui->comboBox_projection->activated(projectionDefault);
  ui->comboBox_projection->setCurrentIndex(projectionDefault);

  glView::LineMode edgeDefault = glView::Solid;
  ui->comboBox_typeLine->activated(edgeDefault);
  ui->comboBox_typeLine->setCurrentIndex(edgeDefault);
  
  glView::VertexMode verticleDefault = glView::Empty;
  ui->comboBox_typeVertex->activated(verticleDefault);
  ui->comboBox_typeVertex->setCurrentIndex(verticleDefault);
  
  int edgeThicknessDefault = 1;
  ui->edge_thickness_edit->setText(QString::number(edgeThicknessDefault));
  ui->widget->edgeThickness = edgeThicknessDefault;

  int verticleSizeDefault = 5;
  ui->vertex_thickness_edit->setText(QString::number(verticleSizeDefault));
  ui->widget->verticleSize = verticleSizeDefault;
}

void MainWindow::defaultColors() {
  // Background
  ui->widget->backgroundColor = QColor(64, 64, 64);
  QColor backgroundDefaultColor = ui->widget->backgroundColor;
  QString backgroundQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(backgroundDefaultColor.name());
  ui->graphics_background_color->setStyleSheet(backgroundQSS);

  // Edges
  ui->widget->edgeColor = QColor(0, 0, 0);
  QColor edgeDefaultColor = ui->widget->edgeColor;
  QString edgeQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(edgeDefaultColor.name());
  ui->graphics_color_edges->setStyleSheet(edgeQSS);

  // Verticles
  ui->widget->verticleColor = QColor(255, 0, 0);
  QColor verticleDefaultColor = ui->widget->verticleColor;
  QString verticleQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(verticleDefaultColor.name());
  ui->graphics_verticles_color->setStyleSheet(verticleQSS);
}
