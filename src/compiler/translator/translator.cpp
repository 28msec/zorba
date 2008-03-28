/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: translator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include <string>
#include <stack>
#include <sstream>
#include <list>

#include "zorbatypes/Unicode_util.h"

#include "common/common.h"
#include "store/api/item.h"
#include "util/properties.h"
#include "context/static_context_consts.h"

#include "compiler/translator/translator.h"
#include "compiler/api/compilercb.h"

#include "errors/error_manager.h"

#include "context/static_context.h"
#include "context/namespace_context.h"
#include "types/node_test.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "compiler/expression/expr.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenode_visitor.h"
#include "compiler/normalizer/normalizer.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/api/compiler_api.h"
#include "compiler/parser/util.h"
#include "util/tracer.h"
#include "system/globalenv.h"
#include "functions/signature.h"
#include "functions/external_function_adapters.h"
#include "util/stl_extra.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "types/delegating_typemanager.h"
#include "types/schema/schema.h"

using namespace std;

namespace zorba {

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (sctx_p->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 1))
#define LOOKUP_OP2( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 2))
#define LOOKUP_OP3( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 3))
#define LOOKUP_OPN( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))

#define CHK_ONE_DECL( state, err ) do { if (state) ZORBA_ERROR(err); state = true; } while (0)
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

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

  typedef rchandle<expr> expr_t;
  typedef rchandle<var_expr> var_expr_t;
  typedef std::pair<var_expr_t, expr_t> global_binding;

  template<class T> T &peek_stack (std::stack<T> &stk) {
    ZORBA_ASSERT (! stk.empty ());
    return stk.top ();
  }

  template <typename T> T pop_stack (std::stack<T> &stk) {
    T x = peek_stack (stk);
    stk.pop ();
    return x;
  }


class TranslatorImpl : public parsenode_visitor
{
public:
  friend TranslatorImpl *make_translator (bool, CompilerCB*);

protected:
  uint32_t depth;
  bool     print_translated;

  CompilerCB                        *compilerCB;
  static_context                    *sctx_p;
  vector<rchandle<static_context> > &sctx_list;
  std::stack<expr_t>                 nodestack;
  std::stack<xqtref_t>               tstack;  // types stack
  int                                tempvar_counter;
  std::list<global_binding>          global_vars;
  const RelativePathExpr           * theRootRelPathExpr;
  std::stack<const RelativePathExpr *> relpathstack;
  rchandle<namespace_context>          ns_ctx;

  // FOR WHITESPACE CHECKING OF DirElemContent (stack is need because of nested elements)
  /**
   * Saves true if the previous DirElemContent is a boundary (DirElemConstructor or EnclosedExpr).
   */
  std::stack<bool>                theIsWSBoundaryStack;
  /**
   * Saves the previous DirElemContent if it might be boundary whitespace (its previous item is a boundary
   * and it contains whitespace). It must be checked if the next item (the current item) is a boundary.
   */
  std::stack<const DirElemContent*>     thePossibleWSContentStack;

  bool hadBSpaceDecl, hadBUriDecl, hadConstrDecl, hadCopyNSDecl, hadDefNSDecl, hadEmptyOrdDecl, hadOrdModeDecl;

  var_expr_t theDotVar, theDotPosVar, theLastVar;

  TranslatorImpl (bool print_, CompilerCB* aCompilerCB)
    :
    depth (0), print_translated (print_),
    compilerCB(aCompilerCB),
    sctx_p (aCompilerCB->m_sctx),
    sctx_list (aCompilerCB->m_sctx_list),
    tempvar_counter (1),
    theRootRelPathExpr(0),
    ns_ctx(new namespace_context(sctx_p)),
    hadBSpaceDecl (false),
    hadBUriDecl (false),
    hadConstrDecl (false),
    hadCopyNSDecl (false),
    hadEmptyOrdDecl (false),
    hadOrdModeDecl (false)
  {
    theDotVar = bind_var(QueryLoc::null, DOT_VAR, var_expr::context_var, GENV_TYPESYSTEM.ITEM_TYPE_ONE);
    theDotPosVar = bind_var(QueryLoc::null, DOT_POS_VAR, var_expr::context_var, GENV_TYPESYSTEM.POSITIVE_INTEGER_TYPE_ONE);
    theLastVar = bind_var (QueryLoc::null, LAST_IDX_VAR, var_expr::context_var, GENV_TYPESYSTEM.POSITIVE_INTEGER_TYPE_ONE);
  }

  expr_t pop_nodestack (int n = 1)
  {
    ZORBA_ASSERT (n >= 0);
    rchandle<expr> e_h;
    for (; n > 0; --n) {
      ZORBA_ASSERT (! nodestack.empty());
      e_h = nodestack.top();
      nodestack.pop();
    }
    return e_h;
  }

  xqtref_t pop_tstack()
  { return pop_stack (tstack); }

  expr_t peek_nodestk_or_null () {
    return (nodestack.empty ()) ? expr_t (NULL) : peek_stack (nodestack);
  }

  var_expr_t bind_var (const QueryLoc& loc, string varname, var_expr::var_kind kind, xqtref_t type = NULL)
  {
    store::Item_t qname = sctx_p->lookup_qname ("", varname);
    var_expr_t e = new var_expr (loc, kind, qname);
    e->set_type (type);
    sctx_p->bind_var (qname, e.getp ());
    return e;
  }

  var_expr_t bind_var_and_push (const QueryLoc& loc, string varname, var_expr::var_kind kind, xqtref_t type = NULL)
  {
    var_expr_t e = bind_var (loc, varname, kind, type);
    nodestack.push (&*e);
    return e;
  }

  fo_expr *create_seq (const QueryLoc& loc) {
    return new fo_expr (loc, LOOKUP_OPN ("concatenate"));
  }

  void push_scope ()
  {
    sctx_list.push_back (sctx_p = sctx_p->create_child_context());
  }

  void pop_scope (int n = 1)
  {
    while (n-- > 0) {
      static_context *parent = (static_context *) sctx_p->get_parent ();
      sctx_p = parent;
    }
  }

  rchandle<axis_step_expr> expect_axis_step_top () {
    rchandle<axis_step_expr> axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
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

  void push_elem_scope()
  {
    ns_ctx = new namespace_context(&*ns_ctx);
  }

  void pop_elem_scope()
  {
    ns_ctx = ns_ctx->get_parent();
  }

public:

bool is_root_rpe(const RelativePathExpr* rpe)
{
  return rpe == theRootRelPathExpr;
}


expr_t result ()
{
  return pop_nodestack ();
}


void *begin_visit(const parsenode& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const parsenode& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const exprnode& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const exprnode& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const ArgList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ArgList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const BaseURIDecl& v)
{
  TRACE_VISIT ();
  CHK_ONE_DECL (hadBUriDecl, ZorbaError::XQST0032);
  sctx_p->set_baseuri(v.get_base_uri());
  return NULL;
}

void end_visit(const BaseURIDecl& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const BoundarySpaceDecl& v)
{
  TRACE_VISIT ();
  CHK_ONE_DECL (hadBSpaceDecl, ZorbaError::XQST0068);
  sctx_p->set_boundary_space_mode(v.get_boundary_space_mode());
  return NULL;
}

void end_visit(const BoundarySpaceDecl& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const CaseClause& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CaseClause& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const CaseClauseList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CaseClauseList& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const ConstructionDecl& v)
{
  TRACE_VISIT ();
  CHK_ONE_DECL (hadConstrDecl, ZorbaError::XQST0067);
  sctx_p->set_construction_mode(v.get_mode());
  return NULL;
}

void end_visit(const ConstructionDecl& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const CopyNamespacesDecl& /*v*/)
{
  TRACE_VISIT ();
  CHK_ONE_DECL (hadCopyNSDecl, ZorbaError::XQST0055);
  return no_state;
}

void end_visit(const CopyNamespacesDecl& v, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
 sctx_p->set_inherit_mode  (v.get_inherit_mode ());
 sctx_p->set_preserve_mode (v.get_preserve_mode ());
}


void *begin_visit(DefaultCollationDecl const& v)
{
  TRACE_VISIT ();
  string uri = v.get_collation();
  sctx_p->set_default_collation_uri(uri);
  return NULL;
}

void end_visit(const DefaultCollationDecl& /*v*/, void* /*visit_state*/)
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
  case ParseConstants::ns_element_default:
    sctx_p->set_default_elem_type_ns (v.get_default_namespace ());
    break;
  case ParseConstants::ns_function_default:
    sctx_p->set_default_function_namespace (v.get_default_namespace ());
    break;
  }
  return NULL;
}

void end_visit(const DefaultNamespaceDecl& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const EmptyOrderDecl& v)
{
  TRACE_VISIT ();
  CHK_ONE_DECL (hadEmptyOrdDecl, ZorbaError::XQST0069);
  sctx_p->set_order_empty_mode(v.get_mode());
  return no_state;
}

void end_visit(const EmptyOrderDecl& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


/*******************************************************************************

   Enclosed Expr
   Used in direct element/attribute constructors and in function definition.

********************************************************************************/
void *begin_visit(const EnclosedExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const EnclosedExpr& v, void* /*visit_state*/)
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

void *begin_visit(const DirCommentConstructor& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DirCommentConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  QueryLoc loc = v.get_location();
  xqpString str = v.get_comment();
  expr_t content = new const_expr (loc, str);
  nodestack.push (new text_expr(loc,
                                text_expr::comment_constructor,
                                content));
}

void *begin_visit(const DirPIConstructor& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DirPIConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  QueryLoc loc = v.get_location ();
  xqp_string target_str = v.get_pi_target ();
  if (target_str.substr (0).uppercase () == "XML")
    ZORBA_ERROR_LOC ( ZorbaError::XPST0003, loc);
  expr_t
    target = new const_expr (loc, target_str),
    content = new const_expr (loc, v.get_pi_content ());
  nodestack.push (new pi_expr (loc, target,  content));
}


void *begin_visit(const DirElemConstructor& /*v*/)
{
  TRACE_VISIT();
  push_scope();
  push_elem_scope();
  return no_state;
}

void end_visit(const DirElemConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t nameExpr;
  expr_t attrExpr;
  expr_t contentExpr;

  rchandle<QName> end_tag = v.get_end_name  ();
  if (end_tag != NULL && v.get_elem_name ()->get_qname () != end_tag->get_qname ())
    ZORBA_ERROR( ZorbaError::XPST0003);
  if (v.get_dir_content_list() != NULL)
  {
    contentExpr = pop_nodestack();
    fo_expr *lDocFilter = new fo_expr(v.get_location(), LOOKUP_OP1 ("doc-filter"));
    lDocFilter->add(contentExpr);
    contentExpr = lDocFilter;
  }

  if (v.get_attr_list() != NULL)
    attrExpr = pop_nodestack();

  nameExpr = new const_expr(v.get_location(),
                            sctx_p->lookup_elem_qname(v.get_elem_name()->get_qname()));

  nodestack.push(new elem_expr(v.get_location(),
                               nameExpr,
                               attrExpr,
                               contentExpr,
                               ns_ctx));
  pop_elem_scope();
  pop_scope();
}

/**
 * Inserts an entry in theIsWSBoundaryStack and thePossibleWSContentStack to save
 * information during boundary whitespace checking.
 */
void begin_check_boundary_whitespace() {
  if (sctx_p->boundary_space_mode() == StaticContextConsts::strip_space) {
    theIsWSBoundaryStack.push(true);
    thePossibleWSContentStack.push(0);
  }
}

/**
 * Whitespace checking. Checks if v might be a whitespace (check of the following boundary can
 * only be checked during the next invocation), and if the items saved in thePossibleWSContentStack
 * is really boundary whitespace.
 */
void check_boundary_whitespace(const DirElemContent& v) {
  v.setIsStripped(false);
  if (sctx_p->boundary_space_mode() == StaticContextConsts::strip_space) {
    bool lPrevIsBoundary = pop_stack (theIsWSBoundaryStack);
    const DirElemContent* lPrev = peek_stack (thePossibleWSContentStack);
    thePossibleWSContentStack.pop();

    if (v.get_direct_cons() != 0 || (v.get_common_content() != 0 && v.get_common_content()->get_expr() != 0)) {
      thePossibleWSContentStack.push(0);
      theIsWSBoundaryStack.push(true);
      if (lPrev != 0) {
        lPrev->setIsStripped(true);
      }
    } else if (v.get_common_content() != 0 || v.get_cdata() != 0) {
      thePossibleWSContentStack.push(0);
      theIsWSBoundaryStack.push(false);
    } else {
      bool lCouldBe = false;
      if (lPrevIsBoundary) {
        xqpString content = v.get_elem_content();
        // Filtering out of whitespaces
        if (content.trim(" \n\r\t", 4).empty()) {
          lCouldBe = true;
        }
      }
      if (lCouldBe) {
        thePossibleWSContentStack.push(&v);
      } else {
        thePossibleWSContentStack.push(0);
      }
      theIsWSBoundaryStack.push(false);
    }
  }
}

/**
 * Deletes the entries in theIsWSBoundaryStack and thePossibleWSContentStack. If thePossibleWSContentStack
 * contains an item, this item is boundary whitespace because end of content is a boundary.
 */
void end_check_boundary_whitespace() {
  if (sctx_p->boundary_space_mode() == StaticContextConsts::strip_space) {
    const DirElemContent* lPrev = pop_stack (thePossibleWSContentStack);
    if (lPrev != 0) {
      lPrev->setIsStripped(true);
    }
    theIsWSBoundaryStack.pop();
  }
}

void *begin_visit(const DirElemContentList& /*v*/)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const DirElemContentList& v, void* /*visit_state*/)
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


