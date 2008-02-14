#ifndef XQP_ITEM_SEQUENCE_H
#define XQP_ITEM_SEQUENCE_H

#include "zorba/common/shared_types_incl.h"

namespace xqp {

  class ItemSequence : public rcobject 
  {
    public:
      virtual ~ItemSequence() { }
      virtual Item_t next() = 0;

  }; /* class ItemSequence */

} /* namespace xqp */

#endif
