template <typename T>
class Mul
{
public:
    T operator()(const T &x, const T &y)
    {
        return x * y;
    }
};