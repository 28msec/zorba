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

#include "functions/Nodes.h"
#include "functions/function_impl.h"

#include "runtime/nodes/NodesImpl.h"

#include "store/api/iterator.h"

using namespace std;

namespace zorba {


class node_reference : public function
{
public:
  node_reference(const signature &sig) : function (sig) {} 

  DEFAULT_CODEGEN (NodeReferenceIterator)
};


class node_by_reference : public function
{
public:
  node_by_reference(const signature &sig) : function (sig) {}    

  DEFAULT_CODEGEN (NodeByReferenceIterator)
};


class fn_local_name : public function 
{
public:
  fn_local_name(const signature &sig) : function (sig) {}

  DEFAULT_CODEGEN (FnLocalNameIterator)
};


class fn_namespace_uri : public function 
{
public:
  fn_namespace_uri(const signature &sig) : function (sig) {}

  DEFAULT_CODEGEN (FnNamespaceUriIterator)
};
  

class fn_lang : public function 
{
public:
  fn_lang(const signature &sig) : function (sig) {}

  DEFAULT_CODEGEN (FnLangIterator)
};
  

void populateContext_Nodes(static_context *sctx)
{
//begin functions on nodes
DECL(sctx, fn_local_name,
     (createQName(XQUERY_FN_NS, "fn", "local-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_namespace_uri,
     (createQName(XQUERY_FN_NS, "fn", "namespace-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));

// lang / - handled by translator
DECL(sctx, fn_lang,
     (createQName(XQUERY_FN_NS, "fn", "lang"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
//end functions on nodes

DECL(sctx, node_reference,
     (createQName(ZORBA_NODEREF_FN_NS, "fn-zorba", "node-reference"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));

DECL(sctx, node_by_reference,
     (createQName(ZORBA_NODEREF_FN_NS, "fn-zorba", "node-by-reference"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));

}

}/* namespace zorba */
