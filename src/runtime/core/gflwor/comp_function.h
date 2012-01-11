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

#include "context/dynamic_context.h"

#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/gflwor/common.h"
#include "runtime/core/gflwor/orderby_iterator.h"


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
  const QueryLoc               & theLocation;
  const std::vector<OrderSpec> * theOrderSpecs;
  const TypeManager            * theTypeManager;
  long                           theTimezone;

public:
  //SortTupleCmp() : theOrderSpecs(0), theTypeManager(0), theTimezone(0) {}

  SortTupleCmp(
        const QueryLoc& loc,
        dynamic_context* dctx,
        const TypeManager* tm,
        const std::vector<OrderSpec>* orderSpecs)
    :
    theLocation(loc),
    theOrderSpecs(orderSpecs) 
  {
    theTypeManager = tm;
    theTimezone = dctx->get_implicit_timezone();
  }

  /**
     The key comparison function, a Strict Weak Ordering whose argument type is
     key_type. It returns true if its first argument is less than its second argument,
     and false otherwise. This is also defined as multimap::key_compare.
  */
  bool operator()(const SortTuple& t1, const SortTuple& t2) const;

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
        bool nativeCompare,
        XQPCollator* collator) const;

  long descAsc(long result, bool desc) const
  {
    return desc ? -result : result;
  }
};


} // namespace flwor
} // namespace zorba
#endif /* ZORBA_RUNTIME_GFLWOR_COMP_FUNCTION */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
