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

#include "../context/static_context.h"
#include "../types/qname.h"
#include "../util/rchandle.h"

#include "location.hh"

namespace xqp {

/*
**  base class: syntax-only nodes
*/
class parsenode : public rcobject
{
protected:
	yy::location loc;

public:
	parsenode(yy::location const& _loc) : loc(_loc) {}
	parsenode() {}
  ~parsenode() {}

public:
	yy::location get_location() const { return loc; }

};


/*
**  base class:  nodes with values.
*/
class exprnode : public rcobject
{
protected:
	yy::location loc;

public:
	exprnode(yy::location const& _loc) : loc(_loc) {}
	exprnode() {}
  ~exprnode() {}

public:
	yy::location get_location() const { return loc; }

};


class AbbrevForwardStep;
class AdditiveExpr;
class AndExpr;
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
class CastExpr;
class CastableExpr;
class CommentTest;
class CommonContent;
class CompAttrConstructor;
class CompCommentConstructor;
class CompDocConstructor;
class CompElemConstructor;
class CompPIConstructor;
class CompTextConstructor;
class ComparisonExpr;
class ComputedConstructor;
class ConstructionDecl;
class Constructor;
//class ContentExpr;
class ContextItemExpr;
class CopyNamespacesDecl;
class DefaultCollationDecl;
class DefaultNamespaceDecl;
class DeleteExpr;
class DirAttr;
class DirAttributeList;
class DirAttributeValue;
class DirCommentConstructor;
class DirElemConstructor;
class DirElemContent;
class DirElemContentList;
class DirPIConstructor;
class DirectConstructor;
class DocumentTest;
class ElementDeclaration;
class ElementName;
class ElementNameOrWildcard;
class ElementTest;
class EmptyOrderDecl;
class EnclosedExpr;
class Expr;
class ExprSingle;
class ExtensionExpr;
class FLWORExpr;
class FTAnd;
class FTAnyallOption;
class FTBigUnit;
class FTCaseOption;
class FTContainsExpr;
class FTContent;
class FTDiacriticsOption;
class FTDistance;
class FTIgnoreOption;
class FTInclExclStringLiteral;
class FTInclExclStringLiteralList;
class FTLanguageOption;
class FTMatchOption;
class FTMatchOptionProximityList;
class FTMildnot;
class FTOr;
class FTOrderedIndicator;
class FTProximity;
class FTRange;
class FTRefOrList;
class FTScope;
class FTScoreVar;
class FTSelection;
class FTStemOption;
class FTStopwordOption;
class FTStringLiteralList;
class FTThesaurusID;
class FTThesaurusList;
class FTThesaurusOption;
class FTTimes;
class FTUnaryNot;
class FTUnit;
class FTWildcardOption;
class FTWindow;
class FTWords;
class FTWordsSelection;
class FTWordsValue;
class FilterExpr;
class ForClause;
class ForLetClause;
class ForLetClauseList;
class ForwardAxis;
class ForwardStep;
class FunctionCall;
class FunctionDecl;
class GeneralComp;
class IfExpr;
class Import;
class InheritMode;
class InsertExpr;
class InstanceofExpr;
class IntersectExceptExpr;
class ItemType;
class KindTest;
class LetClause;
class LibraryModule;
class Literal;
class MainModule;
class Module;
class ModuleDecl;
class ModuleImport;
class MultiplicativeExpr;
class NameTest;
class NamespaceDecl;
class NodeComp;
class NodeTest;
class NumericLiteral;
class OccurrenceIndicator;
class OptionDecl;
class OrExpr;
class OrderByClause;
class OrderCollationSpec;
class OrderDirSpec;
class OrderEmptySpec;
class OrderModifier;
class OrderSpec;
class OrderSpecList;
class OrderedExpr;
class OrderingModeDecl;
class PITest;
class Param;
class ParamList;
class ParenthesizedExpr;
class PathExpr;
class PositionalVar;
class Pragma;
class PragmaList;
class Predicate;
class PredicateList;
class PreserveMode;
class PrimaryExpr;
class Prolog;
//class QName;
class QVarInDecl;
class QVarInDeclList;
class QuantifiedExpr;
class QueryBody;
class QuoteAttrContentList;
class QuoteAttrValueContent;
class RangeExpr;
class RelativePathExpr;
class RenameExpr;
class ReplaceExpr;
class RevalidationDecl;
class ReverseAxis;
class ReverseStep;
class SIND_Decl;
class SIND_DeclList;
class SchemaAttributeTest;
class SchemaElementTest;
class SchemaImport;
class SchemaPrefix;
class SequenceType;
class Setter;
class SignList;
class SingleType;
class StepExpr;
class TextTest;
class TransformExpr;
class TreatExpr;
class TypeDeclaration;
class TypeName;
class TypeswitchExpr;
class URILiteralList;
class UnaryExpr;
class UnionExpr;
class UnorderedExpr;
class VFO_Decl;
class VFO_DeclList;
class ValidateExpr;
class ValueComp;
class ValueExpr;
class VarBinding;
class VarDecl;
class VarGetsDecl;
class VarGetsDeclList;
class VarInDecl;
class VarInDeclList;
class VarNameList;
class VarRef;
class VersionDecl;
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
	//rchandle<dynamic_context> dynamic_context_h;

public:
	Module(
		rchandle<static_context>);
	~Module();

public:	//manipulators
	rchandle<static_context> get_static_context() const
		{	return static_context_h; }
	//rchandle<dynamic_context> get_dynamic_context() const
	//	{	return dynamic_context_h; }

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
		yy::location const&,
		std::string const& version,
		std::string const& encoding);
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
		yy::location const&,
		rchandle<Prolog>,
		rchandle<QueryBody>);
	MainModule(
		yy::location const&,
		rchandle<QueryBody>);
	~MainModule();

public:
	rchandle<Prolog> get_prolog() const { return prolog_h; }
	rchandle<QueryBody> get_query_body() const { return query_body_h; }

};



// [4] LibraryModule
// -----------------
class LibraryModule : public parsenode
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
		yy::location const&,
		rchandle<ModuleDecl>, 
		rchandle<Prolog>);
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
		yy::location const&,
		std::string const& prefix,
		std::string const& target_namespace);
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
		yy::location const&,
		rchandle<SIND_DeclList>,
		rchandle<VFO_DeclList>);
	Prolog();
	~Prolog();

public:
	rchandle<SIND_DeclList> get_sind_list() const { return sind_list_h; }
	rchandle<VFO_DeclList> get_vfo_list() const { return vfo_list_h; }

};



// [6a] SIND_DeclList
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
	SIND_DeclList(
		yy::location const&);
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
	VFO_DeclList(
		yy::location const&);
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
	SIND_Decl(
		yy::location const&);
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
	VFO_Decl(
		yy::location const&);
	~VFO_Decl();

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
	Setter(
		yy::location const&);
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
	Import(
		yy::location const&);
	~Import();

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
		yy::location const&,
		std::string const& prefix,
		std::string const& uri);
	~NamespaceDecl();

public:
	std::string get_prefix() const { return prefix; }
	std::string get_uri() const { return uri; }

};



// [11] BoundarySpaceDecl
// ----------------------
class BoundarySpaceDecl : public Setter
/*______________________________________________________________________
|
|	::= DECLARE_BOUNDARY_SPACE  ( PRESERVE | STRIP )
|_______________________________________________________________________*/
{
protected:
	static_context::boundary_space_mode_t mode;

public:
	BoundarySpaceDecl(
		yy::location const&,
		static_context::boundary_space_mode_t);
	~BoundarySpaceDecl();

public:
	static_context::boundary_space_mode_t
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
	std::string default_namespace;

public:
	DefaultNamespaceDecl(
		yy::location const&,
		enum default_namespace_mode_t mode,
		std::string const& default_namespace);
	~DefaultNamespaceDecl();

public:
	enum default_namespace_mode_t get_mode() const { return mode; }
	std::string get_default_namespace() const { return default_namespace; }

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
	OptionDecl(
		yy::location const&,
		rchandle<QName> qname_h,
		std::string const& val);
	~OptionDecl();

public:
	rchandle<QName> get_qname() const { return qname_h; }
	std::string get_val() const { return val; }

};



