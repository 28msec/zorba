#ifndef ZORBAC_DYNAMIC_CONTEXT_H
#define ZORBAC_DYNAMIC_CONTEXT_H

#include <zorba/zorbac.h>

namespace zorbac {

  class DynamicContext {
    public:
	    static XQUERY_ERROR 
      set_context_item (XQC_DynamicContext context, XQC_Item value);

	    static XQUERY_ERROR 
      set_context_sequence(XQC_DynamicContext context, XQC_Sequence value);

      static void
      free(XQC_DynamicContext context);

  }; /* class DynamicContext */

} /* namespace zorbac */

#endif
