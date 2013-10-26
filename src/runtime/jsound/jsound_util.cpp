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

#define ASSERT_KIND(ITEM,KEY,KIND) \
  assert_kind( ITEM, KEY, store::Item::KIND )

#define ASSERT_TYPE(ITEM,KEY,TYPE) \
  assert_type( ITEM, KEY, store::TYPE )

static store::Item_t get_value( store::Item_t const &jsd, char const *key,
                                bool required = false ) {
  zstring s( key );
  store::Item_t key_item, value_item;
  GENV_ITEMFACTORY->createString( key_item, s );
  value_item = jsd->getObjectValue( key_item );
  if ( required && !value_item )
    throw ZORBA_EXCEPTION( jsd::MISSING_KEY, ERROR_PARAMS( key ) );
  return value_item;
}

///////////////////////////////////////////////////////////////////////////////

JSound::JSound( store::Item_t const &jsd ) {
  store::Item_t value;

  value = get_value( jsd, "$imports" );
  if ( !!value )
    load_imports( value );

  value = get_value( jsd, "$namespace", true );
  load_namespace( value );

  value = get_value( jsd, "$types", true );
  load_types( value );
}

void JSound::load_about( store::Item_t const &about ) {
  // TODO
}

void JSound::load_baseType( store::Item_t const &baseType ) {
  // TODO
}

void JSound::load_constraints( store::Item_t const &constraints ) {
  // TODO
}

void JSound::load_content_array( store::Item_t const &content ) {
  ASSERT_KIND( content, "$content", ARRAY );
  if ( content->getArraySize() != numeric_consts<xs_integer>::one() )
    throw ZORBA_EXCEPTION( jsd::ILLEGAL_ARRAY_SIZE );
  store::Item_t const type(
    content->getArrayValue( numeric_consts<xs_integer>::one() )
  );
  if ( IS_ATOMIC_TYPE( type, XS_STRING ) ) {
    // TODO: do something with type
  } else if ( IS_KIND( type, OBJECT ) ) {
    // TODO
  } else
    throw ZORBA_EXCEPTION( jsd::ILLEGAL_ARRAY_TYPE );
}

void JSound::load_content_object( store::Item_t const &content ) {
  ASSERT_KIND( content, "$content", OBJECT );

  store::Iterator_t it( content->getObjectKeys() );
  store::Item_t key;
  while ( it->next( key ) ) {
    store::Item_t const value( content->getObjectValue( key ) );
    load_field_descriptor( value );
  }
}

void JSound::load_enumeration( store::Item_t const &enumeration ) {
  ASSERT_KIND( enumeration, "$enumeration", ARRAY );
}

void JSound::load_explicitTimezone( store::Item_t const &eTz ) {
  // TODO
}

void JSound::load_field_descriptor( store::Item_t const &field ) {
  store::Item_t const type( get_value( field, "$type", true ) );
  store::Item_t const optional( get_value( field, "$type" ) );
  store::Item_t const default_value( get_value( field, "$default" ) );
}

void JSound::load_fractionDigits( store::Item_t const &fractionDigits ) {
  // TODO
}

void JSound::load_imports( store::Item_t const &imports ) {
  ASSERT_KIND( imports, "$imports", ARRAY );
  store::Iterator_t it( imports->getArrayValues() );
  store::Item_t item;
  while ( it->next( item ) ) {
    // TODO
  }
}

void JSound::load_kind( store::Item_t const &kind ) {
  ASSERT_TYPE( kind, "$kind", XS_STRING );
}

void JSound::load_length( store::Item_t const &length ) {
  // TODO
}

void JSound::load_maxExclusive( store::Item_t const &maxExclusive ) {
  // TODO
}

void JSound::load_maxInclusive( store::Item_t const &maxInclusive ) {
  // TODO
}

void JSound::load_maxLength( store::Item_t const &maxLength ) {
  // TODO
}

void JSound::load_minExclusive( store::Item_t const &minExclusive ) {
  // TODO
}

void JSound::load_minInclusive( store::Item_t const &minInclusive ) {
  // TODO
}

void JSound::load_minLength( store::Item_t const &minLength ) {
  // TODO
}

