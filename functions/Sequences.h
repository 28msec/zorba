/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: Sequences.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan, Paul Pedersen
 */

#ifndef XQP_SEQUENCES_H
#define XQP_SEQUENCES_H

#include "../functions/function.h"
#include "../runtime/iterator.h"
#include "../util/rchandle.h"
#include "../values/nodes.h"
#include <string>
#include <vector>

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
	iterator_t operator()(zorba*,std::vector<iterator_t>&);
	sequence_type_t type_check(signature&);
	bool validate_args(std::vector<iterator_t>&);
};


//15.1.3 fn:index-of
//------------------
class fn_index_of : public function
{
public:
	fn_index_of(const signature&);
	~fn_index_of() {}

public:
	iterator_t operator()(zorba*,std::vector<iterator_t>&);
	sequence_type_t type_check(signature&);
	bool validate_args(std::vector<iterator_t>&);
};


//15.1.4 fn:empty
//---------------
class fn_empty : public function
{
public:
	fn_empty(const signature&);
	~fn_empty() {}

public:
	iterator_t operator()(zorba*,std::vector<iterator_t>&);
	sequence_type_t type_check(signature&);
	bool validate_args(std::vector<iterator_t>&);
};


//15.1.5 fn:exists
//----------------
class fn_exists : public function
{
public:
	fn_exists(const signature&);
	~fn_exists() {}

public:
	iterator_t operator()(zorba*,std::vector<iterator_t>&);
	sequence_type_t type_check(signature&);
	bool validate_args(std::vector<iterator_t>&);
};


//15.1.6 fn:distinct-values
//-------------------------
class fn_distinct_values : public function
{
public:
	fn_distinct_values(const signature&);
	~fn_distinct_values() {}

public:
	iterator_t operator()(zorba*,std::vector<iterator_t>&);
	sequence_type_t type_check(signature&);
	bool validate_args(std::vector<iterator_t>&);
};


//15.1.7 fn:insert-before
//-----------------------


//15.1.8 fn:remove
//----------------


//15.1.9 fn:reverse
//-----------------
class fn_reverse : public function
{
public:
	fn_reverse(const signature&);
	~fn_reverse() {}

public:
	iterator_t operator()(zorba*,std::vector<iterator_t>&);
	sequence_type_t type_check(signature&);
	bool validate_args(std::vector<iterator_t>&);
};


//15.1.10 fn:subsequence
//----------------------
class fn_subsequence : public function
{
public:
	fn_subsequence(const signature&);
	~fn_subsequence() {}

public:
	iterator_t operator()(zorba*,std::vector<iterator_t>&);
	sequence_type_t type_check(signature&);
	bool validate_args(std::vector<iterator_t>&);
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
	sequence_type_t type_check(signature&) { return xs_untypedValue; }
	iterator_t operator()(zorba*,std::vector<iterator_t>&) { return NULL; } 
	bool validate_args(std::vector<iterator_t>&) { return true; }

};


/*
class fn_min_int : public function
{
public:
	fn_min_int(const signature&);
	~fn_min_int() {}
public:
	sequence_type_t type_check(signature&);
	iterator_t operator()(zorba*, vector<iterator_t>);
};

class fn_min_float : public function
{
public:
	fn_min_float(const signature&);
	~fn_min_float() {}
public:
	sequence_type_t type_check(signature&);
	iterator_t operator()(zorba*, vector<iterator_t>);
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
class fn_doc : public function
{
public:
	fn_doc(const signature&);
	~fn_doc() {}

public:
	sequence_type_t type_check(signature&);
	iterator_t operator()(zorba*, std::vector<iterator_t>&);
	bool validate_args(std::vector<iterator_t>&);
};


//15.5.5 fn:doc-available

//15.5.6 fn:collection


/*______________________________________________________________________
|
| Extensions
|_______________________________________________________________________*/

iterator_t xqp_load(
	zorba*,
	const std::string& path,
	const std::string& baseuri,
	const std::string& uri);


} /* namespace xqp */
#endif /* XQP_SEQUENCES_H */
