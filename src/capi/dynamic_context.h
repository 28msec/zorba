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
#ifndef ZORBAC_DYNAMIC_CONTEXT_H
#define ZORBAC_DYNAMIC_CONTEXT_H

#include <zorba/zorbac.h>

namespace zorbac {

  class DynamicContext {
    public:
	    static XQUERY_ERROR 
      set_context_item (XQC_DynamicContext context, XQC_Item value);

      static XQUERY_ERROR
      set_context_document(XQC_DynamicContext context, FILE* document);

      static XQUERY_ERROR
      set_variable_item(XQC_DynamicContext context, XQC_String qname, XQC_Item value);
      
      static XQUERY_ERROR
      set_variable_sequence(XQC_DynamicContext context, XQC_String qname, XQC_Sequence value);
      
      static XQUERY_ERROR
      set_variable_document(XQC_DynamicContext context, XQC_String qname, FILE* document);
      
      static XQUERY_ERROR 
      set_implicit_timezone(XQC_DynamicContext context, int timezone);
      
      static XQUERY_ERROR
      set_default_collection(XQC_DynamicContext context, XQC_Item collection_uri);

      static void
      free(XQC_DynamicContext context);

      static void
      assign_functions(XQC_DynamicContext context);

  }; /* class DynamicContext */

} /* namespace zorbac */

#endif
