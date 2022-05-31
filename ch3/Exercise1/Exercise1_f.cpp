#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    // Initial condition
    constexpr double a0 = 0.0;
    constexpr size_t n = 10;
    constexpr double d = 2.0;
    double Sn = 0.0;

    // arithmetic sequence
    vector<double> vec(n);
    vector<double>::iterator iter;

    for (iter = vec.begin(); iter != vec.end(); iter++)
    {
        if (iter == vec.begin())
        {
            *iter = a0;
            continue;
        }
        *iter = *(iter - 1) + d;
    }

    for (auto &value : vec)
    {
        Sn += value;
        cout << value << endl;
    }
    cout << "size: " << vec.size() << endl;
    cout << "Sn:" << Sn << endl;

    return 0;
}