/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: parsenodes.h,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 */

#ifndef XQP_PARSENODES_H
#define XQP_PARSENODES_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>

#include "compiler/parser/parse_constants.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "store/api/item.h"
#include "util/rchandle.h"
#include "compiler/parser/location.hh"

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

    friend class ParseNodePrintXMLVisitor;

public:
	parsenode(const yy::location& _loc) : loc(_loc) { }
  virtual ~parsenode() {}

public:
	const yy::location& get_location() const { return loc; }
  
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
	exprnode(const yy::location& loc) : parsenode(loc) { }
  virtual ~exprnode() {}

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
class ForOrLetClause;
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
	Module(const yy::location&);
	~Module();

public:
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

    friend class ParseNodePrintXMLVisitor;

public:
	VersionDecl(
		const yy::location&,
		std::string const& version,
		std::string const& encoding);

	~VersionDecl();

public:
	std::string get_version() const { return version; }
	std::string get_encoding() const { return encoding; }

public:
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
		const yy::location&,
		rchandle<Prolog>,
		rchandle<QueryBody>);
	
	MainModule(
		const yy::location&,
		rchandle<QueryBody>);

	~MainModule();

public:
	rchandle<Prolog> get_prolog() const { return prolog_h; }
	rchandle<QueryBody> get_query_body() const { return query_body_h; }

public:
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
		const yy::location&,
		rchandle<ModuleDecl>, 
		rchandle<Prolog>);

	~LibraryModule();

public:
	rchandle<ModuleDecl> get_decl() const { return decl_h; }
	rchandle<Prolog> get_prolog() const { return prolog_h; }

public:
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
		const yy::location&,
		std::string const& prefix,
		std::string const& target_namespace);

	~ModuleDecl();

public:
	std::string get_prefix() const { return prefix; }
	std::string get_target_namespace() const { return target_namespace; }

public:
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
		const yy::location&,
		rchandle<SIND_DeclList>,
		rchandle<VFO_DeclList>);

	~Prolog();

public:
	rchandle<SIND_DeclList> get_sind_list() const { return sind_list_h; }
	rchandle<VFO_DeclList> get_vfo_list() const { return vfo_list_h; }

public:
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
	SIND_DeclList(const yy::location&);
	~SIND_DeclList();

public:
	void push_back(rchandle<parsenode> sind_h) { sind_hv.push_back(sind_h); }
	rchandle<parsenode> operator[](int k) const { return sind_hv[k]; }

public:
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
	VFO_DeclList(const yy::location&);
	~VFO_DeclList();

public:
	void push_back(rchandle<parsenode> vfo_h) { vfo_hv.push_back(vfo_h); }
	rchandle<parsenode> operator[](int k) const { return vfo_hv[k]; }

public:
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
	std::string thePrefix;
	std::string theUri;

public:
	NamespaceDecl(
		const yy::location&,
		std::string const& prefix,
		std::string const& uri);

	~NamespaceDecl();

public:
	std::string get_prefix() const { return thePrefix; }
	std::string get_uri() const { return theUri; }

public:
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
	StaticQueryContext::boundary_space_mode_t mode;

public:
	BoundarySpaceDecl(
		const yy::location&,
		StaticQueryContext::boundary_space_mode_t);

	~BoundarySpaceDecl();

public:
	StaticQueryContext::boundary_space_mode_t
		get_boundary_space_mode() const { return mode; }

public:
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
		const yy::location&,
		enum default_namespace_mode_t mode,
		std::string const& default_namespace);

	~DefaultNamespaceDecl();

public:
	enum default_namespace_mode_t get_mode() const { return mode; }
	std::string get_default_namespace() const { return default_namespace; }

public:
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
		const yy::location&,
		rchandle<QName> qname_h,
		std::string const& val);

	~OptionDecl();

public:
	rchandle<QName> get_qname() const { return qname_h; }
	std::string get_val() const { return val; }

public:
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
		const yy::location&,
		rchandle<parsenode>);

	~FTOptionDecl();

public:
	rchandle<parsenode> get_match_option() const { return match_option_h; }

public:
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
	StaticQueryContext::ordering_mode_t mode;
		
public:
	OrderingModeDecl(
		const yy::location&,
		StaticQueryContext::ordering_mode_t);

	~OrderingModeDecl();
	
public:
	StaticQueryContext::ordering_mode_t get_mode() const { return mode; }

public:
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
	StaticQueryContext::order_empty_mode_t mode;

public:
	EmptyOrderDecl(
		const yy::location&,
		StaticQueryContext::order_empty_mode_t);

	~EmptyOrderDecl();
	
public:
	StaticQueryContext::order_empty_mode_t get_mode() const { return mode; }

public:
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
	StaticQueryContext::preserve_mode_t preserve_mode;
	StaticQueryContext::inherit_mode_t inherit_mode;

public:
	CopyNamespacesDecl(
		const yy::location&,
		StaticQueryContext::preserve_mode_t preserve_mode,
		StaticQueryContext::inherit_mode_t  inherit_mode);

	~CopyNamespacesDecl();

public: 
	StaticQueryContext::preserve_mode_t get_preserve_mode() const
  { return preserve_mode; }
	StaticQueryContext::inherit_mode_t  get_inherit_mode() const
  { return inherit_mode; }

public:
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
		const yy::location&,
		std::string const&  collation);

	~DefaultCollationDecl();

public:
	std::string get_collation() const { return collation; }

public:
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
		const yy::location&,
		std::string const& base_uri);

	~BaseURIDecl();

public:
	std::string get_base_uri() const { return base_uri; }

public:
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
		const yy::location&,
		rchandle<SchemaPrefix>,
		std::string const& uri,
		rchandle<URILiteralList>);

	~SchemaImport();

public:
	rchandle<SchemaPrefix> get_prefix() const { return prefix_h; }
	std::string get_uri() const { return uri; }
	rchandle<URILiteralList> get_at_list() const { return at_list_h; }

public:
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
		const yy::location&);

	~URILiteralList();

public:
	void push_back(std::string const& uri) { uri_v.push_back(uri); }
	std::string operator[](int i) const { return uri_v[i]; }

public:
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
		const yy::location&,
		bool default_b);

	SchemaPrefix(
		const yy::location&,
		std::string const& prefix);

	~SchemaPrefix();

public:
	std::string get_prefix() const { return prefix; }
	bool get_default_bit() const { return default_b; }

public:
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
		const yy::location&,
		std::string const& uri,
		rchandle<URILiteralList>);
	ModuleImport(
		const yy::location&,
		std::string const& prefix,
		std::string const& uri,
		rchandle<URILiteralList>);
	~ModuleImport();

public:
	std::string get_prefix() const { return prefix; }
	std::string get_uri() const { return uri; }
	rchandle<URILiteralList> get_uri_list() const { return uri_list_h; }

public:
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
		const yy::location&,
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
	StaticQueryContext::construction_mode_t mode;

public:
	ConstructionDecl(
		const yy::location&,
		StaticQueryContext::construction_mode_t);

	~ConstructionDecl();

public:
	StaticQueryContext::construction_mode_t get_mode() const { return mode; }

public:
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
		const yy::location&,
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
	ParamList(const yy::location&);
	~ParamList();

public:
	void push_back(rchandle<Param> param_h) { param_hv.push_back(param_h); }
	rchandle<Param> operator[](int i) const { return param_hv[i]; }
  std::vector<rchandle<Param> >::const_iterator begin () const { return param_hv.begin (); }
  std::vector<rchandle<Param> >::const_iterator end () const { return param_hv.end (); }

