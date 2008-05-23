#include "capi/dynamic_context.h"

#include <zorba/zorba.h>

using namespace zorba;

namespace zorbac {

  XQUERY_ERROR 
  DynamicContext::set_context_item (XQC_DynamicContext context, XQC_Item value)
  {
    try {
      zorba::DynamicContext* lContext = static_cast<zorba::DynamicContext*>(context->data); 
      zorba::Item* lItem = static_cast<zorba::Item*>(value->data);

      lContext->setContextItem(*lItem);

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
  }

  XQUERY_ERROR 
  DynamicContext::set_context_sequence(XQC_DynamicContext context, XQC_Sequence value)
  {
    return XQ_SUCCESS;
  }

  void
  DynamicContext::free(XQC_DynamicContext context)
  {
    try {
      delete context;
    } catch (ZorbaException& e) {
      assert(false);
    } catch (...) {
      assert(false);
    }
  }

} /* namespace zorbac */
