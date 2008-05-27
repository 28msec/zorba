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
  DynamicContext::assign_functions(XQC_DynamicContext context)
  {
    context->set_context_item = DynamicContext::set_context_item;
    context->set_context_sequence = DynamicContext::set_context_sequence;
  }

} /* namespace zorbac */
