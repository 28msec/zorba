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
#ifndef ZORBA_URI_RESOLVERS_H
#define ZORBA_URI_RESOLVERS_H

#include <istream>
#include <vector>

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"
#include "store/api/item.h"

namespace zorba 
{


/*******************************************************************************

********************************************************************************/
class InternalDocumentURIResolver
{
public:
  virtual ~InternalDocumentURIResolver() {}

  virtual store::Item_t resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext,
        bool validate,
        bool tidying,
        bool replaceDoc,
        const store::Item_t& tidyUserOpt = NULL) = 0;
};


/*******************************************************************************

********************************************************************************/
class InternalCollectionURIResolver
{
public:
  virtual ~InternalCollectionURIResolver() {}
  
  virtual store::Collection_t resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext) = 0;
};
  

/*******************************************************************************

********************************************************************************/
class InternalSchemaURIResolver
{
public:
  virtual ~InternalSchemaURIResolver() {}
      
  virtual std::string resolve(
        const store::Item_t& aURI,
        static_context* aStaticContext,
        std::vector<store::Item_t>& aAtList,
        zstring& aFileUri) = 0;
};


/*******************************************************************************

********************************************************************************/
class InternalModuleURIResolver
{
public:
  virtual ~InternalModuleURIResolver() {}

  virtual void resolveTargetNamespace(
        const std::string& nsURI,
        static_context& sctx,
        std::vector<std::string>& compURIs) = 0;

  virtual std::istream* resolve(
        const std::string& uri,
        static_context& sctx,
        std::string& url) = 0;
#if 0
  virtual ExternalModule* getExternalModule(
        const zstring& aFileUri,
        static_context& sctx)
  {
    return NULL;
  }
#endif
};

} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
