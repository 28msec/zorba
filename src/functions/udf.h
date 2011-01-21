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

  theLoc           : The query location where this udf is declared at.
  theBodyExpr      : The expr tree representing what this function is doing.
                     It is the result of translating the udf declaration (so
                     for a udf with one or more params, it is the flwor expr
                     described above). Note: translation of udf declarations
                     includes normalization and optimization of the expr tree.
  theArgVars       : The internally generated arg vars (the $xi_ vars described
                     above)

  theScriptingKind : The update type of this udf.

  theIsLeaf        : True if this udf does not invoke any other udfs

  thePlan          :
  theArgVarRefs    : For each arg var, this vector stores the LetVarIterators 
                     that represent the references to that var within the udf
                     body. If there are more than one references of an arg var,
                     these references are "mutually exclusive", ie, at most one
                     of the references will actually be reached during each 
                     particular execution of the body.
********************************************************************************/
class user_function : public function 
{
private:
  QueryLoc                    theLoc;

  expr_t                      theBodyExpr;
  std::vector<var_expr_t>     theArgVars;

  expr_script_kind_t          theScriptingKind;

  bool                        theIsLeaf;
  std::vector<user_function*> theMutuallyRecursiveUDFs;

  bool                                     theIsOptimized;

  PlanIter_t                               thePlan;
  std::vector<std::vector<LetVarIter_t> >  theArgVarRefs;

public:
  SERIALIZABLE_CLASS(user_function)
  user_function(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  user_function(
        const QueryLoc& loc,
        const signature& sig,
        expr_t expr_body, 
        expr_script_kind_t kind);

  virtual ~user_function();

  expr_script_kind_t getUpdateType() const { return theScriptingKind; }

  //xqtref_t getUDFReturnType(static_context* sctx) const;

  const QueryLoc& getLoc() const { return theLoc; }

  void setLeaf(bool v) { theIsLeaf = v; }

  bool isLeaf() const { return theIsLeaf; }

  void setBody(const expr_t& body);

  expr_t getBody() const;

  void setArgVars(std::vector<var_expr_t>& args);

  const std::vector<var_expr_t>& getArgVars() const;

  void setOptimized(bool v) { theIsOptimized = v; }

  bool isOptimized() const { return theIsOptimized; }

  void addMutuallyRecursiveUDFs(const std::vector<user_function*>& udfs);

  bool isMutuallyRecursiveWith(const user_function* udf);

  bool isRecursive() const;

  bool accessesDynCtx() const;

  BoolAnnotationValue ignoresSortedNodes(expr* fo, ulong input) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, ulong input) const;

  PlanIter_t getPlan(CompilerCB *);
  
  const std::vector<std::vector<LetVarIter_t> >& getArgVarRefIters() const;

  PlanIter_t codegen(
        CompilerCB* cb,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const;
};


} /* namespace zorba */
#endif
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */

