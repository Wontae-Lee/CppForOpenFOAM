class A
{
public:
    A(int x, double y);
};

A func()
{
    return {1, 2.3};
}

int main()
{
    func();
    return 0;
}