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
#include "functions/cacheable_function.h"
#include "functions/function_impl.h"

#include "annotations/annotations.h"

#include "diagnostics/xquery_warning.h"
#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "types/typeops.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

#include "zorbautils/hashmap_itemh_strict.h"

#include "runtime/base/plan_iterator.h"
#include "context/dynamic_context.h"

namespace zorba
{

/*******************************************************************************
********************************************************************************/
FunctionCache::FunctionCache(
    static_context* aSctx,
    std::vector<bool>& aExcludeFromCacheKey,
    std::vector<bool>& aCompareWithDeepEqual,
    bool aAcrossSnapshots):
      FunctionCacheBaseMap(aSctx, aExcludeFromCacheKey, aCompareWithDeepEqual),
      theAcrossSnapshots(aAcrossSnapshots),
      theSnapshotID(0)
{
}

/*******************************************************************************
********************************************************************************/
bool FunctionCache::ensureCacheValidity(PlanState& aPlanState)
{
  if (!theAcrossSnapshots)
  {
    uint64_t lCurrentSnapshot = aPlanState.theGlobalDynCtx->getSnapshotID();
    if (theSnapshotID != lCurrentSnapshot)
    {
      theSnapshotID = lCurrentSnapshot;
      clear();
      return false;
    }
  }
  return true;
}

/*******************************************************************************
********************************************************************************/
FunctionCache::iterator FunctionCache::find(const store::Item_t& item, PlanState& aPlanState)
{
  if (!ensureCacheValidity(aPlanState) || empty())
    return end();
  else
    return FunctionCacheBaseMap::find(item);
}


/*******************************************************************************
********************************************************************************/
bool FunctionCache::insert(const store::Item_t& item, std::vector<store::Item_t>& value, PlanState& aPlanState)
{
  ensureCacheValidity(aPlanState);
  return FunctionCacheBaseMap::insert(item, value);
}


/*******************************************************************************
********************************************************************************/
bool FunctionCache::insert(const store::Item_t& item, const store::Item_t& value, PlanState& aPlanState)
{
  std::vector<store::Item_t> lVector;
  lVector.push_back(value);
  return insert(item, lVector, aPlanState);
}

SERIALIZABLE_CLASS_VERSIONS(cacheable_function)


/*******************************************************************************
********************************************************************************/
cacheable_function::cacheable_function(
    const signature& aSig,
    FunctionConsts::FunctionKind aKind,
    bool aIsBuiltin,
    const QueryLoc& aLoc,
    TypeManager* aTypeManager):
      function(aSig, aKind, aIsBuiltin),
      theLoc(aLoc),
      theTypeManager(aTypeManager),
      theHasCache(false),
      theCacheAcrossSnapshots(false),
      theIsCacheAutomatic(false),
      theAreCacheSettingsComputed(false)
{

}

/*******************************************************************************
********************************************************************************/
cacheable_function::cacheable_function(::zorba::serialization::Archiver& ar):
  function(ar)
{

}


/*******************************************************************************
********************************************************************************/
void cacheable_function::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (function*)this);
}


/*******************************************************************************
********************************************************************************/
FunctionCache* cacheable_function::getCache()
{
  return theCache.get();
}


/*******************************************************************************
********************************************************************************/
bool cacheable_function::hasCache() const
{
  return theHasCache;
}

/*******************************************************************************
********************************************************************************/
bool cacheable_function::cacheAcrossSnapshots() const
{
  return theCacheAcrossSnapshots;
}


/*******************************************************************************
********************************************************************************/
TypeManager* cacheable_function::getTypeManager()
{
  ZORBA_ASSERT(false);
  return nullptr;
}

