/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: translator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "compiler/translator/translator.h"

#include "functions/library.h"
#include "compiler/parsetree/parsenodes.h"
#include "util/tracer.h"
#include "store/api/item.h"
#include "util/zorba.h"
#include "functions/signature.h"

#include <iostream>
#include <string>

using namespace std;

namespace xqp {

static uint32_t depth = 0;

static void *no_state = (void *) new int;

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (sctx_p->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 1))
#define LOOKUP_OP2( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 2))
#define LOOKUP_OP3( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 3))
#define LOOKUP_OPN( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))

#define TRACE_VISIT() cout << std::string(++depth, ' ') << TRACE << endl;
#define TRACE_VISIT_OUT() cout << std::string(depth--, ' ') << TRACE << endl

var_expr *translator::bind_var (yy::location loc, string varname) {
  QNameItem_t qname = sctx_p->lookup_qname ("", varname);
  var_expr *e = new var_expr (loc, qname);
  sctx_p->bind_var (qname, e);
  return e;
}

  fo_expr *translator::create_seq (yy::location loc) {
    fo_expr *e = new fo_expr (loc);
    e->set_func (LOOKUP_OPN ("concatenate"));
    return e;
  }

translator::translator()
{
	zorp = zorba::getZorbaForCurrentThread();
  sctx_p = zorp->get_static_context();
}



void *translator::begin_visit(const parsenode& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const parsenode& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const exprnode& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const exprnode& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ArgList& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ArgList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const AtomicType& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const AtomicType& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const BaseURIDecl& v)
{
  TRACE_VISIT ();
	sctx_p->set_baseuri(v.get_base_uri());
	return NULL;
}

void translator::end_visit(const BaseURIDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const BoundarySpaceDecl& v)
{
  TRACE_VISIT ();
	sctx_p->set_boundary_space_mode(v.get_boundary_space_mode());
	return NULL;
}

void translator::end_visit(const BoundarySpaceDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const CaseClause& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CaseClause& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const CaseClauseList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const CaseClauseList& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ConstructionDecl& v)
{
TRACE_VISIT ();
	sctx_p->set_construction_mode(v.get_mode());
	return NULL;
}

