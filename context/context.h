/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: context.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_CONTEXT_H
#define XQP_CONTEXT_H

#include "namespace.h"

#include "../functions/function_impl.h"
#include "../runtime/item_iterator.h"
#include "../types/types.h"
#include "../types/collation.h"
#include "../types/qname.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"
#include "../values/values.h"

#include <vector>

namespace xqp {

class document_node;
class collection_node;
class function_impl;

class var_binding
{
protected:
	qnameid qid;
	item_type vartype;

public:
	var_binding();
	var_binding(rchandle<QName>, item_type const&);
	~var_binding() {}

public:
	rchandle<QName> get_qname() const { return qnameid::get_qname(qid); }
	item_type get_type() const { return vartype; }

};


/*______________________________________________________________________
|  
|	XQuery 1.0 static context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class context : public rcobject
{
public:	// types
	enum construction_mode_t {
		cons_preserve,
		cons_strip
	};

	enum ordering_mode_t {
		ordered,
		unordered
	};

	enum order_empty_mode_t {
		empty_greatest,
		empty_least
	};

	enum boundary_space_mode_t {
		preserve_space,
		strip_space
	};

	enum copy_ns_mode_t {
		inherit_ns,
		no_inherit_ns,
		preserve_ns,
		no_preserve_ns
	};

	typedef rchandle<QName> qname_h;
	typedef rchandle<collation> collation_h;
	
protected:	// XQuery 1.0 static context
	rchandle<context> parent;

	/*
	**	[Definition: Statically known namespaces. This is a set of (prefix, 
	**	URI) pairs that define all the namespaces that are known during static 
	**	processing of a given expression.] The URI value is whitespace 
	**	normalized according to the rules for the xs:anyURI type in [XML 
	**	Schema]. Note the difference between in-scope namespaces, which is a 
	**	dynamic property of an element node, and statically known namespaces, 
	**	which is a static property of an expression. 
	**
	**	Some namespaces are predefined; additional namespaces can be added to 
	**	the statically known namespaces by namespace declarations in a Prolog 
	**	and by namespace declaration attributes in direct element 
	**	constructors. 
	*/
  std::vector<name_space> namespaces;

	/*
	**	[Definition: Default element/type namespace. This is a namespace URI 
	**	or "none". The namespace URI, if present, is used for any unprefixed 
	**	QName appearing in a position where an element or type name is 
	**	expected.] The URI value is whitespace normalized according to the 
	**	rules for the xs:anyURI type in [XML Schema]. 
	*/
	name_space default_elem_or_type_ns;

	/*
	**	[Definition: Default function namespace.  This is a namespace URI or 
	**	"none". The namespace URI, if present, is used for any unprefixed 
	**	QName appearing in a position where a function name is expected.] The 
	**	URI value is whitespace normalized according to the rules for the 
	**	xs:anyURI type in [XML Schema]. 
	*/
	name_space default_function_ns;

	/*
	**	[Definition: In-scope schema types. Each schema type definition is 
	**	identified either by an expanded QName  (for a named type) or by an 
	**	implementation-dependent type identifier (for an anonymous type). The 
	**	in-scope schema types include the predefined schema types described in 
	**	2.5.1 Predefined Schema Types. If the Schema Import Feature is 
	**	supported, in-scope schema types also include all type definitions 
	**	found in imported schemas. ] 
	*/
	std::vector<qname_h> in_scope_schema_types;

	/*
	**	[Definition: In-scope element declarations. Each element declaration 
	**	is identified either by an expanded QName (for a top-level element 
	**	declaration) or by an implementation-dependent  element identifier 
	**	(for a local element declaration). If the Schema Import Feature is 
	**	supported, in-scope element declarations include all element 
	**	declarations found in imported schemas. ] An element declaration 
	**	includes information about the element's substitution group 
	**	affiliation. 
	*/
	std::vector<qname_h> in_scope_elem_decls;

	/*
	**	[Definition: In-scope attribute declarations. Each attribute 
	**	declaration is identified either by an expanded QName (for a top-level 
	**	attribute declaration) or by an implementation-dependent  attribute 
	**	identifier (for a local attribute declaration). If the Schema Import 
	**	Feature is supported, in-scope attribute declarations include all 
	**	attribute declarations found in imported schemas.] 
	*/
	std::vector<qname_h> in_scope_attr_decls;

	/*
	**	[Definition: In-scope variables. This is a set of (expanded QName, 
	**	type) pairs. It defines the set of variables that are available for 
	**	reference within an expression. The expanded QName is the name of the 
	**	variable, and the type is the static type of the variable.] 
	**
	**	Variable declarations in a Prolog are added to in-scope variables. An 
	**	expression that binds a variable (such as a let, for, some, or every 
	**	expression) extends the in-scope variables of its subexpressions with 
	**	the new bound variable and its type. Within a function declaration, 
	**	the in-scope variables are extended by the names and types of the 
	**	function parameters. 
	**
	**	The static type of a variable may be either declared in a query or (if 
	**	the Static Typing Feature is enabled) inferred by static type 
	**	inference rules as described in [XQuery 1.0 and XPath 2.0 Formal 
	**	Semantics]. 
	*/
	std::vector<var_binding> in_scope_vars;

