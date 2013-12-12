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
#include <zorba/store_consts.h>

#include "runtime/json/json.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "util/stl_util.h"
#include "zorbautils/store_util.h"

#include "common.h"
#include "jsonml_common.h"
#include "jsonml_object.h"

// JsonML ("object form") grammar.
//
// Note: there is no "object form" of JsonML.  In a JSON user group thread [1],
// Douglas Crockford incorrectly used the term "JsonML" to describe two
// variants: the "array form" and "object form."  This was a misuse of the term
// JsonML which has always *only* stood to mean what Crockford referred to as
// the "array form."
// 
// [1]: <http://groups.yahoo.com/neo/groups/json/conversations/topics/1115>
//
// element
//     = '{' tag-name ',' attributes ',' element-list '}'
//     | '{' tag-name ',' attributes '}'
//     | '{' tag-name ',' element-list '}'
//     | '{' tag-name '}'
//     ;
// tag-name
//     "tagName" ':' json-string
//     ;
// attributes
//     = attribute ',' attributes
//     | attribute
//     ;
// attribute
//     = attribute-name ':' attribute-value
//     ;
// attribute-name
//     = json-string
//     ;
// attribute-value
//     = json-item
//     ;
// element-list
//     = "childNodes" : '[' elements ']'
//     = "childNodes" : '[' ']'
//     ;
// elements
//    = element ',' elements
//    = element
//    ;

using namespace std;

namespace zorba {
namespace jsonml_object {

///////////////////////////////////////////////////////////////////////////////

// forward declaration
static store::Item_t j2x_object( store::Item_t const &object_item,
                                 store::Item_t *parent_xml_item );

static void j2x_array( store::Item_t const &array_item,
                       store::Item_t *parent_xml_item ) {
  store::Item_t item, junk_item;
  zstring value_str;

  store::Iterator_t i( array_item->getArrayValues() );
  i->open();
  while ( i->next( item ) ) {
    switch ( item->getKind() ) {
      case store::Item::ATOMIC:
        value_str = item->getStringValue();
        GENV_ITEMFACTORY->createTextNode(
          junk_item, parent_xml_item->get(), value_str
        );
        break;
      case store::Item::OBJECT:
        j2x_object( item, parent_xml_item );
        break;
      default:
        throw XQUERY_EXCEPTION(
          zerr::ZJ2X0002_JSONML_OBJECT_BAD_JSON,
          ERROR_PARAMS( ZED( ZJ2X0002_BadElement ), item->getKind() )
        );
    } // switch
  } // while
  i->close();
}

static store::Item_t j2x_object( store::Item_t const &object_item,
                                 store::Item_t *parent_xml_item ) {
  ZORBA_ASSERT( parent_xml_item );
  zstring base_uri;
  store::NsBindings ns_bindings;
  store::Item_t element_name, key_item, type_name, xml_item;

  store::Item_t name_item( get_json_value( object_item, "tagName" ) );
  if ( !name_item )
    throw XQUERY_EXCEPTION(
      zerr::ZJ2X0002_JSONML_OBJECT_BAD_JSON,
      ERROR_PARAMS( ZED( ZJ2X0002_tagNameRequired ) )
    );
  GENV_ITEMFACTORY->createQName(
    element_name, "", "", name_item->getStringValue()
  );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    xml_item, parent_xml_item->get(),
    element_name, type_name, false, false, ns_bindings, base_uri
  );

