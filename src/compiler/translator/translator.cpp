/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: translator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "compiler/translator/translator.h"

#include "zorba/common.h"

#include "functions/library.h"
#include "compiler/parsetree/parsenodes.h"
#include "util/tracer.h"
#include "store/api/item.h"
#include "system/zorba.h"
#include "util/utf8/Unicode_util.h"
#include "functions/signature.h"
#include "system/zorba_engine.h"

#ifndef NDEBUG
# include "zorba/util/properties.h"
#endif

#include <string>
#include <stack>
#include <sstream>


using namespace std;

namespace xqp {

static void *no_state = (void *) new int;

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (sctx_p->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 1))
#define LOOKUP_OP2( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 2))
#define LOOKUP_OP3( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 3))
#define LOOKUP_OPN( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))

#ifndef NDEBUG
# define TRACE_VISIT() if (Properties::instance()->traceTranslator()) cerr << std::string(++depth, ' ') << TRACE << endl;
# define TRACE_VISIT_OUT() if (Properties::instance()->traceTranslator()) cerr << std::string(depth--, ' ') << TRACE << endl
#else
# define TRACE_VISIT()
# define TRACE_VISIT_OUT()
#endif

#define DOT_VAR "$$dot"
#define DOT_POS_VAR "$$pos"
#define LAST_IDX_VAR "$$last-idx"


class TranslatorImpl : public Translator 
{
public:
  typedef rchandle<expr> expr_t;
  typedef rchandle<var_expr> var_expr_t;
  typedef std::pair<var_expr_t, expr_t> global_binding;

  friend Translator *make_translator (static_context *);

protected:
  uint32_t                         depth;

  static_context                 * sctx_p;
  std::stack<expr_t>               nodestack;
  std::stack<TypeSystem::xqtref_t> tstack;  // types stack
  int                              tempvar_counter;
  std::list<global_binding>        global_vars;
  const RelativePathExpr         * theRootRelPathExpr;

  TranslatorImpl (static_context *sctx_p_)
    :
    depth (0), sctx_p (sctx_p_), tempvar_counter (0), theRootRelPathExpr(0)
  {
    yy::location loc;
    var_expr *ctx_var = bind_var(loc, DOT_VAR, var_expr::context_var);
  }


  expr_t pop_nodestack() 
  {
    ZORBA_ASSERT (! nodestack.empty());
    rchandle<expr> e_h = nodestack.top();
    nodestack.pop();
    return e_h;
  }

  TypeSystem::xqtref_t pop_tstack() 
  {
    ZORBA_ASSERT (! tstack.empty());
    TypeSystem::xqtref_t e_h = tstack.top();
    tstack.pop();
    return e_h;
  }

  var_expr *bind_var (yy::location loc, string varname, var_expr::var_kind kind)
  {
    Item_t qname = sctx_p->lookup_qname ("", varname);
    var_expr *e = new var_expr (loc, kind, qname);
    sctx_p->bind_var (qname, e);
    return e;
  }
  
  fo_expr *create_seq (yy::location loc) {
    fo_expr *e = new fo_expr (loc, LOOKUP_OPN ("concatenate"));
    return e;
  }

  void push_scope ()
  {
    sctx_p = new static_context (sctx_p);
  }

  void pop_scope (int n = 1)
  { 
    while (n-- > 0) {
      static_context *parent = (static_context *) sctx_p->get_parent ();
      delete sctx_p;
      sctx_p = parent;
    }
  }

  rchandle<axis_step_expr> expect_axis_step_top () {
    rchandle<axis_step_expr> axisExpr = dynamic_cast<axis_step_expr*>(&*nodestack.top());
    if (axisExpr == NULL) {
      cout << "Expecting axis step on top of stack; ";
      if (nodestack.top() != NULL)
        cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
      else
        cout << "top is null\n";
      ZORBA_ASSERT (false);
    }
    return axisExpr;
  }

public:

