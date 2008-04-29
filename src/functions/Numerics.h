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
#ifndef ZORBA_NUMERICS_H
#define ZORBA_NUMERICS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class zorba;


 class single_numeric_func : public function {
 public:
   single_numeric_func (const signature &sig) : function (sig) {}
   virtual xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
 };

/*______________________________________________________________________
|  
| 6.2 Operators on Numeric Values
|_______________________________________________________________________*/


// 6.2.1 op:numeric-add
// --------------------
class op_numeric_add : public function
{
public:
	op_numeric_add(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.2 op:numeric-subtract
// -------------------------
class op_numeric_subtract : public function
{
public:
	op_numeric_subtract(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};


// 6.2.3 op:numeric-multiply
// -------------------------
class op_numeric_multiply : public function
{
public:
	op_numeric_multiply(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};


// 6.2.4 op:numeric-divide
// -----------------------
class op_numeric_divide : public function
{
public:
	op_numeric_divide(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.5 op:numeric-integer-divide
// -------------------------------
class op_numeric_integer_divide : public function
{
public:
	op_numeric_integer_divide(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.6 op:numeric-mod
// --------------------
class op_numeric_mod : public function
{
public:
	op_numeric_mod(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.7 op:numeric-unary-plus
// ---------------------------
class op_numeric_unary_plus : public single_numeric_func
{
public:
	op_numeric_unary_plus(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.8 op:numeric-unary-minus
// ----------------------------
class op_numeric_unary_minus : public single_numeric_func
{
public:
	op_numeric_unary_minus(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};


/*______________________________________________________________________
|  
| 6.4 Functions on Numeric Values
|_______________________________________________________________________*/

// 6.4.1 fn:abs
class fn_abs : public single_numeric_func 
{
public:
	fn_abs(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.4.2 fn:ceiling
class fn_ceiling : public single_numeric_func
{
  public:
    fn_ceiling(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.4.3 fn:floor
class fn_floor : public single_numeric_func
{
  public:
    fn_floor(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.4.4 fn:round
class fn_round : public single_numeric_func
{
  public:
    fn_round(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.4.5 fn:round-half-to-even
class fn_round_half_to_even : public single_numeric_func
{
  public:
    fn_round_half_to_even(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// Zorba specific functions:

/**
 * Function to produce a fixed amount of integer for testing purposes.
 */
class zor_numgen : public function
{
public:
	zor_numgen(const signature&);
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

}	/* namespace zorba */
#endif	/* ZORBA_NUMERICS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
