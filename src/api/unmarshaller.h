/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#pragma once
#ifndef ZORBA_UNMARSHALLER_H
#define ZORBA_UNMARSHALLER_H

#include <zorba/api_shared_types.h>
#include <zorba/zorba_string.h>

#include "store/api/iterator.h"
#include "common/shared_types.h"
#include "zorbatypes/zstring.h"

namespace zorba {

class ZORBA_DLL_PUBLIC Unmarshaller 
{
public:
  static store::Item* getInternalItem(const Item& aItem);

  static zstring& getInternalString(const String& aString);

  static String newString( zstring const &s ) {
    String::zstring_ptr const p = { &s };
    return String( p );
  }

  static static_context* getInternalStaticContext(const StaticContext_t& aContext);

  static dynamic_context* getInternalDynamicContext(DynamicContext* aContext);

  static store::Iterator_t getInternalIterator(Iterator* aIter);

};

} // namespace

#endif /* ZORBA_UNMARSHALLER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
