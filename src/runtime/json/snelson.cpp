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
#include <string>

#include <zorba/diagnostic_list.h>
#include <zorba/internal/cxx_util.h>

#include "runtime/json/json.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "util/ascii_util.h"
#include "util/indent.h"
#include "util/json_parser.h"
#include "util/json_util.h"
#include "util/mem_streambuf.h"
#include "util/omanip.h"
#include "util/oseparator.h"
#include "util/stl_util.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/float.h"
#include "zorbatypes/integer.h"

#include "snelson.h"

#define SNELSON_NS "http://john.snelson.org.uk/parsing-json-into-xquery"

using namespace std;

namespace zorba {
namespace snelson {

///////////////////////////////////////////////////////////////////////////////

static void add_type_attribute( store::Item *parent, char const *value ) {
  store::Item_t junk_item, att_name, type_name, value_item;
  GENV_ITEMFACTORY->createQName( att_name, "", "", "type" );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  zstring value_str( value );
  GENV_ITEMFACTORY->createString( value_item, value_str );
  GENV_ITEMFACTORY->createAttributeNode(
    junk_item, parent, att_name, type_name, value_item
  );
}

#define ADD_TYPE_ATTRIBUTE(T)               \
  do {                                      \
    if ( needs_type_attribute ) {           \
      add_type_attribute( xml_item, (T) );  \
      needs_type_attribute = false;         \
    }                                       \
  } while (0)

static void add_item_element( item_stack_type &xml_item_stack,
                              store::Item_t &xml_item,
                              char const *type ) {
  zstring base_uri;
  store::Item_t element_name;
  store::NsBindings ns_bindings;

  GENV_ITEMFACTORY->createQName( element_name, SNELSON_NS, "", "item" );
  store::Item_t type_name( GENV_TYPESYSTEM.XS_UNTYPED_QNAME );
  GENV_ITEMFACTORY->createElementNode(
    xml_item, xml_item_stack.top(),
    element_name, type_name, false, false, ns_bindings, base_uri
  );
  add_type_attribute( xml_item.getp(), type );
  PUSH_ITEM( xml );
}

#define ADD_ITEM_ELEMENT(T)                               \
  do {                                                    \
    if ( IN_STATE( in_array ) )                           \
      add_item_element( xml_item_stack, xml_item, (T) );  \
  } while (0)

#define POP_ITEM_ELEMENT()      \
  do {                          \
    if ( IN_STATE( in_array ) ) \
      POP_ITEM( xml );          \
  } while (0)

static void add_pair_element( item_stack_type &xml_item_stack,
                              store::Item_t &xml_item,
                              zstring const &name ) {
  zstring base_uri;
  store::Item_t att_name, element_name, junk_item, name_item, type_name;
  store::NsBindings ns_bindings;

  GENV_ITEMFACTORY->createQName( element_name, SNELSON_NS, "", "pair" );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    xml_item, xml_item_stack.top(),
    element_name, type_name, false, false, ns_bindings, base_uri
  );

  GENV_ITEMFACTORY->createQName( att_name, "", "", "name" );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  zstring name_copy( name );
  GENV_ITEMFACTORY->createString( name_item, name_copy );
  GENV_ITEMFACTORY->createAttributeNode(
    junk_item, xml_item, att_name, type_name, name_item
  );
}

#define ADD_PAIR_ELEMENT(NAME)                            \
  do {                                                    \
    add_pair_element( xml_item_stack, xml_item, (NAME) ); \
    needs_type_attribute = true;                          \
  } while (0)

///////////////////////////////////////////////////////////////////////////////

void json_to_xml( store::Item_t const &item, store::Item_t *result ) {
  ZORBA_ASSERT( result );

  store::Item_t element_name, xml_item, junk_item, value_item;

  zstring base_uri;
  iterator_stack_type iterator_stack;
  item_stack_type json_item_stack, xml_item_stack;
  store::NsBindings ns_bindings;
  state_stack_type state_stack;

  GENV_ITEMFACTORY->createQName( element_name, SNELSON_NS, "", "json" );
  store::Item_t type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    xml_item, nullptr,
    element_name, type_name, false, false, ns_bindings, base_uri
  );
  bool needs_type_attribute = true;
  PUSH_ITEM( xml );
  *result = xml_item;

