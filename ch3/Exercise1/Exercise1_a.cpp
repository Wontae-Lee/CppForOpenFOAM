#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

template <typename T>
T Sn(const T &a0, const T &an, size_t n)
{
    return n * (a0 + an) / 2;
}

int main(int argc, char **argv)
{
    // Initial condition
    constexpr double a0 = 0.0;
    constexpr size_t n = 10;
    constexpr double d = 2.0;

    // arithmetic sequence
    vector<double> vec(n);
    for (int i = 0; i < vec.size(); ++i)
    {
        if (i == 0)
        {
            cout << vec[i] << endl;
            continue;
        }
        vec[i] = vec[i - 1] + d;
        cout << vec[i] << endl;
    }
    cout << "Sn:" << Sn(vec.front(), vec.back(), n) << endl;

    return 0;
}