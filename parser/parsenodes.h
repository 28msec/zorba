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
	VersionDecl(
		std::string const& version,
		std::string const& encoding);
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
|	::= Prolog  QueryBody | QueryBody
|_______________________________________________________________________*/
{
protected:
	rchandle<Prolog> prolog_h;
	rchandle<QueryBody> query_body_h;

public:
	MainModule(
		rchandle<Prolog>,
		rchandle<QueryBody>);
	MainModule(
		rchandle<QueryBody>);
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
	rchandle<ModuleDecl> decl_h;
	rchandle<Prolog> prolog_h;

public:
	LibraryModule(
		rchandle<ModuleDecl>, 
		rchandle<Prolog>);
	LibraryModule();
	~LibraryModule();

public:
	rchandle<ModuleDecl> get_decl() const { return decl_h; }
	rchandle<Prolog> get_prolog() const { return prolog_h; }

};



// [5] ModuleDecl
// --------------
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
	ModuleDecl(
		std::string const& prefix,
		std::string const& target_namespace);
	ModuleDecl();
	~ModuleDecl();

public:
	std::string get_prefix() const { return prefix; }
	std::string get_target_namespace() const { return target_namespace; }

};


// [6] Prolog
// ----------
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
	Prolog(
		rchandle<SIND_DeclList>,
		rchandle<VFO_DeclList>);
	Prolog();
	~Prolog();

public:
	rchandle<SIND_DeclList> get_sind_list() const { return sind_list_h; }
	rchandle<VFO_DeclList> get_vfo_list() const { return vfo_list_h; }

};



// [6a] SIDN_DeclList
// ------------------
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
	~SIND_DeclList();

public:
	void push_back(rchandle<SIND_Decl> sind_h) { sind_hv.push_back(sind_h); }
	rchandle<SIND_Decl> operator[](int k) const { return sind_hv[k]; }

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
	~VFO_DeclList();

public:
	void push_back(rchandle<VFO_Decl> vfo_h) { vfo_hv.push_back(vfo_h); }
	rchandle<VFO_Decl> operator[](int k) const { return vfo_hv[k]; }

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
	SIND_Decl() {}
	~SIND_Decl() {}

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
	VFO_Decl() {}
	~VFO_Decl() {}

};



// [7] Setter
// ----------
class Setter : public SIND_Decl
/*______________________________________________________________________
|
|	::= BoundarySpaceDecl
|			| DefaultCollationDecl
|			| BaseURIDecl
|			| ConstructionDecl
|			| OrderingModeDecl
|			| EmptyOrderDecl
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
	NamespaceDecl(
		std::string const& prefix,
		std::string const& uri);
	NamespaceDecl();
	~NamespaceDecl();

public:
	std::string get_prefix() const { return prefix; }
	std::string get_uri() const { return uri; }

};



// [11] BoundarySpaceDecl
// ----------------------
class BoundarySpaceDecl : public SIND_Decl
/*______________________________________________________________________
|
|	::= DECLARE_BOUNDARY_SPACE  ( PRESERVE | STRIP )
|_______________________________________________________________________*/
{
protected:
	static_context::boundary_space_mode_t mode;

public:
	BoundarySpaceDecl(static_context::boundary_space_mode_t);
	BoundarySpaceDecl();
	~BoundarySpaceDecl();

public:
	static_context::boundary_space_mode 
		get_boundary_space_mode() const { return mode; }

};


// [12] DefaultNamespaceDecl
// -------------------------
class DefaultNamespaceDecl : public SIND_Decl
/*______________________________________________________________________
|
|	::= DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
|			| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
|_______________________________________________________________________*/
{
public:
	enum default_namespace_mode_t {
		element,
		function
	};

protected:
	enum default_namespace_mode_t mode;
	std::string default_element_namespace;
	std::string default_function_namespace;

public:
	DefaultNamespaceDecl(
		enum default_namespace_mode_t mode,
		std::string const& default_namespace);
	DefaultNamespaceDecl();
	~DefaultNamespaceDecl();

public:
	enum default_namespace_mode_t get_mode() const { return mode; }
	std::string get_default_element_namespace() const
		{ return default_element_namespace; }
	std::string get_default_function_namespace() const
		{ return default_function_namespace; }

};



// [13] OptionDecl
// ---------------
class OptionDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_OPTION  QNAME  STRING_LITERAL
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> qname_h;
	std::string val;

public:
	OptionDecl(rchandle<QName> qname_h, std::string const& val);
	OptionDecl();
	~OptionDecl();

public:
	rchandle<QName> get_qname() const { return qname_p; }
	std::string get_val() const { return val; }

};



// [14] OrderingModeDecl
// ---------------------
class OrderingModeDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_ORDERING  ( ORDERED | UNORDERED )
|_______________________________________________________________________*/
{
protected:
	static_context::ordering_mode_t mode;
		
public:
	OrderingModeDecl(static_context::ordering_mode);
	OrderingModeDecl();
	~OrderingModeDecl();
	
public:
	static_context::ordering_mode
		get_ordering_mode() const { return mode; }

};



// [15] EmptyOrderDecl
// -------------------
class EmptyOrderDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
|			|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
|_______________________________________________________________________*/
{
protected:
	static_context::empty_order_mode_t mode;

public:
	EmptyOrderDecl(static_context::empty_order_mode_t);
	EmptyOrderDecl();
	~EmptyOrderDecl();
	
public:
	static_context::empty_order_mode_t
		get_mode() const { return mode; }

};



