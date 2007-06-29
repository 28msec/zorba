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

#include "parse_constants.h"
#include "../context/static_context.h"
#include "../context/dynamic_context.h"
#include "../values/values.h"
#include "../util/rchandle.h"

#include "location.hh"

namespace xqp {


// (See: runtime/normalize.h)
class parsenode_visitor;


/*
**  base class: syntax-only nodes
*/
class parsenode : public rcobject
{
protected:
	yy::location loc;

public:
	parsenode(yy::location const& _loc) : loc(_loc) { }
  ~parsenode() {}

public:	// context
	yy::location get_location() const { return loc; }

public:
	virtual std::ostream& put(std::ostream&) const;
	virtual void accept(parsenode_visitor&) const = 0;

};


/*______________________________________________________________________
|  
|  See Section 21.2.3.1 in
|  "The C++ Programming Language", by B. Stroustrup (1997) AT&T
|_______________________________________________________________________*/

/*
std::ostream& operator<<(std::ostream& s, parsenode const& r)
{
	return r.put(s);
}
*/


/*
**  exprnode:  nodes with values.
*/
class exprnode : public parsenode
{
public:
	exprnode(yy::location const& loc) : parsenode(loc) { }
  ~exprnode() {}

public:
	virtual std::ostream& put(std::ostream&) const;

public:
	virtual void accept(parsenode_visitor&) const = 0;

};

/*
std::ostream& operator<<(std::ostream& s, exprnode const& r)
{
	return r.put(s);
}
*/




class AbbrevForwardStep;
class AdditiveExpr;
class AndExpr;
class AnyKindTest;
class AposAttrContentList;
class AposAttrValueContent;
class ArgList;
class AtomicType;
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
class ConstructionDecl;
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
class DocumentTest;
class ElementTest;
class EmptyOrderDecl;
class EnclosedExpr;
class Expr;
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
class FTMatchOptionProximity;
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
class ForLetClauseList;
class ForwardAxis;
class ForwardStep;
class FunctionCall;
class FunctionDecl;
class GeneralComp;
class IfExpr;
class InsertExpr;
class InstanceofExpr;
class IntersectExceptExpr;
class ItemType;
class LetClause;
class LibraryModule;
class MainModule;
class Module;
class ModuleDecl;
class ModuleImport;
class MultiplicativeExpr;
class NameTest;
class NamespaceDecl;
class NodeComp;
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
class PredicateList;
class Prolog;
class QName;
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
class SIND_DeclList;
class SchemaAttributeTest;
class SchemaElementTest;
class SchemaImport;
class SchemaPrefix;
class SequenceType;
class SignList;
class SingleType;
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
class VFO_DeclList;
class ValidateExpr;
class ValueComp;
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
public:
	Module(yy::location const&);
	~Module();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	std::vector<rchandle<parsenode> > sind_hv;

public:
	SIND_DeclList(yy::location const&);
	~SIND_DeclList();

public:
	void push_back(rchandle<parsenode> sind_h) { sind_hv.push_back(sind_h); }
	rchandle<parsenode> operator[](int k) const { return sind_hv[k]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	std::vector<rchandle<parsenode> > vfo_hv;

public:
	VFO_DeclList(yy::location const&);
	~VFO_DeclList();

public:
	void push_back(rchandle<parsenode> vfo_h) { vfo_hv.push_back(vfo_h); }
	rchandle<parsenode> operator[](int k) const { return vfo_hv[k]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [6c] SIND_Decl
/*______________________________________________________________________
|	::= Setter
|			| Import
|			| NamespaceDecl
|			| DefaultNamespaceDecl
|_______________________________________________________________________*/


// [6d] VFO_Decl
/*______________________________________________________________________
|	::= VarDecl
|			| FunctionDecl
|			| OptionDecl
|_______________________________________________________________________*/


// [7] Setter
/*______________________________________________________________________
|	::= BoundarySpaceDecl
|			| DefaultCollationDecl
|			| BaseURIDecl
|			| ConstructionDecl
|			| OrderingModeDecl
|			| EmptyOrderDecl
|			| CopyNamespacesDecl
|_______________________________________________________________________*/


// [8] Import
/*______________________________________________________________________
|	::= SchemaImport
|			| ModuleImport
|_______________________________________________________________________*/


// [9] Separator (Lexical rule)
// -------------


// [10] NamespaceDecl
// ------------------
class NamespaceDecl : public parsenode
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [11] BoundarySpaceDecl
// ----------------------
class BoundarySpaceDecl : public parsenode
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [12] DefaultNamespaceDecl
// -------------------------
class DefaultNamespaceDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
|			| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
|_______________________________________________________________________*/
{
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


/* full-text extension */
// [13a] FTOptionDecl
// ------------------
class FTOptionDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_FTOPTION  FTMatchOption
|_______________________________________________________________________*/
{
protected:
	rchandle<parsenode> match_option_h;

public:
	FTOptionDecl(
		yy::location const&,
		rchandle<parsenode>);

	~FTOptionDecl();

public:
	rchandle<parsenode> get_match_option() const { return match_option_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	dynamic_context::ordering_mode_t mode;
		
public:
	OrderingModeDecl(
		yy::location const&,
		dynamic_context::ordering_mode_t);

	~OrderingModeDecl();
	
public:
	dynamic_context::ordering_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	static_context::order_empty_mode_t mode;

public:
	EmptyOrderDecl(
		yy::location const&,
		static_context::order_empty_mode_t);

	~EmptyOrderDecl();
	
public:
	static_context::order_empty_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [16] CopyNamespacesDecl
// -----------------------
class CopyNamespacesDecl : public parsenode
/*______________________________________________________________________
|
|	::= DECLARE_COPY_NAMESPACES  ("preserve"|"no preserve")
|				COMMA  ("inherit"|"no inherit")
|_______________________________________________________________________*/
{
protected:
	static_context::preserve_mode_t preserve_mode;
	static_context::inherit_mode_t inherit_mode;

public:
	CopyNamespacesDecl(
		yy::location const&,
		static_context::preserve_mode_t preserve_mode,
		static_context::inherit_mode_t  inherit_mode);

	~CopyNamespacesDecl();

public: 
	static_context::preserve_mode_t get_preserve_mode() const;
	static_context::inherit_mode_t  get_inherit_mode() const;

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [17] PreserveMode
// -----------------

// [18] InheritMode
// ----------------



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
	DefaultCollationDecl(
		yy::location const&,
		std::string const&  collation);

	~DefaultCollationDecl();

public:
	std::string get_collation() const { return collation; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	BaseURIDecl(
		yy::location const&,
		std::string const& base_uri);

	~BaseURIDecl();

public:
	std::string get_base_uri() const { return base_uri; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [21] SchemaImport
// -----------------
class SchemaImport : public parsenode
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [23] ModuleImport
// -----------------
class ModuleImport : public parsenode
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> initexpr_h;

public:
	VarDecl(
		yy::location const&,
		std::string varname,
		rchandle<TypeDeclaration>,
		rchandle<exprnode>);
	~VarDecl();

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<exprnode> get_initexpr() const { return initexpr_h; }
	bool is_extern() const { return initexpr_h==NULL; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	static_context::construction_mode_t mode;

public:
	ConstructionDecl(
		yy::location const&,
		static_context::construction_mode_t);

	~ConstructionDecl();

public:
	static_context::construction_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	function_type_t type;
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
		function_type_t type);

	~FunctionDecl();

public:
	rchandle<QName> get_name() const { return name_h; }
	rchandle<ParamList> get_paramlist() const { return paramlist_h; }
	rchandle<EnclosedExpr> get_body() const { return body_h; }
	rchandle<SequenceType> get_return_type() const { return return_type_h; }
	function_type_t get_type() const { return type; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	ParamList(yy::location const&);
	~ParamList();

public:
	void push_back(rchandle<Param> param_h) { param_hv.push_back(param_h); }
	rchandle<Param> operator[](int i) const { return param_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> expr_h;

public:
	EnclosedExpr(
		yy::location const&,
		rchandle<exprnode>);

	~EnclosedExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }
	
public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> expr_h;

public:
	QueryBody(
		yy::location const&,
		rchandle<exprnode>);

	QueryBody();

	~QueryBody();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }
	
public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	std::vector<rchandle<exprnode> > expr_hv;

public:
	Expr(yy::location const&);
	~Expr();

public:
	void push_back(rchandle<exprnode> expr_h) { expr_hv.push_back(expr_h); }
	rchandle<exprnode> operator[](int i) const { return expr_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [32] ExprSingle
/*______________________________________________________________________
|	::= FLWORExpr
|			|	QuantifiedExpr
|			|	TypeswitchExpr
|			|	IfExpr
|			|	OrExpr
|_______________________________________________________________________*/


// [33] FLWORExpr
// --------------
class FLWORExpr : public exprnode
/*______________________________________________________________________
|
|	::= ForLetClauseList  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  RETURN  ExprSingle
|			|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
|			|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<ForLetClauseList> forlet_list_h;
	rchandle<WhereClause> where_h;
	rchandle<OrderByClause> orderby_h;
	rchandle<exprnode> return_val_h;

public:
	FLWORExpr(
		yy::location const&,
		rchandle<ForLetClauseList>,
		rchandle<WhereClause>,
		rchandle<OrderByClause>,
		rchandle<exprnode>);

	~FLWORExpr();

public:
	rchandle<ForLetClauseList> get_forlet_list() const { return forlet_list_h; }
	rchandle<WhereClause> get_where() const { return where_h; }
	rchandle<OrderByClause> get_orderby() const { return orderby_h; }
	rchandle<exprnode> get_return_val() const { return return_val_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	std::vector<rchandle<parsenode> > forlet_hv;

public:
	ForLetClauseList(yy::location const&);
	~ForLetClauseList();

public:
	void push_back(rchandle<parsenode> forlet_h) { forlet_hv.push_back(forlet_h); }
	rchandle<parsenode> operator[](int i) const { return forlet_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [33b] ForLetClause
/*______________________________________________________________________
|	::= ForClause | LetClause
|_______________________________________________________________________*/


// [34] ForClause
// --------------
class ForClause : public parsenode
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	VarInDeclList(yy::location const&);
	~VarInDeclList();

public:
	void push_back(rchandle<VarInDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }
	rchandle<VarInDecl> operator[](int i) const { return vardecl_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> valexpr_h;
	
public:
	VarInDecl(
		yy::location const&,
		std::string varname,
		rchandle<TypeDeclaration>,
		rchandle<PositionalVar>,
		rchandle<FTScoreVar>,
		rchandle<exprnode>);

	~VarInDecl();

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<PositionalVar> get_posvar() const { return posvar_h; }
	rchandle<FTScoreVar> get_ftscorevar() const { return ftscorevar_h; }
	rchandle<exprnode> get_valexpr() const { return valexpr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [36] LetClause
// --------------
class LetClause : public parsenode
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	VarGetsDeclList(yy::location const&);
	~VarGetsDeclList();

public:
	void push_back(rchandle<VarGetsDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }
	rchandle<VarGetsDecl> operator[](int i) const { return vardecl_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> valexpr_h;

public:
	VarGetsDecl(
		yy::location const&,
		std::string varname,
		rchandle<TypeDeclaration>,
		rchandle<FTScoreVar>,
		rchandle<exprnode>);
	~VarGetsDecl();

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<FTScoreVar> get_ftscorevar() const { return ftscorevar_h; }
	rchandle<exprnode> get_valexpr() const { return valexpr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> predicate_h;

public:
	WhereClause(
		yy::location const&,
		rchandle<exprnode>);
	~WhereClause();

public:
	rchandle<exprnode> get_predicate() const { return predicate_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	OrderSpecList(yy::location const&);
	~OrderSpecList();

public:
	void push_back(rchandle<OrderSpec> spec_h) { spec_hv.push_back(spec_h); }
	rchandle<OrderSpec> operator[](int i) const { return spec_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> spec_h;
	rchandle<OrderModifier> modifier_h;

public:
	OrderSpec(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<OrderModifier>);
	~OrderSpec();

public:
	rchandle<exprnode> get_spec() const { return spec_h; }
	rchandle<OrderModifier> get_modifier() const { return modifier_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [41a] OrderDirSpec
// ------------------
class OrderDirSpec : public parsenode
/*______________________________________________________________________
|
|	::= ASCENDING  |  DESCENDING
|_______________________________________________________________________*/
{
protected:
	dir_spec_t dir_spec;

public:
	OrderDirSpec(
		yy::location const&,
		dir_spec_t dir_spec);
	~OrderDirSpec();
	
public:
	dir_spec_t get_dir_spec() const { return dir_spec; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [41b] OrderEmptySpec
// --------------------
class OrderEmptySpec : public parsenode
/*______________________________________________________________________
|
|	::= EMPTY_GREATEST  |  EMPTY_LEAST
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	quantification_mode_t qmode;
	rchandle<QVarInDeclList> decl_list_h;
	rchandle<exprnode> expr_h;

public:
	QuantifiedExpr(
		yy::location const&,
		quantification_mode_t qmode,
		rchandle<QVarInDeclList>,
		rchandle<exprnode>);
	~QuantifiedExpr();

public:
	quantification_mode_t get_qmode() const { return qmode; }
	rchandle<QVarInDeclList> get_decl_list() const { return decl_list_h; }
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	QVarInDeclList(yy::location const&);
	~QVarInDeclList();

public:
	void push_back(rchandle<QVarInDecl> decl_h) { qvar_decl_hv.push_back(decl_h); }
	rchandle<QVarInDecl> operator[](int i) const { return qvar_decl_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> val_h;

public:
	QVarInDecl(
		yy::location const&,
		std::string name,
		rchandle<exprnode>);

	QVarInDecl(
		yy::location const&,
		std::string name,
		rchandle<TypeDeclaration>,
		rchandle<exprnode>);

	~QVarInDecl();

public:
	std::string get_name() const { return name; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<exprnode> get_val() const { return val_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> switch_expr_h;
	rchandle<CaseClauseList> clause_list_h;
	std::string default_varname;
	rchandle<exprnode> default_clause_h;

public:
	TypeswitchExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<CaseClauseList>,
		rchandle<exprnode>);

	TypeswitchExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<CaseClauseList>,
		std::string default_varname,
		rchandle<exprnode>);

	~TypeswitchExpr();

public:
	rchandle<exprnode> get_switch_expr() const { return switch_expr_h; }
	rchandle<CaseClauseList> get_clause_list() const { return clause_list_h; }
	std::string get_default_varname() const { return default_varname; }
	rchandle<exprnode> get_default_clause() const { return default_clause_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	CaseClauseList(yy::location const&);
	~CaseClauseList();

public:
	void push_back(rchandle<CaseClause> clause_h)
		{ clause_hv.push_back(clause_h); }
	rchandle<CaseClause> operator[](int i) const
		{ return clause_hv[i]; }
	std::vector<rchandle<CaseClause> >::const_iterator begin()
		{ return clause_hv.begin(); }
	std::vector<rchandle<CaseClause> >::const_iterator end()
		{ return clause_hv.end(); }
	std::vector<rchandle<CaseClause> >::const_reverse_iterator rbegin()
		{ return clause_hv.rbegin(); }
	std::vector<rchandle<CaseClause> >::const_reverse_iterator rend()
		{ return clause_hv.rend(); }
	uint32_t size() const 
		{ return clause_hv.size(); }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> val_h;

public:
	CaseClause(
		yy::location const&,
		std::string varname,
		rchandle<SequenceType>,
		rchandle<exprnode>);
		
	CaseClause(
		yy::location const&,
		rchandle<SequenceType>,
		rchandle<exprnode>);
		
	~CaseClause();

public:
	std::string get_varname() const { return varname; }
	rchandle<SequenceType> get_type() const { return type_h; }
	rchandle<exprnode> get_val() const { return val_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> cond_expr_h;
	rchandle<exprnode> then_expr_h;
	rchandle<exprnode> else_expr_h;

public:
	IfExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>,
		rchandle<exprnode>);
	~IfExpr();

public:
	rchandle<exprnode> get_cond_expr() const { return cond_expr_h; }
	rchandle<exprnode> get_then_expr() const { return then_expr_h; }
	rchandle<exprnode> get_else_expr() const { return else_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> or_expr_h;
	rchandle<exprnode> and_expr_h;

public:
	OrExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~OrExpr();

public:
	rchandle<exprnode> get_or_expr() const { return or_expr_h; }
	rchandle<exprnode> get_and_expr() const { return and_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> and_expr_h;
	rchandle<exprnode> comp_expr_h;

public:
	AndExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~AndExpr();

public:
	rchandle<exprnode> get_and_expr() const { return and_expr_h; }
	rchandle<exprnode> get_comp_expr() const { return comp_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> left_h;
	rchandle<exprnode> right_h;
	rchandle<ValueComp> valcomp_h;
	rchandle<GeneralComp> gencomp_h;
	rchandle<NodeComp> nodecomp_h;
	// XXX could use a union for these three

public:
	ComparisonExpr(
		yy::location const&,
		rchandle<ValueComp>,
		rchandle<exprnode>,
		rchandle<exprnode>);

	ComparisonExpr(
		yy::location const&,
		rchandle<GeneralComp>,
		rchandle<exprnode>,
		rchandle<exprnode>);

	ComparisonExpr(
		yy::location const&,
		rchandle<NodeComp>,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~ComparisonExpr();

public:
	rchandle<exprnode> get_left() const { return left_h; }
	rchandle<exprnode> get_right() const { return right_h; }
	rchandle<ValueComp> get_valcomp() const { return valcomp_h; }
	rchandle<GeneralComp> get_gencomp() const { return gencomp_h; }
	rchandle<NodeComp> get_nodecomp() const { return nodecomp_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> range_expr_h;
	rchandle<FTSelection> ftselect_h;
	rchandle<FTIgnoreOption> ftignore_h;

public:
	FTContainsExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<FTSelection>,
		rchandle<FTIgnoreOption>);

	~FTContainsExpr();

public:
	rchandle<exprnode> get_range_expr() const { return range_expr_h; }
	rchandle<FTSelection> get_ftselect() const { return ftselect_h; }
	rchandle<FTIgnoreOption> get_ftignore() const { return ftignore_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> from_expr_h;
	rchandle<exprnode> to_expr_h;

public:
	RangeExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~RangeExpr();

public:
	rchandle<exprnode> get_from_expr() const { return from_expr_h; }
	rchandle<exprnode> get_to_expr() const { return to_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	add_op_t add_op;
	rchandle<exprnode> add_expr_h;
	rchandle<exprnode> mult_expr_h;

public:
	AdditiveExpr(
		yy::location const&,
		add_op_t add_op,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~AdditiveExpr();

public:
	add_op_t get_add_op() const { return add_op; }
	rchandle<exprnode> get_add_expr() const { return add_expr_h; }
	rchandle<exprnode> get_mult_expr() const { return mult_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	mult_op_t mult_op;
	rchandle<exprnode> mult_expr_h;
	rchandle<exprnode> union_expr_h;

public:
	MultiplicativeExpr(
		yy::location const&,
		mult_op_t,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~MultiplicativeExpr();

public:
	rchandle<exprnode> get_mult_expr() const { return mult_expr_h; }
	rchandle<exprnode> get_union_expr() const { return union_expr_h; }
	mult_op_t get_mult_op() const { return mult_op; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> union_expr_h;
	rchandle<exprnode> intex_expr_h;

public:
	UnionExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~UnionExpr();

public:
	rchandle<exprnode> union_expr() const { return union_expr_h; }
	rchandle<exprnode> intex_expr() const { return intex_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	enum intex_op_t intex_op;
	rchandle<exprnode> intex_expr_h;
	rchandle<exprnode> instof_expr_h;

public:
	IntersectExceptExpr(
		yy::location const&,
		enum intex_op_t,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~IntersectExceptExpr();

public:
	rchandle<exprnode> get_intex_expr() const { return intex_expr_h; }
	enum intex_op_t get_intex_op() const { return intex_op; }
	rchandle<exprnode> get_instof_expr() const { return instof_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> treat_expr_h;
	rchandle<SequenceType> seqtype_h;

public:
	InstanceofExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<SequenceType>);

	~InstanceofExpr();

public:
	rchandle<exprnode> get_treat_expr() const { return treat_expr_h; }
	rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> castable_expr_h;
	rchandle<SequenceType> seqtype_h;

public:
	TreatExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<SequenceType>);

	~TreatExpr();

public:
	rchandle<exprnode> get_castable_expr() const { return castable_expr_h; }
	rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> cast_expr_h;
	rchandle<SingleType> singletype_h;

public:
	CastableExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<SingleType>);

	~CastableExpr();

public:
	rchandle<exprnode> cast_expr() const { return cast_expr_h; }
	rchandle<SingleType> singletype() const { return singletype_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> unary_expr_h;
	rchandle<SingleType> singletype_h;

public:
	CastExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<SingleType>);
	
	~CastExpr();

public:
	rchandle<exprnode> get_unary_expr() const { return unary_expr_h; }
	rchandle<SingleType> get_singletype() const { return singletype_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> value_expr_h;
	rchandle<SignList> signlist_h;

public:
	UnaryExpr(
		yy::location const&,
		rchandle<SignList>,
		rchandle<exprnode>);

	~UnaryExpr();

public:
	rchandle<exprnode> get_value_expr() const { return value_expr_h; }
	rchandle<SignList> get_signlist() const { return signlist_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [59] ValueExpr
/*______________________________________________________________________
|	::= ValidateExpr
|			|	PathExpr
|			|	ExtensionExpr
|_______________________________________________________________________*/



// [60] GeneralComp
// ----------------
class GeneralComp : public parsenode
/*______________________________________________________________________
|
|	::= EQUALS | NE | LT | LE | GT | GE
|_______________________________________________________________________*/
{
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
	
public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [61] ValueComp
// --------------
class ValueComp : public parsenode
/*______________________________________________________________________
|
|	::= VAL_EQ | VAL_NE | VAL_LT | VAL_LE | VAL_GT | VAL_GE
|_______________________________________________________________________*/
{
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
	
public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [62] NodeComp
// -------------
class NodeComp : public parsenode
/*______________________________________________________________________
|
|	::= IS | PRECEDES | FOLLOWS
|_______________________________________________________________________*/
{
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
	
public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	enum validation_mode_t valmode;
	rchandle<exprnode> expr_h;

public:
	ValidateExpr(
		yy::location const&,
		std::string const& valmode,
		rchandle<exprnode>);

	~ValidateExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }
	enum validation_mode_t get_valmode() const { return valmode; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> expr_h;

public:
	ExtensionExpr(
		yy::location const&,
		rchandle<PragmaList>,
		rchandle<exprnode>);

	~ExtensionExpr();

public:
	rchandle<PragmaList> get_pragma_list() const { return pragma_list_h; }
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	PragmaList(yy::location const&);
	~PragmaList();

public:
	void push_back(rchandle<Pragma> pragma_h) { pragma_hv.push_back(pragma_h); }
	rchandle<Pragma> operator[](int i) const { return pragma_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<QName> name_h;
	std::string pragma_lit;

public:
	Pragma(
		yy::location const&,
		rchandle<QName>,
		std::string pragma_lit);

	~Pragma();

public:
	rchandle<QName> get_name() const { return name_h; }
	std::string get_pragma_lit() const { return pragma_lit; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	enum pathtype_t type;
	rchandle<exprnode> relpath_expr_h;

public:
	PathExpr(
		yy::location const&,
		enum pathtype_t type,
		rchandle<exprnode>);

	~PathExpr();

public:
	enum pathtype_t get_type() const { return type; }
	rchandle<exprnode> get_relpath_expr() const { return relpath_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	enum steptype_t step_type;
	rchandle<exprnode> step_expr_h;
	rchandle<exprnode> relpath_expr_h;

public:
	RelativePathExpr(
		yy::location const&,
		enum steptype_t,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~RelativePathExpr();

public:
	enum steptype_t get_step_type() const { return step_type; }
	rchandle<exprnode> get_step_expr() const { return step_expr_h; }
	rchandle<exprnode> get_relpath_expr() const { return relpath_expr_h; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [69] StepExpr
/*______________________________________________________________________
|	::= AxisStep  |  FilterExpr
|_______________________________________________________________________*/



// [70] AxisStep
// -------------
class AxisStep : public exprnode
/*______________________________________________________________________
|
|	::= (ForwardStep | ReverseStep)  PredicateList?
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

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<parsenode> node_test_h;
	rchandle<AbbrevForwardStep> abbrev_step_h;

public:
	ForwardStep(
		yy::location const&,
		rchandle<ForwardAxis>,
		rchandle<parsenode> node_test_h);

	ForwardStep(
		yy::location const&,
		rchandle<AbbrevForwardStep>);

	~ForwardStep();

public:
	rchandle<ForwardAxis> get_forward_axis() const { return forward_axis_h; }
	rchandle<parsenode> get_node_test() const { return node_test_h; }
	rchandle<AbbrevForwardStep> get_abbrev_step() const { return abbrev_step_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	enum forward_axis_t axis;

public:
	ForwardAxis(
		yy::location const&,
		enum forward_axis_t);

	~ForwardAxis();

public:
	enum forward_axis_t get_axis() const { return axis; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<parsenode> node_test_h;
	bool attr_b;
	
public:
	AbbrevForwardStep(
		yy::location const&,
		rchandle<parsenode>,
		bool attr_b);
		
	AbbrevForwardStep(
		yy::location const&,
		rchandle<parsenode>);
		
	~AbbrevForwardStep();

public:
	rchandle<parsenode> get_node_test() const { return node_test_h; }
	bool get_attr_bit() const { return attr_b; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<parsenode> node_test_h;

public:
	ReverseStep(
		yy::location const&,
		rchandle<ReverseAxis>,
		rchandle<parsenode>);

	ReverseStep(
		yy::location const&,
		rchandle<ReverseAxis>);

	~ReverseStep();

public:
	rchandle<ReverseAxis> get_axis() const { return axis_h; }
	rchandle<parsenode> get_node_test() const { return node_test_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	enum reverse_axis_t axis;

public:
	ReverseAxis(
		yy::location const&,
		enum reverse_axis_t);

	~ReverseAxis();

public:
	enum reverse_axis_t get_axis() const { return axis; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [76] AbbrevReverseStep
// ----------------------
/* folded into [74] */


// [77] NodeTest
/*______________________________________________________________________
|	::= KindTest | NameTest
|_______________________________________________________________________*/
 


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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	enum wildcard_t type;
	rchandle<QName> qname_h;
	
public:
	Wildcard(
		yy::location const&,
		rchandle<QName>,
		enum wildcard_t);

	~Wildcard();

public:
	enum wildcard_t get_type() const { return type; }
	rchandle<QName> get_qname() const { return qname_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [80] FilterExpr
// ---------------
class FilterExpr : public exprnode
/*______________________________________________________________________
|
|	::= PrimaryExpr  PredicateList  | PrimaryExpr
|_______________________________________________________________________*/
{
protected:
	rchandle<exprnode> primary_h;
	rchandle<PredicateList> pred_list_h;

public:
	FilterExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<PredicateList>);

	~FilterExpr();

public:
	rchandle<exprnode> get_primary() const { return primary_h; }
	rchandle<PredicateList> get_pred_list() const { return pred_list_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	std::vector<rchandle<exprnode> > pred_hv;

public:
	PredicateList(yy::location const&);
	~PredicateList();

public:
	void push_back(rchandle<exprnode> pred_h) { pred_hv.push_back(pred_h); }
	rchandle<exprnode> operator[](int i) { return pred_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [82] Predicate
/*______________________________________________________________________
|	::= LBRACK  Expr  RBRACK
|_______________________________________________________________________*/


// [83] PrimaryExpr
/*______________________________________________________________________
|	::= Literal
|			|	VarRef
|			|	ParenthesizedExpr
|			|	ContextItemExpr
|			|	FunctionCall
|			|	Constructor
|			|	OrderedExpr
|			|	UnorderedExpr
|_______________________________________________________________________*/


// [84] Literal
/*______________________________________________________________________
|	::= NumericLiteral | StringLiteral
|_______________________________________________________________________*/


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
	typedef long long decimal;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [86] VarRef
// -----------
class VarRef : public exprnode
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [87] ParenthesizedExpr
// ----------------------
class ParenthesizedExpr : public exprnode
/*______________________________________________________________________
|
|	::= LPAR  RPAR
|			|	LPAR  Expr  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<exprnode> expr_h;

public:
	ParenthesizedExpr(
		yy::location const&,
		rchandle<exprnode>);

	~ParenthesizedExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	ContextItemExpr(yy::location const&);
	~ContextItemExpr();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> expr_h;

public:
	OrderedExpr(
		yy::location const&,
		rchandle<exprnode>);

	~OrderedExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> expr_h;

public:
	UnorderedExpr(
		yy::location const&,
		rchandle<exprnode>);

	~UnorderedExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	FunctionCall(
		yy::location const&,
		rchandle<QName>,
		rchandle<ArgList>);

	~FunctionCall();

public:
	rchandle<QName> get_fname() const { return fname_h; }
	rchandle<ArgList> get_arg_list() const { return arg_list_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	std::vector<rchandle<exprnode> > arg_hv;

public:
	ArgList(yy::location const&);
	~ArgList();

public:
	void push_back(rchandle<exprnode> arg_h) { arg_hv.push_back(arg_h); }
	rchandle<exprnode> operator[](int i) const { return arg_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [92] Constructor
/*______________________________________________________________________
|
|	::= DirectConstructor |	ComputedConstructor
|_______________________________________________________________________*/

// [93] DirectConstructor
/*______________________________________________________________________
|
|	::= DirElemConstructor
|			|	DirCommentConstructor
|			|	DirPIConstructor
|_______________________________________________________________________*/



// [94] DirElemConstructor
// -----------------------
class DirElemConstructor : public exprnode
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
		rchandle<QName> start_name_h,
		rchandle<QName> end_name_h,
		rchandle<DirAttributeList>,
		rchandle<DirElemContentList>);

	~DirElemConstructor();

public:
	rchandle<QName> get_elem_name() const { return elem_name_h; }
	rchandle<DirAttributeList> get_attr_list() const { return attr_list_h; }
	rchandle<DirElemContentList> get_dir_content_list() const { return dir_content_list_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	std::vector<rchandle<exprnode> > dir_content_hv;

public:
	DirElemContentList(yy::location const&);
	~DirElemContentList();

public:
	void push_back(rchandle<exprnode> dir_content_h)
		{ dir_content_hv.push_back(dir_content_h); }
	rchandle<exprnode> operator[](int i) const
		{ return dir_content_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	DirAttributeList(yy::location const&);
	~DirAttributeList();

public:
	void push_back(rchandle<DirAttr> dir_attr_h)
		{ dir_attr_hv.push_back(dir_attr_h); }
	rchandle<DirAttr> operator[](int i)
		{ return dir_attr_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
		rchandle<QuoteAttrContentList>);

	DirAttributeValue(
		yy::location const&,
		rchandle<AposAttrContentList>);

	~DirAttributeValue();

public:
	rchandle<QuoteAttrContentList> get_quot_attr_content() const
		{ return quot_attr_content_h; }
	rchandle<AposAttrContentList> get_apos_attr_content() const
		{ return apos_attr_content_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	QuoteAttrContentList(yy::location const&);
	~QuoteAttrContentList();

public:
	void push_back(rchandle<QuoteAttrValueContent> quot_atval_content_h)
		{ quot_atval_content_hv.push_back(quot_atval_content_h); }
	rchandle<QuoteAttrValueContent> operator[](int i) const
		{ return quot_atval_content_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	AposAttrContentList(yy::location const&);
	~AposAttrContentList();

public:
	void push_back(rchandle<AposAttrValueContent> apos_atval_content_h)
		{ apos_atval_content_hv.push_back(apos_atval_content_h); }
	rchandle<AposAttrValueContent> operator[](int i) const
		{ return apos_atval_content_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
		std::string quot_atcontent);

	QuoteAttrValueContent(
		yy::location const&,
		rchandle<CommonContent>);

	~QuoteAttrValueContent();

public:
	std::string get_quot_atcontent() const { return quot_atcontent; }
	rchandle<CommonContent> get_common_content() const { return common_content_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
		std::string apos_atcontent);

	AposAttrValueContent(
		yy::location const&,
		rchandle<CommonContent>);

	~AposAttrValueContent();

public:
	std::string get_apos_atcontent() const { return apos_atcontent; }
	rchandle<CommonContent> get_common_content() const { return common_content_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> direct_cons_h;
	std::string elem_content;
	rchandle<CDataSection> cdata_h;
	rchandle<CommonContent> common_content_h;

public:
	DirElemContent(
		yy::location const&,
		rchandle<exprnode>);

	DirElemContent(
		yy::location const&,
		std::string elem_content);

	DirElemContent(
		yy::location const&,
		rchandle<CDataSection>);

	DirElemContent(
		yy::location const&,
		rchandle<CommonContent>); 

	~DirElemContent();

public:
	rchandle<exprnode> get_direct_cons() const
		{ return direct_cons_h; }
	std::string get_elem_content() const
		{ return elem_content; }
	rchandle<CDataSection> get_cdata() const
		{ return cdata_h; }
	rchandle<CommonContent> get_common_content() const
		{ return common_content_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	DirCommentConstructor(
		yy::location const&,
		std::string const& comment);

	~DirCommentConstructor();

public:
	std::string get_comment() const { return comment; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	DirPIConstructor(
		yy::location const&,
		std::string const& pi_target);

	DirPIConstructor(
		yy::location const&,
		std::string const& pi_target,
		std::string const& pi_content);

	~DirPIConstructor();

public:
	std::string get_pi_target() const { return pi_target; }
	std::string get_pi_content() const { return pi_content; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



// [106] CDataSectionContents
// --------------------------
/* lexical rule */



// [107] ComputedConstructor
// -------------------------
/*______________________________________________________________________
|
|	::= CompDocConstructor
|			|	CompElemConstructor
|			|	CompAttrConstructor
|			|	CompTextConstructor
|			|	CompCommentConstructor
|			|	CompPIConstructor
|_______________________________________________________________________*/



// [108] CompDocConstructor
// ------------------------
class CompDocConstructor : public exprnode
/*______________________________________________________________________
|
|	::= DOCUMENT_LBRACE  Expr  RBRACE
|_______________________________________________________________________*/
{
protected:
	rchandle<exprnode> expr_h;

public:
	CompDocConstructor(
		yy::location const&,
		rchandle<exprnode>);

	~CompDocConstructor();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> qname_expr_h;
	rchandle<exprnode> content_expr_h;

public:
	CompElemConstructor(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~CompElemConstructor();

public:
	rchandle<QName> get_qname() const { return qname_h; }
	rchandle<exprnode> get_qname_expr() const { return qname_expr_h; }
	rchandle<exprnode> get_content_expr() const { return content_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> expr_h;

public:
	ContentExpr(
		yy::location const&,
		rchandle<exprnode>);

	~ContentExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> qname_expr_h;
	rchandle<exprnode> val_expr_h;

public:
	CompAttrConstructor(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~CompAttrConstructor();

public:
	rchandle<QName> get_qname() const { return qname_h; }
	rchandle<exprnode> get_qname_expr() const { return qname_expr_h; }
	rchandle<exprnode> get_val_expr() const { return val_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> text_expr_h;

public:
	CompTextConstructor(
		yy::location const&,
		rchandle<exprnode> text_expr_h);

	~CompTextConstructor();

public:
	rchandle<exprnode> get_text_expr() const { return text_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> comment_expr_h;

public:
	CompCommentConstructor(
		yy::location const&,
		rchandle<exprnode>);

	~CompCommentConstructor();

public:
	rchandle<exprnode> get_comment_expr() const { return comment_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> target_expr_h;
	rchandle<exprnode> content_expr_h;

public:
	CompPIConstructor(
		yy::location const&,
		std::string target,
		rchandle<exprnode>);

	CompPIConstructor(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~CompPIConstructor();

public:
	std::string get_target() const { return target; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }
	rchandle<exprnode> get_content_expr() const { return content_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	SequenceType(
		yy::location const&,
		rchandle<ItemType>,
		rchandle<OccurrenceIndicator>);

	~SequenceType();

public:
	rchandle<ItemType> get_itemtype() const { return itemtype_h; }
	rchandle<OccurrenceIndicator> get_occur() const { return occur_h; }
	bool get_void_bit() const { return itemtype_h==NULL; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [118] OccurrenceIndicator
// -------------------------
class OccurrenceIndicator : public parsenode
/*______________________________________________________________________
|
|	::= HOOK | STAR | PLUS   gn:occurrence-indicatorsXQ
|_______________________________________________________________________*/
{
protected:
	enum occurrence_t type;

public:
	OccurrenceIndicator(
		yy::location const&,
		enum occurrence_t);

	~OccurrenceIndicator();

public:
	enum occurrence_t get_type() const { return type; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	bool item_test_b;

public:
	ItemType(
		yy::location const&,
		bool item_test_b);
		
	ItemType(yy::location const&);
		
	~ItemType();

public:
	bool get_item_test_bit() const { return item_test_b; }

public:
	virtual std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [120] AtomicType
// ----------------
class AtomicType : public parsenode
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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


// [121] KindTest
// --------------
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



// [122] AnyKindTest
// -----------------
class AnyKindTest : public parsenode
/*______________________________________________________________________
|
|	::= NODE_LPAR  RPAR
|_______________________________________________________________________*/
{
public:
	AnyKindTest(yy::location const&);
	~AnyKindTest();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	rchandle<ElementTest> elem_test_h;
	rchandle<SchemaElementTest> schema_elem_test_h;

public:
	DocumentTest(yy::location const&);

	DocumentTest(
		yy::location const&,
		rchandle<ElementTest>);
	
	DocumentTest(
		yy::location const&,
		rchandle<SchemaElementTest>);

	~DocumentTest();

public:
	rchandle<ElementTest> get_elem_test() const
		{ return elem_test_h; }
	rchandle<SchemaElementTest> get_schema_elem_test() const
		{ return schema_elem_test_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	TextTest(yy::location const&);
	~TextTest();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	CommentTest(yy::location const&);
	~CommentTest();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	rchandle<QName> attr_h;
	rchandle<TypeName> type_h;

public:
	AttributeTest(
		yy::location const&,
		rchandle<QName>,
		rchandle<TypeName>);

	~AttributeTest();

public:
	rchandle<QName> get_attr() const { return attr_h; }
	rchandle<TypeName> get_type() const { return type_h; }
	bool is_wild() const { return attr_h==NULL; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<QName> attr_h;

public:
	SchemaAttributeTest(
		yy::location const&,
		rchandle<QName>);

	~SchemaAttributeTest();

public:
	rchandle<QName> get_attr() const { return attr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<QName> elem_h;
	rchandle<TypeName> type_h;
	bool optional_b;

public:
	ElementTest(
		yy::location const&,
		rchandle<QName>,
		rchandle<TypeName>);

	ElementTest(
		yy::location const&,
		rchandle<QName>,
		rchandle<TypeName>,
		bool optional_bit);

	~ElementTest();

public:
	rchandle<QName> get_elem() const { return elem_h; }
	rchandle<TypeName> get_type() const { return type_h; }
	bool is_wild() const { return elem_h==NULL; }
	bool get_optional_bit() const { return optional_b; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<QName> elem_h;

public:
	SchemaElementTest(
		yy::location const&,
		rchandle<QName> _elem_h);

	~SchemaElementTest();

public:
	rchandle<QName> get_elem() const { return elem_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



/* inlined productions */
/* ------------------- */
// [128] AttribNameOrWildcard ::= AttributeName | STAR
// [130] AttributeDeclaration ::= AttributeName
// [132] ElementNameOrWildcard ::= ElementName | STAR
// [134] ElementDeclaration ::= ElementName
// [135] AttributeName ::= QNAME
// [136] ElementName ::= QNAME



// [137] TypeName
// --------------
class TypeName : public parsenode
/*______________________________________________________________________
|
|	::=  QName  |  QName "?"
|_______________________________________________________________________*/
// [137] TypeName ::= QNAME
{
protected:
	rchandle<QName> qname_h;
	bool optional_b;

public:
	TypeName(
		yy::location const&,
		rchandle<QName>);

	TypeName(
		yy::location const&,
		rchandle<QName>,
		bool);

	~TypeName();

public:
	rchandle<QName> get_name() const { return qname_h; }
	bool get_optional_bit() const { return optional_b; }
	
public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


/* lexical rules, see xquery.l */
/* --------------------------- */
// [138] IntegerLiteral
// [139] DecimalLiteral
// [140] DoubleLiteral
// [141] URILiteral 




// [142] StringLiteral
// -------------------
class StringLiteral : public exprnode
/*______________________________________________________________________
|
|	::= STRING_LITERAL
|_______________________________________________________________________*/
{
protected:
	std::string strval;

public:
	StringLiteral(
		yy::location const&,
		std::string const&);

	~StringLiteral();

public:
	std::string get_strval() const { return strval; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



/* lexical rules, see xquery.l */
/* --------------------------- */
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
class QName : public exprnode
/*______________________________________________________________________
|
|	::=  QNAME
|_______________________________________________________________________*/
{
protected:
	std::string qname;
	std::string theURI;

public:
	QName(
		const yy::location&,
		const std::string& qname);

	QName(
		const yy::location&,
		const std::string& qname,
		const std::string& uri);

	~QName();

public:
	std::string get_qname() const { return qname; }
	std::string get_uri() const { return theURI; }
	std::string get_localname() const;
	std::string get_prefix() const;

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	RevalidationDecl(
		yy::location const&,
		rchandle<QName>);

	~RevalidationDecl();

public:
	rchandle<QName> get_qname() const { return qname_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> source_expr_h;
	rchandle<exprnode> target_expr_h;

public:
	InsertExpr(
		yy::location const&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~InsertExpr();

public:
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> target_expr_h;

public:
	DeleteExpr(
		yy::location const&,
		rchandle<exprnode>);

	~DeleteExpr();

public:
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> source_expr_h;
	rchandle<exprnode> target_expr_h;

public:
	ReplaceExpr(
		yy::location const&,
		rchandle<exprnode> source_expr_h,
		rchandle<exprnode> target_expr_h);

	~ReplaceExpr();

public:
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> source_expr_h;
	rchandle<exprnode> target_expr_h;

public:
	RenameExpr(
		yy::location const&,
		rchandle<exprnode> source_expr_h,
		rchandle<exprnode> target_expr_h);

	~RenameExpr();

public:
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> source_expr_h;
	rchandle<exprnode> target_expr_h;

public:
	TransformExpr(
		yy::location const&,
		rchandle<VarNameList>,
		rchandle<exprnode> source_expr_h,
		rchandle<exprnode> target_expr_h);

	~TransformExpr();

public:
	rchandle<VarNameList> get_varname_list() const { return varname_list_h; }
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	VarNameList(yy::location const&);
	~VarNameList();

public:
	void push_back(rchandle<VarBinding> varbinding_h)
		{ varbinding_hv.push_back(varbinding_h); }
	rchandle<VarBinding> operator[](int i) const
		{ return varbinding_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<exprnode> val_h;

public:
	VarBinding(
		yy::location const&,
		std::string varname,
		rchandle<exprnode>);

	~VarBinding();

public:
	std::string get_varname() const { return varname; }
	rchandle<exprnode> get_val() const { return val_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



//[344a] FTMatchOptionProximityList
//---------------------------------
class FTMatchOptionProximityList : public parsenode
/*______________________________________________________________________
|
|	::=	FTMatchOptionProximity
|			| FTMatchOptionProximityList  FTMatchOptionProximity
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<FTMatchOptionProximity> > opt_prox_hv;

public:
	FTMatchOptionProximityList(yy::location const&);
	~FTMatchOptionProximityList();

public:
	void push_back(rchandle<FTMatchOptionProximity> opt_prox_h)
		{ opt_prox_hv.push_back(opt_prox_h); }
	rchandle<FTMatchOptionProximity> operator[](int i)
		{ return opt_prox_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



//[344b] FTMatchOptionProximity
//-----------------------------
class FTMatchOptionProximity : public parsenode
/*______________________________________________________________________
|
|	::=	FTMatchOption | FTProximity
|_______________________________________________________________________*/
{
protected:
	rchandle<FTMatchOption> opt_h;
	rchandle<FTProximity> prox_h;

public:
	FTMatchOptionProximity(
		rchandle<FTMatchOption>,
		yy::location const&);

	FTMatchOptionProximity(
		rchandle<FTProximity>,
		yy::location const&);

	FTMatchOptionProximity(
		yy::location const&);

	~FTMatchOptionProximity();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	rchandle<StringLiteral> lit_h;
	rchandle<Expr> expr_h;

public:
	FTWordsValue(
		yy::location const&,
		rchandle<StringLiteral>,
		rchandle<Expr>);

	~FTWordsValue();

public:
	rchandle<StringLiteral> get_lit() const { return lit_h; }
	rchandle<Expr> get_expr() const { return expr_h; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	FTProximity(yy::location const&);
	~FTProximity();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	FTOrderedIndicator(yy::location const&);
	~FTOrderedIndicator();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	FTMatchOption(yy::location const&);
	~FTMatchOption();

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	ft_case_mode_t mode;

public:
	FTCaseOption(
		yy::location const&,
		enum ft_case_mode_t);

	~FTCaseOption();

public:
	enum ft_case_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	ft_diacritics_mode_t mode;

public:
	FTDiacriticsOption(
		yy::location const&,
		ft_diacritics_mode_t);

	~FTDiacriticsOption();

public:
	enum ft_diacritics_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;

public:
	void accept(parsenode_visitor&) const;

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
	FTThesaurusList(yy::location const&);
	~FTThesaurusList();

public:
	void push_back(rchandle<FTThesaurusID> thesaurus_h)
		{ thesaurus_hv.push_back(thesaurus_h); }
	rchandle<FTThesaurusID> operator[](int i) const
		{ return thesaurus_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	FTInclExclStringLiteralList(yy::location const&);
	~FTInclExclStringLiteralList();

public:
	void push_back(rchandle<FTInclExclStringLiteral> incl_excl_lit_h)
		{ incl_excl_lit_hv.push_back(incl_excl_lit_h); }
	rchandle<FTInclExclStringLiteral> operator[](int i) const
		{ return incl_excl_lit_hv[i]; }

public:
	std::ostream& put(std::ostream&) const;

public:
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
	FTStringLiteralList(yy::location const&);
	~FTStringLiteralList();

public:
	void push_back(std::string strlit) { strlit_v.push_back(strlit); }
	std::string operator[](int i) const { return strlit_v[i]; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	rchandle<FTRefOrList> ref_or_list_h;
	intex_op_t mode;

public:
	FTInclExclStringLiteral(
		yy::location const&,
		rchandle<FTRefOrList>,
		intex_op_t);

	~FTInclExclStringLiteral();

public:
	rchandle<FTRefOrList> get_ref_or_list() const
		{ return ref_or_list_h; }
	intex_op_t get_mode() const
		{ return mode; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	ft_content_mode_t mode;

public:
	FTContent(
		yy::location const&,
		enum ft_content_mode_t);

	~FTContent();

public:
	enum ft_content_mode_t get_mode() const { return mode; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	enum ft_anyall_option_t option;

public:
	FTAnyallOption(
		yy::location const&,
		enum ft_anyall_option_t);

	~FTAnyallOption();

public:
	enum ft_anyall_option_t get_option() const { return option; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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
protected:
	ft_scope_t scope;

public:
	FTScope(
		yy::location const&,
		ft_scope_t);

	~FTScope();

public:
	enum ft_scope_t get_scope() const { return scope; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



//[372]	FTUnit
//------------
class FTUnit : public parsenode
/*______________________________________________________________________
|
|	::=	WORDS | SENTENCES | PARAGRAPH
|_______________________________________________________________________*/
{
protected:
	ft_unit_t unit;

public:
	FTUnit(
		yy::location const&,
		ft_unit_t);

	~FTUnit();

public:
	enum ft_unit_t get_unit() const { return unit; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};



//[373]	FTBigUnit
//---------------
class FTBigUnit : public parsenode
/*______________________________________________________________________
|
|	::=	SENTENCE | PARAGRAPH
|_______________________________________________________________________*/
{
protected:
	enum ft_big_unit_t unit;

public:
	FTBigUnit(
		yy::location const&,
		enum ft_big_unit_t);

	~FTBigUnit();

public:
	enum ft_big_unit_t get_unit() const { return unit; }

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

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

public:
	std::ostream& put(std::ostream&) const;
	void accept(parsenode_visitor&) const;

};


}	/* namespace xqp */
#endif	/*  XQP_PARSENODES_H */
