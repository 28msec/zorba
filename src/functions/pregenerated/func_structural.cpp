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
#include "runtime/nodes/structural.h"
#include "functions/func_structural.h"


namespace zorba{



PlanIter_t fn_zorba_struct_node_structural_information::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_ancestor_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAncestorStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_following_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingSiblingStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_following_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_descendant_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDescendantStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_preceding_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingSiblingStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_preceding_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_child_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsChildStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_attribute_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAttributeOfStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_parent_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsParentStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_preceding_in_document_order_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingInDocumentOrderStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_following_in_document_order_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingInDocumentOrderStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_level::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LevelStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_is_attribute::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAttributeStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_is_comment::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsCommentStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_is_document::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDocumentStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_is_element::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsElementStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_is_processing_instruction::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsProcessingInstructionStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_is_text::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsTextStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsSiblingStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_in_same_tree_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InSameTreeStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_in_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InCollectionStructuralInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_struct_in_same_collection_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InSameCollectionStructuralInformationIterator(sctx, loc, argv);
}

void populate_context_structural(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_node_structural_information,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","node-structural-information"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_NODE_STRUCTURAL_INFORMATION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_ancestor_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","ancestor-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_ANCESTOR_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_following_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","following-sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_FOLLOWING_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_following_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","following-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_FOLLOWING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_descendant_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","descendant-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_DESCENDANT_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_preceding_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","preceding-sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_PRECEDING_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_preceding_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","preceding-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_PRECEDING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_child_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","child-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_CHILD_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_attribute_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","attribute-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_ATTRIBUTE_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_parent_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","parent-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_PARENT_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_preceding_in_document_order_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","preceding-in-document-order-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_PRECEDING_IN_DOCUMENT_ORDER_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_following_in_document_order_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","following-in-document-order-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_FOLLOWING_IN_DOCUMENT_ORDER_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_level,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","level"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_LEVEL_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_is_attribute,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","is-attribute"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IS_ATTRIBUTE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_is_comment,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","is-comment"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IS_COMMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_is_document,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","is-document"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IS_DOCUMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_is_element,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","is-element"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IS_ELEMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_is_processing_instruction,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","is-processing-instruction"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IS_PROCESSING_INSTRUCTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_is_text,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","is-text"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IS_TEXT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_in_same_tree_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","in-same-tree-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IN_SAME_TREE_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_in_collection,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","in-collection"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IN_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_struct_in_same_collection_of,
        (createQName("http://www.zorba-xquery.com/modules/node-structural-information","","in-same-collection-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_STRUCT_IN_SAME_COLLECTION_OF_2);

  }

}


}



