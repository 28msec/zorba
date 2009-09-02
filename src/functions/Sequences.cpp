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
#include "functions/function_impl.h"
#include "functions/single_seq_func.h"

#include "runtime/sequences/SequencesImpl.h"

#include "context/static_context.h"

#include "system/globalenv.h"

#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

#include "types/typeops.h"


using namespace std;


namespace zorba 
{


#define TSV_TRUE TSVAnnotationValue::TRUE_VAL
#define TSV_TRUE_P TSVAnnotationValue::TRUE_VAL.getp()


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.1 General Functions and Operators on Sequences                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.1.1 fn:boolean (effective boolean value)
********************************************************************************/


/*******************************************************************************
  15.1.2  op:concatenate($seq1 as item()*, $seq2 as item()*) as item()*

  Summary: Returns a sequence consisting of the items in $seq1 followed by the
  items in $seq2. This function backs up the infix operator ",". If either
  sequence is the empty sequence, the other operand is returned. 
********************************************************************************/
class op_concatenate : public function 
{
public:
  op_concatenate(const signature& sig) : function (sig) {}

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const;

  void compute_annotation(
        AnnotationHolder* parent,
        std::vector<AnnotationHolder *>& kids,
        Annotation::key_t k) const;

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder &ann) const 
  {
    return new FnConcatIterator(sctx, loc, argv, ann.is_updating());
  }

};
  

xqtref_t op_concatenate::return_type(const std::vector<xqtref_t>& arg_types) const 
{
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


void op_concatenate::compute_annotation (
    AnnotationHolder *parent,
    std::vector<AnnotationHolder *> &kids,
    Annotation::key_t k) const 
{
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    for (std::vector<AnnotationHolder *>::iterator i = kids.begin (); i < kids.end (); i++)
      TSVAnnotationValue::update_annotation ((*i), k, parent->get_annotation (k));
    break;
  default: break;
  }
}


/*******************************************************************************
  15.1.3 fn:index-of
********************************************************************************/
typedef function_impl<FnIndexOfIterator> fn_index_of;


/*******************************************************************************
  15.1.4 fn:empty
********************************************************************************/
typedef function_impl<FnEmptyIterator> fn_empty;


/*******************************************************************************
  15.1.5 fn:exists
********************************************************************************/
typedef function_impl<FnExistsIterator> fn_exists;


/*******************************************************************************
  15.1.6 fn:distinct-values
********************************************************************************/
class fn_distinct_values : public single_seq_function 
{
public:
  fn_distinct_values(const signature& sig) : single_seq_function (sig) {}

  ZORBA_PRODUCES_SORTED;
  ZORBA_PRODUCES_DISTINCT;

  DEFAULT_NARY_CODEGEN(FnDistinctValuesIterator);
};


/*******************************************************************************
  15.1.7 fn:insert-before
********************************************************************************/
class fn_insert_before : public function 
{
public:
  fn_insert_before(const signature& sig) : function (sig) {}

  bool propagatesInputToOutput(uint32_t aProducer) const { return 1 != aProducer; }

  DEFAULT_NARY_CODEGEN(FnInsertBeforeIterator);
};


/*******************************************************************************
  15.1.8 fn:remove
********************************************************************************/
class fn_remove : public single_seq_opt_function 
{
public:
  fn_remove(const signature& sig) : single_seq_opt_function (sig) {}

  DEFAULT_NARY_CODEGEN(FnRemoveIterator);
};


/*******************************************************************************
  15.1.9 fn:reverse
********************************************************************************/
class fn_reverse : public single_seq_function 
{
public:
  fn_reverse(const signature& sig) : single_seq_function (sig) {}

  ZORBA_NOT_PRODUCES_SORTED;

  DEFAULT_NARY_CODEGEN(FnReverseIterator);
};


/*******************************************************************************
  15.1.10 fn:subsequence
********************************************************************************/
class fn_subsequence : public single_seq_opt_function 
{
public:
  fn_subsequence(const signature&sig) : single_seq_opt_function (sig) {}

  COMPUTE_ANNOTATION_DECL();

  DEFAULT_NARY_CODEGEN(FnSubsequenceIterator);
};
  

