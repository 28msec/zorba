/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: normalize_visitor.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "compiler/translator/normalize_visitor.h"

#include "functions/library.h"
#include "compiler/parsetree/parsenodes.h"
#include "util/tracer.h"
#include "store/api/item.h"
#include "util/zorba.h"


#include <iostream>
#include <string>

using namespace std;

namespace xqp {

static uint32_t depth = 0;

static void *no_state = (void *) new int;

normalize_visitor::normalize_visitor()
{
	zorp = zorba::getZorbaForCurrentThread();
	dctx_p = zorp->get_dynamic_context();
// 	dmgr_h = zorp->get_data_manager();
  sctx_p = zorp->get_static_context();
}



/*..........................................
 :  begin visit                            :
 :.........................................*/

void *normalize_visitor::begin_visit(const parsenode& v)
{
cout<< std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const exprnode& v)
{
cout<< std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void *normalize_visitor::begin_visit(const AposAttrContentList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
// 	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const AposAttrValueContent& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ArgList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const AtomicType& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void *normalize_visitor::begin_visit(const BaseURIDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	sctx_p->set_baseuri(v.get_base_uri());
	return NULL;
}

void *normalize_visitor::begin_visit(const BoundarySpaceDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	sctx_p->set_boundary_space_mode(v.get_boundary_space_mode());
	return NULL;
}

void *normalize_visitor::begin_visit(const CaseClause& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CaseClauseList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}


void *normalize_visitor::begin_visit(const ConstructionDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	sctx_p->set_construction_mode(v.get_mode());
	return NULL;
}

void *normalize_visitor::begin_visit(const CopyNamespacesDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(DefaultCollationDecl const& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	string uri = v.get_collation();
	sctx_p->set_default_collation(uri);
	return NULL;
}

void *normalize_visitor::begin_visit(
	DefaultNamespaceDecl const& v)
{
// TODO adapt to new store
// cout << std::string(++depth, ' ') << TRACE << endl;
// 	switch (v.get_mode()) {
// 	case ns_element_default: {
// 		namespace_node* ns_p = new dom_namespace_node("#elem#",v.get_default_namespace());
// 		zorp->get_dynamic_context()->set_default_element_type_namespace(*ns_p);
// 		break;
// 	}
// 	case ns_function_default: {
// 		namespace_node* ns_p = new dom_namespace_node("#func#",v.get_default_namespace());
// 		sctx_p->set_default_function_namespace(ns_p);
// 		break;
// 	}}
  switch (v.get_mode()) {
  case ns_element_default:
    sctx_p->set_default_elem_type_ns (v.get_default_namespace ());
    break;
  case ns_function_default:
    sctx_p->set_default_function_namespace (v.get_default_namespace ());
    break;
  }
  return NULL;
}

void *normalize_visitor::begin_visit(const DirAttr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	// boundary is needed because the value of an attribute might be empty
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const DirAttributeList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const DirAttributeValue& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const DirElemContentList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}


void *normalize_visitor::begin_visit(const EmptyOrderDecl& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;

	sctx_p->set_order_empty_mode(v.get_mode());
	return no_state;
}

void *normalize_visitor::begin_visit(const FLWORExpr& v)
{
	cout << std::string(++depth, ' ') << TRACE << endl;
  return no_state;
}

void normalize_visitor::end_visit(const FLWORExpr& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;

  int i, j;

  flwor_expr *flwor = new flwor_expr (v.get_location ());
  flwor->set_retval (pop_nodestack ());

  ForLetClauseList *clauses = v.get_forlet_list ().get_ptr ();
  vector <forlet_clause *> eclauses;

  for (i = clauses->size () - 1; i >= 0; i--) {
    ForOrLetClause *clause = (*clauses) [i].get_ptr ();
    vector<rchandle <var_expr> > vars;
    vector<rchandle <expr> > exprs;
    int size = clause->get_decl_count ();

    if (clause->for_or_let () == ForOrLetClause::for_clause) {
      ForClause *forclause = static_cast<ForClause *> (clause);

      for (j = 0; j < size; j++) {
        exprs.push_back(pop_nodestack ());
        rchandle<var_expr> ve = pop_nodestack ().cast<var_expr> ();
        ve->set_kind (var_expr::for_var);
        vars.push_back (ve);
        pop_scope ();
      }

      for (j = 0; j < size; j++) {
        forlet_clause *flc = new forlet_clause (forlet_clause::for_clause, vars [j], NULL, NULL, exprs [j]);
        eclauses.push_back (flc);
      }
    } else {
      LetClause *letclause = static_cast<LetClause *> (clause);
      
      for (j = 0; j < size; j++) {
        exprs.push_back(pop_nodestack ());
        rchandle<var_expr> ve = pop_nodestack ().cast<var_expr> ();
        ve->set_kind (var_expr::let_var);
        vars.push_back (ve);
        pop_scope ();
      }

      for (j = 0; j < size; j++) {
        forlet_clause *flc = new forlet_clause (forlet_clause::let_clause, vars [j], NULL, NULL, exprs [j]);
        eclauses.push_back (flc);
      }
    }
  }
  
  for (i = eclauses.size () - 1; i >= 0; i--)
    flwor->add (rchandle<forlet_clause> (eclauses [i]));
  nodestack.push (rchandle<expr> (flwor));
}

void *normalize_visitor::begin_visit(const LetClause& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const LetClause& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void *normalize_visitor::begin_visit(const ForClause& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const ForClause& v, void *visit_state)
{
  cout << std::string(depth--, ' ') <<TRACE << endl;
}

void *normalize_visitor::begin_visit(const ForLetClauseList& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const ForLetClauseList& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void *normalize_visitor::begin_visit(const WhereClause& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const WhereClause& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
}

void *normalize_visitor::begin_visit(const OrderByClause& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const OrderByClause& v, void *visit_state)
{
  cout << std::string(depth--, ' ') <<TRACE << endl;
}

void *normalize_visitor::begin_visit(const VarDecl& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const VarDecl& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void *normalize_visitor::begin_visit(const VarGetsDecl& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
  push_scope ();
  var_expr *evar = new var_expr (v.get_location ());
  string varname = v.get_varname ();
  // TODO: qname
  evar->set_varname (new qname_expr (v.get_location (), "", varname));
  sctx_p->bind_var (varname, evar);
  nodestack.push (evar);
	return no_state;
}

void normalize_visitor::end_visit(const VarGetsDecl& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void *normalize_visitor::begin_visit(const VarGetsDeclList& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const VarGetsDeclList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void *normalize_visitor::begin_visit(const VarInDecl& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
  push_scope ();
  var_expr *evar = new var_expr (v.get_location ());
  string varname = v.get_varname ();
  // TODO: qname
  evar->set_varname (new qname_expr (v.get_location (), "", varname));
  sctx_p->bind_var (varname, evar);
  nodestack.push (evar);
	return no_state;
}

void normalize_visitor::end_visit(const VarInDecl& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
}

void *normalize_visitor::begin_visit(const VarInDeclList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const VarInDeclList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}


void *normalize_visitor::begin_visit(const FunctionDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const GeneralComp& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ItemType& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const LibraryModule& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const MainModule & v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const Module& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ModuleDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ModuleImport& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const NamespaceDecl& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
  sctx_p->bind_ns (v.get_prefix (), v.get_uri ());
  return NULL;
}

void *normalize_visitor::begin_visit(const NodeComp& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OccurrenceIndicator& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OptionDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OrderCollationSpec& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OrderDirSpec& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OrderEmptySpec& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OrderModifier& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OrderSpec& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OrderSpecList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const OrderingModeDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	zorp->get_dynamic_context()->set_ordering_mode(v.get_mode());
	return NULL;
}


void *normalize_visitor::begin_visit(const Param& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ParamList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const PositionalVar& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const Pragma& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const PragmaList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const PredicateList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const Prolog& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const QVarInDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const QVarInDeclList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const QuoteAttrValueContent& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const QuoteAttrContentList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}


void *normalize_visitor::begin_visit(const SIND_DeclList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}


void *normalize_visitor::begin_visit(const SchemaImport& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const SchemaPrefix& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const SequenceType& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const SignList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const SingleType& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void *normalize_visitor::begin_visit(const TypeDeclaration& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const TypeName& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const URILiteralList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const ValueComp& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const VersionDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const VFO_DeclList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}


/* expressions */
void *normalize_visitor::begin_visit(const AdditiveExpr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const AndExpr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void *normalize_visitor::begin_visit(const CDataSection& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CastExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CastableExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CommonContent& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ComparisonExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
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
	return no_state;
}

void *normalize_visitor::begin_visit(const CompAttrConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CompCommentConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CompDocConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CompElemConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CompPIConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const CompTextConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ContextItemExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const DirCommentConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const DirElemConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const DirElemContent& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const DirPIConstructor& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const EnclosedExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const Expr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

// void *normalize_visitor::begin_visit(const ExprSingle& v)
// {
// cout << std::string(++depth, ' ') << TRACE << endl;
//  return no_state;
// }

void *normalize_visitor::begin_visit(const ExtensionExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FilterExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FunctionCall& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
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
	rchandle<fo_expr> fo_h = new fo_expr(loc);

	fo_h->set_func(dctx_p->get_function(funkey));
	nodestack.push(&*fo_h);
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const IfExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	// nothing to do here
	return no_state;
}

void *normalize_visitor::begin_visit(const InstanceofExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const IntersectExceptExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	fo_expr *fo_h = new fo_expr(v.get_location());

	switch (v.get_intex_op()) {
	case op_intersect:
		fo_h->set_func(dctx_p->get_function(library::op_intersect_key));
		break;
	case op_except:
		fo_h->set_func(dctx_p->get_function(library::op_except_key));
		break;
	}
	nodestack.push(fo_h);
	return no_state;
}

void *normalize_visitor::begin_visit(const MultiplicativeExpr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const NumericLiteral& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OrExpr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const OrderedExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ParenthesizedExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}



/*******************************************************************************

  NodeTest (NameTest | KindTest)

********************************************************************************/
void *normalize_visitor::begin_visit(const NameTest& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}



void normalize_visitor::end_visit(const NameTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << ": "; v.put(cout);

	// Find axis step on top of stack
	rchandle<axis_step_expr> axisExpr = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (axisExpr == NULL)
  {
    cout << std::string(depth--, ' ') <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	// Construct name-test match expr
  rchandle<match_expr> matchExpr = new match_expr(v.get_location());;
  matchExpr->setTestKind(match_name_test);

  if (v.getQName() != NULL)
  {
    string qname = v.getQName()->get_qname();
    rchandle<qname_expr> qn_h = new qname_expr(v.get_location(), qname);
    matchExpr->setQName(qn_h);
  }
  else
  {
    rchandle<Wildcard> wildcard = v.getWildcard();
    Assert(wildcard != NULL);

		switch (wildcard->getKind())
    {
		case wild_all:
      matchExpr->setWildKind(match_all_wild);
      break;
		case wild_elem:
      matchExpr->setWildKind(match_name_wild);
      matchExpr->setWildName(wildcard->getPrefix());
      break;
		case wild_prefix:
      matchExpr->setWildKind(match_prefix_wild);
      matchExpr->setWildName(wildcard->getLocalName());
      break;
		}
	}

	// add the match expression
	axisExpr->setTest(matchExpr);
}


void *normalize_visitor::begin_visit(const Wildcard& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const Wildcard& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
}


void *normalize_visitor::begin_visit(const AnyKindTest& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	// no action needed here
	return no_state;
}


void normalize_visitor::end_visit(const AnyKindTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ')<<TRACE<<": AnyKindTest()\n";
	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
		cout << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	rchandle<match_expr> me = new match_expr(v.get_location());
	me->setTestKind(match_anykind_test);
	ase->setTest(me);
}


void *normalize_visitor::begin_visit(const DocumentTest& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;

	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_doc_test);

	rchandle<ElementTest> e_h = v.get_elem_test();
	if (e_h != NULL)
  {
		rchandle<QName> elem_h = e_h->getElementName();
		if (elem_h != NULL)
    {
			m_h->setQName(new qname_expr(v.get_location(),
                                   elem_h->get_prefix(), elem_h->get_localname()));
		}
		rchandle<TypeName> type_h = e_h->getTypeName();
		if (type_h != NULL)
    {
			m_h->setTypeName(new qname_expr(v.get_location(),
                                      type_h->get_name()->get_qname()));
		}
		bool optional_b =  e_h->isNilledAllowed();
		if (optional_b)
    {
			// XXX missing member variable for this
		}
	}
	nodestack.push(&*m_h);
	return no_state;
}


void normalize_visitor::end_visit(const DocumentTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ') <<TRACE << endl;
}


void *normalize_visitor::begin_visit(const ElementTest& v)
{
	cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const ElementTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ')<<TRACE<<": ElementTest(";
  v.getElementName()->put(cout)<<")\n";

	// find axis step expression on top of stack
	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
    cout << std::string(depth--, ' ') << TRACE
         << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	// construct the element match
	rchandle<match_expr> me = new match_expr(v.get_location());
	me->setTestKind(match_elem_test);

	rchandle<QName> ename = v.getElementName();
	if (ename != NULL)
		me->setQName(new qname_expr(v.get_location(), ename->get_qname()));

	rchandle<TypeName> tname = v.getTypeName();
	if (tname != NULL)
		me->setTypeName(new qname_expr(v.get_location(), tname->get_name()->get_qname()));

	bool nilled =  v.isNilledAllowed();
	if (nilled)
    me->setNilledAllowed(true);

	// add the match expression
	ase->setTest(me);
}


void *normalize_visitor::begin_visit(const AttributeTest& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const AttributeTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ')<<TRACE<<": AttributeTest("; v.get_attr()->put(cout)<<")\n";

	// find axis step expression on top of stack
	rchandle<axis_step_expr> ase_h = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h == NULL)
  {
    cout << std::string(depth--, ' ') <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	/*
	 * construct the attribute match
	 */
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_attr_test);
	rchandle<QName> elem_h = v.get_attr();
	if (elem_h != NULL)
  {
		m_h->setQName(new qname_expr(v.get_location(), elem_h->get_qname()));
	}
	rchandle<TypeName> type_h = v.get_type();
	if (type_h!=NULL)
  {
		m_h->setTypeName(new qname_expr(v.get_location(), type_h->get_name()->get_qname()));
	}
	if (v.is_wild())
  {
		// XXX missing member variable for this
	}

	/*
	 * add the match expression
	 */
	ase_h->setTest(m_h);
}


void *normalize_visitor::begin_visit(const TextTest& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	// no action needed here
	return no_state;
}


void normalize_visitor::end_visit(const TextTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ')<<TRACE<<": TextTest()\n";

	rchandle<axis_step_expr> ase_h = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h == NULL)
  {
		cout << std::string(depth--, ' ') << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_text_test);
	ase_h->setTest(m_h);
}


void *normalize_visitor::begin_visit(const CommentTest& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	// no action needed here
	return no_state;
}


void normalize_visitor::end_visit(const CommentTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ')<<TRACE<<": CommentTest()\n";

	rchandle<axis_step_expr> ase_h = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h == NULL)
  {
    cout << std::string(depth--, ' ') <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_comment_test);
	ase_h->setTest(m_h);
}


void *normalize_visitor::begin_visit(const PITest& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;

	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_pi_test);

	string target = v.get_target();
	m_h->setQName(new qname_expr(v.get_location(), target));
	nodestack.push(&*m_h);
	return no_state;
}


void normalize_visitor::end_visit(const PITest& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}


void *normalize_visitor::begin_visit(const SchemaAttributeTest& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_xs_attr_test);

	rchandle<QName> attr_h = v.get_attr();
	if (attr_h!=NULL) {
		m_h->setQName(new qname_expr(v.get_location(), attr_h->get_qname()));
	}
	nodestack.push(&*m_h);
	return no_state;
}


void normalize_visitor::end_visit(const SchemaAttributeTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
}


void *normalize_visitor::begin_visit(const SchemaElementTest& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_xs_elem_test);

	rchandle<QName> elem_h = v.get_elem();
	if (elem_h!=NULL) {
		m_h->setQName(new qname_expr(v.get_location(), elem_h->get_qname()));
	}
	nodestack.push(&*m_h);
	return no_state;
}


void normalize_visitor::end_visit(const SchemaElementTest& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
}



/*******************************************************************************

  Path Expressions

  The syntax tree for a generic PathExpr looks like this:

       PathExpr
           |
         rpe1
        /    \
      step1  rpe2
            /    \
          step2  rpe3
                /    \
              step3  step4

  The PathExpr node will be there only if the path expr starts with / or //

********************************************************************************/
void *normalize_visitor::begin_visit(const PathExpr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const PathExpr& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;

  // Create fn:root(self::node()) expr
  rchandle<match_expr> me = new match_expr(v.get_location());
  me->setTestKind(match_anykind_test);

  rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
  ase->setAxis(axis_kind_self);
  ase->setTest(me);
 
  rchandle<fo_expr> fo = new fo_expr(v.get_location());
  fo->set_func(dctx_p->get_function(library::fn_root_key));
  fo->add(&*ase);

  if (v.get_type() == path_leading_lone_slash)
  {
    	nodestack.push(&*fo);
  }
  else
  {
    rchandle<relpath_expr> rpe = dynamic_cast<relpath_expr*>(&*nodestack.top());
    Assert(rpe != NULL);    

    if (v.get_type() == path_leading_slash)
    {
      rpe->add_front(&*fo);
    }
    else if (v.get_type() == path_leading_slashslash)
    {
      ase = new axis_step_expr(v.get_location());
      me = new match_expr(v.get_location());
      me->setTestKind(match_anykind_test);
      ase->setAxis(axis_kind_descendant_or_self);
      ase->setTest(me);
      rpe->add_front(&*ase);
      rpe->add_front(&*fo);
    }
  }
}


void *normalize_visitor::begin_visit(const RelativePathExpr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const RelativePathExpr& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;

	expr_t arg2 = pop_nodestack();		// step-(i+1) or rpe-(i+1)
	expr_t arg1 = pop_nodestack();		// step-i

	rchandle<relpath_expr> rpe = dynamic_cast<relpath_expr*>(&*arg2);
	if (rpe == NULL)
  {
		rpe = new relpath_expr(v.get_location());
		rpe->add_front(arg2);
	}

	if (v.get_step_type() == st_slashslash)
  {
		rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
		rchandle<match_expr> me = new match_expr(v.get_location());
		me->setTestKind(match_anykind_test);
		ase->setAxis(axis_kind_descendant_or_self);
		ase->setTest(me);
		rpe->add_front(&*ase);
	}

	rpe->add_front(arg1);
	nodestack.push(&*rpe);
}


void *normalize_visitor::begin_visit(const AxisStep& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;

	rchandle<axis_step_expr> aexpr_h = new axis_step_expr(v.get_location());
	nodestack.push(&*aexpr_h);
	return no_state;
}


void normalize_visitor::end_visit(const AxisStep& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << ": AxisStep\n";

	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
		 cout << std::string(depth--, ' ') <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		 cout << std::string(depth--, ' ') <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	while (!pstack.empty())
  {
		expr_t e = pstack.top();
		pstack.pop();
		ase->addPred(e);
	}
}


void *normalize_visitor::begin_visit(const ForwardStep& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const ForwardStep& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << ": ForwardStep\n";
}


void *normalize_visitor::begin_visit(const AbbrevForwardStep& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const AbbrevForwardStep& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << ": AbbrevForwardStep\n";

	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL) 
  {
		cout << TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	if (v.get_attr_bit())
  {
		ase->setAxis(axis_kind_attribute);
	}
	else
  {
		ase->setAxis(axis_kind_child);
	}
}


void *normalize_visitor::begin_visit(const ForwardAxis& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const ForwardAxis& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << ": ForwardAxis" << endl;

	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
    cout << std::string(depth--, ' ') <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	switch (v.get_axis())
  {
	case axis_child:
  {
		ase->setAxis(axis_kind_child);
		break;
	}
	case axis_descendant:
  {
		ase->setAxis(axis_kind_descendant);
		break;
	}
	case axis_attribute:
  {
		ase->setAxis(axis_kind_attribute);
		break;
	}
	case axis_self:
  {
		ase->setAxis(axis_kind_self);
		break;
	}
	case axis_descendant_or_self:
  {
		ase->setAxis(axis_kind_descendant_or_self);
		break;
	}
	case axis_following_sibling:
  {
		ase->setAxis(axis_kind_following_sibling);
		break;
	}
	case axis_following:
  {
		ase->setAxis(axis_kind_following);
		break;
	}
	}
}


void *normalize_visitor::begin_visit(const ReverseStep& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const ReverseStep& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << ": ReverseStep" << endl;
}


void *normalize_visitor::begin_visit(const ReverseAxis& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void normalize_visitor::end_visit(const ReverseAxis& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << ": ReverseAxis" << endl;

	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
    cout << std::string(depth--, ' ') <<TRACE << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	switch (v.get_axis())
  {
	case axis_parent:
  {
		ase->setAxis(axis_kind_parent);
		break;
	}
	case axis_ancestor:
  {
		ase->setAxis(axis_kind_ancestor);
		break;
	}
	case axis_preceding_sibling:
  {
		ase->setAxis(axis_kind_preceding_sibling);
		break;
	}
	case axis_preceding:
  {
		ase->setAxis(axis_kind_preceding);
		break;
	}
	case axis_ancestor_or_self:
  {
		ase->setAxis(axis_kind_ancestor_or_self);
		break;
	}
	}
}


/*******************************************************************************

********************************************************************************/
void *normalize_visitor::begin_visit(const QuantifiedExpr& v)
{
  cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


/*******************************************************************************

********************************************************************************/
void *normalize_visitor::begin_visit(const QueryBody& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


/*******************************************************************************

********************************************************************************/
void *normalize_visitor::begin_visit(const RangeExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


void *normalize_visitor::begin_visit(const StringLiteral& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const TreatExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const TypeswitchExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const UnaryExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	fo_expr *fo_h = new fo_expr(v.get_location());
	if (v.get_signlist()->get_sign())
		fo_h->set_func(dctx_p->get_function(library::op_unary_plus_key));
	else
		fo_h->set_func(dctx_p->get_function(library::op_unary_minus_key));
	nodestack.push(fo_h);
	return no_state;
}

void *normalize_visitor::begin_visit(const UnionExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	fo_expr *fo_h = new fo_expr(v.get_location());
	fo_h->set_func(dctx_p->get_function(library::op_union_key));
	nodestack.push(fo_h);
	return no_state;
}

void *normalize_visitor::begin_visit(const UnorderedExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ValidateExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const VarRef& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void normalize_visitor::end_visit(const VarRef& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
	var_expr *e = static_cast<var_expr *> (sctx_p->lookup_var (v.get_varname ()));
  if (e == NULL)
    cout << "Variable " << v.get_varname () << " not found!\n";
  Assert (e != NULL);
	nodestack.push (rchandle<expr> (e));
}


/* update-related */
void *normalize_visitor::begin_visit(const DeleteExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const InsertExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const RenameExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const ReplaceExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const RevalidationDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const TransformExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const VarNameList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}



/* full-text-related */
void *normalize_visitor::begin_visit(const FTAnd& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTAnyallOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTBigUnit& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTCaseOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTContainsExpr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTContent& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTDiacriticsOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTDistance& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTIgnoreOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTInclExclStringLiteral& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTInclExclStringLiteralList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const FTLanguageOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTMatchOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTMatchOptionProximityList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const FTMildnot& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTOptionDecl& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTOr& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTOrderedIndicator& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTProximity& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTRange& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTRefOrList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTScope& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTScoreVar& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTSelection& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTStemOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTStopwordOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTStringLiteralList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const FTThesaurusID& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTThesaurusList& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	nodestack.push(NULL);
	return no_state;
}

void *normalize_visitor::begin_visit(const FTThesaurusOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTTimes& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTUnaryNot& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTUnit& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTWildcardOption& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTWindow& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTWords& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTWordsSelection& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}

void *normalize_visitor::begin_visit(const FTWordsValue& v)
{
cout << std::string(++depth, ' ') << TRACE << endl;
	return no_state;
}


/*..........................................
 :  end visit                              :
 :.........................................*/

void normalize_visitor::end_visit(const parsenode& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const exprnode& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}


void normalize_visitor::end_visit(const AposAttrContentList& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const AposAttrValueContent& v, void *visit_state)
{
cout << std::string(depth--, ' ') <<TRACE << endl;
	
}

void normalize_visitor::end_visit(const ArgList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << ": ArgList" << endl;
}

void normalize_visitor::end_visit(const AtomicType& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}


void normalize_visitor::end_visit(const BaseURIDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const BoundarySpaceDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const CaseClause& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const CaseClauseList& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}


void normalize_visitor::end_visit(const ConstructionDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const CopyNamespacesDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const DefaultCollationDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const DefaultNamespaceDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const DirAttr& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
 	expr_t attrValue = pop_nodestack();
 	if (attrValue != NULL) {
 		// delete boundary
 		nodestack.pop();
 	}
 	rchandle<qname_expr> name = new qname_expr(v.get_location(), v.get_atname()->get_prefix(), v.get_atname()->get_localname());
 	rchandle<attr_expr> attr_expr_t = new attr_expr(v.get_location(), name, attrValue);
 	nodestack.push(&*attr_expr_t);
}

void normalize_visitor::end_visit(const DirAttributeList& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
 	rchandle<expr_list> expr_list_t = new expr_list(v.get_location());
 	while(true) {
 		expr_t e_h = pop_nodestack();
 		if (e_h == NULL) break;
 		expr_list_t->add(e_h);
 	}
 	nodestack.push(&*expr_list_t);
}

void normalize_visitor::end_visit(const DirAttributeValue& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
 
}

void normalize_visitor::end_visit(const DirElemContentList& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
	rchandle<expr_list> expr_list_t = new expr_list(v.get_location());
	while (true) {
		expr_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		expr_list_t->add(e_h);
	}
	nodestack.push(&*expr_list_t);
}


void normalize_visitor::end_visit(const EmptyOrderDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}


void normalize_visitor::end_visit(const FunctionDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const GeneralComp& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const ItemType& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const LibraryModule& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const MainModule & v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const Module& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const ModuleDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const ModuleImport& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}


void normalize_visitor::end_visit(const NamespaceDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const NodeComp& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OccurrenceIndicator& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OptionDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderCollationSpec& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderDirSpec& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderEmptySpec& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderModifier& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderSpec& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderSpecList& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const OrderingModeDecl& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}


void normalize_visitor::end_visit(const Param& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const ParamList& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const PositionalVar& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const Pragma& v, void *visit_state)
{
 cout << std::string(depth--, ' ') <<TRACE << endl;
}

void normalize_visitor::end_visit(const PragmaList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const PredicateList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << ": PredicateList" << endl;
	clear_pstack();
	while (true) {
		expr_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		pstack.push(e_h);
	}
}

void normalize_visitor::end_visit(const Prolog& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const QVarInDecl& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const QVarInDeclList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const QuoteAttrValueContent& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	if (v.get_common_content() == NULL) {
		std::string content = v.get_quot_atcontent();
		rchandle<text_expr> text_t = new text_expr(v.get_location(), content);
		nodestack.push(&*text_t);
	}
	// nothing to be done becaus when common content != NULL, 
	// because the corresponding expr is already on the stack
	
}

void normalize_visitor::end_visit(const QuoteAttrContentList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
 	rchandle<expr_list> expr_list_t = new expr_list(v.get_location());
 	while(true) {
 		expr_t e_h = pop_nodestack();
 		if (e_h == NULL) break;
 		expr_list_t->add(e_h);
 	}
 	nodestack.push(&*expr_list_t);
}


void normalize_visitor::end_visit(const SIND_DeclList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const SchemaImport& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const SchemaPrefix& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const SequenceType& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const SignList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const SingleType& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}


void normalize_visitor::end_visit(const TypeDeclaration& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const TypeName& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const URILiteralList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const ValueComp& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const VersionDecl& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const VFO_DeclList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}


/* expressions */
void normalize_visitor::end_visit(const AdditiveExpr& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << ": AdditiveExpr\n";
	Assert(nodestack.size()>=2,"stack underflow");
	rchandle<expr> e1_h = pop_nodestack();
	rchandle<expr> e2_h = pop_nodestack();
	fo_expr *fo_h = new fo_expr(v.get_location());
	switch (v.get_add_op()) {
	case op_plus:
		fo_h->set_func(dctx_p->get_function(library::op_add_key));
		break;
	case op_minus:
		fo_h->set_func(dctx_p->get_function(library::op_subtract_key));
		break;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
  nodestack.push (fo_h);
}

void normalize_visitor::end_visit(const AndExpr& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
	Assert(nodestack.size()>=2,"stack underflow");
	rchandle<expr> e1_h = pop_nodestack();
	rchandle<expr> e2_h = pop_nodestack();
	fo_expr *fo_h = new fo_expr(v.get_location());
	fo_h->set_func(dctx_p->get_function(library::op_and_key));
	fo_h->add(e2_h);
	fo_h->add(e1_h);
  nodestack.push (fo_h);
}


void normalize_visitor::end_visit(const CDataSection& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const CastExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const CastableExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const CommonContent& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const ComparisonExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << ": ComparisonExpr\n";

	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=3,"stack underflow");
	rchandle<expr> e1_h = pop_nodestack();
	rchandle<expr> e2_h = pop_nodestack();;
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << std::string(depth--, ' ') <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << std::string(depth--, ' ') <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const CompAttrConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const CompCommentConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const CompDocConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const CompElemConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const CompPIConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const CompTextConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const ContextItemExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << ": ContextItemExpr" << endl;
	rchandle<var_expr> v_h = new var_expr(v.get_location());
	v_h->set_kind(var_expr::context_var);
	nodestack.push(&*v_h);
}

void normalize_visitor::end_visit(const DirCommentConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const DirElemConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	expr_t attributes = NULL;
	expr_t content = NULL;
	if (v.get_attr_list() != NULL)
		attributes = pop_nodestack();
	if (v.get_dir_content_list() != NULL)
		content = pop_nodestack();
	rchandle<qname_expr> name = new qname_expr(v.get_location(), v.get_elem_name()->get_prefix(), v.get_elem_name()->get_localname());
	rchandle<elem_expr> elem_t = new elem_expr(v.get_location(), name, attributes, content);
	nodestack.push(&*elem_t);
}

void normalize_visitor::end_visit(const DirElemContent& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	if (v.get_direct_cons() != NULL) {
		// nothing to be done, the content expression is already on the stack
	} else if (v.get_cdata() != NULL) {
		
	} else if (v.get_common_content() != NULL) {
	
	} else {
		std::string content = v.get_elem_content();
		rchandle<text_expr> text_t = new text_expr(v.get_location(), content);
		nodestack.push(&*text_t);
	}
}

void normalize_visitor::end_visit(const DirPIConstructor& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const EnclosedExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	expr_t expr_h = pop_nodestack();
	expr_t enclosedExpr = new enclosed_expr(v.get_location(), expr_h);
	nodestack.push(&*enclosedExpr);
}

void normalize_visitor::end_visit(const Expr& v, void *visit_state)
{
	rchandle<expr_list> elist_h = new expr_list(v.get_location());
  for (int i = 0; i < v.numberOfChildren (); i++) {
		expr_t e_h = pop_nodestack();
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

// void normalize_visitor::end_visit(const ExprSingle& v, void *visit_state)
// {
// cout << std::string(depth--, ' ') << TRACE << endl;
// }

void normalize_visitor::end_visit(const ExtensionExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FilterExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FunctionCall& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	std::vector<expr_t> arguments;
	while (true) {
		expr_t e_h = pop_nodestack();
		if (e_h == NULL)
			break;
		arguments.push_back(e_h);
	}
	
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h == NULL) return;
	
	// TODO this should be a const iterator
	std::vector<expr_t>::reverse_iterator iter = arguments.rbegin();
	for(; iter != arguments.rend(); ++iter) {
		fo_h->add(*iter);
	}
}

void normalize_visitor::end_visit(const IfExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	expr_t e_h = nodestack.top(); nodestack.pop();
	expr_t t_h = nodestack.top(); nodestack.pop();
	expr_t c_h = nodestack.top(); nodestack.pop();
	rchandle<if_expr> if_h = new if_expr(v.get_location(),c_h,t_h,e_h);
	nodestack.push(&*if_h);
}

void normalize_visitor::end_visit(const InstanceofExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const IntersectExceptExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << ": IntersectExceptExpr\n";

	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=3,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<expr> e2_h = nodestack.top(); nodestack.pop();
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << std::string(depth--, ' ') <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << std::string(depth--, ' ') <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const MultiplicativeExpr& v, void *visit_state)
{
  cout << std::string(depth--, ' ') << TRACE << endl;
	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=2,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<expr> e2_h = nodestack.top(); nodestack.pop();
	fo_expr *fo_h = new fo_expr(v.get_location());
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
	fo_h->add(e2_h);
	fo_h->add(e1_h);
  nodestack.push (fo_h);
}

void normalize_visitor::end_visit(const NumericLiteral& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
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

void normalize_visitor::end_visit(const OrExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	Assert(nodestack.size()>=2,"stack underflow");
	rchandle<expr> e1_h = pop_nodestack();
	rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_h = new fo_expr(v.get_location());
	fo_h->set_func(dctx_p->get_function(library::op_or_key));
	fo_h->add(e2_h);
	fo_h->add(e1_h);
  nodestack.push (fo_h);
}

void normalize_visitor::end_visit(const OrderedExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const ParenthesizedExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	expr_t expr = pop_nodestack();
	if (expr != NULL) {
		pop_nodestack();
		nodestack.push(expr);
	} else {
		expr = new empty_expr(v.get_location());
		nodestack.push(expr);
	}
}


void normalize_visitor::end_visit(const QuantifiedExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const QueryBody& v, void *visit_state)
{
cout  << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const RangeExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}


void normalize_visitor::end_visit(const StringLiteral& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	nodestack.push(new literal_expr(v.get_location(),v.get_strval()));
}

void normalize_visitor::end_visit(const TreatExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const TypeswitchExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
	case_clause * cc_p;
	expr_t e_h;
	rchandle<typeswitch_expr> tse_h = new typeswitch_expr(v.get_location());

	rchandle<var_expr> ve_h = new var_expr(v.get_location());
	rchandle<qname_expr> qname = new qname_expr(v.get_default_varname());
	ve_h->set_varname(qname);
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

void normalize_visitor::end_visit(const UnaryExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;

	Assert(nodestack.size()>=2,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << std::string(depth--, ' ') <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << std::string(depth--, ' ') <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const UnionExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;

	//d Assert<normalize_error>(nodestack.size()>=3,"stack underflow");
	Assert(nodestack.size()>=3,"stack underflow");
	rchandle<expr> e1_h = nodestack.top(); nodestack.pop();
	rchandle<expr> e2_h = nodestack.top(); nodestack.pop();
	rchandle<fo_expr> fo_h = dynamic_cast<fo_expr*>(&*nodestack.top());
	if (fo_h==NULL) {
		 cout << std::string(depth--, ' ') <<TRACE << ": expecting fo_expr on top of stack" << endl;
		 cout << std::string(depth--, ' ') <<TRACE << ": typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
}

void normalize_visitor::end_visit(const UnorderedExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const ValidateExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}



/* update-related */
void normalize_visitor::end_visit(const DeleteExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const InsertExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const RenameExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const ReplaceExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const RevalidationDecl& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const TransformExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const VarNameList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}



/* full-text-related */
void normalize_visitor::end_visit(const FTAnd& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTAnyallOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTBigUnit& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTCaseOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTContainsExpr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTContent& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTDiacriticsOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTDistance& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTIgnoreOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTInclExclStringLiteral& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTInclExclStringLiteralList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTLanguageOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTMatchOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTMatchOptionProximityList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTMildnot& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTOptionDecl& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTOr& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTOrderedIndicator& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTProximity& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTRange& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTRefOrList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTScope& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTScoreVar& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTSelection& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTStemOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTStopwordOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTStringLiteralList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTThesaurusID& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTThesaurusList& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTThesaurusOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTTimes& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTUnaryNot& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTUnit& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWildcardOption& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWindow& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWords& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWordsSelection& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

void normalize_visitor::end_visit(const FTWordsValue& v, void *visit_state)
{
cout << std::string(depth--, ' ') << TRACE << endl;
}

} /* namespace xqp */

