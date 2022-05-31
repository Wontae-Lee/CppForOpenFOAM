class A
{
public:
    A(const A &) = delete;
    A &operator=(const A &) = delete;
};