  store::Item_t json_item( item );
  PUSH_ITEM( json );

  store::Iterator_t cur_iter;
  switch ( json_item->getKind() ) {
    case store::Item::ARRAY:
      ADD_TYPE_ATTRIBUTE( "array" );
      cur_iter = json_item->getArrayValues();
      PUSH_STATE( in_array );
      break;
    case store::Item::OBJECT:
      ADD_TYPE_ATTRIBUTE( "object" );
      cur_iter = json_item->getObjectKeys();
      PUSH_STATE( in_object );
      break;
    default:
      ZORBA_ASSERT( false );
  }
  cur_iter->open();

  zstring value_str;

  while ( true ) {
    bool added_pair_element = false;
    if ( !cur_iter->next( value_item ) ) {
      cur_iter->close();
      if ( iterator_stack.empty() )
        break;
      POP_ITERATOR();
      POP_STATE();
      POP_ITEM_ELEMENT();
      if ( IN_STATE( in_object ) ) {
        POP_ITEM( xml );
        POP_ITEM( json );
      }
      continue;
    }
    if ( IN_STATE( in_object ) ) {
      ADD_PAIR_ELEMENT( value_item->getStringValue() );
      PUSH_ITEM( xml );
      value_item = json_item->getObjectValue( value_item );
      added_pair_element = true;
    }

    switch ( value_item->getKind() ) {

      case store::Item::ATOMIC:
        switch ( value_item->getTypeCode() ) {

          case store::JS_NULL:
            ADD_TYPE_ATTRIBUTE( "null" );
            ADD_ITEM_ELEMENT( "null" );
            POP_ITEM_ELEMENT();
            break;

          case store::XS_BOOLEAN:
            ADD_TYPE_ATTRIBUTE( "boolean" );
            ADD_ITEM_ELEMENT( "boolean" );
            value_str = value_item->getBooleanValue() ? "true" : "false";
            GENV_ITEMFACTORY->createTextNode( junk_item, xml_item, value_str );
            POP_ITEM_ELEMENT();
            break;

          case store::XS_BYTE:
          case store::XS_DECIMAL:
          case store::XS_DOUBLE:
          case store::XS_FLOAT:
          case store::XS_INT:
          case store::XS_INTEGER:
          case store::XS_LONG:
          case store::XS_NEGATIVE_INTEGER:
          case store::XS_NON_NEGATIVE_INTEGER:
          case store::XS_NON_POSITIVE_INTEGER:
          case store::XS_POSITIVE_INTEGER:
          case store::XS_SHORT:
          case store::XS_UNSIGNED_BYTE:
          case store::XS_UNSIGNED_INT:
          case store::XS_UNSIGNED_LONG:
          case store::XS_UNSIGNED_SHORT:
            ADD_TYPE_ATTRIBUTE( "number" );
            ADD_ITEM_ELEMENT( "number" );
            value_str = value_item->getStringValue();
            GENV_ITEMFACTORY->createTextNode( junk_item, xml_item, value_str );
            POP_ITEM_ELEMENT();
            break;

          default:
            ADD_TYPE_ATTRIBUTE( "string" );
            ADD_ITEM_ELEMENT( "string" );
            value_str = value_item->getStringValue();
            GENV_ITEMFACTORY->createTextNode( junk_item, xml_item, value_str );
            POP_ITEM_ELEMENT();
        } // switch
        break;

      case store::Item::ARRAY:
        if ( IN_STATE( in_object ) )
          PUSH_ITEM( xml );
        ADD_TYPE_ATTRIBUTE( "array" );
        ADD_ITEM_ELEMENT( "array" );
        PUSH_STATE( in_array );
        PUSH_ITERATOR( cur_iter );
        cur_iter = value_item->getArrayValues();
        cur_iter->open();
        break;

      case store::Item::OBJECT:
        if ( IN_STATE( in_object ) )
          PUSH_ITEM( xml );
        ADD_TYPE_ATTRIBUTE( "object" );
        ADD_ITEM_ELEMENT( "object" );
        PUSH_STATE( in_object );
        PUSH_ITEM( json );
        json_item = value_item;
        PUSH_ITERATOR( cur_iter );
        cur_iter = json_item->getObjectKeys();
        cur_iter->open();
        break;

      default:
        break;
    } // switch

    if ( added_pair_element )
      POP_ITEM( xml );
  } // while
}

