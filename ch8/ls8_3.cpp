#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "object.h"
#include "objectManager.h"

class scalarList : public object
{
private:
  std::vector<double> data_;

public:
  scalarList(const std::string &name)
      : object(name)
  {
  }

  std::vector<double> &data() { return data_; }

  size_t size() { return data_.size(); }
  void resize(size_t size) { return data_.resize(size); }
  void reserve(size_t size) { return data_.reserve(size); }
};

class dictionary : public object
{
private:
  std::map<std::string, std::string> dict_;

public:
  dictionary(const std::string &name) : object(name) {}
  std::map<std::string, std::string> &dict() { return dict_; }
};

int main(int argc, char **argv)
{
  objectManager manager;

  manager.checkIn(new object("myobj"));
  manager.checkIn(new scalarList("mylist"));
  manager.checkIn(new dictionary("mydict"));

  manager.showRecord();

  scalarList &cache = static_cast<scalarList &>(manager.lookupObject("mylist"));
  cache.resize(10);

  std::cout << cache.name() << std::endl;
  std::cout << cache.size() << std::endl;

  for (auto iter = cache.data().begin(); iter != cache.data().end(); ++iter)
  {
    std::cout << *iter << std::endl;
  }

  auto &dict = static_cast<dictionary &>(manager.lookupObject("mydict"));
  dict.dict().insert(std::pair("value", "uniform (1 0 0)"));
  dict.dict().insert(std::pair("rho", "1.21"));

  for (auto item : dict.dict())
  {
    std::cout << item.first << " : " << item.second << std::endl;
  }

  return 0;
}
