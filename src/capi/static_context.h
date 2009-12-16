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
#ifndef ZORBAC_STATIC_CONTEXT_H
#define ZORBAC_STATIC_CONTEXT_H

#include <vector>
#include <map>
#include <zorba/zorbac.h>
#include <zorba/api_shared_types.h>
#include <zorba/zorbastring.h>
#include <zorba/static_context.h>


namespace zorbac {

  class ExternalModuleWrapper;

  class StaticContext {

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
      add_collation(XQC_StaticContext* context, const char* uri);

      static XQC_Error
      set_default_collation(XQC_StaticContext* context, const char* uri);

      static XQC_Error
      get_default_collation(XQC_StaticContext* context, const char** uri);

      static XQC_Error
      set_xquery_version(XQC_StaticContext* context, xquery_version_t mode );

      static XQC_Error 
      get_xquery_version(XQC_StaticContext* context, xquery_version_t* mode);

      static XQC_Error
      set_xpath1_0_mode(XQC_StaticContext* context, xpath1_0compatib_mode_t mode );

      static XQC_Error 
      get_xpath1_0_mode(XQC_StaticContext* context, xpath1_0compatib_mode_t* mode);

      static XQC_Error
      set_construction_mode(XQC_StaticContext* context, construction_mode_t mode );

      static XQC_Error
      get_construction_mode(XQC_StaticContext* context, construction_mode_t* mode);

      static XQC_Error
      set_ordering_mode(XQC_StaticContext* context, ordering_mode_t mode );

      static XQC_Error
      get_ordering_mode(XQC_StaticContext* context, ordering_mode_t* mode );

      static XQC_Error
      set_default_order_empty_sequences(XQC_StaticContext* context, order_empty_mode_t mode );

      static XQC_Error
      get_default_order_empty_sequences(XQC_StaticContext* context, order_empty_mode_t* mode );

      static XQC_Error  
      set_boundary_space_policy(XQC_StaticContext* context, boundary_space_mode_t mode);

      static XQC_Error
      get_boundary_space_policy(XQC_StaticContext* context, boundary_space_mode_t* mode );

      static XQC_Error 
        set_copy_ns_mode(XQC_StaticContext* context,  
                         preserve_mode_t preserve,
                         inherit_mode_t inherit );

      static XQC_Error
        get_copy_ns_mode(XQC_StaticContext* context,
                         preserve_mode_t* aPreserve, 
                         inherit_mode_t* aInherit );

      static XQC_Error
      set_base_uri(XQC_StaticContext* context, const char* base_uri );

      static XQC_Error
      get_base_uri(XQC_StaticContext* context, const char** base_uri);

      static XQC_Error
      set_revalidation_enabled(XQC_StaticContext* context, bool enabled);

      static XQC_Error
      get_revalidation_enabled(XQC_StaticContext* context, bool* enabled);

      
      static XQC_Error
      register_external_function(XQC_StaticContext* context, 
                                const char* uri,
                                const char* localname,
                                external_function_init init,
                                external_function_release release,
                                void* global_user_data);

      static void
      free(XQC_StaticContext* context);

      // private use
      static void
      assign_functions(XQC_StaticContext* context);

      ~StaticContext();

      std::vector<zorba::String>                              theStrings;
      zorba::StaticContext_t                                  theContext;
      std::map<std::string, zorbac::ExternalModuleWrapper*>   theModules;
  }; /* class StaticContext */

} /* namespace zorbac */

#endif
