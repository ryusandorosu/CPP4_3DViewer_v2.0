#ifndef CPP4_3DVIEWER_V2_0_2_SRC_FRONT_GLVIEW_GLVIEW_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_FRONT_GLVIEW_GLVIEW_H_

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

  /* variables*/
  enum ProjectionMode { Central, Parallel };
  enum LineMode { Solid, Dashed };
  enum VertexMode { Empty, Circle, Square };
  ProjectionMode projection_mode_ = Central;
  LineMode line_mode_;
  VertexMode vertex_mode_;
  int edgeThickness = 1, verticleSize = 5;
  QColor backgroundColor;

  /* glview */
  void initializeGL() override;
  void resizeGL(int w, int h) override { glViewport(0, 0, w, h); };
  void paintGL() override;
  void setProjection(); // bonus 1.1
  void setLineMode();   // bonus 1.2
  void setVertexMode();   // bonus 1.2

  /* transformation */
  void scaleChange(double scaleLocal);

  void turnX(double xDeg);
  void turnY(double yDeg);
  void turnZ(double zDeg);

  void shiftX(double xshiftLocal);
  void shiftY(double yshiftLocal);
  void shiftZ(double zshiftLocal);

  /* file_opening */
  void openFile(QString filenameLocal);
  void deletePointers();
  int vertexCountReturn() { return vertex_count / 3; };
  int indexesCountReturn() { return indexes_count / 2; };

  // обновление рендера
  void update() override { QOpenGLWidget::update(); };

 protected:
  // void wheelEvent(QWheelEvent *event) override;

 private:
  /* variables */
  double scale = 1;
  double xdegree, ydegree, zdegree = 0;
  double xshift, yshift, zshift = 0;
  double *vertex_pointer = NULL;
  unsigned int *indexes_pointer = NULL;
  int vertex_count, indexes_count = 0;
  char *filename = NULL;
};

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_FRONT_GLVIEW_GLVIEW_H_
