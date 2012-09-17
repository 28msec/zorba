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

#include "runtime/function_item/function_item.h"
#include "runtime/core/fncall_iterator.h"
#include "runtime/base/plan_iterator.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/function_item_expr.h"

#include "functions/signature.h"
#include "functions/udf.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(FunctionItem)


FunctionItem::FunctionItem(::zorba::serialization::Archiver& ar)
  :
  store::Item(store::Item::FUNCTION)
{
}


FunctionItem::FunctionItem(
    CompilerCB* ccb,
    static_context* sctx,
    function_item_expr* expr,
    const std::vector<PlanIter_t>& varValues)
  :
  store::Item(store::Item::FUNCTION),
  theCCB(ccb),
  theSctx(sctx),
  theLoc(expr->get_loc()),
  theQName(expr->get_qname()),
  theFunction(expr->get_function()),
  theArity(expr->get_arity()),
  theVariableValues(varValues)
{
  assert(theFunction->isUdf());
}


FunctionItem::FunctionItem(
    CompilerCB* ccb,
    static_context* sctx,
    function_item_expr* expr)
  :
  store::Item(store::Item::FUNCTION),
  theCCB(ccb),
  theSctx(sctx),
  theLoc(expr->get_loc()),
  theQName(expr->get_qname()),
  theFunction(expr->get_function()),
  theArity(expr->get_arity())
{
  assert(theFunction->isUdf());
}


FunctionItem::~FunctionItem()
{
}

void FunctionItem::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theCCB;
  ar & theSctx;
  ar & theLoc;
  ar & theQName;
  ar & theArity;
  ar & theFunction;
  ar & theVariableValues;

  if (ar.is_serializing_out())
  {
    uint32_t planStateSize;
    (void)static_cast<user_function*>(theFunction.getp())->
    getPlan(planStateSize);
  }
}

const store::Item_t FunctionItem::getFunctionName() const
{
  return theQName;
}


uint32_t FunctionItem::getArity() const
{
  return theArity;
}


const signature& FunctionItem::getSignature() const
{
  return theFunction->getSignature();
}


const std::vector<PlanIter_t>& FunctionItem::getVariables() const
{
  return theVariableValues;
}


PlanIter_t FunctionItem::getImplementation(std::vector<PlanIter_t>& args) const
{
  expr* dummy = theCCB->theEM->create_function_item_expr(theSctx, theLoc);

  PlanIter_t udfCallIterator = theFunction->codegen(theCCB,
                                                    theSctx,
                                                    theLoc,
                                                    args,
                                                    *dummy);

  static_cast<UDFunctionCallIterator*>(udfCallIterator.getp())->setDynamic();

  return udfCallIterator;
}


zstring FunctionItem::show() const
{
  std::ostringstream lRes;
  if (getFunctionName() != NULL)
  {
    lRes << getFunctionName()->getStringValue() << "#" << getArity();
  }
  else
  {
    lRes << "inline function";
  }
  lRes << " (" << theLoc << ")";
  return lRes.str();
}


} //namespace zorba
/* vim:set et sw=2 ts=2: */
