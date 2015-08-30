#ifndef ZORBA_SERVER_UTILS_JSONOBJECT_H_
#define ZORBA_SERVER_UTILS_JSONOBJECT_H_

#include <map>
#include <vector>

#include "zorba/item.h"
#include "zorba/item_factory.h"

#include "request-handler.h"

namespace zorba
{
namespace server
{
namespace utils
{
  typedef std::pair<zorba::Item, zorba::Item> ObjectPair;
  typedef std::vector<ObjectPair> ObjectPairs;

  class JSONObject
  {
    public:
    JSONObject();

    void addField(const std::string& aFieldName, const std::string& aFieldValue);
    void addField(const std::string& aFieldName, long aFieldValue);
    void addField(const std::string& aFieldName, double aFieldValue);
    void addField(const std::string& aFieldName, utils::JSONObject& aFieldValue);

    zorba::Item getAsItem();

    private:
    zorba::ItemFactory& theItemFactory;
    ObjectPairs thePairs;
  };
}
}
}

#endif
