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
#pragma once
#ifndef ZORBA_COMPILER_EXPR_BASE
#define ZORBA_COMPILER_EXPR_BASE

#include <map>

#include <zorba/config.h>

#include "common/shared_types.h"

#include "compiler/parser/query_loc.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/expression/expr_consts.h"

#include "functions/function_consts.h"

//#include "types/typeimpl.h"

#include "context/static_context_consts.h"


namespace zorba
{

class static_context;

class expr;

class wrapper_expr;

class expr_visitor;

class CompilerCB;


enum expr_kind_t
{
  const_expr_kind,

  var_expr_kind,

  doc_expr_kind,
  elem_expr_kind,
  attr_expr_kind,
  namespace_expr_kind,
  text_expr_kind,
  pi_expr_kind,

  relpath_expr_kind,
  axis_step_expr_kind,
  match_expr_kind,

  flwor_expr_kind,
  gflwor_expr_kind,
  if_expr_kind,
  trycatch_expr_kind,

  fo_expr_kind,
  dynamic_function_invocation_expr_kind,
  argument_placeholder_expr_kind,
  function_item_expr_kind,

  castable_expr_kind,
  cast_expr_kind,
  instanceof_expr_kind,
  treat_expr_kind,
  promote_expr_kind,
  name_cast_expr_kind,

  validate_expr_kind,

  extension_expr_kind,

  order_expr_kind,

#ifndef ZORBA_NO_FULL_TEXT
  ft_expr_kind,
#endif /* ZORBA_NO_FULL_TEXT */

  delete_expr_kind,
  insert_expr_kind,
  rename_expr_kind,
  replace_expr_kind,
  transform_expr_kind,

  block_expr_kind,
  var_decl_expr_kind,
  var_set_expr_kind,
  apply_expr_kind,
  exit_expr_kind,
  exit_catcher_expr_kind,
  flowctl_expr_kind,
  while_expr_kind,

  eval_expr_kind,
  debugger_expr_kind,
  wrapper_expr_kind,
  function_trace_expr_kind,

#ifdef ZORBA_WITH_JSON
  json_direct_object_expr_kind,
  json_object_expr_kind,
  json_array_expr_kind,
#endif

  unknown_expr_kind
};


/*******************************************************************************
  Base class for the expression tree node hierarchy
********************************************************************************/
class expr
{
  friend class ExprIterator;
  friend class forletwin_clause;
  friend class forlet_clause;
  friend class where_clause;
  friend class function_trace_expr;

public:
  typedef std::map<const expr *, expr*> substitution_t;

  typedef substitution_t::iterator subst_iter_t;

  typedef std::set<var_expr *> FreeVars;

  typedef enum
  {
    PRODUCES_SORTED_NODES   = 0,
    PRODUCES_DISTINCT_NODES = 2,
    IGNORES_SORTED_NODES    = 4,
    IGNORES_DUPLICATE_NODES = 6,
    NON_DISCARDABLE         = 8,
    UNFOLDABLE              = 10,
    CONTAINS_RECURSIVE_CALL = 12,
    PROPAGATES_INPUT_NODES  = 14,
    MUST_COPY_NODES         = 16,
    CONTAINS_PRAGMA         = 18,
    CONSTRUCTS_NODES        = 20,
    DEREFERENCES_NODES      = 22
  } Annotationkey;

  typedef enum
  {
    PRODUCES_SORTED_NODES_MASK    = 0x003,
    PRODUCES_DISTINCT_NODES_MASK  = 0x00C,
    IGNORES_SORTED_NODES_MASK     = 0x030,
    IGNORES_DUPLICATE_NODES_MASK  = 0x0C0,
    NON_DISCARDABLE_MASK          = 0x300,
    UNFOLDABLE_MASK               = 0xC00,
    CONTAINS_RECURSIVE_CALL_MASK  = 0x3000,
    PROPAGATES_INPUT_NODES_MASK   = 0xC000,
    MUST_COPY_NODES_MASK          = 0x30000,
    CONTAINS_PRAGMA_MASK          = 0xC0000,
    CONSTRUCTS_NODES_MASK         = 0x300000,
    DEREFERENCES_NODES_MASK       = 0xC00000
  } AnnotationMask;

  typedef enum
  {
    IN_TYPE_COMPUTE  = 0x1
  } BoolFlags;


protected:
  static expr*      iter_end_expr;
  static expr*    * iter_done;

protected:
  CompilerCB * const theCCB;

  static_context   * theSctx;

  user_function    * theUDF;

  QueryLoc           theLoc;

  unsigned short     theKind;

  unsigned short     theScriptingKind;

  xqtref_t           theType;

  uint32_t           theAnnotationFlags;

  uint8_t            theBoolFlags;

  uint8_t            theVisitId;

  FreeVars           theFreeVars;
  
  dataguide_cb_t     theJsonDataguide;

public:
  static bool is_sequential(unsigned short theScriptingKind);