void *begin_visit(const DirElemContent& /*v*/)
{
  TRACE_VISIT ();

  return no_state;
}

void end_visit(const DirElemContent& v, void* /*visit_state*/)
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
    if (!v.isStripped()) {
      expr_t content = new const_expr (v.get_location (), v.get_elem_content());
      nodestack.push (new text_expr(v.get_location(),
                                    text_expr::text_constructor,
                                    content));
    }
  }
}


void *begin_visit(const CDataSection& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CDataSection& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  expr_t content = new const_expr (v.get_location (), v.get_cdata_content ());
  nodestack.push (new text_expr (v.get_location (), text_expr::text_constructor, content));
}


void *begin_visit(const DirAttributeList& v)
{
  TRACE_VISIT ();

  nodestack.push(NULL);
  // visit prefix attributes first
  for (int visitType = 0; visitType < 2; visitType++)
    for (int i = 0; i < v.size (); i++) {
      const DirAttr *attr = v [i];
      const QName* qname = attr->get_name().getp();
      bool isPrefix = qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns";
      if ((isPrefix && visitType == 0)
          || (! isPrefix && visitType == 1))
        attr->accept (*this);
    }

  unsigned long numAttrs = 0;
  std::vector<rchandle<attr_expr> > attributes;
  while(true) {
    expr_t expr = pop_nodestack();
    if (expr == NULL)
      break;

    attr_expr* attrExpr = expr.dyn_cast<attr_expr> ().getp();

    for (unsigned long i = 0; i < numAttrs; i++) {
      if (attributes[i]->getQName()->equals(attrExpr->getQName()))
         ZORBA_ERROR_LOC( ZorbaError::XQST0040, v.get_location());
    }

    attributes.push_back(attrExpr);
    numAttrs++;
  }

  if (attributes.size() == 1)
  {
    nodestack.push(attributes[0].getp());
  }
  else
  {
    fo_expr* expr_list = create_seq(v.get_location());

    for (std::vector<rchandle<attr_expr> >::reverse_iterator it = attributes.rbegin();
         it != attributes.rend();
         ++it)
    {
      expr_list->add((*it).cast<expr> ());
    }

    nodestack.push(expr_list);
  }

  return NULL;  // reject visitor -- everything done
}

void end_visit(const DirAttributeList& v, void* /*visit_state*/)
{
  // begin_visit() rejects visitor
  assert (false);
}


void *begin_visit(const DirAttr& /*v*/)
{
  TRACE_VISIT ();
  // boundary is needed because the value of an attribute might be empty
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const DirAttr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t valueExpr = pop_nodestack();

  if (valueExpr != NULL)
  {
    // delete boundary
    nodestack.pop();
  }

  QName* qname = v.get_name().getp();

  if (qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns")
  {
    xqpString prefix;

    if (qname->get_qname() == "xmlns")
    {
      // we have a defult-namespace declaration
      prefix = "";
    }
    else
    {
      prefix = qname->get_localname();
      if (prefix == "xmlns")
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XQST0070, v.get_location(),
                             "Cannot bind predefined prefix \"xmlns\"");
      }
    }

    const_expr* constValueExpr = valueExpr.dyn_cast<const_expr> ().getp();
    if (constValueExpr != NULL)
    {
      xqpString uri = constValueExpr->get_val()->getStringValue();

      if (prefix == "xml" && uri != "http://www.w3.org/XML/1998/namespace")
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XQST0070, v.get_location(),
                          "Predefined prefix \"xml\" is not bound to uri \"http://www.w3.org/XML/1998/namespace\"");
      }
      if (prefix != "xml" && uri == "http://www.w3.org/XML/1998/namespace")
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XQST0070, v.get_location(),
                          "Uri \"http://www.w3.org/XML/1998/namespace\" can only be bound to prefix \"xml\"");
      }
      sctx_p->bind_ns(prefix, uri, ZorbaError::XQST0071);
      ns_ctx->bind_ns(prefix, uri);
    }
    else if (valueExpr == NULL)
    {
      if (prefix == "xml")
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XQST0070, v.get_location(),
                          "Cannot unbind predefined prefix \"xml\"");
      }

      // unbind the prefix
      sctx_p->bind_ns(prefix, "", ZorbaError::XQST0071);
      ns_ctx->bind_ns(prefix, "");
    }
    else
    {
      ZORBA_ERROR_LOC( ZorbaError::XQST0022, v.get_location());
    }
  }
  else
  {
    expr_t nameExpr = new const_expr(v.get_location(),
                                     sctx_p->lookup_qname("", qname->get_qname()));
    expr_t attrExpr = new attr_expr(v.get_location(), nameExpr, valueExpr);
    nodestack.push(attrExpr);
  }
}


