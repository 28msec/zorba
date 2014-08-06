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
#include <zorba/config.h>

//
// This entire file should be effectively skipped when building with
// ZORBA_NO_FULL_TEXT. We can't prevent it from being compiled, but we
// can prevent it from having any real content.
//
#ifndef ZORBA_NO_FULL_TEXT


#include <limits>
#include <typeinfo>

#include <zorba/diagnostic_list.h>
#include <zorba/internal/unique_ptr.h>

#include "api/unmarshaller.h"

#include "context/namespace_context.h"
#include "context/static_context.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "store/api/index.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/store.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeimpl.h"
#include "types/typeops.h"

#include "util/locale.h"
#include "util/stl_util.h"
#include "util/utf8_util.h"

#include "zorbatypes/integer.h"
#include "zorbatypes/URI.h"

#include "ft_module_util.h"
#include "ft_stop_words_set.h"
#include "ft_token_seq_iterator.h"
#include "ft_util.h"
#include "thesaurus.h"

#include "runtime/full_text/ft_module.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

inline iso639_1::type get_lang_from( static_context const *sctx ) {
  iso639_1::type const lang = get_lang_from( sctx->get_match_options() );
  return lang ? lang : GENV.get_host_lang();
}

static iso639_1::type get_lang_from( store::Item_t lang_item,
                                     QueryLoc const &loc ) {
  zstring const lang_str( lang_item->getStringValue() );
  if ( !GenericCast::instance()->castableToLanguage( lang_str ) )
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS(
        ZED( BadType_23o ), lang_str, ZED( NoCastTo_45o ), "xs:language"
      ),
      ERROR_LOC( loc )
    );
  if ( iso639_1::type const lang = find_lang( lang_str ) )
    return lang;
  throw XQUERY_EXCEPTION(
    err::FTST0009 /* lang not supported */,
    ERROR_PARAMS( lang_str ),
    ERROR_LOC( loc )
  );
}

static Tokenizer::ptr get_tokenizer( iso639_1::type lang,
                                     Tokenizer::State *t_state,
                                     QueryLoc const &loc ) {
  TokenizerProvider const *const provider = GENV_STORE.getTokenizerProvider();
  ZORBA_ASSERT( provider );
  Tokenizer::ptr tokenizer;
  if ( !provider->getTokenizer( lang, t_state, &tokenizer ) )
    throw XQUERY_EXCEPTION(
      err::FTST0009 /* lang not supported */,
      ERROR_PARAMS( iso639_1::str( lang ), ZED( FTST0009_BadTokenizerLang ) ),
      ERROR_LOC( loc )
    );
  return std::move( tokenizer );
}

static void make_token_object( FTToken const &token, store::Item_t &result ) {
  store::Item_t item;
  zstring s;
  vector<store::Item_t> keys, values;

  if ( token.lang() ) {
    s = "lang";
    GENV_ITEMFACTORY->createString( item, s );
    keys.push_back( item );
    s = iso639_1::str( token.lang() );
    GENV_ITEMFACTORY->createString( item, s );
    values.push_back( item );
  }

  s = "paragraph";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  GENV_ITEMFACTORY->createInteger( item, xs_integer( token.para() ) );
  values.push_back( item );

  s = "sentence";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  GENV_ITEMFACTORY->createInteger( item, xs_integer( token.sent() ) );
  values.push_back( item );

  s = "value";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  s = token.value();
  GENV_ITEMFACTORY->createString( item, s );
  values.push_back( item );

  if ( store::Item const *const token_item = token.item() ) {
    if ( GENV_STORE.getNodeReference( item, token_item ) ) {
      s = item->getStringValue();
      GENV_ITEMFACTORY->createAnyURI( item, s );
      values.push_back( item );
      s = "node-ref";
      GENV_ITEMFACTORY->createString( item, s );
      keys.push_back( item );
    }
  }

  GENV_ITEMFACTORY->createJSONObject( result, keys, values );
}

///////////////////////////////////////////////////////////////////////////////

