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

#include <algorithm>
#include <iterator>
#include <set>
#include <sstream>

#include <zorba/config.h>
#include <zorba/internal/cxx_util.h>
#include <zorba/diagnostic_list.h>
#include <zorba/store_consts.h>

#include "runtime/csv/csv.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/casting.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "util/ascii_util.h"
#include "util/json_parser.h"
#include "util/stl_util.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/float.h"
#include "zorbatypes/integer.h"

#include "csv_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

#define IS_ATOMIC_TYPE(ITEM,TYPE) \
  ( (ITEM)->isAtomic() && TypeOps::is_subtype( (ITEM)->getTypeCode(), store::TYPE ) )

#define IS_JSON_NULL(ITEM) \
  ( (ITEM)->isAtomic() && (ITEM)->getTypeCode() == store::JS_NULL )

static bool get_opt( store::Item_t const &object, char const *opt_name,
                     store::Item_t *result ) {
  store::Item_t key_item;
  zstring s( opt_name );
  GENV_ITEMFACTORY->createString( key_item, s );
  *result = object->getObjectValue( key_item );
  return !result->isNull();
}

static bool get_bool_opt( store::Item_t const &object,
                          char const *opt_name, bool *result,
                          QueryLoc const &loc ) {
  store::Item_t opt_item;
  if ( get_opt( object, opt_name, &opt_item ) ) {
    if ( !IS_ATOMIC_TYPE( opt_item, XS_BOOLEAN ) )
      throw XQUERY_EXCEPTION(
        csv::INVALID_OPTION,
        ERROR_PARAMS(
          opt_item->getStringValue(),
          opt_name,
          ZED( INVALID_OPTION_MustBeBoolean )
        ),
        ERROR_LOC( loc )
      );
    *result = opt_item->getBooleanValue();
    return true;
  }
  return false;
}

static bool get_char_opt( store::Item_t const &object,
                          char const *opt_name, char *result,
                          QueryLoc const &loc ) {
  store::Item_t opt_item;
  if ( get_opt( object, opt_name, &opt_item ) ) {
    zstring const value( opt_item->getStringValue() );
    if ( !IS_ATOMIC_TYPE( opt_item, XS_STRING ) ||
         value.size() != 1 || !ascii::is_ascii( value[0] ) ) {
      throw XQUERY_EXCEPTION(
        csv::INVALID_OPTION,
        ERROR_PARAMS( value, opt_name, ZED( INVALID_OPTION_MustBeASCIIChar ) ),
        ERROR_LOC( loc )
      );
    }
    *result = value[0];
    return true;
  }
  return false;
}

static bool get_string_opt( store::Item_t const &object,
                            char const *opt_name, zstring *result,
                            QueryLoc const &loc ) {
  store::Item_t opt_item;
  if ( get_opt( object, opt_name, &opt_item ) ) {
    if ( !IS_ATOMIC_TYPE( opt_item, XS_STRING ) )
      throw XQUERY_EXCEPTION(
        csv::INVALID_OPTION,
        ERROR_PARAMS(
          opt_item->getStringValue(),
          opt_name,
          ZED( INVALID_OPTION_MustBeString )
        ),
        ERROR_LOC( loc )
      );
    opt_item->getStringValue2( *result );
    return true;
  }
  return false;
}

static json::type parse_json( zstring const &s, json::token *ptoken ) {
  mem_streambuf buf( (char*)s.data(), s.size() );
  istringstream iss;
  iss.ios::rdbuf( &buf );
  json::lexer lex( iss );
  return lex.next( ptoken, false ) ?
    json::map_type( ptoken->get_type() ) : json::none;
}

///////////////////////////////////////////////////////////////////////////////

void CsvParseIterator::set_input( store::Item_t const &item,
                                  CsvParseIteratorState *state ) const {
  if ( item->isStreamable() )
    state->csv_.set_stream( item->getStream() );
  else {
    item->getStringValue2( state->string_ );
    state->mem_streambuf_.set( state->string_.data(), state->string_.size() );
    state->iss_.ios::rdbuf( &state->mem_streambuf_ );
    state->csv_.set_stream( state->iss_ );
  }
}

