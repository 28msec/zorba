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
#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/sequencetypes.h"

#include "compiler/expression/expr_base.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

#include "functions/nodeid_internal.h"
#include "functions/function_impl.h"

#include "types/typeops.h"


namespace zorba 
{


#define TSV_TRUE TSVAnnotationValue::TRUE_VAL
#define TSV_TRUE_P TSVAnnotationValue::TRUE_VAL.getp()


/*******************************************************************************
  Let f be "this" function, F be the fo expr representing a call to f, and E be
  the arg of F. This method is used to optimize the exression F(E) by replacing
  f with another op_node_sort_distinct function g, such that the action set of g
  is a subset of the action set of f, or by completely eliminating F, if no 
  op_node_sort_distinct action is needed on E.

  The optimization is based on :
  (a) The PRODUCES_SORTED_NODES and PRODUCES_DISTINCT_NODES annotations of E,
  (b) The IGNORES_SORTED_NODES and IGNORES_DUP_NODES annotations of F, and
  (c) The "noa" param.

  The "self" param is the fo expr F, and the "child" param is the E expr.
********************************************************************************/
function* op_node_sort_distinct::optimize(
    static_context* sctx,
    const expr* self,
    expr* child) const
{
  TypeManager* tm = sctx->get_typemanager();

  Annotations::Key ignoresSortedNodes = Annotations::IGNORES_SORTED_NODES;
  Annotations::Key ignoresDupNodes = Annotations::IGNORES_DUP_NODES;

#if 0
  cout << "optimize: self " << self << " child " << child
       << " self_ignores_sorted "
       << (self != NULL && 
           self->get_annotation(Annotations::IGNORES_SORTED_NODES) == TSV_TRUE)
       << " child_prod_sorted "
       << (child != NULL &&
           child->get_annotation(Annotations::PRODUCES_SORTED_NODES) == TSV_TRUE)
       << endl;
#endif

  // Get the acction set of "this" function
  const bool* myActions = this->action();

  // Check if the NOA action is really required.
  bool noa = myActions[NOA];
  if (noa)
  {
    xqtref_t inputType = child->get_return_type();

    if (TypeOps::is_subtype(tm, *inputType, *GENV_TYPESYSTEM.ANY_SIMPLE_TYPE))
    {
      // No action is required at all in this case, because the result is sure
      // to consist of atomic values only, and this is an allowed result given
      // that the NOA action is in "this" action set.
      return NULL;
    }
    else if (TypeOps::is_subtype(tm, *inputType, *GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR))
    {
      noa = false;
    }
  }

  // See if duplicate node elimination is really required
  bool distinct = myActions[DISTINCT];
  if (distinct)
  {
    if (self != NULL &&
        self->get_annotation(ignoresDupNodes).getp() == TSV_TRUE_P)
      distinct = false;

    if (child != NULL && child->getProducesDistinctNodes() == expr::ANNOTATION_TRUE)
      distinct = false;
  }

  bool sort = (myActions[SORT_ASC] || myActions[SORT_DESC]);
  if (sort)
  {
    if (self != NULL &&
        self->get_annotation(ignoresSortedNodes).getp() == TSV_TRUE_P)
      sort = false;

    if (child != NULL &&
        child->getProducesSortedNodes() == expr::ANNOTATION_TRUE &&
        myActions[SORT_ASC])
      sort = false;
  }

  if (!sort)
  {
    if (distinct && noa)
    {
      return GET_BUILTIN_FUNCTION(OP_DISTINCT_NODES_OR_ATOMICS_1); 
    }
    else if (distinct)
    {
      return GET_BUILTIN_FUNCTION(OP_DISTINCT_NODES_1); 
    }
    else if (noa)
    {
      return GET_BUILTIN_FUNCTION(OP_EITHER_NODES_OR_ATOMICS_1);
    }
    else
    {
      return NULL;
    }
  }
  else if (distinct && noa)
  {
    return (myActions[SORT_ASC] ?
            GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_ASC_OR_ATOMICS_1) :
            GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_DESC_OR_ATOMICS_1)); 
  }
  else if (distinct)
  {
    return (myActions[SORT_ASC] ?
            GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_ASC_1) :
            GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_DESC_1)); 
  }
  else if (noa)
  {
    return (myActions[SORT_ASC] ?
            GET_BUILTIN_FUNCTION(OP_SORT_NODES_ASC_OR_ATOMICS_1) :
            GET_BUILTIN_FUNCTION(OP_SORT_NODES_DESC_OR_ATOMICS_1)); 
  }
  else
  {
    return (myActions[SORT_ASC] ?
            GET_BUILTIN_FUNCTION(OP_SORT_NODES_ASC_1) :
            GET_BUILTIN_FUNCTION(OP_SORT_NODES_DESC_1)); 
  }
}