///////////////////////////////////////////////////////////////////////////////

// forward declarations
static void x2j_item_element( store::Item_t const &item, store::Item_t *value );
static void x2j_object( store::Item_t const &parent, store::Item_t *object );
static void x2j_pair_element( store::Item_t const &pair, store::Item_t *key,
                              store::Item_t *value );
static void x2j_type( store::Item_t const &item, store::Item_t *value );

inline zstring element_name_of( store::Item_t const &element ) {
  return element->getNodeName()->getStringValue();
}

static void assert_element_name( store::Item_t const &element,
                                 char const *required_name ) {
  zstring const element_name( element_name_of( element ) );
  if ( element_name != required_name ) {
    zstring parent_type;
    if ( ::strcmp( required_name, "item" ) == 0 )
      parent_type = "array";
    else if ( ::strcmp( required_name, "pair" ) == 0 )
      parent_type = "object";
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0004_BAD_NODE,
      ERROR_PARAMS( element_name, parent_type, required_name )
    );
  }
}

static void assert_json_type( json::type t, zstring const &s,
                              json::token *ptoken = nullptr ) {
  // Doing it this way uses the string data in-place with no copy.
  mem_streambuf::char_type *const p =
    const_cast<mem_streambuf::char_type*>( s.data() );
  mem_streambuf buf( p, s.size() );
  istringstream iss;
  iss.ios::rdbuf( &buf );

  json::lexer lex( iss );
  json::token token;
  if ( !ptoken )
    ptoken = &token;
  try {
    if ( lex.next( ptoken ) && json::map_type( ptoken->get_type() ) == t )
      return;
  }
  catch ( json::exception const& ) {
    // do nothing
  }
  throw XQUERY_EXCEPTION(
    zerr::ZJSE0008_BAD_ELEMENT_VALUE,
    ERROR_PARAMS( s, t )
  );
}

static void require_attribute_value( store::Item_t const &element,
                                     char const *att_name,
                                     zstring *att_value ) {
  if ( !get_attribute_value( element, att_name, att_value ) )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0002_ELEMENT_MISSING_ATTRIBUTE,
      ERROR_PARAMS( element_name_of( element ), att_name )
    );
}

static json::type get_json_type( store::Item_t const &element,
                                 bool allow_all_types = true ) {
  zstring att_value;
  require_attribute_value( element, "type", &att_value );
  if ( att_value == "array" )
    return json::array;
  if ( att_value == "object" )
    return json::object;
  if ( allow_all_types ) {
    if ( att_value == "boolean" )
      return json::boolean;
    if ( att_value == "null" )
      return json::null;
    if ( att_value == "number" )
      return json::number;
    if ( att_value == "string" )
      return json::string;
  }
  throw XQUERY_EXCEPTION(
    zerr::ZJSE0003_BAD_ATTRIBUTE_VALUE,
    ERROR_PARAMS( att_value, "type" )
  );
}

static void x2j_array( store::Item_t const &parent, store::Item_t *array ) {
  vector<store::Item_t> elements;
  store::Iterator_t i( parent->getChildren() );
  i->open();
  store::Item_t child, element;
  while ( i->next( child ) ) {
    switch ( child->getNodeKind() ) {
      case store::StoreConsts::elementNode:
        x2j_item_element( child, &element );
        elements.push_back( element );
        break;
      case store::StoreConsts::commentNode:
      case store::StoreConsts::piNode:
        // ignore
        break;
      default:
        throw XQUERY_EXCEPTION(
          zerr::ZJSE0004_BAD_NODE,
          ERROR_PARAMS( child->getNodeKind(), json::array )
        );
    } // switch
  } // while
  i->close();
  GENV_ITEMFACTORY->createJSONArray( *array, elements );
}

