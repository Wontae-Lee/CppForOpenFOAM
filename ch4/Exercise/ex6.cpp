#include <iostream>

class Point {
  double x_;
  double y_;

public:
  // Constructor
  Point(const double x, const double y) : x_(x), y_(y) {}
  Point(const Point &p) : x_(p.x_), y_(p.y_) {}

  // operater +
  Point &operator+=(const Point &p) {
    x_ += p.x_;
    y_ += p.y_;
    return *this;
  }
  friend Point operator+(const Point &p1, const Point &p2) {
    return Point(p1.x_ + p2.x_, p1.y_ + p2.y_);
  }

  // operator -

  Point &operator-=(const Point &p) {
    x_ -= p.x_;
    y_ -= p.y_;
    return *this;
  }
  friend Point operator-(const Point &p1, const Point &p2) {
    return Point(p1.x_ - p2.x_, p1.y_ - p2.y_);
  }

  // operator *

  Point &operator*=(const Point &p) {
    x_ *= p.x_;
    y_ *= p.y_;
    return *this;
  }
  friend Point operator*(const Point &p1, const Point &p2) {
    return Point(p1.x_ * p2.x_, p1.y_ * p2.y_);
  }

  // 출력용
  friend std::ostream &operator<<(std::ostream &os, const Point p) {
    std::cout << "x: " << p.x_ << "y: " << p.y_ << std::endl;
  }
};

int main(int argc, char **argv) {
  Point a{1.0, 2.0};
  Point b{3.0, 4.0};

  std::cout << a + b << std::endl;
  std::cout << a + b << std::endl;
  return 0;
}