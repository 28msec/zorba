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
#include "system/globalenv.h"

#include "functions/Boolean.h"
#include "functions/function_impl.h"

#include "runtime/booleans/compare_types.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/item_iterator.h"

#include "store/api/item_factory.h"

#include "types/typeops.h"

#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

namespace zorba
{

/*******************************************************************************
  class GenericOpComparison
********************************************************************************/

void GenericOpComparison::compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const
{
  switch (k) {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    for (std::vector<AnnotationHolder *>::iterator i = kids.begin (); i < kids.end (); i++)
      TSVAnnotationValue::update_annotation ((*i), k, TSVAnnotationValue::TRUE_VAL);
    break;
  default: break;
  }
}
  
  
const function *GenericOpComparison::specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const {
  xqtref_t t0 = argTypes[0];
  xqtref_t t1 = argTypes[1];

  if (! (TypeOps::is_atomic (*t0) && TypeOps::is_atomic (*t1)))
    return NULL;
    
  TypeConstants::atomic_type_code_t tc0 = TypeOps::get_atomic_type_code(*t0);
  TypeConstants::atomic_type_code_t tc1 = TypeOps::get_atomic_type_code(*t1);
  if (tc0 == TypeConstants::XS_UNTYPED_ATOMIC || tc1 == TypeConstants::XS_UNTYPED_ATOMIC
      || tc0 == TypeConstants::XS_ANY_ATOMIC || tc1 == TypeConstants::XS_ANY_ATOMIC)
    return NULL;
  
  return toValueComp (sctx);
}
  

/*******************************************************************************

  Specific instances of ValueOpComparison. Specialization is based on both the
  comparison kind (eq, gt, etc) and the type of the operands. One class is
  created for each comparison kind, and another class foreach combination of
  comparison kind and data type. For example:

  class op_value_greater : SpecificValueComparison<CompareConsts::GREATER>

  typedef TypedValueComparison<CompareConsts::GREATER, TypeConstants::XS_DOUBLE>
          op_value_greater_double

********************************************************************************/

template<enum CompareConsts::CompareType CC>
class SpecificValueComparison : public ValueOpComparison {
public:
  SpecificValueComparison (const signature &sig) : ValueOpComparison (sig) {}

  virtual PlanIter_t createIterator( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const {
    return new CompareIterator (loc, argv[0], argv[1], CC);
  }
};


template<enum CompareConsts::CompareType CC, TypeConstants::atomic_type_code_t t>
class TypedValueComparison : public SpecificValueComparison<CC> {
public:
  TypedValueComparison (const signature &sig) : SpecificValueComparison<CC> (sig) {}

