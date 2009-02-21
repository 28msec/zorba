
#include "store/util/item_vector.h"
#include "store/api/item.h"

namespace zorba
{

namespace store
{

/******************************************************************************

********************************************************************************/
std::string ItemVector::toString() const
{
  std::ostringstream str;
  str << *this;
  return str.str();
}


/******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const ItemVector& key)
{
  ulong size = key.theItems.size();

  os << "[";

  for (ulong i = 0; i < size; i++)
  {
    if (key.theItems[i] == NULL)
      os << "NULL";
    else
      os << key.theItems[i]->getStringValue()->c_str();
  }

  os << "]";

  return os;
}


}
}