void fn_subsequence::compute_annotation(
    AnnotationHolder* parent,
    std::vector<AnnotationHolder *>& kids,
    Annotation::key_t k) const 
{
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    // don't use single_seq_fun default propagation rule
    return;
  default: single_seq_opt_function::compute_annotation (parent, kids, k);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.2 Functions That Test the Cardinality of Sequences                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.2.1 fn:zero-or-one
********************************************************************************/
class fn_zero_or_one : public function
{
public:
  fn_zero_or_one(const signature& sig) : function(sig) { }

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const
  {
    xqtref_t srcType = arg_types[0];

    return srcType->get_manager()->
           create_type(*TypeOps::prime_type(*srcType), TypeConstants::QUANT_QUESTION);
  }

  CODEGEN_DECL();
};


CODEGEN_DEF(fn_zero_or_one)
{
  return new FnZeroOrOneIterator(aSctx, aLoc, aArgs, testFlag(DoDistinct));
}


/*******************************************************************************
  15.2.2 fn:one-or-more
********************************************************************************/
class fn_one_or_more : public single_seq_function 
{
public:
  fn_one_or_more (const signature& sig) : single_seq_function (sig) {}

  DEFAULT_NARY_CODEGEN(FnOneOrMoreIterator)
};


/*******************************************************************************
  15.2.3 fn:exactly-one
********************************************************************************/
class fn_exactly_one_noraise : public function 
{
protected:
  bool theRaiseError;

public:
  fn_exactly_one_noraise(const signature& sig) 
    :
    function(sig),
    theRaiseError(false)
  {}

  xqtref_t return_type(const std::vector<xqtref_t>& arg_types) const;

  CODEGEN_DECL();
};


class fn_exactly_one : public fn_exactly_one_noraise 
{
public:
  fn_exactly_one(const signature& sig) : fn_exactly_one_noraise(sig)
  {
    theRaiseError = true; 
  }
};


xqtref_t fn_exactly_one_noraise::return_type(
    const std::vector<xqtref_t>& arg_types) const 
{
  if (theRaiseError)
    return TypeOps::prime_type(*arg_types[0]);
  else
    return function::return_type(arg_types);
}


CODEGEN_DEF(fn_exactly_one_noraise)
{
  return new FnExactlyOneIterator(aSctx,
                                  aLoc,
                                  aArgs,
                                  theRaiseError,
                                  testFlag(DoDistinct));
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.3 Equals, Union, Intersection and Except                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.3.1 fn:deep-equal
********************************************************************************/
class fn_deep_equal : public function 
{
public:
  fn_deep_equal(const signature& sig) : function (sig) {}

  ZORBA_NOT_PROPAGATES_I2O;

  DEFAULT_NARY_CODEGEN(FnDeepEqualIterator);
};


/*******************************************************************************
  fn:union is implemented as fn:concat wrapped in a sort-distinct-nodes-asc.
********************************************************************************/
class fn_union : public function 
{
public:
  fn_union(const signature& sig) : function (sig) {}

  ZORBA_PRODUCES_SORTED;
  ZORBA_PRODUCES_DISTINCT;

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder &ann) const
  {
    return new FnConcatIterator(sctx, loc, argv, false);
  }
};


/*******************************************************************************
  For intersect and except, it's always more efficient to sort the output
  and use hash-join than to sort the inputs and use mergesort-join. Only if
  the inputs happen to be sorted for a different reason will we use mergesort:
  for $x in path/expr1 for $y in path/expr2 return ($x, $y, ($x intersect $y))

  For now, codegen doesn't know whether the inputs are sorted or not.
  TODO: annotate expressions with USE_HASH / USE_MERGESORT properties
  during optimization.
********************************************************************************/
class fn_intersect : public function 
{
public:
  fn_intersect(const signature& sig) : function (sig) {}

  ZORBA_PRODUCES_SORTED;
  ZORBA_PRODUCES_DISTINCT;

  CODEGEN_DECL();
};


PlanIter_t fn_intersect::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc, 
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann) const
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

  return new HashSemiJoinIterator(sctx, loc, argv);
}


/*******************************************************************************

********************************************************************************/
class fn_except: public function 
{
public:
  fn_except(const signature& sig) : function (sig) {}

  ZORBA_PRODUCES_SORTED;
  ZORBA_PRODUCES_DISTINCT;
  
  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    // TODO: use SortAntiJoinIterator when available (trac ticket 254)
    return new HashSemiJoinIterator(sctx, loc, argv, true);
  }
};
  


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.4 Aggregate Functions                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.4.1 fn:count
********************************************************************************/
typedef function_impl<FnCountIterator> fn_count;


/*******************************************************************************
  15.4.2 fn:avg
********************************************************************************/
typedef function_impl<FnAvgIterator> fn_avg;


/*******************************************************************************
  15.4.3 fn:max
********************************************************************************/
class fn_max : public function 
{
public:
  fn_max(const signature& sig) : function (sig) {}

  ZORBA_PROPAGATES_ONE_I2O(0);

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const 
  {
    return new FnMinMaxIterator(sctx, loc, argv, FnMinMaxIterator::MAX);
  }
};


/*******************************************************************************
  15.4.4 fn:min
********************************************************************************/
class fn_min : public function 
{
public:
  fn_min(const signature& sig) : function (sig) {}

  ZORBA_PROPAGATES_ONE_I2O(0);

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const 
  {
    return new FnMinMaxIterator(sctx, loc, argv, FnMinMaxIterator::MIN);
  }
};


/*******************************************************************************
  15.4.5 fn:sum
********************************************************************************/
typedef function_impl<FnSumIterator> fn_sum;


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.5 Functions and Operators that Generate Sequences                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.5.1 op:to
********************************************************************************/
typedef function_impl<OpToIterator> op_to;


/*******************************************************************************
  15.5.2 fn:id
********************************************************************************/
typedef function_impl<FnIdIterator> fn_id;


/*******************************************************************************
  15.5.3 fn:idref
********************************************************************************/
typedef function_impl<FnIdRefIterator> fn_id_ref;


