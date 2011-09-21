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
#ifndef ZORBA_CEXPRESSION_H
#define ZORBA_CEXPRESSION_H

#include <zorba/zorbac.h>
#include <zorba/xquery.h>
#include "zorbautils/mutex.h"
#include "common/common.h"

using namespace zorba;

namespace zorbac {

  class CExpression
  {
    public:
      static XQC_Error
      create_context(const XQC_Expression* expr, XQC_DynamicContext** context);

      static XQC_Error 
      execute(const XQC_Expression* expr, const XQC_DynamicContext* ctx,
        XQC_Sequence** seq);

      static void*
      get_interface(const XQC_Expression* expr, const char *name);

      static void 
      free(XQC_Expression* expr);

      CExpression(XQuery_t query, XQC_ErrorHandler* handler);
      ~CExpression();

      static CExpression*
      get(const XQC_Expression* expr);

      XQuery_t
      getCPP();

      XQC_Expression*
      getXQC();

    private:
      XQC_Expression       theXQCExpr;
      XQuery_t             theMasterQuery;
      XQC_ErrorHandler*    theErrorHandler;
      SYNC_CODE(mutable Mutex theMutex;)
  };

} /* namespace zorbac */
#endif
/* vim:set et sw=2 ts=2: */
