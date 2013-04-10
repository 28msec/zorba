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
class FunctionItemInfo;

typedef rchandle<FunctionItemInfo> FunctionItemInfo_t;

/*******************************************************************************
  A class to hold information about a dynamic function. This info is shared
  between the FunctionItemIterator and the FunctionItems it creates.

  theCCB :
  --------

  theLoc:
  -------
  The location where the function item expr or inline function expr appear at.

  theClosureSctx:
  ---------------
  The static context to be used when the function item is actually invoked.

  theFunction:
  ------------
  The function obj that represents the implementation of this function item.
  This is always a pointer to a user_function obj. In case of an inline function
  expr, it is an anonymous user_function obj that is created on-the-fly by the
  translator to represent the body and signature of the inline function. In case
  of a function item expr where the named function is a UDF, it is the
  user_function obj of that UDF. Finally, in case of a function item expr where
  the named function F is not a UDF, it is a user_function obj UF that is created
  on-the-fly by the translator. The signature of UF is the same as that of F, and
  its body simply invokes F. The reason why UF is built is to unify the
  implemenation of dynamic function invocation.

  theQName:
  ---------

  theArity:
  ---------
  We need to store the arity also here because the function obj above doesn't
  know about its arity in case it's a variadic function.

  theIsInline:
  ------------

  theNeedsContextItem:
  --------------------
  Whether the function is a contextual one, i.e., accesses the context item, or
  context position, or context size directly.

  theIsCoercion:
  --------------
  This is set to true if the function item is a function coercion. In this
  case the newly created function item's name is taken from the coerced
  function.

  theScopedVarsValues:
  --------------------
  Empty in the case of LiteralFunctionItem. Otherwise, the vars that are in
  scope at the place where the InlineFunction expr appears at.

  theSubstVarsValues:
  -------------------

  theScopedVarsNames:
  -------------------

  theIsGlobalVar:
  ---------------

  theVarId:
  ---------

  theScopedVarsIteratosr:
  -----------------------

********************************************************************************/
class FunctionItemInfo : public SimpleRCObject
{
public:
  CompilerCB                  * theCCB;

  QueryLoc                      theLoc;
  static_context_t              theClosureSctx;
  function_t                    theFunction;
  store::Item_t                 theQName;
  unsigned int                  theArity;
  bool                          theIsInline;
  bool                          theNeedsContextItem;
  bool                          theIsCoercion;

  std::vector<expr*>            theScopedVarsValues;
  std::vector<var_expr*>        theSubstVarsValues;
  std::vector<store::Item_t>    theScopedVarsNames;
  std::vector<int>              theIsGlobalVar;
  std::vector<ulong>            theVarId;

  std::vector<PlanIter_t>       theScopedVarsIterators;

  store::NsBindings             theLocalBindings;

public:
  SERIALIZABLE_CLASS(FunctionItemInfo)
  FunctionItemInfo(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FunctionItemInfo(
      static_context* closureSctx,
      const QueryLoc& loc,
      function* func,
      store::Item_t qname,
      uint32_t arity,
      bool isInline,
      bool needsContextItem,
      bool isCoercion);

  virtual ~FunctionItemInfo();

  void add_variable(
      expr* var,
      var_expr* substVar,
      const store::Item_t& name,
      int isGlobal);
};


/*******************************************************************************
  A FunctionItem is created during codegen, when a function_item_expr is reached.

  theSctx           : The static context of the function_item_expr.
  theExpr           : The associated function_item_expr.
  theVariableValues : Vector of var iterators representing the values of the
                      in-scope FLWOR variables for inline function items.
********************************************************************************/
class FunctionItem : public store::Item, public zorba::serialization::SerializeBaseClass
{
protected:
  FunctionItemInfo_t              theFunctionItemInfo;

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
  FunctionItem(
      const FunctionItemInfo_t& dynamicFunctionInfo,
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
  
  bool isInline() const { return theFunctionItemInfo->theIsInline; }
  
  bool needsContextItem() const { return theFunctionItemInfo->theNeedsContextItem; }

  bool isCoercion() const { return theFunctionItemInfo->theIsCoercion; }

  zstring show() const;
};


}//end of zorba namespace

#endif
/* vim:set et sw=2 ts=2: */
