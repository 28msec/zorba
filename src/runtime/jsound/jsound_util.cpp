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
#include <iostream>
#include <sstream>

#include <zorba/config.h>
#include <zorba/internal/cxx_util.h>
#include <zorba/diagnostic_list.h>
#include <zorba/store_consts.h>

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"
#include "diagnostics/assert.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "system/globalenv.h"
#include "types/casting.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "util/less.h"
#include "util/regex.h"
#include "util/stl_util.h"
#include "util/string_util.h"
#include "util/xml_util.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"

#include "jsound_util.h"

namespace zorba {
namespace ztd {

// TODO: these functions should be put in some header somewhere

inline zstring to_string( store::Item const &i ) {
  return i.toString();
}

inline zstring to_string( store::Item_t const &i ) {
  return !i ? "<null>" : to_string( *i );
}

} // namespace ztd
} // namespace zorba

using namespace std;

namespace zorba {
namespace jsound {

///////////////////////////////////////////////////////////////////////////////

struct constraints {
  typedef zstring value_type;
  typedef vector<value_type> content_type;
  content_type values_;
};

struct enumeration {
  typedef store::Item_t value_type;
  typedef vector<value_type> content_type;
  content_type values_;
};

typedef unsigned short facet_mask;

enum kind {
  k_none,
  k_array,
  k_atomic,
  k_object,
  k_union
};
ostream& operator<<( ostream&, kind );

namespace timezone {
  enum type {
    prohibited,
    optional,
    required
  };
}
ostream& operator<<( ostream&, timezone::type );

class type {
public:
  zstring about_;
  type const* baseType_;
  constraints constraints_;
  enumeration enumeration_;
  facet_mask facet_mask_;
  kind const kind_;
  zstring name_;

  type( kind );
  virtual ~type();

protected:
  virtual bool annotate( store::Item_t const&, store::Item_t* ) const = 0;
  virtual void assert_subtype_of( type const* ) const = 0;
  void load_about( store::Item_t const& );
  type const* find_facet( facet_mask facet ) const;
  virtual void load_baseType( store::Item_t const&, schema const& );
  void load_constraints( store::Item_t const& );
  void load_enumeration( store::Item_t const& );
  virtual void load_type( store::Item_t const&, schema& ) = 0;
  void load_name( store::Item_t const&, schema const& );
  virtual bool validate( store::Item_t const& ) const = 0;

  friend class array_type;
  friend class atomic_type;
  friend class object_type;
  friend class schema;
  friend class union_type;
};
typedef type type_type;                 // eliminate special case for macros

class min_max_type : public type {
public:
  int minLength_;
  int maxLength_;

protected:
  void load_maxLength( store::Item_t const& );
  void load_minLength( store::Item_t const& );

  min_max_type( kind );

  friend class schema;
};

class array_type : public min_max_type {
public:
  typedef type const* content_type;
  content_type content_;

  array_type();

protected:
  virtual bool annotate( store::Item_t const&, store::Item_t* ) const;
  virtual void assert_subtype_of( type const* ) const;
  virtual void load_type( store::Item_t const&, schema& );
  virtual bool validate( store::Item_t const& ) const;

private:
  void load_content( store::Item_t const&, schema& );

  friend class schema;
};

class atomic_type : public min_max_type {
public:
  store::SchemaTypeCode schemaTypeCode_;

  // string, anyURI, base64Binary, hexBinary
  int length_;

  // date, dateTime, time, gYear, gYearMOnth, gMonth, gMondyDay, gDay,
  // duration, decimal (and all derived types), double, float
  store::Item_t maxExclusive_;
  store::Item_t maxInclusive_;
  store::Item_t minExclusive_;
  store::Item_t minInclusive_;

  // decimal (and all derived types)
  int totalDigits_;

  // decimal (only)
  int fractionDigits_;

  // date, dateTime, time
  timezone::type explicitTimezone_;

  // all types
  zstring pattern_;
  mutable unicode::regex pattern_re_;

  atomic_type();

protected:
  virtual bool annotate( store::Item_t const&, store::Item_t* ) const;
  virtual void assert_subtype_of( type const* ) const;
  virtual void load_baseType( store::Item_t const&, schema const& );
  virtual void load_type( store::Item_t const&, schema& );
  virtual bool validate( store::Item_t const& ) const;

private:
  void assert_min_max_facet( store::Item_t const&, char const* ) const;
  void load_explicitTimezone( store::Item_t const& );
  void load_fractionDigits( store::Item_t const& );
  void load_length( store::Item_t const& );
  void load_maxInclusive( store::Item_t const& );
  void load_minInclusive( store::Item_t const& );
  void load_maxExclusive( store::Item_t const& );
  void load_minExclusive( store::Item_t const& );
  void load_pattern( store::Item_t const& );
  void load_totalDigits( store::Item_t const& );
};

class object_type : public type {
public:
  class field_descriptor {
  public:
    type const *type_;
    bool optional_;
    store::Item_t default_;

    field_descriptor();
    // default copy constructor is OK
    // defalut assignment operator is OK
    // default destructor is OK

  private:
    void load_default( store::Item_t const& );
    void load_optional( store::Item_t const& );
    void load_type( store::Item_t const&, schema& );
    friend class object_type;
  };

  typedef zstring key_type;
  typedef field_descriptor value_type;
  typedef unordered_map<key_type,value_type> content_type;

  content_type content_;
  bool open_;

  object_type();

protected:
  virtual bool annotate( store::Item_t const&, store::Item_t* ) const;
  virtual void assert_subtype_of( type const* ) const;
  virtual void load_type( store::Item_t const&, schema& );
  virtual bool validate( store::Item_t const& ) const;

private:
  void load_content( store::Item_t const&, schema& );
  void load_field_descriptor( store::Item_t const&, schema&,
                              field_descriptor* );
  void load_open( store::Item_t const& );

  friend class schema;
};

class union_type : public type {
public:
  typedef type const* value_type;
  typedef vector<value_type> content_type;

  content_type content_;

