#include <iostream>

class Point
{
    double x_;
    double y_;

public:
    Point() : x_(0), y_(0) {}
    Point(const double x, const double y) : x_(x), y_(y) {}

    friend std::ostream &operator<<(std::ostream &os, const Point &p);

    static Point add(const Point &p1, const Point &p2);
    static Point sub(const Point &p1, const Point &p2);
    static Point mul(const double &c, const Point &p);
};

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << p.x_ << " " << p.y_;
    return os;
}

Point Point::add(const Point &p1, const Point &p2)
{
    Point temp;
    temp.x_ = p1.x_ + p2.x_;
    temp.y_ = p1.y_ + p2.y_;
    return temp;
}
Point Point::sub(const Point &p1, const Point &p2)
{
    Point temp;
    temp.x_ = p1.x_ - p2.x_;
    temp.y_ = p1.y_ - p2.y_;
    return temp;
}
Point Point::mul(const double &c, const Point &p)
{
    Point temp;
    temp.x_ = c * p.x_;
    temp.y_ = c * p.y_;
    return temp;
}

int main(int argc, char **argv)
{
    Point p1(3.0, 4.0);
    Point p2(5.0, 6.0);
    double c = 5;
    std::cout << Point::add(p1, p2) << std::endl;

    std::cout << Point::sub(p1, p2) << std::endl;

    std::cout << Point::mul(c, p1) << std::endl;

    return 0;
}