/*******************************************************************************
********************************************************************************/
void cacheable_function::computeCacheSettings(XQueryDiagnostics* aDiag)
{
  if (theAreCacheSettingsComputed)
    return;

  if (!theTypeManager)
    theTypeManager = getTypeManager();

  ZORBA_ASSERT(theTypeManager);

  if (!theAnnotationList)
    useDefaultCachingSettings();
  else if (theAnnotationList->contains(AnnotationInternal::zann_cache))
    useLegacyCache(aDiag);
  else if (theAnnotationList->contains(AnnotationInternal::zann_strictlydeterministic))
    useStrictlyDeterministicCache(aDiag);
  else if (theAnnotationList->contains(AnnotationInternal::zann_deterministic))
    theHasCache = false;
  else
    useDefaultCachingSettings();

  theAreCacheSettingsComputed = true;
  theCache.reset(new FunctionCache(
      theModuleSctx,
      theExcludeFromCacheKey,
      theCompareWithDeepEqual,
      theCacheAcrossSnapshots));
}


/*******************************************************************************
********************************************************************************/
void cacheable_function::useDefaultCachingSettings()
{
  if (isVariadic() || isUpdating() || isSequential() || !isDeterministic())
  {
    theHasCache = false;
  }
  else
  {
    if (!haveAtomicArgumentsAndReturnType())
    {
      theHasCache = false;
    }
    else
    {
      theHasCache = true;
      theIsCacheAutomatic = true;
      theCacheAcrossSnapshots = false;
    }
  }
}


/*******************************************************************************
********************************************************************************/
bool cacheable_function::haveAtomicArgumentsAndReturnType() const
{
  // parameters are subtype of xs:anyAtomicType
  csize lArity = theSignature.paramCount();
  for (csize i = 0; i < lArity; ++i)
  {
    if (!isAtomicSequence(theSignature[i]))
      return false;
  }
  // return type is subtype of xs:anyAtomicType
  if (!isAtomicSequence(theSignature.returnType()))
    return false;

  return true;
}


/*******************************************************************************
********************************************************************************/
bool cacheable_function::isAtomicSequence(const xqtref_t& aType) const
{
  return
  (
    TypeOps::is_subtype(theTypeManager, *aType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE, theLoc) ||
    TypeOps::is_subtype(theTypeManager, *aType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_PLUS, theLoc) ||
    TypeOps::is_subtype(theTypeManager, *aType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, theLoc) ||
    TypeOps::is_subtype(theTypeManager, *aType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, theLoc)
  );
}


/*******************************************************************************
********************************************************************************/
bool cacheable_function::haveAllArgumentOneCardinality() const
{
  // parameters are subtype of xs:anyAtomicType
  csize lArity = theSignature.paramCount();
  for (csize i = 0; i < lArity; ++i)
  {
    if (theSignature[i]->card() != 1)
      return false;
  }
  // return type is subtype of xs:anyAtomicType
  if (theSignature.returnType()->card() != 1)
    return false;

  return true;
}


/*******************************************************************************
********************************************************************************/
void cacheable_function::useLegacyCache(XQueryDiagnostics* aDiag)
{
  if (isUpdating() || isVariadic())
  {
    if (aDiag)
    {
      aDiag->add_warning(
        NEW_XQUERY_WARNING(zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
        WARN_PARAMS(getName()->getStringValue(), isUpdating() ? ZED(ZWST0005_UPDATING) : ZED(ZWST0005_VARIADIC)),
        WARN_LOC(theLoc)));
    }
    theHasCache = false;
    return;
  }

  if (isSequential() || !isDeterministic())
  {
    if (aDiag)
    {
      aDiag->add_warning(
        NEW_XQUERY_WARNING(zwarn::ZWST0006_CACHING_MIGHT_NOT_BE_INTENDED,
        WARN_PARAMS(getName()->getStringValue(), (isSequential() ? "sequential" : "non-deterministic")),
        WARN_LOC(theLoc)));
    }
  }

  parseCachingAnnotations(aDiag);
  theHasCache = true;
  theIsCacheAutomatic = false;
  theCacheAcrossSnapshots = true;
}


