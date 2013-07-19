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
#include <zorba/internal/cxx_util.h>

#include "runtime/json/json.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "util/ascii_util.h"
#include "util/json_parser.h"
#include "util/json_util.h"
#include "util/mem_streambuf.h"
#include "util/omanip.h"
#include "util/oseparator.h"
#include "util/stl_util.h"
#include "util/xml_util.h"

#include "jsonml_array.h"

using namespace std;

namespace zorba {
namespace jsonml_array {

///////////////////////////////////////////////////////////////////////////////

inline void split_name( zstring const &name, zstring *prefix, zstring *local ) {
  if ( !xml::split_qname( name, prefix, local ) )
    throw XQUERY_EXCEPTION(
      zerr::ZJPE0008_ILLEGAL_QNAME,
      ERROR_PARAMS( name )
    );
}

namespace expect {
  enum type {
    none,
    element_name,
    attribute_name,
    attribute_value
  };
}

///////////////////////////////////////////////////////////////////////////////

void json_to_xml( store::Item_t const &json_item, store::Item_t *result ) {
  // TODO
}

void xml_to_json( store::Item_t const &xml_item, store::Item_t *result ) {
  // TODO
}

///////////////////////////////////////////////////////////////////////////////

// JsonML grammar
// Source: http://www.ibm.com/developerworks/library/x-jsonml/#N10138
//
// element
//     = '[' tag-name ',' attributes ',' element-list ']'
//     | '[' tag-name ',' attributes ']'
//     | '[' tag-name ',' element-list ']'
//     | '[' tag-name ']'
//     | json-string
//     ;
// tag-name
//     = json-string
//     ;
// attributes
//     = '{' attribute-list '}'
//     | '{' '}'
//     ;
// attribute-list
//     = attribute ',' attribute-list
//     | attribute
//     ;
// attribute
//     = attribute-name ':' attribute-value
//     ;
// attribute-name
//     = json-string
//     ;
// attribute-value
//     = json-string
//     ;
// element-list
//     = element ',' element-list
//     | element
//     ;

void parse( json::parser &p, store::Item_t *result ) {
  ZORBA_ASSERT( result );

  state_stack_type state_stack;

  store::Item_t junk_item, value_item, xml_item;
  store::Item_t att_name, element_name, type_name;

  zstring base_uri;
  bool got_something = false;
  expect::type expect_what = expect::none;
  store::NsBindings ns_bindings;
  zstring value_str;
  item_stack_type xml_item_stack;

  json::token token;
  while ( p.next( &token ) ) {
    got_something = true;
    switch ( token.get_type() ) {

      case '[':
        if ( expect_what )
          throw XQUERY_EXCEPTION(
            zerr::ZJPE0006_UNEXPECTED_TOKEN,
            ERROR_PARAMS( token )
          );
        PUSH_STATE( in_array );
        expect_what = expect::element_name;
        break;

      case '{':
        if ( expect_what )
          throw XQUERY_EXCEPTION(
            zerr::ZJPE0006_UNEXPECTED_TOKEN,
            ERROR_PARAMS( token )
          );
        if ( state_stack.empty() )
          throw XQUERY_EXCEPTION(
            zerr::ZJPE0010_JSONML_ARRAY_REQUIRES_BRACKET
          );
        PUSH_STATE( in_object );
        expect_what = expect::attribute_name;
        break;

      case ']':
        POP_ITEM( xml );
        // no break;
      case '}':
        POP_STATE();
        expect_what = expect::none;
        break;

      case ',':
        expect_what = IN_STATE( in_object ) ?
          expect::attribute_name : expect::none;
        break;

      case ':':
        expect_what = expect::attribute_value;
        break;

      case json::token::number:
      case 'F':
      case 'T':
      case json::token::json_null:
      case json::token::string: {
        value_str = token.get_value();
        zstring prefix, local;
        switch ( expect_what ) {
          case expect::element_name:
            split_name( value_str, &prefix, &local );
            GENV_ITEMFACTORY->createQName( element_name, "", prefix, local );
            type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
            GENV_ITEMFACTORY->createElementNode(
              xml_item,
              xml_item_stack.empty() ? nullptr : xml_item_stack.top(),
              element_name, type_name, false, false, ns_bindings, base_uri
            );
            PUSH_ITEM( xml );
            if ( !*result )
              *result = xml_item;
            break;
          case expect::attribute_name:
            split_name( value_str, &prefix, &local );
            GENV_ITEMFACTORY->createQName( att_name, "", prefix, local );
            break;
          case expect::attribute_value:
            type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
            GENV_ITEMFACTORY->createString( value_item, value_str );
            GENV_ITEMFACTORY->createAttributeNode(
              junk_item, xml_item, att_name, type_name, value_item
            );
            break;
          case expect::none:
            GENV_ITEMFACTORY->createTextNode( junk_item, xml_item, value_str );
            break;
        }
        break;
      }

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

static ostream& serialize_attributes( ostream &o, store::Item_t const &element,
                                      oseparator &sep, whitespace::type ws ) {
  bool emitted_attributes = false;
  oseparator att_sep;
  switch ( ws ) {
    case whitespace::none  : att_sep.sep( ","   ); break;
    case whitespace::some  : att_sep.sep( ", "  ); break;
    case whitespace::indent: att_sep.sep( ",\n" ); break;
  }

  store::Iterator_t i( element->getAttributes() );
  i->open();
  store::Item_t att_item;
  while ( i->next( att_item ) ) {
    zstring const att_name( att_item->getNodeName()->getStringValue() );
    if ( att_name == "xmlns" )
      continue;
    if ( !emitted_attributes ) {
      o << sep
        << if_emit( ws == whitespace::indent, '\n' )
        << if_indent( ws, indent ) << '{'
        << if_indent( ws, inc_indent );
      emitted_attributes = true;
    }
    bool const was_printing = att_sep.printing();
    o << att_sep;
    if ( was_printing )
      o << if_indent( ws, indent );
    else
      o << if_emit( ws, ' ' );
    
    o << '"' << att_name << '"'
      << if_emit( ws, ' ' ) << ':' << if_emit( ws, ' ' )
      << '"' << json::serialize( att_item->getStringValue() ) << '"';
  }
  i->close();
  if ( emitted_attributes )
    o << if_emit( ws, ' ' ) << '}' << if_indent( ws, dec_indent );
  return o;
}
DEF_OMANIP3( serialize_attributes, store::Item_t const&, oseparator&,
             whitespace::type )

static ostream& serialize_children( ostream&, store::Item_t const &parent,
                                    oseparator&, whitespace::type );
DEF_OMANIP3( serialize_children, store::Item_t const&, oseparator&,
             whitespace::type )

static ostream& serialize_element( ostream &o, store::Item_t const &element,
                                   oseparator &sep, whitespace::type ws ) {
  if ( sep.printing() )
    o << if_emit( ws == whitespace::indent, '\n' );
  sep.printing( true );
  o << if_indent( ws, indent ) << '[' << if_emit( ws, ' ' )
    << '"' << element->getNodeName()->getStringValue() << '"'
    << if_indent( ws, inc_indent )
    << serialize_attributes( element, sep, ws )
    << serialize_children( element, sep, ws )
    << if_emit( ws, ' ' ) << ']'
    << if_indent( ws, dec_indent );
  return o;
}
DEF_OMANIP3( serialize_element, store::Item_t const&, oseparator&,
             whitespace::type )

static ostream& serialize_children( ostream &o, store::Item_t const &parent,
                                    oseparator &sep, whitespace::type ws ) {
  store::Iterator_t i( parent->getChildren() );
  i->open();
  store::Item_t child;
  while ( i->next( child ) ) {
    switch ( child->getNodeKind() ) {
      case store::StoreConsts::elementNode:
        o << sep << serialize_element( child, sep, ws );
        break;
      case store::StoreConsts::textNode:
        o << sep << '"' << json::serialize( child->getStringValue() ) << '"';
        break;
      default:
        break;
    }
  }
  i->close();
  return o;
}

///////////////////////////////////////////////////////////////////////////////

void serialize( ostream &o, store::Item_t const &item, whitespace::type ws ) {
  oseparator sep;
  if ( ws )
    sep.sep( ", " );
  else
    sep.sep( "," );
  switch ( item->getNodeKind() ) {
    case store::StoreConsts::documentNode:
      o << serialize_children( item, sep, ws );
      break;
    case store::StoreConsts::elementNode:
      o << serialize_element( item, sep, ws );
      break;
    default:
      throw XQUERY_EXCEPTION( zerr::ZJSE0001_NOT_DOCUMENT_OR_ELEMENT_NODE );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace jsonml_array
} // namespace zorba
/* vim:set et sw=2 ts=2: */
