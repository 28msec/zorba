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
// unique_ptr<dynamic_context> manages to dealocate the
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


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  FunctionItem                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
FunctionItemInfo::FunctionItemInfo(
    static_context* closureSctx,
    const QueryLoc& loc,
    function* func,
    const store::Item_t& qname,
    csize arity,
    bool isInline,
    bool isCoercion)
  :
  theLoc(loc),
  theClosureSctx(closureSctx),
  theFunction(func),
  theQName(qname),
  theArity(arity),
  theIsInline(isInline),
  theIsCoercion(isCoercion)
{
#if 0
  std::cerr << std::endl;

  if (theFunction && theFunction->getName() != NULL)
    std::cerr << "Allocated FunctionItemInfo " << this << " for function: "
              << theFunction->getName()->getStringValue()
              << std::endl;
  else if (theQName != NULL)
    std::cerr << "Allocated FunctionItemInfo " << this << " for function: "
              << theQName->getStringValue()
              << std::endl;
  else
    std::cerr << "Allocated FunctionItemInfo " << this
              << " for anonymous function at loc: " << loc << std::endl;

  std::cerr << std::endl;
#endif
}


FunctionItemInfo::FunctionItemInfo(::zorba::serialization::Archiver& ar)
{
}


FunctionItemInfo::~FunctionItemInfo()
{
#if 0
  std::cerr << std::endl;

  if (theFunction->getName() != NULL)
    std::cerr << "DeAllocated FunctionItemInfo " << this << " for function: "
              << theFunction->getName()->getStringValue()
              << std::endl;
  else
    std::cerr << "DeAllocated FunctionItemInfo " << this << " for anonymous function"
              << std::endl;

  std::cerr << std::endl;
#endif
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
  ar & theIsCoercion;

  // These are not serialized
  // ar & theScopedVarsValues;
  // ar & theSubstVarsValues;

  ar & theInScopeVarNames;
  ar & theInScopeVarIds;

  ar & theInScopeVarIterators;

  if (ar.is_serializing_out())
  {
    uint32_t planStateSize;
    (void)static_cast<user_function*>(theFunction)->getPlan(planStateSize, 1);
  }
}


/*******************************************************************************

********************************************************************************/
void FunctionItemInfo::add_variable(expr* var, var_expr* substVar)
{
  theInScopeVarValues.push_back(var);
  theInScopeVars.push_back(substVar);
  theInScopeVarNames.push_back(substVar->get_name());
  theInScopeVarIds.push_back(substVar->get_unique_id());
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  FunctionItem                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


FunctionItem::FunctionItem(const FunctionItem& aFunctionItem)
  :
  store::Item(store::Item::FUNCTION),
  theFunctionItemInfo(aFunctionItem.theFunctionItemInfo),
  theArity(aFunctionItem.theArity),
  theClosureDctx(aFunctionItem.getDctx()),
  theClosureDctxOwned(false)
{
  theArgValues.insert(theArgValues.begin(), aFunctionItem.theArgValues.begin(), aFunctionItem.theArgValues.end());
}

/*******************************************************************************

********************************************************************************/
FunctionItem::FunctionItem(const FunctionItemInfo_t& fiInfo, dynamic_context* dctx)
  :
  store::Item(store::Item::FUNCTION),
  theFunctionItemInfo(fiInfo),
  theArity(fiInfo->theArity),
  theClosureDctx(dctx),
  theClosureDctxOwned(true)
{
  assert(theFunctionItemInfo->theFunction->isUdf());
  theArgValues.resize(theArity);

#if 0
  if (theFunctionItemInfo->theFunction->getName() != NULL)
    std::cerr << "Allocated FunctionItem " << this << " for function: "
              << theFunctionItemInfo->theFunction->getName()->getStringValue()
              << std::endl;
  else
    std::cerr << "Allocated FunctionItem " << this << " for anonymous function"
              << std::endl;
#endif
}


/*******************************************************************************

********************************************************************************/
FunctionItem::FunctionItem(::zorba::serialization::Archiver& ar)
  :
  store::Item(store::Item::FUNCTION),
  theClosureDctx(NULL),
  theClosureDctxOwned(false)
{
}


/*******************************************************************************

********************************************************************************/
FunctionItem::~FunctionItem()
{
#if 0
  if (theFunctionItemInfo->theFunction->getName() != NULL)
    std::cerr << "DeAllocated FunctionItem " << this << " for function: "
              << theFunctionItemInfo->theFunction->getName()->getStringValue()
              << std::endl;
  else
    std::cerr << "DeAllocated FunctionItem " << this << " for anonymous function"
              << std::endl;
#endif
  if (theClosureDctxOwned)
    delete theClosureDctx;
}


/*******************************************************************************

********************************************************************************/
void FunctionItem::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theFunctionItemInfo;
  ar & theArity;
  ar & theArgValues;
}


/*******************************************************************************

********************************************************************************/
const store::Item_t FunctionItem::getFunctionName() const
{
  return theFunctionItemInfo->theQName;
}


/*******************************************************************************
  Returns the arity of the function before any partial application
********************************************************************************/
csize FunctionItem::getStartArity() const
{
  return theFunctionItemInfo->theArity;
}


/*******************************************************************************

********************************************************************************/
const signature& FunctionItem::getSignature() const
{
  return theFunctionItemInfo->theFunction->getSignature();
}


/*******************************************************************************
  This function will return true if the pos-th argument of the function
  has been partially applied, i.e. theArgumentsValues[pos] is not NULL
********************************************************************************/
bool FunctionItem::isArgumentApplied(csize pos) const
{
  assert(pos < theArgValues.size());
  return (theArgValues[pos].getp() != NULL);
}


/*******************************************************************************

********************************************************************************/
void FunctionItem::setArgumentValue(csize pos, const PlanIter_t& value)
{
  theArity--;

  // find the pos-th NULL value and fill it
  for (csize i = 0; i < theArgValues.size(); ++i)
  {
    if (theArgValues[i] == NULL)
    {
      if (pos == 0)
      {
        theArgValues[i] = value;
        return;
      }
      else
      {
        pos--;
      }
    }
  }

  assert(false);
}


/*******************************************************************************

********************************************************************************/
ulong FunctionItem::getMaxInScopeVarId() const
{
  return theFunctionItemInfo->
         theInScopeVarIds[theFunctionItemInfo->theInScopeVarIds.size()-1];
}


/*******************************************************************************
  The getImplementation function assumes the dynChildren vector comes from a
  DynamicFnCallIterator, and as such, the first element of dynChildren is
  the function item itself, so it will be skipped.
********************************************************************************/
PlanIter_t FunctionItem::getImplementation(
    const std::vector<PlanIter_t>& dynChildren,
    CompilerCB* ccb)
{
  std::vector<PlanIter_t> args;
  args.resize(theArgValues.size());

  std::vector<PlanIter_t>::iterator argsIte = args.begin();
  std::vector<PlanIter_t>::iterator ite = theArgValues.begin();
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


/*******************************************************************************

********************************************************************************/
PlanIter_t FunctionItem::getImplementation(CompilerCB* ccb)
{
  std::vector<PlanIter_t> args;

  expr* dummy = ccb->theEM->
  create_function_item_expr(NULL,
                            NULL,
                            theFunctionItemInfo->theLoc,
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


/*******************************************************************************

********************************************************************************/
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
