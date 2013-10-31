/*
 * Copyright 2006-2013 The FLWOR Foundation.
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
#include <zorba/internal/cxx_util.h>
#include <zorba/diagnostic_list.h>
#include <zorba/store_consts.h>

#include "diagnostics/assert.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "system/globalenv.h"
#include "types/casting.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "util/json_parser.h"
#include "util/stl_util.h"
#include "zorbatypes/integer.h"

#include "jsound_util.h"

using namespace std;

namespace zorba {
namespace jsound {

///////////////////////////////////////////////////////////////////////////////

#define IS_ATOMIC_TYPE(ITEM,TYPE) \
  ( (ITEM)->isAtomic() && TypeOps::is_subtype( (ITEM)->getTypeCode(), store::TYPE ) )

#define IS_KIND(ITEM,KIND) \
  ( (ITEM)->getKind() == store::Item::KIND )

static void assert_kind( store::Item_t const &item, char const *key,
                         store::Item::ItemKind kind ) {
  if ( item->getKind() != kind )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_TYPE,
      ERROR_PARAMS( item->getStringValue(), key, kind )
    );
}

static void assert_type( store::Item_t const &item, char const *key,
                         store::SchemaTypeCode type ) {
  if ( !(item->isAtomic() && TypeOps::is_subtype( item->getTypeCode(), type )) )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_TYPE,
      ERROR_PARAMS( item->getStringValue(), key, type )
    );
}

#define JSOUND_ASSERT_KIND(ITEM,KEY,KIND) \
  assert_kind( ITEM, KEY, store::Item::KIND )

#define JSOUND_ASSERT_TYPE(ITEM,KEY,TYPE) \
  assert_type( ITEM, KEY, store::TYPE )

static store::Item_t get_value( store::Item_t const &jsd, char const *key ) {
  zstring s( key );
  store::Item_t key_item, value_item;
  GENV_ITEMFACTORY->createString( key_item, s );
  return jsd->getObjectValue( key_item );
}

static store::Item_t require_value( store::Item_t const &jsd,
                                    char const *key ) {
  store::Item_t value_item( get_value( jsd, key ) );
  if ( !value_item )
    throw ZORBA_EXCEPTION( jsd::MISSING_KEY, ERROR_PARAMS( key ) );
  return value_item;
}

///////////////////////////////////////////////////////////////////////////////

type::~type() {
  // out-of-line since it's virtual
}

array_type::array_type() {
}

array_type::~array_type() {
  ztd::delete_ptr_seq( content_ );
}

atomic_type::atomic_type() {
  explicitTimezone_ = timezone::optional;  // TODO: correct?
  length_ = -1;
  totalDigits_ = fractionDigits_ = -1;
}

min_max_type::min_max_type() {
  maxLength_ = minLength_ = -1;
}

object_type::~object_type() {
  MUTATE_EACH( content_type, i, content_ )
    delete i->second;
}

validator::validator( store::Item_t const &jsd_item ) {
  store::Item_t value_item;

  value_item = get_value( jsd_item, "$imports" );
  if ( !!value_item )
    load_imports( value_item );

  value_item = require_value( jsd_item, "$namespace" );
  load_namespace( value_item );

  value_item = require_value( jsd_item, "$types" );
  load_types( value_item );
}

validator::~validator() {
  MUTATE_EACH( typename_map, i, types_ )
    delete i->second;
}

void validator::load_about( store::Item_t const &about_item ) {
  JSOUND_ASSERT_TYPE( about_item, "$about", XS_STRING );
  about_ = about_item->getStringValue();
}

void validator::load_baseType( store::Item_t const &baseType_item ) {
  // TODO
}

void validator::load_constraints( store::Item_t const &constraints_item ) {
  // TODO
}

void validator::load_content_array( store::Item_t const &content_item ) {
  JSOUND_ASSERT_KIND( content_item, "$content", ARRAY );
  if ( content_item->getArraySize() != numeric_consts<xs_integer>::one() )
    throw ZORBA_EXCEPTION( jsd::ILLEGAL_ARRAY_SIZE );
  store::Item_t const type(
    content_item->getArrayValue( numeric_consts<xs_integer>::one() )
  );
  if ( IS_ATOMIC_TYPE( type, XS_STRING ) ) {
    // TODO: do something with type
  } else if ( IS_KIND( type, OBJECT ) ) {
    // TODO
  } else
    throw ZORBA_EXCEPTION( jsd::ILLEGAL_ARRAY_TYPE );
}

void validator::load_content_object( store::Item_t const &content_item ) {
  JSOUND_ASSERT_KIND( content_item, "$content", OBJECT );

  store::Iterator_t it( content_item->getObjectKeys() );
  store::Item_t key;
  it->open();
  while ( it->next( key ) ) {
    store::Item_t const value_item( content_item->getObjectValue( key ) );
    load_field_descriptor( value_item );
  }
  it->close();
}

void validator::load_enumeration( store::Item_t const &enumeration_item ) {
  JSOUND_ASSERT_KIND( enumeration_item, "$enumeration", ARRAY );
}

void validator::load_explicitTimezone( store::Item_t const &eTz_item,
                                       atomic_type *t ) {
  JSOUND_ASSERT_TYPE( eTz_item, "$explicitTimezone", XS_STRING );
  zstring const eTz_str( eTz_item->getStringValue() );
  if ( eTz_str == "optional" )
    t->explicitTimezone_ = timezone::optional;
  else if ( eTz_str == "prohibited" )
    t->explicitTimezone_ = timezone::prohibited;
  else if ( eTz_str == "required" )
    t->explicitTimezone_ = timezone::required;
  else
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_EXPLICIT_TIMEZONE,
      ERROR_PARAMS( eTz_str )
    );
}

void validator::load_field_descriptor( store::Item_t const &field_item ) {
  store::Item_t const type( require_value( field_item, "$type" ) );
  store::Item_t const optional( get_value( field_item, "$type" ) );
  store::Item_t const default_value( get_value( field_item, "$default" ) );
}

void validator::load_fractionDigits( store::Item_t const &fractionDigits_item,
                                     atomic_type *t ) {
  JSOUND_ASSERT_TYPE( fractionDigits_item, "$fracionDigits", XS_INTEGER );
  t->fractionDigits_ = fractionDigits_item->getIntValue();
  // TODO: assert >= 0
}

void validator::load_imports( store::Item_t const &imports_item ) {
  JSOUND_ASSERT_KIND( imports_item, "$imports", ARRAY );
  store::Iterator_t it( imports_item->getArrayValues() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    // TODO
  }
  it->close();
}

unique_ptr<type> validator::load_kind( store::Item_t const &kind_item ) {
  JSOUND_ASSERT_TYPE( kind_item, "$kind", XS_STRING );
  zstring const kind_str( kind_item->getStringValue() );
  if ( kind_str == "atomic" )
    return unique_ptr<type>( new atomic_type );
  if ( kind_str == "array" )
    return unique_ptr<type>( new array_type );
  if ( kind_str == "object" )
    return unique_ptr<type>( new object_type );
  if ( kind_str == "union" )
    return unique_ptr<type>( new union_type );
  throw ZORBA_EXCEPTION(
    jsd::ILLEGAL_VALUE, ERROR_PARAMS( kind_str, "$kind" )
  );
}

void validator::load_length( store::Item_t const &length_item,
                             atomic_type *t ) {
  JSOUND_ASSERT_TYPE( length_item, "$length", XS_INTEGER );
  t->length_ = length_item->getIntValue();
  // TODO: assert >= 0
}

void validator::load_maxExclusive( store::Item_t const &maxExclusive_item,
                                   atomic_type *t ) {
  JSOUND_ASSERT_TYPE( maxExclusive_item, "$maxExclusive", XS_INTEGER );
  // TODO
}

void validator::load_maxInclusive( store::Item_t const &maxInclusive_item,
                                   atomic_type *t ) {
  JSOUND_ASSERT_TYPE( maxInclusive_item, "$maxInclusive", XS_INTEGER );
  // TODO
}

void validator::load_maxLength( store::Item_t const &maxLength_item,
                                min_max_type *t ) {
  JSOUND_ASSERT_TYPE( maxLength_item, "$maxLength", XS_INTEGER );
  // TODO
}

void validator::load_minExclusive( store::Item_t const &minExclusive_item,
                                   atomic_type *t ) {
  JSOUND_ASSERT_TYPE( minExclusive_item, "$minExclusive", XS_INTEGER );
  // TODO
}

void validator::load_minInclusive( store::Item_t const &minInclusive_item,
                                   atomic_type *t ) {
  JSOUND_ASSERT_TYPE( minInclusive_item, "$minInclusive", XS_INTEGER );
  // TODO
}

void validator::load_minLength( store::Item_t const &minLength_item,
                                min_max_type *t ) {
  JSOUND_ASSERT_TYPE( minLength_item, "$minLength", XS_INTEGER );
  // TODO
}

void validator::load_name( store::Item_t const &name_item ) {
  JSOUND_ASSERT_TYPE( name_item, "$name", XS_STRING );
  zstring const name_str( name_item->getStringValue() );
  if ( ztd::contains( types_, name_str ) )
    throw ZORBA_EXCEPTION( jsd::DUPLICATE_TYPE, ERROR_PARAMS( name_str ) );
}

void validator::load_namespace( store::Item_t const &namespace_item ) {
  JSOUND_ASSERT_TYPE( namespace_item, "$namespace", XS_STRING );
  namespace_ = namespace_item->getStringValue();
}

void validator::load_pattern( store::Item_t const &pattern_item ) {
  // TODO
}

void validator::load_totalDigits( store::Item_t const &totalDigits_item ) {
  // TODO
}

void validator::load_array_type( store::Item_t const &type_item,
                                 array_type *t ) {
  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( key == "$constraints" )
      load_constraints( value_item );
    else if ( key == "$content" )
      load_content_array( value_item );
    else if ( key == "$enumeration" )
      load_enumeration( value_item );
    else if ( key == "$maxLength" )
      load_maxLength( value_item, t );
    else if ( key == "$minLength" )
      load_minLength( value_item, t );
    else if ( key == "$kind" )
      /* already handled */;
    else if ( key == "$name" )
      load_name( value_item );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
  it->close();
}