public:
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
		const yy::location&,
		std::string name,
		rchandle<TypeDeclaration>);

	~Param();

public:
	std::string get_name() const { return name; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }

public:
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
		const yy::location&,
		rchandle<exprnode>);

	~EnclosedExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }
	
public:
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
		const yy::location&,
		rchandle<exprnode>);

	QueryBody();

	~QueryBody();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }
	
public:
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
	Expr(const yy::location&);
	~Expr();

public:
	void push_back(rchandle<exprnode> expr_h) { expr_hv.push_back(expr_h); }
	rchandle<exprnode> operator[](int i) const { return expr_hv[i]; }
    int  numberOfChildren() const;

public:
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
		const yy::location&,
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
	void accept(parsenode_visitor&) const;

};


// [33a] ForLetClauseList
// ----------------------
class ForLetClauseList : public parsenode
/*______________________________________________________________________
|
|	::= ForOrLetClause
|			|	ForOrLetClause  ForLetClauseList
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<ForOrLetClause> > forlet_hv;

public:
	ForLetClauseList(const yy::location&);
	~ForLetClauseList();

public:
	void push_back(rchandle<ForOrLetClause> forlet_h) { forlet_hv.push_back(forlet_h); }
	rchandle<ForOrLetClause> operator[](int i) const { return forlet_hv[i]; }
  int size () const { return forlet_hv.size (); }

public:
	void accept(parsenode_visitor&) const;

};


// [33b] ForOrLetClause
/*______________________________________________________________________
|	::= ForClause | LetClause
|_______________________________________________________________________*/

class ForOrLetClause : public parsenode {
public:
  ForOrLetClause (const yy::location& _loc) : parsenode (_loc) {}
  typedef enum { for_clause, let_clause } for_or_let_t;
  virtual for_or_let_t for_or_let () const = 0;
  virtual int get_decl_count () const = 0;
};

// [34] ForClause
// --------------
class ForClause : public ForOrLetClause
/*______________________________________________________________________
|
|	::= FOR_DOLLAR  VarInDeclList
|_______________________________________________________________________*/
{
protected:
	rchandle<VarInDeclList> vardecl_list_h;

public:
	ForClause(
		const yy::location&,
		rchandle<VarInDeclList>);

	~ForClause();

public:
	rchandle<VarInDeclList> get_vardecl_list() const { return vardecl_list_h; }

public:
	void accept(parsenode_visitor&) const;

public:
  for_or_let_t for_or_let () const { return for_clause; }
  int get_decl_count () const;
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
	VarInDeclList(const yy::location&);
	~VarInDeclList();

public:
	void push_back(rchandle<VarInDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }
	rchandle<VarInDecl> operator[](int i) const { return vardecl_hv[i]; }
	int size() const { return vardecl_hv.size();}

public:
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
	std::string varname;  // TODO: qname
	rchandle<TypeDeclaration> typedecl_h;
	rchandle<PositionalVar> posvar_h;
	rchandle<FTScoreVar> ftscorevar_h;
	rchandle<exprnode> valexpr_h;
	
public:
	VarInDecl(
		const yy::location&,
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
		const yy::location&,
		std::string const& varname);

	~PositionalVar();

public:
	std::string get_varname() const { return varname; }

public:
	void accept(parsenode_visitor&) const;

};


// [36] LetClause
// --------------
class LetClause : public ForOrLetClause
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
		const yy::location&,
		rchandle<VarGetsDeclList>);
	~LetClause();

public:
	rchandle<VarGetsDeclList> get_vardecl_list() const { return vardecl_list_h; }

public:
	void accept(parsenode_visitor&) const;

public:
  for_or_let_t for_or_let () const { return let_clause; }
  int get_decl_count () const;
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
	VarGetsDeclList(const yy::location&);
	~VarGetsDeclList();

public:
	void push_back(rchandle<VarGetsDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }
	rchandle<VarGetsDecl> operator[](int i) const { return vardecl_hv[i]; }

public:
	void accept(parsenode_visitor&) const;

public:
  int size () const { return vardecl_hv.size (); }
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
		const yy::location&,
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
		const yy::location&,
		std::string varname);
	~FTScoreVar();

public:
	std::string get_varname() const { return varname; }

public:
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
		const yy::location&,
		rchandle<exprnode>);
	~WhereClause();

public:
	rchandle<exprnode> get_predicate() const { return predicate_h; }

public:
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
		const yy::location&,
		rchandle<OrderSpecList>,
		bool stable_b = false);
	~OrderByClause();

public:
	rchandle<OrderSpecList> get_spec_list() const { return spec_list_h; }
	bool get_stable_bit() const { return stable_b; }

public:
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
	OrderSpecList(const yy::location&);
	~OrderSpecList();

public:
	void push_back(rchandle<OrderSpec> spec_h) { spec_hv.push_back(spec_h); }
	rchandle<OrderSpec> operator[](int i) const { return spec_hv[i]; }
  size_t size () { return spec_hv.size (); }

public:
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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<OrderModifier>);
	~OrderSpec();

public:
	rchandle<exprnode> get_spec() const { return spec_h; }
	rchandle<OrderModifier> get_modifier() const { return modifier_h; }

public:
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
		const yy::location&,
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
		const yy::location&,
		dir_spec_t dir_spec);
	~OrderDirSpec();
	
public:
	dir_spec_t get_dir_spec() const { return dir_spec; }

public:
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
	StaticQueryContext::order_empty_mode_t empty_order_spec;

public:
	OrderEmptySpec(
		const yy::location&,
		StaticQueryContext::order_empty_mode_t empty_order_spec);
	~OrderEmptySpec();

public:
	StaticQueryContext::order_empty_mode_t get_empty_order_spec() const
		{ return empty_order_spec; }

public:
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
		const yy::location&,
		std::string const& uri);
	~OrderCollationSpec();

public:
	std::string get_uri() const { return uri; }

public:
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
		const yy::location&,
		quantification_mode_t qmode,
		rchandle<QVarInDeclList>,
		rchandle<exprnode>);
	~QuantifiedExpr();

public:
	quantification_mode_t get_qmode() const { return qmode; }
	rchandle<QVarInDeclList> get_decl_list() const { return decl_list_h; }
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
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
	QVarInDeclList(const yy::location&);
	~QVarInDeclList();

public:
	void push_back(rchandle<QVarInDecl> decl_h) { qvar_decl_hv.push_back(decl_h); }
	rchandle<QVarInDecl> operator[](int i) const { return qvar_decl_hv[i]; }
	int size() { return qvar_decl_hv.size();}

public:
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
		const yy::location&,
		std::string name,
		rchandle<exprnode>);

	QVarInDecl(
		const yy::location&,
		std::string name,
		rchandle<TypeDeclaration>,
		rchandle<exprnode>);

	~QVarInDecl();

public:
	std::string get_name() const { return name; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<exprnode> get_val() const { return val_h; }

public:
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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<CaseClauseList>,
		rchandle<exprnode>);

	TypeswitchExpr(
		const yy::location&,
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
	CaseClauseList(const yy::location&);
	~CaseClauseList();

public:
	void push_back(rchandle<CaseClause> clause_h)
  { clause_hv.push_back(clause_h); }
	rchandle<CaseClause> operator[](int i) const
  { return clause_hv[i]; }
	std::vector<rchandle<CaseClause> >::const_iterator begin() const
  { return clause_hv.begin(); }
	std::vector<rchandle<CaseClause> >::const_iterator end() const
  { return clause_hv.end(); }
	std::vector<rchandle<CaseClause> >::const_reverse_iterator rbegin() const
  { return clause_hv.rbegin(); }
	std::vector<rchandle<CaseClause> >::const_reverse_iterator rend() const
  { return clause_hv.rend(); }
	uint32_t size() const 
  { return clause_hv.size(); }

public:
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
		const yy::location&,
		std::string varname,
		rchandle<SequenceType>,
		rchandle<exprnode>);
		
	CaseClause(
		const yy::location&,
		rchandle<SequenceType>,
		rchandle<exprnode>);
		
	~CaseClause();

