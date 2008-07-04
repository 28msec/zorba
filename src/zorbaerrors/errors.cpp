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

#include "zorbaerrors/errors.h"
#include "zorbaerrors/error_messages.h"

namespace zorba { namespace error {


ZorbaError::~ZorbaError()
{
}


ZorbaError::ZorbaError(
    XQUERY_ERROR&       aErrorCode,
    const xqpString&    aDescription,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn,
    const std::string&  aFileName,
    int                 aLineNumber)
  :
  theLocalName(toString(aErrorCode)),
  thePrefix("err"),
  theNamespace(XQUERY_ERR_NS),
  theErrorCode(aErrorCode),
  theDescription(aDescription),
  theQueryLine(aQueryLine),
  theQueryColumn(aQueryColumn),
  theFileName(aFileName),
  theLineNumber(aLineNumber)
{
}


ZorbaError::ZorbaError(
    const xqpString&    aErrLocalName,
    const xqpString&    aErrPrefix,
    const xqpString&    aErrNamespace,
    const xqpString&    aDescription,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn,
    const std::string&  aFileName,
    int                 aLineNumber)
  :
  theLocalName(aErrLocalName),
  thePrefix(aErrPrefix),
  theNamespace(aErrNamespace),
  theDescription(aDescription),
  theQueryLine(aQueryLine),
  theQueryColumn(aQueryColumn),
  theFileName(aFileName),
  theLineNumber(aLineNumber)
{
  // compute err code from qname
  if (aErrNamespace.getStore()->byteEqual(XQUERY_ERR_NS))
    theErrorCode = ErrorMessages::getErrorCodeForName(aErrLocalName.getStore()->c_str());
  else
    theErrorCode = XQP0021_USER_ERROR;
}


ZorbaError::ZorbaError(const ZorbaError& other)
  :
  theLocalName(other.theLocalName),
  thePrefix(other.thePrefix),
  theNamespace(other.theNamespace),
  theErrorCode(other.theErrorCode),
  theDescription(other.theDescription),
  theQueryLine(other.theQueryLine),
  theQueryColumn(other.theQueryColumn),
  theFileName(other.theFileName),
  theLineNumber(other.theLineNumber)
{
}


std::string 
ZorbaError::toString(const XQUERY_ERROR& code) 
{
  return ErrorMessages::getNameForErrorCode(code);
}


bool 
ZorbaError::isXPathStaticError() const
{
  return (XPST0001 <= theErrorCode && theErrorCode <= XPST0083);
}

      
bool 
ZorbaError::isXPathDynamicError() const
{
  return (XPDY0002 <= theErrorCode && theErrorCode <= XPDY0050);
}

      
bool 
ZorbaError::isXPathTypeError() const 
{
  return XPTY0004 <= theErrorCode && theErrorCode <= XPTY0020;
}
      

bool
ZorbaError::isXQueryDynamicError() const
{
  return ((XQDY0025 <= theErrorCode && 
           theErrorCode <= XQDY0092) ||
          XUDY0009 == theErrorCode ||
          (XUDY0014 <= theErrorCode && 
           theErrorCode <= XUDY0021) ||
          (XUDY0023 <= theErrorCode && 
           theErrorCode <= XUDY0025) ||
          theErrorCode == XUDY0027 ||
          theErrorCode == XUDY0029 ||
          theErrorCode == XUDY0030);
}

  
bool 
ZorbaError::isXQueryStaticError() const
{
  return ((XQST0009 <= theErrorCode && 
           theErrorCode <= XQST0093) ||
          (XUST0001 <= theErrorCode && 
           theErrorCode <= XUST0003) ||
          theErrorCode == XUST0028);
}

  
bool 
ZorbaError::isXQueryTypeError() const
{
  return ((XQTY0023 <= theErrorCode && 
           theErrorCode <= XQTY0086) ||
          (XUTY0004 <= theErrorCode && 
           theErrorCode <= XUTY0008) ||
          (XUTY0010 <= theErrorCode && 
           theErrorCode <= XUTY0013) ||
          theErrorCode == XUTY0022);
}
    

bool 
ZorbaError::isFunctionError() const
{
  return FOER0000 <= theErrorCode && theErrorCode <= FOTY0012;
}
  

bool
ZorbaError::isSerializationError() const
{
  return SENR0001 <= theErrorCode && theErrorCode <= SEPM0016;
}
    
 
bool 
ZorbaError::isInternalError() const
{
  return XQP0000_DYNAMIC_RUNTIME_ERROR <= theErrorCode && 
    theErrorCode <= MAX_ZORBA_ERROR_CODE;
}
  

bool
ZorbaError::isStaticError() const
{
  return isXPathStaticError() || isXQueryStaticError();
}
    
  
bool
ZorbaError::isDynamicError() const
{
  return isXPathDynamicError() || isXQueryDynamicError() || isFunctionError();
}


bool
ZorbaError::isTypeError() const
{
  return isXPathTypeError() || isXQueryTypeError();
}


ZorbaWarning::ZorbaWarning(
    WarningCode        aWarningCode,
    const xqpString&   aDescription,
    unsigned int       aQueryLine,
    unsigned int       aQueryColumn,
    const std::string& aFileName,
    int aLineNumber)
  :
  theCode(aWarningCode),
  theDescription(aDescription),
  theQueryLine(aQueryLine),
  theQueryColumn(aQueryColumn),
  theFileName(aFileName),
  theLineNumber(aLineNumber)
{
}


} /* namespace error */
} /* namespace zorba */
