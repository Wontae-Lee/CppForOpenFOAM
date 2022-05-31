

#include <iostream>
#include <stddef.h>

#define ADD(x, y) x + y
#define SUB(x, y) x - y
#define MUL(x, y) x *y
#define DIV(x, y) x / y

#define TYPED_VECTOR(token)                                                         \
                                                                                    \
    class token##_vector                                                            \
    {                                                                               \
        size_t size_;                                                               \
        token *data_;                                                               \
        const char *typename_ = "" #token "";                                       \
                                                                                    \
    public:                                                                         \
        void print_type() { std::cout << "my type is " << typename_ << std::endl; } \
    };

TYPED_VECTOR(int)
TYPED_VECTOR(double)
TYPED_VECTOR(char)
int main()
{
    int_vector a;
    double_vector b;
    char_vector c;
    a.print_type();
    b.print_type();
    c.print_type();
    return 0;
}