  virtual bool specializable() const { return false; }
};


#define DECL_SPECIFIC_OP( cc, op, t, xqt )                              \
  typedef TypedValueComparison <CompareConsts::VALUE_##cc, TypeConstants::XS_##xqt> \
  op_value_##op##_##t

#define DECL_ALL_SPECIFIC_OPS( cc, op, name )                           \
  class op_value_##op                                                   \
  : public SpecificValueComparison<CompareConsts::VALUE_##cc>           \
  {                                                                     \
  public:                                                               \
    op_value_##op (const signature &sig)                                \
    : SpecificValueComparison<CompareConsts::VALUE_##cc> (sig)          \
    {}                                                                  \
    const char *comparison_name () const { return name; }               \
  };                                                                    \
  DECL_SPECIFIC_OP (cc, op, double, DOUBLE);                            \
  DECL_SPECIFIC_OP (cc, op, decimal, DECIMAL);                          \
  DECL_SPECIFIC_OP (cc, op, float, FLOAT);                              \
  DECL_SPECIFIC_OP (cc, op, integer, INTEGER);                          \
  DECL_SPECIFIC_OP (cc, op, string, STRING)
  
DECL_ALL_SPECIFIC_OPS (EQUAL, equal, "equal");
DECL_ALL_SPECIFIC_OPS (NOT_EQUAL, not_equal, "not-equal");
DECL_ALL_SPECIFIC_OPS (GREATER, greater, "greater");
DECL_ALL_SPECIFIC_OPS (LESS, less, "less");
DECL_ALL_SPECIFIC_OPS (GREATER_EQUAL, greater_equal, "greater-equal");
DECL_ALL_SPECIFIC_OPS (LESS_EQUAL, less_equal, "less-equal");

#undef DECL_ALL_SPECIFIC_OPS
#undef DECL_SPECIFIC_OP


const function *ValueOpComparison::specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const {
  xqtref_t t0 = argTypes[0];
  xqtref_t t1 = argTypes[1];
  if (TypeOps::is_simple(*t0) && TypeOps::is_simple (*t1)) {
    TypeConstants::atomic_type_code_t tc0 = TypeOps::get_atomic_type_code(*t0);
    TypeConstants::atomic_type_code_t tc1 = TypeOps::get_atomic_type_code(*t1);
    if (tc0 == tc1) {
      std::ostringstream oss;
      oss << ":value-" << comparison_name () << "-";
      switch(tc0) {
      case TypeConstants::XS_DOUBLE:
        oss << "double";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      case TypeConstants::XS_DECIMAL:
        oss << "decimal";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      case TypeConstants::XS_FLOAT:
        oss << "float";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      case TypeConstants::XS_INTEGER:
        oss << "integer";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      case TypeConstants::XS_STRING:
        oss << "string";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      default:
        return NULL;
      }
    }
  }
  return NULL;
}
  
  
xqtref_t ValueOpComparison::return_type (const std::vector<xqtref_t> &arg_types) const {
  xqtref_t empty = GENV_TYPESYSTEM.EMPTY_TYPE;
  TypeConstants::quantifier_t quant = TypeConstants::QUANT_ONE;
  for (int i = 0; i < 2; i++) {
    if (TypeOps::is_equal (*empty, *arg_types [i]))
      return empty;
    TypeConstants::quantifier_t aq = TypeOps::quantifier(*arg_types[i]);
    if (aq == TypeConstants::QUANT_QUESTION || aq == TypeConstants::QUANT_STAR) {
      quant = TypeConstants::QUANT_QUESTION;
    }
  }
  return quant == TypeConstants::QUANT_QUESTION ? GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION : GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
}
  


/*******************************************************************************
  Specific instances of GenericOpComparison.
********************************************************************************/

template<enum CompareConsts::CompareType CC>
class SpecificGenericComparison : public GenericOpComparison {
public:
  SpecificGenericComparison (const signature &sig) : GenericOpComparison (sig) {}

  virtual PlanIter_t createIterator( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const {
    return new CompareIterator (loc, argv[0], argv[1], CC);
  }

  function *toValueComp (static_context *sctx) const {
    std::string name = get_fname ()->getLocalName ()->str ();
    return sctx->lookup_builtin_fn (name.substr (0, 1) + "value-" + name.substr (1), 2);
  }
};


typedef SpecificGenericComparison<CompareConsts::GENERAL_EQUAL> op_equal;
typedef SpecificGenericComparison<CompareConsts::GENERAL_NOT_EQUAL> op_not_equal;
typedef SpecificGenericComparison<CompareConsts::GENERAL_GREATER> op_greater;
typedef SpecificGenericComparison<CompareConsts::GENERAL_GREATER_EQUAL> op_greater_equal;
typedef SpecificGenericComparison<CompareConsts::GENERAL_LESS> op_less;
typedef SpecificGenericComparison<CompareConsts::GENERAL_LESS_EQUAL> op_less_equal;
 

  /*-------------------------- Node Comparison ---------------------------------------*/

  class op_is_same_node : public function {
  public:
    op_is_same_node( const signature &sig) : function(sig) {}
    DEFAULT_CODEGEN (OpIsSameNodeIterator)
  };
  
  class op_node_before : public function {
  public:
    op_node_before( const signature &sig) : function(sig) {}
    DEFAULT_CODEGEN (OpNodeBeforeIterator)
  };
  
  class op_node_after : public function {
  public:
    op_node_after( const signature &sig) : function(sig) {}
    DEFAULT_CODEGEN (OpNodeAfterIterator)
  };
  
