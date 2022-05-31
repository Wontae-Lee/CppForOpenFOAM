#include <math.h>
#include <stdio.h>

float sqr(float x) {
  printf("sqr function called\n");
  return x * x;
}

float sqrt(float x) {
  printf("cubic function called\n");
  return pow(x, 0.5);
}

float cubic(float x) {
  printf("cubic function called\n");
  return x * x * x;
}

int main(int argc, char **argv) {
  float x;
  int choice;
  x = 3;

  // input part
  printf("select method(0 for sqr, 1 for sqrt, 2 for cubic):");
  scanf("%d", &choice);
  printf("Input Value: %\n", x);
  if (choice == 0) {
    printf("Function call: %f\n", sqr(x));
  } else if (choice == 1) {
    printf("Function call: %f\n", sqrt(x));
  } else if (choice == 2) {
    printf("Function call : % f\n", cubic(x));
  }
  return 0;
}
