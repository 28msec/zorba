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
#include <zorba/api_shared_types.h>
#include <zorba/exception.h>

#include "zorbamisc/ns_consts.h"
#include "zorbatypes/xqpstring.h"
#include "compiler/parser/query_loc.h"
#include "store/api/item.h"

namespace zorba 
{

namespace error 
{


/*******************************************************************************

********************************************************************************/
class ZORBA_DLL_PUBLIC ZorbaError : public ::zorba::serialization::SerializeBaseClass
{
public:
  //typedef std::pair<store::Item_t, QueryLoc> StackEntry_t;
  typedef std::pair<QueryLoc, std::pair<store::Item_t, unsigned int> > StackEntry_t;
  typedef std::vector<StackEntry_t> StackTrace_t;
  xqpString             theLocalName;
  xqpString             thePrefix;
  xqpString             theNamespace;
  XQUERY_ERROR          theErrorCode;
  xqpString             theDescription;
  unsigned int          theQueryLine;
  unsigned int          theQueryColumn;
  std::string           theQueryFileName; // the name of the file where the error occured
  std::string           theFileName; // source file
  int                   theLineNumber; // line number in the source file
  bool                  theDebug;
  StackTrace_t theStackTrace;

public:
  SERIALIZABLE_CLASS(ZorbaError)
  SERIALIZABLE_CLASS_CONSTRUCTOR(ZorbaError)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  static std::string toString(const XQUERY_ERROR& code);

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

  virtual std::string toString();

  void setQueryLocation(
        unsigned int line,
        unsigned int column,
        const std::string& filename);

  bool hasQueryLocation();

  const xqpString& localName() const;

  const xqpString& ns() const;

  const xqpString& prefix() const;

  virtual bool isXPathStaticError() const;

  virtual bool isXPathDynamicError() const;
      
  virtual bool isXPathTypeError() const;
      
  virtual bool isXQueryDynamicError() const;

  virtual bool isXQueryStaticError() const;

  virtual bool isXQueryTypeError() const;
  
  virtual bool isFunctionError() const;
  
  virtual bool isSerializationError() const;
  
  virtual bool isStaticError() const;
  
  virtual bool isDynamicError() const;

  virtual bool isTypeError() const;

  virtual bool isStoreError() const;

  virtual bool isAPIError() const;

  virtual bool isInternalError() const;

  virtual bool isUserError() const  { return false; }

  virtual std::auto_ptr<ZorbaError> clone() const;

  virtual void raise() const { throw *this; }

  virtual ZorbaException::StackTrace_t
  getStackTrace() const;
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


class ZORBA_DLL_PUBLIC ZorbaInternalException 
{
};


} /* namespace error */
} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
