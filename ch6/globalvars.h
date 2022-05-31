// input
//// domain
const double L = 1;
//// mesh properties
const int nodeSize = 11;
const int internalFieldSize = nodeSize - 2;
const double deltaX = L / (nodeSize - 1);
const double rDeltaX = 1. / deltaX;

// physical properties
const double rho = 1;
const double diffusivity = 0.02;

// field variable
double *phi;
double *U;
double *exact;

// matrix coeffs and sources
double *source;
double *d;
double *l;
double *u;
double *internalField;

// boundaries
double phiLeft;
double phiRight;
