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

  
  
class ctx_variable : public function
{
public:
  ctx_variable(const signature& sig) : function (sig) {}

public:
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

  bool requires_dyn_ctx () const { return true; }
};
  
class ctx_var_assign : public function
{
public:
  ctx_var_assign(const signature& sig) : function (sig) {}

public:
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

  bool requires_dyn_ctx () const { return true; }
};
  
}


#endif  /* ZORBA_FN_CONTEXT_H */
