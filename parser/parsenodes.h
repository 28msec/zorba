/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: parsenodes.h,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Apache Foundation.
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

#include <rchandle.h>




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


// kinds of comparisons
enum CompKind {
  valueCompKind,
  nodeCompKind,
  orderCompKind,
  containsCompKind
};



/*
**  base class
*/
class class parsenode : public rcobject
{
protected:
  unsigned lineno;

public:
class   parsenode(unsigned _lineno) lineno(_lineno) {}
  ~parsenode() {}

public:
	// 
  virtual void put(
    std::ostream&,
		runtime_context const*,
		static_context const*, 
    int depth=0) const = 0;

public:
  inline unsigned get_lineno() const { return lineno; }

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
class WhereClause;
class Wildcard;






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
class WhereClause;
class Wildcard;



// [1] Module
// ----------
class Module : public parsenode
/*
::= MainModule
  | VersionDecl MainModule
  | LibraryModule 
  | VersionDecl LibraryModule 
*/
{

};


// [2] VersionDecl
// ---------------
class VersionDecl
/*
::= XQUERY_VERSION  STRING_LITERAL  SEMI
	| XQUERY_VERSION  STRING_LITERAL  ENCODING  STRING_LITERAL  SEMI
*/
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
class MainModule 
/*
::= Prolog  QueryBody
*/
{

};


// [4] LibraryModule
// -----------------
class LibraryModule
/*
::= ModuleDecl  Prolog
*/
{

};


// [5] ModuleDecl
// --------------
/*
**	Module declaration serves to identify a module as a library module.
**	
**	A module declaration begins with the keyword module and contains a 
**	namespace prefix and a URILiteral.  The URILiteral must be of nonzero 
**	length [err:XQST0088]. The URILiteral identifies the target namespace 
**	of the library module, which is the namespace for all variables and 
**	functions exported by the library module. The name of every variable 
**	and function declared in a library module must have a namespace URI 
**	that is the same as the target namespace of the module; otherwise a 
**	static error is raised [err:XQST0048]. In the statically known 
**	namespaces of the library module, the namespace prefix specified in 
**	the module declaration is bound to the module's target namespace. The 
**	namespace prefix specified in a module declaration must not be xml or 
**	xmlns [err:XQST0070]. 
*/
class ModuleDecl
/*
::= MODULE_NAMESPACE  NCNAME  EQ  URI_LITERAL  SEMI
*/
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

class Prolog
/*
::= SIND_DeclList  VFO_DeclList
*/
{
protected:
	rchandle<SIND_DeclList> sindList_h;
	rchandle<VFO_DeclList vfoList_h;

public:
	Prolog();
	~Prolog():

public:
	rchandle<SIND_DeclList> get_sindList() const { return sindList_h; }
	rchandle<VFO_DeclList> get_vfoList() const { return vfoList_h; }
};



// [6a] SIDN_DeclList
// ------------------
/*
**	The first part of the Prolog: Setters, Imports, Namespace declarations,
**	and Default namespace declarations.  
*/
class SIND_DeclList : public parsenode
/*
SIND_DeclList ::= SIND_Decl | SIND_DeclList  SEMI  SIND_Decl
*/
{
protected:
	std::vector<rchandle<SIND_Decl> > sind_h_vec;

public:
	SIND_DeclList();
	~SIND_DeclList():

public:
	rchandle<SIND_Decl> operator[] (uint32_t k) const
		{ return sind_h_vec[k]; }
	rchandle<SIND_Decl>& push_back(rchandle<SIND_Decl>& sind_h) 
		{ sind_h_vec.push_back(sind_h); }
};



// [6b] VFO_DeclList
// -----------------
class VFO_DeclList : public parsenode
/*
::= VFO_Decl | VFO_DeclList  SEMI  VFO_Decl
*/
{
protected:
	std::vector<rchandle<VFO_Decl> > vfo_h_vec;

public:
	VFO_DeclList();
	~VFO_DeclList();

public:
	rchandle<VFO_Decl> operator[] (uint32_t k) const
		{ return vfo_h_vec[k]; }
	rchandle<VFO_Decl>& push_back(rchandle<VFO_Decl>& vfo_h) 
		{ vfo_h_vec.push_back(vfo_h); }
};



// [6c] SIND_Decl
// --------------
class SIND_Decl : public parsenode
/*
::= Setter | Import | NamespaceDecl | DefaultNamespaceDecl
*/
{
public:
	SIND_Decl() : parsenode(lineno()) {}
	~SIND_Decl() {}
};



// [6d] VFO_Decl
// -------------
class VFO_Decl : public parsenode
/*
::= VarDecl | FunctionDecl | OptionDecl
*/
{
public:
	VFO_decl() : parsenode(lineno()) {}
	~VFO_decl() {}
};



// [7] Setter
// ----------
class Setter : public SIND_Decl
/*
::= BoundarySpaceDecl | DefaultCollationDecl | BaseURIDecl
	| ConstructionDecl | OrderingModeDecl | EmptyOrderDecl
	| CopyNamespacesDecl
*/
{
public:
	Setter() {}
	~Setter() {}
};



// [8] Import
// ----------
class Import : public SIND_Decl
/*
::= SchemaImport | ModuleImport
*/
{
public:
	Import() {}
	~Import() {}
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
/*
::= DECLARE_NAMESPACE  NCNAME  EQ  URI_LITERAL
*/
{
protected:
	std::string prefix;
	std::string uri;

public:
	NamespaceDecl()
		: prefix(""), uri("") {}
	NamespaceDecl(std::string const& _prefix, std::string const& _uri)
		: prefix(_prefix), uri(_uri) {}
	~NamespaceDecl() {}

public:
	std::string get_prefix() const { return prefix; }
	std::string get_uri() const { return uri; }
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
class BoundarySpaceDecl
/*
::= DECLARE_BOUNDARY_SPACE  PRESERVE |	DECLARE_BOUNDARY_SPACE  STRIP
*/
{
public:
	enum boundaryspace_mode {
		preserve,
		strip
	};

protected:
	boundaryspace_mode mode;

public:
	BoundarySpaceDecl() {}
	BoundarySpaceDecl(boundaryspace_mode _mode) : mode(_mode) {}
	~BoundarySpaceDecl() {}

public:
	boundaryspace_mode get_boundaryspace_mode() const { return mode; }
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
/*
::= DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
	| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
*/
{
protected:
	rchandle<string> default_element_namespace;
	rchandle<string> default_function_namespace;

public:
	DefaultNamespaceDecl()
		:
		default_element_namespace(NULL),
		default_function_namespace(NULL)
	{}
	DefaultNamespaceDecl(
		rchandle<string> _default_element_namespace,
		rchandle<string> _default_function_namespace)
		:
		default_element_namespace(_default_element_namespace),
		default_function_namespace(_default_function_namespace)
	{}
	~DefaultNamespaceDecl() {}

public:
	rchandle<string> get_default_element_namespace() const
		{ return default_element_namespace; }
	rchandle<string> get_default_function_namespace() const
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
/*
::= DECLARE_OPTION  QNAME  STRING_LITERAL
*/
{
protected:
	rchandle<QName> name_h;
	std::string val;

public:
	OptionDecl()
		:
		parsenode(lineno()),
		name_h(NULL),
		val("")
	{}
	OptionDecl(
		rchandle<QName> const& _name_h,
		std::string const& _val)
		:
		parsenode(lineno()),
		name_h(_name_h),
		val(_val)
	{}
	~OptionDecl() {}

public:
	rchandle<QName> get_name() const { return name_h; }
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
/*
::= DECLARE_ORDERING  ORDERED | DECLARE_ORDERING  UNORDERED
*/
{
public:
	enum ordering_mode {
		ordered,
		unordered
	};

protected:
	ordering_mode mode;
		
public:
	OrderingModeDecl()
		:
		parsenode(lineno()),
		mode(unordered)
	{}
	OrderingModeDecl(
		ordering_mode _mode)
		:
		parsenode(lineno()),
		mode(_mode)
	{}
	~OrderingModeDecl()
	{}
	
public:
	ordering_mode get_ordering_mode() const { returm mode; }
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
/*
::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
	|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
*/
{
public:
	enum emptyorder_mode {
		empty_greatest,
		empty_least
	};

protected:
	emptyorder_mode mode;

public:
	EmptyOrderDecl()
		:
		parsenode(lineno()
		mode(empty_least)
	{}
		
	EmptyOrderDecl(
		emptyorder_mode _mode)
		:
		parsenode(lineno()),
		mode(_mode)
	{}
	~EmptyOrderDecl() {}
	
public:
	emptyorder_mode get_mode() const { return mode; }
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
class CopyNamespacesDecl
/*
::= DECLARE_COPY_NAMESPACES  PreserveMode  COMMA  InheritMode
*/
{
protected:
public:
public:
};


// [17] PreserveMode
// -----------------
class PreserveMode
		PRESERVE
		{
		}
	| NO_PRESERVE
		{
		}
{
protected:
public:
public:
};


// [18] InheritMode
// ----------------
class InheritMode
		INHERIT
		{
		}
	| NO_INHERIT
		{
		}
};


// [19] DefaultCollationDecl
// -------------------------
class DefaultCollationDecl
		DECLARE_DEFAULT_COLLATION  URI_LITERAL
		{
		}
};


// [20] BaseURIDecl
// ----------------
class BaseURIDecl
		DECLARE_BASE_URI  URI_LITERAL
		{
		}
};


// [21] SchemaImport
// -----------------
class SchemaImport
		IMPORT_SCHEMA  URI_LITERAL
		{
		}
	| IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL
		{
		}
	|	IMPORT_SCHEMA  URI_LITERAL  AT  URI_LITERALList
		{
		}
	|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT  URI_LITERALList
		{
		}
};


// [21a] URLLiteralList
// --------------------
class URI_LITERALList
		URI_LITERAL
		{
		}
	| URI_LITERALList  COMMA  URI_LITERAL
		{
		}
};



// [22] SchemaPrefix
// -----------------
class SchemaPrefix
		NAMESPACE  NCNAME  EQ
		{
		}
	|	DEFAULT_ELEMENT  NAMESPACE
		{
		}
};


// [23] ModuleImport
// -----------------
class ModuleImport
		IMPORT_MODULE  URI_LITERAL 
		{
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQ  URI_LITERAL
		{
		}
	|	IMPORT_MODULE  URI_LITERAL  AT  URI_LITERALList
		{
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQ  URI_LITERAL  AT  URI_LITERALList
		{
		}
};



// [24] VarDecl
// ------------
class VarDecl
		DECLARE_VARIABLE_DOLLAR  VARNAME  GETS  ExprSingle
		{
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
		{
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
		{
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
		{
		}
};


// [25] ConstructionDecl
// ---------------------
class ConstructionDecl
		DECLARE_CONSTRUCTION  PRESERVE
		{
		}
	|	DECLARE_CONSTRUCTION  STRIP
		{
		}
};


// [26] FunctionDecl
// -----------------
class FunctionDecl
		DECLARE_FUNCTION  QNAME  LPAR  RPAR  EXTERNAL
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  EnclosedExpr
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  EXTERNAL
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  EnclosedExpr
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  AS  SequenceType  EXTERNAL
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  AS  SequenceType  EnclosedExpr
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  AS  SequenceType  EXTERNAL
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  AS  SequenceType  EnclosedExpr
		{
		}
};



// [27] ParamList
// --------------
class ParamList
		Param
		{
		}
	|	ParamList  COMMA  Param
		{
		}
};


// [28] Param
// ----------
class Param
		DOLLAR  VARNAME
		{
		}
	|	DOLLAR  VARNAME  TypeDeclaration
		{
		}
};


// [29] EnclosedExpr
// -----------------
class EnclosedExpr
		LBRACE  Expr  RBRACE
		{
		}
};


// [30] QueryBody
// --------------
class QueryBody
		Expr
		{
		}
};


