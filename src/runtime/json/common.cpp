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

#include "store/api/iterator.h"

#include "common.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool get_attribute_value( store::Item_t const &element, char const *att_name,
                          zstring *att_value ) {
  store::Iterator_t i( element->getAttributes() );
  bool found = false;
  i->open();
  store::Item_t att_item;
  while ( i->next( att_item ) ) {
    if ( att_item->getNodeName()->getStringValue() == att_name ) {
      att_item->getStringValue2( *att_value );
      found = true;
      break;
    }
  }
  i->close();
  return found;
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
