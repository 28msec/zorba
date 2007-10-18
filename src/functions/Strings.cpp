/**
 * @copyright
 * ========================================================================
 *	Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/Strings.cpp
 *
 */

#include <iostream>

#include "functions/Strings.h"
#include "runtime/strings/StringsImpl.h"

using namespace std;
namespace xqp {

/*
 * 7.2.1 fn:codepoints-to-string
 * --------------------*/
/*begin class fn_codepoints_to_string*/
fn_codepoints_to_string::fn_codepoints_to_string(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_codepoints_to_string::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;
	return new CodepointsToStringIterator(loc, argv[0]);
}

sequence_type_t
fn_codepoints_to_string::type_check(
	signature& sig) const
{
	return xs_integer;
}

bool
fn_codepoints_to_string::validate_args(
	vector<PlanIter_t>& argv) const
{
	return true;
}
/*end class fn_codepoints_to_string*/
	
/*
 * 7.2.2 fn:string-to-codepoints
 * --------------------*/
/*begin class fn_string_to_codepoints*/
fn_string_to_codepoints::fn_string_to_codepoints(
	const signature& sig)
:
	function(sig)
	{
	}

PlanIter_t
fn_string_to_codepoints::operator()(
	const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
		return NULL;
	return new StringToCodepointsIterator(loc, argv[0]);
}

sequence_type_t
fn_string_to_codepoints::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_string_to_codepoints::validate_args(
		vector<PlanIter_t>& argv) const
{
	return true;
}
/*end class fn_string_to_codepoints*/

/*
 * 7.3.2 fn:compare
 * --------------------*/
/*begin class fn_string_compare*/
fn_string_compare::fn_string_compare(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_string_compare::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;
	return new CompareStrIterator(loc, argv);
}

sequence_type_t
fn_string_compare::type_check(
	signature& sig) const
{
	return xs_integer;
}

bool
fn_string_compare::validate_args(
	vector<PlanIter_t>& argv) const
{
	return ((argv.size() == 2) || (argv.size() == 3));
}
/*end class fn_string_compare*/

/*
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
/*begin class fn_codepoint_equal*/
fn_codepoint_equal::fn_codepoint_equal(
		const signature& sig)
	:
		function(sig)
{
}

PlanIter_t
fn_codepoint_equal::operator()(
	const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
		return NULL;
	return new CodepointEqualIterator(loc, argv[0], argv[1]);
}

sequence_type_t
fn_codepoint_equal::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_codepoint_equal::validate_args(
	vector<PlanIter_t>& argv) const
{
	return (argv.size() == 2);
}
/*end class fn_codepoint_equal*/

/*
 * 7.4.1 fn:string-concat
 * --------------------*/
/*begin class fn_concat*/
fn_concat::fn_concat(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_concat::operator()(
	const yy::location& loc, 
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv)) return NULL;
	return new ConcatStrIterator(loc,argv);
}

bool
fn_concat::validate_args(
	vector<PlanIter_t>& argv) const
{
		//TODO check if the types ogf the iterators are xs:anyAtomicType something like
		//if((_argv[0]->getType() & NODE_MASK) == NOT_NODE)
	return true;
}

sequence_type_t
fn_concat::type_check(
	signature& sig) const
{
	return xs_anyType;
}
/*end class fn_concat*/

/*
 * 7.4.2 fn:string-join
 * --------------------*/
/*begin class fn_string_join*/
fn_string_join::fn_string_join(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_string_join::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;
	return new StringJoinIterator(loc, argv[0], argv[1]);
}

sequence_type_t
fn_string_join::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_string_join::validate_args(
	vector<PlanIter_t>& argv) const
{
		return (argv.size() == 1 || argv.size() == 2);
}
/*end class fn_string_join*/

/*
 * 7.4.4 fn:string-length
 * --------------------*/
/*begin class fn_string_length*/
fn_string_length::fn_string_length(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_string_length::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;
	return new StringLengthIterator(loc, argv[0]);
}

sequence_type_t
fn_string_length::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_string_length::validate_args(
	vector<PlanIter_t>& argv) const
{
		return (argv.size() == 1);
}
/*end class fn_string_length*/

/*
 * 7.5.1 fn:contains
 * --------------------*/
/*begin class fn_contains*/
fn_contains::fn_contains(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_contains::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;

	return new ContainsIterator(loc, argv);
}

sequence_type_t
fn_contains::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_contains::validate_args(
	vector<PlanIter_t>& argv) const
{
		return (argv.size() == 2 || argv.size() == 3);
}
/*end class fn_contains*/

/*
 * 7.5.2 fn:starts-with
 * --------------------*/
/*begin class fn_starts_with*/
fn_starts_with::fn_starts_with(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_starts_with::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;

	return new StartsWithIterator(loc, argv);
}

sequence_type_t
fn_starts_with::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_starts_with::validate_args(
	vector<PlanIter_t>& argv) const
{
		return (argv.size() == 2 || argv.size() == 3);
}
/*end class fn_starts_with*/

/*
 * 7.5.3 fn:ends-with
 * --------------------*/
/*begin class fn_ends_with*/
fn_ends_with::fn_ends_with(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_ends_with::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;

	return new EndsWithIterator(loc, argv);
}

sequence_type_t
fn_ends_with::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_ends_with::validate_args(
	vector<PlanIter_t>& argv) const
{
		return (argv.size() == 2 || argv.size() == 3);
}
/*end class fn_ends_with*/

/*
 * 7.5.4 fn:substring-before
 * --------------------*/
/*begin class fn_substring_before*/
fn_substring_before::fn_substring_before(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_substring_before::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;

	return new SubstringBeforeIterator(loc, argv);
}

sequence_type_t
fn_substring_before::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_substring_before::validate_args(
	vector<PlanIter_t>& argv) const
{
		return (argv.size() == 2 || argv.size() == 3);
}
/*end class fn_substring_before*/

/*
 * 7.5.5 fn:substring-after
 * --------------------*/
/*begin class fn_substring_after*/
fn_substring_after::fn_substring_after(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t
fn_substring_after::operator()(
  const yy::location& loc,
	vector<PlanIter_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;

	return new SubstringAfterIterator(loc, argv);
}

sequence_type_t
fn_substring_after::type_check(
	signature& sig) const
{
	return xs_string;
}

bool
fn_substring_after::validate_args(
	vector<PlanIter_t>& argv) const
{
		return (argv.size() == 2 || argv.size() == 3);
}
/*end class fn_substring_after*/
}/*namespace xqp*/
