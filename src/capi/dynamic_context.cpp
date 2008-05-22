#include "capi/dynamic_context.h"

namespace zorbac {

  XQUERY_ERROR 
  DynamicContext::set_context_item (XQC_DynamicContext context, XQC_Item value)
  {
    return XQ_SUCCESS;
  }

  XQUERY_ERROR 
  DynamicContext::set_context_sequence(XQC_DynamicContext context, XQC_Sequence value)
  {
    return XQ_SUCCESS;
  }

} /* namespace zorbac */
