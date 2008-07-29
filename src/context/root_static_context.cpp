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
#include "types/root_typemanager.h"
#include "context/root_static_context.h"
#include "context/namespace_context.h"
#include "context/uri_resolver_wrapper.h"
#include "context/standard_uri_resolvers.h"
#include "system/globalenv.h"
#include "common/common.h"

namespace zorba {

static const char *default_ns_initializers [] = {
  "fn", XQUERY_FN_NS,
  "xml", XML_NS,
  "xs", XML_SCHEMA_NS,
  "xsi", XSI_NS,
  "local", XQUERY_LOCAL_FN_NS,
  "err", XQUERY_ERR_NS,
  NULL, NULL
};

root_static_context::root_static_context()
    : static_context()
{
  typemgr.reset(new RootTypeManager());
}


void root_static_context::init() 
{
  // must be initialized or there be assertions
  set_current_absolute_baseuri ("");

  set_xpath1_0compatib_mode(StaticContextConsts::xpath2_0);
  const char **p = default_ns_initializers;
  for (; *p != NULL; p += 2)
    bind_ns (p [0], p [1]);
  set_default_elem_type_ns ("");		
  set_default_function_namespace (lookup_ns ("fn"));
  set_context_item_static_type(GENV_TYPESYSTEM.ITEM_TYPE_ONE);
  set_default_collation_uri (W3C_CODEPT_COLLATION_NS);
  add_collation(ZORBA_DEF_COLLATION_NS);
  add_collation(W3C_CODEPT_COLLATION_NS);
  set_construction_mode(StaticContextConsts::cons_preserve);
  set_ordering_mode(StaticContextConsts::ordered);
  set_order_empty_mode(StaticContextConsts::empty_greatest);
  set_boundary_space_mode(StaticContextConsts::strip_space);
  set_inherit_mode(StaticContextConsts::inherit_ns);
  set_preserve_mode(StaticContextConsts::preserve_ns);
  set_default_collection_type(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
  set_document_uri_resolver(new StandardDocumentURIResolver());
  set_collection_uri_resolver(new StandardCollectionURIResolver());
  set_schema_uri_resolver(new StandardSchemaURIResolver());
  set_module_uri_resolver(new StandardModuleURIResolver());
} 

root_static_context::~root_static_context()
{
}

}
/* vim:set ts=2 sw=2: */
