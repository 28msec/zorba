#ifndef ZORBA_ITERATOR_API_H
#define ZORBA_ITERATOR_API_H

#include <zorba/api_shared_types.h>

namespace zorba {

  class Iterator 
  {
    public:

      virtual ~Iterator() {}

      virtual void 
      open() = 0;

      virtual bool
      next(Item&) = 0;

      virtual void 
      close() = 0;

  };

} /* namespace zorba */
#endif
