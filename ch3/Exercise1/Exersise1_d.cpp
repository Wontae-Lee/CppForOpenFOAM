#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char** argv) {
  // Initial condition
  constexpr double a0 = 0.0;
  constexpr size_t n = 10;
  constexpr double d = 2.0;
  double Sn = 0.0;

  // dynamic container
  auto vec = make_unique<double[]>(n);

  for (int i = 0; i < n; ++i) {
    vec[i] = a0;
    if (i == 0)
      continue;
    vec[i] += d;
  }

  // sum all components
  for (int i = 0; i < n; ++i) {
    Sn += vec[i];
  }

  cout << Sn << endl;

  return 0;
}