void translator::end_visit(const ConstructionDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const CopyNamespacesDecl& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CopyNamespacesDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(DefaultCollationDecl const& v)
{
TRACE_VISIT ();
	string uri = v.get_collation();
	sctx_p->set_default_collation(uri);
	return NULL;
}

void translator::end_visit(const DefaultCollationDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(DefaultNamespaceDecl const& v)
{
// TODO adapt to new store
// TRACE_VISIT ();
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

void translator::end_visit(const DefaultNamespaceDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const EmptyOrderDecl& v)
{
  TRACE_VISIT ();

	sctx_p->set_order_empty_mode(v.get_mode());
	return no_state;
}

void translator::end_visit(const EmptyOrderDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


/*******************************************************************************

   Enclosed Expr
   Used in direct element/attribute constructors and in function definition.

********************************************************************************/
void *translator::begin_visit(const EnclosedExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const EnclosedExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	expr_t expr_h = pop_nodestack();
	expr_t enclosedExpr = new enclosed_expr(v.get_location(), expr_h);
	nodestack.push(&*enclosedExpr);
  // enclosed_expr gone -- leave expression on the stack
}


/*******************************************************************************

  Direct Node Construction

********************************************************************************/

void *translator::begin_visit(const DirCommentConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void translator::end_visit(const DirCommentConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
    
  xqpString content = v.get_comment();
  
  nodestack.push (new text_expr(v.get_location(),
                                text_expr::comment_constructor,
                                new const_expr (v.get_location (), content)));
}

void *translator::begin_visit(const DirPIConstructor& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const DirPIConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const DirElemConstructor& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const DirElemConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	expr_t attributes = NULL;
	expr_t content = NULL;

	if (v.get_attr_list() != NULL)
		attributes = pop_nodestack();

	if (v.get_dir_content_list() != NULL)
		content = pop_nodestack();

  QNameItem_t item = sctx_p->lookup_elem_qname (v.get_elem_name()->get_prefix(), v.get_elem_name()->get_localname());
	elem_expr *elem_t = new elem_expr(v.get_location(), item, attributes, content);
	nodestack.push(elem_t);
}

void *translator::begin_visit(const DirElemContentList& v)
{
  TRACE_VISIT ();

	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const DirElemContentList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	fo_expr *expr_list_t = create_seq (v.get_location ());
	while (true) 
  {
		expr_t e_h = pop_nodestack();
		if (e_h == NULL)
      break;
		expr_list_t->add(e_h);
	}
  if (expr_list_t->size() == 1)
    nodestack.push(*expr_list_t->begin());
  else
    nodestack.push(&*expr_list_t);
}


void *translator::begin_visit(const DirElemContent& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const DirElemContent& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	if (v.get_direct_cons() != NULL) 
  {
		// nothing to be done, the content expression is already on the stack
	}
  else if (v.get_cdata() != NULL)
  {
	}
  else if (v.get_common_content() != NULL)
  {
	}
  else
  {
		xqpString content = v.get_elem_content();
    nodestack.push (new text_expr(v.get_location(),
                                  text_expr::text_constructor,
                                  new const_expr (v.get_location (), content)));
	}
}


void *translator::begin_visit(const CDataSection& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CDataSection& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const DirAttributeList& v)
{
  TRACE_VISIT ();

	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const DirAttributeList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

 	fo_expr *expr_list_t = create_seq (v.get_location ());
 	while(true)
  {
 		expr_t e_h = pop_nodestack();
 		if (e_h == NULL)
      break;
 		expr_list_t->add(e_h);
 	}
 	nodestack.push(&*expr_list_t);
}


void *translator::begin_visit(const DirAttr& v)
{
  TRACE_VISIT ();
	// boundary is needed because the value of an attribute might be empty
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const DirAttr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

 	expr_t attrValue = pop_nodestack();
 	if (attrValue != NULL)
  {
 		// delete boundary
 		nodestack.pop();
 	}
 
  QNameItem_t item = sctx_p->lookup_elem_qname (v.get_atname()->get_prefix(), v.get_atname()->get_localname());
 	rchandle<attr_expr> attr_expr_t = new attr_expr(v.get_location(),
                                                  item,
                                                  attrValue);
 	nodestack.push(&*attr_expr_t);
}


void *translator::begin_visit(const DirAttributeValue& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const DirAttributeValue& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const QuoteAttrContentList& v)
{
  TRACE_VISIT ();

	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const QuoteAttrContentList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

 	fo_expr *expr_list_t = create_seq (v.get_location ());
  expr_t e_h;
 	while(true)
  {
 		expr_t e_h = pop_nodestack();
 		if (e_h == NULL)
      break;
 		expr_list_t->add(e_h);
 	}

  if (expr_list_t->size() == 1)
    nodestack.push(*expr_list_t->begin());
  else
    nodestack.push(&*expr_list_t);
}


void *translator::begin_visit(const QuoteAttrValueContent& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const QuoteAttrValueContent& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  
	if (v.get_common_content() == NULL)
  {
		xqpString content = v.get_quot_atcontent();
    nodestack.push (new text_expr(v.get_location(),
                                  text_expr::text_constructor,
                                  new const_expr (v.get_location (), content)));
  }
	// nothing to be done because when common content != NULL, 
	// the corresponding expr is already on the stack
}


void *translator::begin_visit(const AposAttrContentList& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const AposAttrContentList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const AposAttrValueContent& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const AposAttrValueContent& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const CommonContent& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CommonContent& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

  Computed Node Construction

********************************************************************************/

void *translator::begin_visit(const CompDocConstructor& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CompDocConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new doc_expr (v.get_location (), pop_nodestack ()));
}

void *translator::begin_visit(const CompElemConstructor& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CompElemConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const CompAttrConstructor& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CompAttrConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const CompCommentConstructor& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CompCommentConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new text_expr (v.get_location (), text_expr::comment_constructor, pop_nodestack ()));
}

void *translator::begin_visit(const CompPIConstructor& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CompPIConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  pi_expr *e;
  if (v.get_target_expr () != NULL) {
    expr_t target = pop_nodestack ();
    expr_t content = pop_nodestack ();
    e = new pi_expr (v.get_location (), target, content);
  } else {
    e = new pi_expr (v.get_location (), v.get_target (), pop_nodestack ());
  }
  nodestack.push (e);
}

void *translator::begin_visit(const CompTextConstructor& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CompTextConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new text_expr (v.get_location (), text_expr::text_constructor, pop_nodestack ()));
}


/*******************************************************************************

  FLWOR Expression

********************************************************************************/
void *translator::begin_visit(const FLWORExpr& v)
{
	TRACE_VISIT ();
  return no_state;
}

void translator::end_visit(const FLWORExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  int i, j;

  flwor_expr *flwor = new flwor_expr (v.get_location ());
  flwor->set_retval (pop_nodestack ());
  OrderByClause *orderby = &*v.get_orderby ();
  if (orderby) {
    flwor->set_order_stable (orderby->get_stable_bit ());
    OrderSpecList *order_list = &*orderby->get_spec_list ();
    int n = order_list->size ();
    for (i = 0; i < n; i++) {
      OrderSpec *spec = &*((*order_list) [i]);
      OrderModifier *mod = &*spec->get_modifier ();
      dir_spec_t dir_spec = dir_descending;
      if (mod && mod->get_dir_spec () != NULL)
        dir_spec = mod->get_dir_spec ()->get_dir_spec ();
      StaticQueryContext::order_empty_mode_t empty_spec = sctx_p->order_empty_mode ();
      if (mod && mod->get_empty_spec () != NULL)
        empty_spec = mod->get_empty_spec ()->get_empty_order_spec ();
      string col = sctx_p->default_collation ();
      if (mod && mod->get_collation_spec () != NULL)
        col = mod->get_collation_spec ()->get_uri ();
      rchandle<order_modifier> emod (new order_modifier (dir_spec, empty_spec, col));
      flwor->add (flwor_expr::orderspec_t (pop_nodestack (), emod));
    }
  }
  if (v.get_where () != NULL)
    flwor->set_where (pop_nodestack ());
  ForLetClauseList *clauses = v.get_forlet_list ().get_ptr ();
  vector <forlet_clause *> eclauses;

  for (i = clauses->size () - 1; i >= 0; i--) {
    ForOrLetClause *clause = (*clauses) [i].get_ptr ();
    vector<rchandle <var_expr> > vars;
    vector<rchandle <var_expr> > pos_vars;
    vector<rchandle <expr> > exprs;
    int size = clause->get_decl_count ();

    if (clause->for_or_let () == ForOrLetClause::for_clause) {
      ForClause *forclause = static_cast<ForClause *> (clause);
      VarInDeclList *decl_list = &*forclause->get_vardecl_list ();

      for (j = 0; j < size; j++) {
        rchandle<var_expr> ve;
        exprs.push_back(pop_nodestack ());
        if ((*decl_list) [j]->get_posvar () == NULL)
          pos_vars.push_back (NULL);
        else {
          rchandle<var_expr> pve = pop_nodestack ().cast<var_expr> ();
          pve->set_kind (var_expr::pos_var);
          pos_vars.push_back (pve);
        }
        ve = pop_nodestack ().cast<var_expr> ();
        ve->set_kind (var_expr::for_var);
        vars.push_back (ve);
        pop_scope ();
      }

      for (j = 0; j < size; j++) {
        forlet_clause *flc = new forlet_clause (forlet_clause::for_clause, vars [j], pos_vars [j], NULL, exprs [j]);
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


void *translator::begin_visit(const ForLetClauseList& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ForLetClauseList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const LetClause& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const LetClause& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const VarGetsDeclList& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const VarGetsDeclList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const VarGetsDecl& v)
{
  TRACE_VISIT ();
  push_scope ();
  nodestack.push (bind_var (v.get_location (), v.get_varname ()));
	return no_state;
}

void translator::end_visit(const VarGetsDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ForClause& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ForClause& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const VarInDeclList& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const VarInDeclList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const VarInDecl& v)
{
  TRACE_VISIT ();
  push_scope ();
  nodestack.push (bind_var (v.get_location (), v.get_varname ()));
	return no_state;
}

void translator::end_visit(const VarInDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const PositionalVar& v)
{
  TRACE_VISIT ();
  nodestack.push (bind_var (v.get_location (), v.get_varname ()));
	return no_state;
}

void translator::end_visit(const PositionalVar& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const WhereClause& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const WhereClause& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const OrderByClause& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrderByClause& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const OrderSpecList& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrderSpecList& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const OrderSpec& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrderSpec& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const OrderModifier& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrderModifier& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const OrderCollationSpec& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrderCollationSpec& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const OrderDirSpec& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrderDirSpec& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const OrderEmptySpec& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrderEmptySpec& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/

void *translator::begin_visit(const VarDecl& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const VarDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const FunctionDecl& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FunctionDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const GeneralComp& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const GeneralComp& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ItemType& v)
{
  TRACE_VISIT ();
  return no_state;
}

void translator::end_visit(const ItemType& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const LibraryModule& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const LibraryModule& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const MainModule & v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const MainModule & v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const Module& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const Module& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ModuleDecl& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ModuleDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ModuleImport& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ModuleImport& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const NamespaceDecl& v)
{
  TRACE_VISIT ();
  sctx_p->bind_ns (v.get_prefix (), v.get_uri ());
	return NULL;
}

void translator::end_visit(const NamespaceDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const NodeComp& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const NodeComp& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const OccurrenceIndicator& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OccurrenceIndicator& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const OptionDecl& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OptionDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const OrderingModeDecl& v)
{
TRACE_VISIT ();
//daniel	zorp->get_dynamic_context()->set_ordering_mode(v.get_mode());
	sctx_p->set_ordering_mode(v.get_mode());
	return NULL;
}


void translator::end_visit(const OrderingModeDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const Param& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const Param& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ParamList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const ParamList& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const Pragma& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const Pragma& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const PragmaList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const PragmaList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const PredicateList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const PredicateList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
	clear_pstack();
	while (true) {
		expr_t e_h = pop_nodestack();
		if (e_h==NULL) break;
		pstack.push(e_h);
	}
}

void *translator::begin_visit(const Prolog& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const Prolog& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const QVarInDecl& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const QVarInDecl& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const QVarInDeclList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const QVarInDeclList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const SIND_DeclList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const SIND_DeclList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const SchemaImport& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const SchemaImport& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const SchemaPrefix& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const SchemaPrefix& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const SequenceType& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const SequenceType& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const SignList& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const SignList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const SingleType& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const SingleType& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const TypeDeclaration& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const TypeDeclaration& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const TypeName& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const TypeName& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const URILiteralList& v)
{
  TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const URILiteralList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ValueComp& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ValueComp& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const VersionDecl& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const VersionDecl& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const VFO_DeclList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const VFO_DeclList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const AdditiveExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const AdditiveExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	rchandle<expr> e1_h = pop_nodestack();
	rchandle<expr> e2_h = pop_nodestack();
	fo_expr *fo_h = new fo_expr(v.get_location());
	switch (v.get_add_op()) {
	case op_plus:
		fo_h->set_func(LOOKUP_OP2 ("add"));
		break;
	case op_minus:
		fo_h->set_func(LOOKUP_OP2 ("subtract"));
		break;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
  nodestack.push (fo_h);
}


void *translator::begin_visit(const AndExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const AndExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	rchandle<expr> e1_h = pop_nodestack();
	rchandle<expr> e2_h = pop_nodestack();
	fo_expr *fo_h = new fo_expr(v.get_location());
	fo_h->set_func(LOOKUP_OP2 ("and"));
	fo_h->add(e2_h);
	fo_h->add(e1_h);
  nodestack.push (fo_h);
}


void *translator::begin_visit(const CastExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CastExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}



void *translator::begin_visit(const CastableExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const CastableExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ComparisonExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ComparisonExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	fo_expr *fo_p = new fo_expr(v.get_location());

	if (v.get_gencomp()!=NULL) {
		switch (v.get_gencomp()->get_type()) {
		case op_eq:
			fo_p->set_func(LOOKUP_OP2 ("equal"));
			break;
		case op_ne:
			fo_p->set_func(LOOKUP_OP2 ("not-equal"));
			break;
		case op_lt:
			fo_p->set_func(LOOKUP_OP2 ("less"));
			break;
		case op_le:
			fo_p->set_func(LOOKUP_OP2 ("less-equal"));
			break;
		case op_gt:
			fo_p->set_func(LOOKUP_OP2 ("greater"));
			break;
		case op_ge:
			fo_p->set_func(LOOKUP_OP2 ("greater-equal"));
			break;
		}
	} else if (v.get_valcomp () != NULL) {
		switch (v.get_valcomp()->get_type()) {
		case op_val_eq:
			fo_p->set_func(LOOKUP_OP2 ("value-equal"));
			break;
		case op_val_ne:
			fo_p->set_func(LOOKUP_OP2 ("value-not-equal"));
			break;
		case op_val_lt:
			fo_p->set_func(LOOKUP_OP2 ("value-less"));
			break;
		case op_val_le:
			fo_p->set_func(LOOKUP_OP2 ("value-less-equal"));
			break;
		case op_val_gt:
			fo_p->set_func(LOOKUP_OP2 ("value-greater"));
			break;
		case op_val_ge:
			fo_p->set_func(LOOKUP_OP2 ("value-greater-equal"));
			break;
		}
	} else if (v.get_nodecomp()!=NULL) {
		switch (v.get_nodecomp()->get_type()) {
		case op_is:
			fo_p->set_func(LOOKUP_OP2 ("is"));
			break;
		case op_precedes:
			fo_p->set_func(LOOKUP_OP2 ("precedes"));
			break;
		case op_follows:
			fo_p->set_func(LOOKUP_OP2 ("follows"));
			break;
		}
	}

	rchandle<expr> e1_h = pop_nodestack();
	rchandle<expr> e2_h = pop_nodestack();;
	fo_p->add(e2_h);
	fo_p->add(e1_h);
	nodestack.push(fo_p);
}



void *translator::begin_visit(const ContextItemExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ContextItemExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	rchandle<var_expr> v_h = new var_expr(v.get_location(), NULL);
	v_h->set_kind(var_expr::context_var);
	nodestack.push(&*v_h);
}


void *translator::begin_visit(const Expr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const Expr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  
  if (v.numberOfChildren () > 1) {
    fo_expr *elist_h = create_seq (v.get_location());
    for (int i = 0; i < v.numberOfChildren (); i++) {
      expr_t e_h = pop_nodestack();
      elist_h->add(e_h);
    }
		nodestack.push(&*elist_h);
	}
}

// void *translator::begin_visit(const ExprSingle& v)
// {
// TRACE_VISIT ();
//  return no_state;
// }

void *translator::begin_visit(const ExtensionExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ExtensionExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FilterExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FilterExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FunctionCall& v)
{
  TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const FunctionCall& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	std::vector<expr_t> arguments;
	while (true) {
		expr_t e_h = pop_nodestack();
		if (e_h == NULL)
			break;
		arguments.push_back(e_h);
	}
  
	rchandle<QName> qn_h = v.get_fname();
	string prefix = qn_h->get_prefix();
	string fname = qn_h->get_localname();

	rchandle<fo_expr> fo_h = new fo_expr(v.get_location());
  fo_h->set_func(LOOKUP_FN(prefix, fname, v.get_arg_list ()->size ()));
	
	// TODO this should be a const iterator
	std::vector<expr_t>::reverse_iterator iter = arguments.rbegin();
	for(; iter != arguments.rend(); ++iter) {
		fo_h->add(*iter);
	}

	nodestack.push(&*fo_h);
}

void *translator::begin_visit(const IfExpr& v)
{
TRACE_VISIT ();
	// nothing to do here
	return no_state;
}

void translator::end_visit(const IfExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
	expr_t e_h = pop_nodestack ();
	expr_t t_h = pop_nodestack ();
	expr_t c_h = pop_nodestack ();
	rchandle<if_expr> if_h = new if_expr(v.get_location(),c_h,t_h,e_h);
	nodestack.push(&*if_h);
}


void *translator::begin_visit(const InstanceofExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const InstanceofExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const IntersectExceptExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const IntersectExceptExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	rchandle<expr> e1_h = pop_nodestack ();
	rchandle<expr> e2_h = pop_nodestack ();
	fo_expr *fo_h = new fo_expr(v.get_location());

	switch (v.get_intex_op()) {
	case op_intersect:
		fo_h->set_func(LOOKUP_OP2 ("intersect"));
		break;
	case op_except:
		fo_h->set_func(LOOKUP_OP2 ("except"));
		break;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
	nodestack.push(fo_h);
}

void *translator::begin_visit(const MultiplicativeExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const MultiplicativeExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	rchandle<expr> e1_h = pop_nodestack ();
	rchandle<expr> e2_h = pop_nodestack ();
	fo_expr *fo_h = new fo_expr(v.get_location());
	switch (v.get_mult_op()) {
	case op_mul:
		fo_h->set_func(LOOKUP_OP2 ("multiply"));
		break;
	case op_div:
		fo_h->set_func(LOOKUP_OP2 ("divide"));
		break;
	case op_idiv:
		fo_h->set_func(LOOKUP_OP2 ("integer-divide"));
		break;
	case op_mod:
		fo_h->set_func(LOOKUP_OP2 ("mod"));
		break;
	}
	fo_h->add(e2_h);
	fo_h->add(e1_h);
  nodestack.push (fo_h);
}

void *translator::begin_visit(const NumericLiteral& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const NumericLiteral& v, void *visit_state)
{
TRACE_VISIT_OUT ();
	switch (v.get_type()) {
	case num_integer: {
		nodestack.push(new const_expr(v.get_location(), (xqp_integer) v.get_int()));
		break;
	}
	case num_decimal: {
		nodestack.push(new const_expr(v.get_location(), (xqp_decimal) v.get_decimal()));
		break;
	}
	case num_double: {
		nodestack.push(new const_expr(v.get_location(), (xqp_double) v.get_double()));
		break;
	}
	}
}

void *translator::begin_visit(const OrExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	rchandle<expr> e1_h = pop_nodestack();
	rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_p = new fo_expr(v.get_location());
	fo_p->set_func(LOOKUP_OP2 ("or"));
	fo_p->add(e2_h);
	fo_p->add(e1_h);
  nodestack.push (fo_p);
}

void *translator::begin_visit(const OrderedExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const OrderedExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new order_expr (v.get_location (), order_expr::ordered, 
                                  pop_nodestack ()));
}


void *translator::begin_visit(const ParenthesizedExpr& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const ParenthesizedExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	expr_t expr = pop_nodestack();
	if (expr != NULL) {
		pop_nodestack();
		nodestack.push(expr);
	} else {
		nodestack.push(create_seq (v.get_location ()));
	}
}


/*******************************************************************************

  NodeTest (NameTest | KindTest)

********************************************************************************/
void *translator::begin_visit(const NameTest& v)
{
  TRACE_VISIT ();
	return no_state;
}



void translator::end_visit(const NameTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	// Find axis step on top of stack
	rchandle<axis_step_expr> axisExpr = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (axisExpr == NULL)
  {
    TRACE_VISIT_OUT ();
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	// Construct name-test match expr
  rchandle<match_expr> matchExpr = new match_expr(v.get_location());;
  matchExpr->setTestKind(match_name_test);

  if (v.getQName() != NULL)
  {
    string qname = v.getQName()->get_qname();
    QNameItem_t qn_h = sctx_p->lookup_elem_qname (qname);
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


void *translator::begin_visit(const Wildcard& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const Wildcard& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const AnyKindTest& v)
{
  TRACE_VISIT ();
	// no action needed here
	return no_state;
}


void translator::end_visit(const AnyKindTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
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


void *translator::begin_visit(const DocumentTest& v)
{
  TRACE_VISIT ();

	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_doc_test);

	rchandle<ElementTest> e_h = v.get_elem_test();
	if (e_h != NULL)
  {
		rchandle<QName> elem_h = e_h->getElementName();
		if (elem_h != NULL)
    {
			m_h->setQName (sctx_p->lookup_elem_qname (elem_h->get_prefix(), elem_h->get_localname()));
		}
		rchandle<TypeName> type_h = e_h->getTypeName();
		if (type_h != NULL)
    {
			m_h->setTypeName (sctx_p->lookup_qname ("", type_h->get_name()->get_qname()));
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


void translator::end_visit(const DocumentTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ElementTest& v)
{
	TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const ElementTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  v.getElementName()->put(cout)<<")\n";

	// find axis step expression on top of stack
	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
    cout << std::string(depth, ' ') << TRACE
         << ": expecting axis_step_expr on top of stack" << endl;
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	// construct the element match
	rchandle<match_expr> me = new match_expr(v.get_location());
	me->setTestKind(match_elem_test);

	rchandle<QName> ename = v.getElementName();
	if (ename != NULL)
		me->setQName(sctx_p->lookup_elem_qname (ename->get_qname()));

	rchandle<TypeName> tname = v.getTypeName();
	if (tname != NULL)
		me->setTypeName(sctx_p->lookup_elem_qname (tname->get_name()->get_qname()));

	bool nilled =  v.isNilledAllowed();
	if (nilled)
    me->setNilledAllowed(true);

	// add the match expression
	ase->setTest(me);
}


void *translator::begin_visit(const AttributeTest& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const AttributeTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	// find axis step expression on top of stack
	rchandle<axis_step_expr> ase_h = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h == NULL)
  {
    TRACE_VISIT_OUT ();
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
		m_h->setQName(sctx_p->lookup_elem_qname (elem_h->get_qname()));
	}
	rchandle<TypeName> type_h = v.get_type();
	if (type_h!=NULL)
  {
		m_h->setTypeName(sctx_p->lookup_qname ("", type_h->get_name()->get_qname()));
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


void *translator::begin_visit(const TextTest& v)
{
  TRACE_VISIT ();
	// no action needed here
	return no_state;
}


void translator::end_visit(const TextTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	rchandle<axis_step_expr> ase_h = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h == NULL)
  {
		TRACE_VISIT_OUT ();
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_text_test);
	ase_h->setTest(m_h);
}


void *translator::begin_visit(const CommentTest& v)
{
  TRACE_VISIT ();
	// no action needed here
	return no_state;
}


void translator::end_visit(const CommentTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	rchandle<axis_step_expr> ase_h = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase_h == NULL)
  {
    TRACE_VISIT_OUT ();
		cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
	}

	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_comment_test);
	ase_h->setTest(m_h);
}


void *translator::begin_visit(const PITest& v)
{
  TRACE_VISIT ();

	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_pi_test);

	string target = v.get_target();
	m_h->setQName(sctx_p->lookup_elem_qname (target));
	nodestack.push(&*m_h);
	return no_state;
}


void translator::end_visit(const PITest& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const SchemaAttributeTest& v)
{
  TRACE_VISIT ();
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_xs_attr_test);

	rchandle<QName> attr_h = v.get_attr();
	if (attr_h!=NULL) {
		m_h->setQName(sctx_p->lookup_elem_qname (attr_h->get_qname()));
	}
	nodestack.push(&*m_h);
	return no_state;
}


void translator::end_visit(const SchemaAttributeTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const SchemaElementTest& v)
{
  TRACE_VISIT ();
	rchandle<match_expr> m_h = new match_expr(v.get_location());
	m_h->setTestKind(match_xs_elem_test);

	rchandle<QName> elem_h = v.get_elem();
	if (elem_h!=NULL) {
		m_h->setQName (sctx_p->lookup_qname ("", elem_h->get_qname()));
	}
	nodestack.push(&*m_h);
	return no_state;
}


void translator::end_visit(const SchemaElementTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
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
void *translator::begin_visit(const PathExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const PathExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  // Create fn:root(self::node()) expr
  rchandle<match_expr> me = new match_expr(v.get_location());
  me->setTestKind(match_anykind_test);

  rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
  ase->setAxis(axis_kind_self);
  ase->setTest(me);
 
  rchandle<fo_expr> fo = new fo_expr(v.get_location());
  fo->set_func(LOOKUP_FN("fn", "root", 1));
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


void *translator::begin_visit(const RelativePathExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const RelativePathExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

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


void *translator::begin_visit(const AxisStep& v)
{
  TRACE_VISIT ();

	rchandle<axis_step_expr> aexpr_h = new axis_step_expr(v.get_location());
	nodestack.push(&*aexpr_h);
	return no_state;
}


void translator::end_visit(const AxisStep& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
		 TRACE_VISIT_OUT ();
		 TRACE_VISIT_OUT ();
	}

	while (!pstack.empty())
  {
		expr_t e = pstack.top();
		pstack.pop();
		ase->addPred(e);
	}
}


void *translator::begin_visit(const ForwardStep& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const ForwardStep& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const AbbrevForwardStep& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const AbbrevForwardStep& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

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


void *translator::begin_visit(const ForwardAxis& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const ForwardAxis& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
    TRACE_VISIT_OUT ();
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


void *translator::begin_visit(const ReverseStep& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const ReverseStep& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const ReverseAxis& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const ReverseAxis& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	rchandle<axis_step_expr> ase = dynamic_cast<axis_step_expr*>(&*nodestack.top());
	if (ase == NULL)
  {
    TRACE_VISIT_OUT ();
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
void *translator::begin_visit(const QuantifiedExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}


void translator::end_visit(const QuantifiedExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/
void *translator::begin_visit(const QueryBody& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const QueryBody& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/
void *translator::begin_visit(const RangeExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const RangeExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const StringLiteral& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const StringLiteral& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	nodestack.push(new const_expr(v.get_location(),v.get_strval()));
}

void *translator::begin_visit(const TreatExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const TreatExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const TypeswitchExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const TypeswitchExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	case_clause * cc_p;
	expr_t e_h;
	rchandle<typeswitch_expr> tse_h = new typeswitch_expr(v.get_location());

	rchandle<var_expr> ve_h = bind_var (v.get_location(), v.get_default_varname());
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


void *translator::begin_visit(const UnaryExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const UnaryExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	rchandle<expr> e1_h = pop_nodestack ();
	fo_expr *fo_p = new fo_expr(v.get_location());
	fo_p->add(e1_h);
	if (v.get_signlist()->get_sign())
		fo_p->set_func(LOOKUP_OP1 ("unary-plus"));
	else
		fo_p->set_func(LOOKUP_OP1 ("unary-minus"));
	nodestack.push(fo_p);
}

void *translator::begin_visit(const UnionExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const UnionExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

	rchandle<expr> e1_h = pop_nodestack ();
	rchandle<expr> e2_h = pop_nodestack ();
	fo_expr *fo_h = new fo_expr(v.get_location());
	fo_h->set_func(LOOKUP_OP2 ("union"));
	fo_h->add(e2_h);
	fo_h->add(e1_h);
	nodestack.push(fo_h);
}

void *translator::begin_visit(const UnorderedExpr& v)
{
  TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const UnorderedExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new order_expr (v.get_location (), order_expr::unordered, 
                                  pop_nodestack ()));
}

void *translator::begin_visit(const ValidateExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ValidateExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const VarRef& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const VarRef& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
	var_expr *e = static_cast<var_expr *> (sctx_p->lookup_var (v.get_varname ()));
  if (e == NULL)
    cout << "Variable " << v.get_varname () << " not found!\n";
  Assert (e != NULL);
	nodestack.push (rchandle<expr> (e));
}


/* update-related */
void *translator::begin_visit(const DeleteExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const DeleteExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const InsertExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const InsertExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const RenameExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const RenameExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const ReplaceExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const ReplaceExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const RevalidationDecl& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const RevalidationDecl& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const TransformExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const TransformExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const VarNameList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const VarNameList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


/* full-text-related */
void *translator::begin_visit(const FTAnd& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTAnd& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTAnyallOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTAnyallOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTBigUnit& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTBigUnit& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTCaseOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTCaseOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTContainsExpr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTContainsExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTContent& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTContent& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTDiacriticsOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTDiacriticsOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTDistance& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTDistance& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTIgnoreOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTIgnoreOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTInclExclStringLiteral& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTInclExclStringLiteral& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTInclExclStringLiteralList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const FTInclExclStringLiteralList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTLanguageOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTLanguageOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTMatchOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTMatchOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


void *translator::begin_visit(const FTMatchOptionProximityList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const FTMatchOptionProximityList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTMildnot& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTMildnot& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTOptionDecl& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTOptionDecl& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTOr& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTOr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTOrderedIndicator& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTOrderedIndicator& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTProximity& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTProximity& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTRange& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTRange& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTRefOrList& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTRefOrList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTScope& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTScope& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTScoreVar& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTScoreVar& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTSelection& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTSelection& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTStemOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTStemOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTStopwordOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTStopwordOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTStringLiteralList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const FTStringLiteralList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTThesaurusID& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTThesaurusID& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTThesaurusList& v)
{
TRACE_VISIT ();
	nodestack.push(NULL);
	return no_state;
}

void translator::end_visit(const FTThesaurusList& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTThesaurusOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTThesaurusOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTTimes& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTTimes& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTUnaryNot& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTUnaryNot& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTUnit& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTUnit& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTWildcardOption& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTWildcardOption& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTWindow& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTWindow& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTWords& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTWords& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTWordsSelection& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTWordsSelection& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *translator::begin_visit(const FTWordsValue& v)
{
TRACE_VISIT ();
	return no_state;
}

void translator::end_visit(const FTWordsValue& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}


} /* namespace xqp */

