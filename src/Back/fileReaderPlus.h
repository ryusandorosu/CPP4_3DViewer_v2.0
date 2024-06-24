#ifndef S21_FILEREADERPLUS_H
#define S21_FILEREADERPLUS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

class model {
 public:
  model();
  ~model();
  model(const model &) = delete;
  model &operator=(const model &) = delete;

 public:
  static int arraysCreate(double *vArray, unsigned int *fArray, char *filename);
  static void reader(char *filename, int *vCount, int *fCount);

 private:
  static void convertFLine(char *line);
  static void swap(unsigned int *a, unsigned int *b);
};

#endif  // S21_FILEREADERPLUS_H
