#include "field.h"

void initVariables() {
  phi = new double[internalFieldSize];
  exact = new double[internalFieldSize];
  U = new double[internalFieldSize];
  source = new double[internalFieldSize];
  l = new double[internalFieldSize];
  d = new double[internalFieldSize];
  u = new double[internalFieldSize];

  for (int i = 0; i < internalFieldSize; ++i) {
    phi[i] = 0.0;
    U[i] = 1.0;
    l[i] = 0;
    d[i] = 0;
    u[i] = 0;
    source[i] = 0;
    exact[i] = 0;
  }
}

void destroyVariables() {
  delete[] U;
  delete[] phi;
  delete[] exact;
  delete[] d;
  delete[] l;
  delete[] u;
  delete[] source;
}

void correctBC() {
  phiLeft = 0;
  phiRight = L;
}