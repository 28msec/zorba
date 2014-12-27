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
#include <cstring>
#include <iostream>
#include <sstream>

#include <zorba/config.h>
#include <zorba/diagnostic_list.h>
#include <zorba/internal/cxx_util.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/properties.h>
#include <zorba/store_consts.h>

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "diagnostics/assert.h"
#include "diagnostics/xquery_exception.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/json/json_loader.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "system/globalenv.h"
#include "types/casting.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "util/ascii_util.h"
#include "util/fs_util.h"
#include "util/less.h"
#include "util/regex.h"
#include "util/stl_util.h"
#include "util/string_util.h"
#include "util/xml_util.h"
#include "zorbamisc/ns_consts.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"
#include "zorbautils/store_util.h"

#include "jsound_util.h"

// Change to "1" to include $raise-file and $raise-line in annotated results.
#define INVALID_RAISE_LOCATION 0

using namespace std;

namespace zorba {
namespace jsound {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %constraint is a JSONiq expression that tests the value of a JSON item for
 * compliance.
 */
struct constraint {
  zstring const query_;

  constraint( zstring const &query );
  // default destructor is fine

  bool validate( dynamic_context& ) const;

private:
  CompilerCB ccb_;
  PlanIter_t plan_;
  static_context_t sctx_;

  static XQueryDiagnostics* get_shared_diagnostics();

  // forbid these
  constraint( constraint const& );
  constraint& operator=( constraint const& );
};

// We're forced to use a pointer because CompilerCB doesn't have operator=().
typedef vector<constraint const*> constraints_type;

typedef vector<store::Item_t> enumeration_type;
typedef unsigned short facet_mask;

/**
 * The different kinds of JSound types.
 */
enum kind {
  k_none,
  k_array,
  k_atomic,
  k_object,
  k_union
};
ostream& operator<<( ostream&, kind );

/**
 * Internal values for the $explicitTimezone facet.
 */
namespace timezone {
  enum type {
    prohibited,
    optional,
    required
  };
}
ostream& operator<<( ostream&, timezone::type );

/**
 * The abstract base class for all JSound types.
 */
struct type {
  zstring about_;
  type const *baseType_;
  constraints_type constraints_;
  enumeration_type enumeration_;
  facet_mask facet_mask_;
  kind const kind_;
  zstring name_;

  type( kind );
  virtual ~type();

  void to_json( store::Item_t* ) const;

protected:
  virtual void assert_subtype_of( type const* ) const = 0;
  void load_about( store::Item_t const& );
  type const* find_facet( facet_mask facet ) const;
  virtual void load_baseType( store::Item_t const&, schema const& );
  void load_constraints( store::Item_t const& );
  void load_enumeration( store::Item_t const& );
  virtual void load_type( store::Item_t const&, schema& ) = 0;
  void load_name( store::Item_t const&, schema const& );
  virtual bool validate( store::Item_t const&, bool,
                         store::Item_t* = nullptr ) const;

private:
  bool is_enum_valid( store::Item_t const &item ) const;

  friend struct array_type;
  friend struct atomic_type;
  friend struct min_max_type;
  friend struct object_type;
  friend struct schema;
  friend struct union_type;

  // forbid these
  type( type const& );
  type& operator=( type const& );
};
typedef type type_type;                 // eliminate special case for macros

/**
 * This is a base class for array_type and atomic_type to factor out code for
 * their common facets.
 */
struct min_max_type : type {
  int minLength_;
  int maxLength_;

protected:
  void load_maxLength( store::Item_t const& );
  void load_minLength( store::Item_t const& );

  min_max_type( kind );

  friend struct schema;
};

/**
 * The JSound array type.
 */
struct array_type : min_max_type {
  typedef type const* content_type;
  content_type content_;

  array_type();

protected:
  virtual void assert_subtype_of( type const* ) const;
  virtual void load_type( store::Item_t const&, schema& );
  virtual bool validate( store::Item_t const&, bool, store::Item_t* ) const;

private:
  void load_content( store::Item_t const&, schema& );

  friend struct schema;
};

/**
 * The JSound atomic type.
 */
struct atomic_type : min_max_type {
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
  virtual void assert_subtype_of( type const* ) const;
  virtual void load_baseType( store::Item_t const&, schema const& );
  virtual void load_type( store::Item_t const&, schema& );
  virtual bool validate( store::Item_t const&, bool, store::Item_t* ) const;

private:
  void assert_min_max_facet( store::Item_t const&, char const* ) const;
  bool cast( store::Item_t const&, store::Item_t* ) const;
  bool is_castable( store::Item_t const &item ) const;
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

/**
 * The JSound object type.
 */
struct object_type : type {
  struct field_descriptor {
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
    friend struct object_type;
  };

  typedef zstring key_type;
  typedef field_descriptor value_type;
  typedef unordered_map<key_type,value_type> content_type;

  content_type content_;
  bool open_;

  object_type();

protected:
  virtual void assert_subtype_of( type const* ) const;
  virtual void load_type( store::Item_t const&, schema& );
  virtual bool validate( store::Item_t const&, bool, store::Item_t* ) const;

private:
  void assert_subtype_of_helper( type const*, bool,
                                 unordered_set<zstring>* ) const;
  void catch_helper( ZorbaException const&, type const*, zstring const& ) const;
  void load_content( store::Item_t const&, schema& );
  void load_field_descriptor( store::Item_t const&, schema&,
                              field_descriptor* );
  void load_open( store::Item_t const& );

  friend class schema;
};

/**
 * The JSound union type.
 */
struct union_type : type {
  typedef type const* value_type;
  typedef vector<value_type> content_type;

  content_type content_;

