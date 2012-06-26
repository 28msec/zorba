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
#pragma once
#ifndef ZORBA_BINARY_SERIALIZATION_ARCHIVER_CONSTS
#define ZORBA_BINARY_SERIALIZATION_ARCHIVER_CONSTS

namespace zorba
{

namespace serialization
{

#define FIELD_IS_SIMPLE   true
#define FIELD_IS_CLASS    true


/*******************************************************************************

  ARCHIVE_FIELD_NORMAL:
  ---------------------
  A field of kind NORMAL or PTR acts as the root of a tree of fields representing
  the serialization of a concrete obj. If the kind is PTR, then the obj was 
  serialized when a pointer to it was encountered. In this case, during 
  deserialization, the archiver will allocate the obj on the heap and fill-in
  its data members. If the kind is NORMAL, then the obj was serialized when the 
  objitself was encountered (e.g., the object was an embedded data member of 
  another obj, or was residing on the program stack). In this case, during 
  deserialization, the object exists already (in an uninitialized state) and a
  reference to it is given to the archiver, which will fill-in the obj's data.

  ARCHIVE_FIELD_PTR:
  ------------------
  See comment for ARCHIVE_FIELD_NORMAL.

  ARCHIVE_FIELD_REFERENCING:
  --------------------------
  A field A that references another field B (of kind NORMAL or PTR), where both
  A and B represent the "same" object. 

  ARCHIVE_FIELD_BASECLASS:
  ------------------------
  A field representing a "partial" class object: If an obj O belongs to a 
  concrete class C and C is a subclass of a base class B, then a field of 
  BASECLASS kind is created to represent the serialization of the data members
  of B. This field is placed as the 1st child of the NORMAL or PTR field that 
  represents the serialization of O, and the children of the BASECALSS field
  represent the serializations of B's data members. If B itself is a subclass
  of another class A, then the 1st child of the B BASECLASS field is another
  BASECLASS field representing class A, etc.

  ARCHIVE_FIELD_NULL:
  -------------------
  A field representing a NULL pointer.

********************************************************************************/
enum ArchiveFieldKind
{
  ARCHIVE_FIELD_NORMAL,
  ARCHIVE_FIELD_PTR,
  ARCHIVE_FIELD_NULL,
  ARCHIVE_FIELD_BASECLASS,
  ARCHIVE_FIELD_REFERENCING
};


/*******************************************************************************

********************************************************************************/
enum ENUM_ALLOW_DELAY  
{
  ALLOW_DELAY,
  DONT_ALLOW_DELAY,
  SERIALIZE_NOW
};


/*******************************************************************************

********************************************************************************/
enum TypeCode
{
  TYPE_NULL = 0,

  TYPE_static_context,

  TYPE_SingletonIterator,

  TYPE_CtxVarDeclareIterator,
  TYPE_CtxVarIterator,
  TYPE_LetVarIterator,
  TYPE_ForVarIterator,
  TYPE_FLWORIterator,
  TYPE_ForLetClause,
  TYPE_OrderByClause,
  TYPE_MaterializeClause,
  TYPE_GroupByClause,

  TYPE_ChildAxisIterator,
  TYPE_DescendantSelfAxisIterator,
  TYPE_DescendantAxisIterator,
  TYPE_AttributeAxisIterator,
  TYPE_NodeNameTest,

  TYPE_SequentialIterator,

  TYPE_NodeSortIterator,
  TYPE_NodeDistinctIterator,

  TYPE_UDFunctionCallIterator,
  TYPE_ExtFunctionCallIterator,

  TYPE_HoistIterator,
  TYPE_UnhoistIterator,

  TYPE_ElementIterator,
  TYPE_AttributeIterator,
  TYPE_EnclosedIterator,

  TYPE_AndIterator,
  TYPE_OrIterator,
  TYPE_CompareIterator,
  TYPE_TypedValueCompareIterator_1,
  TYPE_TypedValueCompareIterator_2,
  TYPE_TypedValueCompareIterator_3,
  TYPE_TypedValueCompareIterator_4,
  TYPE_TypedValueCompareIterator_5,
  TYPE_FnBooleanIterator,

  TYPE_IfThenElseIterator,

  TYPE_InstanceOfIterator,
  TYPE_CastIterator,
  TYPE_PromoteIterator,
  TYPE_TreatIterator,
  TYPE_CastableIterator,
  TYPE_EitherNodesOrAtomicsIterator,

