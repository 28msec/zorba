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

#include "capi/cexpression.h"

#include <memory>
#include <cassert>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/iterator.h>

#include "cdynamic_context.h"
#include "csequence.h"
#include "cstatic_context.h"
#include "error.h"

using namespace zorba;

#define CEXPR_TRY CAPI_TRY(CExpression,expr)
#define CEXPR_CATCH CAPI_CATCH

namespace zorbac {

  CExpression::CExpression(XQuery_t query, XQC_ErrorHandler* handler)
    : theMasterQuery(query), theErrorHandler(handler)
  {
    memset(&theXQCExpr, 0, sizeof (XQC_Expression));
    theXQCExpr.create_context        = CExpression::create_context;
    theXQCExpr.execute               = CExpression::execute;
    theXQCExpr.get_interface         = CExpression::get_interface;
    theXQCExpr.free                  = CExpression::free;
  }

  CExpression::~CExpression()
  {
  }

  CExpression*
  CExpression::get(const XQC_Expression* xqc)
  {
    return (CExpression*)
      (((char*)xqc) - CLASS_OFFSET(CExpression, theXQCExpr));
  }

  XQuery_t
  CExpression::getCPP()
  {
    return theMasterQuery;
  }

  XQC_Expression*
  CExpression::getXQC()
  {
    return &theXQCExpr;
  }

//   static int readSome(std::istream& stream, char *buffer, int maxlen)
//   {
//     stream.read(buffer, maxlen);
//     return stream.gcount();
//   }

  XQC_Error
  CExpression::create_context
  (const XQC_Expression* expr, XQC_DynamicContext** context)
  {
    CEXPR_TRY {
      // The Zorba C++ API has different semantics for compiled
      // queries and dynamic contexts. A Zorba XQuery has-a
      // DynamicContext. In order to support executing the same
      // XQC_Expression with different XQC_DynamicContexts, we must
      // clone() the original XQuery object and get the clone's
      // DynamicContext here. The CDynamicContext will then keep a
      // reference to this cloned XQuery so that we may execute that
      // one later.
      XQuery_t lClone = me->theMasterQuery->clone();
      DynamicContext* lContext = lClone->getDynamicContext();
      std::auto_ptr<CDynamicContext> lCCtx
        (new CDynamicContext(lContext, lClone, me->theErrorHandler));
      (*context) = lCCtx.release()->getXQC();
    }
    CEXPR_CATCH;
  }

//   XQC_Error 
//   CExpression::execute(XQC_Expression* query, FILE* file)
//   {
//     XQuery* lQuery = 0;
//     ZORBA_XQUERY_TRY
//       lQuery = getXQuery(query); 

//       std::stringstream lStream;
//       char lBuf[1024];

//       // TODO this is eager at the moment, we need a pull serializer
//       lStream << lQuery; 
//       lStream.seekg(0);

//       int lRes = 0;
//       while ( (lRes = readSome(lStream, lBuf, 1023)) > 0 ) {
//         lBuf[lRes] = 0;
//         fprintf (file, "%s", lBuf);
//       }
//     ZORBA_XQUERY_CATCH_NOTIFY
//   }

//   XQC_Error 
//   CExpression::serialize_file(XQC_Query* query, const Zorba_SerializerOptions_t* options, FILE* file)
//   {
//     XQuery* lQuery = 0;
//     ZORBA_XQUERY_TRY
//       lQuery = getXQuery(query);

//       std::stringstream lStream;
//       char lBuf[1024];

//       // TODO this is eager at the moment, we need a pull serializer
//       if (options)
//         lQuery->execute(lStream, options);
//       else
//         lQuery->execute(lStream);
//       lStream.seekg(0);

//       int lRes = 0;
// #ifdef WIN32
//       while ( (lRes = lStream._Readsome_s(lBuf, 1024, 1023)) > 0 ) {
// #else
//       while ( (lRes = lStream.readsome(lBuf, 1023)) > 0 ) {
// #endif
//         lBuf[lRes] = 0;
//         fprintf (file, "%s", lBuf);
//       }
//     ZORBA_XQUERY_CATCH_NOTIFY
//   }

//   XQC_Error 
//   CExpression::serialize_stream(XQC_Query* query, 
//                           const Zorba_SerializerOptions_t* options, 
//                           XQC_OutputStream stream)
//   {
//     XQuery* lQuery = 0; 
//     ZORBA_XQUERY_TRY
//       lQuery = getXQuery(query);

//       std::stringstream lStream;
//       char lBuf[1024];

//       // TODO this is eager at the moment, we need a pull serializer
//       if (options)
//         lQuery->execute(lStream, options);
//       else
//         lQuery->execute(lStream);
//       lStream.seekg(0);

//       int lRes = 0;
// #ifdef WIN32
//       while ( (lRes = lStream._Readsome_s(lBuf, 1024, 1023)) > 0 ) {
// #else
//       while ( (lRes = lStream.readsome(lBuf, 1023)) > 0 ) {
// #endif
//         lBuf[lRes] = 0;
//         stream->write(stream, lBuf, lRes);
//       }
//       stream->free(stream);
//     ZORBA_XQUERY_CATCH_NOTIFY
//   }


  XQC_Error 
  CExpression::execute
  (const XQC_Expression* expr, const XQC_DynamicContext* context,
    XQC_Sequence** sequence)
  {
    CEXPR_TRY {
      // If we are given an XQC_DynamicContext, we must use that
      // object's XQuery_t since it is the one which is associated
      // with the corresponding DynamicContext. If we are not given an
      // XQC_DynamicContext, we may execute the master XQuery_t.
      Iterator_t lIter;
      if (context == NULL) {
        SYNC_CODE(AutoMutex lock(&me->theMutex));
        lIter = me->theMasterQuery->iterator();
      }
      else {
        CDynamicContext* lCtx = CDynamicContext::get(context);
        SYNC_CODE(AutoMutex lock(&lCtx->theMutex));
        lIter = lCtx->getClonedXQuery()->iterator();
      }

      XQC_ErrorHandler* lHandler;
      if (context) {
        context->get_error_handler(context, &lHandler);
      }
      else {
        lHandler = me->theErrorHandler;
      }
      std::auto_ptr<CSequence> lSeq(new CSequence(lIter, lHandler));

      (*sequence) = lSeq.release()->getXQC();
    }
    CEXPR_CATCH;
  }

  void*
  CExpression::get_interface(const XQC_Expression* expr, const char* name)
  {
    // No custom interfaces
    return NULL;
  }

  void
  CExpression::free(XQC_Expression* expr)
  {
    try {
      CExpression* me = CExpression::get(expr);
      delete me;
    } catch (ZorbaException const&) {
      assert(false);
    } catch (...) {
      assert(false);
    }
  }

} /* namespace zorbac */
/* vim:set et sw=2 ts=2: */