// [31] Expr
// ---------
class Expr
		ExprSingle 
		{
		}
	|	Expr  COMMA  ExprSingle
		{
		}
};


// [32] ExprSingle
// ---------------
class ExprSingle
		FLWORExpr
		{
		}
	|	QuantifiedExpr
		{
		}
	|	TypeswitchExpr
		{
		}
	|	IfExpr
		{
		}
	|	OrExpr
		{
		}
};


// [33] FLWORExpr
// --------------
class FLWORExpr
	  ForLetClauseList  RETURN  ExprSingle
		{
		}
	|	ForLetClauseList  WhereClause  RETURN  ExprSingle
		{
		}
	|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
		{
		}
	|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
		{
		}
};


// [33a] ForLetClauseList
// ----------------------
class ForLetClauseList
		ForLetClause
		{
		}
	|	ForLetClause  ForLetClauseList
		{
		}
};


// [33b] ForLetClause
// ------------------
class ForLetClause
		ForClause
		{
		}
	|	LetClause
		{
		}
};


// [34] ForClause
// --------------
class ForClause
		FOR_DOLLAR  VarInDeclList
		{
		}
};


// [34a] VarInDeclList
// -------------------
class VarInDeclList
		VarInDecl
		{
		}
	|	VarInDeclList  COMMA  DOLLAR  VarInDecl
		{
		}
};


