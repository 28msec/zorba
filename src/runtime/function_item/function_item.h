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

#include "compiler/parser/query_loc.h"

#include "store/api/item.h"


namespace zorba
{

class signature;
class function_item_expr;


/*******************************************************************************
  A FunctionItem is created during codegen, when a function_item_expr is reached.

  theCCB            :
  theSctx           : The static context of the function_item_expr.
  theExpr           : The associated function_item_expr.
  theVariableValues : Vector of var iterators representing the values of the
                      in-scope FLWOR variables for inline function items.
********************************************************************************/
class FunctionItem : public store::Item, public zorba::serialization::SerializeBaseClass
{
protected:
  CompilerCB                   * theCCB;

  static_context               * theSctx;

  std::auto_ptr<dynamic_context> theDctx;

  QueryLoc                       theLoc;
  store::Item_t                  theQName;
	function_t                     theFunction;
  uint32_t                       theArity;

  std::vector<PlanIter_t>        theVariableValues;

  std::vector<store::Iterator_t> theVariableWrappers; // TODO: move somewhere else? dctx maybe?

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

  void setVariableWrappers(std::vector<store::Iterator_t>& wrappers);

  const std::vector<store::Iterator_t>& getVariableWrappers() const;

  const store::Item_t getFunctionName() const;

  uint32_t getArity() const;

  const signature& getSignature() const;

  const std::vector<PlanIter_t>& getVariables() const;

  PlanIter_t getImplementation(std::vector<PlanIter_t>& args);

  zstring show() const;
};


}//end of zorba namespace

#endif
/* vim:set et sw=2 ts=2: */
