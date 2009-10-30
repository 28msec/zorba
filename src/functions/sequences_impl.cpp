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
 
#include "functions/sequences.h"
#include "functions/sequences_impl.h"

#include "runtime/sequences/sequences.h"
#include "runtime/sequences/SequencesImpl.h"
#include "system/globalenv.h"

#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/path_expr.h"

#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

#include "types/typeops.h"

namespace zorba 
{

xqtref_t op_concatenate::return_type(const std::vector<xqtref_t>& arg_types) const 
{
  int sz = arg_types.size();

  if (sz == 0)
  {
    return GENV_TYPESYSTEM.EMPTY_TYPE;
  }
  else 
  {
    xqtref_t t = arg_types[0];
    TypeConstants::quantifier_t q = TypeConstants::QUANT_STAR;
    for (int i = 1; i < sz; i++) 
    {
      t = TypeOps::union_type(*t, *arg_types[i]);
      TypeConstants::quantifier_t pq = TypeOps::quantifier(*t);
      if (pq == TypeConstants::QUANT_ONE || pq == TypeConstants::QUANT_PLUS)
        q = TypeConstants::QUANT_PLUS;
    }

    return GENV_TYPESYSTEM.create_type_x_quant(*t, q);
  }
}


void op_concatenate::compute_annotation(
    AnnotationHolder *parent,
    std::vector<AnnotationHolder *> &kids,
    Annotations::Key k) const 
{
  switch (k) 
  {
    case Annotations::IGNORES_SORTED_NODES:
    case Annotations::IGNORES_DUP_NODES:
    {
      for (std::vector<AnnotationHolder *>::iterator i = kids.begin();
           i < kids.end();
           ++i)
        TSVAnnotationValue::update_annotation((*i), k, parent->get_annotation(k));

      break;
    }
    default: break;
  }
}



function* fn_sum::specialize(
   static_context* sctx,
   const std::vector<xqtref_t>& argTypes) const
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t argType = argTypes[0];

  if (TypeOps::is_subtype(*argType, *rtm.UNTYPED_ATOMIC_TYPE_STAR))
  {
    return sctx->lookup_builtin_fn("sum_double", get_arity());
  }
  else if (TypeOps::is_subtype(*argType, *rtm.DOUBLE_TYPE_STAR))
  {
    return sctx->lookup_builtin_fn("sum_double", get_arity());
  }
  else if (TypeOps::is_subtype(*argType, *rtm.FLOAT_TYPE_STAR))
  {
    return sctx->lookup_builtin_fn("sum_foat", get_arity());
  }
  else if (TypeOps::is_subtype(*argType, *rtm.INTEGER_TYPE_STAR))
  {
    return sctx->lookup_builtin_fn("sum_integer", get_arity());
  }
  else if (TypeOps::is_subtype(*argType, *rtm.DECIMAL_TYPE_STAR))
  {
    return sctx->lookup_builtin_fn("sum_decimal", get_arity());
  }
  else
  {
    return NULL;
  }
}

xqtref_t fn_exactly_one_noraise::return_type(
    const std::vector<xqtref_t>& arg_types) const
{
  if (theRaiseError)
    return TypeOps::prime_type(*arg_types[0]);
  else
    return function::return_type(arg_types);
}


PlanIter_t
fn_exactly_one_noraise::codegen(CompilerCB* aCb,
                                static_context* aSctx,
                                const QueryLoc& aLoc,
                                std::vector<PlanIter_t>& aArgs,
                                AnnotationHolder& aAnn) const
{
  return new FnExactlyOneIterator(aSctx,
                                  aLoc,
                                  aArgs,
                                  theRaiseError,
                                  testFlag(FunctionConsts::DoDistinct));
}

PlanIter_t
fn_union::codegen (
      CompilerCB* /*cb*/,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      AnnotationHolder &ann) const
{
  return new FnConcatIterator(sctx, loc, argv, false);
}

PlanIter_t fn_intersect::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc, 
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann) const
{
#if 0  // we can't access PRODUCES_* from the inputs, must rethink
  bool distinct = ann.get_annotation (Annotations::IGNORES_DUP_NODES) != TSVAnnotationValue::TRUE_VAL;
  bool sort = ann.get_annotation (Annotations::IGNORES_SORTED_NODES) != TSVAnnotationValue::TRUE_VAL;

  std::vector<PlanIter_t> inputs;
  for (std::vector<PlanIter_t>::iterator i = argv.begin ();
       i != argv.end (); i++)
    inputs.push_back (new NodeSortIterator (loc, *i, true, distinct, false));
  return new SortSemiJoinIterator(loc, inputs);
#endif

  return new HashSemiJoinIterator(sctx, loc, argv);
}


