class A
{
public:
    A(){};
    A(int x){};
};

class B : public A
{
public:
    using A::A(){};
};