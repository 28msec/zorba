#ifndef XQP_EXCEPTION_H
#define XQP_EXCEPTION_H

#include <exception>
#include <ostream>
#include <string>

#include "errors/errors.h"

namespace zorba { namespace error {
  class ZorbaException : public std::exception
  { 
    public: 
      virtual ~ZorbaException() throw() {}

      const ZorbaError&
      getError() const { return theError; }

    protected:
      friend class ErrorManager;
      ZorbaException(const ZorbaError& aError)
        : theError(aError) {}

      ZorbaError theError;
   }; /* class ZorbaException */

} /* namespace error */
} /* namespace zorba */
#endif /* XQP_EXCEPTION_H */
