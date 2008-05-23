#include "capi/implementation.h"

#include <sstream>
#include <memory>
#include <zorba/zorba.h>
#include "capi/shared_wrapper.h"
#include "capi/query.h"
#include "capi/item.h"
#include "capi/string.h"
#include "capi/item_factory.h"
#include "capi/static_context.h"

using namespace zorba;

namespace zorbac {

  XQUERY_ERROR
  Implementation::create_context(XQC_Implementation impl, XQC_StaticContext_Ref context)
  {
    try {
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_StaticContext_s> lContext(new XQC_StaticContext_s());
      std::auto_ptr<SharedWrapper<zorba::StaticContext> > 
        lWrapper(new SharedWrapper<zorba::StaticContext>());

      zorba::StaticContext_t lInnerContext = lZorba->createStaticContext();
      lWrapper->theObject = lInnerContext;

      lContext->create_child_context              = StaticContext::create_child_context;
      lContext->add_namespace                     = StaticContext::add_namespace;
      lContext->get_namespace_by_prefix           = StaticContext::get_namespace_by_prefix;
      lContext->set_default_element_and_type_ns   = StaticContext::set_default_element_and_type_ns;
      lContext->get_default_element_and_type_ns   = StaticContext::get_default_element_and_type_ns;
      lContext->set_default_function_ns           = StaticContext::set_default_function_ns;
      lContext->get_default_function_ns           = StaticContext::get_default_function_ns;
      lContext->add_collation                     = StaticContext::add_collation;
      lContext->set_default_collation             = StaticContext::set_default_collation;
      lContext->get_default_collation             = StaticContext::get_default_collation;
      lContext->set_xpath1_0_mode                 = StaticContext::set_xpath1_0_mode;
      lContext->get_xpath1_0_mode                 = StaticContext::get_xpath1_0_mode;
      lContext->set_construction_mode             = StaticContext::set_construction_mode;
      lContext->get_construction_mode             = StaticContext::get_construction_mode;
      lContext->set_ordering_mode                 = StaticContext::set_ordering_mode;
      lContext->get_ordering_mode                 = StaticContext::get_ordering_mode;
      lContext->set_default_order_empty_sequences = StaticContext::set_default_order_empty_sequences;
      lContext->get_default_order_empty_sequences = StaticContext::get_default_order_empty_sequences;
      lContext->set_boundary_space_policy         = StaticContext::set_boundary_space_policy;
      lContext->get_boundary_space_policy         = StaticContext::get_boundary_space_policy;
      lContext->set_copy_namespaces_mode          = StaticContext::set_copy_namespaces_mode;
      lContext->get_copy_namespaces_mode          = StaticContext::get_copy_namespaces_mode;
      lContext->set_base_uri                      = StaticContext::set_base_uri;
      lContext->get_base_uri                      = StaticContext::get_base_uri;
      lContext->free                              = StaticContext::free;

      (*context) = lContext.release();
      (*context)->data = lWrapper.release();

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
        // TODO static context

      std::auto_ptr<XQC_Query_s> lQuery(new XQC_Query_s());
      std::auto_ptr<SharedWrapper<XQuery> > lWrapper(new SharedWrapper<XQuery>());

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
    try {
      Zorba* lZorba = static_cast<Zorba*>(impl->data);

      std::auto_ptr<XQC_Query_s> lQuery(new XQC_Query_s());
      std::auto_ptr<SharedWrapper<XQuery> > lWrapper(new SharedWrapper<XQuery>());
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
