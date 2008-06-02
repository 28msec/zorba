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
      prepare(XQC_Implementation implementation, const char *query_string,
	    	      XQC_StaticContext context, XQC_Query_Ref query);

	    static XQUERY_ERROR 
      prepare_file(XQC_Implementation implementation, FILE *query_file,
	    	           XQC_StaticContext context, XQC_Query_Ref query);

	    static void 
      free(XQC_Implementation implementation);

      static XQUERY_ERROR
      create_item(XQC_Implementation implementation, XQC_Item_Ref item);

      static XQUERY_ERROR
      item_factory(XQC_Implementation implementation, XQC_ItemFactory_Ref factory);  

      static XQUERY_ERROR
      data_manager(XQC_Implementation implementation, XQC_DataManager_Ref data_manager);

      static void
      assign_functions(XQC_Implementation implementation);

  };
} /* namespace zorbac */

#endif
