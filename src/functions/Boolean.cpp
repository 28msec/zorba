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
#include "runtime/booleans/compare_types.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/item_iterator.h"
#include "store/api/item_factory.h"
#include "types/typeops.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

namespace zorba
{

  /* begin class GenericOpComparison */
  PlanIter_t
  GenericOpComparison::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return this->createIterator(loc, argv);
  }
  

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
    if (tc0 == TypeConstants::XS_UNTYPED_ATOMIC || tc1 == TypeConstants::XS_UNTYPED_ATOMIC)
      return NULL;

    return toValueComp (sctx);
  }

  /* end class GenericOpComparison */

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
  

  /* begin class op_is_same_node */
  PlanIter_t
  op_is_same_node::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return new OpIsSameNodeIterator ( loc, argv );
  }


  /* end class op_is_same_node */

  /* begin class op_node_before */
  PlanIter_t
  op_node_before::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return new OpNodeBeforeIterator ( loc, argv );
  }


  /* end class op_node_before */

  /* begin class op_node_after */
  PlanIter_t
  op_node_after::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return new OpNodeAfterIterator ( loc, argv );
  }


  /* end class op_node_after */
  
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
}
