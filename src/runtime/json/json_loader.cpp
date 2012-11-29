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

#ifdef ZORBA_WITH_JSON

#include <string>

// Zorba
#include <store/api/item.h>
#include <store/api/store.h>
#include <zorba/store_consts.h>

#include "context/static_context.h"
#include "diagnostics/xquery_diagnostics.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"

// local
#include "json_loader.h"

using namespace std;

namespace zorba {
namespace json {

///////////////////////////////////////////////////////////////////////////////

loader::stack_element::stack_element( type t ) : type_( t ) {
  switch ( type_ ) {
    case array_type:
      array_ = new json_array_type;
      break;
    case object_type:
      object_ = new json_object_type;
      break;
    default:
      break;
  }
}

///////////////////////////////////////////////////////////////////////////////

loader::loader( istream &is, bool allow_multiple, bool strip_top_level_array ) :
  parser_( is, allow_multiple ),
  strip_top_level_array_( strip_top_level_array ),
  stripped_top_level_array_( false )
{
}

loader::~loader() {
  while ( !stack_.empty() ) {
    stack_element const top( stack_.top() );
    switch ( top.type_ ) {
      case stack_element::array_type:
        delete top.array_;
        break;
      case stack_element::object_type:
        delete top.object_;
        break;
      case stack_element::key_type:
        top.key_->removeReference();
        break;
      default:
        break;
    }
    stack_.pop();
  } // while
}

void loader::add_value( store::Item_t const &value ) {
  stack_element const top( stack_.top() );
  switch ( top.type_ ) {
    case stack_element::array_type:
      top.array_->push_back( value );
      break;
    case stack_element::object_type:
      //
      // value must be a string that's the name of the object's next key/value
      // pair.
      //
      push( stack_element::key_type ).key_ = value.getp();
      value->addReference();
      break;
    case stack_element::key_type: {
      //
      // Otherwise, the top of the stack must be a string which means that the
      // second-to-top must be an object awaiting a value associated with this
      // name.
      //
      stack_.pop();
      stack_element &top2 = stack_.top();
      assert( top2.type_ == stack_element::object_type );
      top2.object_->keys_.push_back( top.key_ );
      top2.object_->values_.push_back( value );
      top.key_->removeReference();
      break;
    }
    default:
      assert( false );
  }
}

bool loader::next( store::Item_t *result ) {
  store::Item_t item;
  zstring s;
  json::token t;

  try {
    while ( parser_.next( &t ) ) {
      switch( t.get_type() ) {
        case '[':
          if ( strip_top_level_array_ && !stripped_top_level_array_ )
            stripped_top_level_array_ = true;
          else
            push( stack_element::array_type );
          continue;
        case '{':
          push( stack_element::object_type );
          continue;
        case ']':
          if ( stack_.empty() && strip_top_level_array_ )
            continue;
        case '}': {
          stack_element const top( stack_.top() );
          stack_.pop();
          switch ( top.type_ ) {
            case stack_element::array_type:
              GENV_ITEMFACTORY->createJSONArray( item, *top.array_ );
              break;
            case stack_element::object_type:
              GENV_ITEMFACTORY->createJSONObject(
                item, top.object_->keys_, top.object_->values_
              );
              break;
            default:
              assert( false );
          } // switch
          break;
        }
        case ':':
        case ',':
          continue;
        case token::number:
          s = t.get_value();
          GENV_ITEMFACTORY->createJSONNumber( item, s );
          break;
        case token::string:
          s = t.get_value();
          GENV_ITEMFACTORY->createString( item, s );
          break;
        case 'F':
        case 'T':
          GENV_ITEMFACTORY->createBoolean( item, t.get_type() == 'T' );
          break;
        case token::json_null:
          GENV_ITEMFACTORY->createJSONNull( item );
          break;
        default:
          assert( false );
      } // switch

      if ( stack_.empty() ) {
        *result = item;
        return true;
      }
      add_value( item );
    } // while
    return false;
  } // try
  catch ( json::illegal_character const &e ) {
    char const c = e.get_char();
    std::string c_as_string;
    if ( ascii::is_print( c ) )
      c_as_string = c;
    else
      c_as_string = BUILD_STRING(
        "#x" << uppercase << hex << (static_cast<unsigned>( c ) & 0xFF)
      );
    throw XQUERY_EXCEPTION(
      jerr::JNDY0021,
      ERROR_PARAMS( c_as_string ),
      ERROR_LOC( e.get_loc() )
    );
  }
  catch ( json::illegal_codepoint const &e ) {
    throw XQUERY_EXCEPTION(
      jerr::JNDY0021,
      ERROR_PARAMS( e.what() ),
      ERROR_LOC( e.get_loc() )
    );
  }
  catch ( json::illegal_escape const &e ) {
    throw XQUERY_EXCEPTION(
      jerr::JNDY0021,
      ERROR_PARAMS( e.what() ),
      ERROR_LOC( e.get_loc() )
    );
  }
  catch ( json::illegal_literal const &e ) {
    throw XQUERY_EXCEPTION(
      jerr::JNDY0021,
      ERROR_PARAMS( e.what() ),
      ERROR_LOC( e.get_loc() )
    );
  }
  catch ( json::illegal_number const &e ) {
    throw XQUERY_EXCEPTION(
      jerr::JNDY0021,
      ERROR_PARAMS( e.what() ),
      ERROR_LOC( e.get_loc() )
    );
  }
  catch ( json::unexpected_token const &e ) {
    throw XQUERY_EXCEPTION(
      jerr::JNDY0021,
      ERROR_PARAMS( e.what() ),
      ERROR_LOC( e.get_loc() )
    );
  }
  catch ( json::unterminated_string const &e ) {
    throw XQUERY_EXCEPTION(
      jerr::JNDY0021,
      ERROR_PARAMS( e.what() ),
      ERROR_LOC( e.get_loc() )
    );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace json
} // namespace zorba

#endif /* ZORBA_WITH_JSON */
/* vim:set et sw=2 ts=2: */