// [16] CopyNamespacesDecl
// -----------------------
class CopyNamespacesDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_COPY_NAMESPACES  PreserveMode  COMMA  InheritMode
|_______________________________________________________________________*/
{
protected:
	rchandle<PreserveMode> preserve_h;
	rchandle<InheritMode> inherit_h;

public:
	CopyNamespacesDecl(
		rchandle<PreserveMode>,
		rchandle<InheritMode>);
	CopyNamespacesDecl();
	~CopyNamespacesDecl();

public: 
	rchandle<PreserveMode> get_preserve() const { return preserve_h; }
	rchandle<InheritMode> get_inherit() const { return inherit_h; }

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
	static_context::preserve_mode_t preserve_mode;

public:
	PreserveMode(static_context::preserve_mode_t);
	PreserveMode();
	~PreserveMode();

public:
	static_context::preserve_mode_t
		get_preserve_mode() const { return preserve_mode; }

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
	static_context::inherit_mode_t inherit_mode;
	
public:
	InheritMode(static_context::inherit_mode mode_t);
	InheritMode();
	~InheritMode();

public:
	static_context::inherit_mode_t
		get_inherit_mode() const { return inherit_mode; }

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
	DefaultCollationDecl(std::string const&  collation);
	DefaultCollationDecl();
	~DefaultCollationDecl();

public:
	std::string get_collation() const { return collation; }

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
	BaseURIDecl(std::string const& base_uri);
	BaseURIDecl();
	~BaseURIDecl();

public:
	std::string get_base_uri() const { return base_uri; }

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
	std::string uri;
	rchandle<URI_LITERALList> at_list_h;

public:
	SchemaImport(
		std::string const& uri);
	SchemaImport(
		rchandle<SchemaPrefix>,
		std::string const& uri);
	SchemaImport(
		std::string const& uri,
		rchandle<URI_LITERALList>);
	SchemaImport(
		rchandle<SchemaPrefix>,
		std::string const& uri,
		rchandle<URI_LITERALList>);
	SchemaImport();
	~SchemaImport();

public:
	rchandle<SchemaPrefix> get_prefix() const { return prefix_h; }
	std::string get_uri() const { return uri; }
	rchandle<URI_LITERALList> get_at_list() const { return at_list_h; }
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

public:
	push_back(std::string const& uri) { uri_v.push_back(uri); }
	std::string operator[](int i) const { return uri_v[i]; }

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
	SchemaPrefix(
		std::string const& prefix;
		bool default_b);
	SchemaPrefix(
		std::string const& prefix);
	SchemaPrefix();
	~SchemaPrefix();

public:
	std::string get_prefix() const { return prefix; }
	bool get_default_bit() const { return default_b; }

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
	ModuleImport(
		std::string const& uri);
	ModuleImport(
		std::string const& prefix,
		std::string const& uri);
	ModuleImport(
		std::string const& uri,
		rchandle<URI_LITERALList>);
	ModuleImport(
		std::string const& prefix,
		std::string const& uri,
		rchandle<URI_LITERALList>);
	ModuleImport();
	~ModuleImport();

public:
	std::string get_prefix() const { return prefix; }
	std::string get_uri() const { return uri; }
	rchandle<URI_LITERALList> get_uri_list() const { return uri_list_h; }

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
	VarDecl(
		std::string varname,
		rchandle<ExprSingle>);
	VarDecl(
		std::string varname,
		bool extern_b);
	VarDecl(
		std::string varname,
		rchandle<TypeDeclaration>,
		rchandle<ExprSingle>);
	VarDecl(
		std::string varname,
		rchandle<TypeDeclaration>,
		bool extern_b);
	VarDecl();
	~VarDecl();

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<ExprSingle> get_initval() const { return initval_h; }
	bool get_extern_bit() const { return extern_b; }

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
protected:
	enum static_context::boundary_space_t mode;

public:
	ConstructionDecl(
		enum static_context::boundary_space_t mode);
	ConstructionDecl();
	~ConstructionDecl();

public:
	enum static_context::boundary_space_t get_mode() const { mode; }

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
|
|_______________________________________________________________________*/
{
public:
	enum function_type_t {
		extern,
		read,
		update,
		extern_update,
	};

protected:
	enum function_type_t type;
	rchandle<QName> name_h;
	rchandle<ParamList> paramlist_h;
	rchandle<ExclosedExpr> body_h;
	rchandle<SequenceType> return_type_h;
	bool extern_b;

public:
	FunctionDecl(
		rchandle<QName>,
		enum function_type_t type);
	FunctionDecl(
		rchandle<QName>,
		rchandle<ExclosedExpr>,
		enum function_type_t type);
	FunctionDecl(
		rchandle<QName>,
		rchandle<ParamList>,
		enum function_type_t type);
	FunctionDecl(
		rchandle<QName>,
		rchandle<ParamList>,
		rchandle<ExclosedExpr>,
		enum function_type_t type);
	FunctionDecl(
		rchandle<QName>,
		rchandle<SequenceType>,
		enum function_type_t type);
	FunctionDecl(
		rchandle<QName>,
		rchandle<ParamList>,
		rchandle<ExclosedExpr>,
		enum function_type_t type);
	FunctionDecl(
		rchandle<QName>,
		rchandle<ParamList>,
		rchandle<SequenceType>,
		enum function_type_t type);
	FunctionDecl(
		rchandle<QName>,
		rchandle<ParamList>,
		rchandle<SequenceType>,
		rchandle<ExclosedExpr>,
		enum function_type_t type);

	FunctionDecl();
	~FunctionDecl();

public:
	rchandle<QName> get_name() const { return name_h; }
	rchandle<ParamList> get_paramlist() const { return paramlist_h; }
	rchandle<ExclosedExpr> get_body() const { return body_h; }
	rchandle<SequenceType> get_return_type() const { return return_type_h; }
	enum function_type_t get_type() const { return type; }

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

public:
	void push_back(rchandle<Param> param_h) { param_hv.push_back(param_h); }
	rchandle<Param> operator[](int i) const { return param_hv[i]; }

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
	Param(
		std::string name,
		rchandle<TypeDeclaration>);
	Param();
	~Param();

public:
	std::string get_name() const { get_name; }
	rchandle<TypeDeclaration> get_typedecl() const { get_typedecl_h; }

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
	EnclosedExpr(rchandle<Expr>);
	EnclosedExpr();
	~EnclosedExpr();

public:
	rchandle<Expr> get_expr() const { return expr_h; }
	
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
	QueryBody(rchandle<Expr>);
	QueryBody();
	~QueryBody();

public:
	rchandle<Expr> get_expr() const { return expr_h; }
	
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
	std::vector<rchandle<ExprSingle> > expr_hv;

public:
	Expr();
	~Expr();

public:
	void push_back(rchandle<ExprSingle> expr_h) { expr_hv.push_back(expr_h); }
	rchandle<ExprSingle> operator[](int i) const { return expr_hv[i]; }

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
	FLWORExpr(
		rchandle<ForLetClauseList>,
		rchandle<ExprSingle>);
	FLWORExpr(
		rchandle<ForLetClauseList>,
		rchandle<WhereClause>,
		rchandle<ExprSingle>);
	FLWORExpr(
		rchandle<ForLetClauseList>,
		rchandle<OrderByClause>,
		rchandle<ExprSingle>);
	FLWORExpr(
		rchandle<ForLetClauseList>,
		rchandle<WhereClause>,
		rchandle<OrderByClause>,
		rchandle<ExprSingle>);
	FLWORExpr();
	~FLWORExpr();

public:
	rchandle<ForLetClauseList> get_forlet_list() const { return forlet_list_h; }
	rchandle<WhereClause> get_where() const { return where_h; }
	rchandle<OrderByClause> get_orderby() const { return orderby_h; }
	rchandle<ExprSingle> get_return_val() const { return return_val_h; }

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

public:
	void push_back(rchandle<ForLetClause> forlet_h) { forlet_hv.push_back(forlet_h); }
	rchandle<ForLetClause> operator[](int i) const { return forlet_hv[i]; }

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
	ForClause(
		rchandle<VarInDeclList>);
	ForClause();
	~ForClause();

public:
	rchandle<VarInDeclList> get_vardecl_list() const { return vardecl_list_h; }

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

public:
	void push_back(rchandle<VarInDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }
	rchandle<VarInDecl> operator[](int i) const { return vardecl_hv[i]; }

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
	rchandle<ExprSingle> valexpr_h;
	
public:
	VarInDecl(
		std::string varname,
		rchandle<ExprSingle>);
	VarInDecl(
		std::string varname,
		rchandle<TypeDeclaration>
		rchandle<ExprSingle>);
	VarInDecl(
		std::string varname,
		rchandle<PositionalVar>
		rchandle<ExprSingle>);
	VarInDecl(
		std::string varname,
		rchandle<TypeDeclaration>
		rchandle<PositionalVar>
		rchandle<ExprSingle>);
	VarInDecl(
		std::string varname,
		rchandle<FTScoreVar>
		rchandle<ExprSingle>);
	VarInDecl(
		std::string varname,
		rchandle<TypeDeclaration>
		rchandle<FTScoreVar>
		rchandle<ExprSingle>);
	VarInDecl(
		std::string varname,
		rchandle<PositionalVar>
		rchandle<FTScoreVar>
		rchandle<ExprSingle>);
	VarInDecl(
		std::string varname,
		rchandle<TypeDeclaration>
		rchandle<PositionalVar>
		rchandle<FTScoreVar>
		rchandle<ExprSingle>);

	VarInDecl();
	~VarInDecl();

public:
	std::string get_varname() const { return get_varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return get_typedecl_h; }
	rchandle<PositionalVar> get_posvar() const { return get_posvar_h; }
	rchandle<FTScoreVar> get_ftscorevar() const { return get_ftscorevar_h; }
	rchandle<ExprSingle> get_valexpr() const { return get_valexpr_h; }

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
	PositionalVar(std::string const& varname);
	PositionalVar();
	~PositionalVar();

public:
	std::string get_varname() const { return varname; }
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
	LetClause(rchandle<VarGetsDeclList>);
	LetClause();
	~LetClause();

public:
	rchandle<VarGetsDeclList> get_vardecl_list() const { return vardecl_list_h; }

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

public:
	void push_back(rchandle<VarGetsDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }
	rchandle<VarGetsDecl> operator[](int i) const { return vardecl_hv[i]; }

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
	rchandle<ExprSingle> valexpr_h;

public:
	VarGetsDecl(
		std::string varname,
		rchandle<TypeDeclaration>
		rchandle<FTScoreVar>
		rchandle<ExprSingle>);
	VarGetsDecl();
	~VarGetsDecl();

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<FTScoreVar> get_scorevar() const { return scorevar_h; }
	rchandle<ExprSingle> get_valexpr() const { return valexpr_h; }
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
	WhereClause(rchandle<ExprSingle>);
	WhereClause();
	~WhereClause();

public:
	rchandle<ExprSingle> get_predicate() const { return predicate_h; }
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
	OrderByClause(rchandle<OrderSpecList>, bool stable_b);
	OrderByClause(rchandle<OrderSpecList>);
	OrderByClause();
	~OrderByClause();

public:
	rchandle<OrderSpecList> get_spec_list() const { return spec_list_h; }
	bool get_stable_bit() const { return stable_b; }
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

public:
	void push_back(rchandle<OrderSpec> spec_h) { spec_hv.push_back(spec_h); }
	rchandle<OrderSpec> operator[](int i) const { return spec_hv[i]; }

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
		rchandle<ExprSingle>,
		rchandle<OrderModifier>);
	OrderSpec();
	~OrderSpec();

public:
	rchandle<ExprSingle> get_spec() const { return spec_h; }
	rchandle<OrderModifier> get_modifier() const { return modifier_h; }

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
		rchandle<OrderDirSpec>,
		rchandle<OrderEmptySpec>,
		rchandle<OrderCollationSpec>);
	OrderModifier();
	~OrderModifier();

