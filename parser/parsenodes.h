/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: parsenodes.h,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 */

#ifndef XQP_PARSENODES_H
#define XQP_PARSENODES_H

#ifdef __GNUC__
#pragma interface
#endif

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>

#include "../util/rchandle.h"

namespace xqp {


// three-valued boolean
enum Bool {
  falseBool,
  trueBool,
  indeterminateBool
};


static inline enum Bool 
not3(enum Bool b)
{
  switch (b) {
  case falseBool: return trueBool;
  case trueBool: return falseBool;
  default: return indeterminateBool;
  }
}


/*
**  base class: syntax-only nodes
*/
class parsenode : public rcobject
{
protected:
  uint32_t lineno;

public:
	parsenode(uint32_t _lineno) : lineno(_lineno) {}
	parsenode() {}
  ~parsenode() {}

public:
  inline uint32_t get_lineno() const { return lineno; }

};


/*
**  base class:  nodes with values.
*/
class exprnode : public rcobject
{
protected:
  uint32_t lineno;

public:
	exprnode(uint32_t _lineno) : lineno(_lineno) {}
	exprnode() {}
  ~exprnode() {}

public:
  inline uint32_t get_lineno() const { return lineno; }

};



class AbbrevForwardStep;
class AnyKindTest;
class AposAttrContentList;
class AposAttrValueContent;
class ArgList;
class AtomicType;
class AttribNameOrWildcard;
class AttributeDeclaration;
class AttributeName;
class AttributeTest;
class AxisStep;
class BaseURIDecl;
class BoundarySpaceDecl;
class CDataSection;
class CaseClause;
class CaseClauseList;
class CommentTest;
class CommonContent;
class ConstructionDecl;
class Constructor;
class CopyNamespacesDecl;
class DefaultCollationDecl;
class DefaultNamespaceDecl;
class DirAttr;
class DirAttributeList;
class DirAttributeValue;
class DirElemContent;
class DirElemContentList;
class DocumentTest;
class ElementDeclaration;
class ElementName;
class ElementNameOrWildcard;
class ElementTest;
class EmptyOrderDecl;
class ForLetClause;
class ForLetClauseList;
class ForwardAxis;
class ForwardStep;
class FunctionCall;
class FunctionDecl;
class Import;
class InheritMode;
class ItemType;
class KindTest;
class LetClause;
class LibraryModule;
class Literal;
class MainModule;
class Module;
class ModuleDecl;
class NameTest;
class NamespaceDecl;
class NodeTest;
class OccurrenceIndicator;
class OptionDecl;
class OrderByClause;
class OrderCollationSpec;
class OrderDirSpec;
class OrderModifier;
class OrderSpec;
class OrderSpecList;
class OrderingModeDecl;
class PITest;
class Param;
class ParamList;
class PositionalVar;
class Pragma;
class PragmaList;
class Predicate;
class PredicateList;
class PreserveMode;
class Prolog;
class QName;
class QVarInDecl;
class QVarInDeclList;
class QueryBody;
class QuoteAttrValueContent;
class QuoteAttrContentList;
class ReverseAxis;
class ReverseStep;
class SIND_DeclList;
class SIND_Decl;
class SchemaAttributeTest;
class SchemaElementTest;
class SchemaImport;
class SchemaPrefix;
class SequenceType;
class Setter;
class SignList;
class SingleType;
class TextTest;
class TypeDeclaration;
class TypeName;
class VarDecl;
class VarGetsDecl;
class VarInDecl;
class VarInDeclList;
class VarRef;
class VersionDecl;
class VFO_Decl;
class VFO_DeclList;
class WhereClause;
class Wildcard;




// [1] Module
// ----------
class Module : public parsenode
/*______________________________________________________________________
|
|	::= MainModule
|			| VersionDecl MainModule
|			| LibraryModule 
|			| VersionDecl LibraryModule 
|_______________________________________________________________________*/
{
protected:
	rchandle<static_context> static_context_h;
	rchandle<dynamic_context> dynamic_context_h;

public:
	Module(rchandle<static_context> static_context_h);
	~Module();

public:	//manipulators
	rchandle<static_context> get_static_context() const
		{	return static_context_h; }
	rchandle<dynamic_context> get_dynamic_context() const
		{	return dynamic_context_h; }

};


// [2] VersionDecl
// ---------------
class VersionDecl : public parsenode
/*______________________________________________________________________
|
|	::= XQUERY_VERSION  STRING_LITERAL  SEMI
|			| XQUERY_VERSION  STRING_LITERAL  ENCODING  STRING_LITERAL  SEMI
|_______________________________________________________________________*/
{
protected:
	std::string version;
	std::string encoding;

public:
	VersionDecl();
	~VersionDecl();

public:
	std::string get_version() const { return version; }
	std::string get_encoding() const { return encoding; }

};


// [3] MainModule
// --------------
class MainModule : public parsenode
/*______________________________________________________________________
|
|	::= Prolog  QueryBody
|_______________________________________________________________________*/
{
protected:
	rchandle<Prolog> prolog_h;
	rchandle<QueryBody> query_body_h;

public:
	MainModule();
	~MainModule();

public:
	rchandle<Prolog> get_prolog() const { return prolog_h; }
	rchandle<QueryBody> get_query_body() const { return query_body_h; }
};


// [4] LibraryModule
// -----------------
class LibraryModule : parsenode
/*______________________________________________________________________
|
|	::= ModuleDecl  Prolog
|_______________________________________________________________________*/
{
protected:
	rchandle<
	rchandle<

public:
	LibraryModule();
	~LibraryModule();

};


// [5] ModuleDecl
// --------------
/*______________________________________________________________________
|
| Module declaration serves to identify a module as a library module.
| 	
| A module declaration begins with the keyword module and contains a 
| namespace prefix and a URILiteral.  The URILiteral must be of nonzero 
| length [err:XQST0088]. The URILiteral identifies the target namespace 
| of the library module, which is the namespace for all variables and 
| functions exported by the library module. The name of every variable 
| and function declared in a library module must have a namespace URI 
| that is the same as the target namespace of the module; otherwise a 
| static error is raised [err:XQST0048]. In the statically known 
| namespaces of the library module, the namespace prefix specified in 
| the module declaration is bound to the module's target namespace. The 
| namespace prefix specified in a module declaration must not be xml or 
| xmlns [err:XQST0070]. 
| 
|_______________________________________________________________________*/
class ModuleDecl : public parsenode
/*______________________________________________________________________
|
|	::= MODULE_NAMESPACE  NCNAME  EQ  URI_LITERAL  SEMI
|_______________________________________________________________________*/
{
protected:
	std::string prefix;
	std::string target_namespace;

public:
	ModuleDecl();
	~ModuleDecl();

public:
	std::string get_prefix() const { return prefix; }
	std::string get_target_namespace() const { return target_namespace; }

};


// [6] Prolog
// ----------
/*
**	A Prolog is a series of declarations and imports that define the 
**	processing environment for the module that contains the Prolog.
**	
**	Each declaration or import is followed by a semicolon. A Prolog is 
**	organized into two parts.
**	
**	The first part of the Prolog (SIND_DeclList) consists of Setters, 
**	Imports, Namespace declarations, and Default namespace declarations.  
**	Setters are declarations that set the value of some property that 
**	affects query processing, such as construction mode, ordering mode, 
**	or default collation.  Namespace declarations and default namespace 
**	declarations affect the interpretation of QNames within the query.  
**	Imports are used to import definitions from schemas and modules.  
**	Each imported schema or module is identified by its target namespace, 
**	which is the namespace of the objects (such as elements or functions)
**	that are defined by the schema or module.
**	
**	The second part of the Prolog (VFO_DeclList) consists of declarations 
**	of Variables, Functions, and Options. These declarations appear at 
**	the end of the Prolog because they may be affected by declarations 
**	and imports in the first part of the Prolog.
*/

class Prolog : public parsenode
/*______________________________________________________________________
|
|	::= SIND_DeclList  VFO_DeclList
|_______________________________________________________________________*/
{
protected:
	rchandle<SIND_DeclList> sind_list_h;
	rchandle<VFO_DeclList> vfo_list_h;

public:
	Prolog();
	~Prolog();

public:

};



// [6a] SIDN_DeclList
// ------------------
/*
**	The first part of the Prolog: Setters, Imports, Namespace declarations,
**	and Default namespace declarations.  
*/
class SIND_DeclList : public parsenode
/*______________________________________________________________________
|
|	::= SIND_Decl | SIND_DeclList  SEMI  SIND_Decl
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<SIND_Decl> > sind_hv;

public:
	SIND_DeclList();
	SIND_DeclList(SIND_Decl*);
	~SIND_DeclList();

public:
	rchandle<SIND_Decl> operator[] (uint32_t k) const { return sind_hv[k]; }
	void push_back(SIND_Decl* sind_p) { sind_hv.push_back(sind_p); }

};



// [6b] VFO_DeclList
// -----------------
class VFO_DeclList : public parsenode
/*______________________________________________________________________
|
|	::= VFO_Decl | VFO_DeclList  SEMI  VFO_Decl
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<VFO_Decl> > vfo_hv;

public:
	VFO_DeclList();
	VFO_DeclList(VFO_Decl*);
	~VFO_DeclList();

public:
	VFO_Decl* operator[] (uint32_t k) const { return vfo_hv[k]; }
	void push_back(VFO_Decl* vfo_p) { vfo_hv.push_back(vfo_p); }

};



// [6c] SIND_Decl
// --------------
class SIND_Decl : public parsenode
/*______________________________________________________________________
|
|	::= Setter | Import | NamespaceDecl | DefaultNamespaceDecl
|_______________________________________________________________________*/
{
public:
	SIND_Decl();
	~SIND_Decl();

};



// [6d] VFO_Decl
// -------------
class VFO_Decl : public parsenode
/*______________________________________________________________________
|
|	::= VarDecl | FunctionDecl | OptionDecl
|_______________________________________________________________________*/
{
public:
	VFO_Decl();
	~VFO_Decl();

};



// [7] Setter
// ----------
class Setter : public SIND_Decl
/*______________________________________________________________________
|
|	::= BoundarySpaceDecl | DefaultCollationDecl | BaseURIDecl
|			| ConstructionDecl | OrderingModeDecl | EmptyOrderDecl
|			| CopyNamespacesDecl
|_______________________________________________________________________*/
{
public:
	Setter();
	~Setter();

};



// [8] Import
// ----------
class Import : public SIND_Decl
/*______________________________________________________________________
|
|	::= SchemaImport | ModuleImport
|_______________________________________________________________________*/
{
public:
	Import();
	~Import();

};



// [9] Separator
// -------------
// (Lexical rule)



// [10] NamespaceDecl
// ------------------
/*
**	[Definition: A namespace declaration declares a namespace prefix and 
**	associates it with a namespace URI, adding the (prefix, URI) pair to 
**	the set of statically known namespaces.] The namespace declaration is 
**	in scope throughout the query in which it is declared, unless it is 
**	overridden by a namespace declaration attribute in a direct element 
**	constructor.
**	
**	If the URILiteral part of a namespace declaration is a zero-length 
**	string, any existing namespace binding for the given prefix is removed 
**	from the statically known namespaces. This feature provides a way to 
**	remove predeclared namespace prefixes such as local.
*/
class NamespaceDecl : public SIND_Decl
/*______________________________________________________________________
|
|	::= DECLARE_NAMESPACE  NCNAME  EQ  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string prefix;
	std::string uri;

public:
	NamespaceDecl();
	NamespaceDecl(std::string const& _prefix, std::string const& _uri);
	~NamespaceDecl();

public:
	std::string get_prefix() const
		{ return prefix; }
	std::string get_uri() const
		{ return uri; }

};



// [11] BoundarySpaceDecl
// ----------------------
/*
**	[Definition: A boundary-space declaration sets the boundary-space 
**	policy in the static context, overriding any implementation-defined 
**	default. Boundary-space policy controls whether boundary whitespace is 
**	preserved by element constructors during processing of the query.] If 
**	boundary-space policy is preserve, boundary whitespace is preserved. 
**	If boundary-space policy is strip, boundary whitespace is stripped 
**	(deleted). 
*/
class BoundarySpaceDecl : public SIND_Decl
/*______________________________________________________________________
|
|	::= DECLARE_BOUNDARY_SPACE  ( PRESERVE | STRIP )
|_______________________________________________________________________*/
{
protected:
	static_context::boundaryspace_mode mode;

public:
	BoundarySpaceDecl();
	BoundarySpaceDecl(static_context::boundaryspace_mode _mode);
	~BoundarySpaceDecl();

public:
	static_context::boundaryspace_mode get_boundaryspace_mode() const
		{ return mode; }

};


// [12] DefaultNamespaceDecl
// -------------------------
/*
**	A default element/type namespace declaration declares a namespace URI 
**	that is associated with unprefixed names of elements and types. This 
**	declaration is recorded as the default element/type namespace in the 
**	static context. A Prolog may contain at most one default element/type 
**	namespace declaration [err:XQST0066]. If the URILiteral in a default 
**	element/type namespace declaration is a zero-length string, the 
**	default element/type namespace is undeclared (set to "none"), and 
**	unprefixed names of elements and types are considered to be in no 
**	namespace.
**	
**	A default element/type namespace declaration may be overridden by a 
**	namespace declaration attribute in a direct element constructor.
**	
**	If no default element/type namespace declaration is present, 
**	unprefixed element and type names are in no namespace (however, an 
**	implementation may define a different default as specified in C.1 
**	Static Context Components.)
**	
**	A default function namespace declaration declares a namespace URI that 
**	is associated with unprefixed function names in function calls and 
**	function declarations. This declaration is recorded as the default 
**	function namespace in the static context. A Prolog may contain at most 
**	one default function namespace declaration [err:XQST0066]. If the 
**	StringLiteral in a default function namespace declaration is a 
**	zero-length string, the default function namespace is undeclared (set 
**	to "none"). In that case, any functions that are associated with a 
**	namespace can be called only by using an explicit namespace prefix.
**	
**	If no default function namespace declaration is present, the default 
**	function namespace is the namespace of XPath/XQuery functions, 
**	http://www.w3.org/2005/xpath-functions (however, an implementation may 
**	define a different default as specified in C.1 Static Context 
**	Components.)
**
**	The effect of declaring a default function namespace is that all 
**	functions in the default function namespace, including 
**	implicitly-declared constructor functions, can be invoked without 
**	specifying a namespace prefix. When a function call uses a function 
**	name with no prefix, the local name of the function must match a 
**	function (including implicitly-declared constructor functions) in the 
**	default function namespace [err:XPST0017].
**
**	Note: Only constructor functions can be in no namespace.
**
**	Unprefixed attribute names and variable names are in no namespace.
*/
class DefaultNamespaceDecl : public SIND_Decl
/*______________________________________________________________________
|
|	::= DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
|			| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string default_element_namespace;
	std::string default_function_namespace;

public:
	DefaultNamespaceDecl();
	DefaultNamespaceDecl(
		std::string const& _default_element_namespace,
		std::string const& _default_function_namespace);
	~DefaultNamespaceDecl();

public:
	std::string get_default_element_namespace() const
		{ return default_element_namespace; }
	std::string get_default_function_namespace() const
		{ return default_function_namespace; }

};



// [13] OptionDecl
// ---------------
/*
**	[Definition: An option declaration declares an option that affects the 
**	behavior of a particular implementation. Each option consists of an 
**	identifying QName and a StringLiteral.]
*/
class OptionDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_OPTION  QNAME  STRING_LITERAL
|
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> qname_h;
	std::string val;

public:
	OptionDecl();
	OptionDecl(handle<QName> _name_h, std::string const& _val);
	~OptionDecl();

public:
	rchandle<QName> get_qname() const { return name_p; }
	std::string get_val() const { return val; }
};



