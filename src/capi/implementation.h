#ifndef ZORBAC_IMPLEMENTATION_H
#define ZORBAC_IMPLEMENTATION_H

#include <zorba/zorbac.h>

namespace zorbac {

  class Implementation
  {
    public:
      static XQUERY_ERROR
      create_context(XQC_Implementation impl, XQC_StaticContext_Ref context);

	    static XQUERY_ERROR 
      compile(XQC_Implementation implementation, const char *query_string,
	    	      XQC_StaticContext context, XQC_Query_Ref query);

	    static XQUERY_ERROR 
      compile_file(XQC_Implementation implementation, FILE *query_file,
	    	           XQC_StaticContext context, XQC_Query_Ref query);

	    static void 
      free(XQC_Implementation implementation);

      static XQUERY_ERROR
      create_item(XQC_Implementation implementation, XQC_Item_Ref item);

      static XQUERY_ERROR
      create_string(XQC_Implementation implementation, const char* str, XQC_String_Ref res);

      static XQUERY_ERROR
      item_factory(XQC_Implementation implementation, XQC_ItemFactory_Ref factory);  

  };
} /* namespace zorbac */

#endif
