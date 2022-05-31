#include "linalg.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

void TDMA(const double *__restrict__ l, const double *__restrict__ d,
          const double *__restrict__ u, const int n,
          const double *__restrict__ b, double *x

) {
  double *__restrict__ uprime = new double[n];
  double *__restrict__ bprime = new double[n];

  // forward sweep
  uprime[0] = u[0] / d[0];
  bprime[0] = b[0] / d[0];

  for (int i = 1; i < n - 1; i++) {
    uprime[i] = u[i] / (d[i] - l[i] * uprime[i - 1]);
  }

  for (int i = 1; i < n; i++) {
    bprime[i] = (b[i] - l[i] * bprime[i - 1]) / (d[i] - l[i] * uprime[i - 1]);
  }

  // backward substitution
  x[n - 1] = bprime[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    x[i] = bprime[i] - uprime[i] * x[i + 1];
  }

  delete[] uprime;
  delete[] bprime;
  return;
}

void writeCoeffs() {
  std::ofstream os;
  os.open("coeffs.dat");
  for (int i = 0; i < internalFieldSize; ++i) {
    for (int j = 0; j < internalFieldSize; ++j) {
      if (i == j) {
        os << std::setw(10) << d[i];
      } else if (i == j + 1) {
        os << std::setw(10) << u[i];
      } else if (i == j - 1) {
        os << std::setw(10) << l[i];
      } else {
        os << std::setw(10) << " ";
      }
    }
    os << std::endl;
  }
  os.close();
}

void writeSources() {
  std::ofstream os;
  os.open("sources.dat");
  for (int j = 0; j < internalFieldSize; ++j) {
    os << std::setw(10) << source[j] << std::endl;
  }
  os.close();
}

void writeSolutions() {
  //// solution
  const double Pe = rho * U[0] * L / diffusivity;
  for (int i = 0; i < internalFieldSize; ++i) {
    double x = deltaX * (i + 1);
    exact[i] =
        phiLeft + (exp(x * Pe) / L - 1) / (exp(Pe) - 1) * (phiRight - phiLeft);
  }

  std::ofstream os;
  os.open("solutions.dat");
  os << "#solution comparison" << std::endl;
  os << 0 << "\t" << phiLeft << "\t" << phiLeft << std::endl;
  for (int i = 0; i < internalFieldSize; ++i) {
    double x = deltaX * (i + 1);
    os << x << " \t" << exact[i] << " \t" << phi[i] << std::endl;
  }

  os << L << "\t" << phiRight << " \t" << phiRight << std::endl;
  os.close();
}