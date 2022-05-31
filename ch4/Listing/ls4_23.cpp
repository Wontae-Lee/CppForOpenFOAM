class A
{
};

class B
{
public:
    explicit B() {}
    explicit B(A &a) {}
    explicit B(int n) {}
    explicit B(double a) {}
};

int main()
{
    A a;
    int n = 1;
    double d = 1.0;

    B b = B();
    b = B(a);
    b = B(n);
    b = B(d);
}
