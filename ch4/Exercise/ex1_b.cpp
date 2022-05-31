template <typename T>
class Add
{
public:
    T operator()(const T &x, const T &y)
    {
        return x + y;
    }
};