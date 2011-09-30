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
#include "runtime/nodes/nodes.h"
#include "functions/func_nodes.h"


namespace zorba{



PlanIter_t fn_zorba_ref_node_reference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeReferenceIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ref_has_reference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new HasReferenceIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_ref_node_by_reference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeByReferenceIterator(sctx, loc, argv);
}

PlanIter_t fn_local_name::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnLocalNameIterator(sctx, loc, argv);
}

PlanIter_t fn_namespace_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnNamespaceUriIterator(sctx, loc, argv);
}

PlanIter_t fn_lang::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnLangIterator(sctx, loc, argv);
}

PlanIter_t fn_number::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return NULL;
}

PlanIter_t fn_has_children_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnHasChildrenIterator(sctx, loc, argv);
}

PlanIter_t fn_innermost_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnInnermostIterator(sctx, loc, argv);
}

PlanIter_t fn_outermost_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnOutermostIterator(sctx, loc, argv);
}

PlanIter_t fn_generate_id_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnGenerateIdIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_ancestor_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAncestorIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_descendant_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDescendantIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_parent_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsParentIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_child_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsChildIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_following_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_preceding_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_following_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingSiblingIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_preceding_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingSiblingIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_level::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LevelIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_node_least_common_ancestor::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LeastCommonAncestor(sctx, loc, argv);
}

void populate_context_nodes(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_zorba_ref_node_reference,
        (createQName("http://www.zorba-xquery.com/modules/node-reference","","node-reference"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE),
        FunctionConsts::FN_ZORBA_REF_NODE_REFERENCE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_ref_has_reference,
        (createQName("http://www.zorba-xquery.com/modules/node-reference","","has-reference"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_REF_HAS_REFERENCE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_ref_node_by_reference,
        (createQName("http://www.zorba-xquery.com/modules/node-reference","","node-by-reference"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION),
        FunctionConsts::FN_ZORBA_REF_NODE_BY_REFERENCE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_local_name,
        (createQName("http://www.w3.org/2005/xpath-functions","","local-name"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_LOCAL_NAME_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_local_name,
        (createQName("http://www.w3.org/2005/xpath-functions","","local-name"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_LOCAL_NAME_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_namespace_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","namespace-uri"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION),
        FunctionConsts::FN_NAMESPACE_URI_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_namespace_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","namespace-uri"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION),
        FunctionConsts::FN_NAMESPACE_URI_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_lang,
        (createQName("http://www.w3.org/2005/xpath-functions","","lang"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_LANG_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_lang,
        (createQName("http://www.w3.org/2005/xpath-functions","","lang"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_LANG_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_number,
        (createQName("http://www.w3.org/2005/xpath-functions","","number"), 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_NUMBER_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_number,
        (createQName("http://www.w3.org/2005/xpath-functions","","number"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
        FunctionConsts::FN_NUMBER_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_has_children_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","has-children"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_HAS_CHILDREN_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_innermost_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","innermost"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_INNERMOST_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_outermost_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","outermost"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::FN_OUTERMOST_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_generate_id_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","generate-id"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_GENERATE_ID_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_generate_id_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","generate-id"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_GENERATE_ID_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_ancestor_of,
        (createQName("http://www.zorba-xquery.com/modules/node","","ancestor-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_ANCESTOR_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_descendant_of,
        (createQName("http://www.zorba-xquery.com/modules/node","","descendant-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_DESCENDANT_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_parent_of,
        (createQName("http://www.zorba-xquery.com/modules/node","","parent-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_PARENT_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_child_of,
        (createQName("http://www.zorba-xquery.com/modules/node","","child-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_CHILD_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_following_of,
        (createQName("http://www.zorba-xquery.com/modules/node","","following-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_FOLLOWING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_preceding_of,
        (createQName("http://www.zorba-xquery.com/modules/node","","preceding-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_PRECEDING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_following_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node","","following-sibling-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_FOLLOWING_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_preceding_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node","","preceding-sibling-of"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_PRECEDING_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_level,
        (createQName("http://www.zorba-xquery.com/modules/node","","level"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_ZORBA_NODE_LEVEL_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_node_least_common_ancestor,
        (createQName("http://www.zorba-xquery.com/modules/node","","least-common-ancestor"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION),
        FunctionConsts::FN_ZORBA_NODE_LEAST_COMMON_ANCESTOR_2);

  }

}


}



