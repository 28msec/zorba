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
#include "runtime/nodes/node_position.h"
#include "functions/func_node_position.h"


namespace zorba{



PlanIter_t fn_zorba_pos_node_position::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodePositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_ancestor_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAncestorPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_following_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingSiblingPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_following_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_in_subtree_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsInSubtreeOfPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_descendant_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDescendantPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_preceding_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingSiblingPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_preceding_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_child_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsChildPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_attribute_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAttributeOfPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_parent_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsParentPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_preceding_in_document_order_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingInDocumentOrderPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_following_in_document_order_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingInDocumentOrderPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_level::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LevelPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_is_attribute::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAttributePositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_is_comment::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsCommentPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_is_document::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDocumentPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_is_element::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsElementPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_is_processing_instruction::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsProcessingInstructionPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_is_text::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsTextPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsSiblingPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_in_same_tree_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InSameTreePositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_in_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InCollectionPositionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_pos_in_same_collection_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InSameCollectionPositionIterator(sctx, loc, argv);
}

void populate_context_node_position(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_node_position,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","node-position"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_NODE_POSITION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_ancestor_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","ancestor-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_ANCESTOR_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_following_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","following-sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_FOLLOWING_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_following_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","following-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_FOLLOWING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_in_subtree_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","in-subtree-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IN_SUBTREE_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_descendant_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","descendant-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_DESCENDANT_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_preceding_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","preceding-sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_PRECEDING_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_preceding_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","preceding-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_PRECEDING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_child_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","child-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_CHILD_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_attribute_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","attribute-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_ATTRIBUTE_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_parent_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","parent-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_PARENT_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_preceding_in_document_order_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","preceding-in-document-order-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_PRECEDING_IN_DOCUMENT_ORDER_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_following_in_document_order_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","following-in-document-order-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_FOLLOWING_IN_DOCUMENT_ORDER_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_level,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","level"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_LEVEL_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_is_attribute,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","is-attribute"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IS_ATTRIBUTE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_is_comment,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","is-comment"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IS_COMMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_is_document,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","is-document"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IS_DOCUMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_is_element,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","is-element"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IS_ELEMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_is_processing_instruction,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","is-processing-instruction"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IS_PROCESSING_INSTRUCTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_is_text,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","is-text"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IS_TEXT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_in_same_tree_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","in-same-tree-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IN_SAME_TREE_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_in_collection,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","in-collection"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IN_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_pos_in_same_collection_of,
        (createQName("http://www.zorba-xquery.com/modules/node-position","","in-same-collection-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_POS_IN_SAME_COLLECTION_OF_2);

  }

}


}



