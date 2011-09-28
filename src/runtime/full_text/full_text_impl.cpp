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

#include <zorba/locale.h>

#include "common/common.h"
#include "store/api/ft_token_iterator.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "system/globalenv.h"
#include "util/stl_util.h"

#include "ft_util.h"
#include "ftcontains_visitor.h"
#include "full_text.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

FTContainsIterator::FTContainsIterator(
  static_context *sctx,
  QueryLoc const &loc,
  PlanIter_t &search_ctx,
  PlanIter_t &ftignore_option,
  ftnode_t const &ftselection,
  sub_iter_list_t &sub_iters
) : 
  base_type( sctx, loc, search_ctx, ftignore_option ),
  ftselection_( ftselection )
{
  ZORBA_ASSERT( search_ctx );
  ZORBA_ASSERT( ftselection );
  sub_iters_.swap( sub_iters );
}

uint32_t FTContainsIterator::getStateSizeOfSubtree() const {
  uint32_t size = 0;
  FOR_EACH( sub_iter_list_t, i, sub_iters_ ) {
    size += (*i)->getStateSizeOfSubtree();
  }
  return base_type::getStateSizeOfSubtree() + size;
}

void FTContainsIterator::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (base_type*)this );
  ar & ftselection_;
  ar & sub_iters_;
}

bool FTContainsIterator::nextImpl( store::Item_t &result,
                                   PlanState &plan_state ) const {
  store::Item_t doc_item;
  bool ftcontains = false;
  PlanIterator const *const ftignore = theChild1.getp();
  locale::iso639_1::type lang;
  ftmatch_options const *options;
  PlanIterator const *const search_ctx = theChild0.getp();
  static_context const *static_ctx;
  TokenizerProvider const *tokenizer_provider;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  static_ctx = getStaticContext();
  options = static_ctx->get_match_options();
  lang = get_lang_from( options );
  tokenizer_provider = GENV_STORE.getTokenizerProvider();

  while ( !ftcontains && consumeNext( doc_item, search_ctx, plan_state ) ) {
    Tokenizer::Numbers no;
    FTTokenIterator_t doc_tokens(
      doc_item->getTokens( *tokenizer_provider, no, lang )
    );
    store::Item_t ignore_item;
    if ( ftignore )
      consumeNext( ignore_item, ftignore, plan_state );
    ftcontains_visitor v(
      doc_tokens, *static_ctx, ignore_item.getp(), plan_state
    );
    ftselection_->accept( v );
    ftcontains = v.ftcontains();
  }

  STACK_PUSH( GENV_ITEMFACTORY->createBoolean( result, ftcontains ), state );
  STACK_END( state );
}

void FTContainsIterator::openImpl( PlanState &state, uint32_t &offset ) {
  base_type::openImpl( state, offset );
  MUTATE_EACH( sub_iter_list_t, i, sub_iters_ ) {
    (*i)->open( state, offset );
  }
}

void FTContainsIterator::closeImpl( PlanState &state ) {
  MUTATE_EACH( sub_iter_list_t, i, sub_iters_ ) {
    (*i)->close( state );
  }
  base_type::closeImpl( state );
}

void FTContainsIterator::resetImpl( PlanState &state ) const {
  base_type::resetImpl( state );
  FOR_EACH( sub_iter_list_t, i, sub_iters_ ) {
    (*i)->reset( state );
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