  expr_t result () {
    return pop_nodestack ();
  }

void *begin_visit(const parsenode& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const parsenode& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const exprnode& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const exprnode& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const ArgList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ArgList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const AtomicType& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AtomicType& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  rchandle<QName> qname = v.get_qname ();
  TypeSystem::xqtref_t t =
    GENV_TYPESYSTEM.create_type (sctx_p->lookup_qname ("", qname->get_prefix (), qname->get_localname ()),
                                 TypeSystem::QUANT_ONE);
  if (t == NULL)
    ZORBA_ERROR_ALERT (AlertCodes::XPST0051, NULL);
  else
    tstack.push (t);
}


void *begin_visit(const BaseURIDecl& v)
{
  TRACE_VISIT ();
  sctx_p->set_baseuri(v.get_base_uri());
  return NULL;
}

void end_visit(const BaseURIDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const BoundarySpaceDecl& v)
{
  TRACE_VISIT ();
  sctx_p->set_boundary_space_mode(v.get_boundary_space_mode());
  return NULL;
}

void end_visit(const BoundarySpaceDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const CaseClause& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CaseClause& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const CaseClauseList& v)
{
TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const CaseClauseList& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const ConstructionDecl& v)
{
TRACE_VISIT ();
  sctx_p->set_construction_mode(v.get_mode());
  return NULL;
}

void end_visit(const ConstructionDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const CopyNamespacesDecl& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const CopyNamespacesDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(DefaultCollationDecl const& v)
{
TRACE_VISIT ();
  string uri = v.get_collation();
  sctx_p->set_default_collation_uri(uri);
  return NULL;
}

void end_visit(const DefaultCollationDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(DefaultNamespaceDecl const& v)
{
  TRACE_VISIT ();
// TODO adapt to new store
//  switch (v.get_mode()) {
//  case ns_element_default: {
//    namespace_node* ns_p = new dom_namespace_node("#elem#",v.get_default_namespace());
//    zorp->get_dynamic_context()->set_default_element_type_namespace(*ns_p);
//    break;
//  }
//  case ns_function_default: {
//    namespace_node* ns_p = new dom_namespace_node("#func#",v.get_default_namespace());
//    sctx_p->set_default_function_namespace(ns_p);
//    break;
//  }}
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

void end_visit(const DefaultNamespaceDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const EmptyOrderDecl& v)
{
  TRACE_VISIT ();

  sctx_p->set_order_empty_mode(v.get_mode());
  return no_state;
}

void end_visit(const EmptyOrderDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


/*******************************************************************************

   Enclosed Expr
   Used in direct element/attribute constructors and in function definition.

********************************************************************************/
void *begin_visit(const EnclosedExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const EnclosedExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  
  expr_t lContent = pop_nodestack();
  fo_expr *fo_h = new fo_expr(v.get_location(), LOOKUP_OP1 ("enclosed-expr"));
  fo_h->add(lContent);
  nodestack.push(fo_h);
}


/*******************************************************************************

  Direct Node Construction

********************************************************************************/

void *begin_visit(const DirCommentConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DirCommentConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
    
  xqpString content = v.get_comment();
  
  nodestack.push (new text_expr(v.get_location(),
                                text_expr::comment_constructor,
                                new const_expr (v.get_location (), content)));
}

void *begin_visit(const DirPIConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DirPIConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const DirElemConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DirElemConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  expr_t attributes = NULL;
  expr_t content = NULL;

  if (v.get_dir_content_list() != NULL) {
    content = pop_nodestack();
    fo_expr *lDocFilter = new fo_expr(v.get_location(), LOOKUP_OP1 ("doc-filter"));
    lDocFilter->add(content);
    content = lDocFilter;
  }
  
  if (v.get_attr_list() != NULL)
    attributes = pop_nodestack();

  expr_t lQNameExpr =  new const_expr (
                                        v.get_location (), 
                                        v.get_elem_name()->get_uri().c_str(), 
                                        v.get_elem_name()->get_prefix().c_str(), 
                                        v.get_elem_name()->get_localname().c_str()
                                      );
  elem_expr *elem_t = new elem_expr(v.get_location(), lQNameExpr, attributes, content);
  nodestack.push(elem_t);
}

void *begin_visit(const DirElemContentList& v)
{
  TRACE_VISIT ();

  nodestack.push(NULL);
  return no_state;
}

void end_visit(const DirElemContentList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  fo_expr *expr_list = create_seq (v.get_location ());
  while (true) 
  {
    expr_t e_h = pop_nodestack();
    if (e_h == NULL)
      break;
    expr_list->add(e_h);
  }
  if (expr_list->size() == 1)
  {
    nodestack.push(*expr_list->begin());
    delete expr_list;
  }
  else
  {
    nodestack.push(expr_list);
  }
}


void *begin_visit(const DirElemContent& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DirElemContent& v, void *visit_state)
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


void *begin_visit(const CDataSection& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CDataSection& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const DirAttributeList& v)
{
  TRACE_VISIT ();

  nodestack.push(NULL);
  return no_state;
}

void end_visit(const DirAttributeList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  fo_expr *expr_list = create_seq (v.get_location ());
  while(true)
  {
    expr_t e_h = pop_nodestack();
    if (e_h == NULL)
      break;
    expr_list->add(e_h);
  }
  if (expr_list->size() == 1)
  {
    nodestack.push(*expr_list->begin());
    delete expr_list;
  }
  else
  {
    nodestack.push(expr_list);
  }
}


void *begin_visit(const DirAttr& v)
{
  TRACE_VISIT ();
  // boundary is needed because the value of an attribute might be empty
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const DirAttr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  expr_t attrValue = pop_nodestack();
  if (attrValue != NULL)
  {
    // delete boundary
    nodestack.pop();
  }

  expr_t lQNameExpr = new const_expr(
                                  v.get_location(),
                                  v.get_atname()->get_uri().c_str(),
                                  v.get_atname()->get_prefix().c_str(),
                                  v.get_atname()->get_localname().c_str()
                                );
  
  rchandle<attr_expr> attr_expr_t = new attr_expr(v.get_location(),
                                                  lQNameExpr,
                                                  attrValue);
  nodestack.push(&*attr_expr_t);
}


void *begin_visit(const DirAttributeValue& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DirAttributeValue& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const QuoteAttrContentList& v)
{
  TRACE_VISIT ();

  nodestack.push(NULL);
  return no_state;
}

void end_visit(const QuoteAttrContentList& v, void *visit_state)
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


void *begin_visit(const QuoteAttrValueContent& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const QuoteAttrValueContent& v, void *visit_state)
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


void *begin_visit(const AposAttrContentList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AposAttrContentList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const AposAttrValueContent& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AposAttrValueContent& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const CommonContent& v)
{
  TRACE_VISIT ();
  
  return no_state;
}

void end_visit(const CommonContent& v, void *visit_state)
{
  switch (v.get_type())
  {
    case cont_entity:
    {
      break;
    }
    case cont_charref:
    {
      // &#xFF; or &#255;
      unsigned int codepoint;
      xqp_string charref;
      stringstream ss;

      if (v.get_ref()[2] == 'x')
        ss << hex << v.get_ref().substr(3, v.get_ref().size()-3);
      else
        ss << v.get_ref().substr(2, v.get_ref().size()-2);
      
      ss >> codepoint;
      charref = codepoint;
      
      Item_t lItem = Store::getInstance().getItemFactory().createTextNode(charref, false);
      const_expr *lConstExpr = new const_expr(v.get_location(), lItem);
      nodestack.push ( lConstExpr );
      break;
    }
    case cont_escape_lbrace:
    {
      // we always create a text node here because if we are in an attribute, we atomice
      // the text node into its string value
      Item_t lItem = Store::getInstance().getItemFactory().createTextNode("{", false);
      const_expr *lConstExpr = new const_expr(v.get_location(), lItem);
      nodestack.push ( lConstExpr );
      break;
    }
    case cont_escape_rbrace:
    {
      // we always create a text node here because if we are in an attribute, we atomice
      // the text node into its string value
      Item_t lItem = Store::getInstance().getItemFactory().createTextNode("}", false);
      const_expr *lConstExpr = new const_expr(v.get_location(), lItem);
      nodestack.push ( lConstExpr );
      break;
    }
    case cont_expr:
    {
       break;
    }
  }
  TRACE_VISIT_OUT ();
}

void *begin_visit(const CompDocConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompDocConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  
  expr_t lContent = pop_nodestack();
  
  fo_expr *lDocFilter = new fo_expr(v.get_location(), LOOKUP_OP1("doc-filter"));
  lDocFilter->add(lContent);
  
  fo_expr *lEnclosed = new fo_expr(v.get_location(), LOOKUP_OP1("enclosed-expr"));
  lEnclosed->add(lDocFilter);
  
  nodestack.push (new doc_expr (v.get_location (), lEnclosed ));
}

void *begin_visit(const CompElemConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompElemConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  
  expr_t lContent = 0;
  expr_t lElem = 0;

  if (v.get_content_expr() != 0) {
    lContent = pop_nodestack();
    
    fo_expr *lDocFilter = new fo_expr(v.get_location(), LOOKUP_OP1 ("doc-filter"));
    lDocFilter->add(lContent);
    
    fo_expr *lEnclosed = new fo_expr(v.get_location(), LOOKUP_OP1 ("enclosed-expr"));
    lEnclosed->add(lDocFilter);
    lContent = lEnclosed;
  }
  
  expr_t lQNameExpr = pop_nodestack();
  lElem = new elem_expr(v.get_location(), lQNameExpr, lContent);

  nodestack.push(lElem);
}

void *begin_visit(const CompAttrConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompAttrConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  
  expr_t lValueExpr = 0;
  expr_t lAttr = 0;
  
  if (v.get_val_expr() != 0) {
    lValueExpr = pop_nodestack();
    
    fo_expr *lDocFilter = new fo_expr(v.get_location(), LOOKUP_OP1 ("doc-filter"));
    lDocFilter->add(lValueExpr);
    
    fo_expr *lEnclosed = new fo_expr(v.get_location(), LOOKUP_OP1("enclosed-expr"));
    lEnclosed->add(lValueExpr);

    lValueExpr = lEnclosed;
  } 
  
  expr_t lQNameExpr = pop_nodestack();

  lAttr = new attr_expr(v.get_location(), lQNameExpr, lValueExpr);
  
  nodestack.push(&*lAttr);
}

void *begin_visit(const CompCommentConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompCommentConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new text_expr (v.get_location (), text_expr::comment_constructor, pop_nodestack ()));
}

void *begin_visit(const CompPIConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompPIConstructor& v, void *visit_state)
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

void *begin_visit(const CompTextConstructor& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompTextConstructor& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new text_expr (v.get_location (), text_expr::text_constructor, pop_nodestack ()));
}


/*******************************************************************************

  FLWOR Expression

********************************************************************************/
void *begin_visit(const FLWORExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const FLWORExpr& v, void *visit_state)
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
      string col = sctx_p->default_collation_uri ();
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
        ve = pop_nodestack ().cast<var_expr> ();
        ve->set_kind (var_expr::for_var);
        // for var
        vars.push_back (ve);
        // value expression
        exprs.push_back(pop_nodestack ());
        // pos var
        if ((*decl_list) [j]->get_posvar () == NULL)
          pos_vars.push_back (NULL);
        else {
          rchandle<var_expr> pve = pop_nodestack ().cast<var_expr> ();
          pve->set_kind (var_expr::pos_var);
          pos_vars.push_back (pve);
        }
        pop_scope ();
      }

      for (j = 0; j < size; j++) {
        forlet_clause *flc = new forlet_clause (forlet_clause::for_clause, vars [j], pos_vars [j], NULL, exprs [j]);
        eclauses.push_back (flc);
      }
    } else {  // let clause
      LetClause *letclause = static_cast<LetClause *> (clause);
      
      for (j = 0; j < size; j++) {
        rchandle<var_expr> ve = pop_nodestack ().cast<var_expr> ();
        exprs.push_back(pop_nodestack ());
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


void *begin_visit(const ForLetClauseList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ForLetClauseList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const LetClause& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const LetClause& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarGetsDecl& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarGetsDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  push_scope ();
  nodestack.push (bind_var (v.get_location (), v.get_varname (), var_expr::let_var));
}


void *begin_visit(const ForClause& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ForClause& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarInDecl& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarInDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  push_scope ();
  const PositionalVar *pv = v.get_posvar ();
  if (pv != NULL) {
    expr_t val_expr = pop_nodestack ();
    nodestack.push (bind_var (pv->get_location (), pv->get_varname (), var_expr::pos_var));
    nodestack.push (val_expr);
  }
  nodestack.push (bind_var (v.get_location (), v.get_varname (), var_expr::for_var));
}

void *begin_visit(const PositionalVar& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const PositionalVar& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const WhereClause& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const WhereClause& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const OrderByClause& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderByClause& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderSpecList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderSpecList& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderSpec& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderSpec& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderModifier& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderModifier& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderCollationSpec& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderCollationSpec& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderDirSpec& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderDirSpec& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderEmptySpec& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderEmptySpec& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/

void *begin_visit(const VarDecl& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  global_vars.push_back (global_binding (bind_var (v.get_location(), v.get_varname(), var_expr::let_var),
                                         v.is_extern () ? expr_t (NULL) : pop_nodestack ()));
}


void *begin_visit(const FunctionDecl& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const FunctionDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const GeneralComp& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const GeneralComp& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const ItemType& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ItemType& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const LibraryModule& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const LibraryModule& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const MainModule & v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const MainModule & v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const Module& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const Module& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const ModuleDecl& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const ModuleDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const ModuleImport& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const ModuleImport& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const NamespaceDecl& v)
{
  TRACE_VISIT ();
  sctx_p->bind_ns (v.get_prefix (), v.get_uri ());
  return NULL;
}

void end_visit(const NamespaceDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}

void *begin_visit(const NodeComp& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const NodeComp& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const OccurrenceIndicator& v)
{
  TRACE_VISIT ();
  TypeSystem::quantifier_t q;
  switch (v.get_type ()) {
  case occurs_exactly_one:
    q = TypeSystem::QUANT_ONE; break;
  case occurs_one_or_more:
    q = TypeSystem::QUANT_PLUS; break;
  case occurs_optionally:
    q = TypeSystem::QUANT_QUESTION; break;
  case occurs_zero_or_more:
    q = TypeSystem::QUANT_STAR; break;
  case occurs_never:
    ZORBA_ASSERT (false);
  }

  if (q != TypeSystem::QUANT_ONE)
    tstack.push (GENV_TYPESYSTEM.create_type (*pop_tstack (), q));
    
  return no_state;
}

void end_visit(const OccurrenceIndicator& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const OptionDecl& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const OptionDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const OrderingModeDecl& v)
{
  TRACE_VISIT ();
  sctx_p->set_ordering_mode(v.get_mode());
  return NULL;
}


void end_visit(const OrderingModeDecl& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}

void *begin_visit(const Param& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Param& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const ParamList& v)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const ParamList& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const Pragma& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Pragma& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}

void *begin_visit(const PragmaList& v)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const PragmaList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const PredicateList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const PredicateList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const Prolog& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Prolog& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const QVarInDecl& v)
{
  TRACE_VISIT ();
  push_scope ();
  nodestack.push (bind_var (v.get_location (), v.get_name (), var_expr::quant_var));
  return no_state;
}

void end_visit(const QVarInDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const QVarInDeclList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const QVarInDeclList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SIND_DeclList& v)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const SIND_DeclList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SchemaImport& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const SchemaImport& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const SchemaPrefix& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const SchemaPrefix& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const SequenceType& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const SequenceType& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SignList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const SignList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SingleType& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const SingleType& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  if (v.get_hook_bit ())
    tstack.push (GENV_TYPESYSTEM.create_type (*pop_tstack (), TypeSystem::QUANT_QUESTION));
  // else leave type as it is on tstack
}


void *begin_visit(const TypeDeclaration& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TypeDeclaration& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const TypeName& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TypeName& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const URILiteralList& v)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const URILiteralList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const ValueComp& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ValueComp& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const VersionDecl& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VersionDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const VFO_DeclList& v)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const VFO_DeclList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const AdditiveExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AdditiveExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  function *func = NULL;
  switch (v.get_add_op()) {
  case op_plus:
    func = LOOKUP_OP2 ("add");
    break;
  case op_minus:
    func = LOOKUP_OP2 ("subtract");
    break;
  }
  fo_expr *fo_h = new fo_expr(v.get_location(), func);
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