void *begin_visit(const DirAttributeValue& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DirAttributeValue& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void attr_content_list(const QueryLoc& loc, void* /*visit_state*/)
{
  rchandle<fo_expr> expr_list_t = create_seq(loc);
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
  else if (expr_list_t->size() > 1)
    nodestack.push(expr_list_t.getp());
}

void *begin_visit(const QuoteAttrContentList& /*v*/)
{
  TRACE_VISIT ();

  nodestack.push(NULL);
  return no_state;
}

void end_visit(const QuoteAttrContentList& v, void* visit_state)
{
  TRACE_VISIT_OUT ();
  attr_content_list(v.get_location (), visit_state);
}


void *begin_visit(const AposAttrContentList& /*v*/)
{
  TRACE_VISIT ();

  nodestack.push(NULL);
  return no_state;
}

void end_visit(const AposAttrContentList& v, void* visit_state)
{
  TRACE_VISIT_OUT ();
  attr_content_list (v.get_location (), visit_state);
}


void attr_val_content (const QueryLoc& loc, const CommonContent *cc, xqpString content)
{
  if (cc == NULL)
  {
    nodestack.push(new const_expr (loc, content));

    //    nodestack.push(new text_expr(loc,
    //                            text_expr::text_constructor,
    //                            new const_expr (loc, content)));
  }
  else
  {
    // nothing to be done because when common content != NULL,
    // the corresponding expr is already on the stack
  }
}

void *begin_visit(const QuoteAttrValueContent& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const QuoteAttrValueContent& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  attr_val_content (v.get_location(), v.get_common_content(), v.get_quot_atcontent());
}


void *begin_visit(const AposAttrValueContent& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AposAttrValueContent& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  attr_val_content (v.get_location(), v.get_common_content(), v.get_apos_atcontent());
}


void *begin_visit(const CommonContent& /*v*/)
{
  TRACE_VISIT ();

  return no_state;
}

void end_visit(const CommonContent& v, void* /*visit_state*/)
{
  QueryLoc loc = v.get_location ();

  switch (v.get_type())
  {
    case ParseConstants::cont_entity: assert (false); break;
    case ParseConstants::cont_charref:
    {
      string content;
      decode_entity (v.get_ref ().c_str (), &content);
      expr_t lConstExpr = new const_expr(loc, content);
      nodestack.push(lConstExpr);
      break;
    }
    case ParseConstants::cont_escape_lbrace:
    {
      // we always create a text node here because if we are in an attribute, we atomice
      // the text node into its string value
      xqpString content("{");
      expr_t lConstExpr = new const_expr(loc, content);
      nodestack.push ( lConstExpr );
      break;
    }
    case ParseConstants::cont_escape_rbrace:
    {
      // we always create a text node here because if we are in an attribute, we atomice
      // the text node into its string value
      xqpString content("}");
      expr_t lConstExpr = new const_expr(loc, content);
      nodestack.push ( lConstExpr );
      break;
    }
    case ParseConstants::cont_expr:
    {
       break;
    }
  }
  TRACE_VISIT_OUT ();
}


void *begin_visit(const CompDocConstructor& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompDocConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t lContent = pop_nodestack();

  fo_expr *lDocFilter = new fo_expr(v.get_location(), LOOKUP_OP1("doc-filter"));
  lDocFilter->add(lContent);

  fo_expr *lEnclosed = new fo_expr(v.get_location(), LOOKUP_OP1("enclosed-expr"));
  lEnclosed->add(lDocFilter);

  nodestack.push (new doc_expr (v.get_location (), lEnclosed ));
}


void *begin_visit(const CompElemConstructor& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompElemConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t nameExpr;
  expr_t contentExpr = 0;

  if (v.get_content_expr() != 0)
  {
    contentExpr = pop_nodestack();

    fo_expr *lDocFilter = new fo_expr(v.get_location(), LOOKUP_OP1 ("doc-filter"));
    lDocFilter->add(contentExpr);

    fo_expr *lEnclosed = new fo_expr(v.get_location(), LOOKUP_OP1 ("enclosed-expr"));
    lEnclosed->add(lDocFilter);
    contentExpr = lEnclosed;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName> ().getp();

  if (constQName != NULL)
  {
    nameExpr = new const_expr(v.get_location(),
                              sctx_p->lookup_elem_qname(constQName->get_qname()));
  }
  else
  {
    nameExpr = pop_nodestack();

    rchandle<fo_expr> atomExpr = new fo_expr(v.get_location(),
                                             LOOKUP_FN("fn", "data", 1));
    atomExpr->add(nameExpr);

    nameExpr = new cast_expr(v.get_location(),
                             atomExpr.getp(),
                             GENV_TYPESYSTEM.QNAME_TYPE_ONE);
  }

  nodestack.push (new elem_expr(v.get_location(), nameExpr, contentExpr, ns_ctx));
}


void *begin_visit(const CompAttrConstructor& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompAttrConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t nameExpr;
  expr_t valueExpr;
  expr_t attrExpr;

  if (v.get_val_expr() != 0)
  {
    valueExpr = pop_nodestack();

    fo_expr* docFilterExpr = new fo_expr(v.get_location(), LOOKUP_OP1 ("doc-filter"));
    docFilterExpr->add(valueExpr);

    fo_expr* enclosedExpr = new fo_expr(v.get_location(), LOOKUP_OP1("enclosed-expr"));
    enclosedExpr->add(docFilterExpr);

    valueExpr = enclosedExpr;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName> ().getp();

  if (constQName != NULL)
  {
    nameExpr = new const_expr(v.get_location(),
                              sctx_p->lookup_qname("", constQName->get_qname()));
  }
  else
  {
    nameExpr = pop_nodestack();

    rchandle<fo_expr> atomExpr = new fo_expr(v.get_location(),
                                             LOOKUP_FN("fn", "data", 1));
    atomExpr->add(nameExpr);

    expr_t castExpr = new cast_expr(v.get_location(),
                                    atomExpr.getp(),
                                    GENV_TYPESYSTEM.QNAME_TYPE_ONE);

    //fo_expr* enclosedExpr = new fo_expr(v.get_location(), LOOKUP_OP1("enclosed-expr"));
    //enclosedExpr->add(castExpr);

    nameExpr = castExpr;
  }

  attrExpr = new attr_expr(v.get_location(), nameExpr, valueExpr);

  nodestack.push(attrExpr);
}


void *begin_visit(const CompCommentConstructor& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompCommentConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t inputExpr = pop_nodestack();

  rchandle<fo_expr> enclosedExpr = new fo_expr(v.get_location(),
                                               LOOKUP_OP1("enclosed-expr"));
  enclosedExpr->add(inputExpr);

  expr_t textExpr = new text_expr(v.get_location(),
                                  text_expr::comment_constructor,
                                  enclosedExpr.getp());

  nodestack.push(textExpr);
}


void *begin_visit(const CompPIConstructor& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompPIConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  QueryLoc loc = v.get_location();
  expr_t target;
  expr_t content;

  if (v.get_content_expr() == NULL)
  {
    content = create_seq(loc);
  }
  else
  {
    content = pop_nodestack();

    rchandle<fo_expr> enclosedExpr = new fo_expr(loc, LOOKUP_OP1("enclosed-expr"));
    enclosedExpr->add(content);

    content = enclosedExpr;
  }

  if (v.get_target_expr() != NULL)
  {
    target = pop_nodestack();

    rchandle<fo_expr> atomExpr = new fo_expr(loc, LOOKUP_FN("fn", "data", 1));
    atomExpr->add(target);

    rchandle<cast_expr> castExpr =
      new cast_expr(loc, atomExpr.getp(),
                    GENV_TYPESYSTEM.NCNAME_TYPE_ONE);

    rchandle<fo_expr> enclosedExpr = new fo_expr(loc, LOOKUP_OP1("enclosed-expr"));
    enclosedExpr->add(castExpr.getp());

    target = enclosedExpr;
  }

  expr_t e = (v.get_target_expr () != NULL ?
              new pi_expr (loc, target, content) :
              new pi_expr (loc, new const_expr (loc, v.get_target()), content));

  nodestack.push (e);
}


void *begin_visit(const CompTextConstructor& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompTextConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t inputExpr = pop_nodestack();

  rchandle<fo_expr> enclosedExpr = new fo_expr(v.get_location(),
                                               LOOKUP_OP1("enclosed-expr"));
  enclosedExpr->add(inputExpr);

  expr_t textExpr = new text_expr(v.get_location(),
                                  text_expr::text_constructor,
                                  enclosedExpr.getp());

  nodestack.push(textExpr);
}


/*******************************************************************************

  FLWOR Expression

********************************************************************************/
void *begin_visit(const FLWORExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const FLWORExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  int i, j;

  rchandle<flwor_expr> flwor = new flwor_expr (v.get_location ());
  flwor->set_retval (pop_nodestack ());
  OrderByClause *orderby = &*v.get_orderby ();
  if (orderby) {
    flwor->set_order_stable (orderby->get_stable_bit ());
    OrderSpecList *order_list = &*orderby->get_spec_list ();
    int n = order_list->size ();
    for (i = 0; i < n; i++) {
      OrderSpec *spec = &*((*order_list) [i]);
      OrderModifier *mod = &*spec->get_modifier ();
      ParseConstants::dir_spec_t dir_spec = ParseConstants::dir_ascending;
      if (mod && mod->get_dir_spec () != NULL)
        dir_spec = mod->get_dir_spec ()->get_dir_spec ();
      StaticContextConsts::order_empty_mode_t empty_spec = sctx_p->order_empty_mode ();
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
  ForLetClauseList *clauses = v.get_forlet_list ().getp ();
  vector <forlet_clause *> eclauses;

  for (i = clauses->size () - 1; i >= 0; i--) {
    ForOrLetClause *clause = (*clauses) [i].getp ();
    vector<rchandle <var_expr> > vars;
    vector<rchandle <var_expr> > pos_vars;
    vector<rchandle <expr> > exprs;
    int size = clause->get_decl_count ();

    if (clause->for_or_let () == ForOrLetClause::for_clause) {
      ForClause *forclause = static_cast<ForClause *> (clause);
      VarInDeclList *decl_list = &*forclause->get_vardecl_list ();

      for (j = size - 1; j >= 0; j--) {
        var_expr_t ve;
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
          var_expr_t pve = pop_nodestack ().cast<var_expr> ();
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
      for (j = 0; j < size; j++) {
        var_expr_t ve = pop_nodestack ().cast<var_expr> ();
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

  nodestack.push (&*flwor);
}


void *begin_visit(const ForLetClauseList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ForLetClauseList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const LetClause& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const LetClause& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarGetsDecl& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarGetsDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  push_scope ();
  bind_var_and_push (v.get_location (), v.get_varname (), var_expr::let_var, v.get_typedecl () == NULL ? NULL : pop_tstack ());
}


void *begin_visit(const ForClause& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ForClause& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarInDecl& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarInDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  QueryLoc loc = v.get_location ();

  push_scope ();
  const PositionalVar *pv = v.get_posvar ();
  xqp_string varname = v.get_varname ();
  if (pv != NULL) {
    expr_t val_expr = pop_nodestack ();
    xqp_string pvarname = pv->get_varname ();
    if (pvarname == varname)
      ZORBA_ERROR_LOC (ZorbaError::XQST0089, loc);
    bind_var_and_push (pv->get_location (), pvarname, var_expr::pos_var);
    nodestack.push (val_expr);
  }
  bind_var_and_push (loc, v.get_varname (), var_expr::for_var, v.get_typedecl () == NULL ? NULL : pop_tstack ());
}

void *begin_visit(const PositionalVar& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const PositionalVar& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const WhereClause& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const WhereClause& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const OrderByClause& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderByClause& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderSpecList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderSpecList& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderSpec& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderSpec& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderModifier& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderModifier& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderCollationSpec& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderCollationSpec& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderDirSpec& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderDirSpec& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderEmptySpec& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderEmptySpec& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/

void *begin_visit(const VarDecl& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  global_vars.push_back(global_binding(bind_var(v.get_location(),
                                                v.get_varname(),
                                                var_expr::let_var),
                                       v.is_extern() ? expr_t(NULL) : pop_nodestack()));
}


void *begin_visit(const FunctionDecl& /*v*/)
{
  TRACE_VISIT ();
  push_scope ();
  return no_state;
}

void end_visit(const FunctionDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  switch(v.get_type()) {
    case ParseConstants::fn_read:
      {
        expr_t body = pop_nodestack ();
        if (v.get_return_type () != NULL)
          pop_tstack ();

        int nargs = v.get_param_count ();
        vector<var_expr_t> params;
        if (nargs > 0) {
          rchandle<flwor_expr> flwor = pop_nodestack().dyn_cast<flwor_expr> ();
          ZORBA_ASSERT(flwor != NULL);

          for(int i = 0; i < nargs; ++i) {
            rchandle<forlet_clause>& flc = (*flwor)[i];
            var_expr *param_var = flc->get_expr().dyn_cast<var_expr> ().getp ();
            ZORBA_ASSERT(param_var != NULL);
            params.push_back(param_var);
          }
          flwor->set_retval(body);
          body = &*flwor;
        }

        user_function *udf = dynamic_cast<user_function *>(LOOKUP_FN(v.get_name ()->get_prefix (), v.get_name ()->get_localname (), nargs));
        ZORBA_ASSERT (udf != NULL);

        assert (body != NULL);
        if (print_translated) {
          cout << "Expression tree for " << v.get_name ()->get_qname () << " after translation:" << endl;
          body->put(cout) << endl;
        }
        normalize_expr_tree (Properties::instance ()->printNormalizedExpressions ()
                             ? v.get_name ()->get_qname ().c_str () : NULL,
                             compilerCB, body);

        if (compilerCB->m_config.opt_level == CompilerCB::config_t::O1) {
          RewriterContext rCtx(compilerCB, body);
          GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
          body = rCtx.getRoot();
          if (Properties::instance ()->printOptimizedExpressions ()) {
            cout << "Optimized expression tree for " << v.get_name ()->get_qname () << endl;
            body->put (cout) << endl;
          }
        }

        udf->set_body (body);
        udf->set_params(params);
      }
      break;
    default:
      break;
  }
  pop_scope ();
}


void *begin_visit(const GeneralComp& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const GeneralComp& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const LibraryModule& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const LibraryModule& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const MainModule & /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const MainModule & /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const Module& /*v*/)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const Module& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const ModuleDecl& /*v*/)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const ModuleDecl& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const ModuleImport& /*v*/)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const ModuleImport& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const NamespaceDecl& v)
{
  TRACE_VISIT ();
  sctx_p->bind_ns (v.get_prefix (), v.get_uri ());
  return NULL;
}

void end_visit(const NamespaceDecl& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}

void *begin_visit(const NodeComp& /*v*/)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const NodeComp& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const OptionDecl& /*v*/)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const OptionDecl& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const OrderingModeDecl& v)
{
  TRACE_VISIT ();
  CHK_ONE_DECL (hadOrdModeDecl, ZorbaError::XQST0065);
  sctx_p->set_ordering_mode(v.get_mode());
  return NULL;
}


void end_visit(const OrderingModeDecl& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}

void *begin_visit(const Param& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Param& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  rchandle<flwor_expr> flwor = nodestack.top().cast<flwor_expr> ();
  ZORBA_ASSERT(flwor != NULL);
  store::Item_t qname = sctx_p->lookup_qname ("", v.get_name());
  var_expr_t param_var = new var_expr (v.get_location(), var_expr::param_var, qname);
  var_expr_t subst_var = new var_expr(v.get_location(), var_expr::let_var, qname);
  flwor->add(wrap_in_letclause(&*param_var, subst_var));
  sctx_p->bind_var(qname, subst_var);
  if (v.get_typedecl () != NULL) {
    param_var->set_type (pop_tstack ());
    subst_var->set_type(param_var->get_type());
  }
}


void *begin_visit(const ParamList& v)
{
  TRACE_VISIT ();
  if (v.size() > 0) {
    nodestack.push(new flwor_expr(v.get_location()));
  }
  return no_state;
}

void end_visit(const ParamList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const Pragma& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Pragma& v, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
 // may raise XPST0081
 sctx_p->lookup_ns (v.get_name ()->get_prefix ());
}

void *begin_visit(const PragmaList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const PragmaList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const PredicateList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const PredicateList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const Prolog& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Prolog& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const QVarInDecl& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const QVarInDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  push_scope ();
  bind_var_and_push (v.get_location (), v.get_name (), var_expr::for_var);
}


void *begin_visit(const QVarInDeclList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const QVarInDeclList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SIND_DeclList& /*v*/)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const SIND_DeclList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

}


void *begin_visit(const SchemaImport& v)
{
  TRACE_VISIT ();
  SchemaPrefix *sp = &*v.get_prefix();
  if (sp != NULL) {
    sctx_p->bind_ns (sp->get_prefix (), v.get_uri ());
  }

#if 0
  std::string prefix = ((SchemaPrefix*)(v.get_prefix().getp()))->get_prefix();
  std::string uri = v.get_uri();

  // TODO: get_at_list() might return NULL
  rchandle<URILiteralList> atlist = v.get_at_list();
  if (atlist != NULL) {
    std::string at = (*atlist) [0];
  }
  //std::cout << "SchemaImport: " << prefix << " : " << uri
  //    << " @ " << at << std::endl;
  //std::cout << " Context: " << sctx_p->get_typemanager() << "\n";

  //((DelegatingTypeManager*)sctx_p->get_typemanager())->initializeSchema();
  //Schema* schema_p = ((DelegatingTypeManager*)sctx_p->get_typemanager())->getSchema();

  //schema_p->registerXSD(at.c_str());	
  //schema_p->printXSDInfo();
#endif

  return no_state;
}

void end_visit(const SchemaImport& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const SchemaPrefix& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const SchemaPrefix& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SignList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const SignList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SingleType& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const SingleType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  if (v.get_hook_bit ())
    tstack.push (sctx_p->get_typemanager()->create_type (*pop_tstack (), TypeConstants::QUANT_QUESTION));
  // else leave type as it is on tstack
}


void *begin_visit(const TypeDeclaration& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TypeDeclaration& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const TypeName& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TypeName& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const URILiteralList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const URILiteralList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const ValueComp& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ValueComp& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const VersionDecl& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VersionDecl& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const VFO_DeclList& v)
{
  TRACE_VISIT ();

  // Function declaration translation must be done in two passes
  // because of mutually recursive functions. So, here's the 1st pass.
  for (vector<rchandle<parsenode> >::const_iterator it = v.begin();
       it != v.end(); ++it)
  {
    const FunctionDecl *n = it->dyn_cast<FunctionDecl> ().getp ();
    if (n != NULL) {
      rchandle<ParamList> params = n->get_paramlist ();
      if (params == NULL) params = new ParamList (n->get_location ());
      std::vector<xqtref_t> arg_types;
      for (std::vector<rchandle<Param> >::const_iterator it = params->begin ();
           it != params->end (); ++it)
      {
        const Param *p = (*it).getp ();
        const TypeDeclaration *td = p->get_typedecl ().getp ();
        if (td == NULL)
          arg_types.push_back (GENV_TYPESYSTEM.ITEM_TYPE_STAR);
        else {
          td->accept (*this);
          arg_types.push_back (pop_tstack ());
        }
      }
      int nargs = params->size();

      xqtref_t return_type = GENV_TYPESYSTEM.ITEM_TYPE_STAR;
      if (n->get_return_type () != NULL) {
        n->get_return_type ()->accept (*this);
        return_type = pop_tstack ();
      }
      store::Item_t qname = sctx_p->lookup_fn_qname (n->get_name ()->get_prefix (), n->get_name ()->get_localname ());
      signature sig(qname, arg_types, return_type);
      switch(n->get_type()) {
        case ParseConstants::fn_extern:
          {
            StatelessExternalFunction *ef = sctx_p->lookup_stateless_external_function(
              n->get_name()->get_prefix(), n->get_name()->get_localname());
            ZORBA_ASSERT(ef != NULL);
            sctx_p->bind_fn(qname, new stateless_external_function_adapter(sig, ef), nargs);
          }
          break;

        case ParseConstants::fn_read:
          sctx_p->bind_fn (qname, new user_function (n->get_location(), sig, NULL), nargs);
          break;
        default:
          ZORBA_ASSERT(false);
      }
    }
  }
  return no_state;
}

void end_visit(const VFO_DeclList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const AdditiveExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AdditiveExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  function *func = NULL;
  switch (v.get_add_op()) {
  case ParseConstants::op_plus:
    func = LOOKUP_OP2 ("add");
    break;
  case ParseConstants::op_minus:
    func = LOOKUP_OP2 ("subtract");
    break;
  }
  fo_expr *fo_h = new fo_expr(v.get_location(), func);
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


void *begin_visit(const AndExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AndExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_h = new fo_expr(v.get_location(), LOOKUP_OPN ("and"));
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


/// Creates a cast_expr or castable_expr.
expr_t create_cast_expr (const QueryLoc& loc, expr_t node, xqtref_t type, bool isCast) {
  if (TypeOps::get_atomic_type_code (*type) != TypeConstants::XS_QNAME) {
    if (isCast)
      return new cast_expr (loc, node, type);
    else
      return new castable_expr (loc, node, type);
  } else {  // a QName cast
    const const_expr *ce = node.dyn_cast<const_expr> ().getp();
    if (ce != NULL
        && TypeOps::is_equal (*sctx_p->get_typemanager()->create_type (ce->get_val ()->getType (), TypeConstants::QUANT_ONE),
                              *GENV_TYPESYSTEM.STRING_TYPE_ONE))
      {
        store::Item_t castLiteral = GenericCast::instance()->castToQName (ce->get_val ()->getStringValue(), isCast, true);
        if (castLiteral != NULL) {
          xqp_string pre = castLiteral->getPrefix ();
          if (! pre.empty ()) {
            xqp_string ns = sctx_p->lookup_ns (pre, isCast ? ZorbaError::FONS0004 : ZorbaError::XPST0081);
            castLiteral = ITEM_FACTORY->createQName(ns.getStore (), pre.getStore (), castLiteral->getLocalName ().getStore ());
          }
        }
        if (isCast)
          return new const_expr (loc, castLiteral);
        else
          return new const_expr (loc, castLiteral != NULL);
      } else {
      if (isCast)
        return new treat_expr (loc, node, type, ZorbaError::XPTY0004);
      else
        return new instanceof_expr (loc, node, type);
    }
  }
}

void *begin_visit(const CastExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CastExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  nodestack.push (create_cast_expr (v.get_location (), pop_nodestack (), pop_tstack (), true));
}

void *begin_visit(const CastableExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CastableExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  nodestack.push (create_cast_expr (v.get_location (), pop_nodestack (), pop_tstack (), false));
}


void *begin_visit(const ComparisonExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ComparisonExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  function *f = NULL;
  if (v.get_gencomp()!=NULL) {
    switch (v.get_gencomp()->get_type()) {
    case ParseConstants::op_eq:
      f = (LOOKUP_OP2 ("equal"));
      break;
    case ParseConstants::op_ne:
      f = (LOOKUP_OP2 ("not-equal"));
      break;
    case ParseConstants::op_lt:
      f = (LOOKUP_OP2 ("less"));
      break;
    case ParseConstants::op_le:
      f = (LOOKUP_OP2 ("less-equal"));
      break;
    case ParseConstants::op_gt:
      f = (LOOKUP_OP2 ("greater"));
      break;
    case ParseConstants::op_ge:
      f = (LOOKUP_OP2 ("greater-equal"));
      break;
    }
  } else if (v.get_valcomp () != NULL) {
    switch (v.get_valcomp()->get_type()) {
    case ParseConstants::op_val_eq:
      f = (LOOKUP_OP2 ("value-equal"));
      break;
    case ParseConstants::op_val_ne:
      f = (LOOKUP_OP2 ("value-not-equal"));
      break;
    case ParseConstants::op_val_lt:
      f = (LOOKUP_OP2 ("value-less"));
      break;
    case ParseConstants::op_val_le:
      f = (LOOKUP_OP2 ("value-less-equal"));
      break;
    case ParseConstants::op_val_gt:
      f = (LOOKUP_OP2 ("value-greater"));
      break;
    case ParseConstants::op_val_ge:
      f = (LOOKUP_OP2 ("value-greater-equal"));
      break;
    }
  } else if (v.get_nodecomp()!=NULL) {
    switch (v.get_nodecomp()->get_type()) {
    case ParseConstants::op_is:
      f = (LOOKUP_OP2 ("is-same-node"));
      break;
    case ParseConstants::op_precedes:
      f = (LOOKUP_OP2 ("node-before"));
      break;
    case ParseConstants::op_follows:
      f = (LOOKUP_OP2 ("node-after"));
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



void *begin_visit(const ContextItemExpr& /*v*/)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const ContextItemExpr& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  var_expr *e = static_cast<var_expr *> (sctx_p->lookup_var_nofail (DOT_VAR));
  nodestack.push(e);
}


void *begin_visit(const Expr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Expr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  if (v.numberOfChildren () > 1) {
    fo_expr *elist_h = create_seq (v.get_location());
    for (int i = 0; i < v.numberOfChildren (); i++) {
      expr_t e_h = pop_nodestack();
      elist_h->add(e_h);
    }
    nodestack.push(elist_h);
  }
}

// void *begin_visit(const ExprSingle& v)
// {
// TRACE_VISIT ();
//  return no_state;
// }

void *begin_visit(const ExtensionExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ExtensionExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  if (v.get_expr () == NULL)
    ZORBA_ERROR( ZorbaError::XQST0079);
}

void *begin_visit(const FilterExpr& /*v*/)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const FilterExpr& /*v*/, void* /*visit_state*/)
{
TRACE_VISIT_OUT ();
}

void *begin_visit(const FunctionCall& /*v*/)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const FunctionCall& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  QueryLoc loc = v.get_location ();

  std::vector<expr_t> arguments;
  while (true) {
    expr_t e_h = pop_nodestack();
    if (e_h == NULL)
      break;
    arguments.push_back(e_h);
  }
  int sz = arguments.size ();

  rchandle<QName> qn_h = v.get_fname();
  string prefix = qn_h->get_prefix();
  string fname = qn_h->get_localname();

  store::Item_t fn_qname = sctx_p->lookup_fn_qname(prefix, fname);

  if (fn_qname->getNamespace() == XQUERY_FN_NS) {
    xqp_string fn_local = fn_qname->getLocalName ();
    if (fn_local == "position") {
      nodestack.push(sctx_p->lookup_var_nofail (DOT_POS_VAR));
      return;
    } else if (fn_local == "last") {
      nodestack.push(sctx_p->lookup_var_nofail(LAST_IDX_VAR));
      return;
    } else if (fn_local == "string") {
      // TODO: casting to xs:string? is almost correct;
      // it fails, however, the following test:
      // 'fn:string (()) instance of xs:string'
      fn_qname = sctx_p->lookup_fn_qname("xs", "string");
      switch (sz) {
      case 0:
        arguments.push_back (sctx_p->lookup_var_nofail (DOT_VAR));
        break;
      case 1:
        break;
      default:
        ZORBA_ERROR_PARAM ( ZorbaError::XPST0017,  "fn:string", sz );
      }
    } else if (fn_local == "number") {
      switch (sz) {
      case 0:
        arguments.push_back (sctx_p->lookup_var_nofail (DOT_VAR));
        break;
      case 1:
        break;
      default:
        ZORBA_ERROR_PARAM ( ZorbaError::XPST0017, "fn:number", sz );
      }
      var_expr_t tv = tempvar (loc, var_expr::let_var);
      expr_t nan_expr = new const_expr (loc, xqp_double::nan ());
      expr_t ret = new if_expr (loc, new castable_expr (loc, &*tv, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE), new cast_expr (loc, &*tv, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE), nan_expr);
      expr_t data_expr = new fo_expr (loc, LOOKUP_FN("fn", "data", 1), arguments [0]);
      nodestack.push (&*wrap_in_let_flwor (new treat_expr (loc, data_expr, GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, ZorbaError::XPTY0004), tv, ret));
      return;
    } else if (sz == 0 &&
               (fn_local == "string-length" || fn_local == "normalize-space"
                || fn_local == "base-uri" || fn_local == "namespace-uri"
                || fn_local == "local-name"))
    {
      arguments.push_back (sctx_p->lookup_var_nofail (DOT_VAR));
    } else if (fn_local == "static-base-uri") {
      if (sz != 0)
        ZORBA_ERROR_PARAM ( ZorbaError::XPST0017, "fn:static-base-uri", sz );
      xqp_string baseuri = sctx_p->baseuri ();
      if (baseuri.empty ())
        nodestack.push (create_seq (loc));
      else
        nodestack.push (new cast_expr (loc, new const_expr (loc, baseuri), GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));
      return;
    } else if (sz == 1 && fn_local == "lang") {
      arguments.insert (arguments.begin (), sctx_p->lookup_var_nofail (DOT_VAR));
    } else if (sz == 1 && fn_local == "resolve-uri") {
      // TODO: check if static base uri is defined, throw FONS0005 if not
      arguments.insert (arguments.begin (), new const_expr (loc, sctx_p->baseuri()));
    }
  }
  sz = arguments.size ();  // recompute size

  // try constructor functions
  xqtref_t type =
    sctx_p->get_typemanager()->create_type (fn_qname, TypeConstants::QUANT_QUESTION);

  if (type != NULL && fn_qname->getStringValue () != "xs:anyAtomicType")
  {
    if (sz != 1)
      ZORBA_ERROR_PARAM ( ZorbaError::XPST0017,  prefix + ":" + fname, sz);
    nodestack.push (create_cast_expr (loc, arguments [0], type, true));
  }
  else
  {
    rchandle<fo_expr> fo_h = new fo_expr (loc, LOOKUP_FN (prefix, fname, sz));

    // TODO this should be a const iterator
    std::vector<expr_t>::reverse_iterator iter = arguments.rbegin();
    for(; iter != arguments.rend(); ++iter) {
      fo_h->add(*iter);
    }

    nodestack.push(&*fo_h);
  }
}

void *begin_visit(const IfExpr& /*v*/)
{
TRACE_VISIT ();
  // nothing to do here
  return no_state;
}

void end_visit(const IfExpr& v, void* /*visit_state*/)
{
TRACE_VISIT_OUT ();
  expr_t e_h = pop_nodestack ();
  expr_t t_h = pop_nodestack ();
  expr_t c_h = pop_nodestack ();

  nodestack.push(new if_expr(v.get_location(),c_h,t_h,e_h));
}


void *begin_visit(const InstanceofExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const InstanceofExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  nodestack.push(new instanceof_expr(v.get_location(), pop_nodestack(), pop_tstack()));
}


void *begin_visit(const IntersectExceptExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const IntersectExceptExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  function *f = NULL;
  switch (v.get_intex_op()) {
  case ParseConstants::op_intersect:
    f = LOOKUP_OP2 ("intersect");
    break;
  case ParseConstants::op_except:
    f = LOOKUP_OP2 ("except");
    break;
  }

  fo_expr *fo_h = new fo_expr(v.get_location(), f);

  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push(fo_h);
}

void *begin_visit(const MultiplicativeExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const MultiplicativeExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  function *f = NULL;
  switch (v.get_mult_op()) {
  case ParseConstants::op_mul:
    f = LOOKUP_OP2 ("multiply");
    break;
  case ParseConstants::op_div:
    f = LOOKUP_OP2 ("divide");
    break;
  case ParseConstants::op_idiv:
    f = LOOKUP_OP2 ("integer-divide");
    break;
  case ParseConstants::op_mod:
    f = LOOKUP_OP2 ("mod");
    break;
  }
  fo_expr *fo_h = new fo_expr(v.get_location(), f);
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}

void *begin_visit(const NumericLiteral& /*v*/)
{
TRACE_VISIT ();
  return no_state;
}

void end_visit(const NumericLiteral& v, void* /*visit_state*/)
{
TRACE_VISIT_OUT ();
  switch (v.get_type()) {
  case ParseConstants::num_integer: {
    nodestack.push(new const_expr(v.get_location(), (xqp_integer) v.get_int()));
    break;
  }
  case ParseConstants::num_decimal: {
    nodestack.push(new const_expr(v.get_location(), (xqp_decimal) v.get_decimal()));
    break;
  }
  case ParseConstants::num_double: {
    nodestack.push(new const_expr(v.get_location(), (xqp_double) v.get_double()));
    break;
  }
  }
}

void *begin_visit(const OrExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_p = new fo_expr(v.get_location(), LOOKUP_OPN ("or"));
  fo_p->add(e2_h);
  fo_p->add(e1_h);
  nodestack.push (fo_p);
}

void *begin_visit(const OrderedExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new order_expr (v.get_location (), order_expr::ordered,
                                  pop_nodestack ()));
}


void *begin_visit(const ParenthesizedExpr& /*v*/)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const ParenthesizedExpr& v, void* /*visit_state*/)
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

  Sequence Type Matching

  A SequenceType parsenode has 2 children: The right child is always an
  OccurrenceIndicator node. The left child may be either an AtomicType node,
  or one of the 9 kind-test nodes (elementTest, documentTest, ... etc), or
  an ItemType node. ItemType respesents the expression item().

********************************************************************************/

void *begin_visit(const SequenceType& v)
{
  TRACE_VISIT ();
  if (v.get_itemtype () == NULL && v.get_occur () == NULL) {
    tstack.push (GENV_TYPESYSTEM.EMPTY_TYPE);
    return NULL;
  }
  return no_state;
}

void end_visit(const SequenceType& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const OccurrenceIndicator& v)
{
  TRACE_VISIT ();
  TypeConstants::quantifier_t q = TypeConstants::QUANT_STAR;
  switch (v.get_type ()) {
  case ParseConstants::occurs_exactly_one:
    q = TypeConstants::QUANT_ONE; break;
  case ParseConstants::occurs_one_or_more:
    q = TypeConstants::QUANT_PLUS; break;
  case ParseConstants::occurs_optionally:
    q = TypeConstants::QUANT_QUESTION; break;
  case ParseConstants::occurs_zero_or_more:
    q = TypeConstants::QUANT_STAR; break;
  case ParseConstants::occurs_never:
    ZORBA_ASSERT (false);
  }

  if (q != TypeConstants::QUANT_ONE)
    tstack.push (sctx_p->get_typemanager()->create_type (*pop_tstack (), q));

  return no_state;
}

void end_visit(const OccurrenceIndicator& /*v*/, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
}


void *begin_visit(const AtomicType& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AtomicType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  rchandle<QName> qname = v.get_qname ();
  xqtref_t t =
    sctx_p->get_typemanager()->create_atomic_type(sctx_p->lookup_qname("",
                                                            qname->get_prefix (),
                                                            qname->get_localname ()),
                                TypeConstants::QUANT_ONE);
  // some types that should never be parsed, like xs:untyped, are;
  // we catch them with is_simple()
  if (t == NULL)
    ZORBA_ERROR( ZorbaError::XPST0051);
  else
    tstack.push (t);
}


void *begin_visit(const ItemType& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ItemType& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  tstack.push (GENV_TYPESYSTEM.ITEM_TYPE_ONE);
}


/*******************************************************************************

  NodeTest (NameTest | KindTest)

********************************************************************************/
void *begin_visit(const NameTest& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}



void end_visit(const NameTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr *top = &*nodestack.top();

  axis_step_expr *axisExpr = NULL;
  trycatch_expr *tce = NULL;

  if ((axisExpr = dynamic_cast<axis_step_expr *>(top)) != NULL) {
    // Construct name-test match expr
    rchandle<match_expr> matchExpr = new match_expr(v.get_location());;
    matchExpr->setTestKind(match_name_test);

    if (v.getQName() != NULL)
    {
      string qname = v.getQName()->get_qname();
      store::Item_t qn_h = sctx_p->lookup_elem_qname (qname);
      matchExpr->setQName(qn_h);
    }
    else
    {
      rchandle<Wildcard> wildcard = v.getWildcard();
      ZORBA_ASSERT(wildcard != NULL);

      switch (wildcard->getKind())
      {
        case ParseConstants::wild_all:
          matchExpr->setWildKind(match_all_wild);
          break;
        case ParseConstants::wild_elem:
          matchExpr->setWildKind(match_name_wild);
          matchExpr->setWildName(wildcard->getPrefix());
          break;
        case ParseConstants::wild_prefix:
          matchExpr->setWildKind(match_prefix_wild);
          matchExpr->setWildName(wildcard->getLocalName());
          break;
      }
    }

    // add the match expression
    axisExpr->setTest(matchExpr);
  } else if ((tce = dynamic_cast<trycatch_expr *>(top)) != NULL) {
    catch_clause *cc = &*(*tce)[0];
    if (v.getQName() != NULL)
    {
      string qname = v.getQName()->get_qname();
      store::Item_t qn_h = sctx_p->lookup_elem_qname (qname);
      cc->nametest_h = new NodeNameTest(qn_h);
    }
    else
    {
      rchandle<Wildcard> wildcard = v.getWildcard();
      ZORBA_ASSERT(wildcard != NULL);

      switch (wildcard->getKind())
      {
        case ParseConstants::wild_all:
          cc->nametest_h = new NodeNameTest(xqpString("*").theStrStore, xqpString("*").theStrStore);
          break;
        case ParseConstants::wild_elem:
          cc->nametest_h = new NodeNameTest(xqpString("*").theStrStore, wildcard->getPrefix().theStrStore);
          break;
        case ParseConstants::wild_prefix:
          cc->nametest_h = new NodeNameTest(wildcard->getLocalName().theStrStore, xqpString("*").theStrStore);
          break;
      }
    }
  } else {
    ZORBA_ASSERT(false);
  }
}


void *begin_visit(const Wildcard& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const Wildcard& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const QName& /*v*/)
{
  TRACE_VISIT();
  ZORBA_ASSERT(0);
  return no_state;
}


void end_visit(const QName& /*v*/, void* /*visit_state*/)
{
  ZORBA_ASSERT(0);
  TRACE_VISIT_OUT ();
}


void *begin_visit(const AnyKindTest& /*v*/)
{
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit(const AnyKindTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> me = new match_expr(v.get_location());
    me->setTestKind(match_anykind_test);
    axisExpr->setTest(me);
  }
  else
  {
    xqtref_t seqmatch = sctx_p->get_typemanager()->
      create_node_type(NodeTest::ANY_NODE_TEST, NULL, TypeConstants::QUANT_ONE);

    tstack.push(seqmatch);
  }
}


void *begin_visit(const DocumentTest& /*v*/)
{
  TRACE_VISIT ();

  return no_state;
}


void end_visit(const DocumentTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  rchandle<ElementTest> elemTest = v.get_elem_test();

  if (elemTest == NULL)
  {
    axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
    if (axisExpr != NULL)
    {
      rchandle<match_expr> match = new match_expr(v.get_location());
      match->setTestKind(match_doc_test);

      axisExpr->setTest(match);
    }
    else
    {
      rchandle<NodeTest> nodeTest = new NodeTest(store::StoreConsts::documentNode);

      xqtref_t seqmatch = sctx_p->get_typemanager()->
        create_node_type(nodeTest, NULL, TypeConstants::QUANT_ONE);

      tstack.push(seqmatch);
    }
  }
  else
  {
    rchandle<QName> elemName = elemTest->getElementName();
    rchandle<TypeName> typeName = elemTest->getTypeName();
    bool nilled =  elemTest->isNilledAllowed();

    axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
    if (axisExpr != NULL)
    {
      rchandle<match_expr> match = new match_expr(v.get_location());
      match->setTestKind(match_doc_test);

      if (elemName != NULL)
        match->setQName(sctx_p->lookup_elem_qname(elemName->get_qname()));

      if (typeName != NULL)
        match->setTypeName(sctx_p->lookup_elem_qname(typeName->get_name()->get_qname()));

      if (nilled)
        match->setNilledAllowed(true);

      axisExpr->setTest(match);
    }
    else
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED, v.get_location(), "Document kind test");
    }
  }
}


void *begin_visit(const ElementTest& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ElementTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  rchandle<QName> elemName = v.getElementName();
  rchandle<TypeName> typeName = v.getTypeName();
  bool nilled =  v.isNilledAllowed();

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> me = new match_expr(v.get_location());
    me->setTestKind(match_elem_test);

    if (elemName != NULL)
      me->setQName(sctx_p->lookup_elem_qname(elemName->get_qname()));

    if (typeName != NULL)
      me->setTypeName(sctx_p->lookup_elem_qname(typeName->get_name()->get_qname()));

    if (nilled)
      me->setNilledAllowed(true);

    axisExpr->setTest(me);
  }

  // Else, create a sequence-type match
  else
  {
    if (nilled)
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED, v.get_location(), "schema types");
    }

    rchandle<NodeTest> nodeTest;
    if (elemName != NULL)
    {
      store::Item_t qnameItem = sctx_p->lookup_elem_qname(elemName->get_qname());

      rchandle<NodeNameTest> nodeNameTest =
        new NodeNameTest(qnameItem->getNamespace().getStore(),
                         qnameItem->getLocalName().getStore());

      nodeTest = new NodeTest(store::StoreConsts::elementNode, nodeNameTest);
    }
    else
    {
      nodeTest = new NodeTest(store::StoreConsts::elementNode);
    }

    xqtref_t contentType;
    if (typeName != NULL)
    {
      store::Item_t qnameItem = sctx_p->lookup_elem_qname(typeName->get_name()->get_qname());

      contentType = sctx_p->get_typemanager()->create_type(qnameItem, TypeConstants::QUANT_ONE);
    }

    xqtref_t seqmatch = sctx_p->get_typemanager()->
      create_node_type(nodeTest, contentType, TypeConstants::QUANT_ONE);

    tstack.push(seqmatch);
  }
}


