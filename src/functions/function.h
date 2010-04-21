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
#ifndef ZORBA_FUNCTIONS_FUNCTION_H
#define ZORBA_FUNCTIONS_FUNCTION_H

#include <vector>

#include "common/shared_types.h"

#include "functions/function_enum.h"
#include "functions/signature.h"

#include "compiler/parser/parse_constants.h"
#include "compiler/parser/query_loc.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/expression/expr_consts.h"


namespace zorba
{


class fo_expr;
class CompilerCB;
class AnnotationHolder;


/*******************************************************************************

********************************************************************************/
class function : public SimpleRCObject
{
protected:
	signature                    theSignature;
  FunctionConsts::FunctionKind theKind;
  uint32_t                     theFlags;
  bool                         theIsDeterministic;

public:
  SERIALIZABLE_ABSTRACT_CLASS(function)
  SERIALIZABLE_CLASS_CONSTRUCTOR3(function, SimpleRCObject, theSignature)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	function(const signature& sig);

	function(const signature& sig, FunctionConsts::FunctionKind kind);

	virtual ~function() {}

  FunctionConsts::FunctionKind getKind() const { return theKind; }

	const store::Item* getName() const { return theSignature.get_name(); }

	void set_signature(signature& sig) { theSignature = sig; }

  const signature& get_signature() const { return theSignature; }

  signature& get_signature() { return theSignature; }

  ulong get_arity() const { return theSignature.arg_count(); }

  bool isVariadic() const { return theSignature.is_variadic(); }

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

	virtual bool validate_args(std::vector<PlanIter_t>& argv) const;

  bool isUpdating() const { return getUpdateType() == UPDATE_EXPR; }

  bool isSequential() const { return getUpdateType() == SEQUENTIAL_EXPR; }

  virtual bool is_builtin() const { return true; }

  virtual bool is_external() const { return false; }

  virtual bool is_udf() const { return false; }

  virtual expr_script_kind_t getUpdateType() const { return SIMPLE_EXPR; }

  virtual xqtref_t getReturnType(const std::vector<xqtref_t>& argTypes) const;

  virtual function* specialize(
        static_context* sctx,
        const std::vector<xqtref_t>& argTypes) const
  {
    return NULL;
  }

  virtual bool specializable() const { return false; }

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

  virtual bool accessesDynCtx() const { return false; }

  virtual bool isSource() const { return false; }

  virtual bool isDeterministic() const { return theIsDeterministic; }

  virtual void setIsDeterministic(bool isDeterministic) { theIsDeterministic = isDeterministic; }

  virtual bool isMap(ulong input) const;

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const;

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const;

  virtual bool propagatesSortedNodes(ulong input) const { return false; }

  virtual bool propagatesDistinctNodes(ulong input) const { return false; }

  virtual void compute_annotation(
        AnnotationHolder* foExpr,
        std::vector<AnnotationHolder*>& args,
        Annotations::Key) const;

  virtual PlanIter_t codegen(
        CompilerCB* cb,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const = 0;
};




} /* namespace zorba */
#endif
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
