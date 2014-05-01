/*
 * Copyright 2006-2013 The FLWOR Foundation.
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
#ifndef ZORBA_CACHEABLE_FUNCTION
#define ZORBA_CACHEABLE_FUNCTION

#include "functions/function.h"
#include "zorbautils/hashmap_itemh_cache.h"
#include "store/api/item_handle.h"
#include <vector>

namespace zorba
{
class expr;

typedef zorba::ItemHandleCacheHashMap< std::vector<store::Item_t> > FunctionCacheBaseMap;

class FunctionCache : public FunctionCacheBaseMap
{
public:
  typedef FunctionCacheBaseMap::iterator iterator;

  FunctionCache(static_context* aSctx,
      std::vector<bool>& aExcludeFromCacheKey,
      std::vector<bool>& aCompareWithDeepEqual,
      bool aAcrossSnapshots);

  FunctionCache::iterator find(const store::Item_t& aKey, PlanState& aPlanState);

  bool insert(const store::Item_t& aKey, std::vector<store::Item_t>& aValue, PlanState& aPlanState);

  bool insert(const store::Item_t& aKey, const store::Item_t& aValue, PlanState& aPlanState);

private:
  bool ensureCacheValidity(PlanState& aPlanState);

public:
  bool theAcrossSnapshots;
  uint64_t theSnapshotID;
};


/*******************************************************************************
  theCache:
  ---------
  Maps the arg values of an invocation to the result of that invocation.
  If an invocation uses the same arg values as a previous invocation, the cached
  result is simply returned without re-evaluating the udf.

  theHasCache:
  ----------------
  Tells whether caching should be done for this udf or not.

  theCacheComputed:
  -----------------
  Tells whether theHasCache has been computed already or not.
  theHasCache is computed by the computeCacheSettings() method, which is
  invoked during codegen every time a udf call is encountered. The same udf may
  be invoked multiple times, but the computation of theHasCache needs to
  be done only once. So, during the 1st invcocation of computeCacheSettings(),
  theCacheComputed is set to true, and subsequent invocations are noops.
********************************************************************************/
class cacheable_function : public function
{
protected:
  QueryLoc theLoc;
  TypeManager* theTypeManager;
  std::auto_ptr<FunctionCache> theCache;

  //
  // Cache settings
  //
  bool theHasCache;
  bool theCacheAcrossSnapshots;
  bool theIsCacheAutomatic;
  bool theAreCacheSettingsComputed;
  std::vector<bool> theExcludeFromCacheKey;
  std::vector<bool> theCompareWithDeepEqual;

public:
  SERIALIZABLE_CLASS(cacheable_function)
  cacheable_function(::zorba::serialization::Archiver& ar);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  const QueryLoc& getLoc() const { return theLoc; }
  cacheable_function(
      const signature& aSig,
      FunctionConsts::FunctionKind aKkind,
      bool aIsBuiltin,
      const QueryLoc& aLoc,
      TypeManager* aTypeManager);
  FunctionCache* getCache();
  bool hasCache() const;
  bool cacheAcrossSnapshots() const;

  virtual void computeCacheSettings(XQueryDiagnostics* aDiag);
  virtual bool disableAutomaticCaching();

protected:
  virtual void useDefaultCachingSettings();
  virtual void useLegacyCache(XQueryDiagnostics* aDiag);
  virtual void useStrictlyDeterministicCache(XQueryDiagnostics* aDiag);
  void saveFlags(const std::vector<bool>& aFlags, ::zorba::serialization::Archiver& ar);
  void loadFlags(std::vector<bool>& aFlags, ::zorba::serialization::Archiver& ar);

private:
  virtual bool haveAtomicArgumentsAndReturnType() const;
  virtual bool isAtomicSequence(const xqtref_t& aType) const;
  virtual bool haveAllArgumentOneCardinality() const;
  virtual void parseCachingAnnotations(XQueryDiagnostics* aDiag);
  virtual void parseCachingAnnotation(AnnotationInternal* aAnnotation,
      std::vector<bool>& aFlags,
      XQueryDiagnostics* aDiag);

  virtual TypeManager* getTypeManager();
};


} /* namespace zorba */
#endif

