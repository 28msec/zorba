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
#ifndef ZORBA_RUNTIME_GFLWOR_COMP_FUNCTION
#define ZORBA_RUNTIME_GFLWOR_COMP_FUNCTION

#include "runtime/core/gflwor/common.h"
#include "runtime/api/runtimecb.h"
#include "runtime/booleans/BooleanImpl.h"


namespace zorba 
{

namespace flwor
{

/***************************************************************************//**
  Class acting as a comparison function between two sort tuples. An instance of
  this class is passed to std::sort() method that sorts an array of sort tuples. 
********************************************************************************/
class SortTupleCmp
{
private:
  const std::vector<OrderSpec> * theOrderSpecs;
  TypeManager                  * theTypeManager;
  long                           theTimezone;

public:
  SortTupleCmp() : theOrderSpecs(0), theTypeManager(0), theTimezone(0) {}

  SortTupleCmp(RuntimeCB* rcb, static_context* sctx, const std::vector<OrderSpec>* orderSpecs)
  :
  theOrderSpecs(orderSpecs) 
  {
    theTypeManager = sctx->get_typemanager();
    theTimezone = rcb->theDynamicContext->get_implicit_timezone();
  }

  /**
     The key comparison function, a Strict Weak Ordering whose argument type is
     key_type. It returns true if its first argument is less than its second argument,
     and false otherwise. This is also defined as multimap::key_compare.
  */
  bool operator()(const SortTuple& t1, const SortTuple& t2) const
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
                         orderSpecIter->theCollator);
      if (cmp == 1)
      {
        return false;
      }
      else if (cmp == -1)
      {
        return true;
      }
      
      ++t1iter;
      ++t2iter;
      ++orderSpecIter;
    }
    return false;
  }

          
  /**
     Does the actual comparision. Returns:
     -1, if item1 < item2
      0, if item1 == item2
      1, if item1 > item2
  */
  long compare(
        store::Item* item1,
        store::Item* item2,
        bool desc,
        bool emptyLeast,
        XQPCollator* collator) const
  {
    if (empty_item(item1))
    {
      if (empty_item(item2))
        return descAsc(0, desc);
      else
        return descAsc(emptyLeast ? -1 : 1, desc);
    }
    else if (empty_item(item2))
    {
      return descAsc(emptyLeast ? 1 : -1, desc);
    }
    else
    {
      // danm: both valueCompare (x, NaN) and valueCompare (NaN, x) return 2.
      // That's why empty_item is needed.
#if 1
      store::Item_t ls1(item1);
      store::Item_t ls2(item2);
      long result = CompareIterator::valueCompare(ls1 , ls2,
                                                  theTypeManager,
                                                  theTimezone,
                                                  collator);
#else
      long result = item1->compare(item2, theTimezone, collator);
#endif
      if (result > 1 || result < -1) 
      {
        ZORBA_ERROR_DESC( XPTY0004, "Non-comparable types found while sorting" );
      }
      return descAsc (result , desc);
    }
  }
    
  long descAsc(long result, bool desc) const
  {
    ZORBA_ASSERT (result <= 1 && result >= -1);
    return desc ? -result : result;
  }
};


}
}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