// [34b] VarInDecl
// ---------------
class VarInDecl
		VARNAME  IN  ExprSingle
		{
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle
		{
		}
	|	VARNAME  PositionalVar  IN  ExprSingle
		{
		}
	|	VARNAME  TypeDeclaration  PositionalVar  IN  ExprSingle
		{
		}
};


// [35] PositionalVar
// ------------------
class PositionalVar
		AT  DOLLAR  VARNAME
		{
		}
};


// [36] LetClause
// --------------
class LetClause
		LET_DOLLAR VarGetsDeclList
		{
		}
};


// [36a] VarGetsDeclList
// ---------------------
class VarGetsDeclList
		VarGetsDecl
		{
		}
	|	VarGetsDeclList  COMMA  DOLLAR  VarGetsDecl
		{
		}
};


// [36b] VarGetsDecl
// ------------------
class VarGetsDecl
		VARNAME  GETS  ExprSingle
		{
		}
	|	VARNAME  TypeDeclaration  GETS  ExprSingle
		{
		}
	|	VARNAME  PositionalVar  GETS  ExprSingle
		{
		}
	|	VARNAME  TypeDeclaration  PositionalVar  GETS  ExprSingle
		{
		}
};


// [37] WhereClause
// ----------------
class WhereClause
		WHERE  ExprSingle
		{
		}
};


