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

#include "functions/nodeid_internal.h"
#include "functions/function_impl.h"

#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/sequencetypes.h"


namespace zorba 
{


#define TSV_TRUE TSVAnnotationValue::TRUE_VAL
#define TSV_TRUE_P TSVAnnotationValue::TRUE_VAL.getp()

#define A_SORT ((a) [0])
#define A_ATOMICS ((a) [1])
#define A_DISTINCT ((a) [2])
#define A_ASCENDING ((a) [3])


/*******************************************************************************

********************************************************************************/
function* op_node_sort_distinct::op_for_action(
    const static_context* sctx,
    const bool* a,
    const AnnotationHolder* parent,
    const AnnotationHolder* child,
    nodes_or_atomics_t noa) 
{
#define LOOKUP_OP1(local) (sctx->lookup_builtin_fn((xqp_string(":") + local).c_str(), 1))

  Annotation::key_t ignoresSortedNodes = AnnotationKey::IGNORES_SORTED_NODES;
  Annotation::key_t producesSortedNodes = AnnotationKey::PRODUCES_SORTED_NODES;
  Annotation::key_t ignoresDupNodes = AnnotationKey::IGNORES_DUP_NODES;
  Annotation::key_t producesDistinctNodes = AnnotationKey::PRODUCES_DISTINCT_NODES;

  bool distinct = (A_DISTINCT &&
                   (parent == NULL ||
                    parent->get_annotation(ignoresDupNodes) != TSV_TRUE) &&
                   (child == NULL ||
                    child->get_annotation(producesDistinctNodes) != TSV_TRUE));

  if (A_ATOMICS && noa == ATOMICS)
    return NULL;

  bool atomics = A_ATOMICS && noa == MIXED;

#if 0
  cout << "op_for_action parent " << parent << " child " << child
       << " A_SORT " << A_SORT << " parent_ignores_sorted "
       << (parent != NULL && 
           parent->get_annotation(AnnotationKey::IGNORES_SORTED_NODES) == TSV_TRUE)
       << " child_prod_sorted "
       << (child != NULL &&
           child->get_annotation(AnnotationKey::PRODUCES_SORTED_NODES) == TSV_TRUE)
       << endl;
#endif

  if (! A_SORT ||
      (parent != NULL &&
       parent->get_annotation(ignoresSortedNodes).getp() == TSV_TRUE_P) ||
      (child != NULL &&
       child->get_annotation(producesSortedNodes).getp() == TSV_TRUE_P &&
       A_ASCENDING))
  {
    return (distinct ?
            LOOKUP_OP1 ("distinct-nodes" + (atomics ? "-or-atomics" : ""))
            :
            (atomics ? LOOKUP_OP1 ("either-nodes-or-atomics") : NULL));
  }

  xqp_string part1 = xqpString::concat("sort-",
                                       (distinct ? "distinct-" : ""),
                                       "nodes-");

  xqp_string part2 = xqpString::concat(A_ASCENDING ? "asc" : "desc",
                                       (atomics ? "-or-atomics" : ""));

  return LOOKUP_OP1(part1 + part2);

#undef LOOKUP_OP1
}


/*******************************************************************************

********************************************************************************/
function* op_node_sort_distinct::min_action(
    const static_context *sctx,
    const AnnotationHolder *self,
    const AnnotationHolder *child,
    nodes_or_atomics_t noa) const 
{
  return op_for_action (sctx, action(), self, child, noa);
}


/*******************************************************************************

********************************************************************************/
void op_node_sort_distinct::compute_annotation(
    AnnotationHolder* parent,
    std::vector<AnnotationHolder *>& kids,
    Annotation::key_t k) const 
{
  const bool* a  = action();

  switch (k) 
  {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES: 
  {
    bool ignores = 
    (parent->get_annotation(k).getp() == TSV_TRUE_P ||
     (k == AnnotationKey::IGNORES_SORTED_NODES ? A_SORT : A_DISTINCT));

    TSVAnnotationValue::update_annotation(kids[src],
                                          k,
                                          TSVAnnotationValue::from_bool(ignores));
    break;
  }

  case AnnotationKey::PRODUCES_SORTED_NODES:
  case AnnotationKey::PRODUCES_DISTINCT_NODES: 
  {
    bool produces =
    (kids[0]->get_annotation(k).getp() == TSV_TRUE_P ||
     (k == AnnotationKey::PRODUCES_SORTED_NODES ? A_SORT : A_DISTINCT));

    parent->put_annotation(k, TSVAnnotationValue::from_bool(produces));
    break;
  }

  default: break;
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
  const bool* a = action();
  bool distinct = A_DISTINCT;

  if (! A_SORT)
  {
    return (distinct ?
            new NodeDistinctIterator(sctx, loc, argv[0], A_ATOMICS) :
            (A_ATOMICS ? new EitherNodesOrAtomicsIterator(sctx, loc, argv) : argv[0]));
  }
  else
    return new NodeSortIterator(sctx, loc, argv [0], A_ASCENDING, distinct, A_ATOMICS);
}


/*******************************************************************************

********************************************************************************/
class op_either_nodes_or_atomics : public op_node_sort_distinct
{
public:
  op_either_nodes_or_atomics (const signature& sig) : op_node_sort_distinct (sig) {}

  const bool* action() const 
  {
    //                         sort   atomics  distinct  ascendig
    static const bool a [] = { false, true,    false,    false };
    return a;
  }

  bool is_doc_order_func() const { return false; }
};


/*******************************************************************************

********************************************************************************/
class op_distinct_nodes : public op_node_sort_distinct
{
public:
  op_distinct_nodes(const signature& sig) : op_node_sort_distinct (sig) {}

  virtual bool is_node_sort_func() const { return true; }
  virtual bool is_node_distinct_func() const { return true; }

  const bool *action () const 
  {
    //                         sort   atomics  distinct  ascendig
    static const bool a [] = { false, false,   true,     false };
    return a;
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
  op_distinct_nodes_or_atomics(const signature& sig) : op_node_sort_distinct(sig) {}

  const bool* action () const 
  {
    //                         sort   atomics  distinct  ascendig
    static const bool a [] = { false, true,     true,    false };
    return a;
  }
};
  

/*******************************************************************************

********************************************************************************/
class op_sort_nodes_ascending : public op_node_sort_distinct
{
public:
  op_sort_nodes_ascending(const signature& sig) : op_node_sort_distinct (sig) {}

  const bool* action () const 
  {
    static const bool a [] = { true, false, false, true };
    return a;
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
  op_sort_nodes_asc_or_atomics(const signature& sig) : op_node_sort_distinct (sig) {}

  const bool* action () const 
  {
    //                         sort   atomics  distinct  ascendig
    static const bool a [] = { true,  true,    false,    true };
    return a;
  }
};
  

/*******************************************************************************

********************************************************************************/
class op_sort_nodes_descending : public op_node_sort_distinct
{
public:
  op_sort_nodes_descending(const signature& sig) : op_node_sort_distinct (sig) {}
  
  const bool* action () const 
  {
    static const bool a [] = { true, false, false, false };
    return a;
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
  op_sort_nodes_desc_or_atomics(const signature& sig) : op_node_sort_distinct (sig) {}
  
  const bool* action () const 
  {
    //                         sort   atomics  distinct  ascendig
    static const bool a [] = { true,  true,    false,    false };
    return a;
  }
};
  

/*******************************************************************************
  sort nodes in document order and doing distinct-nodes in one run
********************************************************************************/
class op_sort_distinct_nodes_ascending : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_ascending(const signature& sig) : op_node_sort_distinct (sig) {}

  virtual bool is_node_sort_func() const { return true; }
  virtual bool is_node_distinct_func() const { return true; }
  
  const bool* action () const 
  {
    static const bool a [] = { true, false, true, true };
    return a;
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
    op_node_sort_distinct (sig)
  {}

  const bool* action () const 
  {
    //                         sort   atomics  distinct  ascendig
    static const bool a [] = { true,  true,    true,     true };
    return a;
  }
};
  

/*******************************************************************************
  internal function for sort-nodes in reverse document order and doing 
  distinct-nodes in one run
********************************************************************************/ 
class op_sort_distinct_nodes_descending : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_descending(const signature& sig) : op_node_sort_distinct (sig) {}

  const bool* action () const 
  {
    static const bool a [] = { true, false, true, false };
    return a;
  }
};


/*******************************************************************************

********************************************************************************/
class fn_unordered : public single_seq_function 
{
public:
  fn_unordered(const signature& sig) : single_seq_function (sig) {}

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
    Annotation::key_t k) const 
{
  switch (k)
  {
  case AnnotationKey::IGNORES_SORTED_NODES:
    TSVAnnotationValue::update_annotation (kids [src], k, TSVAnnotationValue::TRUE_VAL);
    break;
  case AnnotationKey::IGNORES_DUP_NODES:
    TSVAnnotationValue::update_annotation (kids [src], k, parent->get_annotation (k));
    break;
  default:
    break;
  }
}


/*******************************************************************************

********************************************************************************/
void populateContext_DocOrder(static_context* sctx) 
{
  DECL(sctx, fn_unordered,
       (createQName(XQUERY_FN_NS,"fn","unordered"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
  
  DECL(sctx, op_either_nodes_or_atomics,
       (createQName(XQUERY_FN_NS,"fn",":either-nodes-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_distinct_nodes,
       (createQName(XQUERY_FN_NS,"fn",":distinct-nodes"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
  
  DECL(sctx, op_distinct_nodes_or_atomics,
       (createQName(XQUERY_FN_NS,"fn",":distinct-nodes-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_nodes_ascending,
       (createQName(XQUERY_FN_NS,"fn",":sort-nodes-asc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_nodes_asc_or_atomics,
       (createQName(XQUERY_FN_NS,"fn",":sort-nodes-asc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_nodes_descending,
       (createQName(XQUERY_FN_NS,"fn",":sort-nodes-desc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_nodes_desc_or_atomics,
       (createQName(XQUERY_FN_NS,"fn",":sort-nodes-desc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_ascending,
       (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-asc"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_asc_or_atomics,
       (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-asc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_sort_distinct_nodes_descending,
       (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-desc"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  // TODO: separate function
  DECL(sctx, op_sort_distinct_nodes_descending,
       (createQName(XQUERY_FN_NS,"fn",":sort-distinct-nodes-desc-or-atomics"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}

