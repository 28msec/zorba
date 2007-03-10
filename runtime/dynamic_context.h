/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dynamic_context.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_DYNAMIC_CONTEXT_H
#define XQP_DYNAMIC_CONTEXT_H

#include "../runtime/iterator.h"
#include "../functions/function_impl.h"
#include "../types/collation.h"
#include "../types/base_types.h"
#include "../values/qname_value.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

namespace xqp {


/*______________________________________________________________________
|  
|	XQuery 1.0 dynamic context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class dynamic_context : public rcobject
{
protected:

	rchandle<dynamic_context> parent;
	
	/*
	**	Definition: The context item is the item currently being processed. An 
	**	item is either an atomic value or a node.][Definition: When the 
	**	context item is a node, it can also be referred to as the context 
	**	node.] The context item is returned by an expression consisting of a 
	**	single dot (.). When an expression E1/E2 or E1[E2] is evaluated, each 
	**	item in the sequence obtained by evaluating E1 becomes the context 
	**	item in the inner focus for an evaluation of E2.
	*/
	item const* context_item;

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
	hashmap<rchandle<item_iterator> > var_values;
	
	/*
	**	[Definition: Function implementations. Each function in function 
	**	signatures has a function implementation that enables the function to 
	**	map instances of its parameter types into an instance of its result 
	**	type. For a user-defined function, the function implementation is an 
	**	XQuery expression. For a built-in function or external function, the 
	**	function implementation is implementation-dependent.] 
	*/
	hashmap<function_impl> function_implementations;

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
	hashmap<rchandle<item_iterator> > available_documents;

	/*
	**	[Definition: Available collections. This is a mapping of strings onto 
	**	sequences of nodes. The string represents the absolute URI of a 
	**	resource. The sequence of nodes represents the result of the 
	**	fn:collection function when that URI is supplied as the argument. ] 
	**	The set of available collections is not limited to the set of 
	**	dynamically known collections, and it may be empty. 
	*/
	hashmap<rchandle<item_iterator> > available_collections;

	/*
	**	[Definition: Default collection. This is the sequence of nodes that 
	**	would result from calling the fn:collection function with no 
	**	arguments.] The value of default collection may be initialized by the 
	**	implementation. 
	*/
	rchandle<item_iterator> default_collection;
	
	
public:	
  item const* get_context_item() const { return context_item; }
	uint32_t get_context_position() const { return context_position; }
	uint32_t get_context_size() const { return context_size; }
	time_t get_currtime() const { return currtime; }
	int get_timezone() const { return timezone; }
		
	rchandle<item_iterator> get_var_value(QName const&)
		const throw (xqp_exception);
	rchandle<function_impl> get_function(signature const&)
		const throw (xqp_exception);
	rchandle<item_iterator> get_document(std::string const&)
		const throw (xqp_exception);
	rchandle<item_iterator> get_collection(std::string const&)
		const throw (xqp_exception);
	rchandle<item_iterator> get_default_collection()
	const throw (xqp_exception);
	
	
public:     // diagnostic flags
  enum diagnostic_flag_t {
    trace_functions   = 1,
    trace_timing      = 2,
    trace_all         = 4
  };
	
protected:  // diagnostic context

  uint32_t lineno;
  uint32_t charpos;
  //rchandle<expr> source_expr;
  uint32_t diagnostics;
};


}	/* namespace xqp */
#endif /*	XQP_CONTEXT_H */



