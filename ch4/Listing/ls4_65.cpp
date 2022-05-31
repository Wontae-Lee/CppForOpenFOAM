// header.hpp

template <typename T>
class Number
{
    // body
};

typename Number<int> intNumber;
typename Number<float> floatNumber;
typename Number<double> doubleNumber;

// header.cpp

#include "header.hpp"

// template definition

// 명시적 인스턴스화 선언
template class Number<int>;
typename class Number<float>;
typename class Number<double>;
