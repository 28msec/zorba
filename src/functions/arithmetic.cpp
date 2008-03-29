#include <vector>

#include "system/globalenv.h"
#include "functions/arithmetic.h"
#include "runtime/core/arithmetic_impl.h"

using namespace std;

namespace zorba {

op_add::op_add(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_add::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<AddOperation>(loc, argv[0], argv[1]);
}



op_subtract::op_subtract(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_subtract::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<SubtractOperation>(loc, argv[0], argv[1]);
}



op_multiply::op_multiply(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_multiply::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<MultiplyOperation>(loc, argv[0], argv[1]);
}



op_divide::op_divide(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<DivideOperation>(loc, argv[0], argv[1]);
}



op_integer_divide::op_integer_divide(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_integer_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<IntegerDivideOperation>(loc, argv[0], argv[1]);
}



op_mod::op_mod(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_mod::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<ModOperation>(loc, argv[0], argv[1]);
}




}
