#include "glview.h"

/* --- инициализация --- */

void glView::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10, 10, -10, 10, 200, -200);
}

void glView::paintGL() {
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(3, GL_DOUBLE, 0, vertex_pointer);
  glDrawElements(GL_LINES, indexes_count, GL_UNSIGNED_INT, indexes_pointer);
  glDisableClientState(GL_VERTEX_ARRAY);
}

/* --- обработка модели --- */

void glView::openFile(QString filenameLocal) {
  QByteArray qfilename = filenameLocal.toLocal8Bit();
  const char *filename = qfilename.data();
  int vCount = 0;
  int fCount = 0;
  controller::readFile(filename, vCount, fCount);
  deletePointers();
  double *vArray{new double[vCount]};
  for (int i = 0; i < vCount; i++) {
    vArray[i] = 0;
  }
  unsigned int *fArray{new unsigned int[fCount * 2]};
  for (int i = 0; i < fCount * 2; i++) {
    fArray[i] = 0;
  }
  controller::createArrays(vArray, fArray, filename);
  vertex_pointer = vArray;
  indexes_pointer = fArray;
  indexes_count = fCount * 2;
  vertex_count = vCount;
  xdegree = 0;
  ydegree = 0;
  zdegree = 0;
  xshift = 0;
  yshift = 0;
  zshift = 0;
  scale = 1;
  update();
}

void glView::deletePointers() {
  if (vertex_pointer != NULL) {
    delete[] vertex_pointer;
  }
  if (indexes_pointer != NULL) {
    delete[] indexes_pointer;
  }  
}

/* --- трансформация модели --- */

void glView::turnX(double xDeg) {
  RotateTransformation rotateX(0);
  controller::xturnMatrix(vertex_pointer, vertex_count, xdegree);
  xdegree = -xDeg;
  controller::xturnMatrix(vertex_pointer, vertex_count, xDeg);
  update();
}

void glView::turnY(double yDeg) {
  RotateTransformation rotateY(1);
  controller::yturnMatrix(vertex_pointer, vertex_count, ydegree);
  ydegree = -yDeg;
  controller::yturnMatrix(vertex_pointer, vertex_count, yDeg);
  update();
}

void glView::turnZ(double zDeg) {
  RotateTransformation rotateZ(2);
  controller::zturnMatrix(vertex_pointer, vertex_count, zdegree);
  zdegree = -zDeg;
  controller::zturnMatrix(vertex_pointer, vertex_count, zDeg);
  update();
}

void glView::shiftX(double xshiftLocal) {
  MoveTransformation shiftX(0);
  controller::moveMatrixXbyA(vertex_pointer, vertex_count, xshift);
  xshift = -xshiftLocal;
  controller::moveMatrixXbyA(vertex_pointer, vertex_count, xshiftLocal);
  update();
}

void glView::shiftY(double yshiftLocal) {
  MoveTransformation shiftY(1);
  controller::moveMatrixXbyB(vertex_pointer, vertex_count, yshift);
  yshift = -yshiftLocal;
  controller::moveMatrixXbyB(vertex_pointer, vertex_count, yshiftLocal);
  update();
}

void glView::shiftZ(double zshiftLocal) {
  MoveTransformation shiftZ(2);
  controller::moveMatrixXbyC(vertex_pointer, vertex_count, zshift);
  zshift = -zshiftLocal;
  controller::moveMatrixXbyC(vertex_pointer, vertex_count, zshiftLocal);
  update();
}

void glView::scaleChange(double scaleLocal) {
  ScaleTransformation scaleT;
  controller::scaleMatrix(vertex_pointer, vertex_count, scale);
  scale = 1 / scaleLocal;
  controller::scaleMatrix(vertex_pointer, vertex_count, scaleLocal);
  update();
}
