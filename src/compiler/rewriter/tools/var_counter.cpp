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
#include "compiler/expression/expr.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/abstract_expr_visitor.h"

namespace zorba {

class var_counter : public abstract_expr_visitor {
private:
  var_expr *m_var;
  int m_counter;
  int m_limit;
  
public:
  var_counter(var_expr *var, int limit) : m_var(var), m_counter(0), m_limit (0) { }
  
  int get_counter() { return m_counter; }
  
  using abstract_expr_visitor::begin_visit;
  
  bool begin_visit(var_expr& v)
  {
    if (m_limit > 0 && m_counter >= m_limit) return false;
    if (&v == m_var) {
      ++m_counter;
    }
    return true;
  }
};
  
int count_variable_uses(expr *root, var_expr *var, int limit = 0)
{
  var_counter c(var, limit);
  root->accept(c);
  return c.get_counter();
}

}

/* vim:set ts=2 sw=2: */
