class A
{
public:
    int m;
};

class B : public A
{

    using A::m;
};