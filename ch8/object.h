
#ifndef __object_h
#define __object_h
#include <string>
class object
{
private:
  const std::string name_;

public:
  object(const std::string &name)
      : name_(name)
  {
  }
  virtual ~object(){};

  const std::string &name() { return name_; }
};
#endif