  union_type();

protected:
  virtual void assert_subtype_of( type const* ) const;
  virtual void load_baseType( store::Item_t const&, schema const& );
  virtual void load_type( store::Item_t const&, schema& );
  virtual bool validate( store::Item_t const&, bool, store::Item_t* ) const;

private:
  void load_content( store::Item_t const&, schema& );
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Adds the given facet to the facet mask.
 * This macro assumes that the following variables are available in the same
 * (or enclosing) scope: \c facet_mask_.
 *
 * @param FACET The facet to add.
 * \hideinitializer
 */
#define ADD_FACET(FACET) \
  facet_mask_ |= facet_##FACET

/**
 * Asserts that the given expression is \c true for the given facet;
 * if \c false, an exception is thrown.
 *
 * @param TYPE The type having the facet.
 * @param FACET The relevant facet.
 * @param EXPR The expression to evaluate.  Within the expression, the local
 * variable \c bt (the first base type object having \a FACET) can be used.
 * \hideinitializer
 */
#define ASSERT_BASE_FACET(TYPE,FACET,EXPR)                              \
  do {                                                                  \
    TYPE##_type const *const bt = FIND_FACET( TYPE, baseType_, FACET ); \
    if ( bt && !(EXPR) )                                                \
      throw XQUERY_EXCEPTION(                                           \
        jse::ILLEGAL_FACET_VALUE,                                       \
        ERROR_PARAMS( ztd::to_string( FACET##_ ), "$" #FACET, ZED( ILLEGAL_FACET_VALUE_NoOverrideBase_4 ), ztd::to_string( bt->FACET##_ ) ) \
      );                                                                \
  } while (0)

/**
 * Asserts that the given expression is \c true for the given facets;
 * if \c false, an exception is thrown.
 *
 * @param TYPE The type having the facet.
 * @param THIS_FACET The new facet.
 * @param THAT_FACET The other facet.
 * @param EXPR The expression to evaluate.  Within the expression, the local
 * variable \c tt (the "that" type object having \a FACET) can be used.
 * \hideinitializer
 */
#define ASSERT_COMPATIBLE_FACETS(TYPE,THIS_FACET,THAT_FACET,EXPR)       \
  do {                                                                  \
    TYPE##_type const *const tt = FIND_FACET( TYPE, this, THAT_FACET ); \
    if ( tt && !(EXPR) )                                                \
      throw XQUERY_EXCEPTION(                                           \
        jse::ILLEGAL_FACET_VALUE,                                       \
        ERROR_PARAMS( ztd::to_string( THIS_FACET##_ ), "$" #THIS_FACET, ZED( ILLEGAL_FACET_VALUE_IncompatibleWith_45 ), "$" #THAT_FACET, ztd::to_string( tt->THAT_FACET##_ ) ) \
      );                                                                \
  } while (0)

/**
 * Asserts that the given item is a particular kind; if not, an exception is
 * thrown.
 *
 * @param ITEM The item to check.
 * @param NAME The name of the thing (facet, usually) that must be a particular
 * kind.
 * @param KIND The item kind that \a ITEM must be.
 * \hideinitializer
 */
#define ASSERT_KIND(ITEM,NAME,KIND) \
  assert_kind( ITEM, NAME, store::Item::KIND )

/**
 * Asserts that a facet value for a subtype is compatible with that of the base
 * type; if not, an exception is thrown.
 *
 * @param TYPE The type having the facet.
 * @param OBJ The base-type object.
 * @param FACET The relevant facet.
 * @param EXPR The expression to evaluate.  Within the expression, the local
 * variables \c bt (the first base type object having \a FACET) and \c dt (the
 * first derived type object having \a FACET) can be used.
 * \hideinitializer
 */
#define ASSERT_SUBTYPE_FACET(TYPE,OBJ,FACET,EXPR)                   \
  do {                                                              \
    TYPE##_type const *const bt = FIND_FACET( TYPE, (OBJ), FACET ); \
    TYPE##_type const *const dt = FIND_FACET( TYPE, this, FACET );  \
    if ( bt && dt && bt != dt && !(EXPR) )                          \
      throw XQUERY_EXCEPTION( jse::ILLEGAL_BASE_TYPE, ERROR_PARAMS( (OBJ)->name_, name_, ZED( ILLEGAL_BASE_TYPE_IncompatibleFacets_4 ), "$" #FACET ) ); \
  } while (0)

/**
 * Asserts that the given item is a particular atomic type; if not, an
 * exception is thrown.
 *
 * @param ITEM The item to check.
 * @param NAME The name of the thing (facet, usually) that must be a particular
 * atomic type.
 * @param TYPE The XML schema type code that \a ITEM must be.
 * \hideinitializer
 */
#define ASSERT_TYPE(ITEM,NAME,TYPE) \
  assert_type( ITEM, NAME, store::TYPE )

/**
 * Declares the variable \c baseType in the current scope that is a type's
 * \c baseType_ \c static_cast to \a TYPE.
 * This macro assumes that the following variables are available in the same
 * (or enclosing) scope: \c baseType_.
 *
 * @param TYPE The derived type to \c static_cast to.
 * \hideinitializer
 */
#define DECL_baseType(TYPE) \
  DECL_static_cast( TYPE, baseType, baseType_ )

/**
 * Declares a pointer variable \a D in the current scope that is the result of
 * a \c dynamic_cast of the pointer variable \a B to \a TYPE.
 * If the object to which \c B points is not of type \a TYPE, throws an
 * exception.
 *
 * @param TYPE The derived type to \c dynamic_cast to.
 * @param D The pointer variable to declare.
 * @param B The pointer variable to cast.
 * \hideinitializer
 */
#define DECL_dynamic_cast(TYPE,D,B)                                   \
  TYPE##_type const *const D = dynamic_cast<TYPE##_type const*>( B ); \
  do {                                                                \
    if ( !D )                                                         \
      throw XQUERY_EXCEPTION( jse::ILLEGAL_BASE_TYPE, ERROR_PARAMS( (B)->name_, name_, ZED( ILLEGAL_BASE_TYPE_MustBeX_4 ), #TYPE ) ); \
  } while (0)

/**
 * Declares a variable <i>FACET</i><code>_type</code> in the current scope that
 * is the result of calling the FIND_FACET() macro.
 *
 * @param TYPE The type to pass to FIND_FACET().
 * @param OBJ The type object to pass to FIND_FACET().
 * @param FACET The relevant facet.
 * \hideinitializer
 */
#define DECL_FACET_type(TYPE,OBJ,FACET) \
  TYPE##_type const *const FACET##_type = FIND_FACET( TYPE, OBJ, FACET )

/**
 * Declares a pointer variable \a D in the current scope that is the result of
 * a \c static_cast of the pointer variable \a B to type \a TYPE.
 *
 * @param TYPE The derived type to \c static_cast to.
 * @param D The pointer variable to declare.
 * @Param B The pointer variable to cast.
 */
#define DECL_static_cast(TYPE,D,B) \
  TYPE##_type const *const D = static_cast<TYPE##_type const*>( B )

/**
 * Calls the XQUERY_EXCEPTION macro passing jse::ILLEGAL_FACET_VALUE as the
 * diagnostic.
 *
 * @param FACET The facet that has been violated.
 * @param REASON The partial key entry in ths diagnostics dictionary to use.
 * @return Returns a ZorbaException.
 * \hideinitializer
 */
#define FACET_VALUE_EXCEPTION(FACET,REASON) \
  XQUERY_EXCEPTION(                          \
    jse::ILLEGAL_FACET_VALUE,               \
    ERROR_PARAMS( ztd::to_string( FACET##_ ), "$" #FACET, ZED( ILLEGAL_FACET_VALUE_##REASON ) ) \
  )

/**
 * Finds the type object among a type object's base types that has the given
 * facet, if any.
 *
 * @param TYPE The type class to down-cast the result to.
 * @param OBJ The type object to begin the search at; may be \c nullptr.
 * @param FACET The facet to find.
 * @return Returns a pointer to the type object (cast to \a TYPE) having
 * \a FACET or null if none.
 * \hideinitializer
 */
#define FIND_FACET(TYPE,OBJ,FACET) \
  ( (OBJ) ? static_cast<TYPE##_type const*>( (OBJ)->find_facet( facet_##FACET ) ) : nullptr )

/**
 * Tests whether the given item is both an atomic type and whether said type is
 * a subtype of the given type.
 *
 * @param ITEM The item whose type test.
 * @param TYPE The atomic schema type to test against.
 * @return Returns \a true only if \a ITEM is atomic and a subtype of \a TYPE.
 * \hideinitializer
 */
#define IS_ATOMIC_TYPE(ITEM,TYPE) \
  ( (ITEM)->isAtomic() && IS_SUBTYPE( (ITEM)->getTypeCode(), TYPE ) )

/**
 * Tests whether one schema type is a subtype of the other.
 *
 * @param T The schema type to test whether it's a subtype of \a U.
 * @param U The schema type to test against.
 * @return Returns \a true only if \a T is a subtype of \a U.
 * \hideinitializer
 */
#define IS_SUBTYPE(T,U) \
  TypeOps::is_subtype( (T), store::U )

/**
 * Tests whether the given item is the right kind of item.
 *
 * @param ITEM The item whose kind to test.
 * @param KIND The item kind to test against.
 * @return Returns \a true only if \a ITEM is of kind \a KIND.
 * \hideinitializer
 */
#define IS_KIND(ITEM,KIND) \
  ( (ITEM)->getKind() == store::Item::KIND )

/**
 * Calls make_invalid() passing the current file and line number.
 *
 * @param TYPE The expected type.
 * @param ITEM The invalid JSON item.
 * @param RESULT A pointer to the result item to be constructed.
 * \hideinitializer
 */
#define MAKE_INVALID(TYPE,ITEM,RESULT,...) \
  make_invalid( __FILE__, __LINE__, (TYPE), (ITEM), (RESULT), __VA_ARGS__ )

/**
 * Returns \c false from the enclosing function.
 * This macro assumes that the following variables are available in the same
 * (or enclosing) scope: \c this, \c reslut, and \c validate_item.
 * If \c result is non-null, the MAKE_INVALID() macro is called.
 * \hideinitializer
 */
#define RETURN_INVALID(...)                                     \
  do {                                                          \
    if ( result )                                               \
      MAKE_INVALID( this, validate_item, result, __VA_ARGS__ ); \
    return false;                                               \
  } while (0)

/**
 * Validates that the given facet is not violated.
 * This macro assumes that the following variables are available in the same
 * (or enclosing) scope: \c name_, \c validate_item, and \c result.
 * If the facet has not been violated, nothing happens and program control flow
 * continues to the next statement.
 * If the facet has been violated, the RETURN_INVALID() macro is called.
 *
 * @param FACET The facet to validate.
 * @param EXPR The expression to evaluate: if \c false, the facet has been
 * violated.
 * \hideinitializer
 */
#define VALIDATE_FACET(FACET,EXPR)  \
  do {                              \
    if ( FACET##_type && !(EXPR) )  \
      RETURN_INVALID( jse::FACET_VIOLATION, ERROR_PARAMS( ZED( FACET_VIOLATION_BadValue_23o ), "$" #FACET, FACET##_type->name_ ) ); \
  } while (0)

/**
 * Validates that the given item is the right kind of item.
 * If the item is the right kind of item, nothing happens and program control
 * flow continues to the next statement.
 * If the item is not the right kind of item, then the RETURN_INVALID() macro
 * is called.
 *
 * @param ITEM The item whose kind to validate.
 * @param KIND The kind to ensure \a ITEM is.
 * \hideinitializer
 */
#define VALIDATE_KIND(ITEM,KIND)  \
  do {                            \
    if ( !IS_KIND( ITEM, KIND ) ) \
      RETURN_INVALID( jse::TYPE_VIOLATION, ERROR_PARAMS( to_type_str( validate_item ), store::Item::KIND ) ); \
  } while (0)

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

static void assert_kind( store::Item_t const &item, char const *name,
                         store::Item::ItemKind kind ) {
  if ( item->getKind() != kind )
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_TYPE,
      ERROR_PARAMS( item->getKind(), name, kind )
    );
}

inline void assert_kind( store::Item_t const &item, zstring const &name,
                         store::Item::ItemKind kind ) {
  assert_kind( item, name.c_str(), kind );
}

static void assert_type( store::Item_t const &item, char const *name,
                         store::SchemaTypeCode stc ) {
  if ( !item->isAtomic() )
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_TYPE,
      ERROR_PARAMS( item->getKind(), name, store::Item::ATOMIC )
    );
  store::SchemaTypeCode const item_stc = item->getTypeCode();
  if ( !TypeOps::is_subtype( item_stc, stc ) )
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_TYPE, ERROR_PARAMS( item_stc, name, stc )
    );
}

inline void assert_type( store::Item_t const &item, zstring const &name,
                         store::SchemaTypeCode stc ) {
  assert_type( item, name.c_str(), stc );
}

static store::SchemaTypeCode map_atomic_type( zstring const &type_name ) {
  zstring temp_name( type_name );

  if ( ZSTREQ( temp_name, "js:null" ) )
    return store::JS_NULL;
  if ( ZSTREQ( temp_name, "null" ) )
    return store::JS_NULL;

  if ( ZA_BEGINS_WITH( temp_name, "xs:" ) )
    temp_name.erase( 0, 3 );

  // check common types first
  if ( ZSTREQ( temp_name, "string" ) )
    return store::XS_STRING;
  if ( ZSTREQ( temp_name, "boolean" ) )
    return store::XS_BOOLEAN;
  if ( ZSTREQ( temp_name, "integer" ) )
    return store::XS_INTEGER;
  if ( ZSTREQ( temp_name, "decimal" ) )
    return store::XS_DECIMAL;
  if ( ZSTREQ( temp_name, "double" ) )
    return store::XS_DOUBLE;
  if ( ZSTREQ( temp_name, "float" ) )
    return store::XS_FLOAT;

  if ( ZSTREQ( temp_name, "date" ) )
    return store::XS_DATE;
  if ( ZSTREQ( temp_name, "dateTime" ) )
    return store::XS_DATETIME;
  if ( ZSTREQ( temp_name, "dateTimeStamp" ) )
    return store::XS_DATETIME_STAMP;
  if ( ZSTREQ( temp_name, "dayTimeDuration" ) )
    return store::XS_DT_DURATION;
  if ( ZSTREQ( temp_name, "duration" ) )
    return store::XS_DURATION;
  if ( ZSTREQ( temp_name, "time" ) )
    return store::XS_TIME;
  if ( ZSTREQ( temp_name, "anyURI" ) )
    return store::XS_ANY_URI;
  if ( ZSTREQ( temp_name, "base64Binary" ) )
    return store::XS_BASE64BINARY;
  if ( ZSTREQ( temp_name, "byte" ) )
    return store::XS_BYTE;
  if ( ZSTREQ( temp_name, "gDay" ) )
    return store::XS_GDAY;
  if ( ZSTREQ( temp_name, "gMonth" ) )
    return store::XS_GMONTH;
  if ( ZSTREQ( temp_name, "gMonthDay" ) )
    return store::XS_GMONTH_DAY;
  if ( ZSTREQ( temp_name, "gYear" ) )
    return store::XS_GYEAR;
  if ( ZSTREQ( temp_name, "gYearMonth" ) )
    return store::XS_GYEAR_MONTH;
  if ( ZSTREQ( temp_name, "hexBinary" ) )
    return store::XS_HEXBINARY;
  if ( ZSTREQ( temp_name, "long" ) )
    return store::XS_LONG;
  if ( ZSTREQ( temp_name, "negativeInteger" ) )
    return store::XS_NEGATIVE_INTEGER;
  if ( ZSTREQ( temp_name, "nonNegativeInteger" ) )
    return store::XS_NON_NEGATIVE_INTEGER;
  if ( ZSTREQ( temp_name, "nonPositiveInteger" ) )
    return store::XS_NON_POSITIVE_INTEGER;
  if ( ZSTREQ( temp_name, "positiveInteger" ) )
    return store::XS_POSITIVE_INTEGER;
  if ( ZSTREQ( temp_name, "short" ) )
    return store::XS_SHORT;
  if ( ZSTREQ( temp_name, "unsignedByte" ) )
    return store::XS_UNSIGNED_BYTE;
  if ( ZSTREQ( temp_name, "unsignedInt" ) )
    return store::XS_UNSIGNED_INT;
  if ( ZSTREQ( temp_name, "unsignedLong" ) )
    return store::XS_UNSIGNED_LONG;
  if ( ZSTREQ( temp_name, "unsignedShort" ) )
    return store::XS_UNSIGNED_SHORT;
  if ( ZSTREQ( temp_name, "yearMonthDuration" ) )
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
    throw XQUERY_EXCEPTION(
      jse::TYPE_MISMATCH,
      ERROR_PARAMS( k, t->kind_, name )
    );
  if ( item->isAtomic() ) {
    DECL_static_cast( atomic, cast_t, t );
    store::SchemaTypeCode const item_stc = item->getTypeCode();
    if ( !TypeOps::is_subtype( item_stc, cast_t->schemaTypeCode_ ) )
      throw XQUERY_EXCEPTION(
        jse::TYPE_MISMATCH, ERROR_PARAMS( item_stc, t->name_, name )
      );
  }
}

inline void assert_type_matches( store::Item_t const &item, type const *t,
                                 zstring const &name ) {
  assert_type_matches( item, t, name.c_str() );
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
    INIT_ATOMIC_TYPE( null, JS_NULL );
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

// This may not be necessary.
#if 0

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
#endif
  }

  map_type::const_iterator const i( m.find( type_name.c_str() ) );
  if ( i != m.end() )
    return i->second;
  if ( not_found_error )
    throw XQUERY_EXCEPTION( jse::UNKNOWN_TYPE, ERROR_PARAMS( type_name ) );
  return nullptr;
}

static kind find_kind( zstring const &name ) {
  if ( ZSTREQ( name, "atomic" ) ) return k_atomic;
  if ( ZSTREQ( name, "array"  ) ) return k_array;
  if ( ZSTREQ( name, "object" ) ) return k_object;
  if ( ZSTREQ( name, "union"  ) ) return k_union;
  return k_none;
}

static store::Item_t get_json_value( store::Item_t const &json_object,
                                     char const *key ) {
  zstring s( key );
  store::Item_t key_item;
  GENV_ITEMFACTORY->createString( key_item, s );
  return json_object->getObjectValue( key_item );
}

static void push_back( vector<store::Item_t> *v, char const *s ) {
  zstring s2( s );
  store::Item_t item;
  GENV_ITEMFACTORY->createString( item, s2 );
  v->push_back( item );
}

inline void push_back( vector<store::Item_t> *v, zstring const &s ) {
  push_back( v, s.c_str() );
}

static void make_invalid( char const *raise_file, int raise_line,
                          type const *expected_type,
                          store::Item_t const &instance,
                          store::Item_t *result,
                          Diagnostic const &diagnostic,
                          internal::diagnostic::parameters const &params ) {
  vector<store::Item_t> keys, values;
  store::Item_t item;
  zstring s;

  push_back( &keys, "$invalid" );
  GENV_ITEMFACTORY->createBoolean( item, true );
  values.push_back( item );

  push_back( &keys, "$expected" );
  if ( expected_type->name_.empty() ) {
    expected_type->to_json( &item );
  } else {
    s = expected_type->name_;
    GENV_ITEMFACTORY->createString( item, s );
  }
  values.push_back( item );

  push_back( &keys, "$value" );
  values.push_back( instance );

  push_back( &keys, "$reason" );
  internal::diagnostic::parameters::value_type message( diagnostic.message() );
  params.substitute( &message );
  push_back( &values, message );

#if INVALID_RAISE_LOCATION
  push_back( &keys, "$raise-file" );
  push_back( &values, fs::base_name( raise_file ) );

  push_back( &keys, "$raise-line" );
  GENV_ITEMFACTORY->createInt( item, raise_line );
  values.push_back( item );
#endif /* NDEBUG */

  GENV_ITEMFACTORY->createJSONObject( *result, keys, values );
}

static store::Item_t require_value( store::Item_t const &json_object,
                                    char const *key,
                                    char const *type_name = "" ) {
  store::Item_t value_item( get_json_value( json_object, key ) );
  if ( !value_item )
    throw XQUERY_EXCEPTION( jse::MISSING_KEY, ERROR_PARAMS( key, type_name ) );
  return value_item;
}

inline store::Item_t require_value( store::Item_t const &json_object,
                                    char const *key,
                                    zstring const &type_name ) {
  return require_value( json_object, key, type_name.c_str() );
}

static string to_type_str( store::Item_t const &item ) {
  ostringstream oss;
  if ( item->isAtomic() )
    oss << item->getTypeCode();
  else
    oss << item->getKind();
  return oss.str();
}

inline int to_xs_int( store::Item_t const &item ) {
  return to_xs_int( item->getIntegerValue() );
}

///////////////////////////////////////////////////////////////////////////////

constraint::constraint( zstring const &query ) :
  query_( query ),
  ccb_( get_shared_diagnostics() ),
  sctx_( GENV_ROOT_STATIC_CONTEXT.create_child_context() )
{
  ccb_.theRootSctx = sctx_.get();
  ccb_.theCommonLanguageEnabled = true;

  // TODO: add explicit language parameter to XQueryCompiler::compile()
  zstring temp( query_ );
  temp.insert( 0, "jsoniq version \"1.0\";" );
  istringstream iss( temp.c_str() );
  zstring const no_filename;
  ulong next_dynamic_var_id = 0; // TODO: is this correct?

  XQueryCompiler xc( &ccb_ );
  plan_ = xc.compile( iss, no_filename, next_dynamic_var_id );
}

XQueryDiagnostics* constraint::get_shared_diagnostics() {
  static XQueryDiagnostics diagnostics;
  return &diagnostics;
}

bool constraint::validate( dynamic_context &dctx ) const {
  PlanState state(
    &dctx, &dctx, plan_->getStateSizeOfSubtree(), 0,
    Properties::instance().getMaxUDFCallDepth()
  );
  state.theCompilerCB = const_cast<CompilerCB*>( &ccb_ );
  uint32_t offset = 0;
  plan_->open( state, offset );
  bool const valid = FnBooleanIterator::effectiveBooleanValue(
    QueryLoc::null, state, plan_.get()
  );
  plan_->close( state );
  return valid;
}

ostream& operator<<( ostream &os, kind k ) {
  switch ( k ) {
    case k_none  : return os << "none";
    case k_array : return os << "array";
    case k_atomic: return os << "atomic";
    case k_object: return os << "object";
    case k_union : return os << "union";
    default      : return os << "<unknown kind: " << (int)k << '>';
  }
}

ostream& operator<<( ostream &os, timezone::type tz ) {
  using namespace timezone;
  switch ( tz ) {
    case prohibited: return os << "prohibited";
    case required  : return os << "required";
    case optional  : return os << "optional";
    default        : return os << "<unknown timezone::type: " << (int)tz << '>';
  }
}

///////////////////////////////////////////////////////////////////////////////

array_type::array_type() : min_max_type( k_array ) {
  content_ = nullptr;
}

void array_type::assert_subtype_of( type const *t ) const {
  DECL_dynamic_cast( array, cast_t, t );
  content_->assert_subtype_of( cast_t->content_ );
  ASSERT_SUBTYPE_FACET( array, t, maxLength, dt->maxLength_ <= bt->maxLength_ );
  ASSERT_SUBTYPE_FACET( array, t, minLength, dt->minLength_ >= bt->minLength_ );
}

void array_type::load_content( store::Item_t const &content_item, schema &s ) {
  ASSERT_KIND( content_item, "$content", ARRAY );
  if ( content_item->getArraySize() != numeric_consts<xs_integer>::one() )
    throw XQUERY_EXCEPTION( jse::ILLEGAL_ARRAY_SIZE );
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
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_KEY,
        ERROR_PARAMS( key_str, ZED( ILLEGAL_KEY_Type_34o ), kind_, name_ )
      );
  } // while
  it->close();

  if ( !content_ && baseType_ ) {
    DECL_baseType( array );
    content_ = baseType->content_;      // inherit baseType's content
  }
}

bool array_type::validate( store::Item_t const &validate_item, bool do_cast,
                           store::Item_t *result ) const {
  VALIDATE_KIND( validate_item, ARRAY );
  if ( !type::validate( validate_item, do_cast, result ) )
    return false;

  DECL_FACET_type( array, this, maxLength );
  DECL_FACET_type( array, this, minLength );
  int length;
  if ( minLength_type || maxLength_type )
    length = to_xs_int( validate_item->getArraySize() );
  VALIDATE_FACET( maxLength, length <= maxLength_type->maxLength_ );
  VALIDATE_FACET( minLength, length >= minLength_type->minLength_ );

  vector<store::Item_t> new_items;
  bool valid = true;

  store::Iterator_t it( validate_item->getArrayValues() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) )
    if ( result ) {
      store::Item_t temp;
      if ( !content_->validate( item, do_cast, &temp ) )
        valid = false;
      new_items.push_back( temp );
    } else if ( !content_->validate( item, do_cast ) )
      return false;
  it->close();

  if ( result ) {
    if ( valid )
      *result = validate_item;
    else
      GENV_ITEMFACTORY->createJSONArray( *result, new_items );
  }
  return valid;
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
        throw XQUERY_EXCEPTION(
          jse::ILLEGAL_FACET, ERROR_PARAMS( facet_name, schemaTypeCode_ )
        );
  }
  assert_type( item, facet_name, schemaTypeCode_ );
}

void atomic_type::assert_subtype_of( type const *t ) const {
  DECL_dynamic_cast( atomic, cast_t, t );
  if ( !TypeOps::is_subtype( schemaTypeCode_, cast_t->schemaTypeCode_ ) )
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_BASE_TYPE,
      ERROR_PARAMS(
        t->name_, name_, ZED( ILLEGAL_BASE_TYPE_NotSubtype_45 ),
        schemaTypeCode_, cast_t->schemaTypeCode_
      )
    );

  ASSERT_SUBTYPE_FACET( atomic, t, maxExclusive,
    dt->maxExclusive_->compare( bt->maxExclusive_ ) <= 0 );
  ASSERT_SUBTYPE_FACET( atomic, t, maxInclusive,
    dt->maxInclusive_->compare( bt->maxInclusive_ ) <= 0 );
  ASSERT_SUBTYPE_FACET( atomic, t, minExclusive,
    dt->minExclusive_->compare( bt->minExclusive_ ) >= 0 );
  ASSERT_SUBTYPE_FACET( atomic, t, minInclusive,
    dt->minInclusive_->compare( bt->minInclusive_ ) >= 0 );

  ASSERT_SUBTYPE_FACET( atomic, t, minLength,
    dt->minLength_ >= bt->minLength_ );
  ASSERT_SUBTYPE_FACET( atomic, t, maxLength,
    dt->maxLength_ <= bt->maxLength_ );

  ASSERT_SUBTYPE_FACET( atomic, t, length, dt->length_ == bt->length_ );

  ASSERT_SUBTYPE_FACET( atomic, t, totalDigits,
    dt->totalDigits_ < bt->totalDigits_ );
  ASSERT_SUBTYPE_FACET( atomic, t, fractionDigits,
    dt->fractionDigits_ < bt->fractionDigits_ );

  ASSERT_SUBTYPE_FACET( atomic, t, explicitTimezone,
    dt->explicitTimezone_ == bt->explicitTimezone_ ||
    bt->explicitTimezone_ == timezone::optional
  );

  // can't check whether pattern is a sub-pattern
}

bool atomic_type::cast( store::Item_t const &item,
                        store::Item_t *result ) const {
  store::Item_t temp( item );
  return GenericCast::castToBuiltinAtomic(
    *result, temp, schemaTypeCode_, nullptr, QueryLoc::null, false
  );
}

bool atomic_type::is_castable( store::Item_t const &item ) const {
  store::Item_t mutable_item( item ), result;
  return GenericCast::castToBuiltinAtomic(
    result, mutable_item, schemaTypeCode_, nullptr, QueryLoc::null, false
  );
}

void atomic_type::load_baseType( store::Item_t const &baseType_item,
                                 schema const &s ) {
  if ( !baseType_item )
    throw XQUERY_EXCEPTION(
      jse::MISSING_KEY, ERROR_PARAMS( "$baseType", name_ )
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
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_FACET, ERROR_PARAMS( "$explicitTimezone", schemaTypeCode_ )
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
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_FACET_VALUE,
      ERROR_PARAMS(
        eTz_str, "$explicitTimezone",
        ZED( ILLEGAL_FACET_VALUE_MustBeOPR )
      )
    );
  ASSERT_BASE_FACET( atomic, explicitTimezone,
    explicitTimezone_ == bt->explicitTimezone_ ||
    bt->explicitTimezone_ == timezone::optional
  );
  ADD_FACET( explicitTimezone );
}

void atomic_type::load_fractionDigits( store::Item_t const &fDigits_item ) {
  ASSERT_TYPE( fDigits_item, "$fractionDigits", XS_INTEGER );
  if ( schemaTypeCode_ != store::XS_DECIMAL )
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_FACET, ERROR_PARAMS( "$fractionDigits", schemaTypeCode_ )
    );
  fractionDigits_ = to_xs_int( fDigits_item );
  if ( fractionDigits_ < 0 )
    throw FACET_VALUE_EXCEPTION( fractionDigits, MustBeGE0 );

  ASSERT_BASE_FACET( atomic, fractionDigits,
    fractionDigits_ <= bt->fractionDigits_ );

  ASSERT_COMPATIBLE_FACETS( atomic, fractionDigits, totalDigits,
    fractionDigits_ <= tt->totalDigits_ );

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
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_FACET, ERROR_PARAMS( "$length", schemaTypeCode_ )
      );
  }
  length_ = to_xs_int( length_item );
  if ( length_ < 0 )
    throw FACET_VALUE_EXCEPTION( length, MustBeGE0 );
  ASSERT_BASE_FACET( atomic, length, length_ <= bt->length_ );
  ADD_FACET( length );
}

void atomic_type::load_maxExclusive( store::Item_t const &maxExclusive_item ) {
  assert_min_max_facet( maxExclusive_item, "$maxExclusive" );
  maxExclusive_ = maxExclusive_item;

  ASSERT_BASE_FACET( atomic, maxExclusive,
    maxExclusive_->compare( bt->maxExclusive_ ) <= 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, maxExclusive, maxInclusive,
    maxExclusive_->compare( tt->maxInclusive_ ) > 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, maxExclusive, minExclusive,
    maxExclusive_->compare( tt->minExclusive_ ) > 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, maxExclusive, minInclusive,
    maxExclusive_->compare( tt->minInclusive_ ) > 0 );

  ADD_FACET( maxExclusive );
}

void atomic_type::load_maxInclusive( store::Item_t const &maxInclusive_item ) {
  assert_min_max_facet( maxInclusive_item, "$maxInclusive" );
  maxInclusive_ = maxInclusive_item;

  ASSERT_BASE_FACET( atomic, maxInclusive,
    maxInclusive_->compare( bt->maxInclusive_ ) <= 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, maxInclusive, maxExclusive,
    maxInclusive_->compare( tt->maxExclusive_ ) < 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, maxInclusive, minExclusive,
    maxInclusive_->compare( tt->minExclusive_ ) > 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, maxInclusive, minInclusive,
    maxInclusive_->compare( tt->minInclusive_ ) >= 0 );

  ADD_FACET( maxInclusive );
}

void atomic_type::load_minExclusive( store::Item_t const &minExclusive_item ) {
  assert_min_max_facet( minExclusive_item, "$minExclusive" );
  minExclusive_ = minExclusive_item;

  ASSERT_BASE_FACET( atomic, minExclusive,
    minExclusive_->compare( bt->minExclusive_ ) >= 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, minExclusive, maxExclusive,
    minExclusive_->compare( tt->maxExclusive_ ) < 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, minExclusive, maxInclusive,
    minExclusive_->compare( tt->maxInclusive_ ) < 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, minExclusive, minInclusive,
    minExclusive_->compare( tt->minInclusive_ ) < 0 );

  ADD_FACET( minExclusive );
}

void atomic_type::load_minInclusive( store::Item_t const &minInclusive_item ) {
  assert_min_max_facet( minInclusive_item, "$minInclusive" );
  minInclusive_ = minInclusive_item;

  ASSERT_BASE_FACET( atomic, minInclusive,
    minInclusive_->compare( bt->minInclusive_ ) >= 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, minInclusive, maxExclusive,
    minInclusive_->compare( tt->maxExclusive_ ) < 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, minInclusive, maxInclusive,
    minInclusive_->compare( tt->maxInclusive_ ) <= 0 );

  ASSERT_COMPATIBLE_FACETS( atomic, minInclusive, minExclusive,
    minInclusive_->compare( tt->minExclusive_ ) > 0 );

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
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_FACET_VALUE,
      ERROR_PARAMS(
        xquery_re, "$pattern",
        ZED( ILLEGAL_FACET_VALUE_BadPattern_45 ),
        e.diagnostic().qname(), e.what()
      )
    );
  }
  ADD_FACET( pattern );
}

void atomic_type::load_totalDigits( store::Item_t const &totalDigits_item ) {
  ASSERT_TYPE( totalDigits_item, "$totalDigits", XS_INTEGER );
  if ( !IS_SUBTYPE( schemaTypeCode_, XS_DECIMAL ) )
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_FACET, ERROR_PARAMS( "$totalDigits", schemaTypeCode_ )
    );
  totalDigits_ = to_xs_int( totalDigits_item );
  if ( totalDigits_ < 0 )
    throw FACET_VALUE_EXCEPTION( totalDigits, MustBeGE0 );

