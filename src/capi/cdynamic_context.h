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
#ifndef ZORBAC_CDYNAMIC_CONTEXT_H
#define ZORBAC_CDYNAMIC_CONTEXT_H

#include <zorba/zorbac.h>
#include <zorba/dynamic_context.h>

using namespace zorba;

namespace zorbac {

  class CDynamicContext {
    public:
      static XQC_Error 
      set_context_item (XQC_DynamicContext* context, XQC_Sequence* value);

      static XQC_Error
      set_variable(XQC_DynamicContext* context, const char* qname,
        XQC_Sequence* value);
      
      static XQC_Error 
      set_implicit_timezone(XQC_DynamicContext* context, int timezone);

      static XQC_Error
      set_error_handler(XQC_DynamicContext* context, XQC_ErrorHandler* handler);

      static XQC_Error
      get_error_handler(const XQC_DynamicContext* context, XQC_ErrorHandler** handler);

      static void
      free(XQC_DynamicContext* context);

      CDynamicContext(DynamicContext* ctx, XQC_ErrorHandler* handler);

      ~CDynamicContext();

      static CDynamicContext*
      get(const XQC_DynamicContext* ctx);

      DynamicContext*
      getCPP();

      XQC_DynamicContext*
      getXQC();

    private:
      XQC_DynamicContext                  theXQCDynamic;
      DynamicContext*                     theContext;
      XQC_ErrorHandler*                   theErrorHandler;
  }; /* class DynamicContext */

} /* namespace zorbac */

#endif
