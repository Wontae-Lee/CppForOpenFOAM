
#include <map>
#include <memory>
#include <string>
#include <iostream>
#include "object.h"
class objectManager
{
protected:
  std::map<std::string, std::unique_ptr<object>> db_;

public:
  void checkIn(object *obj)
  {
    db_.insert(std::pair(obj->name(), obj));
  }

  const std::map<std::string, std::unique_ptr<object>> &db()
  {
    return db_;
  }

  object &lookupObject(const std::string &name)
  {
    return *(db_.find(name)->second);
  }
  const object lookupObject(const std::string &name) const
  {
    return *(db_.find(name)->second);
  }

  void showRecord() const
  {
    for (auto iter = db_.begin(); iter != db_.end(); ++iter)
    {
      std::cout << iter->first << " : " << iter->second->name() << std::endl;
    }
  }
};
