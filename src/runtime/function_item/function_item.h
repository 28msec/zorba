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
#ifndef ZORBA_RUNTIME_FUNCTION_ITEM_H
#define ZORBA_RUNTIME_FUNCTION_ITEM_H

#include "common/shared_types.h"

#include "store/api/item.h"


namespace zorba
{

class signature;
class function_item_expr;


/*******************************************************************************
  theVariableValues : (in-scope) variable values for inline function items
********************************************************************************/
class FunctionItem : public store::Item, public zorba::serialization::SerializeBaseClass
{
protected:
  CompilerCB                   * theCCB;

  static_context               * theSctx;

  rchandle<function_item_expr>   theExpr;

  std::vector<PlanIter_t>        theVariableValues;

  SYNC_CODE(mutable RCLock       theRCLock;)

public:
  SERIALIZABLE_CLASS(FunctionItem)
  FunctionItem(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FunctionItem(
      CompilerCB* ccb, 
      static_context* sctx,
      function_item_expr* expr,
      const std::vector<PlanIter_t>& varValues);
    
  FunctionItem(
      CompilerCB* ccb, 
      static_context* sctx,
      function_item_expr* expr);

  ~FunctionItem();

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  const store::Item_t getFunctionName() const;

  uint32_t getArity() const;

  const signature& getSignature() const;

  const std::vector<PlanIter_t>& getVariables() const;

  PlanIter_t getImplementation(std::vector<PlanIter_t>& args) const;

  zstring show() const;
};


}//end of zorba namespace

#endif