void *begin_visit(const AndExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AndExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_h = new fo_expr(v.get_location(), LOOKUP_OPN ("and"));
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


void *begin_visit(const CastExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CastExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new cast_expr (v.get_location (), pop_nodestack (), pop_tstack ()));
}

void *begin_visit(const CastableExpr& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const CastableExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
  nodestack.push(new castable_expr(v.get_location(), pop_nodestack(), pop_tstack()));
}


void *begin_visit(const ComparisonExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ComparisonExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  function *f = NULL;
  if (v.get_gencomp()!=NULL) {
    switch (v.get_gencomp()->get_type()) {
    case op_eq:
      f = (LOOKUP_OP2 ("equal"));
      break;
    case op_ne:
      f = (LOOKUP_OP2 ("not-equal"));
      break;
    case op_lt:
      f = (LOOKUP_OP2 ("less"));
      break;
    case op_le:
      f = (LOOKUP_OP2 ("less-equal"));
      break;
    case op_gt:
      f = (LOOKUP_OP2 ("greater"));
      break;
    case op_ge:
      f = (LOOKUP_OP2 ("greater-equal"));
      break;
    }
  } else if (v.get_valcomp () != NULL) {
    switch (v.get_valcomp()->get_type()) {
    case op_val_eq:
      f = (LOOKUP_OP2 ("value-equal"));
      break;
    case op_val_ne:
      f = (LOOKUP_OP2 ("value-not-equal"));
      break;
    case op_val_lt:
      f = (LOOKUP_OP2 ("value-less"));
      break;
    case op_val_le:
      f = (LOOKUP_OP2 ("value-less-equal"));
      break;
    case op_val_gt:
      f = (LOOKUP_OP2 ("value-greater"));
      break;
    case op_val_ge:
      f = (LOOKUP_OP2 ("value-greater-equal"));
      break;
    }
  } else if (v.get_nodecomp()!=NULL) {
    switch (v.get_nodecomp()->get_type()) {
    case op_is:
      f = (LOOKUP_OP2 ("is"));
      break;
    case op_precedes:
      f = (LOOKUP_OP2 ("precedes"));
      break;
    case op_follows:
      f = (LOOKUP_OP2 ("follows"));
      break;
    }
  }

  fo_expr *fo_p = new fo_expr(v.get_location(), f);

  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();;
  fo_p->add(e2_h);
  fo_p->add(e1_h);
  nodestack.push(fo_p);
}



