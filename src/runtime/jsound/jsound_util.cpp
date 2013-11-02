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
#include "util/stl_util.h"
#include "util/string_util.h"
#include "util/xml_util.h"
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

static store::SchemaTypeCode find_atomic_type( zstring const &type_name ) {
  if ( ZSTREQ( type_name, "string" ) )
    return store::XS_STRING;
  if ( ZSTREQ( type_name, "boolean" ) )
    return store::XS_BOOLEAN;
  if ( ZSTREQ( type_name, "integer" ) )
    return store::XS_INTEGER;
  if ( ZSTREQ( type_name, "decimal" ) )
    return store::XS_DECIMAL;
  if ( ZSTREQ( type_name, "double" ) )
    return store::XS_DOUBLE;
  if ( ZSTREQ( type_name, "float" ) )
    return store::XS_FLOAT;
  if ( ZSTREQ( type_name, "date" ) )
    return store::XS_DATE;
  if ( ZSTREQ( type_name, "dateTime" ) )
    return store::XS_DATETIME;
  if ( ZSTREQ( type_name, "dateTimeStamp" ) )
    return store::XS_DATETIME_STAMP;
  if ( ZSTREQ( type_name, "dayTimeDuration" ) )
    return store::XS_DT_DURATION;
  if ( ZSTREQ( type_name, "duration" ) )
    return store::XS_DURATION;
  if ( ZSTREQ( type_name, "time" ) )
    return store::XS_TIME;
  if ( ZSTREQ( type_name, "anyURI" ) )
    return store::XS_ANY_URI;
  if ( ZSTREQ( type_name, "base64Binary" ) )
    return store::XS_BASE64BINARY;
  if ( ZSTREQ( type_name, "byte" ) )
    return store::XS_BYTE;
  if ( ZSTREQ( type_name, "gDay" ) )
    return store::XS_GDAY;
  if ( ZSTREQ( type_name, "gMonth" ) )
    return store::XS_GMONTH;
  if ( ZSTREQ( type_name, "gMonthDay" ) )
    return store::XS_GMONTH_DAY;
  if ( ZSTREQ( type_name, "gYear" ) )
    return store::XS_GYEAR;
  if ( ZSTREQ( type_name, "gYearMonth" ) )
    return store::XS_GYEAR_MONTH;
  if ( ZSTREQ( type_name, "hexBinary" ) )
    return store::XS_HEXBINARY;
  if ( ZSTREQ( type_name, "long" ) )
    return store::XS_LONG;
  if ( ZSTREQ( type_name, "negativeInteger" ) )
    return store::XS_NEGATIVE_INTEGER;
  if ( ZSTREQ( type_name, "nonNegativeInteger" ) )
    return store::XS_NON_NEGATIVE_INTEGER;
  if ( ZSTREQ( type_name, "nonPositiveInteger" ) )
    return store::XS_NON_POSITIVE_INTEGER;
  if ( ZSTREQ( type_name, "positivInteger" ) )
    return store::XS_POSITIVE_INTEGER;
  if ( ZSTREQ( type_name, "short" ) )
    return store::XS_SHORT;
  if ( ZSTREQ( type_name, "unsignedByte" ) )
    return store::XS_UNSIGNED_BYTE;
  if ( ZSTREQ( type_name, "unsignedInt" ) )
    return store::XS_UNSIGNED_INT;
  if ( ZSTREQ( type_name, "unsignedLong" ) )
    return store::XS_UNSIGNED_LONG;
  if ( ZSTREQ( type_name, "unsignedShort" ) )
    return store::XS_UNSIGNED_SHORT;
  if ( ZSTREQ( type_name, "yearMonthDuration" ) )
    return store::XS_YM_DURATION;
  return store::XS_LAST;
}

static kind find_kind( zstring const &name ) {
  if ( ZSTREQ( name, "atomic" ) )
    return k_atomic;
  if ( ZSTREQ( name, "array" ) )
    return k_array;
  if ( ZSTREQ( name, "object" ) )
    return k_object;
  if ( ZSTREQ( name, "union" ) )
    return k_union;
  return k_none;
}

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

