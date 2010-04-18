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

#include "common/shared_types.h"

#include "compiler/parser/query_loc.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/expression/expr_consts.h"
#include "compiler/semantic_annotations/annotation_holder.h"

#include "functions/function_enum.h"

#include "types/typeimpl.h"

#include "context/static_context_consts.h"


namespace zorba
{

class static_context;


enum expr_kind_t
{
  attr_expr_kind,
  axis_step_expr_kind,
  castable_expr_kind,
  cast_expr_kind,
  const_expr_kind,
  debugger_expr_kind,
  delete_expr_kind,
  doc_expr_kind,
  elem_expr_kind,
  eval_expr_kind,
  exit_expr_kind,
  extension_expr_kind,
  flowctl_expr_kind,
  flwor_expr_kind,
  fo_expr_kind,
	ft_expr_kind,
  gflwor_expr_kind,
  if_expr_kind,
  insert_expr_kind,
  instanceof_expr_kind,
  match_expr_kind,
  name_cast_expr_kind,
  order_expr_kind,
  pi_expr_kind,
  promote_expr_kind,
  relpath_expr_kind,
  rename_expr_kind,
  replace_expr_kind,
  sequential_expr_kind,
  text_expr_kind,
  transform_expr_kind,
  treat_expr_kind,
  trycatch_expr_kind,
  validate_expr_kind,
  var_expr_kind,
  while_expr_kind,
  wrapper_expr_kind,
  dynamic_function_invocation_expr_kind,
  function_item_expr_kind,
  unknown_expr_kind
};

class expr;
typedef rchandle<expr> expr_t;

class wrapper_expr;
typedef rchandle<wrapper_expr> wrapper_expr_t;

class expr_visitor;

class expr_iterator_data;

class expr_iterator;


/*******************************************************************************
  A class to iterate over the subexpressions of an expr. The actual work is done
  by an instance of expr_iterator_data (see below). Such instances are allocated
  dynamically in the heap, whenever we need to iterate over the subexpressions of
  an expr. On the other hand, instances of expr_iterator are always allocated on
  the stack; they wrap corresponding instances of expr_iterator_data (always a
  1:1 relationship) and provide an object-based, rather than pointer-based,
  iterator interface.
********************************************************************************/
class expr_iterator
{
private:
  expr_iterator_data * theIter;

public:
  expr_iterator() : theIter(0) {}

  expr_iterator(expr_iterator_data* iter) : theIter(iter) {}

  expr_iterator(const expr_iterator& other);

  ~expr_iterator();

  expr_iterator& operator=(const expr_iterator& other);

  expr_iterator& operator++();

  //expr_iterator operator++(int);

  expr_t& operator*();

  bool done() const;

private:
  // comparisson forbidden; use done()
  bool operator==(const expr_iterator& other) { return false; }
};


/*******************************************************************************
  A const version of expr_iterator.
********************************************************************************/
class const_expr_iterator
{
private:
  expr_iterator_data * theIter;

public:
  const_expr_iterator() : theIter(0) {}

  const_expr_iterator(expr_iterator_data* iter) : theIter(iter) {}

  const_expr_iterator(const const_expr_iterator& other);

  ~const_expr_iterator();

  const_expr_iterator& operator=(const const_expr_iterator& other);

  const_expr_iterator& operator++();

  expr* operator*();

  bool done() const;

private:
  // comparisson forbidden; use done()
  bool operator==(const const_expr_iterator& other) { return false; }
};



/*******************************************************************************
  Base class for the expression tree node hierarchy
********************************************************************************/
class expr : public AnnotationHolder
{
  friend class expr_iterator_data;
  friend class forletwin_clause;
  friend class for_clause;
  friend class let_clause;
  friend class where_clause;

public:
  typedef rchandle<expr> expr_t;

  typedef std::map<const expr *, expr_t> substitution_t;

  typedef substitution_t::iterator subst_iter_t;


  typedef enum 
  {
    ANNOTATION_UNKNOWN = 0,
    ANNOTATION_FALSE,
    ANNOTATION_TRUE,
    ANNOTATION_TRUE_FIXED
  } BoolAnnotationValue;


protected:
  // Pitfall when using the cache -- AVOID THIS SCENARIO:
  // (1) obtain a non-const ptr to a child expression (cache is invalidated)
  // (2) call an operation P() that caches its result
  // (3) modify the child expr (cache is NOT invalidated)
  // (4) call P() again and get (possibly wrong) cached result
  struct Cache
  {
    mutable struct
    {
      bool             valid;
      xqtref_t         t;
    } type;

    mutable struct
    {
      bool               valid;
      expr_script_kind_t kind;
    } scripting_kind;
  };

protected:
  static expr_t    iter_end_expr;
  static expr_t  * iter_done;

protected:
  static_context * theSctx;
  QueryLoc         theLoc;
  Cache            theCache;

  ulong            theFlags1;

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
  expr(static_context*, const QueryLoc&);