  TYPE_AtomicXQType,
  TYPE_StructuredItemXQType,
  TYPE_NodeXQType,
#ifdef ZORBA_WITH_JSON
  TYPE_JSONXQType,
#endif
  TYPE_FunctionXQType,
  TYPE_ItemXQType,
  TYPE_AnyXQType,
  TYPE_AnySimpleXQType,
  TYPE_AnyFunctionXQType,
  TYPE_UntypedXQType,
  TYPE_EmptyXQType,
  TYPE_NoneXQType,
  TYPE_UserDefinedXQType,
  TYPE_TypeManagerImpl,
  TYPE_Schema,

  TYPE_NumArithIterator_1,
  TYPE_NumArithIterator_2,
  TYPE_NumArithIterator_3,
  TYPE_NumArithIterator_4,
  TYPE_NumArithIterator_5,
  TYPE_NumArithIterator_6,

  TYPE_SpecificNumArithIterator_1,
  TYPE_SpecificNumArithIterator_2,
  TYPE_SpecificNumArithIterator_3,
  TYPE_SpecificNumArithIterator_4,
  TYPE_SpecificNumArithIterator_5,
  TYPE_SpecificNumArithIterator_6,
  TYPE_SpecificNumArithIterator_7,
  TYPE_SpecificNumArithIterator_8,
  TYPE_SpecificNumArithIterator_9,
  TYPE_SpecificNumArithIterator_10,
  TYPE_SpecificNumArithIterator_11,
  TYPE_SpecificNumArithIterator_12,
  TYPE_SpecificNumArithIterator_13,
  TYPE_SpecificNumArithIterator_14,
  TYPE_SpecificNumArithIterator_15,
  TYPE_SpecificNumArithIterator_16,
  TYPE_SpecificNumArithIterator_17,
  TYPE_SpecificNumArithIterator_18,
  TYPE_SpecificNumArithIterator_19,
  TYPE_SpecificNumArithIterator_20,

  TYPE_GenericArithIterator_1,
  TYPE_GenericArithIterator_2,
  TYPE_GenericArithIterator_3,
  TYPE_GenericArithIterator_4,
  TYPE_GenericArithIterator_5,
  TYPE_GenericArithIterator_6,

  TYPE_ApplyIterator,

  TYPE_LoopIterator,
  TYPE_ExitIterator,
  TYPE_ExitCatcherIterator,
  TYPE_FlowCtlIterator,

  TYPE_CtxVarAssignIterator,
  TYPE_CtxVarIsSetIterator,

  TYPE_ForIterator,
  TYPE_LetIterator,
  TYPE_TupleSourceIterator,
  TYPE_CountIterator,
  TYPE_OuterForIterator,
  TYPE_TupleStreamIterator,
  TYPE_WhereIterator,
  TYPE_WindowVars,
  TYPE_WindowIterator,
  TYPE_EndClause,
  TYPE_StartClause,
  TYPE_OrderSpec,
  TYPE_OrderByIterator,
  TYPE_NonGroupingSpec,
  TYPE_GroupingSpec,
  TYPE_GroupByIterator,

  TYPE_user_function,
  TYPE_function,
  TYPE_external_function,
  TYPE_signature,
  TYPE_AnnotationInternal,
  TYPE_AnnotationList,

  TYPE_TryCatchIterator,
  TYPE_CatchClause,

  TYPE_SelfAxisIterator,
  TYPE_ParentAxisIterator,
  TYPE_AncestorAxisIterator,
  TYPE_AncestorReverseAxisIterator,
  TYPE_AncestorSelfAxisIterator,
  TYPE_AncestorSelfReverseAxisIterator,
  TYPE_RSiblingAxisIterator,
  TYPE_LSiblingAxisIterator,
  TYPE_LSiblingReverseAxisIterator,

#include "runtime/iterator_enum.h"

  TYPE_DynamicFnCallIterator,

  TYPE_CountCollectionIterator,
  TYPE_ZorbaCollectionIteratorHelper_1,
  TYPE_ZorbaCollectionIteratorHelper_2,
  TYPE_ZorbaCollectionIteratorHelper_3,
  TYPE_ZorbaCollectionIteratorHelper_4,
  TYPE_ZorbaCollectionIteratorHelper_5,
  TYPE_ZorbaCollectionIteratorHelper_6,
  TYPE_ZorbaCollectionIteratorHelper_7,
  TYPE_ZorbaCollectionIteratorHelper_8,
  TYPE_ZorbaCollectionIteratorHelper_9,
  TYPE_ZorbaCollectionIteratorHelper_10,

