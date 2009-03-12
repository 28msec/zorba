/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_PARSENODES_H
#define ZORBA_PARSENODES_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <cassert>

#include "compiler/parsetree/parsenode_base.h"

#include "store/api/item.h"

#include "zorbatypes/rchandle.h"
#include "zorbatypes/representations.h"
#include "zorbautils/strutil.h"

#include "context/static_context_consts.h"
#include "context/dynamic_context.h"

namespace zorba {


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
class FLWORClause;
class FLWORClauseList;
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
class MultiplicativeExpr;
class NameTest;
class NamespaceDecl;
class NodeComp;
class NumericLiteral;
class OccurrenceIndicator;
class OptionDecl;
class OrExpr;
class GroupByClause;
class GroupSpecList;
class GroupSpec;
class GroupCollationSpec;
class LetClauseList;
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
class UnaryExpr;
class UnionExpr;
class UnorderedExpr;
class VFO_DeclList;
class ValidateExpr;
class ValueComp;
class VarBinding;
class VarDecl;
class VarNameList;
class WhereClause;
class Wildcard;


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
		const QueryLoc&,
		std::string const& version,
		std::string const& encoding);


public:
	std::string get_version() const { return version; }
	std::string get_encoding() const { return encoding; }

public:
	void accept(parsenode_visitor&) const;

};


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
  rchandle<VersionDecl> version_decl_h;
public:
	Module(const QueryLoc& loc_, rchandle<VersionDecl> vd_)
    : parsenode (loc_), version_decl_h (vd_)
  {}
	rchandle<VersionDecl> get_version_decl() const { return version_decl_h; }
  void set_version_decl(rchandle<VersionDecl> vd) { version_decl_h = vd; }

public:
	void accept(parsenode_visitor&) const;

};


// [3] MainModule
// --------------
class MainModule : public Module
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
		const QueryLoc&,
		rchandle<QueryBody>,
		rchandle<Prolog>,
    rchandle<VersionDecl> = NULL);
	
public:
	rchandle<Prolog> get_prolog() const { return prolog_h; }
	rchandle<QueryBody> get_query_body() const { return query_body_h; }

  void set_prolog (rchandle<Prolog> prolog_) { prolog_h = prolog_; }

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
		const QueryLoc&,
		std::string const& prefix,
		std::string const& target_namespace);


public:
	std::string get_prefix() const { return prefix; }
	std::string get_target_namespace() const { return target_namespace; }

public:
	void accept(parsenode_visitor&) const;

};


// [4] LibraryModule
// -----------------
class LibraryModule : public Module
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
		const QueryLoc&,
		rchandle<ModuleDecl>,
		rchandle<Prolog>,
    rchandle<VersionDecl> = NULL);


public:
  rchandle<ModuleDecl> get_decl () const { return decl_h; }
	rchandle<Prolog> get_prolog() const { return prolog_h; }

public:
	void accept(parsenode_visitor&) const;

};


/******************************************************************************

  [6] Prolog ::= SIND_DeclList  VFO_DeclList

********************************************************************************/
class Prolog : public parsenode
{
protected:
	rchandle<SIND_DeclList> sind_list_h;
	rchandle<VFO_DeclList> vfo_list_h;

public:
	Prolog(
		const QueryLoc&,
		rchandle<SIND_DeclList>,
		rchandle<VFO_DeclList>);

public:
	rchandle<SIND_DeclList> get_sind_list() const { return sind_list_h; }
	rchandle<VFO_DeclList> get_vfo_list() const { return vfo_list_h; }

	void set_vfo_list(rchandle<VFO_DeclList> vfo_list_) { vfo_list_h = vfo_list_; }

public:
	void accept(parsenode_visitor&) const;
};


/******************************************************************************

  [6a] SIND_DeclList ::= SIND_Decl | SIND_DeclList  SEMI  SIND_Decl

********************************************************************************/
class SIND_DeclList : public parsenode
{
protected:
	std::vector<rchandle<parsenode> > sind_hv;

public:
	SIND_DeclList(const QueryLoc&);

public:
	void push_back(rchandle<parsenode> sind_h) { sind_hv.push_back(sind_h); }
	rchandle<parsenode> operator[](int k) const { return sind_hv[k]; }

public:
	void accept(parsenode_visitor&) const;
};


/******************************************************************************

  [6b] VFO_DeclList ::= VFO_Decl | VFO_DeclList  SEMI  VFO_Decl

  VFO_DeclList represents a list of prolog declarations that consists of all
  the variable, udf, and option declaration in the prolog. 

********************************************************************************/
class VFO_DeclList : public parsenode
{
protected:
	std::vector<rchandle<parsenode> > vfo_hv;

public:
	VFO_DeclList(const QueryLoc&);

public:
	void push_back(rchandle<parsenode> vfo_h) { vfo_hv.push_back(vfo_h); }
  void push_front(rchandle<parsenode> vfo_h) { vfo_hv.insert(vfo_hv.begin (), vfo_h); }
	rchandle<parsenode> operator[](int k) const { return vfo_hv[k]; }
  std::vector<rchandle<parsenode> >::iterator begin () { return vfo_hv.begin (); }
  std::vector<rchandle<parsenode> >::iterator end   () { return vfo_hv.end   (); }
  std::vector<rchandle<parsenode> >::const_iterator begin () const { return vfo_hv.begin (); }
  std::vector<rchandle<parsenode> >::const_iterator end   () const { return vfo_hv.end   (); }

public:
	void accept(parsenode_visitor&) const;

};


/******************************************************************************

  [6c] SIND_Decl ::= Setter |
                     Import |
                     NamespaceDecl |
                     DefaultNamespaceDecl

********************************************************************************/


/******************************************************************************

  [6d] VFO_Decl ::= VarDecl |
                    FunctionDecl |
                    OptionDecl

********************************************************************************/


/******************************************************************************

  [7] Setter ::= BoundarySpaceDecl |
                 DefaultCollationDecl |
                 BaseURIDecl |
                 ConstructionDecl |
                 OrderingModeDecl |
                 EmptyOrderDecl |
                 CopyNamespacesDecl

********************************************************************************/


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
		const QueryLoc&,
		std::string const& prefix,
		std::string const& uri);


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
	StaticContextConsts::boundary_space_mode_t mode;

public:
	BoundarySpaceDecl(
		const QueryLoc&,
		StaticContextConsts::boundary_space_mode_t);


public:
	StaticContextConsts::boundary_space_mode_t
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
	enum ParseConstants::default_namespace_mode_t mode;
	std::string default_namespace;

public:
	DefaultNamespaceDecl(
		const QueryLoc&,
		enum ParseConstants::default_namespace_mode_t mode,
		std::string const& default_namespace);


public:
	enum ParseConstants::default_namespace_mode_t get_mode() const { return mode; }
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
		const QueryLoc&,
		rchandle<QName> qname_h,
		std::string const& val);


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
		const QueryLoc&,
		rchandle<parsenode>);


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
	StaticContextConsts::ordering_mode_t mode;
		
public:
	OrderingModeDecl(
		const QueryLoc&,
		StaticContextConsts::ordering_mode_t);

	
public:
	StaticContextConsts::ordering_mode_t get_mode() const { return mode; }

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
	StaticContextConsts::order_empty_mode_t mode;

public:
	EmptyOrderDecl(
		const QueryLoc&,
		StaticContextConsts::order_empty_mode_t);

	
public:
	StaticContextConsts::order_empty_mode_t get_mode() const { return mode; }

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
	StaticContextConsts::preserve_mode_t preserve_mode;
	StaticContextConsts::inherit_mode_t inherit_mode;

public:
	CopyNamespacesDecl(
		const QueryLoc&,
		StaticContextConsts::preserve_mode_t preserve_mode,
		StaticContextConsts::inherit_mode_t  inherit_mode);


public:
	StaticContextConsts::preserve_mode_t get_preserve_mode() const
  { return preserve_mode; }
	StaticContextConsts::inherit_mode_t  get_inherit_mode() const
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
		const QueryLoc&,
		std::string const&  collation);


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
		const QueryLoc&,
		std::string const& base_uri);


