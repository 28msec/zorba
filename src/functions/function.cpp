#include "system/globalenv.h"
#include "compiler/expression/expr.h"
#include "compiler/codegen/plan_visitor.h"
#include "runtime/core/fncall_iterator.h"
#include "functions/function.h"
#include "runtime/core/var_iterators.h"
#include "util/hashmap.h"
#include "compiler/semantic_annotations/tsv_annotation.h"
#include "compiler/semantic_annotations/annotation_keys.h"

namespace zorba {


xqtref_t function::return_type (const std::vector<xqtref_t> &) const 
{
  return sig.return_type ();
}


bool function::validate_args(std::vector<PlanIter_t>& argv) const 
{
  uint32_t n = sig.arg_count ();
  return n == VARIADIC_SIG_SIZE || argv.size() == sig.arg_count();
}


void function::compute_annotation (
    AnnotationHolder *,
    std::vector<AnnotationHolder *> &kids,
    Annotation::key_t k) const 
{
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    for (unsigned src = 0; src < kids.size (); src++)
      if (kids [src] != NULL)
        TSVAnnotationValue::update_annotation (kids [src], k, TSVAnnotationValue::MAYBE_VAL);
    break;
  default: break;
  }  
}


user_function::user_function( 
  const QueryLoc& loc, 
  const signature& _sig, 
  expr_t expr_body, 
  bool aIsUpdating)
  :
  function(_sig), 
  m_loc(loc), 
  m_expr_body(expr_body), 
  theUpdateType((aIsUpdating ? UPDATE_EXPR : SIMPLE_EXPR))
{ 
}


user_function::~user_function()
{
}


const QueryLoc& user_function::get_location() const
{
  return m_loc;
}


void user_function::set_body(expr_t body)
{
  m_expr_body = body;
}


expr_t user_function::get_body() const
{
  return m_expr_body;
}


void user_function::set_params(std::vector<var_expr_t>& params)
{
  m_params = params;
}


const std::vector<var_expr_t>& user_function::get_params() const
{
  return m_params;
}


bool user_function::requires_dyn_ctx () const
{
  // All undeclared functions unfoldable. TODO: better analysis
  return (m_expr_body == NULL ||
          m_expr_body->get_annotation (AnnotationKey::UNFOLDABLE_OP) == TSVAnnotationValue::TRUE_VAL);
}


std::vector<LetVarIter_t>& user_function::get_param_iters() const
{
  return m_param_iters;
}


PlanIter_t user_function::get_plan(CompilerCB *ccb) const
{
  if (m_plan == NULL) 
  {
    std::vector<std::vector<LetVarIter_t> > param_iter_vec(m_params.size());
    hash64map<std::vector<LetVarIter_t> *> param_map;

    for(uint32_t i = 0; i < m_params.size(); ++i)
    {
      param_map.put((uint64_t)&*m_params[i], &param_iter_vec[i]);
    }

    m_plan = zorba::codegen(get_fname()->getStringValue()->c_str (),
                            &*m_expr_body,
                            ccb,
                            &param_map);

    for(uint32_t i = 0; i < param_iter_vec.size(); ++i) 
    {
      std::vector<LetVarIter_t>& vec = param_iter_vec[i];
      switch(vec.size()) {
        case 0:
          m_param_iters.push_back(NULL);
          break;

        case 1:
          m_param_iters.push_back(vec[0]);
          break;

        default:
          assert(false);
          break;
      }
    }
  }
  return m_plan;
}


PlanIter_t user_function::codegen (
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann) const
{
  return new UDFunctionCallIterator(loc, argv, this);
}

}

/* vim:set ts=2 sw=2: */
