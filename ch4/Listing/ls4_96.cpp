template <class Lhs, class Rhs>
auto adding_func(const Lhs &lhs, const Rhs &rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

decltype(auto) adding_func(const Lhs &lhs, const Rhs &rhs)
{
    return lhs + rhs;
}