public:
	rchandle<OrderDirSpec> get_dir_spec() const
		{ return dir_spec_h; }
	rchandle<OrderEmptySpec> get_empty_spec() const
		{ return empty_spec_h; }
	rchandle<OrderCollationSpec> get_collation_spec() const
		{ return collation_spec_h; }

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
	OrderDirSpec(enum dir_spec_t dir_spec);
	OrderDirSpec();
	~OrderDirSpec();
	
public:
	enum dir_spec_t get_dir_spec() const { return dir_spec; }

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
	OrderEmptySpec(
		static_context::empty_order_mode empty_order_spec);
	OrderEmptySpec();
	~OrderEmptySpec();

public:
	static_context::empty_order_mode get_empty_order_spec() const
		{ return empty_order_spec; }
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
	OrderCollationSpec(std::string const& uri);
	OrderCollationSpec();
	~OrderCollationSpec();

public:
	std::string get_uri() const { return uri; }

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
	QuantifiedExpr(
		quantification_mode_t qmode,
		rchandle<QVarInDeclList>);
	QuantifiedExpr();
	~QuantifiedExpr();

public:
	quantification_mode_t get_qmode() const { return qmode; }
	rchandle<QVarInDeclList> get_qvar_decl_list() const
		{ return qvar_decl_list_h; }

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

