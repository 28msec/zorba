/*
 * Copyright 2006-2011 The FLWOR Foundation.
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

#include <map>
#include <sstream>

#include <zorba/diagnostic_list.h>

#include "runtime/json/json.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "util/mem_streambuf.h"

#include "jsonml_array.h"
#include "snelson.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

typedef map<zstring,zstring> options_type;

static void get_options( store::Item_t const &options_element,
                         options_type *options ) {
  ZORBA_ASSERT( options_element->getNodeKind() ==
    store::StoreConsts::elementNode );
  store::Iterator_t i = options_element->getChildren();
  i->open();
  store::Item_t option_item;
  while ( i->next( option_item ) ) {
    if ( option_item->getNodeKind() == store::StoreConsts::elementNode ) {
      zstring const name( option_item->getNodeName()->getStringValue() );
      zstring value;
      get_attribute_value( option_item, "value", &value );
      (*options)[ name ] = value;
    }
  }
  i->close();
}

///////////////////////////////////////////////////////////////////////////////

bool JSONParseInternal::nextImpl( store::Item_t& result,
                                  PlanState &planState ) const {
  store::Item_t cur_item;
  options_type options;
  istringstream iss;
  mem_streambuf buf;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  ZORBA_ASSERT( theChildren.size() == 2 );
  ZORBA_ASSERT( consumeNext( cur_item, theChildren[1], planState ) );
  get_options( cur_item, &options );

  if ( consumeNext( cur_item, theChildren[0], planState ) ) {
    istream *is;
    if ( cur_item->isStreamable() ) {
      is = &cur_item->getStream();
    } else {
      zstring s;
      cur_item->getStringValue2( s );
      // Doing it this way uses the string data in-place with no copy.
      buf.set( s.data(), s.size() );
      iss.ios::rdbuf( &buf );
      is = &iss;
    }

    try {
      json::parser p( *is );
      p.set_loc(
        loc.getFilename().c_str(), loc.getLineBegin(), loc.getColumnBegin()
      );

      options_type::mapped_type const &format = options[ "json-format" ];
      ZORBA_ASSERT( !format.empty() );
      if ( format == "Snelson" )
        snelson::parse( p, &result );
      else if ( format == "JsonML-array" )
        jsonml_array::parse( p, &result );
      else
        ZORBA_ASSERT( false );
    }
    catch ( json::illegal_character const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0001_ILLEGAL_CHARACTER,
        ERROR_PARAMS( e.get_char() ),
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::illegal_codepoint const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0002_ILLEGAL_CODEPOINT,
        ERROR_PARAMS( e.get_codepoint() ),
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::illegal_escape const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0003_ILLEGAL_ESCAPE,
        ERROR_PARAMS( e.get_escape() ),
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::illegal_literal const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0004_ILLEGAL_LITERAL,
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::illegal_number const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0005_ILLEGAL_NUMBER,
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::unexpected_token const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0006_UNEXPECTED_TOKEN,
        ERROR_PARAMS( e.get_token() ),
        ERROR_LOC( e.get_loc() )
      );
    }
    catch ( json::unterminated_string const &e ) {
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0007_UNTERMINATED_STRING,
        ERROR_LOC( e.get_loc() )
      );
    }

    STACK_PUSH( !!result, state );
  } // if ( consumeNext( ...
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool JSONSerializeInternal::nextImpl( store::Item_t& result,
                                      PlanState &planState ) const {
  store::Item_t cur_item;
  options_type options;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  ZORBA_ASSERT( theChildren.size() == 2 );
  ZORBA_ASSERT( consumeNext( cur_item, theChildren[1], planState ) );
  get_options( cur_item, &options );

  if ( consumeNext( cur_item, theChildren[0], planState ) ) {
    try {
      options_type::mapped_type const &format_opt = options[ "json-format" ];
      ZORBA_ASSERT( !format_opt.empty() );

      whitespace::type ws;
      options_type::mapped_type const &whitespace_opt = options[ "whitespace" ];
      if ( whitespace_opt.empty() || whitespace_opt == "none" )
        ws = whitespace::none;
      else if ( whitespace_opt == "some" )
        ws = whitespace::some;
      else if ( whitespace_opt == "indent" )
        ws = whitespace::indent;
      else
        ZORBA_ASSERT( false );

      ostringstream oss;
      switch ( cur_item->getNodeKind() ) {
        case store::StoreConsts::documentNode:
        case store::StoreConsts::elementNode:
          if ( format_opt == "Snelson" )
            snelson::serialize( oss, cur_item, ws );
          else if ( format_opt == "JsonML-array" )
            jsonml_array::serialize( oss, cur_item, ws );
          else
            ZORBA_ASSERT( false );
          break;
        default:
          throw XQUERY_EXCEPTION(
            zerr::ZJSE0001_NOT_DOCUMENT_OR_ELEMENT_NODE,
            ERROR_LOC( loc )
          );
      }
      // This string copying is inefficient, but I can't see another way.
      zstring temp( oss.str() );
      GENV_ITEMFACTORY->createString( result, temp );
    }
    catch ( ZorbaException &e ) {
      set_source( e, loc );
      throw;
    }
  } // if ( consumeNext( ...
  STACK_PUSH( !!result, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
