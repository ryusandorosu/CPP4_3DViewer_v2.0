#include "mainwindow.h"

void MainWindow::saveSettings() {
  QString settingsPath =
      QCoreApplication::applicationDirPath() + "/" + settingsFile;
  QSettings settings(settingsPath, QSettings::IniFormat);

  if (QFile::exists(settingsFile)) {
    QFile::remove(settingsFile);
  }

  // Save combo box indexes
  settings.setValue("projectionIndex", ui->comboBox_projection->currentIndex());
  // qDebug() << ui->comboBox_projection->currentIndex();
  settings.setValue("edgeIndex", ui->comboBox_typeLine->currentIndex());
  settings.setValue("verticleIndex", ui->comboBox_typeVertex->currentIndex());

  // Save slider values
  settings.setValue("edgeThickness", ui->edge_thickness_edit->text());
  settings.setValue("vertexThickness", ui->vertex_thickness_edit->text());

  // Save colors
  settings.setValue(
      "backgroundColor",
      ui->graphics_background_color->palette().color(QPalette::Window));
  settings.setValue(
      "edgeColor", ui->graphics_color_edges->palette().color(QPalette::Window));
  settings.setValue(
      "vertexColor",
      ui->graphics_verticles_color->palette().color(QPalette::Window));
}
/*
void MainWindow::loadSettings() {
  QString settingsPath =
      QCoreApplication::applicationDirPath() + "/" + settingsFile;
  QSettings settings(settingsPath, QSettings::IniFormat);

  //  load combo box values
  glView::ProjectionMode projectionIndex = settings.value("projectionIndex", 0).toInt();
  glView::LineMode edgeIndex = settings.value("edgeIndex", 0).toInt();
  glView::VertexMode verticleIndex = settings.value("verticleIndex", 0).toInt();

  ui->comboBox_projection->setCurrentIndex(projectionIndex);
  ui->comboBox_typeLine->setCurrentIndex(edgeIndex);
  ui->comboBox_typeVertex->setCurrentIndex(verticleIndex);

  ui->widget->projection_mode_ = projectionIndex;
  ui->widget->line_mode_ = edgeIndex;
  ui->widget->vertex_mode_ = verticleIndex;

  // load slider values
  ui->edge_thickness_edit->setValue(
      settings.value("edgeThickness", 1).toInt());
  ui->vertex_thickness_edit->setValue(
      settings.value("vertexThickness", 1).toInt());

  // load colors
  QColor bgColor = settings.value("backgroundColor").value<QColor>();
  QColor edgeColor = settings.value("edgeColor").value<QColor>();
  QColor verticleColor = settings.value("vertexColor").value<QColor>();

  ui->graphics_background_color->setPalette(QPalette(bgColor));
  ui->graphics_color_edges->setPalette(QPalette(edgeColor));
  ui->graphics_verticles_color->setPalette(QPalette(verticleColor));

  QString backgroundQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(bgColor.name());
  ui->graphics_background_color->setStyleSheet(backgroundQSS);

  QString edgeQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(edgeColor.name());
  ui->graphics_color_edges->setStyleSheet(edgeQSS);

  QString verticleQSS =
      QString("background-color: %1;\nborder:1px solid;\n border-color: black;")
          .arg(verticleColor.name());
  ui->graphics_verticles_color->setStyleSheet(verticleQSS);

  ui->widget->backgroundColor = bgColor;
  ui->widget->edgeColor = edgeColor;
  ui->widget->verticleColor = verticleColor;

  ui->widget->update();
}
*/