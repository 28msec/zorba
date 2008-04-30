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
#include "functions/external_function_adapters.h"
#include "runtime/core/fncall_iterator.h"

namespace zorba {

stateless_external_function_adapter::stateless_external_function_adapter
(const signature& sig, StatelessExternalFunction *function, bool aIsUpdating)
: external_function(sig),
  m_function(function),
  theUpdateType((aIsUpdating ? UPDATE_EXPR : SIMPLE_EXPR))
{
}

stateless_external_function_adapter::~stateless_external_function_adapter()
{
}

PlanIter_t stateless_external_function_adapter::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
    return new StatelessExtFunctionCallIterator(loc, argv, m_function, isUpdating());
}

}
