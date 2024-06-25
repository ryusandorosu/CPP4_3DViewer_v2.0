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
  setProjection();  // bonus 1.1
}

// отрисовка
void glView::paintGL() {
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  setProjection();  // bonus 1.1
  glEnableClientState(GL_VERTEX_ARRAY);
  setLineMode();    // bonus 1.2

  glVertexPointer(3, GL_DOUBLE, 0, vertex_pointer);
  glDrawElements(GL_LINES, indexes_count, GL_UNSIGNED_INT, indexes_pointer);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void glView::setProjection() {  // bonus 1.1
  if (projection_mode_ == Parallel) {
    // -fW, fW, -fH, fH, zNear, zFar
    glOrtho(-5, 8.3, -5, 5, -100, 100);
    // glOrtho(-10, 10, -10, 10, 200, -200);
    glTranslated(2, 0, -10);
  } else if (projection_mode_ == Central) {
    gluPerspective(45.0, 1.0, 1.0, 1000.0);
    glTranslated(0, 0, -10);
  }
}

void glView::setLineMode() {  // bonus 1.2
  if (line_mode_ == Dashed) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);  // dashed pattern
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
}
