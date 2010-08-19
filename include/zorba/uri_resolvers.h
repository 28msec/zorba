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
#ifndef ZORBA_URI_RESOLVERS_API_H
#define ZORBA_URI_RESOLVERS_API_H

#include <istream>
#include <vector>
#include <memory>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include <zorba/zorbastring.h>

namespace zorba {

class ZORBA_DLL_PUBLIC URIResolverResult
{
 public:
  enum ErrorCode
  {
    UR_NOERROR,
    // documents and collections
    UR_FODC0002,
    UR_FODC0003,
    UR_FODC0004,
    UR_FODC0005,
    // modules
    UR_XQST0088,
    UR_XQST0046,
    UR_XQST0059,
    // schemas
    UR_XQST0057
  };

  URIResolverResult() : theErrorCode(UR_NOERROR) {}

  virtual ~URIResolverResult() {}

  ErrorCode
  getError() const { return theErrorCode; }

  void
  setError(const ErrorCode& aErrorCode) { theErrorCode = aErrorCode; }

  void
  setErrorDescription(const String& aDescription) { theDescription = aDescription; }

  String
  getErrorDescription() { return theDescription; }

 protected:
  ErrorCode theErrorCode;
  String    theDescription;
};


class ZORBA_DLL_PUBLIC DocumentURIResolverResult : public URIResolverResult
{
public:
  virtual ~DocumentURIResolverResult() {}

  // TODO make this function throw()
  virtual Item
  getDocument() const = 0;
};


class ZORBA_DLL_PUBLIC DocumentURIResolver 
{
 public:
  virtual ~DocumentURIResolver() {}

  virtual std::auto_ptr<DocumentURIResolverResult>
  resolve(const Item& aURI,
          StaticContext* aStaticContext,
          XmlDataManager* aXmlDataManager,
          bool validateUri,
          bool tidying,
          bool replaceDoc = false,
          const Item& aTidyUserOpt = NULL) = 0;
};


class ZORBA_DLL_PUBLIC CollectionURIResolverResult : public URIResolverResult
{
 public:
  virtual ~CollectionURIResolverResult() {}

  virtual Collection_t
  getCollection() const = 0;
};


class ZORBA_DLL_PUBLIC CollectionURIResolver
{
 public:
  virtual ~CollectionURIResolver() {}

  virtual std::auto_ptr<CollectionURIResolverResult>
  resolve(const Item& aURI,
          StaticContext* aStaticContext,
          XmlDataManager* aXmlDataManager) = 0;
};
  

class ZORBA_DLL_PUBLIC SchemaURIResolverResult : public URIResolverResult 
{
 public:
  virtual ~SchemaURIResolverResult() {}

  virtual String
  getSchema() const = 0;
};


class ZORBA_DLL_PUBLIC SchemaURIResolver
{
 public:
  virtual ~SchemaURIResolver() {}
      
  virtual std::auto_ptr<SchemaURIResolverResult>
  resolve(const Item& aURI,
          StaticContext* aStaticContext,
          std::vector<Item>& aAtList,
          String* aFileUri = 0) = 0;
};
  

class ZORBA_DLL_PUBLIC ModuleURIResolverResult : public URIResolverResult
{
 public:
  virtual ~ModuleURIResolverResult() {}
  
  virtual std::istream* getModuleStream() const = 0;

  virtual void getModuleURL(std::string&) const = 0;

  virtual void getComponentURIs(std::vector<std::string>&) const = 0;
};


class ZORBA_DLL_PUBLIC ModuleURIResolver
{
 public:
  virtual ~ModuleURIResolver() {}

  virtual std::auto_ptr<ModuleURIResolverResult> resolveTargetNamespace(
        const String& aTargetNamespaceURI,
        const StaticContext& aStaticContext) = 0;

  virtual std::auto_ptr<ModuleURIResolverResult> resolve(
        const String& aURI,
        const StaticContext& aStaticContext) = 0;
};


} /* namespace zorba */

#endif