// [14] OrderingModeDecl
// ---------------------
/*
**	[Definition: An ordering mode declaration sets the ordering mode in 
**	the static context, overriding any implementation-defined default.] 
**	This ordering mode applies to all expressions in a module (including 
**	both the Prolog and the Query Body, if any), unless overridden by an 
**	ordered or unordered expression.
**	
**	Ordering mode affects the behavior of path expressions that include a 
**	"/" or "//" operator or an axis step; union, intersect, and except 
**	expressions; and FLWOR expressions that have no order by clause.  If 
**	ordering mode is ordered, node sequences returned by path, union, 
**	intersect, and except expressions are in document order; otherwise the 
**	order of these return sequences is implementation-dependent.  The 
**	effect of ordering mode on FLWOR expressions is described in #3.8 FLWOR 
**	Expressions.
**
**	If a Prolog contains more than one ordering mode declaration, a static 
**	error is raised [err:XQST0065].
*/
class OrderingModeDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_ORDERING  ( ORDERED | UNORDERED )
|_______________________________________________________________________*/
{
protected:
	static_context::ordering_mode mode;
		
public:
	OrderingModeDecl();
	OrderingModeDecl(static_context::ordering_mode _mode);
	~OrderingModeDecl();
	
public:
	static_context::ordering_mode get_ordering_mode() const
		{ return mode; }

};



// [15] EmptyOrderDecl
// -------------------
/*
**	[Definition: An empty order declaration sets the default order for 
**	empty sequences in the static context, overriding any 
**	implementation-defined default.  This declaration controls the 
**	processing of empty sequences and NaN values as ordering keys in an 
**	order by clause in a FLWOR expression.]  An individual order by clause 
**	may override the default order for empty sequences by specifying empty 
**	greatest or empty least.
**
**	If a Prolog contains more than one empty order declaration, a static 
**	error is raised [err:XQST0069].
*/
class EmptyOrderDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
|			|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
|_______________________________________________________________________*/
{
protected:
	static_context::empty_order_mode mode;

public:
	EmptyOrderDecl();
	EmptyOrderDecl(static_context::empty_order_mode _mode);
	~EmptyOrderDecl();
	
public:
	static_context::empty_order_mode get_mode() const
		{ return mode; }

};



// [16] CopyNamespacesDecl
// -----------------------
/*
**	[Definition: A copy-namespaces declaration sets the value of 
**	copy-namespaces mode in the static context, overriding any 
**	implementation-defined default. Copy-namespaces mode controls the 
**	namespace bindings that are assigned when an existing element node is 
**	copied by an element constructor.] Handling of namespace bindings by 
**	element constructors is described in 3.7.1 Direct Element 
**	Constructors.
**
**	If a Prolog contains more than one copy-namespaces declaration, a 
**	static error is raised [err:XQST0055].
*/
class CopyNamespacesDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_COPY_NAMESPACES  PreserveMode  COMMA  InheritMode
|_______________________________________________________________________*/
{
protected:
	static_context::copy_ns_mode mode;

public:
	CopyNamespacesDecl();
	~CopyNamespacesDecl();

};



// [17] PreserveMode
// -----------------
class PreserveMode : public parsenode
/*______________________________________________________________________
|
|	::=	PRESERVE | NO_PRESERVE
|_______________________________________________________________________*/
{
protected:
	static_context::preserve_mode mode;

public:
	PreserveMode();
	~PreserveMode();

};



// [18] InheritMode
// ----------------
class InheritMode : public parsenode
/*______________________________________________________________________
|
|	::= INHERIT | NO_INHERIT
|_______________________________________________________________________*/
{
public:
	static_context::inherit_mode mode;
	
public:
	InheritMode();
	~InheritMode();

};



// [19] DefaultCollationDecl
// -------------------------
class DefaultCollationDecl : public parsenode
/*______________________________________________________________________
|
|	::=	DECLARE_DEFAULT_COLLATION  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string collation;

public:
	DefaultCollationDecl();
	~DefaultCollationDecl();

};



// [20] BaseURIDecl
// ----------------
class BaseURIDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_BASE_URI  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string base_uri;

public:
	BaseURIDecl();
	~BaseURIDecl();

};



// [21] SchemaImport
// -----------------
class SchemaImport : public parsenode
/*______________________________________________________________________
|
|	::= IMPORT_SCHEMA  URI_LITERAL
|			| IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL
|			|	IMPORT_SCHEMA  URI_LITERAL  AT  URI_LITERALList
|			|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT  URI_LITERALList
|_______________________________________________________________________*/
{
protected:
	rchandle<SchemaPrefix> prefix_h;
	std::string schema_uri;
	rchandle<URI_LITERALList> uri_list_h;

public:
	SchemaImport();
	~SchemaImport();

};



// [21a] URLLiteralList
// --------------------
class URI_LITERALList : public parsenode
/*______________________________________________________________________
|
|	::= URI_LITERAL
|			| URI_LITERALList  COMMA  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::vector<std::string> uri_v;

public:
	URI_LITERALList();
	~URI_LITERALList();

};



// [22] SchemaPrefix
// -----------------
class SchemaPrefix : public parsenode
/*______________________________________________________________________
|
|	::= NAMESPACE  NCNAME  EQ
|			|	DEFAULT_ELEMENT  NAMESPACE
|_______________________________________________________________________*/
{
protected:
	std::string prefix;
	bool default_b;

public:
	SchemaPrefix();
	~SchemaPrefix();

};



// [23] ModuleImport
// -----------------
class ModuleImport : public parsenode
/*______________________________________________________________________
|
|	::= IMPORT_MODULE  URI_LITERAL 
|			|	IMPORT_MODULE  NAMESPACE  NCNAME  EQ  URI_LITERAL
|			|	IMPORT_MODULE  URI_LITERAL  AT  URI_LITERALList
|			|	IMPORT_MODULE  NAMESPACE  NCNAME  EQ  URI_LITERAL  AT  URI_LITERALList
|_______________________________________________________________________*/
{
protected:
	std::string prefix;
	std::string uri;
	rchandle<URI_LITERALList> uri_list_h;

public:
	ModuleImport();
	~ModuleImport();

};



