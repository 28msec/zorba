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
#ifndef ZORBAERRORS_ERRORS_H
#define ZORBAERRORS_ERRORS_H

#include <string>
#include <vector>

#include <zorba/error.h>

#include "zorbamisc/ns_consts.h"
#include "zorbatypes/xqpstring.h"


namespace zorba 
{

namespace error 
{


/*******************************************************************************

********************************************************************************/
class ZorbaError
{
public:
  xqpString      theLocalName;
  xqpString      thePrefix;
  xqpString      theNamespace;
  XQUERY_ERROR   theErrorCode;
  xqpString      theDescription;
  unsigned int   theQueryLine;
  unsigned int   theQueryColumn;
  std::string    theFileName; // source file
  int            theLineNumber; // line number in the source file

public:
  static std::string
  toString(const XQUERY_ERROR& code);

public:
  ZorbaError(
        XQUERY_ERROR&       aErrorCode,
        const xqpString&    aDescription,
        unsigned int        aQueryLine,
        unsigned int        aQueryColumn,
        const std::string&  aFileName,
        int                 aLineNumber);

  ZorbaError(
        const xqpString&    aErrLocalName,
        const xqpString&    aErrPrefix,
        const xqpString&    aErrNamespace,
        const xqpString&    aDescription,
        unsigned int        aQueryLine,
        unsigned int        aQueryColumn,
        const std::string&  aFileName,
        int                 aLineNumber);

  ZorbaError(const ZorbaError& other);

  virtual ~ZorbaError();

  virtual bool 
  isXPathStaticError() const;

  virtual bool 
  isXPathDynamicError() const;
      
  virtual bool 
  isXPathTypeError() const;
      
  virtual bool
  isXQueryDynamicError() const;

  virtual bool 
  isXQueryStaticError() const;

  virtual bool 
  isXQueryTypeError() const;
  
  virtual bool 
  isFunctionError() const;
  
  virtual bool
  isSerializationError() const;
  
  virtual bool 
  isInternalError() const;
  
  virtual bool
  isStaticError() const;
  
  virtual bool
  isDynamicError() const;

  virtual bool
  isTypeError() const;

  virtual bool
  isUserError() const          { return false; }
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
  WarningCode   theCode;          
  xqpString     theDescription;   
  unsigned int  theQueryLine;
  unsigned int  theQueryColumn;
  std::string   theFileName;      
  int           theLineNumber;  

public:
  ZorbaWarning(
        WarningCode        aWarningCode,
        const xqpString&   aDescription,
        unsigned int       aQueryLine,
        unsigned int       aQueryColumn,
        const std::string& aFileName,
        int                aLineNumber);  
};
    

} /* namespace error */
} /* namespace zorba */
#endif
