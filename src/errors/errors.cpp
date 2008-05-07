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
#include <zorba/error.h>

#include "errors/errors.h"
#include "errors/error_messages.h"

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "context/ns_consts.h"

namespace zorba { namespace error {


ZorbaError::~ZorbaError()
{
}


ZorbaError::ZorbaError(
    ::zorba::ZorbaError::ErrorCode aErrorCode,
    const xqpString&               aDescription,
    const QueryLoc&                aLocation,
    const std::string&             aFileName,
    int                            aLineNumber)
  :
  theQName(GENV_ITEMFACTORY->createQName(XQUERY_ERR_NS,
                                         "err",
                                         ZorbaError::toString(aErrorCode).c_str())),
  theErrorCode(aErrorCode),
  theDescription(aDescription),
  theQueryLocation(aLocation),
  theFileName(aFileName),
  theLineNumber(aLineNumber)
{
}


ZorbaError::ZorbaError(
    const ::zorba::store::Item_t& aErrQName,
    const xqpString&              aDescription,
    const QueryLoc&               aLocation,
    const std::string&            aFileName,
    int                           aLineNumber)
  :
  theQName(aErrQName),
  theDescription(aDescription),
  theQueryLocation(aLocation),
  theFileName(aFileName),
  theLineNumber(aLineNumber)
{
  // compute err code from qname
  if (theQName->getNamespace()->byteEqual(XQUERY_ERR_NS))
    theErrorCode = ErrorMessages::getErrorCodeForName(theQName->getLocalName()->str());
  else
    theErrorCode = ::zorba::ZorbaError::XQP0021_USER_ERROR;
}


ZorbaError::ZorbaError(const ZorbaError& other)
  :
  theQName(other.theQName),
  theErrorCode(other.theErrorCode),
  theDescription(other.theDescription),
  theQueryLocation(other.theQueryLocation),
  theFileName(other.theFileName),
  theLineNumber(other.theLineNumber)
{
}


std::string ZorbaError::toString(::zorba::ZorbaError::ErrorCode& code) 
{
  return ErrorMessages::getNameForErrorCode(code);
}


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
{
}


ZorbaUserError::ZorbaUserError(
    ::zorba::ZorbaError::ErrorCode       aErrorCode, 
    const xqpString&                     aDescription,
    const QueryLoc&                      aLocation,
    const std::string&                   aFileName,
    int                                  aLineNumber,
    std::vector< ::zorba::store::Item_t> aErrorObject)
  :
  ZorbaError(aErrorCode, aDescription, aLocation, aFileName, aLineNumber),
  theErrorObject(aErrorObject)
{
}


ZorbaUserError::ZorbaUserError(
    const ::zorba::store::Item_t&        aErrQName,
    const xqpString&                     aDescription,
    const QueryLoc&                      aLocation,
    const std::string&                   aFileName,
    int                                  aLineNumber,
    std::vector< ::zorba::store::Item_t> aErrorObject)
  :
  ZorbaError(aErrQName, aDescription, aLocation, aFileName, aLineNumber),
  theErrorObject(aErrorObject)
{
}

    
ZorbaUserError::~ZorbaUserError()
{
}
    
} /* namespace error */
} /* namespace zorba */
