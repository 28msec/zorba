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
#ifndef ZORBA_FN_CONTEXT_H
#define ZORBA_FN_CONTEXT_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"


namespace zorba {

  
/*******************************************************************************
  ctxvar-declare(varName)

  This internal function is used to declare block-local and prolog variables
  (including the context item, if it is declared in the prolog), except for
  external vars without an initalizing expr. During runtime, the function
  registers the varName into the dynamic context.
********************************************************************************/
class ctx_var_declare : public function
{
public:
  ctx_var_declare(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        short sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const;

  bool requires_dyn_ctx() const { return true; }
};


/*******************************************************************************
  ctxvar-assign(varName, initExpr)

  This internal function is used to initialize prolog variables that do have an
  initializing expr, or to assign a value to a prolog or block-local var. For
  the context item var, the function creates, during runtime, a binding in the
  dynamic ctx between the varName (".") and the actual context item. Otherwise,
  the function creates a binding in the dynamic ctx between the varName and an
  iterator plan that computes the initExpr. 
********************************************************************************/
class ctx_var_assign : public function
{
public:
  ctx_var_assign(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        short sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const;

  bool requires_dyn_ctx() const { return true; }
};
  

/*******************************************************************************
  ctxvar-exists(varName)

  This internal function is used to check if a prolog of block-local variable
  has been declared. During runtime, it checks if an entry exists for variable
  in the dynamic ctx.
********************************************************************************/
class ctx_var_exists : public function
{
public:
  ctx_var_exists(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        short sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder &ann) const;

  bool requires_dyn_ctx() const { return true; }
};


/*******************************************************************************
  ctxvariable(varName)

  This internal function is used to represent references to prolog or block-local
  variables. During runtime, it retrieves from the dymanic context the iterator
  (or single item) that is associated with varName and returns, one-at-a-time,
  the items produced by that iterator.
********************************************************************************/ 
class ctx_variable : public function
{
public:
  ctx_variable(const signature& sig) : function (sig) {}

  PlanIter_t codegen(
        short sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const;

  bool requires_dyn_ctx() const { return true; }
};
  

}


#endif  /* ZORBA_FN_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