	/*
	**	[Definition: Context item static type. This component defines the 
	**	static type of the context item within the scope of a given 
	**	expression.] 
	*/
	item_type context_item_type;

	/*
	**	[Definition: Statically known collations. This is an 
	**	implementation-defined set of (URI, collation) pairs. It defines the 
	**	names of the collations that are available for use in processing 
	**	queries and expressions.] [Definition: A collation is a specification 
	**	of the manner in which strings and URIs are compared and, by 
	**	extension, ordered. For a more complete definition of collation, see 
	**	[XQuery 1.0 and XPath 2.0 Functions and Operators].] 
	*/
	std::vector<collation_h> collations;

	/*
	**	[Definition: Default collation. This identifies one of the collations 
	**	in statically known collations as the collation to be used by 
	**	functions and operators for comparing and ordering values of type 
	**	xs:string and xs:anyURI  (and types derived from them) when no 
	**	explicit collation is specified.] 
	*/
	collation_h default_collation;

	/*
	**	[Definition: Construction mode. The construction mode governs the 
	**	behavior of element and document node constructors. If construction 
	**	mode is preserve, the type of a constructed element node is 
	**	xs:anyType, and all attribute and element nodes copied during node 
	**	construction retain their original types. If construction mode is 
	**	strip, the type of a constructed element node is xs:untyped; all 
	**	element nodes copied during node construction receive the type 
	**	xs:untyped, and all attribute nodes copied during node construction 
	**	receive the type xs:untypedAtomic.] 
	*/
	enum construction_mode_t construction_mode;

	/*
	**	[Definition: Ordering mode. Ordering mode, which has the value ordered 
	**	or unordered, affects the ordering of the result sequence returned by 
	**	certain path expressions, union, intersect, and except expressions, 
	**	and FLWOR expressions that have no order by clause.] Details are 
	**	provided in the descriptions of these expressions. 
	*/
	enum ordering_mode_t ordering_mode;

	/*
	**	[Definition: Default order for empty sequences. This component 
	**	controls the processing of empty sequences and NaN values as ordering 
	**	keys in an order by clause in a FLWOR expression, as described in 
	**	3.8.3 Order By and Return Clauses.] Its value may be greatest or 
	**	least. 
	*/
	enum order_empty_mode_t order_empty_mode;

	/*
	**	[Definition: Boundary-space policy. This component controls the 
	**	processing of boundary whitespace by direct element constructors, as 
	**	described in 3.7.1.4 Boundary Whitespace.] Its value may be preserve 
	**	or strip. 
	*/
	enum boundary_space_mode_t boundary_space_mode;

	/*
	**	[Definition: Copy-namespaces mode. This component controls the 
	**	namespace bindings that are assigned when an existing element node is 
	**	copied by an element constructor, as described in 3.7.1 Direct Element 
	**	Constructors. Its value consists of two parts: preserve or 
	**	no-preserve, and inherit or no-inherit.] 
	*/
	enum copy_ns_mode_t copy_ns_mode;

	/*
	**	[Definition: Base URI. This is an absolute URI, used when necessary in 
	**	the resolution of relative URIs (for example, by the fn:resolve-uri 
	**	function.)] The URI value is whitespace normalized according to the 
	**	rules for the xs:anyURI type in [XML Schema]. 
	*/
	std::string base_uri;

	/*
	**	[Definition: Function signatures. This component defines the set of 
	**	functions that are available to be called from within an expression. 
	**	Each function is uniquely identified by its expanded QName and its 
	**	arity (number of parameters).] In addition to the name and arity, each 
	**	function signature specifies the static types of the function 
	**	parameters and result. 
	**
	**	The function signatures include the signatures of constructor 
	**	functions, which are discussed in 3.12.5 Constructor Functions. 
	*/
	hashmap<std::string> signature_map;

	/*
	**	[Definition: Statically known documents. This is a mapping from 
	**	strings onto types. The string represents the absolute URI of a 
	**	resource that is potentially available using the fn:doc function. The 
	**	type is the static type of a call to fn:doc with the given URI as its 
	**	literal argument. ] 
	**
	**	Note: The purpose of the statically known documents is to provide 
	**	static type information, not to determine which documents are 
	**	available. A URI need not be found in the statically known documents 
	**	to be accessed using fn:doc. 
	*/
	hashmap<item_type> statically_known_documents;