public:
	std::string get_base_uri() const { return base_uri; }

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
		const QueryLoc&);


public:
	void push_back(std::string const& uri) { uri_v.push_back(uri); }
	std::string operator[](int i) const { return uri_v[i]; }
  int size () const { return uri_v.size (); }

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
		const QueryLoc&,
		rchandle<SchemaPrefix>,
		std::string const& uri,
		rchandle<URILiteralList>);


public:
	rchandle<SchemaPrefix> get_prefix() const { return prefix_h; }
	std::string get_uri() const { return uri; }
	rchandle<URILiteralList> get_at_list() const { return at_list_h; }

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
		const QueryLoc&,
		bool default_b);

	SchemaPrefix(
		const QueryLoc&,
		std::string const& prefix);


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
		const QueryLoc&,
		std::string const& uri,
		rchandle<URILiteralList>);
	ModuleImport(
		const QueryLoc&,
		std::string const& prefix,
		std::string const& uri,
		rchandle<URILiteralList>);

public:
	std::string get_prefix() const { return prefix; }
	std::string get_uri() const { return uri; }
	rchandle<URILiteralList> get_uri_list() const { return uri_list_h; }

public:
	void accept(parsenode_visitor&) const;

};


class VarDeclBase : public parsenode
{
protected:
	std::string varname;
	rchandle<TypeDeclaration> typedecl_h;

public:
	VarDeclBase(const QueryLoc& loc_, std::string varname_, rchandle<TypeDeclaration> td_)
    : parsenode (loc_), varname (varname_), typedecl_h (td_)
  {}

public:
	std::string get_varname() const { return varname; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
};

class VarDeclWithInit : public VarDeclBase {
protected:
	rchandle<exprnode> initexpr_h;

public:
	VarDeclWithInit(const QueryLoc& loc_, std::string varname_, rchandle<TypeDeclaration> td_, rchandle<exprnode> init_)
    : VarDeclBase (loc_, varname_, td_), initexpr_h (init_)
  {}

	rchandle<exprnode> get_initexpr() const { return initexpr_h; }
	rchandle<exprnode> get_valexpr() const { return get_initexpr (); }
};

class CtxItemDecl : public parsenode {
  rchandle<exprnode> expr;

public:
  bool ext;
  rchandle<ItemType> type;

  CtxItemDecl (const QueryLoc& loc_, rchandle<exprnode> expr_)
    : parsenode (loc_), expr (expr_)
  {}

  rchandle<exprnode> get_expr () const { return expr; }
  bool is_external () const { return ext; }
  rchandle<ItemType> get_type () const { return type; }

public:
	void accept(parsenode_visitor&) const;

};

class IndexField : public parsenode {
  rchandle<exprnode> expr;
  rchandle<TypeDeclaration> type;

public:
  std::string coll;

public:
  IndexField (const QueryLoc& loc_, rchandle<exprnode> expr_, rchandle<TypeDeclaration> type_)
    : parsenode (loc_), expr (expr_), type (type_)
  {}
  rchandle<exprnode> get_expr () const { return expr; }
  rchandle<TypeDeclaration> get_type () const { return type; }

public:
	void accept(parsenode_visitor&) const;
  
};

class IndexFieldList : public parsenode {
public:
  std::vector<rchandle<IndexField> > fields;

public:
  IndexFieldList (const QueryLoc& loc_)
    : parsenode (loc_)
  {}

public:
	void accept(parsenode_visitor&) const;
  
};

class IndexDecl : public parsenode {
protected:
  std::string uri;
  rchandle<exprnode> on_expr;

public:
  std::string method;
  rchandle<IndexFieldList> fields;
  bool create;
  bool uniq;

public:
  bool is_decl_only () const { return ! create; }
  bool is_uniq () const { return uniq; }

  rchandle<exprnode> get_expr () { return on_expr; }
  std::string get_uri () { return uri; }

  IndexDecl (const QueryLoc& loc_, std::string uri_, rchandle<exprnode> expr_, std::string method_, rchandle<IndexFieldList> fields_)
    : parsenode (loc_), uri (uri_), on_expr (expr_), method (method_), fields (fields_),
      create (false), uniq (false)
  {}

public:
	void accept(parsenode_visitor&) const;

};

class IndexStatement : public exprnode {
  std::string uri;
  bool create;  //< create or drop?

public:
  IndexStatement (const QueryLoc& loc_, std::string uri_, bool create_)
    : exprnode (loc_), uri (uri_), create (create_)
  {}
  std::string get_uri () const { return uri; }
  bool is_create () const { return create; }


public:
	void accept(parsenode_visitor&) const;

};

// [24] VarDecl
// ------------
class VarDecl : public VarDeclWithInit
/*______________________________________________________________________
|
|	::= DECLARE_VARIABLE_DOLLAR  VARNAME  GETS  ExprSingle
|			|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
|			|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
|			|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
|_______________________________________________________________________*/
{
protected:
  bool ext;
public:
	VarDecl(const QueryLoc&,
          std::string varname,
          rchandle<TypeDeclaration>,
          rchandle<exprnode>,
          bool ext_ = false);

public:
	bool is_extern() const { return ext; }

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
	StaticContextConsts::construction_mode_t mode;

public:
	ConstructionDecl(
		const QueryLoc&,
		StaticContextConsts::construction_mode_t);


public:
	StaticContextConsts::construction_mode_t get_mode() const { return mode; }

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
  ParseConstants::function_type_t type;
	rchandle<QName> name_h;
	rchandle<ParamList> paramlist_h;
	rchandle<exprnode> body_h;
	rchandle<SequenceType> return_type_h;
	bool extern_b;

public:
	FunctionDecl(
		const QueryLoc&,
		rchandle<QName>,
		rchandle<ParamList>,
		rchandle<SequenceType>,
		rchandle<exprnode>,
		ParseConstants::function_type_t type);


public:
	rchandle<QName> get_name() const { return name_h; }
	rchandle<ParamList> get_paramlist() const { return paramlist_h; }
	int get_param_count() const;
	rchandle<exprnode> get_body() const { return body_h; }
	rchandle<SequenceType> get_return_type() const { return return_type_h; }
  ParseConstants::function_type_t get_type() const { return type; }

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
	ParamList(const QueryLoc&);

public:
	void push_back(rchandle<Param> param_h) { param_hv.push_back(param_h); }
	rchandle<Param> operator[](int i) const { return param_hv[i]; }
  std::vector<rchandle<Param> >::const_iterator begin () const { return param_hv.begin (); }
  std::vector<rchandle<Param> >::const_iterator end () const { return param_hv.end (); }
  std::vector<rchandle<Param> >::size_type size () const { return param_hv.size (); }

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
		const QueryLoc&,
		std::string name,
		rchandle<TypeDeclaration>);


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
		const QueryLoc&,
		rchandle<exprnode>);


public:
	rchandle<exprnode> get_expr() const { return expr_h; }
	
public:
	void accept(parsenode_visitor&) const;

};

class BlockBody : public exprnode
{
protected:
  std::vector<rchandle <exprnode> > statements;

public:
  BlockBody (const QueryLoc& loc_) : exprnode (loc_) {}
  void add (rchandle<exprnode> statement) {
    statements.push_back (statement);
  }
  const rchandle<exprnode> &operator[](int k) const { return statements [k]; }
  rchandle<exprnode> &operator[](int k) { return statements [k]; }

  int size () const { return statements.size (); }

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
		const QueryLoc&,
		rchandle<exprnode>);

	QueryBody();


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
	Expr(const QueryLoc&);

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


class FLWORClause : public parsenode {
public:
  FLWORClause (const QueryLoc& loc_) : parsenode (loc_) {}
};

