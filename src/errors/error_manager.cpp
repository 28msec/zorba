/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
    const ::zorba::store::Item_t& aErrorQName,
    const xqpString& aDescription,
    std::vector< ::zorba::store::Item_t> aErrorObject,
    const QueryLoc& aLocation,
    const std::string& aFileName,
    int aLineNumber)
  {
    ZorbaUserError lError(aErrorQName, aDescription, aLocation, aFileName, aLineNumber, aErrorObject);
    return lError;
  }


  void
  ErrorManager::addError(
    ::zorba::ZorbaError::ErrorCode aErrorCode,
    const xqpString& aDescription,
    const std::string& aFileName,
    int aLineNumber,
    const QueryLoc& aLocation)
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

