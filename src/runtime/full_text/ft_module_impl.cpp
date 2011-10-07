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

#include <limits>

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "zorbatypes/URI.h"

#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "store/api/pul.h"
#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator_factory.h" // for creating the probe iterator
#include "store/api/iterator.h"
#include "store/api/index.h"

#include "runtime/core/apply_updates.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/casting.h"

#include "zorbautils/locale.h"

#include "runtime/full_text/ft_module.h"
#include "ft_stop_words_set.h"
#include "thesaurus.h"
#include "ft_util.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static iso639_1::type get_lang_from( store::Item_t lang_item,
                                     QueryLoc const &loc ) {
  zstring lang_string;
  lang_item->getStringValue2( lang_string );

  if ( !GenericCast::instance()->castableToLanguage( lang_string ) )
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS(
        ZED( BadType_23o ), lang_string, ZED( NoCastTo_45o ), "xs:language"
      ),
      ERROR_LOC( loc )
    );
  if ( iso639_1::type lang = find_lang( lang_string.c_str() ) )
    return lang;
  throw XQUERY_EXCEPTION(
    err::FTST0009, ERROR_PARAMS( lang_string ), ERROR_LOC( loc )
  );
}

///////////////////////////////////////////////////////////////////////////////

bool HostLangIterator::nextImpl( store::Item_t &result,
                                 PlanState &plan_state ) const {
  iso639_1::type const lang = get_host_lang();
  zstring lang_string = iso639_1::string_of[ lang ];

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createLanguage( result, lang_string );
  STACK_PUSH( true, state );

  STACK_END( state );
}