/* full-text extension */
// [13a] FTOptionDecl
// ------------------
class FTOptionDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_FTOPTION  QNAME  FTMatchOption
|_______________________________________________________________________*/
{
protected:
	rchandle<QName> qname_h;
	rchandle<FTMatchOption> match_option_h;

public:
	FTOptionDecl(
		yy::location const&,
		rchandle<QName>,
		rchandle<FTMatchOption>);
	~FTOptionDecl();

public:
	rchandle<QName> get_qname() const { return qname_h; }
	rchandle<FTMatchOption> get_match_option() const { return match_option_h; }

};



// [14] OrderingModeDecl
// ---------------------
class OrderingModeDecl : public Setter
/*______________________________________________________________________
|
|	::= DECLARE_ORDERING  ( ORDERED | UNORDERED )
|_______________________________________________________________________*/
{
protected:
	static_context::ordering_mode_t mode;
		
public:
	OrderingModeDecl(
		yy::location const&,
		static_context::ordering_mode_t);
	~OrderingModeDecl();
	
public:
	static_context::ordering_mode_t get_mode() const { return mode; }

};



// [15] EmptyOrderDecl
// -------------------
class EmptyOrderDecl : public Setter
/*______________________________________________________________________
|
|	::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
|			|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
|_______________________________________________________________________*/
{
protected:
	static_context::order_empty_mode_t mode;

public:
	EmptyOrderDecl(
		yy::location const&,
		static_context::order_empty_mode_t);
	~EmptyOrderDecl();
	
public:
	static_context::order_empty_mode_t get_mode() const { return mode; }

};



// [16] CopyNamespacesDecl
// -----------------------
class CopyNamespacesDecl : public Setter
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
		yy::location const&,
		rchandle<PreserveMode>,
		rchandle<InheritMode>);
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
	static_context::copy_ns_mode_t preserve_mode;

public:
	PreserveMode(
		yy::location const&,
		static_context::copy_ns_mode_t);
	~PreserveMode();

public:
	static_context::copy_ns_mode_t
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
	static_context::copy_ns_mode_t inherit_mode;
	
public:
	InheritMode(
		yy::location const&,
		static_context::copy_ns_mode_t);
	~InheritMode();

public:
	static_context::copy_ns_mode_t
		get_inherit_mode() const { return inherit_mode; }

};



// [19] DefaultCollationDecl
// -------------------------
class DefaultCollationDecl : public Setter
/*______________________________________________________________________
|
|	::=	DECLARE_DEFAULT_COLLATION  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string collation;

public:
	DefaultCollationDecl(
		yy::location const&,
		std::string const&  collation);
	~DefaultCollationDecl();

public:
	std::string get_collation() const { return collation; }

};



// [20] BaseURIDecl
// ----------------
class BaseURIDecl : public Setter
/*______________________________________________________________________
|
|	::= DECLARE_BASE_URI  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string base_uri;

public:
	BaseURIDecl(
		yy::location const&,
		std::string const& base_uri);
	~BaseURIDecl();

public:
	std::string get_base_uri() const { return base_uri; }

};



// [21] SchemaImport
// -----------------
class SchemaImport : public Import
/*______________________________________________________________________
|
|	::= IMPORT_SCHEMA  URI_LITERAL
|			| IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL
|			|	IMPORT_SCHEMA  URI_LITERAL  AT  URILiteralList
|			|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT  URILiteralList
|_______________________________________________________________________*/
{
protected:
	rchandle<SchemaPrefix> prefix_h;
	std::string uri;
	rchandle<URILiteralList> at_list_h;

public:
	SchemaImport(
		yy::location const&,
		rchandle<SchemaPrefix>,
		std::string const& uri,
		rchandle<URILiteralList>);
	~SchemaImport();

public:
	rchandle<SchemaPrefix> get_prefix() const { return prefix_h; }
	std::string get_uri() const { return uri; }
	rchandle<URILiteralList> get_at_list() const { return at_list_h; }
};



// [21a] URLLiteralList
// --------------------
class URILiteralList : public parsenode
/*______________________________________________________________________
|
|	::= URI_LITERAL
|			| URILiteralList  COMMA  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::vector<std::string> uri_v;

public:
	URILiteralList(
		yy::location const&);
	~URILiteralList();

public:
	void push_back(std::string const& uri) { uri_v.push_back(uri); }
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
		yy::location const&,
		bool default_b);
	SchemaPrefix(
		yy::location const&,
		std::string const& prefix);
	~SchemaPrefix();

public:
	std::string get_prefix() const { return prefix; }
	bool get_default_bit() const { return default_b; }

};



// [23] ModuleImport
// -----------------
class ModuleImport : public Import
/*______________________________________________________________________
|
|	::= IMPORT_MODULE  URI_LITERAL 
|			|	IMPORT_MODULE  NAMESPACE  NCNAME  EQ  URI_LITERAL
|			|	IMPORT_MODULE  URI_LITERAL  AT  URILiteralList
|			|	IMPORT_MODULE  NAMESPACE  NCNAME  EQ  URI_LITERAL  AT  URILiteralList
|_______________________________________________________________________*/
{
protected:
	std::string prefix;
	std::string uri;
	rchandle<URILiteralList> uri_list_h;

public:
	ModuleImport(
		yy::location const&,
		std::string const& uri,
		rchandle<URILiteralList>);
	ModuleImport(
		yy::location const&,
		std::string const& prefix,
		std::string const& uri,
		rchandle<URILiteralList>);
	~ModuleImport();

public:
	std::string get_prefix() const { return prefix; }
	std::string get_uri() const { return uri; }
	rchandle<URILiteralList> get_uri_list() const { return uri_list_h; }

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
	rchandle<ExprSingle> initexpr_h;

public:
	VarDecl(
		yy::location const&,
		std::string varname,
		rchandle<TypeDeclaration>,
		rchandle<ExprSingle>);
	~VarDecl();

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<ExprSingle> get_initexpr() const { return initexpr_h; }
	bool is_extern() const { return initexpr_h==NULL; }

};



// [25] ConstructionDecl
// ---------------------
class ConstructionDecl : public Setter
/*______________________________________________________________________
|
|	::= DECLARE_CONSTRUCTION  PRESERVE
|			|	DECLARE_CONSTRUCTION  STRIP
|_______________________________________________________________________*/
{
protected:
	enum static_context::construction_mode_t mode;

public:
	ConstructionDecl(
		yy::location const&,
		enum static_context::construction_mode_t);
	~ConstructionDecl();

public:
	enum static_context::construction_mode_t get_mode() const { mode; }

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
		fn_extern,
		fn_read,
		fn_update,
		fn_extern_update,
	};

protected:
	enum function_type_t type;
	rchandle<QName> name_h;
	rchandle<ParamList> paramlist_h;
	rchandle<EnclosedExpr> body_h;
	rchandle<SequenceType> return_type_h;
	bool extern_b;

public:
	FunctionDecl(
		yy::location const&,
		rchandle<QName>,
		rchandle<ParamList>,
		rchandle<SequenceType>,
		rchandle<EnclosedExpr>,
		enum function_type_t type);
	~FunctionDecl();

