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

SERIALIZABLE_CLASS_VERSIONS(ZorbaError)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaError)


std::string ZorbaError::toString(const XQUERY_ERROR& code) 
{
  return ErrorMessages::getNameForErrorCode(code);
}



ZorbaError::ZorbaError(
    XQUERY_ERROR&       aErrorCode,
    const xqpString&    aDescription,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn,
    const std::string&  aQueryFileName,
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
  theQueryFileName(aQueryFileName),
  theFileName(aFileName),
  theLineNumber(aLineNumber),
  theDebug(false)
{
  //+debug
  //printf("ZorbaError(%s %s: %s %d)\n", theLocalName.c_str(), theDescription, theFileName.c_str(), aLineNumber);
}


ZorbaError::ZorbaError(
    const xqpString&    aErrLocalName,
    const xqpString&    aErrPrefix,
    const xqpString&    aErrNamespace,
    const xqpString&    aDescription,
    unsigned int        aQueryLine,
    unsigned int        aQueryColumn,
    const std::string&  aQueryFileName,
    const std::string&  aFileName,
    int                 aLineNumber)
  :
  theLocalName(aErrLocalName),
  thePrefix(aErrPrefix),
  theNamespace(aErrNamespace),
  theDescription(aDescription),
  theQueryLine(aQueryLine),
  theQueryColumn(aQueryColumn),
  theQueryFileName(aQueryFileName),
  theFileName(aFileName),
  theLineNumber(aLineNumber),
  theDebug(false)
{
  // compute err code from qname
  if (aErrNamespace.getStore()->byteEqual(XQUERY_ERR_NS, strlen(XQUERY_ERR_NS)))
    theErrorCode = ErrorMessages::getErrorCodeForName(aErrLocalName.getStore()->c_str());
  else
    theErrorCode = XQP0021_USER_ERROR;

  //+debug
  //printf("ZorbaError(%s %s: %s %d)\n", theLocalName.c_str(), theDescription, theFileName.c_str(), aLineNumber);
}


ZorbaError::ZorbaError(const ZorbaError& other)
  :
  ::zorba::serialization::SerializeBaseClass(),
  theLocalName(other.theLocalName),
  thePrefix(other.thePrefix),
  theNamespace(other.theNamespace),
  theErrorCode(other.theErrorCode),
  theDescription(other.theDescription),
  theQueryLine(other.theQueryLine),
  theQueryColumn(other.theQueryColumn),
  theQueryFileName(other.theQueryFileName),
  theFileName(other.theFileName),
  theLineNumber(other.theLineNumber),
  theDebug(other.theDebug)
{
}


ZorbaError::~ZorbaError()
{
}


void ZorbaError::free() 
{ 
  delete this; 
}


void ZorbaError::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theLocalName;
  ar & thePrefix;
  ar & theNamespace;
  SERIALIZE_ENUM(XQUERY_ERROR, theErrorCode);
  ar & theDescription;
  ar & theQueryLine;
  ar & theQueryColumn;
  ar & theQueryFileName; // the name of the file where the error occured
  ar & theFileName; // source file
  ar & theLineNumber; // line number in the source file
  if(!ar.is_serializing_out())
    theDebug = false;
}


void ZorbaError::setQueryLocation(
    unsigned int line,
    unsigned int column,
    const std::string& filename)
{
  theQueryLine = line;
  theQueryColumn = column;
  theQueryFileName = filename;
}


bool ZorbaError::hasQueryLocation()
{
  return !(theQueryFileName.empty() && theQueryLine == 0 && 
           theQueryColumn == 0);
}


std::string ZorbaError::toString() 
{
  std::ostringstream strstream;

  strstream << "Code : " << ErrorMessages::getNameForErrorCode(theErrorCode)
            << std::endl << "Description : " << theDescription << std::endl;

  return strstream.str();
}


const xqpString& ZorbaError::localName() const
{
  return theLocalName;
}


const xqpString& ZorbaError::ns() const
{
  return theNamespace;
}


const xqpString&
ZorbaError::prefix() const
{
  return thePrefix;
}


