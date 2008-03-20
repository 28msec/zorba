#include "api/unmarshaller.h"

#include "api/staticcontextimpl.h"
#include "api/dynamiccontextimpl.h"


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

} /* namespace zorba */
