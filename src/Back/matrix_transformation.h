#ifndef CPP4_3DVIEWER_V2_0_2_SRC_BACK_MATRIX_TRANSFORMATION_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_BACK_MATRIX_TRANSFORMATION_H_

#include <cmath>

class MatrixTransformation {
 public:
  virtual void transform(double *vArray, int vCount, double param) = 0;
};

class ScaleTransformation : public MatrixTransformation {
 public:
  void transform(double *vArray, int vCount, double scale) override {
    for (int i = 0; i < vCount; i += 3) {
      vArray[i] *= scale;
      vArray[i + 1] *= scale;
      vArray[i + 2] *= scale;
    }
  }
};

class MoveTransformation : public MatrixTransformation {
 public:
  MoveTransformation(int axis) : axis(axis) {}

  void transform(double *vArray, int vCount, double shift) override {
    for (int i = 0; i < vCount; i += 3) {
      vArray[i + axis] += shift;
    }
  }

 private:
  int axis;
};

class RotateTransformation : public MatrixTransformation {
 public:
  RotateTransformation(int axis) : axis(axis) {}

  void transform(double *vArray, int vCount, double angle) override {
    double rad = angle * M_PI / 180;
    for (int i = 0; i < vCount; i += 3) {
      double x = vArray[i];
      double y = vArray[i + 1];
      double z = vArray[i + 2];
      if (axis == 0) {  // X
        vArray[i + 1] = y * cos(rad) - z * sin(rad);
        vArray[i + 2] = y * sin(rad) + z * cos(rad);
      } else if (axis == 1) {  // Y
        vArray[i] = x * cos(rad) + z * sin(rad);
        vArray[i + 2] = -x * sin(rad) + z * cos(rad);
      } else if (axis == 2) {  // Z
        vArray[i] = x * cos(rad) - y * sin(rad);
        vArray[i + 1] = x * sin(rad) + y * cos(rad);
      }
    }
  }

 private:
  int axis;
};

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_BACK_MATRIX_TRANSFORMATION_H_