// [38] OrderByClause
// ------------------
class OrderByClause
		ORDER_BY  OrderSpecList
		{
		}
	|	STABLE_ORDER_BY  OrderSpecList
		{
		}
};


// [39] OrderSpecList
// ------------------
class OrderSpecList
		OrderSpec 
		{
		}
	|	OrderSpecList  COMMA  OrderSpec
		{
		}
};


// [40] OrderSpec
// --------------
class OrderSpec
		ExprSingle
		{
		}
	|	ExprSingle OrderModifier
		{
		}
};


// [41] OrderModifier
// ------------------
class OrderModifier
		OrderDirSpec
		{
		}
	|	OrderEmptySpec
		{
		}
	|	OrderCollationSpec
		{
		}
	|	OrderDirSpec  OrderEmptySpec
		{
		}
	|	OrderDirSpec  OrderCollationSpec
		{
		}
	|	OrderEmptySpec  OrderCollationSpec
		{
		}
	|	OrderDirSpec  OrderEmptySpec  OrderCollationSpec
		{
		}
};


// [41a] OrderDirSpec
// ------------------
class OrderDirSpec
		ASCENDING
		{
		}
	|	DESCENDING
		{
		}
};


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec:
		EMPTY_GREATEST
		{
		}
	|	EMPTY_LEAST
		{
		}
};


// [41c] OrderCollationSpec
// ------------------------
class OrderCollationSpec
		COLLATION  URI_LITERAL
		{
		}
};


// [42] QuantifiedExpr 	   
// -------------------
class QuantifiedExpr
		SOME_DOLLAR  QVarInDeclList
		{
		}
	|	EVERY_DOLLAR  QVarInDeclList
		{
		}
};


// [42a] QVarInDeclList
// --------------------
class QVarInDeclList
		QVarInDecl
		{
		}
	|	QVarInDeclList  COMMA  DOLLAR  QVarInDecl
		{
		}
};


// [42b] QVarInDecl
// ----------------
class QVarInDecl
		VARNAME  IN  ExprSingle 
		{
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle 
		{
		}
};


// [43] TypeswitchExpr
// -------------------
class TypeswitchExpr
		TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
		{
		}
	|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  DOLLAR  VARNAME  RETURN  ExprSingle
		{
		}
};


// [43a] CaseClauseList
// --------------------
class CaseClauseList
		CaseClause
		{
		}
	|	CaseClauseList  CaseClause
		{
		}
};


// [44] CaseClause
// ---------------
class CaseClause
		CASE  SequenceType  RETURN  ExprSingle
		{
		}
		CASE  DOLLAR  VARNAME  AS  SequenceType  RETURN  ExprSingle
		{
		}
};


// [45] IfExpr
// -----------
class IfExpr
		IF_LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
		{
		}
};


// [46] OrExpr
// -----------
class OrExpr
		AndExpr
		{
		}
	|	OrExpr  OR  AndExpr
		{
		}
};


// [47] AndExpr
// ------------
class AndExpr
		ComparisonExpr
		{
		}
	|	AndExpr  AND  ComparisonExpr
		{
		}
};


// [48] ComparisonExpr
// -------------------
class ComparisonExpr
		RangeExpr
		{
		}
	| ValueCompExpr
		{
		}
	| GeneralCompExpr
		{
		}
	| NodeCompExpr
		{
		}
};


// [48a] ValueCompExpr
// -------------------
class ValueCompExpr
		ComparisonExpr  F_EQ  RangeExpr
		{
		}
	|	ComparisonExpr  F_NE  RangeExpr
		{
		}
	|	ComparisonExpr  F_LT  RangeExpr
		{
		}
	|	ComparisonExpr  F_LE  RangeExpr
		{
		}
	|	ComparisonExpr  F_GT  RangeExpr
		{
		}
	|	ComparisonExpr  F_GE  RangeExpr
		{
		}
};


// [48b] GeneralCompExpr
// ---------------------
class GeneralCompExpr
		ComparisonExpr  EQ  RangeExpr
		{
		}
	|	ComparisonExpr  NE  RangeExpr
		{
		}
	|	ComparisonExpr  LT  RangeExpr
		{
		}
	|	ComparisonExpr  LE  RangeExpr
		{
		}
	|	ComparisonExpr  GT  RangeExpr
		{
		}
	|	ComparisonExpr  GE  RangeExpr
		{
		}
};


