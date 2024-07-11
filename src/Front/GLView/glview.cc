#include "glview.h"
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

// инициализация
void glView::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  setProjection();
}

// отрисовка
void glView::paintGL() {
  glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
               backgroundColor.blueF(), backgroundColor.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  setProjection();
  setVertexMode();
  setLineMode();
}

void glView::setProjection() {
  if (projection_mode == Parallel) {
    // -fW, fW, -fH, fH, zNear, zFar
    glOrtho(-5, 5, -5, 5, -100, 100);
    glTranslated(2, 0, -10);
  } else if (projection_mode == Central) {
    gluPerspective(45.0, 1.0, 1.0, 1000.0);
    glTranslated(0, 0, -10);
  }
}

void glView::setLineMode() {
  glColor3f(edgeColor.redF(), edgeColor.greenF(), edgeColor.blueF());
  glLineWidth(edgeThickness);

  if (line_mode == Dashed) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);  // dashed pattern
  } else {
    glDisable(GL_LINE_STIPPLE);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, vertex_pointer);
  glDrawElements(GL_LINES, indexes_count, GL_UNSIGNED_INT, indexes_pointer);
  glDisableClientState(GL_VERTEX_ARRAY);

  if (line_mode == Solid) {
    glDisable(GL_LINE_STIPPLE);
  }
}

void glView::setVertexMode() {
  if (vertex_mode != Empty) {
    glColor3f(verticleColor.redF(), verticleColor.greenF(),
              verticleColor.blueF());
    glPointSize(verticleSize);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, vertex_pointer);

    if (vertex_mode == Circle) {
      glEnable(GL_POINT_SMOOTH);
      glDrawArrays(GL_POINTS, 0, vertex_count / 3);
      glDisable(GL_POINT_SMOOTH);
    } else if (vertex_mode == Square) {
      glDrawArrays(GL_POINTS, 0, vertex_count / 3);
    }

    glDisableClientState(GL_VERTEX_ARRAY);
  }
}