static void x2j_boolean( store::Item_t const &parent, store::Item_t *boolean ) {
  bool got_value = false;
  store::Iterator_t i( parent->getChildren() );
  i->open();
  store::Item_t child;
  while ( i->next( child ) ) {
    switch ( child->getKind() ) {

      case store::Item::NODE:
        switch ( child->getNodeKind() ) {
          case store::StoreConsts::textNode: {
            zstring const s( child->getStringValue() );
            if ( got_value )
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0009_MULTIPLE_CHILDREN,
                ERROR_PARAMS( s, json::boolean )
              );
            if ( s == "false" )
              GENV_ITEMFACTORY->createBoolean( *boolean, false );
            else if ( s == "true" )
              GENV_ITEMFACTORY->createBoolean( *boolean, true );
            else
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0008_BAD_ELEMENT_VALUE,
                ERROR_PARAMS( s, json::boolean )
              );
            got_value = true;
            break;
          }
          case store::StoreConsts::commentNode:
          case store::StoreConsts::piNode:
            // ignore
            break;
          default:
            throw XQUERY_EXCEPTION(
              zerr::ZJSE0004_BAD_NODE,
              ERROR_PARAMS( child->getNodeKind(), json::boolean )
            );
        } // switch
        break;

      case store::Item::ATOMIC:
        switch ( child->getTypeCode() ) {
          case store::XS_BOOLEAN:
            if ( got_value )
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0009_MULTIPLE_CHILDREN,
                ERROR_PARAMS( child->getStringValue(), json::boolean )
              );
            *boolean = child;
            got_value = true;
            break;
          default:
            throw XQUERY_EXCEPTION(
              zerr::ZJSE0008_BAD_ELEMENT_VALUE,
              ERROR_PARAMS( child->getStringValue(), json::boolean )
            );
        } // switch
        break;

      default:
        throw XQUERY_EXCEPTION(
          zerr::ZJSE0004_BAD_NODE,
          ERROR_PARAMS( child->getKind(), json::boolean )
        );
    } // switch
  } // while
  i->close();
  if ( !got_value )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0007_ELEMENT_MISSING_VALUE,
      ERROR_PARAMS( element_name_of( parent ), json::boolean )
    );
}

static void x2j_item_element( store::Item_t const &item,
                              store::Item_t *value ) {
  assert_element_name( item, "item" );
  x2j_type( item, value );
}

static void x2j_json_element( store::Item_t const &element,
                              store::Item_t *json_item ) {
  assert_element_name( element, "json" );
  switch ( get_json_type( element, false ) ) {
    case json::array:
      x2j_array( element, json_item );
      break;
    case json::object:
      x2j_object( element, json_item );
      break;
    default:
      ZORBA_ASSERT( false );
  }
}