/*
	Appendix: C Context Components,
	From the spec ("XQuery 1.0: An XML Query Language",
	[http://www.w3.org/TR/xquery/#id-xq-context-components]):

  #=========================================================================================#
  |              |              |              |              |              |              |
  | Component    | Default      | (overwrite,  | (overwrite,  | Scope        | Consistency  |
  |              | init value   |    augment)  |    augment)  |              | rules        |
  |              |              | by impl      | by query     |              |              |
	|==============#==============#==============#==============#==============#==============|
  | XPath 1.0    | 'false'      | (no,no)      | (no,no)      | global       | must be      |
  | compatibility|              |              |              |              | 'false'      |
  | mode         |              |              |              |              |              |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Statically   | fn,xml,xs    | (yes,yes)    | (yes,yes)    | lexical      | only one ns  |
  | known ns     | xsi,local    | except for   | by prolog    |              | per prefix   |
  |              |              | 'xml'        | or elem cons |              | per lexical  |
  |              |              |              |              |              | scope        |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Default      |'no namespace'| (yes,no)     | (yes,no)     | lexical      | only one     |
  | element/type |              |              | by prolog    |              | default ns   |
  | ns           |              |              | or elem cons |              | per lexical  |
  |              |              |              |              |              | scope        |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Default      | fn           | (yes,no)     | (yes,no)     | module       | none         |
  | function ns  |              | note: dis-   | by prolog    |              |              |
  |              |              | recommended  |              |              |              |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | In-scope     | built-in     | (no,yes)     | (no,yes)     | module       | one def per  |
  | schema types | types in xs  |              | by schema    |              | global or    |
  |              |              |              | import in    |              | local type   |
  |              |              |              | prolog       |              |              |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | In-scope     | none         | (no,yes)     | (no,yes)     | module       | one def per  |
  | elem decls   |              |              | by schema    |              | global or    |
  |              |              |              | import in    |              | local elem   |
  |              |              |              | prolog       |              | name         |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | In-scope     | none         | (no,yes)     | (no,yes)     | module       | one def per  |
  | attr decls   |              |              | by schema    |              | global or    |
  |              |              |              | import in    |              | local attr   |
  |              |              |              | prolog       |              | name         |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | In-scope     | none         | (no,yes)     | (yes,yes)    | lexical      | one def per  |
  | variable     |              |              | by prolog    |              | variable     |
  |              |              |              | and var-     |              | per lexical  |
  |              |              |              | binding expr |              | scope        |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Context item | none         | (yes,no)     | (no,no)      | lexical      | none         |
  | static type  | (raises      |              | but can be   |              |              |
  |              | error on     |              | 'influenced' |              |              |
  |              | access)      |              | by exprs.    |              |              |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Function     | functions    | (no,yes)     | (no,yes)     | module       | unique per   |
  | signatures   | in 'fn' ns;  |              | by module    |              | expanded     |
  |              | constructors |              | import and   |              | QName + arg  |
  |              | built-in     |              | fun decl in  |              | count        |
  |              | atomic types |              | prolog       |              |              |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Statically   | default      | (no,yes)     | (no,no)      | module       | unique per   |
  | known        | collation    |              |              |              | collation    |
  | collations   |              |              |              |              | URI          |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Default      | Unicode      | (yes,no)     | (yes,no)     | module       | none         |
  | collation    | codepoint    |              | by prolog    |              |              |
  |              | collation    |              |              |              |              |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Construction | 'preserve'   | (yes,no)     | (yes,no)     | module       | 'preserve'   |
  | mode         |              |              | by prolog    |              | or           |
  |              |              |              |              |              | 'strip'      |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Ordering     | 'ordered'    | (yes,no)     | (yes,no)     | lexical      | 'ordered'    |
  | mode         |              |              | by prolog    |              | or           |
  |              |              |              | or expr      |              | 'unordered'  |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Default      | impl-        | (yes,no)     | (yes,no)     | module       | 'greatest'   |
  | order for    |  defined     |              | by prolog    |              | or           |
  | empty seq.   |              |              |              |              | 'least'      |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Boundary     | 'strip'      | (yes,no)     | (yes,no)     | module       | 'preserve'   |
  | space        |              |              | by prolog    |              | or           |
  | policy       |              |              |              |              | 'strip'      |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Copy-ns      | 'inherit',   | (yes,no)     | (yes,no)     | module       | (no-)        |
  | mode         | 'preserve'   |              | by prolog    |              | 'inherit'    |
  |              |              |              |              |              | or           |
  |              |              |              |              |              | 'preserve'   |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Base URI     | none         | (yes,no)     | (yes,no)     | module       | valid        |
  |              |              |              | by prolog    |              | lexical      |
  |              |              |              |              |              | rep. of      |
  |              |              |              |              |              | xs:anyURI    |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Statically   | none         | (no,yes)     | (no,no)      | module       | none         |
  | known        |              |              |              |              |              |
  | documents    |              |              |              |              |              |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Statically   | none         | (no,yes)     | (no,no)      | module       | none         |
  | known        |              |              |              |              |              |
  | collections  |              |              |              |              |              |
  |--------------+--------------+--------------+--------------+--------------+--------------|
  | Statically   | 'node()*'    | (no,yes)     | (no,no)      | module       | none         |
  | known        |              |              |              |              |              |
  | collection   |              |              |              |              |              |
  | types        |              |              |              |              |              |
  #-----------------------------------------------------------------------------------------#

*/

