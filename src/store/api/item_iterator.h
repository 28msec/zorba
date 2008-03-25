#ifndef ZORBA_STORE_ITEM_ITERATOR_H
#define ZORBA_STORE_ITEM_ITERATOR_H

#include <vector>
#include "store/api/iterator.h"
#include "common/shared_types.h"

namespace zorba { namespace store {

class ItemIterator : public Iterator
{
private:
  std::vector<Item_t> theItems;
  std::vector<Item_t>::iterator theIterator;

public:
  ItemIterator(std::vector<Item_t> aItems);
  ItemIterator(Item_t aItem);
  ItemIterator(); // construct the empty sequence
  virtual ~ItemIterator(){}

  virtual void open();
  virtual Item_t next();
  virtual void reset();
  virtual void close();
};

} // namespace store
} // namespace zorba

#endif