  ASSERT_BASE_FACET( atomic, totalDigits,
    totalDigits_ <= bt->totalDigits_ );

  ASSERT_COMPATIBLE_FACETS( atomic, totalDigits, fractionDigits,
    totalDigits_ >= tt->fractionDigits_ );

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
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_KEY,
        ERROR_PARAMS( key_str, ZED( ILLEGAL_KEY_Type_34o ), kind_, name_ )
      );
  } // while
  it->close();
}

bool atomic_type::validate( store::Item_t const &item, bool do_cast,
                            store::Item_t *result ) const {
  store::Item_t validate_item( item );

  if ( !( validate_item->isAtomic() &&
          (TypeOps::is_subtype( item->getTypeCode(), schemaTypeCode_ ) ||
            (do_cast && cast( item, &validate_item )) ) ) ) {
    RETURN_INVALID(
      jse::TYPE_VIOLATION,
      ERROR_PARAMS( to_type_str( validate_item ), schemaTypeCode_ )
    );
  }

  if ( !type::validate( validate_item, do_cast, result ) )
    return false;

  DECL_FACET_type( atomic, this, length );
  DECL_FACET_type( atomic, this, totalDigits );
  DECL_FACET_type( atomic, this, fractionDigits );

  zstring str;
  int length;
  if ( length_type || totalDigits_type || fractionDigits_type ) {
    str = validate_item->getStringValue();
    length = str.length();
  }

  if ( length_type )
    VALIDATE_FACET( length, length == length_ );

  if ( DECL_FACET_type( atomic, this, maxExclusive ) )
    VALIDATE_FACET( maxExclusive,
      validate_item->compare( maxExclusive_type->maxExclusive_ ) <  0 );

  if ( DECL_FACET_type( atomic, this, maxInclusive ) )
    VALIDATE_FACET( maxInclusive,
      validate_item->compare( maxInclusive_type->maxInclusive_ ) <= 0 );

  if ( DECL_FACET_type( atomic, this, minExclusive ) )
    VALIDATE_FACET( minExclusive,
      validate_item->compare( minExclusive_type->minExclusive_ ) >  0 );

  if ( DECL_FACET_type( atomic, this, minInclusive ) )
    VALIDATE_FACET( minInclusive,
      validate_item->compare( minInclusive_type->minInclusive_ ) >= 0 );

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

  if ( DECL_FACET_type( atomic, this, pattern ) ) {
    if ( str.empty() )
      str = validate_item->getStringValue();
    VALIDATE_FACET( pattern, pattern_type->pattern_re_.match_whole( str ) );
  }

  if ( DECL_FACET_type( atomic, this, explicitTimezone ) ) {
    timezone::type const tz = explicitTimezone_type->explicitTimezone_;
    if ( tz != timezone::optional ) {
      xs_time const &time = validate_item->getTimeValue();
      VALIDATE_FACET( explicitTimezone,
        (tz == timezone::required   &&  time.hasTimezone()) ||
        (tz == timezone::prohibited && !time.hasTimezone())
      );
    }
  }

  if ( result )
    *result = validate_item;
  return true;
}

///////////////////////////////////////////////////////////////////////////////

min_max_type::min_max_type( kind k ) : type( k ) {
}

void min_max_type::load_maxLength( store::Item_t const &maxLength_item ) {
  ASSERT_TYPE( maxLength_item, "$maxLength", XS_INTEGER );
  maxLength_ = to_xs_int( maxLength_item );
  if ( maxLength_ < 0 )
    throw FACET_VALUE_EXCEPTION( maxLength, MustBeGE0 );
  ASSERT_BASE_FACET( atomic, maxLength, maxLength_ <= bt->maxLength_ );
  ADD_FACET( maxLength );
}

void min_max_type::load_minLength( store::Item_t const &minLength_item ) {
  ASSERT_TYPE( minLength_item, "$minLength", XS_INTEGER );
  minLength_ = to_xs_int( minLength_item );
  if ( minLength_ < 0 )
    throw FACET_VALUE_EXCEPTION( minLength, MustBeGE0 );
  ASSERT_BASE_FACET( atomic, minLength, minLength_ >= bt->minLength_ );
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
  DECL_dynamic_cast( object, cast_t, t );
  ASSERT_SUBTYPE_FACET( object, t, open, dt->open_ || !bt->open_ );
  DECL_FACET_type( object, this, open );
  bool const open = open_type ? open_type->open_ : true;
  unordered_set<zstring> seen;
  assert_subtype_of_helper( t, open, &seen );
}

void object_type::
assert_subtype_of_helper( type const *t, bool open,
                          unordered_set<zstring> *seen ) const {
  DECL_dynamic_cast( object, cast_t, t );
  for ( type const *u = this; u; u = u->baseType_ ) {
    DECL_static_cast( object, cast_u, u );
    FOR_EACH( content_type, i, cast_u->content_ ) {
      key_type const &key = i->first;
      if ( ztd::contains( *seen, key ) )
        continue;
      field_descriptor const &fd = i->second;
      content_type::const_iterator const t_i( cast_t->content_.find( key ) );
      if ( t_i != cast_t->content_.end() ) {
        field_descriptor const &t_fd = t_i->second;
        if ( fd.optional_ && !t_fd.optional_ )
          throw XQUERY_EXCEPTION(
            jse::ILLEGAL_FACET_VALUE,
            ERROR_PARAMS(
              "false", "$optional",
              ZED( ILLEGAL_FACET_VALUE_NoOverrideBase_4 ),
              t->name_
            )
          );
        try {
          fd.type_->assert_subtype_of( t_fd.type_ );
        }
        catch ( ZorbaException const &e ) {
          catch_helper( e, t, key );
        }
      } else if ( t->baseType_ ) {
        cast_u->assert_subtype_of_helper( t->baseType_, open, seen );
        seen->insert( key );
      } else if ( !open )
        throw XQUERY_EXCEPTION(
          jse::NEW_KEY_NOT_ALLOWED,
          ERROR_PARAMS( key, t->name_ )
        );
    } // FOR_EACH
  } // for
}

void object_type::catch_helper( ZorbaException const &e,
                                type const *illegal_base_type,
                                zstring const &key ) const {
  if ( strcmp( e.diagnostic().qname().ns(), JSOUND_ERR_NS ) != 0 )
    throw;
  //
  // Give a better error message by throwing an exception specific to the
  // current key with the original exception's error message as a sub-message.
  //
  throw XQUERY_EXCEPTION(
    jse::ILLEGAL_BASE_TYPE,
    ERROR_PARAMS(
      illegal_base_type->name_, name_,
      ZED( ILLEGAL_BASE_TYPE_BecauseOfKey_45 ),
      key, e.what()
    )
  );
}

void object_type::load_content( store::Item_t const &content_item, schema &s ) {
  ASSERT_KIND( content_item, "$content", OBJECT );

  DECL_FACET_type( object, this, open );
  bool const open = open_type ? open_type->open_ : true;

  store::Iterator_t it( content_item->getObjectKeys() );
  store::Item_t key_item;
  it->open();
  while ( it->next( key_item ) ) {
    // key_item is guaranteed to be a string by JSON syntax
    zstring const key_str( key_item->getStringValue() );
    // duplicate keys in the same object are checked for by JSON semantics
    field_descriptor &fd = content_[ key_str ];
    load_field_descriptor( content_item->getObjectValue( key_item ), s, &fd );

    //
    // Check every base type for the same key: if found, it's value's type must
    // be a subtype of this key's value's type; if not found and the base type
    // isn't open, thrown an exception.
    //
    for ( type const *t = baseType_; t; t = t->baseType_ ) {
      DECL_static_cast( object, cast_t, t );
      content_type::const_iterator bt_i( cast_t->content_.find( key_str ) );
      if ( bt_i != cast_t->content_.end() )
        try {
          fd.type_->assert_subtype_of( bt_i->second.type_ );
        }
        catch ( ZorbaException const &e ) {
          catch_helper( e, t, key_str );
        }
      else if ( !open )
        throw XQUERY_EXCEPTION(
          jse::NEW_KEY_NOT_ALLOWED,
          ERROR_PARAMS( key_str, t->name_ )
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
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_KEY,
        ERROR_PARAMS( key_str, ZED( ILLEGAL_KEY_FieldDescriptor ) )
      );
  } // while
  it->close();
}

void object_type::load_open( store::Item_t const &open_item ) {
  ASSERT_TYPE( open_item, "$open", XS_BOOLEAN );
  open_ = open_item->getBooleanValue();
  DECL_FACET_type( object, this, open );
  if ( open_type && !open_type->open_ && open_ ) {
    //
    // JSound 5.4: The $open Facet behaves like most Facets, i.e., if that of
    // the Base Type is false, it cannot be set back to true, otherwise
    // jse:JDST0007 is raised.
    //
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_FACET_VALUE,
      ERROR_PARAMS(
        "true", "$open", ZED( ILLEGAL_FACET_VALUE_NoOverrideBase_4 ), "false"
      )
    );
  }
  ADD_FACET( open );
}

void object_type::load_type( store::Item_t const &type_item, schema &s ) {
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
    else if ( ZSTREQ( key_str, "$kind" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$name" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$open" ) )
      load_open( value_item );
    else
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_KEY,
        ERROR_PARAMS( key_str, ZED( ILLEGAL_KEY_Type_34o ), kind_, name_ )
      );
  } // while
  it->close();

  if ( content_.empty() && baseType_ ) {
    DECL_baseType( object );
    content_ = baseType->content_;      // inherit baseType's content
  }
}

