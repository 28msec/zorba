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
#include "stdafx.h"

#include <zorba/uri_resolvers.h>
#include <zorba/zorba_string.h>
#include <zorba/collection.h>
#include <zorba/item.h>

#include "context/uri_resolver_wrapper.h"
#include "store/api/item.h"
#include "store/api/collection.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"

#include "api/staticcontextimpl.h"
#include "api/unmarshaller.h"
#include "api/xmldatamanagerimpl.h"

namespace zorba 
{

#ifndef ZORBA_NO_FULL_TEXT
/*******************************************************************************

********************************************************************************/
FullTextURIResolverWrapper::FullTextURIResolverWrapper(FullTextURIResolver* aFullTextResolver)
  :
  theFullTextResolver(aFullTextResolver)
{
}


zstring
FullTextURIResolverWrapper::resolve(
    const store::Item_t& aURI,
    static_context* aStaticContext)
{
  StaticContextImpl  lOuterStaticContext(aStaticContext, 0);
  Item               lURIItem(aURI.getp());
  
  // we have the ownership; it will be destroyed automatically once we leave this function
  std::auto_ptr<FullTextURIResolverResult> lResult =
    theFullTextResolver->resolve(lURIItem, &lOuterStaticContext);

  if (lResult->getError() == URIResolverResult::UR_NOERROR) 
  {
    return Unmarshaller::getInternalString(lResult->getResolvedFullText()).c_str();
  }
  return "";
}
#endif

} // namespace zorba
/* vim:set et sw=2 ts=2: */
