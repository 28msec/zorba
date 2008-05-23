#include "capi/static_context.h"

#include <cassert>
#include <zorba/zorba.h>
#include "capi/shared_wrapper.h"
#include "capi/string.h"

using namespace zorba;

#define SC_TRY try {
#define SC_CATCH \
    return XQ_SUCCESS;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }

#define ASSIGN_STRING_FUNCTIONS \
      lString->to_char      = zorbac::String::to_char; \
      lString->free         = zorbac::String::free; \

namespace zorbac {

  XQUERY_ERROR
  StaticContext::create_child_context(XQC_StaticContext context, XQC_StaticContext_Ref child_context)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lOldContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      std::auto_ptr<XQC_StaticContext_s> lContext(new XQC_StaticContext_s());
      std::auto_ptr<SharedWrapper<zorba::StaticContext> > 
        lWrapper(new SharedWrapper<zorba::StaticContext>());

      zorba::StaticContext_t lChildContext = lOldContext->theObject->createChildContext();
      lWrapper->theObject = lChildContext;

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

      (*child_context) = lContext.release();
      (*child_context)->data = lWrapper.release();


    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::add_namespace(XQC_StaticContext context, XQC_String prefix, XQC_String uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      zorba::String* lPrefix = static_cast<zorba::String*>(prefix->data);
      zorba::String* lURI = static_cast<zorba::String*>(uri->data);

      lContext->theObject->addNamespace(*lPrefix, *lURI);

    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_namespace_by_prefix(XQC_StaticContext context, XQC_String prefix, 
                                         XQC_String_Ref result_ns)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      zorba::String* lPrefix = static_cast<zorba::String*>(prefix->data);

      zorba::String lNS = lContext->theObject->getNamespaceURIByPrefix(*lPrefix);

      std::auto_ptr<XQC_String_s>  lString(new XQC_String_s());
      std::auto_ptr<zorba::String> lInnerString(new zorba::String(lNS));

      ASSIGN_STRING_FUNCTIONS

      (*result_ns) = lString.release();
      (*result_ns)->data = lInnerString.release();

    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_element_and_type_ns(XQC_StaticContext context, XQC_String uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      zorba::String* lURI = static_cast<zorba::String*>(uri->data);

      lContext->theObject->setDefaultElementAndTypeNamespace(*lURI);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_element_and_type_ns(XQC_StaticContext context, XQC_String_Ref uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      zorba::String lURI = lContext->theObject->getDefaultElementAndTypeNamespace();

      std::auto_ptr<XQC_String_s>  lString(new XQC_String_s());
      std::auto_ptr<zorba::String> lInnerString(new zorba::String(lURI));

      ASSIGN_STRING_FUNCTIONS

      (*uri) = lString.release();
      (*uri)->data = lInnerString.release();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_function_ns(XQC_StaticContext context, XQC_String uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      zorba::String* lURI = static_cast<zorba::String*>(uri->data);

      lContext->theObject->setDefaultFunctionNamespace(*lURI);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_function_ns(XQC_StaticContext context, XQC_String_Ref uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      zorba::String lURI = lContext->theObject->getDefaultFunctionNamespace();

      std::auto_ptr<XQC_String_s>  lString(new XQC_String_s());
      std::auto_ptr<zorba::String> lInnerString(new zorba::String(lURI));

      ASSIGN_STRING_FUNCTIONS

      (*uri) = lString.release();
      (*uri)->data = lInnerString.release();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::add_collation(XQC_StaticContext context, XQC_String uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      zorba::String* lURI = static_cast<zorba::String*>(uri->data);

      lContext->theObject->addCollation(*lURI);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_collation(XQC_StaticContext context, XQC_String uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      zorba::String* lURI = static_cast<zorba::String*>(uri->data);

      lContext->theObject->setDefaultCollation(*lURI);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_collation(XQC_StaticContext context, XQC_String_Ref uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      zorba::String lURI = lContext->theObject->getDefaultCollation();

      std::auto_ptr<XQC_String_s>  lString(new XQC_String_s());
      std::auto_ptr<zorba::String> lInnerString(new zorba::String(lURI));

      ASSIGN_STRING_FUNCTIONS

      (*uri) = lString.release();
      (*uri)->data = lInnerString.release();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_xpath1_0_mode(XQC_StaticContext context, xpath1_0compatib_mode_t mode )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      lContext->theObject->setXPath1_0CompatibMode(mode);
    SC_CATCH
  }

  XQUERY_ERROR 
  StaticContext::get_xpath1_0_mode(XQC_StaticContext context, xpath1_0compatib_mode_t* mode)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      *mode = lContext->theObject->getXPath1_0CompatibMode();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_construction_mode(XQC_StaticContext context, construction_mode_t mode )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      lContext->theObject->setConstructionMode(mode);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_construction_mode(XQC_StaticContext context, construction_mode_t* mode)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      *mode = lContext->theObject->getConstructionMode();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_ordering_mode(XQC_StaticContext context, ordering_mode_t mode )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      lContext->theObject->setOrderingMode(mode);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_ordering_mode(XQC_StaticContext context, ordering_mode_t* mode )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      *mode = lContext->theObject->getOrderingMode();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_order_empty_sequences(XQC_StaticContext context,
                                                   order_empty_mode_t mode )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      lContext->theObject->setDefaultOrderForEmptySequences(mode);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_order_empty_sequences(XQC_StaticContext context,
                                                   order_empty_mode_t* mode )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      *mode = lContext->theObject->getDefaultOrderForEmptySequences();
    SC_CATCH
  }

  XQUERY_ERROR  
  StaticContext::set_boundary_space_policy(XQC_StaticContext context, boundary_space_mode_t mode)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      lContext->theObject->setBoundarySpacePolicy(mode);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_boundary_space_policy(XQC_StaticContext context, boundary_space_mode_t* mode )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      *mode = lContext->theObject->getBoundarySpacePolicy();
    SC_CATCH
  }

  XQUERY_ERROR 
  StaticContext::set_copy_namespaces_mode(XQC_StaticContext context,  
                                          preserve_mode_t preserve,
                                          inherit_mode_t inherit )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      lContext->theObject->setCopyNamespacesMode(preserve, inherit);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_copy_namespaces_mode(XQC_StaticContext context,
                                          preserve_mode_t* aPreserve, 
                                          inherit_mode_t* aInherit )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      lContext->theObject->getCopyNamespacesMode(*aPreserve, *aInherit);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_base_uri(XQC_StaticContext context, XQC_String base_uri )
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      zorba::String* lBaseURI = static_cast<zorba::String*>(base_uri->data);

      lContext->theObject->setBaseURI(*lBaseURI);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_base_uri(XQC_StaticContext context, XQC_String_Ref base_uri)
  {
    SC_TRY
      SharedWrapper<zorba::StaticContext>* lContext
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);

      zorba::String lBaseURI = lContext->theObject->getBaseURI();

      std::auto_ptr<XQC_String_s>  lString(new XQC_String_s());
      std::auto_ptr<zorba::String> lInnerString(new zorba::String(lBaseURI));

      ASSIGN_STRING_FUNCTIONS

      (*base_uri) = lString.release();
      (*base_uri)->data = lInnerString.release();
    SC_CATCH
  }

  void
  StaticContext::free(XQC_StaticContext context)
  {
    try {
      SharedWrapper<zorba::StaticContext>* lQuery 
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      delete lQuery;
      delete context;

    } catch (ZorbaException &e) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }
} /* namespace zorbac */
