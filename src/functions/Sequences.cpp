/**
 * @file Sequences.cpp
 * @author Paul Pedersen (pcp071098@yahoo.com)
 * @copyright 2006-2007 FLWOR Foundation (flworfound.org).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 */

#include "functions/Sequences.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/core/nodeid_iterators.h"
#include "context/static_context.h"
#include "util/tracer.h"
#include "system/globalenv.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

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

op_concatenate::op_concatenate(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t op_concatenate::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new FnConcatIterator(loc, argv);
}

bool op_concatenate::validate_args(vector<PlanIter_t>& argv) const
{
	return true;
}

xqtref_t op_concatenate::type_check(signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

xqtref_t op_concatenate::return_type (const std::vector<xqtref_t> &arg_types) const {
  int sz = arg_types.size ();
  if (sz == 0)
    return GENV_TYPESYSTEM.EMPTY_TYPE;
  else {
    xqtref_t t = arg_types [0];
    TypeConstants::quantifier_t q = TypeConstants::QUANT_STAR;
    for (int i = 1; i < sz; i++) {
      t = GENV_TYPESYSTEM.union_type (*t, *arg_types [i]);
      TypeConstants::quantifier_t pq = GENV_TYPESYSTEM.quantifier (*t);
      if (pq == TypeConstants::QUANT_ONE || pq == TypeConstants::QUANT_PLUS)
        q = TypeConstants::QUANT_PLUS;
    }
    return GENV_TYPESYSTEM.type_x_quant (*t, q);
  }
}

void op_concatenate::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const {
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    for (std::vector<AnnotationHolder *>::iterator i = kids.begin (); i < kids.end (); i++)
      (*i)->put_annotation (k, parent->get_annotation (k));
    break;
  default: break;
  }
}

//15.1.3 fn:index-of
/*_______________________________________________________________________
|
|	fn:index-of($seqParam as xs:anyAtomicType*,
|							$srchParam as xs:anyAtomicType) as xs:integer*
|	fn:index-of($seqParam as xs:anyAtomicType*,
|							$srchParam as xs:anyAtomicType,
|							$collation as xs:string) as xs:integer*
|	
|	Summary: Returns a sequence of positive integers giving the positions 
|	within the sequence $seqParam of items that are equal to $srchParam. 
|	
|	The collation used by the invocation of this function is determined 
|	according to the rules in 7.3.1 Collations. The collation is used when 
|	string comparison is required. 
|
|	The items in the sequence $seqParam are compared with $srchParam under 
|	the rules for the 'eq' operator. Values that cannot be compared, i.e. 
|	the 'eq' operator is not defined for their types, are considered to be 
|	distinct. If an item compares equal, then the position of that item in 
|	the sequence $seqParam is included in the result. 
|
|	If the value of $seqParam is the empty sequence, or if no item in 
|	$seqParam matches $srchParam, then the empty sequence is returned. 
|
|	The first item in a sequence is at position 1, not position 0.
|	The result sequence is in ascending numeric order.
|________________________________________________________________________*/

fn_index_of::fn_index_of(const signature& sig)
: function(sig) { }

PlanIter_t fn_index_of::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnIndexOfIterator(loc, argv);
}

bool fn_index_of::validate_args(
	vector<PlanIter_t>& argv) const
{
	return (argv.size()==2 || argv.size()==3);
}

xqtref_t fn_index_of::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


//15.1.4 fn:empty
//---------------
fn_empty::fn_empty(const signature& sig)
: function(sig) { }

PlanIter_t fn_empty::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnEmptyIterator(loc, argv);
}

bool fn_empty::validate_args(
	vector<PlanIter_t>& argv) const
{
  return ( argv.size() ==1 );
}

xqtref_t fn_empty::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


//15.1.5 fn:exists
//----------------
fn_exists::fn_exists(const signature& sig)
  : function(sig) { }

PlanIter_t fn_exists::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnExistsIterator(loc,argv);
}

bool fn_exists::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

xqtref_t fn_exists::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
}


//15.1.6 fn:distinct-values
//-------------------------
PlanIter_t fn_distinct_values_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDistinctValuesIterator(loc, argv);
}

bool fn_distinct_values_1::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1 || argv.size() == 2);
}

xqtref_t fn_distinct_values_1::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR;
}

//15.1.7 fn:insert-before
//-----------------------
fn_insert_before::fn_insert_before(const signature& sig)
  : function(sig) { }

PlanIter_t fn_insert_before::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnInsertBeforeIterator(loc, argv);
}

bool fn_insert_before::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 3); 
}

xqtref_t fn_insert_before::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_ONE; // what to do here?
}

//15.1.8 fn:remove
//----------------
PlanIter_t fn_remove::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnRemoveIterator(loc, argv);
}

bool fn_remove::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2); 
}

xqtref_t fn_remove::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


