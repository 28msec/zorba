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
#pragma once
#ifndef ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H
#define ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H

#include <vector>
#include <zorba/function.h>

#include "common/shared_types.h"

#include "functions/cacheable_function.h"

namespace zorba 
{

/*******************************************************************************
  theLoc           : The location of the declaration of this external function.
  theNamespace     : The namespace of the module containing the declaration.
  theScriptingKind : Whether the external function is simple, updating, or
                     sequential (this property is part of the declaration).
  theImpl          : The user-provided c++ class that implements the external
                     function.
********************************************************************************/
class external_function : public cacheable_function
{
protected:
  QueryLoc theLoc;
  zstring  theNamespace;
  unsigned short theScriptingKind;
  ExternalFunction * theImpl;


public:
  SERIALIZABLE_CLASS(external_function)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(external_function, cacheable_function)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  external_function(
        const QueryLoc& loc,
        static_context* modSctx,
        const zstring& ns,
        const signature& sig,
        unsigned short scriptingType,
        ExternalFunction* internal,
        XQueryDiagnostics* diag);

  ~external_function() {}

  unsigned short getScriptingKind() const { return theScriptingKind; }

  bool accessesDynCtx() const;

  bool propagatesInputNodes(expr* fo, csize input) const;

  bool mustCopyInputNodes(expr* fo, csize input) const;

  PlanIter_t codegen(
        CompilerCB* /*cb*/,
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        expr& ann) const;
};


} /* namespace zorba */
#endif  /* ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H */


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
