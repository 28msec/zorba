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
**  base class
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
public:
	Module();
	~Module();

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
public:
	MainModule();
	~MainModule();

};


// [4] LibraryModule
// -----------------
class LibraryModule : parsenode
/*______________________________________________________________________
|
|	::= ModuleDecl  Prolog
|_______________________________________________________________________*/
{
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
	SIND_DeclList* sindList_p;
	VFO_DeclList* vfoList_p;

public:
	Prolog();
	~Prolog();

public:
	SIND_DeclList* get_sindList() const { return sindList_p; }
	VFO_DeclList* get_vfoList() const { return vfoList_p; }

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
	std::vector<SIND_Decl*> sind_p_vec;

public:
	SIND_DeclList();
	SIND_DeclList(SIND_Decl*);
	~SIND_DeclList();

public:
	SIND_Decl* operator[] (uint32_t k) const { return sind_p_vec[k]; }
	void push_back(SIND_Decl* sind_p) { sind_p_vec.push_back(sind_p); }

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
	std::vector<VFO_Decl*> vfo_p_vec;

public:
	VFO_DeclList();
	VFO_DeclList(VFO_Decl*);
	~VFO_DeclList();

public:
	VFO_Decl* operator[] (uint32_t k) const { return vfo_p_vec[k]; }
	void push_back(VFO_Decl* vfo_p) { vfo_p_vec.push_back(vfo_p); }
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
	Setter() {}
	~Setter() {}
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
/*______________________________________________________________________
|
|	::= DECLARE_NAMESPACE  NCNAME  EQ  URI_LITERAL
|_______________________________________________________________________*/
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
class BoundarySpaceDecl : public SIND_Decl
/*______________________________________________________________________
|
|	::= DECLARE_BOUNDARY_SPACE  ( PRESERVE | STRIP )
|_______________________________________________________________________*/
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
/*______________________________________________________________________
|
|	::= DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
|			| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string* default_element_namespace_p;
	std::string* default_function_namespace_p;

public:
	DefaultNamespaceDecl()
		:
		default_element_namespace_p(NULL),
		default_function_namespace_p(NULL)
	{}
	DefaultNamespaceDecl(
		std::string* _default_element_namespace_p,
		std::string* _default_function_namespace_p)
		:
		default_element_namespace_p(_default_element_namespace_p),
		default_function_namespace_p(_default_function_namespace_p)
	{}
	~DefaultNamespaceDecl() {}

public:
	std::string* get_default_element_namespace() const
		{ return default_element_namespace_p; }
	std::string* get_default_function_namespace() const
		{ return default_function_namespace_p; }
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
	QName* name_p;
	std::string val;

public:
	OptionDecl();
	OptionDecl(QName const* _name_p, std::string const& _val);
	~OptionDecl();

public:
	QName* get_name() const { return name_p; }
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
public:
	enum ordering_mode {
		ordered,
		unordered
	};

protected:
	ordering_mode mode;
		
public:
	OrderingModeDecl();
	OrderingModeDecl(ordering_mode _mode);
	~OrderingModeDecl();
	
public:
	ordering_mode get_ordering_mode() const { return mode; }
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
public:
	enum emptyorder_mode {
		empty_greatest,
		empty_least
	};

protected:
	emptyorder_mode mode;

public:
	EmptyOrderDecl();
	EmptyOrderDecl(emptyorder_mode _mode);
	~EmptyOrderDecl();
	
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
class CopyNamespacesDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_COPY_NAMESPACES  PreserveMode  COMMA  InheritMode
|_______________________________________________________________________*/
{
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
public:
	Param();
	~Param();

};


// [29] EnclosedExpr
// -----------------
class EnclosedExpr : public parsenode
/*______________________________________________________________________
|
|	::= LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	EnclosedExpr();
	~EnclosedExpr();

};


// [30] QueryBody
// --------------
class QueryBody : public parsenode
/*______________________________________________________________________
|
|	::= Expr
|_______________________________________________________________________*/
{
public:
	QueryBody();
	~QueryBody();

};


// [31] Expr
// ---------
class Expr : public parsenode
/*______________________________________________________________________
|
|	::= ExprSingle 
|			|	Expr  COMMA  ExprSingle
|_______________________________________________________________________*/
{
public:
	Expr();
	~Expr();

};


// [32] ExprSingle
// ---------------
class ExprSingle : public parsenode
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
class FLWORExpr : public parsenode
/*______________________________________________________________________
|
|	::= ForLetClauseList  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  RETURN  ExprSingle
|			|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
|_______________________________________________________________________*/
{
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
class ForClause : public parsenode
/*______________________________________________________________________
|
|	::= FOR_DOLLAR  VarInDeclList
|_______________________________________________________________________*/
{
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
|_______________________________________________________________________*/
{
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
|			|	VARNAME  PositionalVar  GETS  ExprSingle
|			|	VARNAME  TypeDeclaration  PositionalVar  GETS  ExprSingle
|_______________________________________________________________________*/
{
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
public:
	OrderModifier();
	~OrderModifier();

};


// [41a] OrderDirSpec
// ------------------
class OrderDirSpec : public parsenode
/*______________________________________________________________________
|
|	::= ASCENDING
|			|	DESCENDING
|_______________________________________________________________________*/
{
public:
	OrderDirSpec();
	~OrderDirSpec();
	
};


// [41b] OrderEmptySpec
// --------------------
class OrderEmptySpec : public parsenode
/*______________________________________________________________________
|
|	::= EMPTY_GREATEST
|			|	EMPTY_LEAST
|_______________________________________________________________________*/
{
public:
	OrderEmptySpec();
	~OrderEmptySpec();

};


// [41c] OrderCollationSpec
// ------------------------
class OrderCollationSpec : public parsenode
/*______________________________________________________________________
|
|	::= COLLATION  URI_LITERAL
|_______________________________________________________________________*/
{
public:
	OrderCollationSpec();
	~OrderCollationSpec();

};


// [42] QuantifiedExpr 	   
// -------------------
class QuantifiedExpr : public parsenode
/*______________________________________________________________________
|
|	::= SOME_DOLLAR  QVarInDeclList
|			|	EVERY_DOLLAR  QVarInDeclList
|_______________________________________________________________________*/
{
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
public:
	QVarInDecl();
	~QVarInDecl();
};


// [43] TypeswitchExpr
// -------------------
class TypeswitchExpr : public parsenode
/*______________________________________________________________________
|
|	::= TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
|			|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT 
|					DOLLAR  VARNAME  RETURN  ExprSingle
|_______________________________________________________________________*/
{
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
public:
	CaseClause();
	~CaseClause();

};


// [45] IfExpr
// -----------
class IfExpr : public parsenode
/*______________________________________________________________________
|
|	::= IF_LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
|_______________________________________________________________________*/
{
public:
	IfExpr();
	~IfExpr();

};


// [46] OrExpr
// -----------
class OrExpr : public parsenode
/*______________________________________________________________________
|
|	::= AndExpr
|			|	OrExpr  OR  AndExpr
|_______________________________________________________________________*/
{
public:
	OrExpr();
	~OrExpr();
};


// [47] AndExpr
// ------------
class AndExpr : public parsenode
/*______________________________________________________________________
|
|	::= ComparisonExpr
|			|	AndExpr  AND  ComparisonExpr
|_______________________________________________________________________*/
{
public:
	AndExpr();
	~AndExpr();

};


// [48] ComparisonExpr
// -------------------
class ComparisonExpr : public parsenode
/*______________________________________________________________________
|
|	::= RangeExpr
|			| ValueCompExpr
|			| GeneralCompExpr
|			| NodeCompExpr
|_______________________________________________________________________*/
{
public:
	ComparisonExpr();
	~ComparisonExpr();

};


// [48a] ValueCompExpr
// -------------------
class ValueCompExpr : public parsenode
/*______________________________________________________________________
|
|	::= ComparisonExpr  F_EQ  RangeExpr
|			|	ComparisonExpr  F_NE  RangeExpr
|			|	ComparisonExpr  F_LT  RangeExpr
|			|	ComparisonExpr  F_LE  RangeExpr
|			|	ComparisonExpr  F_GT  RangeExpr
|			|	ComparisonExpr  F_GE  RangeExpr
|_______________________________________________________________________*/
{
public:
	ValueCompExpr();
	~ValueCompExpr();

};


// [48b] GeneralCompExpr
// ---------------------
class GeneralCompExpr : public parsenode
/*______________________________________________________________________
|
|	::= ComparisonExpr  EQ  RangeExpr
|			|	ComparisonExpr  NE  RangeExpr
|			|	ComparisonExpr  LT  RangeExpr
|			|	ComparisonExpr  LE  RangeExpr
|			|	ComparisonExpr  GT  RangeExpr
|			|	ComparisonExpr  GE  RangeExpr
|_______________________________________________________________________*/
{
public:
	GeneralCompExpr();
	~GeneralCompExpr();

};


// [48c] NodeComp
// --------------
class NodeCompExpr : public parsenode
/*______________________________________________________________________
|
|	::= ComparisonExpr  IS  RangeExpr
|			|	ComparisonExpr  PRECEDES  RangeExpr
|			| ComparisonExpr  FOLLOWS  RangeExpr
|_______________________________________________________________________*/
{
public:
	NodeCompExpr();
	~NodeCompExpr();

};


// [49] RangeExpr
// --------------
class RangeExpr : public parsenode
/*______________________________________________________________________
|
|	::= AdditiveExpr
|			|	AdditiveExpr  TO  AdditiveExpr
|_______________________________________________________________________*/
{
public:
	RangeExpr();
	~RangeExpr();

};


// [50] AdditiveExpr
// -----------------
class AdditiveExpr : public parsenode
/*______________________________________________________________________
|
|	::= MultiplicativeExpr
|			|	AdditiveExpr  PLUS  MultiplicativeExpr
|			|	AdditiveExpr  MINUS  MultiplicativeExpr
|_______________________________________________________________________*/
{
public:
	AdditiveExpr();
	~AdditiveExpr();

};


// [51] MultiplicativeExpr
// -----------------------
class MultiplicativeExpr : public parsenode
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
public:
	IntersectExceptExpr();
	~IntersectExceptExpr();

};


// [54] InstanceofExpr
// -------------------
class InstanceofExpr : public parsenode
/*______________________________________________________________________
|
|	::= TreatExpr
|			|	TreatExpr  INSTANCE_OF  SequenceType
|_______________________________________________________________________*/
{
public:
	InstanceofExpr();
	~InstanceofExpr();

};


// [55] TreatExpr
// --------------
class TreatExpr : public parsenode
/*______________________________________________________________________
|
|	::= CastableExpr
|			|	CastableExpr  TREAT_AS  SequenceType
|_______________________________________________________________________*/
{
public:
	TreatExpr();
	~TreatExpr();

};


// [56] CastableExpr
// -----------------
class CastableExpr : public parsenode
/*______________________________________________________________________
|
|	::= CastExpr
|			|	CastExpr  CASTABLE_AS  SingleType
|_______________________________________________________________________*/
{
public:
	CastableExpr();
	~CastableExpr();

};


// [57] CastExpr 	   
// -------------
class CastExpr : public parsenode
/*______________________________________________________________________
|
|	::= UnaryExpr
|			|	UnaryExpr  CAST_AS  SingleType
|_______________________________________________________________________*/
{
public:
	CastExpr();
	~CastExpr();

};


// [58] UnaryExpr
// --------------
class UnaryExpr : public parsenode
/*______________________________________________________________________
|
|	::= ValueExpr
|			|	SignList  ValueExpr
|_______________________________________________________________________*/
{
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
public:
	SignList();
	~SignList();

};


// [59] ValueExpr
// --------------
class ValueExpr : public parsenode
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
/* folded into [48b] */

// [61] ValueComp
// --------------
/* folded into [48a] */

// [62] NodeComp
// -------------
/* folded into [48c] */



// [63] ValidateExpr
// -----------------
class ValidateExpr : public parsenode
/*______________________________________________________________________
|
|	::= VALIDATE_LBRACE  Expr  RBRACE
|			|	VALIDATE_MODE  LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	ValidateExpr();
	~ValidateExpr();

};


// [64] ExtensionExpr
// ------------------
class ExtensionExpr : public parsenode
/*______________________________________________________________________
|
|	::= PragmaList  LBRACE  RBRACE
|			|	PragmaList  LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
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
class PathExpr : public parsenode
/*______________________________________________________________________
|
|	::= LEADING_LONE_SLASH
|			|	SLASH  RelativePathExpr
|			|	SLASH_SLASH  RelativePathExpr
|			|	RelativePathExpr	 	 gn:leading-lone-slashXQ
|_______________________________________________________________________*/
{
public:
	PathExpr();
	~PathExpr();

};


// [68] RelativePathExpr
// ---------------------
class RelativePathExpr : public parsenode
/*______________________________________________________________________
|
|	::= StepExpr
|			|	RelativePathExpr SLASH  StepExpr
|			|	RelativePathExpr SLASH_SLASH  StepExpr
|_______________________________________________________________________*/
{
public:
	RelativePathExpr();
	~RelativePathExpr();

};


// [69] StepExpr
// -------------
class StepExpr : public parsenode
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
class AxisStep : public parsenode
/*______________________________________________________________________
|
|	::= ForwardStep  PredicateList
|			|	ReverseStep  PredicateList
|_______________________________________________________________________*/
{
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
	Wildcard();
	~Wildcard();

};


// [80] FilterExpr
// ---------------
class FilterExpr : public parsenode
/*______________________________________________________________________
|
|	::= PrimaryExpr  PredicateList
|_______________________________________________________________________*/
{
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
public:
	PredicateList();
	~PredicateList();

};


// [82] Predicate
// --------------
class Predicate : public parsenode
/*______________________________________________________________________
|
|	::= LBRACK  Expr  RBRACK
|_______________________________________________________________________*/
{
public:
	Predicate();
	~Predicate();

};



// [83] PrimaryExpr
// ----------------
class PrimaryExpr : public parsenode
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
class Literal : public parsenode
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
class NumericLiteral : public parsenode
/*______________________________________________________________________
|
|	::= INTEGER_LITERAL
|			|	DECIMAL_LITERAL
|			|	DOUBLE_LITERAL
|_______________________________________________________________________*/
{
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
public:
	ParenthesizedExpr();
	~ParenthesizedExpr();

};	


// [88] ContextItemExpr
// --------------------
class ContextItemExpr : public parsenode
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
class OrderedExpr : public parsenode
/*______________________________________________________________________
|
|	::= ORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	OrderedExpr();
	~OrderedExpr();

};


// [90] UnorderedExpr
// ------------------
class UnorderedExpr : public parsenode
/*______________________________________________________________________
|
|	::= UNORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	UnorderedExpr();
	~UnorderedExpr();

};


// [91] FunctionCall
// -----------------
class FunctionCall : public parsenode
/*______________________________________________________________________
|
|	::= QNAME  LPAR  ArgList  RPAR 	 gn:parensXQ
|			 gn:reserved-function-namesXQ 
|_______________________________________________________________________*/
{
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
public:
	ArgList();
	~ArgList();

};


// [92] Constructor
// ----------------
class Constructor : public parsenode
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
class DirectConstructor : public parsenode
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
public:
	DirAttributeList();
	~DirAttributeList();

};


// [95a] DirAttr
// -------------
class DirAttr : public parsenode
/*______________________________________________________________________
|
|	::= QNAME  EQ  DirAttributeValue 	 ws:explicitXQ
|_______________________________________________________________________*/
{
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
public:
	AposAttrValueContent();
	~AposAttrValueContent();

};


// [99] DirElemContent
// -------------------
class DirElemContent : public parsenode
/*______________________________________________________________________
|
|	::= DirectConstructor
|			|	ELEMENT_CONTENT
|			|	CDataSection
|			|	CommonContent
|_______________________________________________________________________*/
{
public:
	DirElemContent();
	~DirElemContent();

};


// [100] CommonContent
// -------------------
class CommonContent : public parsenode
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
	CommonContent();
	~CommonContent();

};


// [101] DirCommentConstructor
// ---------------------------
class DirCommentConstructor : public parsenode
/*______________________________________________________________________
|
|	::= COMMENT_BEGIN  EXPR_COMMENT_LITERAL  COMMENT_END 	 ws:explicitXQ
|_______________________________________________________________________*/
{
public:
	DirCommentConstructor();
	~DirCommentConstructor();

};


// [102] DirCommentContents
// ------------------------
/* lexical rule */


// [103] DirPIConstructor
// ----------------------
class DirPIConstructor : public parsenode
/*______________________________________________________________________
|
|	::= PI_BEGIN  PI_TARGET  PI_END    ws:explicitXQ
|			|	PI_BEGIN  PI_TARGET  CHAR_LITERAL  PI_END	   ws:explicitXQ
|_______________________________________________________________________*/
{
public:
	DirPIConstructor();
	~DirPIConstructor();

};


// [104] DirPIContents
// -------------------
/* lexical rule */


// [105] CDataSection
// ------------------
class CDataSection : public parsenode
/*______________________________________________________________________
|
|	::= CDATA_BEGIN  CHAR_LITERAL  CDATA_END 	 ws:explicitXQ
|_______________________________________________________________________*/
{
public:
	CDataSection();
	~CDataSection();

};


// [106] CDataSectionContents
// --------------------------
/* lexical rule */


// [107] ComputedConstructor
// -------------------------
class ComputedConstructor : public parsenode
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
class CompDocConstructor : public parsenode
/*______________________________________________________________________
|
|	::= DOCUMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	CompDocConstructor();
	~CompDocConstructor();

};


// [109] CompElemConstructor
// -------------------------
class CompElemConstructor : public parsenode
/*______________________________________________________________________
|
|	::= ELEMENT_QNAME_LBRACE  RBRACE
|			|	ELEMENT_QNAME_LBRACE  ContentExpr  RBRACE
|			|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
|			|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  ContentExpr  RBRACE
|_______________________________________________________________________*/
{
public:
	CompElemConstructor();
	~CompElemConstructor();

};


// [110] ContentExpr
// -----------------
class ContentExpr : public parsenode
/*______________________________________________________________________
|
|	::= Expr
|_______________________________________________________________________*/
{
public:
	ContentExpr();
	~ContentExpr();

};


// [111] CompAttrConstructor
// -------------------------
class CompAttrConstructor : public parsenode
/*______________________________________________________________________
|
|	::= ATTRIBUTE  QNAME  LBRACE  RBRACE
|			|	ATTRIBUTE  QNAME  LBRACE  Expr  RBRACE
|			|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  RBRACE
|			|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	CompAttrConstructor();
	~CompAttrConstructor();

};


// [112] CompTextConstructor
// -------------------------
class CompTextConstructor : public parsenode
/*______________________________________________________________________
|
|	::= TEXT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	CompTextConstructor();
	~CompTextConstructor();

};


// [113] CompCommentConstructor
// ----------------------------
class CompCommentConstructor : public parsenode
/*______________________________________________________________________
|
|	::= COMMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
public:
	CompCommentConstructor();
	~CompCommentConstructor();

};


// [114] CompPIConstructor
// -----------------------
class CompPIConstructor : public parsenode
/*______________________________________________________________________
|
|	::= PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
|			|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
|			|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
|			|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
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
public:
	ItemType();
	~ItemType();

};


// [120] AtomicType
// ----------------
class AtomicType : public parsenode
/*______________________________________________________________________
|
|	::= QNAME
|_______________________________________________________________________*/
{
public:
	AtomicType();
	~AtomicType();

};


// [121] KindTest
// --------------
class KindTest : public parsenode
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
class AnyKindTest : public parsenode
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
class DocumentTest : public parsenode
/*______________________________________________________________________
|
|	::= DOCUMENT_NODE_LPAR  RPAR
|			|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
|			|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
|_______________________________________________________________________*/
{
public:
	DocumentTest();
	~DocumentTest();

};


// [124] TextTest
// --------------
class TextTest : public parsenode
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
class CommentTest : public parsenode
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
class PITest : public parsenode
/*______________________________________________________________________
|
|	::= PI_LPAR  RPAR
|			|	PI_LPAR  NCNAME  RPAR
|			|	PI_LPAR  STRING_LITERAL  RPAR
|_______________________________________________________________________*/
{
public:
	PITest();
	~PITest();

};


// [127] AttributeTest
// -------------------
class AttributeTest : public parsenode
/*______________________________________________________________________
|
|	::= ATTRIBUTE_LPAR  RPAR
|			|	ATTRIBUTE_LPAR  AttribNameOrWildcard  RPAR
|			|	ATTRIBUTE_LPAR  AttribNameOrWildcard  COMMA  TypeName  RPAR
|_______________________________________________________________________*/
{
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


}	/* namespace xqp */
#endif	/*  XQP_PARSENODES_H */
