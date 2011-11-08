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

#include "system/globalenv.h"

#include "compiler/expression/expr_base.h"

#include "functions/func_booleans_impl.h"
#include "functions/function_impl.h"
#include "functions/library.h"

#include "runtime/booleans/BooleanImpl.h"
#include "runtime/booleans/booleans.h"
#include "runtime/core/item_iterator.h"

#include "store/api/item_factory.h"

#include "types/typeops.h"
#include "zorbamisc/ns_consts.h"


namespace zorba
{

/*******************************************************************************
  Glass GenericOpComparison is the base class for both value and general
  comparisons.
********************************************************************************/
class GenericOpComparison : public function
{
public:
  GenericOpComparison(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    function(sig, kind)
  {
  }

  bool isComparisonFunction() const { return true; }

  virtual const char* comparison_name() const { return ""; }

  virtual function* toValueComp(static_context *) const { return NULL; }

  virtual bool specializable() const { return true; }

  function* specialize(
        static_context* sctx,
        const std::vector<xqtref_t>& argTypes) const;

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const
  {
    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  virtual PlanIter_t codegen(
        CompilerCB* cb,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder &ann) const
  {
    return createIterator(sctx, loc, argv);
  }

protected:
  virtual PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& ) const = 0;
};



function* GenericOpComparison::specialize(
    static_context* sctx,
    const std::vector<xqtref_t>& argTypes) const
{
  const TypeManager* tm = sctx->get_typemanager();
  xqtref_t t0 = argTypes[0];
  xqtref_t t1 = argTypes[1];

  if (! (TypeOps::is_builtin_atomic(tm, *t0) && TypeOps::is_builtin_atomic(tm, *t1)))
    return NULL;

  TypeConstants::atomic_type_code_t tc0 = TypeOps::get_atomic_type_code(*t0);
  TypeConstants::atomic_type_code_t tc1 = TypeOps::get_atomic_type_code(*t1);

  if (tc0 == TypeConstants::XS_UNTYPED_ATOMIC ||
      tc1 == TypeConstants::XS_UNTYPED_ATOMIC ||
      tc0 == TypeConstants::XS_ANY_ATOMIC ||
      tc1 == TypeConstants::XS_ANY_ATOMIC)
    return NULL;

  return toValueComp(sctx);
}


/*******************************************************************************
  class ValueOpComparison
********************************************************************************/
class ValueOpComparison : public GenericOpComparison
{
public:
  ValueOpComparison(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    GenericOpComparison(sig, kind)
  {
  }

  bool isValueComparisonFunction() const { return true; }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;

  function* specialize(
        static_context* sctx,
        const std::vector<xqtref_t>& argTypes) const;
};


xqtref_t ValueOpComparison::getReturnType(
    const TypeManager* tm,
    const std::vector<xqtref_t>& arg_types) const
{
  xqtref_t empty = GENV_TYPESYSTEM.EMPTY_TYPE;
  TypeConstants::quantifier_t quant = TypeConstants::QUANT_ONE;

  for (int i = 0; i < 2; i++)
  {
    if (TypeOps::is_equal(tm, *empty, *arg_types[i], QueryLoc::null))
      return empty;

    TypeConstants::quantifier_t aq = TypeOps::quantifier(*arg_types[i]);
    if (aq == TypeConstants::QUANT_QUESTION || aq == TypeConstants::QUANT_STAR)
    {
      quant = TypeConstants::QUANT_QUESTION;
    }
  }

  return (quant == TypeConstants::QUANT_QUESTION ?
          GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION :
          GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE);
}


#define SPECIALIZE_VALUE_COMP_FUNCTION(kind, type)                  \
  switch (kind)                                                     \
  {                                                                 \
  case FunctionConsts::OP_VALUE_EQUAL_2:                            \
    return GET_BUILTIN_FUNCTION(OP_VALUE_EQUAL_##type##_2);         \
                                                                    \
  case FunctionConsts::OP_VALUE_NOT_EQUAL_2:                        \
    return GET_BUILTIN_FUNCTION(OP_VALUE_NOT_EQUAL_##type##_2);     \
                                                                    \
  case FunctionConsts::OP_VALUE_LESS_EQUAL_2:                       \
    return GET_BUILTIN_FUNCTION(OP_VALUE_LESS_EQUAL_##type##_2);    \
                                                                    \
  case FunctionConsts::OP_VALUE_LESS_2:                             \
    return GET_BUILTIN_FUNCTION(OP_VALUE_LESS_##type##_2);          \
                                                                    \
  case FunctionConsts::OP_VALUE_GREATER_EQUAL_2:                    \
    return GET_BUILTIN_FUNCTION(OP_VALUE_GREATER_EQUAL_##type##_2); \
                                                                    \
  case FunctionConsts::OP_VALUE_GREATER_2:                          \
    return GET_BUILTIN_FUNCTION(OP_VALUE_GREATER_##type##_2);       \
                                                                    \
  default:                                                          \
    ZORBA_ASSERT(false);                                            \
  }


function* ValueOpComparison::specialize(
    static_context* sctx,
    const std::vector<xqtref_t>& argTypes) const
{
  const TypeManager* tm = sctx->get_typemanager();
  xqtref_t t0 = argTypes[0];
  xqtref_t t1 = argTypes[1];

  if (TypeOps::is_builtin_simple(tm, *t0) && TypeOps::is_builtin_simple(tm, *t1))
  {
    TypeConstants::atomic_type_code_t tc0 = TypeOps::get_atomic_type_code(*t0);
    TypeConstants::atomic_type_code_t tc1 = TypeOps::get_atomic_type_code(*t1);

    if (tc0 == tc1)
    {
      switch(tc0)
      {
      case TypeConstants::XS_DOUBLE:
        SPECIALIZE_VALUE_COMP_FUNCTION(theKind, DOUBLE);

      case TypeConstants::XS_DECIMAL:
        SPECIALIZE_VALUE_COMP_FUNCTION(theKind, DECIMAL);

      case TypeConstants::XS_FLOAT:
        SPECIALIZE_VALUE_COMP_FUNCTION(theKind, FLOAT);

      case TypeConstants::XS_INTEGER:
        SPECIALIZE_VALUE_COMP_FUNCTION(theKind, INTEGER);

      case TypeConstants::XS_STRING:
        SPECIALIZE_VALUE_COMP_FUNCTION(theKind, STRING);

      default:
        return NULL;
      }
    }
  }
  return NULL;
}


/*******************************************************************************

  Specific instances of ValueOpComparison. Specialization is based on both the
  comparison kind (eq, gt, etc) and the type of the operands. One class is
  created for each comparison kind, and another class foreach combination of
  comparison kind and data type. For example:

  class op_value_greater : SpecificValueComparison<CompareConsts::GREATER>

  class op_value_greater_double : TypedValueComparison<CompareConsts::GREATER,
                                                       TypeConstants::XS_DOUBLE>


********************************************************************************/

template<enum CompareConsts::CompareType CC>
class SpecificValueComparison : public ValueOpComparison
{
public:
  SpecificValueComparison(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    ValueOpComparison(sig, kind)
  {
  }

  virtual PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv ) const
  {
    return new CompareIterator(sctx, loc, argv[0], argv[1], CC);
  }
};


template<enum CompareConsts::CompareType CC, TypeConstants::atomic_type_code_t t>
class TypedValueComparison : public SpecificValueComparison<CC>
{
public:
  TypedValueComparison(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    SpecificValueComparison<CC>(sig, kind)
  {
  }

  bool specializable() const { return false; }

  PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv) const
  {
    return new TypedValueCompareIterator<t> (sctx, loc, argv, CC);
  }
};


#define DECL_SPECIFIC_TYPED_OP( cc, op, t, xqt )                        \
class op_value_##op##_##t :                                             \
public TypedValueComparison<CompareConsts::VALUE_##cc,                  \
                            TypeConstants::XS_##xqt>                    \
{                                                                       \
public:                                                                 \
  op_value_##op##_##t(const signature& sig)                             \
    :                                                                   \
    TypedValueComparison<CompareConsts::VALUE_##cc,                     \
                         TypeConstants::XS_##xqt>                       \
    (sig, FunctionConsts::OP_VALUE_##cc##_##xqt##_2)                    \
  {                                                                     \
  }                                                                     \
                                                                        \
  CompareConsts::CompareType comparisonKind() const                     \
  {                                                                     \
    return CompareConsts::VALUE_##cc;                                   \
  }                                                                     \
};


#define DECL_SPECIFIC_OPS(OP, op)                                       \
class op_value_##op :                                                   \
public SpecificValueComparison<CompareConsts::VALUE_##OP>               \
{                                                                       \
public:                                                                 \
  op_value_##op(const signature& sig)                                   \
    :                                                                   \
    SpecificValueComparison<CompareConsts::VALUE_##OP>                  \
    (sig, FunctionConsts::OP_VALUE_##OP##_2)                            \
  {                                                                     \
  }                                                                     \
                                                                        \
  CompareConsts::CompareType comparisonKind() const                     \
  {                                                                     \
    return CompareConsts::VALUE_##OP;                                   \
  }                                                                     \
};                                                                      \
                                                                        \
DECL_SPECIFIC_TYPED_OP (OP, op, double, DOUBLE);                        \
DECL_SPECIFIC_TYPED_OP (OP, op, decimal, DECIMAL);                      \
DECL_SPECIFIC_TYPED_OP (OP, op, float, FLOAT);                          \
DECL_SPECIFIC_TYPED_OP (OP, op, integer, INTEGER);                      \
DECL_SPECIFIC_TYPED_OP (OP, op, string, STRING)


DECL_SPECIFIC_OPS (EQUAL, equal);
DECL_SPECIFIC_OPS (NOT_EQUAL, not_equal);
DECL_SPECIFIC_OPS (GREATER, greater);
DECL_SPECIFIC_OPS (LESS, less);
DECL_SPECIFIC_OPS (GREATER_EQUAL, greater_equal);
DECL_SPECIFIC_OPS (LESS_EQUAL, less_equal);

#undef DECL_ALL_SPECIFIC_OPS
#undef DECL_SPECIFIC_OP



/*******************************************************************************
  class GeneralOpComparison
********************************************************************************/
class GeneralOpComparison : public GenericOpComparison
{
public:
  GeneralOpComparison(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    GenericOpComparison(sig, kind)
  {
  }

  bool isGeneralComparisonFunction() const { return true; }
};



/*******************************************************************************
  Specific instances of GeneralOpComparison.
********************************************************************************/
class op_equal : public GeneralOpComparison
{
public:
  op_equal(const signature& sig)
    :
    GeneralOpComparison(sig, FunctionConsts::OP_EQUAL_2)
  {
  }

  PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv) const
  {
    return new CompareIterator(sctx,
                               loc,
                               argv[0],
                               argv[1],
                               CompareConsts::GENERAL_EQUAL);
  }

  function* toValueComp(static_context* sctx) const
  {
    return GET_BUILTIN_FUNCTION(OP_VALUE_EQUAL_2);
  }

  CompareConsts::CompareType comparisonKind() const
  {
    return CompareConsts::GENERAL_EQUAL;
  }
};


class op_not_equal : public GeneralOpComparison
{
public:
  op_not_equal(const signature& sig)
    :
    GeneralOpComparison(sig, FunctionConsts::OP_NOT_EQUAL_2)
  {
  }

  PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv) const
  {
    return new CompareIterator(sctx,
                               loc,
                               argv[0],
                               argv[1],
                               CompareConsts::GENERAL_NOT_EQUAL);
  }

  CompareConsts::CompareType comparisonKind() const
  {
    return CompareConsts::GENERAL_NOT_EQUAL;
  }

  function* toValueComp(static_context* sctx) const
  {
    return GET_BUILTIN_FUNCTION(OP_VALUE_NOT_EQUAL_2);
  }
};


class op_less_equal : public GeneralOpComparison
{
public:
  op_less_equal(const signature& sig)
    :
    GeneralOpComparison(sig, FunctionConsts::OP_LESS_EQUAL_2)
  {
  }

  PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv) const
  {
    return new CompareIterator(sctx,
                               loc,
                               argv[0],
                               argv[1],
                               CompareConsts::GENERAL_LESS_EQUAL);
  }

  CompareConsts::CompareType comparisonKind() const
  {
    return CompareConsts::GENERAL_LESS_EQUAL;
  }

  function* toValueComp(static_context* sctx) const
  {
    return GET_BUILTIN_FUNCTION(OP_VALUE_LESS_EQUAL_2);
  }
};


class op_less : public GeneralOpComparison
{
public:
  op_less(const signature& sig)
    :
    GeneralOpComparison(sig, FunctionConsts::OP_LESS_2)
  {
  }

  PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv) const
  {
    return new CompareIterator(sctx,
                               loc,
                               argv[0],
                               argv[1],
                               CompareConsts::GENERAL_LESS);
  }

  CompareConsts::CompareType comparisonKind() const
  {
    return CompareConsts::GENERAL_LESS;
  }

  function* toValueComp(static_context* sctx) const
  {
    return GET_BUILTIN_FUNCTION(OP_VALUE_LESS_2);
  }
};


class op_greater_equal : public GeneralOpComparison
{
public:
  op_greater_equal(const signature& sig)
    :
    GeneralOpComparison(sig, FunctionConsts::OP_GREATER_EQUAL_2)
  {
  }

  PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv) const
  {
    return new CompareIterator(sctx,
                               loc,
                               argv[0],
                               argv[1],
                               CompareConsts::GENERAL_GREATER_EQUAL);
  }

  CompareConsts::CompareType comparisonKind() const
  {
    return CompareConsts::GENERAL_GREATER_EQUAL;
  }

  function* toValueComp(static_context* sctx) const
  {
    return GET_BUILTIN_FUNCTION(OP_VALUE_GREATER_EQUAL_2);
  }
};


class op_greater : public GeneralOpComparison
{
public:
  op_greater(const signature& sig)
    :
    GeneralOpComparison(sig, FunctionConsts::OP_GREATER_2)
  {
  }

  PlanIter_t createIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv) const
  {
    return new CompareIterator(sctx,
                               loc,
                               argv[0],
                               argv[1],
                               CompareConsts::GENERAL_GREATER);
  }

  CompareConsts::CompareType comparisonKind() const
  {
    return CompareConsts::GENERAL_GREATER;
  }

  function* toValueComp(static_context* sctx) const
  {
    return GET_BUILTIN_FUNCTION(OP_VALUE_GREATER_2);
  }
};


/*******************************************************************************
  Atomic Values Equivalent comparing function

  http://www.w3.org/TR/xquery-11/#dt-equivalence-two-atomic-values
********************************************************************************/
class op_atomic_values_equivalent : public function
{
public:
  op_atomic_values_equivalent(const signature& sig) 
    :
    function(sig, FunctionConsts::OP_ATOMIC_VALUES_EQUIVALENT_2)
  {
  }

  PlanIter_t codegen(
                    CompilerCB* /*cb*/,
                    static_context* sctx,
                    const QueryLoc& loc,
                    std::vector<PlanIter_t>& argv,
                    AnnotationHolder& ann) const
  {
    return new AtomicValuesEquivalenceIterator(sctx, loc, argv[0], argv[1]);
  }
};


/*******************************************************************************
  Logic Operators (and/or)
********************************************************************************/

class op_and : public function
{
public:
  op_and (const signature& sig)
    :
    function(sig, FunctionConsts::OP_AND_N)
  {
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    assert(argv.size() > 0);
    return new AndIterator(sctx, loc, argv);
  }
};


class op_or : public function
{
public:
  op_or (const signature& sig)
    :
    function(sig, FunctionConsts::OP_OR_N)
  {
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    assert(argv.size() > 0);
    return new OrIterator(sctx, loc, argv);
  }
};


/*******************************************************************************
  9 Functions and Operators on Boolean Values

  9.1.1 fn:true
  9.1.2 fn:false
  9.3.1 fn:not
********************************************************************************/

class fn_true : public function
{
public:
  fn_true(const signature& sig) : function(sig, FunctionConsts::FN_TRUE_0) {}

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    store::Item_t res;
    GENV_ITEMFACTORY->createBoolean(res, true);
    return new SingletonIterator(sctx, loc, res);
  }
};


/*******************************************************************************
  fn:false
********************************************************************************/
class fn_false : public function
{
public:
  fn_false(const signature& sig) : function(sig, FunctionConsts::FN_FALSE_0) {}

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    store::Item_t res;
    GENV_ITEMFACTORY->createBoolean(res, false);
    return new SingletonIterator(sctx, loc, res);
  }
};


/*******************************************************************************
  fn:not
********************************************************************************/
class fn_not : public function
{
public:
  fn_not(const signature& sig) : function(sig, FunctionConsts::FN_NOT_1) {}

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new FnBooleanIterator(sctx, loc, argv[0], true);
  }

};


/*******************************************************************************
  fn:boolean
********************************************************************************/
class fn_boolean : public function
{
public:
  fn_boolean(const signature& sig) : function(sig, FunctionConsts::FN_BOOLEAN_1)
  {
  }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize input) const
  {
    return ANNOTATION_TRUE;
  }

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize input) const 
  {
    return ANNOTATION_TRUE;
  }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new FnBooleanIterator(sctx, loc, argv[0]);
  }
};