public:
	rchandle<QName> get_name() const { return name_h; }
	rchandle<ParamList> get_paramlist() const { return paramlist_h; }
	rchandle<EnclosedExpr> get_body() const { return body_h; }
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
	ParamList(
		yy::location const&);
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
		yy::location const&,
		std::string name,
		rchandle<TypeDeclaration>);
	~Param();

public:
	std::string get_name() const { return name; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }

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
	EnclosedExpr(
		yy::location const&,
		rchandle<Expr>);
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
	QueryBody(
		yy::location const&,
		rchandle<Expr>);
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
	Expr(
		yy::location const&);
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
	ExprSingle(
		yy::location const&);
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
		yy::location const&,
		rchandle<ForLetClauseList>,
		rchandle<WhereClause>,
		rchandle<OrderByClause>,
		rchandle<ExprSingle>);
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
	std::vector<rchandle<ForLetClause> > forlet_hv;

public:
	ForLetClauseList(
		yy::location const&);
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
	ForLetClause(
		yy::location const&);
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
		yy::location const&,
		rchandle<VarInDeclList>);
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
	std::vector<rchandle<VarInDecl> > vardecl_hv;

public:
	VarInDeclList(
		yy::location const&);
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
		yy::location const&,
		std::string varname,
		rchandle<TypeDeclaration>,
		rchandle<PositionalVar>,
		rchandle<FTScoreVar>,
		rchandle<ExprSingle>);
	~VarInDecl();

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<PositionalVar> get_posvar() const { return posvar_h; }
	rchandle<FTScoreVar> get_ftscorevar() const { return ftscorevar_h; }
	rchandle<ExprSingle> get_valexpr() const { return valexpr_h; }

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
	PositionalVar(
		yy::location const&,
		std::string const& varname);
	~PositionalVar();

public:
	std::string get_varname() const { return varname; }
};



// [36] LetClause
// --------------
class LetClause : public ForLetClause
/*______________________________________________________________________
|
|	::= LET_DOLLAR VarGetsDeclList
|			| LET_SCORE_DOLLAR VarGetsDeclList
|_______________________________________________________________________*/
{
protected:
	rchandle<VarGetsDeclList> vardecl_list_h;

public:
	LetClause(
		yy::location const&,
		rchandle<VarGetsDeclList>);
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
	VarGetsDeclList(
		yy::location const&);
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
	rchandle<FTScoreVar> ftscorevar_h;
	rchandle<ExprSingle> valexpr_h;

public:
	VarGetsDecl(
		yy::location const&,
		std::string varname,
		rchandle<TypeDeclaration>,
		rchandle<FTScoreVar>,
		rchandle<ExprSingle>);
	~VarGetsDecl();

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<FTScoreVar> get_ftscorevar() const { return ftscorevar_h; }
	rchandle<ExprSingle> get_valexpr() const { return valexpr_h; }
};



// [36c] FTScoreVar
// ----------------
/*______________________________________________________________________
|
|	::= SCORE  DOLLAR  VarName
|______________________________________________________________________*/
class FTScoreVar : public parsenode
{
protected:
	std::string varname;

public:
	FTScoreVar(
		yy::location const&,
		std::string varname);
	~FTScoreVar();

public:
	std::string get_varname() const { return varname; }

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
	WhereClause(
		yy::location const&,
		rchandle<ExprSingle>);
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
	OrderByClause(
		yy::location const&,
		rchandle<OrderSpecList>,
		bool stable_b);
	OrderByClause(
		yy::location const&,
		rchandle<OrderSpecList>);
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
	OrderSpecList(
		yy::location const&);
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
	OrderSpec(
		yy::location const&,
		rchandle<ExprSingle>,
		rchandle<OrderModifier>);
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
	OrderModifier(
		yy::location const&,
		rchandle<OrderDirSpec>,
		rchandle<OrderEmptySpec>,
		rchandle<OrderCollationSpec>);
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
class OrderDirSpec : public parsenode
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
	OrderDirSpec(
		yy::location const&,
		enum dir_spec_t dir_spec);
	~OrderDirSpec();
	
public:
	enum dir_spec_t get_dir_spec() const { return dir_spec; }

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
protected:
	static_context::order_empty_mode_t empty_order_spec;

public:
	OrderEmptySpec(
		yy::location const&,
		static_context::order_empty_mode_t empty_order_spec);
	~OrderEmptySpec();

public:
	static_context::order_empty_mode_t get_empty_order_spec() const
		{ return empty_order_spec; }
};



// [41c] OrderCollationSpec
// ------------------------
class OrderCollationSpec : public parsenode
/*______________________________________________________________________
|
|	::= COLLATION  URI_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string uri;

public:
	OrderCollationSpec(
		yy::location const&,
		std::string const& uri);
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
	rchandle<QVarInDeclList> decl_list_h;
	rchandle<ExprSingle> expr_h;

public:
	QuantifiedExpr(
		yy::location const&,
		quantification_mode_t qmode,
		rchandle<QVarInDeclList>,
		rchandle<ExprSingle>);
	~QuantifiedExpr();

public:
	quantification_mode_t get_qmode() const { return qmode; }
	rchandle<QVarInDeclList> get_decl_list() const { return decl_list_h; }
	rchandle<ExprSingle> get_expr() const { return expr_h; }

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
	QVarInDeclList(
		yy::location const&);
	~QVarInDeclList();

public:
	void push_back(rchandle<QVarInDecl> decl_h) { qvar_decl_hv.push_back(decl_h); }
	rchandle<QVarInDecl> operator[](int i) const { return qvar_decl_hv[i]; }

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
		yy::location const&,
		std::string name,
		rchandle<ExprSingle>);
	QVarInDecl(
		yy::location const&,
		std::string name,
		rchandle<TypeDeclaration>,
		rchandle<ExprSingle>);
	~QVarInDecl();

public:
	std::string get_name() const { return name; }
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
		yy::location const&,
		rchandle<Expr>,
		rchandle<CaseClauseList>,
		rchandle<ExprSingle>);
	TypeswitchExpr(
		yy::location const&,
		rchandle<Expr>,
		rchandle<CaseClauseList>,
		std::string default_varname,
		rchandle<ExprSingle>);
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
	CaseClauseList(
		yy::location const&);
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
		yy::location const&,
		std::string varname,
		rchandle<SequenceType>,
		rchandle<ExprSingle>);
	CaseClause(
		yy::location const&,
		rchandle<SequenceType>,
		rchandle<ExprSingle>);
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
		yy::location const&,
		rchandle<Expr>,
		rchandle<ExprSingle>,
		rchandle<ExprSingle>);
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
		yy::location const&,
		rchandle<OrExpr>,
		rchandle<AndExpr>);
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
	rchandle<AndExpr> and_expr_h;
	rchandle<ComparisonExpr> comp_expr_h;

public:
	AndExpr(
		yy::location const&,
		rchandle<AndExpr>,
		rchandle<ComparisonExpr>);
	~AndExpr();

public:
	rchandle<AndExpr> get_and_expr() const { return and_expr_h; }
	rchandle<ComparisonExpr> get_comp_expr() const { return comp_expr_h; }

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
	rchandle<GeneralComp> gencomp_h;
	rchandle<NodeComp> nodecomp_h;

public:
	ComparisonExpr(
		yy::location const&,
		rchandle<FTContainsExpr>,
		rchandle<ValueComp>,
		rchandle<FTContainsExpr>);
	ComparisonExpr(
		yy::location const&,
		rchandle<FTContainsExpr>,
		rchandle<GeneralComp>,
		rchandle<FTContainsExpr>);
	ComparisonExpr(
		yy::location const&,
		rchandle<FTContainsExpr>,
		rchandle<NodeComp>,
		rchandle<FTContainsExpr>);
	~ComparisonExpr();

public:
	rchandle<FTContainsExpr> get_left() const { return left_h; }
	rchandle<FTContainsExpr> get_right() const { return right_h; }
	rchandle<ValueComp> get_valcomp() const { return valcomp_h; }
	rchandle<GeneralComp> get_gencomp() const { return gencomp_h; }
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
	FTContainsExpr(
		yy::location const&,
		rchandle<RangeExpr>,
		rchandle<FTSelection>,
		rchandle<FTIgnoreOption>);
	~FTContainsExpr();

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
		yy::location const&,
		rchandle<AdditiveExpr>,
		rchandle<AdditiveExpr>);
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
	rchandle<AdditiveExpr> add_expr_h;
	enum add_op_t add_op;
	rchandle<MultiplicativeExpr> mult_expr_h;

public:
	AdditiveExpr(
		yy::location const&,
		rchandle<AdditiveExpr>,
		enum add_op_t add_op,
		rchandle<MultiplicativeExpr>);
	~AdditiveExpr();

public:
	add_op_t get_add_op() const { return add_op; }
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
	enum mult_op_t mult_op;
	rchandle<UnionExpr> union_expr_h;

public:
	MultiplicativeExpr(
		yy::location const&,
		rchandle<MultiplicativeExpr>,
		enum mult_op_t,
		rchandle<UnionExpr>);
	~MultiplicativeExpr();

public:
	rchandle<MultiplicativeExpr> get_mult_expr() const { return mult_expr_h; }
	rchandle<UnionExpr> get_union_expr() const { return union_expr_h; }
	enum mult_op_t get_mult_op() const { return mult_op; }

};



// [52] UnionExpr
// --------------
class UnionExpr : public exprnode
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
		yy::location const&,
		rchandle<UnionExpr>,
		rchandle<IntersectExceptExpr>);
	~UnionExpr();

public:
	rchandle<UnionExpr> union_expr() const { return union_expr_h; }
	rchandle<IntersectExceptExpr> intex_expr() const { return intex_expr_h; }

};



// [53] IntersectExceptExpr
// ------------------------
class IntersectExceptExpr : public exprnode
/*______________________________________________________________________
|
|	::= InstanceofExpr
|			|	IntersectExceptExpr  INTERSECT  InstanceofExpr
|			|	IntersectExceptExpr  EXCEPT  InstanceofExpr
|_______________________________________________________________________*/
{
public:
	enum intex_op_t {
		intersect,
		except	
	};

protected:
	rchandle<IntersectExceptExpr> intex_expr_h;
	enum intex_op_t intex_op;
	rchandle<InstanceofExpr> instof_expr_h;

public:
	IntersectExceptExpr(
		yy::location const&,
		rchandle<IntersectExceptExpr>,
		enum intex_op_t,
		rchandle<InstanceofExpr>);
	~IntersectExceptExpr();

public:
	rchandle<IntersectExceptExpr> get_intex_expr() const { return intex_expr_h; }
	enum intex_op_t get_intex_op() const { return intex_op; }
	rchandle<InstanceofExpr> get_instof_expr() const { return instof_expr_h; }

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
		yy::location const&,
		rchandle<TreatExpr>,
		rchandle<SequenceType>);
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
	rchandle<CastableExpr> castable_expr_h;
	rchandle<SequenceType> seqtype_h;