bool IsStopWordIterator::nextImpl( store::Item_t &result,
                                   PlanState &plan_state ) const {
  store::Item_t item;
  iso639_1::type lang;
  ftmatch_options const *options;
  static_context const *static_ctx;
  ft_stop_words_set::ptr stop_words;
  zstring word;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  static_ctx = getStaticContext();
  options = static_ctx->get_match_options();
  lang = get_lang_from( options );

  if ( consumeNext( item, theChildren[0], plan_state ) ) {
    item->getStringValue2( word );
    if ( theChildren.size() > 1 ) {
      ZORBA_ASSERT( consumeNext( item, theChildren[1], plan_state ) );
      lang = get_lang_from( item, loc );
    }
    stop_words.reset( ft_stop_words_set::get_default( lang ) );
    GENV_ITEMFACTORY->createBoolean( result, stop_words->contains( word ) );
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

bool StemIterator::nextImpl( store::Item_t &result,
                             PlanState &plan_state ) const {
  store::Item_t item;
  iso639_1::type lang;
  ftmatch_options const *options;
  internal::StemmerProvider const *provider;
  static_context const *static_ctx;
  internal::Stemmer::ptr stemmer;
  zstring word, stem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  static_ctx = getStaticContext();
  options = static_ctx->get_match_options();
  lang = get_lang_from( options );

  if ( consumeNext( item, theChildren[0], plan_state ) ) {
    item->getStringValue2( word );
    if ( theChildren.size() > 1 ) {
      ZORBA_ASSERT( consumeNext( item, theChildren[1], plan_state ) );
      lang = get_lang_from( item, loc );
    }
    provider = &internal::StemmerProvider::get_default();
    stemmer = provider->get_stemmer( lang );
    if ( stemmer ) {
      stemmer->stem( word, lang, &stem );
      GENV_ITEMFACTORY->createString( result, stem );
      STACK_PUSH( true, state );
    }
  }

  STACK_END( state );
}

bool StripDiacriticsIterator::nextImpl( store::Item_t &result,
                                        PlanState &plan_state ) const {
  store::Item_t item;
  zstring phrase, stripped_phrase;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  if ( consumeNext( item, theChildren[0], plan_state ) ) {
    item->getStringValue2( phrase );
    utf8::strip_diacritics( phrase, &stripped_phrase );
    GENV_ITEMFACTORY->createString( result, stripped_phrase );
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

bool ThesaurusLookupIterator::nextImpl( store::Item_t &result,
                                        PlanState &plan_state ) const {
  vector<zstring> comp_uris;
  store::Item_t item;
  iso639_1::type lang;
  ftmatch_options const *options;
  zstring uri = "##default";
  static_context const *static_ctx;
  zstring synonym;

  ThesaurusLookupIteratorState *state;
  DEFAULT_STACK_INIT( ThesaurusLookupIteratorState, state, plan_state );

  static_ctx = getStaticContext();
  options = static_ctx->get_match_options();
  lang = get_lang_from( options );
  state->at_least_ = 0;
  state->at_most_ = numeric_limits<internal::Thesaurus::level_type>::max();

  if ( theChildren.size() == 1 ) {
    ZORBA_ASSERT( consumeNext( item, theChildren[0], plan_state ) );
    item->getStringValue2( state->phrase_ );
  } else if ( theChildren.size() > 1 ) {
    ZORBA_ASSERT( consumeNext( item, theChildren[0], plan_state ) );
    item->getStringValue2( uri );
    ZORBA_ASSERT( consumeNext( item, theChildren[1], plan_state ) );
    item->getStringValue2( state->phrase_ );
    if ( theChildren.size() > 2 ) {
      ZORBA_ASSERT( consumeNext( item, theChildren[2], plan_state ) );
      lang = get_lang_from( item, loc );
      if ( theChildren.size() > 3 ) {
        ZORBA_ASSERT( consumeNext( item, theChildren[3], plan_state ) );
        item->getStringValue2( state->relationship_ );
        if ( theChildren.size() > 4 ) {
          ZORBA_ASSERT( theChildren.size() == 6 );
          ZORBA_ASSERT( consumeNext( item, theChildren[4], plan_state ) );
          state->at_least_ = item->getUnsignedIntValue();
          ZORBA_ASSERT( consumeNext( item, theChildren[5], plan_state ) );
          state->at_most_ = item->getUnsignedIntValue();
        }
      }
    }
  }

  static_ctx->get_component_uris( uri, impl::EntityData::THESAURUS, comp_uris );
  if ( comp_uris.size() != 1 )
    throw XQUERY_EXCEPTION(
      err::FTST0018, ERROR_PARAMS( uri ), ERROR_LOC( loc )
    );

  state->thesaurus_ = std::move(
    static_ctx->get_thesaurus( comp_uris.front(), lang )
  );
  ZORBA_ASSERT( state->thesaurus_.get() );
  state->tresult_ = std::move(
    state->thesaurus_->lookup(
      state->phrase_, state->relationship_, state->at_least_, state->at_most_
    )
  );
  ZORBA_ASSERT( state->tresult_.get() );

  while ( state->tresult_->next( &synonym ) ) {
    GENV_ITEMFACTORY->createString( result, synonym );
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

void ThesaurusLookupIterator::resetImpl( PlanState &plan_state ) const {
  NaryBaseIterator<ThesaurusLookupIterator,ThesaurusLookupIteratorState>::
    resetImpl( plan_state );
  ThesaurusLookupIteratorState *const state =
    StateTraitsImpl<ThesaurusLookupIteratorState>::getState(
      plan_state, this->theStateOffset
    );
  state->tresult_ = std::move(
    state->thesaurus_->lookup(
      state->phrase_, state->relationship_, state->at_least_, state->at_most_
    )
  );
  ZORBA_ASSERT( state->tresult_.get() );
}

bool TokenizeIterator::nextImpl( store::Item_t &result,
                                 PlanState &plan_state ) const {
  store::Item_t attr_name, attr_node;
  zstring base_uri = static_context::ZORBA_FULL_TEXT_FN_NS;
  store::Item_t item;
  iso639_1::type lang;
  Tokenizer::Numbers no;
  store::NsBindings const ns_bindings;
  ftmatch_options const *options;
  static_context const *static_ctx;
  TokenizerProvider const *tokenizer_provider;
  store::Item_t type_name;
  zstring value_string;

  TokenizeIteratorState *state;
  DEFAULT_STACK_INIT( TokenizeIteratorState, state, plan_state );

  static_ctx = getStaticContext();
  options = static_ctx->get_match_options();
  lang = get_lang_from( options );

  if ( consumeNext( state->doc_item_, theChildren[0], plan_state ) ) {
    if ( theChildren.size() > 1 ) {
      ZORBA_ASSERT( consumeNext( item, theChildren[1], plan_state ) );
      lang = get_lang_from( item, loc );
    }

    tokenizer_provider = GENV_STORE.getTokenizerProvider();
    state->doc_tokens_ =
      state->doc_item_->getTokens( *tokenizer_provider, no, lang );

    while ( state->doc_tokens_->hasNext() ) {
      FTToken const *token;
      token = state->doc_tokens_->next();
      ZORBA_ASSERT( token );

      if ( state->token_qname_.isNull() )
        GENV_ITEMFACTORY->createQName(
          state->token_qname_, static_context::ZORBA_FULL_TEXT_FN_NS, "",
          "token"
        );

      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createElementNode(
        result, nullptr, state->token_qname_, type_name, true, false,
        ns_bindings, base_uri
      );

      if ( token->lang() ) {
        value_string = iso639_1::string_of[ token->lang() ];
        type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
        GENV_ITEMFACTORY->createQName( attr_name, "", "", "lang" );
        GENV_ITEMFACTORY->createString( item, value_string );
        GENV_ITEMFACTORY->createAttributeNode(
          attr_node, result, attr_name, type_name, item
        );
      }

      ztd::to_string( token->para(), &value_string );
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createQName( attr_name, "", "", "paragraph" );
      GENV_ITEMFACTORY->createString( item, value_string );
      GENV_ITEMFACTORY->createAttributeNode(
        attr_node, result, attr_name, type_name, item
      );

      ztd::to_string( token->sent(), &value_string );
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createQName( attr_name, "", "", "sentence" );
      GENV_ITEMFACTORY->createString( item, value_string );
      GENV_ITEMFACTORY->createAttributeNode(
        attr_node, result, attr_name, type_name, item
      );

      value_string = token->value();
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createQName( attr_name, "", "", "value" );
      GENV_ITEMFACTORY->createString( item, value_string );
      GENV_ITEMFACTORY->createAttributeNode(
        attr_node, result, attr_name, type_name, item
      );

      STACK_PUSH( true, state );
    }
  }

  STACK_END( state );
}

void TokenizeIterator::resetImpl( PlanState &plan_state ) const {
  NaryBaseIterator<TokenizeIterator,TokenizeIteratorState>::
    resetImpl( plan_state );
  TokenizeIteratorState *const state =
    StateTraitsImpl<TokenizeIteratorState>::getState(
      plan_state, this->theStateOffset
    );
  state->doc_tokens_->reset();
}

bool TokenizerPropertiesIterator::nextImpl( store::Item_t &result,
                                            PlanState &plan_state ) const {
  store::Item_t attr_name, attr_node, item;
  zstring base_uri = static_context::ZORBA_FULL_TEXT_FN_NS;
  iso639_1::type lang;
  Tokenizer::Numbers no;
  store::NsBindings const ns_bindings;
  ftmatch_options const *options;
  static_context const *static_ctx;
  Tokenizer::ptr tokenizer;
  store::Item_t type_name;
  Tokenizer::Properties props;
  TokenizerProvider const *tokenizer_provider;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  static_ctx = getStaticContext();
  options = static_ctx->get_match_options();
  lang = get_lang_from( options );

  if ( !theChildren.empty() ) {
    ZORBA_ASSERT( consumeNext( item, theChildren[0], plan_state ) );
    lang = get_lang_from( item, loc );
  }

  tokenizer_provider = GENV_STORE.getTokenizerProvider();
  tokenizer = tokenizer_provider->getTokenizer( lang, no );
  tokenizer->properties( &props );

  GENV_ITEMFACTORY->createQName(
    item, static_context::ZORBA_FULL_TEXT_FN_NS, "", "tokenizer-properties"
  );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    result, nullptr, item, type_name, true, false, ns_bindings, base_uri
  );

  GENV_ITEMFACTORY->createQName( attr_name, "", "", "elements-separate-tokens" );
  GENV_ITEMFACTORY->createBoolean( item, props.elements_separate_tokens );
  GENV_ITEMFACTORY->createAttributeNode(
    attr_node, result, attr_name, type_name, item
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