bool CurrentCompareOptionsIterator::nextImpl( store::Item_t &result,
                                              PlanState &plan_state ) const {
  store::Item_t item;
  zstring s;
  vector<store::Item_t> keys, values;

  static_context const *const sctx = getStaticContext();
  ZORBA_ASSERT( sctx );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  ft_case_mode::type case_mode;
  ft_diacritics_mode::type diacritics_mode;
  ft_stem_mode::type stem_mode;

  if ( ftmatch_options const *const options = sctx->get_match_options() ) {
    case_mode = options->get_case_option()->get_mode();
    diacritics_mode = options->get_diacritics_option()->get_mode();
    stem_mode = options->get_stem_option()->get_mode();
  } else {
    case_mode = ft_case_mode::DEFAULT;
    diacritics_mode = ft_diacritics_mode::DEFAULT;
    stem_mode = ft_stem_mode::DEFAULT;
  }

  s = "case";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  s = ft_case_mode::string_of[ case_mode ];
  GENV_ITEMFACTORY->createString( item, s );
  values.push_back( item );

  s = "diacritics";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  s = ft_diacritics_mode::string_of[ diacritics_mode ];
  GENV_ITEMFACTORY->createString( item, s );
  values.push_back( item );

  s = "stemming";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  s = ft_stem_mode::string_of[ stem_mode ];
  GENV_ITEMFACTORY->createString( item, s );
  values.push_back( item );

  GENV_ITEMFACTORY->createJSONObject( result, keys, values );

  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool CurrentLangIterator::nextImpl( store::Item_t &result,
                                    PlanState &plan_state ) const {
  static_context const *const sctx = getStaticContext();
  ZORBA_ASSERT( sctx );
  iso639_1::type const lang = get_lang_from( sctx );
  zstring lang_string( iso639_1::str( lang ) );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createLanguage( result, lang_string );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool HostLangIterator::nextImpl( store::Item_t &result,
                                 PlanState &plan_state ) const {
  iso639_1::type const lang = GENV.get_host_lang();
  zstring lang_string = iso639_1::str( lang );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createLanguage( result, lang_string );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool IsStemLangSupportedIterator::nextImpl( store::Item_t &result,
                                            PlanState &plan_state ) const {
  bool is_supported;
  store::Item_t item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  try {
    internal::StemmerProvider const *const provider =
      GENV_STORE.getStemmerProvider();
    is_supported = provider->getStemmer( get_lang_from( item, loc ) );
  }
  catch ( ZorbaException const &e ) {
    if ( e.diagnostic() != err::FTST0009 /* lang not supported */ )
      throw;
    is_supported = false;
  }

  GENV_ITEMFACTORY->createBoolean( result, is_supported );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool IsStopWordIterator::nextImpl( store::Item_t &result,
                                   PlanState &plan_state ) const {
  store::Item_t item;
  iso639_1::type lang;
  ft_stop_words_set::ptr stop_words;
  zstring word;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  item->getStringValue2( word );

  if ( theChildren.size() > 1 ) {
    consumeNext( item, theChildren[1], plan_state );
    lang = get_lang_from( item, loc );
  } else {
    static_context const *const sctx = getStaticContext();
    ZORBA_ASSERT( sctx );
    lang = get_lang_from( sctx );
  }

  stop_words.reset( ft_stop_words_set::get_default( lang ) );
  if ( !stop_words )
    throw XQUERY_EXCEPTION(
      err::FTST0009 /* lang not supported */,
      ERROR_PARAMS( iso639_1::str( lang ), ZED( FTST0009_BadStopWordsLang ) ),
      ERROR_LOC( loc )
    );
  GENV_ITEMFACTORY->createBoolean( result, stop_words->contains( word ) );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool IsStopWordLangSupportedIterator::nextImpl( store::Item_t &result,
                                                PlanState &plan_state ) const {
  bool is_supported;
  store::Item_t item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  try {
    is_supported =
      !!ft_stop_words_set::get_default( get_lang_from( item, loc ) );
  }
  catch ( ZorbaException const &e ) {
    if ( e.diagnostic() != err::FTST0009 /* lang not supported */ )
      throw;
    is_supported = false;
  }

  GENV_ITEMFACTORY->createBoolean( result, is_supported );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool IsThesaurusLangSupportedIterator::nextImpl( store::Item_t &result,
                                                 PlanState &plan_state ) const {
  bool is_supported;
  store::Item_t item;
  zstring uri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  if ( theChildren.size() > 1 ) {
    item->getStringValue2( uri );
    consumeNext( item, theChildren[1], plan_state );
  } else {
    uri = "##default";
  }

  try {
    iso639_1::type const lang = get_lang_from( item, loc );
    static_context const *const sctx = getStaticContext();
    ZORBA_ASSERT( sctx );
    zstring error_msg;
    unique_ptr<internal::Resource> rsrc = sctx->resolve_uri(
      uri, internal::EntityData::THESAURUS, error_msg
    );
    if ( !rsrc.get() )
      throw XQUERY_EXCEPTION(
        err::FTST0018, ERROR_PARAMS( uri ), ERROR_LOC( loc )
      );
#if 0
    if ( !error_msg.empty() )
      cerr << "error_msg=" << error_msg << endl;
#endif
    internal::ThesaurusProvider const *const provider =
      dynamic_cast<internal::ThesaurusProvider const*>( rsrc.get() );
    ZORBA_ASSERT( provider );
    is_supported = provider->getThesaurus( lang );
  }
  catch ( ZorbaException const &e ) {
    if ( e.diagnostic() != err::FTST0009 /* lang not supported */ )
      throw;
    is_supported = false;
  }

  GENV_ITEMFACTORY->createBoolean( result, is_supported );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool IsTokenizerLangSupportedIterator::nextImpl( store::Item_t &result,
                                                 PlanState &plan_state ) const {
  bool is_supported;
  store::Item_t item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  try {
    TokenizerProvider const *const p = GENV_STORE.getTokenizerProvider();
    is_supported = p && p->getTokenizer( get_lang_from( item, loc ) );
  }
  catch ( ZorbaException const &e ) {
    if ( e.diagnostic() != err::FTST0009 /* lang not supported */ )
      throw;
    is_supported = false;
  }

  GENV_ITEMFACTORY->createBoolean( result, is_supported );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool StemIterator::nextImpl( store::Item_t &result,
                             PlanState &plan_state ) const {
  store::Item_t item;
  iso639_1::type lang;
  internal::StemmerProvider const *provider;
  internal::Stemmer::ptr stemmer;
  zstring word, stem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  item->getStringValue2( word );
  utf8::to_lower( word );

  if ( theChildren.size() > 1 ) {
    consumeNext( item, theChildren[1], plan_state );
    lang = get_lang_from( item, loc );
  } else {
    static_context const *const sctx = getStaticContext();
    ZORBA_ASSERT( sctx );
    lang = get_lang_from( sctx );
  }

  provider = GENV_STORE.getStemmerProvider();
  ZORBA_ASSERT( provider );
  if ( provider->getStemmer( lang, &stemmer ) ) {
    stemmer->stem( word, lang, &stem );
    GENV_ITEMFACTORY->createString( result, stem );
    STACK_PUSH( true, state );
  } else {
    throw XQUERY_EXCEPTION(
      err::FTST0009 /* lang not supported */,
      ERROR_PARAMS( iso639_1::str( lang ), ZED( FTST0009_BadStemmerLang ) ),
      ERROR_LOC( loc )
    );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool StripDiacriticsIterator::nextImpl( store::Item_t &result,
                                        PlanState &plan_state ) const {
  store::Item_t item;
  zstring phrase, stripped_phrase;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  item->getStringValue2( phrase );
  utf8::strip_diacritics( phrase, &stripped_phrase );
  GENV_ITEMFACTORY->createString( result, stripped_phrase );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUC__
# ifdef GCC_PRAGMA_DIAGNOSTIC_PUSH
#   pragma GCC diagnostic push
# endif /* GCC_PRAGMA_DIAGNOSTIC_PUSH */
# pragma GCC diagnostic ignored "-Wunknown-pragmas"
# pragma GCC diagnostic ignored "-Wpragmas"
# pragma GCC diagnostic ignored "-Wbind-to-temporary-copy"
#endif /* __GNUC__ */

bool ThesaurusLookupIterator::nextImpl( store::Item_t &result,
                                        PlanState &plan_state ) const {
  zstring error_msg;
  store::Item_t item;
  iso639_1::type lang;
  unique_ptr<internal::Resource> rsrc;
  zstring uri = "##default";
  static_context const *sctx;
  zstring synonym;
  internal::ThesaurusProvider const *provider;

  ThesaurusLookupIteratorState *state;
  DEFAULT_STACK_INIT( ThesaurusLookupIteratorState, state, plan_state );

  sctx = getStaticContext();
  ZORBA_ASSERT( sctx );
  lang = get_lang_from( sctx );
  state->at_least_ = 0;
  state->at_most_ = numeric_limits<internal::Thesaurus::level_type>::max();

  if ( theChildren.size() == 1 ) {
    consumeNext( item, theChildren[0], plan_state );
    item->getStringValue2( state->phrase_ );
  } else if ( theChildren.size() > 1 ) {
    consumeNext( item, theChildren[0], plan_state );
    item->getStringValue2( uri );
    consumeNext( item, theChildren[1], plan_state );
    item->getStringValue2( state->phrase_ );
    if ( theChildren.size() > 2 ) {
      consumeNext( item, theChildren[2], plan_state );
      lang = get_lang_from( item, loc );
      if ( theChildren.size() > 3 ) {
        consumeNext( item, theChildren[3], plan_state );
        item->getStringValue2( state->relationship_ );
        if ( theChildren.size() > 4 ) {
          ZORBA_ASSERT( theChildren.size() == 6 );
          consumeNext( item, theChildren[4], plan_state );
          state->at_least_ = to_ft_int( item->getIntegerValue() );
          consumeNext( item, theChildren[5], plan_state );
          state->at_most_ = to_ft_int( item->getIntegerValue() );
        }
      }
    }
  }

  rsrc = sctx->resolve_uri(
    uri, internal::EntityData::THESAURUS, error_msg
  );
  if ( !rsrc.get() )
    throw XQUERY_EXCEPTION(
      err::FTST0018, ERROR_PARAMS( uri ), ERROR_LOC( loc )
    );

  provider = dynamic_cast<internal::ThesaurusProvider const*>( rsrc.get() );
  ZORBA_ASSERT( provider );
  if ( !provider->getThesaurus( lang, &state->thesaurus_ ) )
    throw XQUERY_EXCEPTION(
      err::FTST0009 /* lang not supported */,
      ERROR_PARAMS( iso639_1::str( lang ), ZED( FTST0009_BadThesaurusLang ) ),
      ERROR_LOC( loc )
    );

  state->tresult_ = state->thesaurus_->lookup(
    state->phrase_, state->relationship_, state->at_least_, state->at_most_
  );
  if ( state->tresult_ )
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
  state->tresult_ = state->thesaurus_->lookup(
    state->phrase_, state->relationship_, state->at_least_, state->at_most_
  );
}

#ifndef WIN32
#ifdef GCC_PRAGMA_DIAGNOSTIC_PUSH
# pragma GCC diagnostic pop
#else
# pragma GCC diagnostic warning "-Wbind-to-temporary-copy"
# pragma GCC diagnostic warning "-Wunknown-pragmas"
# pragma GCC diagnostic warning "-Wpragmas"
#endif /* GCC_PRAGMA_DIAGNOSTIC_PUSH */
#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

bool TokenizeNodeIterator::nextImpl( store::Item_t &result,
                                     PlanState &plan_state ) const {
  store::Item_t item;
  iso639_1::type lang;
  Tokenizer::State t_state;
  TokenizerProvider const *tokenizer_provider;

  TokenizeNodeIteratorState *state;
  DEFAULT_STACK_INIT( TokenizeNodeIteratorState, state, plan_state );

  if ( consumeNext( state->doc_item_, theChildren[0], plan_state ) ) {
    if ( theChildren.size() > 1 ) {
      consumeNext( item, theChildren[1], plan_state );
      lang = get_lang_from( item, loc );
    } else {
      static_context const *const sctx = getStaticContext();
      ZORBA_ASSERT( sctx );
      lang = get_lang_from( sctx );
    }

    tokenizer_provider = GENV_STORE.getTokenizerProvider();
    ZORBA_ASSERT( tokenizer_provider );
    state->doc_tokens_ =
      state->doc_item_->getTokens( *tokenizer_provider, t_state, lang );

    while ( state->doc_tokens_->hasNext() ) {
      make_token_object( *state->doc_tokens_->next(), result );
      STACK_PUSH( true, state );
    }
  }

  STACK_END( state );
}

void TokenizeNodeIterator::resetImpl( PlanState &plan_state ) const {
  NaryBaseIterator<TokenizeNodeIterator,TokenizeNodeIteratorState>::
    resetImpl( plan_state );
  TokenizeNodeIteratorState *const state =
    StateTraitsImpl<TokenizeNodeIteratorState>::getState(
      plan_state, this->theStateOffset
    );
  FTTokenIterator_t &doc_tokens = state->doc_tokens_;
  if ( !doc_tokens.isNull() )
    doc_tokens->reset();
}

///////////////////////////////////////////////////////////////////////////////

bool TokenizeNodesIterator::nextImpl( store::Item_t &result,
                                      PlanState &plan_state ) const {
  store::Item_t item;
  iso639_1::type lang;
  Tokenizer::State t_state;
  Tokenizer::ptr tokenizer;

  TokenizeNodesIteratorState *state;
  DEFAULT_STACK_INIT( TokenizeNodesIteratorState, state, plan_state );

  if ( theChildren.size() > 2 ) {
    consumeNext( item, theChildren[2], plan_state );
    lang = get_lang_from( item, loc );
  } else {
    static_context const *const sctx = getStaticContext();
    ZORBA_ASSERT( sctx );
    lang = get_lang_from( sctx );
  }

  tokenizer = get_tokenizer( lang, &state->t_state_, loc );

  // $includes
  while ( consumeNext( item, theChildren[0], plan_state ) )
    state->includes_.push_back( item );
  state->includes_.push_back( store::Item_t() );  // sentinel

  // $excludes
  while ( consumeNext( item, theChildren[1], plan_state ) ) {
    store::Item_t exc_si;
    GENV_STORE.getStructuralInformation( exc_si, item.getp() );
    state->excludes_.push_back( exc_si );
  }

  state->callback_.set_tokens( state->tokens_ );
  state->langs_.push( lang );
  state->tokenizers_.push( tokenizer.get() );
  tokenizer.release();

  while ( true ) {
    if ( state->tokens_.empty() ) {
      if ( state->includes_.empty() )
        break;

      store::Item_t inc( state->includes_.front() );
      state->includes_.pop_front();
      if ( inc.isNull() ) {             // sentinel
        state->langs_.pop();
        Tokenizer::ptr deleter( ztd::pop_stack( state->tokenizers_ ) );
        continue;
      }

      store::Item_t inc_si;
      GENV_STORE.getStructuralInformation( inc_si, inc.getp() );
      bool excluded = false;
      FOR_EACH( vector<store::Item_t>, exc, state->excludes_ ) {
        if ( inc_si->equals( *exc ) || (*exc)->isInSubtreeOf( inc_si ) ) {
          excluded = true;
          break;
        }
      }
      if ( excluded )
        continue;

      bool add_sentinel = false;
      switch ( inc->getNodeKind() ) {
        case store::StoreConsts::elementNode:
          ++state->t_state_.para;
          if ( find_lang_attribute( *inc, &lang ) ) {
            state->langs_.push( lang );
            tokenizer = get_tokenizer( lang, &state->t_state_, loc );
            state->tokenizers_.push( tokenizer.get() );
            tokenizer.release();
            add_sentinel = true;
          }
          // no break;
        case store::StoreConsts::documentNode: {
          list<store::Item_t>::iterator pos = state->includes_.begin();
          store::Iterator_t i = inc->getChildren();
          i->open();
          for ( store::Item_t child; i->next( child ); ) {
            switch ( child->getNodeKind() ) {
              case store::StoreConsts::attributeNode:
              case store::StoreConsts::commentNode:
              case store::StoreConsts::piNode:
                continue;               // never include these implicitly
              default:
                pos = state->includes_.insert( pos, child );
                ++pos;
            }
          }
          i->close();
          if ( add_sentinel )           // sentinel
            state->includes_.insert( pos, store::Item_t() );
          continue;
        }

        case store::StoreConsts::attributeNode:
        case store::StoreConsts::commentNode:
        case store::StoreConsts::piNode:
          // tokenize these because they were included explicitly
        case store::StoreConsts::textNode: {
          zstring const s( inc->getStringValue() );
          Item const temp( inc.getp() );
          state->tokenizers_.top()->tokenize_string(
            s.data(), s.size(), state->langs_.top(), false, state->callback_,
            &temp
          );
          break;
        }

        default:
          break;
      } // switch
      continue;
    } // if ( state->tokens_.empty() )

    make_token_object( state->tokens_.front(), result );
    state->tokens_.pop_front();
    STACK_PUSH( true, state );
  } // while

  STACK_END( state );
}

void TokenizeNodesIterator::resetImpl( PlanState &plan_state ) const {
  NaryBaseIterator<TokenizeNodesIterator,TokenizeNodesIteratorState>::
    resetImpl( plan_state );
  TokenizeNodesIteratorState *const state =
    StateTraitsImpl<TokenizeNodesIteratorState>::getState(
      plan_state, this->theStateOffset
    );
  FTTokenIterator_t &doc_tokens = state->doc_tokens_;
  if ( !doc_tokens.isNull() )
    doc_tokens->reset();
}

///////////////////////////////////////////////////////////////////////////////

bool TokenizerPropertiesIterator::nextImpl( store::Item_t &result,
                                            PlanState &plan_state ) const {
  store::Item_t item;
  iso639_1::type lang;
  Tokenizer::Properties props;
  zstring s;
  Tokenizer::ptr tokenizer;
  Tokenizer::State t_state;
  vector<store::Item_t> keys, values;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  if ( theChildren.size() > 0 ) {
    consumeNext( item, theChildren[0], plan_state );
    lang = get_lang_from( item, loc );
  } else {
    static_context const *const sctx = getStaticContext();
    ZORBA_ASSERT( sctx );
    lang = get_lang_from( sctx );
  }

  tokenizer = get_tokenizer( lang, &t_state, loc );
  tokenizer->properties( &props );

  s = "uri";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  GENV_ITEMFACTORY->createAnyURI( item, props.uri );
  values.push_back( item );

  s = "comments-separate-tokens";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  GENV_ITEMFACTORY->createBoolean( item, props.comments_separate_tokens );
  values.push_back( item );

  s = "elements-separate-tokens";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  GENV_ITEMFACTORY->createBoolean( item, props.elements_separate_tokens );
  values.push_back( item );

  s = "processing-instructions-separate-tokens";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  GENV_ITEMFACTORY->createBoolean( item, props.processing_instructions_separate_tokens );
  values.push_back( item );

  s = "supported-languages";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  { // local scope
    vector<store::Item_t> langs;
    FOR_EACH( Tokenizer::Properties::languages_type, i, props.languages ) {
      s = iso639_1::str( *i );
      GENV_ITEMFACTORY->createString( item, s );
      langs.push_back( item );
    }
    GENV_ITEMFACTORY->createJSONArray( item, langs );
  }
  values.push_back( item );

  GENV_ITEMFACTORY->createJSONObject( result, keys, values );

  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

struct TokenizeStringIteratorCallback : Tokenizer::Callback {
  void token( char const*, size_type, iso639_1::type, size_type, size_type,
              size_type, Item const* );

  FTTokenSeqIterator::FTTokens tokens_;
};

void TokenizeStringIteratorCallback::
token( char const *utf8_s, size_type utf8_len, iso639_1::type lang,
       size_type token_no, size_type sent_no, size_type para_no,
       Item const *api_item ) {
  store::Item const *const store_item =
    api_item ? Unmarshaller::getInternalItem( *api_item ) : nullptr;

  FTToken const token(
    utf8_s, utf8_len, token_no, sent_no, para_no, store_item, lang
  );
  tokens_.push_back( token );
}

bool TokenizeStringIterator::nextImpl( store::Item_t &result,
                                       PlanState &plan_state ) const {
  store::Item_t item;
  iso639_1::type lang;
  zstring value_string;

  TokenizeStringIteratorState *state;
  DEFAULT_STACK_INIT( TokenizeStringIteratorState, state, plan_state );

  if ( consumeNext( item, theChildren[0], plan_state ) ) {
    item->getStringValue2( value_string );
    if ( theChildren.size() > 1 ) {
      consumeNext( item, theChildren[1], plan_state );
      lang = get_lang_from( item, loc );
    } else {
      static_context const *const sctx = getStaticContext();
      ZORBA_ASSERT( sctx );
      lang = get_lang_from( sctx );
    }

    { // local scope
    Tokenizer::State t_state;
    Tokenizer::ptr const tokenizer( get_tokenizer( lang, &t_state, loc ) );
    TokenizeStringIteratorCallback callback;
    tokenizer->tokenize_string(
      value_string.data(), value_string.size(), lang, false, callback
    );
    state->string_tokens_.swap( callback.tokens_ );
    } // local scope

    while ( state->string_tokens_.hasNext() ) {
      FTToken const *token;
      token = state->string_tokens_.next();
      ZORBA_ASSERT( token );
      value_string = token->value();
      GENV_ITEMFACTORY->createString( result, value_string );
      STACK_PUSH( true, state );
    }
  }

  STACK_END( state );
}

void TokenizeStringIterator::resetImpl( PlanState &plan_state ) const {
  NaryBaseIterator<TokenizeStringIterator,TokenizeStringIteratorState>::
    resetImpl( plan_state );
  TokenizeStringIteratorState *const state =
    StateTraitsImpl<TokenizeStringIteratorState>::getState(
      plan_state, this->theStateOffset
    );
  state->string_tokens_.reset();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_NO_FULL_TEXT */
/* vim:set et sw=2 ts=2: */