bool object_type::validate( store::Item_t const &validate_item, bool do_cast,
                            store::Item_t *result ) const {
  VALIDATE_KIND( validate_item, OBJECT );
  if ( !type::validate( validate_item, do_cast, result ) )
    return false;

  typedef unordered_set<zstring> seen_type;

  seen_type seen;
  vector<store::Item_t> new_keys, new_values;
  bool added_default = false, valid = true;

  DECL_FACET_type( object, this, open );
  bool const open = open_type ? open_type->open_ : true;

  //
  // Check each key in the given object against this type.
  //
  store::Iterator_t it( validate_item->getObjectKeys() );
  store::Item_t key_item;
  it->open();
  while ( it->next( key_item ) ) {
    zstring const key_str( key_item->getStringValue() );
    field_descriptor const *fd = nullptr;
    for ( type const *t = this; t; t = t->baseType_ ) {
      DECL_static_cast( object, cast_t, t );
      content_type::const_iterator const i( cast_t->content_.find( key_str ) );
      if ( i != cast_t->content_.end() ) {
        fd = &i->second;
        break;
      }
    } // for
    if ( !fd ) {
      if ( open )
        continue;
      RETURN_INVALID(
        jse::FACET_VIOLATION,
        ERROR_PARAMS(
          ZED( FACET_VIOLATION_BadKey_23o ),
          key_str, open_type->name_
        )
      );
    }

    store::Item_t const value_item( validate_item->getObjectValue( key_item ) );
    if ( result ) {
      store::Item_t temp;
      if ( !fd->type_->validate( value_item, do_cast, &temp ) )
        valid = false;
      new_keys.push_back( key_item );
      new_values.push_back( temp );
    } else if ( !fd->type_->validate( value_item, do_cast ) )
      return false;
    seen.insert( key_str );
  } // while
  it->close();

  //
  // Check each key in this type against the given object: look for keys that
  // aren't present.
  //
  for ( type const *t = this; t; t = t->baseType_ ) {
    DECL_static_cast( object, cast_t, t );
    FOR_EACH( content_type, i, cast_t->content_ ) {
      zstring const &key_str = i->first;
      field_descriptor const &fd = i->second;
      seen_type::const_iterator const j( seen.find( key_str ) );
      if ( j != seen.end() )
        continue;
      if ( result && !!fd.default_ ) {
        //
        // The key isn't present and there is a default value: add it.
        //
        push_back( &new_keys, key_str );
        new_values.push_back( fd.default_ );
        added_default = true;
        //
        // Add the key to "seen" so that we don't add a default value again in
        // the case where a base type has the same key.
        //
        seen.insert( key_str );
        continue;
      }
      if ( !fd.optional_ ) {
        //
        // The key isn't present and it's not optional: invalid.
        //
        valid = false;
        if ( !result )
          break;
        push_back( &new_keys, key_str );
        store::Item_t item, null_item;
        GENV_ITEMFACTORY->createJSONNull( null_item );
        MAKE_INVALID(
          fd.type_, null_item, &item,
          jse::MISSING_KEY, ERROR_PARAMS( key_str, fd.type_->name_ )
        );
        new_values.push_back( item );
      }
    } // FOR_EACH
  } // for

  if ( result ) {
    if ( valid && !added_default )
      *result = validate_item;
    else
      GENV_ITEMFACTORY->createJSONObject( *result, new_keys, new_values );
  }
  return valid;
}