public:
	TreatExpr(
		yy::location const&,
		rchandle<CastableExpr>,
		rchandle<SequenceType>);
	~TreatExpr();

public:
	rchandle<CastableExpr> get_castable_expr() const { return castable_expr_h; }
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
		yy::location const&,
		rchandle<CastExpr>,
		rchandle<SingleType>);
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
		yy::location const&,
		rchandle<UnaryExpr>,
		rchandle<SingleType>);
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
		yy::location const&,
		rchandle<SignList>,
		rchandle<ValueExpr>);
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
	bool sign;

public:
	SignList(
		yy::location const&,
		bool _sign);
	~SignList();

public:
	bool get_sign() const { return sign; }
	void negate() { sign = !sign; }

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
	ValueExpr(
		yy::location const&);
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
	GeneralComp(
		yy::location const&,
		enum gencomp_t);
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
	ValueComp(
		yy::location const&,
		enum valcomp_t);
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
	NodeComp(
		yy::location const&,
		enum nodecomp_t);
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
public:
	enum validation_mode_t {
		strict,
		lax
	};

protected:
	enum validation_mode_t valmode;
	rchandle<Expr> expr_h;

public:
	ValidateExpr(
		yy::location const&,
		std::string const& valmode,
		rchandle<Expr>);
	~ValidateExpr();

public:
	rchandle<Expr> get_expr() const { return expr_h; }
	validation_mode_t get_valmode() const { return valmode; }

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
		yy::location const&,
		rchandle<PragmaList>,
		rchandle<Expr>);
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
	PragmaList(
		yy::location const&);
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
	Pragma(
		yy::location const&,
		rchandle<QName>,
		std::string pragma_lit);
	~Pragma();

public:
	rchandle<QName> get_name() const { return name; }
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
|			|	RelativePathExpr	 								 gn:leading-lone-slashXQ
|_______________________________________________________________________*/
{
public:
	enum pathtype_t {
		leading_lone_slash,
		leading_slash,
		leading_slash_slash,
		relative
	};

protected:
	enum pathtype_t type;
	rchandle<RelativePathExpr> relpath_expr_h;

public:
	PathExpr(
		yy::location const&,
		enum pathtype_t type,
		rchandle<RelativePathExpr>);
	~PathExpr();

public:
	enum pathtype_t get_type() const { return type; }
	rchandle<RelativePathExpr> get_relpath_expr() const { return relpath_expr_h; }

};



// [68] RelativePathExpr
// ---------------------
class RelativePathExpr : public exprnode
/*______________________________________________________________________
|
|	::= StepExpr
|			| StepExpr  SLASH  RelativePathExpr
|			| StepExpr  SLASH_SLASH  RelativePathExpr 
|_______________________________________________________________________*/
{
public:
	enum steptype_t {
		step,
		slash,
		slash_slash	
	};

protected:
	enum steptype_t step_type;
	rchandle<StepExpr> step_expr_h;
	rchandle<RelativePathExpr> relpath_expr_h;

public:
	RelativePathExpr(
		yy::location const&,
		enum steptype_t,
		rchandle<StepExpr>,
		rchandle<RelativePathExpr>);
	~RelativePathExpr();

public:
	enum steptype_t get_step_type() const { return step_type; }
	rchandle<StepExpr> get_step_expr() const { return step_expr_h; }
	rchandle<RelativePathExpr> get_relpath_expr() const { return relpath_expr_h; }

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
	StepExpr(
		yy::location const&);
	~StepExpr();

};



// [70] AxisStep
// -------------
class AxisStep : public StepExpr
/*______________________________________________________________________
|
|	::= ForwardStep
|			| ForwardStep  PredicateList
|			|	ReverseStep
|			|	ReverseStep  PredicateList
|_______________________________________________________________________*/
{
protected:
	rchandle<ForwardStep> forward_step_h;
	rchandle<ReverseStep> reverse_step_h;
	rchandle<PredicateList> predicate_list_h;

public:
	AxisStep(
		yy::location const&,
		rchandle<ForwardStep>,
		rchandle<PredicateList>);
	AxisStep(
		yy::location const&,
		rchandle<ReverseStep>,
		rchandle<PredicateList>);
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
	rchandle<AbbrevForwardStep> abbrev_step_h;

public:
	ForwardStep(
		yy::location const&,
		rchandle<ForwardAxis>,
		rchandle<NodeTest>);
	ForwardStep(
		yy::location const&,
		rchandle<AbbrevForwardStep>);
	~ForwardStep();

public:
	rchandle<ForwardAxis> get_forward_axis() const { return forward_axis_h; }
	rchandle<NodeTest> get_node_test() const { return node_test_h; }
	rchandle<AbbrevForwardStep> get_abbrev_step() const { return abbrev_step_h; }

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
		following
	};

