
template <typename T>
class Div
{
public:
    T operator()(const T &x, const T &y)
    {
        return x * y;
    }
};