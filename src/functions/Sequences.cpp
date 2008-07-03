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
#include "functions/Sequences.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/core/nodeid_iterators.h"
#include "context/static_context.h"
#include "util/tracer.h"
#include "system/globalenv.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"
#include "types/typeops.h"

#include "store/api/iterator.h"

using namespace std;
namespace zorba {


/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/

//15.1.1 fn:boolean (effective boolean value)
//-----------------



//15.1.2 op:concatenate 
/*_______________________________________________________________________
|
|	op:concatenate($seq1 as item()*, $seq2 as item()*) as item()*
|
|	Summary: Returns a sequence consisting of the items in $seq1 followed 
|	by the items in $seq2. This function backs up the infix operator ",". 
|	If either sequence is the empty sequence, the other operand is 
|	returned. 
|________________________________________________________________________*/

PlanIter_t op_concatenate::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new FnConcatIterator(loc, argv, ann.isUpdating());
}



xqtref_t op_concatenate::return_type (const std::vector<xqtref_t> &arg_types) const {
  int sz = arg_types.size ();
  if (sz == 0)
    return GENV_TYPESYSTEM.EMPTY_TYPE;
  else {
    xqtref_t t = arg_types [0];
    TypeConstants::quantifier_t q = TypeConstants::QUANT_STAR;
    for (int i = 1; i < sz; i++) {
      t = TypeOps::union_type (*t, *arg_types [i]);
      TypeConstants::quantifier_t pq = TypeOps::quantifier (*t);
      if (pq == TypeConstants::QUANT_ONE || pq == TypeConstants::QUANT_PLUS)
        q = TypeConstants::QUANT_PLUS;
    }
    return GENV_TYPESYSTEM.create_type_x_quant (*t, q);
  }
}

void op_concatenate::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const {
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    for (std::vector<AnnotationHolder *>::iterator i = kids.begin (); i < kids.end (); i++)
      TSVAnnotationValue::update_annotation ((*i), k, parent->get_annotation (k));
    break;
  default: break;
  }
}


//15.1.6 fn:distinct-values
//-------------------------
PlanIter_t fn_distinct_values::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDistinctValuesIterator(loc, argv);
}



//15.1.7 fn:insert-before
//-----------------------
PlanIter_t fn_insert_before::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnInsertBeforeIterator(loc, argv);
}



//15.1.8 fn:remove
//----------------
PlanIter_t fn_remove::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnRemoveIterator(loc, argv);
}




//15.1.9 fn:reverse
//-----------------
PlanIter_t fn_reverse::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new FnReverseIterator(loc, argv);
}



//15.1.10 fn:subsequence
//----------------------
PlanIter_t fn_subsequence::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnSubsequenceIterator(loc, argv);
}

void fn_subsequence::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const {
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    // don't use single_seq_fun default propagation rule
    return;
  default: single_seq_function::compute_annotation (parent, kids, k);
  }
}



//15.1.11 fn:unordered
//--------------------


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.3 fn:exactly-one
PlanIter_t fn_exactly_one_noraise::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnExactlyOneIterator(loc, argv, raise_err);
}


/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal
PlanIter_t fn_deep_equal::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDeepEqualIterator(loc, argv);
}


//15.3.2 op:union
//ordered
PlanIter_t fn_union::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnConcatIterator(loc, argv, false);
}


// For intersect and except, it's always more efficient to sort the output
// and use hash-join than to sort the inputs and use mergesort-join. Only if
// the inputs happen to be sorted for a different reason will we use mergesort:
// for $x in path/expr1 for $y in path/expr2 return ($x, $y, ($x intersect $y))
//
// For now, codegen doesn't know whether the inputs are sorted or not.
// TODO: annotate expressions with USE_HASH / USE_MERGESORT properties
// during optimization.

//15.3.3 op:intersect
PlanIter_t fn_intersect::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
#if 0  // we can't access PRODUCES_* from the inputs, must rethink
  bool distinct = ann.get_annotation (AnnotationKey::IGNORES_DUP_NODES) != TSVAnnotationValue::TRUE_VAL;
  bool sort = ann.get_annotation (AnnotationKey::IGNORES_SORTED_NODES) != TSVAnnotationValue::TRUE_VAL;

  std::vector<PlanIter_t> inputs;
  for (std::vector<PlanIter_t>::iterator i = argv.begin ();
       i != argv.end (); i++)
    inputs.push_back (new NodeSortIterator (loc, *i, true, distinct, false));
  return new SortSemiJoinIterator(loc, inputs);
#endif

  return new HashSemiJoinIterator(loc, argv);
}



//15.3.4 op:except
PlanIter_t fn_except::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  // TODO: use SortAntiJoinIterator when available (trac ticket 254)
  return new HashSemiJoinIterator(loc, argv, true);
}


/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.3 fn:max
PlanIter_t fn_max_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnMinMaxIterator(loc, argv, FnMinMaxIterator::MAX);
}



//15.4.4 fn:min
PlanIter_t fn_min_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnMinMaxIterator(loc, argv, FnMinMaxIterator::MIN);
}



/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/


//15.5.4 fn:doc
//-------------
PlanIter_t fn_doc_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDocIterator(loc, argv[0]);
}



//15.5.5 fn:doc-available
/*begin class fn_doc_available_func*/
PlanIter_t
fn_doc_available_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDocAvailableIterator(loc, argv);
}


