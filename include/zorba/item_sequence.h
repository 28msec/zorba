#ifndef ZORBA_ITEM_SEQUENCE_H
#define ZORBA_ITEM_SEQUENCE_H

#include <zorba/common/api_shared_types.h>

namespace xqp {

  class ItemSequence : public SimpleRCObject 
  {
    public:
      virtual ~ItemSequence() { }
      virtual Item_t next() = 0;

  }; /* class ItemSequence */

} /* namespace xqp */
#endif
