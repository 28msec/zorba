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

// This include needs to be kept in order to make sure the
// auto_ptr<dynamic_context> manages to dealocate the
// dynamic_context object.
#include "context/dynamic_context.h"

#include "runtime/hof/function_item.h"
#include "runtime/core/fncall_iterator.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/expr_manager.h"

#include "functions/signature.h"
#include "functions/udf.h"

#include "store/api/temp_seq.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(FunctionItemInfo)

SERIALIZABLE_CLASS_VERSIONS(FunctionItem)


/*******************************************************************************

********************************************************************************/
FunctionItemInfo::FunctionItemInfo(
    static_context* closureSctx,
    const QueryLoc& loc,
    function* func,
    store::Item_t qname,
    uint32_t arity,
    bool isInline,
    bool needsContextItem,
    bool isCoercion)
  :
  theLoc(loc),
  theClosureSctx(closureSctx),
  theFunction(func),
  theQName(qname),
  theArity(arity),
  theIsInline(isInline),
  theNeedsContextItem(needsContextItem),
  theIsCoercion(isCoercion)
{
}


FunctionItemInfo::FunctionItemInfo(::zorba::serialization::Archiver& ar)
{
}


FunctionItemInfo::~FunctionItemInfo()
{
}


void FunctionItemInfo::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theCCB;
  ar & theClosureSctx;
  ar & theLoc;
  ar & theFunction;
  ar & theQName;
  ar & theArity;
  ar & theIsInline;
  ar & theNeedsContextItem;
  ar & theIsCoercion;

  // These are not serialized
  // ar & theScopedVarsValues;
  // ar & theSubstVarsValues;

  ar & theScopedVarsNames;
  ar & theIsGlobalVar;
  ar & theVarId;

  ar & theScopedVarsIterators;

  if (ar.is_serializing_out())
  {
    uint32_t planStateSize;
    (void)static_cast<user_function*>(theFunction.getp())->getPlan(planStateSize);
  }
}


void FunctionItemInfo::add_variable(
    expr* var,
    var_expr* substVar,
    const store::Item_t& name,
    int isGlobal)
{
  theScopedVarsValues.push_back(var);
  theSubstVarsValues.push_back(substVar);
  theScopedVarsNames.push_back(name);
  theIsGlobalVar.push_back(isGlobal);
  theVarId.push_back(substVar->get_unique_id());
}


/*******************************************************************************

********************************************************************************/
FunctionItem::FunctionItem(::zorba::serialization::Archiver& ar)
  :
  store::Item(store::Item::FUNCTION)
{
}


FunctionItem::FunctionItem(
    const FunctionItemInfo_t& dynamicFunctionInfo,
    dynamic_context* dctx)
  :
  store::Item(store::Item::FUNCTION),
  theFunctionItemInfo(dynamicFunctionInfo),
  theArity(dynamicFunctionInfo->theArity),
  theClosureDctx(dctx)
{
  assert(theFunctionItemInfo->theFunction->isUdf());
  theArgumentsValues.resize(theFunctionItemInfo->theArity);
}


void FunctionItem::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theFunctionItemInfo;
  ar & theArity;
  ar & theArgumentsValues;
}


const store::Item_t FunctionItem::getFunctionName() const
{
  return theFunctionItemInfo->theQName;
}


uint32_t FunctionItem::getArity() const
{
  return theArity;
}


uint32_t FunctionItem::getStartArity() const
{
  return theFunctionItemInfo->theArity;
}


const signature& FunctionItem::getSignature() const
{
  return theFunctionItemInfo->theFunction->getSignature();
}


const std::vector<PlanIter_t>& FunctionItem::getArgumentsValues() const
{
  return theArgumentsValues;
}


bool FunctionItem::isArgumentApplied(unsigned int pos) const
{
  assert(pos < theArgumentsValues.size());
  return (theArgumentsValues[pos].getp() != NULL);
}


void FunctionItem::setArgumentValue(unsigned int pos, const PlanIter_t& value)
{
  theArity--;

  // find the pos-th NULL value and fill it
  for (unsigned int i=0; i<theArgumentsValues.size(); i++)
    if (theArgumentsValues[i] == NULL)
    {
      if (pos == 0)
      {
        theArgumentsValues[i] = value;
        return;
      }
      else
        pos--;
    }

  assert(false);
}


PlanIter_t FunctionItem::getImplementation(
    const std::vector<PlanIter_t>& dynChildren,
    CompilerCB* ccb)
{
  std::vector<PlanIter_t> args;
  args.resize(theArgumentsValues.size());

  std::vector<PlanIter_t>::iterator argsIte = args.begin();
  std::vector<PlanIter_t>::iterator ite = theArgumentsValues.begin();
  std::vector<PlanIter_t>::const_iterator ite2 = dynChildren.begin();
  ++ite2; // skip the first child because it's the function item

  for( ; argsIte != args.end(); ++argsIte, ++ite)
  {
    if (*ite != NULL)
    {
      *argsIte = *ite;
      static_cast<PlanStateIteratorWrapper*>(ite->getp())->reset();
    }
    else
    {
      *argsIte = *ite2;
      ++ite2;
    }
  }

  expr* dummy = ccb->theEM->
  create_function_item_expr(NULL,
                            NULL,
                            theFunctionItemInfo->theLoc,
                            false,
                            false,
                            false);
  
  PlanIter_t udfCallIterator = theFunctionItemInfo->theFunction->
  codegen(ccb,
          theFunctionItemInfo->theClosureSctx,
          theFunctionItemInfo->theLoc,
          args,
          *dummy);

  UDFunctionCallIterator* udfIter =
  static_cast<UDFunctionCallIterator*>(udfCallIterator.getp());

  udfIter->setDynamic();
  udfIter->setFunctionItem(this);
  return udfCallIterator;
}


zstring FunctionItem::show() const
{
  std::ostringstream lRes;
  lRes << getFunctionName()->getStringValue();
  if (!isInline())
    lRes << "#" << getArity() << " (" << theFunctionItemInfo->theLoc << ")";
  return lRes.str();
}


} //namespace zorba
/* vim:set et sw=2 ts=2: */
