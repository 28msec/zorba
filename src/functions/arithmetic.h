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
	op_add(const signature&);
	
public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.2.2 op:numeric-subtract
// -------------------------
class op_subtract : public function
{
public:
	op_subtract(const signature&);
	
public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


// 6.2.3 op:numeric-multiply
// -------------------------
class op_multiply : public function
{
public:
	op_multiply(const signature&);
	
public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


// 6.2.4 op:numeric-divide
// -----------------------
class op_divide : public function
{
public:
	op_divide(const signature&);
	
public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.2.5 op:numeric-integer-divide
// -------------------------------
class op_integer_divide : public function
{
public:
	op_integer_divide(const signature&);
	
public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// 6.2.6 op:numeric-mod
// --------------------
class op_mod : public function
{
public:
	op_mod(const signature&);
	
public:
	PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

} // namespace zorba

#endif
