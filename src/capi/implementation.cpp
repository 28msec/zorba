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
#include "capi/implementation.h"

#include <sstream>
#include <memory>
#include <zorba/zorba.h>
#include "capi/query.h"
#include "capi/item.h"
#include "capi/item_factory.h"
#include "capi/static_context.h"
#include "capi/data_manager.h"
#include "capi/capi_util.h"
#include "api/staticcontextimpl.h"
#include "api/xqueryimpl.h"

using namespace zorba;

#define ZORBA_IMPLEMENTATION_TRY try {

#define ZORBA_IMPLEMENTATION_CATCH_NOTIFY \
    return XQ_NO_ERROR; \
    } catch (QueryException& qe) { \
      if (handler) { \
        handler->error(handler, qe.getErrorCode(), \
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

  XQUERY_ERROR
  Implementation::create_context(XQC_Implementation impl, XQC_StaticContext_Ref context)
  {
    try {
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_StaticContext_s> lContext(new XQC_StaticContext_s());
      std::auto_ptr<zorbac::StaticContext> lInnerContext(new zorbac::StaticContext());

      lInnerContext->theContext = lZorba->createStaticContext();

      zorbac::StaticContext::assign_functions(lContext.get());

      (*context) = lContext.release();
      (*context)->data = lInnerContext.release();

      return XQ_NO_ERROR;
    } catch (ZorbaException& e) {
      return e.getErrorCode(); 
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
  }

  XQUERY_ERROR 
  Implementation::prepare(XQC_Implementation impl, 
                          const char *query_string,
                          XQC_StaticContext context, 
                          XQC_ErrorHandler handler,
                          XQC_Query_Ref query)
  {
    ZORBA_IMPLEMENTATION_TRY
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_Query_s>   lQuery(new XQC_Query_s());
      std::auto_ptr<zorbac::Query> lInnerQuery(new zorbac::Query());
      if (handler)
        lInnerQuery->theErrorHandler = handler;

      if (context) {
        zorba::StaticContext_t lContext = 
              (static_cast<zorbac::StaticContext*> (context->data))->theContext;

        // reference counting in the smartptr takes care of garbage collection
        lInnerQuery->theQuery = lZorba->compileQuery(query_string, lContext);
      } else {
        lInnerQuery->theQuery = lZorba->compileQuery(query_string);
      }

      Query::assign_functions(lQuery.get());

      (*query)   = lQuery.release();
      (*query)->data = lInnerQuery.release(); 
    ZORBA_IMPLEMENTATION_CATCH_NOTIFY
  }

  XQUERY_ERROR 
  Implementation::prepare_file(XQC_Implementation impl, 
                               FILE *query_file,
                               XQC_StaticContext context, 
                               XQC_ErrorHandler handler,
                               XQC_Query_Ref query)
  {
    ZORBA_IMPLEMENTATION_TRY 
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_Query_s>   lQuery(new XQC_Query_s());
      std::auto_ptr<zorbac::Query> lInnerQuery(new zorbac::Query());
      if (handler)
        lInnerQuery->theErrorHandler = handler;

      std::stringstream lStream;
      CAPIUtil::getIStream(query_file, lStream);

      if (context) {
        zorba::StaticContext_t lContext = 
              (static_cast<zorbac::StaticContext*> (context->data))->theContext;
        lInnerQuery->theQuery = lZorba->compileQuery(lStream, lContext);
      } else {
        lInnerQuery->theQuery = lZorba->compileQuery(lStream);
      }

      Query::assign_functions(lQuery.get());

      *query   = lQuery.release();
      (*query)->data = lInnerQuery.release();

      return XQ_NO_ERROR;
    ZORBA_IMPLEMENTATION_CATCH_NOTIFY
  }

  XQUERY_ERROR
  Implementation::prepare_stream(XQC_Implementation impl, 
                                 XQC_InputStream stream,
                                 XQC_StaticContext context, 
                                 XQC_ErrorHandler handler,
                                 XQC_Query_Ref query)
  {
    ZORBA_IMPLEMENTATION_TRY 
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_Query_s> lQuery(new XQC_Query_s());
      std::auto_ptr<zorbac::Query> lInnerQuery(new zorbac::Query());
      if (handler)
        lInnerQuery->theErrorHandler = handler;

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
          return API0002_COMPILE_FAILED; 
        }
      }

      if (context) {
        zorba::StaticContext_t lContext = 
              (static_cast<zorbac::StaticContext*> (context->data))->theContext;
        lInnerQuery->theQuery = lZorba->compileQuery(lStream, lContext);
      } else {
        lInnerQuery->theQuery = lZorba->compileQuery(lStream);
      }

      Query::assign_functions(lQuery.get());

      *query   = lQuery.release();
      (*query)->data = lInnerQuery.release();

    ZORBA_IMPLEMENTATION_CATCH_NOTIFY 
  }

  void
  Implementation::free(XQC_Implementation impl)
  {
    try {
      Zorba* lZorba = static_cast<Zorba*>(impl->data);
      lZorba->shutdown();

      delete impl;
    } catch (ZorbaException &e) {
      assert(false);
    } catch (...) {
      assert(false);
    }
  }

  XQUERY_ERROR
  Implementation::create_item(XQC_Implementation impl, XQC_Item_Ref item)
  {
    try {
      std::auto_ptr<XQC_Item_s> lItem(new XQC_Item_s());
      std::auto_ptr<zorbac::Item> lInnerItem(new zorbac::Item());

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

      return XQ_NO_ERROR;
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }


  XQUERY_ERROR
  Implementation::item_factory(XQC_Implementation impl, XQC_ItemFactory_Ref factory)
  {
    try {
      std::auto_ptr<XQC_ItemFactory_s> lFactory(new XQC_ItemFactory_s());

      zorba::Zorba* lZorba = static_cast<zorba::Zorba*>(impl->data);
      
      ItemFactory::assign_functions(lFactory.get());

      (*factory) = lFactory.release();
      (*factory)->data = lZorba->getItemFactory();

      return XQ_NO_ERROR;
    } catch (ZorbaException& e) {
      return e.getErrorCode(); 
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
    
  }

  XQUERY_ERROR
  Implementation::data_manager(XQC_Implementation impl, XQC_DataManager_Ref data_manager)
  {
    try {
      std::auto_ptr<XQC_DataManager_s> lDataManager(new XQC_DataManager_s());

      zorba::Zorba* lZorba = static_cast<zorba::Zorba*>(impl->data);
      
      DataManager::assign_functions(lDataManager.get());

      (*data_manager) = lDataManager.release();
      (*data_manager)->data = lZorba->getXmlDataManager();

      return XQ_NO_ERROR;
    } catch (ZorbaException& e) {
      return e.getErrorCode(); 
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
  }

  void
  Implementation::assign_functions(XQC_Implementation impl)
  {
    impl->create_context = Implementation::create_context;
    impl->prepare        = Implementation::prepare;
    impl->prepare_file   = Implementation::prepare_file;
    impl->prepare_stream = Implementation::prepare_stream;
    impl->free           = Implementation::free;
    impl->create_item    = Implementation::create_item;
    impl->item_factory   = Implementation::item_factory;
    impl->data_manager   = Implementation::data_manager;
  }

} /* namespace zorbac */
