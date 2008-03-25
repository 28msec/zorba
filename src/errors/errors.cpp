#include "errors/errors.h"
#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

namespace zorba { namespace error {

  ZorbaError::ZorbaError(::zorba::ZorbaError::ErrorCode aErrorCode, const xqpString& aDescription,
                         const QueryLoc& aLocation, const std::string& aFileName,
                         int aLineNumber)
    : theQName(GENV_ITEMFACTORY->createQName(
        "http://www.w3.org/2005/xqt-errors",
        "err",
        ZorbaError::toString(aErrorCode).c_str())),
      theErrorCode(aErrorCode),
      theDescription(aDescription),
      theQueryLocation(aLocation),
      theFileName(aFileName),
      theLineNumber(aLineNumber)
  {}

  ZorbaError::ZorbaError(const ZorbaError& other)
    : theQName(other.theQName),
    theErrorCode(other.theErrorCode),
    theDescription(other.theDescription),
    theQueryLocation(other.theQueryLocation),
    theFileName(other.theFileName),
    theLineNumber(other.theLineNumber)
  {
  }

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
