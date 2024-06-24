#include <QApplication>

#include "glview.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  // glView win;
  // win.show();
  MainWindow w;
  w.show();
  return a.exec();
}