// [24] VarDecl
// ------------
class VarDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_VARIABLE_DOLLAR  VARNAME  GETS  ExprSingle
|			|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
|			|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
|			|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
|_______________________________________________________________________*/
{
protected:
	std::string varname;
	rchandle<TypeDeclaration> typedecl_h;
	rchandle<ExprSingle> initval_h;
	bool extern_b;

public:
	VarDecl();
	~VarDecl();

};



// [25] ConstructionDecl
// ---------------------
class ConstructionDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_CONSTRUCTION  PRESERVE
|			|	DECLARE_CONSTRUCTION  STRIP
|_______________________________________________________________________*/
{
public:
	ConstructionDecl();
	~ConstructionDecl();

};



// [26] FunctionDecl
// -----------------
class FunctionDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_FUNCTION  QNAME  LPAR  RPAR  EXTERNAL
|			|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  EnclosedExpr
|			|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  EXTERNAL
|			|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  EnclosedExpr
|			|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  AS  SequenceType  EXTERNAL
|			|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  AS  SequenceType  EnclosedExpr
|			|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  AS  SequenceType  EXTERNAL
|			|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  AS  SequenceType  EnclosedExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> name_h;
	rchandle<ParamList> paramlist_h;
	rchandle<ExclosedExpr> body_h;
	rchandle<SequenceType> return_type_h;
	bool extern_b;

public:
	FunctionDecl();
	~FunctionDecl();

};



// [27] ParamList
// --------------
class ParamList : public parsenode
/*______________________________________________________________________
|
|	::= Param
|			|	ParamList  COMMA  Param
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<Param> > param_hv;

public:
	ParamList();
	~ParamList();

};



// [28] Param
// ----------
class Param : public parsenode
/*______________________________________________________________________
|
|	::= DOLLAR  VARNAME
|			|	DOLLAR  VARNAME  TypeDeclaration
|_______________________________________________________________________*/
{
protected:
	std::string name;
	rchandle<TypeDeclaration> typedecl_h;

public:
	Param();
	~Param();

};



// [29] EnclosedExpr
// -----------------
class EnclosedExpr : public exprnode
/*______________________________________________________________________
|
|	::= LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	EnclosedExpr();
	~EnclosedExpr();

};



// [30] QueryBody
// --------------
class QueryBody : public exprnode
/*______________________________________________________________________
|
|	::= Expr
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	QueryBody();
	~QueryBody();

};



// [31] Expr
// ---------
class Expr : public exprnode
/*______________________________________________________________________
|
|	::= ExprSingle 
|			|	Expr  COMMA  ExprSingle
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<ExprSingle> > expr_single_hv;

public:
	Expr();
	~Expr();

};



// [32] ExprSingle
// ---------------
class ExprSingle : public exprnode
/*______________________________________________________________________
|
|	::= FLWORExpr
|			|	QuantifiedExpr
|			|	TypeswitchExpr
|			|	IfExpr
|			|	OrExpr
|_______________________________________________________________________*/
{
public:
	ExprSingle();
	~ExprSingle();

};



// [33] FLWORExpr
// --------------
class FLWORExpr : public ExprSingle
/*______________________________________________________________________
|
|	::= ForLetClauseList  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  RETURN  ExprSingle
|			|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
|_______________________________________________________________________*/
{
	rchandle<ForLetClauseList> forlet_list_h;
	rchandle<WhereClause> where_h;
	rchandle<OrderByClause> orderby_h;
	rchandle<ExprSingle> return_val_h;

public:
	FLWORExpr();
	~FLWORExpr();

};



// [33a] ForLetClauseList
// ----------------------
class ForLetClauseList : public parsenode
/*______________________________________________________________________
|
|	::= ForLetClause
|			|	ForLetClause  ForLetClauseList
|_______________________________________________________________________*/
{
protected:
	std:vector<rchandle<ForLetClause> > forlet_hv;

public:
	ForLetClauseList();
	~ForLetClauseList();

};



// [33b] ForLetClause
// ------------------
class ForLetClause : public parsenode
/*______________________________________________________________________
|
|	::= ForClause | LetClause
|_______________________________________________________________________*/
{
public:
	ForLetClause();
	~ForLetClause();

};



// [34] ForClause
// --------------
class ForClause : public ForLetClause
/*______________________________________________________________________
|
|	::= FOR_DOLLAR  VarInDeclList
|_______________________________________________________________________*/
{
protected:
	rchandle<VarInDeclList> vardecl_list_h;

public:
	ForClause();
	~ForClause();

};



// [34a] VarInDeclList
// -------------------
class VarInDeclList : public parsenode
/*______________________________________________________________________
|
|	::= VarInDecl
|			|	VarInDeclList  COMMA  DOLLAR  VarInDecl
|_______________________________________________________________________*/
{
protected:
	std::vector<VarInDecl> vardecl_hv;

public:
	VarInDeclList();
	~VarInDeclList();

};



// [34b] VarInDecl
// ---------------
class VarInDecl : public parsenode
/*______________________________________________________________________
|
|	::= VARNAME  IN  ExprSingle
|			|	VARNAME  TypeDeclaration  IN  ExprSingle
|			|	VARNAME  PositionalVar  IN  ExprSingle
|			|	VARNAME  TypeDeclaration  PositionalVar  IN  ExprSingle
|	(ft extensions)
|			| VARNAME  FTScoreVar  IN  ExprSingle
|			| VARNAME  TypeDeclaration  FTScoreVar  IN  ExprSingle
|			| VARNAME  PositionalVar  FTScoreVar  IN  ExprSingle
|			| VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  IN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	std::string varname;
	rchandle<TypeDeclaration> typedecl_h;
	rchandle<PositionalVar> posvar_h;
	rchandle<FTScoreVar> ftscorevar_h;
	rchandle<ExprSingle> val_h;
	
public:
	VarInDecl();
	~VarInDecl();

};



// [35] PositionalVar
// ------------------
class PositionalVar : public parsenode
/*______________________________________________________________________
|
|	::= AT  DOLLAR  VARNAME
|_______________________________________________________________________*/
{
protected:
	std::string varname;

public:
	PositionalVar();
	~PositionalVar();

};



// [36] LetClause
// --------------
class LetClause : public parsenode
/*______________________________________________________________________
|
|	::= LET_DOLLAR VarGetsDeclList
|_______________________________________________________________________*/
{
protected:
	rchandle<VarGetsDeclList> vardecl_list_h;

public:
	LetClause();
	~LetClause();

};



// [36a] VarGetsDeclList
// ---------------------
class VarGetsDeclList : public parsenode
/*______________________________________________________________________
|
|	::= VarGetsDecl
|			|	VarGetsDeclList  COMMA  DOLLAR  VarGetsDecl
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<VarGetsDecl> > vardecl_hv;

public:
	VarGetsDeclList();
	~VarGetsDeclList();

};



// [36b] VarGetsDecl
// ------------------
class VarGetsDecl : public parsenode
/*______________________________________________________________________
|
|	::= VARNAME  GETS  ExprSingle
|			|	VARNAME  TypeDeclaration  GETS  ExprSingle
|	(ft extensions)
|			| VARNAME  FTScoreVar  GETS  ExprSingle
|			| VARNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
|_______________________________________________________________________*/
{
protected:
	std::string varname;
	rchandle<TypeDeclaration> typedecl_h;
	rchandle<FTScoreVar> scorevar_h;
	rchandle<ExprSingle> val_h;

public:
	VarGetsDecl();
	~VarGetsDecl();

};



// [37] WhereClause
// ----------------
class WhereClause : public parsenode
/*______________________________________________________________________
|
|	::= WHERE  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<ExprSingle> predicate_h;

public:
	WhereClause();
	~WhereClause();

};



// [38] OrderByClause
// ------------------
class OrderByClause : public parsenode
/*______________________________________________________________________
|
|	::= ORDER_BY  OrderSpecList
|			|	STABLE_ORDER_BY  OrderSpecList
|_______________________________________________________________________*/
{
protected:
	rchandle<OrderSpecList> spec_list_h;
	bool stable_b;
		
public:
	OrderByClause();
	~OrderByClause();

};



// [39] OrderSpecList
// ------------------
class OrderSpecList : public parsenode
/*______________________________________________________________________
|
|	::= OrderSpec 
|			|	OrderSpecList  COMMA  OrderSpec
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<OrderSpec> > spec_hv;

public:
	OrderSpecList();
	~OrderSpecList();

};



// [40] OrderSpec
// --------------
class OrderSpec : public parsenode
/*______________________________________________________________________
|
|	::= ExprSingle
|			|	ExprSingle OrderModifier
|_______________________________________________________________________*/
{
protected:
	rchandle<ExprSingle> spec_h;
	rchandle<OrderModifier> modifier_h;

public:
	OrderSpec();
	~OrderSpec();

};



// [41] OrderModifier
// ------------------
class OrderModifier : public parsenode
/*______________________________________________________________________
|
|	::= OrderDirSpec
|			|	OrderEmptySpec
|			|	OrderCollationSpec
|			|	OrderDirSpec  OrderEmptySpec
|			|	OrderDirSpec  OrderCollationSpec
|			|	OrderEmptySpec  OrderCollationSpec
|			|	OrderDirSpec  OrderEmptySpec  OrderCollationSpec
|_______________________________________________________________________*/
{
protected:
	rchandle<OrderDirSpec> dir_spec_h;
	rchandle<OrderEmptySpec> empty_spec_h;
	rchandle<OrderCollationSpec> collation_spec_h;

public:
	OrderModifier();
	~OrderModifier();

};



// [41a] OrderDirSpec
// ------------------
class OrderDirSpec : public OrderModifier
/*______________________________________________________________________
|
|	::= ASCENDING
|			|	DESCENDING
|_______________________________________________________________________*/
{
public:
	enum dir_spec_t {
		ascending,
		descending
	};

protected:
	enum dir_spec_t dir_spec;

public:
	OrderDirSpec();
	~OrderDirSpec();
	
};



// [41b] OrderEmptySpec
// --------------------
class OrderEmptySpec : public OrderModifier
/*______________________________________________________________________
|
|	::= EMPTY_GREATEST
|			|	EMPTY_LEAST
|_______________________________________________________________________*/
{
protected:
	static_context::empty_order_mode empty_order_spec;

public:
	OrderEmptySpec();
	~OrderEmptySpec();

};



// [41c] OrderCollationSpec
// ------------------------
class OrderCollationSpec : public OrderModifier
/*______________________________________________________________________
|
|	::= COLLATION  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string uri;

public:
	OrderCollationSpec();
	~OrderCollationSpec();

};


// [42] QuantifiedExpr 	   
// -------------------
class QuantifiedExpr : public exprnode
/*______________________________________________________________________
|
|	::= SOME_DOLLAR  QVarInDeclList
|			|	EVERY_DOLLAR  QVarInDeclList
|_______________________________________________________________________*/
{
public:
	enum quantification_mode_t {
		some,
		every
	};

protected:
	quantification_mode_t qmode;
	rchandle<QVarInDeclList> qvar_decl_list_h;

public:
	QuantifiedExpr();
	~QuantifiedExpr();

};


