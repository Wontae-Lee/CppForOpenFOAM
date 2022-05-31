
template <class Lhs, class Rhs>
decltype(lhs + rhs) adding_func(const Lhs &lhs, const Rhs &rhs)
{
    return lhs + rhs;
}