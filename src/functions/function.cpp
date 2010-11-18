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

#include "compiler/expression/expr_base.h"

#include "system/globalenv.h"

#include "functions/function_impl.h"

#include "types/typeops.h"

#include "util/hashmap32.h"
#include "util/string_util.h"

#include "zorbaerrors/Assert.h"


namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(function)
END_SERIALIZABLE_CLASS_VERSIONS(function)


/*******************************************************************************

********************************************************************************/
function::function(const signature& sig, FunctionConsts::FunctionKind kind)
  :
  theSignature(sig),
  theKind(kind),
  theFlags(0)
{
  setFlag(FunctionConsts::isBuiltin);
  setFlag(FunctionConsts::isDeterministic);

  zorba::serialization::Archiver& ar =
  *::zorba::serialization::ClassSerializer::getInstance()->
  getArchiverForHardcodedObjects();

  if(ar.is_loading_hardcoded_objects())
  {
    // register this hardcoded object to help plan serialization
    function* this_ptr = this;
    ar & this_ptr;
  }
}


/*******************************************************************************

********************************************************************************/
void function::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theSignature;
  SERIALIZE_ENUM(FunctionConsts::FunctionKind, theKind);
  ar & theFlags;
  ar & theAnnotationList;
}


/*******************************************************************************

********************************************************************************/
xqtref_t function::getReturnType(
    const TypeManager* tm,
    const std::vector<xqtref_t>&) const
{
  return theSignature.returnType();
}


/*******************************************************************************

********************************************************************************/
bool function::validate_args(std::vector<PlanIter_t>& argv) const
{
  ulong n = theSignature.paramCount();
  return n == VARIADIC_SIG_SIZE || argv.size() == n;
}


/*******************************************************************************
  Check whether this function is a map with respect to the given input
********************************************************************************/
bool function::isMap(ulong input) const
{
  if (!theSignature.isVariadic() &&
      theSignature.paramCount() > 0 &&
      (theSignature[input]->get_quantifier() == TypeConstants::QUANT_ONE ||
       theSignature[input]->get_quantifier() == TypeConstants::QUANT_QUESTION))
    return true;

  return false;
}


/*******************************************************************************
  Check whether this function produces, preserves, or eliminates duplicate nodes.
********************************************************************************/
FunctionConsts::AnnotationValue function::producesDistinctNodes() const
{
  xqtref_t rt = theSignature.returnType();

  TypeManager* tm = rt->get_manager();

  if (TypeOps::type_max_cnt(tm, *rt) <= 1 ||
      TypeOps::is_subtype(tm, *rt, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
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

  if (TypeOps::type_max_cnt(tm, *rt) <= 1 ||
      TypeOps::is_subtype(tm, *rt, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
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
********************************************************************************/
BoolAnnotationValue function::ignoresSortedNodes(expr* fo, ulong input) const 
{
  if (isVariadic() && input > 0)
  {
    return ANNOTATION_FALSE;
  }

  xqtref_t rt = theSignature[input];

  TypeManager* tm = rt->get_manager();

  if (TypeOps::type_max_cnt(tm, *rt) <= 1)
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
********************************************************************************/
BoolAnnotationValue function::ignoresDuplicateNodes(expr* fo, ulong input) const
{
  return ANNOTATION_FALSE;
}


}

/* vim:set ts=2 sw=2: */