public:
	void push_back(rchandle<QVarInDecl> decl_h) { decl_hv.push_back(decl_h); }
	rchandle<QVarInDecl> operator[](int i) const { return decl_hv[i]; }

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
	QVarInDecl(
		std::string name,
		rchandle<TypeDeclaration>,
		rchandle<ExprSingle>);
	QVarInDecl();
	~QVarInDecl();

public:
	std::string get_name() const { name;
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<ExprSingle> get_val() const { return val_h; }

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
	TypeswitchExpr(
		rchandle<Expr>,
		rchandle<CaseClauseList>,
		std::string default_varname;
		rchandle<ExprSingle>);
	TypeswitchExpr();
	~TypeswitchExpr();

public:
	rchandle<Expr> get_switch_expr() const { return switch_expr_h; }
	rchandle<CaseClauseList> get_clause_list() const { return clause_list_h; }
	std::string get_default_varname() const { return default_varname; }
	rchandle<ExprSingle> get_default_clause() const { return default_clause_h; }

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

public:
	void push_back(rchandle<CaseClause> clause_h) { clause_hv.push_back(clause_h); }
	rchandle<CaseClause> operator[](int i) const { return clause_hv[i]; }

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
	CaseClause(
		std::string varname,
		rchandle<SequenceType>,
		rchandle<ExprSingle>);
	CaseClause();
	~CaseClause();

public:
	std::string get_varname() const { return varname; }
	rchandle<SequenceType> get_type() const { return type_h; }
	rchandle<ExprSingle> get_val() const { return val_h; }

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
	IfExpr(
		rchandle<Expr>,
		rchandle<ExprSingle>,
		rchandle<ExprSingle>);
	IfExpr();
	~IfExpr();

public:
	rchandle<Expr> get_cond_expr() const { return cond_expr_h; }
	rchandle<ExprSingle> get_then_expr() const { return then_expr_h; }
	rchandle<ExprSingle> get_else_expr() const { return else_expr_h; }

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
	rchandle<OrExpr> or_expr_h;
	rchandle<AndExpr> and_expr_h;

public:
	OrExpr(
		rchandle<OrExpr>,
		rchandle<AndExpr>);
	OrExpr();
	~OrExpr();

public:
	rchandle<OrExpr> get_or_expr() const { return or_expr_h; }
	rchandle<AndExpr> get_and_expr() const { return and_expr_h; }

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
	AndExpr(
		rchandle<ComparisonExpr>,
		rchandle<AndExpr>);
	AndExpr();
	~AndExpr();

public:
	rchandle<ComparisonExpr> get_comp_expr() const { return comp_expr_h; }
	rchandle<AndExpr> get_and_expr() const { return and_expr_h; }

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
	rchandle<GeneraleComp> gencomp_h;
	rchandle<NodeComp> nodecomp_h;

public:
	ComparisonExpr(
		rchandle<FTContainsExpr>,
		rchandle<FTContainsExpr>,
		rchandle<ValueComp>);
	ComparisonExpr(
		rchandle<FTContainsExpr>,
		rchandle<FTContainsExpr>,
		rchandle<GeneraleComp>);
	ComparisonExpr(
		rchandle<FTContainsExpr>,
		rchandle<FTContainsExpr>,
		rchandle<NodeComp>);
	ComparisonExpr();
	~ComparisonExpr();

public:
	rchandle<FTContainsExpr> get_left() const { return left_h; }
	rchandle<FTContainsExpr> get_right() const { return right_h; }
	rchandle<ValueComp> get_valcomp() const { return valcomp_h; }
	rchandle<GeneraleComp> get_gencomp() const { return gencomp_h; }
	rchandle<NodeComp> get_nodecomp() const { return nodecomp_h; }

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
	ValueCompExpr(
		rchandle<RangeExpr>,
		rchandle<FTSelection>,
		rchandle<FTIgnoreOption>);
	ValueCompExpr();
	~ValueCompExpr();

public:
	rchandle<RangeExpr> get_range_expr() const { return range_expr_h; }
	rchandle<FTSelection> get_ftselect() const { return ftselect_h; }
	rchandle<FTIgnoreOption> get_ftignore() const { return ftignore_h; }

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
	RangeExpr(
		rchandle<AdditiveExpr>,
		rchandle<AdditiveExpr>);
	RangeExpr();
	~RangeExpr();

public:
	rchandle<AdditiveExpr> get_from_expr() const { return from_expr_h; }
	rchandle<AdditiveExpr> get_to_expr() const { return to_expr_h; }

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
public:
	enum add_op_t {
		plus,
		minus
	};

protected:
	enum add_op_t add_od;
	rchandle<AdditiveExpr> add_expr_h;
	rchandle<MultiplicativeExpr> mult_expr_h;

public:
	AdditiveExpr(
		enum add_op_t add_op,
		rchandle<AdditiveExpr>,
		rchandle<MultiplicativeExpr>);
	AdditiveExpr();
	~AdditiveExpr();

public:
	enum add_op_t get_add_op() const { return add_op; }
	rchandle<AdditiveExpr> get_add_expr() const { return add_expr_h; }
	rchandle<MultiplicativeExpr> get_mult_expr() const { return mult_expr_h; }

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
	rchandle<MultiplicativeExpr> mult_expr_h;
	rchandle<UnionExpr> union_expr_h;
	enum mult_op_t op;

public:
	MultiplicativeExpr(
		rchandle<MultiplicativeExpr>,
		rchandle<UnionExpr>,
		enum mult_op_t);
	MultiplicativeExpr();
	~MultiplicativeExpr();

public:
	rchandle<MultiplicativeExpr> get_mult_expr() const { return mult_expr_h; }
	rchandle<UnionExpr> get_union_expr() const { return union_expr_h; }
	enum mult_op get_op() const { return op; }

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
	rchandle<UnionExpr> union_expr_h;
	rchandle<IntersectExceptExpr> intex_expr_h;

public:
	UnionExpr(
		rchandle<UnionExpr>,
		rchandle<IntersectExceptExpr>);
	UnionExpr();
	~UnionExpr();

public:
	rchandle<UnionExpr> union_expr() const { return union_expr_h; }
	rchandle<IntersectExceptExpr> intex_expr() const { return intex_expr_h; }

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
	rchandle<IntersectExceptExpr> intex_expr_h;
	rchandle<InstanceofExpr> instof_expr_h;
	enum mult_op_t op;

public:
	IntersectExceptExpr(
		rchandle<IntersectExceptExpr>,
		rchandle<InstanceofExpr>,
		enum intex_op_t op);
	IntersectExceptExpr();
	~IntersectExceptExpr();

public:
	rchandle<IntersectExceptExpr> get_intex_expr() const { return intex_expr_h; }
	rchandle<InstanceofExpr> get_instof_expr() const { return instof_expr_h; }
	enum mult_op_t get_op() const { return op; }

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
	InstanceofExpr(
		rchandle<TreatExpr>,
		rchandle<SequenceType>);
	InstanceofExpr();
	~InstanceofExpr();

public:
	rchandle<TreatExpr> get_treat_expr() const { return treat_expr_h; }
	rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

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
	TreatExpr(
		rchandle<CastableExpr>,
		rchandle<SequenceType>);
	TreatExpr();
	~TreatExpr();

public:
	rchandle<CastableExpr> get_treat_expr() const { return treat_expr_h; }
	rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

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
	CastableExpr(
		rchandle<CastExpr>,
		rchandle<SingleType>);
	CastableExpr();
	~CastableExpr();

public:
	rchandle<CastExpr> cast_expr() const { return cast_expr_h; }
	rchandle<SingleType> singletype() const { return singletype_h; }

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
	CastExpr(
		rchandle<UnaryExpr>
		rchandle<SingleType>);
	CastExpr();
	~CastExpr();

public:
	rchandle<UnaryExpr> get_unary_expr() const { return unary_expr_h; }
	rchandle<SingleType> get_singletype() const { return singletype_h; }

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
	UnaryExpr(
		rchandle<ValueExpr>,
		rchandle<SignList>);
	UnaryExpr();
	~UnaryExpr();

public:
	rchandle<ValueExpr> get_value_expr() const { return value_expr_h; }
	rchandle<SignList> get_signlist() const { return signlist_h; }

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

public:
	void push_back(bool sign) { signv.push_back(sign); }
	bool operator[](int i) const { return signv[i]; }
	bool sign() const;

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
	GeneralComp(enum gencomp_t);
	GeneralComp();
	~GeneralComp();

public:
	enum gencomp_t get_type() const { return type; }
	
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
	ValueComp(enum valcomp_t);
	ValueComp();
	~ValueComp();

public:
	enum valcomp_t get_type() const { return type; }
	
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
	NodeComp(enum nodecomp_t);
	NodeComp();
	~NodeComp();

public:
	enum nodecomp_t get_type() const { return type; }
	
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
	ValidateExpr(
		rchandle<Expr>,
		validatemode_t valmode);
	ValidateExpr();
	~ValidateExpr();

public:
	rchandle<Expr> get_expr() const { return expr_h; }
	validatemode_t get_valmode() const { return valmode; }

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
	ExtensionExpr(
		rchandle<PragmaList>,
		rchandle<Expr>);
	ExtensionExpr();
	~ExtensionExpr();

public:
	rchandle<PragmaList> get_pragma_list() const { return pragma_list_h; }
	rchandle<Expr> get_expr() const { return expr_h; }

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

public:
	void push_back(rchandle<Pragma> pragma_h) { pragma_hv.push_back(pragma_h); }
	rchandle<Pragma> operator[](int i) const { return pragma_hv[i]; }

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
		rchandle<QName>,
		std::string pragma_lit);
	Pragma();
	~Pragma();