  virtual ~expr();

  virtual expr_kind_t get_expr_kind() const = 0;

  const QueryLoc& get_loc() const { return theLoc; }

  void set_loc(const QueryLoc& aLoc) { theLoc = aLoc; }

  static_context* get_sctx() const { return theSctx; }

  expr_script_kind_t get_scripting_kind() const;

  bool is_updating() const;

  bool is_sequential() const;

  bool is_vacuous() const;

  bool is_simple() const;

  bool is_updating_or_vacuous() const;

  xqtref_t return_type(static_context* sctx) const;

  virtual xqtref_t return_type_impl(static_context* sctx) const;

  expr_iterator expr_begin(bool invalidateCache = true);

  const_expr_iterator expr_begin_const() const;

  virtual void next_iter(expr_iterator_data &) = 0;

  expr_t clone() const;

  virtual expr_t clone(substitution_t& substitution) const;

  virtual void accept(expr_visitor& v);

  virtual void accept_children(expr_visitor& v);

  virtual std::ostream& put(std::ostream&) const = 0;

  std::string toString() const;

public:
  BoolAnnotationValue getProducesSortedNodes() const;

  void setProducesSortedNodes(BoolAnnotationValue v);

  BoolAnnotationValue getProducesDistinctNodes() const;

  void setProducesDistinctNodes(BoolAnnotationValue v);

  BoolAnnotationValue getNonDiscardable() const;

  bool isNonDiscardable() const;

  void setNonDiscardable(BoolAnnotationValue v);

  BoolAnnotationValue getUnfoldable() const;

  void setUnfoldable(BoolAnnotationValue v);

  bool isUnfoldable() const;

  void setDirectAnnotations();

  bool is_constant() const;

  void replace_expr(const expr* oldExpr, const expr* newExpr);

  bool contains_expr(const expr* e) const;

  bool contains_node_construction() const;

  bool is_map(const expr* e, static_context* sctx) const;

  FunctionConsts::FunctionKind get_function_kind() const;

  const var_expr* get_var() const;

  const store::Item* getQName(static_context* sctx) const;

  void clear_annotations();

  xqtref_t get_return_type_with_empty_input(
        static_context* sctx,
        const expr* input) const;

protected:
  void invalidate()
  {
    theCache.type.valid = false;
    // theCache.upd_seq_kind.valid = false;
  }

  // Returns true if all modifiers, as well as all accessors that permit future
  // modifications of child expressions, call invalidate(). Note that expr
  // iterators are compliant.
  virtual bool cache_compliant() const { return false; }

  virtual void compute_scripting_kind() const = 0;

  virtual expr_iterator_data* make_iter();

  bool is_map_internal(const expr* e, bool& found) const;
};


/*******************************************************************************
  Base class for iterators that iterate over the subexpressions (children) of
  a given expr. Notice that theCurrentChild is a pointer to expr_t.

  Each actual instance of the abstract expr class has its own way of storing
  pointers to its subexpressions. So, to make expr_iterator_data work with any
  kind of expr, the actual work of expr_iterator_data is done by the virtual
  expr::next_iter() method. Every concrete subclass of expr must defined its
  own next_iter() method.
********************************************************************************/
class expr_iterator_data
{
protected:
  expr   * theExpr;

public:
  expr_t * theCurrentChild;
  int      theState;
  bool     theInvalidate;

public:
  expr_iterator_data(expr* e)
    :
    theExpr(e),
    theCurrentChild(NULL),
    theState(0),
    theInvalidate(true)
  {
  }

  virtual ~expr_iterator_data() {}

  void set_invalidate(bool v) { theInvalidate = v; }

  void next() { theExpr->next_iter(*this); }

  bool done() const;
};


/*******************************************************************************
  Iterator macros. These macros are used inside the expr::next_iter() method:
  expr::next_iter(expr_iterator_data& v)
********************************************************************************/

#define BEGIN_EXPR_ITER() switch (v.theState) { case 0:


#define BEGIN_EXPR_ITER2( type )                                       \
  type##_iterator_data& vv = dynamic_cast<type##_iterator_data &>(v);  \
  BEGIN_EXPR_ITER()

#define END_EXPR_ITER()   v.theCurrentChild = expr::iter_done; }


#define ITER(subExprHandle)                                         \
do                                                                  \
{                                                                   \
  v.theState = __LINE__;                                            \
  v.theCurrentChild = reinterpret_cast<expr_t*>(&(subExprHandle));  \
                                                                    \
  if ((subExprHandle) != NULL)                                      \
  {                                                                 \
    if (v.theInvalidate) invalidate();                              \
    return;                                                         \
  }                                                                 \
                                                                    \
case __LINE__:;                                                     \
                                                                    \
} while (0)


#define ITER_FOR_EACH( iter, begin, end, expr )                  \
for (vv.iter = (begin); vv.iter != (end); ++(vv.iter))           \
{                                                                \
  ITER(expr);                                                    \
}


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
