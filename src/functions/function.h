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
#ifndef ZORBA_FUNCTION_H
#define ZORBA_FUNCTION_H

#include <vector>
#include "common/shared_types.h"
#include "functions/signature.h"
#include "compiler/parser/query_loc.h"
#include "compiler/semantic_annotations/annotation_holder.h"
#include "compiler/expression/expr_consts.h"
#include "compiler/api/compilercb.h"

#include "runtime/booleans/compare_types.h"

namespace zorba {


class fo_expr;

typedef rchandle<var_expr> var_expr_t;

#define ZORBA_PRESERVES_SORTED \
  function::AnnotationProperty_t producesNodeIdSorted() const { return PRESERVE; }

#define ZORBA_PRESERVES_DISTINCT \
  function::AnnotationProperty_t producesDuplicates() const { return PRESERVE; }

#define ZORBA_NOT_PRODUCES_SORTED \
  function::AnnotationProperty_t producesNodeIdSorted() const { return NO; }

#define ZORBA_NOT_PRODUCES_DISTINCT \
  function::AnnotationProperty_t producesDuplicates() const { return NO; }

#define ZORBA_PRODUCES_SORTED \
  function::AnnotationProperty_t producesNodeIdSorted() const { return YES; }

#define ZORBA_PRODUCES_DISTINCT \
  function::AnnotationProperty_t producesDuplicates() const { return YES; }

#define ZORBA_NOT_PROPAGATES_I2O \
  bool propagatesInputToOutput(uint32_t aProducer) const { return false; }
#define ZORBA_PROPAGATES_I2O \
  bool propagatesInputToOutput(uint32_t aProducer) const { return true; }
#define ZORBA_PROPAGATES_ONE_I2O( n ) \
  bool propagatesInputToOutput(uint32_t aProducer) const { return n == aProducer; }

class function_typechecker {
public:
  function_typechecker() {}
  virtual ~function_typechecker() {}
  
  virtual xqtref_t return_type(const fo_expr *fo) = 0;
};

class function_codegenerator {
public:
  function_codegenerator() {}
  virtual ~function_codegenerator() {}
  virtual PlanIter_t codegen(const fo_expr *fo) = 0;
};


class function : public SimpleRCObject {
public:
  typedef enum {
    NO = 0,
    YES,
    PRESERVE
  } AnnotationProperty_t;

protected:
	signature sig;

public:
	function(const signature& _sig) : sig(_sig) {}
	virtual ~function() {}

public:
	// XQuery signature (name+arity)
	const store::Item_t& get_fname() const { return sig.get_name(); }
	void set_signature(signature& _sig) { sig = _sig; }
  const signature& get_signature() const { return sig; }
  int  get_arity() const { return sig.arg_count(); }

	// codegen: functor specification
	virtual PlanIter_t codegen (short sctx,
                              const QueryLoc& loc,
                              std::vector<PlanIter_t>& argv,
                              AnnotationHolder &ann) const = 0;

  virtual bool requires_dyn_ctx () const { return false; }

  virtual xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;

  virtual void compute_annotation (AnnotationHolder *, std::vector<AnnotationHolder *> &, Annotation::key_t) const;

	// runtime arg validation
	virtual bool validate_args(std::vector<PlanIter_t>& argv) const;

  // Annotation calculator functions
  virtual bool isSource() const { return false; }

  virtual bool isPureFunction() const { return true; }

  virtual expr_update_t getUpdateType () const { return SIMPLE_EXPR; }
  bool isUpdating () const { return getUpdateType () == UPDATE_EXPR; }

  virtual AnnotationProperty_t producesDuplicates() const;
  virtual AnnotationProperty_t producesNodeIdSorted() const;
  virtual bool propagatesInputToOutput(uint32_t aProducer) const { return true; }

  virtual const function *specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const { return NULL; }

  virtual bool specializable() const { return false; }

  virtual bool isArithmeticFunction() const { return false; }
  virtual bool isComparisonFunction() const { return false; }
  virtual bool isValueComparisonFunction() const { return false; }
  virtual bool isGeneralComparisonFunction() const { return false; }

  virtual CompareConsts::CompareType comparison_kind() const 
  {
    return CompareConsts::UNKNOWN;
  }
};


class user_function : public function {
public:
  user_function(const QueryLoc& loc,
                const signature& _sig,
                expr_t expr_body, 
                ParseConstants::function_type_t,
                bool deterministic_);

  virtual ~user_function();

  const QueryLoc& get_location() const;

  virtual expr_update_t getUpdateType() const { return theUpdateType; }

  void set_body(expr_t body);
  expr_t get_body() const;

  void set_params(std::vector<var_expr_t>& params);
  const std::vector<var_expr_t>& get_params() const;

  virtual PlanIter_t codegen(short sctx,
                             const QueryLoc& loc,
                             std::vector<PlanIter_t>& argv,
                             AnnotationHolder &ann) const;

  virtual PlanIter_t get_plan(CompilerCB *) const;

  virtual std::vector<LetVarIter_t>& get_param_iters() const;

  bool requires_dyn_ctx () const;
  bool isPureFunction () const;
  bool isSequential () const { return sequential; }

  void setLeaf (bool leaf_) { leaf = leaf_; }
  bool isLeaf() const { return leaf; }

private:
  QueryLoc                m_loc;
  expr_t                  m_expr_body;
  std::vector<var_expr_t> m_params;

  expr_update_t           theUpdateType;
  bool sequential;

  bool deterministic;
  bool leaf;  // does not call other UDF's
  
  mutable PlanIter_t                m_plan;
  mutable std::vector<LetVarIter_t> m_param_iters;
  mutable int32_t                   m_state_size;
};


class external_function : public function 
{
  public:
    external_function(const signature& sig)
      : function(sig) { }
    virtual ~external_function() { }
};


} /* namespace zorba */
#endif  /* ZORBA_FUNCTION_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