// [48c] NodeComp
// --------------
class NodeCompExpr
		ComparisonExpr  IS  RangeExpr
		{
		}
	|	ComparisonExpr  PRECEDES  RangeExpr
		{
		}
	| ComparisonExpr  FOLLOWS  RangeExpr
		{
		}
};




// [49] RangeExpr
// --------------
class RangeExpr
		AdditiveExpr
		{
		}
	|	AdditiveExpr  TO  AdditiveExpr
		{
		}
};


// [50] AdditiveExpr
// -----------------
class AdditiveExpr
		MultiplicativeExpr
		{
		}
	|	AdditiveExpr  PLUS  MultiplicativeExpr
		{
		}
	|	AdditiveExpr  MINUS  MultiplicativeExpr
		{
		}
};


// [51] MultiplicativeExpr
// -----------------------
class MultiplicativeExpr
		UnionExpr
		{
		}
	|	MultiplicativeExpr  STAR  UnionExpr
		{
		}
	|	MultiplicativeExpr  DIV  UnionExpr
		{
		}
	|	MultiplicativeExpr  IDIV  UnionExpr
		{
		}
	|	MultiplicativeExpr  MOD  UnionExpr
		{
		}
};


// [52] UnionExpr
// --------------
class UnionExpr
		IntersectExceptExpr
		{
		}
	|	UnionExpr  UNION  IntersectExceptExpr
		{
		}
	|	UnionExpr  VBAR  IntersectExceptExpr
		{
		}
};


// [53] IntersectExceptExpr
// ------------------------
class IntersectExceptExpr
		InstanceofExpr
		{
		}
	|	IntersectExceptExpr  INTERSECT  InstanceofExpr
		{
		}
	|	IntersectExceptExpr  EXCEPT  InstanceofExpr
		{
		}
};


// [54] InstanceofExpr
// -------------------
class InstanceofExpr
		TreatExpr
		{
		}
	|	TreatExpr  INSTANCE_OF  SequenceType
		{
		}
};


// [55] TreatExpr
// --------------
class TreatExpr
		CastableExpr
		{
		}
	|	CastableExpr  TREAT_AS  SequenceType
		{
		}
};


// [56] CastableExpr
// -----------------
class CastableExpr
		CastExpr
		{
		}
	|	CastExpr  CASTABLE_AS  SingleType
		{
		}
};


// [57] CastExpr 	   
// -------------
class CastExpr
		UnaryExpr
		{
		}
	|	UnaryExpr  CAST_AS  SingleType
		{
		}
};


// [58] UnaryExpr
// --------------
class UnaryExpr
		ValueExpr
		{
		}
	|	SignList  ValueExpr
		{
		}
};


// [58a] SignList
// --------------
class SignList
		PLUS
		{
		}
	|	MINUS
		{
		}
	|	SignList  PLUS
		{
		}
	|	SignList  MINUS
		{
		}
};


// [59] ValueExpr
// --------------
class ValueExpr
		ValidateExpr
		{
		}
	|	PathExpr
		{
		}
	|	ExtensionExpr
		{
		}
};



// [60] GeneralComp
// ----------------
/* folded into [48b] */

// [61] ValueComp
// --------------
/* folded into [48a] */

// [62] NodeComp
// -------------
/* folded into [48c] */



// [63] ValidateExpr
// -----------------
class ValidateExpr
		VALIDATE_LBRACE  Expr  RBRACE
		{
		}
	|	VALIDATE_MODE  LBRACE  Expr  RBRACE
		{
		}
};


// [64] ExtensionExpr
// ------------------
class ExtensionExpr
		PragmaList  LBRACE  RBRACE
		{
		}
	|	PragmaList  LBRACE  Expr  RBRACE
		{
		}
};


// [64a] PragmaList
// ----------------
class PragmaList
		Pragma
		{
		}
	|	PragmaList  Pragma
		{
		}
};


// [65] Pragma
// -----------
class Pragma
		PRAGMA_BEGIN  QNAME  PRAGMA_LITERAL  PRAGMA_END
		{
		}
};	/* ws: explicit */


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
class PathExpr
		LEADING_LONE_SLASH
		{
		}
	|	SLASH  RelativePathExpr
		{
		}
	|	SLASH_SLASH  RelativePathExpr
		{
		}
	|	RelativePathExpr	 	/* gn: leading-lone-slashXQ */
		{
		}
};


// [68] RelativePathExpr
// ---------------------
class RelativePathExpr
		StepExpr
		{
		}
	|	RelativePathExpr SLASH  StepExpr
		{
		}
	|	RelativePathExpr SLASH_SLASH  StepExpr
		{
		}
};


