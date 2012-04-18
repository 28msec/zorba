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
#include <typeinfo>

#include <zorba/diagnostic_list.h>

#include "api/unmarshaller.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "store/api/index.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/store.h"

#include "system/globalenv.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/casting.h"

#include "util/utf8_util.h"
#include "zorbatypes/URI.h"
#include "zorbautils/locale.h"

#include "runtime/full_text/ft_module.h"
#include "ft_stop_words_set.h"
#include "ft_token_seq_iterator.h"
#include "ft_util.h"
#include "thesaurus.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

inline iso639_1::type get_lang_from( static_context const *sctx ) {
  iso639_1::type const lang = get_lang_from( sctx->get_match_options() );
  return lang ? lang : get_host_lang();
}

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
  if ( iso639_1::type const lang = find_lang( lang_string.c_str() ) )
    return lang;
  throw XQUERY_EXCEPTION(
    err::FTST0009, ERROR_PARAMS( lang_string ), ERROR_LOC( loc )
  );
}

///////////////////////////////////////////////////////////////////////////////

bool CurrentLangIterator::nextImpl( store::Item_t &result,
                                    PlanState &plan_state ) const {
  iso639_1::type const lang = get_lang_from( getStaticContext() );
  zstring lang_string( iso639_1::string_of[ lang ] );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createLanguage( result, lang_string );
  STACK_PUSH( true, state );

  STACK_END( state );
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

///////////////////////////////////////////////////////////////////////////////

bool IsStemLangSupportedIterator::nextImpl( store::Item_t &result,
                                            PlanState &plan_state ) const {
  bool is_supported;
  store::Item_t item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0], plan_state );
  try {
    // TODO: why is this always the default StemmerProvider?
    internal::StemmerProvider const *const provider =
      &internal::StemmerProvider::get_default();
    is_supported = provider->get_stemmer( get_lang_from( item, loc ) );
  }
  catch ( XQueryException const &e ) {
    if ( e.diagnostic() != err::FTST0009 )
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

  lang = get_lang_from( getStaticContext() );

  consumeNext( item, theChildren[0], plan_state );
  item->getStringValue2( word );

  if ( theChildren.size() > 1 ) {
    consumeNext( item, theChildren[1], plan_state );
    lang = get_lang_from( item, loc );
  }

  stop_words.reset( ft_stop_words_set::get_default( lang ) );
  if ( !stop_words )
    throw XQUERY_EXCEPTION(
      zerr::ZXQP8405_STOP_WORDS_LANG_NOT_SUPPORTED,
      ERROR_PARAMS( lang ),
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
    is_supported = ft_stop_words_set::get_default( get_lang_from( item, loc ) );
  }
  catch ( XQueryException const &e ) {
    if ( e.diagnostic() != err::FTST0009 )
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

    vector<zstring> comp_uris;
    sctx->get_component_uris(
      uri, internal::EntityData::THESAURUS, comp_uris
    );
    if ( comp_uris.size() != 1 )
      throw XQUERY_EXCEPTION(
        err::FTST0018, ERROR_PARAMS( uri ), ERROR_LOC( loc )
      );

    zstring error_msg;
    auto_ptr<internal::Resource> rsrc = sctx->resolve_uri(
      comp_uris.front(), internal::EntityData::THESAURUS, error_msg
    );
    if ( !rsrc.get() )
      throw XQUERY_EXCEPTION(
        err::FTST0018, ERROR_PARAMS( uri ), ERROR_LOC( loc )
      );
#if 0
    if ( !error_msg.empty() )
      cerr << "error_msg=" << error_msg << endl;
#endif
    cout << typeid(*rsrc.get()).name() << endl;
    internal::ThesaurusProvider const *const t_provider =
      dynamic_cast<internal::ThesaurusProvider const*>( rsrc.get() );
    ZORBA_ASSERT( t_provider );
    is_supported = t_provider->getThesaurus( lang );
  }
  catch ( XQueryException const &e ) {
    if ( e.diagnostic() != err::FTST0009 /* lang not supported by Zorba */ )
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

  lang = get_lang_from( getStaticContext() );

  consumeNext( item, theChildren[0], plan_state );
  item->getStringValue2( word );
  utf8::to_lower( word );

  if ( theChildren.size() > 1 ) {
    consumeNext( item, theChildren[1], plan_state );
    lang = get_lang_from( item, loc );
  }

  // TODO: why is this always the default StemmerProvider?
  provider = &internal::StemmerProvider::get_default();
  if ( stemmer = provider->get_stemmer( lang ) ) {
    stemmer->stem( word, lang, &stem );
    GENV_ITEMFACTORY->createString( result, stem );
    STACK_PUSH( true, state );
  } else {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP8404_STEM_LANG_NOT_SUPPORTED,
      ERROR_PARAMS( lang ),
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

bool ThesaurusLookupIterator::nextImpl( store::Item_t &result,
                                        PlanState &plan_state ) const {
  vector<zstring> comp_uris;
  zstring error_msg;
  store::Item_t item;
  iso639_1::type lang;
  auto_ptr<internal::Resource> rsrc;
  zstring uri = "##default";
  static_context const *sctx;
  zstring synonym;
  internal::ThesaurusProvider const *t_provider;

  ThesaurusLookupIteratorState *state;
  DEFAULT_STACK_INIT( ThesaurusLookupIteratorState, state, plan_state );

  sctx = getStaticContext();
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

  sctx->get_component_uris(
    uri, internal::EntityData::THESAURUS, comp_uris
  );
  if ( comp_uris.size() != 1 )
    throw XQUERY_EXCEPTION(
      err::FTST0018, ERROR_PARAMS( uri ), ERROR_LOC( loc )
    );

  rsrc = sctx->resolve_uri(
    comp_uris.front(), internal::EntityData::THESAURUS, error_msg
  );
  if ( !rsrc.get() )
    throw XQUERY_EXCEPTION(
      err::FTST0018, ERROR_PARAMS( uri ), ERROR_LOC( loc )
    );

  t_provider = dynamic_cast<internal::ThesaurusProvider const*>( rsrc.get() );
  ZORBA_ASSERT( t_provider );
  if ( !t_provider->getThesaurus( lang, &state->thesaurus_ ) )
    throw XQUERY_EXCEPTION(
      zerr::ZXQP8406_THESAURUS_LANG_NOT_SUPPORTED,
      ERROR_PARAMS( lang ),
      ERROR_LOC( loc )
    );

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

///////////////////////////////////////////////////////////////////////////////

bool TokenizeIterator::nextImpl( store::Item_t &result,
                                 PlanState &plan_state ) const {
  store::Item_t attr_name, attr_node;
  zstring base_uri;
  store::Item_t item;
  iso639_1::type lang;
  Tokenizer::Numbers no;
  store::NsBindings const ns_bindings;
  static_context const *sctx;
  TokenizerProvider const *tokenizer_provider;
  store::Item_t type_name;
  zstring value_string;

  sctx = getStaticContext();

  TokenizeIteratorState *state;
  DEFAULT_STACK_INIT( TokenizeIteratorState, state, plan_state );

  lang = get_lang_from( sctx );

  if ( consumeNext( state->doc_item_, theChildren[0], plan_state ) ) {
    if ( theChildren.size() > 1 ) {
      consumeNext( item, theChildren[1], plan_state );
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

      base_uri = static_context::ZORBA_FULL_TEXT_FN_NS;
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createElementNode(
        result, nullptr, state->token_qname_, type_name, false, false,
        ns_bindings, base_uri
      );

      if ( token->lang() ) {
        value_string = iso639_1::string_of[ token->lang() ];
        GENV_ITEMFACTORY->createQName( attr_name, "", "", "lang" );
        GENV_ITEMFACTORY->createString( item, value_string );
        type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
        GENV_ITEMFACTORY->createAttributeNode(
          attr_node, result, attr_name, type_name, item
        );
      }

      ztd::to_string( token->para(), &value_string );
      GENV_ITEMFACTORY->createQName( attr_name, "", "", "paragraph" );
      GENV_ITEMFACTORY->createString( item, value_string );
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createAttributeNode(
        attr_node, result, attr_name, type_name, item
      );

      ztd::to_string( token->sent(), &value_string );
      GENV_ITEMFACTORY->createQName( attr_name, "", "", "sentence" );
      GENV_ITEMFACTORY->createString( item, value_string );
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createAttributeNode(
        attr_node, result, attr_name, type_name, item
      );

      value_string = token->value();
      GENV_ITEMFACTORY->createQName( attr_name, "", "", "value" );
      GENV_ITEMFACTORY->createString( item, value_string );
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createAttributeNode(
        attr_node, result, attr_name, type_name, item
      );

      if ( store::Item const *const token_item = token->item() ) {
        if ( GENV_STORE.getNodeReference( item, token_item ) ) {
          item->getStringValue2( value_string );
          GENV_ITEMFACTORY->createQName( attr_name, "", "", "node-ref" );
          GENV_ITEMFACTORY->createString( item, value_string );
          type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
          GENV_ITEMFACTORY->createAttributeNode(
            attr_node, result, attr_name, type_name, item
          );
        }
      }

#ifndef ZORBA_NO_XMLSCHEMA
      sctx->validate( result, result, StaticContextConsts::strict_validation );
#endif /* ZORBA_NO_XMLSCHEMA */

      STACK_PUSH( true, state );
    } // while
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

///////////////////////////////////////////////////////////////////////////////

bool TokenizerPropertiesIterator::nextImpl( store::Item_t &result,
                                            PlanState &plan_state ) const {
  store::Item_t element, item, junk, name;
  zstring base_uri;
  iso639_1::type lang;
  Tokenizer::Numbers no;
  store::NsBindings const ns_bindings;
  static_context const *sctx;
  Tokenizer::ptr tokenizer;
  store::Item_t type_name;
  Tokenizer::Properties props;
  TokenizerProvider const *tokenizer_provider;
  zstring value_string;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  sctx = getStaticContext();
  lang = get_lang_from( getStaticContext() );

  if ( theChildren.size() > 0 ) {
    consumeNext( item, theChildren[0], plan_state );
    lang = get_lang_from( item, loc );
  }

  tokenizer_provider = GENV_STORE.getTokenizerProvider();
  tokenizer = tokenizer_provider->getTokenizer( lang, no );
  tokenizer->properties( &props );

  GENV_ITEMFACTORY->createQName(
    name, static_context::ZORBA_FULL_TEXT_FN_NS, "", "tokenizer-properties"
  );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    result, nullptr, name, type_name, false, false, ns_bindings, base_uri
  );

  // uri="..."
  GENV_ITEMFACTORY->createQName( name, "", "", "uri" );
  GENV_ITEMFACTORY->createAnyURI( item, props.uri );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  GENV_ITEMFACTORY->createAttributeNode( junk, result, name, type_name, item );

  // <comments-separate-tokens value="..."/>
  GENV_ITEMFACTORY->createQName(
    name, static_context::ZORBA_FULL_TEXT_FN_NS, "", "comments-separate-tokens"
  );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    element, result, name, type_name, false, false, ns_bindings, base_uri
  );
  GENV_ITEMFACTORY->createQName( name, "", "", "value" );
  GENV_ITEMFACTORY->createBoolean( item, props.comments_separate_tokens );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  GENV_ITEMFACTORY->createAttributeNode( junk, element, name, type_name, item );

  // <elements-separate-tokens value="..."/>
  GENV_ITEMFACTORY->createQName(
    name, static_context::ZORBA_FULL_TEXT_FN_NS, "", "elements-separate-tokens"
  );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    element, result, name, type_name, false, false, ns_bindings, base_uri
  );
  GENV_ITEMFACTORY->createQName( name, "", "", "value" );
  GENV_ITEMFACTORY->createBoolean( item, props.elements_separate_tokens );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  GENV_ITEMFACTORY->createAttributeNode( junk, element, name, type_name, item );

  // <processing-instructions-separate-tokens value="..."/>
  GENV_ITEMFACTORY->createQName(
    name, static_context::ZORBA_FULL_TEXT_FN_NS, "",
    "processing-instructions-separate-tokens"
  );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    element, result, name, type_name, false, false, ns_bindings, base_uri
  );
  GENV_ITEMFACTORY->createQName( name, "", "", "value" );
  GENV_ITEMFACTORY->createBoolean( item, props.processing_instructions_separate_tokens );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  GENV_ITEMFACTORY->createAttributeNode( junk, element, name, type_name, item );

  // <supported-languages>...</supported-languages>
  GENV_ITEMFACTORY->createQName(
    name, static_context::ZORBA_FULL_TEXT_FN_NS, "", "supported-languages"
  );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    element, result, name, type_name, false, false, ns_bindings, base_uri
  );

  // <lang>...</lang>
  FOR_EACH( Tokenizer::Properties::languages_type, i, props.languages ) {
    store::Item_t lang_element;
    type_name = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
    GENV_ITEMFACTORY->createQName(
      name, static_context::ZORBA_FULL_TEXT_FN_NS, "", "lang"
    );
    GENV_ITEMFACTORY->createElementNode(
      lang_element, element, name, type_name, false, false, ns_bindings,
      base_uri
    );
    value_string = iso639_1::string_of[ *i ];
    GENV_ITEMFACTORY->createTextNode( junk, lang_element.getp(), value_string );
  }

#ifndef ZORBA_NO_XMLSCHEMA
  sctx->validate( result, result, StaticContextConsts::strict_validation );
#endif /* ZORBA_NO_XMLSCHEMA */

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
       Item const *item ) {
  store::Item const *const store_item =
    item ? Unmarshaller::getInternalItem( *item ) : nullptr;

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

  lang = get_lang_from( getStaticContext() );

  if ( consumeNext( item, theChildren[0], plan_state ) ) {
    item->getStringValue2( value_string );
    if ( theChildren.size() > 1 ) {
      consumeNext( item, theChildren[1], plan_state );
      lang = get_lang_from( item, loc );
    }

    { // local scope
    TokenizerProvider const *const tokenizer_provider =
      GENV_STORE.getTokenizerProvider();
    Tokenizer::Numbers no;
    Tokenizer::ptr tokenizer = tokenizer_provider->getTokenizer( lang, no );
    TokenizeStringIteratorCallback callback;
    tokenizer->tokenize_string(
      value_string.data(), value_string.size(), lang, false, callback
    );
    state->string_tokens_.take( callback.tokens_ );
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
/* vim:set et sw=2 ts=2: */
