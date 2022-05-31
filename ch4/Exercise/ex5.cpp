#include <cmath>
#include <iostream>
#include <math.h>
#include <memory>
#include <stddef.h>
#include <string>
#include <utility>

using namespace std;

class Shape {
public:
  virtual ~Shape() {
    cout << "~Shape" << endl;
  } //자식클래스 리소스해제을 위한 가상 소멸자
  virtual double area() const = 0;
};

// Circle class definition
class Circle : public Shape {
  double x_, y_;
  double radius_;

public:
  // Constructor
  Circle(const double x, const double y, const double radius) {
    x_ = x;
    y_ = y;
    radius_ = radius;
  }

  // Destructor
  ~Circle() { cout << "~Circle" << endl; }

  virtual double area() const override { return std::pow(radius_, 2) * M_PI; }
};

class Triangle : public Shape {
  double height_, width_;

public:
  Triangle(const double height, const double width)
      : height_(height), width_(width) {}

  // Destructor
  ~Triangle() { cout << "~Triangle" << endl; }

  virtual double area() const override { return height_ * width_ / 2; }
};

class Rectangle : public Shape {
  double height_, width_;

public:
  Rectangle(const double height, const double width)
      : height_(height), width_(width) {}

  // Destructor
  ~Rectangle() { cout << "~Rectangle" << endl; }

  virtual double area() const override { return height_ * width_; }
};

int main(int argc, char **argv) {
  string choice;
  unique_ptr<Shape> shape = nullptr;

  choice = "circle";
  if (choice == "circle") {
    shape = unique_ptr<Shape>(new Circle(1.0, 2.0, 3.0));
  } else if (choice == "triangle") {
    shape = unique_ptr<Shape>(new Triangle(10.0, 5.0));
  } else if (choice == "rectangle") {
    shape = unique_ptr<Shape>(new Rectangle(10.0, 5.0));
  }

  std::cout << "Area of shape: " << shape->area() << std::endl;

  return 0;
};