// [33] FLWORExpr
// --------------
class FLWORExpr : public exprnode
/*______________________________________________________________________
|
|	::= FLWORClauseList  RETURN  ExprSingle
|			|	FLWORClauseList  WhereClause  RETURN  ExprSingle
|			|	FLWORClauseList  OrderByClause  RETURN  ExprSingle
|			|	FLWORClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<FLWORClauseList> clauses;
	rchandle<exprnode> return_val_h;
  bool general;  //< needs to be translated into gflwor_expr?
  bool non_10;  //< non-conformant to XQuery 1.0 spec?

  void compute_general ();

  QueryLoc return_location;

public:
	FLWORExpr(const QueryLoc& loc_, rchandle<FLWORClauseList> clauses_, rchandle<exprnode> ret_, const QueryLoc& return_loc_, bool force_general = false);

public:
	rchandle<FLWORClauseList> get_clause_list() const { return clauses; }
	rchandle<exprnode> get_return_val() const { return return_val_h; }
  GroupByClause *get_groupby() const;
  OrderByClause *get_orderby() const;
  WhereClause *get_where() const;

  bool is_general () const { return general; }
  bool is_non_10 () const { return non_10; }
  const QueryLoc& get_return_location() const { return return_location; }

public:
	void accept(parsenode_visitor&) const;

};

class ReturnExpr: public exprnode
{
  protected:
    rchandle<exprnode> return_val_h;

  public:
    ReturnExpr(const QueryLoc& loc_, rchandle<exprnode> ret_): exprnode(loc_), return_val_h(ret_){}
    rchandle<exprnode> get_return_val() const { return return_val_h; }
    void accept(parsenode_visitor&) const { /* do nothing... */ }
};

// [33a] FLWORClauseList
// ----------------------
class FLWORClauseList : public parsenode
/*______________________________________________________________________
|
|	::= ForOrLetClause
|			|	ForOrLetClause  FLWORClauseList
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<FLWORClause> > forlet_hv;

public:
	FLWORClauseList(const QueryLoc&);

public:
	void push_back(rchandle<FLWORClause> forlet_h) { forlet_hv.push_back(forlet_h); }
	rchandle<FLWORClause> operator[](int i) const { return forlet_hv[i]; }
  size_t size () const { return forlet_hv.size (); }

public:
	void accept(parsenode_visitor&) const;

};

class FLWORInitialClause : public FLWORClause {
public:
  FLWORInitialClause (const QueryLoc& loc_) : FLWORClause (loc_) {}
};

// [33b] ForOrLetClause
/*______________________________________________________________________
|	::= ForClause | LetClause
|_______________________________________________________________________*/

class ForOrLetClause : public FLWORInitialClause {
public:
  ForOrLetClause (const QueryLoc& loc_) : FLWORInitialClause (loc_) {}
  typedef enum { for_clause, let_clause } for_or_let_t;
  virtual for_or_let_t for_or_let () const = 0;
  virtual int get_decl_count () const = 0;
};

class WindowVars : public parsenode {
  rchandle<PositionalVar> posvar;
  std::string curr, prev, next;

public:
  WindowVars (const QueryLoc& loc_, rchandle<PositionalVar> posvar_, std::string curr_, std::string prev_, std::string next_)
    : parsenode (loc_), posvar (posvar_), curr (curr_), prev (prev_), next (next_)
  {}
  rchandle<PositionalVar> get_posvar () const { return posvar; }
  std::string get_curr () const { return curr; }
  std::string get_prev () const { return prev; }
  std::string get_next () const { return next; }

  void set_curr (std::string curr_) { curr = curr_; }
  void set_posvar (rchandle<PositionalVar> posvar_) { posvar = posvar_; }

public:
	void accept(parsenode_visitor&) const;
};

class FLWORWinCond : public parsenode {
  rchandle<WindowVars> winvars;
  rchandle<exprnode> val;

  bool isStart;
  bool isOnly;  // only when isStart == false

public:
  FLWORWinCond (const QueryLoc& loc_, rchandle<WindowVars> winvars_, rchandle<exprnode> val_, bool isStart_, bool isOnly_ = false)
    : parsenode (loc_), winvars (winvars_), val (val_), isStart (isStart_), isOnly (isOnly_)
  {}
  rchandle<WindowVars> get_winvars () const { return winvars; }
  rchandle<exprnode> get_val () const { return val; }
  bool is_start () const { return isStart; }
  bool is_only () const { return isOnly; }

public:
	void accept(parsenode_visitor&) const;
};

class WindowVarDecl : public VarDeclWithInit {
public:
  WindowVarDecl (const QueryLoc& loc_, std::string varname_, rchandle<TypeDeclaration> td_, rchandle<exprnode> init_)
    : VarDeclWithInit (loc_, varname_, td_, init_)
  {}

public:
	void accept(parsenode_visitor&) const;
};

class WindowClause : public FLWORInitialClause {
public:
  typedef enum { tumbling_window, sliding_window } win_clause_t;

private:
  rchandle<WindowVarDecl> var;
  win_clause_t type;
  rchandle<FLWORWinCond> conditions [2];

public:
  WindowClause (const QueryLoc& loc_, win_clause_t type_, rchandle<WindowVarDecl> var_, rchandle<FLWORWinCond> start_, rchandle<FLWORWinCond> end_)
    : FLWORInitialClause (loc_), var (var_), type (type_)
  {
    conditions [0] = start_;
    conditions [1] = end_;
  }

  win_clause_t get_wintype () const { return type; }
  rchandle<WindowVarDecl> get_var () const { return var; }
  rchandle<FLWORWinCond> operator[] (unsigned i) const
  { assert (i <= 2); return conditions [i]; }

public:
	void accept(parsenode_visitor&) const;
};

// [34b] VarInDecl
// ---------------
class VarInDecl : public VarDeclWithInit
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
	rchandle<PositionalVar> posvar_h;
	rchandle<FTScoreVar> ftscorevar_h;
	rchandle<exprnode> valexpr_h;
	
public:
	VarInDecl(
		const QueryLoc&,
		std::string varname,
		rchandle<TypeDeclaration>,
		rchandle<PositionalVar>,
		rchandle<FTScoreVar>,
		rchandle<exprnode>);


public:
	rchandle<PositionalVar> get_posvar() const { return posvar_h; }
	rchandle<FTScoreVar> get_ftscorevar() const { return ftscorevar_h; }

public:
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
	VarInDeclList(const QueryLoc&);

public:
	void push_back(rchandle<VarInDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }
	rchandle<VarInDecl> operator[](int i) const { return vardecl_hv[i]; }
	size_t size () const { return vardecl_hv.size ();}

public:
	void accept(parsenode_visitor&) const;

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
  bool outer;

public:
	ForClause(const QueryLoc&, rchandle<VarInDeclList>, bool outer = false);


public:
	rchandle<VarInDeclList> get_vardecl_list() const { return vardecl_list_h; }

public:
	void accept(parsenode_visitor&) const;

public:
  for_or_let_t for_or_let () const { return for_clause; }
  int get_decl_count () const;
  bool is_outer () const { return outer; }
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
		const QueryLoc&,
		std::string const& varname);


public:
	std::string get_varname() const { return varname; }

public:
	void accept(parsenode_visitor&) const;

};


// [36b] VarGetsDecl
// ------------------
class VarGetsDecl : public VarDeclWithInit
/*______________________________________________________________________
|
|	::= VARNAME  GETS  ExprSingle
|			|	VARNAME  TypeDeclaration  GETS  ExprSingle
|	(ft extensions)
|			| VARNAME  FTScoreVar  GETS  ExprSingle
|			| VARNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
|_______________________________________________________________________*/
{
public:
  enum var_kind {
    let_var, eval_var
  };

protected:
	rchandle<FTScoreVar> ftscorevar_h;
  enum var_kind kind;

public:
	VarGetsDecl(const QueryLoc& loc_,
              std::string varname_,
              rchandle<TypeDeclaration> typedecl_h_,
              rchandle<FTScoreVar> ftscorevar_h_,
              rchandle<exprnode> valexpr_h_,
              enum var_kind kind_ = let_var)
    : VarDeclWithInit (loc_, varname_, typedecl_h_, valexpr_h_),
      ftscorevar_h(ftscorevar_h_), kind (kind_)
  {}

	rchandle<FTScoreVar> get_ftscorevar() const { return ftscorevar_h; }
  enum var_kind get_kind () const { return kind; }
  void set_kind (enum var_kind kind_) { kind = kind_; }
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
	VarGetsDeclList(const QueryLoc&);

public:
	void push_back(rchandle<VarGetsDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }
	rchandle<VarGetsDecl> operator[](int i) const { return vardecl_hv[i]; }

public:
	void accept(parsenode_visitor&) const;

public:
  size_t size () const { return vardecl_hv.size (); }
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
		const QueryLoc&,
		rchandle<VarGetsDeclList>);

