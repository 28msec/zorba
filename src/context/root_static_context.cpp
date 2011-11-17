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

#include "context/root_static_context.h"
#include "context/namespace_context.h"
#include "context/default_url_resolvers.h"
#include "context/default_uri_mappers.h"

#include "types/root_typemanager.h"

#include "system/globalenv.h"

#include "compiler/parser/query_loc.h"

#include "common/common.h"
#include "zorbamisc/ns_consts.h"

#include "store/api/item_factory.h"

namespace zorba 
{


root_static_context::root_static_context() : static_context()
{
  theTypemgr = new RootTypeManager();
}

#ifdef WIN32
static void append_to_path(std::vector<zstring>& aPath, zstring& zorba_root,
                           zstring& relpath)
{
  ascii::replace_all(relpath, '/', '\\');
  zstring full_path(zorba_root);
  full_path.append(relpath);
  full_path.append("\\");
  aPath.push_back(full_path);
}
#endif

void root_static_context::init() 
{
  QueryLoc loc;

  theImplementationBaseUri = ZORBA_NS;
  compute_base_uri();

  set_xquery_version(StaticContextConsts::xquery_version_3_0);
  set_xpath_compatibility(StaticContextConsts::xpath2_0);

  const char* const default_ns_initializers[] = 
    {
      //"err", XQUERY_ERR_NS,
      "fn", static_context::W3C_FN_NS.c_str(),
      "local", XQUERY_LOCAL_FN_NS,
      //"math", XQUERY_MATH_FN_NS,
      "xml", XML_NS,
      "xs", XML_SCHEMA_NS,
      "xsi", XSI_NS,
      "zerr", ZORBA_ERR_NS,
      NULL, NULL
    };

  for (const char* const* p = default_ns_initializers; *p != NULL; p += 2)
  {
    zstring pfx(p[0]);
    zstring ns (p[1]);
    bind_ns(pfx, ns, loc);
  }

  set_default_elem_type_ns(zstring(), loc);   

  set_default_function_ns(W3C_FN_NS, loc);

  set_context_item_type(GENV_TYPESYSTEM.ITEM_TYPE_ONE);

  add_collation(ZORBA_DEF_COLLATION_NS, QueryLoc::null);
  add_collation(W3C_CODEPT_COLLATION_NS, QueryLoc::null);
  set_default_collation(W3C_CODEPT_COLLATION_NS, QueryLoc::null);

  set_construction_mode(StaticContextConsts::cons_preserve);
  set_inherit_mode(StaticContextConsts::inherit_ns);
  set_preserve_mode(StaticContextConsts::preserve_ns);

  set_ordering_mode(StaticContextConsts::ordered);

  set_empty_order_mode(StaticContextConsts::empty_greatest);

  set_boundary_space_mode(StaticContextConsts::strip_space);

  set_default_w3c_collection_type(GENV_TYPESYSTEM.ITEM_TYPE_STAR);


  // TODO move into globalenv? memory leaks?
  add_url_resolver(new internal::FileURLResolver());
  add_url_resolver(new internal::HTTPURLResolver());
#ifndef ZORBA_NO_FULL_TEXT
  add_url_resolver(new internal::ThesaurusURLResolver());
#endif /* ZORBA_NO_FULL_TEXT */
  add_uri_mapper(new internal::FileizeURIMapper());
  add_uri_mapper(new internal::ModuleVersioningURIMapper());
  add_uri_mapper(new internal::AutoFSURIMapper());
  add_url_resolver(new internal::ZorbaCollectionURLResolver());
  add_uri_mapper(new internal::ZorbaCollectionURIMapper());

  set_validation_mode(StaticContextConsts::lax_validation);

  std::vector<zstring> lRootURIPath;
  std::vector<zstring> lRootLibPath;
#ifdef WIN32
  // compute the relative path to zorba_simplestore.dll (this dll)
  WCHAR  wdll_path[1024];
  DWORD dll_path_size;
  dll_path_size = GetModuleFileNameW(NULL, wdll_path, sizeof(wdll_path)/sizeof(wdll_path[0]));
  if(dll_path_size)
  {
    wdll_path[dll_path_size] = 0;
    char  dll_path[1024];
    WideCharToMultiByte(CP_UTF8, 0, wdll_path, -1, dll_path, sizeof(dll_path), NULL, NULL);
    char *last_slash = strrchr(dll_path, '\\');
    if(last_slash)
    {
      last_slash[1] = 0;
      zstring zorba_root_dir(dll_path);

      append_to_path(lRootURIPath, zorba_root_dir, zstring(ZORBA_CORE_URI_DIR));
      append_to_path(lRootURIPath, zorba_root_dir, zstring(ZORBA_NONCORE_URI_DIR));
      append_to_path(lRootLibPath, zorba_root_dir, zstring(ZORBA_CORE_LIB_DIR));
      append_to_path(lRootLibPath, zorba_root_dir, zstring(ZORBA_NONCORE_LIB_DIR));
    }
  }
#endif
  const char ** lURIPathIter = get_builtin_uri_path();
  for (; *lURIPathIter != 0; ++lURIPathIter)
  {
    lRootURIPath.push_back(*lURIPathIter);
  }
  set_uri_path(lRootURIPath);

  const char ** lLibPathIter = get_builtin_lib_path();
  for (; *lLibPathIter != 0; ++lLibPathIter)
  {
    lRootLibPath.push_back(*lLibPathIter);
  }
  set_lib_path(lRootLibPath);

  // by default enabled features
  set_feature( feature::ddl );
  set_feature( feature::scripting );
  set_feature( feature::trace );
} 


root_static_context::~root_static_context()
{
}

}
/* vim:set et sw=2 ts=2: */
