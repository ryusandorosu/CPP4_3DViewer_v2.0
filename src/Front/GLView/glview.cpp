#include "glview.h"

// инициализация
void glView::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10, 10, -10, 10, 200, -200);
}

// отрисовка
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