// [69] StepExpr
// -------------
class StepExpr
		AxisStep
		{
		}
	|	FilterExpr
		{
		}
};


// [70] AxisStep
// -------------
class AxisStep
		ForwardStep  PredicateList
		{
		}
	|	ReverseStep  PredicateList
		{
		}
};


// [71] ForwardStep
// ----------------
class ForwardStep
		ForwardAxis  NodeTest
		{
		}
	|	AbbrevForwardStep
		{
		}
};


// [72] ForwardAxis
// ----------------
class ForwardAxis
		CHILD_AXIS
		{
		}
	| DESCENDANT_AXIS
		{
		}
	| ATTRIBUTE_AXIS
		{
		}
	| SELF_AXIS
		{
		}
	| DESCENDANT_OR_SELF_AXIS
		{
		}
	| FOLLOWING_SIBLING_AXIS
		{
		}
	| FOLLOWING_AXIS
		{
		}
};


// [73] AbbrevForwardStep
// ----------------------
class AbbrevForwardStep
		NodeTest
		{
		}
	|	AT_SIGN  NodeTest
		{
		}
};


// [74] ReverseStep
// ----------------
class ReverseStep
		ReverseAxis  NodeTest
		{
		}
	|	DOT_DOT
		{
		}
};


// [75] ReverseAxis
// ----------------
class ReverseAxis
		PARENT_AXIS
		{
		}
	| ANCESTOR_AXIS
		{
		}
	| PRECEDING_SIBLING_AXIS
		{
		}
	| PRECEDING_AXIS
		{
		}
	| ANCESTOR_OR_SELF_AXIS
		{
		}
};


// [76] AbbrevReverseStep
// ----------------------
/* folded into [74] */


// [77] NodeTest
// -------------
class NodeTest
		KindTest
		{
		}
	|	NameTest
		{
		}
};
 

// [78] NameTest
// -------------
class NameTest
		QNAME
		{
		}
	|	Wildcard
		{
		}
};


// [79] Wildcard
// -------------
class Wildcard
		STAR
		{
		}
	|	ELEM_WILDCARD
		{
		}
	|	PREFIX_WILDCARD   /* ws: explicitXQ */
		{
		}
};


// [80] FilterExpr
// ---------------
class FilterExpr
		PrimaryExpr  PredicateList
		{
		}
};


// [81] PredicateList
// ------------------
class PredicateList
		Predicate
		{
		}
	|	PredicateList  Predicate
		{
		}
};


// [82] Predicate
// --------------
class Predicate
		LBRACK  Expr  RBRACK
		{
		}
};



// [83] PrimaryExpr
// ----------------
class PrimaryExpr
		Literal
		{
		}
	|	VarRef
		{
		}
	|	ParenthesizedExpr
		{
		}
	|	ContextItemExpr
		{
		}
	|	FunctionCall
		{
		}
	|	Constructor
		{
		}
	|	OrderedExpr
		{
		}
	|	UnorderedExpr
		{
		}
};


// [84] Literal
// ------------
class Literal
		NumericLiteral
		{
		}
	|	STRING_LITERAL
		{
		}
};


// [85] NumericLiteral
// -------------------
class NumericLiteral
		INTEGER_LITERAL
		{
		}
	|	DECIMAL_LITERAL
		{
		}
	|	DOUBLE_LITERAL
		{
		}
};


// [86] VarRef
// -----------
class VarRef
		DOLLAR  VARNAME
		{
		}
};


// [87] ParenthesizedExpr
// ----------------------
class ParenthesizedExpr
		LPAR  RPAR
		{
		}
	|	LPAR  Expr  RPAR
		{
		}
};	


// [88] ContextItemExpr
// --------------------
class ContextItemExpr
		DOT
		{
		}
};	


// [89] OrderedExpr
// ----------------
class OrderedExpr
		ORDERED_LBRACE  Expr  RBRACE
		{
		}
};


// [90] UnorderedExpr
// ------------------
class UnorderedExpr
		UNORDERED_LBRACE  Expr  RBRACE
		{
		}
};


// [91] FunctionCall
// -----------------
class FunctionCall
		QNAME  LPAR  ArgList  RPAR 	/* gn: parensXQ */
		{
		}
				/* gn: reserved-function-namesXQ */
};


// [91a] ArgList
// -------------
class ArgList
		ExprSingle
		{
		}
	|	ArgList  COMMA  ExprSingle
		{
		}
};


// [92] Constructor
// ----------------
class Constructor
		DirectConstructor
		{
		}
	|	ComputedConstructor
		{
		}
};


