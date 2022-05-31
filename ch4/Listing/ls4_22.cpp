class A
{
};

class B
{
public:
    B() {}
    B(A &a) {}
    B(int n) {}
    B(double a) {}
};

int main()
{
    A a;
    int n = 1;
    double d = 1.0;
    B b;
    b = a;
    b = n;
    b = d;
}
