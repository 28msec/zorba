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

#include <memory>
#include <string>

#include <zorba/store_consts.h>

#include "common/common.h"

#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/utf8.h"

#include "runtime/full_text/full_text.h"
#include "runtime/full_text/ftcontains_visitor.h"
#include "runtime/full_text/ft_tokenizer.h"
#include "runtime/full_text/stl_helpers.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"

#include "system/globalenv.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class ft_item_token_creator : public ft_tokenizer::callback {
public:
  ft_item_token_creator( ft_item_tokens &tokens ) : tokens_( tokens ) { }

  void operator()( char const *utf8_s, int utf8_len,
                   int token_no, int sent_no, int para_no );
private:
  ft_item_tokens &tokens_;
};

void ft_item_token_creator::operator()( char const *utf8_s, int utf8_len,
                                        int token_no, int sent_no,
                                        int para_no ) {
  ft_item_token t;
  t.word = string( utf8_s, utf8_len );
  t.pos  = token_no;
  t.sent = sent_no;
  t.para = para_no;
  tokens_.push_back( t );
}

///////////////////////////////////////////////////////////////////////////////

static void tokenize( store::Item_t item, ft_tokenizer &tokenizer,
                      ft_tokenizer::callback &callback ) {
  switch ( item->getNodeKind() ) {
    case store::StoreConsts::documentNode:
    case store::StoreConsts::elementNode: {
      tokenizer.inc_para();
      store::Iterator_t it = item->getChildren();
      store::Item_t child;
      for ( it->open(); it->next( child ); it->close() )
        tokenize( child, tokenizer, callback );
      break;
    }
    case store::StoreConsts::textNode: {
      xqpStringStore_t const s = item->getStringValue();
      tokenizer.tokenize( s->str(), callback );
      break;
    }
    default:
      break;
  }
}

///////////////////////////////////////////////////////////////////////////////

FTContainsIterator::FTContainsIterator(
  static_context *sctx,
  QueryLoc const &loc,
  PlanIter_t &search_context, PlanIter_t &ftignore_option,
  ftexpr *ftselection,
  sub_iter_list_t &sub_iters
) : 
  base_type( sctx, loc, search_context, ftignore_option ),
  ftselection_( ftselection )
{
  sub_iters_.swap( sub_iters );
}

void FTContainsIterator::serialize( serialization::Archiver &ar ) {
  serialize_baseclass( ar, (base_type*)this );
  ar & ftselection_;
  ar & sub_iters_;
}

bool FTContainsIterator::nextImpl( store::Item_t &result,
                                   PlanState &plan_state ) const {
  bool ftcontains = false;
  store::Item_t item;
  auto_ptr<ft_tokenizer> tokenizer( ft_tokenizer::create() );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  while ( !ftcontains && consumeNext( item, theChild0.getp(), plan_state ) ) {
    ft_item_tokens tokens;
    ft_item_token_creator token_creator( tokens );
    tokenize( item, *tokenizer, token_creator );
    if ( !tokens.empty() ) {
      ftcontains_visitor v( tokens, plan_state );
      ftselection_->accept( v );
      ftcontains = v.ftcontains();
    }
  }

  STACK_PUSH( GENV_ITEMFACTORY->createBoolean( result, ftcontains ), state );
  STACK_END( state );
}

void FTContainsIterator::openImpl( PlanState &state, uint32_t &offset ) {
  BinaryBaseIterator<FTContainsIterator,PlanIteratorState>
    ::openImpl( state, offset );
  theChild0->open( state, offset );
  if ( theChild1 ) // the optional FTIgnoreOption
    theChild1->open( state, offset );
  MUTATE_EACH( sub_iter_list_t, i, sub_iters_ ) {
    (*i)->open( state, offset );
  }
}

void FTContainsIterator::closeImpl( PlanState &state ) {
  BinaryBaseIterator<FTContainsIterator,PlanIteratorState>::closeImpl( state );
  theChild0->close( state );
  if ( theChild1 ) // the optional FTIgnoreOption
    theChild1->close( state );
  MUTATE_EACH( sub_iter_list_t, i, sub_iters_ ) {
    (*i)->close( state );
  }
}

void FTContainsIterator::resetImpl( PlanState &state ) const {
  BinaryBaseIterator<FTContainsIterator, PlanIteratorState>::resetImpl( state );
  theChild0->reset( state );
  if ( theChild1 ) // the optional FTIgnoreOption
    theChild1->reset( state );
  FOR_EACH( sub_iter_list_t, i, sub_iters_ ) {
    (*i)->reset( state );
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
