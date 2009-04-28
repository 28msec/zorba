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
#ifndef ZORBA_ARITHMETIC_H
#define ZORBA_ARITHMETIC_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

  class binary_arith_func : public function {
  public:
    binary_arith_func (const signature &sig) : function (sig) {}
    virtual bool isArithmeticFunction() const { return true; }
    virtual const char *op_name () const = 0;
    xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;

    const function *specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const;
  };

  // 6.2.2 op:numeric-subtract
  // -------------------------
  class op_subtract : public binary_arith_func {
  public:
    op_subtract(const signature& sig) : binary_arith_func (sig) {}
    const char *op_name () const { return "subtract"; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  void populateContext_Arithmetics(static_context *sctx);
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