// [93] DirectConstructor
// ----------------------
class DirectConstructor
		DirElemConstructor
		{
		}
	|	DirCommentConstructor
		{
		}
	|	DirPIConstructor
		{
		}
};

 
// [94] DirElemConstructor
// -----------------------
class DirElemConstructor
		LT  QNAME  DirAttributeList SGT /* ws: explicitXQ */
		{
		}
	|	LT  QNAME  DirAttributeList GT  DirElemContentList  LTS  QNAME  GT /* ws: explicitXQ */
		{
		}
			/* gn: ltXQ */
};


// [94a] DirElemContentList
// ------------------------
class DirElemContentList
		DirElemContent
		{
		}
	|	DirElemContentList  DirElemContent
		{
		}
};


// [95] DirAttributeList
// ---------------------
class DirAttributeList
		DirAttr
		{
		}
	|	DirAttributeList  DirAttr
		{
		}
};


// [95a] DirAttr
// -------------
class DirAttr
		QNAME  EQ  DirAttributeValue 	/* ws: explicitXQ */
		{
		}
};


// [96] DirAttributeValue
// ----------------------
class DirAttributeValue
		QUOTE  QuoteAttrContentList  QUOTE
		{
		}
	|	APOS  AposAttrContentList  APOS 	/* ws: explicitXQ */
		{
		}
};


// [96a] QuoteAttrContentList
// --------------------------
class QuoteAttrContentList
		ESCAPE_QUOTE
		{
		}
	|	QuoteAttrValueContent
		{
		}
	|	QuoteAttrContentList  ESCAPE_QUOTE
		{
		}
	|	QuoteAttrContentList  QuoteAttrValueContent
		{
		}
};


// [96b] AposAttrContentList
// -------------------------
class AposAttrContentList
		ESCAPE_APOS
		{
		}
	|	AposAttrValueContent
		{
		}
	|	AposAttrContentList  ESCAPE_APOS
		{
		}
	|	AposAttrContentList  AposAttrValueContent
		{
		}
};


// [97] QuotAttrValueContent
// -------------------------
class QuoteAttrValueContent
		QUOTE_ATTR_CONTENT
		{
		}
	|	CommonContent
		{
		}
};


// [98] AposAttrValueContent
// -------------------------
class AposAttrValueContent
		APOS_ATTR_CONTENT
		{
		}
	|	CommonContent
		{
		}
};


// [99] DirElemContent
// -------------------
class DirElemContent
		DirectConstructor
		{
		}
	|	ELEMENT_CONTENT
		{
		}
	|	CDataSection
		{
		}
	|	CommonContent
		{
		}
};


// [100] CommonContent
// -------------------
class CommonContent
		ENTITY_REF
		{
		}
	|	CHAR_REF_LITERAL
		{
		}
	|	DOUBLE_LBRACE
		{
		}
	|	DOUBLE_RBRACE
		{
		}
	|	EnclosedExpr
		{
		}
};


// [101] DirCommentConstructor
// ---------------------------
class DirCommentConstructor
		COMMENT_BEGIN  EXPR_COMMENT_LITERAL  COMMENT_END 	/* ws: explicitXQ */
		{
		}
};


// [102] DirCommentContents
// ------------------------
/* lexical rule */


// [103] DirPIConstructor
// ----------------------
class DirPIConstructor
		PI_BEGIN  PI_TARGET  PI_END 	/* ws: explicitXQ */
		{
		}
	|	PI_BEGIN  PI_TARGET  CHAR_LITERAL  PI_END 	/* ws: explicitXQ */
		{
		}
};


// [104] DirPIContents
// -------------------
/* lexical rule */


// [105] CDataSection
// ------------------
class CDataSection
		CDATA_BEGIN  CHAR_LITERAL  CDATA_END 	/* ws: explicitXQ */
		{
		}
};


// [106] CDataSectionContents
// --------------------------
/* lexical rule */


// [107] ComputedConstructor
// -------------------------
class ComputedConstructor
		CompDocConstructor
		{
		}
	|	CompElemConstructor
		{
		}
	|	CompAttrConstructor
		{
		}
	|	CompTextConstructor
		{
		}
	|	CompCommentConstructor
		{
		}
	|	CompPIConstructor
		{
		}
};


// [108] CompDocConstructor
// ------------------------
class CompDocConstructor
		DOCUMENT_LBRACE  Expr  RBRACE
		{
		}
};


// [109] CompElemConstructor
// -------------------------
class CompElemConstructor
		ELEMENT_QNAME_LBRACE  RBRACE
		{
		}
	|	ELEMENT_QNAME_LBRACE  ContentExpr  RBRACE
		{
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  ContentExpr  RBRACE
		{
		}
};


// [110] ContentExpr
// -----------------
class ContentExpr
		Expr
		{
		}
};