ostream& operator<<( ostream &os, kind k ) {
  switch ( k ) {
    case k_none  : return os << "none";
    case k_array : return os << "array";
    case k_atomic: return os << "atomic";
    case k_object: return os << "object";
    case k_union : return os << "union";
  }
}

///////////////////////////////////////////////////////////////////////////////

array_type::array_type() : min_max_type( k_array ) {
}

array_type::~array_type() {
  ztd::delete_ptr_seq( content_ );
}

void array_type::load_type( store::Item_t const &type_item ) {
  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( ZSTREQ( key, "$constraints" ) )
      load_constraints( value_item );
    else if ( ZSTREQ( key, "$content" ) )
      load_content_array( value_item );
    else if ( ZSTREQ( key, "$enumeration" ) )
      load_enumeration( value_item, t );
    else if ( ZSTREQ( key, "$maxLength" ) )
      load_maxLength( value_item, t );
    else if ( ZSTREQ( key, "$minLength" ) )
      load_minLength( value_item, t );
    else if ( ZSTREQ( key, "$kind" ) )
      /* already handled */;
    else if ( ZSTREQ( key, "$name" ) )
      load_name( value_item, t );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
  it->close();
}

///////////////////////////////////////////////////////////////////////////////

atomic_type::atomic_type() : min_max_type( k_atomic ) {
  explicitTimezone_ = timezone::optional;  // TODO: correct?
  length_ = -1;
  totalDigits_ = fractionDigits_ = -1;
}

void atomic_type::load_type( store::Item_t const &type_item ) {
  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( ZSTREQ( key, "$about" ) )
      load_about( value_item );
    else if ( ZSTREQ( key, "$baseType" ) )
      /* already handled */;
    else if ( ZSTREQ( key, "$constraints" ) )
      load_constraints( value_item );
    else if ( ZSTREQ( key, "$enumeration" ) )
      load_enumeration( value_item, t );
    else if ( ZSTREQ( key, "$explicitTimezone" ) )
      load_explicitTimezone( value_item, t );
    else if ( ZSTREQ( key, "$fractionDigits" ) )
      load_fractionDigits( value_item, t );
    else if ( ZSTREQ( key, "$kind" ) )
      /* already handled */;
    else if ( ZSTREQ( key, "$length" ) )
      load_length( value_item, t );
    else if ( ZSTREQ( key, "$maxExclusive" ) )
      load_maxExclusive( value_item, t );
    else if ( ZSTREQ( key, "$maxInclusive" ) )
      load_maxInclusive( value_item, t );
    else if ( ZSTREQ( key, "$maxLength" ) )
      load_maxLength( value_item, t );
    else if ( ZSTREQ( key, "$minExclusive" ) )
      load_minExclusive( value_item, t );
    else if ( ZSTREQ( key, "$minInclusive" ) )
      load_minInclusive( value_item, t );
    else if ( ZSTREQ( key, "$minLength" ) )
      load_minLength( value_item, t );
    else if ( ZSTREQ( key, "$name" ) )
      load_name( value_item, t );
    else if ( ZSTREQ( key, "$pattern" ) )
      load_pattern( value_item, t );
    else if ( ZSTREQ( key, "$totalDigits" ) )
      load_totalDigits( value_item, t );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
  it->close();
}

///////////////////////////////////////////////////////////////////////////////

min_max_type::min_max_type( kind k ) : type( k ) {
  maxLength_ = minLength_ = -1;
}

///////////////////////////////////////////////////////////////////////////////

object_type::object_type() : type( k_object ) {
  open_ = true;
}

object_type::~object_type() {
  MUTATE_EACH( content_type, i, content_ )
    delete i->second;
}

void object_type::load_type( store::Item_t const &type_item ) {
  store::Item_t const baseType_item( get_value( type_item, "$baseType" ) );
  if ( !!baseType_item )
    load_baseType( baseType_item, t );
  store::Item_t const content( require_value( type_item, "$content" ) );
  load_content_object( content );

  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( ZSTREQ( key, "$baseType" ) )
      /* already handled */;
    else if ( ZSTREQ( key, "$constraints" ) )
      load_constraints( value_item );
    else if ( ZSTREQ( key, "$content" ) )
      /* already checked above */;
    else if ( ZSTREQ( key, "$name" ) )
      load_name( value_item, t );
    else if ( ZSTREQ( key, "$open" ) )
      load_open( value_item, t );
    else
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_KEY, ERROR_PARAMS( key, "$type" ) );
  } // while
  it->close();
}

