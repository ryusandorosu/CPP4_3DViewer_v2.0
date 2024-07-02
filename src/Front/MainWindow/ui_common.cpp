#include "mainwindow.h"

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
