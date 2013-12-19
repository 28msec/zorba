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

#include "store/api/item_factory.h"
#include "system/globalenv.h"

#include "store_util.h"

using namespace std;

namespace zorba { 

///////////////////////////////////////////////////////////////////////////////

store::Item_t get_json_value( store::Item_t const &object,
                              char const *key ) {
  zstring key_str( key );
  store::Item_t key_item;
  GENV_ITEMFACTORY->createString( key_item, key_str );
  return object->getObjectValue( key_item );
}

void push_back( vector<store::Item_t> *v, char const *s ) {
  zstring s2( s );
  store::Item_t item;
  GENV_ITEMFACTORY->createString( item, s2 );
  v->push_back( item );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