bool ZorbaError::isXPathStaticError() const
{
  return (XPST0001 <= theErrorCode && theErrorCode <= XPST0083) ||
         theErrorCode == FTST0009;
}

      
bool ZorbaError::isXPathDynamicError() const
{
  return  (XPDY0002 <= theErrorCode && theErrorCode <= XPDY0050);
}

      
bool ZorbaError::isXPathTypeError() const 
{
  return XPTY0004 <= theErrorCode && theErrorCode <= XPTY0020;
}
      

bool ZorbaError::isXQueryDynamicError() const
{
  return ((XQDY0025 <= theErrorCode && theErrorCode <= XQDY0092) ||
          XUDY0009 == theErrorCode ||
          (XUDY0014 <= theErrorCode && theErrorCode <= XUDY0021) ||
          (XUDY0023 <= theErrorCode && theErrorCode <= XUDY0025) ||
          theErrorCode == XUDY0027 ||
          theErrorCode == XUDY0029 ||
          theErrorCode == XUDY0030 ||
          theErrorCode == XUDY0031 ||
          (XDDY0000_MIN <= theErrorCode && theErrorCode <= XDDY0000_MAX) ||
          (XTDE1310 <= theErrorCode && theErrorCode <= XTDE1350))
#ifndef ZORBA_NO_FULL_TEXT
          || (theErrorCode >= FTDY0016 && theErrorCode <= FTDY0020)
#endif /* ZORBA_NO_FULL_TEXT */
          ;
}

  
bool ZorbaError::isXQueryStaticError() const
{
  return ((XQST0009 <= theErrorCode && theErrorCode <= XQST0093) ||
          (XUST0001 <= theErrorCode && theErrorCode <= XUST0003) ||
          theErrorCode == FTST0019 ||
          theErrorCode == XPST0003 ||
          theErrorCode == XUST0028 ||
          (XDST0000_MIN <= theErrorCode && theErrorCode <= XDST0000_MAX))
#ifndef ZORBA_NO_FULL_TEXT
          || (theErrorCode >= FTST0008 && theErrorCode <= FTST0019)
#endif /* ZORBA_NO_FULL_TEXT */
          ;
}

  
bool ZorbaError::isXQueryTypeError() const
{
  return ((XQTY0023 <= theErrorCode && theErrorCode <= XQTY0086) ||
          (XUTY0004 <= theErrorCode && theErrorCode <= XUTY0008) ||
          (XUTY0010 <= theErrorCode && theErrorCode <= XUTY0013) ||
          theErrorCode == XUTY0022 ||
          theErrorCode == XDTY0001_COLLECTION_INVALID_NODE_TYPE);
}
    

bool ZorbaError::isFunctionError() const
{
  return FOER0000 <= theErrorCode && theErrorCode <= FOUP0002;
}
  


bool ZorbaError::isSerializationError() const
{
  return SENR0001 <= theErrorCode && theErrorCode <= SEPM0016;
}
    
 
bool ZorbaError::isInternalError() const
{
  return XQP0000_DYNAMIC_RUNTIME_ERROR <= theErrorCode && 
    theErrorCode <= MAX_ZORBA_ERROR_CODE;
}
  

bool ZorbaError::isStaticError() const
{
  return isXPathStaticError() || isXQueryStaticError();
}
    
  
bool ZorbaError::isDynamicError() const
{
  return isXPathDynamicError() || isXQueryDynamicError() || isFunctionError();
}


bool ZorbaError::isTypeError() const
{
  return isXPathTypeError() || isXQueryTypeError();
}


std::auto_ptr<ZorbaError> ZorbaError::clone() const
{
    std::auto_ptr<ZorbaError> err(new ZorbaError(*this));
    return err;
}


ZorbaWarning::ZorbaWarning(
    WarningCode        aWarningCode,
    const xqpString&   aDescription,
    unsigned int       aQueryLine,
    unsigned int       aQueryColumn,
    const std::string& aQueryFileName,
    const std::string& aFileName,
    int aLineNumber)
  :
  theCode(aWarningCode),
  theDescription(aDescription),
  theQueryLine(aQueryLine),
  theQueryColumn(aQueryColumn),
  theQueryFileName(aQueryFileName),
  theFileName(aFileName),
  theLineNumber(aLineNumber)
{
}


} /* namespace error */
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
