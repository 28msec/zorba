/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: normalize_visitor.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "normalize_visitor.h"
#include "indent.h"

#include "functions/library.h"
#include "parser/parsenodes.h"
#include "util/tracer.h"
#include "store/api/item.h"
#include "runtime/zorba.h"


#include <iostream>
#include <string>

using namespace std;
namespace xqp {

static uint32_t depth = 0;


normalize_visitor::normalize_visitor()
{
	zorp = zorba::getZorbaForCurrentThread();
	dctx_p = zorp->get_dynamic_context();
// 	dmgr_h = zorp->get_data_manager();
}



/*..........................................
 :  begin visit                            :
 :.........................................*/

bool normalize_visitor::begin_visit(const parsenode& v)
{
cout<< indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const exprnode& v)
{
cout<< indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const AbbrevForwardStep& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const AnyKindTest& v)
{
cout << indent[++depth] << TRACE << endl;
	// no action needed here
	return true;
}

bool normalize_visitor::begin_visit(const AposAttrContentList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const AposAttrValueContent& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ArgList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const AtomicType& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const AttributeTest& v)
{
cout << indent[++depth] << TRACE << endl;
	// no action needed here
	return true;
}

bool normalize_visitor::begin_visit(const BaseURIDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	zorp->get_static_context()->set_baseuri(v.get_base_uri());
	return false;
}

bool normalize_visitor::begin_visit(const BoundarySpaceDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	zorp->get_static_context()->set_boundary_space_mode(v.get_boundary_space_mode());
	return false;
}

bool normalize_visitor::begin_visit(const CaseClause& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CaseClauseList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const CommentTest& v)
{
cout << indent[++depth] << TRACE << endl;
	// no action needed here
	return true;
}

bool normalize_visitor::begin_visit(const ConstructionDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	zorp->get_static_context()->set_construction_mode(v.get_mode());
	return false;
}

bool normalize_visitor::begin_visit(const CopyNamespacesDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(DefaultCollationDecl const& v)
{
cout << indent[++depth] << TRACE << endl;
	string uri = v.get_collation();
	zorp->get_static_context()->set_default_collation(uri);
	return false;
}

bool normalize_visitor::begin_visit(
	DefaultNamespaceDecl const& v)
{
// TODO adapt to new store
// cout << indent[++depth] << TRACE << endl;
// 	switch (v.get_mode()) {
// 	case ns_element_default: {
// 		namespace_node* ns_p = new dom_namespace_node("#elem#",v.get_default_namespace());
// 		zorp->get_dynamic_context()->set_default_element_type_namespace(*ns_p);
// 		break;
// 	}
// 	case ns_function_default: {
// 		namespace_node* ns_p = new dom_namespace_node("#func#",v.get_default_namespace());
// 		zorp->get_static_context()->set_default_function_namespace(ns_p);
// 		break;
// 	}}
	return false;
}

bool normalize_visitor::begin_visit(const DirAttr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const DirAttributeList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const DirAttributeValue& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const DirElemContentList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const DocumentTest& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::doc_test);

	rchandle<ElementTest> e_h = v.get_elem_test();
	if (e_h!=NULL) {
		rchandle<QName> elem_h = e_h->get_elem();
		if (elem_h!=NULL) {
			m_h->set_name(new qname_expr(v.get_location(),
																		elem_h->get_qname()));
		}
		rchandle<TypeName> type_h = e_h->get_type();
		if (type_h!=NULL) {
			m_h->set_typename(new qname_expr(v.get_location(),
																				type_h->get_name()->get_qname()));
		}
		bool optional_b =  e_h->get_optional_bit();
		if (optional_b) {
			// XXX missing member variable for this
		}
	}
	nodestack.push(&*m_h);
	return true;
}

bool normalize_visitor::begin_visit(const ElementTest& v)
{
	cout << indent[++depth] << TRACE << endl;
	// no action needed here
	return true;
}

bool normalize_visitor::begin_visit(const EmptyOrderDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	zorp->get_static_context()->set_order_empty_mode(v.get_mode());
	return true;
}

bool normalize_visitor::begin_visit(const ForClause& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const ForLetClause& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ForLetClauseList& v)
{
cout << indent[++depth] << TRACE << endl;
// 	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const ForwardAxis& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ForwardStep& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FunctionDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const GeneralComp& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ItemType& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const LetClause& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const LibraryModule& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const MainModule & v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const Module& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ModuleDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ModuleImport& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const NameTest& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const NamespaceDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	// add namespace def to context
	return false;
}

bool normalize_visitor::begin_visit(const NodeComp& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OccurrenceIndicator& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OptionDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrderByClause& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrderCollationSpec& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrderDirSpec& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrderEmptySpec& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrderModifier& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrderSpec& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrderSpecList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const OrderingModeDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	zorp->get_dynamic_context()->set_ordering_mode(v.get_mode());
	return false;
}

bool normalize_visitor::begin_visit(const PITest& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::pi_test);

