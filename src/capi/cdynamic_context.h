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
#pragma once
#ifndef ZORBAC_CDYNAMIC_CONTEXT_H
#define ZORBAC_CDYNAMIC_CONTEXT_H

#include <vector>
#include <zorba/zorbac.h>
#include <zorba/dynamic_context.h>
#include "zorbautils/mutex.h"
#include "common/common.h"

using namespace zorba;

namespace zorbac {

  class CDynamicContext {
    public:
      static XQC_Error 
      set_context_item(XQC_DynamicContext* context, XQC_Sequence* value);

      static XQC_Error
      get_context_item(const XQC_DynamicContext* context, XQC_Sequence** value);

      static XQC_Error
      set_variable(XQC_DynamicContext* context, const char* uri,
        const char* name, XQC_Sequence* value);
      
      static XQC_Error
      get_variable(const XQC_DynamicContext* context, const char* uri,
        const char* name, XQC_Sequence** value);
      
      static XQC_Error 
      set_implicit_timezone(XQC_DynamicContext* context, int timezone);

      static XQC_Error 
      get_implicit_timezone(const XQC_DynamicContext* context, int* timezone);

      static XQC_Error
      set_error_handler(XQC_DynamicContext* context, XQC_ErrorHandler* handler);

      static XQC_Error
      get_error_handler(const XQC_DynamicContext* context,
        XQC_ErrorHandler** handler);

      static void*
      get_interface(const XQC_DynamicContext* context, const char* name);

      static void
      free(XQC_DynamicContext* context);

      CDynamicContext(DynamicContext* ctx, XQuery_t clone,
        XQC_ErrorHandler* handler);

      ~CDynamicContext();

      static CDynamicContext*
      get(const XQC_DynamicContext* ctx);

      DynamicContext*
      getCPP();

      XQC_DynamicContext*
      getXQC();

      XQuery_t
      getClonedXQuery();

    private:
      XQC_DynamicContext                  theXQCDynamic;
      DynamicContext*                     theContext;

      /**
       * Each XQC_DynamicContext represents a *cloned* XQuery object,
       * since in the Zorba C++ API an XQuery has-a
       * DynamicContext. See CExpression.create_context() for more
       * details.
       */
      XQuery_t                            theCloneQuery;
      XQC_ErrorHandler*                   theErrorHandler;
      std::vector<XQC_Sequence*>          theBoundVariables;
      SYNC_CODE(mutable Mutex theMutex;)
      SYNC_CODE(friend class CExpression;)
  }; /* class DynamicContext */

} /* namespace zorbac */

#endif
/* vim:set et sw=2 ts=2: */