  /*-------------------------- Logical Expressions -----------------------------------*/
  class op_and : public function {
  public:
    op_and (const signature &sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  class op_or : public function {
  public:
    op_or (const signature &sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  // 9 Functions and Operators on Boolean Values
  // 9.1.1 fn:true
  class fn_true : public function {
  public:
    fn_true (const signature &sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  }; /* class fn_true */
  
  // 9.1.2 fn:false
  class fn_false : public function {
  public:
    fn_false (const signature &sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  }; /* class fn_false */
  
  // 9.3.1 fn:not
  class fn_not : public function {
  public:
    fn_not (const signature &sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  // 15 Functions and Operators on Sequences
  // 15.1.1 fn:boolean
  class fn_boolean : public function {
    public:
    fn_boolean (const signature &sig) : function (sig) {}
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  }; /* class fn_false */




  
  /* start class op_and */
  PlanIter_t
  op_and::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return new LogicIterator ( loc, argv[0], argv[1], LogicIterator::AND );
  }


  /* end class op_and */
  
  /*start class op_or */
  PlanIter_t
  op_or::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return new LogicIterator ( loc, argv[0], argv[1], LogicIterator::OR );
  }


  /* end class op_or */

  /* start class fn_true */
  PlanIter_t
  fn_true::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    store::Item_t res;
    GENV_ITEMFACTORY->createBoolean(res, true);
    return new SingletonIterator ( loc, res );
  }


  /* end class fn_true */
  
  /* start class fn_false */
  PlanIter_t
  fn_false::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    store::Item_t res;
    GENV_ITEMFACTORY->createBoolean(res, false);
    return new SingletonIterator ( loc, res);
  }


  /* end class fn_false */
  
  /* begin class fn_not */
  PlanIter_t
  fn_not::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return new FnBooleanIterator(loc, argv[0], true );
  }


  /* end class fn_not */

  /* start class fn_boolean */
  PlanIter_t
  fn_boolean::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return new FnBooleanIterator ( loc, argv[0] );
  }

  /* end class fn_boolean */

void populateContext_Comparison(static_context *sctx) {
// Generic Comparison;
DECL(sctx, op_equal,
     (createQName(XQUERY_OP_NS,"fn", ":equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_not_equal,
     (createQName(XQUERY_OP_NS,"fn", ":not-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_greater,
     (createQName(XQUERY_OP_NS,"fn", ":greater"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_greater_equal,
     (createQName(XQUERY_OP_NS,"fn", ":greater-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_less,
     (createQName(XQUERY_OP_NS,"fn", ":less"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_less_equal,
     (createQName(XQUERY_OP_NS,"fn", ":less-equal"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Generic Comparison

// Value Comparison
 
#define DECL_TYPED_VAL( sctx, op, name, type, xqt )                     \
  DECL(sctx, op_value_##op##_##type,                                    \
       (createQName (XQUERY_OP_NS,"fn", ":value-" name "-" #type),     \
        GENV_TYPESYSTEM.xqt##_TYPE_QUESTION,                            \
        GENV_TYPESYSTEM.xqt##_TYPE_QUESTION,                            \
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION))
 
#define DECL_ALL_VAL( sctx, op, name )                                  \
  DECL(sctx, op_value_##op,                                             \
       (createQName (XQUERY_OP_NS, "fn", ":value-" name),              \
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,                       \
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,                       \
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));                        \
  DECL_TYPED_VAL( sctx, op, name, double, DOUBLE );                     \
  DECL_TYPED_VAL( sctx, op, name, float, FLOAT );                       \
  DECL_TYPED_VAL( sctx, op, name, decimal, DECIMAL );                   \
  DECL_TYPED_VAL( sctx, op, name, integer, INTEGER );                   \
  DECL_TYPED_VAL( sctx, op, name, string, STRING )


 DECL_ALL_VAL (sctx, equal, "equal");
 DECL_ALL_VAL (sctx, not_equal, "not-equal");
 DECL_ALL_VAL (sctx, less, "less");
 DECL_ALL_VAL (sctx, greater, "greater");
 DECL_ALL_VAL (sctx, less_equal, "less-equal");
 DECL_ALL_VAL (sctx, greater_equal, "greater-equal");

#undef DECL_ALL_VAL
#undef DECL_TYPED_VAL

// end Value Comparison

// Node Comparison
DECL(sctx, op_is_same_node,
     (createQName(XQUERY_FN_NS,"fn", ":is-same-node"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_node_before,
     (createQName(XQUERY_FN_NS,"fn", ":node-before"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

DECL(sctx, op_node_after,
     (createQName(XQUERY_FN_NS,"fn", ":node-after"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

// end Node Comparson

}

void populateContext_Boolean(static_context *sctx) {
// start Boolean
DECL(sctx, fn_true,
     (createQName(XQUERY_FN_NS,"fn","true"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_false,
     (createQName(XQUERY_FN_NS,"fn","false"),
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_boolean,
     (createQName(XQUERY_FN_NS,"fn","boolean"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, fn_not,
     (createQName(XQUERY_FN_NS,"fn","not"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Boolean

// start Logic
DECL(sctx, op_and,
     (createQName(XQUERY_OP_NS,"fn", ":and"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

DECL(sctx, op_or,
     (createQName(XQUERY_OP_NS,"fn", ":or"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      true, GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
// end Logic

}


}
