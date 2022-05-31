
template <typename T>
class Sub
{
public:
    T operator()(const T &x, const T &y) { return x - y; }
};