  static void checkSimpleExpr(const expr* e);

  static void checkNonUpdating(const expr* e);

protected:
  expr(CompilerCB*, static_context*, user_function*, const QueryLoc&, expr_kind_t);

  expr();

public:
  virtual ~expr();

  CompilerCB* get_ccb() { return theCCB; }

  static_context* get_sctx() const { return theSctx; }

  TypeManager* get_type_manager() const;

  user_function* get_udf() const { return theUDF; }

  expr_kind_t get_expr_kind() const { return static_cast<expr_kind_t>(theKind); }

  const QueryLoc& get_loc() const { return theLoc; }

  void set_loc(const QueryLoc& loc) { theLoc = loc; }

  uint32_t getAnnotationFlags() const { return theAnnotationFlags; }

  void setAnnotationFlags(uint32_t flags) { theAnnotationFlags = flags; }

  unsigned short get_scripting_detail() const { return theScriptingKind; }

  bool is_updating() const;

  bool is_sequential() const;

  bool is_vacuous() const;

  bool is_simple() const;

  bool is_updating_or_vacuous() const;

  void set_not_exiting();

  void adjustSequential();

  void checkScriptingKind() const;

  void compute_return_type(bool deep, bool* modified);

  xqtref_t get_return_type();

  expr* clone(user_function* udf) const;

  expr* clone(user_function* udf, substitution_t& subst) const;

  virtual void accept(expr_visitor& v) = 0;

  void accept_children(expr_visitor& v);

  virtual std::ostream& put(std::ostream&) const = 0;

  std::string toString() const;

  std::string show() const; // to mirror the Item's class show() method

public:
  //
  void setVisitId(uint8_t id) { theVisitId = id; }

  bool isVisited(uint8_t id) const { return theVisitId == id; }

  uint8_t getVisitId() const { return theVisitId; }

  // Transient flag used only during the type computation for global vars
  bool isInTypeCompute() const { return theBoolFlags & IN_TYPE_COMPUTE; }

  void setInTypeCompute() { theBoolFlags |= IN_TYPE_COMPUTE; }

  void resetInTypeCompute() { theBoolFlags &= ~IN_TYPE_COMPUTE; }

  // Annotation : produces-sorted-nodes
  BoolAnnotationValue getProducesSortedNodes() const;

  void setProducesSortedNodes(BoolAnnotationValue v);

  bool producesSortedNodes() const;

  // Annotation : produces-distinct-nodes
  BoolAnnotationValue getProducesDistinctNodes() const;

  void setProducesDistinctNodes(BoolAnnotationValue v);

  bool producesDistinctNodes() const;

  // Annotation : propagatesInputNodes
  BoolAnnotationValue getPropagatesInputNodes() const;

  void setPropagatesInputNodes(BoolAnnotationValue v);

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

  // Annotation : mustCopyNodes
  BoolAnnotationValue getMustCopyNodes() const;

  void setMustCopyNodes(BoolAnnotationValue v);

  // Annotation : containsPragma
  BoolAnnotationValue getContainsPragma() const;

  void setContainsPragma(BoolAnnotationValue v);

  bool containsPragma() const;

  // Annotation : constructsNodes
  BoolAnnotationValue getConstructsNodes() const;

  void setConstructsNodes(BoolAnnotationValue v);

  bool constructsNodes() const;

  // Annotation : dereferencesNodes
  BoolAnnotationValue getDereferencesNodes() const;

  void setDereferencesNodes(BoolAnnotationValue v);

  bool dereferencesNodes() const;

  // Annotation : free vars
  const FreeVars& getFreeVars() const { return theFreeVars; }

  FreeVars& getFreeVars() { return theFreeVars; }

  void setFreeVars(FreeVars& s);

  //
  bool is_constant() const;

  bool is_nondeterministic() const;

  void replace_expr(expr* oldExpr, expr* newExpr);

  bool contains_expr(const expr* e) const;

  void get_exprs_of_kind(
      expr_kind_t kind,
      bool deep,
      std::vector<expr*>& exprs) const;

  void get_fo_exprs_of_kind(
      FunctionConsts::FunctionKind kind,
      bool deep,
      std::vector<expr*>& exprs) const;

  bool is_map(expr* e, static_context* sctx) const;

  FunctionConsts::FunctionKind get_function_kind() const;

  const var_expr* get_var() const;

  const store::Item* getQName() const;

  expr* skip_wrappers() const;

  void clear_annotations();

  xqtref_t get_return_type_with_empty_input(const expr* input) const;
  
  dataguide_cb* get_dataguide(); 
  
  // If the object's dataguide is NULL, will create a new one and return it
  dataguide_cb* get_dataguide_or_new();
  
  dataguide_cb* set_dataguide(dataguide_cb* a_json_dataguide); 

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
/* vim:set et sw=2 ts=2: */
