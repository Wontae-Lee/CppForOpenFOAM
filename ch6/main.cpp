#include "convection.h"
#include "field.h"
#include "globalvars.h"
#include "laplacian.h"
#include "linalg.h"

int convectionScheme = 0; //
int main(int argc, char **argv) {
  initVariables();
  correctBC();

  if (convectionScheme == 0) {
    cds_convection();
  } else if (convectionScheme == 1) {
    upwind_convection();
  }

  cds_laplacian();

  TDMA(l, d, u, internalFieldSize, source, phi);
  correctBC(); // update boundary value

  writeSolutions();
  // destroy variables
  destroyVariables();
  return 0;
}