///////////////////////////////////////////////////////////////////////////////

type::type( kind k ) : kind_( k ) {
  baseType_ = nullptr;
  facet_mask_ = 0;
}

type::~type() {
  ztd::delete_ptr_seq( constraints_ );
}

type const* type::find_facet( facet_mask facet ) const {
  for ( type const *t = this; t; t = t->baseType_ )
    if ( t->facet_mask_ & facet )
      return t;
  return nullptr;
}

bool type::is_enum_valid( store::Item_t const &item ) const {
  FOR_EACH( enumeration_type, i, enumeration_ )
    if ( item->compare( *i ) == 0 )
      return true;
  return baseType_ ? baseType_->is_enum_valid( item ) : false;
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
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_BASE_TYPE,
        ERROR_PARAMS( k, name_, ZED( ILLEGAL_BASE_TYPE_MustBeX_4 ), kind_ )
      );
    }
    return;
  }

  zstring fq_baseType_str( baseType_str );
  type const *const baseType = s.fq_find_type( &fq_baseType_str );

  if ( baseType->kind_ != kind_ )
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_BASE_TYPE,
      ERROR_PARAMS(
        fq_baseType_str, name_, ZED( ILLEGAL_BASE_TYPE_MustBeX_4 ), kind_
      )
    );
  baseType_ = baseType;
}

