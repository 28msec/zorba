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
#include "stdafx.h"

#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/sequencetypes.h"

#include "compiler/expression/fo_expr.h"

#include "functions/func_node_sort_distinct.h"
#include "functions/function_impl.h"

#include "types/typeops.h"


namespace zorba 
{


/*******************************************************************************

********************************************************************************/
xqtref_t op_node_sort_distinct_base::getReturnType(const fo_expr* caller) const
{
  return caller->get_arg(0)->get_return_type(); 
}


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
function* op_node_sort_distinct_base::optimize(const expr* self, expr* child) const
{
  TypeManager* tm = self->get_sctx()->get_typemanager();

#if 0
  cout << "optimize: self " << self << " child " << child
       << " self_ignores_sorted "
       << (self != NULL &&  self->ignoresSortedNodes())
       << " child_prod_sorted "
       << (child != NULL && child->producesSortedNodes())
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
    if (self != NULL && self->ignoresDuplicateNodes())
      distinct = false;

    if (child != NULL && child->producesDistinctNodes())
      distinct = false;
  }

  bool sort = (myActions[SORT_ASC] || myActions[SORT_DESC]);
  if (sort)
  {
    if (self != NULL && self->ignoresSortedNodes())
      sort = false;

    if (child != NULL &&
        child->producesSortedNodes() &&
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
      return (getKind() == FunctionConsts::OP_CHECK_DISTINCT_NODES_1 ?
              GET_BUILTIN_FUNCTION(OP_CHECK_DISTINCT_NODES_1) :
              GET_BUILTIN_FUNCTION(OP_DISTINCT_NODES_1)); 
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
BoolAnnotationValue op_node_sort_distinct_base::ignoresSortedNodes(
    expr* fo,
    ulong input) const 
{
  const bool* myActions = action();

  bool sort = (myActions[SORT_ASC]  || myActions[SORT_DESC]);

  if (sort)
  {
    return ANNOTATION_TRUE;
  }
  else
  {
    return fo->getIgnoresSortedNodes();
  }
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue op_node_sort_distinct_base::ignoresDuplicateNodes(
    expr* fo, 
    ulong input) const 
{
  const bool* myActions = action();

  bool distinct = myActions[DISTINCT];

  if (distinct)
  {
    return ANNOTATION_TRUE;
  }
  else
  {
    return fo->getIgnoresDuplicateNodes();
  }
}


/*******************************************************************************

********************************************************************************/
PlanIter_t op_node_sort_distinct_base::codegen(
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
    {
      bool check = (getKind() == FunctionConsts::OP_CHECK_DISTINCT_NODES_1);

      return new NodeDistinctIterator(sctx, loc, argv[0], noa, check);
    }
    else if (noa)
    {
      return new EitherNodesOrAtomicsIterator(sctx, loc, argv);
    }
    else
    {
      return argv[0];
    }
  }
  else
  {
    return new NodeSortIterator(sctx,
                                loc,
                                argv[0],
                                myActions[SORT_ASC],
                                distinct,
                                noa);
  }
}


/*******************************************************************************

********************************************************************************/
class op_either_nodes_or_atomics : public op_node_sort_distinct_base
{
public:
  op_either_nodes_or_atomics(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_EITHER_NODES_OR_ATOMICS_1)
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
class op_distinct_nodes : public op_node_sort_distinct_base
{
public:
  op_distinct_nodes(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_DISTINCT_NODES_1)
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
  Check that the argument expr does not produce duplicate nodes. Used to wrap
  the domain expr of a general index.
********************************************************************************/
class op_check_distinct_nodes : public op_node_sort_distinct_base
{
public:
  op_check_distinct_nodes(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_CHECK_DISTINCT_NODES_1)
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
class op_distinct_nodes_or_atomics : public op_node_sort_distinct_base
{
public:
  op_distinct_nodes_or_atomics(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_DISTINCT_NODES_OR_ATOMICS_1)
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
class op_sort_nodes_ascending : public op_node_sort_distinct_base
{
public:
  op_sort_nodes_ascending(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_SORT_NODES_ASC_1)
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
class op_sort_nodes_asc_or_atomics : public op_node_sort_distinct_base 
{
public:
  op_sort_nodes_asc_or_atomics(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_SORT_NODES_ASC_OR_ATOMICS_1)
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
class op_sort_nodes_descending : public op_node_sort_distinct_base
{
public:
  op_sort_nodes_descending(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_SORT_NODES_DESC_1)
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
class op_sort_nodes_desc_or_atomics : public op_node_sort_distinct_base
{
public:
  op_sort_nodes_desc_or_atomics(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_SORT_NODES_DESC_OR_ATOMICS_1)
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
class op_sort_distinct_nodes_ascending : public op_node_sort_distinct_base
{
public:
  op_sort_distinct_nodes_ascending(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_SORT_DISTINCT_NODES_ASC_1)
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
class op_sort_distinct_nodes_asc_or_atomics : public op_node_sort_distinct_base
{
public:
  op_sort_distinct_nodes_asc_or_atomics(const signature& sig) 
    :
    op_node_sort_distinct_base(sig,
                               FunctionConsts::OP_SORT_DISTINCT_NODES_ASC_OR_ATOMICS_1)
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
class op_sort_distinct_nodes_descending : public op_node_sort_distinct_base
{
public:
  op_sort_distinct_nodes_descending(const signature& sig)
    :
    op_node_sort_distinct_base(sig, FunctionConsts::OP_SORT_DISTINCT_NODES_DESC_1)
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
class op_sort_distinct_nodes_descending_or_atomics : public op_node_sort_distinct_base
{
public:
  op_sort_distinct_nodes_descending_or_atomics(const signature& sig)
    :
    op_node_sort_distinct_base(sig,
                               FunctionConsts::OP_SORT_DISTINCT_NODES_DESC_OR_ATOMICS_1)
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
void populateContext_DocOrder(static_context* sctx) 
{
  const char* zorba_op_ns = static_context::ZORBA_OP_NS.c_str();

  DECL(sctx, op_either_nodes_or_atomics,
       (createQName(zorba_op_ns,"","either-nodes-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_distinct_nodes,
       (createQName(zorba_op_ns,"","distinct-nodes"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_check_distinct_nodes,
       (createQName(zorba_op_ns,"","check-distinct-nodes"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
  
  DECL(sctx, op_distinct_nodes_or_atomics,
       (createQName(zorba_op_ns,"","distinct-nodes-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_nodes_ascending,
       (createQName(zorba_op_ns,"","sort-nodes-asc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_nodes_asc_or_atomics,
       (createQName(zorba_op_ns,"","sort-nodes-asc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
#if 0
  DECL(sctx, op_sort_nodes_descending,
       (createQName(zorba_op_ns,"","sort-nodes-desc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_nodes_desc_or_atomics,
       (createQName(zorba_op_ns,"","sort-nodes-desc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
#endif
  DECL(sctx, op_sort_distinct_nodes_ascending,
       (createQName(zorba_op_ns,"","sort-distinct-nodes-asc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_asc_or_atomics,
       (createQName(zorba_op_ns, "", "sort-distinct-nodes-asc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
#if 0
  DECL(sctx, op_sort_distinct_nodes_descending,
       (createQName(zorba_op_ns, "", "sort-distinct-nodes-desc"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_descending_or_atomics,
       (createQName(zorba_op_ns, "", "sort-distinct-nodes-desc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
#endif
}


}

/* vim:set et sw=2 ts=2: */