// [42a] QVarInDeclList
// --------------------
class QVarInDeclList : public parsenode
/*______________________________________________________________________
|
|	:= QVarInDecl
|			|	QVarInDeclList  COMMA  DOLLAR  QVarInDecl
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<QVarInDecl> > qvar_decl_hv;

public:
	QVarInDeclList();
	~QVarInDeclList();

};


// [42b] QVarInDecl
// ----------------
class QVarInDecl : public parsenode
/*______________________________________________________________________
|
|	::= VARNAME  IN  ExprSingle 
|			|	VARNAME  TypeDeclaration  IN  ExprSingle 
|_______________________________________________________________________*/
{
protected:
	std::string name;
	rchandle<TypeDeclaration> typedecl_h;
	rchandle<ExprSingle> val_h;

public:
	QVarInDecl();
	~QVarInDecl();

};


// [43] TypeswitchExpr
// -------------------
class TypeswitchExpr : public exprnode
/*______________________________________________________________________
|
|	::= TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
|			|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT 
|					DOLLAR  VARNAME  RETURN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> switch_expr_h;
	rchandle<CaseClauseList> clause_list_h;
	std::string default_varname;
	rchandle<ExprSingle> default_clause_h;

public:
	TypeswitchExpr();
	~TypeswitchExpr();

};


// [43a] CaseClauseList
// --------------------
class CaseClauseList : public parsenode
/*______________________________________________________________________
|
|	::= CaseClause
|			|	CaseClauseList  CaseClause
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<CaseClause> > clause_hv;

public:
	CaseClauseList();
	~CaseClauseList();

};


// [44] CaseClause
// ---------------
class CaseClause : public parsenode
/*______________________________________________________________________
|
|	::= CASE  SequenceType  RETURN  ExprSingle
|			| CASE  DOLLAR  VARNAME  AS  SequenceType  RETURN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	std::string varname;
	rchandle<SequenceType> type_h;
	rchandle<ExprSingle> val_h;

public:
	CaseClause();
	~CaseClause();

};


// [45] IfExpr
// -----------
class IfExpr : public exprnode
/*______________________________________________________________________
|
|	::= IF_LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> cond_expr_h;
	rchandle<ExprSingle> then_expr_h;
	rchandle<ExprSingle> else_expr_h;

public:
	IfExpr();
	~IfExpr();

};


// [46] OrExpr
// -----------
class OrExpr : public exprnode
/*______________________________________________________________________
|
|	::= AndExpr
|			|	OrExpr  OR  AndExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<AndExpr> and_expr_h;
	rchandle<OrExpr> or_expr_h;

public:
	OrExpr();
	~OrExpr();
};


// [47] AndExpr
// ------------
class AndExpr : public exprnode
/*______________________________________________________________________
|
|	::= ComparisonExpr
|			|	AndExpr  AND  ComparisonExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<ComparisonExpr> comp_expr_h;
	rchandle<AndExpr> and_expr_h;

public:
	AndExpr();
	~AndExpr();

};


// [48] ComparisonExpr
// -------------------
class ComparisonExpr : public exprnode
/*______________________________________________________________________
|
|		::= FTContainsExpr
|			| FTContainsExpr ValueComp FTContainsExpr
|			| FTContainsExpr GeneralComp FTContainsExpr
|			| FTContainsExpr NodeComp FTContainsExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<FTContainsExpr> left_h;
	rchandle<FTContainsExpr> right_h;
	rchandle<ValueComp> valcomp_h;
	rchandle<ValueComp> gencomp_h;
	rchandle<ValueComp> nodecomp_h;

public:
	ComparisonExpr();
	~ComparisonExpr();

};


// [48a] FTContainsExpr
// --------------------
class FTContainsExpr : public exprnode
/*______________________________________________________________________
|
|	::= RangeExpr
|			| RangeExpr  FTCONTAINS  FTSelection
|			| RangeExpr  FTCONTAINS  FTSelection  FTIgnoreOption
|_______________________________________________________________________*/
{
protected:
	rchandle<RangeExpr> range_expr_h;
	rchandle<FTSelection> ftselect_h;
	rchandle<FTIgnoreOption> ftignore_h;

public:
	ValueCompExpr();
	~ValueCompExpr();

};



// [49] RangeExpr
// --------------
class RangeExpr : public exprnode
/*______________________________________________________________________
|
|	::= AdditiveExpr
|			|	AdditiveExpr  TO  AdditiveExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<AdditiveExpr> from_expr_h;
	rchandle<AdditiveExpr> to_expr_h;

public:
	RangeExpr();
	~RangeExpr();

};


// [50] AdditiveExpr
// -----------------
class AdditiveExpr : public exprnode
/*______________________________________________________________________
|
|	::= MultiplicativeExpr
|			|	AdditiveExpr  PLUS  MultiplicativeExpr
|			|	AdditiveExpr  MINUS  MultiplicativeExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<MultiplicativeExpr> mult_expr_h;
	rchandle<AdditiveExpr> add_expr_h;

public:
	AdditiveExpr();
	~AdditiveExpr();

};


// [51] MultiplicativeExpr
// -----------------------
class MultiplicativeExpr : public exprnode
/*______________________________________________________________________
|
|	::= UnionExpr
|			|	MultiplicativeExpr  STAR  UnionExpr
|			|	MultiplicativeExpr  DIV  UnionExpr
|			|	MultiplicativeExpr  IDIV  UnionExpr
|			|	MultiplicativeExpr  MOD  UnionExpr
|_______________________________________________________________________*/
{
public:
	enum mult_op_t {
		times,
		div,
		idiv,
		mod
	};

protected:
	rchandle<MultiplicativeExpr> union_expr_h;
	rchandle<AdditiveExpr> mult_expr_h;
	enum mult_op_t op;

public:
	MultiplicativeExpr();
	~MultiplicativeExpr();

};


// [52] UnionExpr
// --------------
class UnionExpr : public parsenode
/*______________________________________________________________________
|
|	::= IntersectExceptExpr
|			|	UnionExpr  UNION  IntersectExceptExpr
|			|	UnionExpr  VBAR  IntersectExceptExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<IntersectExceptExpr> intex_expr_h;
	rchandle<AdditiveExpr> union_expr_h;

public:
	UnionExpr();
	~UnionExpr();

};


// [53] IntersectExceptExpr
// ------------------------
class IntersectExceptExpr : public parsenode
/*______________________________________________________________________
|
|	::= InstanceofExpr
|			|	IntersectExceptExpr  INTERSECT  InstanceofExpr
|			|	IntersectExceptExpr  EXCEPT  InstanceofExpr
|_______________________________________________________________________*/
{
	enum intex_op_t {
		intersect,
		except	
	};

protected:
	rchandle<InstanceofExpr> instof_expr_h;
	rchandle<IntersectExceptExpr> intex_expr_h;
	enum mult_op_t op;

public:
	IntersectExceptExpr();
	~IntersectExceptExpr();

};


// [54] InstanceofExpr
// -------------------
class InstanceofExpr : public exprnode
/*______________________________________________________________________
|
|	::= TreatExpr
|			|	TreatExpr  INSTANCE_OF  SequenceType
|_______________________________________________________________________*/
{
protected:
	rchandle<TreatExpr> treat_expr_h;
	rchandle<SequenceType> seqtype_h;

public:
	InstanceofExpr();
	~InstanceofExpr();

};


// [55] TreatExpr
// --------------
class TreatExpr : public exprnode
/*______________________________________________________________________
|
|	::= CastableExpr
|			|	CastableExpr  TREAT_AS  SequenceType
|_______________________________________________________________________*/
{
protected:
	rchandle<CastableExpr> treat_expr_h;
	rchandle<SequenceType> seqtype_h;

public:
	TreatExpr();
	~TreatExpr();

};


// [56] CastableExpr
// -----------------
class CastableExpr : public exprnode
/*______________________________________________________________________
|
|	::= CastExpr
|			|	CastExpr  CASTABLE_AS  SingleType
|_______________________________________________________________________*/
{
protected:
	rchandle<CastExpr> cast_expr_h;
	rchandle<SingleType> singletype_h;

public:
	CastableExpr();
	~CastableExpr();

};


// [57] CastExpr 	   
// -------------
class CastExpr : public exprnode
/*______________________________________________________________________
|
|	::= UnaryExpr
|			|	UnaryExpr  CAST_AS  SingleType
|_______________________________________________________________________*/
{
protected:
	rchandle<UnaryExpr> unary_expr_h;
	rchandle<SingleType> singletype_h;

public:
	CastExpr();
	~CastExpr();

};


// [58] UnaryExpr
// --------------
class UnaryExpr : public exprnode
/*______________________________________________________________________
|
|	::= ValueExpr
|			|	SignList  ValueExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<ValueExpr> value_expr_h;
	rchandle<SignList> signlist_h;

public:
	UnaryExpr();
	~UnaryExpr();

};


// [58a] SignList
// --------------
class SignList : public parsenode
/*______________________________________________________________________
|
|	::= PLUS
|			|	MINUS
|			|	SignList  PLUS
|			|	SignList  MINUS
|_______________________________________________________________________*/
{
protected:
	vector<bool> signv;

public:
	SignList();
	~SignList();

};


// [59] ValueExpr
// --------------
class ValueExpr : public exprnode
/*______________________________________________________________________
|
|	::= ValidateExpr
|			|	PathExpr
|			|	ExtensionExpr
|_______________________________________________________________________*/
{
public:
	ValueExpr();
	~ValueExpr();

};



// [60] GeneralComp
// ----------------
class GeneralComp : public parsenode
/*______________________________________________________________________
|
|	::= EQUALS | NE | LT | LE | GT | GE
|_______________________________________________________________________*/
{
public:
	enum gencomp_t {
		eq,
		ne,
		lt,
		le,
		gt,
		ge
	};

protected:
	enum gencomp_t type;

public:
	GeneralComp();
	~GeneralComp();

};



// [61] ValueComp
// --------------
class ValueComp : public parsenode
/*______________________________________________________________________
|
|	::= VAL_EQ | VAL_NE | VAL_LT | VAL_LE | VAL_GT | VAL_GE
|_______________________________________________________________________*/
{
public:
	enum valcomp_t {
		val_eq,
		val_ne,
		val_lt,
		val_le,
		val_gt,
		val_ge
	};

protected:
	enum valcomp_t type;

public:
	ValueComp();
	~ValueComp();

};



// [62] NodeComp
// -------------
class NodeComp : public parsenode
/*______________________________________________________________________
|
|	::= IS | PRECEDES | FOLLOWS
|_______________________________________________________________________*/
{
public:
	enum nodecomp_t {
		is,
		precedes,
		follows	
	};

protected:
	enum nodecomp_t type;

public:
	NodeComp();
	~NodeComp();

};



