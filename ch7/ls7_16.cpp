#include <cmath>
#include <iostream>
#include <map>
#include <string>

float Sqr(float x) {
  std::cout << "sqr function called" << std::endl;
  return x * x;
}

float Sqrt(float x) {
  std::cout << "sqrt function called" << std::endl;
  return pow(x, 0.5);
}
float Cubic(float x) {
  std::cout << "cubic function called" << std::endl;
  return x * x * x;
}

typedef float (*function1Ptr)(float);
std::map<std::string, function1Ptr> RTStable;
int main(int argc, char** argv) {
  // register algorithm
  RTStable.insert(std::make_pair("Sqr", Sqr));
  RTStable.insert(std::make_pair("Sqrt", Sqrt));
  RTStable.insert(std::make_pair("Cubic", Cubic));

  float x;
  std::string choice;
  x = 3;

  // input part
  std::cout << "select method(Sqr or Sqrt or Cubic): " << std::endl;
  std::cin >> choice;
  std::cout << "Input Value: " << x << std::endl;
  // logic part
  std::cout << "Function call: " << RTStable[choice](x) << std::endl;
  return 0;
}