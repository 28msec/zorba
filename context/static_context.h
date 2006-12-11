/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: static_context.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_STATIC_CONTEXT_H
#define XQP_STATIC_CONTEXT_H

#include <map>
#include <vector>

#include "../types/qname.h"
#include "../types/collation.h"
#include "../types/builtin_types.h"

#include "../util/namespace_.h"
#include "../util/rchandle.h"
#include "../util/URI.h"


/*

	From the spec:

  #==============#==============#==============#==============#==============#==============#
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
  #--------------+--------------+--------------+--------------+--------------+--------------#

*/

namespace xqp {

class var_binding
{
protected:
	rchandle<QName> qname_h;
	static_type_t type;

public:
	var_binding();
	var_binding(
		rchandle<QName>,
		static_type_t);
	~var_binding() {}

public:
	rchandle<QName> get_qname() const { return qname_h; }
	static_type_t get_type() const { return type; }

};



class static_context : public rcobject
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

	typedef rchandle<QName> qname_t;
	typedef rchandle<collation> collation_t;
	typedef std::vector<static_type_t> signature_t;
	typedef static_type_t return_type_t;

protected:	// state
	rchandle<static_context> parent;

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
  std::vector<namespace_> namespaces;

	/*
	**	[Definition: Default element/type namespace. This is a namespace URI 
	**	or "none". The namespace URI, if present, is used for any unprefixed 
	**	QName appearing in a position where an element or type name is 
	**	expected.] The URI value is whitespace normalized according to the 
	**	rules for the xs:anyURI type in [XML Schema]. 
	*/
	namespace_ default_elem_or_type_ns;

	/*
	**	[Definition: Default function namespace.  This is a namespace URI or 
	**	"none". The namespace URI, if present, is used for any unprefixed 
	**	QName appearing in a position where a function name is expected.] The 
	**	URI value is whitespace normalized according to the rules for the 
	**	xs:anyURI type in [XML Schema]. 
	*/
	namespace_ default_function_ns;

	/*
	**	[Definition: In-scope schema types. Each schema type definition is 
	**	identified either by an expanded QName  (for a named type) or by an 
	**	implementation-dependent type identifier (for an anonymous type). The 
	**	in-scope schema types include the predefined schema types described in 
	**	2.5.1 Predefined Schema Types. If the Schema Import Feature is 
	**	supported, in-scope schema types also include all type definitions 
	**	found in imported schemas. ] 
	*/
	std::vector<qname_t> in_scope_schema_types;

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
	std::vector<qname_t> in_scope_elem_decls;

	/*
	**	[Definition: In-scope attribute declarations. Each attribute 
	**	declaration is identified either by an expanded QName (for a top-level 
	**	attribute declaration) or by an implementation-dependent  attribute 
	**	identifier (for a local attribute declaration). If the Schema Import 
	**	Feature is supported, in-scope attribute declarations include all 
	**	attribute declarations found in imported schemas.] 
	*/
	std::vector<qname_t> in_scope_attr_decls;

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
	static_type_t context_item_type;

	/*
	**	[Definition: Statically known collations. This is an 
	**	implementation-defined set of (URI, collation) pairs. It defines the 
	**	names of the collations that are available for use in processing 
	**	queries and expressions.] [Definition: A collation is a specification 
	**	of the manner in which strings and URIs are compared and, by 
	**	extension, ordered. For a more complete definition of collation, see 
	**	[XQuery 1.0 and XPath 2.0 Functions and Operators].] 
	*/
	std::vector<collation_t> collations;

	/*
	**	[Definition: Default collation. This identifies one of the collations 
	**	in statically known collations as the collation to be used by 
	**	functions and operators for comparing and ordering values of type 
	**	xs:string and xs:anyURI  (and types derived from them) when no 
	**	explicit collation is specified.] 
	*/
	collation_t default_collation;

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
	URI base_uri;

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
	std::map<signature_t,return_type_t> funmap;

	/*
	**	[Definition: Statically known documents. This is a mapping from 
	**	strings onto types. The string represents the absolute URI of a 
	**	resource that is potentially available using the fn:doc function. The 
	**	type is the static type of a call to fn:doc with the given URI as its 
	**	literal argument. ] If the argument to fn:doc is a string literal that 
	**	is not present in statically known documents, then the static type of 
	**	fn:doc is document-node()?. 
	**
	**	Note: The purpose of the statically known documents is to provide 
	**	static type information, not to determine which documents are 
	**	available. A URI need not be found in the statically known documents 
	**	to be accessed using fn:doc. 
	*/
	std::map<URI,static_type_t> known_documents;

	/*
	**	[Definition: Statically known collections. This is a mapping from 
	**	strings onto types. The string represents the absolute URI of a 
	**	resource that is potentially available using the fn:collection 
	**	function. The type is the type of the sequence of nodes that would 
	**	result from calling the fn:collection function with this URI as its 
	**	argument.] If the argument to fn:collection is a string literal that 
	**	is not present in statically known collections, then the static type 
	**	of fn:collection is node()*. 
	**
	**	Note: The purpose of the statically known collections is to provide 
	**	static type information, not to determine which collections are 
	**	available. A URI need not be found in the statically known collections 
	**	to be accessed using fn:collection. 
	*/
	std::map<URI,static_type_t> known_collections;

	/*
	**	[Definition: Statically known default collection type. This is the 
	**	type of the sequence of nodes that would result from calling the 
	**	fn:collection function with no arguments.] Unless initialized to some 
	**	other value by an implementation, the value of statically known 
	**	default collection type is node()*. 
	*/
	std::map<URI,static_type_t> known_collection_types;


public:	// manipulators
  std::vector<namespace_> get_namespaces() const { return namespaces; }
	namespace_ get_default_elem_or_type_ns() const { return default_elem_or_type_ns; }
	namespace_ get_default_function_ns() const { return default_function_ns; }
	std::vector<qname_t>get_in_scope_schema_types() const { return in_scope_schema_types; }
	std::vector<qname_t> get_in_scope_elem_decls() const { return in_scope_elem_decls; }
	std::vector<qname_t> get_in_scope_attr_decls() const { return in_scope_attr_decls; }
	std::vector<var_binding> get_in_scope_vars() const { return in_scope_vars; }
	static_type_t get_context_item_type() const { return context_item_type; }
	std::vector<collation_t> get_collations() const { return collations; }
	collation_t get_default_collation() const { return default_collation; }
	enum construction_mode_t get_construction_mode() const { return construction_mode; }
	enum ordering_mode_t get_ordering_mode() const { return ordering_mode; }
	enum order_empty_mode_t get_order_empty_mode() const { return order_empty_mode; }
	enum boundary_space_mode_t get_boundary_space_mode() const { return boundary_space_mode; }
	enum copy_ns_mode_t get_copy_ns_mode() const { return copy_ns_mode; }
	URI get_base_uri() const { return base_uri; }

	return_type_t get_fun(signature_t) const;
	static_type_t get_document_type(URI doc_uri) const;
	static_type_t get_collection_type(URI collect_uri) const;

};


}	/* namespace xqp */
#endif	/* XQP_STATIC_CONTEXT_H */
