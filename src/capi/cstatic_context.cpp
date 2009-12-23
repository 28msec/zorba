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
#include "capi/cstatic_context.h"

#include <cassert>
#include <string.h>
#include <zorba/zorba.h>
#include "capi/external_module.h"
#include "capi/external_function.h"
#include "capi/error.h"
#include "capi/capi_util.h"

using namespace zorba;

#define SC_TRY \
  CStaticContext* me = CStaticContext::get(context);    \
  try
#define SC_CATCH                                                        \
  catch (QueryException &qe) {                                          \
    if (me->theErrorHandler) {                                          \
      me->theErrorHandler->error(me->theErrorHandler,                   \
        Error::convert_xquery_error(qe.getErrorCode()),                 \
        ZorbaException::getErrorCodeAsString(qe.getErrorCode()).c_str(), \
        qe.getDescription().c_str(),                                    \
        qe.getQueryURI().c_str(),                                       \
        qe.getLineBegin(),                                              \
        qe.getColumnBegin());                                           \
    }                                                                   \
    return Error::convert_xquery_error(qe.getErrorCode());              \
  } catch (ZorbaException &e) {                                         \
    return Error::convert_xquery_error(e.getErrorCode());               \
  }                                                                     \
  catch (...) {                                                         \
    return XQC_INTERNAL_ERROR;                                          \
  }                                                                     \
  return XQC_NO_ERROR

namespace zorbac {