///////////////////////////////////////////////////////////////////////////////

type::type( kind k ) : kind_( k ) {
}

type::~type() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

union_type::union_type() : type( k_union ) {
}

void union_type::load_type( store::Item_t const &type ) {
  // TODO
}

///////////////////////////////////////////////////////////////////////////////

validator::validator( store::Item_t const &jsd_item ) {
  JSOUND_ASSERT_KIND( jsd_item, "JSound", OBJECT );
  load_namespace( require_value( jsd_item, "$namespace" ) );
  store::Item_t item( get_value( jsd_item, "$imports" ) );
  if ( !!item )
    load_imports( item );
  load_types( require_value( jsd_item, "$types" ) );
}

validator::~validator() {
  MUTATE_EACH( typename_map, i, types_ )
    delete i->second;
}

type const* validator::find_type( zstring const &type_name ) const {
  if ( type_name.compare( 0, 2, "Q{" ) == 0 ) {
    typename_map::const_iterator const i( types_.find( type_name ) );
    if ( i == types_.end() )
      throw ZORBA_EXCEPTION( jsd::UNKNOWN_TYPE, ERROR_PARAMS( type_name ) );
    return i->second;
  }
  return nullptr;
}

void validator::fq_type_name( zstring *type_name ) {
  zstring prefix, local;
  if ( xml::split_qname( *type_name, &prefix, &local ) ) {
    prefix_namespace_map::const_iterator const i( prefix_ns_.find( prefix ) );
    if ( i == prefix_ns_.end() )
      throw ZORBA_EXCEPTION( jsd::UNKNOWN_PREFIX, ERROR_PARAMS( prefix ) );
    *type_name = "Q{" + i->second + '}' + local;
    return true;
  }
  *type_name = "Q{" + namespace_ + '}' + *type_name;
}

void validator::load_about( store::Item_t const &about_item ) {
  JSOUND_ASSERT_TYPE( about_item, "$about", XS_STRING );
  about_ = about_item->getStringValue();
}

void validator::load_baseType( store::Item_t const &baseType_item, type *t ) {
  JSOUND_ASSERT_TYPE( baseType_item, "$baseType", XS_STRING );
  zstring const baseType_str( baseType_item->getStringValue() );
  if ( kind const k = find_kind( baseType_str ) ) {
    //
    // The case where the kind of the base type of "array", "atomic", "object",
    // or "union" is specified explicitly ...
    //
    if ( k != t->kind_ ) {
      //
      // ... and does NOT match the kind of this type.
      //
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_BASE_TYPE,
        ERROR_PARAMS( k, t->name_, t->kind_ )
      );
    }
    return;
  }

  zstring fq_baseType_str( baseType_str );
  fq_type_name( &fq_baseType_str );

  type const *const bt = find_type( fq_baseType_str );
  if ( bt ) {
    if ( bt->kind_ != t->kind_ )
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_BASE_TYPE,
        ERROR_PARAMS( fq_baseType_str, t->name_, t->kind_ )
      );
    t->baseType_ = fq_baseType_str;
    return;
  }

  if ( t->kind_ == k_atomic ) {
    store::SchemaTypeCode const tc = find_atomic_type( fq_baseType_str );
    if ( tc != store::XS_LAST ) {
      t->baseType_ = fq_baseType_str;
      return;
    }
  }

  throw ZORBA_EXCEPTION( jsd::UNKNOWN_TYPE, ERROR_PARAMS( fq_baseType_str ) );
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
  store::Item_t key_item;
  it->open();
  while ( it->next( key_item ) )
    load_field_descriptor( content_item->getObjectValue( key_item ) );
  it->close();
}

void validator::load_enumeration( store::Item_t const &enumeration_item,
                                  type *t ) {
  JSOUND_ASSERT_KIND( enumeration_item, "$enumeration", ARRAY );
  store::Iterator_t it( enumeration_item->getArrayValues() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    // TODO: verify values match type
    t->enumeration_.values_.push_back( item );
  }
  it->close();
}