public:
	std::string get_varname() const { return varname; }
	rchandle<SequenceType> get_type() const { return type_h; }
	rchandle<exprnode> get_val() const { return val_h; }

public:
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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>,
		rchandle<exprnode>);
	~IfExpr();

public:
	rchandle<exprnode> get_cond_expr() const { return cond_expr_h; }
	rchandle<exprnode> get_then_expr() const { return then_expr_h; }
	rchandle<exprnode> get_else_expr() const { return else_expr_h; }

public:
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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~OrExpr();

public:
	rchandle<exprnode> get_or_expr() const { return or_expr_h; }
	rchandle<exprnode> get_and_expr() const { return and_expr_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~AndExpr();

public:
	rchandle<exprnode> get_and_expr() const { return and_expr_h; }
	rchandle<exprnode> get_comp_expr() const { return comp_expr_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<ValueComp>,
		rchandle<exprnode>,
		rchandle<exprnode>);

	ComparisonExpr(
		const yy::location&,
		rchandle<GeneralComp>,
		rchandle<exprnode>,
		rchandle<exprnode>);

	ComparisonExpr(
		const yy::location&,
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
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<FTSelection>,
		rchandle<FTIgnoreOption>);

	~FTContainsExpr();

public:
	rchandle<exprnode> get_range_expr() const { return range_expr_h; }
	rchandle<FTSelection> get_ftselect() const { return ftselect_h; }
	rchandle<FTIgnoreOption> get_ftignore() const { return ftignore_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~RangeExpr();

public:
	rchandle<exprnode> get_from_expr() const { return from_expr_h; }
	rchandle<exprnode> get_to_expr() const { return to_expr_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		add_op_t add_op,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~AdditiveExpr();

public:
	add_op_t get_add_op() const { return add_op; }
	rchandle<exprnode> get_add_expr() const { return add_expr_h; }
	rchandle<exprnode> get_mult_expr() const { return mult_expr_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		mult_op_t,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~MultiplicativeExpr();

public:
	rchandle<exprnode> get_mult_expr() const { return mult_expr_h; }
	rchandle<exprnode> get_union_expr() const { return union_expr_h; }
	mult_op_t get_mult_op() const { return mult_op; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~UnionExpr();

public:
	rchandle<exprnode> union_expr() const { return union_expr_h; }
	rchandle<exprnode> intex_expr() const { return intex_expr_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		enum intex_op_t,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~IntersectExceptExpr();

public:
	rchandle<exprnode> get_intex_expr() const { return intex_expr_h; }
	enum intex_op_t get_intex_op() const { return intex_op; }
	rchandle<exprnode> get_instof_expr() const { return instof_expr_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<SequenceType>);

	~InstanceofExpr();

public:
	rchandle<exprnode> get_treat_expr() const { return treat_expr_h; }
	rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<SequenceType>);

	~TreatExpr();

public:
	rchandle<exprnode> get_castable_expr() const { return castable_expr_h; }
	rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<SingleType>);

	~CastableExpr();

public:
	rchandle<exprnode> cast_expr() const { return cast_expr_h; }
	rchandle<SingleType> singletype() const { return singletype_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<SingleType>);
	
	~CastExpr();

public:
	rchandle<exprnode> get_unary_expr() const { return unary_expr_h; }
	rchandle<SingleType> get_singletype() const { return singletype_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		rchandle<SignList>,
		rchandle<exprnode>);

	~UnaryExpr();

public:
	rchandle<exprnode> get_value_expr() const { return value_expr_h; }
	rchandle<SignList> get_signlist() const { return signlist_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

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
		const yy::location&,
		bool _sign);

	~SignList();

public:
	bool get_sign() const { return sign; }
	void negate() { sign = !sign; }

public:
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
		const yy::location&,
		enum gencomp_t);

	GeneralComp();

	~GeneralComp();

public:
	enum gencomp_t get_type() const { return type; }
	
public:
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
		const yy::location&,
		enum valcomp_t);

	ValueComp();

	~ValueComp();

public:
	enum valcomp_t get_type() const { return type; }
	
public:
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
		const yy::location&,
		enum nodecomp_t);

	NodeComp();

	~NodeComp();

public:
	enum nodecomp_t get_type() const { return type; }
	
public:
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
		const yy::location&,
		std::string const& valmode,
		rchandle<exprnode>);

	~ValidateExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }
	enum validation_mode_t get_valmode() const { return valmode; }

public:
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
		const yy::location&,
		rchandle<PragmaList>,
		rchandle<exprnode>);

	~ExtensionExpr();

public:
	rchandle<PragmaList> get_pragma_list() const { return pragma_list_h; }
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
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
	PragmaList(const yy::location&);
	~PragmaList();

public:
	void push_back(rchandle<Pragma> pragma_h) { pragma_hv.push_back(pragma_h); }
	rchandle<Pragma> operator[](int i) const { return pragma_hv[i]; }

public:
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
		const yy::location&,
		rchandle<QName>,
		std::string pragma_lit);

	~Pragma();

public:
	rchandle<QName> get_name() const { return name_h; }
	std::string get_pragma_lit() const { return pragma_lit; }

public:
	void accept(parsenode_visitor&) const;

};



// [66] PragmaContents
// -------------------
/* folded into [65] */



/*******************************************************************************

  [68] PathExpr	::= LEADING_LONE_SLASH |
                    SLASH  RelativePathExpr |
                    SLASH_SLASH  RelativePathExpr |
                    RelativePathExpr	 								 gn:leading-lone-slashXQ

  Constraint: leading-lone-slash

  A single slash may appear either as a complete path expression or as the first
  part of a path expression in which it is followed by a RelativePathExpr, which
  can take the form of a NameTest ("*" or a QName). In contexts where operators
  like "*", "union", etc., can occur, parsers may have difficulty distinguishing
  operators from NameTests. For example, without lookahead the first part of the
  expression "/ * 5", for example is easily taken to be a complete expression,
  "/ *", which has a very different interpretation (the child nodes of "/").
 
  To reduce the need for lookahead, therefore, if the token immediately following
  a slash is "*" or a keyword, then the slash must be the beginning, but not the
  entirety, of a PathExpr (and the following token must be a NameTest, not an
  operator).
 
  A single slash may be used as the left-hand argument of an operator by
  parenthesizing it: (/) * 5. The expression 5 * /, on the other hand, is legal
  without parentheses.

********************************************************************************/
class PathExpr : public exprnode
{
protected:
	enum pathtype_t type;
	rchandle<exprnode> relpath_expr_h;

public:
	PathExpr(
		const yy::location&,
		enum pathtype_t type,
		rchandle<exprnode>);

	~PathExpr();

public:
	enum pathtype_t get_type() const { return type; }
	rchandle<exprnode> get_relpath_expr() const { return relpath_expr_h; }

public:
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

	[69] RelativePathExpr ::= StepExpr |
                            StepExpr  SLASH  RelativePathExpr |
                            StepExpr  SLASH_SLASH  RelativePathExpr 

