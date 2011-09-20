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
#include "stdafx.h"

#include "capi/cdynamic_context.h"

#include <cassert>
#include <sstream>
#include <string.h>
#include <zorba/zorba.h>
#include "capi/csequence.h"
#include "capi/error.h"
#include "capi/single_item_sequence.h"

using namespace zorba;
using namespace std;

#define DC_TRY CAPI_TRY(CDynamicContext, context)
#define DC_CATCH CAPI_CATCH


namespace zorbac {

  CDynamicContext::CDynamicContext
  (DynamicContext* ctx, XQuery_t clone, XQC_ErrorHandler* handler)
    : theContext(ctx), theCloneQuery(clone), theErrorHandler(handler)
  {
    memset(&theXQCDynamic, 0, sizeof (XQC_DynamicContext));
    theXQCDynamic.set_context_item     = CDynamicContext::set_context_item;
    theXQCDynamic.get_context_item     = CDynamicContext::get_context_item;
    theXQCDynamic.set_variable         = CDynamicContext::set_variable;
    theXQCDynamic.get_variable         = CDynamicContext::get_variable;
    theXQCDynamic.set_implicit_timezone= CDynamicContext::set_implicit_timezone;
    theXQCDynamic.get_implicit_timezone= CDynamicContext::get_implicit_timezone;
    theXQCDynamic.set_error_handler    = CDynamicContext::set_error_handler;
    theXQCDynamic.get_error_handler    = CDynamicContext::get_error_handler;
    theXQCDynamic.get_interface        = CDynamicContext::get_interface;
    theXQCDynamic.free                 = CDynamicContext::free;
  }

  CDynamicContext::~CDynamicContext()
  {
    vector<XQC_Sequence*>::iterator it;
    for (it = theBoundVariables.begin(); it < theBoundVariables.end(); it++) {
      (*it)->free(*it);
    }
  }

  CDynamicContext*
  CDynamicContext::get(const XQC_DynamicContext* xqc)
  {
    return (CDynamicContext*)
      (((char*)xqc) - CLASS_OFFSET(CDynamicContext, theXQCDynamic));
  }

  DynamicContext*
  CDynamicContext::getCPP()
  {
    return theContext;
  }

  XQuery_t
  CDynamicContext::getClonedXQuery()
  {
    return theCloneQuery;
  }

