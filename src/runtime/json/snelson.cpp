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
#include "types/root_typemanager.h"
#include "util/ascii_util.h"
#include "util/cxx_util.h"
#include "util/indent.h"
#include "util/json_parser.h"
#include "util/mem_streambuf.h"
#include "util/omanip.h"
#include "util/oseparator.h"
#include "util/stl_util.h"

#include "snelson.h"

#define SNELSON_NS "http://john.snelson.org.uk/parsing-json-into-xquery"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static void add_type_attribute( store::Item *parent, char const *value ) {
  store::Item_t junk_item, att_name, type_name, value_item;
  GENV_ITEMFACTORY->createQName( att_name, "", "", "type" );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  zstring value_string( value );
  GENV_ITEMFACTORY->createString( value_item, value_string );
  GENV_ITEMFACTORY->createAttributeNode(
    junk_item, parent, att_name, type_name, value_item
  );
}

#define ADD_TYPE_ATTRIBUTE(T)             \
  do {                                    \
    if ( needs_type_attribute ) {         \
      add_type_attribute( cur_item, T );  \
      needs_type_attribute = false;       \
    }                                     \
  } while (0)

static void add_item_element( item_stack_type &item_stack,
                              state_stack_type &state_stack,
                              store::Item_t &cur_item,
                              char const *type ) {
  if ( !state_stack.empty() && state_stack.top() == in_array ) {
    store::Item_t element_name, type_name;
    zstring base_uri;
    store::NsBindings ns_bindings;
    GENV_ITEMFACTORY->createQName( element_name, SNELSON_NS, "", "item" );
    type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createElementNode(
      cur_item, item_stack.top(),
      element_name, type_name, false, false, ns_bindings, base_uri
    );
    add_type_attribute( cur_item.getp(), type );
  }
}

#define ADD_ITEM_ELEMENT(T) \
  add_item_element( item_stack, state_stack, cur_item, T );

static void escape_json_chars( zstring *s ) {
  ascii::replace_all( *s, "\"", 1, "\\\"", 2 );
  ascii::replace_all( *s, "\\", 1, "\\\\", 2 );
  ascii::replace_all( *s, "\b", 1, "\\b", 2 );
  ascii::replace_all( *s, "\f", 1, "\\f", 2 );
  ascii::replace_all( *s, "\n", 1, "\\n", 2 );
  ascii::replace_all( *s, "\r", 1, "\\r", 2 );
  ascii::replace_all( *s, "\t", 1, "\\t", 2 );
}

///////////////////////////////////////////////////////////////////////////////

namespace snelson {

void parse( json::parser &p, store::Item_t *result ) {
  ZORBA_ASSERT( result );

  state_stack_type state_stack;

  store::Item_t cur_item, junk_item, value_item;
  store::Item_t att_name, element_name, type_name;

  zstring base_uri;
  item_stack_type item_stack;
  bool needs_type_attribute = false;
  bool next_string_is_key = false;
  store::NsBindings ns_bindings;
  zstring value;

  json::token token;
  while ( p.next( &token ) ) {
    if ( !*result ) {
      GENV_ITEMFACTORY->createQName( element_name, SNELSON_NS, "", "json" );
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createElementNode(
        cur_item, nullptr,
        element_name, type_name, false, false, ns_bindings, base_uri
      );
      *result = cur_item;
      needs_type_attribute = true;
    }

    switch ( token.get_type() ) {

      case '[':
        PUSH_ITEM( cur_item );
        ADD_TYPE_ATTRIBUTE( "array" );
        ADD_ITEM_ELEMENT( "array" );
        PUSH_STATE( in_array );
        break;

      case '{':
        PUSH_ITEM( cur_item );
        ADD_TYPE_ATTRIBUTE( "object" );
        ADD_ITEM_ELEMENT( "object" );
        PUSH_STATE( in_object );
        next_string_is_key = true;
        break;

      case ']':
      case '}':
        POP_ITEM();
        POP_STATE();
        break;

      case ',':
        next_string_is_key = (state_stack.top() == in_object);
        break;

      case json::token::number:
        ADD_TYPE_ATTRIBUTE( "number" );
        ADD_ITEM_ELEMENT( "number" );
        value = token.get_value();
        GENV_ITEMFACTORY->createTextNode( junk_item, cur_item, value );
        break;

      case json::token::string:
        ADD_TYPE_ATTRIBUTE( "string" );
        value = token.get_value();
#if 0
        escape_json_chars( &value );
#endif

        if ( next_string_is_key ) {
          // <pair name="..." ...>
          GENV_ITEMFACTORY->createQName( element_name, SNELSON_NS, "", "pair" );
          type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
          GENV_ITEMFACTORY->createElementNode(
            cur_item, item_stack.top(),
            element_name, type_name, false, false, ns_bindings, base_uri
          );

          GENV_ITEMFACTORY->createQName( att_name, "", "", "name" );
          type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
          GENV_ITEMFACTORY->createString( value_item, value );
          GENV_ITEMFACTORY->createAttributeNode(
            junk_item, cur_item, att_name, type_name, value_item
          );

          needs_type_attribute = true;
          next_string_is_key = false;
        } else {
          ADD_ITEM_ELEMENT( "string" );
          GENV_ITEMFACTORY->createTextNode( junk_item, cur_item, value );
        }
        break;

      case 'F':
      case 'T':
        ADD_TYPE_ATTRIBUTE( "boolean" );
        ADD_ITEM_ELEMENT( "boolean" );
        value = token.get_type() == 'F' ? "false" : "true";
        GENV_ITEMFACTORY->createTextNode( junk_item, cur_item, value );
        break;

      case json::token::json_null:
        ADD_TYPE_ATTRIBUTE( "null" );
        ADD_ITEM_ELEMENT( "null" );
        break;

      case ':':
      case json::token::none:
        break;

      default:
        assert( false );
    } // switch
  } // while
}

} // namespace snelson

