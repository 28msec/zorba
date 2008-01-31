#include "runtime/base/iterator.h"
#include "system/zorba.h"
#include "compiler/expression/expr.h"
#include "compiler/codegen/plan_visitor.h"
#include "runtime/core/fncall_iterator.h"
#include "functions/function.h"
#include "runtime/core/var_iterators.h"
#include "util/hashmap.h"

namespace xqp {

user_function::user_function(const yy::location& loc, const signature& _sig, expr_t expr_body)
  : function(_sig), m_loc(loc), m_expr_body(expr_body) { }

user_function::~user_function() { }

const yy::location& user_function::get_location() const
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

PlanIter_t user_function::operator()(const yy::location& loc, std::vector<PlanIter_t>& argv) const
{
  return new UDFunctionCallIterator(loc, argv, this);
}

TypeSystem::xqtref_t user_function::type_check(signature& sig) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

bool user_function::validate_args(std::vector<PlanIter_t>& argv) const
{
  return argv.size() == sig.arg_count();
}

PlanIter_t user_function::get_plan() const
{
  if (m_plan == NULL) {
    std::vector<std::vector<ref_iter_t> > param_iter_vec(m_params.size());
    hash64map<std::vector<ref_iter_t> *> param_map;
    for(uint32_t i = 0; i < m_params.size(); ++i) {
      param_map.put((uint64_t)&*m_params[i], &param_iter_vec[i]);
    }
    m_plan = codegen(&*m_expr_body, &param_map);
    for(uint32_t i = 0; i < param_iter_vec.size(); ++i) {
      std::vector<ref_iter_t>& vec = param_iter_vec[i];
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
    m_state_size = m_plan->getStateSizeOfSubtree();
  }
  return m_plan;
}

std::vector<ref_iter_t>& user_function::get_param_iters() const
{
  return m_param_iters;
}

PlanState *user_function::create_plan_state() const
{
  PlanState *state = new PlanState(m_state_size);
  uint32_t offset = 0;
  m_plan->open(*state, offset);

  return state;
}

}

/* vim:set ts=2 sw=2: */
