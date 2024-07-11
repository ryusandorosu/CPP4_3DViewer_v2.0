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

void MainWindow::loadSettings() {
  QString settingsPath =
      QCoreApplication::applicationDirPath() + "/" + settingsFile;
  QSettings settings(settingsPath, QSettings::IniFormat);

  //  load combo box values
  int projectionIndexInt = settings.value("projectionIndex", 0).toInt();
  int edgeIndexInt = settings.value("edgeIndex", 0).toInt();
  int verticleIndexInt = settings.value("verticleIndex", 0).toInt();

  glView::ProjectionMode projectionIndex = glView::Central;  // default
  if (projectionIndexInt == 0) {
    projectionIndex = glView::Central;
  } else if (projectionIndexInt == 1) {
    projectionIndex = glView::Parallel;
  }

  glView::LineMode edgeIndex = glView::Solid;  // default
  if (edgeIndexInt == 0) {
    edgeIndex = glView::Solid;
  } else if (edgeIndexInt == 1) {
    edgeIndex = glView::Dashed;
  }

  glView::VertexMode verticleIndex = glView::Empty;  // default
  if (verticleIndexInt == 0) {
    verticleIndex = glView::Empty;
  } else if (verticleIndexInt == 1) {
    verticleIndex = glView::Circle;
  } else if (verticleIndexInt == 2) {
    verticleIndex = glView::Square;
  }

  ui->comboBox_projection->setCurrentIndex(projectionIndex);
  ui->comboBox_typeLine->setCurrentIndex(edgeIndex);
  ui->comboBox_typeVertex->setCurrentIndex(verticleIndex);

  ui->comboBox_projection->activated(projectionIndex);
  ui->comboBox_typeLine->activated(edgeIndex);
  ui->comboBox_typeVertex->activated(verticleIndex);

  ui->widget->projection_mode = projectionIndex;
  ui->widget->line_mode = edgeIndex;
  ui->widget->vertex_mode = verticleIndex;

  // load slider values
  QString edgeThicknessQ = settings.value("edgeThickness", 1).toString();
  QString vertexThicknessQ = settings.value("vertexThickness", 1).toString();

  ui->edge_thickness_edit->setText(edgeThicknessQ);
  ui->vertex_thickness_edit->setText(vertexThicknessQ);

  ui->widget->edgeThickness = settings.value("edgeThickness", 1).toInt();
  ui->widget->verticleSize = settings.value("vertexThickness", 1).toInt();

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
