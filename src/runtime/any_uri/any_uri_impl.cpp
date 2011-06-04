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
  zstring strRelative;
  zstring strBase;
  zstring strResult;
  URI baseURI;
  URI resolvedURI;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0], planState ))
  {
    strRelative = item->getStringValue();

    //If first param is an absolute URI reference, it is returned unchanged.
    try
    {
      resolvedURI = URI(strRelative);
    } 
    catch (ZorbaException const&)
    {
    }

    if (resolvedURI.is_absolute()) 
    {
      strResult = strRelative;
    }
    else 
    {
      try 
      {
        if (theChildren.size() == 1) 
        {
          // use base-uri from static context
          strBase = theSctx->get_base_uri();
          if (strBase.empty()) 
          {
            throw XQUERY_EXCEPTION( err::FONS0005, ERROR_LOC( loc ) );
          }
        }
        else if (consumeNext(item, theChildren[1], planState )) 
        {
          // two parameters => get baseuri from the second argument
          strBase = item->getStringValue();
        } 
        else
        {
          throw XQUERY_EXCEPTION(
            err::FORG0009,
            ERROR_PARAMS( ZED( NoEmptySeqAsBaseURI ) ),
            ERROR_LOC( loc )
          );
        }
        baseURI = URI(strBase, true);
      } 
      catch (ZorbaException const& e) 
      {
        throw XQUERY_EXCEPTION(
          err::FORG0002, ERROR_PARAMS( strBase, e.what() ), ERROR_LOC( loc )
        );
      }

      try 
      {
        resolvedURI = URI(baseURI, strRelative, true); // resolve with baseURI or return strRelative if it's a valid absolute URI
        strResult = resolvedURI.toString();
      }
      catch (ZorbaException const& e) 
      {
        throw XQUERY_EXCEPTION(
          err::FORG0002, ERROR_PARAMS( strRelative, e.what() ), ERROR_LOC( loc )
        );
      }
    }

    STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, strResult), state);
  } // else return empty sequence if the first argument is the empty sequence

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
