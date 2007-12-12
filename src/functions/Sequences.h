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

#ifndef XQP_SEQUENCES_H
#define XQP_SEQUENCES_H

#include <string>
#include <vector>

#include "system/globalenv.h"
#include "functions/function.h"

namespace xqp {

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
	PlanIter_t operator()(const yy::location& loc,std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
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
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
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
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
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
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.6 fn:distinct-values
//-------------------------
class fn_distinct_values : public function
{
public:
	fn_distinct_values(const signature&);
	~fn_distinct_values() {}

public:
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.7 fn:insert-before
//-----------------------
class fn_insert_before : public function
{
public:
	fn_insert_before(const signature&);
	~fn_insert_before() {}

public:
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
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
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
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
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.10 fn:subsequence
//----------------------
class fn_subsequence : public function
{
public:
	fn_subsequence(const signature&);
	~fn_subsequence() {}

public:
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
	TypeSystem::xqtref_t type_check(signature&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.1.11 fn:unordered
//--------------------


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one

//15.2.2 fn:one-or-more

//15.2.3 fn:exactly-one


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

//15.4.2 fn:avg

//15.4.3 fn:max


//15.4.4 fn:min
//-------------
class fn_min : public function
{
public:
	fn_min(const signature&);
	~fn_min() {}

public:
	TypeSystem::xqtref_t type_check(signature&) const { return GENV_TYPESYSTEM.UNTYPED_TYPE; }
	PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const { return NULL; } 
	bool validate_args(std::vector<PlanIter_t>&) const { return true; }

};


/*
class fn_min_int : public function
{
public:
	fn_min_int(const signature&);
	~fn_min_int() {}
public:
	TypeSystem::xqtref_t type_check(signature&) const;
	PlanIter_t operator()( vector<PlanIter_t>) const;
};

class fn_min_float : public function
{
public:
	fn_min_float(const signature&);
	~fn_min_float() {}
public:
	TypeSystem::xqtref_t type_check(signature&) const;
	PlanIter_t operator()( vector<PlanIter_t>) const;
};
*/


//15.4.5 fn:sum


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to

//15.5.2 fn:id

//15.5.3 fn:idref


//15.5.4 fn:doc
class fn_doc_func : public function
{
public:
	fn_doc_func(const signature&);
	~fn_doc_func() {}

public:
	TypeSystem::xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const yy::location& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


//15.5.5 fn:doc-available

//15.5.6 fn:collection


/*______________________________________________________________________
|
| Extensions
|_______________________________________________________________________*/

// internal distinct-nodes function
class fn_distinct_nodes : public function
{
public:
	fn_distinct_nodes(const signature&);
	~fn_distinct_nodes() {}

public:
	TypeSystem::xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const yy::location& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};

// internal sort-nodes function
class fn_sort_nodes : public function
{
public:
	fn_sort_nodes(const signature&);
	~fn_sort_nodes() {}

public:
	TypeSystem::xqtref_t type_check(signature&) const;
	PlanIter_t operator()( const yy::location& loc, std::vector<PlanIter_t>&) const;
	bool validate_args(std::vector<PlanIter_t>&) const;
};


PlanIter_t xqp_load(
	const std::string& path,
	const std::string& baseuri,
	const std::string& uri);


} /* namespace xqp */
#endif /* XQP_SEQUENCES_H */