void validator::load_atomic_type( store::Item_t const &type_item,
                                  atomic_type *t ) {
  store::Item_t const baseType_item( require_value( type_item, "$baseType" ) );
  // TODO: do something with baseType

  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( key == "$about" )
      load_about( value_item );
    else if ( key == "$baseType" )
      /* already checked above */;
    else if ( key == "$constraints" )
      load_constraints( value_item );
    else if ( key == "$enumeration" )
      load_enumeration( value_item );
    else if ( key == "$explicitTimezone" )
      load_explicitTimezone( value_item, t );
    else if ( key == "$fractionDigits" )
      load_fractionDigits( value_item, t );
    else if ( key == "$kind" )
      /* already handled */;
    else if ( key == "$length" )
      load_length( value_item, t );
    else if ( key == "$maxExclusive" )
      load_maxExclusive( value_item, t );
    else if ( key == "$maxInclusive" )
      load_maxInclusive( value_item, t );
    else if ( key == "$maxLength" )
      load_maxLength( value_item, t );
    else if ( key == "$minExclusive" )
      load_minExclusive( value_item, t );
    else if ( key == "$minInclusive" )
      load_minInclusive( value_item, t );
    else if ( key == "$minLength" )
      load_minLength( value_item, t );
    else if ( key == "$name" )
      load_name( value_item );
    else if ( key == "$pattern" )
      load_pattern( value_item );
    else if ( key == "$totalDigits" )
      load_totalDigits( value_item );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
  it->close();
}