  XQC_DynamicContext*
  CDynamicContext::getXQC()
  {
    return &theXQCDynamic;
  }


XQC_Error 
CDynamicContext::set_context_item(
    XQC_DynamicContext* context,
    XQC_Sequence* value)
{
  DC_TRY {
    CSequence* lSeq = CSequence::get(value);
    Item lItem = lSeq->getCPPItem();
    if (lItem.isNull()) {
      return XQC_NO_CURRENT_ITEM;
    }
    
    me->theContext->setContextItem(lItem);
  }
  DC_CATCH;
}


XQC_Error
CDynamicContext::get_context_item(
    const XQC_DynamicContext* context,
    XQC_Sequence** value)
{
  DC_TRY {
    Item lItem;
    if (! me->theContext->getContextItem(lItem)) {
      return XQC_NO_CURRENT_ITEM;
    }
    std::auto_ptr<SingleItemSequence> lItemSeq(new SingleItemSequence(lItem));
    // Wrap in a CSequence to produce an XQC_Sequence. We pass
    // "true" to make CSequence assume memory-management
    // responsibility for the SingleItemSequence.
    std::auto_ptr<CSequence> lSeq(new CSequence(lItemSeq.get(), true, NULL));
    lItemSeq.release();
    (*value) = lSeq.release()->getXQC();
    return XQC_NO_ERROR;
  }
  DC_CATCH;
}
  

//   XQC_Error
//   CDynamicContext::set_context_document
//   (XQC_DynamicContext* context, const char* doc_uri, FILE* document)
//   {
//     DC_TRY
//       zorba::DynamicContext* lContext = getDynamicContext(context);

//       std::stringstream* lStream = new std::stringstream();
//       CAPIUtil::getIStream(document, *lStream); // must not throw

//       lContext->setContextItemAsDocument(doc_uri, std::auto_ptr<std::istream>(lStream));
//     DC_CATCH
//   }
  

XQC_Error
CDynamicContext::set_variable(
    XQC_DynamicContext* context,
    const char* uri,
    const char* name,
    XQC_Sequence* seq)
{
  DC_TRY 
  {
    CSequence* lSeq = CSequence::get(seq);
    Iterator_t lIter = lSeq->getCPPIterator();

    me->theContext->setVariable(uri == NULL ? "" : uri, name, lIter);

    // XQC claims that the XQC_DynamicContext takes ownership,
    // memory allocation-wise, of any XQC_Sequences passed to
    // set_variable(). This seems weird, but hey.
    me->theBoundVariables.push_back(seq);
  }
  DC_CATCH;
}


XQC_Error
CDynamicContext::get_variable(
    const XQC_DynamicContext* context,
    const char* uri,
    const char* name,
    XQC_Sequence** seq)
{
  DC_TRY 
  {
    Item lItem;
    Iterator_t lIter;
    if (! me->theContext->getVariable(uri, name, lItem, lIter)) {
      return XQC_INVALID_ARGUMENT;
    }

    // We could have gotten a single Item or an Iterator. We assume
    // the Item takes precedence if not null.
    if (! lItem.isNull()) {
      std::auto_ptr<SingleItemSequence> lItemSeq
        (new SingleItemSequence(lItem));
      // Wrap in a CSequence to produce an XQC_Sequence. We pass
      // "true" to make CSequence assume memory-management
      // responsibility for the SingleItemSequence.
      std::auto_ptr<CSequence> lSeq
        (new CSequence(lItemSeq.get(), true, NULL));
      
      lItemSeq.release();
      (*seq) = lSeq.release()->getXQC();
      return XQC_NO_ERROR;
    }
    
    // Otherwise, the Iterator must be the value.
    std::auto_ptr<CSequence> lSeq (new CSequence(lIter, me->theErrorHandler));
    (*seq) = lSeq.release()->getXQC();
    return XQC_NO_ERROR;
  }
  DC_CATCH;
}
  
//   XQC_Error
//   CDynamicContext::set_variable_document
//   (XQC_DynamicContext* context, const char* var_qname,
//     const char* doc_uri, FILE* document)
//   {
//     DC_TRY
//       zorba::DynamicContext* lContext = getDynamicContext(context);

//       std::stringstream* lStream = new std::stringstream();
//       CAPIUtil::getIStream(document, *lStream); // must not throw

//       lContext->setVariableAsDocument(var_qname, doc_uri, 
//                                       std::auto_ptr<std::istream>(lStream)); // transfer ownership here
//     DC_CATCH
//   }

  XQC_Error
  CDynamicContext::set_error_handler
  (XQC_DynamicContext* context, XQC_ErrorHandler* handler)
  {
    DC_TRY {
      me->theErrorHandler = handler;
    }
    DC_CATCH;
  }

  XQC_Error
  CDynamicContext::get_error_handler
  (const XQC_DynamicContext* context, XQC_ErrorHandler** handler)
  {
    DC_TRY {
      (*handler) = me->theErrorHandler;
    }
    DC_CATCH;
  }
  
  XQC_Error
  CDynamicContext::set_implicit_timezone
  (XQC_DynamicContext* context, int timezone)
  {
    DC_TRY {
      me->theContext->setImplicitTimezone(timezone);
    }
    DC_CATCH;
  }

  XQC_Error
  CDynamicContext::get_implicit_timezone
  (const XQC_DynamicContext* context, int* timezone)
  {
    DC_TRY {
      (*timezone) = me->theContext->getImplicitTimezone();
    }
    DC_CATCH;
  }

  void*
  CDynamicContext::get_interface
  (const XQC_DynamicContext* context, const char* name)
  {
    // No custom interfaces
    return NULL;
  }
 
  void
  CDynamicContext::free(XQC_DynamicContext* context)
  {
    try {
      CDynamicContext* me = CDynamicContext::get(context);
      delete me;
    } catch (ZorbaException const&) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }

} /* namespace zorbac */
/* vim:set et sw=2 ts=2: */
