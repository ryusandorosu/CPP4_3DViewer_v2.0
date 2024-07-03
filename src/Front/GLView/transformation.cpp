#include "glview.h"

void glView::scaleChange(double scaleLocal) {
  controller::scaleMatrix(vertex_pointer, vertex_count, scale);
  scale = 1 / scaleLocal;
  controller::scaleMatrix(vertex_pointer, vertex_count, scaleLocal);
  update();
}

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

/* setters */
double glView::setScale(double scaleLocal) {
  scale = scaleLocal;
  return scale;
}
