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
#include "util/stl_util.h"

#include "jsonml_array.h"

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

using namespace std;

namespace zorba {
namespace jsonml_array {

///////////////////////////////////////////////////////////////////////////////

static void j2x_object( store::Item_t const &object_item,
                        store::Item_t *parent_xml_item ) {
  ZORBA_ASSERT( parent_xml_item );
  store::Iterator_t k( object_item->getObjectKeys() );
  k->open();
  store::Item_t junk_item, key_item, type_name;
  while ( k->next( key_item ) ) {
    store::Item_t att_name;
    GENV_ITEMFACTORY->createQName(
      att_name, "", "", key_item->getStringValue()
    );
    store::Item_t value_item( object_item->getObjectValue( key_item ) );
    zstring value_str( value_item->getStringValue() );
    GENV_ITEMFACTORY->createString( value_item, value_str );
    type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createAttributeNode(
      junk_item, *parent_xml_item, att_name, type_name, value_item
    );
  }
  k->close();
}

static store::Item_t j2x_array( store::Item_t const &array_item,
                                store::Item *parent_xml_item ) {
  zstring base_uri;
  store::NsBindings ns_bindings;
  store::Item_t array_elt_item, element_name, junk_item, type_name, xml_item;

  store::Iterator_t i( array_item->getArrayValues() );
  i->open();

  if ( !i->next( array_elt_item ) )
    throw XQUERY_EXCEPTION(
      zerr::ZJ2X0001_JSONML_ARRAY_BAD_JSON,
      ERROR_PARAMS( ZED( ZJ2X0001_EmptyArray ) )
    );
  if ( !array_elt_item->isAtomic() )
    throw XQUERY_EXCEPTION(
      zerr::ZJ2X0001_JSONML_ARRAY_BAD_JSON,
      ERROR_PARAMS( ZED( ZJ2X0001_Bad1stElement ) )
    );

  switch ( array_elt_item->getTypeCode() ) {
    case store::XS_ENTITY:
    case store::XS_ID:
    case store::XS_IDREF:
    case store::XS_NAME:
    case store::XS_NCNAME:
    case store::XS_NMTOKEN:
    case store::XS_NORMALIZED_STRING:
    case store::XS_STRING:
    case store::XS_TOKEN:
      break;
    default:
      throw XQUERY_EXCEPTION(
        zerr::ZJ2X0001_JSONML_ARRAY_BAD_JSON,
        ERROR_PARAMS( ZED( ZJ2X0001_Bad1stElement ) )
      );
  } // switch

  GENV_ITEMFACTORY->createQName(
    element_name, "", "", array_elt_item->getStringValue()
  );
  type_name = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  GENV_ITEMFACTORY->createElementNode(
    xml_item, parent_xml_item,
    element_name, type_name, false, false, ns_bindings, base_uri
  );

  bool did_attributes = false;
  while ( i->next( array_elt_item ) ) {
    switch ( array_elt_item->getKind() ) {
      case store::Item::ARRAY:
        j2x_array( array_elt_item, xml_item.getp() );
        break;
      case store::Item::ATOMIC: {
        zstring value_str( array_elt_item->getStringValue() );
        GENV_ITEMFACTORY->createTextNode( junk_item, xml_item, value_str );
        break;
      }
      case store::Item::OBJECT:
        if ( did_attributes )
          throw XQUERY_EXCEPTION(
            zerr::ZJ2X0001_JSONML_ARRAY_BAD_JSON,
            ERROR_PARAMS( ZED( ZJ2X0001_UnexpectedObject ) )
          );
        j2x_object( array_elt_item, &xml_item );
        did_attributes = true;
        break;
      default:
        throw XQUERY_EXCEPTION(
          zerr::ZJ2X0001_JSONML_ARRAY_BAD_JSON,
          ERROR_PARAMS( ZED( ZJ2X0001_BadElement ), array_elt_item->getKind() )
        );
    } // switch
  } // while

  i->close();
  return xml_item;
}

void json_to_xml( store::Item_t const &json_item, store::Item_t *xml_item ) {
  ZORBA_ASSERT( xml_item );
  switch ( json_item->getKind() ) {
    case store::Item::ARRAY:
      *xml_item = j2x_array( json_item, nullptr );
      break;
    case store::Item::OBJECT:
      throw XQUERY_EXCEPTION(
        zerr::ZJ2X0001_JSONML_ARRAY_BAD_JSON,
        ERROR_PARAMS( ZED( ZJ2X0001_ArrayRequired ) )
      );
    default:
      ZORBA_ASSERT( false );
  }
}

///////////////////////////////////////////////////////////////////////////////

static bool x2j_map_atomic_item( store::Item_t const &xml_item,
                                 store::Item_t *json_item ) {
  if ( xml_item->isAtomic() ) {
    switch ( xml_item->getTypeCode() ) {
      case store::JS_NULL:
      case store::XS_BOOLEAN:
      case store::XS_BYTE:
      case store::XS_DECIMAL:
      case store::XS_DOUBLE:
      case store::XS_ENTITY:
      case store::XS_FLOAT:
      case store::XS_ID:
      case store::XS_IDREF:
      case store::XS_INT:
      case store::XS_INTEGER:
      case store::XS_LONG:
      case store::XS_NAME:
      case store::XS_NCNAME:
      case store::XS_NEGATIVE_INTEGER:
      case store::XS_NMTOKEN:
      case store::XS_NON_NEGATIVE_INTEGER:
      case store::XS_NON_POSITIVE_INTEGER:
      case store::XS_NORMALIZED_STRING:
      case store::XS_POSITIVE_INTEGER:
      case store::XS_SHORT:
      case store::XS_STRING:
      case store::XS_TOKEN:
      case store::XS_UNSIGNED_BYTE:
      case store::XS_UNSIGNED_INT:
      case store::XS_UNSIGNED_LONG:
      case store::XS_UNSIGNED_SHORT:
        *json_item = xml_item;
        break;
      default:
        zstring s( xml_item->getStringValue() );
        GENV_ITEMFACTORY->createString( *json_item, s );
        break;
    } // switch
    return true;
  } // if
  return false;
}

static void x2j_attributes( store::Item_t const &element,
                            store::Item_t *json_item ) {
  ZORBA_ASSERT( json_item );

  store::Item_t att_item, item;
  vector<store::Item_t> keys, values;

  store::Iterator_t i( element->getAttributes() );
  i->open();
  while ( i->next( att_item ) ) {
    zstring att_name( name_of( att_item ) );
    if ( att_name == "xmlns" )
      continue;
    GENV_ITEMFACTORY->createString( item, att_name );
    keys.push_back( item );
    zstring att_value( att_item->getStringValue() );
    GENV_ITEMFACTORY->createString( item, att_value );
    values.push_back( item );
  } // while
  i->close();
  if ( !keys.empty() )
    GENV_ITEMFACTORY->createJSONObject( *json_item, keys, values );
}

// forward declaration
static void x2j_element( store::Item_t const &element,
                         store::Item_t *json_item );

static void x2j_children( store::Item_t const &parent,
                          vector<store::Item_t> *elements ) {
  ZORBA_ASSERT( elements );
  store::Iterator_t i( parent->getChildren() );
  i->open();
  store::Item_t child_item, temp_item;
  while ( i->next( child_item ) ) {
    if ( !x2j_map_atomic_item( child_item, &temp_item ) ) {
      if ( !child_item->isNode() )
        throw XQUERY_EXCEPTION(
          zerr::ZJ2X0001_JSONML_ARRAY_BAD_JSON,
          ERROR_PARAMS( ZED( ZJ2X0001_BadElement ), child_item->getKind() )
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
    elements->push_back( temp_item );
  } // while
  i->close();
}

static void x2j_element( store::Item_t const &element,
                         store::Item_t *json_item ) {
  ZORBA_ASSERT( json_item );
  store::Item_t name_item, attributes_item;
  vector<store::Item_t> elements;

  zstring name( name_of( element ) );
  GENV_ITEMFACTORY->createString( name_item, name );
  elements.push_back( name_item );
  x2j_attributes( element, &attributes_item );
  if ( !attributes_item.isNull() )
    elements.push_back( attributes_item );
  x2j_children( element, &elements );
  GENV_ITEMFACTORY->createJSONArray( *json_item, elements );
}

void xml_to_json( store::Item_t const &xml_item, store::Item_t *json_item ) {
  ZORBA_ASSERT( json_item );
  switch ( xml_item->getNodeKind() ) {
    case store::StoreConsts::documentNode:
      //x2j_children( xml_item, json_item );
      break;
    case store::StoreConsts::elementNode:
      x2j_element( xml_item, json_item );
      break;
    default:
      throw XQUERY_EXCEPTION( zerr::ZJSE0001_NOT_DOCUMENT_OR_ELEMENT_NODE );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace jsonml_array
} // namespace zorba
/* vim:set et sw=2 ts=2: */
