#include <iostream>

using namespace std;
class superClass
{
public:
    virtual void func(int a) const { cout << a << endl; }
    // virtual void func(int a)  {cout<< a<<endl;}
};

class subClass : public superClass
{
public:
    virtual void func(int a) { cout << a + 1 << std::endl; }
};

int main(int argc, char **argv)
{
    subClass sub;
    sub.func(2);
    return 0;
}