void type::load_constraints( store::Item_t const &constraints_item ) {
  ASSERT_KIND( constraints_item, "$constraints", ARRAY );
  store::Iterator_t it( constraints_item->getArrayValues() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    ASSERT_TYPE( item, "constraint", XS_STRING );
    zstring constraint_str( item->getStringValue() );
    try {
      unique_ptr<constraint> c( new constraint( constraint_str ) );
      constraints_.push_back( c.get() );
      c.release();
    }
    catch ( ZorbaException const &e ) {
      ascii::replace_all( constraint_str, '\n', ' ' );
      ascii::normalize_space( constraint_str );
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_FACET_VALUE,
        ERROR_PARAMS(
          constraint_str, "$constraints",
          ZED( ILLEGAL_FACET_VALUE_BadConstraint_45 ),
          e.diagnostic().qname(), e.what()
        )
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
    if ( DECL_FACET_type( type, this, enumeration ) ) {
      bool found = false;
      FOR_EACH( enumeration_type, i, enumeration_type->enumeration_ ) {
        if ( item->compare( *i ) == 0 ) {
          found = true;
          break;
        }
      }
      if ( !found )
        throw XQUERY_EXCEPTION(
          jse::ILLEGAL_FACET_VALUE,
          ERROR_PARAMS(
            item->toString(), "$enumeration",
            ZED( ILLEGAL_FACET_VALUE_NoAddEnum_4 ),
            enumeration_type->name_
          )
        );
    }
    enumeration_.push_back( item );
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
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_NAMESPACE,
      ERROR_PARAMS( fq_name_str, s.get_namespace() )
    );
  if ( s.find_type( fq_name_str, false ) )
    throw XQUERY_EXCEPTION( jse::DUPLICATE_TYPE, ERROR_PARAMS( fq_name_str ) );
  name_ = fq_name_str;
}

void type::to_json( store::Item_t *result ) const {
  store::Item_t item;
  vector<store::Item_t> keys, values;
  ostringstream oss;
  zstring s;

  push_back( &keys, "$name" );
  push_back( &values, name_.empty() ? "<anonymous>" : name_.c_str() );

  push_back( &keys, "$kind" );
  oss << kind_;
  push_back( &values, oss.str() );

  if ( baseType_ && !baseType_->name_.empty() ) {
    push_back( &keys, "$baseType" );
    push_back( &values, baseType_->name_ );
  }

  if ( DECL_FACET_type( atomic, this, explicitTimezone ) ) {
    push_back( &keys, "$explicitTimezone" );
    oss << explicitTimezone_type->explicitTimezone_;
    push_back( &values, oss.str() );
  }
  if ( DECL_FACET_type( atomic, this, fractionDigits ) ) {
    push_back( &keys, "$fractionDigits" );
    GENV_ITEMFACTORY->createInteger(
      item, xs_integer( fractionDigits_type->fractionDigits_ )
    );
    values.push_back( item );
  }
  if ( DECL_FACET_type( atomic, this, maxExclusive ) ) {
    push_back( &keys, "$maxExclusive" );
    values.push_back( maxExclusive_type->maxExclusive_ );
  }
  if ( DECL_FACET_type( atomic, this, maxInclusive ) ) {
    push_back( &keys, "$maxInclusive" );
    values.push_back( maxInclusive_type->maxInclusive_ );
  }
  if ( DECL_FACET_type( min_max, this, maxLength ) ) {
    push_back( &keys, "$maxLength" );
    GENV_ITEMFACTORY->createInteger(
      item, xs_integer( maxLength_type->maxLength_ )
    );
    values.push_back( item );
  }
  if ( DECL_FACET_type( atomic, this, minInclusive ) ) {
    push_back( &keys, "$minInclusive" );
    values.push_back( minInclusive_type->minInclusive_ );
  }
  if ( DECL_FACET_type( atomic, this, minExclusive ) ) {
    push_back( &keys, "$minExclusive" );
    values.push_back( minExclusive_type->minExclusive_ );
  }
  if ( DECL_FACET_type( min_max, this, minLength ) ) {
    push_back( &keys, "$minLength" );
    GENV_ITEMFACTORY->createInteger(
      item, xs_integer( minLength_type->minLength_ )
    );
    values.push_back( item );
  }
  if ( DECL_FACET_type( object, this, open ) ) {
    push_back( &keys, "$open" );
    GENV_ITEMFACTORY->createBoolean( item, open_type->open_ );
    values.push_back( item );
  }
  if ( DECL_FACET_type( atomic, this, pattern ) ) {
    push_back( &keys, "$pattern" );
    s = pattern_type->pattern_;
    GENV_ITEMFACTORY->createString( item, s );
    values.push_back( item );
  }
  if ( DECL_FACET_type( atomic, this, totalDigits ) ) {
    push_back( &keys, "$totalDigits" );
    GENV_ITEMFACTORY->createInteger(
      item, xs_integer( totalDigits_type->totalDigits_ )
    );
    values.push_back( item );
  }

  GENV_ITEMFACTORY->createJSONObject( *result, keys, values );
}

bool type::validate( store::Item_t const &validate_item, bool do_cast,
                     store::Item_t *result ) const {
  DECL_FACET_type( type, this, enumeration );
  VALIDATE_FACET( enumeration,
    enumeration_type->is_enum_valid( validate_item ) );

  if ( DECL_FACET_type( type, this, constraints ) ) {
    dynamic_context dctx;
    store::Item_t ctx_item( validate_item );
    dctx.add_variable( dynamic_context::IDVAR_CONTEXT_ITEM, ctx_item );

    // we need these in the catch() clause below
    zstring const *query;
    type const *t;

    try {
      for ( t = constraints_type; t; t = t->baseType_ ) {
        FOR_EACH( constraints_type, i, t->constraints_ ) {
          constraint const *const c = *i;
          query = &c->query_;
          if ( !c->validate( dctx ) )
            RETURN_INVALID(
              jse::FACET_VIOLATION,
              ERROR_PARAMS(
                ZED( FACET_VIOLATION_BadConstraint_23o4o5o ),
                c->query_, t->name_
              )
            );
        } // FOR_EACH
      } // for
    }
    catch ( ZorbaException const &e ) {
      RETURN_INVALID(
        jse::FACET_VIOLATION,
        ERROR_PARAMS(
          ZED( FACET_VIOLATION_BadConstraint_23o4o5o ),
          *query, t->name_,
          e.diagnostic().qname(), e.what()
        )
      );
    }
  } // if

  return true;
}

///////////////////////////////////////////////////////////////////////////////

union_type::union_type() : type( k_union ) {
}

void union_type::assert_subtype_of( type const *t ) const {
  DECL_dynamic_cast( union, cast_t, t );
  FOR_EACH( content_type, u, content_ )
    (*u)->assert_subtype_of( t );
}

void union_type::load_baseType( store::Item_t const &baseType_item,
                                schema const& ) {
  if ( !!baseType_item )
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_KEY,
      ERROR_PARAMS( "$baseType", ZED( ILLEGAL_KEY_UnionNoBaseType ) )
    );
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
      load_content( value_item, s );
    else if ( ZSTREQ( key_str, "$enumeration" ) )
      load_enumeration( value_item );
    else if ( ZSTREQ( key_str, "$kind" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$name" ) )
      /* already handled */;
    else
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_KEY,
        ERROR_PARAMS( key_str, ZED( ILLEGAL_KEY_Type_34o ), kind_, name_ )
      );
  } // while
  it->close();

  if ( content_.empty() && baseType_ ) {
    DECL_baseType( union );
    content_ = baseType->content_;      // inherit baseType's content
  }
}

