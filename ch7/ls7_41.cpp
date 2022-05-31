#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <string>

class Function1 {
 public:
  Function1() = default;

  virtual float operator()(float x) = 0;

  static constexpr char* typeName_ = "Function1";
  static const std::string typeName;

  using Function1Ptr = std::unique_ptr<Function1> (*)();
  using Function1Table = std::map<std::string, Function1Ptr>;
  static Function1Table Function1RTStable;

  template <typename derivedType>
  class AddToTable {
   public:
    static std::unique_ptr<Function1> factory() {
      return std::unique_ptr<Function1>(new derivedType());
    }

    AddToTable(const std::string& name = derivedType::typeName) {
      Function1::Function1RTStable.insert(
          std::pair<std::string, Function1Ptr>(name, factory));
    }
  };
};

class Sqr : public Function1 {
 public:
  Sqr() = default;

  virtual float operator()(float x) {
    std::cout << "sqr function called" << std::endl;
    return x * x;
  }

  static constexpr char* typeName_ = "sqr";
  static const std::string typeName;
};

class Sqrt : public Function1 {
 public:
  Sqrt() = default;

  virtual float operator()(float x) {
    std::cout << "sqrt function called" << std::endl;
    return pow(x, 0.5);
  }

  static constexpr char* typeName_ = "sqrt";
  static const std::string typeName;
};

class Cubic : public Function1 {
 public:
  Cubic() = default;

  virtual float operator()(float x) {
    std::cout << "cubic function called" << std::endl;
    return x * x * x;
  }

  static constexpr char* typeName_ = "cubic";
  static const std::string typeName;
};

const std::string Function1::typeName = Function1::typeName_;
Function1::Function1Table Function1::Function1RTStable;
const std::string Sqr::typeName = Sqr::typeName_;
Function1::AddToTable<Sqr> SqrDelegator;

const std::string Sqrt::typeName = Sqrt::typeName_;
Function1::AddToTable<Sqrt> SqrtDelegator;

const std::string Cubic::typeName = Cubic::typeName_;
Function1::AddToTable<Cubic> CubicDelegator;
int main(int argc, char** argv) {
  std::cout << "Function1RTStable" << std::endl;
  for (auto iter = Function1::Function1RTStable.begin();
       iter != Function1::Function1RTStable.end(); ++iter) {
    std::cout << " * key : " << iter->first << std::endl;
  }
  float x;
  std::string choice;
  x = 3;
  // input part 118 std::cout << ”select method(sqr or sqrt or cubic) : ” <<
  // std::endl;
  std::cin >> choice;
  std::cout << "Input Value : " << x << std::endl;
  // logic part
  std::unique_ptr<Function1> func = Function1::Function1RTStable[choice]();
  std::cout << "Function call : " << (*func)(x) << std::endl;

  return 0;
}