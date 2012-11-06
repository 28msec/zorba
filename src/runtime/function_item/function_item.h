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
class DynamicFunctionInfo;

typedef rchandle<DynamicFunctionInfo> DynamicFunctionInfo_t;

/*******************************************************************************
  A class to hold information about a dynamic function. This info is shared
  between the DynamicFunctionIterator and the FunctionItems it creates.
********************************************************************************/
class DynamicFunctionInfo : public SimpleRCObject
{
public: // TODO: not public

  CompilerCB                  * theCCB;
  static_context              * theSctx;
  static_context_t              theScopedSctx;
  QueryLoc                      theLoc;
  function_t                    theFunction;
  store::Item_t                 theQName;
  uint32_t                      theArity;

  std::vector<expr_t>           theScopedVarsValues;
  std::vector<var_expr_t>       theSubstVarsValues;
  std::vector<store::Item_t>    theScopedVarsNames;
  std::vector<PlanIter_t>       theScopedVarsIterators;
  std::vector<int>              theIsGlobalVar;
  
  store::NsBindings             theLocalBindings; // TODO: not sure these are needed, to check

public:
  SERIALIZABLE_CLASS(DynamicFunctionInfo)
  DynamicFunctionInfo(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  DynamicFunctionInfo(const static_context_t& scoped_sctx, const QueryLoc& loc, function_t function, store::Item_t qname, uint32_t arity);
  
  virtual ~DynamicFunctionInfo();
  
  void add_variable(expr* var, var_expr* substVar, const store::Item_t& name, int isGlobal);
};


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
  DynamicFunctionInfo_t           theDynamicFunctionInfo;

  std::vector<store::Iterator_t>  theVariablesValues;
  
  std::auto_ptr<CompilerCB>       theCCB;
  
  std::auto_ptr<dynamic_context>  theDctx;

  SYNC_CODE(mutable RCLock        theRCLock;)

public:
  SERIALIZABLE_CLASS(FunctionItem)
  FunctionItem(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FunctionItem(const DynamicFunctionInfo_t& dynamicFunctionInfo,
               const std::vector<store::Iterator_t>& varsValues,
               CompilerCB* ccb,
               dynamic_context* dctx);

  FunctionItem(const DynamicFunctionInfo_t& dynamicFunctionInfo);

  virtual ~FunctionItem();
      
  dynamic_context* getDctx() const { return theDctx.get(); }

  store::Iterator_t getVariableValue(const store::Item_t& variableQName);

  const std::vector<PlanIter_t>& getVariablesIterators() const;

  const std::vector<store::Iterator_t>& getVariablesValues() const;

  store::Iterator_t getVariableValue(unsigned int i) const;

  PlanIter_t getImplementation(std::vector<PlanIter_t>& args);

  const store::Item_t getFunctionName() const;

  uint32_t getArity() const;

  const signature& getSignature() const;

  zstring show() const;
};


}//end of zorba namespace

#endif
/* vim:set et sw=2 ts=2: */
