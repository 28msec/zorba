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
#include "functions/function.h"

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
  theExpr(expr),
  theVariableValues(varValues)
{ 
}

  
FunctionItem::FunctionItem(
    CompilerCB* ccb, 
    static_context* sctx,
    function_item_expr* expr)
  :
  store::Item(store::Item::FUNCTION),
  theCCB(ccb),
  theSctx(sctx),
  theExpr(expr)
{ 
}
  

FunctionItem::~FunctionItem()
{
}

void FunctionItem::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theCCB;
  ar & theSctx;
  ar & theExpr;
  ar & theVariableValues;
}

void FunctionItem::setVariableWrappers(std::vector<store::Iterator_t>& wrappers)
{
  theVariableWrappers = wrappers;
}

const std::vector<store::Iterator_t>& FunctionItem::getVariableWrappers() const
{
  return theVariableWrappers;
}

const store::Item_t FunctionItem::getFunctionName() const 
{
  return theExpr->get_qname();
}


uint32_t FunctionItem::getArity() const 
{
  return theExpr->get_arity();
}


const signature& FunctionItem::getSignature() const
{
  return theExpr->get_function()->getSignature();
}


const std::vector<PlanIter_t>& FunctionItem::getVariables() const
{
  return theVariableValues;
}
  
 
PlanIter_t FunctionItem::getImplementation(std::vector<PlanIter_t>& args)
{ 
  PlanIter_t res = theExpr->get_function()->codegen(theCCB,
                                                    theSctx,
                                                    theExpr->get_loc(),
                                                    args,
                                                    *theExpr);

  UDFunctionCallIterator* udfIter = static_cast<UDFunctionCallIterator*>(res.getp());
  udfIter->setDynamic();
  udfIter->setFunctionItem(this);

  return res;
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
  lRes << " (" << theExpr->get_loc() << ")";
  return lRes.str();
}
  

} //namespace zorba
/* vim:set et sw=2 ts=2: */
