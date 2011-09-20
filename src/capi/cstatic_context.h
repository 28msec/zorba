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
#pragma once
#ifndef ZORBAC_CSTATIC_CONTEXT_H
#define ZORBAC_CSTATIC_CONTEXT_H

#include <vector>
#include <map>
#include <zorba/zorbac.h>
#include <zorba/api_shared_types.h>
#include <zorba/zorba_string.h>
#include <zorba/static_context.h>

using namespace zorba;

namespace zorbac {

  class ExternalModuleWrapper;

  class CStaticContext {

    public:
      static XQC_Error
      create_child_context(XQC_StaticContext* context, XQC_StaticContext** child_context);

      static XQC_Error
      declare_ns(XQC_StaticContext* context, const char* prefix, const char* uri);

      static XQC_Error
      get_ns_by_prefix(XQC_StaticContext* context, const char* prefix, const char** result_ns);

      static XQC_Error
      set_default_element_and_type_ns(XQC_StaticContext* context, const char* uri);

      static XQC_Error
      get_default_element_and_type_ns(XQC_StaticContext* context, const char** uri);

      static XQC_Error
      set_default_function_ns(XQC_StaticContext* context, const char* uri);

      static XQC_Error
      get_default_function_ns(XQC_StaticContext* context, const char** uri);

      static XQC_Error
      set_xpath_compatib_mode(XQC_StaticContext* context, XQC_XPath1Mode mode);

      static XQC_Error 
      get_xpath_compatib_mode(XQC_StaticContext* context, XQC_XPath1Mode* mode);

      static XQC_Error
      set_construction_mode(XQC_StaticContext* context,
        XQC_ConstructionMode mode);

      static XQC_Error
      get_construction_mode(XQC_StaticContext* context,
        XQC_ConstructionMode* mode);

      static XQC_Error
      set_ordering_mode(XQC_StaticContext* context, XQC_OrderingMode mode);

      static XQC_Error
      get_ordering_mode(XQC_StaticContext* context, XQC_OrderingMode* mode);

      static XQC_Error
      set_default_order_empty_sequences(XQC_StaticContext* context,
        XQC_OrderEmptyMode mode);

      static XQC_Error
      get_default_order_empty_sequences(XQC_StaticContext* context,
        XQC_OrderEmptyMode* mode);

      static XQC_Error  
      set_boundary_space_policy(XQC_StaticContext* context,
        XQC_BoundarySpaceMode mode);

      static XQC_Error
      get_boundary_space_policy(XQC_StaticContext* context,
        XQC_BoundarySpaceMode* mode);

      static XQC_Error 
      set_copy_ns_mode(XQC_StaticContext* context,  
        XQC_PreserveMode preserve, XQC_InheritMode inherit);

      static XQC_Error
      get_copy_ns_mode(XQC_StaticContext* context,
        XQC_PreserveMode* preserve, XQC_InheritMode* inherit);

      static XQC_Error
      set_base_uri(XQC_StaticContext* context, const char* base_uri );

      static XQC_Error
      get_base_uri(XQC_StaticContext* context, const char** base_uri);

      static XQC_Error
      set_revalidation_enabled(XQC_StaticContext* context, bool enabled);

      static XQC_Error
      get_revalidation_enabled(XQC_StaticContext* context, bool* enabled);

      static XQC_Error
      set_error_handler(XQC_StaticContext* context, XQC_ErrorHandler* handler);

      static XQC_Error
      get_error_handler(const XQC_StaticContext* context, XQC_ErrorHandler** handler);

      static void*
      get_interface(const XQC_StaticContext* context, const char* name);

      static void
      free(XQC_StaticContext* context);

      // The methods after this point are Zorba-specific extensions.
      
      static XQC_Error
      add_collation(Zorba_StaticContext* context, const char* uri);

      static XQC_Error
      set_default_collation(Zorba_StaticContext* context, const char* uri);

      static XQC_Error
      get_default_collation(Zorba_StaticContext* context, const char** uri);

      static XQC_Error
      set_xquery_version(Zorba_StaticContext* context, XQC_XQueryVersion ver);

      static XQC_Error 
      get_xquery_version(Zorba_StaticContext* context, XQC_XQueryVersion* ver);

      static XQC_Error
      register_external_function(Zorba_StaticContext* context, 
        const char* uri, const char* localname, external_function_init init,
        external_function_next next_fn, external_function_free free_fn,
        void* function_user_data);

      // Constructors and accessors.

      CStaticContext(StaticContext_t aContext, Zorba* aZorba,
        XQC_ErrorHandler* handler);
      ~CStaticContext();

      static CStaticContext*
      get(const XQC_StaticContext* xqc);
 
      static CStaticContext*
      get(const Zorba_StaticContext* zsc);

      StaticContext_t
      getCPP();

      XQC_StaticContext*
      getXQC();

      Zorba_StaticContext*
      getZSC();

    private:
      XQC_StaticContext                               theXQCStatic;
      Zorba_StaticContext                             theZorbaStatic;
      StaticContext_t                                 theContext;
      Zorba*                                          theZorba;
      std::vector<zorba::String>                      theStrings;
      std::map<std::string, ExternalModuleWrapper*>   theExternalModules;
      XQC_ErrorHandler*                               theErrorHandler;
  }; /* class CStaticContext */

} /* namespace zorbac */

#endif
/* vim:set et sw=2 ts=2: */