/*******************************************************************************

********************************************************************************/
void populateContext_Comparison(static_context* sctx)
{
  const char* zorba_ns = static_context::ZORBA_OP_NS.c_str();

  // General Comparison;
  DECL(sctx, op_equal,
       (createQName(zorba_ns, "", "equal"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
  
  DECL(sctx, op_not_equal,
       (createQName(zorba_ns, "", "not-equal"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, op_greater,
       (createQName(zorba_ns, "", "greater"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
  
  DECL(sctx, op_greater_equal,
       (createQName(zorba_ns, "", "greater-equal"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, op_less,
       (createQName(zorba_ns, "", "less"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, op_less_equal,
       (createQName(zorba_ns, "", "less-equal"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  // Value Comparison

#define DECL_TYPED_VAL( sctx, op, name, type, xqt )                     \
  DECL(sctx, op_value_##op##_##type,                                    \
       (createQName (zorba_ns, "", "value-" name "-" #type),            \
        GENV_TYPESYSTEM.xqt##_TYPE_QUESTION,                            \
        GENV_TYPESYSTEM.xqt##_TYPE_QUESTION,                            \
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION))

#define DECL_ALL_VAL( sctx, op, name )                                  \
  DECL(sctx, op_value_##op,                                             \
       (createQName (zorba_ns, "", "value-" name),                      \
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,                       \
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,                       \
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));                        \
                                                                        \
  DECL_TYPED_VAL( sctx, op, name, double, DOUBLE );                     \
  DECL_TYPED_VAL( sctx, op, name, float, FLOAT );                       \
  DECL_TYPED_VAL( sctx, op, name, decimal, DECIMAL );                   \
  DECL_TYPED_VAL( sctx, op, name, integer, INTEGER );                   \
  DECL_TYPED_VAL( sctx, op, name, string, STRING )


  DECL_ALL_VAL(sctx, equal, "equal");
  DECL_ALL_VAL(sctx, not_equal, "not-equal");
  DECL_ALL_VAL(sctx, less, "less");
  DECL_ALL_VAL(sctx, greater, "greater");
  DECL_ALL_VAL(sctx, less_equal, "less-equal");
  DECL_ALL_VAL(sctx, greater_equal, "greater-equal");

#undef DECL_ALL_VAL
#undef DECL_TYPED_VAL

// Atomic Values Equivalent comparing function
// http://www.w3.org/TR/xquery-11/#dt-equivalence-two-atomic-values
DECL(sctx, op_atomic_values_equivalent,
     (createQName(zorba_ns, "", "atomic-values-equivalent"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Atomic Values Equivalent

}


void populate_context_booleans_impl(static_context* sctx)
{
  const char* xquery_op_ns = static_context::XQUERY_OP_NS.c_str();
  const char* fn_ns = static_context::W3C_FN_NS.c_str();

  // Boolean
  DECL(sctx, fn_true,
       (createQName(fn_ns, "", "true"),
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, fn_false,
       (createQName(fn_ns, "", "false"),
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, fn_boolean,
       (createQName(fn_ns, "", "boolean"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
  
  DECL(sctx, fn_not,
       (createQName(fn_ns, "", "not"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  // Logic
  DECL(sctx, op_and,
       (createQName(xquery_op_ns, "", "and"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        true, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
  
  DECL(sctx, op_or,
       (createQName(xquery_op_ns, "", "or"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        true, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

}


}
/* vim:set et sw=2 ts=2: */
