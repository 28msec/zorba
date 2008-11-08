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
#include <zorba/uri_resolvers.h>
#include <zorba/zorbastring.h>
#include <zorba/collection.h>
#include <zorba/item.h>

#include "context/uri_resolver_wrapper.h"
#include "store/api/item.h"
#include "store/api/collection.h"

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "api/staticcontextimpl.h"
#include "api/unmarshaller.h"
#include "api/xmldatamanagerimpl.h"

namespace zorba {

  static void
  handle_resolver_error(URIResolverResult* aResolverResult)
  {
    XQUERY_ERROR lError = XQ_NO_ERROR;
    switch (aResolverResult->getError()) {
      case URIResolverResult::UR_FODC0002: lError = FODC0002; break;
      case URIResolverResult::UR_FODC0003: lError = FODC0003; break;
      case URIResolverResult::UR_FODC0004: lError = FODC0004; break;
      case URIResolverResult::UR_FODC0005: lError = FODC0005; break;
      case URIResolverResult::UR_XQST0046: lError = XQST0046; break;
      case URIResolverResult::UR_XQST0088: lError = XQST0088; break;
      case URIResolverResult::UR_NOERROR: ZORBA_ASSERT(false); break; // avoid warnings => handled in the if-statement above
    }
    zorba::String lErrorDescription = aResolverResult->getErrorDescription();
    if (lErrorDescription.length() != 0) {
      ZORBA_ERROR_DESC(lError, *Unmarshaller::getInternalString(lErrorDescription));
    } else {
      ZORBA_ERROR(lError);
    }
  }

  DocumentURIResolverWrapper::DocumentURIResolverWrapper(DocumentURIResolver* aDocResolver)
    : theDocResolver(aDocResolver) {}

  store::Item_t
  DocumentURIResolverWrapper::resolve(const store::Item_t& aURI,
                                      static_context* aStaticContext,
                                      bool validate,
                                      bool tidying)
  {
    StaticContextImpl  lOuterStaticContext(aStaticContext, 0);
    Item               lURIItem(aURI.getp());

    // we have the ownership; it will be destroyed automatically once we leave this function
    std::auto_ptr<DocumentURIResolverResult> lResult = theDocResolver->resolve( lURIItem, 
                                                                                &lOuterStaticContext,
                                                                                XmlDataManagerImpl::getInstance(),
                                                                                validate,
                                                                                tidying);

    if (lResult->getError() == URIResolverResult::UR_NOERROR) {
      return Unmarshaller::getInternalItem(lResult->getDocument());
    } else {
      // handle errors
      handle_resolver_error(lResult.get());
    }

    // we either return a valid item or throw an error. hence, we should never get here
    ZORBA_ASSERT(false);
    return NULL;
  }

  CollectionURIResolverWrapper::CollectionURIResolverWrapper(CollectionURIResolver* aColResolver)
    : theColResolver(aColResolver) {}

  store::Collection_t 
  CollectionURIResolverWrapper::resolve(const store::Item_t& aURI,
                                        static_context* aStaticContext)
  {
    StaticContextImpl  lOuterStaticContext(aStaticContext, 0);
    Item               lURIItem(aURI.getp());  

    // we have the ownership; it will be destroyed automatically once we leave this function
    std::auto_ptr<CollectionURIResolverResult> lResult = theColResolver->resolve(lURIItem, 
                                                                                 &lOuterStaticContext,
                                                                                 XmlDataManagerImpl::getInstance());

    if (lResult->getError() == URIResolverResult::UR_NOERROR) {
      return  Unmarshaller::getInternalCollection(lResult->getCollection());
    } else {
      // handle errors
      handle_resolver_error(lResult.get());
    }

    // we either return a valid item or throw an error. hence, we should never get here
    ZORBA_ASSERT(false);
    return NULL;
  }

  SchemaURIResolverWrapper::SchemaURIResolverWrapper(SchemaURIResolver* aSchemaResolver)
    : theSchemaResolver(aSchemaResolver) {}

  std::istream*
  SchemaURIResolverWrapper::resolve(const store::Item_t& aURI,
                                    const std::vector<store::Item_t>& aLocationHints,
                                    static_context* aStaticContext)
  {
    StaticContextImpl  lOuterStaticContext(aStaticContext, 0);
    Item               lURIItem(aURI.getp());  
    std::vector<Item>  lLocationHints(aLocationHints.size());
    for (std::vector<store::Item_t>::const_iterator lIter = aLocationHints.begin();
         lIter != aLocationHints.end(); ++lIter) {
      lLocationHints.push_back(Item((*lIter).getp()));
    }

    // we have the ownership; it will be destroyed automatically once we leave this function
    std::auto_ptr<SchemaURIResolverResult> lResult = theSchemaResolver->resolve(lURIItem, 
                                                                                lLocationHints,
                                                                                &lOuterStaticContext);

    if (lResult->getError() == URIResolverResult::UR_NOERROR) {
      return lResult->getSchema();
    } else {
      // handle errors
      handle_resolver_error(lResult.get());
    }

    // we either return a valid item or throw an error. hence, we should never get here
    ZORBA_ASSERT(false);
    return NULL;
  }

  ModuleURIResolverWrapper::ModuleURIResolverWrapper(ModuleURIResolver* aModuleResolver)
    : theModuleResolver(aModuleResolver) {}

  std::istream*
  ModuleURIResolverWrapper::resolve(const store::Item_t& aURI,
                                    static_context* aStaticContext)
  {
    StaticContextImpl  lOuterStaticContext(aStaticContext, 0);
    Item               lURIItem(aURI.getp());  

    // we have the ownership; it will be destroyed automatically once we leave this function
    std::auto_ptr<ModuleURIResolverResult> lResult = theModuleResolver->resolve(lURIItem, 
                                                                                &lOuterStaticContext);

    if (lResult->getError() == URIResolverResult::UR_NOERROR) {
      return lResult->getModule();
    } else {
      // handle errors
      handle_resolver_error(lResult.get());
    }

    // we either return a valid item or throw an error. hence, we should never get here
    ZORBA_ASSERT(false);
    return NULL;
  }

} /* namespace zorba */
