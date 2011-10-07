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
#include "runtime/nodes/node_information.h"
#include "functions/func_node_information.h"


namespace zorba{



PlanIter_t fn_zorba_info_node_information::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_ancestor_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAncestorInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_following_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingSiblingInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_following_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_descendant_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDescendantInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_preceding_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingSiblingInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_preceding_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_child_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsChildInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_attribute_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAttributeOfInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_parent_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsParentInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_preceding_in_document_order_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsPrecedingInDocumentOrderInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_following_in_document_order_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsFollowingInDocumentOrderInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_level::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LevelInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_is_attribute::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsAttributeInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_is_comment::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsCommentInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_is_document::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsDocumentInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_is_element::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsElementInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_is_processing_instruction::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsProcessingInstructionInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_is_text::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsTextInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_sibling_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new IsSiblingInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_in_same_tree_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InSameTreeInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_in_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InCollectionInformationIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_info_in_same_collection_of::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InSameCollectionInformationIterator(sctx, loc, argv);
}

void populate_context_node_information(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_node_information,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","node-information"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_NODE_INFORMATION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_ancestor_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","ancestor-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_ANCESTOR_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_following_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","following-sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_FOLLOWING_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_following_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","following-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_FOLLOWING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_descendant_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","descendant-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_DESCENDANT_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_preceding_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","preceding-sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_PRECEDING_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_preceding_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","preceding-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_PRECEDING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_child_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","child-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_CHILD_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_attribute_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","attribute-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_ATTRIBUTE_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_parent_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","parent-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_PARENT_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_preceding_in_document_order_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","preceding-in-document-order-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_PRECEDING_IN_DOCUMENT_ORDER_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_following_in_document_order_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","following-in-document-order-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_FOLLOWING_IN_DOCUMENT_ORDER_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_level,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","level"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_LEVEL_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_is_attribute,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","is-attribute"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IS_ATTRIBUTE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_is_comment,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","is-comment"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IS_COMMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_is_document,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","is-document"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IS_DOCUMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_is_element,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","is-element"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IS_ELEMENT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_is_processing_instruction,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","is-processing-instruction"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IS_PROCESSING_INSTRUCTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_is_text,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","is-text"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IS_TEXT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_sibling_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","sibling-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_SIBLING_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_in_same_tree_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","in-same-tree-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IN_SAME_TREE_OF_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_in_collection,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","in-collection"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IN_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_info_in_same_collection_of,
        (createQName("http://www.zorba-xquery.com/modules/node-information","","in-same-collection-of"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_INFO_IN_SAME_COLLECTION_OF_2);

  }

}


}



