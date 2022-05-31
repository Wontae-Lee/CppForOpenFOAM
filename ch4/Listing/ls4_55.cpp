#include <iostream>
using namespace std;

class A
{
public:
    static int state_;
};

int main()
{
    A a;
    A b;

    a.state_ = 1;
    b.state_ = 2;
    cout << a.state_ << " :" << b.state_ << endl;

    return 0;
}