  Note: for the 1st alternative production, a RelativePathExpr node is generated
  whose left child is a ContextItemExpr and its right child is the StepExpr.

********************************************************************************/
class RelativePathExpr : public exprnode
{
protected:
	enum steptype_t step_type;
	rchandle<exprnode> step_expr_h;
	rchandle<exprnode> relpath_expr_h;

public:
	RelativePathExpr(
		const yy::location&,
		enum steptype_t,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~RelativePathExpr();

public:
	enum steptype_t get_step_type() const { return step_type; }
	rchandle<exprnode> get_step_expr() const { return step_expr_h; }
	rchandle<exprnode> get_relpath_expr() const { return relpath_expr_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

[70] StepExpr ::= AxisStep  |  FilterExpr

********************************************************************************/


/*******************************************************************************

 [71] AxisStep ::= (ForwardStep | ReverseStep)  PredicateList?

********************************************************************************/
class AxisStep : public exprnode
{
protected:
	rchandle<ForwardStep> forward_step_h;
	rchandle<ReverseStep> reverse_step_h;
	rchandle<PredicateList> predicate_list_h;

public:
	AxisStep(
		const yy::location&,
		rchandle<ForwardStep>,
		rchandle<PredicateList>);

	AxisStep(
		const yy::location&,
		rchandle<ReverseStep>,
		rchandle<PredicateList>);

	~AxisStep();

public:
	rchandle<ForwardStep> get_forward_step() const { return forward_step_h; }
	rchandle<ReverseStep> get_reverse_step() const { return reverse_step_h; }
	rchandle<PredicateList> get_predicate_list() const { return predicate_list_h; }

public:
	virtual	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

   [72] ForwardStep	::= ForwardAxis  NodeTest | AbbrevForwardStep

********************************************************************************/
class ForwardStep : public parsenode
{
protected:
	rchandle<ForwardAxis> forward_axis_h;
	rchandle<parsenode> node_test_h;
	rchandle<AbbrevForwardStep> abbrev_step_h;

public:
	ForwardStep(
		const yy::location&,
		rchandle<ForwardAxis>,
		rchandle<parsenode> node_test_h);

	ForwardStep(
		const yy::location&,
		rchandle<AbbrevForwardStep>);

	~ForwardStep();

public:
	rchandle<ForwardAxis> get_forward_axis() const { return forward_axis_h; }
	rchandle<parsenode> get_node_test() const { return node_test_h; }
	rchandle<AbbrevForwardStep> get_abbrev_step() const { return abbrev_step_h; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [73] ForwardAxis ::= CHILD_AXIS	|
                       DESCENDANT_AXIS |
                       ATTRIBUTE_AXIS |
                       SELF_AXIS |
                       DESCENDANT_OR_SELF_AXIS |
                       FOLLOWING_SIBLING_AXIS |
                       FOLLOWING_AXIS

********************************************************************************/
class ForwardAxis : public parsenode
{
protected:
	enum forward_axis_t axis;

public:
	ForwardAxis(
		const yy::location&,
		enum forward_axis_t);

	~ForwardAxis();

public:
	enum forward_axis_t get_axis() const { return axis; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [74] AbbrevForwardStep ::= NodeTest |	AT_SIGN  NodeTest

********************************************************************************/
class AbbrevForwardStep : public parsenode
{
protected:
	rchandle<parsenode> node_test_h;
	bool attr_b;
	
public:
	AbbrevForwardStep(
		const yy::location&,
		rchandle<parsenode>,
		bool attr_b);
		
	AbbrevForwardStep(
		const yy::location&,
		rchandle<parsenode>);
		
	~AbbrevForwardStep();

public:
	rchandle<parsenode> get_node_test() const { return node_test_h; }
	bool get_attr_bit() const { return attr_b; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [75] ReverseStep ::= ReverseAxis  NodeTest |	DOT_DOT

********************************************************************************/
class ReverseStep : public parsenode
{
protected:
	rchandle<ReverseAxis> axis_h;
	rchandle<parsenode> node_test_h;

public:
	ReverseStep(
		const yy::location&,
		rchandle<ReverseAxis>,
		rchandle<parsenode>);

	ReverseStep(
		const yy::location&,
		rchandle<ReverseAxis>);

	~ReverseStep();

public:
	rchandle<ReverseAxis> get_axis() const { return axis_h; }
	rchandle<parsenode> get_node_test() const { return node_test_h; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

 [76] ReverseAxis ::= PARENT_AXIS |
                      ANCESTOR_AXIS |
                      PRECEDING_SIBLING_AXIS |
                      PRECEDING_AXIS |
                      ANCESTOR_OR_SELF_AXIS

********************************************************************************/
class ReverseAxis : public parsenode
{
protected:
	enum reverse_axis_t axis;

public:
	ReverseAxis(
		const yy::location&,
		enum reverse_axis_t);

	~ReverseAxis();

public:
	enum reverse_axis_t get_axis() const { return axis; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [77] AbbrevReverseStep ::= folded into [75]

********************************************************************************/


/*******************************************************************************

  [78] NodeTest	::= KindTest | NameTest

********************************************************************************/


/*******************************************************************************

  [79] NameTest	::= QNAME | Wildcard

  qname_h and wild_h cannot both be non-NULL

********************************************************************************/
class NameTest : public parsenode
{
protected:
	rchandle<QName>    theQName;
	rchandle<Wildcard> theWildcard;

public:
	NameTest(const yy::location& l, rchandle<QName> n);

	NameTest(const yy::location& l, rchandle<Wildcard> w);

	~NameTest();

public:
	rchandle<QName> getQName() const { return theQName; }
  rchandle<Wildcard> getWildcard() const { return theWildcard; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [80] Wildcard	::= STAR |
                    ELEM_WILDCARD |
                    PREFIX_WILDCARD    ws:explicitXQ

  At least one of thePrefix and theLocalName will be the empty string.

********************************************************************************/
class Wildcard : public parsenode
{
protected:
	enum wildcard_t theKind;
	xqp_string      thePrefix;
  xqp_string      theLocalName;
	
public:
	Wildcard(
		const yy::location& loc,
    const xqp_string& prefix,
    const xqp_string& lname,
		enum wildcard_t type);

	~Wildcard();

public:
	enum wildcard_t getKind() const        { return theKind; }
	const xqp_string& getPrefix() const    { return thePrefix; }
	const xqp_string& getLocalName() const { return theLocalName; }

public:
	void accept(parsenode_visitor&) const;
};



// [81] FilterExpr
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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<PredicateList>);

	~FilterExpr();

public:
	rchandle<exprnode> get_primary() const { return primary_h; }
	rchandle<PredicateList> get_pred_list() const { return pred_list_h; }

public:
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
	PredicateList(const yy::location&);
	~PredicateList();

public:
	void push_back(rchandle<exprnode> pred_h) { pred_hv.push_back(pred_h); }
	rchandle<exprnode> operator[](int i) { return pred_hv[i]; }
    int size() { return pred_hv.size(); }

public:
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

protected:
	enum numeric_type_t type;
	union {
		int ival;
		decimal decval;
		double dval;
	};

public:
	NumericLiteral(
		const yy::location&,
		int);

	NumericLiteral(
		const yy::location&,
		decimal);

	NumericLiteral(
		const yy::location&,
		double);

	~NumericLiteral();

public:
	enum numeric_type_t get_type() const { return type; }
	int get_int() const { return ival; }
	decimal get_decimal() const { return decval; }
	double get_double() const { return dval; }

public:
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
		const yy::location&,
		std::string varname);

	~VarRef();

public:
	std::string get_varname() const { return varname; }

public:
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
		const yy::location&,
		rchandle<exprnode>);

	~ParenthesizedExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
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
	ContextItemExpr(const yy::location&);
	~ContextItemExpr();

public:
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
		const yy::location&,
		rchandle<exprnode>);

	~OrderedExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
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
		const yy::location&,
		rchandle<exprnode>);

	~UnorderedExpr();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
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
		const yy::location&,
		rchandle<QName>,
		rchandle<ArgList>);

	~FunctionCall();

public:
	rchandle<QName> get_fname() const { return fname_h; }
	rchandle<ArgList> get_arg_list() const { return arg_list_h; }

public:
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
	ArgList(const yy::location&);
	~ArgList();

public:
	void push_back(rchandle<exprnode> arg_h) { arg_hv.push_back(arg_h); }
	rchandle<exprnode> operator[](int i) const { return arg_hv[i]; }
  int size () { return arg_hv.size (); }

public:
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

  [92] Constructor ::= DirectConstructor |	ComputedConstructor

  [93] DirectConstructor ::= DirElemConstructor |
                             DirCommentConstructor |
                            DirPIConstructor

********************************************************************************/


/*******************************************************************************

  [94] DirElemConstructor ::= LT QNAME DirAttributeList SGT  ws:explicitXQ
                            | LT QNAME DirAttributeList GT DirElemContentList
                              LTS QNAME GT               ws:explicitXQ,  gn:ltXQ

********************************************************************************/
class DirElemConstructor : public exprnode
{
protected:
	rchandle<QName> elem_name_h;
	rchandle<DirAttributeList> attr_list_h;
	rchandle<DirElemContentList> dir_content_list_h;

public:
	DirElemConstructor(
		const yy::location&,
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
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

  [94a] DirElemContentList ::= DirElemContent |
                               DirElemContentList DirElemContent

********************************************************************************/
class DirElemContentList : public parsenode
{
protected:
	std::vector<rchandle<DirElemContent> > dir_content_hv;

public:
	DirElemContentList(const yy::location&);
	~DirElemContentList();

public:
	void push_back(rchandle<DirElemContent> dir_content_h)
		{ dir_content_hv.push_back(dir_content_h); }
	rchandle<DirElemContent> operator[](int i) const
		{ return dir_content_hv[i]; }

public:
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

  [99] DirElemContent ::= DirectConstructor |
                          ELEMENT_CONTENT |
                          CDataSection |
                          CommonContent

********************************************************************************/
class DirElemContent : public exprnode
{
protected:
	rchandle<exprnode> direct_cons_h;
	std::string elem_content;
	rchandle<CDataSection> cdata_h;
	rchandle<CommonContent> common_content_h;
  mutable bool theIsStripped;

public:
	DirElemContent(
		const yy::location&,
		rchandle<exprnode>);

	DirElemContent(
		const yy::location&,
		std::string elem_content);

	DirElemContent(
		const yy::location&,
		rchandle<CDataSection>);

	DirElemContent(
		const yy::location&,
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
  bool isStripped() const { return theIsStripped; }
  void setIsStripped(bool aIsStripped) const { theIsStripped = aIsStripped; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [100] CommonContent ::= ENTITY_REF |
                          CHAR_REF_LITERAL |
                          DOUBLE_LBRACE |
                          DOUBLE_RBRACE |
                          EnclosedExpr

********************************************************************************/
class CommonContent : public exprnode
{
protected:
	enum common_content_t type;
	std::string ref;
	rchandle<EnclosedExpr> expr_h;

public:
	CommonContent(
		const yy::location&,
		enum common_content_t,
		std::string ref);

	CommonContent(
		const yy::location&,
		rchandle<EnclosedExpr> expr_h);

	CommonContent(
		const yy::location&,
		enum common_content_t);

	~CommonContent();

public:
	enum common_content_t get_type() const { return type; }
	std::string get_ref() const { return ref; }
	rchandle<EnclosedExpr> get_expr() const { return expr_h; }

public:
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

  [105] CDataSection ::= CDATA_BEGIN  CHAR_LITERAL  CDATA_END 	ws:explicitXQ

********************************************************************************/
class CDataSection : public exprnode
{
protected:
	std::string cdata_content;

public:
	CDataSection(
		const yy::location&,
		std::string cdata_content);

	~CDataSection();

public:
	std::string get_cdata_content() const { return cdata_content; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

 [106] CDataSectionContents  (lexical rule)

********************************************************************************/


/*******************************************************************************

   [97] DirAttributeList ::= DirAttr | DirAttributeList  DirAttr

********************************************************************************/
class DirAttributeList : public parsenode
{
protected:
	std::vector<rchandle<DirAttr> > theAttributes;

public:
	DirAttributeList(const yy::location&);
	~DirAttributeList();

public:
	void push_back(rchandle<DirAttr> attr)
  {
    theAttributes.push_back(attr);
  }

	rchandle<DirAttr> operator[](int i)
  {
    return theAttributes[i];
  }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [97a] DirAttr ::= QNAME  EQUALS  DirAttributeValue 	 ws:explicitXQ

********************************************************************************/
class DirAttr : public parsenode
{
protected:
	rchandle<QName>             theName;
	rchandle<DirAttributeValue> theValue;
	
public:
	DirAttr(
        const yy::location&,
        rchandle<QName>,
        rchandle<DirAttributeValue>);
  
	~DirAttr();

public:
	rchandle<QName> get_name() const { return theName; }
	rchandle<DirAttributeValue> get_value() const { return theValue; }

public:
	void accept(parsenode_visitor&) const;
};


/******************************************************************************

  [98] DirAttributeValue ::= QUOTE QuoteAttrContentList QUOTE |
                             APOS AposAttrContentList APOS       ws:explicitXQ

*******************************************************************************/
class DirAttributeValue : public parsenode
{
protected:
	rchandle<QuoteAttrContentList> quot_attr_content_h;
	rchandle<AposAttrContentList> apos_attr_content_h;

public:
	DirAttributeValue(
		const yy::location&,
		rchandle<QuoteAttrContentList>);

	DirAttributeValue(
		const yy::location&,
		rchandle<AposAttrContentList>);

	~DirAttributeValue();

public:
	rchandle<QuoteAttrContentList> get_quot_attr_content() const
  { 
    return quot_attr_content_h;
  }

	rchandle<AposAttrContentList> get_apos_attr_content() const
  {
    return apos_attr_content_h;
  }

public:
	void accept(parsenode_visitor&) const;
};


/******************************************************************************

  [98a] QuoteAttrContentList ::= ESCAPE_QUOTE |
                                 QuoteAttrValueContent |
                                 QuoteAttrContentList  ESCAPE_QUOTE |
                                 QuoteAttrContentList  QuoteAttrValueContent

********************************************************************************/
class QuoteAttrContentList : public parsenode
{
protected:
	std::vector<rchandle<QuoteAttrValueContent> > quot_atval_content_hv;
	
public:
	QuoteAttrContentList(const yy::location&);
	~QuoteAttrContentList();

public:
	void push_back(rchandle<QuoteAttrValueContent> quot_atval_content_h)
  {
    quot_atval_content_hv.push_back(quot_atval_content_h);
  }

	rchandle<QuoteAttrValueContent> operator[](int i) const
  {
    return quot_atval_content_hv[i];
  }

public:
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

  [98b] AposAttrContentList ::= ESCAPE_APOS |
                                AposAttrValueContent |
                                AposAttrContentList  ESCAPE_APOS |
                                AposAttrContentList  AposAttrValueContent

********************************************************************************/
class AposAttrContentList : public parsenode
{
protected:
	std::vector<rchandle<AposAttrValueContent> > apos_atval_content_hv;
	
public:
	AposAttrContentList(const yy::location&);
	~AposAttrContentList();

public:
	void push_back(rchandle<AposAttrValueContent> apos_atval_content_h)
		{ apos_atval_content_hv.push_back(apos_atval_content_h); }
	rchandle<AposAttrValueContent> operator[](int i) const
		{ return apos_atval_content_hv[i]; }

public:
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

  [99] QuotAttrValueContent ::= QUOTE_ATTR_CONTENT | CommonContent

********************************************************************************/
class QuoteAttrValueContent : public parsenode
{
protected:
	std::string quot_atcontent;
	rchandle<CommonContent> common_content_h;

public:
	QuoteAttrValueContent(
		const yy::location&,
		std::string quot_atcontent);

	QuoteAttrValueContent(
		const yy::location&,
		rchandle<CommonContent>);

	~QuoteAttrValueContent();

public:
	std::string get_quot_atcontent() const { return quot_atcontent; }
	rchandle<CommonContent> get_common_content() const { return common_content_h; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [100] AposAttrValueContent ::= APOS_ATTR_CONTENT | CommonContent

********************************************************************************/
class AposAttrValueContent : public parsenode
{
protected:
	std::string apos_atcontent;
	rchandle<CommonContent> common_content_h;

public:
	AposAttrValueContent(
		const yy::location&,
		std::string apos_atcontent);

	AposAttrValueContent(
		const yy::location&,
		rchandle<CommonContent>);

	~AposAttrValueContent();

public:
	std::string get_apos_atcontent() const { return apos_atcontent; }
	rchandle<CommonContent> get_common_content() const { return common_content_h; }

public:
	void accept(parsenode_visitor&) const;

};



/*******************************************************************************

********************************************************************************/
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
		const yy::location&,
		std::string const& comment);

	~DirCommentConstructor();

public:
  std::string get_comment() const { return comment; }

public:
	void accept(parsenode_visitor&) const;

};



// [102] DirCommentContents
// ------------------------
/* lexical rule */


/*******************************************************************************

********************************************************************************/
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
		const yy::location&,
		std::string const& pi_target);

	DirPIConstructor(
		const yy::location&,
		std::string const& pi_target,
		std::string const& pi_content);

	~DirPIConstructor();

public:
	std::string get_pi_target() const { return pi_target; }
	std::string get_pi_content() const { return pi_content; }

public:
	void accept(parsenode_visitor&) const;

};



// [104] DirPIContents
// -------------------
/* lexical rule */



/*******************************************************************************

********************************************************************************/
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



// [110] CompDocConstructor
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
		const yy::location&,
		rchandle<exprnode>);

	~CompDocConstructor();

public:
	rchandle<exprnode> get_expr() const { return expr_h; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [111] CompElemConstructor ::= 
                          ELEMENT_QNAME_LBRACE RBRACE |
                          ELEMENT_QNAME_LBRACE ContentExp  RBRACE |
                          ELEMENT_LBRACE Expr RBRACE LBRACE RBRACE |
                          ELEMENT_LBRACE Expr RBRACE LBRACE ContentExpr RBRACE

  [112] ContentExpr := Expr

********************************************************************************/
class CompElemConstructor : public exprnode
{
protected:
	rchandle<exprnode> qname_expr_h;
	rchandle<exprnode> content_expr_h;

public:
	CompElemConstructor(
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~CompElemConstructor();

public:
	rchandle<exprnode> get_qname_expr() const { return qname_expr_h; }
	rchandle<exprnode> get_content_expr() const { return content_expr_h; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

 [113] CompAttrConstructor ::= ATTRIBUTE QNAME LBRACE RBRACE |
                               ATTRIBUTE QNAME LBRACE Expr RBRACE |
                               ATTRIBUTE LBRACE Expr RBRACE LBRACE RBRACE |
                               ATTRIBUTE LBRACE Expr RBRACE LBRACE Expr RBRACE

********************************************************************************/
class CompAttrConstructor : public exprnode
{
protected:
	rchandle<exprnode> qname_expr_h;
	rchandle<exprnode> val_expr_h;

public:
	CompAttrConstructor(
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~CompAttrConstructor();

public:
	rchandle<exprnode> get_qname_expr() const { return qname_expr_h; }
	rchandle<exprnode> get_val_expr() const { return val_expr_h; }

public:
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
		const yy::location&,
		rchandle<exprnode> text_expr_h);

	~CompTextConstructor();

public:
	rchandle<exprnode> get_text_expr() const { return text_expr_h; }

public:
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
		const yy::location&,
		rchandle<exprnode>);

	~CompCommentConstructor();

public:
	rchandle<exprnode> get_comment_expr() const { return comment_expr_h; }

public:
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
		const yy::location&,
		std::string target,
		rchandle<exprnode>);

	CompPIConstructor(
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~CompPIConstructor();

public:
	std::string get_target() const { return target; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }
	rchandle<exprnode> get_content_expr() const { return content_expr_h; }

public:
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
		const yy::location&,
		rchandle<AtomicType>,
		bool hook_b);

	~SingleType();

public:
	rchandle<AtomicType> get_atomic_type() const { return atomic_type_h; }
	bool get_hook_bit() const { return hook_b; }

public:
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
		const yy::location&,
		rchandle<SequenceType>);

	~TypeDeclaration();

public:
	rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

public:
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

  [119] SequenceType ::= ItemType OccurrenceIndicator? | "empty-sequence" "(" ")"

********************************************************************************/
class SequenceType : public parsenode
{
protected:
	rchandle<parsenode> itemtype_h;
	rchandle<OccurrenceIndicator> occur_h;

public:
	SequenceType(
		const yy::location&,
		rchandle<parsenode>,
		rchandle<OccurrenceIndicator>);

	~SequenceType();

public:
	rchandle<parsenode> get_itemtype() const { return itemtype_h; }
	rchandle<OccurrenceIndicator> get_occur() const { return occur_h; }
	bool get_void_bit() const { return itemtype_h==NULL; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [120] OccurrenceIndicator ::= HOOK | STAR | PLUS   gn:occurrence-indicatorsXQ

********************************************************************************/
class OccurrenceIndicator : public parsenode
{
protected:
	enum occurrence_t type;

public:
	OccurrenceIndicator(
		const yy::location&,
		enum occurrence_t);

	~OccurrenceIndicator();

public:
	enum occurrence_t get_type() const { return type; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [121] ItemType ::= AtomicType | KindTest | ITEM_TEST

********************************************************************************/
class ItemType : public parsenode
{
protected:
	bool item_test_b;

public:
	ItemType(
		const yy::location&,
		bool item_test_b);
		
	ItemType(const yy::location&);
		
	~ItemType();

public:
	bool get_item_test_bit() const { return item_test_b; }

public:
	virtual	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [122] AtomicType ::= QNAME

********************************************************************************/
class AtomicType : public parsenode
{
protected:
	rchandle<QName> qname_h;

public:
	AtomicType(
		const yy::location&,
		rchandle<QName>);
		
	~AtomicType();

public:
	rchandle<QName> get_qname() const { return qname_h; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [123] KindTest ::= DocumentTest |
                     ElementTest |
                     AttributeTest |
                     SchemaElementTest |
                     SchemaAttributeTest |
                     PITest |
                     CommentTest |
                     TextTest |
                     AnyKindTest

********************************************************************************/


/*******************************************************************************

  [124] AnyKindTest ::= NODE_LPAR  RPAR

********************************************************************************/
class AnyKindTest : public parsenode
{
public:
	AnyKindTest(const yy::location&);
	~AnyKindTest();

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [125] DocumentTest ::= DOCUMENT_NODE_LPAR  RPAR |
                         DOCUMENT_NODE_LPAR  ElementTest  RPAR |
                         DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR

********************************************************************************/
class DocumentTest : public parsenode
{
protected:
	rchandle<ElementTest> elem_test_h;
	rchandle<SchemaElementTest> schema_elem_test_h;

public:
	DocumentTest(const yy::location&);

	DocumentTest(
		const yy::location&,
		rchandle<ElementTest>);
	
	DocumentTest(
		const yy::location&,
		rchandle<SchemaElementTest>);

	~DocumentTest();

public:
	rchandle<ElementTest> get_elem_test() const
		{ return elem_test_h; }
	rchandle<SchemaElementTest> get_schema_elem_test() const
		{ return schema_elem_test_h; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [126] TextTest ::= TEXT_LPAR  RPAR 

********************************************************************************/
class TextTest : public parsenode
{
public:
	TextTest(const yy::location&);
	~TextTest();

public:
	void accept(parsenode_visitor&) const;
};


// [127] CommentTest
// -----------------
class CommentTest : public parsenode
/*______________________________________________________________________
|
|	::= COMMENT_LPAR  RPAR 
|_______________________________________________________________________*/
{
public:
	CommentTest(const yy::location&);
	~CommentTest();

public:
	void accept(parsenode_visitor&) const;

};
 

// [128] PITest
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
		const yy::location&,
		std::string target,
		std::string content);

	~PITest();

public:
	std::string get_target() const { return target; }
	std::string get_content() const { return content; }

public:
	void accept(parsenode_visitor&) const;
};


/******************************************************************************

  [129] AttributeTest ::= ATTRIBUTE_LPAR RPAR |
                          ATTRIBUTE_LPAR AttribNameOrWildcard RPAR |
                          ATTRIBUTE_LPAR AttribNameOrWildcard COMMA TypeName RPAR

********************************************************************************/
class AttributeTest : public parsenode
{
protected:
	rchandle<QName> theAttrName;
	rchandle<TypeName> theTypeName;

public:
	AttributeTest(
		const yy::location&,
		rchandle<QName>,
		rchandle<TypeName>);

	~AttributeTest();

public:
	rchandle<QName> get_attr_name() const    { return theAttrName; }
	rchandle<TypeName> get_type_name() const { return theTypeName; }
	bool is_wild() const                     { return theAttrName == NULL; }

public:
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
		const yy::location&,
		rchandle<QName>);

	~SchemaAttributeTest();

public:
	rchandle<QName> get_attr() const { return attr_h; }

public:
	void accept(parsenode_visitor&) const;

};


/*******************************************************************************

  [132] ElementNameOrWildcard ::= ElementName | STAR (inlined production)

  [133] ElementTest ::= ELEMENT_LPAR RPAR |
                        ELEMENT_LPAR ElemNameOrWildcard RPAR |
                        ELEMENT_LPAR ElemNameOrWildcard COMMA TypeName RPAR |
                        ELEMENT_LPAR ElemNameOrWildcard COMMA TypeName HOOK RPAR

  Note: theElementName will be NULL in the case of the 1st production or in
  case of wildcard (*) in the other productions. 
 
********************************************************************************/
class ElementTest : public parsenode
{
protected:
	rchandle<QName>    theElementName;
	rchandle<TypeName> theTypeName;
	bool               theNilledAllowed;

public:
	ElementTest(
		const yy::location& l,
		rchandle<QName> qn,
		rchandle<TypeName> tn,
    bool na = false);

	~ElementTest();

public:
	rchandle<QName> getElementName() const { return theElementName; }
	rchandle<TypeName> getTypeName() const { return theTypeName; }
	bool isWildcard() const                { return theElementName == NULL; }
	bool isNilledAllowed() const           { return theNilledAllowed; }

public:
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
		const yy::location&,
		rchandle<QName> _elem_h);

	~SchemaElementTest();

public:
	rchandle<QName> get_elem() const { return elem_h; }

public:
	void accept(parsenode_visitor&) const;

};



/* inlined productions */
/* ------------------- */
// [128] AttribNameOrWildcard ::= AttributeName | STAR
// [130] AttributeDeclaration ::= AttributeName
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
		const yy::location&,
		rchandle<QName>);

	TypeName(
		const yy::location&,
		rchandle<QName>,
		bool);

	~TypeName();

public:
	rchandle<QName> get_name() const { return qname_h; }
	bool get_optional_bit() const { return optional_b; }
	
public:
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
		const yy::location&,
		std::string const&);

	~StringLiteral();

public:
	std::string get_strval() const { return strval; }

public:
	void accept(parsenode_visitor&) const;

};



/*******************************************************************************
  lexical rules, see xquery.l

  [143] PITarget
  [144] VarName
  [145] ValidationMode
  [146] Digits
  [147] PredefinedEntityRef
  [148] CharRef
  [149] EscapeQuot
  [150] EscapeApos
  [151] ElementContentChar
  [152] QuotAttrContentChar
  [153] AposAttrContentChar
  [154] Comment
  [155] CommentContents

  [156] QName ::= QNAME

  The "qname" data member is either (a) the empty string, or (b) a single NCName,
  or (c) NCName1:NCName2. In cases (a) and (b), get_prefix() returns the empty
  string, and get_localname() returns "qname".

********************************************************************************/
class QName : public exprnode
{
protected:
	std::string qname;

public:
	QName(const yy::location&, const std::string& qname);

	~QName();

public:
	std::string get_qname() const { return qname; }
	std::string get_localname() const;
	std::string get_prefix() const;

public:
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
		const yy::location&,
		rchandle<QName>);

	~RevalidationDecl();

public:
	rchandle<QName> get_qname() const { return qname_h; }

public:
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
		const yy::location&,
		rchandle<exprnode>,
		rchandle<exprnode>);

	~InsertExpr();

public:
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
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
		const yy::location&,
		rchandle<exprnode>);

	~DeleteExpr();

public:
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
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
		const yy::location&,
		rchandle<exprnode> source_expr_h,
		rchandle<exprnode> target_expr_h);

	~ReplaceExpr();

public:
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
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
		const yy::location&,
		rchandle<exprnode> source_expr_h,
		rchandle<exprnode> target_expr_h);

	~RenameExpr();

public:
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
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
		const yy::location&,
		rchandle<VarNameList>,
		rchandle<exprnode> source_expr_h,
		rchandle<exprnode> target_expr_h);

	~TransformExpr();

public:
	rchandle<VarNameList> get_varname_list() const { return varname_list_h; }
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
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
	VarNameList(const yy::location&);
	~VarNameList();

public:
	void push_back(rchandle<VarBinding> varbinding_h)
		{ varbinding_hv.push_back(varbinding_h); }
	rchandle<VarBinding> operator[](int i) const
		{ return varbinding_hv[i]; }

public:
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
		const yy::location&,
		std::string varname,
		rchandle<exprnode>);

	~VarBinding();

public:
	std::string get_varname() const { return varname; }
	rchandle<exprnode> get_val() const { return val_h; }

public:
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
		const yy::location&,
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
	FTMatchOptionProximityList(const yy::location&);
	~FTMatchOptionProximityList();

public:
	void push_back(rchandle<FTMatchOptionProximity> opt_prox_h)
		{ opt_prox_hv.push_back(opt_prox_h); }
	rchandle<FTMatchOptionProximity> operator[](int i)
		{ return opt_prox_hv[i]; }

public:
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
		const yy::location&);

	FTMatchOptionProximity(
		rchandle<FTProximity>,
		const yy::location&);

	FTMatchOptionProximity(
		const yy::location&);

	~FTMatchOptionProximity();

public:
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
		const yy::location&,
		rchandle<FTOr>,
		rchandle<FTAnd>);

	~FTOr();

public:
	rchandle<FTOr> get_ftor() const { return ftor_h; }
	rchandle<FTAnd> get_ftand() const { return ftand_h; }

public:
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
		const yy::location&,
		rchandle<FTAnd>,
		rchandle<FTMildnot>);
	
	~FTAnd();

public:
	rchandle<FTAnd> get_ftand() const { return ftand_h; }
	rchandle<FTMildnot> get_ftmild_not() const { return ftmild_not_h; }

public:
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
		const yy::location&,
		rchandle<FTMildnot>,
		rchandle<FTUnaryNot>);

	~FTMildnot();

public:
	rchandle<FTMildnot> get_ftmild_not() const { return ftmild_not_h; }
	rchandle<FTUnaryNot> get_ftunary_not() const { return ftunary_not_h; }

public:
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
		const yy::location&,
		rchandle<FTWordsSelection>,
		bool not_b);

	~FTUnaryNot();

public:
	rchandle<FTWordsSelection> get_words_selection() const
		{ return words_selection_h; }
	bool get_not_bit() const
		{ return not_b; }

public:
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
		const yy::location&,
		rchandle<FTWords>,
		rchandle<FTTimes>,
		rchandle<FTSelection>);

	~FTWordsSelection();

public:
	rchandle<FTWords> get_words() const { return words_h; }
	rchandle<FTTimes> get_times() const { return times_h; }
	rchandle<FTSelection> get_selection() const { return selection_h; }

public:
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
		const yy::location&,
		rchandle<FTWordsValue>,
		rchandle<FTAnyallOption>);

	~FTWords();

public:
	rchandle<FTWordsValue> get_words_val() const
		{ return words_val_h; }
	rchandle<FTAnyallOption> get_any_all_option() const
		{ return any_all_option_h; }

public:
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
		const yy::location&,
		rchandle<StringLiteral>,
		rchandle<Expr>);

	~FTWordsValue();

public:
	rchandle<StringLiteral> get_lit() const { return lit_h; }
	rchandle<Expr> get_expr() const { return expr_h; }

public:
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
	FTProximity(const yy::location&);
	~FTProximity();

public:
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
	FTOrderedIndicator(const yy::location&);
	~FTOrderedIndicator();

public:
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
	FTMatchOption(const yy::location&);
	~FTMatchOption();

public:
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
		const yy::location&,
		enum ft_case_mode_t);

	~FTCaseOption();

public:
	enum ft_case_mode_t get_mode() const { return mode; }

public:
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
		const yy::location&,
		ft_diacritics_mode_t);

	~FTDiacriticsOption();

public:
	enum ft_diacritics_mode_t get_mode() const { return mode; }

public:
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
		const yy::location&,
		ft_stem_mode_t);

	~FTStemOption();

public:
	enum ft_stem_mode_t get_mode() const { return mode; }

public:
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
		const yy::location&,
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
	FTThesaurusList(const yy::location&);
	~FTThesaurusList();

public:
	void push_back(rchandle<FTThesaurusID> thesaurus_h)
		{ thesaurus_hv.push_back(thesaurus_h); }
	rchandle<FTThesaurusID> operator[](int i) const
		{ return thesaurus_hv[i]; }

public:
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
		const yy::location&,
		std::string thesaurus_name,
		std::string relationship_name,
		rchandle<FTRange> levels_h);
	
	~FTThesaurusID();

public:
	std::string get_thesaurus_name() const { return thesaurus_name; }
	std::string get_relationship_name() const { return relationship_name; }
	rchandle<FTRange> get_levels() const { return levels_h; }

public:
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
		const yy::location&,
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
	FTInclExclStringLiteralList(const yy::location&);
	~FTInclExclStringLiteralList();

public:
	void push_back(rchandle<FTInclExclStringLiteral> incl_excl_lit_h)
		{ incl_excl_lit_hv.push_back(incl_excl_lit_h); }
	rchandle<FTInclExclStringLiteral> operator[](int i) const
		{ return incl_excl_lit_hv[i]; }

public:

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
		const yy::location&,
		std::string at_str,
		rchandle<FTStringLiteralList>);

	~FTRefOrList();

	std::string get_at_str() const
		{ return at_str; }
	rchandle<FTStringLiteralList> get_stringlit_list() const
		{ return stringlit_list_h; }

public:
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
	FTStringLiteralList(const yy::location&);
	~FTStringLiteralList();

public:
	void push_back(std::string strlit) { strlit_v.push_back(strlit); }
	std::string operator[](int i) const { return strlit_v[i]; }

public:
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
		const yy::location&,
		rchandle<FTRefOrList>,
		intex_op_t);

	~FTInclExclStringLiteral();

public:
	rchandle<FTRefOrList> get_ref_or_list() const
		{ return ref_or_list_h; }
	intex_op_t get_mode() const
		{ return mode; }

public:
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
		const yy::location&,
		std::string lang);

	~FTLanguageOption();

public:
	std::string get_lang() const { return lang; }

public:
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
		const yy::location&,
		bool with_b);

	~FTWildcardOption();

public:
	bool get_with_bit() const { return with_b; }

public:
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
		const yy::location&,
		enum ft_content_mode_t);

