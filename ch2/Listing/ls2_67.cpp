#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char **argv)
{
    std::ifstream ifs("wave.csv");

    char delimiter = ',';
    std::istringstream iss;
    std::string line;
    std::string token;
    int num_of_columns = 2;

    // header
    std::getline(ifs, line);
    std::cout << line << std::endl;
    // iss.str(line);

    // data table
    // tokensize

    std::vector<double> time;
    std::vector<double> eta;
    time.reserve(100000);
    eta.reserve(100000);

    while (std::getline(ifs, line))
    {
        iss.str(line);
        for (int i = 0; i < num_of_columns; ++i)
        {
            std::getline(iss, token, delimiter);
            if (i == 0)
            {
                time.push_back(std::stod(token));
            }
            else
                eta.push_back(std::stod(token));
        }
        std::cout << time.back() << " " << eta.back() << std::endl;
        // reset the stream to the beginning
        iss.seekg(0, iss.beg);
    }
}