/*******************************************************************************
  15.5.4 fn:doc
********************************************************************************/
class fn_doc_func : public function 
{
public:
  fn_doc_func(const signature& sig) : function (sig) {}

  virtual bool isSource() const { return true; }

  bool requires_dyn_ctx () const { return true; }  // TODO: rename to unfoldable()

  ZORBA_NOT_PROPAGATES_I2O;

  DEFAULT_NARY_CODEGEN(FnDocIterator);
};


/*******************************************************************************

********************************************************************************/
class fn_parse_func : public function 
{
public:
  fn_parse_func(const signature& sig) : function (sig) {}

  virtual bool isSource() const { return true; }

  bool requires_dyn_ctx () const { return true; }  // TODO: rename to unfoldable()

  DEFAULT_NARY_CODEGEN(FnParseIterator);
};


/*******************************************************************************
  15.5.5 fn:doc-available
********************************************************************************/
class fn_doc_available_func : public function 
{
public:
  fn_doc_available_func(const signature& sig) : function (sig) {}

  ZORBA_NOT_PROPAGATES_I2O;

  DEFAULT_NARY_CODEGEN(FnDocAvailableIterator);
};


/*******************************************************************************

********************************************************************************/
void populateContext_Sequences(static_context* sctx) 
{
  DECL(sctx, fn_doc_func,
       (createQName(XQUERY_FN_NS,"fn","doc"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_UNTYPED_TYPE_QUESTION));
  
  DECL(sctx, fn_doc_available_func,
       (createQName(XQUERY_FN_NS,"fn","doc-available"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, fn_parse_func,
       (createQName(ZORBA_ALEXIS_FN_NS,"fn-zorba-util","parse"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE));

  DECL(sctx, op_concatenate,
       (createQName(XQUERY_FN_NS,"fn",":concatenate"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_exists,
       (createQName(XQUERY_FN_NS,"fn","exists"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, fn_empty,
       (createQName(XQUERY_FN_NS,"fn","empty"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, fn_index_of,
       (createQName(XQUERY_FN_NS,"fn","index-of"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

  DECL(sctx, fn_index_of,
       (createQName(XQUERY_FN_NS,"fn","index-of"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

  DECL(sctx, fn_remove,
       (createQName(XQUERY_FN_NS,"fn","remove"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_reverse,
       (createQName(XQUERY_FN_NS,"fn","reverse"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_distinct_values,
       (createQName(XQUERY_FN_NS,"fn","distinct-values"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

  DECL(sctx, fn_distinct_values,
       (createQName(XQUERY_FN_NS,"fn","distinct-values"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

  DECL(sctx, fn_insert_before,
       (createQName(XQUERY_FN_NS,"fn","insert-before"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE,    
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_subsequence,
       (createQName(XQUERY_FN_NS,"fn","subsequence"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,    
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_subsequence,
       (createQName(XQUERY_FN_NS,"fn","subsequence"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_zero_or_one,
       (createQName(XQUERY_FN_NS,"fn","zero-or-one"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION));
  
  DECL(sctx, fn_one_or_more,
       (createQName(XQUERY_FN_NS,"fn","one-or-more"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_PLUS));
  
  DECL(sctx, fn_exactly_one,
       (createQName(XQUERY_FN_NS,"fn","exactly-one"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, fn_exactly_one_noraise,
       (createQName(XQUERY_FN_NS,"fn",":exactly-one-noraise"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, fn_count,
       (createQName(XQUERY_FN_NS,"fn","count"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

  DECL(sctx, fn_avg,
       (createQName(XQUERY_FN_NS,"fn","avg"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, fn_max,
       (createQName(XQUERY_FN_NS,"fn","max"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));
  
  DECL(sctx, fn_max,
       (createQName(XQUERY_FN_NS,"fn","max"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, fn_min,
       (createQName(XQUERY_FN_NS,"fn","min"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, fn_min,
       (createQName(XQUERY_FN_NS,"fn","min"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, fn_sum,
       (createQName(XQUERY_FN_NS,"fn","sum"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, fn_sum,
       (createQName(XQUERY_FN_NS,"fn","sum"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_to,
       (createQName(XQUERY_FN_NS,"fn",":to"),
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION, 
        GENV_TYPESYSTEM.INTEGER_TYPE_STAR));

  DECL(sctx, fn_id,
       (createQName(XQUERY_FN_NS,"fn","id"),
        GENV_TYPESYSTEM.STRING_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR)
       );

  DECL(sctx, fn_id_ref,
       (createQName(XQUERY_FN_NS,"fn","idref"),
        GENV_TYPESYSTEM.STRING_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, fn_union,
       (createQName(XQUERY_FN_NS,"fn",":union"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
  
  DECL(sctx, fn_intersect,
       (createQName(XQUERY_FN_NS,"fn",":intersect"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
  
  DECL(sctx, fn_except,
       (createQName(XQUERY_FN_NS,"fn",":except"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));
  
  DECL(sctx, fn_deep_equal,
       (createQName(XQUERY_FN_NS, "fn", "deep-equal"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, fn_deep_equal,
       (createQName(XQUERY_FN_NS, "fn", "deep-equal"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
}

} /* namespace zorba */

