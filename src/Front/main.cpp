#include <QApplication>

#include "GLView/glview.h"
#include "MainWindow/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
