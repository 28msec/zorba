/**
 * @file Strings.cpp
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @copyright 2006-2007 FLWOR Foundation (flworfound.org)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "Strings.h"
#include "StringsImpl.h"
#include <iostream>

using namespace std;
namespace xqp {
/*______________________________________________________________________
|  
|	7.2.1 fn:codepoints-to-string
|	
|	The term "code point"/"codepoint" (also known as "character number" or
|"code position") means a non-negative integer that represents a
|character in some encoding.
|[The Unicode Standard](http://www.w3.org/TR/xpath-functions/#Unicode4),
|defines code points that range from #x0000 to #x10FFFF inclusive and
|may include code points that have not yet been assigned to characters.
|
|	In functions that involve character counting such as fn:substring,
|fn:string-length and fn:translate, what is counted is the number of
|XML characters in the string (or equivalently, the number of Unicode
|code points). Some implementations may represent a code point above
|xFFFF using two 16-bit values known as a surrogate. A surrogate counts
|as one character, not two.
|
|	fn:codepoints-to-string($arg as xs:integer*) as xs:string
|	
|	Summary:Creates an xs:string from a sequence of code points.
|Returns the zero-length string if $arg is the empty sequence.
|If any of the code points in $arg is not a legal XML character,
|an error is raised [err:FOCH0001] ("Code point not valid.").
|_______________________________________________________________________*/

fn_codepoints_to_string::fn_codepoints_to_string(
	const signature& sig)
:
	function(sig)
{
}

iterator_t fn_codepoints_to_string::operator()(
  yy::location loc,
	vector<iterator_t>& argv) const
{
	if (!validate_args(argv))
			return NULL;
	return new fn_codepoints_to_string_iterator(loc, argv[0]);
}

sequence_type_t fn_codepoints_to_string::type_check(
	signature& sig) const
{
	return xs_integer;
}

bool fn_codepoints_to_string::validate_args(
	vector<iterator_t>& argv) const
{
	return (argv.size() == 1);
}

	
/*______________________________________________________________________
|  
|	7.2.1 fn:string-to-codepoints
|
|	Summary: Returns the sequence of code points that constitute an
|xs:string.
|If $arg is a zero-length string or the empty sequence,
|the empty sequence is returned.
|_______________________________________________________________________*/
	
fn_string_to_codepoints::fn_string_to_codepoints(
	const signature& sig)
:
	function(sig)
	{
	}

	iterator_t fn_string_to_codepoints::operator()(
	yy::location loc,
	vector<iterator_t>& argv) const
{
	if (!validate_args(argv))
		return NULL;
	return new fn_string_to_codepoints_iterator(loc, argv[0]);
}

sequence_type_t fn_string_to_codepoints::type_check(
	signature& sig) const
{
	return xs_string;
}

bool fn_string_to_codepoints::validate_args(
		vector<iterator_t>& argv) const
{
	return (argv.size() == 1);
}
}/*namespace xqp*/
