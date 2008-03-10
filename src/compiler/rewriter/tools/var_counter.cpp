#include "compiler/expression/expr.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/abstract_expr_visitor.h"

namespace zorba {

class var_counter : public abstract_expr_visitor {
  private:
    var_expr *m_var;
    int m_counter;

  public:
    var_counter(var_expr *var) : m_var(var), m_counter(0) { }

    int get_counter() { return m_counter; }

    using abstract_expr_visitor::begin_visit;

    bool begin_visit(var_expr& v)
    {
      if (&v == m_var) {
        ++m_counter;
      }
      return true;
    }
};

int count_variable_uses(expr *root, var_expr *var)
{
  var_counter c(var);
  root->accept(c);
  return c.get_counter();
}

}

/* vim:set ts=2 sw=2: */
