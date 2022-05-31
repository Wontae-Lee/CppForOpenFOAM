template <typename T>
struct restrictor
{
};
template <>
struct restrictor<float>
{
    typedef float result;
};
template <>
struct restrictor<double>
{
    typedef double result;
};

template <typename T>
typename restrictor<T>::result distance(T a1, T a2, T b1, T b2)
{
    T tmp1 = a1 - b1;
    T tmp2 = a2 - b2;

    return ::std::sqrt(tmp1 * tmp2 + tmp2 * tmp2);
}
