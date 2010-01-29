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
#ifndef ZORBA_FUNCTIONS_UDF
#define ZORBA_FUNCTIONS_UDF

#include "functions/function.h"

#include "compiler/expression/expr_base.h"


namespace zorba 
{


/*******************************************************************************
  A udf with params $x1, $x2, ..., $xn and a body_expr is translated into a
  flwor expr:

  let $x1 := $x1_, $x2 := $x2_, ..., $xn := $xn_
  return body_expr

  The internally generated vars $x1_, ..., $xn_ are not registered in any sctx,
  but they are registered in the udf obj instead (m_args data member).

  A call to a udf is translated the same way as a call to a built-in function,
  i.e., an fo_expr is created that points to the udf obj and also has a vector
  of pointers to the arg exprs appearing in the function call.

  m_loc         : The query location where this udf is declared at.
  m_expr_body   : The expr tree representing what this function is doing. It is
                  the result of translating the udf declaration (so for a udf
                  with one or more params, it is the flwor expr described above).
                  Note: translation of udf declarations includes normalization
                  and optimization of the expr tree.
  m_args        : The internally generated arg vars (the $xi_ vars described above)

  theUpdateType : The update type of this udf.
  sequential    :
  deterministic :
  leaf          :

  m_plan        :
  m_param_itrers:
  m_state_size  :
********************************************************************************/
class user_function : public function 
{
private:
  QueryLoc                m_loc;

  expr_t                  m_expr_body;
  std::vector<var_expr_t> m_args;

  expr_script_kind_t      theUpdateType;
  bool                    deterministic;
  bool                    leaf;  // does not call other UDF's
  
  mutable PlanIter_t                m_plan;
  mutable std::vector<LetVarIter_t> m_param_iters;
  mutable int32_t                   m_state_size;

public:
  SERIALIZABLE_CLASS(user_function)

  user_function(::zorba::serialization::Archiver& ar);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  user_function(
        const QueryLoc& loc,
        const signature& sig,
        expr_t expr_body, 
        ParseConstants::function_type_t,
        bool deterministic);

  virtual ~user_function();

  const QueryLoc& get_location() const;

  virtual expr_script_kind_t getUpdateType() const { return theUpdateType; }

  virtual bool is_builtin_fn_named(const char* local, int local_len, int arg_count) const {return false;}

  bool isDeterministic() const { return deterministic; }

  void setLeaf(bool leaf_) { leaf = leaf_; }

  bool isLeaf() const { return leaf; }

  void set_body(expr_t body);

  expr_t get_body() const;

  void set_args(std::vector<var_expr_t>& args);

  const std::vector<var_expr_t>& get_args() const;

  bool accessesDynCtx() const;

  virtual PlanIter_t get_plan(CompilerCB *) const;
  
  virtual std::vector<LetVarIter_t>& get_param_iters() const;

  PlanIter_t codegen(
        CompilerCB* cb,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const; 
};


/*******************************************************************************

********************************************************************************/
class external_function : public function 
{
public:
  SERIALIZABLE_ABSTRACT_CLASS(external_function)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(external_function, function)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    zorba::serialization::serialize_baseclass(ar, (function*)this);
  }
public:
  external_function(const signature& sig) 
    :
    function(sig, FunctionConsts::FN_UNKNOWN)
  {
  }

  virtual ~external_function() { }
};


} /* namespace zorba */
#endif
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */

