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
 * @file functions/Strings.h
 *
 */

#ifndef XQP_STRINGS_H
#define XQP_STRINGS_H

#include "context/common.h"
#include "functions/function.h"
#include "runtime/item_iterator.h"
#include "util/rchandle.h"
#include "errors/Error.h"

#include <vector>

namespace xqp {
/**______________________________________________________________________
 *
 * 7.2 Functions to Assemble and Disassemble Strings
 *_______________________________________________________________________*/

/**
 * 7.2.1 fn:codepoints-to-string
 *-----------------------*/
	
class fn_codepoints_to_string: public function
{
public:
	fn_codepoints_to_string(const signature&);
	~fn_codepoints_to_string() {}

public:
	iterator_t operator()(yy::location loc, std::vector<iterator_t>&) const;
	sequence_type_t type_check(signature&) const;
	bool validate_args(std::vector<iterator_t>&) const;
};
	

/**
 * 7.2.2 fn:string-to-codepoints
 *-----------------------*/
	class fn_string_to_codepoints: public function
{
	public:
		fn_string_to_codepoints(const signature&);
		~fn_string_to_codepoints() {}

	public:
		iterator_t operator()(yy::location loc, std::vector<iterator_t>&) const;
		sequence_type_t type_check(signature&) const;
		bool validate_args(std::vector<iterator_t>&) const;
};


/**______________________________________________________________________
 *
 * 7.3 Equality and Comparison of Strings
 *_______________________________________________________________________*/
/**
 * 7.3.2 fn:compare
 *-----------------------*/


/**
 * 7.3.3 fn:codepoint-equal
 *-----------------------*/
class fn_codepoint_equal: public function
{
	public:
		fn_codepoint_equal(const signature&);
		~fn_codepoint_equal() {}

	public:
		iterator_t operator()(yy::location loc, std::vector<iterator_t>&) const;
		sequence_type_t type_check(signature&) const;
		bool validate_args(std::vector<iterator_t>&) const;
};

/**______________________________________________________________________
 *
 * 7.4 Functions on String Values
 *_______________________________________________________________________*/

/**
 * 7.4.1 fn:concat
 *-----------------------*/
class fn_concat: public function
{
	public:
		fn_concat(const signature&);
		~fn_concat() {}

	public:
		iterator_t operator()(yy::location loc, std::vector<iterator_t>&) const;
		sequence_type_t type_check(signature&) const;
		bool validate_args(std::vector<iterator_t>&) const;
};

/**
 * 7.4.2 fn:string-join
 *-----------------------*/
class fn_string_join: public function
{
	public:
		fn_string_join(const signature&);
		~fn_string_join() {}

	public:
		iterator_t operator()(yy::location loc, std::vector<iterator_t>&) const;
		sequence_type_t type_check(signature&) const;
		bool validate_args(std::vector<iterator_t>&) const;
};

} /* namespace xqp */
#endif /* XQP_STRINGS_H */

/*
7.4 Functions on String Values
7.4.1 fn:concat
7.4.2 fn:string-join
7.4.3 fn:substring
7.4.4 fn:string-length
7.4.5 fn:normalize-space
7.4.6 fn:normalize-unicode
7.4.7 fn:upper-case
7.4.8 fn:lower-case
7.4.9 fn:translate
7.4.10 fn:encode-for-uri
7.4.11 fn:iri-to-uri
7.4.12 fn:escape-html-uri

7.5 Functions Based on Substring Matching
7.5.1 fn:contains
7.5.2 fn:starts-with
7.5.3 fn:ends-with
7.5.4 fn:substring-before
7.5.5 fn:substring-after

7.6 String Functions that Use Pattern Matching
7.6.1 Regular Expression Syntax
7.6.2 fn:matches
7.6.3 fn:replace
7.6.4 fn:tokenize
*/
