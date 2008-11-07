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
#include "zorbaerrors/errors.h"

using namespace zorba;

#define ZORBA_XQUERY_TRY try {

#define ZORBA_XQUERY_CATCH      \
     return XQ_NO_ERROR;             \
   } catch (ZorbaException& e) {  \
     return e.getErrorCode();       \
   } catch (...) {                \
     return XQP0019_INTERNAL_ERROR; \
   }

#define ZORBA_XQUERY_CATCH_NOTIFY \
    return XQ_NO_ERROR; \
    } catch (QueryException& qe) { \
      zorbac::Query* lInnerQuery = static_cast<zorbac::Query*>(query->data); \
      if (lInnerQuery->theErrorHandler) { \
        lInnerQuery->theErrorHandler->error(lInnerQuery->theErrorHandler, qe.getErrorCode(), \
                                 ZorbaException::getErrorCodeAsString(qe.getErrorCode()).c_str(), \
                                 qe.getDescription().c_str(), \
                                 qe.getQueryURI().c_str(), \
                                 qe.getLineBegin(), \
                                 qe.getColumnBegin()); \
      } \
      return qe.getErrorCode(); \
    } catch (ZorbaException &ze) { \
      return ze.getErrorCode(); \
    } catch (...) { \
      return XQP0019_INTERNAL_ERROR; \
    }

namespace zorbac {

  static int readSome(std::istream& stream, char *buffer, int maxlen)
  {
    stream.read(buffer, maxlen);
    return stream.gcount();
  }

  zorba::XQuery*
  getXQuery(XQC_Query query)
  {
    return (static_cast<zorbac::Query*>(query->data))->theQuery.get();
  }
      
  XQUERY_ERROR
  Query::get_dynamic_context(XQC_Query query, XQC_DynamicContext_Ref context)
  {
    ZORBA_XQUERY_TRY
      XQuery* lQuery = getXQuery(query);
      std::auto_ptr<XQC_DynamicContext_s> lContext(new XQC_DynamicContext_s());

      lContext->data = lQuery->getDynamicContext();

      DynamicContext::assign_functions(lContext.get());

      (*context) = lContext.release();
    ZORBA_XQUERY_CATCH
  }


  XQUERY_ERROR
  Query::get_static_context(XQC_Query query, XQC_StaticContext_Ref context)
  {
    ZORBA_XQUERY_TRY
      XQuery* lQuery = getXQuery(query);
      std::auto_ptr<XQC_StaticContext_s> lContext(new XQC_StaticContext_s());
      std::auto_ptr<zorbac::StaticContext> lNewContext(new zorbac::StaticContext());

      const zorba::StaticContext* lInnerContext = lQuery->getStaticContext();
      lNewContext->theContext = lInnerContext->createChildContext();

      zorbac::StaticContext::assign_functions(lContext.get());

      (*context) = lContext.release();
      (*context)->data = lNewContext.release();;
    ZORBA_XQUERY_CATCH
  }

  XQUERY_ERROR 
  Query::execute(XQC_Query query, FILE* file)
  {
    XQuery* lQuery = 0;
    ZORBA_XQUERY_TRY
      lQuery = getXQuery(query); 

      std::stringstream lStream;
      char lBuf[1024];

      // TODO this is eager at the moment, we need a pull serializer
      lStream << lQuery; 
      lStream.seekg(0);

      int lRes = 0;
      while ( (lRes = readSome(lStream, lBuf, 1023)) > 0 ) {
        lBuf[lRes] = 0;
        fprintf (file, "%s", lBuf);
      }
    ZORBA_XQUERY_CATCH_NOTIFY
  }

  XQUERY_ERROR 
  Query::serialize_file(XQC_Query query, const Zorba_SerializerOptions_t* options, FILE* file)
  {
    XQuery* lQuery = 0;
    ZORBA_XQUERY_TRY
      lQuery = getXQuery(query);

      std::stringstream lStream;
      char lBuf[1024];

      // TODO this is eager at the moment, we need a pull serializer
      if (options)
        lQuery->serialize(lStream, *options);
      else
        lQuery->serialize(lStream);
      lStream.seekg(0);

      int lRes = 0;
      while ( (lRes = lStream.readsome(lBuf, 1023)) > 0 ) {
        lBuf[lRes] = 0;
        fprintf (file, "%s", lBuf);
      }
    ZORBA_XQUERY_CATCH_NOTIFY
  }

  XQUERY_ERROR 
  Query::serialize_stream(XQC_Query query, 
                          const Zorba_SerializerOptions_t* options, 
                          XQC_OutputStream stream)
  {
    XQuery* lQuery = 0; 
    ZORBA_XQUERY_TRY
      lQuery = getXQuery(query);

      std::stringstream lStream;
      char lBuf[1024];

      // TODO this is eager at the moment, we need a pull serializer
      if (options)
        lQuery->serialize(lStream, *options);
      else
        lQuery->serialize(lStream);
      lStream.seekg(0);

      int lRes = 0;
      while ( (lRes = lStream.readsome(lBuf, 1023)) > 0 ) {
        lBuf[lRes] = 0;
        stream->write(stream, lBuf, lRes);
      }
      stream->free(stream);
    ZORBA_XQUERY_CATCH_NOTIFY
  }

  int
  Query::is_update_query(XQC_Query query)
  {
    ZORBA_XQUERY_TRY
      XQuery* lQuery = getXQuery(query);

      lQuery->isUpdateQuery();

    ZORBA_XQUERY_CATCH
  }

	XQUERY_ERROR 
  Query::apply_updates(XQC_Query query)
  {
    XQuery* lQuery = 0;
    ZORBA_XQUERY_TRY
      lQuery = getXQuery(query);

      lQuery->applyUpdates();

    ZORBA_XQUERY_CATCH_NOTIFY;
  }

  XQUERY_ERROR 
  Query::sequence(XQC_Query query, XQC_Sequence_Ref sequence)
  {
    XQuery* lQuery = 0;
    ZORBA_XQUERY_TRY
      lQuery = getXQuery(query);

      std::auto_ptr<XQC_Sequence_s> lSeq(new XQC_Sequence_s());
      std::auto_ptr<zorbac::Sequence> lInnerSequence(new zorbac::Sequence());

      lInnerSequence->theSequence = lQuery->iterator();
      lInnerSequence->theSequence->open();

      lInnerSequence->theErrorHandler = static_cast<zorbac::Query*>(query->data)->theErrorHandler;

      Sequence::assign_functions(lSeq.get());

      (*sequence) = lSeq.release();
      (*sequence)->data = lInnerSequence.release();;

    ZORBA_XQUERY_CATCH_NOTIFY
  }

  void
  Query::set_error_handler(XQC_Query query, XQC_ErrorHandler handler)
  {
    (static_cast<zorbac::Query*>(query->data))->theErrorHandler = handler;
  }

  void
  Query::free(XQC_Query query)
  {
    try {
      delete static_cast<zorbac::Query*>(query->data);
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
    query->serialize_file        = Query::serialize_file;
    query->serialize_stream      = Query::serialize_stream;
    query->is_update_query       = Query::is_update_query;
    query->apply_updates         = Query::apply_updates;
    query->sequence              = Query::sequence;
    query->set_error_handler     = Query::set_error_handler;
    query->free                  = Query::free;
  }

  Query::Query()
    : theErrorHandler(0)
  { }


} /* namespace zorbac */
