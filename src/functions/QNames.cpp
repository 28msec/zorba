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
#include "system/globalenv.h"

#include "functions/QNames.h"
#include "functions/function_impl.h"

#include "runtime/qnames/QNamesImpl.h"

#include "types/node_test.h"

namespace zorba 
{


/*
 * 11.1.1 fn:resolve-QName
 *-----------------------*/
class fn_resolve_qname : public function
{
public:
  fn_resolve_qname(const signature& sig) : function (sig) {}
  
  DEFAULT_BINARY_CODEGEN(ResolveQNameIterator);
};
  

/*
 * 11.1.2 fn:QName
 *-----------------------*/
class fn_qname : public function
{
public:
  fn_qname(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(QNameIterator);
};

  
/*
 * 11.2.1 op:QName-equal
 *-----------------------*/
class op_qname_equal: public function
{
public:
  op_qname_equal(const signature& sig) : function (sig) {}

  DEFAULT_BINARY_CODEGEN(QNameEqualIterator);
};


/*
 * 11.2.2 fn:prefix-from-QName
 *-----------------------*/
class fn_prefix_from_qname: public function
{
public:
  fn_prefix_from_qname(const signature& sig) : function (sig) {}

  DEFAULT_UNARY_CODEGEN(PrefixFromQNameIterator);
};

/*
 * 11.2.3 fn:local-name-from-QName
 *-----------------------*/
class fn_local_name_from_qname: public function
{
public:
  fn_local_name_from_qname(const signature& sig) : function (sig) {}

  DEFAULT_UNARY_CODEGEN(LocalNameFromQNameIterator);
};


/*
 * 11.2.4 fn:namespace-uri-from-QName
 *-----------------------*/
class fn_namespace_uri_from_qname: public function
{
public:
  fn_namespace_uri_from_qname(const signature& sig) : function (sig) {}

  DEFAULT_UNARY_CODEGEN(NamespaceUriFromQNameIterator);
};


/*
 * 11.2.5 fn:namespace-uri-for-prefix
 *-----------------------*/
class fn_namespace_uri_for_prefix: public function
{
public:
  fn_namespace_uri_for_prefix(const signature& sig) : function (sig) {}
  
  DEFAULT_NARY_CODEGEN(NamespaceUriForPrefixIterator);
};


/*
 * 11.2.6 fn:in-scope-prefixes
 *-----------------------*/
class fn_in_scope_prefixes: public function
{
public:
  fn_in_scope_prefixes(const signature& sig) : function (sig) {}

  DEFAULT_UNARY_CODEGEN(InScopePrefixesIterator);
};


void populateContext_QNames(static_context* sctx)
{
  DECL(sctx, fn_resolve_qname,
       (createQName(XQUERY_FN_NS, "fn",  "resolve-QName"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));
      
  DECL(sctx, fn_qname,
       (createQName(XQUERY_FN_NS, "fn", "QName"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.QNAME_TYPE_ONE));

  DECL(sctx, op_qname_equal,
       (createQName(XQUERY_FN_NS,"fn","QName-equal"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, fn_prefix_from_qname,
       (createQName(XQUERY_FN_NS,"fn","prefix-from-QName"),
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
        GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));

  DECL(sctx, fn_local_name_from_qname,
       (createQName(XQUERY_FN_NS,"fn","local-name-from-QName"),
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
        GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));
  
  DECL(sctx, fn_namespace_uri_from_qname,
       (createQName(XQUERY_FN_NS,"fn","namespace-uri-from-QName"),
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

  DECL(sctx, fn_namespace_uri_for_prefix,
       (createQName(XQUERY_FN_NS,"fn","namespace-uri-for-prefix"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

  DECL(sctx, fn_in_scope_prefixes,
       (createQName(XQUERY_FN_NS,"fn","in-scope-prefixes"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_STAR));
}

}
