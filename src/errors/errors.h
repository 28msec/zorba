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
#ifndef ZORBA_ERRORS_ERRORS_H
#define ZORBA_ERRORS_ERRORS_H

#include <string>
#include <vector>

#include <zorba/error.h>

#include "common/shared_types.h"

#include "compiler/parser/query_loc.h"

namespace zorba { namespace error {



/*******************************************************************************

********************************************************************************/
class ZorbaError
{
public:
  store::Item_t  theQName;
  XQUERY_ERROR   theErrorCode;
  xqpString      theDescription;
  QueryLoc       theQueryLocation;
  std::string    theFileName; // source file
  int            theLineNumber; // line number in the source file

public:
  ZorbaError(
        XQUERY_ERROR&                  aErrorCode,
        const xqpString&               aDescription,
        const QueryLoc&                aLocation,
        const std::string&             aFileName,
        int                            aLineNumber);

  ZorbaError(
        const ::zorba::store::Item_t&  aErrorQName,
        const xqpString&               aDescription,
        const QueryLoc&                aLocation,
        const std::string&             aFileName,
        int                            aLineNumber);

  ZorbaError(const ZorbaError& other);

  virtual ~ZorbaError();

  virtual bool 
  isXPathStaticError() const
  {
    return (XPST0001 <= theErrorCode && 
            theErrorCode <= XPST0083);
  }
      
  virtual bool 
  isXPathDynamicError() const
  {
    return (XPDY0002 <= theErrorCode && 
            theErrorCode <= XPDY0050);
  }
      
  virtual bool 
  isXPathTypeError() const 
  {
    return XPTY0004 <= theErrorCode && 
      theErrorCode <= XPTY0020;
  }
      
  virtual bool
  isXQueryDynamicError() const
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
  
  virtual bool 
  isXQueryStaticError() const
  {
    return ((XQST0009 <= theErrorCode && 
             theErrorCode <= XQST0093) ||
            (XUST0001 <= theErrorCode && 
             theErrorCode <= XUST0003) ||
            theErrorCode == XUST0028);
  }
  
  virtual bool 
  isXQueryTypeError() const
  {
    return ((XQTY0023 <= theErrorCode && 
             theErrorCode <= XQTY0086) ||
            (XUTY0004 <= theErrorCode && 
             theErrorCode <= XUTY0008) ||
            (XUTY0010 <= theErrorCode && 
             theErrorCode <= XUTY0013) ||
            theErrorCode == XUTY0022);
  }
  
  virtual bool 
  isFunctionError() const
  {
    return FOER0000 <= theErrorCode && 
      theErrorCode <= FOTY0012;
  }
  
  virtual bool
  isSerializationError() const
  {
    return SENR0001 <= theErrorCode && 
      theErrorCode <= SEPM0016;
  }
  
  virtual bool 
  isInternalError() const
  {
    return XQP0000_DYNAMIC_RUNTIME_ERROR <= theErrorCode && 
      theErrorCode <= API0021_ITEM_TO_LOAD_IS_NOT_NODE; 
  }
  
  virtual bool
  isStaticError() const
  {
    return isXPathStaticError() || isXQueryStaticError();
  }
  
  virtual bool
  isDynamicError() const
  {
    return isXPathDynamicError() || isXQueryDynamicError() || isFunctionError();
  }

  virtual bool
  isTypeError() const
  {
    return isXPathTypeError() || isXQueryTypeError();
  }

  virtual bool
  isUserError() const          { return false; }

  static std::string
  toString(const XQUERY_ERROR& code);
};


/*******************************************************************************
  Used for implementing the fn:error function.
********************************************************************************/
class ZorbaUserError : public ZorbaError
{
public:
  std::vector< ::zorba::store::Item_t> theErrorObject;

public:
  ZorbaUserError(
        XQUERY_ERROR& aErrorCode,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber,
        std::vector< ::zorba::store::Item_t> aErrorObject);

  ZorbaUserError(
        const ::zorba::store::Item_t& aErrorQName,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber,
        std::vector< ::zorba::store::Item_t> aErrorObject);

  virtual ~ZorbaUserError();

  virtual bool
  isUserError() const          { return true; }
};


/*******************************************************************************

********************************************************************************/
class ZorbaWarning
{
public:
  // move to the outside if we ever have warnings
  enum WarningCode
  {
  };

protected:
  WarningCode  theCode;          
  xqpString    theDescription;   
  QueryLoc     theQueryLocation; 
  std::string  theFileName;      
  int          theLineNumber;  

public:
  ZorbaWarning(WarningCode aWarningCode, const xqpString& aDescription,
               const QueryLoc& aLocation, const std::string& aFileName,
               int aLineNumber);  
};
    

} /* namespace error */
} /* namespace zorba */
#endif
