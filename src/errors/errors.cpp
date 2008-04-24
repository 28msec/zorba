#include <zorba/error.h>

#include "errors/errors.h"
#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "context/ns_consts.h"

namespace zorba { namespace error {

  ZorbaError::ZorbaError(
    ::zorba::ZorbaError::ErrorCode aErrorCode,
    const xqpString& aDescription,
    const QueryLoc& aLocation,
    const std::string& aFileName,
    int aLineNumber)
    :
    theQName(GENV_ITEMFACTORY->createQName(XQUERY_ERR_NS, "err", ZorbaError::toString(aErrorCode).c_str())),
    theErrorCode(aErrorCode),
    theDescription(aDescription),
    theQueryLocation(aLocation),
    theFileName(aFileName),
    theLineNumber(aLineNumber)
  {}

  ZorbaError::ZorbaError(
    const ::zorba::store::Item_t& aErrQName,
    const xqpString& aDescription,
    const QueryLoc& aLocation,
    const std::string& aFileName,
    int aLineNumber)
    :
    theQName(aErrQName),
    theDescription(aDescription),
    theQueryLocation(aLocation),
    theFileName(aFileName),
    theLineNumber(aLineNumber)
  {
    // compute err code from qname
    if (xqp_string (theQName->getNamespace ()) == XQUERY_ERR_NS)
      theErrorCode = err_name_to_code(theQName->getLocalName()->str());
    else
      theErrorCode = ::zorba::ZorbaError::XQP0021_USER_ERROR;
  }


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

  ZorbaWarning::ZorbaWarning(
    WarningCode aWarningCode,
    const xqpString& aDescription,
    const QueryLoc& aLocation,
    const std::string& aFileName,
    int aLineNumber)
    :
    theCode(aWarningCode),
    theDescription(aDescription),
    theQueryLocation(aLocation),
    theFileName(aFileName),
    theLineNumber(aLineNumber)
  {}

  ZorbaUserError::ZorbaUserError(
    ::zorba::ZorbaError::ErrorCode aErrorCode, 
    const xqpString& aDescription,
    const QueryLoc& aLocation,
    const std::string& aFileName,
    int aLineNumber,
    std::vector< ::zorba::store::Item_t> aErrorObject)
    :
    ZorbaError(aErrorCode, aDescription, aLocation, aFileName, aLineNumber),
    theErrorObject(aErrorObject) {}

  ZorbaUserError::ZorbaUserError(
    const ::zorba::store::Item_t& aErrQName,
    const xqpString& aDescription,
    const QueryLoc& aLocation,
    const std::string& aFileName,
    int aLineNumber,
    std::vector< ::zorba::store::Item_t> aErrorObject)
    :
    ZorbaError(aErrQName, aDescription, aLocation, aFileName, aLineNumber),
    theErrorObject(aErrorObject) {}

  ZorbaUserError::~ZorbaUserError() {}

} /* namespace error */
} /* namespace zorba */
