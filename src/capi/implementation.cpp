#include "capi/implementation.h"

#include <sstream>
#include <memory>
#include <zorba/zorba.h>
#include "capi/shared_wrapper.h"
#include "capi/query.h"
#include "capi/item.h"
#include "capi/string.h"
#include "capi/item_factory.h"

using namespace zorba;

namespace zorbac {

  XQUERY_ERROR
  Implementation::create_context(XQC_Implementation impl, XQC_StaticContext_Ref context)
  {
    return XQ_SUCCESS;
  }

  XQUERY_ERROR 
  Implementation::compile(XQC_Implementation impl, const char *query_string,
                          XQC_StaticContext context, XQC_Query_Ref query)
  {
    Zorba* lZorba = static_cast<Zorba*>(impl->data);
      // TODO static context

    std::auto_ptr<XQC_Query_s> lQuery(new XQC_Query_s());
    std::auto_ptr<SharedWrapper<XQuery> > lWrapper(new SharedWrapper<XQuery>());

    try {
      XQuery_t lQuerySmart = lZorba->compileQuery(query_string);
      lWrapper->theObject = lQuerySmart;

      lQuery->get_dynamic_context = Query::get_dynamic_context;
      lQuery->execute             = Query::execute;
      lQuery->sequence            = Query::sequence;
      lQuery->free                = Query::free;

      (*query)   = lQuery.release();
      (*query)->data = lWrapper.release();
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
    Zorba* lZorba = static_cast<Zorba*>(impl->data);

    std::auto_ptr<XQC_Query_s> lQuery(new XQC_Query_s());
    std::auto_ptr<SharedWrapper<XQuery> > lWrapper(new SharedWrapper<XQuery>());
    try {
      std::stringstream lStream;
      char lBuf[1024];
      size_t lSize;

      // TODO static context

      // TODO error checking
      while ((lSize = fread(lBuf, 1, 1024, query_file)) > 0) {
          lStream.write(lBuf, lSize);
      }
      XQuery_t lQuerySmart = lZorba->compileQuery(lStream);
      lWrapper->theObject = lQuerySmart;

      (*query)->get_dynamic_context = Query::get_dynamic_context;
      (*query)->execute             = Query::execute;
      (*query)->sequence            = Query::sequence;
      (*query)->free                = Query::free;

      *query   = static_cast<XQC_Query>(lQuery.release());
      (*query)->data = lWrapper.release();
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

      lItem->string_value = zorbac::Item::string_value;
      lItem->free         = zorbac::Item::free;

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

      lString->to_char      = zorbac::String::to_char;
      lString->free         = zorbac::String::free;

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
      
      lFactory->create_string    = zorbac::ItemFactory::create_string;
      lFactory->create_anyuri    = zorbac::ItemFactory::create_anyuri;
      lFactory->create_qname2    = zorbac::ItemFactory::create_qname2;
      lFactory->create_qname3    = zorbac::ItemFactory::create_qname3;
      lFactory->create_boolean   = zorbac::ItemFactory::create_boolean;
      lFactory->free             = zorbac::ItemFactory::free;

      (*factory) = lFactory.release();
      (*factory)->data = lZorba->getItemFactory();

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode(); 
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
    
  }

} /* namespace zorbac */
