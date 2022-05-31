#include "laplacian.h"
void cds_laplacian() {
  for (int i = 0; i < internalFieldSize; ++i) {
    // diffusion
    //- cds scheme
    //// lower triangle
    l[i] += -diffusivity * rDeltaX * rDeltaX;

    //// upper triangle
    u[i] += -diffusivity * rDeltaX * rDeltaX;
  }

  // source term from diffusion
  source[0] += diffusivity * rDeltaX * rDeltaX * phiLeft;
  source[internalFieldSize - 1] += diffusivity * rDeltaX * rDeltaX * phiRight;
}