void *begin_visit(const ContextItemExpr& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const ContextItemExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  var_expr *e = static_cast<var_expr *> (sctx_p->lookup_var (DOT_VAR));
  nodestack.push(e);
}


void *begin_visit(const Expr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Expr& v, void *visit_state)
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

// void *begin_visit(const ExprSingle& v)
// {
// TRACE_VISIT ();
//  return no_state;
// }

void *begin_visit(const ExtensionExpr& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const ExtensionExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *begin_visit(const FilterExpr& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const FilterExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
}

void *begin_visit(const FunctionCall& v)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const FunctionCall& v, void *visit_state) {
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

  Item_t fn_qname = sctx_p->lookup_fn_qname(prefix, fname);

  if (fn_qname->getNamespace() == XQUERY_FN_NS && fn_qname->getLocalName() == "position") {
    nodestack.push(sctx_p->lookup_var(DOT_POS_VAR));
    return;
  }
  if (fn_qname->getNamespace() == XQUERY_FN_NS && fn_qname->getLocalName() == "last") {
    nodestack.push(sctx_p->lookup_var(LAST_IDX_VAR));
    return;
  }
  if (fn_qname->getNamespace() == XQUERY_FN_NS && fn_qname->getLocalName() == "string") {
    fn_qname = sctx_p->lookup_fn_qname("xs", "string");
    switch (arguments.size ()) {
    case 0:
      arguments.push_back (sctx_p->lookup_var (DOT_VAR));
      break;
    case 1:
      break;
    default:
      ZORBA_ERROR_ALERT_OSS (AlertCodes::XPST0017, NULL, false, "fn:string", arguments.size ());
    }
  }
  TypeSystem::xqtref_t type =
    GENV_TYPESYSTEM.create_type (fn_qname,
                                 TypeSystem::QUANT_QUESTION);
  if (type != NULL) {
    if (arguments.size () != 1)
      ZORBA_ERROR_ALERT_OSS (AlertCodes::XPST0017, NULL, false, prefix + ":" + fname, arguments.size ());
    nodestack.push (new cast_expr (v.get_location (), arguments [0], type));
  } else {
    int sz = (v.get_arg_list () == NULL) ? 0 : v.get_arg_list ()->size ();
    rchandle<fo_expr> fo_h = new fo_expr(v.get_location(), LOOKUP_FN (prefix, fname, sz));
    
    // TODO this should be a const iterator
    std::vector<expr_t>::reverse_iterator iter = arguments.rbegin();
    for(; iter != arguments.rend(); ++iter) {
      fo_h->add(*iter);
    }
    
    nodestack.push(&*fo_h);
  }
}

