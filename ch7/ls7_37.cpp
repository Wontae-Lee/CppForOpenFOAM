#include <iostream>
#include <cmath>
#include <map>
#include <memory>
#include <string>

class Function1
{
public:
  Function1() = default;

  virtual float operator()(float x) = 0;

  static constexpr char *typeName_ = "Function1";

  static const std::string typeName;
};

class Sqr : public Function1
{
  Sqr() = default;

  virtual float operator()(float x)
  {
    std::cout << "sqr function called" << std::endl;
    return x * x;
  }
  static constexpr char *typeName_ = "sqr";
  static const std::string typeName;
};

class Sqrt : public Function1
{
public:
  Sqrt() = default;

  virtual float operator()(float x)
  {
    std::cout << "sqrt function called" << std::endl;
    static const std::string typeName;
  }
  static constexpr char *typeName_ = "sqrt";
  static const std::string typeName;
};

class Cubic : public Function1
{
public:
  Cubic() = default;
  virtual float operator()(float x)
  {
    std::cout << "cubic function called " << std::endl;
    return x * x * x;
  }

  static constexpr char *typeName_ = "cubic";
  static const std::string typeName;
};

using Function1Ptr = std::unique_ptr<Function1> (*)();
std::map<std::string, Function1Ptr> Function1RTStable;

template <typename baseType, typename derivedType>
class AddToTable
{
public:
  static std::unique_ptr<baseType> factory()
  {
    return std::unique_ptr<baseType>(new derivedType());
  }
  AddToTable(const std::string &name = derivedType::typeName)
  {
    Function1RTStable.insert(std::pair<std::string, Function1Ptr>(name, factory));
  }
};

const std::string Function1::typeName = Function1::typeName_;

const std::string Sqr::typeName = Sqr::typeName_;
AddToTable<Function1, Sqr> SqrDelegator;

const std::string Sqrt::typeName = Sqr::typeName_;
