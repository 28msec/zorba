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

  // 6.2.1 op:add
  // --------------------
  class op_add : public function
  {
  public:
	op_add(const signature& sig) : function (sig) {}
	
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  // 6.2.2 op:numeric-subtract
  // -------------------------
  class op_subtract : public function
  {
  public:
	op_subtract(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  // 6.2.3 op:numeric-multiply
  // -------------------------
  class op_multiply : public function
  {
  public:
	op_multiply(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  // 6.2.4 op:numeric-divide
  // -----------------------
  class op_divide : public function
  {
  public:
	op_divide(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  // 6.2.5 op:numeric-integer-divide
  // -------------------------------
  class op_integer_divide : public function
  {
  public:
	op_integer_divide(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  // 6.2.6 op:numeric-mod
  // --------------------
  class op_mod : public function
  {
  public:
	op_mod(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