// [63] ValidateExpr
// -----------------
class ValidateExpr : public exprnode
/*______________________________________________________________________
|
|	::= VALIDATE_LBRACE  Expr  RBRACE
|			|	VALIDATE_MODE  LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;
	validatemode_t valmode;

public:
	ValidateExpr();
	~ValidateExpr();

};


// [64] ExtensionExpr
// ------------------
class ExtensionExpr : public exprnode
/*______________________________________________________________________
|
|	::= PragmaList  LBRACE  RBRACE
|			|	PragmaList  LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<PragmaList> pragma_list_h;
	rchandle<Expr> expr_h;

public:
	ExtensionExpr();
	~ExtensionExpr();

};


// [64a] PragmaList
// ----------------
class PragmaList : public parsenode
/*______________________________________________________________________
|
|	::= Pragma | PragmaList  Pragma
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<Pragma> > pragma_hv;

public:
	PragmaList();
	~PragmaList();

};


// [65] Pragma
// -----------
class Pragma : public parsenode
/*______________________________________________________________________
|
|	::= PRAGMA_BEGIN  QNAME  PRAGMA_LITERAL  PRAGMA_END   ws:explicit
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> name;
	std::string pragma_lit;

public:
	Pragma();
	~Pragma();

};


// [66] PragmaContents
// -------------------
/* folded into [65] */


/*
* Constraint: leading-lone-slash
*
* A single slash may appear either as a complete path expression or as the first
* part of a path expression in which it is followed by a RelativePathExpr, which
* can take the form of a NameTest ("*" or a QName). In contexts where operators
* like "*", "union", etc., can occur, parsers may have difficulty distinguishing
* operators from NameTests. For example, without lookahead the first part of the
* expression "/ * 5", for example is easily taken to be a complete expression,
* "/ *", which has a very different interpretation (the child nodes of "/").
* 
* To reduce the need for lookahead, therefore, if the token immediately following
* a slash is "*" or a keyword, then the slash must be the beginning, but not the
* entirety, of a PathExpr (and the following token must be a NameTest, not an
* operator).
* 
* A single slash may be used as the left-hand argument of an operator by
* parenthesizing it: (/) * 5. The expression 5 * /, on the other hand, is legal
* without parentheses.
*/

// [67] PathExpr
// -------------
class PathExpr : public exprnode
/*______________________________________________________________________
|
|	::= LEADING_LONE_SLASH
|			|	SLASH  RelativePathExpr
|			|	SLASH_SLASH  RelativePathExpr
|			|	RelativePathExpr	 	 gn:leading-lone-slashXQ
|_______________________________________________________________________*/
{
public:
	enum pathtype_t {
		leading_lone,
		leading_slash,
		leading_slashslash,
		relative
	};

protected:
	enum pathtype_t type;
	rchandle<RelatvePathExpr> relpath_expr_h;

public:
	PathExpr();
	~PathExpr();

};


// [68] RelativePathExpr
// ---------------------
class RelativePathExpr : public exprnode
/*______________________________________________________________________
|
|	::= StepExpr
|			|	RelativePathExpr SLASH  StepExpr
|			|	RelativePathExpr SLASH_SLASH  StepExpr
|_______________________________________________________________________*/
{
public:
	enum steptype_t {
		child,
		descendant
	};

protected:
	rchandle<RelativePathExpr> relpath_expr_h;
	rchandle<StepExpr> step_expr_h;

public:
	RelativePathExpr();
	~RelativePathExpr();

};



// [69] StepExpr
// -------------
class StepExpr : public exprnode
/*______________________________________________________________________
|
|	::= AxisStep
|			|	FilterExpr
|_______________________________________________________________________*/
{
public:
	StepExpr();
	~StepExpr();

};



// [70] AxisStep
// -------------
class AxisStep : public exprnode
/*______________________________________________________________________
|
|	::= ForwardStep  PredicateList
|			|	ReverseStep  PredicateList
|_______________________________________________________________________*/
{
protected:
	rchandle<ForwardStep> forward_step_h;
	rchandle<ReverseStep> reverse_step_h;
	rchandle<PredicateList> predicate_list_h;

public:
	AxisStep();
	~AxisStep();

};



// [71] ForwardStep
// ----------------
class ForwardStep : public parsenode
/*______________________________________________________________________
|
|	::= ForwardAxis  NodeTest
|			|	AbbrevForwardStep
|_______________________________________________________________________*/
{
protected:
	rchandle<ForwardAxis> forward_axis_h;
	rchandle<NodeTest> node_test_h;
	rchandle<AbbreviatedForwardStep> abbrev_step_h;

public:
	ForwardStep();
	~ForwardStep();

};



// [72] ForwardAxis
// ----------------
class ForwardAxis : public parsenode
/*______________________________________________________________________
|
|	::= CHILD_AXIS
|			| DESCENDANT_AXIS
|			| ATTRIBUTE_AXIS
|			| SELF_AXIS
|			| DESCENDANT_OR_SELF_AXIS
|			| FOLLOWING_SIBLING_AXIS
|			| FOLLOWING_AXIS
|_______________________________________________________________________*/
{
public:
	enum forward_axis_t {
		child,
		descendant,
		attribute,
		self,
		descendant_or_self,
		following_sibling,
		folowing
	};

protected:
	enum forward_axis_t axis;

public:
	ForwardAxis();
	~ForwardAxis();

};



// [73] AbbrevForwardStep
// ----------------------
class AbbrevForwardStep : public parsenode
/*______________________________________________________________________
|
|	::= NodeTest
|			|	AT_SIGN  NodeTest
|_______________________________________________________________________*/
{
proteced:
	rchandle<NodeTest> node_test_h;
	bool attr_b;
	
public:
	AbbrevForwardStep();
	~AbbrevForwardStep();

};



// [74] ReverseStep
// ----------------
class ReverseStep : public parsenode
/*______________________________________________________________________
|
|	::= ReverseAxis  NodeTest
|			|	DOT_DOT
|_______________________________________________________________________*/
{
protected:
	rchandle<ReverseAxis> axis_h;
	rchandle<NodeTest> node_test_h;

public:
	ReverseStep();
	~ReverseStep();

};



// [75] ReverseAxis
// ----------------
class ReverseAxis : public parsenode
/*______________________________________________________________________
|
|	::= PARENT_AXIS
|			| ANCESTOR_AXIS
|			| PRECEDING_SIBLING_AXIS
|			| PRECEDING_AXIS
|			| ANCESTOR_OR_SELF_AXIS
|_______________________________________________________________________*/
{
public:
	enum reverse_axis_t {
		parent,
		ancestor,
		preceding_sibling,
		preceding,
		ancestor_or_self
	};

protected:
	enum reverse_axis_t axis;

public:
	ReverseAxis();
	~ReverseAxis();

};



// [76] AbbrevReverseStep
// ----------------------
/* folded into [74] */



// [77] NodeTest
// -------------
class NodeTest : public parsenode
/*______________________________________________________________________
|
|	::= KindTest | NameTest
|_______________________________________________________________________*/
{
public:
	NodeTest();
	~NodeTest();

};
 


// [78] NameTest
// -------------
class NameTest : public parsenode
/*______________________________________________________________________
|
|	::= QNAME | Wildcard
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> qname_h;
	rchandle<WildCard> wild_h;

public:
	NameTest();
	~NameTest();

};



// [79] Wildcard
// -------------
class Wildcard : public parsenode
/*______________________________________________________________________
|
|	::= STAR
|			|	ELEM_WILDCARD
|			|	PREFIX_WILDCARD    ws:explicitXQ
|_______________________________________________________________________*/
{
public:
	enum wildcard_t {
		all,
		elem,
		prefix
	};

protected:
	enum wildcard_t type;
	std::string prefix;
	rchandle<QName> qname_h;
	
public:
	Wildcard();
	~Wildcard();

};



// [80] FilterExpr
// ---------------
class FilterExpr : public exprnode
/*______________________________________________________________________
|
|	::= PrimaryExpr  PredicateList
|_______________________________________________________________________*/
{
protected:
	rchandle<PrimaryExpr> primary_h;
	rchandle<PredicateList> pred_list_h;

public:
	FilterExpr();
	~FilterExpr();

};



// [81] PredicateList
// ------------------
class PredicateList : public parsenode
/*______________________________________________________________________
|
|	::= Predicate
|			|	PredicateList  Predicate
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<Predicate> > pred_hv;

public:
	PredicateList();
	~PredicateList();

};



// [82] Predicate
// --------------
class Predicate : public exprnode
/*______________________________________________________________________
|
|	::= LBRACK  Expr  RBRACK
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> pred_h;

public:
	Predicate();
	~Predicate();

};



// [83] PrimaryExpr
// ----------------
class PrimaryExpr : public exprnode
/*______________________________________________________________________
|
|	::= Literal
|			|	VarRef
|			|	ParenthesizedExpr
|			|	ContextItemExpr
|			|	FunctionCall
|			|	Constructor
|			|	OrderedExpr
|			|	UnorderedExpr
|_______________________________________________________________________*/
{
public:
	PrimaryExpr();
	~PrimaryExpr();

};



// [84] Literal
// ------------
class Literal : public exprnode
/*______________________________________________________________________
|
|	::= NumericLiteral | StringLiteral
|_______________________________________________________________________*/
{
public:
	Literal();
	~Literal();

};



// [85] NumericLiteral
// -------------------
class NumericLiteral : public exprnode
/*______________________________________________________________________
|
|	::= INTEGER_LITERAL
|			|	DECIMAL_LITERAL
|			|	DOUBLE_LITERAL
|_______________________________________________________________________*/
{
public:
	enum numeric_t {
		integer,
		decimal,
		double
	};

protected:
	enum numeric_t type;
	int ival;
	double dval;

public:
	NumericLiteral();
	~NumericLiteral();

};



// [86] VarRef
// -----------
class VarRef : public parsenode
/*______________________________________________________________________
|
|	::= DOLLAR  VARNAME
|_______________________________________________________________________*/
{
protected:
	std::string varname;

public:
	VarRef();
	~VarRef();

};



// [87] ParenthesizedExpr
// ----------------------
class ParenthesizedExpr : public parsenode
/*______________________________________________________________________
|
|	::= LPAR  RPAR
|			|	LPAR  Expr  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	ParenthesizedExpr();
	~ParenthesizedExpr();

};	



// [88] ContextItemExpr
// --------------------
class ContextItemExpr : public exprnode
/*______________________________________________________________________
|
|	::= DOT
|_______________________________________________________________________*/
{
public:
	ContextItemExpr();
	~ContextItemExpr();

};	