PlanIter_t
fn_except::codegen(
      CompilerCB* /*cb*/,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      AnnotationHolder& ann) const
{
  // TODO: use SortAntiJoinIterator when available (trac ticket 254)
  return new HashSemiJoinIterator(sctx, loc, argv, true);
}

void
fn_subsequence::compute_annotation(
    AnnotationHolder* parent,
    std::vector<AnnotationHolder *>& kids,
    Annotations::Key k) const
{
  switch (k) 
  {
  case Annotations::IGNORES_SORTED_NODES:
  case Annotations::IGNORES_DUP_NODES:
    // don't use single_seq_fun default propagation rule
    return;
  default: single_seq_opt_function::compute_annotation (parent, kids, k);
  }
}


PlanIter_t
fn_subsequence::codegen(
      CompilerCB* /*cb*/,
      static_context* aSctx,
      const QueryLoc& aLoc,
      std::vector<PlanIter_t>& aArgs,
      AnnotationHolder& aAnn) const
{
  fo_expr& subseqExpr = static_cast<fo_expr&>(aAnn);

  const relpath_expr* pathExpr =
  dynamic_cast<const relpath_expr*>(subseqExpr[0].getp());

  const const_expr* posExpr =
  dynamic_cast<const const_expr*>(subseqExpr[1].getp());

  const const_expr* lenExpr = NULL;
  if (subseqExpr.num_args() > 2)
    lenExpr = dynamic_cast<const const_expr*>(subseqExpr[2].getp());

  if (posExpr != NULL && lenExpr != NULL && pathExpr != NULL)
  {
    xqp_double pos1 = posExpr->get_val()->getDoubleValue().round();
    long pos2 = static_cast<long>(pos1.getNumber());

    xqp_double len1 = lenExpr->get_val()->getDoubleValue().round();
    long len2 = static_cast<long>(pos1.getNumber());

    ulong numSteps = pathExpr->numSteps();

    if (pos2 > 0 && len2 == 1 && numSteps == 2)
    {
      AxisIteratorHelper* input = dynamic_cast<AxisIteratorHelper*>(aArgs[0].getp());
      assert(input != NULL);

      if (input->setTargetPos(pos2-1))
        return aArgs[0];
    }
  }

  return new FnSubsequenceIterator(aSctx, aLoc, aArgs);
}

xqtref_t
fn_zero_or_one::return_type(const std::vector<xqtref_t>& arg_types) const
{
  xqtref_t srcType = arg_types[0];

  return srcType->get_manager()->
         create_type(*TypeOps::prime_type(*srcType), TypeConstants::QUANT_QUESTION);
}

PlanIter_t
fn_zero_or_one::codegen(
      CompilerCB* /*cb*/,
      static_context* aSctx,
      const QueryLoc& aLoc,
      std::vector<PlanIter_t>& aArgs,
      AnnotationHolder& aAnn) const
{
  return new FnZeroOrOneIterator(aSctx,
                                 aLoc,
                                 aArgs,
                                 testFlag(FunctionConsts::DoDistinct));
}

PlanIter_t
fn_distinct_values::codegen(CompilerCB* /* cb */,
                   static_context* sctx,
                   const QueryLoc& loc,
                   std::vector<PlanIter_t>& argv,
                   AnnotationHolder &/*ann*/) const
{
  return new FnDistinctValuesIterator(sctx, loc, argv);
}

PlanIter_t
fn_max::codegen(
        CompilerCB* /*cb*/,
        static_context* aSctx,
        const QueryLoc& aLoc,
        std::vector<PlanIter_t>& aArgs,
        AnnotationHolder& /*aAnn*/) const
{
  return new FnMinMaxIterator(aSctx, aLoc, aArgs, FnMinMaxIterator::MAX);
}

PlanIter_t
fn_min::codegen(
        CompilerCB* /*cb*/,
        static_context* aSctx,
        const QueryLoc& aLoc,
        std::vector<PlanIter_t>& aArgs,
        AnnotationHolder& /*ann*/) const
{
  return new FnMinMaxIterator(aSctx, aLoc, aArgs, FnMinMaxIterator::MIN);
}

//15.5.2 fn:id
typedef function_impl<FnIdIterator> fn_id;


//15.5.3 fn:idref
typedef function_impl<FnIdRefIterator> fn_id_ref;

void
populate_context_sequences_impl(static_context* sctx)
{
  DECL(sctx, fn_exactly_one,
       (createQName(XQUERY_FN_NS,"fn","exactly-one"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, fn_exactly_one_noraise,
       (createQName(XQUERY_FN_NS,"fn",":exactly-one-noraise"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

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

  DECL(sctx, fn_distinct_values,
       (createQName(XQUERY_FN_NS,"fn","distinct-values"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));

  DECL(sctx, fn_distinct_values,
       (createQName(XQUERY_FN_NS,"fn","distinct-values"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR));
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

}

} /* namespace zorba */