static void x2j_number( store::Item_t const &parent, store::Item_t *number ) {
  bool got_value = false;
  store::Iterator_t i( parent->getChildren() );
  i->open();
  store::Item_t child;
  while ( i->next( child ) ) {
    switch ( child->getKind() ) {

      case store::Item::NODE:
        switch ( child->getNodeKind() ) {
          case store::StoreConsts::textNode: {
            zstring const s( child->getStringValue() );
            if ( got_value )
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0009_MULTIPLE_CHILDREN,
                ERROR_PARAMS( s, json::number )
              );
            json::token token;
            assert_json_type( json::number, s, &token );
            switch ( token.get_numeric_type() ) {
              case json::token::integer:
                GENV_ITEMFACTORY->createInteger( *number, xs_integer( s ) );
                break;
              case json::token::decimal:
                GENV_ITEMFACTORY->createDecimal( *number, xs_decimal( s ) );
                break;
              case json::token::floating_point:
                GENV_ITEMFACTORY->createDouble( *number, xs_double( s ) );
                break;
              default:
                ZORBA_ASSERT( false );
            }
            got_value = true;
            break;
          }
          case store::StoreConsts::commentNode:
          case store::StoreConsts::piNode:
            // ignore
            break;
          default:
            throw XQUERY_EXCEPTION(
              zerr::ZJSE0004_BAD_NODE,
              ERROR_PARAMS( child->getNodeKind(), json::number )
            );
        } // switch
        break;

      case store::Item::ATOMIC:
        switch ( child->getTypeCode() ) {
          case store::XS_BYTE:
          case store::XS_DECIMAL:
          case store::XS_DOUBLE:
          case store::XS_FLOAT:
          case store::XS_INT:
          case store::XS_INTEGER:
          case store::XS_LONG:
          case store::XS_NEGATIVE_INTEGER:
          case store::XS_NON_NEGATIVE_INTEGER:
          case store::XS_NON_POSITIVE_INTEGER:
          case store::XS_POSITIVE_INTEGER:
          case store::XS_SHORT:
          case store::XS_UNSIGNED_BYTE:
          case store::XS_UNSIGNED_INT:
          case store::XS_UNSIGNED_LONG:
          case store::XS_UNSIGNED_SHORT:
            if ( got_value )
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0009_MULTIPLE_CHILDREN,
                ERROR_PARAMS( child->getStringValue(), json::number )
              );
            *number = child;
            got_value = true;
            break;
          default:
            throw XQUERY_EXCEPTION(
              zerr::ZJSE0008_BAD_ELEMENT_VALUE,
              ERROR_PARAMS( child->getStringValue(), json::number )
            );
        } // switch
        break;

      default:
        throw XQUERY_EXCEPTION(
          zerr::ZJSE0004_BAD_NODE,
          ERROR_PARAMS( child->getKind(), json::number )
        );
    } // switch
  } // while
  i->close();
  if ( !got_value )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0007_ELEMENT_MISSING_VALUE,
      ERROR_PARAMS( element_name_of( parent ), json::number )
    );
}

static void x2j_object( store::Item_t const &parent, store::Item_t *object ) {
  vector<store::Item_t> keys, values;
  store::Iterator_t i( parent->getChildren() );
  i->open();
  store::Item_t child, key, value;
  while ( i->next( child ) ) {
    switch ( child->getNodeKind() ) {
      case store::StoreConsts::elementNode:
        x2j_pair_element( child, &key, &value );
        keys.push_back( key );
        values.push_back( value );
        break;
      case store::StoreConsts::commentNode:
      case store::StoreConsts::piNode:
        // ignore
        break;
      default:
        throw XQUERY_EXCEPTION(
          zerr::ZJSE0004_BAD_NODE,
          ERROR_PARAMS( child->getNodeKind(), json::object )
        );
    } // switch
  } // while
  i->close();
  GENV_ITEMFACTORY->createJSONObject( *object, keys, values );
}

static void x2j_pair_element( store::Item_t const &pair, store::Item_t *key,
                              store::Item_t *value ) {
  assert_element_name( pair, "pair" );
  zstring key_name;
  require_attribute_value( pair, "name", &key_name );
  GENV_ITEMFACTORY->createString( *key, key_name );
  x2j_type( pair, value );
}

