#ifndef ZORBA_COLLECTION_API_H
#define ZORBA_COLLECTION_API_H

#include <zorba/api_shared_types.h>
#include <zorba/item.h>

namespace zorba {

class Collection
{
  public:
    virtual ~Collection() {}

    virtual Item
    getUri() = 0;

    virtual bool
    addItem(const Item& aItem) = 0;

    virtual bool
    deleteItem(const Item& aItem) = 0;

    virtual bool
    addItems(const ResultIterator_t& aResultIterator) = 0;

    virtual bool
    addDocument(std::istream& lInStream) = 0;

}; /* class Collection */

} /* namespace zorba */


#endif