	string target = v.get_target();
	m_h->set_name(new qname_expr(v.get_location(), target));
	nodestack.push(&*m_h);
	return true;
}

bool normalize_visitor::begin_visit(const Param& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ParamList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const PositionalVar& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const Pragma& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const PragmaList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const PredicateList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const Prolog& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const QVarInDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const QVarInDeclList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const QuoteAttrValueContent& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const QuoteAttrContentList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const ReverseAxis& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ReverseStep& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const SIND_DeclList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const SchemaAttributeTest& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::xs_attr_test);

	rchandle<QName> attr_h = v.get_attr();
	if (attr_h!=NULL) {
		m_h->set_name(new qname_expr(v.get_location(),
																	attr_h->get_qname()));
	}
	nodestack.push(&*m_h);
	return true;
}

bool normalize_visitor::begin_visit(const SchemaElementTest& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::xs_elem_test);

	rchandle<QName> elem_h = v.get_elem();
	if (elem_h!=NULL) {
		m_h->set_name(new qname_expr(v.get_location(),
																	elem_h->get_qname()));
	}
	nodestack.push(&*m_h);
	return true;
}

bool normalize_visitor::begin_visit(const SchemaImport& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const SchemaPrefix& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const SequenceType& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const SignList& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const SingleType& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const TextTest& v)
{
cout << indent[++depth] << TRACE << endl;
	// no action needed here
	return true;
}