static void x2j_string( store::Item_t const &parent, store::Item_t *string ) {
  bool got_value = false;
  store::Iterator_t i( parent->getChildren() );
  i->open();
  store::Item_t child;
  while ( i->next( child ) ) {
    switch ( child->getKind() ) {

      case store::Item::NODE:
        switch ( child->getNodeKind() ) {
          case store::StoreConsts::textNode: {
            zstring value( child->getStringValue() );
            if ( got_value )
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0009_MULTIPLE_CHILDREN,
                ERROR_PARAMS( element_name_of( parent ), json::string )
              );
            GENV_ITEMFACTORY->createString( *string, value );
            got_value = true;
            break;
          }
          case store::StoreConsts::commentNode:
          case store::StoreConsts::piNode:
            // ignore
            break;
          default:
            throw XQUERY_EXCEPTION(
              zerr::ZJSE0004_BAD_NODE,
              ERROR_PARAMS( child->getNodeKind(), json::string )
            );
        }
        break;

      case store::Item::ATOMIC:
        switch ( child->getTypeCode() ) {
          case store::XS_ENTITY:
          case store::XS_ID:
          case store::XS_IDREF:
          case store::XS_NAME:
          case store::XS_NCNAME:
          case store::XS_NMTOKEN:
          case store::XS_NORMALIZED_STRING:
          case store::XS_STRING:
          case store::XS_TOKEN: {
            if ( got_value )
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0009_MULTIPLE_CHILDREN,
                ERROR_PARAMS( element_name_of( parent ), json::string )
              );
            *string = child;
            got_value = true;
            break;
          }
          default:
            throw XQUERY_EXCEPTION(
              zerr::ZJSE0008_BAD_ELEMENT_VALUE,
              ERROR_PARAMS( child->getStringValue(), json::string )
            );
        }
        break;

      default:
        throw XQUERY_EXCEPTION(
          zerr::ZJSE0004_BAD_NODE,
          ERROR_PARAMS( child->getKind(), json::string )
        );
    } // switch
  } // while
  i->close();
  if ( !got_value )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0007_ELEMENT_MISSING_VALUE,
      ERROR_PARAMS( element_name_of( parent ), json::boolean )
    );
}

static void x2j_type( store::Item_t const &xml_item,
                      store::Item_t *json_item ) {
  switch ( get_json_type( xml_item ) ) {
    case json::array:
      x2j_array( xml_item, json_item );
      break;
    case json::object:
      x2j_object( xml_item, json_item );
      break;
    case json::boolean:
      x2j_boolean( xml_item, json_item );
      break;
    case json::null:
      GENV_ITEMFACTORY->createJSONNull( *json_item );
      break;
    case json::number:
      x2j_number( xml_item, json_item );
      break;
    case json::string:
      x2j_string( xml_item, json_item );
      break;
    case json::none:
      ZORBA_ASSERT( false );
  } // switch
}

void xml_to_json( store::Item_t const &xml_item, store::Item_t *json_item ) {
  switch ( xml_item->getNodeKind() ) {
    case store::StoreConsts::documentNode:
      // TODO
      //serialize_children( xml_item, json::none );
      break;
    case store::StoreConsts::elementNode:
      x2j_json_element( xml_item, json_item );
      break;
    default:
      throw XQUERY_EXCEPTION( zerr::ZJSE0001_NOT_DOCUMENT_OR_ELEMENT_NODE );
  }
}

///////////////////////////////////////////////////////////////////////////////

