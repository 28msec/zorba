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

#include <sstream>

#include <zorba/diagnostic_list.h>

#include "runtime/json/json.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "util/mem_streambuf.h"

#include "snelson.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool JSONParseInternal::nextImpl( store::Item_t& result,
                                  PlanState &planState ) const {
  store::Item_t cur_item;
  istringstream iss;
  mem_streambuf buf;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

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
      snelson::parse( p, &result );
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

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( consumeNext( cur_item, theChildren[0], planState ) ) {
    try {
      ostringstream oss;
      switch ( cur_item->getNodeKind() ) {
        case store::StoreConsts::documentNode:
        case store::StoreConsts::elementNode:
          snelson::serialize( oss, cur_item );
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
