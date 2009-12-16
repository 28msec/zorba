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
#include <sstream>
#include <zorba/zorba.h>
#include "capi/capi_util.h"
#include "capi/sequence.h"
#include "capi/error.h"

using namespace zorba;

#define DC_TRY try {
#define DC_CATCH \
    return XQC_NO_ERROR;              \
  } catch (ZorbaException &e) {     \
    return Error::convert_xquery_error(e.getErrorCode()); \
  } catch (...) {                   \
    return XQC_INTERNAL_ERROR;  \
  }

namespace zorbac {

  zorba::DynamicContext*
  getDynamicContext(XQC_DynamicContext* context)
  {
    return static_cast<zorba::DynamicContext*>(context->data);
  }

  XQC_Error 
  DynamicContext::set_context_item (XQC_DynamicContext* context, XQC_Sequence* value)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);
      zorbac::Sequence* lSeq = static_cast<zorbac::Sequence*>(value->data);
      zorba::Item lItem = lSeq->theItem;
      if (lItem.isNull()) {
        return XQC_NO_CURRENT_ITEM;
      }

      lContext->setContextItem(lItem);

    DC_CATCH
  }

  XQC_Error
  DynamicContext::set_context_document(XQC_DynamicContext* context, const char* doc_uri, FILE* document)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);

      std::stringstream* lStream = new std::stringstream();
      CAPIUtil::getIStream(document, *lStream); // must not throw

      lContext->setContextItemAsDocument(doc_uri, std::auto_ptr<std::istream>(lStream));
    DC_CATCH
  }
  

  XQC_Error
  DynamicContext::set_variable(XQC_DynamicContext* context, const char* qname, XQC_Sequence* seq)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);
      zorba::ResultIterator* lIter = static_cast<zorbac::Sequence*>(seq->data)->theSequence.get();

      lContext->setVariable(qname, lIter);
    DC_CATCH
  }
  
  XQC_Error
  DynamicContext::set_variable_document(XQC_DynamicContext* context, 
                                        const char* var_qname,
                                        const char* doc_uri, 
                                        FILE* document)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);

      std::stringstream* lStream = new std::stringstream();
      CAPIUtil::getIStream(document, *lStream); // must not throw

      lContext->setVariableAsDocument(var_qname, doc_uri, 
                                      std::auto_ptr<std::istream>(lStream)); // transfer ownership here
    DC_CATCH
  }
  
  XQC_Error 
  DynamicContext::set_implicit_timezone(XQC_DynamicContext* context, int timezone)
  {
    DC_TRY
      zorba::DynamicContext* lContext = getDynamicContext(context);

      lContext->setImplicitTimezone(timezone);
    DC_CATCH
  }
  
  void
  DynamicContext::free(XQC_DynamicContext* context)
  {
    try {
      //zorba::DynamicContext* lContext = getDynamicContext(context);
      delete context;
    } catch (ZorbaException&) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }

  void
  DynamicContext::assign_functions(XQC_DynamicContext* context)
  {
    context->set_context_item       = DynamicContext::set_context_item;
    context->set_context_document   = DynamicContext::set_context_document;
    context->set_variable           = DynamicContext::set_variable;
    context->set_variable_document  = DynamicContext::set_variable_document;
    context->set_implicit_timezone  = DynamicContext::set_implicit_timezone;
    context->free                   = DynamicContext::free;
  }

} /* namespace zorbac */
