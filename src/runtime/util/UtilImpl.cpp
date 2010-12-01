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

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"

#include "runtime/util/UtilImpl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "util/web/web.h"

using namespace std;

namespace zorba {

#ifdef ZORBA_WITH_TIDY
SERIALIZABLE_CLASS_VERSIONS(ZorbaTidyIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaTidyIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaTDocIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaTDocIterator)
#endif

#ifdef ZORBA_WITH_TIDY
NARY_ACCEPT(ZorbaTidyIterator);

NARY_ACCEPT(ZorbaTDocIterator);
#endif  /* ZORBA_WITH_TIDY */

#ifdef ZORBA_WITH_TIDY
bool
ZorbaTidyIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item, itemOpt;
  zstring xmlString, diag;
  zstring docUri;
  zstring baseUri = theSctx->get_base_uri();
  zstring options;
  std::istringstream is(std::istringstream::in);
  store::LoadProperties loadProps;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    if ((theChildren.size() > 1) &&
        consumeNext(itemOpt, theChildren[1].getp(), planState))
      itemOpt->getStringValue2(options);

    if( tidy(item->getStringValue().c_str(),
             xmlString,
             diag,
             (theChildren.size() > 1 ? options.c_str() : NULL)) >= 0)
    {
      //if tidy returns a value >0 a warning should be raised
      is.str(xmlString.c_str());
      loadProps.setStoreDocument(false);
      result = GENV_STORE.loadDocument(baseUri, docUri, is, loadProps);
      STACK_PUSH(result != NULL, state);
    }
    else
    {
      ZORBA_ERROR_LOC_PARAM(API0036_TIDY_ERROR, loc, diag.c_str() , "");
    }
  }

  STACK_END (state);
}



bool
ZorbaTDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t uriItem, itemOpt;
  zstring uriString;
  zstring resolvedURIString;
  store::Item_t resolvedURIItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(uriItem, theChildren[0].getp(), planState))
  {
    uriItem->getStringValue2(uriString);

    if(theChildren.size() > 1)
      consumeNext(itemOpt, theChildren[1].getp(), planState);

    try
    {
      // maybe the document is stored with the uri that is given by the user
      result = GENV_STORE.getDocument(uriString);
    }
    catch (error::ZorbaError& e)
    {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }

    if (result != NULL)
    {
      STACK_PUSH(true, state);
    }
    else
    {
      try
      {
        resolvedURIString = theSctx->resolve_relative_uri(uriString, false);
        GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
      }
      catch (error::ZorbaError& e)
      {
        ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
      }

      try
      {
        result = theSctx->get_document_uri_resolver()->
                 resolve(resolvedURIItem,
                         theSctx,
                         false,
                         true,
                         false,
                         (theChildren.size() > 1 ? itemOpt : NULL));
      }
      catch (error::ZorbaError& e)
      {
        ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
      }

      STACK_PUSH(true, state);
    }

  } // return empty sequence if input is the empty sequence
  STACK_END (state);
}
#endif  /* ZORBA_WITH_TIDY */

} /* namespace zorba */