protected:
	enum forward_axis_t axis;

public:
	ForwardAxis(
		yy::location const&,
		enum forward_axis_t);
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
protected:
	rchandle<NodeTest> node_test_h;
	bool attr_b;
	
public:
	AbbrevForwardStep(
		yy::location const&,
		rchandle<NodeTest>,
		bool attr_b);
	AbbrevForwardStep(
		yy::location const&,
		rchandle<NodeTest>);
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
		yy::location const&,
		rchandle<ReverseAxis>,
		rchandle<NodeTest>);
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
	ReverseAxis(
		yy::location const&,
		enum reverse_axis_t);
	~ReverseAxis();

public:
	enum reverse_axis_t get_axis() const { return axis; }

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
	NodeTest(
		yy::location const&);
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
	rchandle<Wildcard> wild_h;

public:
	NameTest(
		yy::location const&,
		rchandle<QName>);
	NameTest(
		yy::location const&,
		rchandle<Wildcard>);
	~NameTest();

public:
	rchandle<QName> get_qname() const { return qname_h; }
	rchandle<Wildcard> get_wild() const { return wild_h; }

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
		wild_all,
		wild_elem,
		wild_prefix
	};

protected:
	enum wildcard_t type;
	std::string prefix;
	rchandle<QName> qname_h;
	
public:
	Wildcard(
		yy::location const&,
		enum wildcard_t);
	Wildcard(
		yy::location const&,
		std::string const&);
	Wildcard(
		yy::location const&,
		rchandle<QName>);
	~Wildcard();

public:
	enum wildcard_t get_type() const { return type; }
	std::string get_prefix() const { return prefix; }
	rchandle<QName> get_qname() const { return qname_h; }

};



// [80] FilterExpr
// ---------------
class FilterExpr : public StepExpr
/*______________________________________________________________________
|
|	::= PrimaryExpr  PredicateList
|			| PrimaryExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<PrimaryExpr> primary_h;
	rchandle<PredicateList> pred_list_h;

public:
	FilterExpr(
		yy::location const&,
		rchandle<PrimaryExpr>,
		rchandle<PredicateList>);
	~FilterExpr();

public:
	rchandle<PrimaryExpr> get_primary() const { return primary_h; }
	rchandle<PredicateList> get_pred_list() const { return pred_list_h; }

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
	PredicateList(
		yy::location const&);
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
	Predicate(
		yy::location const&,
		rchandle<Expr>);
	~Predicate();

public:
	rchandle<Expr> get_pred() const { return pred_h; }

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
	PrimaryExpr(
		yy::location const&);
	~PrimaryExpr();

};



// [84] Literal
// ------------
class Literal : public PrimaryExpr
/*______________________________________________________________________
|
|	::= NumericLiteral | StringLiteral
|_______________________________________________________________________*/
{
public:
	Literal(
		yy::location const&);
	~Literal();

};



// [85] NumericLiteral
// -------------------
class NumericLiteral : public Literal
/*______________________________________________________________________
|
|	::= INTEGER_LITERAL
|			|	DECIMAL_LITERAL
|			|	DOUBLE_LITERAL
|_______________________________________________________________________*/
{
public:
	enum numeric_type_t {
		num_integer,
		num_decimal,
		num_double
	};
	typedef float decimal;

protected:
	enum numeric_type_t type;
	union {
		int ival;
		decimal decval;
		double dval;
	};

public:
	NumericLiteral(
		yy::location const&,
		int);
	NumericLiteral(
		yy::location const&,
		decimal);
	NumericLiteral(
		yy::location const&,
		double);
	~NumericLiteral();

public:
	enum numeric_type_t get_type() const { return type; }
	int get_int() const { return ival; }
	decimal get_decimal() const { return decval; }
	double get_double() const { return dval; }

};



// [86] VarRef
// -----------
class VarRef : public PrimaryExpr
/*______________________________________________________________________
|
|	::= DOLLAR  VARNAME
|_______________________________________________________________________*/
{
protected:
	std::string varname;

public:
	VarRef(
		yy::location const&,
		std::string varname);
	~VarRef();

public:
	std::string get_varname() const { return varname; }

};



// [87] ParenthesizedExpr
// ----------------------
class ParenthesizedExpr : public PrimaryExpr
/*______________________________________________________________________
|
|	::= LPAR  RPAR
|			|	LPAR  Expr  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	ParenthesizedExpr(
		yy::location const&,
		rchandle<Expr>);
	~ParenthesizedExpr();

public:
	rchandle<Expr> get_expr() const { return expr_h; }

};	



// [88] ContextItemExpr
// --------------------
class ContextItemExpr : public PrimaryExpr
/*______________________________________________________________________
|
|	::= DOT
|_______________________________________________________________________*/
{
public:
	ContextItemExpr(
		yy::location const&);
	~ContextItemExpr();

};	



// [89] OrderedExpr
// ----------------
class OrderedExpr : public PrimaryExpr
/*______________________________________________________________________
|
|	::= ORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	OrderedExpr(
		yy::location const&,
		rchandle<Expr>);
	~OrderedExpr();

public:
	rchandle<Expr> get_expr() const { return expr_h; }

};



// [90] UnorderedExpr
// ------------------
class UnorderedExpr : public PrimaryExpr
/*______________________________________________________________________
|
|	::= UNORDERED_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<Expr> expr_h;

public:
	UnorderedExpr(
		yy::location const&,
		rchandle<Expr>);
	~UnorderedExpr();

public:
	rchandle<Expr> get_expr() const { return expr_h; }

};



// [91] FunctionCall
// -----------------
class FunctionCall : public PrimaryExpr
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
	FunctionCall(
		yy::location const&,
		rchandle<QName>,
		rchandle<ArgList>);
	~FunctionCall();

public:
	rchandle<QName> get_fname() const { return fname_h; }
	rchandle<ArgList> get_arg_list() const { return arg_list_h; }

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
	std::vector<rchandle<ExprSingle> > arg_hv;

public:
	ArgList(
		yy::location const&);
	~ArgList();

public:
	void push_back(rchandle<ExprSingle> arg_h) { arg_hv.push_back(arg_h); }
	rchandle<ExprSingle> operator[](int i) const { return arg_hv[i]; }

};



// [92] Constructor
// ----------------
class Constructor : public PrimaryExpr
/*______________________________________________________________________
|
|	::= DirectConstructor |	ComputedConstructor
|_______________________________________________________________________*/
{
public:
	Constructor(
		yy::location const&);
	~Constructor();

};



// [93] DirectConstructor
// ----------------------
class DirectConstructor : public Constructor
/*______________________________________________________________________
|
|	::= DirElemConstructor
|			|	DirCommentConstructor
|			|	DirPIConstructor
|_______________________________________________________________________*/
{
public:
	DirectConstructor(
		yy::location const&);
	~DirectConstructor();

};

 

// [94] DirElemConstructor
// -----------------------
class DirElemConstructor : public DirectConstructor
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
	DirElemConstructor(
		yy::location const&,
		rchandle<QName>,
		rchandle<DirAttributeList>,
		rchandle<DirElemContentList>);
	~DirElemConstructor();

public:
	rchandle<QName> get_elem_name() const { return elem_name_h; }
	rchandle<DirAttributeList> get_attr_list() const { return attr_list_h; }
	rchandle<DirElemContentList> get_dir_content_list() const { return dir_content_list_h; }

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
	DirElemContentList(
		yy::location const&);
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
	DirAttributeList(
		yy::location const&);
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
	DirAttr(
		yy::location const&,
		rchandle<QName>,
		rchandle<DirAttributeValue>);
	~DirAttr();

