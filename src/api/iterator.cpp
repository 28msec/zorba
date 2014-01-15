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

#include <zorba/item.h>
#include <zorba/iterator.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

int64_t Iterator::count() {
  int64_t count = 0;
  Item item;
  while ( next( item ) )
    ++count;
  return count;
}

bool Iterator::skip( int64_t count ) {
  Item item;
  bool more_items = true;
  while ( count > 0 && (more_items = next( item )) )
    --count;
  return more_items;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
