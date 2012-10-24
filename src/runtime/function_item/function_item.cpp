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
#include "compiler/expression/var_expr.h"
#include "compiler/expression/function_item_expr.h"

#include "functions/signature.h"
#include "functions/udf.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(DynamicFunctionInfo)

SERIALIZABLE_CLASS_VERSIONS(FunctionItem)


/*******************************************************************************

********************************************************************************/
DynamicFunctionInfo::DynamicFunctionInfo(const static_context_t& scopedSctx,
                                         const QueryLoc& loc,
                                         function_t function, 
                                         store::Item_t qname, 
                                         uint32_t arity)
  :
  theCCB(NULL),
  theSctx(NULL),
  theScopedSctx(scopedSctx),          
  theLoc(loc),
  theFunction(function),
  theQName(qname),
  theArity(arity)
{
}    


DynamicFunctionInfo::~DynamicFunctionInfo()
{
}


DynamicFunctionInfo::DynamicFunctionInfo(::zorba::serialization::Archiver& ar)
{
}


void DynamicFunctionInfo::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theCCB;
  ar & theSctx;
  ar & theScopedSctx;
  // ar & theLoc; TODO
  ar & theQName;
  ar & theArity;
  ar & theFunction;
  ar & theScopedVarsNames;
  ar & theScopedVarsIterators;

  if (ar.is_serializing_out())
  {
    uint32_t planStateSize;
    (void)static_cast<user_function*>(theFunction.getp())->
      getPlan(theCCB, planStateSize);
  }
}


void DynamicFunctionInfo::add_variable(expr* var, var_expr* substVar, const store::Item_t& name, int isGlobal)
{
  theScopedVarsValues.push_back(var);
  theSubstVarsValues.push_back(substVar);
  theScopedVarsNames.push_back(name);
  theIsGlobalVar.push_back(isGlobal);
}

/*******************************************************************************

********************************************************************************/
FunctionItem::FunctionItem(::zorba::serialization::Archiver& ar)
  :
  store::Item(store::Item::FUNCTION)
{
}


FunctionItem::FunctionItem(const DynamicFunctionInfo_t& dynamicFunctionInfo,
                           const std::vector<store::Iterator_t>& varsValues,
                           CompilerCB* ccb,
                           dynamic_context* dctx)
  :
  store::Item(store::Item::FUNCTION),
  theDynamicFunctionInfo(dynamicFunctionInfo),
  theVariablesValues(varsValues),
  theCCB(ccb),
  theDctx(dctx)
{
  assert(theDynamicFunctionInfo->theFunction->isUdf());
}


FunctionItem::FunctionItem(const DynamicFunctionInfo_t& dynamicFunctionInfo)
  :
  store::Item(store::Item::FUNCTION),
  theDynamicFunctionInfo(dynamicFunctionInfo)
{
  assert(theDynamicFunctionInfo->theFunction->isUdf());
}


FunctionItem::~FunctionItem()
{
}


void FunctionItem::serialize(::zorba::serialization::Archiver& ar)
{
  // ar & theDynamicFunctionInfo;
  ar & theVariablesValues;
}


const store::Item_t FunctionItem::getFunctionName() const
{
  return theDynamicFunctionInfo->theQName;
}


uint32_t FunctionItem::getArity() const
{
  return theDynamicFunctionInfo->theArity;
}


const signature& FunctionItem::getSignature() const
{
  return theDynamicFunctionInfo->theFunction->getSignature();
}


const std::vector<PlanIter_t>& FunctionItem::getVariablesIterators() const
{
  return theDynamicFunctionInfo->theScopedVarsIterators;
}


const std::vector<store::Iterator_t>& FunctionItem::getVariablesValues() const
{
  return theVariablesValues;
}


store::Iterator_t FunctionItem::getVariableValue(unsigned int i) const
{
  if (i < theVariablesValues.size())
    return theVariablesValues[i];
  else
    return NULL;
}


store::Iterator_t FunctionItem::getVariableValue(const store::Item_t& variableQName)
{
  for (csize i=0; i<theDynamicFunctionInfo->theScopedVarsNames.size(); i++)
    if (theDynamicFunctionInfo->theScopedVarsNames[i].getp() != NULL)
      if (theDynamicFunctionInfo->theScopedVarsNames[i]->equals(variableQName))
        return theVariablesValues[i];

  return NULL;
}


PlanIter_t FunctionItem::getImplementation(std::vector<PlanIter_t>& args)
{
  expr_t dummy = new function_item_expr(NULL, NULL, theDynamicFunctionInfo->theLoc);

  /*
  PlanIter_t udfCallIterator = 
      theDynamicFunctionInfo->theFunction->codegen(theDynamicFunctionInfo->theCCB,
                                                   theDynamicFunctionInfo->theSctx,
                                                   theDynamicFunctionInfo->theLoc,
                                                   args,
                                                   *dummy.getp());
  */
  PlanIter_t udfCallIterator = 
      theDynamicFunctionInfo->theFunction->codegen(theCCB.get(),
                                                   theCCB->theRootSctx,
                                                   theDynamicFunctionInfo->theLoc,
                                                   args,
                                                   *dummy.getp());
  
  UDFunctionCallIterator* udfIter = static_cast<UDFunctionCallIterator*>(udfCallIterator.getp());
  udfIter->setDynamic();
  udfIter->setFunctionItem(this);

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
  lRes << " (" << theDynamicFunctionInfo->theLoc << ")";
  return lRes.str();

  return "";
}


} //namespace zorba
/* vim:set et sw=2 ts=2: */