void CsvParseIterator::set_options( store::Item_t const &item,
                                    CsvParseIteratorState *state ) const {
  store::Item_t opt_item;
  char opt_char;
  zstring value;

  get_bool_opt( item, "cast-unquoted-values", &state->cast_unquoted_, loc );
  get_string_opt( item, "extra-name", &state->extra_name_, loc );
  if ( get_opt( item, "field-names", &opt_item ) ) {
    store::Iterator_t i( opt_item->getArrayValues() );
    i->open();
    store::Item_t name_item;
    while ( i->next( name_item ) )
      state->keys_.push_back( name_item );
    i->close();
  }
  if ( get_string_opt( item, "missing-value", &value, loc ) ) {
    if ( value == "error" )
      state->missing_ = missing::error;
    else if ( value == "omit" )
      state->missing_ = missing::omit;
    else if ( value == "null" )
      state->missing_ = missing::null;
    else
      ZORBA_ASSERT( false );            // should be caught by JSON schema
  }
  if ( get_char_opt( item, "quote-char", &opt_char, loc ) ) {
    state->csv_.set_quote( opt_char );
    state->csv_.set_quote_esc( opt_char );
  }
  if ( get_char_opt( item, "quote-escape", &opt_char, loc ) )
    state->csv_.set_quote_esc( opt_char );
  if ( get_char_opt( item, "separator", &opt_char, loc ) )
    state->csv_.set_separator( opt_char );
}

bool CsvParseIterator::count( store::Item_t &result,
                              PlanState &plan_state ) const {
  unsigned long count = 0;
  bool eol;
  store::Item_t item;
  zstring value;

  CsvParseIteratorState *state;
  DEFAULT_STACK_INIT( CsvParseIteratorState, state, plan_state );

  // $csv as string
  consumeNext( item, theChildren[0], plan_state );
  set_input( item, state );

  // $options as object()
  consumeNext( item, theChildren[1], plan_state );
  set_options( item, state );

  while ( state->csv_.next_value( &value, &eol ) )
    if ( eol )
      ++count;

  if ( state->keys_.empty() && count ) {
    //
    // If keys_ is empty, it means that the "field-names" option wasn't
    // specified; hence, the first line of the file is assumed to be a header
    // line.  A header line shouldn't count as a real record to be skipped, so
    // decrement the count by 1 to compensate.
    //
    --count;
  }

  STACK_PUSH(
    GENV_ITEMFACTORY->createInteger( result, xs_integer( count ) ),
    state
  );
  STACK_END( state );
}

bool CsvParseIterator::skip( int64_t count, PlanState &plan_state ) const {
  bool eol;
  store::Item_t item;
  vector<store::Item_t> keys;
  zstring value;

  CsvParseIteratorState *const state = StateTraitsImpl<CsvParseIteratorState>::
    getState( plan_state, theStateOffset );

  // $csv as string
  consumeNext( item, theChildren[0], plan_state );
  set_input( item, state );

  // $options as object()
  consumeNext( item, theChildren[1], plan_state );
  set_options( item, state );

  if ( state->keys_.empty() ) {
    //
    // If keys_ is empty, it means that the "field-names" option wasn't
    // specified; hence, the first line of the file is assumed to be a header
    // line.  A header line shouldn't count as a real record to be skipped, so
    // bump up the count by 1 to compensate.
    //
    ++count;
  }

  //
  // Since we called consumeNext() here and consumed the arguments, we have to
  // use the already-consumed arguments (stored in the iterator's state) in
  // nextImpl() and not call consumeNext() there.  Set a flag to indicate this.
  //
  state->skip_called_ = true;

  while ( count-- > 0 ) {
    while ( true ) {
      if ( !state->csv_.next_value( &value, &eol ) )
        return false;
      if ( state->keys_.empty() ) {
        if ( value.empty() ) {
          //
          // Header field names can never be empty.
          //
          throw XQUERY_EXCEPTION(
            csv::MISSING_VALUE,
            ERROR_PARAMS( ZED( MISSING_VALUE_EmptyHeader ) ),
            ERROR_LOC( loc )
          );
        }
        GENV_ITEMFACTORY->createString( item, value );
        keys.push_back( item );
      }
      if ( eol ) {
        if ( state->keys_.empty() ) {
          //
          // The first line of values are taken to be the header field names.
          //
          state->keys_.swap( keys );
        }
        break;
      }
    } // while ( true )
  } // while ( count-- > 0 )
  return true;
}