//15.1.9 fn:reverse
//-----------------
PlanIter_t fn_reverse::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new FnReverseIterator(loc, argv);
}

bool fn_reverse::validate_args(
	vector<PlanIter_t>& argv) const
{
	return argv.size() == 1;
}

xqtref_t fn_reverse::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

//15.1.10 fn:subsequence
//----------------------
PlanIter_t fn_subsequence_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnSubsequenceIterator(loc, argv);
}

bool fn_subsequence_2::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2 || argv.size() == 3 );
}

xqtref_t fn_subsequence_2::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


//15.1.11 fn:unordered
//--------------------


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one
fn_zero_or_one::fn_zero_or_one(const signature& sig)
: function(sig) { }

PlanIter_t fn_zero_or_one::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnZeroOrOneIterator(loc, argv);
}

bool fn_zero_or_one::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

xqtref_t fn_zero_or_one::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

//15.2.2 fn:one-or-more
fn_one_or_more::fn_one_or_more(const signature& sig)
: function(sig) { }

PlanIter_t fn_one_or_more::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnOneOrMoreIterator(loc, argv);
}

bool fn_one_or_more::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

xqtref_t fn_one_or_more::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

//15.2.3 fn:exactly-one
fn_exactly_one::fn_exactly_one(const signature& sig)
: function(sig) { }

PlanIter_t fn_exactly_one::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnExactlyOneIterator(loc, argv);
}

bool fn_exactly_one::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

xqtref_t fn_exactly_one::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}



/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal

//15.3.2 op:union
//ordered
fn_union::fn_union(const signature& sig)
: function(sig) { }

PlanIter_t fn_union::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  bool distinct = ann.get_annotation (AnnotationKey::IGNORES_DUP_NODES) != TSVAnnotationValue::TRUE_VALUE;
  if (ann.get_annotation (AnnotationKey::IGNORES_SORTED_NODES) != TSVAnnotationValue::TRUE_VALUE)
    return new NodeSortIterator(loc, new FnConcatIterator(loc, argv), true, distinct, false);
  else {
    PlanIter_t concat = new FnConcatIterator(loc, argv);
    return
      distinct ? new NodeDistinctIterator(loc, concat, true) : concat;
  }
}

bool fn_union::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2);
}

xqtref_t fn_union::type_check(signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR;
}

//15.3.3 op:intersect
fn_intersect::fn_intersect(const signature& sig)
: function(sig) { }

PlanIter_t fn_intersect::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  bool distinct = ann.get_annotation (AnnotationKey::IGNORES_DUP_NODES) != TSVAnnotationValue::TRUE_VALUE;
  if (ann.get_annotation (AnnotationKey::IGNORES_SORTED_NODES) != TSVAnnotationValue::TRUE_VALUE) {
    std::vector<PlanIter_t> inputs;
    for (std::vector<PlanIter_t>::iterator i = argv.begin ();
         i != argv.end (); i++)
      inputs.push_back (new NodeSortIterator (loc, *i, true, distinct, false));
    return new SortSemiJoinIterator(loc, inputs);
  } else
    return new HashSemiJoinIterator(loc, argv);
}

bool fn_intersect::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2);
}

xqtref_t fn_intersect::type_check(signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR;
}

//15.3.4 op:except
// except; requires two sorted inputs; does duplicate elimination
fn_except::fn_except(const signature& sig)
: function(sig) { }

PlanIter_t fn_except::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  // bool distinct = ann.get_annotation (AnnotationKey::IGNORES_DUP_NODES) != TSVAnnotationValue::TRUE_VALUE;
  if (ann.get_annotation (AnnotationKey::IGNORES_SORTED_NODES) == TSVAnnotationValue::TRUE_VALUE) 
    return new HashSemiJoinIterator(loc, argv, true);
  else {
    ZORBA_NOT_IMPLEMENTED ("op:except when sorted output is required");
    return NULL;
  }
}

bool fn_except::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2);
}

xqtref_t fn_except::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR;
}

#if 0
// except; doesn't require sorted inputs but does not return the result in document order
//         also does duplicate elimination
PlanIter_t fn_except::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
}
#endif

/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.1 fn:count
fn_count::fn_count(const signature& sig)
: function(sig) { }

PlanIter_t fn_count::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
 return new FnCountIterator(loc, argv);
}

bool fn_count::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

xqtref_t fn_count::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.INTEGER_TYPE_ONE;
}

//15.4.2 fn:avg
fn_avg::fn_avg(const signature& sig)
: function(sig) { }

PlanIter_t fn_avg::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnAvgIterator(loc, argv);
}

bool fn_avg::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}

xqtref_t fn_avg::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION;
}

//15.4.3 fn:max
fn_max_1::fn_max_1(const signature& sig)
: function(sig) { }

PlanIter_t fn_max_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnMinMaxIterator(loc, argv, FnMinMaxIterator::MAX);
}

