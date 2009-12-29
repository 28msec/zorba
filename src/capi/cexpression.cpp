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
#include "capi/cexpression.h"

#include <memory>
#include <cassert>
#include <sstream>
#include <zorba/zorba.h>
#include "capi/cdynamic_context.h"
#include "capi/cstatic_context.h"
#include "capi/csequence.h"
#include "capi/error.h"
#include "capi/capi_util.h"
#include "zorbaerrors/errors.h"

using namespace zorba;

#define CEXPR_TRY CAPI_TRY(CExpression,expr)
#define CEXPR_CATCH CAPI_CATCH

namespace zorbac {

  CExpression::CExpression(XQuery_t query, XQC_ErrorHandler* handler)
    : theQuery(query), theErrorHandler(handler)
  {
    memset(&theXQCExpr, 0, sizeof (XQC_Expression));
    theXQCExpr.create_context        = CExpression::create_context;
    theXQCExpr.execute               = CExpression::execute;
    theXQCExpr.get_interface         = CExpression::get_interface;
    theXQCExpr.free                  = CExpression::free;
  }

  CExpression::~CExpression() throw ()
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
    return theQuery;
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
      // Obtain the C++ DynamicContext, wrap in a CDynamicContext,
      // then return the inner XQC_DynamicContext
      DynamicContext* lContext = me->theQuery->getDynamicContext();
      std::auto_ptr<CDynamicContext> lCCtx
        (new CDynamicContext(lContext, me->theErrorHandler));
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
      ResultIterator_t lIter= me->theQuery->iterator();
      lIter->open();
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
    } catch (ZorbaException&) {
      assert(false);
    } catch (...) {
      assert(false);
    }
  }

} /* namespace zorbac */