/*end class fn_doc_available_func*/

//15.5.6 fn:collection


// internal functions

#define A_SORT ((a) [0])
#define A_ATOMICS ((a) [1])
#define A_DISTINCT ((a) [2])
#define A_ASCENDING ((a) [3])

PlanIter_t op_node_sort_distinct::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder& ann) const {
  const bool *a = action ();
  bool distinct = A_DISTINCT;
  if (! A_SORT)
    return distinct ? new NodeDistinctIterator (loc, argv [0], A_ATOMICS)
      : (A_ATOMICS ? new EitherNodesOrAtomicsIterator (loc, argv) : argv [0]);
  else
    return new NodeSortIterator (loc, argv [0], A_ASCENDING, distinct, A_ATOMICS);
}

void op_node_sort_distinct::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const {
  const bool *a = action ();

  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES: {
    bool ignores = (parent->get_annotation (k) == TSVAnnotationValue::TRUE_VAL || (k == AnnotationKey::IGNORES_SORTED_NODES ? A_SORT : A_DISTINCT));
    TSVAnnotationValue::update_annotation (kids [src], k, TSVAnnotationValue::from_bool (ignores));
    break;
  }

  case AnnotationKey::PRODUCES_SORTED_NODES:
  case AnnotationKey::PRODUCES_DISTINCT_NODES: {
    bool produces = (kids [0]->get_annotation (k) == TSVAnnotationValue::TRUE_VAL || (k == AnnotationKey::PRODUCES_SORTED_NODES ? A_SORT : A_DISTINCT));
    parent->put_annotation (k, TSVAnnotationValue::from_bool (produces));
    break;
  }

  default: break;
  }
}

const function *op_node_sort_distinct::op_for_action (const static_context *sctx, const bool *a, const AnnotationHolder *parent, const AnnotationHolder *child, nodes_or_atomics_t noa) {
#define LOOKUP_OP1( local ) (static_cast<const function *> (sctx->lookup_builtin_fn ((xqp_string (":") + local).c_str (), 1)))
  bool distinct = A_DISTINCT 
    && (parent == NULL || parent->get_annotation (AnnotationKey::IGNORES_DUP_NODES) != TSVAnnotationValue::TRUE_VAL)
    && (child == NULL || child->get_annotation (AnnotationKey::PRODUCES_DISTINCT_NODES) != TSVAnnotationValue::TRUE_VAL);

  if (A_ATOMICS && noa == ATOMICS)
    return NULL;

  bool atomics = A_ATOMICS && noa == MIXED;

#if 0
  cout << "op_for_action parent " << parent << " child " << child << " A_SORT " << A_SORT << " parent_ignores_sorted " << (parent != NULL && parent->get_annotation (AnnotationKey::IGNORES_SORTED_NODES) == TSVAnnotationValue::TRUE_VAL) << " child_prod_sorted " << (child != NULL && child->get_annotation (AnnotationKey::PRODUCES_SORTED_NODES) == TSVAnnotationValue::TRUE_VAL) << endl;
#endif
  if (! A_SORT
      || (parent != NULL && parent->get_annotation (AnnotationKey::IGNORES_SORTED_NODES) == TSVAnnotationValue::TRUE_VAL)
      || (child != NULL && child->get_annotation (AnnotationKey::PRODUCES_SORTED_NODES) == TSVAnnotationValue::TRUE_VAL))
#if 1  // trust NodeDistinctIterator
    return distinct ? LOOKUP_OP1 ("distinct-nodes" + (atomics ? "-or-atomics" : ""))
#else
    return distinct ? LOOKUP_OP1 ("sort-distinct-nodes-asc" + (atomics ? "-or-atomics" : "ending"))
#endif
      : (atomics ? LOOKUP_OP1 ("either-nodes-or-atomics") : NULL);
  xqp_string part1 = xqpString::concat("sort-", (distinct ? "distinct-" : ""), "nodes-");
  xqp_string part2 = xqpString::concat( A_ASCENDING ? "asc" : "desc", (atomics ? "-or-atomics" : "ending"));
  return LOOKUP_OP1 (part1 + part2);
#undef LOOKUP_OP1
}

const function *op_node_sort_distinct::min_action (const static_context *sctx, const AnnotationHolder *self, const AnnotationHolder *child, nodes_or_atomics_t noa) const {
  return op_for_action (sctx, action (), self, child, noa);
}

PlanIter_t fn_unordered::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &) const
{
  return argv [0];
}

void fn_unordered::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const {
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
    TSVAnnotationValue::update_annotation (kids [src], k, TSVAnnotationValue::TRUE_VAL);
    break;
  case AnnotationKey::IGNORES_DUP_NODES:
    TSVAnnotationValue::update_annotation (kids [src], k, parent->get_annotation (k));
    break;
  default: break;
  }
}

xqtref_t single_seq_function::return_type (const std::vector<xqtref_t> &arg_types) const { return arg_types [src]; }

void single_seq_function::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const {
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    TSVAnnotationValue::update_annotation (kids [src], k, parent->get_annotation (k));
    break;
  case AnnotationKey::PRODUCES_DISTINCT_NODES:
  case AnnotationKey::PRODUCES_SORTED_NODES:
    parent->put_annotation (k, kids [src]->get_annotation (k));
    break;
  default: break;
  }
}

} /* namespace zorba */