bool fn_max_1::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1 || argv.size() == 2);
}

xqtref_t fn_max_1::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION;
}

//15.4.4 fn:min
fn_min_1::fn_min_1(const signature& sig)
: function(sig) { }

PlanIter_t fn_min_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnMinMaxIterator(loc, argv, FnMinMaxIterator::MIN);
}

bool fn_min_1::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1 || argv.size() == 2);
}

xqtref_t fn_min_1::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION;
}

//15.4.5 fn:sum
fn_sum_1::fn_sum_1(const signature& sig)
: function(sig) { }

PlanIter_t fn_sum_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnSumIterator(loc, argv);
}

bool fn_sum_1::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1 || argv.size() == 2);
}

xqtref_t fn_sum_1::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;
}

xqtref_t fn_sum_2::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION;
}


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to
op_to::op_to(const signature& sig)
: function(sig) { }

PlanIter_t op_to::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new OpToIterator(loc, argv);
}

bool op_to::validate_args(
	vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2);
}

xqtref_t op_to::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

//15.5.2 fn:id

//15.5.3 fn:idref



//15.5.4 fn:doc
//-------------
fn_doc_func::fn_doc_func(
	const signature& sig)
:
	function(sig)
{
}

PlanIter_t fn_doc_func::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDocIterator(loc, argv[0]);
}
  
bool fn_doc_func::validate_args(
	vector<PlanIter_t>& argv) const
{
	if (argv.size()!=1) return false;
	return true;
}

xqtref_t fn_doc_func::type_check(
	signature& /*sig*/) const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


//15.5.5 fn:doc-available

//15.5.6 fn:collection


// internal functions

#define A_SORT a [0]
#define A_ATOMICS a [1]
#define A_DISTINCT a [2]
#define A_ASCENDING a [3]

bool op_node_sort_distinct::required (const AnnotationHolder &ann) const {
  const bool *a = action ();
  return (A_SORT && ann.get_annotation (AnnotationKey::IGNORES_SORTED_NODES) != TSVAnnotationValue::TRUE_VALUE)
    || (A_DISTINCT && ann.get_annotation (AnnotationKey::IGNORES_DUP_NODES) != TSVAnnotationValue::TRUE_VALUE);
}

PlanIter_t op_node_sort_distinct::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const {
  const bool *a = action ();
  bool distinct = A_DISTINCT;
  if (ann.get_annotation (AnnotationKey::IGNORES_DUP_NODES))
    distinct = false;
#if 0  // NodeDistinctIterator seems broken for now
  if (! A_SORT || ann.get_annotation (AnnotationKey::IGNORES_SORTED_NODES))
    return distinct ? new NodeDistinctIterator (loc, argv [0], A_ATOMICS) : NULL;
#endif
  return new NodeSortIterator (loc, argv [0], A_ASCENDING, distinct, A_ATOMICS);
}

bool op_node_sort_distinct::validate_args(vector<PlanIter_t>& argv) const {
  return (argv.size() == 1);
}

xqtref_t op_node_sort_distinct::type_check(signature& /*sig*/) const {
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

void op_node_sort_distinct::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const {
  const bool *a = action ();
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    if (parent->get_annotation (k) == TSVAnnotationValue::TRUE_VALUE || (k == AnnotationKey::IGNORES_SORTED_NODES ? A_SORT : A_DISTINCT))
      kids [src]->put_annotation (k, TSVAnnotationValue::TRUE_VALUE);
    break;
  default: break;
  }
}

const function *op_node_sort_distinct::op_for_action (const static_context *sctx, const bool *a, const AnnotationHolder &ann) {
#define LOOKUP_OP1( local ) static_cast<const function *> (sctx->lookup_builtin_fn ((xqp_string (":") + local).c_str (), 1))
  bool distinct = A_DISTINCT;
  if (ann.get_annotation (AnnotationKey::IGNORES_DUP_NODES))
    distinct = false;
  if (! A_SORT || ann.get_annotation (AnnotationKey::IGNORES_SORTED_NODES))
    return distinct ? LOOKUP_OP1 ("distinct-nodes" + (A_ATOMICS ? "-or-atomics" : "")) : NULL;
  xqp_string part1 = xqp_string ("sort-") + (distinct ? "distinct-" : "") + "nodes-";
  xqp_string part2 = xqp_string (A_ASCENDING ? "asc" : "desc") + (A_ATOMICS ? "-or-atomics" : "ending");
  return LOOKUP_OP1 (part1 + part2);
#undef LOOKUP_OP1
}


xqtref_t single_seq_function::return_type (const std::vector<xqtref_t> &arg_types) const { return arg_types [src]; }

void single_seq_function::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const {
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    kids [src]->put_annotation (k, parent->get_annotation (k));
    break;
  default: break;
  }
}

} /* namespace zorba */