  CStaticContext::CStaticContext
  (StaticContext_t aContext, XQC_ErrorHandler* handler)
    : theContext(aContext), theErrorHandler(handler)
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
    theXQCStatic.add_collation          = CStaticContext::add_collation;
    theXQCStatic.set_default_collation  = CStaticContext::set_default_collation;
    theXQCStatic.get_default_collation  = CStaticContext::get_default_collation;
    theXQCStatic.set_xquery_version     = CStaticContext::set_xquery_version;
    theXQCStatic.get_xquery_version     = CStaticContext::get_xquery_version;
    theXQCStatic.set_xpath1_0_mode      = CStaticContext::set_xpath1_0_mode;
    theXQCStatic.get_xpath1_0_mode      = CStaticContext::get_xpath1_0_mode;
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
    theXQCStatic.register_external_function =
      CStaticContext::register_external_function;
    theXQCStatic.set_error_handler      = CStaticContext::set_error_handler;
    theXQCStatic.get_error_handler      = CStaticContext::get_error_handler;
    theXQCStatic.free                   = CStaticContext::free;
  }

  CStaticContext::~CStaticContext()
  {
    for (std::map<std::string, ExternalModuleWrapper*>::iterator lIter =
           theModules.begin();
         lIter != theModules.end();
         ++lIter) {
      delete lIter->second;
    }
  }

  CStaticContext*
  CStaticContext::get(const XQC_StaticContext* xqc)
  {
    return (CStaticContext*)
      (((char*)xqc) - CLASS_OFFSET(CStaticContext, theXQCStatic));
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

  XQC_Error
  CStaticContext::create_child_context
  (XQC_StaticContext* context, XQC_StaticContext** child_context)
  {
    SC_TRY {
      StaticContext_t lChild = me->theContext.get()->createChildContext();
      std::auto_ptr<CStaticContext> lCtx
        (new CStaticContext(lChild, me->theErrorHandler));
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
  CStaticContext::add_collation(XQC_StaticContext* context, const char* uri)
  {
    SC_TRY {
      me->theContext.get()->addCollation(uri);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_default_collation
  (XQC_StaticContext* context, const char* uri)
  {
    SC_TRY {
      me->theContext.get()->setDefaultCollation(uri);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_default_collation
  (XQC_StaticContext* context, const char** uri)
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
  (XQC_StaticContext* context, xquery_version_t mode )
  {
    SC_TRY {
      me->theContext.get()->setXQueryVersion(mode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_xquery_version
  (XQC_StaticContext* context, xquery_version_t* mode)
  {
    SC_TRY {
      *mode = me->theContext.get()->getXQueryVersion();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_xpath1_0_mode
  (XQC_StaticContext* context, xpath1_0compatib_mode_t mode )
  {
    SC_TRY {
      me->theContext.get()->setXPath1_0CompatibMode(mode);
    }
    SC_CATCH;
  }

  XQC_Error 
  CStaticContext::get_xpath1_0_mode
  (XQC_StaticContext* context, xpath1_0compatib_mode_t* mode)
  {
    SC_TRY {
      *mode = me->theContext.get()->getXPath1_0CompatibMode();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_construction_mode
  (XQC_StaticContext* context, construction_mode_t mode )
  {
    SC_TRY {
      me->theContext.get()->setConstructionMode(mode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_construction_mode
  (XQC_StaticContext* context, construction_mode_t* mode)
  {
    SC_TRY {
      *mode = me->theContext.get()->getConstructionMode();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_ordering_mode
  (XQC_StaticContext* context, ordering_mode_t mode)
  {
    SC_TRY {
      me->theContext.get()->setOrderingMode(mode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_ordering_mode
  (XQC_StaticContext* context, ordering_mode_t* mode)
  {
    SC_TRY {
      *mode = me->theContext.get()->getOrderingMode();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_default_order_empty_sequences
  (XQC_StaticContext* context, order_empty_mode_t mode)
  {
    SC_TRY {
      me->theContext.get()->setDefaultOrderForEmptySequences(mode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_default_order_empty_sequences
  (XQC_StaticContext* context, order_empty_mode_t* mode)
  {
    SC_TRY {
      *mode = me->theContext.get()->getDefaultOrderForEmptySequences();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_boundary_space_policy
  (XQC_StaticContext* context, boundary_space_mode_t mode)
  {
    SC_TRY {
      me->theContext.get()->setBoundarySpacePolicy(mode);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_boundary_space_policy
  (XQC_StaticContext* context, boundary_space_mode_t* mode)
  {
    SC_TRY {
      *mode = me->theContext.get()->getBoundarySpacePolicy();
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::set_copy_ns_mode
  (XQC_StaticContext* context, preserve_mode_t preserve, inherit_mode_t inherit)
  {
    SC_TRY {
      me->theContext.get()->setCopyNamespacesMode(preserve, inherit);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_copy_ns_mode
  (XQC_StaticContext* context, preserve_mode_t* aPreserve, 
    inherit_mode_t* aInherit)
  {
    SC_TRY {
      me->theContext.get()->getCopyNamespacesMode(*aPreserve, *aInherit);
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
  CStaticContext::set_revalidation_enabled
  (XQC_StaticContext* context, bool enabled)
  {
    SC_TRY {
      me->theContext.get()->setRevalidationEnabled (enabled);
    }
    SC_CATCH;
  }

  XQC_Error
  CStaticContext::get_revalidation_enabled
  (XQC_StaticContext* context, bool *enabled)
  {
    SC_TRY {
      (*enabled) = me->theContext.get()->getRevalidationEnabled ();
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

  XQC_Error
  CStaticContext::register_external_function
  (XQC_StaticContext* context, const char* uri, const char* localname,
    external_function_init init, external_function_release release,
    void* global_user_data)
  {
    SC_TRY {
//       ExternalModuleWrapper*& lModule = me->theModules[uri];
//       if (!lModule) {
//         lModule = new ExternalModuleWrapper(uri);
//         me->theContext.get()->registerModule(lModule);
//       }

//       std::auto_ptr<ExternalFunctionWrapper> lFunc;
//       lFunc.reset(new ExternalFunctionWrapper(uri, localname, init, 
//                                               release, global_user_data));

//       XQC_Error lErr = lModule->registerFunction(lFunc.get());
//       if (lErr == XQC_NO_ERROR) {
//         // deletion is done when releasing the static context
//         lFunc.release();
//       } else {
//         return lErr;
//       }
    }
    SC_CATCH;
  }

  void
  CStaticContext::free(XQC_StaticContext* context)
  {
    try {
      CStaticContext* me = CStaticContext::get(context);
      delete me;
    } catch (ZorbaException&) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }

} /* namespace zorbac */
