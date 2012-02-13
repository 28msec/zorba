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
#pragma once
#ifndef ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H
#define ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H

#include <vector>
#include <zorba/function.h>

#include "common/shared_types.h"

#include "functions/function.h"

namespace zorba 
{

/*******************************************************************************
  theLoc           : The location of the declaration of this external function.
  theNamespace     : The namespace of the module containing the declaration.
  theScriptingKind : Whether the external function is simple, updating, or
                     sequential (this property is part of the declaration).
  theImpl          : The user-provided c++ class that implements the external
                     function.
********************************************************************************/
class external_function : public function 
{
protected:
  QueryLoc           theLoc;
  zstring            theNamespace;
  short              theScriptingKind;
  ExternalFunction * theImpl;

public:
  SERIALIZABLE_CLASS(external_function)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(external_function, function)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  external_function(
      const QueryLoc& loc,
      static_context* modSctx,
      const zstring& ns,
      const signature& sig,
      short scriptingType,
      ExternalFunction* internal);

  ~external_function() { }

  short getScriptingKind() const { return theScriptingKind; }

  bool accessesDynCtx() const;

  bool propagatesInputNodes(expr* fo, csize input) const;

  bool mustCopyInputNodes(expr* fo, csize input) const;

  PlanIter_t codegen(
      CompilerCB* /*cb*/,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      AnnotationHolder& ann) const;
};


#if 0
/*******************************************************************************
  theLoc           : The location of the declaration of this external function.
  theModuleContext : The root sctx of the module containing the declaration.
********************************************************************************/
class external_builtin_function : public function 
{
protected:
  QueryLoc           theLoc;
  static_context   * theModuleSctx;
  function         * theImpl;

public:
  SERIALIZABLE_CLASS(external_builtin_function)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(external_builtin_function, function)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  external_builtin_function(
      function* impl,
      const QueryLoc& loc,
      static_context* modSctx);

  ~external_builtin_function() { }

  virtual short getScriptingKind() const 
  {
    return theImpl->();
  }

  virtual xqtref_t getReturnType(const fo_expr* caller) const
  {
    return theImpl->();
  }

  virtual bool accessesDynCtx() const 
  {
    return theImpl->();
  }

  virtual bool isMap(ulong input) const
  {
    return theImpl->();
  }

  virtual bool propagatesInputNodes(expr* fo, csize input) const
  {
    return theImpl->();
  }

  virtual bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return theImpl->();
  }

  virtual bool propagatesSortedNodes(csize input) const 
  {
    return theImpl->propagatesSortedNodes();
  }

  virtual bool propagatesDistinctNodes(csize input) const 
  {
    return theImpl->propagatesDistinctNodes();
  }

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return theImpl->producesDistinctNodes();
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return theImpl->producesSortedNodes();
  }

  virtual BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const
  {
    return theImpl->ignoresSortedNodes();
  }

  virtual BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const
  {
    return theImpl->ignoresDuplicateNodes();
  }

  virtual bool isArithmeticFunction() const 
  {
    return theImpl->isArithmeticFunction();
  }

  virtual ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return theImpl->arithmeticKind();
  }

  virtual bool isComparisonFunction() const 
  {
    return theImpl->isComparisonFunction(); 
  }

  virtual bool isValueComparisonFunction() const 
  {
    return theImpl->isValueComparisonFunction();; 
  }

  virtual bool isGeneralComparisonFunction() const 
  {
    return theImpl->isGeneralComparisonFunction(); 
  }

  virtual CompareConsts::CompareType comparisonKind() const
  {
    return theImpl->comparisonKind();
  }

  virtual bool isNodeDistinctFunction() const 
  {
    return theImpl->isNodeDistinctFunction();
  }

  virtual bool isSource() const 
  {
    return theImpl->isSource();
  }

  virtual bool specializable() const 
  {
    return theImpl->specializable();
  }

  virtual function* specialize(
        static_context* sctx,
        const std::vector<xqtref_t>& argTypes) const
  {
    return theImpl->specialize(sctx, argTypes);
  }

  PlanIter_t codegen(
      CompilerCB* /*cb*/,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      AnnotationHolder& ann) const;
};
#endif


} /* namespace zorba */
#endif  /* ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H */


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
