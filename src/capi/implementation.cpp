#include "capi/implementation.h"

#include <sstream>
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
  }

  XQUERY_ERROR 
  Implementation::compile(XQC_Implementation impl, const char *query_string,
                          XQC_StaticContext context, XQC_Query_Ref query)
  {
    Zorba* lZorba = static_cast<Zorba*>(impl->data);
      // TODO static context

    try {
      XQuery_t lQuerySmart = lZorba->compileQuery(query_string);

      XQC_Query lQuery              = new XQC_Query_s();
      *query                        = static_cast<XQC_Query>(lQuery);
      (*query)->data                = new SharedWrapper<XQuery>(lQuerySmart);
      (*query)->get_dynamic_context = Query::get_dynamic_context;
      (*query)->execute             = Query::execute;
      (*query)->sequence            = Query::sequence;
      (*query)->free                = Query::free;

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

      XQC_Query lQuery              = new XQC_Query_s();
      *query                        = static_cast<XQC_Query>(lQuery);
      (*query)->data                = new SharedWrapper<XQuery>(lQuerySmart);
      (*query)->get_dynamic_context = Query::get_dynamic_context;
      (*query)->execute             = Query::execute;
      (*query)->sequence            = Query::sequence;
      (*query)->free                = Query::free;
      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode(); 
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
  }

  XQUERY_ERROR 
  Implementation::free(XQC_Implementation impl)
  {
    try {
      Zorba* lZorba = static_cast<Zorba*>(impl->data);
      lZorba->shutdown();

      delete impl;
      return XQ_SUCCESS;
    } catch (ZorbaException &e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }

  XQUERY_ERROR
  Implementation::create_item(XQC_Implementation impl, XQC_Item_Ref item)
  {
    zorba::Item* lInnerItem = 0;
    *item = 0;
    try {
      lInnerItem = new zorba::Item();
      *item = new XQC_Item_s();
      (*item)->data = lInnerItem;

      (*item)->string_value = zorbac::Item::string_value;
      (*item)->free         = zorbac::Item::free;

      return XQ_SUCCESS;
    } catch (...) {
      delete lInnerItem;
      delete item;
      return XQP0019_INTERNAL_ERROR;
    }
  }

  XQUERY_ERROR
  Implementation::create_string(XQC_Implementation impl, const char* str, XQC_String_Ref res)
  {
    zorba::String* lInnerString = 0;
    *res = 0;
    try {
      if (!str)
        lInnerString = new zorba::String("");
      else
        lInnerString = new zorba::String(str);
      *res = new XQC_String_s();
      (*res)->data = lInnerString;

      (*res)->to_char      = zorbac::String::to_char;
      (*res)->free         = zorbac::String::free;

      return XQ_SUCCESS;
    } catch (...) {
      delete lInnerString;
      delete res;
      return XQP0019_INTERNAL_ERROR;
    }
  }


  XQUERY_ERROR
  Implementation::item_factory(XQC_Implementation impl, XQC_ItemFactory_Ref factory)
  {
    XQC_ItemFactory lFactory  = new XQC_ItemFactory_s();
    try {
      zorba::Zorba* lZorba = static_cast<zorba::Zorba*>(impl->data);
      lFactory->data = lZorba->getItemFactory();
      
      lFactory->create_string    = zorbac::ItemFactory::create_string;
      lFactory->create_anyuri    = zorbac::ItemFactory::create_anyuri;
      lFactory->create_qname2    = zorbac::ItemFactory::create_qname2;
      lFactory->create_qname3    = zorbac::ItemFactory::create_qname3;
      lFactory->create_boolean   = zorbac::ItemFactory::create_boolean;
      lFactory->free             = zorbac::ItemFactory::free;

      *factory = lFactory;

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      delete lFactory;
      return e.getErrorCode(); 
    } catch (...) {
      delete lFactory;
      return XQP0019_INTERNAL_ERROR; 
    }
    
  }

} /* namespace zorbac */