void *begin_visit(const AttributeTest& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const AttributeTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<QName> attrName = v.get_attr_name();
  rchandle<TypeName> typeName = v.get_type_name();

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> match = new match_expr(v.get_location());
    match->setTestKind(match_attr_test);

    if (attrName != NULL)
      match->setQName(sctx_p->lookup_qname("", attrName->get_qname()));

    if (typeName != NULL)
      match->setTypeName(sctx_p->lookup_elem_qname(typeName->get_name()->get_qname()));

    axisExpr->setTest(match);
  }
  else
  {
    rchandle<NodeTest> nodeTest;
    if (attrName != NULL)
    {
      store::Item_t qnameItem = sctx_p->lookup_qname("", attrName->get_qname());

      rchandle<NodeNameTest> nodeNameTest =
        new NodeNameTest(qnameItem->getNamespace().getStore(),
                         qnameItem->getLocalName().getStore());

      nodeTest = new NodeTest(store::StoreConsts::attributeNode, nodeNameTest);
    }
    else
    {
      nodeTest = new NodeTest(store::StoreConsts::attributeNode);
    }

    xqtref_t contentType;
    if (typeName != NULL)
    {
      store::Item_t qnameItem = sctx_p->lookup_elem_qname(typeName->get_name()->get_qname());

      contentType = sctx_p->get_typemanager()->create_type(qnameItem, TypeConstants::QUANT_ONE);
    }

    xqtref_t seqmatch = sctx_p->get_typemanager()->
      create_node_type(nodeTest, contentType, TypeConstants::QUANT_ONE);

    tstack.push(seqmatch);
  }
}