public:
	rchandle<VarGetsDeclList> get_vardecl_list() const { return vardecl_list_h; }

public:
	void accept(parsenode_visitor&) const;

public:
  for_or_let_t for_or_let () const { return let_clause; }
  int get_decl_count () const;
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
		const QueryLoc&,
		std::string varname);

public:
	std::string get_varname() const { return varname; }

public:
	void accept(parsenode_visitor&) const;

};


// [37] WhereClause
// ----------------
class WhereClause : public FLWORClause
/*______________________________________________________________________
|
|	::= WHERE  ExprSingle
|_______________________________________________________________________*/
{
protected:
	rchandle<exprnode> predicate_h;

public:
	WhereClause(
		const QueryLoc&,
		rchandle<exprnode>);

public:
	rchandle<exprnode> get_predicate() const { return predicate_h; }

public:
	void accept(parsenode_visitor&) const;

};


class CountClause : public FLWORClause
{
  std::string varname;

public:
  CountClause (const QueryLoc &loc_, std::string varname_)
    : FLWORClause (loc_), varname (varname_)
  {}
  std::string get_varname () const { return varname; }

public:
	void accept(parsenode_visitor&) const;
};

class GroupByClause : public FLWORClause
{
protected:
  FLWORExpr*              flwor_h;
  rchandle<GroupSpecList> spec_list_h;
	rchandle<LetClauseList> let_h;
	rchandle<WhereClause> where_h;

public:
  GroupByClause(
    const QueryLoc&,
    rchandle<GroupSpecList>,
    rchandle<LetClauseList>,
    rchandle<WhereClause>);

public:
  void set_flwor(FLWORExpr* a) { flwor_h = a; }
  FLWORExpr*     get_flwor() const { return flwor_h; }
  GroupSpecList* get_spec_list() const { return &*spec_list_h; }
  LetClauseList* get_let() const { return &*let_h; }
  WhereClause* get_where() const { return &*where_h; }

public:
  void accept(parsenode_visitor&) const;
};

class GroupSpecList : public parsenode
{
protected:
  std::vector<rchandle<GroupSpec> > spec_hv;
 
public:
  GroupSpecList(const QueryLoc&);

public:
	void push_back(rchandle<GroupSpec> spec_h) { spec_hv.push_back(spec_h); }
	GroupSpec* operator[](int i) const { return &*spec_hv[i]; }
  size_t size () const { return spec_hv.size (); }

public:
	void accept(parsenode_visitor&) const;
};

class GroupSpec : public parsenode
{
protected:
  std::string            var_name_h;
  rchandle<GroupCollationSpec> group_coll_spec_h;

public:
  GroupSpec(
    const QueryLoc&,
    std::string,
    rchandle<GroupCollationSpec>);

public:
  std::string get_var_name() const  { return var_name_h; }
  rchandle<GroupCollationSpec> group_coll_spec() const { return group_coll_spec_h; }

public:
  void accept(parsenode_visitor&) const;
};

class GroupCollationSpec : public parsenode
{
protected:
	std::string uri;

public:
	GroupCollationSpec(
		const QueryLoc&,
		std::string const& uri);

public:
	std::string get_uri() const { return uri; }

public:
	void accept(parsenode_visitor&) const;

};

class LetClauseList : public parsenode
{
protected:
	std::vector<rchandle<LetClause> > let_hv;

public:
  LetClauseList(const QueryLoc&);

public:
	void push_back(rchandle<LetClause> let_h) { let_hv.push_back(let_h); }
	rchandle<LetClause> operator[](int i) const { return let_hv[i]; }
  int size () const { return let_hv.size (); }

public:
	void accept(parsenode_visitor&) const;

};

// [38] OrderByClause
// ------------------
class OrderByClause : public FLWORClause
/*______________________________________________________________________
|
|	::= ORDER_BY  OrderSpecList
|			|	STABLE_ORDER_BY  OrderSpecList
|_______________________________________________________________________*/
{
protected:
	rchandle<OrderSpecList> spec_list_h;
	bool stable_b;
  const FLWORExpr *flwor;
		
public:
	OrderByClause(
		const QueryLoc&,
		rchandle<OrderSpecList>,
		bool stable_b = false);

public:
	rchandle<OrderSpecList> get_spec_list() const { return spec_list_h; }
	bool get_stable_bit() const { return stable_b; }

  const FLWORExpr *get_flwor () const { return flwor; }
  void set_flwor (const FLWORExpr *flwor_) { flwor = flwor_; }

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
	OrderSpecList(const QueryLoc&);

public:
	void push_back(rchandle<OrderSpec> spec_h) { spec_hv.push_back(spec_h); }
	rchandle<OrderSpec> operator[](int i) const { return spec_hv[i]; }
  size_t size () const { return spec_hv.size (); }

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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<OrderModifier>);

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
		const QueryLoc&,
		rchandle<OrderDirSpec>,
		rchandle<OrderEmptySpec>,
		rchandle<OrderCollationSpec>);

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
  ParseConstants::dir_spec_t dir_spec;

public:
	OrderDirSpec(
		const QueryLoc&,
		ParseConstants::dir_spec_t dir_spec);
	
public:
  ParseConstants::dir_spec_t get_dir_spec() const { return dir_spec; }

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
	StaticContextConsts::order_empty_mode_t empty_order_spec;

public:
	OrderEmptySpec(
		const QueryLoc&,
		StaticContextConsts::order_empty_mode_t empty_order_spec);

public:
	StaticContextConsts::order_empty_mode_t get_empty_order_spec() const
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
		const QueryLoc&,
		std::string const& uri);

public:
	std::string get_uri() const { return uri; }

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
		const QueryLoc&,
		std::string name,
		rchandle<exprnode>);

	QVarInDecl(
		const QueryLoc&,
		std::string name,
		rchandle<TypeDeclaration>,
		rchandle<exprnode>);


public:
	std::string get_name() const { return name; }
	rchandle<TypeDeclaration> get_typedecl() const { return typedecl_h; }
	rchandle<exprnode> get_val() const { return val_h; }

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
	QVarInDeclList(const QueryLoc&);

public:
	void push_back(rchandle<QVarInDecl> decl_h) { qvar_decl_hv.push_back(decl_h); }
	rchandle<QVarInDecl> operator[](int i) const { return qvar_decl_hv[i]; }
	int size () const { return qvar_decl_hv.size ();}

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
  ParseConstants::quantification_mode_t qmode;
	rchandle<QVarInDeclList> decl_list_h;
	rchandle<exprnode> expr_h;

public:
	QuantifiedExpr(
		const QueryLoc&,
		ParseConstants::quantification_mode_t qmode,
		rchandle<QVarInDeclList>,
		rchandle<exprnode>);

public:
  ParseConstants::quantification_mode_t get_qmode() const { return qmode; }
	rchandle<QVarInDeclList> get_decl_list() const { return decl_list_h; }
	rchandle<exprnode> get_expr() const { return expr_h; }

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
		const QueryLoc&,
		std::string varname,
		rchandle<SequenceType>,
		rchandle<exprnode>);
		
	CaseClause(
		const QueryLoc&,
		rchandle<SequenceType>,
		rchandle<exprnode>);

