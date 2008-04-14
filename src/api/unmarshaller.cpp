#include "api/unmarshaller.h"

#include "api/staticcontextimpl.h"
#include "api/dynamiccontextimpl.h"
#include "api/resultiteratorimpl.h"
#include "api/collectionimpl.h"
#include "store/api/collection.h"
#include "runtime/api/plan_wrapper.h"


namespace zorba {

  static_context*
  Unmarshaller::getInternalStaticContext(const StaticContext_t& aCtx)
  {
    return static_cast<StaticContextImpl*>(aCtx.get())->theCtx;
  }

  dynamic_context*
  Unmarshaller::getInternalDynamicContext(const DynamicContext_t& aCtx)
  {
    return static_cast<DynamicContextImpl*>(aCtx.get())->theCtx; 
  }

  PlanWrapper_t
  Unmarshaller::getInternalPlan(const ResultIterator_t& aResultIter)
  {
    return static_cast<ResultIteratorImpl*>(aResultIter.get())->thePlan;
  }

  store::Collection_t
  Unmarshaller::getInternalCollection(const Collection_t& aCollection)
  {
    return static_cast<CollectionImpl*>(aCollection.get())->theCollection; 
  }

} /* namespace zorba */
