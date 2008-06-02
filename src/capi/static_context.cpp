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
#include "capi/static_context.h"

#include <cassert>
#include <zorba/zorba.h>

using namespace zorba;

#define SC_TRY try {
#define SC_CATCH \
    return XQ_NO_ERROR;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }

namespace zorbac {

  zorba::StaticContext*
  getStaticContext(XQC_StaticContext context)
  {
    return (static_cast<zorbac::StaticContext*>(context->data))->theContext.get();
  }

  XQUERY_ERROR
  StaticContext::create_child_context(XQC_StaticContext context, XQC_StaticContext_Ref child_context)
  {
    SC_TRY
      std::auto_ptr<XQC_StaticContext_s> lContext(new XQC_StaticContext_s());
      std::auto_ptr<zorbac::StaticContext> lInnerContext(new zorbac::StaticContext());

      zorba::StaticContext* lOldContext = getStaticContext(context);
      lInnerContext->theContext = lOldContext->createChildContext();

      zorbac::StaticContext::assign_functions(lContext.get());
      
      (*child_context) = lContext.release();
      (*child_context)->data = lInnerContext.release();

    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::declare_ns(XQC_StaticContext context, const char* prefix, const char* uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->addNamespace(prefix, uri);

    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_ns_by_prefix(XQC_StaticContext context, const char* prefix, 
                                         const char** result_ns)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);
      zorbac::StaticContext* lWrapper = static_cast<zorbac::StaticContext*>(context->data);

      zorba::String lNS = lContext->getNamespaceURIByPrefix(prefix);
      lWrapper->theStrings.push_back(lNS);

      (*result_ns) = lNS.c_str();

    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_element_and_type_ns(XQC_StaticContext context, const char* uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setDefaultElementAndTypeNamespace(uri);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_element_and_type_ns(XQC_StaticContext context, const char** uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);
      zorbac::StaticContext* lWrapper = static_cast<zorbac::StaticContext*>(context->data);

      zorba::String lURI = lContext->getDefaultElementAndTypeNamespace();
      lWrapper->theStrings.push_back(lURI);

      (*uri) = lURI.c_str();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_function_ns(XQC_StaticContext context, const char* uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setDefaultFunctionNamespace(uri);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_function_ns(XQC_StaticContext context, const char** uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;
      zorbac::StaticContext* lWrapper = static_cast<zorbac::StaticContext*>(context->data);

      zorba::String lURI = lContext->getDefaultFunctionNamespace();
      lWrapper->theStrings.push_back(lURI);

      (*uri) = lURI.c_str();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::add_collation(XQC_StaticContext context, const char* uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->addCollation(uri);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_collation(XQC_StaticContext context, const char* uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setDefaultCollation(uri);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_collation(XQC_StaticContext context, const char** uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;
      zorbac::StaticContext* lWrapper = static_cast<zorbac::StaticContext*>(context->data);

      zorba::String lURI = lContext->getDefaultCollation();
      lWrapper->theStrings.push_back(lURI);

      (*uri) = lURI.c_str();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_xpath1_0_mode(XQC_StaticContext context, xpath1_0compatib_mode_t mode )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setXPath1_0CompatibMode(mode);
    SC_CATCH
  }

  XQUERY_ERROR 
  StaticContext::get_xpath1_0_mode(XQC_StaticContext context, xpath1_0compatib_mode_t* mode)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;

      *mode = lContext->getXPath1_0CompatibMode();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_construction_mode(XQC_StaticContext context, construction_mode_t mode )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setConstructionMode(mode);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_construction_mode(XQC_StaticContext context, construction_mode_t* mode)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;

      *mode = lContext->getConstructionMode();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_ordering_mode(XQC_StaticContext context, ordering_mode_t mode )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setOrderingMode(mode);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_ordering_mode(XQC_StaticContext context, ordering_mode_t* mode )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;

      *mode = lContext->getOrderingMode();
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_order_empty_sequences(XQC_StaticContext context,
                                                   order_empty_mode_t mode )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setDefaultOrderForEmptySequences(mode);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_order_empty_sequences(XQC_StaticContext context,
                                                   order_empty_mode_t* mode )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;

      *mode = lContext->getDefaultOrderForEmptySequences();
    SC_CATCH
  }

  XQUERY_ERROR  
  StaticContext::set_boundary_space_policy(XQC_StaticContext context, boundary_space_mode_t mode)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setBoundarySpacePolicy(mode);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_boundary_space_policy(XQC_StaticContext context, boundary_space_mode_t* mode )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;

      *mode = lContext->getBoundarySpacePolicy();
    SC_CATCH
  }

  XQUERY_ERROR 
  StaticContext::set_copy_ns_mode(XQC_StaticContext context,  
                                          preserve_mode_t preserve,
                                          inherit_mode_t inherit )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setCopyNamespacesMode(preserve, inherit);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_copy_ns_mode(XQC_StaticContext context,
                                          preserve_mode_t* aPreserve, 
                                          inherit_mode_t* aInherit )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;

      lContext->getCopyNamespacesMode(*aPreserve, *aInherit);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_base_uri(XQC_StaticContext context, const char* base_uri )
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);

      lContext->setBaseURI(base_uri);
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_base_uri(XQC_StaticContext context, const char** base_uri)
  {
    SC_TRY
      zorba::StaticContext* lContext = getStaticContext(context);;
      zorbac::StaticContext* lWrapper = static_cast<zorbac::StaticContext*>(context->data);

      zorba::String lBaseURI = lContext->getBaseURI();
      lWrapper->theStrings.push_back(lBaseURI);

      (*base_uri) = lBaseURI.c_str();
    SC_CATCH
  }

  void
  StaticContext::free(XQC_StaticContext context)
  {
    try {
      zorbac::StaticContext* lWrapper = static_cast<zorbac::StaticContext*>(context->data);
      delete lWrapper;
      delete context;
    } catch (ZorbaException &e) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }

  void
  StaticContext::assign_functions(XQC_StaticContext context)
  {
    context->create_child_context              = StaticContext::create_child_context;
    context->declare_ns                        = StaticContext::declare_ns;
    context->get_ns_by_prefix                  = StaticContext::get_ns_by_prefix;
    context->set_default_element_and_type_ns   = StaticContext::set_default_element_and_type_ns;
    context->get_default_element_and_type_ns   = StaticContext::get_default_element_and_type_ns;
    context->set_default_function_ns           = StaticContext::set_default_function_ns;
    context->get_default_function_ns           = StaticContext::get_default_function_ns;
    context->add_collation                     = StaticContext::add_collation;
    context->set_default_collation             = StaticContext::set_default_collation;
    context->get_default_collation             = StaticContext::get_default_collation;
    context->set_xpath1_0_mode                 = StaticContext::set_xpath1_0_mode;
    context->get_xpath1_0_mode                 = StaticContext::get_xpath1_0_mode;
    context->set_construction_mode             = StaticContext::set_construction_mode;
    context->get_construction_mode             = StaticContext::get_construction_mode;
    context->set_ordering_mode                 = StaticContext::set_ordering_mode;
    context->get_ordering_mode                 = StaticContext::get_ordering_mode;
    context->set_default_order_empty_sequences = StaticContext::set_default_order_empty_sequences;
    context->get_default_order_empty_sequences = StaticContext::get_default_order_empty_sequences;
    context->set_boundary_space_policy         = StaticContext::set_boundary_space_policy;
    context->get_boundary_space_policy         = StaticContext::get_boundary_space_policy;
    context->set_copy_ns_mode                  = StaticContext::set_copy_ns_mode;
    context->get_copy_ns_mode                  = StaticContext::get_copy_ns_mode;
    context->set_base_uri                      = StaticContext::set_base_uri;
    context->get_base_uri                      = StaticContext::get_base_uri;
    context->free                              = StaticContext::free;
  }

} /* namespace zorbac */
