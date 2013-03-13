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

#include "runtime/base/narybase.h"


namespace zorba
{

class signature;
class function_item_expr;
class DynamicFunctionInfo;

typedef rchandle<DynamicFunctionInfo> DynamicFunctionInfo_t;

/*******************************************************************************
  A class to hold information about a dynamic function. This info is shared
  between the DynamicFunctionIterator and the FunctionItems it creates.

  theCCB :
  --------

  theMustDeleteCCB :
  ------------------
  This is set to true if the DynamicFunctionInfo is the owner of the CCB,
  and must delete it upon destruction.  
********************************************************************************/
class DynamicFunctionInfo : public SimpleRCObject
{
public:
  CompilerCB                  * theCCB;
  bool                          theMustDeleteCCB;

  static_context              * theClosureSctx;
  QueryLoc                      theLoc;
  function_t                    theFunction;
  store::Item_t                 theQName;
  unsigned int                  theArity;
  bool                          theIsInline;
  bool                          theNeedsContextItem;

  std::vector<expr*>            theScopedVarsValues;
  std::vector<var_expr*>        theSubstVarsValues;
  std::vector<store::Item_t>    theScopedVarsNames;
  std::vector<int>              theIsGlobalVar;
  std::vector<ulong>            theVarId;

  std::vector<PlanIter_t>       theScopedVarsIterators;

  store::NsBindings             theLocalBindings;

public:
  SERIALIZABLE_CLASS(DynamicFunctionInfo)
  DynamicFunctionInfo(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  DynamicFunctionInfo(
      static_context* closureSctx,
      const QueryLoc& loc,
      function* func,
      store::Item_t qname,
      uint32_t arity,
      bool isInline,
      bool needsContextItem);

  virtual ~DynamicFunctionInfo();

  void add_variable(
      expr* var,
      var_expr* substVar,
      const store::Item_t& name,
      int isGlobal);
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

  unsigned int                    theArity;   // The arity of the function
                                              // item will decrease when a
                                              // partial application is used.

  std::vector<PlanIter_t>         theArgumentsValues;

  std::auto_ptr<dynamic_context>  theClosureDctx;

  SYNC_CODE(mutable RCLock        theRCLock;)

public:
  SERIALIZABLE_CLASS(FunctionItem)
  FunctionItem(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FunctionItem(const DynamicFunctionInfo_t& dynamicFunctionInfo,
               dynamic_context* dctx);

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  dynamic_context* getDctx() const { return theClosureDctx.get(); }

  void setDctx(dynamic_context* dctx) { theClosureDctx.reset(dctx); }

  const std::vector<PlanIter_t>& getArgumentsValues() const;

  void setArgumentValue(unsigned int pos, const PlanIter_t& value);

  // This function will return true if the pos-th argument of the function
  // has been partially applied, i.e. theArgumentsValues[pos] is not NULL
  bool isArgumentApplied(unsigned int pos) const;

  // The getImplementation function assumes the dynChildren vector comes from a
  // DynamicFnCallIterator, and as such, the first element of dynChildren is
  // the function item itself, so it will be skipped.
  // The last element(s) of dynChildren might contain DOT vars iterators. They
  // will be picked up automatically if needed.
  PlanIter_t getImplementation(const std::vector<PlanIter_t>& dynChildren, CompilerCB* ccb);

  const store::Item_t getFunctionName() const;

  unsigned int getArity() const;
  
  // returns the arity of the function before any partial application
  unsigned int getStartArity() const;

  const signature& getSignature() const;
  
  bool isInline() const { return theDynamicFunctionInfo->theIsInline; }
  
  bool needsContextItem() const { return theDynamicFunctionInfo->theNeedsContextItem; }

  zstring show() const;
};


/*******************************************************************************
  An iterator that creates and returns dynamic function items
********************************************************************************/
class DynamicFunctionIterator : public NaryBaseIterator<DynamicFunctionIterator, PlanIteratorState>
{
protected:
  DynamicFunctionInfo_t theDynamicFunctionInfo;

public:
  SERIALIZABLE_CLASS(DynamicFunctionIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DynamicFunctionIterator,
  NaryBaseIterator<DynamicFunctionIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  DynamicFunctionIterator(
      static_context* sctx,
      const QueryLoc& loc,
      DynamicFunctionInfo* fnInfo);

  virtual ~DynamicFunctionIterator();

  // Used for pretty-printing of the iterator tree
  const DynamicFunctionInfo_t getDynamicFunctionInfo() const
  {
    return theDynamicFunctionInfo;
  }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

public:
  void importOuterEnv(PlanState& planState,
      CompilerCB* evalCCB,
      static_context* importSctx,
      dynamic_context* evalDctx) const;

private:
  void setExternalVariables(
      CompilerCB* ccb,
      static_context* importSctx,
      dynamic_context* evalDctx) const;
};


}//end of zorba namespace

#endif
/* vim:set et sw=2 ts=2: */
