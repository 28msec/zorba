#ifndef ZORBA_STORE_ITEM_SEQUENCE_H
#define ZORBA_STORE_ITEM_SEQUENCE_H

#include <zorba/common/api_shared_types.h>

namespace zorba { namespace store {
  class ItemSequence : public SimpleRCObject 
  {
    public:
      virtual ~ItemSequence() { }
      virtual Item_t next() = 0;

  }; /* class ItemSequence */

} // namespace store
} // namespace zorba
#endif
