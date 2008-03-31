#include "api/resultiteratorchainer.h"

#include <zorba/result_iterator.h>
#include <zorba/item.h>
#include "store/api/item.h"
#include "api/unmarshaller.h"

namespace zorba { namespace store {

ResultIteratorChainer::ResultIteratorChainer(ResultIterator* aResIter) 
  : theResult(aResIter)
{}


ResultIteratorChainer::~ResultIteratorChainer() 
{
}

void
ResultIteratorChainer::open() 
{
  theResult->open();
}

Item_t
ResultIteratorChainer::next() 
{
  Item_t lStoreItem;

  ::zorba::Item lItem;
  while ( theResult->next(lItem) ) {
    return Unmarshaller::getInternalItem(lItem); 
  }

  return NULL;
}

void
ResultIteratorChainer::reset() 
{
  theResult->close();
}

void
ResultIteratorChainer::close() 
{
  theResult->close();
}

} // namespace store
} // namespace zorba

