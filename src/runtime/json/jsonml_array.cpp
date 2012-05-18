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
#include "util/json_parser.h"
#include "util/mem_streambuf.h"
#include "util/omanip.h"
#include "util/oseparator.h"
#include "util/stl_util.h"

#include "jsonml_array.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static void split_name( zstring const &name, zstring *prefix, zstring *local ) {
  zstring::size_type const colon = name.find( ':' );
  if ( colon != zstring::npos ) {
    *prefix = name.substr( 0, colon );
    *local = name.substr( colon + 1 );
    if ( prefix->empty() || local->empty() )
      throw XQUERY_EXCEPTION(
        zerr::ZJPE0008_ILLEGAL_QNAME,
        ERROR_PARAMS( name )
      );
  } else {
    prefix->clear();
    *local = name;
  }
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

namespace jsonml_array {

void parse( json::parser &p, store::Item_t *result ) {
  ZORBA_ASSERT( result );

  state_stack_type state_stack;

  store::Item_t cur_item, junk_item, value_item;
  store::Item_t att_name, element_name, type_name;

  zstring base_uri;
  bool got_something = false;
  item_stack_type item_stack;
  expect::type expect_what = expect::none;
  store::NsBindings ns_bindings;
  zstring value;

  json::token token;
  while ( p.next( &token ) ) {
    got_something = true;
    switch ( token.get_type() ) {

      case '[':
        PUSH_STATE( in_array );
        expect_what = expect::element_name;
        break;

      case '{':
        if ( state_stack.empty() )
          throw XQUERY_EXCEPTION(
            zerr::ZJPE0010_JSONML_ARRAY_REQUIRES_BRACKET
          );
        PUSH_STATE( in_object );
        expect_what = expect::attribute_name;
        break;

      case ']':
        POP_ITEM();
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
        value = token.get_value();
        zstring prefix, local;
        switch ( expect_what ) {
          case expect::element_name:
            split_name( value, &prefix, &local );
            GENV_ITEMFACTORY->createQName( element_name, "", prefix, local );
            type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
            GENV_ITEMFACTORY->createElementNode(
              cur_item,
              item_stack.empty() ? nullptr : item_stack.top(),
              element_name, type_name, false, false, ns_bindings, base_uri
            );
            PUSH_ITEM( cur_item );
            if ( !*result )
              *result = cur_item;
            break;
          case expect::attribute_name:
            split_name( value, &prefix, &local );
            GENV_ITEMFACTORY->createQName( att_name, "", prefix, local );
            break;
          case expect::attribute_value:
            type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
            GENV_ITEMFACTORY->createString( value_item, value );
            GENV_ITEMFACTORY->createAttributeNode(
              junk_item, cur_item, att_name, type_name, value_item
            );
            break;
          case expect::none:
            GENV_ITEMFACTORY->createTextNode( junk_item, cur_item, value );
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

} // namespace jsonml_array

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
      << '"' << att_item->getStringValue() << '"';
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
        o << sep << '"' << child->getStringValue() << '"';
        break;
      default:
        break;
    }
  }
  i->close();
  return o;
}

///////////////////////////////////////////////////////////////////////////////

namespace jsonml_array {

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

} // namespace jsonml_array

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