public:
	rchandle<QName> get_atname() const { return atname_h; }
	rchandle<DirAttributeValue> get_dir_atval() const { return dir_atval_h; }

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
	rchandle<AposAttrContentList> apos_attr_content_h;

public:
	DirAttributeValue(
		yy::location const&,
		rchandle<QuoteAttrContentList>,
		rchandle<AposAttrContentList>);
	~DirAttributeValue();

public:
	rchandle<QuoteAttrContentList> get_quot_attr_content() const
		{ return quot_attr_content_h; }
	rchandle<AposAttrContentList> get_apos_attr_content() const
		{ return apos_attr_content_h; }

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
	std::vector<rchandle<QuoteAttrValueContent> > quot_atval_content_hv;
	
public:
	QuoteAttrContentList(
		yy::location const&);
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
	std::vector<rchandle<AposAttrValueContent> > apos_atval_content_hv;
	
public:
	AposAttrContentList(
		yy::location const&);
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
	std::string quot_atcontent;
	rchandle<CommonContent> common_content_h;

public:
	QuoteAttrValueContent(
		yy::location const&,
		std::string quot_atcontent,
		rchandle<CommonContent>);
	~QuoteAttrValueContent();

public:
	std::string get_quot_atcontent() const { return quot_atcontent; }
	rchandle<CommonContent> get_common_content() const { return common_content_h; }

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
	std::string apos_atcontent;
	rchandle<CommonContent> common_content_h;

public:
	AposAttrValueContent(
		yy::location const&,
		std::string apos_atcontent,
		rchandle<CommonContent>);
	~AposAttrValueContent();

public:
	std::string get_apos_atcontent() const { return apos_atcontent; }
	rchandle<CommonContent> get_common_content() const { return common_content_h; }

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
	DirElemContent(
		yy::location const&,
		std::string elem_content);
	~DirElemContent();

public:
	std::string get_elem_content() const { return elem_content; }

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
	std::string ref;
	rchandle<EnclosedExpr> expr_h;

public:
	CommonContent(
		yy::location const&,
		enum common_content_t,
		std::string ref);
	CommonContent(
		yy::location const&,
		rchandle<EnclosedExpr> expr_h);
	CommonContent(
		yy::location const&,
		enum common_content_t);
	~CommonContent();

public:
	enum common_content_t get_type() const { return type; }
	std::string get_ref() const { return ref; }
	rchandle<EnclosedExpr> get_expr() const { return expr_h; }

};



// [101] DirCommentConstructor
// ---------------------------
class DirCommentConstructor : public DirectConstructor
/*______________________________________________________________________
|
|	::= COMMENT_BEGIN  EXPR_COMMENT_LITERAL  COMMENT_END 	 ws:explicitXQ
|_______________________________________________________________________*/
{
protected:
	std::string comment;

public:
	DirCommentConstructor(
		yy::location const&,
		std::string const& comment);
	~DirCommentConstructor();

public:
	std::string get_comment() const { return comment; }

};



// [102] DirCommentContents
// ------------------------
/* lexical rule */



// [103] DirPIConstructor
// ----------------------
class DirPIConstructor : public DirectConstructor
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
	DirPIConstructor(
		yy::location const&,
		std::string const& pi_target,
		std::string const& pi_content);
	~DirPIConstructor();

public:
	std::string get_pi_target() const { return pi_target; }
	std::string get_pi_content() const { return pi_content; }

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
	CDataSection(
		yy::location const&,
		std::string cdata_content);
	~CDataSection();

public:
	std::string get_cdata_content() const { return cdata_content; }

};



// [106] CDataSectionContents
// --------------------------
/* lexical rule */



// [107] ComputedConstructor
// -------------------------
class ComputedConstructor : public Constructor
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
	ComputedConstructor(
		yy::location const&);
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
	CompDocConstructor(
		yy::location const&,
		rchandle<Expr>);
	~CompDocConstructor();

public:
	rchandle<Expr> get_expr() const { return expr_h; }

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
	rchandle<Expr> content_expr_h;

public:
	CompElemConstructor(
		yy::location const&,
		rchandle<QName>,
		rchandle<Expr>,
		rchandle<Expr>);
	~CompElemConstructor();

public:
	rchandle<QName> get_qname() const { return qname_h; }
	rchandle<Expr> get_qname_expr() const { return qname_expr_h; }
	rchandle<Expr> get_content_expr() const { return content_expr_h; }

};



// [110] ContentExpr
// -----------------
//class ContentExpr : public exprnode
/*______________________________________________________________________
|
|	::= Expr
|_______________________________________________________________________*/
/*
{
protected:
	rchandle<Expr> expr_h;

public:
	ContentExpr(
		yy::location const&,
		rchandle<Expr>);
	~ContentExpr();

public:
	rchandle<Expr> get_expr() const { return expr_h; }

};
*/



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
	CompAttrConstructor(
		yy::location const&,
		rchandle<QName>,
		rchandle<Expr>,
		rchandle<Expr>);
	~CompAttrConstructor();

public:
	rchandle<QName> get_qname() const { return qname_h; }
	rchandle<Expr> get_qname_expr() const { return qname_expr_h; }
	rchandle<Expr> get_val_expr() const { return val_expr_h; }

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
	CompTextConstructor(
		yy::location const&,
		rchandle<Expr> text_expr_h);
	~CompTextConstructor();

public:
	rchandle<Expr> get_text_expr() const { return text_expr_h; }

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
	CompCommentConstructor(
		yy::location const&,
		rchandle<Expr>);
	~CompCommentConstructor();

public:
	rchandle<Expr> get_comment_expr() const { return comment_expr_h; }

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
	CompPIConstructor(
		yy::location const&,
		std::string target,
		rchandle<Expr>,
		rchandle<Expr>);
	~CompPIConstructor();

public:
	std::string get_target() const { return target; }
	rchandle<Expr> get_target_expr() const { return target_expr_h; }
	rchandle<Expr> get_content_expr() const { return content_expr_h; }

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
	SingleType(
		yy::location const&,
		rchandle<AtomicType>,
		bool hook_b);
	~SingleType();

public:
	rchandle<AtomicType> get_atomic_type() const { return atomic_type_h; }
	bool get_hook_bit() const { return hook_b; }

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
	TypeDeclaration(
		yy::location const&,
		rchandle<SequenceType>);
	~TypeDeclaration();

public:
	rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

};


// [117] SequenceType
// ------------------
class SequenceType : public parsenode
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
	SequenceType(
		yy::location const&,
		rchandle<ItemType>,
		rchandle<OccurrenceIndicator>,
		bool void_b);
	~SequenceType();

public:
	rchandle<ItemType> get_itemtype() const { return itemtype_h; }
	rchandle<OccurrenceIndicator> get_occur() const { return occur_h; }
	bool get_void_bit() const { return void_b; }

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
	OccurrenceIndicator(
		yy::location const&,
		enum occurrence_t);
	~OccurrenceIndicator();

public:
	enum occurrence_t get_type() const { return type; }

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
	ItemType(
		yy::location const&,
		std::string item_test);
	ItemType(
		yy::location const&);
	~ItemType();

public:
	std::string get_item_test() const { return item_test; }

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
	AtomicType(
		yy::location const&,
		rchandle<QName>);
	~AtomicType();

public:
	rchandle<QName> get_qname() const { return qname_h; }

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
	KindTest(
		yy::location const&);
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
	AnyKindTest(
		yy::location const&);
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
	DocumentTest(
		yy::location const&,
		rchandle<ElementTest>,
		rchandle<SchemaElementTest>);
	~DocumentTest();

