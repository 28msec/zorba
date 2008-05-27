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

#include <zorba/zorbac.h>

namespace zorbac {

  class StaticContext {

    public:
      static XQUERY_ERROR
      create_child_context(XQC_StaticContext context, XQC_StaticContext_Ref child_context);

      static XQUERY_ERROR
      add_namespace(XQC_StaticContext context, XQC_String prefix, XQC_String uri);

      static XQUERY_ERROR
      get_namespace_by_prefix(XQC_StaticContext context, XQC_String prefix, XQC_String_Ref result_ns);

      static XQUERY_ERROR
      set_default_element_and_type_ns(XQC_StaticContext context, XQC_String uri);

      static XQUERY_ERROR
      get_default_element_and_type_ns(XQC_StaticContext context, XQC_String_Ref uri);

      static XQUERY_ERROR
      set_default_function_ns(XQC_StaticContext context, XQC_String uri);

      static XQUERY_ERROR
      get_default_function_ns(XQC_StaticContext context, XQC_String_Ref uri);

      static XQUERY_ERROR
      add_collation(XQC_StaticContext context, XQC_String uri);

      static XQUERY_ERROR
      set_default_collation(XQC_StaticContext context, XQC_String uri);

      static XQUERY_ERROR
      get_default_collation(XQC_StaticContext context, XQC_String_Ref uri);

      static XQUERY_ERROR
      set_xpath1_0_mode(XQC_StaticContext context, xpath1_0compatib_mode_t mode );

      static XQUERY_ERROR 
      get_xpath1_0_mode(XQC_StaticContext context, xpath1_0compatib_mode_t* mode);

      static XQUERY_ERROR
      set_construction_mode(XQC_StaticContext context, construction_mode_t mode );

      static XQUERY_ERROR
      get_construction_mode(XQC_StaticContext context, construction_mode_t* mode);

      static XQUERY_ERROR
      set_ordering_mode(XQC_StaticContext context, ordering_mode_t mode );

      static XQUERY_ERROR
      get_ordering_mode(XQC_StaticContext context, ordering_mode_t* mode );

      static XQUERY_ERROR
      set_default_order_empty_sequences(XQC_StaticContext context, order_empty_mode_t mode );

      static XQUERY_ERROR
      get_default_order_empty_sequences(XQC_StaticContext context, order_empty_mode_t* mode );

      static XQUERY_ERROR  
      set_boundary_space_policy(XQC_StaticContext context, boundary_space_mode_t mode);

      static XQUERY_ERROR
      get_boundary_space_policy(XQC_StaticContext context, boundary_space_mode_t* mode );

      static XQUERY_ERROR 
      set_copy_namespaces_mode(XQC_StaticContext context,  
                               preserve_mode_t preserve,
                               inherit_mode_t inherit );

      static XQUERY_ERROR
      get_copy_namespaces_mode(XQC_StaticContext context,
                               preserve_mode_t* aPreserve, 
                               inherit_mode_t* aInherit );

      static XQUERY_ERROR
      set_base_uri(XQC_StaticContext context, XQC_String base_uri );

      static XQUERY_ERROR
      get_base_uri(XQC_StaticContext context, XQC_String_Ref base_uri);

      static void
      free(XQC_StaticContext context);

      // private use
      static void
      assign_functions(XQC_StaticContext context);
  }; /* class StaticContext */

} /* namespace zorbac */

#endif
