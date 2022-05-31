class Point
{
    double x_;
    double y_;
    double z_;

public:
    Point() : Point(0.0, 0.0, 0.0) {}
    Point(double x, double y, double z)
    {
        x_ = x;
        y_ = y;
        z_ = z;
    }
};

int main(int argc, int **argv)
{
    Point p1;
    Point p2(1., 2.2, 3.5);
}