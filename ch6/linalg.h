#ifndef __MATRIX_H
#define __MATRIX_H

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

void TDMA(const double *__restrict__ l, const double *__restrict__ d,
          const double *__restrict__ u, const int n,
          const double *__restrict__ b, double *x);

void writeCoeffs();
void writeSources();
void writeSolutions();

#endif