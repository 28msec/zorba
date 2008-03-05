/**
 * @file Sequences.h
 * @author Paul Pedersen (pcp071098@yahoo.com)
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

#ifndef ZORBA_SEQUENCES_H
#define ZORBA_SEQUENCES_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class zorba;

/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/

//15.1.1 fn:boolean (effective boolean value)
//-----------------


//15.1.2 op:concatenate
//---------------------
class op_concatenate : public function
{
public:
	op_concatenate(const signature&);
	~op_concatenate() {}

public:
	PlanIter_t operator()(const QueryLoc& loc,std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.3 fn:index-of
//------------------
class fn_index_of : public function
{
public:
	fn_index_of(const signature&);
	~fn_index_of() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.4 fn:empty
//---------------
class fn_empty : public function
{
public:
	fn_empty(const signature&);
	~fn_empty() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.5 fn:exists
//----------------
class fn_exists : public function
{
public:
	fn_exists(const signature&);
	~fn_exists() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.6 fn:distinct-values
//-------------------------
class fn_distinct_values_1 : public function
{
public:
	fn_distinct_values_1(const signature&);
	~fn_distinct_values_1() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

class fn_distinct_values_2 : public fn_distinct_values_1
{
public:
	fn_distinct_values_2(const signature& sig)
	  : fn_distinct_values_1(sig) { }
	~fn_distinct_values_2() {}
};


//15.1.7 fn:insert-before
//-----------------------
class fn_insert_before : public function
{
public:
	fn_insert_before(const signature&);
	~fn_insert_before() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.8 fn:remove
//----------------
class fn_remove : public function
{
public:
	fn_remove(const signature&);
	~fn_remove() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.9 fn:reverse
//-----------------
class fn_reverse : public function
{
public:
	fn_reverse(const signature&);
	~fn_reverse() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.10 fn:subsequence
//----------------------
// subsequence with 2 arguments
class fn_subsequence_2 : public function
{
public:
	fn_subsequence_2(const signature&);
	~fn_subsequence_2() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// subsequence with a third length argument
class fn_subsequence_3 : public fn_subsequence_2
{
public:
	fn_subsequence_3(const signature& sig)
	  : fn_subsequence_2(sig) { }
	~fn_subsequence_3() {}
};


//15.1.11 fn:unordered
//--------------------


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one
class fn_zero_or_one : public function
{
public:
	fn_zero_or_one(const signature&);
	~fn_zero_or_one() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

//15.2.2 fn:one-or-more
class fn_one_or_more : public function
{
public:
	fn_one_or_more(const signature&);
	~fn_one_or_more() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

//15.2.3 fn:exactly-one
class fn_exactly_one : public function
{
public:
	fn_exactly_one(const signature&);
	~fn_exactly_one() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal

//15.3.2 op:union

//15.3.3 op:intersect

//15.3.4 op:except


/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.1 fn:count
class fn_count: public function
{
public:
	fn_count(const signature&);
	~fn_count() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

//15.4.2 fn:avg
class fn_avg: public function
{
public:
	fn_avg(const signature&);
	~fn_avg() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

//15.4.3 fn:max
class fn_max_1 : public function
{
public:
	fn_max_1(const signature&);
	~fn_max_1() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

class fn_max_2 : public fn_max_1
{
public:
	fn_max_2(const signature& sig)
	  : fn_max_1(sig) { }
	~fn_max_2() {}
};


//15.4.4 fn:min
//-------------
class fn_min_1 : public function
{
public:
	fn_min_1(const signature&);
	~fn_min_1() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

class fn_min_2 : public fn_min_1
{
public:
	fn_min_2(const signature& sig)
	  : fn_min_1(sig) { }
	~fn_min_2() {}
};

//15.4.5 fn:sum
class fn_sum_1 : public function
{
public:
	fn_sum_1(const signature&);
	~fn_sum_1() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

class fn_sum_2 : public fn_sum_1
{
public:
	fn_sum_2(const signature& sig)
	  : fn_sum_1(sig) { }
	~fn_sum_2() {}
	xqtref_t type_check(signature&) const;
};


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to
class op_to : public function
{
public:
	op_to(const signature&);
	~op_to() {}

public:
	PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.5.2 fn:id

//15.5.3 fn:idref


//15.5.4 fn:doc
class fn_doc_func : public function
{
public:
	fn_doc_func(const signature&);
	~fn_doc_func() {}

public:
	xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.5.5 fn:doc-available

//15.5.6 fn:collection


/*______________________________________________________________________
|
| Extensions
|_______________________________________________________________________*/

