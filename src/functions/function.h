/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: function.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#ifndef XQP_FUNCTION_H
#define XQP_FUNCTION_H

#include <vector>
#include "common/shared_types.h"
#include "functions/signature.h"
#include "compiler/parser/query_loc.h"

namespace xqp {

typedef rchandle<class PlanIterator> PlanIter_t;
typedef rchandle<class expr> expr_t;
typedef rchandle<class var_expr> var_expr_t;
typedef rchandle<class LetVarIterator> ref_iter_t;

class fo_expr;

class function_typechecker {
    public:
        function_typechecker() {}
        virtual ~function_typechecker() {}

        virtual xqtref_t return_type(const fo_expr *fo) = 0;
        virtual xqtref_t type_check(const fo_expr *fo) = 0;
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
	const Item_t& get_fname() const { return sig.get_name(); }
	void set_signature(signature& _sig) { sig = _sig; }
    const signature& get_signature() const { return sig; }

	// codegen: functor specification
	virtual PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>& argv) const = 0;

	// polymorphic type inference
	virtual xqtref_t type_check(signature&) const = 0;

	// runtime arg validation: XXX move this out
	virtual bool validate_args(std::vector<PlanIter_t>& argv) const = 0;

};

class user_function : public function {
  public:
    user_function(const QueryLoc& loc, const signature& _sig, expr_t expr_body);
    virtual ~user_function();

    const QueryLoc& get_location() const;

    void set_body(expr_t body);
    expr_t get_body() const;

    void set_params(std::vector<var_expr_t>& params);
    const std::vector<var_expr_t>& get_params() const;

    virtual PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>& argv) const;

    virtual xqtref_t type_check(signature&) const;

    virtual bool validate_args(std::vector<PlanIter_t>& argv) const;

    virtual PlanIter_t get_plan() const;

    virtual std::vector<ref_iter_t>& get_param_iters() const;

  private:
    QueryLoc m_loc;
    expr_t m_expr_body;
    std::vector<var_expr_t> m_params;
    mutable PlanIter_t m_plan;
    mutable std::vector<ref_iter_t> m_param_iters;
    mutable int32_t m_state_size;
};

class external_function : public function {
  public:
    external_function(const signature& sig)
      : function(sig) { }
    virtual ~external_function() { }
};


} /* namespace xqp */
#endif  /* XQP_FUNCTION_H */
/* vim:set ts=2 sw=2: */
