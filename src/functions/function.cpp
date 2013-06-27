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

#include "compiler/expression/expr_base.h"
#include "compiler/expression/fo_expr.h"

#include "system/globalenv.h"

#include "functions/function_impl.h"

#include "types/typeops.h"

#include "util/string_util.h"

#include "diagnostics/assert.h"

#include "zorbaserialization/serialize_template_types.h"


namespace zorba {


SERIALIZABLE_CLASS_VERSIONS(function);


/*******************************************************************************

********************************************************************************/
function::function(const signature& sig, FunctionConsts::FunctionKind kind)
  :
  theSignature(sig),
  theKind(kind),
  theFlags(0),
  theModuleSctx(NULL),
  theXQueryVersion(StaticContextConsts::xquery_version_1_0)
{
  setFlag(FunctionConsts::isBuiltin);
  setFlag(FunctionConsts::isDeterministic);
}


/*******************************************************************************

********************************************************************************/
void function::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theSignature;
  SERIALIZE_ENUM(FunctionConsts::FunctionKind, theKind);
  ar & theFlags;
  ar & theAnnotationList;
  ar & theModuleSctx;
  SERIALIZE_ENUM(StaticContextConsts::xquery_version_t, theXQueryVersion);

  // If we don't pre-serialize builtin function, it is possible that a builtin
  // functions needs to be serialized. This happens for builtin functions that
  // are disabled, and as a result, have been registered in a non-root static
  // context.
}


/*******************************************************************************

********************************************************************************/
bool function::validate_args(std::vector<PlanIter_t>& argv) const
{
  ulong n = theSignature.paramCount();
  return n == VARIADIC_SIG_SIZE || argv.size() == n;
}


/*******************************************************************************

********************************************************************************/
void function::setAnnotations(AnnotationList* annotations)
{
  theAnnotationList = annotations;

  if (!theAnnotationList)
    return;

  if (theAnnotationList->contains(AnnotationInternal::zann_nondeterministic))
    setDeterministic(false);

  setPrivate(theAnnotationList->contains(AnnotationInternal::fn_private));

  if (isUpdating() &&
      theAnnotationList->contains(AnnotationInternal::zann_sequential))
  {
    throw XQUERY_EXCEPTION(zerr::XSST0001,
    ERROR_PARAMS(getName()->getStringValue()));
  }
}


/*******************************************************************************
  This is a virstual method. It is redefined by udf and external-function
  classes. 
********************************************************************************/
unsigned short function::getScriptingKind() const 
{
  return SIMPLE_EXPR;
}


/*******************************************************************************

********************************************************************************/
bool function::isSequential() const
{
  return expr::is_sequential(getScriptingKind());
}


/*******************************************************************************

********************************************************************************/
bool function::isContextual() const 
{
  switch (getKind())
  {
  case FunctionConsts::FN_POSITION_0:
  case FunctionConsts::FN_LAST_0:
  case FunctionConsts::FN_STRING_LENGTH_0: 
  case FunctionConsts::FN_NORMALIZE_SPACE_0:
  case FunctionConsts::FN_ROOT_0:
  case FunctionConsts::FN_BASE_URI_0:
  case FunctionConsts::FN_NAMESPACE_URI_0:
  case FunctionConsts::FN_LOCAL_NAME_0:
  case FunctionConsts::FN_NAME_0:     
  case FunctionConsts::FN_STRING_0:
  case FunctionConsts::FN_GENERATE_ID_0:
  case FunctionConsts::FN_DATA_0:
  case FunctionConsts::FN_DOCUMENT_URI_0:
  case FunctionConsts::FN_NODE_NAME_0:
  case FunctionConsts::FN_NILLED_0:
  case FunctionConsts::FN_HAS_CHILDREN_0:
  case FunctionConsts::FN_PATH_0:
  case FunctionConsts::FN_NUMBER_0:
  case FunctionConsts::FN_LANG_1:
  case FunctionConsts::FN_IDREF_1:
  case FunctionConsts::FN_ID_1:
  case FunctionConsts::FN_ELEMENT_WITH_ID_1:
  case FunctionConsts::FN_FUNCTION_LOOKUP_2:
    return true;
  default:
    return false;
  }
}


/*******************************************************************************
  This is a virstual method. It is NOT redefined by udf and external-function
  classes. However, for UDFs it is possible that the user-declared type is
  narrowed down to a subtypes; see UDFGraph::optimizeUDFs() in udf_graph.cpp
********************************************************************************/
xqtref_t function::getReturnType(const fo_expr*) const
{
  return theSignature.returnType();
}