/*******************************************************************************

********************************************************************************/
void op_node_sort_distinct::compute_annotation(
    AnnotationHolder* parent,
    std::vector<AnnotationHolder *>& kids,
    Annotations::Key k) const
{
  const bool* myActions = action();

  switch (k) 
  {
  case Annotations::IGNORES_SORTED_NODES:
  case Annotations::IGNORES_DUP_NODES: 
  {
    bool sort = (myActions[SORT_ASC]  || myActions[SORT_DESC]);
    bool distinct = myActions[DISTINCT];

    bool ignores = (parent->get_annotation(k).getp() == TSV_TRUE_P ||
                    (k == Annotations::IGNORES_SORTED_NODES ? sort : distinct));

    TSVAnnotationValue::update_annotation(kids[0],
                                          k,
                                          TSVAnnotationValue::from_bool(ignores));
    break;
  }

  default:
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
PlanIter_t op_node_sort_distinct::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const 
{
  const bool* myActions = action();
  bool sort = (myActions[SORT_ASC]  || myActions[SORT_DESC]);
  bool distinct = myActions[DISTINCT];
  bool noa = myActions[NOA];

  if (! sort)
  {
    if (distinct)
      return new NodeDistinctIterator(sctx, loc, argv[0], noa);
    else if (noa)
      return new EitherNodesOrAtomicsIterator(sctx, loc, argv);
    else
      return argv[0];
  }
  else
  {
    return new NodeSortIterator(sctx, loc, argv[0],
                                myActions[SORT_ASC],
                                distinct,
                                noa);
  }
}


/*******************************************************************************

********************************************************************************/
class op_either_nodes_or_atomics : public op_node_sort_distinct
{
public:
  op_either_nodes_or_atomics(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_EITHER_NODES_OR_ATOMICS_1)
  {
  }

  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { false,    false,     false,    true };
    return a;
  }

  bool propagatesSortedNodes(ulong producer) const
  {
    return producer == 0;
  }

  bool propagatesDistinctNodes(ulong producer) const
  {
    return producer == 0;
  }
};


/*******************************************************************************

********************************************************************************/
class op_distinct_nodes : public op_node_sort_distinct
{
public:
  op_distinct_nodes(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_DISTINCT_NODES_1)
  {
  }

  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { false,    false,     true,     false };
    return a;
  }

  bool propagatesSortedNodes(ulong producer) const
  {
    return producer == 0;
  }

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return FunctionConsts::YES;
  }
};


/*******************************************************************************
  Similar to op-distinct, but it allows a sequences of atomic items as input 
  (but no mixture of atomic and node items). In this case, the result is equal
  to the input
********************************************************************************/
class op_distinct_nodes_or_atomics : public op_node_sort_distinct 
{
public:
  op_distinct_nodes_or_atomics(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_DISTINCT_NODES_OR_ATOMICS_1)
  {
  }

  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { false,    false,     true,     true };
    return a;
  }

  bool propagatesSortedNodes(ulong producer) const
  {
    return producer == 0;
  }

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return FunctionConsts::YES;
  }
};
  

/*******************************************************************************

********************************************************************************/
class op_sort_nodes_ascending : public op_node_sort_distinct
{
public:
  op_sort_nodes_ascending(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_SORT_NODES_ASC_1)
  {
  }

  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { true,     false,     false,    false };
    return a;
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::YES;
  }

  bool propagatesDistinctNodes(ulong producer) const
  {
    return producer == 0;
  }
};
  

/*******************************************************************************
  Similar to op-sort-ascending, but it allows a sequences of atomic items as input 
  (but no mixture of atomic and node items). In this case, the result is
  equal to the input
********************************************************************************/
class op_sort_nodes_asc_or_atomics : public op_node_sort_distinct 
{
public:
  op_sort_nodes_asc_or_atomics(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_SORT_NODES_ASC_OR_ATOMICS_1)
  {
  }

  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { true,     false,     false,    true };
    return a;
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::YES;
  }

  bool propagatesDistinctNodes(ulong producer) const
  {
    return producer == 0;
  }
};
  

/*******************************************************************************

********************************************************************************/
class op_sort_nodes_descending : public op_node_sort_distinct
{
public:
  op_sort_nodes_descending(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_SORT_NODES_DESC_1)
  {
  }
  
  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { false,    true,      false,    false };
    return a;
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::YES;
  }

  bool propagatesDistinctNodes(ulong producer) const
  {
    return producer == 0;
  }
};


/*******************************************************************************
  Similar to op-sort-descending, but it allows a sequences of atomic items as
  input (but no mixture of atomic and node items). In this case, the result is
  equal to the input
********************************************************************************/
class op_sort_nodes_desc_or_atomics : public op_node_sort_distinct
{
public:
  op_sort_nodes_desc_or_atomics(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_SORT_NODES_DESC_OR_ATOMICS_1)
  {
  }
  
  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { false,    true,      false,    true };
    return a;
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::YES;
  }

  bool propagatesDistinctNodes(ulong producer) const
  {
    return producer == 0;
  }
};
  