// [89] OrderedExpr
// ----------------
class OrderedExpr : public exprnode
/*______________________________________________________________________
|
|	::= ORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	OrderedExpr();
	~OrderedExpr();

};



// [90] UnorderedExpr
// ------------------
class UnorderedExpr : public exprnode
/*______________________________________________________________________
|
|	::= UNORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	UnorderedExpr();
	~UnorderedExpr();

};



// [91] FunctionCall
// -----------------
class FunctionCall : public exprnode
/*______________________________________________________________________
|
|	::= QNAME  LPAR  ArgList  RPAR 	
|																	gn:parensXQ
|			 														gn:reserved-function-namesXQ 
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> fname_h;
	rchandle<ArgList> arg_list_h;

public:
	FunctionCall();
	~FunctionCall();

};



// [91a] ArgList
// -------------
class ArgList : public parsenode
/*______________________________________________________________________
|
|	::= ExprSingle | ArgList  COMMA  ExprSingle
|_______________________________________________________________________*/
{
protected:
	std::vector<ExprSingle> arg_hv;

public:
	ArgList();
	~ArgList();

};



// [92] Constructor
// ----------------
class Constructor : public exprnode
/*______________________________________________________________________
|
|	::= DirectConstructor |	ComputedConstructor
|_______________________________________________________________________*/
{
public:
	Constructor();
	~Constructor();

};



// [93] DirectConstructor
// ----------------------
class DirectConstructor : public exprnode
/*______________________________________________________________________
|
|	::= DirElemConstructor
|			|	DirCommentConstructor
|			|	DirPIConstructor
|_______________________________________________________________________*/
{
public:
	DirectConstructor();
	~DirectConstructor();

};

 

// [94] DirElemConstructor
// -----------------------
class DirElemConstructor : public parsenode
/*______________________________________________________________________
|
|	::= LT  QNAME  DirAttributeList SGT
|					 ws:explicitXQ
|			|	LT  QNAME  DirAttributeList GT  DirElemContentList  LTS  QNAME  GT
|					 ws:explicitXQ,  gn:ltXQ
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> elem_name_h;
	rchandle<DirAttributeList> attr_list_h;
	rchandle<DirElemContentList> dir_content_list_h;

public:
	DirElemConstructor();
	~DirElemConstructor();

};



// [94a] DirElemContentList
// ------------------------
class DirElemContentList : public parsenode
/*______________________________________________________________________
|
|	::= DirElemContent
|			|	DirElemContentList  DirElemContent
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<DirElemeContent> > dir_content_hv;

public:
	DirElemContentList();
	~DirElemContentList();

};



// [95] DirAttributeList
// ---------------------
class DirAttributeList : public parsenode
/*______________________________________________________________________
|
|	::= DirAttr
|			|	DirAttributeList  DirAttr
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<DirAttr> > dir_attr_hv;

public:
	DirAttributeList();
	~DirAttributeList();

};



// [95a] DirAttr
// -------------
class DirAttr : public parsenode
/*______________________________________________________________________
|
|	::= QNAME  EQUALS  DirAttributeValue 	 ws:explicitXQ
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> atname_h;
	rchandle<DirAttributeValue> dir_atval_h;
	
public:
	DirAttr();
	~DirAttr();

};



// [96] DirAttributeValue
// ----------------------
class DirAttributeValue : public parsenode
/*______________________________________________________________________
|
|	::= QUOTE  QuoteAttrContentList  QUOTE
|			|	APOS  AposAttrContentList  APOS 	 ws:explicitXQ
|_______________________________________________________________________*/
{
protected:
	rchandle<QuoteAttrContentList> quot_attr_content_h;
	rchandle<AposContentList> apos_attr_content_h;

public:
	DirAttributeValue();
	~DirAttributeValue();

};



// [96a] QuoteAttrContentList
// --------------------------
class QuoteAttrContentList : public parsenode
/*______________________________________________________________________
|
|	::= ESCAPE_QUOTE
|			|	QuoteAttrValueContent
|			|	QuoteAttrContentList  ESCAPE_QUOTE
|			|	QuoteAttrContentList  QuoteAttrValueContent
|_______________________________________________________________________*/
{
protected:
	std::vector<QuoteAttrValueContent> quot_atval_content_hv;
	
public:
	QuoteAttrContentList();
	~QuoteAttrContentList();

};



// [96b] AposAttrContentList
// -------------------------
class AposAttrContentList : public parsenode
/*______________________________________________________________________
|
|	::= ESCAPE_APOS
|			|	AposAttrValueContent
|			|	AposAttrContentList  ESCAPE_APOS
|			|	AposAttrContentList  AposAttrValueContent
|_______________________________________________________________________*/
{
protected:
	std::vector<AposAttrValueContent> apos_atval_content_hv;
	
public:
	AposAttrContentList();
	~AposAttrContentList();

};



// [97] QuotAttrValueContent
// -------------------------
class QuoteAttrValueContent : public parsenode
/*______________________________________________________________________
|
|	::= QUOTE_ATTR_CONTENT
|			|	CommonContent
|_______________________________________________________________________*/
{
protected:
	std:string quot_atcontent_h;
	rchandle<CommonContent> common_content_h;

public:
	QuoteAttrValueContent();
	~QuoteAttrValueContent();

};



// [98] AposAttrValueContent
// -------------------------
class AposAttrValueContent : public parsenode
/*______________________________________________________________________
|
|	::= APOS_ATTR_CONTENT
|			|	CommonContent
|_______________________________________________________________________*/
{
protected:
	std:string apos_atcontent_h;
	rchandle<CommonContent> common_content_h;

public:
	AposAttrValueContent();
	~AposAttrValueContent();

};



// [99] DirElemContent
// -------------------
class DirElemContent : public exprnode
/*______________________________________________________________________
|
|	::= DirectConstructor
|			|	ELEMENT_CONTENT
|			|	CDataSection
|			|	CommonContent
|_______________________________________________________________________*/
{
protected:
	std::string elem_content;

public:
	DirElemContent();
	~DirElemContent();

};



// [100] CommonContent
// -------------------
class CommonContent : public exprnode
/*______________________________________________________________________
|
|	::= ENTITY_REF
|			|	CHAR_REF_LITERAL
|			|	DOUBLE_LBRACE
|			|	DOUBLE_RBRACE
|			|	EnclosedExpr
|_______________________________________________________________________*/
{
public:
	enum common_content_t {
		entity,
		charref,
		escape_lbrace,
		escape_rbrace,
		expr
	};

protected:
	enum common_content_t type;
	std::string entity_ref;
	std::string char_ref;
	rchandle<EnclosedExpr> expr_h;

public:
	CommonContent();
	~CommonContent();

};



// [101] DirCommentConstructor
// ---------------------------
class DirCommentConstructor : public exprnode
/*______________________________________________________________________
|
|	::= COMMENT_BEGIN  EXPR_COMMENT_LITERAL  COMMENT_END 	 ws:explicitXQ
|_______________________________________________________________________*/
{
protected:
	std::string comment;

public:
	DirCommentConstructor();
	~DirCommentConstructor();

};



// [102] DirCommentContents
// ------------------------
/* lexical rule */



// [103] DirPIConstructor
// ----------------------
class DirPIConstructor : public exprnode
/*______________________________________________________________________
|
|	::= PI_BEGIN  PI_TARGET  PI_END    ws:explicitXQ
|			|	PI_BEGIN  PI_TARGET  CHAR_LITERAL  PI_END	   ws:explicitXQ
|_______________________________________________________________________*/
{
protected:
	std::string pi_target;
	std::string pi_content;

public:
	DirPIConstructor();
	~DirPIConstructor();

};



// [104] DirPIContents
// -------------------
/* lexical rule */



// [105] CDataSection
// ------------------
class CDataSection : public exprnode
/*______________________________________________________________________
|
|	::= CDATA_BEGIN  CHAR_LITERAL  CDATA_END 	 ws:explicitXQ
|_______________________________________________________________________*/
{
protected:
	std::string cdata_content;

public:
	CDataSection();
	~CDataSection();

};



// [106] CDataSectionContents
// --------------------------
/* lexical rule */



// [107] ComputedConstructor
// -------------------------
class ComputedConstructor : public exprnode
/*______________________________________________________________________
|
|	::= CompDocConstructor
|			|	CompElemConstructor
|			|	CompAttrConstructor
|			|	CompTextConstructor
|			|	CompCommentConstructor
|			|	CompPIConstructor
|_______________________________________________________________________*/
{
public:
	ComputedConstructor();
	~ComputedConstructor();

};



// [108] CompDocConstructor
// ------------------------
class CompDocConstructor : public exprnode
/*______________________________________________________________________
|
|	::= DOCUMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	CompDocConstructor();
	~CompDocConstructor();

};



// [109] CompElemConstructor
// -------------------------
class CompElemConstructor : public exprnode
/*______________________________________________________________________
|
|	::= ELEMENT_QNAME_LBRACE  RBRACE
|			|	ELEMENT_QNAME_LBRACE  ContentExpr  RBRACE
|			|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
|			|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  ContentExpr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> qname_h;
	rchandle<Expr> qname_expr_h;
	rchandle<ContentExpr> content_expr_h;

public:
	CompElemConstructor();
	~CompElemConstructor();

};



// [110] ContentExpr
// -----------------
class ContentExpr : public exprnode
/*______________________________________________________________________
|
|	::= Expr
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	ContentExpr();
	~ContentExpr();

};



// [111] CompAttrConstructor
// -------------------------
class CompAttrConstructor : public exprnode
/*______________________________________________________________________
|
|	::= ATTRIBUTE  QNAME  LBRACE  RBRACE
|			|	ATTRIBUTE  QNAME  LBRACE  Expr  RBRACE
|			|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  RBRACE
|			|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> qname_h;
	rchandle<Expr> qname_expr_h;
	rchandle<Expr> val_expr_h;

public:
	CompAttrConstructor();
	~CompAttrConstructor();

};



// [112] CompTextConstructor
// -------------------------
class CompTextConstructor : public exprnode
/*______________________________________________________________________
|
|	::= TEXT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> text_expr_h;

public:
	CompTextConstructor();
	~CompTextConstructor();

};



// [113] CompCommentConstructor
// ----------------------------
class CompCommentConstructor : public exprnode
/*______________________________________________________________________
|
|	::= COMMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> comment_expr_h;

public:
	CompCommentConstructor();
	~CompCommentConstructor();

};



// [114] CompPIConstructor
// -----------------------
class CompPIConstructor : public exprnode
/*______________________________________________________________________
|
|	::= PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
|			|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
|			|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
|			|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	std::string target;
	rchandle<Expr> target_expr_h;
	rchandle<Expr> content_expr_h;

public:
	CompPIConstructor();
	~CompPIConstructor();

};


// [115] SingleType
// ----------------
class SingleType : public parsenode
/*______________________________________________________________________
|
|	::= AtomicType | AtomicType  HOOK
|_______________________________________________________________________*/
{
protected:
	rchandle<AtomicType> atomic_type_h;
	bool hook_b;

public:
	SingleType();
	~SingleType();

};


