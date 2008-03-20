#include "errors/errors.h"

#include "store/api/item.h"

namespace zorba { namespace error {

  ZorbaError::ZorbaError(::zorba::ZorbaError::ErrorCode aErrorCode, const xqpString& aDescription,
                         const QueryLoc& aLocation, const std::string& aFileName,
                         int aLineNumber)
    : theErrorCode(aErrorCode),
      theDescription(aDescription),
      theQueryLocation(aLocation),
      theFileName(aFileName),
      theLineNumber(aLineNumber)
  {}

  ZorbaError::~ZorbaError() {}

  ZorbaWarning::ZorbaWarning(WarningCode aWarningCode, const xqpString& aDescription,
                             const QueryLoc& aLocation, const std::string& aFileName,
                             int aLineNumber)
    : theCode(aWarningCode),
      theDescription(aDescription),
      theQueryLocation(aLocation),
      theFileName(aFileName),
      theLineNumber(aLineNumber)
  {}

  ZorbaUserError::ZorbaUserError(::zorba::ZorbaError::ErrorCode aErrorCode, 
                                 const xqpString& aDescription,
                                 const QueryLoc& aLocation, const std::string& aFileName,
                                 int aLineNumber, std::vector< ::zorba::store::Item_t> aErrorObject)
    : ZorbaError(aErrorCode, aDescription, aLocation, aFileName, aLineNumber),
      theErrorObject(aErrorObject) {}

  ZorbaUserError::~ZorbaUserError() {}

} /* namespace error */
} /* namespace zorba */