///////////////////////////////////////////////////////////////////////////////

static void assert_json_type( json::type t, zstring const &s ) {
  // Doing it this way uses the string data in-place with no copy.
  mem_streambuf::char_type *const p =
    const_cast<mem_streambuf::char_type*>( s.data() );
  mem_streambuf buf( p, s.size() );
  istringstream iss;
  iss.ios::rdbuf( &buf );

  json::lexer lex( iss );
  json::token token;
  try {
    if ( lex.next( &token ) && json::map_type( token.get_type() ) == t )
      return;
  }
  catch ( json::exception const& ) {
    // do nothing
  }
  throw XQUERY_EXCEPTION(
    zerr::ZJSE0008_BAD_VALUE,
    ERROR_PARAMS( s, t )
  );
}

static void require_attribute_value( store::Item_t const &element,
                                     char const *att_name,
                                     zstring *att_value ) {
  if ( !get_attribute_value( element, att_name, att_value ) )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0002_ELEMENT_MISSING_ATTRIBUTE,
      ERROR_PARAMS( element->getNodeName()->getStringValue(), att_name )
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
    case json::array :
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
  zstring temp( s );
  escape_json_chars( &temp );
  temp.insert( (zstring::size_type)0, 1, '"' );
  temp.append( 1, '"' );
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
  zstring const element_name( element->getNodeName()->getStringValue() );
  if ( element_name != "json" )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0004_BAD_ELEMENT,
      ERROR_PARAMS( element_name, "json" )
    );

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
  zstring const element_name( element->getNodeName()->getStringValue() );
  if ( element_name != "item" )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0005_BAD_CHILD_ELEMENT,
      ERROR_PARAMS( element_name, "array", "item" )
    );

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
  zstring const element_name( element->getNodeName()->getStringValue() );
  if ( element_name != "pair" )
    throw XQUERY_EXCEPTION(
      zerr::ZJSE0005_BAD_CHILD_ELEMENT,
      ERROR_PARAMS( element_name, "object", "pair" )
    );

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

    store::Iterator_t i = parent->getChildren();
    i->open();
    store::Item_t child;
    while ( i->next( child ) ) {
      o << sep;

      switch ( child->getNodeKind() ) {

        case store::StoreConsts::elementNode:
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
                zerr::ZJSE0006_NO_ELEMENT_CHILD,
                ERROR_PARAMS( json::type_string_of[ parent_type ] )
              );
          }
          break;

        case store::StoreConsts::textNode:
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
                zerr::ZJSE0007_NO_TEXT_CHILD,
                ERROR_PARAMS( json::type_string_of[ parent_type ] )
              );
          }
          break;

        default:
          // do nothing
          break;
      } // switch
    } // while
    i->close();
  }
  return o;
}

///////////////////////////////////////////////////////////////////////////////

namespace snelson {

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

} // namespace snelson

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