// [116] TypeDeclaration
// ---------------------
class TypeDeclaration : public parsenode
/*______________________________________________________________________
|
|	::= AS  SequenceType
|_______________________________________________________________________*/
{
protected:
	rchandle<SequenceType> seqtype_h;

public:
	TypeDeclaration();
	~TypeDeclaration();

};


// [117] SequenceType : public parsenode
// ------------------
class SequenceType
/*______________________________________________________________________
|
|	::= ItemType
|			|	ItemType OccurrenceIndicator
|			|	VOID_TEST
|_______________________________________________________________________*/
{
protected:
	rchandle<ItemType> itemtype_h;
	rchandle<OccurrenceIndicator> occur_h;
	bool void_b;

public:
	SequenceType();
	~SequenceType();

};


// [118] OccurrenceIndicator
// -------------------------
class OccurrenceIndicator : public parsenode
/*______________________________________________________________________
|
|	::= HOOK | STAR | PLUS   gn:occurrence-indicatorsXQ
|_______________________________________________________________________*/
{
public:
	enum occurrence_t {
		hook,
		star,
		plus
	};

protected:
	enum occurrence_t type;

public:
	OccurrenceIndicator();
	~OccurrenceIndicator();

};


// [119] ItemType
// --------------
class ItemType : public parsenode
/*______________________________________________________________________
|
|	::= AtomicType | KindTest | ITEM_TEST
|_______________________________________________________________________*/
{
protected:
	std::string item_test;

public:
	ItemType();
	~ItemType();

};


// [120] AtomicType
// ----------------
class AtomicType : public ItemType
/*______________________________________________________________________
|
|	::= QNAME
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> qname_h;

public:
	AtomicType();
	~AtomicType();

};


// [121] KindTest
// --------------
class KindTest : public ItemType
/*______________________________________________________________________
|
|	::= DocumentTest
|			| ElementTest
|			| AttributeTest
|			| SchemaElementTest
|			| SchemaAttributeTest
|			| PITest
|			| CommentTest
|			| TextTest
|			| AnyKindTest
|_______________________________________________________________________*/
{
public:
	KindTest();
	~KindTest();

};


// [122] AnyKindTest
// -----------------
class AnyKindTest : public KindTest
/*______________________________________________________________________
|
|	::= NODE_LPAR  RPAR
|_______________________________________________________________________*/
{
public:
	AnyKindTest();
	~AnyKindTest();

};
 

// [123] DocumentTest
// ------------------
class DocumentTest : public KindTest
/*______________________________________________________________________
|
|	::= DOCUMENT_NODE_LPAR  RPAR
|			|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
|			|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<ElementTest> elem_test_h;
	rchandle<SchemaElementTest> schema_elem_test_h;

public:
	DocumentTest();
	~DocumentTest();

};


// [124] TextTest
// --------------
class TextTest : public KindTest
/*______________________________________________________________________
|
|	::= TEXT_LPAR  RPAR 
|_______________________________________________________________________*/
{
public:
	TextTest();
	~TextTest();

};


// [125] CommentTest
// -----------------
class CommentTest : public KindTest
/*______________________________________________________________________
|
|	::= COMMENT_LPAR  RPAR 
|_______________________________________________________________________*/
{
public:
	CommentTest();
	~CommentTest();

};
 

// [126] PITest
// ------------
class PITest : public KindTest
/*______________________________________________________________________
|
|	::= PI_LPAR  RPAR
|			|	PI_LPAR  NCNAME  RPAR
|			|	PI_LPAR  STRING_LITERAL  RPAR
|_______________________________________________________________________*/
{
protected:
	std::string target;
	std::string content;

public:
	PITest();
	~PITest();

};


// [127] AttributeTest
// -------------------
class AttributeTest : public KindTest
/*______________________________________________________________________
|
|	::= ATTRIBUTE_LPAR  RPAR
|			|	ATTRIBUTE_LPAR  AttribNameOrWildcard  RPAR
|			|	ATTRIBUTE_LPAR  AttribNameOrWildcard  COMMA  TypeName  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<AttributeNameOrWildcard> attr_name_or_wildcard_h;
	rchandle<TypeName> type_name_h;

public:
	AttributeTest();
	~AttributeTest();

};


// [128] AttribNameOrWildcard
// --------------------------
class AttribNameOrWildcard : public parsenode
/*______________________________________________________________________
|
|	::= AttributeName | STAR
|_______________________________________________________________________*/
{
protected:
	rchandle<AttributeName> attr_name_h;
	bool star_b;

public:
	AttribNameOrWildcard();
	~AttribNameOrWildcard();

};


// [129] SchemaAttributeTest
// -------------------------
class SchemaAttributeTest : public parsenode
/*______________________________________________________________________
|
|	::= SCHEMA_ATTRIBUTE_LPAR  AttributeDeclaration  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<AttributeDeclaration> attr_decl_h;

public:
	SchemaAttributeTest();
	~SchemaAttributeTest();

};


// [130] AttributeDeclaration
// --------------------------
class AttributeDeclaration : public parsenode
/*______________________________________________________________________
|
|	::= AttributeName
|_______________________________________________________________________*/
{
protected:
	rchandle<AttributeName> attr_name_h;

public:
	AttributeDeclaration();
	~AttributeDeclaration();

};


// [131] ElementTest
// -----------------
class ElementTest : public parsenode
/*______________________________________________________________________
|
|	::= ELEMENT_LPAR  RPAR
|			|	ELEMENT_LPAR  ElementNameOrWildcard  RPAR
|			|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  RPAR
|			|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  HOOK  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<ElementNameOrWildcard> elem_name_or_wildcard_h;
	rchandle<TypeName> type_name_h;

public:
	ElementTest();
	~ElementTest();

};


// [132] ElementNameOrWildcard
// ---------------------------
class ElementNameOrWildcard : public parsenode
/*______________________________________________________________________
|
|	::= ElementName | STAR
|_______________________________________________________________________*/
{
protected:
	rchandle<ElementName> elem_name_h;
	bool star_b;

public:
	ElementNameOrWildcard();
	~ElementNameOrWildcard();

};


// [133] SchemaElementTest
// -----------------------
class SchemaElementTest : public parsenode
/*______________________________________________________________________
|
|	::= SCHEMA_ELEMENT_LPAR  ElementDeclaration  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<ElementDeclaration> elem_decl_h;

public:
	SchemaElementTest();
	~SchemaElementTest();

};


// [134] ElementDeclaration
// ------------------------
class ElementDeclaration : public parsenode
/*______________________________________________________________________
|
|	::= ElementName
|_______________________________________________________________________*/
{
protected:
	rchandle<ElementName> elem_name_h;

public:
	ElementDeclaration();
	~ElementDeclaration();

};


// [135] AttributeName
// -------------------
class AttributeName : public parsenode
/*______________________________________________________________________
|
|	::= QNAME
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> attr_qname_h;

public:
	AttributeName();
	~AttributeName();

};


// [136] ElementName
// -----------------
class ElementName : public parsenode
/*______________________________________________________________________
|
|	::= QNAME
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> elem_qname_h;

public:
	ElementName();
	~ElementName();

};


// [137] TypeName
// --------------
class TypeName : public parsenode
/*______________________________________________________________________
|
|	::= QNAME
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> type_qname_h;

public:
	TypeName();
	~TypeName();

};


/* lexical rules, see xquery.l */
/* --------------------------- */

// [138] IntegerLiteral
// [139] DecimalLiteral
// [140] DoubleLiteral
// [141] URILiteral 
// [142] StringLiteral
// [143] PITarget
// [144] VarName
// [145] ValidationMode
// [146] Digits
// [147] PredefinedEntityRef
// [148] CharRef
// [149] EscapeQuot
// [150] EscapeApos
// [151] ElementContentChar
// [152] QuotAttrContentChar
// [153] AposAttrContentChar
// [154] Comment
// [155] CommentContents

// [156] QName
// -----------
class QName : public parsenode
{
public:
	QName();
	~QName();

};


// [157] NCName
// [158] S  (WS)
// [159] Char



/*_______________________________________________________________________
 *                                                                       *
 *  Update productions                                                   *
 *  [http://www.w3.org/TR/xqupdate/]                                     *
 *                                                                       *
 *_______________________________________________________________________*/


// [241]	RevalidationDecl
// -----------------------
class RevalidationDecl : public parsenode
/*______________________________________________________________________
|
|	::= QNAME DECLARE_REVALIDATION_MODE
|_______________________________________________________________________*/
{
public:
	RevalidationDecl();
	~RevalidationDecl();

};



// [242]	InsertExpr
// ----------------
class InsertExpr : public exprnode
/*______________________________________________________________________
|
|	::= DO_INSERT  ExprSingle  INTO  ExprSingle
|			|	DO_INSERT  ExprSingle  AS  FIRST_INTO  ExprSingle
|			|	DO_INSERT  ExprSingle  AS  LAST_INTO  ExprSingle
|			| DO_INSERT  ExprSingle  AFTER  ExprSingle
|			| DO_INSERT  ExprSingle  BEFORE  ExprSingle
|_______________________________________________________________________*/
{
public:
	InsertExpr();
	~InsertExpr();
};



// [243] DeleteExpr
// ----------------
class DeleteExpr : public exprnode
/*______________________________________________________________________
|
|	::= DO_DELETE  ExprSingle
|_______________________________________________________________________*/
{
public:
	DeleteExpr();
	~DeleteExpr();
};



// [244] ReplaceExpr
// -----------------
class ReplaceExpr : public exprnode
/*______________________________________________________________________
|
|	::= DO_REPLACE  ExprSingle  WITH  ExprSingle
|			| DO_REPLACE  VALUE_OF  ExprSingle  WITH  ExprSingle
|_______________________________________________________________________*/
{
public:
	ReplaceExpr();
	~ReplaceExpr();
};



// [245] RenameExpr
// ----------------
class RenameExpr : public exprnode
/*______________________________________________________________________
|
|	::= DO_RENAME  ExprSingle  AS  ExprSingle
|_______________________________________________________________________*/
{
public:
	RenameExpr();
	~RenameExpr();
};



// [246] SourceExpr
// ----------------
// folded



// [247] TargetExpr
// ----------------
// folded



// [248] NewNameExpr
// -----------------
// folded into [245] RenameExpr



// [249] TransformExpr
// -------------------
class TransformExpr : public exprnode
/*______________________________________________________________________
|
|	::= TRANSFORM_COPY_DOLLAR  VarNameList
|				MODIFY  ExprSingle  RETURN  ExprSingle
|_______________________________________________________________________*/
{
public:
	TransformExpr();
	~TransformExpr();
};


// [249a] VarNameList
// ------------------
class VarNameList : public parsenode
/*______________________________________________________________________
|
|	::= VARNAME	 GETS  ExprSingle
|			|	VarNameList  COMMA_DOLLAR  VARNAME  GETS  ExprSingle
/*______________________________________________________________________
{
public:
	VarNameList();
	~VarNameList();
};




/*_______________________________________________________________________
 *                                                                       *
 *  Full-text productions                                                *
 *  [http://www.w3.org/TR/xqupdate/]                                     *
 *                                                                       *
 *_______________________________________________________________________*/


