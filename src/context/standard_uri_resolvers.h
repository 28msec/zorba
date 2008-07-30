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
#ifndef ZORBA_STANDARD_URI_RESOLVERS_H
#define ZORBA_STANDARD_URI_RESOLVERS_H

#include "context/internal_uri_resolvers.h"

namespace zorba {

  class StandardDocumentURIResolver : public InternalDocumentURIResolver
  {
    public:
      virtual ~StandardDocumentURIResolver() {}

      virtual store::Item_t
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext);
  };

  class StandardCollectionURIResolver : public InternalCollectionURIResolver
  {
    public:
      virtual ~StandardCollectionURIResolver() {}

      virtual store::Collection_t 
      resolve(const store::Item_t& aURI,
              static_context* aStaticContext);
  };

  class StandardSchemaURIResolver : public InternalSchemaURIResolver
  {
    public:
      virtual ~StandardSchemaURIResolver() {}
      
      virtual std::istream* 
      resolve(const store::Item_t& aURI,
              const std::vector<store::Item_t>& aLocationHints,
              static_context* aStaticContext);
  };

  class StandardModuleURIResolver : public InternalModuleURIResolver
  {
    public:
      virtual ~StandardModuleURIResolver() {}

      virtual std::istream*
      resolve(const store::Item_t& aURI,
              const std::vector<store::Item_t>& aLocationHints,
              static_context* aStaticContext);
  };

} /* namespace zorba */

#endif