/*******************************************************************************
  sort nodes in document order and doing distinct-nodes in one run
********************************************************************************/
class op_sort_distinct_nodes_ascending : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_ascending(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_SORT_DISTINCT_NODES_ASC_1)
  {
  }

  virtual bool is_node_sort_func() const { return true; }
  virtual bool is_node_distinct_func() const { return true; }
  
  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { true,     false,     true,     false };
    return a;
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::YES;
  }

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return FunctionConsts::YES;
  }
};


/*******************************************************************************
  Similar to sort-distinct-nodes-ascending, but it allows a sequences of atomic
  items as input (but no mixture of atomic and node items). In this case, the
  result is equal to the input
********************************************************************************/
class op_sort_distinct_nodes_asc_or_atomics : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_asc_or_atomics(const signature& sig) 
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_SORT_DISTINCT_NODES_ASC_OR_ATOMICS_1)
  {
  }

  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { true,     false,     true,     true };
    return a;
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::YES;
  }

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return FunctionConsts::YES;
  }
};
  

/*******************************************************************************
  internal function for sort-nodes in reverse document order and doing 
  distinct-nodes in one run
********************************************************************************/ 
class op_sort_distinct_nodes_descending : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_descending(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_SORT_DISTINCT_NODES_DESC_1)
  {
  }

  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { false,    true,      true,     false };
    return a;
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::YES;
  }

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return FunctionConsts::YES;
  }
};


/*******************************************************************************
  internal function for sort-nodes in reverse document order and doing 
  distinct-nodes in one run
********************************************************************************/ 
class op_sort_distinct_nodes_descending_or_atomics : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_descending_or_atomics(const signature& sig)
    :
    op_node_sort_distinct(sig, FunctionConsts::OP_SORT_DISTINCT_NODES_DESC_OR_ATOMICS_1)
  {
  }

  const bool* action() const 
  {
    //                        sort_asc  sort_desc  distinct  noa
    static const bool a[] = { false,    true,      true,     true };
    return a;
  }

  virtual FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::YES;
  }

  virtual FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return FunctionConsts::YES;
  }
};


/*******************************************************************************

********************************************************************************/
class fn_unordered : public single_seq_function 
{
public:
  fn_unordered(const signature& sig)
    :
    single_seq_function(sig, FunctionConsts::FN_UNORDERED_1) {}

  bool isMap(ulong input) const { return true; }

  FunctionConsts::AnnotationValue producesSortedNodes() const
  {
    return FunctionConsts::PRESERVE;
  }

  FunctionConsts::AnnotationValue producesDistinctNodes() const
  {
    return FunctionConsts::PRESERVE;
  }

  COMPUTE_ANNOTATION_DECL();

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ) const
  {
    return argv[0];
  }
};


void fn_unordered::compute_annotation(
    AnnotationHolder* parent,
    std::vector<AnnotationHolder *>& kids,
    Annotations::Key k) const 
{
  switch (k)
  {
  case Annotations::IGNORES_SORTED_NODES:
    TSVAnnotationValue::update_annotation(kids[theInput], k, TSVAnnotationValue::TRUE_VAL);
    break;
  case Annotations::IGNORES_DUP_NODES:
    TSVAnnotationValue::update_annotation(kids[theInput], k, parent->get_annotation(k));
    break;
  default:
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
void populateContext_DocOrder(static_context* sctx) 
{
  DECL(sctx, fn_unordered,
       (createQName(XQUERY_OP_NS,"fn","unordered"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
  
  DECL(sctx, op_either_nodes_or_atomics,
       (createQName(ZORBA_OP_NS,"op","either-nodes-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_distinct_nodes,
       (createQName(ZORBA_OP_NS,"op","distinct-nodes"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
  
  DECL(sctx, op_distinct_nodes_or_atomics,
       (createQName(ZORBA_OP_NS,"op","distinct-nodes-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_nodes_ascending,
       (createQName(ZORBA_OP_NS,"op","sort-nodes-asc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_nodes_asc_or_atomics,
       (createQName(ZORBA_OP_NS,"op","sort-nodes-asc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_nodes_descending,
       (createQName(ZORBA_OP_NS,"op","sort-nodes-desc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_nodes_desc_or_atomics,
       (createQName(ZORBA_OP_NS,"op","sort-nodes-desc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_ascending,
       (createQName(ZORBA_OP_NS,"op","sort-distinct-nodes-asc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_asc_or_atomics,
       (createQName(ZORBA_OP_NS, "op", "sort-distinct-nodes-asc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_descending,
       (createQName(ZORBA_OP_NS, "op", "sort-distinct-nodes-desc"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_descending_or_atomics,
       (createQName(ZORBA_OP_NS, "op", "sort-distinct-nodes-desc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}