	/*
	**	[Definition: Statically known collections. This is a mapping from 
	**	strings onto types. The string represents the absolute URI of a 
	**	resource that is potentially available using the fn:collection 
	**	function. The type is the type of the sequence of nodes that would 
	**	result from calling the fn:collection function with this URI as its 
	**	argument.]
	**
	**	Note: The purpose of the statically known collections is to provide 
	**	static type information, not to determine which collections are 
	**	available. A URI need not be found in the statically known collections 
	**	to be accessed using fn:collection. 
	*/
	hashmap<item_type> statically_known_collections;

	/*
	**	[Definition: Statically known default collection type. This is the 
	**	type of the sequence of nodes that would result from calling the 
	**	fn:collection function with no arguments.] Unless initialized to some 
	**	other value by an implementation, the value of statically known 
	**	default collection type is node()*. 
	*/
	hashmap<item_type> statically_known_collection_types;


public:	// manipulators
  std::vector<name_space> get_namespaces() const
		{ return namespaces; }
	name_space get_default_elem_or_type_ns() const
		{ return default_elem_or_type_ns; }
	name_space get_default_function_ns() const
		{ return default_function_ns; }
	std::vector<qname_h>get_in_scope_schema_types() const
		{ return in_scope_schema_types; }
	std::vector<qname_h> get_in_scope_elem_decls() const
		{ return in_scope_elem_decls; }
	std::vector<qname_h> get_in_scope_attr_decls() const
		{ return in_scope_attr_decls; }
	std::vector<var_binding> get_in_scope_vars() const
		{ return in_scope_vars; }
	item_type get_context_item_type() const
		{ return context_item_type; }
	std::vector<collation_h> get_collations() const
		{ return collations; }
	collation_h get_default_collation() const
		{ return default_collation; }
	enum construction_mode_t get_construction_mode() const
		{ return construction_mode; }
	enum ordering_mode_t get_ordering_mode() const
		{ return ordering_mode; }
	enum order_empty_mode_t get_order_empty_mode() const
		{ return order_empty_mode; }
	enum boundary_space_mode_t get_boundary_space_mode() const
		{ return boundary_space_mode; }
	enum copy_ns_mode_t get_copy_ns_mode() const
		{ return copy_ns_mode; }
	std::string get_base_uri() const
		{ return base_uri; }
	
	std::string get_function_type(QName const&, uint32_t arity) 
	 const throw (xqp_exception);
	item_type get_document_type(std::string const&) 
	  const throw (xqp_exception);
	item_type get_collection_type(std::string const&) 
	  const throw (xqp_exception);
	
	
protected:  // XQuery 1.0 dynamic context
	/*
	**	Definition: The context item is the item currently being processed. An 
	**	item is either an atomic value or a node.][Definition: When the 
	**	context item is a node, it can also be referred to as the context 
	**	node.] The context item is returned by an expression consisting of a 
	**	single dot (.). When an expression E1/E2 or E1[E2] is evaluated, each 
	**	item in the sequence obtained by evaluating E1 becomes the context 
	**	item in the inner focus for an evaluation of E2.
	*/
	rchandle<item> context_item_h;

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
	hashmap<var_binding> var_values;
	
	/*
	**	[Definition: Function implementations. Each function in function 
	**	signatures has a function implementation that enables the function to 
	**	map instances of its parameter types into an instance of its result 
	**	type. For a user-defined function, the function implementation is an 
	**	XQuery expression. For a built-in function or external function, the 
	**	function implementation is implementation-dependent.] 
	*/
	hashmap<function_impl const*> function_implementations;

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
	hashmap<document_node*> available_documents;

	/*
	**	[Definition: Available collections. This is a mapping of strings onto 
	**	sequences of nodes. The string represents the absolute URI of a 
	**	resource. The sequence of nodes represents the result of the 
	**	fn:collection function when that URI is supplied as the argument. ] 
	**	The set of available collections is not limited to the set of 
	**	dynamically known collections, and it may be empty. 
	*/
	hashmap<collection_node*> available_collections;

	/*
	**	[Definition: Default collection. This is the sequence of nodes that 
	**	would result from calling the fn:collection function with no 
	**	arguments.] The value of default collection may be initialized by the 
	**	implementation. 
	*/
	rchandle<collection_node> default_collection;
	
	
public:
  rchandle<item> get_context_item() const { return context_item_h; }
	uint32_t get_context_position() const { return context_position; }
	uint32_t get_context_size() const { return context_size; }
	time_t get_currtime() const { return currtime; }
	int get_timezone() const { return timezone; }
		
	item_iterator get_var_value(QName const&) const throw (xqp_exception);
	function_impl const* get_function(signature const&) const throw (xqp_exception);
	item_iterator get_document(std::string const&) const throw (xqp_exception);
	item_iterator get_collection(std::string const&) const throw (xqp_exception);
	item_iterator get_default_collection() const throw (xqp_exception);
	
	
public:     // diagnostic flags
  enum diagnostic_flag_t {
    trace_functions   = 1,
    trace_timing      = 2,
    trace_all         = 4
  };
	
protected:  // diagnostic context
  uint32_t lineno;
  uint32_t charpos;

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

