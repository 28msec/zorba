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

#include "compiler/semantic_annotations/tsv_annotation.h"
#include "compiler/semantic_annotations/annotation_keys.h"

#include "functions/function_impl.h"

#include "util/hashmap32.h"
#include "util/string_util.h"

#include "types/typeops.h"

#include "zorbaerrors/Assert.h"


using namespace std;

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(function)
END_SERIALIZABLE_CLASS_VERSIONS(function)


/*******************************************************************************

********************************************************************************/
function::function(const signature& sig)
  :
  theSignature(sig),
  theKind(FunctionConsts::FN_UNKNOWN),
  theFlags(0)
{
  const store::Item* lName = getName();
  //lName may be null for inlined functions
  if(lName != 0 &&
     equals(getName()->getNamespace(), XQUERY_FN_NS, sizeof(XQUERY_FN_NS)-1))
  {
    setFlag(FunctionConsts::hasFnNamespace);
  }

  setDeterministic(true);

  zorba::serialization::Archiver& ar =
  *::zorba::serialization::ClassSerializer::getInstance()->
  getArchiverForHardcodedObjects();

  if (ar.is_loading_hardcoded_objects())
  {
    // register this hardcoded object to help plan serialization
    function* this_ptr = this;
    ar & this_ptr;
  }
}


/*******************************************************************************

********************************************************************************/
function::function(const signature& sig, FunctionConsts::FunctionKind kind)
  :
  theSignature(sig),
  theKind(kind),
  theFlags(0)
{
  if (equals(getName()->getNamespace(), XQUERY_FN_NS, sizeof(XQUERY_FN_NS)-1))
    setFlag(FunctionConsts::hasFnNamespace);

  setDeterministic(true);

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
  uint32_t n = theSignature.paramCount ();
  return n == VARIADIC_SIG_SIZE || argv.size() == theSignature.paramCount();
}



/*******************************************************************************
  Propagate a property of this function down to its inputs.
********************************************************************************/
void function::compute_annotation(
    AnnotationHolder* parent,
    std::vector<AnnotationHolder *>& kids,
    Annotations::Key k) const
{
  switch (k)
  {
  case Annotations::IGNORES_SORTED_NODES:
  case Annotations::IGNORES_DUP_NODES:
  {
    for (unsigned src = 0; src < kids.size(); ++src)
    {
      if (kids[src] != NULL)
      {
        // Unless this method is redefined by a specific function, a function
        // is considered as "potentially interested" in sorted and/or duplicate
        // nodes. In this case, each of its input exprs must also be marked as
        // "potentially interested", even if the input expr by itself is not
        // interested.
        TSVAnnotationValue::update_annotation(kids[src],
                                              k,
                                              TSVAnnotationValue::MAYBE_VAL);
      }
    }
    break;
  }
  default:
    ZORBA_ASSERT(false);
  }
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


}

/* vim:set ts=2 sw=2: */