public:
	rchandle<ElementTest> get_elem_test() const
		{ return elem_test_h; }
	rchandle<SchemaElementTest> get_schema_elem_test() const
		{ return schema_elem_test_h; }

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
	TextTest(
		yy::location const&);
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
	CommentTest(
		yy::location const&);
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
	PITest(
		yy::location const&,
		std::string target,
		std::string content);
	~PITest();

public:
	std::string get_target() const { return target; }
	std::string get_content() const { return content; }

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
	rchandle<AttribNameOrWildcard> attr_name_or_wildcard_h;
	rchandle<TypeName> type_name_h;

public:
	AttributeTest(
		yy::location const&,
		rchandle<AttribNameOrWildcard>,
		rchandle<TypeName>);
	~AttributeTest();

public:
	rchandle<AttribNameOrWildcard> get_attr_name_or_wildcard() const
		{ return attr_name_or_wildcard_h; }
	rchandle<TypeName> get_type_name() const
		{ return type_name_h; }

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
	AttribNameOrWildcard(
		yy::location const&,
		rchandle<AttributeName>,
		bool star_b);
	~AttribNameOrWildcard();

public:
	rchandle<AttributeName> get_attr_name() const { return attr_name_h; }
	bool get_star_bit() const { return star_b; }

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
	SchemaAttributeTest(
		yy::location const&,
		rchandle<AttributeDeclaration>);
	~SchemaAttributeTest();

public:
	rchandle<AttributeDeclaration> get_attr_decl() const { return attr_decl_h; }

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
	AttributeDeclaration(
		yy::location const&,
		rchandle<AttributeName>);
	~AttributeDeclaration();

public:
	rchandle<AttributeName> get_attr_name() const { return attr_name_h; }

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
	ElementTest(
		yy::location const&,
		rchandle<ElementNameOrWildcard>,
		rchandle<TypeName>);
	~ElementTest();

public:
	rchandle<ElementNameOrWildcard> get_elem_name_or_wildcard() const
		{ return elem_name_or_wildcard_h; }
	rchandle<TypeName> get_type_name() const
		{ return type_name_h; }

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
	ElementNameOrWildcard(
		yy::location const&,
		rchandle<ElementName>,
		bool star_b);
	~ElementNameOrWildcard();

public:
	rchandle<ElementName> get_elem_name() const { return elem_name_h; }
	bool get_star_bit() const { return star_b; }

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
	SchemaElementTest(
		yy::location const&,
		rchandle<ElementDeclaration>);
	~SchemaElementTest();

public:
	rchandle<ElementDeclaration> get_elem_decl() const { return elem_decl_h; }

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
	ElementDeclaration(
		yy::location const&,
		rchandle<ElementName>);
	~ElementDeclaration();

public:
	rchandle<ElementName> get_elem_name() const { return elem_name_h; }
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
	AttributeName(
		yy::location const&,
		rchandle<QName>);
	~AttributeName();

public:
	rchandle<QName> get_attr_qname() const { return attr_qname_h; }

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
	ElementName(
		yy::location const&,
		rchandle<QName>);
	~ElementName();

public:
	rchandle<QName> get_elem_qname() const { return elem_qname_h; }

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
	TypeName(
		yy::location const&,
		rchandle<QName>);
	~TypeName();

public:
	rchandle<QName> get_type_qname() const { return type_qname_h; }

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
/*
class QName : public parsenode
{
public:
	QName(
		yy::location const&);
	~QName();
};
*/
#include "../types/qname.h"


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
	RevalidationDecl(
		yy::location const&,
		rchandle<QName>);
	~RevalidationDecl();

public:
	rchandle<QName> get_qname() const { return qname_h; }

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
	InsertExpr(
		yy::location const&,
		rchandle<ExprSingle>,
		rchandle<ExprSingle>);
	~InsertExpr();

public:
	rchandle<ExprSingle> get_source_expr() const { return source_expr_h; }
	rchandle<ExprSingle> get_target_expr() const { return target_expr_h; }

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
	DeleteExpr(
		yy::location const&,
		rchandle<ExprSingle>);
	~DeleteExpr();

public:
	rchandle<ExprSingle> get_target_expr() const { return target_expr_h; }

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
	ReplaceExpr(
		yy::location const&,
		rchandle<ExprSingle> source_expr_h,
		rchandle<ExprSingle> target_expr_h);
	~ReplaceExpr();

public:
	rchandle<ExprSingle> get_source_expr() const { return source_expr_h; }
	rchandle<ExprSingle> get_target_expr() const { return target_expr_h; }

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
	RenameExpr(
		yy::location const&,
		rchandle<ExprSingle> source_expr_h,
		rchandle<ExprSingle> target_expr_h);
	~RenameExpr();

public:
	rchandle<ExprSingle> get_source_expr() const { return source_expr_h; }
	rchandle<ExprSingle> get_target_expr() const { return target_expr_h; }

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
	TransformExpr(
		yy::location const&,
		rchandle<VarNameList>,
		rchandle<ExprSingle> source_expr_h,
		rchandle<ExprSingle> target_expr_h);
	~TransformExpr();

public:
	rchandle<VarNameList> get_varname_list() const { return varname_list_h; }
	rchandle<ExprSingle> get_source_expr() const { return source_expr_h; }
	rchandle<ExprSingle> get_target_expr() const { return target_expr_h; }

};



