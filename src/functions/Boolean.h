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
#ifndef ZORBA_BOOLEAN_H
#define ZORBA_BOOLEAN_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"
#include "runtime/booleans/compare_types.h"
#include "runtime/booleans/BooleanImpl.h"

namespace zorba
{
  class GenericOpComparison : public function {
  public:
    GenericOpComparison (const signature &sig) : function (sig) {}
    
    virtual PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    void compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const;
    virtual function *toValueComp (static_context *) const { return NULL; }
    bool isComparisonFunction () const { return true; }
    const function *specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const;

  protected:
    virtual PlanIter_t createIterator( const QueryLoc& loc, std::vector<PlanIter_t>& ) const = 0;
  };

  class ValueOpComparison : public GenericOpComparison {
  public:
    ValueOpComparison (const signature &sig) : GenericOpComparison (sig) {}
    xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
  };
  
  template<enum CompareConsts::CompareType CC> class SpecificValueComparison : public ValueOpComparison {
  public:
    SpecificValueComparison (const signature &sig) : ValueOpComparison (sig) {}
    virtual PlanIter_t createIterator( const QueryLoc& loc, std::vector<PlanIter_t>& argv ) const {
      return new CompareIterator (loc, argv[0], argv[1], CC);
    }
  };

  template<enum CompareConsts::CompareType CC> class SpecificGenericComparison : public GenericOpComparison {
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

  /*----------------------------------- generic comparison --------------------------------*/

  typedef SpecificGenericComparison<CompareConsts::GENERAL_EQUAL> op_equal;
  typedef SpecificGenericComparison<CompareConsts::GENERAL_NOT_EQUAL> op_not_equal;
  typedef SpecificGenericComparison<CompareConsts::GENERAL_GREATER> op_greater;
  typedef SpecificGenericComparison<CompareConsts::GENERAL_GREATER_EQUAL> op_greater_equal;
  typedef SpecificGenericComparison<CompareConsts::GENERAL_LESS> op_less;
  typedef SpecificGenericComparison<CompareConsts::GENERAL_LESS_EQUAL> op_less_equal;
  
  /*----------------------------------- value comparison --------------------------------*/
  
  typedef SpecificValueComparison<CompareConsts::VALUE_EQUAL> op_value_equal;
  typedef SpecificValueComparison<CompareConsts::VALUE_NOT_EQUAL> op_value_not_equal;
  typedef SpecificValueComparison<CompareConsts::VALUE_GREATER> op_value_greater;
  typedef SpecificValueComparison<CompareConsts::VALUE_GREATER_EQUAL> op_value_greater_equal;
  typedef SpecificValueComparison<CompareConsts::VALUE_LESS> op_value_less;
  typedef SpecificValueComparison<CompareConsts::VALUE_LESS_EQUAL> op_value_less_equal;  

  /*-------------------------- Node Comparison -------------------------------------------*/

  class op_is_same_node : public function {
  public:
    op_is_same_node( const signature &sig) : function(sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  class op_node_before : public function {
  public:
    op_node_before( const signature &sig) : function(sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  class op_node_after : public function {
  public:
    op_node_after( const signature &sig) : function(sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  /*-------------------------- Logical Expressions ---------------------------------------*/
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
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
