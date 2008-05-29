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
#include "capi/string.h"
#include "capi/item_factory.h"
#include "capi/static_context.h"
#include "api/staticcontextimpl.h"
#include "api/xqueryimpl.h"

using namespace zorba;

namespace zorbac {

  XQUERY_ERROR
  Implementation::create_context(XQC_Implementation impl, XQC_StaticContext_Ref context)
  {
    try {
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_StaticContext_s> lContext(new XQC_StaticContext_s());

      zorba::StaticContext_t lInnerContext = lZorba->createStaticContext();

      zorbac::StaticContext::assign_functions(lContext.get());

      (*context) = lContext.release();
      (*context)->data = lInnerContext.get();
      lInnerContext->addReference();

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode(); 
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
  }

  XQUERY_ERROR 
  Implementation::compile(XQC_Implementation impl, const char *query_string,
                          XQC_StaticContext context, XQC_Query_Ref query)
  {
    try {
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_Query_s> lQuery(new XQC_Query_s());

      XQuery_t lQuerySmart;
      if (context) {
        zorba::StaticContext* lContext = static_cast<zorba::StaticContext*> (context->data);

        // reference counting in the smartptr takes care of garbage collection
        lQuerySmart = lZorba->compileQuery(query_string, lContext);
      } else {
        lQuerySmart = lZorba->compileQuery(query_string);
      }

      Query::assign_functions(lQuery.get());

      (*query)   = lQuery.release();
      // get and reset never throw
      (*query)->data = lQuerySmart.get(); 
      lQuerySmart->addReference(); 

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode(); 
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
  }

  XQUERY_ERROR 
  Implementation::compile_file(XQC_Implementation impl, FILE *query_file,
                               XQC_StaticContext context, XQC_Query_Ref query)
  {
    try {
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_Query_s> lQuery(new XQC_Query_s());
      std::stringstream lStream;
      char lBuf[1024];
      size_t lSize;

      // TODO error checking
      while ((lSize = fread(lBuf, 1, 1024, query_file)) > 0) {
          lStream.write(lBuf, lSize);
      }

      XQuery_t lQuerySmart;
      if (context) {
        zorba::StaticContext* lContext = static_cast<zorba::StaticContext*>(context->data);
        zorba::StaticContext_t lContextCopy = lContext->createChildContext();
        lQuerySmart = lZorba->compileQuery(lStream, lContextCopy);
      } else {
        lQuerySmart = lZorba->compileQuery(lStream);
      }

      Query::assign_functions(lQuery.get());

      *query   = lQuery.release();
      (*query)->data = lQuerySmart.get();
      lQuerySmart->addReference();
      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode(); 
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
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
      std::auto_ptr<zorba::Item> lInnerItem(new zorba::Item());

      Item::assign_functions(lItem.get());

      (*item) = lItem.release();
      (*item)->data = lInnerItem.release();

      return XQ_SUCCESS;
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }

  XQUERY_ERROR
  Implementation::create_string(XQC_Implementation impl, const char* str, XQC_String_Ref res)
  {
    try {
      std::auto_ptr<XQC_String_s>  lString(new XQC_String_s());
      std::auto_ptr<zorba::String> lInnerString(str?new zorba::String(str):new zorba::String(""));

      String::assign_functions(lString.get());

      (*res) = lString.release();
      (*res)->data = lInnerString.release();

      return XQ_SUCCESS;
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

      return XQ_SUCCESS;
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
    impl->compile        = Implementation::compile;
    impl->compile_file   = Implementation::compile_file;
    impl->free           = Implementation::free;
    impl->create_item    = Implementation::create_item;
    impl->create_string  = Implementation::create_string;
    impl->item_factory   = Implementation::item_factory;
  }

} /* namespace zorbac */
