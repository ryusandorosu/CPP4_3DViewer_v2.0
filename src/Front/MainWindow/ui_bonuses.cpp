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

/* gif animation */

void MainWindow::create_screen() {
  if (flag_record == 0) {
    return;
  }

  QPixmap pixmap = ui->widget->grab();  // скриншот
  QImage image = pixmap.toImage();

  mkr_image.push_back(image);  // Добавляем скриншот в вектор кадров

  elapsedTime += 1;

  if (elapsedTime >= 5.0) {
    save_gif();
    timer_for_gif.stop();
  }
}

void MainWindow::save_gif() {
  QString gifFilePath = QFileDialog::getSaveFileName(this, tr("Save GIF"), "",
                                                     tr("GIF Files (*.gif)"));

  if (!gifFilePath.isEmpty()) {
    QGifImage gif(QSize(640, 480));  // Создаем объект GIF анимации

    // Добавляем кадры из вектора mkr_image
    for (const QImage& image : mkr_image) {
      gif.addFrame(image);
    }

    gif.save(gifFilePath);

    mkr_image.clear();  // Очищаем вектор кадров
    // Сбрасываем:
    flag_record = 0;
    elapsedTime = 0;
    ui->rec_button->setStyleSheet("");  // reset
  }
}
