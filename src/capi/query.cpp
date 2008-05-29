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
#include "capi/query.h"

#include <memory>
#include <cassert>
#include <sstream>
#include <zorba/zorba.h>
#include "capi/dynamic_context.h"
#include "capi/static_context.h"
#include "capi/sequence.h"

using namespace zorba;

namespace zorbac {
      
  XQUERY_ERROR
  Query::get_dynamic_context(XQC_Query query, XQC_DynamicContext_Ref context)
  {
    try {
      XQuery* lQuery = static_cast<XQuery*>(query->data);
      std::auto_ptr<XQC_DynamicContext_s> lContext(new XQC_DynamicContext_s());

      lContext->data = lQuery->getDynamicContext();

      DynamicContext::assign_functions(lContext.get());

      (*context) = lContext.release();

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }


  XQUERY_ERROR
  Query::get_static_context(XQC_Query query, XQC_StaticContext_Ref context)
  {
    try {
      XQuery* lQuery = static_cast<XQuery*>(query->data);
      std::auto_ptr<XQC_StaticContext_s> lContext(new XQC_StaticContext_s());

      const zorba::StaticContext* lInnerContext = lQuery->getStaticContext();
      zorba::StaticContext_t lChildContext = lInnerContext->createChildContext();

      zorbac::StaticContext::assign_functions(lContext.get());

      (*context) = lContext.release();

      zorba::StaticContext* lChildContextPtr = lChildContext.get();
      lChildContextPtr->addReference();
      (*context)->data = lChildContextPtr;

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }

  XQUERY_ERROR 
  Query::execute(XQC_Query query, FILE* file)
  {
    XQuery* lQuery = static_cast<XQuery*>(query->data);

    std::stringstream lStream;
    char lBuf[1024];

    try {
      // TODO this is eager at the moment, we need a pull serializer
      lStream << lQuery; 
      lStream.seekg(0);

      int lRes = 0;
      while ( (lRes = lStream.readsome(lBuf, 1023)) > 0 ) {
        lBuf[lRes] = 0;
        fprintf (file, "%s", lBuf);
      }
      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }

	XQUERY_ERROR 
  Query::apply_updates(XQC_Query query)
  {
    try {
      XQuery* lQuery = static_cast<XQuery*>(query->data);

      lQuery->applyUpdates();

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }

  XQUERY_ERROR 
  Query::sequence(XQC_Query query, XQC_Sequence_Ref sequence)
  {
    XQuery* lQuery = static_cast<XQuery*>(query->data);

    std::auto_ptr<XQC_Sequence_s> lSeq(new XQC_Sequence_s());

    try {
      ResultIterator_t lResultSmart = lQuery->iterator();
      lResultSmart->open();

      Sequence::assign_functions(lSeq.get());

      (*sequence) = lSeq.release();
      zorba::ResultIterator* lIter = lResultSmart.get();
      lIter->addReference();
      (*sequence)->data = lIter;

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
  }

  void
  Query::free(XQC_Query query)
  {
    try {
      XQuery* lQuery = static_cast<XQuery*>(query->data);
      lQuery->removeReference();
      delete query;
    } catch (ZorbaException& e) {
      assert(false);
    } catch (...) {
      assert(false);
    }
  }

  void
  Query::assign_functions(XQC_Query query)
  {
    query->get_dynamic_context   = Query::get_dynamic_context;
    query->get_static_context    = Query::get_static_context;
    query->execute               = Query::execute;
    query->apply_updates         = Query::apply_updates;
    query->sequence              = Query::sequence;
    query->free                  = Query::free;
  }

} /* namespace zorbac */