/*******************************************************************************
  This is a virstual method. It is redefined by udf and external-function
  classes. 
********************************************************************************/
bool function::accessesDynCtx() const 
{
  return false;
}


/*******************************************************************************
  Check whether this function is a map with respect to the given input.

  This is a virstual method. It is NOT redefined by udf and external-function
  classes. TODO ???? redefine it for UDFs
********************************************************************************/
bool function::isMap(csize input) const
{
  if (!theSignature.isVariadic() &&
      theSignature.paramCount() > 0 &&
      (theSignature[input]->get_quantifier() == TypeConstants::QUANT_ONE ||
       theSignature[input]->get_quantifier() == TypeConstants::QUANT_QUESTION))
    return true;

  return false;
}


/*******************************************************************************
  Check whether this function may return a node that belongs to the same tree
  as a node inside the sequence that is bound to the given input parameter.

  Note: this method is not applicable to udfs.
********************************************************************************/
bool function::propagatesInputNodes(expr* fo, csize input) const
{
  assert(!isUdf());

  TypeManager* tm = fo->get_type_manager();

  // This method should be called only if the function may indeed return nodes
  assert(!TypeOps::is_subtype(tm,
                              *fo->get_return_type(),
                              *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

  xqtref_t argType = static_cast<fo_expr*>(fo)->get_arg(input)->get_return_type();

  if (TypeOps::is_subtype(tm, *argType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
    return false;

  return true; // conservative answer
}


/*******************************************************************************
  Check whether this function cares whether nodes bound to the given input 
  parameter belong to "standalone" trees or not. A tree is standalone if it
  does not contain references to other trees. Such references are created when
  the optimizer decides that it is ok to avoid copying the referenced subtree
  (as would be required by required by a strict implementation of the spec,
  eg. during node construction). 

  Note: this method is not applicable to udfs.
********************************************************************************/
bool function::mustCopyInputNodes(expr* fo, csize input) const
{
  assert(!isUdf());

  TypeManager* tm = fo->get_type_manager();

  xqtref_t argType = static_cast<fo_expr*>(fo)->get_arg(input)->get_return_type();

  if (TypeOps::is_subtype(tm, *argType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
    return false;

  return true;
}


/*******************************************************************************
  Check whether this function produces, preserves, or eliminates duplicate nodes.
********************************************************************************/
FunctionConsts::AnnotationValue function::producesDistinctNodes() const
{
  xqtref_t rt = theSignature.returnType();

  TypeManager* tm = rt->get_manager();

  if (rt->max_card() <= 1 ||
      TypeOps::is_subtype(tm,
                          *rt,
                          *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
                          QueryLoc::null))
  {
    return FunctionConsts::YES;
  }

  return FunctionConsts::PRESERVE;
}


/*******************************************************************************
  Check whether this function produces nodes in document order, preserves the
  doc order of its input, or produces nodes out of doc order.
********************************************************************************/
FunctionConsts::AnnotationValue function::producesSortedNodes() const
{
  xqtref_t rt = theSignature.returnType();

  TypeManager* tm = rt->get_manager();

  if (rt->max_card() <= 1 ||
      TypeOps::is_subtype(tm,
                          *rt,
                          *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
                          QueryLoc::null))
  {
    return FunctionConsts::YES;
  }

  return FunctionConsts::PRESERVE;
}


/*******************************************************************************
  Check whether this function cares whether the sequence bound to the given
  input parameter is in document order or not. The decision may depend on
  whether the result of this function, at the point where it is called, must
  be in doc order or not.

  This is a virstual method. It is redefined by the udf class but not by the
  external-function class. 
********************************************************************************/
BoolAnnotationValue function::ignoresSortedNodes(expr* fo, csize input) const
{
  if (isVariadic() && input > 0)
  {
    return ANNOTATION_FALSE;
  }

  xqtref_t rt = theSignature[input];

  if (rt->max_card() <= 1)
  {
    return ANNOTATION_TRUE;
  }

  return ANNOTATION_FALSE;
}


/*******************************************************************************
  Check whether this function cares whether the sequence bound to the given
  input parameter contains duplicate nodes or not. The decision may depend on
  whether the result of this function, at the point where it is called, must
  contain distinct nodes or not.

  This is a virstual method. It is redefined by the udf class but not by the
  external-function class. 
********************************************************************************/
BoolAnnotationValue function::ignoresDuplicateNodes(expr* fo, csize input) const
{
  return ANNOTATION_FALSE;
}


/*******************************************************************************

********************************************************************************/
PlanIter_t function::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  ZORBA_ASSERT(false);
}


}
/* vim:set et sw=2 ts=2: */
