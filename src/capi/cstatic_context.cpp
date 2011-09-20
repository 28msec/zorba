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
#include "stdafx.h"

#include "capi/cstatic_context.h"

#include <cassert>
#include <string.h>
#include <zorba/zorba.h>
#include "capi/external_module.h"
#include "capi/cexternal_function.h"
#include "capi/error.h"

using namespace zorba;

#define SC_TRY CAPI_TRY(CStaticContext,context)
#define SC_CATCH CAPI_CATCH

#define ZSC_TRY CAPI_TRY(CStaticContext,context)
#define ZSC_CATCH CAPI_CATCH

namespace zorbac {

  CStaticContext::CStaticContext
  (StaticContext_t aContext, Zorba* aZorba, XQC_ErrorHandler* handler)
    : theContext(aContext), theZorba(aZorba), theErrorHandler(handler)
  {
    memset(&theXQCStatic, 0, sizeof (XQC_StaticContext));
    theXQCStatic.create_child_context   = CStaticContext::create_child_context;
    theXQCStatic.declare_ns             = CStaticContext::declare_ns;
    theXQCStatic.get_ns_by_prefix       = CStaticContext::get_ns_by_prefix;
    theXQCStatic.set_default_element_and_type_ns =
      CStaticContext::set_default_element_and_type_ns;
    theXQCStatic.get_default_element_and_type_ns =
      CStaticContext::get_default_element_and_type_ns;
    theXQCStatic.set_default_function_ns =
      CStaticContext::set_default_function_ns;
    theXQCStatic.get_default_function_ns =
      CStaticContext::get_default_function_ns;
    theXQCStatic.set_xpath_compatib_mode =
      CStaticContext::set_xpath_compatib_mode;
    theXQCStatic.get_xpath_compatib_mode =
      CStaticContext::get_xpath_compatib_mode;
    theXQCStatic.set_construction_mode  = CStaticContext::set_construction_mode;
    theXQCStatic.get_construction_mode  = CStaticContext::get_construction_mode;
    theXQCStatic.set_ordering_mode      = CStaticContext::set_ordering_mode;
    theXQCStatic.get_ordering_mode      = CStaticContext::get_ordering_mode;
    theXQCStatic.set_default_order_empty_sequences =
      CStaticContext::set_default_order_empty_sequences;
    theXQCStatic.get_default_order_empty_sequences =
      CStaticContext::get_default_order_empty_sequences;
    theXQCStatic.set_boundary_space_policy =
      CStaticContext::set_boundary_space_policy;
    theXQCStatic.get_boundary_space_policy =
      CStaticContext::get_boundary_space_policy;
    theXQCStatic.set_copy_ns_mode       = CStaticContext::set_copy_ns_mode;
    theXQCStatic.get_copy_ns_mode       = CStaticContext::get_copy_ns_mode;
    theXQCStatic.set_base_uri           = CStaticContext::set_base_uri;
    theXQCStatic.get_base_uri           = CStaticContext::get_base_uri;
    theXQCStatic.set_error_handler      = CStaticContext::set_error_handler;
    theXQCStatic.get_error_handler      = CStaticContext::get_error_handler;
    theXQCStatic.get_interface          = CStaticContext::get_interface;
    theXQCStatic.free                   = CStaticContext::free;

    // Zorba-specific extension functions.
    theZorbaStatic.add_collation        = CStaticContext::add_collation;
    theZorbaStatic.set_default_collation =
      CStaticContext::set_default_collation;
    theZorbaStatic.get_default_collation =
      CStaticContext::get_default_collation;
    theZorbaStatic.set_xquery_version   = CStaticContext::set_xquery_version;
    theZorbaStatic.get_xquery_version   = CStaticContext::get_xquery_version;
    theZorbaStatic.register_external_function =
      CStaticContext::register_external_function;
  }

  CStaticContext::~CStaticContext()
  {
    for (std::map<std::string, ExternalModuleWrapper*>::iterator lIter =
           theExternalModules.begin();
         lIter != theExternalModules.end();
         ++lIter) {
      delete lIter->second;
    }

    // theStrings will be destructed here, destroying all strings that
    // were put into it automatically.
  }

  CStaticContext*
  CStaticContext::get(const XQC_StaticContext* xqc)
  {
    return (CStaticContext*)
      (((char*)xqc) - CLASS_OFFSET(CStaticContext, theXQCStatic));
  }