bool normalize_visitor::begin_visit(const TypeDeclaration& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const TypeName& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const URILiteralList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const ValueComp& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const VarDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const VarGetsDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const VarGetsDeclList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const VarInDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const VarInDeclList& v)
{
cout << indent[++depth] << TRACE << endl;
// 	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const VersionDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const VFO_DeclList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const WhereClause& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const Wildcard& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}



/* expressions */
bool normalize_visitor::begin_visit(const AdditiveExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<fo_expr> fo_h = new fo_expr(v.get_location());
	switch (v.get_add_op()) {
	case op_plus:
		fo_h->set_func(dctx_p->get_function(library::op_add_key));
		break;
	case op_minus:
		fo_h->set_func(dctx_p->get_function(library::op_subtract_key));
		break;
	}
	nodestack.push(&*fo_h);
	return true;
}

bool normalize_visitor::begin_visit(const AndExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const AxisStep& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<axis_step_expr> aexpr_h =
		new axis_step_expr(v.get_location());
	nodestack.push(&*aexpr_h);
	return true;
}

bool normalize_visitor::begin_visit(const CDataSection& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CastExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CastableExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CommonContent& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ComparisonExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<fo_expr> fo_h = new fo_expr(v.get_location());

	if (v.get_gencomp()!=NULL) {
		switch (v.get_gencomp()->get_type()) {
		case op_eq:
			fo_h->set_func(dctx_p->get_function(library::op_eq_key));
			break;
		case op_ne:
			fo_h->set_func(dctx_p->get_function(library::op_ne_key));
			break;
		case op_lt:
			fo_h->set_func(dctx_p->get_function(library::op_lt_key));
			break;
		case op_le:
			fo_h->set_func(dctx_p->get_function(library::op_le_key));
			break;
		case op_gt:
			fo_h->set_func(dctx_p->get_function(library::op_gt_key));
			break;
		case op_ge:
			fo_h->set_func(dctx_p->get_function(library::op_ge_key));
			break;
		}
	}
	else if (v.get_valcomp()!=NULL) {
		switch (v.get_valcomp()->get_type()) {
		case op_val_eq:
			fo_h->set_func(dctx_p->get_function(library::op_val_eq_key));
			break;
		case op_val_ne:
			fo_h->set_func(dctx_p->get_function(library::op_val_ne_key));
			break;
		case op_val_lt:
			fo_h->set_func(dctx_p->get_function(library::op_val_lt_key));
			break;
		case op_val_le:
			fo_h->set_func(dctx_p->get_function(library::op_val_le_key));
			break;
		case op_val_gt:
			fo_h->set_func(dctx_p->get_function(library::op_val_gt_key));
			break;
		case op_val_ge:
			fo_h->set_func(dctx_p->get_function(library::op_val_ge_key));
			break;
		}
	}
	else if (v.get_nodecomp()!=NULL) {
		switch (v.get_nodecomp()->get_type()) {
		case op_is:
			fo_h->set_func(dctx_p->get_function(library::op_is_key));
			break;
		case op_precedes:
			fo_h->set_func(dctx_p->get_function(library::op_precedes_key));
			break;
		case op_follows:
			fo_h->set_func(dctx_p->get_function(library::op_follows_key));
			break;
		}
	}

	nodestack.push(&*fo_h);
	return true;
}

bool normalize_visitor::begin_visit(const CompAttrConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CompCommentConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CompDocConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CompElemConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CompPIConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const CompTextConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ContextItemExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const DirCommentConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const DirElemConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const DirElemContent& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const DirPIConstructor& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const EnclosedExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const Expr& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const ExprSingle& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ExtensionExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FLWORExpr& v)
{
	cout << indent[++depth] << TRACE << endl;
	rchandle<flwor_expr> flwor = new flwor_expr(v.get_location());
	nodestack.push(&*flwor);
	return true;
}

bool normalize_visitor::begin_visit(const FilterExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FunctionCall& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<QName> qn_h = v.get_fname();
	string uri;
	string prefix = qn_h->get_prefix();
	string fname = qn_h->get_localname();

	if (prefix=="fn" || prefix=="op") {
		uri = XQUERY_FN_NS;
	}
	else {
		uri = ZORBA_NS;
		prefix = ZORBA_PRE;
	}

	qnamekey_t funkey = Item::createQNameKey(uri,prefix,fname);
	yy::location loc = v.get_location();
	rchandle<fo_expr> fo_h = new fo_expr(loc);	nodestack.push(NULL);

	fo_h->set_func(dctx_p->get_function(funkey));
	nodestack.push(&*fo_h);
	return true;
}

bool normalize_visitor::begin_visit(const IfExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	// nothing to do here
	return true;
}

bool normalize_visitor::begin_visit(const InstanceofExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const IntersectExceptExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<fo_expr> fo_h = new fo_expr(v.get_location());

	switch (v.get_intex_op()) {
	case op_intersect:
		fo_h->set_func(dctx_p->get_function(library::op_intersect_key));
		break;
	case op_except:
		fo_h->set_func(dctx_p->get_function(library::op_except_key));
		break;
	}
	nodestack.push(&*fo_h);
	return true;
}

bool normalize_visitor::begin_visit(const MultiplicativeExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<fo_expr> fo_h = new fo_expr(v.get_location());
	switch (v.get_mult_op()) {
	case op_mul:
		fo_h->set_func(dctx_p->get_function(library::op_mul_key));
		break;
	case op_div:
		fo_h->set_func(dctx_p->get_function(library::op_div_key));
		break;
	case op_idiv:
		fo_h->set_func(dctx_p->get_function(library::op_idiv_key));
		break;
	case op_mod:
		fo_h->set_func(dctx_p->get_function(library::op_mod_key));
		break;
	}
	nodestack.push(&*fo_h);
	return true;
}

bool normalize_visitor::begin_visit(const NumericLiteral& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const OrderedExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ParenthesizedExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const PathExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const QuantifiedExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const QueryBody& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const RangeExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const RelativePathExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const StringLiteral& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const TreatExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const TypeswitchExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const UnaryExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const UnionExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	rchandle<fo_expr> fo_h = new fo_expr(v.get_location());
	fo_h->set_func(dctx_p->get_function(library::op_union_key));
	nodestack.push(&*fo_h);
	return true;
}

bool normalize_visitor::begin_visit(const UnorderedExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ValidateExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const VarRef& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}



/* update-related */
bool normalize_visitor::begin_visit(const DeleteExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const InsertExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const RenameExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const ReplaceExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const RevalidationDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const TransformExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const VarNameList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}



/* full-text-related */
bool normalize_visitor::begin_visit(const FTAnd& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTAnyallOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTBigUnit& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTCaseOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTContainsExpr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTContent& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTDiacriticsOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTDistance& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTIgnoreOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTInclExclStringLiteral& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTInclExclStringLiteralList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const FTLanguageOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTMatchOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTMatchOptionProximityList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const FTMildnot& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTOptionDecl& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTOr& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTOrderedIndicator& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTProximity& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTRange& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTRefOrList& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTScope& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTScoreVar& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTSelection& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTStemOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTStopwordOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTStringLiteralList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const FTThesaurusID& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTThesaurusList& v)
{
cout << indent[++depth] << TRACE << endl;
	nodestack.push(NULL);
	return true;
}

bool normalize_visitor::begin_visit(const FTThesaurusOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTTimes& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTUnaryNot& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTUnit& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTWildcardOption& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTWindow& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTWords& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTWordsSelection& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}

bool normalize_visitor::begin_visit(const FTWordsValue& v)
{
cout << indent[++depth] << TRACE << endl;
	return true;
}


/*..........................................
 :  end visit                              :
 :.........................................*/

void normalize_visitor::end_visit(const parsenode& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const exprnode& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const AbbrevForwardStep& v)
{
cout << indent[depth--] << TRACE << ": AbbrevForwardStep\n";
	rchandle<axis_step_expr> aexpr_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (aexpr_h==NULL) {
		cout << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	if (v.get_attr_bit()) {
		aexpr_h->set_axis(axis_step_expr::attribute);
	}
	else {
		aexpr_h->set_axis(axis_step_expr::child);
	}
}

void normalize_visitor::end_visit(const AnyKindTest& v)
{
cout << indent[depth--]<<TRACE<<": AnyKindTest()\n";
	rchandle<axis_step_expr> ase_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h==NULL) {
		cout << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::anykind_test);
	ase_h->set_test(m_h);
}

void normalize_visitor::end_visit(const AposAttrContentList& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const AposAttrValueContent& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

// FIXME The use of an argstack is not correct because of function calls like 'func1(a,func2(b,c),d)'! The arguments must be saved on the normal stack and not on a special one!
void normalize_visitor::end_visit(const ArgList& v)
{
cout << indent[depth--] << TRACE << ": ArgList" << endl;
	clear_argstack();
	while (true) {
		expr_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		argstack.push(e_h);
	}
}

void normalize_visitor::end_visit(const AtomicType& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const AttributeTest& v)
{
cout << indent[depth--]<<TRACE<<": ElementTest("; v.get_attr()->put(cout)<<")\n";

	/*
	 * find axis step expression on top of stack
	 */
	rchandle<axis_step_expr> ase_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	/*
	 * construct the attribute match
	 */
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::attr_test);
	rchandle<QName> elem_h = v.get_attr();
	if (elem_h!=NULL) {
		m_h->set_name(new qname_expr(v.get_location(),
																	elem_h->get_qname()));
	}
	rchandle<TypeName> type_h = v.get_type();
	if (type_h!=NULL) {
		m_h->set_typename(new qname_expr(v.get_location(),
																			type_h->get_name()->get_qname()));
	}
	if (v.is_wild()) {
		// XXX missing member variable for this
	}

	/*
	 * add the match expression
	 */
	ase_h->set_test(m_h);
}

void normalize_visitor::end_visit(const BaseURIDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const BoundarySpaceDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const CaseClause& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const CaseClauseList& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const CommentTest& v)
{
cout << indent[depth--]<<TRACE<<": CommentTest()\n";
	rchandle<axis_step_expr> ase_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::comment_test);
	ase_h->set_test(m_h);
}

