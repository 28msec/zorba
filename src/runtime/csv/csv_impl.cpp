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

#include <set>

#include <zorba/config.h>
#include <zorba/diagnostic_list.h>

#include "runtime/csv/csv.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "util/stl_util.h"

#include "csv_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static bool get_option( store::Item_t const &object, char const *opt_name,
                        store::Item_t *value ) {
  store::Item_t key_item;
  zstring zopt_name( opt_name );
  GENV_ITEMFACTORY->createString( key_item, zopt_name );
  *value = object->getObjectValue( key_item );
  return !value->isNull();
}

#if 0
static bool get_boolean_option( store::Item_t const &object,
                                char const *opt_name, bool *value,
                                QueryLoc const &loc ) {
  store::Item_t opt_value;
  if ( get_option( object, opt_name, &opt_value ) ) {
    if ( !opt_value->isAtomic() ||
         opt_value->getTypeCode() != store::XS_BOOLEAN )
      throw XQUERY_EXCEPTION(
        zerr::ZCSV0001_INVALID_OPTION,
        ERROR_PARAMS( zopt_value, opt_name, ZED( ZCSV0001_MustBeBoolean ) ),
        ERROR_LOC( loc )
      );
    *value = opt_value->getBooleanValue();
    return true;
  }
  return false;
}
#endif

static bool get_char_option( store::Item_t const &object,
                             char const *opt_name, char *value,
                             QueryLoc const &loc ) {
  store::Item_t opt_value;
  if ( get_option( object, opt_name, &opt_value ) ) {
    zstring const zopt_value( opt_value->getStringValue() );
    if ( zopt_value.size() != 1 || ascii::is_ascii( zopt_value[0] ) )
      throw XQUERY_EXCEPTION(
        zerr::ZCSV0001_INVALID_OPTION,
        ERROR_PARAMS( zopt_value, opt_name, ZED( ZCSV0001_MustBeASCIIChar ) ),
        ERROR_LOC( loc )
      );
    *value = zopt_value[0];
    return true;
  }
  return false;
}

bool CsvParseIterator::nextImpl( store::Item_t &result,
                                 PlanState &plan_state ) const {
  char char_opt;
  unsigned field_no = 0;
  store::Item_t item, opt_item;
  vector<store::Item_t> keys_copy, values;
  set<unsigned> keys_omit;
  zstring value;
  bool eol, quoted;

  CsvParseIteratorState *state;
  DEFAULT_STACK_INIT( CsvParseIteratorState, state, plan_state );

  // $csv as string
  consumeNext( item, theChildren[0], plan_state );
  if ( item->isStreamable() )
    state->csv_.set_stream( item->getStream() );
  else {
    item->getStringValue2( state->string_ );
    state->mem_streambuf_.set( state->string_.data(), state->string_.size() );
    state->iss_.ios::rdbuf( &state->mem_streambuf_ );
    state->csv_.set_stream( state->iss_ );
  }

  // $options as object()
  consumeNext( item, theChildren[1], plan_state );
  if ( get_char_option( item, "quote-char", &char_opt, loc ) ) {
    state->csv_.set_quote( char_opt );
    state->csv_.set_quote_esc( char_opt );
  }
  if ( get_char_option( item, "quote-esc", &char_opt, loc ) )
    state->csv_.set_quote_esc( char_opt );
  if ( get_char_option( item, "separator", &char_opt, loc ) )
    state->csv_.set_separator( char_opt );
  if ( get_option( item, "field-names", &opt_item ) ) {
    store::Iterator_t i( opt_item->getArrayValues() );
    i->open();
    store::Item_t name_item;
    while ( i->next( name_item ) )
      state->keys_.push_back( name_item );
    i->close();
  }
  if ( get_option( item, "missing-value", &opt_item ) ) {
    opt_item->getStringValue2( value );
    if ( value == "error" )
      state->missing_ = missing::error;
    else if ( value == "omit" )
      state->missing_ = missing::omit;
    else if ( value == "null" )
      state->missing_ = missing::null;
    else
      ZORBA_ASSERT( false );
  } else
    state->missing_ = missing::null;

  state->cast_ = false;
  state->line_no_ = 1;

  while ( state->csv_.next_value( &value, &eol, &quoted ) ) {
    if ( value.empty() ) {
      if ( state->keys_.empty() )
        throw XQUERY_EXCEPTION(
          zerr::ZCSV0002_MISSING_VALUE,
          ERROR_PARAMS( ZED( ZCSV0002_EmptyHeaderValue ) ),
          ERROR_LOC( loc )
        );
      switch ( state->missing_ ) {
        case missing::error:
          goto missing_error;
        case missing::null:
          GENV_ITEMFACTORY->createJSONNull( item );
          break;
        case missing::omit:
          keys_omit.insert( field_no );
          break;
      }
    } else if ( !quoted && state->cast_ ) {
      // TODO
    } else {
      GENV_ITEMFACTORY->createString( item, value );
    }

    values.push_back( item );

    if ( eol ) {
      if ( state->keys_.empty() )
        state->keys_.swap( values );
      else {
        if ( values.size() < state->keys_.size() ) {
          switch ( state->missing_ ) {
            case missing::error:
              field_no = state->keys_.size() - 1;
              goto missing_error;
            case missing::null:
              GENV_ITEMFACTORY->createJSONNull( item );
              while ( values.size() < state->keys_.size() )
                values.push_back( item );
              break;
            case missing::omit:
              for ( unsigned i = 0; i < state->keys_.size(); ++i )
                if ( !ztd::contains( keys_omit, i ) )
                  keys_copy.push_back( state->keys_[ i ] );
              break;
          }
        } else if ( values.size() > state->keys_.size() ) {
          // TODO
        }
        GENV_ITEMFACTORY->createJSONObject( result, state->keys_, values );
        STACK_PUSH( true, state );
      }
      ++state->line_no_, field_no = 0;
      continue;
    }
    ++field_no;
  } // while

  STACK_END( state );

missing_error:
  throw XQUERY_EXCEPTION(
    zerr::ZCSV0002_MISSING_VALUE,
    ERROR_PARAMS(
      ZED( ZCSV0002_MissingValue ),
      state->keys_[ field_no ]->getStringValue(),
      state->line_no_
    ),
    ERROR_LOC( loc )
  );
}

///////////////////////////////////////////////////////////////////////////////

bool CsvSerializeIterator::nextImpl( store::Item_t &result,
                                     PlanState &plan_state ) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  // TODO

  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
