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
  but they are registered in the udf obj instead (theArgVars data member).

  A call to a udf is translated the same way as a call to a built-in function,
  i.e., an fo_expr is created that points to the udf obj and also has a vector
  of pointers to the arg exprs appearing in the function call.

  theLoc        : The query location where this udf is declared at.
  theBodyExpr   : The expr tree representing what this function is doing. It is
                  the result of translating the udf declaration (so for a udf
                  with one or more params, it is the flwor expr described above).
                  Note: translation of udf declarations includes normalization
                  and optimization of the expr tree.
  theArgVars    : The internally generated arg vars (the $xi_ vars described above)

  theUpdateType : The update type of this udf.
  deterministic :
  leaf          : True if this udf does not invoke any other udfs

  thePlan       :
  theArgVarRefs : Each arg var is referenced at most once in the function body.
                  So, for each arg var, this vector stores the LetVarIterator
                  that represents the reference to that var (or NULL if the arg 
                  var is not referenced at all).
********************************************************************************/
class user_function : public function 
{
private:
  QueryLoc                  theLoc;

  expr_t                    theBodyExpr;
  std::vector<var_expr_t>   theArgVars;

  expr_script_kind_t        theUpdateType;
  bool                      theIsDeterministic;
  bool                      theIsLeaf;
  
  PlanIter_t                thePlan;
  std::vector<LetVarIter_t> theArgVarRefs;

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

  expr_script_kind_t getUpdateType() const { return theUpdateType; }

  //xqtref_t getUDFReturnType(static_context* sctx) const;

  bool isDeterministic() const { return theIsDeterministic; }

  void setLeaf(bool v) { theIsLeaf = v; }

  bool isLeaf() const { return theIsLeaf; }

  void setBody(expr_t body);

  expr_t getBody() const;

  void setArgVars(std::vector<var_expr_t>& args);

  const std::vector<var_expr_t>& getArgVars() const;

  bool accessesDynCtx() const;

  PlanIter_t getPlan(CompilerCB *);
  
  const std::vector<LetVarIter_t>& getArgVarRefIters() const;

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

