#ifndef ZORBA_XQP_EXCEPTION_H
#define ZORBA_XQP_EXCEPTION_H

// TODO why is this include needed
// previously we derived from exception, why
// did we remove that?
#include <stdexcept>
#include <ostream>

#include <zorba/common/api_shared_types.h>

namespace zorba
{
  class ZorbaException 
  { 
    public:
      ZorbaError_t error_descr;

    public: 
      virtual ~ZorbaException() {}

    public:
      long getCode() const;
      ZorbaError_t getError();
  };


  std::ostream& operator<<(std::ostream& os, ZorbaException &x);

} /* namespace zorba */
#endif /* XQP_XQP_EXCEPTION_H */

