#include "compute.h"
#include <math.h>
int mm(float* A,
       float* B,
       int widA,
       int widB,
       int heightA,
       int heightB,
       float* res) {
  if (widA != heightB) {
    return 1;
  }
  for (int i = 0; i < heightA; i++) {
    for (int j = 0; j < widB; j++) {
      float buf = 0;
      for (int k = 0; k < widA; k++) {
        buf += A[i * widA + k] * B[k * widB + j];
      }
      res[i * widB + j] = buf;
    }
  }
  return 0;
}

int relu(float* M, int length) {
  for (int i = 0; i < length; i++) {
    M[i] = M[i] < 0 ? 0 : M[i];
  }
  return 0;
}

int softmax(float* V, int length, void* buf) {
  long double sum = 0;
  long double* bufp = (long double*)buf;
  for (int i = 0; i < length; i++) {
    bufp[i] = exp((long double)V[i]);
    sum += bufp[i];
  }
  for (int i = 0; i < length; i++) {
    V[i] = (float)(bufp[i] / sum);
  }
  return 0;
}