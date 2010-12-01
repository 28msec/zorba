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
#include "zorbatypes/zstring.h"
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
  typedef std::pair<QueryLoc, std::pair<store::Item_t, unsigned int> > StackEntry_t;

  typedef std::vector<StackEntry_t> StackTrace_t;

  zstring               theLocalName;
  zstring               thePrefix;
  zstring               theNamespace;
  XQUERY_ERROR          theErrorCode;
  zstring               theDescription;
  unsigned int          theQueryLine;
  unsigned int          theQueryColumn;
  zstring               theQueryFileName; // the name of the file where the error occured
  zstring               theFileName; // source file
  int                   theLineNumber; // line number in the source file
  bool                  theDebug;
  StackTrace_t          theStackTrace;

public:
  SERIALIZABLE_CLASS(ZorbaError)
  SERIALIZABLE_CLASS_CONSTRUCTOR(ZorbaError)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  static std::string toString(const XQUERY_ERROR& code);

public:
  ZorbaError(
        XQUERY_ERROR&       aErrorCode,
        const zstring&      aDescription,
        unsigned int        aQueryLine,
        unsigned int        aQueryColumn,
        const std::string&  aQueryFileName,
        const std::string&  aFileName,
        int                 aLineNumber);

  ZorbaError(
        const zstring&      aErrLocalName,
        const zstring&      aErrPrefix,
        const zstring&      aErrNamespace,
        const zstring&      aDescription,
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
        const char *filename);

  template<class StringType>
  void setQueryLocation(
        unsigned int line,
        unsigned int column,
        const StringType& filename) 
  {
    theQueryLine = line;
    theQueryColumn = column;
    theQueryFileName = filename;
  }

  bool hasQueryLocation();

  const zstring& localName() const;

  const zstring& ns() const;

  const zstring& prefix() const;

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

  static void
  recordStackTrace(
    const QueryLoc& aLoc,
    const QueryLoc& aFuncCallLoc,
    const store::Item_t& aFunctionName,
    unsigned int aFunctionArity,
    error::ZorbaError* aError);

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
  zstring       theDescription;   
  unsigned int  theQueryLine;
  unsigned int  theQueryColumn;
  zstring       theQueryFileName;
  zstring       theFileName;      
  int           theLineNumber;  

public:
  ZorbaWarning(
        WarningCode        aWarningCode,
        const zstring&     aDescription,
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
