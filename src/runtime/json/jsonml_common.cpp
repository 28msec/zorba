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

#include "store/api/item_factory.h"

#include "jsonml_common.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool x2j_map_atomic( store::Item_t const &xml_item, store::Item_t *json_item ) {
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

///////////////////////////////////////////////////////////////////////////////

#if ZORBA_DEBUG_JSON

ostream& operator<<( ostream &o, parse_state s ) {
  static char const *const string_of[] = {
    "in_array",
    "in_object"
  };
  return o << string_of[ s ];
}

#endif /* ZORBA_DEBUG_JSON */

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
