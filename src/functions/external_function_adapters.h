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

namespace zorba 
{

/*******************************************************************************

********************************************************************************/
class external_function : public function 
{
protected:
  QueryLoc  theLoc;

public:
  SERIALIZABLE_ABSTRACT_CLASS(external_function)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(external_function, function)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    zorba::serialization::serialize_baseclass(ar, (function*)this);
  }

public:
   external_function(const QueryLoc& loc, const signature& sig) 
    :
    function(sig, FunctionConsts::FN_UNKNOWN)
  {
  }

  virtual ~external_function() { }

  bool isBuiltin() const { return false; }

  bool isExternal() const { return true; }

  bool isUdf() const { return false; }
};


class stateless_external_function_adapter : public external_function 
{
private:
  StatelessExternalFunction * theFunction;
  expr_script_kind_t          theScriptingKind;
  xqpStringStore_t            theNamespace;

public:
  SERIALIZABLE_CLASS(stateless_external_function_adapter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(stateless_external_function_adapter, external_function)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  stateless_external_function_adapter(
        const QueryLoc& loc,
        const signature& sig, 
        StatelessExternalFunction* function,
        expr_script_kind_t scriptingType,
        bool deterministic,
        const xqpStringStore_t& ns);
  
  ~stateless_external_function_adapter();

  virtual expr_script_kind_t getUpdateType() const { return theScriptingKind; }

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const;
};


} /* namespace zorba */
#endif  /* ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H */

/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