/*******************************************************************************
********************************************************************************/
void cacheable_function::useStrictlyDeterministicCache(XQueryDiagnostics* aDiag)
{
  if (isUpdating() || isSequential() || isVariadic())
  {
    if (aDiag)
    {
      aDiag->add_warning(
        NEW_XQUERY_WARNING(zwarn::ZWST0005_CACHING_NOT_POSSIBLE,
        WARN_PARAMS(getName()->getStringValue(),
          isUpdating() ? ZED(ZWST0005_UPDATING) :
            (isSequential() ? ZED(ZWST0005_SEQUENTIAL) : ZED(ZWST0005_VARIADIC))),
        WARN_LOC(theLoc)));
    }
    theHasCache = false;
  }
  else
  {
    parseCachingAnnotations(aDiag);
    theHasCache = true;
    theIsCacheAutomatic = false;
    theCacheAcrossSnapshots = false;
  }
}

/*******************************************************************************
********************************************************************************/
bool cacheable_function::disableAutomaticCaching()
{
  if (theIsCacheAutomatic)
  {
    theHasCache = false;
    theCache->clear();
    return true;
  }
  return false;
}

/*******************************************************************************
********************************************************************************/
void cacheable_function::parseCachingAnnotations(XQueryDiagnostics* aDiag)
{
  parseCachingAnnotation(
      theAnnotationList->get(AnnotationInternal::zann_compare_with_deep_equal),
      theCompareWithDeepEqual,
      aDiag);
  parseCachingAnnotation(
      theAnnotationList->get(AnnotationInternal::zann_exclude_from_cache_key),
      theExcludeFromCacheKey,
      aDiag);
}

/*******************************************************************************
********************************************************************************/
void cacheable_function::parseCachingAnnotation(AnnotationInternal* aAnnotation,
    std::vector<bool>& aFlags,
    XQueryDiagnostics* aDiag)
{
  if (!aAnnotation)
    return;

  aFlags.resize(theSignature.paramCount(), false);

  for (csize i=0; i<aAnnotation->getNumLiterals(); ++i)
  {
    zorba::store::Item* lLiteral = aAnnotation->getLiteral(i);
    int lIndex = atoi(lLiteral->getStringValue().c_str());
    if (lIndex <1 || lIndex>(int)theSignature.paramCount())
    {
      std::string lFunctionName = "anonymous";
      if (theSignature.getName())
        lFunctionName = theSignature.getName()->getStringValue().str();

      if (theSignature.paramCount())
      {
        RAISE_ERROR(zerr::ZXQP0064_INVALID_ARGUMENT_INDEX, theLoc,
            ERROR_PARAMS(
                lLiteral->getStringValue(),
                lFunctionName,
                theSignature.paramCount()));
      }
      else
      {
        RAISE_ERROR(zerr::ZXQP0065_INVALID_ANNOTATION, theLoc,
            ERROR_PARAMS(
                lLiteral->getStringValue(),
                lFunctionName,
                ZED(ZXQP0065_NO_ARGUMENTS)));
      }
    }
    else
    {
      aFlags[lIndex-1] = true;
    }
  }
}

/*******************************************************************************
********************************************************************************/
void cacheable_function::saveFlags(const std::vector<bool>& aFlags, ::zorba::serialization::Archiver& ar)
{
  std::vector<bool>::size_type lSize = aFlags.size();
  ar & lSize;
  bool lValue;
  for (std::vector<bool>::size_type i = 0; i<lSize; ++i)
  {
    lValue = aFlags[i];
    ar & lValue;
  }
}

/*******************************************************************************
********************************************************************************/
void cacheable_function::loadFlags(std::vector<bool>& aFlags, ::zorba::serialization::Archiver& ar)
{
  std::vector<bool>::size_type lSize = 0;
  ar & lSize;
  aFlags.resize(lSize, false);
  bool lValue;
  for (std::vector<bool>::size_type i = 0; i<lSize; ++i)
  {
    ar & lValue;
    aFlags[i] = lValue;
  }
}


}
