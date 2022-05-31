#include <stdio.h>
#define SQRMACRO(x)                                                            \
  \ 
(x) * (x)

float sqrFuntion(float x) { return x * x; }

int main(int argc, char **argv) {
  float x;
  x = 3;
  printf("Input Value: %f\n", x);
  printf("Function call:%f\n", sqrFuntion(x));
  printf("Macro Function call: %f\n", SQRMACRO(x));

  return 0;
}
