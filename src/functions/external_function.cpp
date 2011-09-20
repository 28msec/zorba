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
#include "stdafx.h"

#include "functions/external_function.h"

#include "runtime/core/fncall_iterator.h"
#include "api/unmarshaller.h"

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(external_function)
END_SERIALIZABLE_CLASS_VERSIONS(external_function)


external_function::external_function(
    const QueryLoc& loc,
    static_context* modSctx,
    const zstring& ns,
    const signature& sig,
    short scriptingType,
    ExternalFunction* impl) 
  :
  function(sig, FunctionConsts::FN_UNKNOWN),
  theLoc(loc),
  theModuleSctx(modSctx),
  theNamespace(ns),
  theScriptingKind(scriptingType),
  theImpl(impl)
{
  resetFlag(FunctionConsts::isBuiltin);
}


void external_function::serialize(::zorba::serialization::Archiver& ar)
{
  zorba::serialization::serialize_baseclass(ar, (function*)this);

  ar & theLoc;
  ar & theModuleSctx;
  ar & theNamespace;
  ar & theScriptingKind;

  // also serialize the localname of the function
  zstring lLocalName;
  if (ar.is_serializing_out()) 
  {
    ZORBA_ASSERT(theImpl);
    lLocalName = Unmarshaller::getInternalString(theImpl->getLocalName());
  }
  ar.set_is_temp_field(true);
  ar & lLocalName;
  ar.set_is_temp_field(false);

  // if loaded, theImpl needs to be set immediately
  // this is covered by test/unit/external_function.cpp
  if(!ar.is_serializing_out()) 
  {
    try
    {
      theImpl = theModuleSctx->lookup_external_function(theNamespace, lLocalName);
    }
    catch (XQueryException& e)
    {
      set_source( e, theLoc );
      throw;
    }

    if (theImpl == NULL)
    {
      throw XQUERY_EXCEPTION(
        zerr::ZXQP0008_FUNCTION_IMPL_NOT_FOUND,
        ERROR_PARAMS( BUILD_STRING( '{', theNamespace, '}', lLocalName ) ),
        ERROR_LOC( theLoc )
      );
    }
  }
}


bool external_function::accessesDynCtx() const
{
  return theImpl->isContextual();
}


PlanIter_t external_function::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  return new ExtFunctionCallIterator(sctx,
                                     loc,
                                     argv,
                                     theImpl,
                                     isUpdating(),
                                     theNamespace,
                                     theModuleSctx);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