void validator::load_explicitTimezone( store::Item_t const &eTz_item,
                                       atomic_type *t ) {
  JSOUND_ASSERT_TYPE( eTz_item, "$explicitTimezone", XS_STRING );
  zstring const eTz_str( eTz_item->getStringValue() );
  if ( ZSTREQ( eTz_str, "optional" ) )
    t->explicitTimezone_ = timezone::optional;
  else if ( ZSTREQ( eTz_str, "prohibited" ) )
    t->explicitTimezone_ = timezone::prohibited;
  else if ( ZSTREQ( eTz_str, "required" ) )
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

void validator::load_import( store::Item_t const &import_item ) {
  JSOUND_ASSERT_KIND( import_item, "$imports array element", OBJECT );
  store::Item_t const ns_item( require_value( import_item, "$namespace" ) );
  JSOUND_ASSERT_TYPE( ns_item, "$namespace", XS_STRING );
  store::Item_t const prefix_item( require_value( import_item, "$prefix" ) );
  JSOUND_ASSERT_TYPE( prefix_item, "$prefix", XS_STRING );
  // TODO: add optional $location
  zstring const ns_str( ns_item->getStringValue() );
  zstring const prefix_str( prefix_item->getStringValue() );
  if ( prefix_str.find( ':' ) != zstring::npos )
    throw ZORBA_EXCEPTION( jsd::ILLEGAL_PREFIX, ERROR_PARAMS( prefix_str ) );
  if ( ztd::contains( prefix_ns_, prefix_str ) )
    throw ZORBA_EXCEPTION( jsd::DUPLICATE_PREFIX, ERROR_PARAMS( prefix_str ) );
  prefix_ns_[ prefix_str ] = ns_str;
}

void validator::load_imports( store::Item_t const &imports_item ) {
  JSOUND_ASSERT_KIND( imports_item, "$imports", ARRAY );
  store::Iterator_t it( imports_item->getArrayValues() );
  store::Item_t import_item;
  it->open();
  while ( it->next( import_item ) )
    load_import( import_item );
  it->close();
}

unique_ptr<type> validator::load_kind( store::Item_t const &kind_item ) {
  JSOUND_ASSERT_TYPE( kind_item, "$kind", XS_STRING );
  zstring const kind_str( kind_item->getStringValue() );
  switch ( find_kind( kind_str ) ) {
    case k_atomic:
      return unique_ptr<type>( new atomic_type );
    case k_array:
      return unique_ptr<type>( new array_type );
    case k_object:
      return unique_ptr<type>( new object_type );
    case k_union:
      return unique_ptr<type>( new union_type );
    default:
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_VALUE, ERROR_PARAMS( kind_str, "$kind" )
      );
  } // switch
}

void validator::load_length( store::Item_t const &length_item,
                             atomic_type *t ) {
  JSOUND_ASSERT_TYPE( length_item, "$length", XS_INTEGER );

#if 0
  if ( !(IS_ATOMIC_TYPE( length_item, XS_STRING ) ||
         IS_ATOMIC_TYPE( length_item, XS_ANYURI ) ||
         IS_ATOMIC_TYPE( length_item, XS_BASE64BINARY ) ||
         IS_ATOMIC_TYPE( length_item, XS_HEXBINARY )) )
    /* TODO: throw exception */;
#endif

  t->length_ = length_item->getIntValue();
  // TODO: assert >= 0
}

void validator::load_maxExclusive( store::Item_t const &maxExclusive_item,
                                   atomic_type *t ) {
  JSOUND_ASSERT_KIND( maxExclusive_item, "$maxExclusive", ATOMIC );
  t->maxExclusive_ = maxExclusive_item;
  // TODO
}

void validator::load_maxInclusive( store::Item_t const &maxInclusive_item,
                                   atomic_type *t ) {
  JSOUND_ASSERT_KIND( maxInclusive_item, "$maxInclusive", ATOMIC );
  t->maxInclusive_ = maxInclusive_item;
  // TODO
}

void validator::load_maxLength( store::Item_t const &maxLength_item,
                                min_max_type *t ) {
  JSOUND_ASSERT_TYPE( maxLength_item, "$maxLength", XS_INTEGER );
  t->maxLength_ = maxLength_item->getIntValue();
  // TODO
}