// [111] CompAttrConstructor
// -------------------------
class CompAttrConstructor
		ATTRIBUTE  QNAME  LBRACE  RBRACE
		{
		}
	|	ATTRIBUTE  QNAME  LBRACE  Expr  RBRACE
		{
		}
	|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
		}
	|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
		}
};


// [112] CompTextConstructor
// -------------------------
class CompTextConstructor
		TEXT_LBRACE  Expr  RBRACE
		{
		}
};


// [113] CompCommentConstructor
// ----------------------------
class CompCommentConstructor
		COMMENT_LBRACE  Expr  RBRACE
		{
		}
};


// [114] CompPIConstructor
// -----------------------
class CompPIConstructor
		PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
		{
		}
	|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
		{
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
		{
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
		{
		}
};


// [115] SingleType
// ----------------
class SingleType
		AtomicType
		{
		}
	|	AtomicType  HOOK
		{
		}
};


// [116] TypeDeclaration
// ---------------------
class TypeDeclaration
		AS  SequenceType
		{
		}
};


// [117] SequenceType
// ------------------
class SequenceType
		ItemType
		{
		}
	|	ItemType OccurrenceIndicator
		{
		}
	|	VOID_TEST
		{
		}
};


// [118] OccurrenceIndicator
// -------------------------
class OccurrenceIndicator
		HOOK
		{
		}
	|	STAR
		{
		}
	|	PLUS 	/* gn: occurrence-indicatorsXQ */
		{
		}
};


// [119] ItemType
// --------------
class ItemType
		AtomicType
		{
		}
	|	KindTest
		{
		}
	|	ITEM_TEST
		{
		}
};


// [120] AtomicType
// ----------------
class AtomicType
		QNAME
		{
		}
};


// [121] KindTest
// --------------
class KindTest
		DocumentTest
		{
		}
	| ElementTest
		{
		}
	| AttributeTest
		{
		}
	| SchemaElementTest
		{
		}
	| SchemaAttributeTest
		{
		}
	| PITest
		{
		}
	| CommentTest
		{
		}
	| TextTest
		{
		}
	| AnyKindTest
		{
		}
};


// [122] AnyKindTest
// -----------------
class AnyKindTest
		NODE_LPAR  RPAR
		{
		}
};
 

// [123] DocumentTest
// ------------------
class DocumentTest
		DOCUMENT_NODE_LPAR  RPAR
		{
		}
	|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
		{
		}
	|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
		{
		}
};


// [124] TextTest
// --------------
class TextTest
		TEXT_LPAR  RPAR 
		{
		}
};


// [125] CommentTest
// -----------------
class CommentTest
		COMMENT_LPAR  RPAR 
		{
		}
};
 

// [126] PITest
// ------------
class PITest
		PI_LPAR  RPAR
		{
		}
	|	PI_LPAR  NCNAME  RPAR
		{
		}
	|	PI_LPAR  STRING_LITERAL  RPAR
		{
		}
};


// [127] AttributeTest
// -------------------
class AttributeTest
		ATTRIBUTE_LPAR  RPAR
		{
		}
	|	ATTRIBUTE_LPAR  AttribNameOrWildcard  RPAR
		{
		}
	|	ATTRIBUTE_LPAR  AttribNameOrWildcard  COMMA  TypeName  RPAR
		{
		}
};


// [128] AttribNameOrWildcard
// --------------------------
class AttribNameOrWildcard
		AttributeName
		{
		}
	|	STAR
		{
		}
};


// [129] SchemaAttributeTest
// -------------------------
class SchemaAttributeTest
		SCHEMA_ATTRIBUTE_LPAR  AttributeDeclaration  RPAR
		{
		}
};


// [130] AttributeDeclaration
// --------------------------
class AttributeDeclaration
		AttributeName
		{
		}
};


// [131] ElementTest
// -----------------
class ElementTest
		ELEMENT_LPAR  RPAR
		{
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  RPAR
		{
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  RPAR
		{
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  HOOK  RPAR
		{
		}
};


// [132] ElementNameOrWildcard
// ---------------------------
class ElementNameOrWildcard
		ElementName
		{
		}
	|	STAR
		{
		}
};


// [133] SchemaElementTest
// -----------------------
class SchemaElementTest
		SCHEMA_ELEMENT_LPAR  ElementDeclaration  RPAR
		{
		}
};


// [134] ElementDeclaration
// ------------------------
class ElementDeclaration
		ElementName
		{
		}
};


// [135] AttributeName
// -------------------
class AttributeName
		QNAME
		{
		}
};


// [136] ElementName
// -----------------
class ElementName
		QNAME
		{
		}
};


// [137] TypeName
// --------------
class TypeName
		QNAME
		{
		}
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
// [157] NCName
// [158] S  (WS)
// [159] Char