//[344] FTSelection
//-----------------
class FTSelection : public parsenode
/*______________________________________________________________________
|
|	::=	FTOr
|			|	FTOr  FTMatchOptionProximityList
|			|	FTOr  WEIGHT  RangeExpr
|			|	FTOr  FTMatchOptionProximityList  WEIGHT  RangeExpr
|_______________________________________________________________________*/
{
public:
};



//[344a] FTMatchOptionProximityList
//---------------------------------
class FTMatchOptionProximityList : public parsenode
/*______________________________________________________________________
|
|	::=	FTMatchOption
|			| FTProximity
|			| FTMatchOptionProximityList  FTMatchOption
|			| FTMatchOptionProximityList  FTProximity
|_______________________________________________________________________*/
{
public:
};



//[345]	FTOr
//----------
class FTOr : public parsenode
/*______________________________________________________________________
|
|	::=	FTAnd
|			|	FTOr  FTOR  FTAnd
|_______________________________________________________________________*/
{
public:
};



//[346]	FTAnd
//-----------
class FTAnd : public parsenode
/*______________________________________________________________________
|
|	::=	FTMildnot
|			|	FTAnd  FTAND  FTMildnot
|_______________________________________________________________________*/
{
public:
};



//[347]	FTMildnot
//---------------
class FTMildnot : public parsenode
/*______________________________________________________________________
|
|	::=	FTUnaryNot
|			|	FTMildnot  FTNOT_IN  FTUnaryNot
|_______________________________________________________________________*/
{
public:
};



//[348]	FTUnaryNot
//----------------
class FTUnaryNot : public parsenode
/*______________________________________________________________________
|
|	::=	FTWordsSelection
|			|	FTNOT  FTWordsSelection
|_______________________________________________________________________*/
{
public:
};



//[349]	FTWordsSelection
//----------------------
class FTWordsSelection : public parsenode
/*______________________________________________________________________
|
|	::=	FTWords
|			|	FTWords FTTimes
|			| LPAR  FTSelection  RPAR
|_______________________________________________________________________*/
{
public:
};



//[350]	FTWords
//-------------
class FTWords : public parsenode
/*______________________________________________________________________
|
|	::=	FTWordsValue 
|			|	FTWordsValue  FTAnyallOption
|_______________________________________________________________________*/
{
public:
};



//[351]	FTWordsValue
//------------------
class FTWordsValue : public parsenode
/*______________________________________________________________________
|
|	::=	Literal
|			| LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
};



//[352]	FTProximity
//-----------------
class FTProximity : public parsenode
/*______________________________________________________________________
|
|	::=	FTOrderedIndicator
|			| FTWindow
|			| FTDistance
|			| FTScope
|			| FTContent
|_______________________________________________________________________*/
{
public:
};



//[353]	FTOrderedIndicator
//------------------------
class FTOrderedIndicator : public parsenode
/*______________________________________________________________________
|
|	::=	ORDERED
|_______________________________________________________________________*/
{
public:
};



//[354] FTMatchOption 	
//-------------------
class FTMatchOption : public parsenode
/*______________________________________________________________________
|
|	::=	FTCaseOption
|			| FTDiacriticsOption
|			| FTStemOption
|			| FTThesaurusOption
|			| FTStopwordOption
|			| FTLanguageOption
|			| FTWildCardOption
|_______________________________________________________________________*/
{
public:
};



//[355] FTCaseOption
//------------------
class FTCaseOption : public parsenode
/*______________________________________________________________________
|
|	::=	LOWERCASE
|			| UPPERCASE
|			| CASE_SENSITIVE
|			| CASE_INSENSITIVE
|_______________________________________________________________________*/
{
public:
};



//[356] FTDiacriticsOption
//------------------------
class FTDiacriticsOption : public parsenode
/*______________________________________________________________________
|
|	::=	WITH_DIACRITICS
|			| WITHOUT_DIACRITICS
|			| DIACRITICS_SENSITIVE
|			| DIACRITICS_INSENSITIVE
|_______________________________________________________________________*/
{
public:
};



//[357] FTStemOption
//------------------
class FTStemOption : public parsenode
/*______________________________________________________________________
|
|	::=	WITH_STEMMING
|			| WITHOUT_STEMMING
|_______________________________________________________________________*/
{
public:
};



//[358] FTThesaurusOption
//-----------------------
class FTThesaurusOption : public parsenode
/*______________________________________________________________________
|
|	::=	WITH_THESAURUS  FTThesaurusID
|			|	WITH_THESAURUS  DEFAULT
|			| WITH_THESAURUS  LPAR  FTThesaurusID  RPAR
|			| WITH_THESAURUS  LPAR  FTThesaurusID COMMA  FTThesaurusList  RPAR
|			| WITH_THESAURUS  LPAR  DEFAULT  RPAR
|			| WITH_THESAURUS  LPAR  DEFAULT  COMMA  FTThesaurusList  RPAR
|			| WITHOUT_THESAURUS
|_______________________________________________________________________*/
{
public:
};



//[358a] FTThesaurusIDList
//------------------------
class FTThesaurusList : public parsenode
/*______________________________________________________________________
|
|	::=	FTThesaurusID
|			| FTThesaurusList  COMMA  FTThesaurusID
|_______________________________________________________________________*/
{
public:
};



//[359] FTThesaurusID
//-------------------
class FTThesaurusID : public parsenode
/*______________________________________________________________________
|
|	::=	AT  STRING_LITERAL
|			|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL
|			|	AT  STRING_LITERAL  FTRange  LEVELS
|			|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL  FTRange  LEVELS
|_______________________________________________________________________*/
{
public:
};



//[360] FTStopwordOption
//----------------------
class FTStopwordOption : public parsenode
/*______________________________________________________________________
|
|	::=	WITH_STOP_WORDS  FTRefOrList
|			|	WITH_STOP_WORDS  FTRefOrList  FTInclExclStringLiteralList
|			| WITH_DEFAULT_STOP_WORDS 
|			| WITH_DEFAULT_STOP_WORDS  FTInclExclStringLiteralList
|			| WITHOUT_STOP_WORDS
|_______________________________________________________________________*/
{
public:
};



//[360a] FTInclExclStringLiteralList
//----------------------------------
class FTInclExclStringLiteralList : public parsenode
/*______________________________________________________________________
|
|	::=	FTInclExclStringLiteral
|			| FTInclExclStringLiteralList  FTInclExclStringLiteral
|_______________________________________________________________________*/
{
public:
};



//[361] FTRefOrList
//-----------------
class FTRefOrList : public parsenode
/*______________________________________________________________________
|
|	::=	AT  STRING_LITERAL
|			| LPAR  FTStringLiteralList  RPAR 
|_______________________________________________________________________*/
{
public:
};



//[361a] FTStringLiteralList
//--------------------------
class FTStringLiteralList : public parsenode
/*______________________________________________________________________
|
|	::=	STRING_LITERAL
|			|	FTStringLiteralList  STRING_LITERAL
|_______________________________________________________________________*/
{
public:
};



//[362] FTInclExclStringLiteral
//-----------------------------
class FTInclExclStringLiteral : public parsenode
/*______________________________________________________________________
|
|	::=	UNION  FTRefOrList
|			|	EXCEPT  FTRefOrList
|_______________________________________________________________________*/
{
public:
};



//[363] FTLanguageOption
//----------------------
class FTLanguageOption : public parsenode
/*______________________________________________________________________
|
|	::=	LANGUAGE  STRING_LITERAL
|_______________________________________________________________________*/
{
public:
};



//[364] FTWildCardOption
//----------------------
class FTWildCardOption : public parsenode
/*______________________________________________________________________
|
|	::=	WITH_WILDCARDS
|			| WITHOUT_WILDCARDS
|_______________________________________________________________________*/
{
public:
};



//[365]	FTContent
//---------------
class FTContent : public parsenode
/*______________________________________________________________________
|
|	::=	AT_START
|			| AT_END
|			| ENTIRE_CONTENT
|_______________________________________________________________________*/
{
public:
};



//[366]	FTAnyallOption
//--------------------
class FTAnyallOption : public parsenode
/*______________________________________________________________________
|
|	::=	ANY
|			|	ANY_WORD
|			| ALL
|			| ALL_WORDS
|			| PHRASE
|_______________________________________________________________________*/
{
public:
};



//[367]	FTRange
//-------------
class FTRange : public parsenode
/*______________________________________________________________________
|
|	::=	EXACTLY  UnionExpr
|			| AT_LEAST  UnionExpr
|			| AT_MOST  UnionExpr
|			| FROM  UnionExpr  TO  UnionExpr
|_______________________________________________________________________*/
{
public:
};



//[368]	FTDistance
//----------------
class FTDistance : public parsenode
/*______________________________________________________________________
|
|	::=	DISTANCE  FTRange  FTUnit
|_______________________________________________________________________*/
{
public:
};



//[369]	FTWindow
//--------------
class FTWindow : public parsenode
/*______________________________________________________________________
|
|	::=	WINDOW  UnionExpr  FTUnit
|_______________________________________________________________________*/
{
public:
};



//[370]	FTTimes
//-------------
class FTTimes : public parsenode
/*______________________________________________________________________
|
|	::=	OCCURS  FTRange  TIMES
|_______________________________________________________________________*/
{
public:
};



//[371]	FTScope
//-------------
class FTScope : public parsenode
/*______________________________________________________________________
|
|	::=	SAME  FTBigUnit
|			|	DIFFERENT  FTBigUnit
|_______________________________________________________________________*/
{
public:
};



//[372]	FTUnit
//------------
class FTUnit : public parsenode
/*______________________________________________________________________
|
|	::=	WORDS | SENTENCES | PARAGRAPH
|_______________________________________________________________________*/
{
public:
};



//[373]	FTBigUnit
//---------------
class FTBigUnit : public parsenode
/*______________________________________________________________________
|
|	::=	SENTENCE | PARAGRAPH
|_______________________________________________________________________*/
{
public:
};



//[374]	FTIgnoreOption
//--------------------
class FTIgnoreOption : public parsenode
/*______________________________________________________________________
|
|	::=	WITHOUT_CONTENT  UnionExpr
|_______________________________________________________________________*/
{
public:
};




%%



/*
	The error member function registers the errors to the driver.
*/

void yy::xquery_parser::error(
	yy::xquery_parser::location_type const& loc,
	std::string const& msg)
{
  driver.error(loc, msg);
}



/*
static void print_token_value(FILE *file, int type, YYSTYPE value)
{
	if (type==VAR) {
		fprintf (file, "%s", value.tptr->name);
	}
	else if (type==NUM) {
		fprintf (file, "%d", value.val);
	}
}
*/






}	/* namespace xqp */
#endif	/*  XQP_PARSENODES_H */
