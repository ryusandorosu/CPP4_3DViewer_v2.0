#ifndef CPP4_3DVIEWER_V2_0_2_SRC_BACK_MODEL_FACADE_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_BACK_MODEL_FACADE_H_

#include "matrix_transformation.h"
#include "parser.h"

class ModelFacade {
 public:
  static void readFile(const char *filename, int &vCount, int &fCount) {
    model::reader(const_cast<char *>(filename), &vCount, &fCount);
  }

  static void createArrays(double *vArray, unsigned int *fArray,
                           const char *filename) {
    model::arraysCreate(vArray, fArray, const_cast<char *>(filename));
  }

  static void applyTransformation(MatrixTransformation *transformation,
                                  double *vArray, int vCount, double param) {
    transformation->transform(vArray, vCount, param);
  }
};

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_BACK_MODEL_FACADE_H_