void *begin_visit(const TextTest& /*v*/)
{
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit(const TextTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> match = new match_expr(v.get_location());
    match->setTestKind(match_text_test);
    axisExpr->setTest(match);
  }
  else
  {
    xqtref_t seqmatch = sctx_p->get_typemanager()->
      create_node_type(NodeTest::TEXT_TEST, NULL, TypeConstants::QUANT_ONE);

    tstack.push(seqmatch);
  }
}


void *begin_visit(const CommentTest& /*v*/)
{
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit(const CommentTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> match = new match_expr(v.get_location());
    match->setTestKind(match_comment_test);
    axisExpr->setTest(match);
  }
  else
  {
    xqtref_t seqmatch = sctx_p->get_typemanager()->
      create_node_type(NodeTest::COMMENT_TEST, NULL, TypeConstants::QUANT_ONE);

    tstack.push(seqmatch);
  }
}


void *begin_visit(const PITest& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const PITest& v, void* /*visit_state*/)
{
 TRACE_VISIT_OUT ();
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    string target = v.get_target();
    rchandle<match_expr> match = new match_expr(v.get_location());
    match->setTestKind(match_pi_test);
    if (target != "")
      match->setQName(sctx_p->lookup_elem_qname(target));
    axisExpr->setTest(match);
  }
  else
  {
    xqtref_t seqmatch = sctx_p->get_typemanager()->
      create_node_type(NodeTest::PI_TEST, NULL, TypeConstants::QUANT_ONE);

    tstack.push(seqmatch);
  }
}