public:
	rchandle<QName> get_name() cost { return name; }
	std::string get_pragma_lit() const { return pragma_lit; }

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
	PathExpr(
		enum pathtype_t type,
		rchandle<RelatvePathExpr>);
	PathExpr();
	~PathExpr();

public:
	enum pathtype_t get_type() const { return type; }
	rchandle<RelatvePathExpr> get_relpath_expr() const { return relpath_expr_h; }

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
	RelativePathExpr(
		rchandle<RelativePathExpr>,
		rchandle<StepExpr>);
	RelativePathExpr();
	~RelativePathExpr();

public:
	rchandle<RelativePathExpr> get_relpath_expr() const { return relpath_expr_h; }
	rchandle<StepExpr> get_step_expr() const { return step_expr_h; }

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
	AxisStep(
		rchandle<ForwardStep>,
		rchandle<PredicateList>);
	AxisStep(
		rchandle<ReverseStep>,
		rchandle<PredicateList>);
	AxisStep();
	~AxisStep();

public:
	rchandle<ForwardStep> get_forward_step() const { return forward_step_h; }
	rchandle<ReverseStep> get_reverse_step() const { return reverse_step_h; }
	rchandle<PredicateList> get_predicate_list() const { return predicate_list_h; }

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
	ForwardStep(
		rchandle<ForwardAxis>,
		rchandle<NodeTest>);
	ForwardStep(
		rchandle<AbbreviatedForwardStep>);
	ForwardStep();
	~ForwardStep();

