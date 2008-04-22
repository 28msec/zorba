#include "store/api/item.h"
#include "store/api/item_iterator.h"

namespace zorba { namespace store {

ItemIterator::ItemIterator(std::vector<Item_t> aItems) 
: theItems(aItems)
{}

ItemIterator::ItemIterator(Item_t aItem) 
{
  theItems.push_back(aItem);
}

ItemIterator::ItemIterator() {}

void
ItemIterator::open() 
{
  theIterator = theItems.begin();
}

Item_t
ItemIterator::next() 
{
  if (theIterator == theItems.end()) {
    return 0;
  } else {
    return *(theIterator++);
  }
}

void
ItemIterator::reset() 
{
  theIterator = theItems.begin();
}

void
ItemIterator::close() 
{}

} // namespace store
} // namespace zorba