  TYPE_EmptyIterator,

  TYPE_TransformIterator,
  TYPE_CopyClause,
  TYPE_RenameIterator,
  TYPE_ReplaceIterator,
  TYPE_DeleteIterator,
  TYPE_InsertIterator,

  TYPE_EvalIterator,

  TYPE_ProbeIndexPointValueIterator,
  TYPE_ProbeIndexPointGeneralIterator,
  TYPE_ProbeIndexRangeValueIterator,
  TYPE_ProbeIndexRangeGeneralIterator,
  TYPE_ValueIndexEntryBuilderIterator,
  TYPE_GeneralIndexEntryBuilderIterator,
  TYPE_RefreshIndexIterator,
  TYPE_DeleteIndexIterator,
  TYPE_CreateIndexIterator,
  TYPE_CreateInternalIndexIterator,

  TYPE_PrecedingAxisIterator,
  TYPE_PrecedingReverseAxisIterator,
  TYPE_FollowingAxisIterator,

  TYPE_MaterializeIterator,

  TYPE_FnMinMaxIterator,

  TYPE_AtomicValuesEquivalenceIterator,

  TYPE_OpNumericUnaryIterator,
  TYPE_OpDoubleUnaryIterator,

  TYPE_NameCastIterator,
  TYPE_DocumentIterator,
  TYPE_CommentIterator,
  TYPE_PiIterator,
  TYPE_TextIterator,

  TYPE_FnDateTimeConstructorIterator,
  TYPE_FnFormatDateTimeIterator,
  TYPE_FnAdjustToTimeZoneIterator_2,
  TYPE_FnAdjustToTimeZoneIterator_1,

  TYPE_FunctionItem,

  TYPE_namespace_context,

  TYPE_var_expr,

  TYPE_CompilerCB,
  TYPE_CompilerCB_config,

  TYPE_FTContainsIterator,
  TYPE_ftand,
  TYPE_ftcontent_filter,
  TYPE_ftcase_option,
  TYPE_ftdiacritics_option,
  TYPE_ftdistance_filter,
  TYPE_ftextension_option,
  TYPE_ftlanguage_option,
  TYPE_ftmatch_options,
  TYPE_ftmild_not,
  TYPE_ftor,
  TYPE_ftprimary_with_options,
  TYPE_ftscope_filter,
  TYPE_ftselection,
  TYPE_ftstem_option,
  TYPE_ftstop_words,
  TYPE_ftstop_word_option,
  TYPE_ftthesaurus_id,
  TYPE_ftthesaurus_option,
  TYPE_ftunary_not,
  TYPE_ftweight,
  TYPE_ftwild_card_option,
  TYPE_ftwords,
  TYPE_ftwords_times,
  TYPE_ftextension_selection,
  TYPE_ftorder_filter,
  TYPE_ftrange,
  TYPE_ftwindow_filter,

  TYPE_StaticallyKnownCollection,
  TYPE_IndexDecl,
  TYPE_ValueIC,
  TYPE_OrderModifier,

  TYPE_DecimalFormat,

  TYPE_BaseUriInfo,
  TYPE_FunctionInfo,
  TYPE_PrologOption,
  TYPE_sctx_module,

  TYPE_QueryLoc,

  TYPE_PLAN_PROXY,

  TYPE_XQueryImpl,

  TYPE_Breakable,
  TYPE_DebuggerSingletonIterator,
  TYPE_DebuggerCommons,

  TYPE_RCObject,

  TYPE_INT64,
  TYPE_UINT64,
  TYPE_INT32,
  TYPE_UINT32,
  TYPE_ENUM,
  TYPE_INT16,
  TYPE_UINT16,
  TYPE_CHAR,
  TYPE_UCHAR,

  TYPE_FLOAT,
  TYPE_DOUBLE,

  TYPE_BOOL,

  TYPE_STD_STRING,
  TYPE_ZSTRING,

  TYPE_COLLATOR,

  TYPE_UNKNOWN,
  TYPE_LAST
};


/*******************************************************************************

********************************************************************************/
typedef union
{
  int64_t         int64v;
  uint64_t        uint64v;
  int32_t         int32v;
  uint32_t        uint32v;  
  int16_t         int16v;
  uint16_t        uint16v;
  char            charv;
  unsigned char   ucharv;
  bool            boolv;
} SimpleValue;
  

}
}
#endif
/* vim:set et sw=2 ts=2: */
