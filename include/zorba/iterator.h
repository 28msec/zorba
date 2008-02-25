#ifndef ZORBA_ITERATOR_H
#define ZORBA_ITERATOR_H

#include <zorba/common/api_shared_types.h>

namespace xqp
{

  /**
   * General iterator interface. Used to program iterators which return a
   * sequence of items, wrapped into a rchandle object for garbage collection
   */
  class Iterator : virtual public SimpleRCObject
  {
    public:
      virtual ~Iterator() {}

      virtual void
      open() = 0;

      virtual Item_t
      next() = 0;

      virtual void
      reset() = 0;

      virtual void
      close() = 0;

  };
} /* namespace xqp */
#endif