bool union_type::validate( store::Item_t const &validate_item, bool do_cast,
                           store::Item_t *result ) const {
  if ( !type::validate( validate_item, do_cast, result ) )
    return false;
  //
  // We can't pass "result" to nested called of validate() because:
  //
  //  * Typically, N-1 validations will fail, so we don't want N-1 annotation
  //    objects created for no reason (since we can't use them anyway).
  //
  //  * However, we still have to pass some temporary result object to the
  //    nested calls since the 1 validation that succeeds might fill in default
  //    value(s).
  //
  //  * But, we don't have to pass a temporary object if we're just validating
  //    and not annotating.
  //
  store::Item_t temp, *const temp_ptr = result ? &temp : nullptr;
  FOR_EACH( content_type, i, content_ )
    if ( (*i)->validate( validate_item, do_cast, temp_ptr ) ) {
      if ( result )
        result->transfer( temp );
      return true;
    }
  RETURN_INVALID(
    jse::TYPE_VIOLATION,
    ERROR_PARAMS(
      to_type_str( validate_item ), ZED( TYPE_VIOLATION_UnionMemberType )
    )
  );
}

///////////////////////////////////////////////////////////////////////////////

schema::schema( store::Item_t const &jsd_item ) {
  ASSERT_KIND( jsd_item, "JSound", OBJECT );
  load_namespace( require_value( jsd_item, "$namespace" ) );
  store::Item_t item( get_json_value( jsd_item, "$imports" ) );
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
    return load_type( type_item );
  throw XQUERY_EXCEPTION(
    jse::ILLEGAL_TYPE,
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
    throw XQUERY_EXCEPTION( jse::UNKNOWN_TYPE, ERROR_PARAMS( type_name ) );
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
      throw XQUERY_EXCEPTION( jse::UNKNOWN_PREFIX, ERROR_PARAMS( prefix ) );
    *type_name = "Q{" + i->second + '}' + local;
  } else if ( xml::split_uri_name( *type_name, uri, &local ) ) {
    // Do nothing since type_name is already a URIQualifiedName.
  } else {
    if ( !find_builtin_atomic_type( *type_name, false ) )
      *type_name = "Q{" + namespace_ + '}' + *type_name;
  }
}