public:
	rchandle<ForwardAxis> get_forward_axis() const { return forward_axis_h; }
	rchandle<NodeTest> get_node_test() const { return node_test_h; }
	rchandle<AbbreviatedForwardStep> get_abbrev_step() const { return abbrev_step_h; }

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
	ForwardAxis(enum forward_axis_t);
	ForwardAxis();
	~ForwardAxis();

public:
	enum forward_axis_t get_axis() const { return axis; }

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
	AbbrevForwardStep( rchandle<NodeTest>, bool attr_b );
	AbbrevForwardStep( rchandle<NodeTest> );
	AbbrevForwardStep();
	~AbbrevForwardStep();

public:
	rchandle<NodeTest> get_node_test() const { return node_test_h; }
	bool get_attr_bit() const { return attr_b; }

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
	ReverseStep(
		rchandle<ReverseAxis>,
		rchandle<NodeTest>);
	ReverseStep();
	~ReverseStep();

public:
	rchandle<ReverseAxis> get_axis() const { return axis_h; }
	rchandle<NodeTest> get_node_test() const { return node_test_h; }

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

public:
	void push_back(rchandle<Predicate> pred_h) { pred_hv.push_back(pred_h); }
	rchandle<Predicate> operator[](int i) { return pred_hv[i]; }

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

public:
	void push_back(rchandle<ExprSingle> arg_h) { arg_hv.push_back(arg_h); }
	rchandle<ExprSingle> operator[](int i) const { return arg_hv[i]; }

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
	std::vector<rchandle<DirElemContent> > dir_content_hv;

public:
	DirElemContentList();
	~DirElemContentList();

public:
	void push_back(rchandle<DirElemContent> dir_content_h)
		{ dir_content_hv.push_back(dir_content_h); }
	rchandle<DirElemContent> operator[](int i) const
		{ return dir_content_hv[i]; }

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

public:
	void push_back(rchandle<DirAttr> dir_attr_h)
		{ dir_attr_hv.push_back(dir_attr_h); }
	rchandle<DirAttr> operator[](int i)
		{ return dir_attr_hv[i]; }

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

public:
	void push_back(rchandle<QuoteAttrValueContent> quot_atval_content_h)
		{ quot_atval_content_hv.push_back(quot_atval_content_h); }
	rchandle<QuoteAttrValueContent> operator[](int i) const
		{ return quot_atval_content_hv[i]; }

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

public:
	void push_back(rchandle<AposAttrValueContent> apos_atval_content_h)
		{ apos_atval_content_hv.push_back(apos_atval_content_h); }
	rchandle<AposAttrValueContent> operator[](int i) const
		{ return apos_atval_content_hv[i]; }

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
protected:
	rchandle<QName> qname_h;

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
protected:
	rchandle<ExprSingle> source_expr_h;
	rchandle<ExprSingle> target_expr_h;

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
protected:
	rchandle<ExprSingle> target_expr_h;

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
protected:
	rchandle<ExprSingle> source_expr_h;
	rchandle<ExprSingle> target_expr_h;

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
protected:
	rchandle<ExprSingle> source_expr_h;
	rchandle<ExprSingle> target_expr_h;

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
protected:
	rchandle<VarNameList> varname_list_h;
	rchandle<ExprSingle> source_expr_h;
	rchandle<ExprSingle> target_expr_h;

public:
	TransformExpr();
	~TransformExpr();

};



