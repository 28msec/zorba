#ifndef ZORBA_FUNCTION_H
#define ZORBA_FUNCTION_H

#include <vector>
#include "common/shared_types.h"
#include "functions/signature.h"
#include "compiler/parser/query_loc.h"
#include "compiler/semantic_annotations/annotation_holder.h"
#include "compiler/expression/expr_consts.h"
#include "compiler/api/compilercb.h"

namespace zorba {


class fo_expr;

typedef rchandle<var_expr> var_expr_t;


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


class function
{
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

	// codegen: functor specification
	virtual PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const = 0;

  virtual bool requires_dyn_ctx () const { return false; }

  virtual xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;

  virtual void compute_annotation (AnnotationHolder *, std::vector<AnnotationHolder *> &, Annotation::key_t) const;

	// runtime arg validation
	virtual bool validate_args(std::vector<PlanIter_t>& argv) const;

  // Annotation calculator functions
  virtual bool isSource() const { return false; }

  virtual expr_update_t getUpdateType() const { return SIMPLE_EXPR; }
  bool isUpdating() const { return getUpdateType() == UPDATE_EXPR; }
};


class user_function : public function 
{
public:
  user_function(
        const QueryLoc& loc,
        const signature& _sig,
        expr_t expr_body, 
        bool aIsUpdating);

  virtual ~user_function();

  const QueryLoc& get_location() const;

  virtual expr_update_t getUpdateType() const { return theUpdateType; }

  void set_body(expr_t body);
  expr_t get_body() const;

  void set_params(std::vector<var_expr_t>& params);
  const std::vector<var_expr_t>& get_params() const;

  virtual PlanIter_t codegen(
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder &ann) const;

  virtual PlanIter_t get_plan(CompilerCB *) const;

  virtual std::vector<LetVarIter_t>& get_param_iters() const;

  bool requires_dyn_ctx () const;

 private:
    QueryLoc                m_loc;
    expr_t                  m_expr_body;
    std::vector<var_expr_t> m_params;

    expr_update_t           theUpdateType;

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