void parse( json::parser &p, store::Item_t *result ) {
  ZORBA_ASSERT( result );

  store::Item_t junk_item, value_item, xml_item;
  store::Item_t att_name, element_name, type_name;

  zstring base_uri;
  bool got_something = false;
  item_stack_type xml_item_stack;
  bool needs_type_attribute = false;
  bool next_string_is_key = false;
  store::NsBindings ns_bindings;
  state_stack_type state_stack;
  zstring value_str;

  json::token token;
  while ( p.next( &token ) ) {
    got_something = true;

    if ( !*result ) {
      GENV_ITEMFACTORY->createQName( element_name, SNELSON_NS, "", "json" );
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createElementNode(
        xml_item, nullptr,
        element_name, type_name, false, false, ns_bindings, base_uri
      );
      *result = xml_item;
      needs_type_attribute = true;
      PUSH_ITEM( xml );
    }

    switch ( token.get_type() ) {

      case '[':
        if ( IN_STATE( in_object ) )
          PUSH_ITEM( xml );
        ADD_TYPE_ATTRIBUTE( "array" );
        ADD_ITEM_ELEMENT( "array" );
        PUSH_STATE( in_array );
        break;

      case '{':
        if ( IN_STATE( in_object ) )
          PUSH_ITEM( xml );
        ADD_TYPE_ATTRIBUTE( "object" );
        ADD_ITEM_ELEMENT( "object" );
        PUSH_STATE( in_object );
        next_string_is_key = true;
        break;

      case ']':
      case '}':
        POP_STATE();
        POP_ITEM_ELEMENT();
        if ( IN_STATE( in_object ) )
          POP_ITEM( xml );
        break;

      case ',':
        next_string_is_key = IN_STATE( in_object );
        break;

      case json::token::number:
        ADD_TYPE_ATTRIBUTE( "number" );
        ADD_ITEM_ELEMENT( "number" );
        value_str = token.get_value();
        GENV_ITEMFACTORY->createTextNode( junk_item, xml_item, value_str );
        POP_ITEM_ELEMENT();
        break;

      case json::token::string:
        ADD_TYPE_ATTRIBUTE( "string" );
        value_str = token.get_value();
        if ( next_string_is_key ) {
          ADD_PAIR_ELEMENT( value_str );
          next_string_is_key = false;
        } else {
          ADD_ITEM_ELEMENT( "string" );
          GENV_ITEMFACTORY->createTextNode( junk_item, xml_item, value_str );
          POP_ITEM_ELEMENT();
        }
        break;

      case 'F':
      case 'T':
        ADD_TYPE_ATTRIBUTE( "boolean" );
        ADD_ITEM_ELEMENT( "boolean" );
        value_str = token.get_type() == 'F' ? "false" : "true";
        GENV_ITEMFACTORY->createTextNode( junk_item, xml_item, value_str );
        POP_ITEM_ELEMENT();
        break;

      case json::token::json_null:
        ADD_TYPE_ATTRIBUTE( "null" );
        ADD_ITEM_ELEMENT( "null" );
        POP_ITEM_ELEMENT();
        break;

      case ':':
      case json::token::none:
        break;

      default:
        assert( false );
    } // switch
  } // while
  if ( !got_something )
    throw XQUERY_EXCEPTION( zerr::ZJPE0009_ILLEGAL_EMPTY_STRING );
}

///////////////////////////////////////////////////////////////////////////////

inline std::ostream& if_space_or_newline( std::ostream &o,
                                          whitespace::type ws ) {
  if ( ws == whitespace::some )
    o << ' ';
  else
    o << if_emit( ws == whitespace::indent, '\n' );
  return o;
}
DEF_OMANIP1( if_space_or_newline, whitespace::type )

static ostream& serialize_begin( ostream &o, json::type t,
                                 whitespace::type ws ) {
  switch ( t ) {
    case json::array:
      o << '[' << if_emit( ws, ' ' );
      break;
    case json::object:
      o << '{' << if_space_or_newline( ws ) << if_indent( ws, inc_indent );
      break;
    default:
      /* suppress warning */;
  }
  return o;
}
DEF_OMANIP2( serialize_begin, json::type, whitespace::type )

static ostream& serialize_end( ostream &o, json::type t, whitespace::type ws ) {
  switch ( t ) {
    case json::array:
      o << if_emit( ws, ' ' ) << ']';
      break;
    case json::object:
      o << if_space_or_newline( ws ) << if_indent( ws, dec_indent )
        << if_indent( ws, indent ) << '}';
      break;
    default:
      /* suppress warning */;
  }
  return o;
}
DEF_OMANIP2( serialize_end, json::type, whitespace::type )

static ostream& serialize_boolean( ostream &o, zstring const &s ) {
  assert_json_type( json::boolean, s );
  return o << s;
}
DEF_OMANIP1( serialize_boolean, zstring const& )

static ostream& serialize_number( ostream &o, zstring const &s ) {
  assert_json_type( json::number, s );
  return o << s;
}
DEF_OMANIP1( serialize_number, zstring const& )

static ostream& serialize_string( ostream &o, zstring const &s ) {
  ostringstream oss;
  oss << '"' << json::serialize( s ) << '"';
  string const temp( oss.str() );
  assert_json_type( json::string, temp );
  return o << temp;
}
DEF_OMANIP1( serialize_string, zstring const& )