bool CsvParseIterator::nextImpl( store::Item_t &result,
                                 PlanState &plan_state ) const {
  unsigned field_no = 0;
  store::Item_t item;
  vector<store::Item_t> keys_copy, values;
  set<unsigned> keys_omit;
  zstring value;
  bool eol, quoted, swap_keys = false;

  CsvParseIteratorState *state;
  DEFAULT_STACK_INIT( CsvParseIteratorState, state, plan_state );

  if ( !state->skip_called_ ) {
    // $csv as string
    consumeNext( item, theChildren[0], plan_state );
    set_input( item, state );

    // $options as object()
    consumeNext( item, theChildren[1], plan_state );
    set_options( item, state );
  }

  while ( state->csv_.next_value( &value, &eol, &quoted ) ) {
    if ( state->keys_.size() && values.size() == state->keys_.size() &&
         state->extra_name_.empty() ) {
      //
      // We've already max'd out on the number of values for a record and the
      // "extra-name" option wasn't specified.
      //
      throw XQUERY_EXCEPTION(
        csv::EXTRA_VALUE,
        ERROR_PARAMS( value, state->line_no_ ),
        ERROR_LOC( loc )
      );
    }

    item = nullptr;
    if ( value.empty() ) {
      if ( state->keys_.empty() ) {
        //
        // Header field names can never be empty.
        //
        throw XQUERY_EXCEPTION(
          csv::MISSING_VALUE,
          ERROR_PARAMS( ZED( MISSING_VALUE_EmptyHeader ) ),
          ERROR_LOC( loc )
        );
      }
      if ( quoted )
        GENV_ITEMFACTORY->createString( item, value );
      else
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
    } else if ( state->cast_unquoted_ && !quoted && !state->keys_.empty() ) {
      if ( value == "T" || value == "Y" )
        GENV_ITEMFACTORY->createBoolean( item, true );
      else if ( value == "F" || value == "N" )
        GENV_ITEMFACTORY->createBoolean( item, false );
      else {
        json::token t;
        switch ( parse_json( value, &t ) ) {
          case json::boolean:
            GENV_ITEMFACTORY->createBoolean( item, value[0] == 't' );
            break;
          case json::null:
            GENV_ITEMFACTORY->createJSONNull( item );
            break;
          case json::number:
            switch ( t.get_numeric_type() ) {
              case json::token::integer:
                GENV_ITEMFACTORY->createInteger( item, xs_integer( value ) );
                break;
              case json::token::decimal:
                GENV_ITEMFACTORY->createDecimal( item, xs_decimal( value ) );
                break;
              case json::token::floating_point:
                GENV_ITEMFACTORY->createDouble( item, xs_double( value ) );
                break;
              default:
                ZORBA_ASSERT( false );
            }
            break;
          default:
            GENV_ITEMFACTORY->createString( item, value );
        } // switch
      } // else
    } else {
      GENV_ITEMFACTORY->createString( item, value );
    }

    if ( !item.isNull() )
      values.push_back( item );

    if ( eol ) {
      if ( state->keys_.empty() ) {
        //
        // The first line of values are taken to be the header field names.
        //
        state->keys_.swap( values );
      } else {
        if ( values.size() < state->keys_.size() ) {
          //
          // At least one value is missing.
          //
          switch ( state->missing_ ) {
            case missing::error:
              //
              // We don't actually know which field is missing; we know only
              // that there's at least one less field than there should be.
              //
              field_no = values.size();
              goto missing_error;
            case missing::null:
              GENV_ITEMFACTORY->createJSONNull( item );
              while ( values.size() < state->keys_.size() )
                values.push_back( item );
              break;
            case missing::omit:
              //
              // We have to remove the keys for those fields that should be
              // omitted temporarily.
              //
              if ( keys_omit.empty() ) {
                //
                // The last field is the one that's missing and there's no
                // trailing ',' (which is why keys_omit is empty).
                //
                keys_copy = state->keys_;
                state->keys_.pop_back();
              } else {
                for ( unsigned i = 0; i < state->keys_.size(); ++i )
                  if ( !ztd::contains( keys_omit, i ) )
                    keys_copy.push_back( state->keys_[i] );
                keys_copy.swap( state->keys_ );
              }
              swap_keys = true;
              break;
          }
        } else if ( values.size() > state->keys_.size() ) {
          //
          // There's at least one extra value: add in extra fields for keys
          // temporarily.
          //
          keys_copy = state->keys_;
          zstring::size_type const num_pos = state->extra_name_.find( '#' );
          for ( unsigned f = state->keys_.size() +1; f <= values.size(); ++f ) {
            ascii::itoa_buf_type buf;
            ascii::itoa( f, buf );
            zstring extra_name( state->extra_name_ );
            if ( num_pos != zstring::npos )
              extra_name.replace( num_pos, 1, buf );
            else
              extra_name += buf;
            GENV_ITEMFACTORY->createString( item, extra_name );
            state->keys_.push_back( item );
          }
          swap_keys = true;
        }

        GENV_ITEMFACTORY->createJSONObject( result, state->keys_, values );
        if ( swap_keys ) {
          //
          // Put the original set of field names (keys) back the way it was.
          //
          keys_copy.swap( state->keys_ );
        }
        STACK_PUSH( true, state );
      } // else
      ++state->line_no_, field_no = 0;
      continue;
    } // if ( eol )
    ++field_no;
  } // while

  STACK_END( state );

missing_error:
  throw XQUERY_EXCEPTION(
    csv::MISSING_VALUE,
    ERROR_PARAMS(
      ZED( MISSING_VALUE_Default ),
      state->keys_[ field_no ]->getStringValue(),
      state->line_no_
    ),
    ERROR_LOC( loc )
  );
}

