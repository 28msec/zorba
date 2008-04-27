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
#ifndef ZORBA_UNMARSHALLER_H
#define ZORBA_UNMARSHALLER_H

#include <zorba/item.h>
#include <zorba/zorbastring.h>

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"

namespace zorba {

class Unmarshaller {
  public:
      static store::Item*        getInternalItem(const Item& aItem)       { return aItem.m_item;     }

      static xqpStringStore*     getInternalString(const String& aString) { return aString.m_string; }

      static static_context*     getInternalStaticContext(const StaticContext_t& aContext);

      static dynamic_context*    getInternalDynamicContext(const DynamicContext* aContext);

      static PlanWrapper_t       getInternalPlan(const ResultIterator_t& aResultIter);

      static store::Collection_t getInternalCollection(const Collection_t& aCollection);
};

}

#endif /* ZORBA_UNMARSHALLER_H */