// internal distinct-nodes function
class op_distinct_nodes : public function
{
public:
	op_distinct_nodes(const signature&);
	~op_distinct_nodes() {}

public:
	xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// internal distinct-nodes-or-atomics function
/**
 * Similar to op-distinct, but it allows a sequences of atomic items as input 
 * (but no mixture of atomic and node items). In this case, the result is
 * equal to the input
 */
class op_distinct_nodes_or_atomics : public function {
public:
  op_distinct_nodes_or_atomics(const signature&);
  ~op_distinct_nodes_or_atomics() {}

public:
  xqtref_t type_check(signature&) const;
  PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};

// internal sort-nodes function sorting in document order
class op_sort_nodes_ascending : public function
{
public:
	op_sort_nodes_ascending(const signature&);
	~op_sort_nodes_ascending() {}

public:
	xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// internal sort-nodes-asc-or-atomics function
/**
 * Similar to op-sort-ascending, but it allows a sequences of atomic items as input 
 * (but no mixture of atomic and node items). In this case, the result is
 * equal to the input
 */
class op_sort_nodes_asc_or_atomics : public function {
public:
  op_sort_nodes_asc_or_atomics(const signature&);
  ~op_sort_nodes_asc_or_atomics() {}

public:
  xqtref_t type_check(signature&) const;
  PlanIter_t operator()( const QueryLoc& loc, std::vector<PlanIter_t>&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};

// internal sort-nodes function sorting in reverse document order
class op_sort_nodes_descending : public function
{
public:
	op_sort_nodes_descending(const signature&);
	~op_sort_nodes_descending() {}

public:
	xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// internal sort-nodes-desc-or-atomics function
/**
* Similar to op-sort-descending, but it allows a sequences of atomic items as input 
* (but no mixture of atomic and node items). In this case, the result is
* equal to the input
*/
class op_sort_nodes_desc_or_atomics : public function
{
public:
  op_sort_nodes_desc_or_atomics(const signature&);
  ~op_sort_nodes_desc_or_atomics() {}

public:
  xqtref_t type_check(signature&) const;
  PlanIter_t operator()(const QueryLoc& loc, std::vector<PlanIter_t>&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};



// internal function for sort-nodes in document order and doing distinct-nodes in one run
class op_sort_distinct_nodes_ascending : public function
{
public:
	op_sort_distinct_nodes_ascending(const signature&);
	~op_sort_distinct_nodes_ascending() {}

public:
	xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// internal sort-distinct-nodes-asc-or-atomics
/**
* Similar to sort-distinct-nodes-ascending, but it allows a sequences of atomic items as input 
* (but no mixture of atomic and node items). In this case, the result is
* equal to the input
*/
class op_sort_distinct_nodes_asc_or_atomics : public function
{
public:
	op_sort_distinct_nodes_asc_or_atomics(const signature&);
	~op_sort_distinct_nodes_asc_or_atomics() {}

public:
	xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


// internal function for sort-nodes in reverse document order and doing distinct-nodes in one run
class op_sort_distinct_nodes_descending : public function
{
public:
	op_sort_distinct_nodes_descending(const signature&);
	~op_sort_distinct_nodes_descending() {}

public:
	xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const QueryLoc& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

} /* namespace zorba */
#endif /* ZORBA_SEQUENCES_H */