  store::Iterator_t k( object_item->getObjectKeys() );
  k->open();
  while ( k->next( key_item ) ) {
    zstring const key_str( key_item->getStringValue() );
    if ( key_str == "tagName" )
      continue; // already handled
    store::Item_t value_item( object_item->getObjectValue( key_item ) );
    if ( key_str == "childNodes" ) {
      if ( value_item->getKind() != store::Item::ARRAY )
        throw XQUERY_EXCEPTION(
          zerr::ZJ2X0002_JSONML_OBJECT_BAD_JSON,
          ERROR_PARAMS( ZED( ZJ2X0002_childNodesArrayRequired ) )
        );
      j2x_array( value_item, &xml_item );
    } else {
      store::Item_t att_name, junk_item;
      GENV_ITEMFACTORY->createQName( att_name, "", "", key_str );
      type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createAttributeNode(
        junk_item, xml_item, att_name, type_name, value_item
      );
    }
  } // while
  k->close();
  return xml_item;
}

void json_to_xml( store::Item_t const &json_item, store::Item_t *xml_item ) {
  ZORBA_ASSERT( xml_item );
  switch ( json_item->getKind() ) {
    case store::Item::ARRAY:
      throw XQUERY_EXCEPTION(
        zerr::ZJ2X0002_JSONML_OBJECT_BAD_JSON,
        ERROR_PARAMS( ZED( ZJ2X0002_ObjectRequired ) )
      );
    case store::Item::OBJECT:
      *xml_item = j2x_object( json_item, nullptr );
      break;
    default:
      ZORBA_ASSERT( false );
  }
}

///////////////////////////////////////////////////////////////////////////////

static void x2j_attributes( store::Item_t const &element,
                            vector<store::Item_t> *keys,
                            vector<store::Item_t> *values ) {
  ZORBA_ASSERT( keys );
  ZORBA_ASSERT( values );

  store::Iterator_t i( element->getAttributes() );
  store::Item_t att_item;
  i->open();
  while ( i->next( att_item ) ) {
    zstring const name( name_of( att_item ) );
    if ( name != "xmlns" ) {
      push_back( keys, name );
      push_back( values, att_item->getStringValue() );
    }
  } // while
  i->close();
}

// forward declaration
static void x2j_element( store::Item_t const &element,
                         store::Item_t *json_item );

static void x2j_children( store::Item_t const &parent,
                          vector<store::Item_t> *children ) {
  ZORBA_ASSERT( children );
  store::Iterator_t i( parent->getChildren() );
  i->open();
  store::Item_t child_item, temp_item;
  while ( i->next( child_item ) ) {
    if ( !x2j_map_atomic( child_item, &temp_item ) ) {
      if ( !child_item->isNode() )
        throw XQUERY_EXCEPTION(
          zerr::ZJ2X0002_JSONML_OBJECT_BAD_JSON,
          ERROR_PARAMS( ZED( ZJ2X0002_BadElement ), child_item->getKind() )
        );
      switch ( child_item->getNodeKind() ) {
        case store::StoreConsts::elementNode:
          x2j_element( child_item, &temp_item );
          break;
        case store::StoreConsts::textNode: {
          zstring s( child_item->getStringValue() );
          GENV_ITEMFACTORY->createString( temp_item, s );
          break;
        }
        default:
          continue;
      } // switch
    } // if
    children->push_back( temp_item );
  } // while
  i->close();
}

static void x2j_element( store::Item_t const &element,
                         store::Item_t *json_item ) {
  ZORBA_ASSERT( json_item );
  vector<store::Item_t> keys, values, children;

  push_back( &keys, "tagName" );
  push_back( &values, name_of( element ) );
  x2j_attributes( element, &keys, &values );
  x2j_children( element, &children );
  if ( !children.empty() ) {
    push_back( &keys, "childNodes" );
    store::Item_t temp;
    GENV_ITEMFACTORY->createJSONArray( temp, children );
    values.push_back( temp );
  }
  GENV_ITEMFACTORY->createJSONObject( *json_item, keys, values );
}

void xml_to_json( store::Item_t const &xml_item, store::Item_t *json_item ) {
  ZORBA_ASSERT( json_item );
  switch ( xml_item->getNodeKind() ) {
    case store::StoreConsts::elementNode:
      x2j_element( xml_item, json_item );
      break;
    default:
      throw XQUERY_EXCEPTION( zerr::ZJSE0001_NOT_ELEMENT_NODE );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace jsonml_object
} // namespace zorba
/* vim:set et sw=2 ts=2: */
