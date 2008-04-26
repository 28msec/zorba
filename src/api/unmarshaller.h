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
