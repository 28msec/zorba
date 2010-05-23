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

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(external_function)
END_SERIALIZABLE_CLASS_VERSIONS(external_function)


SERIALIZABLE_CLASS_VERSIONS(stateless_external_function_adapter)
END_SERIALIZABLE_CLASS_VERSIONS(stateless_external_function_adapter)


stateless_external_function_adapter::stateless_external_function_adapter(
    const QueryLoc& loc, 
    const signature& sig,
    StatelessExternalFunction* function, 
    expr_script_kind_t scriptingType,
    bool deterministic,
    const xqpStringStore_t& ns)
  :
  external_function(loc, sig),
  theFunction(function),
  theScriptingKind(scriptingType),
  theNamespace(ns)
{
  setDeterministic(deterministic);
}


stateless_external_function_adapter::~stateless_external_function_adapter()
{
}


void stateless_external_function_adapter::serialize(::zorba::serialization::Archiver& ar)
{
  zorba::serialization::serialize_baseclass(ar, (external_function*)this);

  if(!ar.is_serializing_out())
    theFunction = NULL;//don't serialize this for now

  SERIALIZE_ENUM(expr_script_kind_t, theScriptingKind);
  ar & theNamespace;
}


PlanIter_t stateless_external_function_adapter::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  return new StatelessExtFunctionCallIterator(sctx,
                                              loc,
                                              argv,
                                              theFunction,
                                              isUpdating(),
                                              theNamespace);
}

}