void *begin_visit(const SchemaAttributeTest& v)
{
  TRACE_VISIT ();
  rchandle<match_expr> match = new match_expr(v.get_location());
  match->setTestKind(match_xs_attr_test);

  rchandle<QName> attr_h = v.get_attr();
  if (attr_h!=NULL) {
    match->setQName(sctx_p->lookup_elem_qname (attr_h->get_qname()));
  }
  nodestack.push(&*match);
  return no_state;
}


void end_visit(const SchemaAttributeTest& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const SchemaElementTest& v)
{
  TRACE_VISIT ();
  rchandle<match_expr> match = new match_expr(v.get_location());
  match->setTestKind(match_xs_elem_test);

  rchandle<QName> elem_h = v.get_elem();
  if (elem_h!=NULL) {
    match->setQName (sctx_p->lookup_qname ("", elem_h->get_qname()));
  }
  nodestack.push(&*match);
  return no_state;
}


void end_visit(const SchemaElementTest& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

var_expr_t tempvar(const QueryLoc& loc, var_expr::var_kind kind)
{
  xqpString empty;
  xqpString lname("$$temp" + to_string(tempvar_counter++));

  return new var_expr(loc, kind,
                      ITEM_FACTORY->createQName(empty.getStore (), empty.getStore (), lname.getStore ()));
}


rchandle<forlet_clause> wrap_in_forclause(
    expr_t expr,
    var_expr_t fv,
    var_expr_t pv)
{
  assert (fv->get_kind () == var_expr::for_var);
  if (pv != NULL)
    assert (pv->get_kind() == var_expr::pos_var);
  return new forlet_clause(forlet_clause::for_clause, fv, pv, NULL, expr.getp());
}

rchandle<forlet_clause> wrap_in_forclause(expr_t expr, bool add_posvar)
{
  var_expr_t fv = tempvar(expr->get_loc(), var_expr::for_var);
  var_expr_t pv = add_posvar
    ? tempvar(expr->get_loc(), var_expr::pos_var)
    : var_expr_t (NULL);
  return wrap_in_forclause (expr, fv, pv);
}

rchandle<forlet_clause> wrap_in_forclause(
    expr_t expr,
    const QueryLoc& loc,
    string fv_name,
    string pv_name)
{
  return wrap_in_forclause (expr,
                            bind_var (loc, fv_name, var_expr::for_var),
                            bind_var (loc, pv_name, var_expr::pos_var));
}

rchandle<forlet_clause> wrap_in_letclause(expr_t expr, var_expr_t lv)
{
  assert (lv->get_kind () == var_expr::let_var);
  return new forlet_clause(forlet_clause::let_clause, lv, NULL, NULL, expr.getp());
}

rchandle<forlet_clause> wrap_in_letclause(expr_t expr, const QueryLoc& loc, string name)
{
  return wrap_in_letclause (expr, bind_var (loc, name, var_expr::let_var));
}

rchandle<forlet_clause> wrap_in_letclause(expr_t expr)
{
  return wrap_in_letclause (expr, tempvar(expr->get_loc(), var_expr::let_var));
}

rchandle<flwor_expr> wrap_in_let_flwor (expr_t expr, var_expr_t lv, expr_t ret) {
  rchandle<flwor_expr> fe = new flwor_expr (lv->get_loc ());
  fe->add (wrap_in_letclause (expr, lv));
  fe->set_retval (ret);
  return fe;
}

expr_t wrap_in_dos_and_dupelim(expr_t expr)
{
  rchandle<fo_expr> dos = new fo_expr(expr->get_loc(), LOOKUP_OP1("sort-distinct-nodes-asc-or-atomics"));
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

  The possible types of a PathExpr are:
  1. path_leading_lone_slash
  2. path_leading_slash
  3. path_leading_slashslash
  4. path_relative

  In case 1, the PathExpr does not have any child node.
********************************************************************************/
void *begin_visit(const PathExpr& v)
{
  TRACE_VISIT();

  expr_t result;
  rchandle<relpath_expr> rpe = NULL;

  // Save theRootRelPathExpr state.
  relpathstack.push(theRootRelPathExpr);
  theRootRelPathExpr = NULL;

  // Put a NULL in the stack to mark the beginning of a PathExp tree.
  nodestack.push(NULL);

  if (v.get_type() != ParseConstants::path_leading_lone_slash)
  {
    rpe = new relpath_expr(v.get_location());

    result = rpe.getp();
  }

  /*
    If path expr starts with / or // (cases 1, 2, or 3), create an expr E =
    fn:root(./self::node()).  In case 2 or 3 make E the 1st step of the rpe
    that was created above.  In case 1, just push E to the nodestack.
    In case 4, add a "." to path expressions starting with an axis step
  */
  if (v.get_type() == ParseConstants::path_relative) {
    const RelativePathExpr *vrpe = v.get_relpath_expr ().dyn_cast<RelativePathExpr> ().getp ();
    if (vrpe != NULL && vrpe->get_step_expr ().dyn_cast<AxisStep> () != NULL)
      rpe->add_back (sctx_p->lookup_var_nofail (DOT_VAR));
  } else {
    rchandle<relpath_expr> ctx_rpe = new relpath_expr(v.get_location());
    ctx_rpe->add_back(sctx_p->lookup_var_nofail (DOT_VAR));

    rchandle<match_expr> me = new match_expr(v.get_location());
    me->setTestKind(match_anykind_test);
    rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
    ase->setAxis(axis_kind_self);
    ase->setTest(me);

    ctx_rpe->add_back(&*ase);

    rchandle<fo_expr> fo = new fo_expr(v.get_location(), LOOKUP_FN("fn", "root", 1));
    fo->add(&*ctx_rpe);

    result = fo.getp();

    if (rpe != NULL)
    {
      rpe->add_back(&*fo);
      result = &*rpe;
    }
  }

  if (v.get_type() == ParseConstants::path_leading_slashslash)
  {
    rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
    rchandle<match_expr> me = new match_expr(v.get_location());
    me->setTestKind(match_anykind_test);
    ase->setAxis(axis_kind_descendant_or_self);
    ase->setTest(me);

    rpe->add_back(&*ase);
  }

  nodestack.push(result.getp());
  return no_state;
}


void end_visit(const PathExpr& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();

  ZORBA_ASSERT(arg1 == NULL);

  nodestack.push(wrap_in_dos_and_dupelim(arg2));

  // Restore theRootRelPathExpr state.
  theRootRelPathExpr = pop_stack (relpathstack);
}


void* begin_visit(const RelativePathExpr& v)
{
  TRACE_VISIT ();

  if (theRootRelPathExpr == NULL)
    theRootRelPathExpr = &v;

  return no_state;
}

void intermediate_visit(const RelativePathExpr& v, void* /*visit_state*/)
{
  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();

  rchandle<relpath_expr> rpe = NULL;

  if (arg1 != NULL)
  {
    rpe = arg1.dyn_cast<relpath_expr> ();
    ZORBA_ASSERT(rpe != NULL);

    rpe->add_back(arg2);
    if (v.get_step_type() == ParseConstants::st_slashslash)
    {
      rchandle<axis_step_expr> ase = new axis_step_expr(v.get_location());
      rchandle<match_expr> me = new match_expr(v.get_location());
      me->setTestKind(match_anykind_test);
      ase->setAxis(axis_kind_descendant_or_self);
      ase->setTest(me);
      rpe->add_back(&*ase);
    }
  }
  else
  {
    flwor_expr* flwor = arg2.dyn_cast<flwor_expr> ();
    ZORBA_ASSERT(flwor != NULL);

    nodestack.push(NULL);

    rpe = new relpath_expr(v.get_location());
    rpe->add_back(flwor);
  }

  rchandle<exprnode> rstep = v.get_relpath_expr();
  ZORBA_ASSERT(rstep != NULL);

  if (rstep.dyn_cast<RelativePathExpr> () != NULL || rstep.dyn_cast<AxisStep> () != NULL)
     nodestack.push(&*rpe);
  else {
    push_scope();
    rchandle<forlet_clause> lcseq = wrap_in_letclause(&*rpe);

    rchandle<fo_expr> count_expr = new
      fo_expr(v.get_location(), LOOKUP_FN("fn", "count", 1));

    count_expr->add(lcseq->get_var().getp());

    rchandle<forlet_clause> lclast =
      wrap_in_letclause(&*count_expr, v.get_location(), LAST_IDX_VAR);

    rchandle<forlet_clause> fc =
      wrap_in_forclause(lcseq->get_var().getp(), v.get_location(),
                        DOT_VAR, DOT_POS_VAR);

    rchandle<flwor_expr> flwor = new flwor_expr(v.get_location());
    flwor->add(lcseq);
    flwor->add(lclast);
    flwor->add(fc);

    nodestack.push(&*flwor);
  }
}

void end_visit(const RelativePathExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  if (theRootRelPathExpr == &v)
    theRootRelPathExpr = NULL;

  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();

  rchandle<exprnode> rstep = v.get_relpath_expr();

  if (rstep.dyn_cast<RelativePathExpr> () != NULL || rstep.dyn_cast<AxisStep> () != NULL) {
    if (arg1 == NULL) {
      // In this case, all the steps in the rpe tree have been processed.
      nodestack.push(arg1);
      nodestack.push(arg2);
    } else {
      // In this case, v is the bottom RelativePathExpr node in the tree (rpe3
      // in the example). At the top of the node stack is the expr corresponding
      // to the right child of v (step4 in the example), followed by the
      // relpath_expr
      relpath_expr* rpe = arg1.dyn_cast<relpath_expr> ();
      ZORBA_ASSERT(rpe != NULL);
      rpe->add_back(arg2);
      nodestack.push(rpe);
    }
  } else {
    flwor_expr *f = arg1.dyn_cast<flwor_expr> ();
    ZORBA_ASSERT(f != NULL);
    f->set_retval(arg2);
    nodestack.push(f);
    pop_scope();
  }
}


void *begin_visit(const AxisStep& v)
{
  TRACE_VISIT ();

  rchandle<axis_step_expr> aexpr_h = new axis_step_expr(v.get_location());
  nodestack.push(&*aexpr_h);
  return no_state;
}

void post_step_visit(const AxisStep& v, void* /*visit_state*/)
{
  PredicateList *pl = v.get_predicate_list().getp();
  if (pl != NULL && pl->size() > 0) {
    expr_t arg2 = pop_nodestack();
    expr_t arg1 = pop_nodestack();

    relpath_expr *rpe = arg1.dyn_cast<relpath_expr> ();
    ZORBA_ASSERT(rpe != NULL);

    rpe->add_back(arg2);

    expr_t dose = wrap_in_dos_and_dupelim(rpe);
    nodestack.push(dose);
  }
}

void end_visit(const AxisStep& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void pre_predicate_visit(const PredicateList& v, void* /*visit_state*/)
{
  push_scope();
  expr_t seq = pop_nodestack();
  rchandle<forlet_clause> lcseq = wrap_in_letclause(seq);
  rchandle<fo_expr> count_expr = new fo_expr(v.get_location(), LOOKUP_FN("fn", "count", 1));
  count_expr->add(lcseq->get_var().getp());
  rchandle<forlet_clause> lclast = wrap_in_letclause(&*count_expr, v.get_location(), LAST_IDX_VAR);
  rchandle<forlet_clause> fc = wrap_in_forclause(lcseq->get_var().getp(), v.get_location (), DOT_VAR, DOT_POS_VAR);
  rchandle<flwor_expr> flwor = new flwor_expr(v.get_location());
  flwor->add(lcseq);
  flwor->add(lclast);
  flwor->add(fc);
  nodestack.push(&*flwor);
}


void post_predicate_visit(const PredicateList& /*v*/, void* /*visit_state*/)
{
  expr_t pred = pop_nodestack();
  QueryLoc loc = pred->get_loc ();
  expr_t f = pop_nodestack();

  flwor_expr *flwor = f.dyn_cast<flwor_expr> ();
  ZORBA_ASSERT(flwor != NULL);

  rchandle<forlet_clause> predlet = wrap_in_letclause(pred);
  var_expr *predvar = predlet->get_var().getp();

  flwor->add(predlet);

  expr_t dot = sctx_p->lookup_var_nofail (DOT_VAR);

  rchandle<fo_expr> cond = new fo_expr(loc, LOOKUP_OPN("or"));
  cond->add(new instanceof_expr(loc, predvar, GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));
  cond->add(new instanceof_expr(loc, predvar, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));
  cond = new fo_expr(loc, LOOKUP_OPN("or"), &*cond);
  cond->add (new instanceof_expr(loc, predvar, GENV_TYPESYSTEM.FLOAT_TYPE_ONE));

  rchandle<fo_expr> eq = new fo_expr(loc, LOOKUP_OP2("value-equal"));
  eq->add(sctx_p->lookup_var_nofail (DOT_POS_VAR));
  eq->add(predvar);
  expr_t then_ite = new if_expr(loc, &*eq, dot, create_seq(loc));

  rchandle<if_expr> else_ite = new if_expr(loc, predvar, dot, create_seq (loc));

  expr_t type_ite = new if_expr(loc, &*cond, then_ite, &*else_ite);

  flwor->set_retval(type_ite);
  nodestack.push(flwor);
  pop_scope();
}


void *begin_visit(const ForwardStep& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ForwardStep& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const AbbrevForwardStep& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const AbbrevForwardStep& v, void* /*visit_state*/)
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


void *begin_visit(const ForwardAxis& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ForwardAxis& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

  switch (v.get_axis())
  {
  case ParseConstants::axis_child:
  {
    ase->setAxis(axis_kind_child);
    break;
  }
  case ParseConstants::axis_descendant:
  {
    ase->setAxis(axis_kind_descendant);
    break;
  }
  case ParseConstants::axis_attribute:
  {
    ase->setAxis(axis_kind_attribute);
    break;
  }
  case ParseConstants::axis_self:
  {
    ase->setAxis(axis_kind_self);
    break;
  }
  case ParseConstants::axis_descendant_or_self:
  {
    ase->setAxis(axis_kind_descendant_or_self);
    break;
  }
  case ParseConstants::axis_following_sibling:
  {
    ase->setAxis(axis_kind_following_sibling);
    break;
  }
  case ParseConstants::axis_following:
  {
    ase->setAxis(axis_kind_following);
    break;
  }
  }
}


void *begin_visit(const ReverseStep& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ReverseStep& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const ReverseAxis& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ReverseAxis& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

  switch (v.get_axis())
  {
  case ParseConstants::axis_parent:
  {
    ase->setAxis(axis_kind_parent);
    break;
  }
  case ParseConstants::axis_ancestor:
  {
    ase->setAxis(axis_kind_ancestor);
    break;
  }
  case ParseConstants::axis_preceding_sibling:
  {
    ase->setAxis(axis_kind_preceding_sibling);
    break;
  }
  case ParseConstants::axis_preceding:
  {
    ase->setAxis(axis_kind_preceding);
    break;
  }
  case ParseConstants::axis_ancestor_or_self:
  {
    ase->setAxis(axis_kind_ancestor_or_self);
    break;
  }
  }
}


/*******************************************************************************

********************************************************************************/
void *begin_visit(const QuantifiedExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const QuantifiedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  rchandle<flwor_expr> flwor(new flwor_expr(v.get_location()));
  flwor->set_retval(new const_expr(v.get_location(), true));
  rchandle<expr> sat = pop_nodestack();
  if (v.get_qmode() == ParseConstants::quant_every) {
    rchandle<fo_expr> uw = new fo_expr(v.get_expr()->get_location(), LOOKUP_FN("fn", "not", 1));
    uw->add(sat);
    sat = uw.getp();
  }
  flwor->set_where(sat);
  vector<var_expr_t> vars_vals (2 * v.get_decl_list()->size());
  generate (vars_vals.rbegin (), vars_vals.rend (), stack_to_generator (nodestack));
  for (int i = 0; i < v.get_decl_list()->size(); ++i) {
    pop_scope ();
    var_expr_t ve = vars_vals [2 * i + 1].cast<var_expr> ();
    flwor->add(wrap_in_forclause (&*vars_vals [2 * i], ve, NULL));
  }
  rchandle<fo_expr> quant = new fo_expr(v.get_location(), v.get_qmode() == ParseConstants::quant_every ? LOOKUP_FN("fn", "empty", 1) : LOOKUP_FN("fn", "exists", 1));
  quant->add (&*flwor);
  nodestack.push (&*quant);
}


/*******************************************************************************

********************************************************************************/
void *begin_visit(const QueryBody& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const QueryBody& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  const function *ctxf = LOOKUP_OP1 ("ctxvariable");
  flwor_expr::clause_list_t clauses;

  for (std::list<global_binding>::iterator i = global_vars.begin ();
       i != global_vars.end ();
       i++)
  {
    global_binding b = *i;
    var_expr_t var = b.first;
    expr_t expr = b.second;
    if (expr == NULL)
      expr = new fo_expr (var->get_loc (), ctxf, new const_expr (var->get_loc (), var->get_varname ()->getStringValue ()));
    clauses.push_back (wrap_in_letclause (expr, var));
  }

  if (! clauses.empty ())
    nodestack.push (new flwor_expr (v.get_location (), clauses, pop_nodestack ()));
}


/*******************************************************************************

********************************************************************************/
void *begin_visit(const RangeExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const RangeExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  fo_expr *e = new fo_expr (v.get_location(), LOOKUP_OP2 ("to"));

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();

  e->add(e2_h);
  e->add(e1_h);

  nodestack.push(e);
}


void *begin_visit(const StringLiteral& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const StringLiteral& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  nodestack.push(new const_expr(v.get_location(),v.get_strval()));
}

void *begin_visit(const TreatExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TreatExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new treat_expr (v.get_location (), pop_nodestack (), pop_tstack (), ZorbaError::XPDY0050));
}

void *begin_visit(const TypeswitchExpr& v)
{
  TRACE_VISIT ();

  var_expr_t sv = tempvar (v.get_switch_expr ()->get_location (), var_expr::let_var);

  expr_t defret;
  {
    string defvar_name = v.get_default_varname ();
    var_expr_t defvar;
    if (! defvar_name.empty ()) {
      push_scope ();
      defvar = bind_var (v.get_default_clause ()->get_location (), defvar_name, var_expr::let_var);
    }
    v.get_default_clause ()->accept (*this);
    defret = pop_nodestack ();
    if (! defvar_name.empty ()) {
      pop_scope ();
      defret = &*wrap_in_let_flwor (&*sv, defvar, defret);
    }
  }

  const CaseClauseList *clauses = v.get_clause_list ();
  for (vector<rchandle<CaseClause> >::const_reverse_iterator it = clauses->rbegin();
       it!=clauses->rend(); ++it)
  {
    const CaseClause *e_p = &**it;
    QueryLoc loc = e_p->get_location ();
    string name = e_p->get_varname ();
    var_expr_t var;
    if (! name.empty ()) {
      push_scope ();
      var = bind_var (loc, name, var_expr::let_var);
    }
    e_p->accept (*this);
    xqtref_t type = pop_tstack ();
    if (! name.empty ()) {
      pop_scope ();
      nodestack.push (&*wrap_in_let_flwor (new cast_expr (loc, &*sv, type), var, pop_nodestack ()));
    }
    defret = new if_expr (e_p->get_location (),
                          new instanceof_expr (loc, &*sv, type),
                          pop_nodestack (), defret);
  }

  {
    v.get_switch_expr ()->accept (*this);
    expr_t se = pop_nodestack ();
    nodestack.push (&*wrap_in_let_flwor (se, sv, defret));
  }

  return NULL;
}

void end_visit(const TypeswitchExpr& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  // shouldn't get here, begin_visit() rejects visitor
  assert (false);
}


void *begin_visit(const UnaryExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const UnaryExpr& v, void* /*visit_state*/)
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

void *begin_visit(const UnionExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const UnionExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  fo_expr *fo_h = new fo_expr(v.get_location(), LOOKUP_OP2 ("union"));
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push(fo_h);
}

void *begin_visit(const UnorderedExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const UnorderedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  nodestack.push (new order_expr (v.get_location (), order_expr::unordered,
                                  pop_nodestack ()));
}

void *begin_visit(const ValidateExpr& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_IMPLEMENTED ("validation");
  return no_state;
}

void end_visit(const ValidateExpr& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarRef& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarRef& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  var_expr *e = static_cast<var_expr *> (sctx_p->lookup_var (v.get_varname ()));
  if (e == NULL)
    ZORBA_ERROR_PARAM ( ZorbaError::XPST0008, v.get_varname (), "");
  nodestack.push (rchandle<expr> (e));
}


/* update-related */
void *begin_visit(const DeleteExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DeleteExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  expr_t aTarget = pop_nodestack();
  expr_t aDelete = new delete_expr(v.get_location(), aTarget);
  nodestack.push(aDelete);
}

void *begin_visit(const InsertExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const InsertExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  expr_t aTarget = pop_nodestack();
  expr_t aSource = pop_nodestack();
  expr_t aInsert = new insert_expr(v.get_location(), v.getType(), aSource, aTarget);
  nodestack.push(aInsert);
}

void *begin_visit(const RenameExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const RenameExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  expr_t aName = pop_nodestack();
  expr_t aTarget = pop_nodestack();
  expr_t aRename = new rename_expr(v.get_location(), aTarget, aName);
  nodestack.push(aRename);
}

void *begin_visit(const ReplaceExpr& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ReplaceExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  expr_t aReplacement = pop_nodestack();
  expr_t aTarget = pop_nodestack();
  expr_t aReplace = new replace_expr(v.get_location(), v.getType(), aTarget, aReplacement);
  nodestack.push(aReplace);
}

void *begin_visit(const RevalidationDecl& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_IMPLEMENTED ("revalidation");
  return no_state;
}

void end_visit(const RevalidationDecl& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const TransformExpr& /*v*/)
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const TransformExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  expr_t aReturn = pop_nodestack();
  expr_t aModify = pop_nodestack();
  rchandle<transform_expr> aTransform = new transform_expr(v.get_location(), aModify, aReturn);
  rchandle<var_expr> anAssign = pop_nodestack().dyn_cast<var_expr> ();
  while (anAssign != 0)
  {
    aTransform->add(anAssign);
    anAssign = pop_nodestack();
  }
  nodestack.push(&*aTransform);
  pop_scope (v.get_varname_list ()->size ());
}

void *begin_visit(const VarNameList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarNameList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarBinding& v)
{
  TRACE_VISIT ();
  push_scope ();
  bind_var_and_push (v.get_location (), v.get_varname (), var_expr::transform_var);
  return no_state;
}

void end_visit(const VarBinding&, void*)
{
  TRACE_VISIT_OUT ();
}

/* try-catch-related */
void *begin_visit(const TryExpr& v)
{
  TRACE_VISIT ();
  nodestack.push(new trycatch_expr(v.get_location()));
  return no_state;
}

void end_visit(const TryExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const CatchListExpr& v)
{
  TRACE_VISIT ();
  expr_t te = pop_nodestack();
  trycatch_expr *tce = dynamic_cast<trycatch_expr *>(&*nodestack.top());
  tce->set_try_expr(te);
  return no_state;
}

void end_visit(const CatchListExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT ();
}

expr_t cc_component(const QueryLoc& loc, var_expr_t var, const char *local)
{
  expr_t exists = new fo_expr(loc, LOOKUP_FN("fn", "exists", 1), &*var);
  expr_t emptyseq = new fo_expr(loc, LOOKUP_OPN("concatenate"));
  expr_t eName = new const_expr(loc, GENV_ITEMFACTORY->createQName(XQUERY_FN_NS, "fn", local));
  expr_t eContents = new fo_expr(loc, LOOKUP_OP1("enclosed-expr"), &*var);
  push_elem_scope();
  expr_t eVal = new elem_expr(loc, eName, NULL, eContents, ns_ctx);
  pop_elem_scope();
  expr_t ite = new if_expr(loc, exists, eVal, emptyseq);

  return ite;
}

void *begin_visit(const CatchExpr& v)
{
  TRACE_VISIT ();
  trycatch_expr *tce = dynamic_cast<trycatch_expr *>(&*nodestack.top());
  trycatch_expr::clauseref_t cc = new catch_clause();
  tce->add_clause_in_front(cc);
  if (v.getVarname() != "") {
    push_scope();
    cc->errorcode_var_h = tempvar(v.get_location(), var_expr::catch_var);
    cc->errordesc_var_h = tempvar(v.get_location(), var_expr::catch_var);
    cc->errorobj_var_h = tempvar(v.get_location(), var_expr::catch_var);
    var_expr_t lv = bind_var(v.get_location(), v.getVarname(), var_expr::let_var, GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE);

    expr_t eName = new const_expr(v.get_location(), GENV_ITEMFACTORY->createQName(XQUERY_FN_NS, "fn", "error"));

    expr_t comp1 = cc_component(v.get_location(), cc->errorcode_var_h, "errorcode");
    expr_t comp2 = cc_component(v.get_location(), cc->errordesc_var_h, "description");
    expr_t comp3 = cc_component(v.get_location(), cc->errorobj_var_h, "error-obj");
    expr_t eContents = new fo_expr(v.get_location(), LOOKUP_OPN("concatenate"), comp1, comp2, comp3);

    push_elem_scope();
    expr_t eVal = new elem_expr(v.get_location(), eName, NULL, eContents, ns_ctx);
    pop_elem_scope();

    rchandle<flwor_expr> flwor = new flwor_expr(v.get_location());
    rchandle<forlet_clause> flc = new forlet_clause(forlet_clause::let_clause, lv, NULL, NULL, eVal);
    flwor->add(flc);
    cc->catch_expr_h = &*flwor;
  }
  return no_state;
}

void end_visit(const CatchExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT ();
  expr_t ce = pop_nodestack();
  trycatch_expr *tce = dynamic_cast<trycatch_expr *>(&*nodestack.top());
  catch_clause *cc = &*(*tce)[0];
  if (v.getVarname() != "") {
    flwor_expr *flwor = dynamic_cast<flwor_expr *>(&*cc->catch_expr_h);
    flwor->set_retval(ce);
    pop_scope();
  } else {
    cc->catch_expr_h = ce;
  }
}


/* full-text-related */
void *begin_visit(const FTAnd& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit(const FTAnd& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTAnyallOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTAnyallOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTBigUnit& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTBigUnit& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTCaseOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTCaseOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTContainsExpr& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTContainsExpr& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTContent& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTContent& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTDiacriticsOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTDiacriticsOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTDistance& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTDistance& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTIgnoreOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTIgnoreOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTInclExclStringLiteral& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTInclExclStringLiteral& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTInclExclStringLiteralList& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTInclExclStringLiteralList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTLanguageOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTLanguageOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTMatchOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTMatchOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void *begin_visit(const FTMatchOptionProximityList& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTMatchOptionProximityList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTMildnot& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTMildnot& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTOptionDecl& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTOptionDecl& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTOr& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTOr& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTOrderedIndicator& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTOrderedIndicator& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTProximity& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTProximity& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTRange& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTRange& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTRefOrList& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTRefOrList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTScope& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTScope& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTScoreVar& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTScoreVar& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTSelection& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTSelection& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTStemOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTStemOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTStopwordOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTStopwordOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTStringLiteralList& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTStringLiteralList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTThesaurusID& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTThesaurusID& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTThesaurusList& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTThesaurusList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTThesaurusOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTThesaurusOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTTimes& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTTimes& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTUnaryNot& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTUnaryNot& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTUnit& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTUnit& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWildcardOption& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTWildcardOption& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWindow& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTWindow& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWords& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTWords& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWordsSelection& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTWordsSelection& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const FTWordsValue& /*v*/)
{
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit(const FTWordsValue& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

// Pass-thru -- nothing to be done

void *begin_visit(const VarInDeclList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarInDeclList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const VarGetsDeclList& /*v*/)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const VarGetsDeclList& /*v*/, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

// End pass-thru


};


TranslatorImpl *make_translator (bool print, CompilerCB* aCompilerCB)  {
  return new TranslatorImpl (print, aCompilerCB);
}

rchandle<expr> translate (bool print, const parsenode &root, CompilerCB* aCompilerCB) {
  auto_ptr<TranslatorImpl> t (make_translator (print, aCompilerCB));
  root.accept (*t);
  rchandle<expr> result = t->result ();
  if (print) {
    cout << "Expression tree for query after translation:\n";
    result->put(cout) << endl;
  }
  return result;
}


} /* namespace zorba */
/* vim:set ts=2 sw=2: */