  union_type();

protected:
  virtual bool annotate( store::Item_t const&, store::Item_t* ) const;
  virtual void assert_subtype_of( type const* ) const;
  virtual void load_type( store::Item_t const&, schema& );
  virtual bool validate( store::Item_t const& ) const;

private:
  void load_content( store::Item_t const&, schema& );
};

///////////////////////////////////////////////////////////////////////////////

static facet_mask const facet_constraints      = 1 <<  0;
static facet_mask const facet_enumeration      = 1 <<  1;
static facet_mask const facet_explicitTimezone = 1 <<  2;
static facet_mask const facet_fractionDigits   = 1 <<  3;
static facet_mask const facet_length           = 1 <<  4;
static facet_mask const facet_maxExclusive     = 1 <<  5;
static facet_mask const facet_maxInclusive     = 1 <<  6;
static facet_mask const facet_maxLength        = 1 <<  7;
static facet_mask const facet_minExclusive     = 1 <<  8;
static facet_mask const facet_minInclusive     = 1 <<  9;
static facet_mask const facet_minLength        = 1 << 10;
static facet_mask const facet_open             = 1 << 11;
static facet_mask const facet_pattern          = 1 << 12;
static facet_mask const facet_totalDigits      = 1 << 13;

#define ADD_FACET(FACET) \
  facet_mask_ |= facet_##FACET

#define ASSERT_BASE_FACET(FACET,EXPR)             \
  do {                                            \
    if ( FACET##_type && !(EXPR) )                \
      throw FACET_BASE_VALUE_EXCEPTION( FACET );  \
  } while (0)

#define ASSERT_SUBTYPE_FACET(FACET,TYPE,EXPR)                       \
  do {                                                              \
    TYPE##_type const *const bt = FIND_FACET( t, TYPE, FACET );     \
    TYPE##_type const *const dt = FIND_FACET( this, TYPE, FACET );  \
    if ( bt && dt && bt != dt && !(EXPR) )                          \
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_BASE_TYPE, ERROR_PARAMS( t->name_, name_, ZED( ILLEGAL_BASE_TYPE_IncompatibleFacets ), "$" #FACET ) ); \
  } while (0)

#define DECL_baseType(TYPE) \
  TYPE##_type const *const baseType = static_cast<TYPE##_type const*>( baseType_ )

#define DECL_cast_t(TYPE)                                                   \
  TYPE##_type const *const cast_t = dynamic_cast<TYPE##_type const*>( t );  \
  do {                                                                      \
    if ( !cast_t )                                                          \
      throw ZORBA_EXCEPTION( jsd::ILLEGAL_BASE_TYPE, ERROR_PARAMS( t->name_, this->name_, ZED( ILLEGAL_BASE_TYPE_MustBeX ), #TYPE ) ); \
  } while (0)

#define DECL_FACET_type(OBJ,TYPE,FACET) \
  TYPE##_type const *const FACET##_type = FIND_FACET( OBJ, TYPE, FACET )

#define FACET_BASE_VALUE_EXCEPTION(FACET) \
  ZORBA_EXCEPTION(                        \
    jsd::ILLEGAL_FACET_VALUE,             \
    ERROR_PARAMS( ztd::to_string( FACET##_ ), "$" #FACET, ZED( ILLEGAL_FACET_VALUE_NoOverrideBase ), ztd::to_string( FACET##_type->FACET##_ ) ) \
  )

#define FACET_VALUE_EXCEPTION(FACET,REASON)                                   \
  ZORBA_EXCEPTION(                                                            \
    jsd::ILLEGAL_FACET_VALUE,                                                 \
    ERROR_PARAMS( FACET##_, "$" #FACET, ZED( ILLEGAL_FACET_VALUE_##REASON ) ) \
  )

#define FIND_FACET(OBJ,TYPE,FACET) \
  static_cast<TYPE##_type const*>( (OBJ)->find_facet( facet_##FACET ) )

#define IS_ATOMIC_TYPE(ITEM,TYPE) \
  ( (ITEM)->isAtomic() && IS_SUBTYPE( (ITEM)->getTypeCode(), TYPE ) )

#define IS_SUBTYPE(T,U) \
  TypeOps::is_subtype( (T), store::U )

#define IS_KIND(ITEM,KIND) \
  ( (ITEM)->getKind() == store::Item::KIND )

#define VALIDATE_FACET(FACET,EXPR)  \
  do {                              \
    if ( FACET##_type && !(EXPR) )  \
      return false;                 \
  } while (0)

static void assert_kind( store::Item_t const &item, char const *name,
                         store::Item::ItemKind kind ) {
  if ( item->getKind() != kind )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_TYPE,
      ERROR_PARAMS( item->getKind(), name, kind )
    );
}

inline void assert_kind( store::Item_t const &item, zstring const &name,
                         store::Item::ItemKind kind ) {
  assert_kind( item, name.c_str(), kind );
}

#define ASSERT_KIND(ITEM,NAME,KIND) \
  assert_kind( ITEM, NAME, store::Item::KIND )

static void assert_type( store::Item_t const &item, char const *name,
                         store::SchemaTypeCode type ) {
  if ( !item->isAtomic() )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_TYPE,
      ERROR_PARAMS( item->getKind(), name, store::Item::ATOMIC )
    );
  if ( !TypeOps::is_subtype( item->getTypeCode(), type ) )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_TYPE,
      ERROR_PARAMS( item->getTypeCode(), name, type )
    );
}

inline void assert_type( store::Item_t const &item, zstring const &name,
                         store::SchemaTypeCode type ) {
  assert_type( item, name.c_str(), type );
}

#define ASSERT_TYPE(ITEM,NAME,TYPE) \
  assert_type( ITEM, NAME, store::TYPE )

inline bool is_atomic_type( store::Item_t const &item,
                            store::SchemaTypeCode type ) {
  return item->isAtomic() && TypeOps::is_subtype( item->getTypeCode(), type );
}

static store::SchemaTypeCode map_atomic_type( zstring const &type_name ) {
  // check common types first
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

static kind map_kind( store::Item::ItemKind k ) {
  switch ( k ) {
    case store::Item::ARRAY : return k_array ;
    case store::Item::ATOMIC: return k_atomic;
    case store::Item::OBJECT: return k_object;
    default                 : return k_none  ;
  }
}

static void assert_type_matches( store::Item_t const &item, type const *t,
                                 char const *name = "" ) {
  kind const k = map_kind( item->getKind() );
  if ( k != t->kind_ )
    throw ZORBA_EXCEPTION(
      jsd::TYPE_MISMATCH,
      ERROR_PARAMS( k, t->kind_, name )
    );
  if ( item->isAtomic() ) {
    atomic_type const *const at = static_cast<atomic_type const*>( t );
    store::SchemaTypeCode const stc = at->schemaTypeCode_;
    if ( !TypeOps::is_subtype( item->getTypeCode(), stc ) )
      throw ZORBA_EXCEPTION(
        jsd::TYPE_MISMATCH,
        ERROR_PARAMS( item->getTypeCode(), t->name_, name )
      );
  }
}

inline void assert_type_matches( store::Item_t const &item, type const *t,
                                 zstring const &name ) {
  assert_type_matches( item, t, name.c_str() );
}

static void create_invalid( zstring const &expected_type_name,
                            store::Item_t const &instance,
                            store::Item_t *result ) {
  vector<store::Item_t> keys, values;
  store::Item_t item;
  zstring s;

  s = "$invalid";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  GENV_ITEMFACTORY->createBoolean( item, true );
  values.push_back( item );

  s = "$expected";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  s = expected_type_name;
  GENV_ITEMFACTORY->createString( item, s );
  values.push_back( item );

  s = "$value";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  values.push_back( instance );

  s = "$reason";
  GENV_ITEMFACTORY->createString( item, s );
  keys.push_back( item );
  // TODO
  //values.push_back( xxx );

  GENV_ITEMFACTORY->createJSONObject( *result, keys, values );
}

static type const* find_builtin_atomic_type( zstring const &type_name,
                                             bool not_found_error = true ) {
  typedef map<char const*,atomic_type const*> map_type;
  static map_type m;

#define INIT_ATOMIC_TYPE(TYPE,CODE)               \
  static atomic_type instance_##TYPE;             \
  instance_##TYPE.name_ = #TYPE;                  \
  instance_##TYPE.schemaTypeCode_ = store::CODE;  \
  m[ #TYPE ] = &instance_##TYPE

  if ( m.empty() ) {
    INIT_ATOMIC_TYPE( anyURI, XS_ANY_URI );
    INIT_ATOMIC_TYPE( base64Binary, XS_BASE64BINARY );
    INIT_ATOMIC_TYPE( boolean, XS_BOOLEAN );
    INIT_ATOMIC_TYPE( date, XS_DATE );
    INIT_ATOMIC_TYPE( dateTime, XS_DATETIME );
    INIT_ATOMIC_TYPE( dateTimeStamp, XS_DATETIME_STAMP );
    INIT_ATOMIC_TYPE( dayTimeDuration, XS_DT_DURATION );
    INIT_ATOMIC_TYPE( decimal, XS_DECIMAL );
    INIT_ATOMIC_TYPE( double, XS_DOUBLE );
    INIT_ATOMIC_TYPE( duration, XS_DURATION );
    INIT_ATOMIC_TYPE( float, XS_FLOAT );
    INIT_ATOMIC_TYPE( gDay, XS_GDAY );
    INIT_ATOMIC_TYPE( gMonth, XS_GMONTH );
    INIT_ATOMIC_TYPE( gMonthDay, XS_GMONTH_DAY );
    INIT_ATOMIC_TYPE( gYear, XS_GYEAR );
    INIT_ATOMIC_TYPE( gYearMonth, XS_GYEAR_MONTH );
    INIT_ATOMIC_TYPE( hexBinary, XS_HEXBINARY );
    INIT_ATOMIC_TYPE( string, XS_STRING );
    INIT_ATOMIC_TYPE( time, XS_TIME );
    INIT_ATOMIC_TYPE( yearMonthDuration, XS_YM_DURATION );

#define INIT_ATOMIC_TYPE_BASE(TYPE,CODE,BASE)   \
  INIT_ATOMIC_TYPE(TYPE,CODE);                  \
  instance_##TYPE.baseType_ = &instance_##BASE

    INIT_ATOMIC_TYPE_BASE( integer, XS_INTEGER, decimal );
    INIT_ATOMIC_TYPE_BASE( long, XS_LONG, integer );
    INIT_ATOMIC_TYPE_BASE( int, XS_INT, long );
    INIT_ATOMIC_TYPE_BASE( short, XS_SHORT, int );
    INIT_ATOMIC_TYPE_BASE( byte, XS_BYTE, short );
    INIT_ATOMIC_TYPE_BASE( nonPositiveInteger, XS_NON_POSITIVE_INTEGER, integer );
    INIT_ATOMIC_TYPE_BASE( negativeInteger, XS_NEGATIVE_INTEGER, nonPositiveInteger );
    INIT_ATOMIC_TYPE_BASE( nonNegativeInteger, XS_NON_NEGATIVE_INTEGER, integer );
    INIT_ATOMIC_TYPE_BASE( positiveInteger, XS_POSITIVE_INTEGER, nonNegativeInteger );
    INIT_ATOMIC_TYPE_BASE( unsignedLong, XS_UNSIGNED_LONG, nonNegativeInteger );
    INIT_ATOMIC_TYPE_BASE( unsignedInt, XS_UNSIGNED_INT, unsignedLong );
    INIT_ATOMIC_TYPE_BASE( unsignedShort, XS_UNSIGNED_SHORT, unsignedInt );
    INIT_ATOMIC_TYPE_BASE( unsignedByte, XS_UNSIGNED_BYTE, unsignedShort );

#define INIT_ATOMIC_FACET(type,Type,FACET,VALUE) \
    GENV_ITEMFACTORY->create##Type( instance_##type.FACET##_, xs_##type(VALUE) )

    INIT_ATOMIC_FACET( byte, Byte, maxInclusive, 127 );
    INIT_ATOMIC_FACET( byte, Byte, minInclusive, -128 );
    INIT_ATOMIC_FACET( int, Int, maxInclusive, 2147483647 );
    INIT_ATOMIC_FACET( int, Int, minInclusive, -2147483648 );
    INIT_ATOMIC_FACET( long, Long, maxInclusive, 9223372036854775807L );
    INIT_ATOMIC_FACET( long, Long, minInclusive, -9223372036854775808L );
    INIT_ATOMIC_FACET( negativeInteger, NegativeInteger, maxInclusive, -1 );
    INIT_ATOMIC_FACET( nonNegativeInteger, NonNegativeInteger, minInclusive, 0 );
    INIT_ATOMIC_FACET( nonPositiveInteger, NonPositiveInteger, maxInclusive, 0 );
    INIT_ATOMIC_FACET( positiveInteger, PositiveInteger, minInclusive, 1 );
    INIT_ATOMIC_FACET( short, Short, maxInclusive, 32767 );
    INIT_ATOMIC_FACET( short, Short, minInclusive, -32768 );
    INIT_ATOMIC_FACET( unsignedByte, UnsignedByte, maxInclusive, 256 );
    INIT_ATOMIC_FACET( unsignedByte, UnsignedByte, minInclusive, 0 );
    INIT_ATOMIC_FACET( unsignedInt, UnsignedInt, maxInclusive, 4294967295 );
    INIT_ATOMIC_FACET( unsignedInt, UnsignedInt, minInclusive, 0 );
    INIT_ATOMIC_FACET( unsignedLong, UnsignedLong, maxInclusive, 18446744073709551615UL );
    INIT_ATOMIC_FACET( unsignedLong, UnsignedLong, minInclusive, 0 );
    INIT_ATOMIC_FACET( unsignedShort, UnsignedShort, maxInclusive, 65536 );
    INIT_ATOMIC_FACET( unsignedShort, UnsignedShort, minInclusive, 0 );

    // TODO: add facets to other types
  }

  map_type::const_iterator const i( m.find( type_name.c_str() ) );
  if ( i != m.end() )
    return i->second;
  if ( not_found_error )
    throw ZORBA_EXCEPTION( jsd::UNKNOWN_TYPE, ERROR_PARAMS( type_name ) );
  return nullptr;
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
                                    char const *key,
                                    char const *type_name = "" ) {
  store::Item_t value_item( get_value( jsd, key ) );
  if ( !value_item )
    throw ZORBA_EXCEPTION( jsd::MISSING_KEY, ERROR_PARAMS( key, type_name ) );
  return value_item;
}

inline store::Item_t require_value( store::Item_t const &jsd,
                                    char const *key,
                                    zstring const &type_name ) {
  return require_value( jsd, key, type_name.c_str() );
}

inline int to_xs_int( store::Item_t const &item ) {
  return to_xs_int( item->getIntegerValue() );
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

ostream& operator<<( ostream &os, timezone::type tz ) {
  using namespace timezone;
  switch ( tz ) {
    case prohibited : return os << "prohibited";
    case required   : return os << "required";
    case optional   : return os << "optional";
    default         : return os << "unknown (" << (int)tz << ')';
  }
}

///////////////////////////////////////////////////////////////////////////////

array_type::array_type() : min_max_type( k_array ) {
  content_ = nullptr;
}

void array_type::assert_subtype_of( type const *t ) const {
  DECL_cast_t( array );
  content_->assert_subtype_of( cast_t->content_ );
  ASSERT_SUBTYPE_FACET( maxLength, array, dt->maxLength_ <= bt->maxLength_ );
  ASSERT_SUBTYPE_FACET( minLength, array, dt->minLength_ >= bt->minLength_ );
}

void array_type::load_content( store::Item_t const &content_item, schema &s ) {
  ASSERT_KIND( content_item, "$content", ARRAY );
  if ( content_item->getArraySize() != numeric_consts<xs_integer>::one() )
    throw ZORBA_EXCEPTION( jsd::ILLEGAL_ARRAY_SIZE );
  store::Item_t const type_item(
    content_item->getArrayValue( numeric_consts<xs_integer>::one() )
  );
  content_ = s.find_or_create_type( type_item );
}

void array_type::load_type( store::Item_t const &type_item, schema &s ) {
  ASSERT_KIND( type_item, "$type", OBJECT );
  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key_str( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( ZSTREQ( key_str, "$baseType" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$constraints" ) )
      load_constraints( value_item );
    else if ( ZSTREQ( key_str, "$content" ) )
      load_content( value_item, s );
    else if ( ZSTREQ( key_str, "$enumeration" ) )
      load_enumeration( value_item );
    else if ( ZSTREQ( key_str, "$maxLength" ) )
      load_maxLength( value_item );
    else if ( ZSTREQ( key_str, "$minLength" ) )
      load_minLength( value_item );
    else if ( ZSTREQ( key_str, "$kind" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$name" ) )
      /* already handled */;
    else
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_KEY, ERROR_PARAMS( key_str, "$type" )
      );
  } // while
  it->close();
  if ( !content_ ) {
    if ( !baseType_ )
      throw ZORBA_EXCEPTION(
        jsd::MISSING_KEY,
        ERROR_PARAMS( "$content", name_, ZED( MISSING_KEY_NoInherit ) )
      );
    DECL_baseType( array );
    content_ = baseType->content_;
  }
}

bool array_type::annotate( store::Item_t const &array_item,
                           store::Item_t *result ) const {
#if 0
  ASSERT_KIND( array_item, name_, ARRAY );

  int length = -1;
  if ( HAS_FACET( minLength ) || HAS_FACET( maxLength ) )
    length = to_xs_int( array_item->getArraySize() );
  if ( !ABIDE_FACET( minLength, length >= minLength_ ) ) {
    // TODO
    return false;
  }
  if ( !ABIDE_FACET( maxLength, length <= maxLength_ ) ) {
    // TODO
    return false;
  }

  store::Iterator_t it( array_item->getArrayValues() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    store::Item_t temp;
    content_->annotate( item, &temp );
    // TODO: do something with temp
  }
  it->close();
#endif
  return true;
}

bool array_type::validate( store::Item_t const &array_item ) const {
  ASSERT_KIND( array_item, name_, ARRAY );

  DECL_FACET_type( this, array, maxLength );
  DECL_FACET_type( this, array, minLength );
  int length;
  if ( minLength_type || maxLength_type )
    length = to_xs_int( array_item->getArraySize() );
  VALIDATE_FACET( maxLength, length <= maxLength_type->maxLength_ );
  VALIDATE_FACET( minLength, length >= minLength_type->minLength_ );

  store::Iterator_t it( array_item->getArrayValues() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) )
    if ( !content_->validate( item ) )
      return false;
  it->close();
  return true;
}

///////////////////////////////////////////////////////////////////////////////

atomic_type::atomic_type() : min_max_type( k_atomic ) {
  explicitTimezone_ = timezone::optional;
}

void atomic_type::assert_min_max_facet( store::Item_t const &item,
                                        char const *facet_name ) const {
  switch ( schemaTypeCode_ ) {
    case store::XS_DATE:
    case store::XS_DATETIME:
    case store::XS_DOUBLE:
    case store::XS_DURATION:
    case store::XS_FLOAT:
    case store::XS_GDAY:
    case store::XS_GMONTH:
    case store::XS_GMONTH_DAY:
    case store::XS_GYEAR:
    case store::XS_GYEAR_MONTH:
    case store::XS_TIME:
      break;
    default:
      if ( !IS_SUBTYPE( schemaTypeCode_, XS_DECIMAL ) )
        throw ZORBA_EXCEPTION(
          jsd::ILLEGAL_FACET, ERROR_PARAMS( facet_name, schemaTypeCode_ )
        );
  }
  assert_type( item, facet_name, schemaTypeCode_ );
}

void atomic_type::assert_subtype_of( type const *t ) const {
  DECL_cast_t( atomic );
  if ( !TypeOps::is_subtype( schemaTypeCode_, cast_t->schemaTypeCode_ ) )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_BASE_TYPE,
      ERROR_PARAMS(
        t->name_, name_, ZED( ILLEGAL_BASE_TYPE_NotSubtype ),
        schemaTypeCode_, cast_t->schemaTypeCode_
      )
    );

  ASSERT_SUBTYPE_FACET( maxExclusive, atomic,
    dt->maxExclusive_->compare( bt->maxExclusive_ ) <= 0 );
  ASSERT_SUBTYPE_FACET( maxInclusive, atomic,
    dt->maxInclusive_->compare( bt->maxInclusive_ ) <= 0 );
  ASSERT_SUBTYPE_FACET( minExclusive, atomic,
    dt->minExclusive_->compare( bt->minExclusive_ ) >= 0 );
  ASSERT_SUBTYPE_FACET( minInclusive, atomic,
    dt->minInclusive_->compare( bt->minInclusive_ ) >= 0 );

  ASSERT_SUBTYPE_FACET( minLength, atomic, dt->minLength_ >= bt->minLength_ );
  ASSERT_SUBTYPE_FACET( maxLength, atomic, dt->maxLength_ <= bt->maxLength_ );
  ASSERT_SUBTYPE_FACET( length, atomic, dt->length_ == bt->length_ );
  ASSERT_SUBTYPE_FACET( totalDigits, atomic,
    dt->totalDigits_ < bt->totalDigits_ );
  ASSERT_SUBTYPE_FACET( fractionDigits, atomic,
    dt->fractionDigits_ < bt->fractionDigits_ );
  ASSERT_SUBTYPE_FACET( explicitTimezone, atomic,
    dt->explicitTimezone_ == bt->explicitTimezone_ ||
    bt->explicitTimezone_ == timezone::optional
  );
}

void atomic_type::load_baseType( store::Item_t const &baseType_item,
                                 schema const &s ) {
  if ( !baseType_item )
    throw ZORBA_EXCEPTION(
      jsd::MISSING_KEY, ERROR_PARAMS( "$baseType", name_ )
    );
  type::load_baseType( baseType_item, s );
  DECL_baseType( atomic );
  schemaTypeCode_ = baseType ?
    baseType->schemaTypeCode_ :
    map_atomic_type( baseType_item->getStringValue() );
}

void atomic_type::load_explicitTimezone( store::Item_t const &eTz_item ) {
  ASSERT_TYPE( eTz_item, "$explicitTimezone", XS_STRING );
  switch ( schemaTypeCode_ ) {
    case store::XS_DATE:
    case store::XS_DATETIME:
    case store::XS_TIME:
      break;
    default:
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_FACET, ERROR_PARAMS( "$explicitTimezone", schemaTypeCode_ )
      );
  }
  zstring const eTz_str( eTz_item->getStringValue() );
  if ( ZSTREQ( eTz_str, "optional" ) )
    explicitTimezone_ = timezone::optional;
  else if ( ZSTREQ( eTz_str, "prohibited" ) )
    explicitTimezone_ = timezone::prohibited;
  else if ( ZSTREQ( eTz_str, "required" ) )
    explicitTimezone_ = timezone::required;
  else
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_FACET_VALUE,
      ERROR_PARAMS(
        eTz_str, "$explicitTimezone",
        ZED( ILLEGAL_FACET_VALUE_MustBeOPR )
      )
    );
  DECL_FACET_type( this, atomic, explicitTimezone );
  ASSERT_BASE_FACET( explicitTimezone,
    explicitTimezone_ == explicitTimezone_type->explicitTimezone_ ||
    explicitTimezone_type->explicitTimezone_ == timezone::optional
  );
  ADD_FACET( explicitTimezone );
}

void atomic_type::load_fractionDigits( store::Item_t const &fDigits_item ) {
  ASSERT_TYPE( fDigits_item, "$fractionDigits", XS_INTEGER );
  if ( schemaTypeCode_ != store::XS_DECIMAL )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_FACET, ERROR_PARAMS( "$fractionDigits", schemaTypeCode_ )
    );
  fractionDigits_ = to_xs_int( fDigits_item );
  if ( fractionDigits_ < 0 )
    throw FACET_VALUE_EXCEPTION( fractionDigits, MustBeGE0 );
  DECL_FACET_type( this, atomic, fractionDigits );
  ASSERT_BASE_FACET( fractionDigits,
    fractionDigits_ <= fractionDigits_type->fractionDigits_ );
  ADD_FACET( fractionDigits );
}

void atomic_type::load_length( store::Item_t const &length_item ) {
  ASSERT_TYPE( length_item, "$length", XS_INTEGER );
  switch ( schemaTypeCode_ ) {
    case store::XS_ANY_URI:
    case store::XS_BASE64BINARY:
    case store::XS_HEXBINARY:
    case store::XS_STRING:
      break;
    default:
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_FACET, ERROR_PARAMS( "$length", schemaTypeCode_ )
      );
  }
  length_ = to_xs_int( length_item );
  if ( length_ < 0 )
    throw FACET_VALUE_EXCEPTION( length, MustBeGE0 );
  DECL_FACET_type( this, atomic, length );
  ASSERT_BASE_FACET( length, length_ <= length_type->length_ );
  ADD_FACET( length );
}

void atomic_type::load_maxExclusive( store::Item_t const &maxExclusive_item ) {
  assert_min_max_facet( maxExclusive_item, "$maxExclusive" );
  maxExclusive_ = maxExclusive_item;
  DECL_FACET_type( this, atomic, maxExclusive );
  ASSERT_BASE_FACET( maxExclusive,
    maxExclusive_->compare( maxExclusive_type->maxExclusive_ ) <= 0 );
  // TODO: check against this->maxInclusive_
  // TODO: check against baseType->maxInclusive_
  ADD_FACET( maxExclusive );
}

void atomic_type::load_maxInclusive( store::Item_t const &maxInclusive_item ) {
  assert_min_max_facet( maxInclusive_item, "$maxInclusive" );
  maxInclusive_ = maxInclusive_item;
  DECL_FACET_type( this, atomic, maxInclusive );
  ASSERT_BASE_FACET( maxInclusive,
    maxInclusive_->compare( maxInclusive_type->maxInclusive_ ) <= 0 );
  // TODO: check against this->maxExclusive_
  // TODO: check against baseType->maxExclusive_
  ADD_FACET( maxInclusive );
}

void atomic_type::load_minExclusive( store::Item_t const &minExclusive_item ) {
  assert_min_max_facet( minExclusive_item, "$minExclusive" );
  minExclusive_ = minExclusive_item;
  DECL_FACET_type( this, atomic, minExclusive );
  ASSERT_BASE_FACET( minExclusive,
    minExclusive_->compare( minExclusive_type->minExclusive_ ) >= 0 );
  // TODO: check against this->maxInclusive_
  // TODO: check against baseType->maxInclusive_
  ADD_FACET( minExclusive );
}

void atomic_type::load_minInclusive( store::Item_t const &minInclusive_item ) {
  assert_min_max_facet( minInclusive_item, "$minInclusive" );
  minInclusive_ = minInclusive_item;
  DECL_FACET_type( this, atomic, minInclusive );
  ASSERT_BASE_FACET( minInclusive,
    minInclusive_->compare( minInclusive_type->minInclusive_ ) >= 0 );
  // TODO: check against this->minExclusive_
  // TODO: check against baseType->minExclusive_
  ADD_FACET( minInclusive );
}

void atomic_type::load_pattern( store::Item_t const &pattern_item ) {
  ASSERT_TYPE( pattern_item, "$pattern", XS_STRING );
  zstring const xquery_re( pattern_item->getStringValue() );
  try {
    convert_xquery_re( xquery_re, &pattern_ );
    pattern_re_.compile( pattern_ );
  }
  catch ( ZorbaException const &e ) {
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_FACET_VALUE,
      ERROR_PARAMS(
        xquery_re, "$pattern", ZED( ILLEGAL_FACET_VALUE_BadPattern ),
        e.diagnostic().qname(),
        e.what()
      )
    );
  }
  ADD_FACET( pattern );
}

void atomic_type::load_totalDigits( store::Item_t const &totalDigits_item ) {
  ASSERT_TYPE( totalDigits_item, "$totalDigits", XS_INTEGER );
  if ( !IS_SUBTYPE( schemaTypeCode_, XS_DECIMAL ) )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_FACET, ERROR_PARAMS( "$totalDigits", schemaTypeCode_ )
    );
  totalDigits_ = to_xs_int( totalDigits_item );
  if ( totalDigits_ < 0 )
    throw FACET_VALUE_EXCEPTION( totalDigits, MustBeGE0 );
  DECL_FACET_type( this, atomic, totalDigits );
  ASSERT_BASE_FACET( totalDigits,
    totalDigits_ <= totalDigits_type->totalDigits_ );
  ADD_FACET( totalDigits );
}

void atomic_type::load_type( store::Item_t const &type_item, schema &s ) {
  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key_str( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( ZSTREQ( key_str, "$about" ) )
      load_about( value_item );
    else if ( ZSTREQ( key_str, "$baseType" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$constraints" ) )
      load_constraints( value_item );
    else if ( ZSTREQ( key_str, "$enumeration" ) )
      load_enumeration( value_item );
    else if ( ZSTREQ( key_str, "$explicitTimezone" ) )
      load_explicitTimezone( value_item );
    else if ( ZSTREQ( key_str, "$fractionDigits" ) )
      load_fractionDigits( value_item );
    else if ( ZSTREQ( key_str, "$kind" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$length" ) )
      load_length( value_item );
    else if ( ZSTREQ( key_str, "$maxExclusive" ) )
      load_maxExclusive( value_item );
    else if ( ZSTREQ( key_str, "$maxInclusive" ) )
      load_maxInclusive( value_item );
    else if ( ZSTREQ( key_str, "$maxLength" ) )
      load_maxLength( value_item );
    else if ( ZSTREQ( key_str, "$minExclusive" ) )
      load_minExclusive( value_item );
    else if ( ZSTREQ( key_str, "$minInclusive" ) )
      load_minInclusive( value_item );
    else if ( ZSTREQ( key_str, "$minLength" ) )
      load_minLength( value_item );
    else if ( ZSTREQ( key_str, "$name" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$pattern" ) )
      load_pattern( value_item );
    else if ( ZSTREQ( key_str, "$totalDigits" ) )
      load_totalDigits( value_item );
    else
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_KEY, ERROR_PARAMS( key_str, "$type" )
      );
  } // while
  it->close();
}

bool atomic_type::annotate( store::Item_t const &item,
                            store::Item_t *result ) const {
#if 0
  if ( !is_atomic_type( item, schemaTypeCode_ ) ) {
    create_invalid( name_, item, result );
    return false;
  }

  int length;
  if ( HAS_FACET( length ) ) {
    length = item->getStringValue().length();
    VALIDATE_FACET( length, length == length_ );
  }

  VALIDATE_FACET( maxExclusive, item->compare( maxExclusive_ ) <  0 );
  VALIDATE_FACET( maxInclusive, item->compare( maxInclusive_ ) <= 0 );
  VALIDATE_FACET( minExclusive, item->compare( minExclusive_ ) >  0 );
  VALIDATE_FACET( minInclusive, item->compare( minInclusive_ ) >= 0 );

  zstring item_str;
  zstring::size_type dot;
  if ( HAS_FACET( totalDigits ) || HAS_FACET( fractionDigits ) ) {
    item_str = item->toString();
    length = item_str.length();
    dot = item_str.find( '.' );
  }

  if ( HAS_FACET( totalDigits ) ) {
    int const digits = length - (dot != zstring::npos);
    VALIDATE_FACET( totalDigits, digits == totalDigits_ );
  }
  if ( HAS_FACET( fractionDigits ) ) {
    int const digits = dot == zstring::npos ? 0 : length - dot - 1;
    VALIDATE_FACET( fractionDigits, digits == fractionDigits_ );
  }

  // TODO: explicitTimezone
  // TODO: pattern
#endif
  return true;
}

bool atomic_type::validate( store::Item_t const &item ) const {
  assert_type( item, name_, schemaTypeCode_ );
  zstring str;
  int length;

  DECL_FACET_type( this, atomic, length );
  DECL_FACET_type( this, atomic, totalDigits );
  DECL_FACET_type( this, atomic, fractionDigits );

  if ( length_type || totalDigits_type || fractionDigits_type ) {
    str = item->getStringValue();
    length = str.length();
  }

  if ( length_type )
    VALIDATE_FACET( length, length == length_ );

  if ( DECL_FACET_type( this, atomic, maxExclusive ) )
    VALIDATE_FACET( maxExclusive,
      item->compare( maxExclusive_type->maxExclusive_ ) <  0 );

  if ( DECL_FACET_type( this, atomic, maxInclusive ) )
    VALIDATE_FACET( maxInclusive,
      item->compare( maxInclusive_type->maxInclusive_ ) <= 0 );

  if ( DECL_FACET_type( this, atomic, minExclusive ) )
    VALIDATE_FACET( minExclusive,
      item->compare( minExclusive_type->minExclusive_ ) >  0 );

  if ( DECL_FACET_type( this, atomic, minInclusive ) )
    VALIDATE_FACET( minInclusive,
      item->compare( minInclusive_type->minInclusive_ ) >= 0 );

  zstring::size_type dot;
  if ( totalDigits_type || fractionDigits_type )
    dot = str.find( '.' );

  if ( totalDigits_type ) {
    int const digits = length - (dot != zstring::npos);
    VALIDATE_FACET( totalDigits, digits == totalDigits_type->totalDigits_ );
  }
  if ( fractionDigits_type ) {
    int const digits = dot == zstring::npos ? 0 : length - dot - 1;
    VALIDATE_FACET( fractionDigits,
      digits == fractionDigits_type->fractionDigits_ );
  }

  if ( DECL_FACET_type( this, atomic, pattern ) ) {
    if ( str.empty() )
      str = item->getStringValue();
    VALIDATE_FACET( pattern, pattern_type->pattern_re_.match_whole( str ) );
  }

  if ( DECL_FACET_type( this, atomic, explicitTimezone ) ) {
    timezone::type const tz = explicitTimezone_type->explicitTimezone_;
    if ( tz != timezone::optional ) {
      xs_time const &time = item->getTimeValue();
      VALIDATE_FACET( explicitTimezone,
        tz == timezone::required   &&  time.hasTimezone() ||
        tz == timezone::prohibited && !time.hasTimezone()
      );
    }
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////

min_max_type::min_max_type( kind k ) : type( k ) {
  facet_mask_ = 0;
}

void min_max_type::load_maxLength( store::Item_t const &maxLength_item ) {
  ASSERT_TYPE( maxLength_item, "$maxLength", XS_INTEGER );
  maxLength_ = to_xs_int( maxLength_item );
  if ( maxLength_ < 0 )
    throw FACET_VALUE_EXCEPTION( maxLength, MustBeGE0 );
  DECL_FACET_type( this, min_max, maxLength );
  ASSERT_BASE_FACET( maxLength, maxLength_ <= maxLength_type->maxLength_ );
  ADD_FACET( maxLength );
}

void min_max_type::load_minLength( store::Item_t const &minLength_item ) {
  ASSERT_TYPE( minLength_item, "$minLength", XS_INTEGER );
  minLength_ = to_xs_int( minLength_item );
  if ( minLength_ < 0 )
    throw FACET_VALUE_EXCEPTION( minLength, MustBeGE0 );
  DECL_FACET_type( this, min_max, minLength );
  ASSERT_BASE_FACET( minLength, minLength_ >= minLength_type->minLength_ );
  ADD_FACET( minLength );
}

///////////////////////////////////////////////////////////////////////////////

object_type::field_descriptor::field_descriptor() {
  type_ = nullptr;
  optional_ = false;
}

void object_type::field_descriptor::
load_default( store::Item_t const &default_item ) {
  assert_type_matches( default_item, type_, "$default" );
  default_ = default_item;
}

void object_type::field_descriptor::
load_optional( store::Item_t const &optional_item ) {
  ASSERT_TYPE( optional_item, "$optional", XS_BOOLEAN );
  optional_ = optional_item->getBooleanValue();
}

void object_type::field_descriptor::
load_type( store::Item_t const &type_item, schema &s ) {
  type_ = s.find_or_create_type( type_item );
}

object_type::object_type() : type( k_object ) {
  open_ = true;
}

void object_type::assert_subtype_of( type const *t ) const {
  DECL_cast_t( object );
  ASSERT_SUBTYPE_FACET( open, object, dt->open_ || !bt->open_ );
  object_type const *const open_type = FIND_FACET( this, object, open );
  bool const open = open_type ? open_type->open_ : true;

  FOR_EACH( content_type, i, content_ ) {
    key_type const &key = i->first;
    field_descriptor const &fd = i->second;
    content_type::const_iterator const t_i( cast_t->content_.find( key ) );
    if ( t_i != cast_t->content_.end() ) {
      field_descriptor const &t_fd = t_i->second;
      if ( fd.optional_ && !t_fd.optional_ )
        throw ZORBA_EXCEPTION(
          jsd::ILLEGAL_FACET_VALUE,
          ERROR_PARAMS(
            "false", "$optional",
            ZED( ILLEGAL_FACET_VALUE_NoOverrideBase ),
            cast_t->name_
          )
        );
      fd.type_->assert_subtype_of( t_fd.type_ );
    } else if ( !open )
      throw ZORBA_EXCEPTION(
        jsd::NEW_KEY_NOT_ALLOWED,
        ERROR_PARAMS( key, cast_t->name_ )
      );
  }
}

void object_type::load_content( store::Item_t const &content_item, schema &s ) {
  ASSERT_KIND( content_item, "$content", OBJECT );
  store::Iterator_t it( content_item->getObjectKeys() );
  store::Item_t key_item;
  it->open();
  while ( it->next( key_item ) ) {
    // key_item is guaranteed to be a string by JSON syntax
    zstring const key_str( key_item->getStringValue() );
    // duplicate keys in the same object are checked for by JSON semantics
    field_descriptor &fd = content_[ key_str ];
    load_field_descriptor( content_item->getObjectValue( key_item ), s, &fd );

    for ( type const *t = baseType_; t; t = t->baseType_ ) {
      DECL_baseType( object );
      content_type::const_iterator bt_i( baseType->content_.find( key_str ) );
      if ( bt_i != baseType->content_.end() )
        fd.type_->assert_subtype_of( bt_i->second.type_ );
      else if ( !baseType->open_ )
        throw ZORBA_EXCEPTION(
          jsd::NEW_KEY_NOT_ALLOWED,
          ERROR_PARAMS( key_str, baseType->name_ )
        );
    } // for
  } // while
  it->close();
}

void object_type::load_field_descriptor( store::Item_t const &field_item,
                                         schema &s, field_descriptor *fd ) {
  ASSERT_KIND( field_item, "field descriptor", OBJECT );
  store::Item_t const type_item( require_value( field_item, "$type", name_ ) );
  fd->load_type( type_item, s );

  store::Iterator_t it( field_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key_str( item->getStringValue() );
    store::Item_t const value_item( field_item->getObjectValue( item ) );
    if ( ZSTREQ( key_str, "$default" ) )
      fd->load_default( value_item );
    else if ( ZSTREQ( key_str, "$optional" ) )
      fd->load_optional( value_item );
    else if ( ZSTREQ( key_str, "$type" ) )
      /* already handled */;
    else
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_KEY, ERROR_PARAMS( key_str, "field descriptor" )
      );
  } // while
  it->close();
}

void object_type::load_open( store::Item_t const &open_item ) {
  ASSERT_TYPE( open_item, "$open", XS_BOOLEAN );
  open_ = open_item->getBooleanValue();
  DECL_FACET_type( this, object, open );
  if ( open_type && !open_type->open_ && open_ ) {
    //
    // JSound 5.4: The $open Facet behaves like most Facets, i.e., if that of
    // the Base Type is false, it cannot be set back to true, otherwise
    // jsd:JDST0007 is raised.
    //
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_FACET_VALUE,
      ERROR_PARAMS(
        "true", "$open", ZED( ILLEGAL_FACET_VALUE_NoOverrideBase ), "false"
      )
    );
  }
  ADD_FACET( open );
}

void object_type::load_type( store::Item_t const &type_item, schema &s ) {
  store::Item_t const content_item(
    require_value( type_item, "$content", name_ )
  );
  load_content( content_item, s );
  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key_str( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( ZSTREQ( key_str, "$baseType" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$constraints" ) )
      load_constraints( value_item );
    else if ( ZSTREQ( key_str, "$content" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$enumeration" ) )
      load_enumeration( value_item );
    else if ( ZSTREQ( key_str, "$kind" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$name" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$open" ) )
      load_open( value_item );
    else
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_KEY, ERROR_PARAMS( key_str, "$type" )
      );
  } // while
  it->close();
}

bool object_type::annotate( store::Item_t const &object_item,
                            store::Item_t *result ) const {
  // TODO
  return false;
}

bool object_type::validate( store::Item_t const &object_item ) const {
  ASSERT_KIND( object_item, name_, OBJECT );

  typedef unordered_set<zstring> seen_type;
  seen_type seen;

  DECL_FACET_type( this, object, open );
  bool const open = open_type ? open_type->open_ : true;

  // check each key in the given object against this type
  store::Iterator_t it( object_item->getObjectKeys() );
  store::Item_t key_item;
  it->open();
  while ( it->next( key_item ) ) {
    zstring const key_str( key_item->getStringValue() );
    content_type::const_iterator const i( content_.find( key_str ) );
    if ( i == content_.end() ) {        // new key
      if ( !open )
        return false;
      continue;
    }

    store::Item_t const value_item( object_item->getObjectValue( key_item ) );
    field_descriptor const &fd = i->second;
    fd.type_->validate( value_item );   // validate key's value

    seen.insert( key_str );
  } // while
  it->close();

  //
  // Check each key in this type against the given object: look for keys that
  // aren't present that are not optional.
  //
  FOR_EACH( content_type, i, content_ ) {
    zstring const &key_str = i->first;
    field_descriptor const &fd = i->second;
    seen_type::const_iterator const j( seen.find( key_str ) );
    if ( j == seen.end() && !fd.optional_ )
      return false;
  } // FOR_EACH

  return true;
}

///////////////////////////////////////////////////////////////////////////////

type::type( kind k ) : kind_( k ) {
  baseType_ = nullptr;
}

type::~type() {
  // out-of-line since it's virtual
}

type const* type::find_facet( facet_mask facet ) const {
  for ( type const *t = this; t; t = t->baseType_ )
    if ( t->facet_mask_ & facet )
      return t;
  return nullptr;
}

void type::load_about( store::Item_t const &about_item ) {
  ASSERT_TYPE( about_item, "$about", XS_STRING );
  about_ = about_item->getStringValue();
}

void type::load_baseType( store::Item_t const &baseType_item,
                          schema const &s ) {
  if ( !baseType_item )
    return;
  ASSERT_TYPE( baseType_item, "$baseType", XS_STRING );
  zstring const baseType_str( baseType_item->getStringValue() );
  if ( kind const k = find_kind( baseType_str ) ) {
    //
    // The case where the kind of the base type of "array", "atomic", "object",
    // or "union" is specified explicitly ...
    //
    if ( k != kind_ ) {
      //
      // ... and does NOT match the kind of this type.
      //
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_BASE_TYPE,
        ERROR_PARAMS( k, name_, ZED( ILLEGAL_BASE_TYPE_MustBeX ), kind_ )
      );
    }
    return;
  }

  zstring fq_baseType_str( baseType_str );
  type const *const bt = s.fq_find_type( &fq_baseType_str );

  if ( bt->kind_ != kind_ )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_BASE_TYPE,
      ERROR_PARAMS(
        fq_baseType_str, name_, ZED( ILLEGAL_BASE_TYPE_MustBeX ), kind_
      )
    );
  baseType_ = bt;
}

void type::load_constraints( store::Item_t const &constraints_item ) {
  ASSERT_KIND( constraints_item, "$constraints", ARRAY );

  CompilerCB ccb( nullptr );
  store::Iterator_t it( constraints_item->getArrayValues() );
  store::Item_t item;
  zstring const no_filename;
  XQueryCompiler xc( &ccb );

  it->open();
  while ( it->next( item ) ) {
    ASSERT_TYPE( item, "constraint", XS_STRING );
    zstring const constraint( item->getStringValue() );
    try {
      // TODO: add explicit language parameter to XQueryCompiler::parse()
      string temp( "jsoniq version \"1.0\";" );
      temp += constraint.c_str();
      istringstream iss( temp );
      xc.parseOnly( iss, no_filename );
      constraints_.values_.push_back( constraint );
    }
    catch ( ZorbaException const &e ) {
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_CONSTRAINT,
        ERROR_PARAMS( constraint, e.diagnostic().qname(), e.what() )
      );
    }
  } // while
  it->close();
  ADD_FACET( constraints );
}

void type::load_enumeration( store::Item_t const &enumeration_item ) {
  ASSERT_KIND( enumeration_item, "$enumeration", ARRAY );
  store::Iterator_t it( enumeration_item->getArrayValues() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    assert_type_matches( item, baseType_ );
    if ( type const *const t = FIND_FACET( this, type, enumeration ) ) {
      bool found = false;
      FOR_EACH( enumeration::content_type, i, t->enumeration_.values_ ) {
        if ( item->compare( *i ) == 0 ) {
          found = true;
          break;
        }
      }
      if ( !found )
        throw ZORBA_EXCEPTION(
          jsd::ILLEGAL_FACET_VALUE,
          ERROR_PARAMS(
            item->toString(), "$enumeration",
            ZED( ILLEGAL_FACET_VALUE_NoAddEnum ),
            t->name_
          )
        );
    }
    enumeration_.values_.push_back( item );
  } // while
  it->close();
  ADD_FACET( enumeration );
}

void type::load_name( store::Item_t const &name_item, schema const &s ) {
  ASSERT_TYPE( name_item, "$name", XS_STRING );
  zstring fq_name_str( name_item->getStringValue() );
  zstring uri;
  s.fq_type_name( &fq_name_str, &uri );
  if ( !uri.empty() && uri != s.get_namespace() )
    throw ZORBA_EXCEPTION(
      jsd::ILLEGAL_NAMESPACE,
      ERROR_PARAMS( fq_name_str, s.get_namespace() )
    );
  if ( s.find_type( fq_name_str, false ) )
    throw ZORBA_EXCEPTION( jsd::DUPLICATE_TYPE, ERROR_PARAMS( fq_name_str ) );
  name_ = fq_name_str;
}

///////////////////////////////////////////////////////////////////////////////

union_type::union_type() : type( k_union ) {
}

void union_type::assert_subtype_of( type const *t ) const {
  DECL_cast_t( union ); // TODO: is this correct?
  FOR_EACH( content_type, u, content_ )
    (*u)->assert_subtype_of( t );
}

void union_type::load_content( store::Item_t const &content_item, schema &s ) {
  ASSERT_KIND( content_item, "$content", ARRAY );
  store::Iterator_t it( content_item->getArrayValues() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) )
    content_.push_back( s.find_or_create_type( item ) );
  it->close();
}

void union_type::load_type( store::Item_t const &type_item, schema &s ) {
  ASSERT_KIND( type_item, "$type", OBJECT );
  load_content( require_value( type_item, "$content", name_ ), s );
  store::Iterator_t it( type_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key_str( item->getStringValue() );
    store::Item_t const value_item( type_item->getObjectValue( item ) );
    if ( ZSTREQ( key_str, "$constraints" ) )
      load_constraints( value_item );
    else if ( ZSTREQ( key_str, "$content" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$enumeration" ) )
      load_enumeration( value_item );
    else if ( ZSTREQ( key_str, "$kind" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$name" ) )
      /* already handled */;
    else
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_KEY, ERROR_PARAMS( key_str, "$type" )
      );
  } // while
  it->close();
}

bool union_type::annotate( store::Item_t const &item,
                           store::Item_t *result ) const {
  // TODO
  return true;
}

bool union_type::validate( store::Item_t const &item ) const {
  // TODO
  return true;
}

///////////////////////////////////////////////////////////////////////////////

schema::schema( store::Item_t const &jsd_item ) {
  ASSERT_KIND( jsd_item, "JSound", OBJECT );
  load_namespace( require_value( jsd_item, "$namespace" ) );
  store::Item_t item( get_value( jsd_item, "$imports" ) );
  if ( !!item )
    load_imports( item );
  load_types( require_value( jsd_item, "$types" ) );
}

schema::~schema() {
  ztd::delete_ptr_seq( types_ );
}

type const* schema::find_or_create_type( store::Item_t const &type_item ) {
  if ( IS_ATOMIC_TYPE( type_item, XS_STRING ) ) {
    zstring fq_name_str( type_item->getStringValue() );
    return fq_find_type( &fq_name_str );
  }
  if ( IS_KIND( type_item, OBJECT ) )
    return load_type( type_item ).release();
  throw ZORBA_EXCEPTION(
    jsd::ILLEGAL_TYPE,
    ERROR_PARAMS( type_item->getKind(), "$content", "string", "object" )
  );
}

type const* schema::find_type( zstring const &type_name,
                               bool not_found_error ) const {
  if ( type const *const t = find_builtin_atomic_type( type_name, false ) )
    return t;
  if ( type_name.compare( 0, 2, "Q{" ) == 0 ) {
    name_type_map::const_iterator const i( name_type_.find( type_name ) );
    if ( i != name_type_.end() )
      return i->second;
  }
  if ( not_found_error )
    throw ZORBA_EXCEPTION( jsd::UNKNOWN_TYPE, ERROR_PARAMS( type_name ) );
  return nullptr;
}

type const* schema::fq_find_type( zstring *type_name,
                                  bool not_found_error ) const {
  fq_type_name( type_name );
  return find_type( *type_name, not_found_error );
}

void schema::fq_type_name( zstring *type_name, zstring *uri ) const {
  zstring prefix, local, func_local_uri;
  if ( !uri )
    uri = &func_local_uri;

  if ( xml::split_qname( *type_name, &prefix, &local ) && !prefix.empty() ) {
    prefix_namespace_map::const_iterator const i( prefix_ns_.find( prefix ) );
    if ( i == prefix_ns_.end() )
      throw ZORBA_EXCEPTION( jsd::UNKNOWN_PREFIX, ERROR_PARAMS( prefix ) );
    *type_name = "Q{" + i->second + '}' + local;
  } else if ( xml::split_uri_name( *type_name, uri, &local ) ) {
    // Do nothing since type_name is already a URIQualifiedName.
  } else {
    if ( !find_builtin_atomic_type( *type_name, false ) )
      *type_name = "Q{" + namespace_ + '}' + *type_name;
  }
}

void schema::load_import( store::Item_t const &import_item ) {
  ASSERT_KIND( import_item, "import", OBJECT );

  store::Item_t const ns_item( require_value( import_item, "$namespace" ) );
  ASSERT_TYPE( ns_item, "$namespace", XS_STRING );

  store::Item_t const prefix_item( require_value( import_item, "$prefix" ) );
  ASSERT_TYPE( prefix_item, "$prefix", XS_STRING );

  store::Iterator_t it( import_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key_str( item->getStringValue() );
    store::Item_t const value_item( import_item->getObjectValue( item ) );
    if ( ZSTREQ( key_str, "$location" ) ) {
      ASSERT_TYPE( item, "$location", XS_STRING );
      // TODO: use location to locate the schema document
    } else if ( ZSTREQ( key_str, "$name" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$prefix" ) )
      /* already handled */;
    else
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_KEY, ERROR_PARAMS( key_str, "import" )
      );
  } // while
  it->close();

  zstring const prefix_str( prefix_item->getStringValue() );
  if ( prefix_str.find( ':' ) != zstring::npos )
    throw ZORBA_EXCEPTION( jsd::ILLEGAL_PREFIX, ERROR_PARAMS( prefix_str ) );
  if ( ztd::contains( prefix_ns_, prefix_str ) )
    throw ZORBA_EXCEPTION( jsd::DUPLICATE_PREFIX, ERROR_PARAMS( prefix_str ) );
  prefix_ns_[ prefix_str ] = ns_item->getStringValue();

  // TODO: import the schema
}

void schema::load_imports( store::Item_t const &imports_item ) {
  ASSERT_KIND( imports_item, "$imports", ARRAY );
  store::Iterator_t it( imports_item->getArrayValues() );
  store::Item_t import_item;
  it->open();
  while ( it->next( import_item ) )
    load_import( import_item );
  it->close();
}

unique_ptr<type> schema::load_kind( store::Item_t const &kind_item ) {
  ASSERT_TYPE( kind_item, "$kind", XS_STRING );
  zstring const kind_str( kind_item->getStringValue() );
  switch ( find_kind( kind_str ) ) {
    case k_atomic: return unique_ptr<type>( new atomic_type );
    case k_array : return unique_ptr<type>( new array_type  );
    case k_object: return unique_ptr<type>( new object_type );
    case k_union : return unique_ptr<type>( new union_type  );
    default:
      throw ZORBA_EXCEPTION(
        jsd::ILLEGAL_VALUE, ERROR_PARAMS( kind_str, "$kind" )
      );
  } // switch
}

void schema::load_namespace( store::Item_t const &namespace_item ) {
  ASSERT_TYPE( namespace_item, "$namespace", XS_STRING );
  namespace_ = namespace_item->getStringValue();
}

void schema::load_top_type( store::Item_t const &type_item ) {
  store::Item_t const name_item( require_value( type_item, "$name" ) );
  unique_ptr<type> t( load_type( type_item ) );
  zstring fq_name_str( name_item->getStringValue() );
  fq_type_name( &fq_name_str );
  name_type_[ fq_name_str ] = t.get();
  t.release();
}

unique_ptr<type> schema::load_type( store::Item_t const &type_item ) {
  store::Item_t const kind_item( require_value( type_item, "$kind" ) );
  unique_ptr<type> t( load_kind( kind_item ) );
  store::Item_t const name_item( get_value( type_item, "$name" ) );
  if ( !!name_item ) {
    // load name first so it's available for error messages
    t->load_name( name_item, *this );
  }
  t->load_baseType( get_value( type_item, "$baseType" ), *this );
  t->load_type( type_item, *this );
  types_.push_back( t.get() );
  return move( t );
}

void schema::load_types( store::Item_t const &types_item ) {
  ASSERT_KIND( types_item, "$types", ARRAY );
  store::Iterator_t it( types_item->getArrayValues() );
  store::Item_t type_item;
  it->open();
  while ( it->next( type_item ) )
    load_top_type( type_item );
  it->close();
}

bool schema::annotate( store::Item_t const &json, char const *type_name,
                       store::Item_t *result ) const {
  zstring fq_name_str( type_name );
  return fq_find_type( &fq_name_str )->annotate( json, result );
}

bool schema::validate( store::Item_t const &json,
                       char const *type_name ) const {
  zstring fq_name_str( type_name );
  return fq_find_type( &fq_name_str )->validate( json );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace jsound
} // namespace zorba

/* vim:set et sw=2 ts=2: */
