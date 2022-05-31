#include <memory>

class object
{
};

// 책에는 auto_ptr로 작성되었지만 unique_ptr로 바꿔썼다.
int main()
{
    std::unique_ptr<object> objPtr = std::unique_ptr<object>(new object());
    std::unique_ptr<object> opjPtr(new object()); // 이 방법을 더 선호한다.

    return 0;
}