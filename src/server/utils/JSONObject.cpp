#include "zorba/zorba_string.h"

#include "JSONObject.h"

namespace zorba
{
namespace server
{
namespace utils
{
  JSONObject::JSONObject() :
      theItemFactory(RequestHandler::getInstance().getItemFactory())
  {

  }

  void JSONObject::addField(const std::string& aFieldName, const std::string& aFieldValue)
  {
    zorba::Item lName = theItemFactory.createString(zorba::String(aFieldName));
    zorba::Item lValue = theItemFactory.createString(zorba::String(aFieldValue));
    thePairs.push_back(std::pair<zorba::Item, zorba::Item>(lName, lValue));
  }

  void JSONObject::addField(const std::string& aFieldName, long aFieldValue)
  {
    zorba::Item lName = theItemFactory.createString(zorba::String(aFieldName));
    zorba::Item lValue = theItemFactory.createInteger(aFieldValue);
    thePairs.push_back(std::pair<zorba::Item, zorba::Item>(lName, lValue));
  }

  void JSONObject::addField(const std::string& aFieldName, double aFieldValue)
  {
    zorba::Item lName = theItemFactory.createString(aFieldName);
    zorba::Item lValue = theItemFactory.createDouble(aFieldValue);
    thePairs.push_back(std::pair<zorba::Item, zorba::Item>(lName, lValue));
  }

  void JSONObject::addField(const std::string& aFieldName, utils::JSONObject& aFieldValue)
  {
    zorba::Item lName = theItemFactory.createString(aFieldName);
    zorba::Item lValue = aFieldValue.getAsItem();
    thePairs.push_back(std::pair<zorba::Item, zorba::Item>(lName, lValue));
  }

  zorba::Item JSONObject::getAsItem()
  {
    return theItemFactory.createJSONObject(thePairs);
  }

}
}
}