// [249a] VarNameList
// ------------------
class VarNameList : public parsenode
/*______________________________________________________________________
|
|	::= VarBinding |	VarNameList  COMMA_DOLLAR  VarBinding
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<VarBinding> > varbinding_hv;
	
public:
	VarNameList(
		yy::location const&);
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
|_______________________________________________________________________*/
{
protected:
	std::string varname;
	rchandle<ExprSingle> val_h;

public:
	VarBinding(
		yy::location const&,
		std::string varname,
		rchandle<ExprSingle>);
	~VarBinding();

public:
	std::string get_varname() const { return varname; }
	rchandle<ExprSingle> get_val() const { return val_h; }

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
	FTSelection(
		yy::location const&,
		rchandle<FTOr>,
		rchandle<FTMatchOptionProximityList>,
		rchandle<RangeExpr>);
	~FTSelection();

public:
	rchandle<FTOr> get_ftor() const
		{ return ftor_h; }
	rchandle<FTMatchOptionProximityList> get_option_list() const
		{ return option_list_h; }
	rchandle<RangeExpr> get_weight_expr() const
		{ return weight_expr_h; }

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
	FTMatchOptionProximityList(
		yy::location const&);
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
	FTOr(
		yy::location const&,
		rchandle<FTOr>,
		rchandle<FTAnd>);
	~FTOr();

public:
	rchandle<FTOr> get_ftor() const { return ftor_h; }
	rchandle<FTAnd> get_ftand() const { return ftand_h; }

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
	rchandle<FTMildnot> ftmild_not_h;

public:
	FTAnd(
		yy::location const&,
		rchandle<FTAnd>,
		rchandle<FTMildnot>);
	~FTAnd();

public:
	rchandle<FTAnd> get_ftand() const { return ftand_h; }
	rchandle<FTMildnot> get_ftmild_not() const { return ftmild_not_h; }

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
	rchandle<FTMildnot> ftmild_not_h;
	rchandle<FTUnaryNot> ftunary_not_h;

public:
	FTMildnot(
		yy::location const&,
		rchandle<FTMildnot>,
		rchandle<FTUnaryNot>);
	~FTMildnot();

public:
	rchandle<FTMildnot> get_ftmild_not() const { return ftmild_not_h; }
	rchandle<FTUnaryNot> get_ftunary_not() const { return ftunary_not_h; }

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
	FTUnaryNot(
		yy::location const&,
		rchandle<FTWordsSelection>,
		bool not_b);
	~FTUnaryNot();

public:
	rchandle<FTWordsSelection> get_words_selection() const
		{ return words_selection_h; }
	bool get_not_bit() const
		{ return not_b; }

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
	FTWordsSelection(
		yy::location const&,
		rchandle<FTWords>,
		rchandle<FTTimes>,
		rchandle<FTSelection>);
	~FTWordsSelection();

public:
	rchandle<FTWords> get_words() const { return words_h; }
	rchandle<FTTimes> get_times() const { return times_h; }
	rchandle<FTSelection> get_selection() const { return selection_h; }

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
	FTWords(
		yy::location const&,
		rchandle<FTWordsValue>,
		rchandle<FTAnyallOption>);
	~FTWords();

public:
	rchandle<FTWordsValue> get_words_val() const
		{ return words_val_h; }
	rchandle<FTAnyallOption> get_any_all_option() const
		{ return any_all_option_h; }

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
	FTWordsValue(
		yy::location const&,
		rchandle<Literal>,
		rchandle<Expr>);
	~FTWordsValue();

public:
	rchandle<Literal> get_lit() const { return lit_h; }
	rchandle<Expr> get_expr() const { return expr_h; }

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
	FTProximity(
		yy::location const&);
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
	FTOrderedIndicator(
		yy::location const&);
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
|			| FTWildcardOption
|_______________________________________________________________________*/
{
public:
	FTMatchOption(
		yy::location const&);
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
	enum ft_case_mode_t {
		lowercase,
		uppercase,
		senstive,
		insensitive
	};

protected:
	ft_case_mode_t mode;

public:
	FTCaseOption(
		yy::location const&,
		enum ft_case_mode_t);
	~FTCaseOption();

public:
	enum ft_case_mode_t get_mode() const { return mode; }

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
	FTDiacriticsOption(
		yy::location const&,
		ft_diacritics_mode_t);
	~FTDiacriticsOption();

public:
	enum ft_diacritics_mode_t get_mode() const { return mode; }

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
	FTStemOption(
		yy::location const&,
		ft_stem_mode_t);
	~FTStemOption();

public:
	enum ft_stem_mode_t get_mode() const { return mode; }

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
	FTThesaurusOption(
		yy::location const&,
		rchandle<FTThesaurusID>,
		rchandle<FTThesaurusList>,
		bool default_b,
		bool without_b);
	~FTThesaurusOption();

public:
	rchandle<FTThesaurusID> get_thesaurusid() const
		{ return thesaurusid_h; }
	rchandle<FTThesaurusList> get_thesaurus_list() const
		{ return thesaurus_list_h; }

	bool get_default_bit() const { return default_b; }
	bool get_without_bit() const { return without_b; }

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
	FTThesaurusList(
		yy::location const&);
	~FTThesaurusList();

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
	FTThesaurusID(
		yy::location const&,
		std::string thesaurus_name,
		std::string relationship_name,
		rchandle<FTRange> levels_h);
	~FTThesaurusID();

public:
	std::string get_thesaurus_name() const { return thesaurus_name; }
	std::string get_relationship_name() const { return relationship_name; }
	rchandle<FTRange> get_levels() const { return levels_h; }

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
	FTStopwordOption(
		yy::location const&,
		rchandle<FTRefOrList>,
		rchandle<FTInclExclStringLiteralList>,
		stop_words_mode_t);
	~FTStopwordOption();

public:
	rchandle<FTRefOrList> get_refor_list() const
		{ return refor_list_h; }
	rchandle<FTInclExclStringLiteralList> get_incl_excl_list() const
		{ return incl_excl_list_h; }
	stop_words_mode_t get_mode() const
		{ return mode; }

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
	FTInclExclStringLiteralList(
		yy::location const&);
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
	FTRefOrList(
		yy::location const&,
		std::string at_str,
		rchandle<FTStringLiteralList>);
	~FTRefOrList();

	std::string get_at_str() const
		{ return at_str; }
	rchandle<FTStringLiteralList> get_stringlit_list() const
		{ return stringlit_list_h; }

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
	FTStringLiteralList(
		yy::location const&);
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
		inex_union,
		inex_except
	};

protected:
	rchandle<FTRefOrList> ref_or_list_h;
	incl_excl_mode_t mode;

public:
	FTInclExclStringLiteral(
		yy::location const&,
		rchandle<FTRefOrList>,
		incl_excl_mode_t);
	~FTInclExclStringLiteral();

public:
	rchandle<FTRefOrList> get_ref_or_list() const
		{ return ref_or_list_h; }
	incl_excl_mode_t get_mode() const
		{ return mode; }

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
	FTLanguageOption(
		yy::location const&,
		std::string lang);
	~FTLanguageOption();

public:
	std::string get_lang() const { return lang; }

};



//[364] FTWildcardOption
//----------------------
class FTWildcardOption : public FTMatchOption
/*______________________________________________________________________
|
|	::=	WITH_WILDCARDS
|			| WITHOUT_WILDCARDS
|_______________________________________________________________________*/
{
protected:
	bool with_b;

public:
	FTWildcardOption(
		yy::location const&,
		bool with_b);
	~FTWildcardOption();

public:
	bool get_with_bit() const { return with_b; }

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
	FTContent(
		yy::location const&,
		enum ft_content_mode_t);
	~FTContent();

public:
	enum ft_content_mode_t get_mode() const { return mode; }

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
	enum ft_anyall_option_t {
		any,
		any_word,
		all,
		all_words,
		phrase
	};

protected:
	enum ft_anyall_option_t option;

public:
	FTAnyallOption(
		yy::location const&,
		enum ft_anyall_option_t);
	~FTAnyallOption();

public:
	enum ft_anyall_option_t get_option() const { return option; }

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
	FTRange(
		yy::location const&,
		rchandle<UnionExpr> src_expr_h,
		rchandle<UnionExpr> dst_expr_h);
	~FTRange();

public:
	rchandle<UnionExpr> get_src_expr() const { return src_expr_h; }
	rchandle<UnionExpr> get_dst_expr() const { return dst_expr_h; }

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
	FTDistance(
		yy::location const&,
		rchandle<FTRange>,
		rchandle<FTUnit>);
	~FTDistance();

public:
	rchandle<FTRange> get_dist() const { return dist_h; }
	rchandle<FTUnit> get_unit() const { return unit_h; }

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
	FTWindow(
		yy::location const&,
		rchandle<UnionExpr> window_h,
		rchandle<FTUnit> unit_h);
	~FTWindow();

public:
	rchandle<UnionExpr> get_window() const { return window_h; }
	rchandle<FTUnit> get_unit() const { return unit_h; }

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
	FTTimes(
		yy::location const&,
		rchandle<FTRange>);
	~FTTimes();

public:
	rchandle<FTRange> get_range() const { return range_h; }

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
	FTScope(
		yy::location const&,
		ft_scope_t);
	~FTScope();

public:
	enum ft_scope_t get_scope() const { return scope; }

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
	FTUnit(
		yy::location const&,
		ft_unit_t);
	~FTUnit();

public:
	enum ft_unit_t get_unit() const { return unit; }

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
	FTBigUnit(
		yy::location const&,
		enum ft_big_unit_t);
	~FTBigUnit();

public:
	enum ft_big_unit_t get_unit() const { return unit; }

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
	FTIgnoreOption(
		yy::location const&,
		rchandle<UnionExpr>);
	~FTIgnoreOption();

public:
	rchandle<UnionExpr> get_union() const { return union_h; }

};


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


}	/* namespace xqp */
#endif	/*  XQP_PARSENODES_H */