// [249a] VarNameList
// ------------------
class VarNameList : public parsenode
/*______________________________________________________________________
|
|	::= VarBinding |	VarNameList  COMMA_DOLLAR  VarBinding
/*______________________________________________________________________
{
protected:
	std::vector<rchandle<VarBinding> > varbinding_hv;
	
public:
	VarNameList();
	~VarNameList();

public:
	void push_back(rchandle<VarBinding> varbinding_h)
		{ varbinding_hv.push_back(varbinding_h); }
	rchandle<VarBinding> operator[](int i) const
		{ return varbinding_hv[i]; }

};



// [249b] VarBinding
// -----------------
class VarBinding : public parsenode
/*______________________________________________________________________
|
|	::= VARNAME	 GETS  ExprSingle
/*______________________________________________________________________
{
protected:
	std::string varname;
	rchandle<ExprSingle> val_h;

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
protected:
	rchandle<FTOr> ftor_h;
	rchandle<FTMatchOptionProximityList> option_list_h;
	rchandle<RangeExpr> weight_expr_h;

public:
	FTSelection();
	~FTSelection();

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
protected:

public:
	FTMatchOptionProximityList();
	~FTMatchOptionProximityList();

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
protected:
	rchandle<FTOr> ftor_h;
	rchandle<FTAnd> ftand_h;

public:
	FTOr();
	~FTOr();
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
protected:
	rchandle<FTAnd> ftand_h;
	rchandle<FTMildNot> ftmild_not_h;

public:
	FTAnd();
	~FTAnd();

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
protected:
	rchandle<FTMildNot> ftmild_not_h;
	rchandle<FTUnaryNot> ftunary_not_h;

public:
	FTMildNot();
	~FTMildNot();

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
protected:
	rchandle<FTWordsSelection> words_selection_h;
	bool not_b;

public:
	FTUnaryNot();
	~FTUnaryNot();
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
protected:
	rchandle<FTWords> words_h;
	rchandle<FTTimes> times_h;
	rchandle<FTSelection> selection_h;

public:
	FTWordsSelection();
	~FTWordsSelection();

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
protected:
	rchandle<FTWordsValue> words_val_h;
	rchandle<FTAnyallOption> any_all_option_h;

public:
	FTWords();
	~FTWords();

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
protected:
	rchandle<Literal> lit_h;
	rchandle<Expr> expr_h;

public:
	FTWordsValue();
	~FTWordsValue();

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
	FTProximity();
	~FTProximity();

};



//[353]	FTOrderedIndicator
//------------------------
class FTOrderedIndicator : public FTProximity
/*______________________________________________________________________
|
|	::=	ORDERED
|_______________________________________________________________________*/
{
public:
	FTOrderedIndicator();
	~FTOrderedIndicator();

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
	FTMatchOption();
	~FTMatchOption();

};



//[355] FTCaseOption
//------------------
class FTCaseOption : public FTMatchOption
/*______________________________________________________________________
|
|	::=	LOWERCASE
|			| UPPERCASE
|			| CASE_SENSITIVE
|			| CASE_INSENSITIVE
|_______________________________________________________________________*/
{
public:
	enum ft_diacritics_mode_t {
		lowercase,
		uppercase,
		senstive,
		insensitive
	};

protected:
	ft_case_mode_t mode;

public:
	FTCaseOption();
	~FTCaseOption();

};



//[356] FTDiacriticsOption
//------------------------
class FTDiacriticsOption : public FTMatchOption
/*______________________________________________________________________
|
|	::=	WITH_DIACRITICS
|			| WITHOUT_DIACRITICS
|			| DIACRITICS_SENSITIVE
|			| DIACRITICS_INSENSITIVE
|_______________________________________________________________________*/
{
public:
	enum ft_diacritics_mode_t {
		with,
		without,
		senstive,
		insensitive
	};

protected:
	ft_diacritics_mode_t mode;

public:
	FTDiacriticsOption();
	~FTDiacriticsOption();

};



//[357] FTStemOption
//------------------
class FTStemOption : public FTMatchOption
/*______________________________________________________________________
|
|	::=	WITH_STEMMING
|			| WITHOUT_STEMMING
|_______________________________________________________________________*/
{
public:
	enum ft_stem_mode_t {
		with,
		without
	};

protected:
	ft_stem_mode_t mode;

public:
	FTStemOption();
	~FTStemOption();

};



//[358] FTThesaurusOption
//-----------------------
class FTThesaurusOption : public FTMatchOption
/*______________________________________________________________________
|
|	::=	WITH_THESAURUS  FTThesaurusID
|			|	WITH_THESAURUS  DEFAULT
|			| WITH_THESAURUS  LPAR  FTThesaurusList  RPAR
|			| WITH_THESAURUS  LPAR  DEFAULT  RPAR
|			| WITH_THESAURUS  LPAR  DEFAULT  COMMA  FTThesaurusList  RPAR
|			| WITHOUT_THESAURUS
|_______________________________________________________________________*/
{
protected:
	rchandle<FTThesaurusID> thesaurusid_h;
	rchandle<FTThesaurusList> thesaurus_list_h;
	bool default_b;
	bool without_b;

public:
	FTThesaurusOption();
	~FTThesaurusOption();

};



