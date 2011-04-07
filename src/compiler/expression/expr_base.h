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
#ifndef ZORBA_COMPILER_EXPR_BASE_H
#define ZORBA_COMPILER_EXPR_BASE_H

#include <zorba/config.h>

#include "common/shared_types.h"

#include "compiler/parser/query_loc.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/expression/expr_consts.h"
#include "compiler/semantic_annotations/annotation_holder.h"

#include "functions/function_consts.h"

#include "types/typeimpl.h"

#include "context/static_context_consts.h"


namespace zorba
{

class static_context;

class expr;
typedef rchandle<expr> expr_t;

class wrapper_expr;
typedef rchandle<wrapper_expr> wrapper_expr_t;

class expr_visitor;


enum expr_kind_t
{
  attr_expr_kind,
  axis_step_expr_kind,
  castable_expr_kind,
  cast_expr_kind,
  const_expr_kind,
  doc_expr_kind,
  elem_expr_kind,
  extension_expr_kind,
  flwor_expr_kind,
  fo_expr_kind,
#ifndef ZORBA_NO_FULL_TEXT
	ft_expr_kind,
#endif /* ZORBA_NO_FULL_TEXT */
  gflwor_expr_kind,
  if_expr_kind,
  instanceof_expr_kind,
  match_expr_kind,
  name_cast_expr_kind,
  order_expr_kind,
  pi_expr_kind,
  promote_expr_kind,
  relpath_expr_kind,
  text_expr_kind,
  treat_expr_kind,
  validate_expr_kind,
  var_expr_kind,
  var_decl_expr_kind,

  dynamic_function_invocation_expr_kind,
  function_item_expr_kind,
  trycatch_expr_kind,

  delete_expr_kind,
  insert_expr_kind,
  rename_expr_kind,
  replace_expr_kind,
  transform_expr_kind,

  sequential_expr_kind,
  exit_expr_kind,
  flowctl_expr_kind,
  while_expr_kind,

  eval_expr_kind,
  debugger_expr_kind,
  wrapper_expr_kind,
  function_trace_expr_kind,

  unknown_expr_kind
};


/*******************************************************************************
  Base class for the expression tree node hierarchy
********************************************************************************/
class expr : public AnnotationHolder
{
  friend class expr_iterator_data;
  friend class ExprIterator;
  friend class forletwin_clause;
  friend class for_clause;
  friend class let_clause;
  friend class where_clause;
  friend class function_trace_expr;

public:
  typedef rchandle<expr> expr_t;

  typedef std::map<const expr *, expr_t> substitution_t;

  typedef substitution_t::iterator subst_iter_t;

  typedef enum
  {
    PRODUCES_SORTED_NODES   = 0,
    PRODUCES_DISTINCT_NODES = 2,
    IGNORES_SORTED_NODES    = 4,
    IGNORES_DUPLICATE_NODES = 6,
    NON_DISCARDABLE         = 8,
    UNFOLDABLE              = 10,
    CONTAINS_RECURSIVE_CALL = 12
  } Annotationkey;

  typedef enum
  {
    PRODUCES_SORTED_NODES_MASK   = 0x003,
    PRODUCES_DISTINCT_NODES_MASK = 0x00C,
    IGNORES_SORTED_NODES_MASK  = 0x030,
    IGNORES_DUPLICATE_NODES_MASK  = 0x0C0,
    NON_DISCARDABLE_MASK         = 0x300,
    UNFOLDABLE_MASK              = 0xC00,
    CONTAINS_RECURSIVE_CALL_MASK = 0x3000
  } AnnotationMask;


protected:
  static expr_t      iter_end_expr;
  static expr_t    * iter_done;

protected:
  static_context   * theSctx;

  QueryLoc           theLoc;

  short              theKind;
  short              theScriptingKind;

  xqtref_t           theType;

  ulong              theFlags1;

public:
  SERIALIZABLE_ABSTRACT_CLASS(expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(expr, AnnotationHolder)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  static expr_script_kind_t scripting_kind_anding(
        expr_script_kind_t type1,
        expr_script_kind_t type2,
        const QueryLoc& loc);

public:
  expr(static_context*, const QueryLoc&, expr_kind_t);

  virtual ~expr();

  expr_kind_t get_expr_kind() const { return static_cast<expr_kind_t>(theKind); }

  const QueryLoc& get_loc() const { return theLoc; }

  void set_loc(const QueryLoc& loc) { theLoc = loc; }

  static_context* get_sctx() const { return theSctx; }

  TypeManager* get_type_manager() const;

  ulong getFlags() const { return theFlags1; }

  void setFlags(ulong flags) { theFlags1 = flags; }

  expr_script_kind_t get_scripting_kind() const;

  bool is_updating() const;

  bool is_sequential() const;

  bool is_vacuous() const;

  bool is_simple() const;

  bool is_updating_or_vacuous() const;

  void compute_return_type(bool deep, bool* modified);

  xqtref_t get_return_type();

  expr_t clone() const;

  virtual expr_t clone(substitution_t& substitution) const;

  virtual void accept(expr_visitor& v);

  virtual void accept_children(expr_visitor& v);

  virtual std::ostream& put(std::ostream&) const = 0;

  std::string toString() const;

public:
  // Annotation : produces-sorted-nodes
  BoolAnnotationValue getProducesSortedNodes() const;

  void setProducesSortedNodes(BoolAnnotationValue v);

  bool producesSortedNodes() const;

  // Annotation : produces-distinct-nodes
  BoolAnnotationValue getProducesDistinctNodes() const;

  void setProducesDistinctNodes(BoolAnnotationValue v);

  bool producesDistinctNodes() const;

  // Annotation : ignores-sorted-nodes
  BoolAnnotationValue getIgnoresSortedNodes() const;

  void setIgnoresSortedNodes(BoolAnnotationValue v);

  bool ignoresSortedNodes() const;

  // Annotation : ignores-duplicated-nodes
  BoolAnnotationValue getIgnoresDuplicateNodes() const;

  void setIgnoresDuplicateNodes(BoolAnnotationValue v);

  bool ignoresDuplicateNodes() const;

  // Annotation : non-discardable
  BoolAnnotationValue getNonDiscardable() const;

  bool isNonDiscardable() const;

  void setNonDiscardable(BoolAnnotationValue v);

  // Annotation : unfoldable
  BoolAnnotationValue getUnfoldable() const;

  void setUnfoldable(BoolAnnotationValue v);

  bool isUnfoldable() const;

  // Annotation : contains-recursive-call
  BoolAnnotationValue getContainsRecursiveCall() const;

  void setContainsRecursiveCall(BoolAnnotationValue v);

  bool containsRecursiveCall() const;

  bool is_constant() const;

  bool is_nondeterministic() const;

  void replace_expr(const expr* oldExpr, const expr* newExpr);

  bool contains_expr(const expr* e) const;

  bool contains_node_construction() const;

  bool is_map(expr* e, static_context* sctx) const;

  FunctionConsts::FunctionKind get_function_kind() const;

  const var_expr* get_var() const;

  const store::Item* getQName(static_context* sctx) const;

  void clear_annotations();

  xqtref_t get_return_type_with_empty_input(const expr* input) const;

protected:
  virtual void compute_scripting_kind() = 0;

  bool is_map_internal(const expr* e, bool& found) const;
};


/*******************************************************************************

********************************************************************************/
#define DEF_EXPR_ACCEPT( type )             \
void type::accept(expr_visitor& v)          \
{                                           \
  if (v.begin_visit(*this))                 \
    accept_children(v);                     \
                                            \
  v.end_visit(*this);                       \
}


}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
