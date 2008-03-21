#include "errors/error_manager.h"
#include "errors/error_messages.h"

#include "store/api/item.h"

namespace zorba { namespace error {

  ErrorManager::ErrorManager() {}
  ErrorManager::~ErrorManager() {}

  ZorbaError
  ErrorManager::createException(
    ::zorba::ZorbaError::ErrorCode aErrorCode,
    const std::string& aFileName,
    int aLineNumber,
    const QueryLoc& aLocation)
  {
    AlertMessagesEnglish lMessages;
    std::string lDesc = lMessages.error_decode(aErrorCode);
    ZorbaError lError(aErrorCode, lDesc, aLocation, aFileName, aLineNumber);

    return ZorbaError(lError);
  }


  ZorbaError
  ErrorManager::createException(
    ::zorba::ZorbaError::ErrorCode aErrorCode,
    const xqpString& aDescription,
    const std::string& aFileName,
    int aLineNumber,
    const QueryLoc& aLocation)
  {
    ZorbaError lError(aErrorCode, aDescription, aLocation, aFileName, aLineNumber);

    return ZorbaError(lError);
  }


  ZorbaError
  ErrorManager::createException(
    ::zorba::ZorbaError::ErrorCode aErrorCode, 
    const std::string& aFileName,
    int aLineNumber)
  {
    AlertMessagesEnglish lMessages;
    std::string lDesc = lMessages.error_decode(aErrorCode);
    ZorbaError lError(aErrorCode, lDesc , QueryLoc::null, aFileName, aLineNumber);

    return ZorbaError(lError);
  }


  ZorbaError
  ErrorManager::createException(
    ::zorba::ZorbaError::ErrorCode aErrorCode,
    const std::string& aDesc, 
    const std::string& aFileName,
    int aLineNumber)
  {
    ZorbaError lError(aErrorCode, aDesc, QueryLoc::null, aFileName, aLineNumber);

    return ZorbaError(lError);
  }


  ZorbaError
  ErrorManager::createException(
    ::zorba::ZorbaError::ErrorCode aErrorCode, 
    const std::string& aParam1,
    const std::string& aParam2,
    const std::string& aFileName,
    int aLineNumber,
    const QueryLoc& aLocation)
  {
    AlertMessagesEnglish lMessages;
    std::string lDesc = lMessages.error_decode(aErrorCode);
    lMessages.applyParams(&lDesc, &aParam1, &aParam2);

    ZorbaError lError(aErrorCode, lDesc, aLocation, aFileName, aLineNumber);
    return ZorbaError(lError);
  }


  ZorbaUserError
  ErrorManager::createUserException(
    const xqpString& aErrorURI,
    const xqpString aErrorLocalName,
    const xqpString& aDescription,
    const QueryLoc& aLocation,
    std::vector< ::zorba::store::Item_t> aErrorObject,
    const std::string& aFileName,
    int aLineNumber)
  {
    ::zorba::ZorbaError::ErrorCode aErrorCode = ZorbaError::err_name_to_code (aErrorLocalName);
         
    ZorbaUserError lError(aErrorCode, aDescription, aLocation, aFileName, aLineNumber, aErrorObject);
    return lError;
  }


  void
  ErrorManager::addError(
    ::zorba::ZorbaError::ErrorCode aErrorCode,
    const xqpString& aDescription,
    const QueryLoc& aLocation,
    const std::string& aFileName,
    int aLineNumber)
  {
    ZorbaError lError(aErrorCode, aDescription, aLocation, aFileName, aLineNumber);
    theErrors.push_back(lError);
  }


  void
  ErrorManager::addError(
    ::zorba::ZorbaError::ErrorCode aErrorCode, 
    const std::string& aParam1,
    const std::string& aParam2,
    const std::string& aFileName,
    int aLineNumber,
    const QueryLoc& aLocation)
  {
    AlertMessagesEnglish lMessages;
    std::string lDesc = lMessages.error_decode(aErrorCode);
    lMessages.applyParams(&lDesc, &aParam1, &aParam2);

    ZorbaError lError(aErrorCode, lDesc, aLocation, aFileName, aLineNumber);
    theErrors.push_back(lError);
  }


  void
  ErrorManager::addWarning(
    ZorbaWarning::WarningCode aWarningCode,
    const xqpString& aDescription,
    const QueryLoc& aLocation,
    const std::string& aFileName,
    int aLineNumber)
  {
    assert(false);
  }


} /* namespace error */
} /* namespace zorba */

