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
#include <memory>

#include <zorba/config.h>
#include <zorba/error.h>

#include "zorbamisc/ns_consts.h"
#include "zorbatypes/xqpstring.h"


namespace zorba 
{

namespace error 
{


/*******************************************************************************

********************************************************************************/
class ZORBA_DLL_PUBLIC ZorbaError
{
public:
  xqpString      theLocalName;
  xqpString      thePrefix;
  xqpString      theNamespace;
  XQUERY_ERROR   theErrorCode;
  xqpString      theDescription;
  unsigned int   theQueryLine;
  unsigned int   theQueryColumn;
  std::string    theQueryFileName; // the name of the file where the error occured
  std::string    theFileName; // source file
  int            theLineNumber; // line number in the source file
#ifdef ZORBA_DEBUGGER
  bool           theDebug;
#endif

public:
  static std::string
  toString(const XQUERY_ERROR& code);

public:
  ZorbaError(
        XQUERY_ERROR&       aErrorCode,
        const xqpString&    aDescription,
        unsigned int        aQueryLine,
        unsigned int        aQueryColumn,
        const std::string&  aQueryFileName,
        const std::string&  aFileName,
        int                 aLineNumber);

  ZorbaError(
        const xqpString&    aErrLocalName,
        const xqpString&    aErrPrefix,
        const xqpString&    aErrNamespace,
        const xqpString&    aDescription,
        unsigned int        aQueryLine,
        unsigned int        aQueryColumn,
        const std::string&  aQueryFileName,
        const std::string&  aFileName,
        int                 aLineNumber);

  ZorbaError(const ZorbaError& other);

  virtual ~ZorbaError();

  virtual void free();

  virtual std::string
  toString();

  const xqpString&
  localName() const;

  const xqpString&
  ns() const;

  const xqpString&
  prefix() const;

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
  isUserError() const  { return false; }

  virtual std::auto_ptr<ZorbaError>
  clone() const;

  virtual void
  raise() const { throw *this; }
};


/*******************************************************************************

********************************************************************************/
class ZORBA_DLL_PUBLIC  ZorbaWarning
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
  std::string   theQueryFileName;
  std::string   theFileName;      
  int           theLineNumber;  

public:
  ZorbaWarning(
        WarningCode        aWarningCode,
        const xqpString&   aDescription,
        unsigned int       aQueryLine,
        unsigned int       aQueryColumn,
        const std::string& aQueryFileName,
        const std::string& aFileName,
        int                aLineNumber);  
};

class ZORBA_DLL_PUBLIC ZorbaInternalException {
};

} /* namespace error */
} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
