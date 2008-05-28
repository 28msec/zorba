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

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/error_messages.h"

namespace zorba { namespace error {


ErrorManager::ErrorManager() 
{
}


ErrorManager::~ErrorManager() 
{
}


ZorbaError
ErrorManager::createException(
    XQUERY_ERROR        aErrorCode, 
    const std::string&  aFileName,
    int                 aLineNumber)
{
  std::string lDesc = ErrorMessages::getMessageForErrorCode(aErrorCode);

  ZorbaError lError(aErrorCode, lDesc , 0, 0, aFileName, aLineNumber);

  return ZorbaError(lError);
}



ZorbaError
ErrorManager::createException(
    XQUERY_ERROR        aErrorCode,
    const std::string&  aFileName,
    int                 aLineNumber,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn)
{
  std::string lDesc = ErrorMessages::getMessageForErrorCode(aErrorCode);

  ZorbaError lError(aErrorCode, lDesc,
                    aQueryLine, aQueryColumn,
                    aFileName, aLineNumber);

  return ZorbaError(lError);
}


ZorbaError
ErrorManager::createException(
    XQUERY_ERROR        aErrorCode, 
    const std::string&  aParam1,
    const std::string&  aParam2,
    const std::string&  aFileName,
    int                 aLineNumber,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn)
{
  std::string lDesc = ErrorMessages::getMessageForErrorCode(aErrorCode);
  applyParams(&lDesc, &aParam1, &aParam2);

  ZorbaError lError(aErrorCode, lDesc,
                    aQueryLine, aQueryColumn,
                    aFileName, aLineNumber);
  return ZorbaError(lError);
}


ZorbaError
ErrorManager::createException(
    XQUERY_ERROR        aErrorCode,
    const std::string&  aDesc, 
    const std::string&  aFileName,
    int                 aLineNumber)
{
  ZorbaError lError(aErrorCode, aDesc, 0, 0, aFileName, aLineNumber);

  return ZorbaError(lError);
}


ZorbaError
ErrorManager::createException(
    XQUERY_ERROR        aErrorCode,
    const xqpString&    aDescription,
    const std::string&  aFileName,
    int                 aLineNumber,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn)
{
  ZorbaError lError(aErrorCode, aDescription,
                    aQueryLine, aQueryColumn,
                    aFileName, aLineNumber);

  return ZorbaError(lError);
}


void
ErrorManager::addError(
    XQUERY_ERROR        aErrorCode,
    const xqpString&    aDescription,
    const std::string&  aFileName,
    int                 aLineNumber,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn)
{
  ZorbaError lError(aErrorCode, aDescription,
                    aQueryLine, aQueryColumn,
                    aFileName, aLineNumber);
  theErrors.push_back(lError);
}


void
ErrorManager::addError(
    XQUERY_ERROR        aErrorCode, 
    const std::string&  aParam1,
    const std::string&  aParam2,
    const std::string&  aFileName,
    int                 aLineNumber,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn)
{
  std::string lDesc = ErrorMessages::getMessageForErrorCode(aErrorCode);
  applyParams(&lDesc, &aParam1, &aParam2);

  ZorbaError lError(aErrorCode, lDesc,
                    aQueryLine, aQueryColumn,
                    aFileName, aLineNumber);
  theErrors.push_back(lError);
}


void
ErrorManager::addWarning(
    ZorbaWarning::WarningCode aWarningCode,
    const xqpString&          aDescription,
    const std::string&        aFileName,
    int                       aLineNumber,
    unsigned int              aQueryLine,
    unsigned int              aQueryColumn)
{
  assert(false);
}



/*******************************************************************************

********************************************************************************/
void ErrorManager::applyParams(
    std::string*       errorMsg,
    const std::string* param1,
    const std::string* param2)
{
  std::string::size_type off = applyParam(errorMsg, param1, 0);
  applyParam(errorMsg, param2, off);
}


/*******************************************************************************
  Finds next place for param in errorMsg, and puts the param in that place.
  A place for param looks like "/s".
********************************************************************************/
std::string::size_type ErrorManager::applyParam(
    std::string*           errorMsg,
    const std::string*     param1,
    std::string::size_type start)
{
  std::string::size_type off;
  const static std::string empty;

  off = errorMsg->find ("/s", start);

  if (off == std::string::npos)
    return errorMsg->length();

  if (param1 == NULL)
    param1 = &empty;

  errorMsg->replace(off, 2, *param1);

  return off + param1->length ();
}


} /* namespace error */
} /* namespace zorba */