public:
	std::string get_varname() const { return varname; }
	rchandle<SequenceType> get_type() const { return type_h; }
	rchandle<exprnode> get_val() const { return val_h; }

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
	CaseClauseList(const QueryLoc&);

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
	uint32_t size () const
  { return clause_hv.size (); }

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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<CaseClauseList>,
		rchandle<exprnode>);

	TypeswitchExpr(
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<CaseClauseList>,
		std::string default_varname,
		rchandle<exprnode>);


public:
	rchandle<exprnode> get_switch_expr() const { return switch_expr_h; }
	rchandle<CaseClauseList> get_clause_list() const { return clause_list_h; }
	std::string get_default_varname() const { return default_varname; }
	rchandle<exprnode> get_default_clause() const { return default_clause_h; }

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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<exprnode>,
		rchandle<exprnode>);

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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<ValueComp>,
		rchandle<exprnode>,
		rchandle<exprnode>);

	ComparisonExpr(
		const QueryLoc&,
		rchandle<GeneralComp>,
		rchandle<exprnode>,
		rchandle<exprnode>);

	ComparisonExpr(
		const QueryLoc&,
		rchandle<NodeComp>,
		rchandle<exprnode>,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<FTSelection>,
		rchandle<FTIgnoreOption>);


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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<exprnode>);


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
  ParseConstants::add_op_t add_op;
	rchandle<exprnode> add_expr_h;
	rchandle<exprnode> mult_expr_h;

public:
	AdditiveExpr(
		const QueryLoc&,
		ParseConstants::add_op_t add_op,
		rchandle<exprnode>,
		rchandle<exprnode>);


public:
  ParseConstants::add_op_t get_add_op() const { return add_op; }
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
  ParseConstants::mult_op_t mult_op;
	rchandle<exprnode> mult_expr_h;
	rchandle<exprnode> union_expr_h;

public:
	MultiplicativeExpr(
		const QueryLoc&,
		ParseConstants::mult_op_t,
		rchandle<exprnode>,
		rchandle<exprnode>);


public:
	rchandle<exprnode> get_mult_expr() const { return mult_expr_h; }
	rchandle<exprnode> get_union_expr() const { return union_expr_h; }
  ParseConstants::mult_op_t get_mult_op() const { return mult_op; }

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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<exprnode>);


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
	enum ParseConstants::intex_op_t intex_op;
	rchandle<exprnode> intex_expr_h;
	rchandle<exprnode> instof_expr_h;

public:
	IntersectExceptExpr(
		const QueryLoc&,
		ParseConstants::intex_op_t,
		rchandle<exprnode>,
		rchandle<exprnode>);


public:
	rchandle<exprnode> get_intex_expr() const { return intex_expr_h; }
	enum ParseConstants::intex_op_t get_intex_op() const { return intex_op; }
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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<SequenceType>);


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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<SequenceType>);


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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<SingleType>);


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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<SingleType>);
	

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
		const QueryLoc&,
		rchandle<SignList>,
		rchandle<exprnode>);


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
		const QueryLoc&,
		bool _sign);


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
	enum ParseConstants::gencomp_t type;

public:
	GeneralComp(
		const QueryLoc&,
		enum ParseConstants::gencomp_t);

	GeneralComp();


public:
	enum ParseConstants::gencomp_t get_type() const { return type; }
	
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
	enum ParseConstants::valcomp_t type;

public:
	ValueComp(
		const QueryLoc&,
		enum ParseConstants::valcomp_t);

	ValueComp();


public:
	enum ParseConstants::valcomp_t get_type() const { return type; }
	
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
	enum ParseConstants::nodecomp_t type;

public:
	NodeComp(
		const QueryLoc&,
		enum ParseConstants::nodecomp_t);

	NodeComp();


public:
	enum ParseConstants::nodecomp_t get_type() const { return type; }
	
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
	enum ParseConstants::validation_mode_t valmode;
	rchandle<exprnode> expr_h;
  rchandle<QName> type_name;

public:
	ValidateExpr(
		const QueryLoc&,
    std::string const& _valmode,
		rchandle<exprnode>);

  ValidateExpr(
    const QueryLoc&,
    rchandle<QName> _valmode,
    rchandle<exprnode>);


public:
	rchandle<exprnode> get_expr() const { return expr_h; }
  rchandle<QName> get_type_name() const { return type_name; }
	enum ParseConstants::validation_mode_t get_valmode() const { return valmode; }

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
		const QueryLoc&,
		rchandle<PragmaList>,
		rchandle<exprnode>);


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
	PragmaList(const QueryLoc&);

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
		const QueryLoc&,
		rchandle<QName>,
		std::string pragma_lit);


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
	enum ParseConstants::pathtype_t type;
	rchandle<exprnode> relpath_expr_h;

public:
	PathExpr(
		const QueryLoc&,
		enum ParseConstants::pathtype_t type,
		rchandle<exprnode>);


public:
	enum ParseConstants::pathtype_t get_type() const { return type; }
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
  enum ParseConstants::steptype_t step_type;
  rchandle<exprnode> step_expr_h;
  rchandle<exprnode> relpath_expr_h;  

public:
	RelativePathExpr(
		const QueryLoc&,
		ParseConstants::steptype_t,
		rchandle<exprnode>,
		rchandle<exprnode>);

public:
  enum ParseConstants::steptype_t get_step_type() const { return step_type; }	
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
		const QueryLoc&,
		rchandle<ForwardStep>,
		rchandle<PredicateList>);

	AxisStep(
		const QueryLoc&,
		rchandle<ReverseStep>,
		rchandle<PredicateList>);


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
		const QueryLoc&,
		rchandle<ForwardAxis>,
		rchandle<parsenode> node_test_h);

	ForwardStep(
		const QueryLoc&,
		rchandle<AbbrevForwardStep>);


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
	enum ParseConstants::forward_axis_t axis;

public:
	ForwardAxis(
		const QueryLoc&,
		enum ParseConstants::forward_axis_t);


public:
	enum ParseConstants::forward_axis_t get_axis() const { return axis; }

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
		const QueryLoc&,
		rchandle<parsenode>,
		bool attr_b);
		
	AbbrevForwardStep(
		const QueryLoc&,
		rchandle<parsenode>);
		

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
		const QueryLoc&,
		rchandle<ReverseAxis>,
		rchandle<parsenode>);

	ReverseStep(
		const QueryLoc&,
		rchandle<ReverseAxis>);


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
	enum ParseConstants::reverse_axis_t axis;

public:
	ReverseAxis(
		const QueryLoc&,
		enum ParseConstants::reverse_axis_t);


public:
	enum ParseConstants::reverse_axis_t get_axis() const { return axis; }

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
	NameTest(const QueryLoc& l, rchandle<QName> n);

	NameTest(const QueryLoc& l, rchandle<Wildcard> w);


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
	enum ParseConstants::wildcard_t theKind;
	xqp_string      thePrefix;
  xqp_string      theLocalName;
	
public:
	Wildcard(
		const QueryLoc& loc_,
    const xqp_string& prefix,
    const xqp_string& lname,
		enum ParseConstants::wildcard_t type);


public:
	enum ParseConstants::wildcard_t getKind() const        { return theKind; }
	const xqp_string& getPrefix() const    { return thePrefix; }
	const xqp_string& getLocalName() const { return theLocalName; }

public:
	void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [81] FilterExpr ::= PrimaryExpr  PredicateList?

********************************************************************************/
class FilterExpr : public exprnode
{
protected:
  rchandle<exprnode>      primary_h;
  rchandle<PredicateList> pred_list_h;
  bool                    theIsPathStep;

public:
	FilterExpr(
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<PredicateList>);


public:
	rchandle<exprnode> get_primary() const { return primary_h; }
	rchandle<PredicateList> get_pred_list() const { return pred_list_h; }

  bool isPathStep() const { return theIsPathStep; }
  void setIsPathStep()       { theIsPathStep = true; }

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
	PredicateList(const QueryLoc&);

public:
	void push_back(rchandle<exprnode> pred_h) { pred_hv.push_back(pred_h); }
	rchandle<exprnode> operator[](int i) { return pred_hv[i]; }
  int size () const { return pred_hv.size (); }

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
  enum ParseConstants::numeric_type_t type;

