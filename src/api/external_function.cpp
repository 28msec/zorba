/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#include <zorba/function.h>
#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/iterator.h>

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/schema_types.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

ExternalFunction::~ExternalFunction() {
  // out-of-line since it's virtual
}

Item ContextualExternalFunction::count( Arguments_t const &args,
                                        StaticContext const *sctx,
                                        DynamicContext const *dctx ) const {
  ItemSequence_t seq( evaluate( args, sctx, dctx ) );
  Iterator_t it( seq->getIterator() );
  it->open();
  Item item;
  unsigned long count = 0;
  while ( it->next( item ) )
    ++count;
  it->close();
  store::Item_t result;
  GENV_ITEMFACTORY->createInteger( result, xs_integer( count ) );
  return Item( result.get() );
}

bool ContextualExternalFunction::skip( Arguments_t const &args,
                                       StaticContext const *sctx,
                                       DynamicContext const *dctx,
                                       int64_t count ) const {
  ItemSequence_t seq( evaluate( args, sctx, dctx ) );
  Iterator_t it( seq->getIterator() );
  it->open();
  Item item;
  bool more_items = true;
  while ( count > 0 && (more_items = it->next( item )) )
    --count;
  it->close();
  return more_items;
}

Item NonContextualExternalFunction::count( Arguments_t const &args ) const {
  ItemSequence_t seq( evaluate( args ) );
  Iterator_t it( seq->getIterator() );
  it->open();
  Item item;
  unsigned long count = 0;
  while ( it->next( item ) )
    ++count;
  it->close();
  store::Item_t result;
  GENV_ITEMFACTORY->createInteger( result, xs_integer( count ) );
  return Item( result.get() );
}

bool NonContextualExternalFunction::skip( Arguments_t const &args,
                                          int64_t count ) const {
  ItemSequence_t seq( evaluate( args ) );
  Iterator_t it( seq->getIterator() );
  it->open();
  Item item;
  bool more_items = true;
  while ( count > 0 && (more_items = it->next( item )) )
    --count;
  it->close();
  return more_items;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
