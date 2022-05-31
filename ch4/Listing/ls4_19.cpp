class B
{
public:
    int b;
    B() : b(0) {}
};

class A : public B
{
public:
    A() : B(), a_(0), b_(1) {}

private:
    int a_;
    int b_;
};