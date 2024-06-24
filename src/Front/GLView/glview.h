#ifndef GLVIEW_H
#define GLVIEW_H

#include <locale.h>
#include <string.h>

#include <QFileDialog>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>

#include "../../Back/model_facade.h"
#include "../../Controller/controller.h"
#include "../observer.h"

class glView : public QOpenGLWidget, public Observer {
 public:
  glView(QWidget *parent = 0) : QOpenGLWidget(parent) {};
  ~glView() { deletePointers(); };

  void initializeGL() override;
  void resizeGL(int w, int h) override { glViewport(0, 0, w, h); };
  void paintGL() override;

  void scaleChange(double scaleLocal);

  void turnX(double xDeg);
  void turnY(double yDeg);
  void turnZ(double zDeg);

  void shiftX(double xshiftLocal);
  void shiftY(double yshiftLocal);
  void shiftZ(double zshiftLocal);

  void openFile(QString filenameLocal);
  void deletePointers();
  int vertexCountReturn() { return vertex_count / 3; };
  int indexesCountReturn() { return indexes_count / 2; };

  // обновление рендера
  void update() override { QOpenGLWidget::update(); };

 protected:
  // void wheelEvent(QWheelEvent *event) override;

 private:
  double scale = 1;
  double xdegree = 0;
  double ydegree = 0;
  double zdegree = 0;
  double xshift = 0;
  double yshift = 0;
  double zshift = 0;
  double *vertex_pointer = NULL;
  int vertex_count = 0;
  unsigned int *indexes_pointer = NULL;
  int indexes_count = 0;
  char *filename = NULL;
};

#endif  // GLVIEW_H
