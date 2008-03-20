#ifndef ZORBA_STORE_ITEM_SEQUENCE_H
#define ZORBA_STORE_ITEM_SEQUENCE_H

#include <zorba/api_shared_types.h>

namespace zorba { 
  class ItemSequence
  {
    public:
      virtual ~ItemSequence() { }
      virtual bool next(Item& item) = 0;

  }; /* class ItemSequence */

} // namespace zorba
#endif