  class ValueBase {
  public:
    virtual ~ValueBase () {}
    virtual std::string toString () const = 0;
  };
  template<typename T> class Value : public ValueBase {
  public:
    T data;
    Value (const T &x) : data (x) {}
    std::string toString () const { return to_string (data); }
  };
  ValueBase *theValue;

protected:
	NumericLiteral(const QueryLoc& loc_, ParseConstants::numeric_type_t type_, ValueBase *val)
    : exprnode (loc_), type (type_), theValue (val) {}

public:
  ~NumericLiteral () { delete theValue; }
  template<typename T> static NumericLiteral *new_literal (const QueryLoc& loc_, ParseConstants::numeric_type_t type_, const T &x)
  { return new NumericLiteral (loc_, type_, new Value<T> (x)); }
  enum ParseConstants::numeric_type_t get_type() const { return type; }
  std::string toString () const { return theValue->toString (); }
  template<typename T> T get () const { return static_cast<Value<T> *> (theValue)->data; }

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
		const QueryLoc&,
		std::string varname);


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
		const QueryLoc&,
		rchandle<exprnode>);


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
protected:
  bool placeholder;
  
public:
  ContextItemExpr(const QueryLoc&, bool _placeholder = false);
  bool is_placeholder() { return placeholder; };

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
		const QueryLoc&,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<QName>,
		rchandle<ArgList>);


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
	ArgList(const QueryLoc&);

public:
	void push_back(rchandle<exprnode> arg_h) { arg_hv.push_back(arg_h); }
	rchandle<exprnode> operator[](int i) const { return arg_hv[i]; }
  int size () const { return arg_hv.size (); }

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
	rchandle<QName> elem_name_h, end_name_h;
	rchandle<DirAttributeList> attr_list_h;
	rchandle<DirElemContentList> dir_content_list_h;

public:
	DirElemConstructor(
		const QueryLoc&,
		rchandle<QName>,
		rchandle<QName>,
		rchandle<DirAttributeList>,
		rchandle<DirElemContentList>);


public:
	rchandle<QName> get_elem_name() const { return elem_name_h; }
	rchandle<QName> get_end_name() const { return end_name_h; }
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
	DirElemContentList(const QueryLoc&);

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
		const QueryLoc&,
		rchandle<exprnode>);

	DirElemContent(
		const QueryLoc&,
		std::string elem_content);

	DirElemContent(
		const QueryLoc&,
		rchandle<CDataSection>);

	DirElemContent(
		const QueryLoc&,
		rchandle<CommonContent>);


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
	enum ParseConstants::common_content_t type;
	std::string ref;
	rchandle<EnclosedExpr> expr_h;

public:
	CommonContent(
		const QueryLoc&,
		ParseConstants::common_content_t,
		std::string ref);

	CommonContent(
		const QueryLoc&,
		rchandle<EnclosedExpr> expr_h);

	CommonContent(
		const QueryLoc&,
		enum ParseConstants::common_content_t);


public:
	enum ParseConstants::common_content_t get_type() const { return type; }
	const std::string& get_ref() const { return ref; }
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
		const QueryLoc&,
		std::string cdata_content);


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
	DirAttributeList(const QueryLoc&);

public:
	void push_back(rchandle<DirAttr> attr)
  {
    theAttributes.push_back(attr);
  }

	rchandle<DirAttr> operator[](int i)
  {
    return theAttributes[i];
  }
  const DirAttr *operator[] (int i) const {
    return theAttributes[i];
  }
  int size () const { return theAttributes.size (); }

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
        const QueryLoc&,
        rchandle<QName>,
        rchandle<DirAttributeValue>);


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
		const QueryLoc&,
		rchandle<QuoteAttrContentList>);

	DirAttributeValue(
		const QueryLoc&,
		rchandle<AposAttrContentList>);


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
	QuoteAttrContentList(const QueryLoc&);

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
	AposAttrContentList(const QueryLoc&);

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
		const QueryLoc&,
		std::string quot_atcontent);

	QuoteAttrValueContent(
		const QueryLoc&,
		rchandle<CommonContent>);


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
		const QueryLoc&,
		std::string apos_atcontent);

	AposAttrValueContent(
		const QueryLoc&,
		rchandle<CommonContent>);


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
		const QueryLoc&,
		std::string const& comment);


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
		const QueryLoc&,
		std::string const& pi_target);

	DirPIConstructor(
		const QueryLoc&,
		std::string const& pi_target,
		std::string const& pi_content);


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
		const QueryLoc&,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<exprnode> text_expr_h);


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
		const QueryLoc&,
		rchandle<exprnode>);


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
		const QueryLoc&,
		std::string target,
		rchandle<exprnode>);

	CompPIConstructor(
		const QueryLoc&,
		rchandle<exprnode>,
		rchandle<exprnode>);


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
		const QueryLoc&,
		rchandle<AtomicType>,
		bool hook_b);


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
		const QueryLoc&,
		rchandle<SequenceType>);


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
		const QueryLoc&,
		rchandle<parsenode>,
		rchandle<OccurrenceIndicator>);


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
	enum ParseConstants::occurrence_t type;

public:
	OccurrenceIndicator(
		const QueryLoc&,
		enum ParseConstants::occurrence_t);


public:
	enum ParseConstants::occurrence_t get_type() const { return type; }

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
		const QueryLoc&,
		bool item_test_b);
		
	ItemType(const QueryLoc&);
		

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
		const QueryLoc&,
		rchandle<QName>);
		

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
	AnyKindTest(const QueryLoc&);

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
	DocumentTest(const QueryLoc&);

	DocumentTest(
		const QueryLoc&,
		rchandle<ElementTest>);
	
	DocumentTest(
		const QueryLoc&,
		rchandle<SchemaElementTest>);


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
	TextTest(const QueryLoc&);

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
	CommentTest(const QueryLoc&);

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

public:
	PITest(
		const QueryLoc&,
		std::string target);


public:
	std::string get_target() const { return target; }

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
		const QueryLoc&,
		rchandle<QName>,
		rchandle<TypeName>);


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
		const QueryLoc&,
		rchandle<QName>);


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
		const QueryLoc& l,
		rchandle<QName> qn,
		rchandle<TypeName> tn,
    bool na);


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
		const QueryLoc&,
		rchandle<QName> _elem_h);


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
		const QueryLoc&,
		rchandle<QName>);

	TypeName(
		const QueryLoc&,
		rchandle<QName>,
		bool);


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
		const QueryLoc&,
		std::string const&);


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
	QName(const QueryLoc&, const std::string& qname);


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
		const QueryLoc&,
		rchandle<QName>);


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
|	::= INSERT_NODE  ExprSingle  INTO  ExprSingle
|			|	INSERT_NODE  ExprSingle  AS  FIRST_INTO  ExprSingle
|			|	INSERT_NODE  ExprSingle  AS  LAST_INTO  ExprSingle
|			| INSERT_NODE  ExprSingle  AFTER  ExprSingle
|			| INSERT_NODE  ExprSingle  BEFORE  ExprSingle
|	    | INSERT_NODES  ExprSingle  INTO  ExprSingle
|			|	INSERT_NODES  ExprSingle  AS  FIRST_INTO  ExprSingle
|			|	INSERT_NODES  ExprSingle  AS  LAST_INTO  ExprSingle
|			| INSERT_NODES  ExprSingle  AFTER  ExprSingle
|			| INSERT_NODES  ExprSingle  BEFORE  ExprSingle
|_______________________________________________________________________*/
{
protected:
  store::UpdateConsts::InsertType theInsertType;
	rchandle<exprnode> theSourceExpr;
	rchandle<exprnode> theTargetExpr;

public:
	InsertExpr(
		const QueryLoc&,
    store::UpdateConsts::InsertType,
		rchandle<exprnode> aSourceExpr,
		rchandle<exprnode> aTargetExpr);

public:
	rchandle<exprnode> getSourceExpr() const { return theSourceExpr; }
	rchandle<exprnode> getTargetExpr() const { return theTargetExpr; }
  store::UpdateConsts::InsertType getType() const { return theInsertType; }

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
	rchandle<exprnode> theTargetExpr;

public:
	DeleteExpr(
		const QueryLoc&,
		rchandle<exprnode>);

public:
	rchandle<exprnode>       getTargetExpr() const { return theTargetExpr; }

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
  store::UpdateConsts::ReplaceType theReplaceType;
	rchandle<exprnode> theTargetExpr;
	rchandle<exprnode> theReplaceExpr;

public:
	ReplaceExpr(
		const QueryLoc&,
    store::UpdateConsts::ReplaceType aReplaceType,
		rchandle<exprnode> aTargetExpr,
		rchandle<exprnode> aReplaceExpr);


public:
  store::UpdateConsts::ReplaceType getType() const { return theReplaceType; }
	rchandle<exprnode>        getTargetExpr() const  { return theTargetExpr; }
	rchandle<exprnode>        getReplaceExpr() const  { return theReplaceExpr; }

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
	rchandle<exprnode> theTargetExpr;
	rchandle<exprnode> theNameExpr;

public:
	RenameExpr(
		const QueryLoc&,
		rchandle<exprnode> aTargetExpr,
		rchandle<exprnode> aName);


public:
	rchandle<exprnode> getTargetExpr() const { return theTargetExpr; }
	rchandle<exprnode> getNameExpr() const { return theNameExpr; }

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
		const QueryLoc&,
		rchandle<VarNameList>,
		rchandle<exprnode> source_expr_h,
		rchandle<exprnode> target_expr_h);