static ostream& serialize_children( ostream&, store::Item_t const&, json::type,
                                    whitespace::type );
DEF_OMANIP3( serialize_children, store::Item_t const&, json::type,
             whitespace::type )

static ostream& serialize_json_element( ostream &o,
                                        store::Item_t const &element,
                                        whitespace::type ws ) {
  assert_element_name( element, "json" );
  json::type const t = get_json_type( element, false );
  return o
    << serialize_begin( t, ws )
    << serialize_children( element, t, ws )
    << serialize_end( t, ws );
}
DEF_OMANIP2( serialize_json_element, store::Item_t const&, whitespace::type )

static ostream& serialize_item_element( ostream &o,
                                        store::Item_t const &element,
                                        whitespace::type ws ) {
  assert_element_name( element, "item" );
  json::type const t = get_json_type( element );
  return o
    << serialize_begin( t, ws )
    << serialize_children( element, t, ws )
    << serialize_end( t, ws );
}
DEF_OMANIP2( serialize_item_element, store::Item_t const&, whitespace::type )

static ostream& serialize_pair_element( ostream &o,
                                        store::Item_t const &element,
                                        whitespace::type ws ) {
  assert_element_name( element, "pair" );
  zstring name_att_value;
  require_attribute_value( element, "name", &name_att_value );
  json::type const t = get_json_type( element );

  return o
    << if_indent( ws, indent ) << serialize_string( name_att_value )
    << if_emit( ws, ' ' ) << ':' << if_emit( ws, ' ' )
    << serialize_begin( t, ws )
    << serialize_children( element, t, ws )
    << serialize_end( t, ws );
}
DEF_OMANIP2( serialize_pair_element, store::Item_t const&, whitespace::type )

static ostream& serialize_children( ostream &o, store::Item_t const &parent,
                                    json::type parent_type,
                                    whitespace::type ws ) {
  if ( parent_type == json::null )
    o << "null";
  else {
    oseparator sep;
    if ( ws == whitespace::none )
      sep.sep( "," );
    else if ( ws == whitespace::some || parent_type == json::array )
      sep.sep( ", " );
    else
      sep.sep( ",\n" );

    store::Iterator_t i( parent->getChildren() );
    i->open();
    store::Item_t child;
    while ( i->next( child ) ) {
      switch ( child->getNodeKind() ) {

        case store::StoreConsts::elementNode:
          o << sep;
          switch ( parent_type ) {
            case json::none:
              o << serialize_json_element( child, ws );
              break;
            case json::array:
              o << serialize_item_element( child, ws );
              break;
            case json::object:
              o << serialize_pair_element( child, ws );
              break;
            default:
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0004_BAD_NODE,
                ERROR_PARAMS( "element", parent_type )
              );
          }
          break;

        case store::StoreConsts::textNode:
          o << sep;
          switch ( parent_type ) {
            case json::boolean:
              o << serialize_boolean( child->getStringValue() );
              break;
            case json::number:
              o << serialize_number( child->getStringValue() );
              break;
            case json::string:
              o << serialize_string( child->getStringValue() );
              break;
            default:
              throw XQUERY_EXCEPTION(
                zerr::ZJSE0004_BAD_NODE,
                ERROR_PARAMS( "text", parent_type )
              );
          }
          break;

        default:
          /* do nothing */;
      } // switch
    } // while
    i->close();
  }
  return o;
}

///////////////////////////////////////////////////////////////////////////////

void serialize( ostream &o, store::Item_t const &item, whitespace::type ws ) {
  switch ( item->getNodeKind() ) {
    case store::StoreConsts::documentNode:
      o << serialize_children( item, json::none, ws );
      break;
    case store::StoreConsts::elementNode:
      o << serialize_json_element( item, ws );
      break;
    default:
      throw XQUERY_EXCEPTION( zerr::ZJSE0001_NOT_DOCUMENT_OR_ELEMENT_NODE );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace snelson
} // namespace zorba
/* vim:set et sw=2 ts=2: */
