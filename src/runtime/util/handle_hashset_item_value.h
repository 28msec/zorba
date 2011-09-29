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
#ifndef ZORBA_RUNTIME_HANDLE_HAHSET_ITEM_VALUE_H
#define ZORBA_RUNTIME_HANDLE_HAHSET_ITEM_VALUE_H

#include "zorbautils/hashset.h"

#include "runtime/booleans/BooleanImpl.h"

#include "context/dynamic_context.h"

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

********************************************************************************/
class ItemValueCollHandleHashSet
{
public:

  class CompareFunction
  {
  private:
    ValueCompareParam * theCompareParam;

  public:
    CompareFunction(ValueCompareParam* comp) : theCompareParam(comp) {}

    bool equal(const store::Item_t& item1, const store::Item_t& item2) const
    {
      assert (item1 != NULL);
      assert (item2 != NULL);
      store::Item_t t1(item1);
      store::Item_t t2(item2);
      return CompareIterator::valueEqual(theCompareParam->theLocation,
                                         t1,
                                         t2,
                                         theCompareParam->theTypeManager,
                                         theCompareParam->theTimezone,
                                         theCompareParam->theCollator);
    }

    uint32_t hash(const store::Item_t& t) const
    {
      assert (t != NULL);
      return t->hash(theCompareParam->theTimezone,  theCompareParam->theCollator);
    }
  };

private:
  ValueCompareParam                      * theCompareParam;
  CompareFunction                          theCompareFunction;
  HashSet<store::Item_t, CompareFunction>  theSet;

public:
  ItemValueCollHandleHashSet(ValueCompareParam* compParam, ulong size = 1024)
  :
  theCompareParam(compParam),
  theCompareFunction(compParam),
  theSet(theCompareFunction, size, false)
  {
  }

  ~ItemValueCollHandleHashSet()
  {
    if (theCompareParam)
      delete theCompareParam; 
  }

  void clear() { theSet.clear(); }

  bool find(const store::Item_t& key) { return theSet.find(key); }

  bool insert(store::Item_t& key) { return theSet.insert(key); }
};


} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
