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
#ifndef ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H
#define ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H

#include <vector>
#include <zorba/external_function.h>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class stateless_external_function_adapter : public external_function {
  public:
    stateless_external_function_adapter(
      const signature& sig, 
      StatelessExternalFunction *function,
      bool aIsUpdating);

    ~stateless_external_function_adapter();

    virtual PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    virtual expr_update_t getUpdateType() const { return theUpdateType; }

    virtual bool isPureFunction() const { return m_function->isPureFunction(); }

  private:
    StatelessExternalFunction *m_function;
    expr_update_t theUpdateType;
};

} /* namespace zorba */
#endif  /* ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H */
/* vim:set ts=2 sw=2: */
