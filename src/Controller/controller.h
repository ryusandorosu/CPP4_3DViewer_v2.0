#ifndef S21_CONTROLLER_H
#define S21_CONTROLLER_H

#include "../Back/fileReaderPlus.h"

class controller {
 public:
  controller();
  ~controller();

 public:
  static void createArrays(double *vArray, unsigned int *fArray,
                           const char *filename);
  static void readFile(const char *filename, int &vCount, int &fCount);
  static void scaleMatrix(double *vArray, int vCount, double scale);
  static void xturnMatrix(double *vArray, int vCount, int angle);
  static void yturnMatrix(double *vArray, int vCount, int angle);
  static void zturnMatrix(double *vArray, int vCount, int angle);
  static void moveMatrixXbyA(double *vArray, int vCount, double a);
  static void moveMatrixXbyB(double *vArray, int vCount, double b);
  static void moveMatrixXbyC(double *vArray, int vCount, double c);
};

#endif  // S21_CONTROLLER_H