	~FTContent();

public:
	enum ft_content_mode_t get_mode() const { return mode; }

public:
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
		const yy::location&,
		enum ft_anyall_option_t);

	~FTAnyallOption();

public:
	enum ft_anyall_option_t get_option() const { return option; }

public:
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
		const yy::location&,
		rchandle<UnionExpr> src_expr_h,
		rchandle<UnionExpr> dst_expr_h);

	~FTRange();

public:
	rchandle<UnionExpr> get_src_expr() const { return src_expr_h; }
	rchandle<UnionExpr> get_dst_expr() const { return dst_expr_h; }

public:
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
		const yy::location&,
		rchandle<FTRange>,
		rchandle<FTUnit>);

	~FTDistance();

public:
	rchandle<FTRange> get_dist() const { return dist_h; }
	rchandle<FTUnit> get_unit() const { return unit_h; }

public:
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
		const yy::location&,
		rchandle<UnionExpr> window_h,
		rchandle<FTUnit> unit_h);

	~FTWindow();

public:
	rchandle<UnionExpr> get_window() const { return window_h; }
	rchandle<FTUnit> get_unit() const { return unit_h; }

public:
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
		const yy::location&,
		rchandle<FTRange>);

	~FTTimes();

public:
	rchandle<FTRange> get_range() const { return range_h; }

public:
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
		const yy::location&,
		ft_scope_t);

	~FTScope();

public:
	enum ft_scope_t get_scope() const { return scope; }

public:
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
		const yy::location&,
		ft_unit_t);

	~FTUnit();

public:
	enum ft_unit_t get_unit() const { return unit; }

public:
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
		const yy::location&,
		enum ft_big_unit_t);

	~FTBigUnit();

public:
	enum ft_big_unit_t get_unit() const { return unit; }

public:
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
		const yy::location&,
		rchandle<UnionExpr>);

	~FTIgnoreOption();

public:
	rchandle<UnionExpr> get_union() const { return union_h; }

public:
	void accept(parsenode_visitor&) const;

};


}	/* namespace xqp */
#endif	/*  XQP_PARSENODES_H */