///////////////////////////////////////////////////////////////////////////////

bool CsvSerializeIterator::nextImpl( store::Item_t &result,
                                     PlanState &plan_state ) const {
  char char_opt;
  bool do_header, separator;
  store::Item_t item, opt_item;
  zstring line, value;

  CsvSerializeIteratorState *state;
  DEFAULT_STACK_INIT( CsvSerializeIteratorState, state, plan_state );

  // $options as object()
  consumeNext( item, theChildren[1], plan_state );
  if ( get_opt( item, "field-names", &opt_item ) ) {
    store::Iterator_t i( opt_item->getArrayValues() );
    i->open();
    store::Item_t name_item;
    while ( i->next( name_item ) )
      state->keys_.push_back( name_item );
    i->close();
  }
  if ( !get_char_opt( item, "quote-char", &state->quote_, loc ) )
    state->quote_ = '"';
  if ( get_char_opt( item, "quote-escape", &char_opt, loc ) ) {
    state->quote_esc_ = char_opt;
    state->quote_esc_ += state->quote_;
  } else
    state->quote_esc_.assign( 2, state->quote_ );
  if ( !get_bool_opt( item, "serialize-header", &do_header, loc ) )
    do_header = true;
  if ( !get_char_opt( item, "separator", &state->separator_, loc ) )
    state->separator_ = ',';
  if ( !get_string_opt( item, "serialize-null-as", &state->null_string_, loc ) )
    state->null_string_ = "null";
  if ( get_opt( item, "serialize-boolean-as", &opt_item ) ) {
    if ( !get_string_opt( opt_item, "false", &state->boolean_string_[0], loc )
      || !get_string_opt( opt_item, "true", &state->boolean_string_[1], loc ) )
      throw XQUERY_EXCEPTION(
        csv::INVALID_OPTION,
        ERROR_PARAMS(
          "", "serialize-boolea-as",
          ZED( INVALID_OPTION_MustBeTrueFalse )
        ),
        ERROR_LOC( loc )
      );
  } else
    state->boolean_string_[0] = "false", state->boolean_string_[1] = "true";

  state->must_quote_ = state->separator_;
  state->must_quote_ += state->quote_;
  state->must_quote_ += "\r\n";

  if ( state->keys_.empty() ) {
    //
    // We have to take the header field names from the first item, but we have
    // to save the first item to return its values later.
    //
    if ( consumeNext( state->header_item_, theChildren[0], plan_state ) ) {
      store::Iterator_t i( state->header_item_->getObjectKeys() );
      i->open();
      while ( i->next( item ) )
        state->keys_.push_back( item );
      i->close();
    }
  }

  if ( do_header ) {
    separator = false;
    FOR_EACH( vector<store::Item_t>, key, state->keys_ ) {
      if ( separator )
        line += state->separator_;
      else
        separator = true;
      line += (*key)->getStringValue();
    }
    line += "\r\n";
    GENV_ITEMFACTORY->createString( result, line );
    STACK_PUSH( true, state );
  }

  if ( !state->header_item_.isNull() ) {
    //
    // We consumed the first item above to get the field names for the header
    // since they weren't given.  However, we must still return the first
    // item's values as the first "real" result, so set "item" to
    // "header_item_" and jump into the while loop below but skipping the call
    // to consumeNext().
    //
    item = state->header_item_;
    goto skip_consumeNext;
  }

  while ( consumeNext( item, theChildren[0], plan_state ) ) {
skip_consumeNext:
    line.clear();
    separator = false;
    FOR_EACH( vector<store::Item_t>, key, state->keys_ ) {
      if ( separator )
        line += state->separator_;
      else
        separator = true;
      store::Item_t const value_item( item->getObjectValue( *key ) );
      if ( !value_item.isNull() ) {
        if ( IS_ATOMIC_TYPE( value_item, XS_BOOLEAN ) )
          line += state->boolean_string_[ value_item->getBooleanValue() ];
        else if ( IS_JSON_NULL( value_item ) )
          line += state->null_string_;
        else {
          value_item->getStringValue2( value );
          bool const quote =
            value.find_first_of( state->must_quote_ ) != zstring::npos;
          if ( quote )
            line += state->quote_;
          ascii::replace_all( value, state->quote_, state->quote_esc_ );
          line += value;
          if ( quote )
            line += state->quote_;
        }
      }
    } // for
    line += "\r\n";
    GENV_ITEMFACTORY->createString( result, line );
    STACK_PUSH( true, state );
  } // while

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
