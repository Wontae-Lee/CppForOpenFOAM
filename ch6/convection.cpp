#include "convection.h"
#include <cmath>

void cds_convection() {
  for (int i = 0; i < internalFieldSize; ++i) {
    // conveciton
    // -cds scheme

    //// lower triangle
    l[i] += -rho * U[i] * rDeltaX * 0.5;
    //// upper triangle
    u[i] += rho * U[i] * rDeltaX * 0.5;

    // diagonal
    // d[i] +=0; // -(l[i]+u[i])
    d[i] = -(l[i] + u[i]);
  }

  source[0] += rho * U[0] * rDeltaX * 0.5 * phiLeft;
  source[internalFieldSize - 1] +=
      -rho * U[internalFieldSize - 1] * rDeltaX * phiRight;
}

void upwind_convection() {
  for (int i = 0; i < internalFieldSize; ++i) {
    // convection
    //-upwind scheme
    //// lower triangle
    l[i] += -std::fmax(rho * U[i], 0.) * rDeltaX;
    //// upper triangle
    u[i] += std::fmin(rho * U[i], 0.) * rDeltaX;

    d[i] = -(l[i] + u[i]);
  }

  source[0] += std::fmax(rho * U[0], 0.) * rDeltaX * phiLeft;
  source[internalFieldSize - 1] +=
      -std::fmin(rho * U[internalFieldSize - 1], 0.) * rDeltaX * phiRight;
}
