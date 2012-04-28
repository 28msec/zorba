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
#ifndef ZORBA_FUNCTIONS_FUNCTION_H
#define ZORBA_FUNCTIONS_FUNCTION_H

#include <vector>

#include "common/shared_types.h"

#include "functions/function_consts.h"
#include "functions/signature.h"
#include "annotations/annotations.h"

#include "compiler/parser/parse_constants.h"
#include "compiler/parser/query_loc.h"
#include "compiler/expression/expr_consts.h"

#include "context/static_context_consts.h"


namespace zorba
{


class fo_expr;
class CompilerCB;
class expr;


/*******************************************************************************
  theModuleContext:
  -----------------
  The root sctx of the module containing the declaration. It is NULL for 
  functions that must be executed in the static context of the caller.
********************************************************************************/
class function : public SimpleRCObject
{
protected:
	signature                    theSignature;
  FunctionConsts::FunctionKind theKind;
  uint32_t                     theFlags;
  AnnotationList_t             theAnnotationList;
  static_context             * theModuleSctx;

  StaticContextConsts::xquery_version_t theXQueryVersion;


public:
  SERIALIZABLE_ABSTRACT_CLASS(function);
  SERIALIZABLE_CLASS_CONSTRUCTOR3(function, SimpleRCObject, theSignature);
  void serialize(::zorba::serialization::Archiver& ar);

public:
	function(const signature& sig, FunctionConsts::FunctionKind kind);

	virtual ~function() {}

  StaticContextConsts::xquery_version_t getXQueryVersion() const
  {
    return theXQueryVersion;
  }

  void setXQueryVersion(StaticContextConsts::xquery_version_t version)
  {
    theXQueryVersion = version;
  }

  FunctionConsts::FunctionKind getKind() const { return theKind; }

	store::Item* getName() const { return theSignature.getName(); }

	void setSignature(signature& sig) { theSignature = sig; }

  const signature& getSignature() const { return theSignature; }

  signature& getSignature() { return theSignature; }

  size_t getArity() const { return theSignature.paramCount(); }

  bool isVariadic() const { return theSignature.isVariadic(); }

  static_context* getStaticContext() const { return theModuleSctx; }

  void setStaticContext(static_context* sctx) { theModuleSctx = sctx; }

  void setFlag(FunctionConsts::AnnotationFlags flag)
  {
    theFlags |= flag;
  }

  void resetFlag(FunctionConsts::AnnotationFlags flag)
  {
    theFlags &= ~flag;
  }

  bool testFlag(FunctionConsts::AnnotationFlags flag) const
  {
    return (theFlags & flag) != 0;
  }

  bool isBuiltin() const
  {
    return testFlag(FunctionConsts::isBuiltin);
  }

  bool isUdf() const
  {
    return testFlag(FunctionConsts::isUDF);
  }

  bool isExternal() const
  {
    return !isBuiltin() && !isUdf();
  }

  bool isPrivate() const
  {
    return testFlag(FunctionConsts::isPrivate);
  }

  void setPrivate(bool v)
  {
    if (v)
      setFlag(FunctionConsts::isPrivate);
    else
      resetFlag(FunctionConsts::isPrivate);
  }

  bool isDeterministic() const
  {
    // Note: For udfs, the flag is set before the udf is optimized (see call
    // to inferDeterminism in XQueryCompiler::optimize method).
    return testFlag(FunctionConsts::isDeterministic);
  }

  void setDeterministic(bool v)
  {
    if (v)
      setFlag(FunctionConsts::isDeterministic);
    else
      resetFlag(FunctionConsts::isDeterministic);
  }

  void setAnnotations(AnnotationList* annotations);

  const AnnotationList* getAnnotationList() const { return theAnnotationList.getp(); }

	bool validate_args(std::vector<PlanIter_t>& argv) const;

  bool isUpdating() const { return (getScriptingKind() & UPDATING_EXPR) != 0; }

  bool isSequential() const;

  virtual short getScriptingKind() const { return SIMPLE_EXPR; }

  virtual xqtref_t getReturnType(const fo_expr* caller) const;

  virtual bool accessesDynCtx() const { return false; }

  virtual bool isMap(ulong input) const;

  virtual bool propagatesInputNodes(expr* fo, csize input) const;

  virtual bool mustCopyInputNodes(expr* fo, csize input) const;

  virtual bool propagatesSortedNodes(csize input) const { return false; }

  virtual bool propagatesDistinctNodes(csize input) const { return false; }

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const;

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const;

  virtual BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const;

  virtual BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const;

  virtual bool isArithmeticFunction() const { return false; }

  virtual ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::UNKNOWN;
  }

  virtual bool isComparisonFunction() const { return false; }

  virtual bool isValueComparisonFunction() const { return false; }

  virtual bool isGeneralComparisonFunction() const { return false; }

  virtual CompareConsts::CompareType comparisonKind() const
  {
    return CompareConsts::UNKNOWN;
  }

  virtual bool isNodeDistinctFunction() const { return false; }

  virtual bool isSource() const { return false; }

  virtual bool specializable() const { return false; }

  virtual function* specialize(
        static_context* sctx,
        const std::vector<xqtref_t>& argTypes) const
  {
    return NULL;
  }

  virtual PlanIter_t codegen(
        CompilerCB* cb,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        expr& ann) const = 0;
};


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
