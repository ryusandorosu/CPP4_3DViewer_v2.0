#include "parser.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

void model::reader(char *filename, int *vCount, int *fCount) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("cant open file\n");
    return;
  }
  *vCount = 0;
  *fCount = 0;
  const char *shiftArray = " ";
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&line, &len, fp)) != -1) {
    if (len > 2) {
      if (*line == 'v' && *(line + 1) == ' ') {
        *vCount = *vCount + 3;
      }
      if (*line == 'f' && *(line + 1) == ' ') {
        char *tmp = line;
        while ((tmp = strstr(tmp, shiftArray))) {
          *fCount = *fCount + 1;
          tmp++;
          if (*tmp == ' ') {
            *fCount = *fCount - 1;
          }
          if (*tmp == '\n') {
            *fCount = *fCount - 1;
          }
        }
      }
    }
  }
  free(line);
  fclose(fp);
}

void model::convertFLine(char *line) {
  int check = 0;
  for (size_t i = 0; i < strlen(line); i++) {
    if (line[i] == '/') {
      check = 1;
    }
    if (line[i] == ' ') {
      check = 0;
    }
    if (check == 1) {
      line[i] = ' ';
    }
  }
}

void model::swap(unsigned int *a, unsigned int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

int model::arraysCreate(double *vArray, unsigned int *fArray, char *filename) {
  int vArrayCount = 0;
  int fArrayCount = 0;
  int vCountLocal = 0;
  int buffer = 0;
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return 1;
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&line, &len, fp)) != -1) {
    if (len > 2) {
      if (*line == 'v' && *(line + 1) == ' ') {
        vCountLocal++;
        sscanf(line + 2, "%lf%lf%lf", &vArray[vArrayCount],
               &vArray[vArrayCount + 1], &vArray[vArrayCount + 2]);
        vArrayCount = vArrayCount + 3;
      }
      if (*line == 'f' && *(line + 1) == ' ') {
        model::convertFLine(line);
        int lineCordsCount = 0;
        for (size_t k = 2; k < strlen(line);) {
          if (line[k] != ' ' && line[k] != '\n' && line[k] != '\r') {
            sscanf(&line[k], "%d", &buffer);
            if (buffer < 0) {
              buffer = buffer + vCountLocal + 1;
            }
            fArray[fArrayCount] = buffer;
            fArrayCount++;
            lineCordsCount++;
            sscanf(&line[k], "%d", &buffer);
            if (buffer < 0) {
              buffer = buffer + vCountLocal + 1;
            }
            fArray[fArrayCount] = buffer;
            fArrayCount++;
            lineCordsCount++;
            while (line[k] != ' ' && k < strlen(line)) {
              k++;
            }
          }
          k++;
        }
        int countbuffer = lineCordsCount;
        while (lineCordsCount > 1) {
          model::swap(&fArray[fArrayCount - lineCordsCount],
                      &fArray[fArrayCount - lineCordsCount + 1]);
          lineCordsCount--;
        }
        for (int m = countbuffer; m > 0; m--) {
          fArray[fArrayCount - m]--;
        }
      }
    }
  }
  free(line);
  fclose(fp);
  return 0;
}
