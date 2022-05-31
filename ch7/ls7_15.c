#include <math.h>
#include <stdio.h>

typedef float (*funtion1Ptr)(float);

int main(int argc, char **argv) {
  float x;
  int choice;
  funtion1Ptr method;

  x = 3;
  // input part
  scanf("%d", &choice);
  printf("Function call: %f\n", method(x));

  return 0;
}