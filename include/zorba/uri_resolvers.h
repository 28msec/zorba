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

  class URIResolverResult
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
        UR_XQST0046
      };

      URIResolverResult()
        : theErrorCode(UR_NOERROR) {}

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

  class DocumentURIResolverResult : public URIResolverResult
  {
    public:
      virtual ~DocumentURIResolverResult() {}

      // TODO make this function throw()
      virtual Item
      getDocument() const = 0;
  };

  class DocumentURIResolver 
  {
    public:
      virtual ~DocumentURIResolver() {}

      virtual std::auto_ptr<DocumentURIResolverResult>
      resolve(const Item& aURI,
              StaticContext* aStaticContext,
              XmlDataManager* aXmlDataManager) = 0;

  };

  class CollectionURIResolverResult : public URIResolverResult
  {
    public:
      virtual ~CollectionURIResolverResult() {}

      virtual Collection_t
      getCollection() const = 0;
  };

  class CollectionURIResolver
  {
    public:
      virtual ~CollectionURIResolver() {}

      virtual std::auto_ptr<CollectionURIResolverResult>
      resolve(const Item& aURI,
              StaticContext* aStaticContext,
              XmlDataManager* aXmlDataManager) = 0;
  };

  class SchemaURIResolverResult : public URIResolverResult 
  {
    public:
      virtual ~SchemaURIResolverResult() {}

      virtual std::istream*
      getSchema() const = 0;
  };

  class SchemaURIResolver
  {
    public:
      virtual ~SchemaURIResolver() {}
      
      virtual std::auto_ptr<SchemaURIResolverResult>
      resolve(const Item& aURI,
              const std::vector<Item>& aLocationHints,
              StaticContext* aStaticContext) = 0;
  };

  class ModuleURIResolverResult : public URIResolverResult
  {
    public:
      virtual ~ModuleURIResolverResult() {}

      virtual std::istream*
      getModule() const = 0;
  };

  class ModuleURIResolver
  {
    public:
      virtual ~ModuleURIResolver() {}

      virtual std::auto_ptr<ModuleURIResolverResult>
      resolve(const Item& aURI,
              StaticContext* aStaticContext) = 0;
  };

} /* namespace zorba */

#endif
