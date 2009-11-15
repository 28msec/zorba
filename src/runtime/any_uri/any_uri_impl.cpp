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

#include <iostream>

#include "zorbatypes/URI.h"

#include "context/static_context.h"

#include "runtime/any_uri/any_uri.h"
#include "runtime/util/iterator_impl.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "system/globalenv.h"

namespace zorba 
{

// 8.1 fn:resolve-uri
bool
ResolveUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqpStringStore_t strRelative;
  xqpStringStore_t strBase;
  xqpStringStore_t strResult;
  URI              baseURI;
  URI              resolvedURI;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0], planState ))
  {
    strRelative = item->getStringValue();

    //If first param is an absolute URI reference, it is returned unchanged.
    try{
      resolvedURI = URI(&*strRelative);
    } catch (error::ZorbaError&) {}

    if (resolvedURI.is_absolute()) {
      strResult = strRelative;
    }
    else 
    {
      try 
      {
        if (theChildren.size() == 1) 
        {
          // use base-uri from static context
          strBase = theSctx->baseuri().getStore();
          if (strBase->empty()) 
          {
            ZORBA_ERROR_LOC_DESC(FONS0005, loc,
                                 "base-uri is not initialized in the static context");
          }
        }
        else if (consumeNext(item, theChildren[1], planState )) 
        {
          // two parameters => get baseuri from the second argument
          strBase = item->getStringValue();
        } 
        else
        {
          ZORBA_ERROR_LOC_DESC(FORG0009, loc, "Can't treat empty-sequence as base-uri");
        }
        baseURI = URI(&*strBase, true);
      } 
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(FORG0002, loc,
                             "String {" + strBase->str() +  "} is not a valid URI: " + e.theDescription);
      }

      try 
      {
        resolvedURI = URI(baseURI, &*strRelative, true); // resolve with baseURI or return strRelative if it's a valid absolute URI
        strResult = resolvedURI.toString().getStore();
      }
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(FORG0002, loc, e.theDescription);
      }
    }
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strResult), state);
  } // else return empty sequence if the first argument is the empty sequence

  STACK_END (state);
}

} /* namespace zorba */
