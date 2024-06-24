#include "controller.h"

#include "../Back/matrix_transformation.h"
#include "../Back/model_facade.h"

void controller::createArrays(double *vArray, unsigned int *fArray,
                              const char *filename) {
  ModelFacade::createArrays(vArray, fArray, filename);
}

void controller::readFile(const char *filename, int &vCount, int &fCount) {
  ModelFacade::readFile(filename, vCount, fCount);
}

void controller::scaleMatrix(double *vArray, int vCount, double scale) {
  ScaleTransformation scaleT;
  ModelFacade::applyTransformation(&scaleT, vArray, vCount, scale);
}

void controller::xturnMatrix(double *vArray, int vCount, int angle) {
  RotateTransformation rotateX(0);
  ModelFacade::applyTransformation(&rotateX, vArray, vCount, angle);
}

void controller::yturnMatrix(double *vArray, int vCount, int angle) {
  RotateTransformation rotateY(1);
  ModelFacade::applyTransformation(&rotateY, vArray, vCount, angle);
}

void controller::zturnMatrix(double *vArray, int vCount, int angle) {
  RotateTransformation rotateZ(2);
  ModelFacade::applyTransformation(&rotateZ, vArray, vCount, angle);
}

void controller::moveMatrixXbyA(double *vArray, int vCount, double a) {
  MoveTransformation moveX(0);
  ModelFacade::applyTransformation(&moveX, vArray, vCount, a);
}

void controller::moveMatrixXbyB(double *vArray, int vCount, double b) {
  MoveTransformation moveY(1);
  ModelFacade::applyTransformation(&moveY, vArray, vCount, b);
}

void controller::moveMatrixXbyC(double *vArray, int vCount, double c) {
  MoveTransformation moveZ(2);
  ModelFacade::applyTransformation(&moveZ, vArray, vCount, c);
}
