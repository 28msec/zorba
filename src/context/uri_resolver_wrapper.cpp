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
#include "context/uri_resolver_wrapper.h"

namespace zorba {

  DocumentURIResolverWrapper::DocumentURIResolverWrapper(DocumentURIResolver* aDocResolver)
    : theDocResolver(aDocResolver) {}

  store::Item_t
  DocumentURIResolverWrapper::resolve(const store::Item_t& aAbsoluteURI,
                                      static_context* aStaticContext,
                                      dynamic_context* aDynamicContext)
  {
    // TODO: Call the users uri resolver and unmarshall the item here
  }

  CollectionURIResolverWrapper::CollectionURIResolverWrapper(CollectionURIResolver* aColResolver)
    : theColResolver(aColResolver) {}

  store::Collection_t 
  CollectionURIResolverWrapper::resolve(const store::Item_t& aAbsoluteURI,
                                        static_context* aStaticContext,
                                        dynamic_context* aDynamicContext)
  {
  }

  SchemaURIResolverWrapper::SchemaURIResolverWrapper(SchemaURIResolver* aSchemaResolver)
    : theSchemaResolver(aSchemaResolver) {}

  std::istream* 
  SchemaURIResolverWrapper::resolve(const store::Item_t& aAbsoluteURI,
                                    const std::vector<store::Item_t> aLocationHints,
                                    static_context* aStaticContext)
  {
  }

  ModuleURIResolverWrapper::ModuleURIResolverWrapper(ModuleURIResolver* aModuleResolver)
    : theModuleResolver(aModuleResolver) {}

  void // TODO
  ModuleURIResolverWrapper::resolve(const store::Item_t& aAbsoluteURI,
                                    const std::vector<store::Item_t> aLocationHints,
                                    static_context* aStaticContext)
  {
  }

} /* namespace zorba */
