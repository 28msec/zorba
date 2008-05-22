#ifndef ZORBA_QUERY_H
#define ZORBA_QUERY_H

#include <zorba/zorbac.h>

namespace zorbac {

  class Query : public XQC_Query_s
  {
    public:
	    static XQUERY_ERROR
      get_dynamic_context(XQC_Query query, XQC_DynamicContext_Ref context);

	    static XQUERY_ERROR 
      execute(XQC_Query query, FILE*);

	    static XQUERY_ERROR 
      sequence(XQC_Query query, XQC_Sequence_Ref sequence);

	    static void 
      free(XQC_Query query);
  };

} /* namespace zorbac */
#endif
