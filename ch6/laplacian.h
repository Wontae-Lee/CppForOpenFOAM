#ifndef __LAPLACIAN_H
#define __LAPLACIAN_H

// input
//// domain
extern const double L;
//// mesh properties
extern const int nodeSize;
extern const int internalFieldSize;
extern const double deltaX;
extern const double rDeltaX;

// physical properties
extern const double rho;
extern const double diffusivity;

// field variable
extern double *phi;
extern double *U;
extern double *exact;

// matrix coeffs and sources
extern double *source;
extern double *d;
extern double *l;
extern double *u;
extern double *internalField;

// boundaries
extern double phiLeft;
extern double phiRight;

void cds_laplacian();
#endif