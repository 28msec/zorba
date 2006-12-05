/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dynamic_context.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_STATIC_CONTEXT_H
#define XQP_STATIC_CONTEXT_H

#include <time.h>
#include <map>
#include <string>
#include <vector>

#include "../util/rchandle.h"
#include "../parser/exprnode.h"
#include "../runtime/valuenode.h"


/*


*/

class var_binding


class dynamic_context
{

	/*
	**	Definition: The context item is the item currently being processed. An 
	**	item is either an atomic value or a node.][Definition: When the 
	**	context item is a node, it can also be referred to as the context 
	**	node.] The context item is returned by an expression consisting of a 
	**	single dot (.). When an expression E1/E2 or E1[E2] is evaluated, each 
	**	item in the sequence obtained by evaluating E1 becomes the context 
	**	item in the inner focus for an evaluation of E2. 
	*/
	rchandle<expr> context_item;
	

	/*
	**	[Definition: The context position is the position of the context item 
	**	within the sequence of items currently being processed.] It changes 
	**	whenever the context item changes. When the focus is defined, the 
	**	value of the context position is an integer greater than zero. The 
	**	context position is returned by the expression fn:position(). When an 
	**	expression E1/E2 or E1[E2] is evaluated, the context position in the 
	**	inner focus for an evaluation of E2 is the position of the context 
	**	item in the sequence obtained by evaluating E1. The position of the 
	**	first item in a sequence is always 1 (one). The context position is 
	**	always less than or equal to the context size. 
	*/
	uint32_t context_position;

	/*
	**	[Definition: The context size is the number of items in the sequence 
	**	of items currently being processed.] Its value is always an integer 
	**	greater than zero. The context size is returned by the expression 
	**	fn:last(). When an expression E1/E2 or E1[E2] is evaluated, the 
	**	context size in the inner focus for an evaluation of E2 is the number 
	**	of items in the sequence obtained by evaluating E1. 
	*/
	uint32_t context_size;

	/*
	**	[Definition: Variable values. This is a set of (expanded QName, value) 
	**	pairs. It contains the same expanded QNames as the in-scope variables 
	**	in the static context for the expression. The expanded QName is the 
	**	name of the variable and the value is the dynamic value of the 
	**	variable, which includes its dynamic type.] 
	*/
	map<qname,rchandle<value> > var_values;
	

	/*
	**	[Definition: Function implementations. Each function in function 
	**	signatures has a function implementation that enables the function to 
	**	map instances of its parameter types into an instance of its result 
	**	type. For a user-defined function, the function implementation is an 
	**	XQuery expression. For a built-in function or external function, the 
	**	function implementation is implementation-dependent.] 
	*/
	map<signature,function_impl> function_implementations;

	/*
	**	[Definition: Current dateTime. This information represents an 
	**	implementation-dependent point in time during the processing of a 
	**	query, and includes an explicit timezone. It can be retrieved by the 
	**	fn:current-dateTime function. If invoked multiple times during the 
	**	execution of a query, this function always returns the same result.] 
	*/
	time_t currtime;

	/*
	**	[Definition: Implicit timezone. This is the timezone to be used when a 
	**	date, time, or dateTime value that does not have a timezone is used in 
	**	a comparison or arithmetic operation. The implicit timezone is an 
	**	implementation-defined value of type xs:dayTimeDuration. See [XML 
	**	Schema] for the range of legal values of a timezone.] 
	*/
	int timezone;

	/*
	**	[Definition: Available documents. This is a mapping of strings onto 
	**	document nodes. The string represents the absolute URI of a resource. 
	**	The document node is the root of a tree that represents that resource 
	**	using the data model. The document node is returned by the fn:doc 
	**	function when applied to that URI.] The set of available documents is 
	**	not limited to the set of dynamically known documents, and it may be 
	**	empty. 
	*/
	map<std::string, rchandle<docnode> > available_documents;

	/*
	**	[Definition: Available collections. This is a mapping of strings onto 
	**	sequences of nodes. The string represents the absolute URI of a 
	**	resource. The sequence of nodes represents the result of the 
	**	fn:collection function when that URI is supplied as the argument. ] 
	**	The set of available collections is not limited to the set of 
	**	dynamically known collections, and it may be empty. 
	*/
	map<std::string, rchandle<nodeseq> > available_collections;

	/*
	**	[Definition: Default collection. This is the sequence of nodes that 
	**	would result from calling the fn:collection function with no 
	**	arguments.] The value of default collection may be initialized by the 
	**	implementation. 
	*/
	rchandle<nodeseq> default_collection;

};
