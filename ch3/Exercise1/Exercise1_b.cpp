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

    for (auto &value : vec)
    {
        Sn += value;
    }

    cout << "Sn: " << Sn << endl;

    return 0;
}