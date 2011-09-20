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
#ifndef ZORBA_RUNTIME_DURATIONSDATESTIMES
#define ZORBA_RUNTIME_DURATIONSDATESTIMES

#include "common/shared_types.h"

#include "zorbatypes/datetime.h"

#include "runtime/base/binarybase.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"


namespace zorba
{

BINARY_ITER(FnDateTimeConstructorIterator);


// XQuery 3.0 DateTime formatting
class FnFormatDateTimeIterator : public NaryBaseIterator<FnFormatDateTimeIterator,
                                                         PlanIteratorState >
{
private:
  DateTime::FACET_TYPE facet_type;

public:
  SERIALIZABLE_CLASS(FnFormatDateTimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  FnFormatDateTimeIterator,
  NaryBaseIterator<FnFormatDateTimeIterator, PlanIteratorState >);

  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnFormatDateTimeIterator, PlanIteratorState >*)this);

    SERIALIZE_ENUM(DateTime::FACET_TYPE, facet_type);
  }

public:
  FnFormatDateTimeIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& aChildren,
        DateTime::FACET_TYPE a_facet_type = DateTime::DATETIME_FACET)
    :
    NaryBaseIterator<FnFormatDateTimeIterator, PlanIteratorState>(sctx, loc, aChildren),
    facet_type(a_facet_type)
  {
  }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*
10.7 Timezone Adjustment Functions on Dates and Time Values
*/

/*
10.7.1 fn:adjust-dateTime-to-timezone
10.7.2 fn:adjust-date-to-timezone
10.7.3 fn:adjust-time-to-timezone
*/
UNARY_ITER(FnAdjustToTimeZoneIterator_1);

/*
10.7.2 fn:adjust-date-to-timezone
10.7.3 fn:adjust-time-to-timezone
*/
BINARY_ITER(FnAdjustToTimeZoneIterator_2);

} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

/* vim:set et sw=2 ts=2: */
