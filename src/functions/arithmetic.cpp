#include <vector>

#include "system/globalenv.h"
#include "functions/arithmetic.h"
#include "runtime/core/arithmetic_impl.h"

using namespace std;

namespace xqp {

op_add::op_add(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_add::operator()(
	const yy::location& loc, 
	vector<PlanIter_t>& argv) const
{
	return new GenericArithIterator<AddOperation>(loc, argv[0], argv[1]);
}

xqtref_t op_add::type_check(
	signature& sig) const
{
	return GENV_TYPESYSTEM.DECIMAL_TYPE_ONE;
}

bool op_add::validate_args(
	vector<PlanIter_t>& argv) const
{
	return (argv.size()==2);
}

op_subtract::op_subtract(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_subtract::operator()(
	const yy::location& loc, 
	vector<PlanIter_t>& argv) const
{
	return new GenericArithIterator<SubtractOperation>(loc, argv[0], argv[1]);
}

xqtref_t op_subtract::type_check(
	signature& sig) const
{
	return GENV_TYPESYSTEM.DECIMAL_TYPE_ONE;
}

bool op_subtract::validate_args(
	vector<PlanIter_t>& argv) const
{
	return (argv.size()==2);
}

op_multiply::op_multiply(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_multiply::operator()(
	const yy::location& loc, 
	vector<PlanIter_t>& argv) const
{
	return new GenericArithIterator<MultiplyOperation>(loc, argv[0], argv[1]);
}

xqtref_t op_multiply::type_check(
	signature& sig) const
{
	return GENV_TYPESYSTEM.DECIMAL_TYPE_ONE;
}

bool op_multiply::validate_args(
	vector<PlanIter_t>& argv) const
{
	return (argv.size()==2);
}

op_divide::op_divide(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_divide::operator()(
	const yy::location& loc, 
	vector<PlanIter_t>& argv) const
{
	return new GenericArithIterator<DivideOperation>(loc, argv[0], argv[1]);
}

xqtref_t op_divide::type_check(
	signature& sig) const
{
	return GENV_TYPESYSTEM.DECIMAL_TYPE_ONE;
}

bool op_divide::validate_args(
	vector<PlanIter_t>& argv) const
{
	return (argv.size()==2);
}

op_integer_divide::op_integer_divide(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_integer_divide::operator()(
	const yy::location& loc, 
	vector<PlanIter_t>& argv) const
{
	return new GenericArithIterator<IntegerDivideOperation>(loc, argv[0], argv[1]);
}

xqtref_t op_integer_divide::type_check(
	signature& sig) const
{
	return GENV_TYPESYSTEM.DECIMAL_TYPE_ONE;
}

bool op_integer_divide::validate_args(
	vector<PlanIter_t>& argv) const
{
	return (argv.size()==2);
}

op_mod::op_mod(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_mod::operator()(
	const yy::location& loc, 
	vector<PlanIter_t>& argv) const
{
	return new GenericArithIterator<ModOperation>(loc, argv[0], argv[1]);
}

xqtref_t op_mod::type_check(
	signature& sig) const
{
	return GENV_TYPESYSTEM.DECIMAL_TYPE_ONE;
}

bool op_mod::validate_args(
	vector<PlanIter_t>& argv) const
{
	return (argv.size()==2);
}


}
