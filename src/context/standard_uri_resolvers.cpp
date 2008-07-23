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
#include "context/standard_uri_resolvers.h"

namespace zorba {

  store::Item_t
  StandardDocumentURIResolver::resolve(const store::Item_t& aAbsoluteURI,
                                     static_context* aStaticContext,
                                     dynamic_context* aDynamicContext)
  {
    std::cout << "hello! it's me" << std::endl;
  }

  store::Collection_t 
  StandardCollectionURIResolver::resolve(const store::Item_t& aAbsoluteURI,
          static_context* aStaticContext,
          dynamic_context* aDynamicContext)
  {
  }

  std::istream* 
  StandardSchemaURIResolver::resolve(const store::Item_t& aAbsoluteURI,
          const std::vector<store::Item_t> aLocationHints,
          static_context* aStaticContext)
  {
  }

  void // TODO
  StandardModuleURIResolver::resolve(const store::Item_t& aAbsoluteURI,
          const std::vector<store::Item_t> aLocationHints,
          static_context* aStaticContext)
  {
  }

} /* namespace zorba */
