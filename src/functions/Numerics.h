/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author David Graff (david.graf@28msec.com)
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/numerics.h
 *
 */

#ifndef ZORBA_NUMERICS_H
#define ZORBA_NUMERICS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class zorba;

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
	~op_numeric_add() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

//class op_numeric_add_int : public function
//{
//public:
//	op_numeric_add_int(const signature&);
//	~op_numeric_add_int() {}
//
//public:
//	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
//	xqtref_t type_check(signature&) const;
//	bool validate_args(std::vector<PlanIter_t>&) const;
//};


// 6.2.2 op:numeric-subtract
// -------------------------
class op_numeric_subtract : public function
{
public:
	op_numeric_subtract(const signature&);
	~op_numeric_subtract() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


// 6.2.3 op:numeric-multiply
// -------------------------
class op_numeric_multiply : public function
{
public:
	op_numeric_multiply(const signature&);
	~op_numeric_multiply() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


// 6.2.4 op:numeric-divide
// -----------------------
class op_numeric_divide : public function
{
public:
	op_numeric_divide(const signature&);
	~op_numeric_divide() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.2.5 op:numeric-integer-divide
// -------------------------------
class op_numeric_integer_divide : public function
{
public:
	op_numeric_integer_divide(const signature&);
	~op_numeric_integer_divide() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.2.6 op:numeric-mod
// --------------------
class op_numeric_mod : public function
{
public:
	op_numeric_mod(const signature&);
	~op_numeric_mod() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.2.7 op:numeric-unary-plus
// ---------------------------
class op_numeric_unary_plus : public function
{
public:
	op_numeric_unary_plus(const signature&);
	~op_numeric_unary_plus() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.2.8 op:numeric-unary-minus
// ----------------------------
class op_numeric_unary_minus : public function
{
public:
	op_numeric_unary_minus(const signature&);
	~op_numeric_unary_minus() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};



/*______________________________________________________________________
|  
| 6.3 Comparison Operators on Numeric Values
|_______________________________________________________________________*/

// 6.3.1 op:numeric-equal
//-----------------------
// 6.3.2 op:numeric-less-than
// 6.3.3 op:numeric-greater-than


/*______________________________________________________________________
|  
| 6.4 Functions on Numeric Values
|_______________________________________________________________________*/

// 6.4.1 fn:abs
class fn_abs : public function 
{
public:
	fn_abs(const signature&);
	~fn_abs() {}

public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.4.2 fn:ceiling
class fn_ceiling : public function
{
  public:
    fn_ceiling(const signature&);
    ~fn_ceiling(){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.4.3 fn:floor
class fn_floor : public function
{
  public:
    fn_floor(const signature&);
    ~fn_floor(){}

    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check( signature&) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 6.4.4 fn:round
class fn_round : public function
{
  public:
    fn_round(const signature&);
    ~fn_round(){}
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// 6.4.5 fn:round-half-to-even
class fn_round_half_to_even : public function
{
  public:
    fn_round_half_to_even(const signature&);
    ~fn_round_half_to_even(){}
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t type_check( signature& ) const;
    bool validate_args( std::vector<PlanIter_t>&) const;
};

// Zorba specific functions:
/**
 * Function to produce a fixed amount of integer for testing purposes.
 */
class zor_numgen : public function
{
public:
	zor_numgen(const signature&);
	~zor_numgen() {}
	
public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

}	/* namespace zorba */
#endif	/* ZORBA_NUMERICS_H */
