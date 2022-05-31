#include <iostream>

class Point
{
private:
    double x_;
    double y_;

public:
    Point(double x, double y) : x_(x), y_(y) {}
    Point() : Point(0, 0) {}

    Point &operator+=(const Point &b)
    {
        x_ += b.x_;
        y_ += b.y_;

        return *this;
    }

    friend const Point operator+(const Point &a, const Point &b)
    {
        Point p;
        p.x_ = a.x_ + b.x_;
        p.y_ = a.y_ + b.y_;
        return p;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &p);
};

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << '(' << p.x_ << " " << p.y_ << ')';
    return os;
}

int main(int argc, char **argv)
{
    Point a(1, 2);
    Point b(2, 4);
    Point c;

    c = a + b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    c += a;
    std::cout << c << std::endl;
    return 0;
}