#include "mainwindow.h"

void MainWindow::on_background_color_button_clicked() {
  selectAndSetColor(ui->widget->backgroundColor, ui->graphics_background_color);
}
void MainWindow::on_color_edges_button_clicked() {
  selectAndSetColor(ui->widget->edgeColor, ui->graphics_color_edges);
}
void MainWindow::on_color_verticles_button_clicked() {
  selectAndSetColor(ui->widget->verticleColor, ui->graphics_verticles_color);
}

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
