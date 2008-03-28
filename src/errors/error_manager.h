#ifndef XQP_ERROR_MANAGER_H
#define XQP_ERROR_MANAGER_H

#include <vector>
#include <sstream>

#include <zorba/error.h>
#include "errors/errors.h"

namespace zorba { namespace error {

  class ErrorManager
  {
  public:
    ErrorManager();
      virtual ~ErrorManager();

      static ZorbaError
      createException(
        ::zorba::ZorbaError::ErrorCode aErrorCode,
        const xqpString&               aDescription,
        const std::string&             aFileName,
        int                            aLineNumber,
        const QueryLoc&                aLocation);

      static ZorbaError
      createException(
        ::zorba::ZorbaError::ErrorCode aErrorCode,
        const std::string&             aFileName,
        int                            aLineNumber);

      static ZorbaError
      createException(
        ::zorba::ZorbaError::ErrorCode aErrorCode,
        const std::string&             aDesc, 
        const std::string&             aFileName,
        int                            aLineNumber);

      static ZorbaError
      createException(
        ::zorba::ZorbaError::ErrorCode aErrorCode,
        const std::string&             aParam1,
        const std::string&             aParam2,
        const std::string&             aFileName,
        int                            aLineNumber,
        const QueryLoc&                aLocation = QueryLoc::null);

      static ZorbaError
      createException(
        ::zorba::ZorbaError::ErrorCode aErrorCode,
        const std::string&             aFileName,
        int                            aLineNumber, 
        const QueryLoc&                aLocation);

      static ZorbaUserError
      createUserException(
        const xqpString& aErrorURI,
        const xqpString aErrorLocalName,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        std::vector< ::zorba::store::Item_t> aErrorObject,
        const std::string& aFileName,
        int aLineNumber);

      void
      addError(
        ::zorba::ZorbaError::ErrorCode aErrorCode,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber);

      void
      addError(
        ::zorba::ZorbaError::ErrorCode aErrorCode, 
        const std::string& aParam1,
        const std::string& aParam2,
        const std::string& aFileName,
        int aLineNumber,
        const QueryLoc& aLocation = QueryLoc::null);

      void
      addWarning(
        ZorbaWarning::WarningCode aWarningCode,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber);

    protected:
      // contains all errors that were raised but the execution went on
      std::vector<ZorbaError>    theErrors;

      // contains all the warnings
      std::vector<ZorbaWarning>  theWarnings;
  };

#define ZORBA_USER_ERROR(uri, localname, desc, loc, obj) do { \
  throw error::ErrorManager::createUserException(uri, localname, desc, loc, obj, __FILE__, __LINE__); \
} while (0)


// create an exception and throw it
#define ZORBA_ERROR(code) do { \
  throw error::ErrorManager::createException(code, __FILE__, __LINE__); \
} while (0)


#define ZORBA_ERROR_DESC(code, desc) do {  \
  std::ostringstream lOStringStream; \
  lOStringStream << desc; \
  throw error::ErrorManager::createException(code, lOStringStream.str(), __FILE__, __LINE__); \
} while (0) 

#define ZORBA_ERROR_LOC(code, loc) do { \
  throw error::ErrorManager::createException(code, __FILE__, __LINE__, loc); \
} while (0) 


#define ZORBA_ERROR_LOC_DESC(code, loc, descr) do { \
    throw error::ErrorManager::createException(code, descr, __FILE__, __LINE__, loc); \
} while (0) 


// create an exception, replace params, and throw it
#define ZORBA_ERROR_PARAM(code, param1, param2) do { \
  std::ostringstream lOStringStream1, lOStringStream2; \
  lOStringStream1 << param1; \
  lOStringStream2 << param2; \
  throw error::ErrorManager::createException(code, lOStringStream1.str(), lOStringStream2.str(), __FILE__, __LINE__); \
} while (0) 

#define ZORBA_ERROR_LOC_PARAM(code, loc, param1, param2) do { \
  std::ostringstream lOStringStream1, lOStringStream2; \
  lOStringStream1 << param1; \
  lOStringStream2 << param2; \
  throw error::ErrorManager::createException(code, lOStringStream1.str(), lOStringStream2.str(), __FILE__, __LINE__, loc); \
} while (0) 


// create an error, remeber it, and continue
#define ZORBA_ERROR_DESC_CONTINUE(manager, code, loc, desc) do { \
    manager->addError(code, desc, __FILE__, __LINE__, loc);     \
} while (0) 


// create an error, replace params, and continue
#define ZORBA_ERROR_PARAM_CONTINUE(manager, code, param1, param2) do {\
  std::ostringstream lOStringStream1, lOStringStream2; \
  lOStringStream1 << param1; \
  lOStringStream2 << param2; \
  throw manager->addError(code, lOStringStream1.str(), lOStringStream2.str(), __FILE__, __LINE__); \
} while (0) 


// create an error, with location, replace params, and continue
#define ZORBA_ERROR_LOC_PARAM_CONTINUE(manager, code, loc, param1, param2) do { \
  std::ostringstream lOStringStream1, lOStringStream2; \
  lOStringStream1 << param1; \
  lOStringStream2 << param2; \
  throw manager->addError(code, lOStringStream1.str(), lOStringStream2.str(), __FILE__, __LINE__, loc); \
} while (0) 


// create a warning and continue
#define ZORBA_WARNING(manager, code, desc, loc) do {\
  manager->addWarning(ZorbaWarning::code, desc, loc, __FILE__, __LINE__); \
} while (0) 


#define ZORBA_NOT_IMPLEMENTED( what ) do {                                    \
    ZORBA_ERROR_DESC(ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED, what); \
} while (0) 

#define ZORBA_NOT_SUPPORTED( what ) do {                                    \
    ZORBA_ERROR_DESC(ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED, what); \
} while (0) 


} /* namespace error */
} /* namespace zorba */
#endif
