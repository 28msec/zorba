#ifndef ZORBA_COLLECTIONIMPL_H
#define ZORBA_COLLECTIONIMPL_H

#include "common/shared_types.h"
#include <zorba/collection.h>

namespace zorba {

  class CollectionImpl : public Collection
  {
    public:
      CollectionImpl(const store::Collection_t& aCollection, ErrorHandler* aErrorHandler);
      virtual ~CollectionImpl();

      Item
      getUri();

      bool
      addItem(const Item& aItem);

      bool
      deleteItem(const Item& aItem);

      bool
      addItems(const ResultIterator_t& aResultIterator);

      bool
      addDocument(std::istream& lInStream);

    protected:
      friend class Unmarshaller;
      store::Collection_t theCollection;
      ErrorHandler* theErrorHandler;

  }; /* class CollectionImpl */

} /* namespace zorba */

#endif
