#include <zorba/error.h>
#include <zorba/string.h>
#include "errors/errors.h"

namespace zorba {

  String
  ZorbaError::getErrorCode(ZorbaError::ErrorCode code)
  {
    return error::ZorbaError::toString(code);
  }


} /* namespace zorba */
