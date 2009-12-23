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
#include "capi/cimplementation.h"

#include <sstream>
#include <memory>

#include "capi/cexpression.h"
#include "capi/cstatic_context.h"
#include "capi/capi_util.h"
#include "capi/error.h"

#include "api/staticcontextimpl.h"
#include "api/xqueryimpl.h"

#include "context/static_context.h"


using namespace zorba;

#define CIMPL_TRY \
  XQC_ErrorHandler* handler = NULL;                     \
  CImplementation* me = CImplementation::get(impl);     \
  try

#define CIMPL_CATCH \
  catch (QueryException& qe) {             \
    if (handler) {                                                      \
      handler->error(handler, Error::convert_xquery_error(qe.getErrorCode()), \
        ZorbaException::getErrorCodeAsString(qe.getErrorCode()).c_str(), \
        qe.getDescription().c_str(),                                    \
        qe.getQueryURI().c_str(),                                       \
        qe.getLineBegin(),                                              \
        qe.getColumnBegin());                                           \
    }                                                                   \
    return Error::convert_xquery_error(qe.getErrorCode());              \
  } catch (ZorbaException &ze) {                                        \
    return Error::convert_xquery_error(ze.getErrorCode());              \
  } catch (...) {                                                       \
    return XQC_INTERNAL_ERROR;                                          \
  }                                                                     \
  return XQC_NO_ERROR


namespace zorbac {

  CImplementation::CImplementation(Zorba* aZorba)
    : theZorba(aZorba)
  {
    memset(&theXQCImpl, 0, sizeof (XQC_Implementation));
    theXQCImpl.create_context = CImplementation::create_context;
    theXQCImpl.prepare        = CImplementation::prepare;
    theXQCImpl.prepare_file   = CImplementation::prepare_file;
    theXQCImpl.prepare_stream = CImplementation::prepare_stream;
    theXQCImpl.free           = CImplementation::free;
  }

  CImplementation::~CImplementation()
  {
    theZorba->shutdown();
  }

  CImplementation*
  CImplementation::get(const XQC_Implementation* xqc)
  {
    return (CImplementation*)
      (((char*)xqc) - CLASS_OFFSET(CImplementation, theXQCImpl));
  }

  Zorba*
  CImplementation::getCPP()
  {
    return theZorba;
  }

  XQC_Implementation*
  CImplementation::getXQC()
  {
    return &theXQCImpl;
  }

  XQC_Error
  CImplementation::create_context
  (XQC_Implementation* impl, XQC_StaticContext** context)
  {
    CIMPL_TRY {
      // Create a C++ StaticContext, wrap in a CStaticContext, then
      // return the inner XQC_StaticContext
      StaticContext_t lContext = me->theZorba->createStaticContext();
      std::auto_ptr<CStaticContext> lCCtx(new CStaticContext(lContext, NULL));
      (*context) = lCCtx.release()->getXQC();
    }
    CIMPL_CATCH;
  }

  XQC_Error 
  CImplementation::prepare
  (XQC_Implementation* impl, const char* query_string,
    XQC_StaticContext* context, XQC_Expression** expr)
  {
    CIMPL_TRY {
      XQuery_t lQuery;
      if (context) {
        context->get_error_handler(context, &handler);
      }

      if (context) {
        StaticContext_t lContext = CStaticContext::get(context)->getCPP();
        // reference counting in the smartptr takes care of garbage collection
        lQuery = me->theZorba->compileQuery(query_string, lContext);
      } else {
        lQuery = me->theZorba->compileQuery(query_string);
      }

      std::auto_ptr<CExpression> lExpr(new CExpression(lQuery, handler));
      (*expr) = lExpr.release()->getXQC();
    }
    CIMPL_CATCH;
  }

  XQC_Error 
  CImplementation::prepare_file
  (XQC_Implementation* impl, FILE* query_file, XQC_StaticContext* context, 
    XQC_Expression** expr)
  {
    CIMPL_TRY {
      XQuery_t lQuery;
      if (context) {
        context->get_error_handler(context, &handler);
      }

      std::stringstream lStream;
      CAPIUtil::getIStream(query_file, lStream);

      if (context) {
        StaticContext_t lContext = CStaticContext::get(context)->getCPP();
        lQuery = me->theZorba->compileQuery(lStream, lContext);
      } else {
        lQuery = me->theZorba->compileQuery(lStream);
      }

      std::auto_ptr<CExpression> lExpr(new CExpression(lQuery, handler));
      (*expr) = lExpr.release()->getXQC();
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::prepare_stream
  (XQC_Implementation* impl, XQC_InputStream* stream,
    XQC_StaticContext* context, XQC_Expression **expr)
  {
    CIMPL_TRY { 
      XQuery_t lQuery;
      if (context) {
        context->get_error_handler(context, &handler);
      }

      std::stringstream lStream;
      {
        char lBuf[1024];
        memset(lBuf, 0, 1024);
        int lRead = 0;
        while ( (lRead = stream->read(stream, lBuf, 1024)) >= 1024 ) {
          lStream.write(lBuf, lRead);
        }
        if (lRead > 0) {
          assert (lRead < 1024);
          lStream.write(lBuf, lRead);
        }

        stream->free(stream);
        if (lRead == -1) {
          // QQQ right error?
          return XQC_STATIC_ERROR; 
        }
      }

      // QQQ refactor! duplicate code in three places!
      if (context) {
        StaticContext_t lContext = CStaticContext::get(context)->getCPP();
        lQuery = me->theZorba->compileQuery(lStream, lContext);
      } else {
        lQuery = me->theZorba->compileQuery(lStream);
      }

      std::auto_ptr<CExpression> lExpr(new CExpression(lQuery, handler));
      (*expr) = lExpr.release()->getXQC();
    }
    CIMPL_CATCH; 
  }

  void
  CImplementation::free(XQC_Implementation* impl)
  {
    try {
      CImplementation* me = CImplementation::get(impl);
      delete me;
    } catch (ZorbaException&) {
      assert(false);
    } catch (...) {
      assert(false);
    }
  }

} /* namespace zorbac */
