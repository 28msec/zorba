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
#ifndef ZORBA_ZORBAUTILS_HAHSET_ATOMIC_ITEMH
#define ZORBA_ZORBAUTILS_HAHSET_ATOMIC_ITEMH

#include "zorbautils/hashset.h"

#include "runtime/booleans/BooleanImpl.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

namespace zorba 
{ 


/*******************************************************************************

********************************************************************************/
class ValueCompareParam
{
public:
  ValueCompareParam(
      const QueryLoc& loc,
      dynamic_context* dctx,
      static_context* sctx)
    :
    theLocation(loc),
    theTypeManager(sctx->get_typemanager()),
    theTimezone(dctx->get_implicit_timezone()),
    theCollator(sctx->get_default_collator(loc)) 
  {
  }

  const QueryLoc & theLocation;
  TypeManager    * theTypeManager;
  long             theTimezone;
  XQPCollator    * theCollator;
};


/*******************************************************************************
  Used by the fn:distinct-values function.
********************************************************************************/
class AtomicItemHandleHashSet
{
public:

  class CompareFunction
  {
  private:
    ValueCompareParam * theCompareParam;

  public:
    CompareFunction(ValueCompareParam* comp) : theCompareParam(comp) {}

    bool equal(store::Item* item1, store::Item* item2) const
    {
      assert(item1 != NULL);
      assert(item2 != NULL);
      store::Item_t t1(item1);
      store::Item_t t2(item2);

      try
      {
        return CompareIterator::valueEqual(theCompareParam->theLocation,
                                           t1,
                                           t2,
                                           theCompareParam->theTypeManager,
                                           theCompareParam->theTimezone,
                                           theCompareParam->theCollator);
      }
      catch(ZorbaException& e)
      {
        if (e.diagnostic() == err::XPTY0004)
        {
          return false;
        }

        throw e;
      }
    }

    uint32_t hash(store::Item* t) const
    {
      assert (t != NULL);
      return t->hash(theCompareParam->theTimezone,  theCompareParam->theCollator);
    }
  };

private:
  ValueCompareParam                      * theCompareParam;
  CompareFunction                          theCompareFunction;
  HashSet<store::Item*, CompareFunction>   theSet;

public:
  AtomicItemHandleHashSet(ValueCompareParam* compParam, csize size = 1024);

  ~AtomicItemHandleHashSet();

  void clear();

  bool exists(const store::Item_t& key) 
  {
    return theSet.exists(key.getp()); 
  }

  bool insert(store::Item_t& key) 
  {
    assert(key->isAtomic());
    store::Item* tmp = key.getp();

    bool inserted = theSet.insert(tmp);

    if (inserted)
    {
      key->addReference();
    }

    return inserted;
  }
};


} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