//[358a] FTThesaurusList
//----------------------
class FTThesaurusList : public parsenode
/*______________________________________________________________________
|
|	::=	FTThesaurusID
|			| FTThesaurusList  COMMA  FTThesaurusID
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<FTThesaurusID> > thesaurus_hv;

public:
	FTThesaurusIDList();
	~FTThesaurusIDList();

public:
	void push_back(rchandle<FTThesaurusID> thesaurus_h)
		{ thesaurus_hv.push_back(thesaurus_h); }
	rchandle<FTThesaurusID> operator[](int i) const
		{ return thesaurus_hv[i]; }

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
protected:
	std::string thesaurus_name;
	std::string relationship_name;
	rchandle<FTRange> levels_h;

public:
	FTThesaurusID();
	~FTThesaurusID();

};



//[360] FTStopwordOption
//----------------------
class FTStopwordOption : public FTMatchOption
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
	enum stop_words_mode_t {
		with,
		with_default,
		without
	};

protected:
	rchandle<FTRefOrList> refor_list_h;
	rchandle<FTInclExclStringLiteralList> incl_excl_list_h;
	stop_words_mode_t mode;

public:
	FTStopwordOption();
	~FTStopwordOption();

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
protected:
	std::vector<rchandle<FTInclExclStringLiteral> > incl_excl_lit_hv;

public:
	FTInclExclStringLiteralList();
	~FTInclExclStringLiteralList();

public:
	void push_back(rchandle<FTInclExclStringLiteral> incl_excl_lit_h)
		{ incl_excl_lit_hv.push_back(incl_excl_lit_h); }
	rchandle<FTInclExclStringLiteral> operator[](int i) const
		{ return incl_excl_lit_hv[i]; }

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
protected:
	std::string at_str;
	rchandle<FTStringLiteralList> stringlit_list_h;

public:
	FTRefOrList();
	~FTRefOrList();

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
protected:
	std::vector<std::string> strlit_v;

public:
	FTStringLiteralList();
	~FTStringLiteralList();

public:
	void push_back(std::string strlit) { strlit_v.push_back(strlit); }
	std::string operator[](int i) const { return strlit_v[i]; }

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
	enum incl_excl_mode_t {
		union,
		except
	};

protected:
	rchandle<FTRefOrList> ref_or_list_h;
	incl_excl_mode_t mode;

public:
	FTInclExclStringLiteral();
	~FTInclExclStringLiteral();
};



//[363] FTLanguageOption
//----------------------
class FTLanguageOption : public FTMatchOption
/*______________________________________________________________________
|
|	::=	LANGUAGE  STRING_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string lang;

public:
	FTLanguageOption();
	~FTLanguageOption();

};



//[364] FTWildCardOption
//----------------------
class FTWildCardOption : public FTMatchOption
/*______________________________________________________________________
|
|	::=	WITH_WILDCARDS
|			| WITHOUT_WILDCARDS
|_______________________________________________________________________*/
{
protected
	bool with_b;

public:
	FTWildCardOption();
	~FTWildCardOption();

};



//[365]	FTContent
//---------------
class FTContent : public FTProximity
/*______________________________________________________________________
|
|	::=	AT_START
|			| AT_END
|			| ENTIRE_CONTENT
|_______________________________________________________________________*/
{
public:
	enum ft_content_mode_t {
		at_start,
		at_end,
		entire_content
	};

protected:
	ft_content_mode_t mode;

public:
	FTContent();
	~FTContent();

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
	enum ft_any_all_option_t {
		any,
		any_word,
		all,
		all_words,
		phrase
	};

protected:
	ft_anyall_option_t option;

public:
	FTAnyallOption();
	~FTAnyallOption();

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
	enum ft_range_mode_t {
		exactly,
		at_least,
		at_most,
		from_to
	};

protected:
	rchandle<UnionExpr> src_expr_h;
	rchandle<UnionExpr> dst_expr_h;

public:
	FTRange();
	~FTRange();

};



//[368]	FTDistance
//----------------
class FTDistance : public FTProximity
/*______________________________________________________________________
|
|	::=	DISTANCE  FTRange  FTUnit
|_______________________________________________________________________*/
{
protected:
	rchandle<FTRange> dist_h;
	rchandle<FTUnit> unit_h;

public:
	FTDistance();
	~FTDistance();

};



//[369]	FTWindow
//--------------
class FTWindow : public FTProximity
/*______________________________________________________________________
|
|	::=	WINDOW  UnionExpr  FTUnit
|_______________________________________________________________________*/
{
protected:
	rchandle<UnionExpr> window_h;
	rchandle<FTUnit> unit_h;

public:
	FTWindow();
	~FTWindow();

};



//[370]	FTTimes
//-------------
class FTTimes : public parsenode
/*______________________________________________________________________
|
|	::=	OCCURS  FTRange  TIMES
|_______________________________________________________________________*/
{
protected:
	rchandle<FTRange> range_h;

public:
	FTTimes();
	~FTTimes();

};



//[371]	FTScope
//-------------
class FTScope : public FTProximity
/*______________________________________________________________________
|
|	::=	SAME  FTBigUnit
|			|	DIFFERENT  FTBigUnit
|_______________________________________________________________________*/
{
public:
	enum ft_scope_t {
		same,
		different
	};

protected:
	ft_scope_t scope;

public:
	FTScope();
	~FTScope();

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
	enum ft_unit_t {
		words,
		sentences,
		paragraph
	};

protected:
	ft_unit_t unit;

public:
	FTUnit();
	~FTUnit();

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
	enum ft_big_unit_t {
		sentence,
		paragraph
	};

protected:
	enum ft_big_unit_t unit;

public:
	FTBigUnit();
	~FTBigUnit();

};



//[374]	FTIgnoreOption
//--------------------
class FTIgnoreOption : public parsenode
/*______________________________________________________________________
|
|	::=	WITHOUT_CONTENT  UnionExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<UnionExpr> union_h;

public:
	FTIgnoreOption();
	~FTIgnoreOption();

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