void *begin_visit(const IfExpr& v)
{
TRACE_VISIT ();
  // nothing to do here
  return no_state;
}

void end_visit(const IfExpr& v, void *visit_state)
{
TRACE_VISIT_OUT ();
  expr_t e_h = pop_nodestack ();
  expr_t t_h = pop_nodestack ();
  expr_t c_h = pop_nodestack ();
  rchandle<if_expr> if_h = new if_expr(v.get_location(),c_h,t_h,e_h);
  nodestack.push(&*if_h);
}


void *begin_visit(const InstanceofExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const InstanceofExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new instanceof_expr (v.get_location (), pop_nodestack (), pop_tstack ()));
}


void *begin_visit(const IntersectExceptExpr& v)
{
  TRACE_VISIT ();
  nodestack.push (new instanceof_expr (v.get_location (), pop_nodestack (), pop_tstack ()));
  return no_state;
}

void end_visit(const IntersectExceptExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  function *f = NULL;
  switch (v.get_intex_op()) {
  case op_intersect:
    f = LOOKUP_OP2 ("intersect");
    break;
  case op_except:
    f = LOOKUP_OP2 ("except");
    break;
  }
  fo_expr *fo_h = new fo_expr(v.get_location(), f);

  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push(fo_h);
}

void *begin_visit(const MultiplicativeExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const MultiplicativeExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  function *f = NULL;
  switch (v.get_mult_op()) {
  case op_mul:
    f = LOOKUP_OP2 ("multiply");
    break;
  case op_div:
    f = LOOKUP_OP2 ("divide");
    break;
  case op_idiv:
    f = LOOKUP_OP2 ("integer-divide");
    break;
  case op_mod:
    f = LOOKUP_OP2 ("mod");
    break;
  }
  fo_expr *fo_h = new fo_expr(v.get_location(), f);
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}

void *begin_visit(const NumericLiteral& v)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const NumericLiteral& v, void *visit_state)
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

void *begin_visit(const OrExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_p = new fo_expr(v.get_location(), LOOKUP_OPN ("or"));
  fo_p->add(e2_h);
  fo_p->add(e1_h);
  nodestack.push (fo_p);
}

void *begin_visit(const OrderedExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderedExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new order_expr (v.get_location (), order_expr::ordered, 
                                  pop_nodestack ()));
}


void *begin_visit(const ParenthesizedExpr& v)
{
TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const ParenthesizedExpr& v, void *visit_state)
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
void *begin_visit(const NameTest& v)
{
  TRACE_VISIT ();
  return no_state;
}



