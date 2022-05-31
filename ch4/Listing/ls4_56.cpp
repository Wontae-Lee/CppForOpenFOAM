#include <iostream>

using namespace std;

class A
{
private:
    int state_;

public:
    void operator()(int i) { state_ = i; }
    int state() { return state_; }
};

int main()
{
    A a;
    A b;

    a(1);
    b(2);
    cout << a.state() << " :" << b.state() << endl;

    return 0;
}