  CStaticContext*
  CStaticContext::get(const Zorba_StaticContext* zsc)
  {
    return (CStaticContext*)
      (((char*)zsc) - CLASS_OFFSET(CStaticContext, theZorbaStatic));
  }

  StaticContext_t
  CStaticContext::getCPP()
  {
    return theContext;
  }

  XQC_StaticContext*
  CStaticContext::getXQC()
  {
    return &theXQCStatic;
  }

  Zorba_StaticContext*
  CStaticContext::getZSC()
  {
    return &theZorbaStatic;
  }

  XQC_Error
  CStaticContext::create_child_context
  (XQC_StaticContext* context, XQC_StaticContext** child_context)
  {
    SC_TRY {
      StaticContext_t lChild = me->theContext.get()->createChildContext();
      std::auto_ptr<CStaticContext> lCtx
        (new CStaticContext(lChild, me->theZorba, me->theErrorHandler));
      (*child_context) = lCtx.release()->getXQC();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::declare_ns
  (XQC_StaticContext* context, const char* prefix, const char* uri)
  {
    SC_TRY {
      me->theContext.get()->addNamespace(prefix, uri);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_ns_by_prefix
  (XQC_StaticContext* context, const char* prefix, const char** result_ns)
  {
    SC_TRY {
      zorba::String lNS = me->theContext.get()->
        getNamespaceURIByPrefix(prefix);
      me->theStrings.push_back(lNS);

      (*result_ns) = lNS.c_str();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_default_element_and_type_ns
  (XQC_StaticContext* context, const char* uri)
  {
    SC_TRY {
      me->theContext.get()->setDefaultElementAndTypeNamespace(uri);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_default_element_and_type_ns
  (XQC_StaticContext* context, const char** uri)
  {
    SC_TRY {
      zorba::String lURI = me->theContext.get()->
        getDefaultElementAndTypeNamespace();
      me->theStrings.push_back(lURI);
      (*uri) = lURI.c_str();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_default_function_ns
  (XQC_StaticContext* context, const char* uri)
  {
    SC_TRY {
      me->theContext.get()->setDefaultFunctionNamespace(uri);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_default_function_ns
  (XQC_StaticContext* context, const char** uri)
  {
    SC_TRY {
      zorba::String lURI = me->theContext.get()->getDefaultFunctionNamespace();
      me->theStrings.push_back(lURI);
      (*uri) = lURI.c_str();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::add_collation
  (Zorba_StaticContext* context, const char* uri)
  {
    SC_TRY {
      me->theContext.get()->addCollation(uri);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_default_collation
  (Zorba_StaticContext* context, const char* uri)
  {
    SC_TRY {
      me->theContext.get()->setDefaultCollation(uri);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_default_collation
  (Zorba_StaticContext* context, const char** uri)
  {
    SC_TRY {
      zorba::String lURI = me->theContext.get()->getDefaultCollation();
      me->theStrings.push_back(lURI);
      (*uri) = lURI.c_str();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_xquery_version
  (Zorba_StaticContext* context, XQC_XQueryVersion ver)
  {
    SC_TRY 
    {
      xquery_version_t zver;
      switch (ver)
      {
      default:
        assert(false);
        // Fall through - 2.0 is fallback default
      case XQC_VERSION_3_0:
        zver = xquery_version_3_0;
        break;
      case XQC_VERSION_1_0:
        zver = xquery_version_1_0;
        break;
      } 
      me->theContext.get()->setXQueryVersion(zver);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_xquery_version
  (Zorba_StaticContext* context, XQC_XQueryVersion* ver)
  {
    SC_TRY {
      xquery_version_t zver = me->theContext.get()->getXQueryVersion();
      switch (zver)
      {
      case xquery_version_1_0:
        *ver = XQC_VERSION_1_0;
        break;
      case xquery_version_3_0:
        *ver = XQC_VERSION_3_0;
        break;
      default:
        *ver = XQC_VERSION_3_0;
        assert(false);
      }
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_xpath_compatib_mode
  (XQC_StaticContext* context, XQC_XPath1Mode mode)
  {
    SC_TRY {
      xpath1_0compatib_mode_t zmode;
      switch (mode) {
        default:
          assert(false);
          // Fall through - 2.0 is fallback default
        case XQC_XPATH2_0:
          zmode = xpath2_0;
          break;
        case XQC_XPATH1_0:
          zmode = xpath1_0;
          break;
      }
      me->theContext.get()->setXPath1_0CompatibMode(zmode);
    }
    SC_CATCH;
  }

  XQC_Error 
  CStaticContext::get_xpath_compatib_mode
  (XQC_StaticContext* context, XQC_XPath1Mode* mode)
  {
    SC_TRY {
      xpath1_0compatib_mode_t zmode =
        me->theContext.get()->getXPath1_0CompatibMode();
      switch (zmode) {
        default:
          assert(false);
          // Fall through - 2.0 is fallback default
        case xpath2_0:
          (*mode) = XQC_XPATH2_0;
          break;
        case xpath1_0:
          (*mode) = XQC_XPATH1_0;
          break;
      }
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_construction_mode
  (XQC_StaticContext* context, XQC_ConstructionMode mode)
  {
    SC_TRY {
      construction_mode_t zmode;
      switch (mode) {
        default:
          assert(false);
          // Fall through - preserve is fallback default
        case XQC_PRESERVE_CONS:
          zmode = preserve_cons;
          break;
        case XQC_STRIP_CONS:
          zmode = strip_cons;
          break;
      }
      me->theContext.get()->setConstructionMode(zmode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_construction_mode
  (XQC_StaticContext* context, XQC_ConstructionMode* mode)
  {
    SC_TRY {
      construction_mode_t zmode = me->theContext.get()->getConstructionMode();
      switch (zmode) {
        default:
          assert(false);
          // Fall through - preserve is fallback default
        case preserve_cons:
          (*mode) = XQC_PRESERVE_CONS;
          break;
        case strip_cons:
          (*mode) = XQC_STRIP_CONS;
          break;
      }
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_ordering_mode
  (XQC_StaticContext* context, XQC_OrderingMode mode)
  {
    SC_TRY {
      ordering_mode_t zmode;
      switch (mode) {
        default:
          assert(false);
          // Fall through - ordered is fallback default
        case XQC_ORDERED:
          zmode = ordered;
          break;
        case XQC_UNORDERED:
          zmode = unordered;
          break;
      }
      me->theContext.get()->setOrderingMode(zmode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_ordering_mode
  (XQC_StaticContext* context, XQC_OrderingMode* mode)
  {
    SC_TRY {
      ordering_mode_t zmode = me->theContext.get()->getOrderingMode();
      switch (zmode) {
        default:
          assert(false);
          // Fall through - ordered is fallback default
        case ordered:
          (*mode) = XQC_ORDERED;
          break;
        case unordered:
          (*mode) = XQC_UNORDERED;
          break;
      }
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_default_order_empty_sequences
  (XQC_StaticContext* context, XQC_OrderEmptyMode mode)
  {
    SC_TRY {
      order_empty_mode_t zmode;
      switch (mode) {
        default:
          assert(false);
          // Fall through - empty_greatest is fallback default
        case XQC_EMPTY_GREATEST:
          zmode = empty_greatest;
          break;
        case XQC_EMPTY_LEAST:
          zmode = empty_least;
          break;
      }
      me->theContext.get()->setDefaultOrderForEmptySequences(zmode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_default_order_empty_sequences
  (XQC_StaticContext* context, XQC_OrderEmptyMode* mode)
  {
    SC_TRY {
      order_empty_mode_t zmode =
        me->theContext.get()->getDefaultOrderForEmptySequences();
      switch (zmode) {
        default:
          assert(false);
          // Fall through - empty_greatest is fallback default
        case empty_greatest:
          (*mode) = XQC_EMPTY_GREATEST;
          break;
        case empty_least:
          (*mode) = XQC_EMPTY_LEAST;
          break;
      }
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_boundary_space_policy
  (XQC_StaticContext* context, XQC_BoundarySpaceMode mode)
  {
    SC_TRY {
      boundary_space_mode_t zmode;
      switch (mode) {
        default:
          assert(false);
          // Fall through - preserve_space is fallback default
        case XQC_PRESERVE_SPACE:
          zmode = preserve_space;
          break;
        case XQC_STRIP_SPACE:
          zmode = strip_space;
          break;
      }
      me->theContext.get()->setBoundarySpacePolicy(zmode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_boundary_space_policy
  (XQC_StaticContext* context, XQC_BoundarySpaceMode* mode)
  {
    SC_TRY {
      boundary_space_mode_t zmode =
        me->theContext.get()->getBoundarySpacePolicy();
      switch (zmode) {
        default:
          assert(false);
          // Fall through - preserve_space is fallback default
        case preserve_space:
          (*mode) = XQC_PRESERVE_SPACE;
          break;
        case strip_space:
          (*mode) = XQC_STRIP_SPACE;
          break;
      }
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_copy_ns_mode
  (XQC_StaticContext* context, XQC_PreserveMode preserve,
    XQC_InheritMode inherit)
  {
    SC_TRY {
      preserve_mode_t zpreserve;
      switch (preserve) {
        default:
          assert(false);
          // Fall through - preserve_ns is fallback default
        case XQC_PRESERVE_NS:
          zpreserve = preserve_ns;
          break;
        case XQC_NO_PRESERVE_NS:
          zpreserve = no_preserve_ns;
          break;
      }
      inherit_mode_t zinherit;
      switch (inherit) {
        default:
          assert(false);
          // Fall through - inherit_ns is fallback default
        case XQC_INHERIT_NS:
          zinherit = inherit_ns;
          break;
        case XQC_NO_INHERIT_NS:
          zinherit = no_inherit_ns;
          break;
      }
      me->theContext.get()->setCopyNamespacesMode(zpreserve, zinherit);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_copy_ns_mode
  (XQC_StaticContext* context, XQC_PreserveMode* preserve, 
    XQC_InheritMode* inherit)
  {
    SC_TRY {
      preserve_mode_t zpreserve;
      inherit_mode_t zinherit;
      me->theContext.get()->getCopyNamespacesMode(zpreserve, zinherit);
      switch (zpreserve) {
        default:
          assert(false);
          // Fall through - preserve_ns is fallback default
        case preserve_ns:
          (*preserve) = XQC_PRESERVE_NS;
          break;
        case no_preserve_ns:
          (*preserve) = XQC_NO_PRESERVE_NS;
          break;
      }
      switch (zinherit) {
        default:
          assert(false);
          // Fall through - inherit_ns is fallback default
        case inherit_ns:
          (*inherit) = XQC_INHERIT_NS;
          break;
        case no_inherit_ns:
          (*inherit) = XQC_NO_INHERIT_NS;
          break;
      }
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_base_uri
  (XQC_StaticContext* context, const char* base_uri)
  {
    SC_TRY {
      me->theContext.get()->setBaseURI(base_uri);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_base_uri
  (XQC_StaticContext* context, const char** base_uri)
  {
    SC_TRY {
      zorba::String lBaseURI = me->theContext.get()->getBaseURI();
      me->theStrings.push_back(lBaseURI);
      (*base_uri) = lBaseURI.c_str();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_error_handler
  (XQC_StaticContext* context, XQC_ErrorHandler* handler)
  {
    SC_TRY {
      me->theErrorHandler = handler;
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_error_handler
  (const XQC_StaticContext* context, XQC_ErrorHandler** handler)
  {
    SC_TRY {
      (*handler) = me->theErrorHandler;
    }
    SC_CATCH;
  }

  void*
  CStaticContext::get_interface
  (const XQC_StaticContext* context, const char* name)
  {
    // Zorba has its own extension of XQC_StaticContext
    if ( (name != NULL) && (strcmp(name, "Zorba_StaticContext") == 0) ) {
      return CStaticContext::get(context)->getZSC();
    }
    return NULL;
  }

  XQC_Error
  CStaticContext::register_external_function
  (Zorba_StaticContext* context, const char* uri, const char* localname,
    external_function_init init_fn, external_function_next next_fn,
    external_function_free free_fn, void* function_user_data)
  {
    SC_TRY {
      ExternalModuleWrapper*& lModule = me->theExternalModules[uri];
      if (!lModule) {
        lModule = new ExternalModuleWrapper(uri);
        me->theContext.get()->registerModule(lModule);
      }

      std::auto_ptr<CExternalFunction> lFunc
        (new CExternalFunction(uri, localname, init_fn, next_fn, free_fn,
          function_user_data, me->theZorba->getItemFactory(),
          me->theErrorHandler));

      XQC_Error lErr = lModule->registerFunction(lFunc.get());
      if (lErr == XQC_NO_ERROR) {
        // deletion is done when releasing the static context
        lFunc.release();
      } else {
        return lErr;
      }
    }
    SC_CATCH;
  }

  void
  CStaticContext::free(XQC_StaticContext* context)
  {
    try {
      CStaticContext* me = CStaticContext::get(context);
      delete me;
    } catch (ZorbaException const&) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }

} /* namespace zorbac */
/* vim:set et sw=2 ts=2: */
