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
#ifndef ZORBA_URI_RESOLVERS_WRAPPER_H
#define ZORBA_URI_RESOLVERS_WRAPPER_H

#include "context/internal_uri_resolvers.h"

namespace zorba {

  class DocumentURIResolverWrapper : public InternalDocumentURIResolver
  {
    public:
      DocumentURIResolverWrapper(DocumentURIResolver*);

      virtual ~DocumentURIResolverWrapper() {}

      virtual store::Item_t
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext,
              bool validate,
              bool tidying,
              const store::Item_t& tidyUserOpt = NULL);

    protected:
      friend class StaticContextImpl;
      DocumentURIResolver* theDocResolver;
  };

  class CollectionURIResolverWrapper : public InternalCollectionURIResolver
  {
    public:
      CollectionURIResolverWrapper(CollectionURIResolver*);
      virtual ~CollectionURIResolverWrapper() {}

      virtual store::Collection_t 
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext);

    protected:
      friend class StaticContextImpl;
      CollectionURIResolver* theColResolver;
  };

  class SchemaURIResolverWrapper : public InternalSchemaURIResolver
  {
    public:
      SchemaURIResolverWrapper(SchemaURIResolver*);
      virtual ~SchemaURIResolverWrapper() {}
      
      virtual std::string
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext,
              std::vector<store::Item_t>& aAtList,
              xqpStringStore* aFileUri = 0);

    protected:
      friend class StaticContextImpl;
      SchemaURIResolver* theSchemaResolver;
  };

  class ModuleURIResolverWrapper : public InternalModuleURIResolver
  {
    public:
      ModuleURIResolverWrapper(ModuleURIResolver*);
      virtual ~ModuleURIResolverWrapper() {}

      std::istream*
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext,
              xqpStringStore* aFileUri = 0);

    protected:
      friend class StaticContextImpl;
      ModuleURIResolver* theModuleResolver;
  };

} /* namespace zorba */

#endif