void end_visit(const NameTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  // Find axis step on top of stack
  rchandle<axis_step_expr> axisExpr = expect_axis_step_top ();

  // Construct name-test match expr
  rchandle<match_expr> matchExpr = new match_expr(v.get_location());;
  matchExpr->setTestKind(match_name_test);

  if (v.getQName() != NULL)
  {
    string qname = v.getQName()->get_qname();
    Item_t qn_h = sctx_p->lookup_elem_qname (qname);
    matchExpr->setQName(qn_h);
  }
  else
  {
    rchandle<Wildcard> wildcard = v.getWildcard();
    ZORBA_ASSERT(wildcard != NULL);

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


void *begin_visit(const Wildcard& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const Wildcard& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const QName& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const QName& v, void *visit_state)
{
  nodestack.push(
    new const_expr(v.get_location(), v.get_uri().c_str(), v.get_prefix().c_str(), v.get_localname().c_str())
  );
  TRACE_VISIT_OUT ();
}


void *begin_visit(const AnyKindTest& v)
{
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit(const AnyKindTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  rchandle<axis_step_expr> ase = expect_axis_step_top ();

  rchandle<match_expr> me = new match_expr(v.get_location());
  me->setTestKind(match_anykind_test);
  ase->setTest(me);
}


void *begin_visit(const DocumentTest& v)
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


void end_visit(const DocumentTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const ElementTest& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ElementTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  // find axis step expression on top of stack
  rchandle<axis_step_expr> ase = expect_axis_step_top ();

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


void *begin_visit(const AttributeTest& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const AttributeTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  // find axis step expression on top of stack
  rchandle<axis_step_expr> ase_h = expect_axis_step_top ();

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


void *begin_visit(const TextTest& v)
{
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit(const TextTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase_h = expect_axis_step_top ();

  rchandle<match_expr> m_h = new match_expr(v.get_location());
  m_h->setTestKind(match_text_test);
  ase_h->setTest(m_h);
}


void *begin_visit(const CommentTest& v)
{
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit(const CommentTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase_h = expect_axis_step_top ();

  rchandle<match_expr> m_h = new match_expr(v.get_location());
  m_h->setTestKind(match_comment_test);
  ase_h->setTest(m_h);
}


void *begin_visit(const PITest& v)
{
  TRACE_VISIT ();

  rchandle<match_expr> m_h = new match_expr(v.get_location());
  m_h->setTestKind(match_pi_test);

  string target = v.get_target();
  m_h->setQName(sctx_p->lookup_elem_qname (target));
  nodestack.push(&*m_h);
  return no_state;
}


void end_visit(const PITest& v, void *visit_state)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const SchemaAttributeTest& v)
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


void end_visit(const SchemaAttributeTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SchemaElementTest& v)
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


void end_visit(const SchemaElementTest& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

#define TEMP_VAR_URI "http://www.flworfound.org/zorba/temp-var"
#define TEMP_VAR_PREFIX "ztv"

rchandle<var_expr> tempvar(yy::location loc, var_expr::var_kind kind)
{
  return new var_expr(loc, kind, Store::getInstance().getItemFactory().createQName(TEMP_VAR_URI, TEMP_VAR_PREFIX, "v" + to_string (tempvar_counter++)));
}

rchandle<forlet_clause> wrap_in_forclause(expr_t expr, rchandle<var_expr> fv, rchandle<var_expr> pv)
{
  assert (fv->get_kind () == var_expr::for_var);
  if (pv != NULL)
    assert (pv->get_kind() == var_expr::pos_var);
  return new forlet_clause(forlet_clause::for_clause, fv, pv, NULL, expr.get_ptr());
}

rchandle<forlet_clause> wrap_in_forclause(expr_t expr, bool add_posvar)
{
  rchandle<var_expr> fv = tempvar(expr->get_loc(), var_expr::for_var);
  rchandle<var_expr> pv = add_posvar
    ? tempvar(expr->get_loc(), var_expr::pos_var)
    : rchandle<var_expr> (NULL);
  return wrap_in_forclause (expr, fv, pv);
}

rchandle<forlet_clause> wrap_in_forclause(expr_t expr, yy::location loc, string fv_name, string pv_name) {
  return wrap_in_forclause (expr, bind_var (loc, fv_name, var_expr::for_var), bind_var (loc, pv_name, var_expr::pos_var));
}

rchandle<forlet_clause> wrap_in_letclause(expr_t expr, rchandle<var_expr> lv) {
  assert (lv->get_kind () == var_expr::let_var);
  return new forlet_clause(forlet_clause::let_clause, lv, NULL, NULL, expr.get_ptr());
}
rchandle<forlet_clause> wrap_in_letclause(expr_t expr, yy::location loc, string name) {
  return wrap_in_letclause (expr, bind_var (loc, name, var_expr::let_var));
}
rchandle<forlet_clause> wrap_in_letclause(expr_t expr) {
  return wrap_in_letclause (expr, tempvar(expr->get_loc(), var_expr::let_var));
}


expr_t wrap_in_dos_and_dupelim(expr_t expr)
{
  rchandle<fo_expr> dos = new fo_expr(expr->get_loc(), LOOKUP_OP1("sort-distinct-nodes-ascending"));
  dos->add(expr);
  return &*dos;
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
void *begin_visit(const PathExpr& v)
{
  TRACE_VISIT ();
  rchandle<relpath_expr> rpe = NULL;
  if (v.get_type() != path_leading_lone_slash)
  {
    rpe = new relpath_expr(v.get_location());
    nodestack.push(NULL);
  }
  expr_t result = &*rpe;

  if (v.get_type() != path_relative) 
  {
    // Create fn:root(self::node()) expr
    rchandle<relpath_expr> ctx_rpe = new relpath_expr(v.get_location());
    var_expr* ctx_var = static_cast<var_expr *> (sctx_p->lookup_var(DOT_VAR));
    ZORBA_ASSERT(ctx_var != NULL);
    ctx_rpe->add_back(ctx_var);
    rchandle<match_expr> me = new match_expr(v.get_location());
    me->setTestKind(match_anykind_test);

    rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
    ase->setAxis(axis_kind_self);
    ase->setTest(me);

    ctx_rpe->add_back(&*ase);

    rchandle<fo_expr> fo = new fo_expr(v.get_location(), LOOKUP_FN("fn", "root", 1));
    fo->add(&*ctx_rpe);
    result = &*fo;
    if (rpe != NULL) {
      rpe->add_back(&*fo);
      result = &*rpe;
    }
  }

  if (v.get_type() == path_leading_slashslash)
  {
    rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
    rchandle<match_expr> me = new match_expr(v.get_location());
    me->setTestKind(match_anykind_test);
    ase->setAxis(axis_kind_descendant_or_self);
    ase->setTest(me);
    rpe->add_back(&*ase);
  }

  nodestack.push(&*result);
  return no_state;
}

void end_visit(const PathExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();

  relpath_expr *rpe = NULL;
  if (arg1 == NULL || dynamic_cast<relpath_expr *>(&*arg2))
  {
    nodestack.push(wrap_in_dos_and_dupelim(arg2));
  }
  else
  {
    relpath_expr *rpe = dynamic_cast<relpath_expr *>(&*arg1);
    ZORBA_ASSERT(rpe != NULL);
    rpe->add_back(arg2);
    expr_t nulle = pop_nodestack();
    ZORBA_ASSERT(nulle == NULL);
    nodestack.push(wrap_in_dos_and_dupelim(rpe));
  }
}

void* begin_visit(const RelativePathExpr& v)
{
  TRACE_VISIT ();

  if (theRootRelPathExpr == NULL)
  {
    theRootRelPathExpr = &v;
    return (void*)(&v);
  }

  if (dynamic_cast<RelativePathExpr *>(v.get_relpath_expr().get_ptr()) == NULL)
    theRootRelPathExpr = NULL;

  return no_state;
}

void intermediate_visit(const RelativePathExpr& v, void *visit_state)
{
  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();
  
  relpath_expr *rpe = dynamic_cast<relpath_expr *>(&*arg1);
  ZORBA_ASSERT(rpe != NULL);

  rpe->add_back(arg2);
  if (v.get_step_type() == st_slashslash)
  {
    rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
    rchandle<match_expr> me = new match_expr(v.get_location());
    me->setTestKind(match_anykind_test);
    ase->setAxis(axis_kind_descendant_or_self);
    ase->setTest(me);
    rpe->add_back(&*ase);
  }
  nodestack.push(rpe);
}

void end_visit(const RelativePathExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  if (theRootRelPathExpr == &v)
    theRootRelPathExpr = NULL;

  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();

  relpath_expr *rpe = NULL;
  if (arg1 == NULL || dynamic_cast<relpath_expr *>(&*arg2)) {
    nodestack.push(arg1);
    nodestack.push(arg2);
  } else {
    relpath_expr *rpe = dynamic_cast<relpath_expr *>(&*arg1);
    ZORBA_ASSERT(rpe != NULL);
    rpe->add_back(arg2);
    nodestack.push(rpe);
  }
}


void *begin_visit(const AxisStep& v)
{
  TRACE_VISIT ();

  rchandle<axis_step_expr> aexpr_h = new axis_step_expr(v.get_location());
  nodestack.push(&*aexpr_h);
  return no_state;
}

void post_step_visit(const AxisStep& v, void *visit_state)
{
  PredicateList *pl = v.get_predicate_list().get_ptr();
  if (pl != NULL && pl->size() > 0) {
    expr_t arg2 = pop_nodestack();
    expr_t arg1 = pop_nodestack();

    relpath_expr *rpe = dynamic_cast<relpath_expr *>(&*arg1);
    ZORBA_ASSERT(rpe != NULL);

    rpe->add_back(arg2);

    expr_t dose = wrap_in_dos_and_dupelim(rpe);
    nodestack.push(dose);
  }
}

void end_visit(const AxisStep& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void pre_predicate_visit(const PredicateList& v, void *visit_state)
{
  push_scope();
  expr_t seq = pop_nodestack();
  rchandle<forlet_clause> lcseq = wrap_in_letclause(seq);
  rchandle<fo_expr> count_expr = new fo_expr(v.get_location(), LOOKUP_FN("fn", "count", 1));
  count_expr->add(lcseq->get_var().get_ptr());
  rchandle<forlet_clause> lclast = wrap_in_letclause(&*count_expr, v.get_location(), LAST_IDX_VAR);
  rchandle<forlet_clause> fc = wrap_in_forclause(lcseq->get_var().get_ptr(), v.get_location (), DOT_VAR, DOT_POS_VAR);
  rchandle<flwor_expr> flwor = new flwor_expr(v.get_location());
  flwor->add(lcseq);
  flwor->add(lclast);
  flwor->add(fc);
  nodestack.push(&*flwor);
}


static inline bool is_numeric_literal(expr *e)
{
  const_expr *ce = dynamic_cast<const_expr *>(e);
  if (ce == NULL) {
    return false;
  }
  Item_t it = ce->get_val();
  TypeSystem::xqtref_t itype = GENV_TYPESYSTEM.create_type(it->getType(), TypeSystem::QUANT_ONE);
  return GENV_TYPESYSTEM.is_subtype(*itype, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE);
}


void post_predicate_visit(const PredicateList& v, void *visit_state)
{
  expr_t pred = pop_nodestack();
  expr_t f = pop_nodestack();

  flwor_expr *flwor = dynamic_cast<flwor_expr *>(&*f);
  ZORBA_ASSERT(flwor != NULL);
  
  rchandle<if_expr> ite = new if_expr(pred->get_loc());
  if (is_numeric_literal(&*pred) || &*pred == sctx_p->lookup_var(LAST_IDX_VAR)) {
    rchandle<fo_expr> eq = new fo_expr(pred->get_loc(), LOOKUP_OP2("value-equal"));
    eq->add(sctx_p->lookup_var(DOT_POS_VAR));
    eq->add(pred);
    ite->set_cond_expr(&*eq);
  } else {
    ite->set_cond_expr(pred);
  }

  ite->set_then_expr(sctx_p->lookup_var(DOT_VAR));
  ite->set_else_expr(create_seq(pred->get_loc()));
  
  flwor->set_retval(&*ite);
  nodestack.push(flwor);
  pop_scope();
}


void *begin_visit(const ForwardStep& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ForwardStep& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const AbbrevForwardStep& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const AbbrevForwardStep& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

  if (v.get_attr_bit())
  {
    ase->setAxis(axis_kind_attribute);
  }
  else
  {
    ase->setAxis(axis_kind_child);
  }
}


void *begin_visit(const ForwardAxis& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ForwardAxis& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

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


void *begin_visit(const ReverseStep& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ReverseStep& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const ReverseAxis& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ReverseAxis& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

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
void *begin_visit(const QuantifiedExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const QuantifiedExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  rchandle<flwor_expr> flwor(new flwor_expr(v.get_location()));
  flwor->set_retval(new const_expr(v.get_location(), true));
  rchandle<expr> sat = pop_nodestack();
  if (v.get_qmode() == quant_every) {
    rchandle<fo_expr> uw = new fo_expr(v.get_expr()->get_location(), LOOKUP_FN("fn", "not", 1));
    uw->add(sat);
    sat = uw.get_ptr();
  }
  flwor->set_where(sat);
  int i;
  for(i = 0; i < v.get_decl_list()->size(); ++i) {
    rchandle<expr> fe = pop_nodestack();
    rchandle<var_expr> ve = pop_nodestack().cast<var_expr>();
    ve->set_kind(var_expr::for_var);
    flwor->add(new forlet_clause(forlet_clause::for_clause, ve, NULL, NULL, fe));
    pop_scope();
  }
  rchandle<fo_expr> quant = new fo_expr(v.get_location(), v.get_qmode() == quant_every ? LOOKUP_FN("fn", "empty", 1) : LOOKUP_FN("fn", "exists", 1));
  quant->add(rchandle<expr> (flwor.get_ptr()));
  nodestack.push (quant.get_ptr());
}


/*******************************************************************************

********************************************************************************/
void *begin_visit(const QueryBody& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const QueryBody& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  flwor_expr::clause_list_t clauses;
  for (std::list<global_binding>::iterator i = global_vars.begin ();
       i != global_vars.end (); i++)
  {
    global_binding b = *i;
    var_expr_t var = b.first;
    expr_t expr = b.second;
    if (expr == NULL) {
      fo_expr *fo = new fo_expr (var->get_loc (), LOOKUP_OP1 ("ctxvariable"));
      fo->add (new const_expr (var->get_loc (), var->get_varname ()->getStringProperty ()));
      expr = fo;
    }
    clauses.push_back (wrap_in_letclause (expr, var));
  }
  if (clauses.size () > 0)
    nodestack.push (new flwor_expr (v.get_location (), clauses, pop_nodestack ()));
}


/*******************************************************************************

********************************************************************************/
void *begin_visit(const RangeExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const RangeExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  fo_expr *e = new fo_expr (v.get_location(), LOOKUP_OP2 ("to"));

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();

  e->add(e2_h);
  e->add(e1_h);

  nodestack.push(e);
}


void *begin_visit(const StringLiteral& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const StringLiteral& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push(new const_expr(v.get_location(),v.get_strval()));
}

void *begin_visit(const TreatExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TreatExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const TypeswitchExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TypeswitchExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  case_clause * cc_p;
  expr_t e_h;
  rchandle<typeswitch_expr> tse_h = new typeswitch_expr(v.get_location());

  rchandle<var_expr> ve_h = bind_var (v.get_location(), v.get_default_varname(), var_expr::unknown_var);
  tse_h->set_default_varname(ve_h);

  ZORBA_ASSERT((e_h = pop_nodestack())!=NULL);
  tse_h->set_switch_expr(e_h);

  ZORBA_ASSERT((e_h = pop_nodestack())!=NULL);
  tse_h->set_default_clause(e_h);

  while (true) {  // pop clauses
    e_h = nodestack.top();
    if ((cc_p = dynamic_cast<case_clause*>(&*e_h))==NULL) break;
    nodestack.pop();
    tse_h->add_clause(cc_p);
  }

  nodestack.push(&*tse_h);
}


void *begin_visit(const UnaryExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const UnaryExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  fo_expr *fo_p = new fo_expr(v.get_location(),
                              v.get_signlist()->get_sign()
                              ? LOOKUP_OP1 ("unary-plus")
                              : LOOKUP_OP1 ("unary-minus"));
  fo_p->add(e1_h);
  nodestack.push(fo_p);
}

void *begin_visit(const UnionExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const UnionExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  fo_expr *fo_h = new fo_expr(v.get_location(), LOOKUP_OP2 ("union"));
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push(fo_h);
}

void *begin_visit(const UnorderedExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const UnorderedExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new order_expr (v.get_location (), order_expr::unordered, 
                                  pop_nodestack ()));
}

void *begin_visit(const ValidateExpr& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const ValidateExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarRef& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarRef& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
  var_expr *e = static_cast<var_expr *> (sctx_p->lookup_var (v.get_varname ()));
  if (e == NULL)
    ZORBA_ERROR_ALERT (AlertCodes::XPST0008, NULL, false, v.get_varname ());
  nodestack.push (rchandle<expr> (e));
}


/* update-related */
void *begin_visit(const DeleteExpr& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const DeleteExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const InsertExpr& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const InsertExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const RenameExpr& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const RenameExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const ReplaceExpr& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const ReplaceExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const RevalidationDecl& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const RevalidationDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const TransformExpr& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const TransformExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarNameList& v)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const VarNameList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


/* full-text-related */
void *begin_visit(const FTAnd& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTAnd& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTAnyallOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTAnyallOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTBigUnit& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTBigUnit& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTCaseOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTCaseOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTContainsExpr& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTContainsExpr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTContent& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTContent& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTDiacriticsOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTDiacriticsOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTDistance& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTDistance& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTIgnoreOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTIgnoreOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTInclExclStringLiteral& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTInclExclStringLiteral& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTInclExclStringLiteralList& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTInclExclStringLiteralList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTLanguageOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTLanguageOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTMatchOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTMatchOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const FTMatchOptionProximityList& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTMatchOptionProximityList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTMildnot& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTMildnot& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTOptionDecl& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTOptionDecl& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTOr& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTOr& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTOrderedIndicator& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTOrderedIndicator& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTProximity& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTProximity& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTRange& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTRange& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTRefOrList& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTRefOrList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTScope& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTScope& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTScoreVar& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTScoreVar& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTSelection& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTSelection& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTStemOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTStemOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTStopwordOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTStopwordOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTStringLiteralList& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTStringLiteralList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTThesaurusID& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTThesaurusID& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTThesaurusList& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTThesaurusList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTThesaurusOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTThesaurusOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTTimes& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTTimes& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTUnaryNot& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTUnaryNot& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTUnit& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTUnit& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWildcardOption& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTWildcardOption& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWindow& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTWindow& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWords& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTWords& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWordsSelection& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTWordsSelection& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWordsValue& v)
{
  TRACE_VISIT ();
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTWordsValue& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

// Pass-thru

void *begin_visit(const VarInDeclList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarInDeclList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarGetsDeclList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarGetsDeclList& v, void *visit_state)
{
  TRACE_VISIT_OUT ();
}

// End pass-thru


};


Translator *make_translator (static_context *sctx_p) {
  return new TranslatorImpl (sctx_p);
}

rchandle<expr> translate (static_context *sctx_p, const parsenode &root) {
  auto_ptr<Translator> t (make_translator (sctx_p));
  root.accept (*t);
  return t->result ();
}


} /* namespace xqp */
/* vim:set ts=2 sw=2: */
