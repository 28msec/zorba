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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#include "stdafx.h"
#include "runtime/store/identifiers.h"
#include "functions/func_identifiers.h"


namespace zorba{



PlanIter_t zorba_store_node_identifiers_node_identifier::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeIdentifierIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_node_identifiers_has_identifier::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new HasIdentifierIterator(sctx, loc, argv);
}

PlanIter_t zorba_store_node_identifiers_node_by_identifier::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeByIdentifierIterator(sctx, loc, argv);
}

void populate_context_identifiers(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, zorba_store_node_identifiers_node_identifier,
        (createQName("http://www.zorba-xquery.com/modules/store/node-identifiers","","node-identifier"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_NODE_IDENTIFIERS_NODE_IDENTIFIER_3);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_node_identifiers_has_identifier,
        (createQName("http://www.zorba-xquery.com/modules/store/node-identifiers","","has-identifier"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_NODE_IDENTIFIERS_HAS_IDENTIFIER_1);

  }


  {
    

    DECL_WITH_KIND(sctx, zorba_store_node_identifiers_node_by_identifier,
        (createQName("http://www.zorba-xquery.com/modules/store/node-identifiers","","node-by-identifier"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE),
        FunctionConsts::ZORBA_STORE_NODE_IDENTIFIERS_NODE_BY_IDENTIFIER_1);

  }

}


}