void schema::import( zstring const &ns, schema *from ) {
  FOR_EACH( namespace_map, i, from->namespaces_ )
    namespaces_.insert( *i );
  MUTATE_EACH( type_list, i, from->types_ ) {
    types_.push_back( *i );
    //
    // Types must be null'd one at a time rather than simply calling
    // from->types_.clear() because, if an exception is thrown, two schema
    // objects won't be responsible for deleting the same type object.
    //
    *i = nullptr;
  }
  FOR_EACH( name_type_map, i, from->name_type_ )
    name_type_[ i->first ] = i->second;
}

void schema::load_import( store::Item_t const &import_item ) {
  ASSERT_KIND( import_item, "import", OBJECT );
  vector<zstring> schema_uris;

  // I'm not sure if this is correct, but not using the root context doesn't
  // work: base URI resolution beheves differently and URIs for JSound schemas
  // aren't found.
  static_context const *const sctx = &GENV_ROOT_STATIC_CONTEXT;

  store::Item_t const ns_item( require_value( import_item, "$namespace" ) );
  ASSERT_TYPE( ns_item, "$namespace", XS_STRING );
  zstring const ns_str( ns_item->getStringValue() );

  store::Item_t const prefix_item( require_value( import_item, "$prefix" ) );
  ASSERT_TYPE( prefix_item, "$prefix", XS_STRING );
  zstring const prefix_str( prefix_item->getStringValue() );
  if ( prefix_str.find( ':' ) != zstring::npos )
    throw XQUERY_EXCEPTION( jse::ILLEGAL_PREFIX, ERROR_PARAMS( prefix_str ) );
  if ( ztd::contains( prefix_ns_, prefix_str ) )
    throw XQUERY_EXCEPTION( jse::DUPLICATE_PREFIX, ERROR_PARAMS( prefix_str ) );
  prefix_ns_[ prefix_str ] = ns_str;

  zstring location_str;
  store::Item_t location_item( get_json_value( import_item, "$location" ) );
  if ( !!location_item ) {
    ASSERT_TYPE( location_item, "$location", XS_STRING );
    location_str = location_item->getStringValue();
    zstring const resolved( sctx->resolve_relative_uri( location_str ) );
    schema_uris.push_back( resolved );
  }

  namespace_map::const_iterator ns_i( namespaces_.find( ns_str ) );
  if ( ns_i != namespaces_.end() ) {
    zstring const &prev_location = ns_i->second;
    if ( location_str != prev_location )
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_FACET_VALUE,
        ERROR_PARAMS(
          location_str, "$location",
          ZED( ILLEGAL_FACET_VALUE_LocationMismatch_45 ),
          prev_location, ns_str
        )
      );
    return;                             // already imported
  }
  namespaces_[ ns_str ] = location_str;

  schema_uris.push_back( ns_str );      // must come after $location

  store::Iterator_t it( import_item->getObjectKeys() );
  store::Item_t item;
  it->open();
  while ( it->next( item ) ) {
    zstring const key_str( item->getStringValue() );
    store::Item_t const value_item( import_item->getObjectValue( item ) );
    if ( ZSTREQ( key_str, "$location" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$namespace" ) )
      /* already handled */;
    else if ( ZSTREQ( key_str, "$prefix" ) )
      /* already handled */;
    else
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_KEY, ERROR_PARAMS( key_str, "import" )
      );
  } // while
  it->close();

  unique_ptr<internal::Resource> rsrc;
  internal::StreamResource *stream_rsrc = nullptr;
  zstring error_msg;
  FOR_EACH( vector<zstring>, i, schema_uris ) {
    rsrc = sctx->resolve_uri( *i, internal::EntityData::SCHEMA, error_msg );
    stream_rsrc = dynamic_cast<internal::StreamResource*>( rsrc.get() );
    if ( stream_rsrc )
      break;
  }
  if ( !stream_rsrc )
    throw XQUERY_EXCEPTION(
      jse::SCHEMA_NOT_FOUND,
      ERROR_PARAMS( ns_str, location_str, error_msg )
    );
  json::loader loader( *stream_rsrc->getStream() );
  store::Item_t jsd;
  try {
    if ( !loader.next( &jsd ) )
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_SCHEMA,
        ERROR_PARAMS( ns_str, location_str )
      );
    schema schema_to_import( jsd );
    import( ns_str, &schema_to_import );
  }
  catch ( ZorbaException const &e ) {
    if ( e.diagnostic().qname() != "{" JSONIQ_ERR_NS "}" "JNDY0021" )
      throw;
    throw XQUERY_EXCEPTION(
      jse::ILLEGAL_SCHEMA,
      ERROR_PARAMS( ns_str, location_str, e.diagnostic().qname(), e.what() )
    );
  }
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

void schema::load_namespace( store::Item_t const &namespace_item ) {
  ASSERT_TYPE( namespace_item, "$namespace", XS_STRING );
  namespace_ = namespace_item->getStringValue();
}

void schema::load_top_type( store::Item_t const &type_item ) {
  store::Item_t const name_item( require_value( type_item, "$name" ) );
  type const *const t = load_type( type_item );
  zstring fq_name_str( name_item->getStringValue() );
  fq_type_name( &fq_name_str );
  name_type_[ fq_name_str ] = t;
}

type const* schema::load_type( store::Item_t const &type_item ) {
  type *const t = new_type( require_value( type_item, "$kind" ) );
  store::Item_t const name_item( get_json_value( type_item, "$name" ) );
  if ( !!name_item ) {
    // load name first so it's available for error messages
    t->load_name( name_item, *this );
  }
  t->load_baseType( get_json_value( type_item, "$baseType" ), *this );
  t->load_type( type_item, *this );
  return t;
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

type* schema::new_type( store::Item_t const &kind_item ) {
  ASSERT_TYPE( kind_item, "$kind", XS_STRING );
  zstring const kind_str( kind_item->getStringValue() );
  unique_ptr<type> t;
  switch ( find_kind( kind_str ) ) {
    case k_atomic: t.reset( new atomic_type ); break;
    case k_array : t.reset( new array_type  ); break;
    case k_object: t.reset( new object_type ); break;
    case k_union : t.reset( new union_type  ); break;
    default:
      throw XQUERY_EXCEPTION(
        jse::ILLEGAL_FACET_VALUE,
        ERROR_PARAMS( kind_str, "$kind", ZED( ILLEGAL_FACET_VALUE_MustBeAAOU ) )
      );
  } // switch
  types_.push_back( t.get() );
  return t.release();
}

bool schema::validate( store::Item_t const &json, char const *type_name,
                       bool do_cast, store::Item_t *result ) const {
  zstring fq_name_str( type_name );
  return fq_find_type( &fq_name_str )->validate( json, do_cast, result );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace jsound
} // namespace zorba

/* vim:set et sw=2 ts=2: */