public:
	rchandle<VarNameList> get_varname_list() const { return varname_list_h; }
	rchandle<exprnode> get_source_expr() const { return source_expr_h; }
	rchandle<exprnode> get_target_expr() const { return target_expr_h; }

public:
	void accept(parsenode_visitor&) const;

};



// [249a] VarNameList
// ------------------
class VarNameList : public exprnode
/*______________________________________________________________________
|
|	::= VarBinding |	VarNameList  COMMA_DOLLAR  VarBinding
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<VarBinding> > varbinding_hv;
	
public:
	VarNameList(const QueryLoc&);

public:
	void push_back(rchandle<VarBinding> varbinding_h)
  { varbinding_hv.push_back(varbinding_h); }
	rchandle<VarBinding> operator[](int i) const
  { return varbinding_hv[i]; }
  size_t size () const { return varbinding_hv.size (); }

public:
	void accept(parsenode_visitor&) const;

};



// [249b] VarBinding
// -----------------
class VarBinding : public exprnode
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
		const QueryLoc&,
		std::string varname,
		rchandle<exprnode>);


public:
	const std::string& get_varname() const { return varname; }
	rchandle<exprnode> get_val() const { return val_h; }

public:
	void accept(parsenode_visitor&) const;

};




/*_______________________________________________________________________
 *                                                                       *
 *  Try-Catch productions                                                *
 *  []                                                                   *
 *                                                                       *
 *_______________________________________________________________________*/
class CatchExpr : public exprnode
/*_______________________________________________________________________________
|                                                                                *
| ::= CATCH_LPAR NameTest (COMMA DOLLAR VARNAME)? RPAR LBRACE ExprSingle RBRACE  *
|________________________________________________________________________________*/
{
protected:
  rchandle<NameTest> theNameTest;
  std::string theVarErrorCode;
  std::string theVarErrorDescr;
  std::string theVarErrorVal;
  rchandle<parsenode> theExprSingle;

public:
  CatchExpr(
    const QueryLoc& aQueryLoc,
    rchandle<NameTest> aNameTest,
    rchandle<parsenode> aExprSingle)
  : exprnode(aQueryLoc),
    theNameTest(aNameTest),
    theVarErrorCode(""),
    theVarErrorDescr(""),
    theVarErrorVal(""),
    theExprSingle(aExprSingle)
  {}

  CatchExpr(
    const QueryLoc& aQueryLoc,
    rchandle<NameTest> aNameTest,
    const std::string& aVarErrorCode,
    rchandle<parsenode> aExprSingle)
  :
    exprnode(aQueryLoc),
    theNameTest(aNameTest),
    theVarErrorCode(aVarErrorCode),
    theVarErrorDescr(""),
    theVarErrorVal(""),
    theExprSingle(aExprSingle)
  {}

  CatchExpr(
    const QueryLoc& aQueryLoc,
    rchandle<NameTest> aNameTest,
    const std::string& aVarErrorCode,
    const std::string& aVarErrorDescr,
    rchandle<parsenode> aExprSingle)
  :
    exprnode(aQueryLoc),
    theNameTest(aNameTest),
    theVarErrorCode(aVarErrorCode),
    theVarErrorDescr(aVarErrorDescr),
    theVarErrorVal(""),
    theExprSingle(aExprSingle)
  {}

  CatchExpr(
    const QueryLoc& aQueryLoc,
    rchandle<NameTest> aNameTest,
    const std::string& aVarErrorCode,
    const std::string& aVarErrorDescr,
    const std::string& aVarErrorVal,
    rchandle<parsenode> aExprSingle)
  :
    exprnode(aQueryLoc),
    theNameTest(aNameTest),
    theVarErrorCode(aVarErrorCode),
    theVarErrorDescr(aVarErrorDescr),
    theVarErrorVal(aVarErrorVal),
    theExprSingle(aExprSingle)
  {}

public:
  rchandle<NameTest> getNameTest() const { return theNameTest; }
  const std::string& getVarErrorCode() const { return theVarErrorCode; }
  const std::string& getVarErrorDescr() const { return theVarErrorDescr; }
  const std::string& getVarErrorVal() const { return theVarErrorVal; }
  rchandle<parsenode> getExprSingle() const { return theExprSingle; }

public:
  void accept(parsenode_visitor&) const;
};


class CatchListExpr : public exprnode
/*______________________________________________________________________
|                                                                       *
| ::=  CatchExpr*                                                       *
|_______________________________________________________________________*/
{
protected:
  std::vector<rchandle<CatchExpr> > theCatchExprs;

public:
  CatchListExpr(const QueryLoc& aQueryLoc)
  : exprnode(aQueryLoc)
  {}

public:
	void push_back(rchandle<CatchExpr> aCatchExpr)
		{ theCatchExprs.push_back(aCatchExpr); }

	rchandle<CatchExpr> operator[](int i) const
		{ return theCatchExprs[i]; }

public:
  void accept(parsenode_visitor&) const;
};

class TryExpr : public exprnode
/*______________________________________________________________________
|                                                                       *
| ::= TRY LBRACE ExprSingle RBRACE CatchListExpr                        *
|_______________________________________________________________________*/
{
protected:
  rchandle<exprnode> theExprSingle;
  rchandle<exprnode> theCatchListExpr;

public:
  TryExpr(
    const QueryLoc& aQueryLoc,
    rchandle<exprnode> aExprSingle,
    rchandle<exprnode> aCatchListExpr)
  : exprnode(aQueryLoc),
    theExprSingle(aExprSingle),
    theCatchListExpr(aCatchListExpr)
  {}

public:
  rchandle<exprnode> getExprSingle() const { return theExprSingle; }
  rchandle<CatchListExpr> getCatchListExpr() const { return theCatchListExpr.cast<CatchListExpr> (); }

public:
  void accept(parsenode_visitor&) const;
};

// Eval productions

class EvalExpr : public exprnode {
protected:
  rchandle <VarGetsDeclList> vgdl;
  rchandle <exprnode> expr_h;

public:
  EvalExpr (const QueryLoc& loc_, rchandle <VarGetsDeclList> vgdl_, rchandle <parsenode> expr_)
    : exprnode (loc_), vgdl (vgdl_), expr_h (expr_.dyn_cast<exprnode> ())
  {}
  