void validator::load_open( store::Item_t const &open_item ) {
  // TODO
}

void validator::load_object_type( store::Item_t const &type_item,
                                  object_type *t ) {
  store::Item_t const content( require_value( type_item, "$content" ) );
  load_content_object( content );

  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( key == "$baseType" )
      load_baseType( value_item );
    else if ( key == "$constraints" )
      load_constraints( value_item );
    else if ( key == "$content" )
      /* already checked above */;
    else if ( key == "$name" )
      load_name( value_item );
    else if ( key == "$open" )
      load_open( value_item );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
  it->close();
}

unique_ptr<type> validator::load_type( store::Item_t const &type_item ) {
  JSOUND_ASSERT_KIND( type_item, "$type", OBJECT );
  store::Item_t const kind_item( require_value( type_item, "$kind" ) );
  unique_ptr<type> t( load_kind( kind_item ) );
#if 0
  switch ( k ) {
    case k_none:
      ZORBA_ASSERT( false );
    case k_array:
      load_array_type( type_item, static_cast<array_type*>( t.get() ) );
      break;
    case k_atomic:
      load_atomic_type( type_item, static_cast<atomic_type*>( t.get() ) );
      break;
    case k_object:
      load_object_type( type_item, static_cast<object_type*>( t.get() ) );
      break;
    case k_union:
      load_union_type( type_item, static_cast<union_type>( t.get() ) );
      break;
  } // switch
#endif
  return t;
}

void validator::load_types( store::Item_t const &types ) {
  JSOUND_ASSERT_KIND( types, "$types", ARRAY );
  store::Iterator_t it( types->getArrayValues() );
  store::Item_t type_item;
  it->open();
  while ( it->next( type_item ) ) {
    load_type( type_item );
    // TODO: do something with returned type
  }
  it->close();
}

void validator::load_union_type( store::Item_t const &type, union_type *t ) {
  // TODO
}

void validator::validate( store::Item_t const &json, zstring const &type_name,
                          store::Item_t *result ) const {
  // TODO
}

///////////////////////////////////////////////////////////////////////////////

} // namespace jsound
} // namespace zorba

/* vim:set et sw=2 ts=2: */
