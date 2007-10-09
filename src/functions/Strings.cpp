/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/Strings.cpp
 *
 */

#include "Strings.h"
#include "StringsImpl.h"
#include <iostream>

using namespace std;
namespace xqp {

/**
 * ______________________________________________________________________
 *  
 *	7.2.1 fn:codepoints-to-string
 *	
 *	The term "code point"/"codepoint" (also known as "character number" or
 *"code position") means a non-negative integer that represents a
 *character in some encoding.
 *[The Unicode Standard](http://www.w3.org/TR/xpath-functions/#Unicode4),
 *defines code points that range from #x0000 to #x10FFFF inclusive and
 *may include code points that have not yet been assigned to characters.
 *
 *	In functions that involve character counting such as fn:substring,
 *fn:string-length and fn:translate, what is counted is the number of
 *XML characters in the string (or equivalently, the number of Unicode
 *code points). Some implementations may represent a code point above
 *xFFFF using two 16-bit values known as a surrogate. A surrogate counts
 *as one character, not two.
 *
 *	fn:codepoints-to-string($arg as xs:integer*) as xs:string
 *
 *	Summary:Creates an xs:string from a sequence of code points.
 *Returns the zero-length string if $arg is the empty sequence.
 *If any of the code points in $arg is not a legal XML character,
 *an error is raised [err:FOCH0001] ("Code point not valid.").
 *_______________________________________________________________________*/

fn_codepoints_to_string::fn_codepoints_to_string(
	const signature& sig)
:
	function(sig)
{
}

Iterator_t fn_codepoints_to_string::operator()(
  const yy::location& loc,
	vector<Iterator_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;
	return new CodepointsToStringIterator(loc, argv[0]);
}

sequence_type_t fn_codepoints_to_string::type_check(
	signature& sig) const
{
	return xs_integer;
}

bool fn_codepoints_to_string::validate_args(
	vector<Iterator_t>& argv) const
{
	return (argv.size() == 1);
}

	
/**______________________________________________________________________
 *
 *	7.2.1 fn:string-to-codepoints
 *
 *	Summary: Returns the sequence of code points that constitute an
 *xs:string.
 *If $arg is a zero-length string or the empty sequence,
 *the empty sequence is returned.
 *_______________________________________________________________________*/
	
fn_string_to_codepoints::fn_string_to_codepoints(
	const signature& sig)
:
	function(sig)
	{
	}

	Iterator_t fn_string_to_codepoints::operator()(
	const yy::location& loc,
	vector<Iterator_t>& argv) const
{
	if (!validate_args(argv))
		return NULL;
	return new StringToCodepointsIterator(loc, argv[0]);
}

sequence_type_t fn_string_to_codepoints::type_check(
	signature& sig) const
{
	return xs_string;
}

bool fn_string_to_codepoints::validate_args(
		vector<Iterator_t>& argv) const
{
	return (argv.size() == 1);
}

/**______________________________________________________________________
 *
 *	7.3.2 fn:compare
 *
 *
 *_______________________________________________________________________*/


/**______________________________________________________________________
 *
 *	7.3.3 fn:codepoint-equal
 *
 *	Summary: Returns true or false depending on whether the value
 * of $comparand1 is equal to the value of $comparand2, according to
 * the Unicode code point collation
 * (http://www.w3.org/2005/xpath-functions/collation/codepoint).
 *
 * If either argument is the empty sequence, the result is the empty sequence.
 *
 * Note: This function allows xs:anyURI values to be compared
 * without having to specify the Unicode code point collation.
 *_______________________________________________________________________*/
	
fn_codepoint_equal::fn_codepoint_equal(
		const signature& sig)
	:
		function(sig)
{
}

Iterator_t fn_codepoint_equal::operator()(
	const yy::location& loc,
	vector<Iterator_t>& argv) const
{
	if (!validate_args(argv))
		return NULL;
	return new CodepointEqualIterator(loc, argv[0], argv[1]);
}

sequence_type_t fn_codepoint_equal::type_check(
	signature& sig) const
{
	return xs_string;
}

bool fn_codepoint_equal::validate_args(
	vector<Iterator_t>& argv) const
{
	return (argv.size() == 2);
}

/**______________________________________________________________________
 *
 *	7.4.1 fn:concat
 *
 *	Summary: Accepts two or more xs:anyAtomicType arguments and casts
 * them to xs:string.
 * 
 * Returns the xs:string that is the concatenation of the values of its
 * arguments after conversion.
 * If any of the arguments is the empty sequence, the argument is treated
 * as the zero-length string.
 * If either argument is the empty sequence, the result is the
 * empty sequence.
 *
 * The fn:concat function is specified to allow an two or more arguments
 * that are concatenated together.
 *_______________________________________________________________________*/

fn_concat::fn_concat(
	const signature& sig)
:
	function(sig)
{
}

Iterator_t fn_concat::operator()(
	const yy::location& loc, 
	vector<Iterator_t>& argv) const
{
	if (!validate_args(argv)) return NULL;
	return new ConcatFnIterator(loc,argv);
}

bool fn_concat::validate_args(
	vector<Iterator_t>& argv) const
{
	return (argv.size() >= 2);
}

sequence_type_t fn_concat::type_check(
	signature& sig) const
{
	return xs_anyType;
}


/**
 * ______________________________________________________________________
 *  
 *	7.4.2 fn:string-join
 *
 * Summary: Returns a xs:string created by concatenating the members
 * of the $arg1 sequence using $arg2 as a separator.
 * 
 * If the value of $arg2 is the zero-length string, then the members
 * of $arg1 are concatenated without a separator.
 *
 * If the value of $arg1 is the empty sequence,
 * the zero-length string is returned.
 * 
 *_______________________________________________________________________*/

fn_string_join::fn_string_join(
	const signature& sig)
:
	function(sig)
{
}

Iterator_t fn_string_join::operator()(
  const yy::location& loc,
	vector<Iterator_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;
	return new StringJoinIterator(loc, argv);
}

sequence_type_t fn_string_join::type_check(
	signature& sig) const
{
	return xs_string;
}

bool fn_string_join::validate_args(
	vector<Iterator_t>& argv) const
{
	return true;
}


}/*namespace xqp*/
