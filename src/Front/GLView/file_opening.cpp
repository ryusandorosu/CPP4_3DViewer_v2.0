#include "glview.h"

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
  // will need to move these to defaults:
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