void JSound::load_name( store::Item_t const &name ) {
  ASSERT_TYPE( name, "$name", XS_STRING );
  // TODO: check for duplicate name
}

void JSound::load_namespace( store::Item_t const &ns ) {
  ASSERT_TYPE( ns, "$namespace", XS_STRING );
}

void JSound::load_pattern( store::Item_t const &pattern ) {
  // TODO
}

void JSound::load_totalDigits( store::Item_t const &totalDigits ) {
  // TODO
}

void JSound::load_array_type( store::Item_t const &type ) {
  store::Item_t const kind( get_value( type, "$kind", true ) );

  store::Iterator_t it( type->getObjectKeys() );
  store::Item_t item;
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value( type->getObjectValue( item ) );
    if ( key == "$constraints" )
      load_constraints( value );
    else if ( key == "$content" )
      load_content_array( value );
    else if ( key == "$enumeration" )
      load_enumeration( value );
    else if ( key == "$maxLength" )
      load_maxLength( value );
    else if ( key == "$minLength" )
      load_minLength( value );
    else if ( key == "$kind" )
      load_kind( value );
    else if ( key == "$name" )
      load_name( value );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
}

void JSound::load_atomic_type( store::Item_t const &type ) {
  store::Item_t const baseType( get_value( type, "$baseType", true ) );
  // TODO: do something with baseType
  store::Iterator_t it( type->getObjectKeys() );
  store::Item_t item;
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value( type->getObjectValue( item ) );
    if ( key == "$about" )
      load_about( value );
    else if ( key == "$baseType" )
      /* already checked above */;
    else if ( key == "$constraints" )
      load_constraints( value );
    else if ( key == "$enumeration" )
      load_enumeration( value );
    else if ( key == "$explicitTimezone" )
      load_explicitTimezone( value );
    else if ( key == "$fractionDigits" )
      load_fractionDigits( value );
    else if ( key == "$length" )
      load_length( value );
    else if ( key == "$maxExclusive" )
      load_maxExclusive( value );
    else if ( key == "$maxInclusive" )
      load_maxInclusive( value );
    else if ( key == "$maxLength" )
      load_maxLength( value );
    else if ( key == "$minExclusive" )
      load_minExclusive( value );
    else if ( key == "$minInclusive" )
      load_minInclusive( value );
    else if ( key == "$minLength" )
      load_minLength( value );
    else if ( key == "$name" )
      load_name( value );
    else if ( key == "$pattern" )
      load_pattern( value );
    else if ( key == "$totalDigits" )
      load_totalDigits( value );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
}

void JSound::load_open( store::Item_t const &open ) {
  // TODO
}

void JSound::load_object_type( store::Item_t const &type ) {
  store::Item_t const content( get_value( type, "$content", true ) );
  load_content_object( content );

  store::Iterator_t it( type->getObjectKeys() );
  store::Item_t item;
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value( type->getObjectValue( item ) );
    if ( key == "$baseType" )
      load_baseType( value );
    else if ( key == "$constraints" )
      load_constraints( value );
    else if ( key == "$content" )
      /* already checked above */;
    else if ( key == "$name" )
      load_name( value );
    else if ( key == "$open" )
      load_open( value );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
}

void JSound::load_type( store::Item_t const &type ) {
  ASSERT_KIND( type, "$type", OBJECT );
  store::Item_t const kind( get_value( type, "$kind", true ) );
  load_kind( kind );
  zstring const kind_str( kind->getStringValue() );
  if ( kind_str == "atomic" )
    load_atomic_type( type );
  else if ( kind_str == "array" )
    load_array_type( type );
  else if ( kind_str == "object" )
    load_object_type( type );
  else if ( kind_str == "union" )
    load_union_type( type );
  else
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_VALUE, ERROR_PARAMS( kind_str, "$kind" )
    );
}

void JSound::load_types( store::Item_t const &types ) {
  ASSERT_KIND( types, "$types", ARRAY );
  store::Iterator_t it( types->getArrayValues() );
  store::Item_t type;
  while ( it->next( type ) )
    load_type( type );
}

void JSound::load_union_type( store::Item_t const &types ) {
  // TODO
}

void JSound::validate( store::Item_t const &json, zstring const &type_name,
                       store::Item_t *result ) const {
  // TODO
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
