/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#include "expr_manager.h"

namespace zorba {

ExprManager::ExprManager(){}

//calls on the destructors and also keeps tracks of certain numbers
ExprManager::~ExprManager()
{
  unsigned long total_expr = theExprs.size();
  unsigned long zero_ref_expr = 0;

  unsigned long total_bytes = 0;
  unsigned long zero_ref_bytes = 0;

  for(std::list<expr*>::iterator iter = theExprs.begin();
      iter != theExprs.end();
      iter++)
  {
    expr* exp = *iter;

    unsigned long bytes = sizeof *exp;

    total_bytes += bytes;

    if(exp->getRefCount() == 0)
    {
      ++zero_ref_expr;
      zero_ref_bytes += bytes;
    }

    exp->~expr();
  }
}

expr* ExprManager::reg(expr* exp)
{
  theExprs.push_back(exp);
  return exp;
}

} // namespace zorba