  rchandle<VarGetsDeclList> get_vars () const { return vgdl; }
  rchandle<exprnode> get_expr () const { return expr_h; }

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
		const QueryLoc&,
		rchandle<FTOr>,
		rchandle<FTMatchOptionProximityList>,
		rchandle<RangeExpr>);


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
	FTMatchOptionProximityList(const QueryLoc&);

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
		const QueryLoc&);

	FTMatchOptionProximity(
		rchandle<FTProximity>,
		const QueryLoc&);

	FTMatchOptionProximity(
		const QueryLoc&);


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
		const QueryLoc&,
		rchandle<FTOr>,
		rchandle<FTAnd>);


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
		const QueryLoc&,
		rchandle<FTAnd>,
		rchandle<FTMildnot>);
	

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
		const QueryLoc&,
		rchandle<FTMildnot>,
		rchandle<FTUnaryNot>);


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
		const QueryLoc&,
		rchandle<FTWordsSelection>,
		bool not_b);


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
		const QueryLoc&,
		rchandle<FTWords>,
		rchandle<FTTimes>,
		rchandle<FTSelection>);


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
		const QueryLoc&,
		rchandle<FTWordsValue>,
		rchandle<FTAnyallOption>);


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
	rchandle<exprnode> expr_h;

public:
	FTWordsValue(
		const QueryLoc&,
		rchandle<StringLiteral>,
		rchandle<exprnode>);


public:
	rchandle<StringLiteral> get_lit() const { return lit_h; }
	rchandle<exprnode> get_expr() const { return expr_h; }

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
	FTProximity(const QueryLoc&);

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
	FTOrderedIndicator(const QueryLoc&);

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
	FTMatchOption(const QueryLoc&);

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
  ParseConstants::ft_case_mode_t mode;

public:
	FTCaseOption(
		const QueryLoc&,
		enum ParseConstants::ft_case_mode_t);


public:
	enum ParseConstants::ft_case_mode_t get_mode() const { return mode; }

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
  ParseConstants::ft_diacritics_mode_t mode;

public:
	FTDiacriticsOption(
		const QueryLoc&,
		ParseConstants::ft_diacritics_mode_t);


public:
	enum ParseConstants::ft_diacritics_mode_t get_mode() const { return mode; }

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
protected:
  ParseConstants::ft_stem_mode_t mode;

public:
	FTStemOption(
		const QueryLoc&,
		ParseConstants::ft_stem_mode_t);


public:
	enum ParseConstants::ft_stem_mode_t get_mode() const { return mode; }

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
		const QueryLoc&,
		rchandle<FTThesaurusID>,
		rchandle<FTThesaurusList>,
		bool default_b,
		bool without_b);


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
	FTThesaurusList(const QueryLoc&);

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
		const QueryLoc&,
		std::string thesaurus_name,
		std::string relationship_name,
		rchandle<FTRange> levels_h);
	

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
  ParseConstants::stop_words_mode_t mode;

public:
	FTStopwordOption(
		const QueryLoc&,
		rchandle<FTRefOrList>,
		rchandle<FTInclExclStringLiteralList>,
	  ParseConstants::stop_words_mode_t);


public:
	rchandle<FTRefOrList> get_refor_list() const
		{ return refor_list_h; }
	rchandle<FTInclExclStringLiteralList> get_incl_excl_list() const
		{ return incl_excl_list_h; }
  ParseConstants::stop_words_mode_t get_mode() const
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
	FTInclExclStringLiteralList(const QueryLoc&);

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
		const QueryLoc&,
		std::string at_str,
		rchandle<FTStringLiteralList>);


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
	FTStringLiteralList(const QueryLoc&);

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
  ParseConstants::intex_op_t mode;

public:
	FTInclExclStringLiteral(
		const QueryLoc&,
		rchandle<FTRefOrList>,
		ParseConstants::intex_op_t);


public:
	rchandle<FTRefOrList> get_ref_or_list() const
		{ return ref_or_list_h; }
  ParseConstants::intex_op_t get_mode() const
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
		const QueryLoc&,
		std::string lang);


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
		const QueryLoc&,
		bool with_b);


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
  ParseConstants::ft_content_mode_t mode;

public:
	FTContent(
		const QueryLoc&,
		enum ParseConstants::ft_content_mode_t);


public:
	enum ParseConstants::ft_content_mode_t get_mode() const { return mode; }

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
	enum ParseConstants::ft_anyall_option_t option;

public:
	FTAnyallOption(
		const QueryLoc&,
		enum ParseConstants::ft_anyall_option_t);


public:
	enum ParseConstants::ft_anyall_option_t get_option() const { return option; }

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
  ft_range_mode_t mode;
	rchandle<exprnode> src_expr_h;
	rchandle<exprnode> dst_expr_h;

public:
	FTRange(
		const QueryLoc&,
    ft_range_mode_t,
		rchandle<exprnode> src_expr_h,
		rchandle<exprnode> dst_expr_h = NULL);


public:
	rchandle<UnionExpr> get_src_expr() const { return src_expr_h.cast<UnionExpr> (); }
	rchandle<UnionExpr> get_dst_expr() const { return dst_expr_h.cast<UnionExpr> (); }

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
		const QueryLoc&,
		rchandle<FTRange>,
		rchandle<FTUnit>);


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
		const QueryLoc&,
		rchandle<UnionExpr> window_h,
		rchandle<FTUnit> unit_h);


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
		const QueryLoc&,
		rchandle<FTRange>);


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
  ParseConstants::ft_scope_t scope;

public:
	FTScope(
		const QueryLoc&,
		ParseConstants::ft_scope_t);


public:
	enum ParseConstants::ft_scope_t get_scope() const { return scope; }

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
  ParseConstants::ft_unit_t unit;

public:
	FTUnit(
		const QueryLoc&,
		ParseConstants::ft_unit_t);


public:
	enum ParseConstants::ft_unit_t get_unit() const { return unit; }

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
	enum ParseConstants::ft_big_unit_t unit;

public:
	FTBigUnit(
		const QueryLoc&,
		enum ParseConstants::ft_big_unit_t);


public:
	enum ParseConstants::ft_big_unit_t get_unit() const { return unit; }

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
		const QueryLoc&,
		rchandle<UnionExpr>);


public:
	rchandle<UnionExpr> get_union() const { return union_h; }

public:
	void accept(parsenode_visitor&) const;

};

class ExitExpr : public exprnode {
	rchandle<exprnode> value_h;
public:
  ExitExpr (const QueryLoc& loc_, rchandle<exprnode> val_)
    : exprnode (loc_), value_h (val_)
  {}
  rchandle<exprnode> get_value () { return value_h; }
	void accept(parsenode_visitor&) const;
};

class AssignExpr : public exprnode {
  std::string varname;
	rchandle<exprnode> value_h;

public:
  AssignExpr (const QueryLoc& loc_, std::string varname_, rchandle<exprnode> val_)
    : exprnode (loc_), varname (varname_), value_h (val_)
  {}
	const std::string& get_varname() const { return varname; }
  rchandle<exprnode> get_value () const { return value_h; }
	void accept(parsenode_visitor&) const;
};

class FlowCtlStatement : public exprnode {
public:
  enum action { BREAK, CONTINUE };

private:
  enum action action;

public:
  FlowCtlStatement (const QueryLoc& loc_, enum action action_)
    : exprnode (loc_), action (action_)
  {}
  enum action get_action () const { return action; }
	void accept(parsenode_visitor&) const;
};

class WhileExpr : public exprnode {
  rchandle<exprnode> cond;
  rchandle<BlockBody> body;

public:
  WhileExpr (const QueryLoc& loc_, rchandle<exprnode> cond_, rchandle<BlockBody> body_)
    : exprnode (loc_), cond (cond_), body (body_)
  {}
  rchandle<exprnode> get_cond () { return cond; }
  rchandle<BlockBody> get_body () { return body; }

	void accept(parsenode_visitor&) const;
};

}	/* namespace zorba */
#endif	/*  ZORBA_PARSENODES_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
