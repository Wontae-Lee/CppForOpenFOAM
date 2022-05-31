#include <cmath>
#include <iostream>
#include <math.h>
#include <stddef.h>

class Point {
  double x_;
  double y_;

public:
  Point() : x_(0), y_(0) {}
  Point(const double x, const double y) : x_(x), y_(y) {}

  friend std::ostream &operator<<(std::ostream &os, const Point &p);

  static Point add(const Point &p1, const Point &p2);
  static Point sub(const Point &p1, const Point &p2);
  static Point mul(const double &c, const Point &p);

  friend class Circle;
};

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << p.x_ << " " << p.y_;
  return os;
}

Point Point::add(const Point &p1, const Point &p2) {
  Point temp;
  temp.x_ = p1.x_ + p2.x_;
  temp.y_ = p1.y_ + p2.y_;
  return temp;
}
Point Point::sub(const Point &p1, const Point &p2) {
  Point temp;
  temp.x_ = p1.x_ - p2.x_;
  temp.y_ = p1.y_ - p2.y_;
  return temp;
}
Point Point::mul(const double &c, const Point &p) {
  Point temp;
  temp.x_ = c * p.x_;
  temp.y_ = c * p.y_;
  return temp;
}

class Circle {
  double x_;
  double y_;
  double radius_;

public:
  Circle() = delete;
  Circle(const double x, const double y, const double radius)
      : x_(x), y_(x), radius_(radius) {}

  Circle(const double x1, const double y1, const double x2, const double y2) {
    if (x1 > x2) {
      x_ = x1 - x2;
    } else {
      x_ = x2 - x1;
    }
    if (y1 > y2) {
      y_ = y1 - y2;
    } else {
      y_ = y2 - y1;
    }

    radius_ = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
  }

  Circle(const double radius, const Point &p) {
    radius_ = radius;
    x_ = p.x_;
    y_ = p.y_;
  }

  double area() const { return std::pow(radius_, 2) * M_PI; }
};
