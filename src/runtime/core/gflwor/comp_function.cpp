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

#include "runtime/core/gflwor/comp_function.h"

#include <iostream>

namespace zorba {
namespace flwor {


bool SortTupleCmp::operator()(const SortTuple& t1, const SortTuple& t2) const
{
  ZORBA_ASSERT(t1.theKeyValues.size() == t2.theKeyValues.size());
  ZORBA_ASSERT(t1.theKeyValues.size() == theOrderSpecs->size());

  std::vector<store::Item*>::const_iterator t1iter = t1.theKeyValues.begin();
  std::vector<store::Item*>::const_iterator t1end = t1.theKeyValues.end();
  std::vector<store::Item*>::const_iterator t2iter = t2.theKeyValues.begin();

  std::vector<OrderSpec>::const_iterator orderSpecIter = theOrderSpecs->begin();

  while (t1iter != t1end)
  {
    long cmp = compare(*t1iter,
                        *t2iter,
                        orderSpecIter->theDescending,
                        orderSpecIter->theEmptyLeast,
                        orderSpecIter->theNativeCompare,
                        orderSpecIter->theCollator);
    if (cmp > 0)
    {
      return false;
    }
    else if (cmp < 0)
    {
      return true;
    }
    
    ++t1iter;
    ++t2iter;
    ++orderSpecIter;
  }
  return false;
}

          
long SortTupleCmp::compare(
      store::Item* item1,
      store::Item* item2,
      bool desc,
      bool emptyLeast,
      bool nativeCompare,
      XQPCollator* collator) const
{
  if (item1 == NULL)
  {
    if (item2 == NULL)
      return 0;
    else
      return descAsc(emptyLeast ? -1 : 1, desc);
  }
  else if (item1->isNaN())
  {
    if (item2 == NULL)
      return descAsc(emptyLeast ? 1 : -1, desc);
    else if (item2->isNaN())
      return 0;
    else
      return descAsc(emptyLeast ? -1 : 1, desc);
  }
  else if (item2 == NULL || item2->isNaN())
  {
    return descAsc(emptyLeast ? 1 : -1, desc);
  }
  else
  {
    long result;

    // danm: both valueCompare (x, NaN) and valueCompare (NaN, x) return 2.
    // That's why empty_item is needed.
    if (nativeCompare)
    {
      result = item1->compare(item2, theTimezone, collator);
    }
    else
    {
      store::Item_t ls1(item1);
      store::Item_t ls2(item2);
      result = CompareIterator::valueCompare(theLocation,
                                             ls1,
                                             ls2,
                                             theTypeManager,
                                             theTimezone,
                                             collator);
    }

    return descAsc(result , desc);
  }
}
  
} // namespace flwor
} // namespace zorba

/*
* Local variables:
* mode: c++
* End:
*/
/* vim:set et sw=2 ts=2: */
