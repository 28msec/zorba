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

#include <cassert>
#include <zorba/zorba.h>

using namespace zorba;

#define DC_TRY try {
#define DC_CATCH \
    return XQ_SUCCESS;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }

namespace zorbac {

  zorba::DynamicContext*
  getDynamicContext(XQC_DynamicContext context)
  {
    return static_cast<zorba::DynamicContext*>(context->data);
  }

  XQUERY_ERROR 
  DynamicContext::set_context_item (XQC_DynamicContext context, XQC_Item value)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);
      zorba::Item* lItem = static_cast<zorba::Item*>(value->data);

      lContext->setContextItem(*lItem);

    DC_CATCH
  }

  XQUERY_ERROR
  DynamicContext::set_context_document(XQC_DynamicContext context, FILE* document)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);
    DC_CATCH
  }
  

  XQUERY_ERROR
  DynamicContext::set_variable_item(XQC_DynamicContext context, XQC_String qname, XQC_Item value)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);
      zorba::String* lQName = static_cast<zorba::String*>(value->data);
      zorba::Item* lItem = static_cast<zorba::Item*>(value->data);

      lContext->setVariable(*lQName, *lItem);

    DC_CATCH
  }
  
  XQUERY_ERROR
  DynamicContext::set_variable_sequence(XQC_DynamicContext context, XQC_String qname, XQC_Sequence seq)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);
      zorba::String* lQName = static_cast<zorba::String*>(qname->data);
      zorba::ResultIterator* lIter = static_cast<zorba::ResultIterator*>(seq->data);

      lContext->setVariable(*lQName, lIter);
    DC_CATCH
  }
  
  XQUERY_ERROR
  DynamicContext::set_variable_document(XQC_DynamicContext context, XQC_String qname, FILE* document)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);
    DC_CATCH
  }
  
  XQUERY_ERROR 
  DynamicContext::set_implicit_timezone(XQC_DynamicContext context, int timezone)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);

      lContext->setImplicitTimezone(timezone);
    DC_CATCH
  }
  
  XQUERY_ERROR
  DynamicContext::set_default_collection(XQC_DynamicContext context, XQC_Item collection_uri)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);

      zorba::Item* lItem = static_cast<zorba::Item*>(collection_uri->data);

      lContext->setDefaultCollection(*lItem);
    DC_CATCH
  }

  void
  DynamicContext::free(XQC_DynamicContext context)
  {
    try {
      zorba::DynamicContext* lContext = getDynamicContext(context);
      delete context;
    } catch (ZorbaException &e) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }

  void
  DynamicContext::assign_functions(XQC_DynamicContext context)
  {
    context->set_context_item       = DynamicContext::set_context_item;
    context->set_context_document   = DynamicContext::set_context_document;
    context->set_variable_item      = DynamicContext::set_variable_item;
    context->set_variable_sequence  = DynamicContext::set_variable_sequence;
    context->set_variable_document  = DynamicContext::set_variable_document;
    context->set_implicit_timezone  = DynamicContext::set_implicit_timezone;
    context->set_default_collection = DynamicContext::set_default_collection;
    context->free                   = DynamicContext::free;
  }

} /* namespace zorbac */