void validator::load_minExclusive( store::Item_t const &minExclusive_item,
                                   atomic_type *t ) {
  JSOUND_ASSERT_KIND( minExclusive_item, "$minExclusive", ATOMIC );
  t->minExclusive_ = minExclusive_item;
  // TODO
}

void validator::load_minInclusive( store::Item_t const &minInclusive_item,
                                   atomic_type *t ) {
  JSOUND_ASSERT_KIND( minInclusive_item, "$minInclusive", ATOMIC );
  t->minInclusive_ = minInclusive_item;
  // TODO
}

void validator::load_minLength( store::Item_t const &minLength_item,
                                min_max_type *t ) {
  JSOUND_ASSERT_TYPE( minLength_item, "$minLength", XS_INTEGER );
  t->minLength_ = minLength_item->getIntValue();
  // TODO
}

void validator::load_name( store::Item_t const &name_item, type *t ) {
  JSOUND_ASSERT_TYPE( name_item, "$name", XS_STRING );
  zstring const name_str( name_item->getStringValue() );
  if ( ztd::contains( types_, name_str ) )
    throw ZORBA_EXCEPTION( jsd::DUPLICATE_TYPE, ERROR_PARAMS( name_str ) );
  t->name_ = name_str;
}

void validator::load_namespace( store::Item_t const &namespace_item ) {
  JSOUND_ASSERT_TYPE( namespace_item, "$namespace", XS_STRING );
  namespace_ = namespace_item->getStringValue();
}

void validator::load_pattern( store::Item_t const &pattern_item,
                              atomic_type *t ) {
  JSOUND_ASSERT_TYPE( pattern_item, "$pattern", XS_STRING );
  // TODO: verify that the pattern is valid regex
  t->pattern_ = pattern_item->getStringValue();
}

void validator::load_totalDigits( store::Item_t const &totalDigits_item,
                                  atomic_type *t ) {
  JSOUND_ASSERT_TYPE( totalDigits_item, "$totalDigits", XS_INTEGER );
  t->totalDigits_ = totalDigits_item->getIntValue();
  // TODO
}

void validator::load_open( store::Item_t const &open_item, object_type *t ) {
  JSOUND_ASSERT_TYPE( open_item, "$open", XS_BOOLEAN );
  // TODO: do not override baseType's open if false
  t->open_ = open_item->getBooleanValue();
}

unique_ptr<type> validator::load_type( store::Item_t const &type_item ) {
#if 0
  if ( IS_ATOMIC_TYPE( type_item, XS_STRING ) ) {
    // TODO
    return;
  }
  if ( IS_KIND( type_item, OBJECT ) ) {
    // TODO
    return;
  }
  throw ZORBA_EXCEPTION(
    jsd::ILLEGAL_TYPE,
    ERROR_PARAMS( type_item->getStringValue(), "$type", "string", "object" )
  );

  unique_ptr<type> t( load_kind( kind_item ) );
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
  return nullptr;
}

void validator::load_type_top( store::Item_t const &type_item ) {
  store::Item_t const kind_item( require_value( type_item, "$kind" ) );
  store::Item_t const name_item( require_value( type_item, "$name" ) );
  zstring name_str( name_item->getStringValue() );
  fq_type_name( &name_str );
  unique_ptr<type> t( load_kind( kind_item ) );
  load_baseType( require_value( type_item, "$baseType" ), t.get() );
  t->load_type( type_item );
  types_[ name_str ] = t.get();
  t.release();
}

void validator::load_types( store::Item_t const &types_item ) {
  JSOUND_ASSERT_KIND( types_item, "$types", ARRAY );
  store::Iterator_t it( types_item->getArrayValues() );
  store::Item_t type_item;
  it->open();
  while ( it->next( type_item ) )
    load_type_top( type_item );
  it->close();
}

void validator::validate( store::Item_t const &json, zstring const &type_name,
                          store::Item_t *result ) const {
  type const *const t = find_type( type_name );
  if ( !t )
    throw ZORBA_EXCEPTION( jsd::UNKNOWN_TYPE, ERROR_PARAMS( type_name ) );
  // TODO
}

///////////////////////////////////////////////////////////////////////////////

} // namespace jsound
} // namespace zorba

/* vim:set et sw=2 ts=2: */