void normalize_visitor::end_visit(const ConstructionDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const CopyNamespacesDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const DefaultCollationDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const DefaultNamespaceDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const DirAttr& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const DirAttributeList& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const DirAttributeValue& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const DirElemContentList& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const DocumentTest& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const ElementTest& v)
{
cout << indent[depth--]<<TRACE<<": ElementTest("; v.get_elem()->put(cout)<<")\n";

	/*
	 * find axis step expression on top of stack
	 */
	rchandle<axis_step_expr> ase_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	/*
	 * construct the element match
	 */
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::elem_test);

	rchandle<QName> elem_h = v.get_elem();
	if (elem_h!=NULL) {
		m_h->set_name(new qname_expr(v.get_location(),
																	elem_h->get_qname()));
	}
	rchandle<TypeName> type_h = v.get_type();
	if (type_h!=NULL) {
		m_h->set_typename(new qname_expr(v.get_location(),
																			type_h->get_name()->get_qname()));
	}
	bool optional_b =  v.get_optional_bit();
	if (optional_b) {
		// XXX missing member variable for this
	}

	/*
	 * add the match expression
	 */
	ase_h->set_test(m_h);

}

void normalize_visitor::end_visit(const EmptyOrderDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const ForClause& v)
{
cout << indent[depth--] <<TRACE << endl;
	int size = v.get_vardecl_list()->size();
	vector<expr_t> exprs;
	while (true) {
		expr_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		exprs.push_back(e_h);
	}
	
	rchandle<flwor_expr> flwor_h = dynamic_cast<flwor_expr*>(&*nodestack.top());
	if (flwor_h == NULL) {
		 cout << indent[depth] <<TRACE << ": expecting flwor_expr on top of stack" << endl;
	}

	for (int i = 0; i < size; i++) {
		expr_t expr = exprs[i];
		rchandle<VarInDecl> vid = (*v.get_vardecl_list())[i];
		string varname = vid->get_varname();
		rchandle<var_expr> var_h = new var_expr(v.get_location());
		var_h->set_kind(var_expr::for_var);
		rchandle<qname_expr> qname_h = new qname_expr(v.get_location(), varname);
		var_h->set_varname(qname_h);
		rchandle<forlet_clause> forlet_h = new forlet_clause(
			forlet_clause::for_clause, 
			var_h,
			NULL,
			NULL,
			expr
		);
		flwor_h->add(forlet_h);
	}

}

