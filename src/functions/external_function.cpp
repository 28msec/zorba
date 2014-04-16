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

#include "diagnostics/util_macros.h"

#include "types/typeops.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(external_function)


/*******************************************************************************

********************************************************************************/
external_function::external_function(
    const QueryLoc& loc,
    static_context* modSctx,
    const zstring& ns,
    const signature& sig,
    unsigned short scriptingType,
    ExternalFunction* impl,
    XQueryDiagnostics* diag)
  :
  cacheable_function(sig, FunctionConsts::FN_UNKNOWN, false, loc, modSctx->get_typemanager()),
  theNamespace(ns),
  theScriptingKind(scriptingType),
  theImpl(impl)
{
  theModuleSctx = modSctx;
}


/*******************************************************************************

********************************************************************************/
void external_function::serialize(::zorba::serialization::Archiver& ar)
{
  zorba::serialization::serialize_baseclass(ar, (function*)this);

  ar & theNamespace;
  ar & theScriptingKind;

  // also serialize the localname of the function
  zstring lLocalName;
  if (ar.is_serializing_out()) 
  {
    computeCacheSettings(NULL);
    ZORBA_ASSERT(theImpl);
    lLocalName = Unmarshaller::getInternalString(theImpl->getLocalName());
  }
  ar.set_is_temp_field(true);
  ar & lLocalName;
  ar.set_is_temp_field(false);

  // if loaded, theImpl needs to be set immediately
  // this is covered by test/unit/external_function.cpp
  if (!ar.is_serializing_out()) 
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
      RAISE_ERROR(zerr::ZXQP0008_FUNCTION_IMPL_NOT_FOUND, theLoc,
        ERROR_PARAMS(BUILD_STRING( '{', theNamespace, '}', lLocalName)));
    }
  }

  ar & theLoc;
  ar & theHasCache;
  ar & theCacheAcrossSnapshots;

  if (ar.is_serializing_out())
  {
    saveDynamicBitset(theExcludeFromCacheKey, ar);
    saveDynamicBitset(theCompareWithDeepEqual, ar);
  }
  else
  {
    loadDynamicBitset(theExcludeFromCacheKey, ar);
    loadDynamicBitset(theCompareWithDeepEqual, ar);
  }

  ar & theAreCacheSettingsComputed;
  ar & theIsCacheAutomatic;

  if (!ar.is_serializing_out())
  {
    theCache.reset(new FunctionCache(
      theModuleSctx,
      theExcludeFromCacheKey,
      theCompareWithDeepEqual,
      theCacheAcrossSnapshots));
  }
}


/*******************************************************************************

********************************************************************************/
bool external_function::accessesDynCtx() const
{
  return theImpl->isContextual();
}


/*******************************************************************************

********************************************************************************/
bool external_function::propagatesInputNodes(
    expr* fo,
    csize input) const
{
  bool res = function::propagatesInputNodes(fo, input);

  if (res == false)
    return res;

  AnnotationInternal* ann = NULL;

  if (theAnnotationList)
    ann = theAnnotationList->get(AnnotationInternal::zann_propagates_input_nodes);

  if (ann != NULL)
  {
    csize numLiterals = ann->getNumLiterals();

    for (csize i = 0; i < numLiterals; ++i)
    {
      if (ann->getLiteral(i)->getLongValue() == (unsigned int)input + 1)
        return true;
    }

    return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool external_function::mustCopyInputNodes(
    expr* fo,
    csize input) const
{
  bool res = function::mustCopyInputNodes(fo, input);

  if (res == false)
    return res;

  AnnotationInternal* ann = NULL;

  if (theAnnotationList)
    ann = theAnnotationList->get(AnnotationInternal::zann_must_copy_input_nodes);

  if (ann != NULL)
  {
    csize numLiterals = ann->getNumLiterals();

    for (csize i = 0; i < numLiterals; ++i)
    {
      if (ann->getLiteral(i)->getLongValue() == (unsigned int)input + 1)
        return true;
    }

    return false;
  }

  return true;
}

/*******************************************************************************

********************************************************************************/
PlanIter_t external_function::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  return new ExtFunctionCallIterator(sctx,
                                     loc,
                                     argv,
                                     this,
                                     theImpl,
                                     isUpdating(),
                                     isSequential(),
                                     theNamespace,
                                     theModuleSctx);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