void normalize_visitor::end_visit(const ForLetClause& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const ForLetClauseList& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const ForwardAxis& v)
{
cout << indent[depth--] << TRACE << ": ForwardAxis" << endl;
	rchandle<axis_step_expr> aexpr_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (aexpr_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	switch (v.get_axis()) {
	case axis_child: {
		aexpr_h->set_axis(axis_step_expr::child);
		break;
	}
	case axis_descendant: {
		aexpr_h->set_axis(axis_step_expr::descendant);
		break;
	}
	case axis_attribute: {
		aexpr_h->set_axis(axis_step_expr::attribute);
		break;
	}
	case axis_self: {
		aexpr_h->set_axis(axis_step_expr::self);
		break;
	}
	case axis_descendant_or_self: {
		aexpr_h->set_axis(axis_step_expr::descendant_or_self);
		break;
	}
	case axis_following_sibling: {
		aexpr_h->set_axis(axis_step_expr::following_sibling);
		break;
	}
	case axis_following: {
		aexpr_h->set_axis(axis_step_expr::following);
		break;
	}
	}
}

void normalize_visitor::end_visit(const ForwardStep& v)
{
cout << indent[depth--] << TRACE << ": ForwardStep\n";
}

void normalize_visitor::end_visit(const FunctionDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const GeneralComp& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const ItemType& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const LetClause& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const LibraryModule& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const MainModule & v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const Module& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const ModuleDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const ModuleImport& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const NameTest& v)
{
cout << indent[depth--]<<TRACE<<": NameTest("; v.get_qname()->put(cout)<<")\n";
	/*
	 * find axis step on top of stack
	 */
	rchandle<axis_step_expr> ase_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	/*
	 * construct and add name test match
	 */
	string qname = v.get_qname()->get_qname();
	rchandle<qname_expr> qn_h = new qname_expr(v.get_location(),qname);
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_name(qn_h);
	m_h->set_test(match_expr::name_test);

	/*
	 * set wildcard type: *,  pre:*,  *:name
	 */
	rchandle<Wildcard> wild_h = v.get_wild();
	if (wild_h!=NULL) {
		switch (wild_h->get_type()) {
		case wild_all: m_h->set_wild(match_expr::all_wild); break;
		case wild_elem: m_h->set_wild(match_expr::name_wild); break;
		case wild_prefix: m_h->set_wild(match_expr::prefix_wild); break;
		}
	}

	/*
	 * add the match expression
	 */
	ase_h->set_test(m_h);
}

void normalize_visitor::end_visit(const NamespaceDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const NodeComp& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OccurrenceIndicator& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OptionDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderByClause& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderCollationSpec& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderDirSpec& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderEmptySpec& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderModifier& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderSpec& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderSpecList& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderingModeDecl& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const PITest& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const Param& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const ParamList& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const PositionalVar& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const Pragma& v)
{
 cout << indent[depth--] <<TRACE << endl;
}

void normalize_visitor::end_visit(const PragmaList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const PredicateList& v)
{
cout << indent[depth--] << TRACE << ": PredicateList" << endl;
	clear_pstack();
	while (true) {
		expr_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		pstack.push(e_h);
	}
}

void normalize_visitor::end_visit(const Prolog& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const QVarInDecl& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const QVarInDeclList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const QuoteAttrValueContent& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const QuoteAttrContentList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const ReverseAxis& v)
{
cout << indent[depth--] << TRACE << ": ReverseAxis" << endl;
	rchandle<axis_step_expr> aexpr_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (aexpr_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	switch (v.get_axis()) {
	case axis_parent: {
		aexpr_h->set_axis(axis_step_expr::parent);
		break;
	}
	case axis_ancestor: {
		aexpr_h->set_axis(axis_step_expr::ancestor);
		break;
	}
	case axis_preceding_sibling: {
		aexpr_h->set_axis(axis_step_expr::preceding_sibling);
		break;
	}
	case axis_preceding: {
		aexpr_h->set_axis(axis_step_expr::preceding);
		break;
	}
	case axis_ancestor_or_self: {
		aexpr_h->set_axis(axis_step_expr::ancestor_or_self);
		break;
	}
	}
}

void normalize_visitor::end_visit(const ReverseStep& v)
{
cout << indent[depth--] << TRACE << ": ReverseStep" << endl;
}

void normalize_visitor::end_visit(const SIND_DeclList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const SchemaAttributeTest& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const SchemaElementTest& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const SchemaImport& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const SchemaPrefix& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const SequenceType& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const SignList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const SingleType& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const TextTest& v)
{
cout << indent[depth--]<<TRACE<<": TextTest()\n";
	rchandle<axis_step_expr> ase_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h==NULL) {
		cout << indent[depth--] << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->set_test(match_expr::text_test);
	ase_h->set_test(m_h);
}

void normalize_visitor::end_visit(const TypeDeclaration& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const TypeName& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const URILiteralList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const ValueComp& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VarDecl& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VarGetsDecl& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VarGetsDeclList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VarInDecl& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VarInDeclList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VersionDecl& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VFO_DeclList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const WhereClause& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const Wildcard& v)
{
cout << indent[depth--] << TRACE << endl;
}




/* expressions */
void normalize_visitor::end_visit(const AdditiveExpr& v)
{
cout << indent[depth--] << TRACE << ": AdditiveExpr\n";

	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=3,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<expr> e2_h = nodestack.top(); nodestack.pop();
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << indent[depth--] <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const AndExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const AxisStep& v)
{
cout << indent[depth--] << TRACE << ": AxisStep\n";
	rchandle<axis_step_expr> aexpr_h =
		dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (aexpr_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		 cout << indent[depth--] <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	while (!pstack.empty()) {
		expr_t e_h = pstack.top();
		pstack.pop();
		aexpr_h->add_pred(e_h);
	}
}

void normalize_visitor::end_visit(const CDataSection& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const CastExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const CastableExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const CommonContent& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const ComparisonExpr& v)
{
cout << indent[depth--] << TRACE << ": ComparisonExpr\n";

	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=3,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<expr> e2_h = nodestack.top(); nodestack.pop();
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << indent[depth--] <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const CompAttrConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const CompCommentConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const CompDocConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const CompElemConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const CompPIConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const CompTextConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const ContextItemExpr& v)
{
cout << indent[depth--] << TRACE << ": ContextItemExpr" << endl;
	rchandle<var_expr> v_h = new var_expr(v.get_location());
	v_h->set_kind(var_expr::context_var);
	nodestack.push(&*v_h);
}

void normalize_visitor::end_visit(const DirCommentConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const DirElemConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const DirElemContent& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const DirPIConstructor& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const EnclosedExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const Expr& v)
{
	rchandle<expr_list> elist_h = new expr_list(v.get_location());
	while (true) {	
		expr_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		elist_h->add(e_h);
	}
	if (elist_h->size()==1) {
		list_iterator<expr_t> it = elist_h->begin();
		nodestack.push(&**it);
	}
	else {
		nodestack.push(&*elist_h);
	}
}

void normalize_visitor::end_visit(const ExprSingle& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const ExtensionExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FLWORExpr& v)
{
cout << indent[depth--] << TRACE << endl;
	expr_t returnExpr = pop_nodestack();
	rchandle<flwor_expr> flwor_h = dynamic_cast<flwor_expr*>(&*nodestack.top());
	if (flwor_h == NULL) {
		 cout << indent[depth] <<TRACE << ": expecting flwor_expr on top of stack" << endl;
	}
	flwor_h->set_retval(returnExpr);
}

void normalize_visitor::end_visit(const FilterExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FunctionCall& v)
{
cout << indent[depth--] << TRACE << ": FunctionCall" 
			<< " : argstack.size() = " << argstack.size() << endl;

	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) return;
	while (!argstack.empty()) {
		expr_t e_h = argstack.top();
		argstack.pop();
		if (e_h==NULL) continue;
		// >>add type promotion wrappers here<<
		fo_h->add(e_h);
	}
}

void normalize_visitor::end_visit(const IfExpr& v)
{
cout << indent[depth--] << TRACE << endl;
	expr_t c_h = nodestack.top(); nodestack.pop();
	expr_t t_h = nodestack.top(); nodestack.pop();
	expr_t e_h = nodestack.top(); nodestack.pop();
	rchandle<if_expr> if_h = new if_expr(v.get_location(),c_h,t_h,e_h);
	nodestack.push(&*if_h);
}

void normalize_visitor::end_visit(const InstanceofExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const IntersectExceptExpr& v)
{
cout << indent[depth--] << TRACE << ": IntersectExceptExpr\n";

	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=3,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<expr> e2_h = nodestack.top(); nodestack.pop();
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << indent[depth--] <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const MultiplicativeExpr& v)
{
cout << indent[depth--] << TRACE << endl;

	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=3,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<expr> e2_h = nodestack.top(); nodestack.pop();
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << indent[depth--] <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const NumericLiteral& v)
{
cout << indent[depth--] << TRACE << endl;
	switch (v.get_type()) {
	case num_integer: {
		nodestack.push(new literal_expr(v.get_location(), v.get_int()));
		break;
	}
	case num_decimal: {
		nodestack.push(new literal_expr(v.get_location(), v.get_decimal()));
		break;
	}
	case num_double: {
		nodestack.push(new literal_expr(v.get_location(), v.get_double()));
		break;
	}
	}
}

void normalize_visitor::end_visit(const OrExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const OrderedExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const ParenthesizedExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const PathExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const QuantifiedExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const QueryBody& v)
{
cout  << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const RangeExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const RelativePathExpr& v)
{
cout << indent[depth--] << TRACE << endl;
	expr_t e0_h = pop_nodestack();		// b
	expr_t e1_h = pop_nodestack();		// a

	rchandle<relpath_expr> rp_h = dynamic_cast<relpath_expr*>(&*e0_h);
	if (rp_h==NULL) {
		rp_h = new relpath_expr(v.get_location());
		rp_h->add_front(e0_h);
	}

	// check for 'a//b'
	if (v.get_step_type()==st_slashslash) {
		rchandle<axis_step_expr> ase_h = new axis_step_expr(v.get_location());
		rchandle<match_expr> m_h = new match_expr(v.get_location());
		m_h->set_test(match_expr::anykind_test);
		ase_h->set_axis(axis_step_expr::descendant_or_self);
		ase_h->set_test(m_h);
		rp_h->add_front(&*ase_h);
	}

	rp_h->add_front(e1_h);
	nodestack.push(&*rp_h);
}

void normalize_visitor::end_visit(const StringLiteral& v)
{
cout << indent[depth--] << TRACE << endl;
	nodestack.push(new literal_expr(v.get_location(),v.get_strval()));
}

void normalize_visitor::end_visit(const TreatExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const TypeswitchExpr& v)
{
cout << indent[depth--] << TRACE << endl;
	case_clause * cc_p;
	expr_t e_h;
	rchandle<typeswitch_expr> tse_h = new typeswitch_expr(v.get_location());

	rchandle<var_expr> ve_h = new var_expr(v.get_location());
	//ve_h->set_varname(new QName(v.get_default_varname()));
	tse_h->set_default_varname(ve_h);

	//d Assert<null_pointer>((e_h = pop_nodestack())!=NULL);
	Assert((e_h = pop_nodestack())!=NULL);
	tse_h->set_switch_expr(e_h);

	//d Assert<null_pointer>((e_h = pop_nodestack())!=NULL);
	Assert((e_h = pop_nodestack())!=NULL);
	tse_h->set_default_clause(e_h);

	while (true) {	// pop clauses
		e_h = nodestack.top();
		if ((cc_p = dynamic_cast<case_clause*>(&*e_h))==NULL) break;
		nodestack.pop();
		tse_h->add_clause(cc_p);
	}

	nodestack.push(&*tse_h);
}

void normalize_visitor::end_visit(const UnaryExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const UnionExpr& v)
{
cout << indent[depth--] << TRACE << endl;

	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=3,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<expr> e2_h = nodestack.top(); nodestack.pop();
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << indent[depth--] <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << indent[depth--] <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const UnorderedExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const ValidateExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VarRef& v)
{
cout << indent[depth--] << TRACE << endl;
	rchandle<var_expr> ve_h = new var_expr(v.get_location());
	//ve_h->set_varname(new QName(v.get_varname()));
	nodestack.push(&*ve_h);
}



/* update-related */
void normalize_visitor::end_visit(const DeleteExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const InsertExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const RenameExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const ReplaceExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const RevalidationDecl& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const TransformExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const VarNameList& v)
{
cout << indent[depth--] << TRACE << endl;
}



/* full-text-related */
void normalize_visitor::end_visit(const FTAnd& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTAnyallOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTBigUnit& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTCaseOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTContainsExpr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTContent& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTDiacriticsOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTDistance& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTIgnoreOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTInclExclStringLiteral& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTInclExclStringLiteralList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTLanguageOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTMatchOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTMatchOptionProximityList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTMildnot& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTOptionDecl& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTOr& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTOrderedIndicator& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTProximity& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTRange& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTRefOrList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTScope& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTScoreVar& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTSelection& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTStemOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTStopwordOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTStringLiteralList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTThesaurusID& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTThesaurusList& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTThesaurusOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTTimes& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTUnaryNot& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTUnit& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWildcardOption& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWindow& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWords& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWordsSelection& v)
{
cout << indent[depth--] << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWordsValue& v)
{
cout << indent[depth--] << TRACE << endl;
}

} /* namespace xqp */

