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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************
#ifndef ZORBA_RUNTIME_DURATIONS_DATES_TIMES_DURATIONS_DATES_TIMES_H
#define ZORBA_RUNTIME_DURATIONS_DATES_TIMES_DURATIONS_DATES_TIMES_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * fn:years-from-duration
 * Author: Zorba Team
 */
class YearsFromDurationIterator : public NaryBaseIterator<YearsFromDurationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(YearsFromDurationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(YearsFromDurationIterator,
    NaryBaseIterator<YearsFromDurationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<YearsFromDurationIterator, PlanIteratorState>*)this);
  }

  YearsFromDurationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<YearsFromDurationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~YearsFromDurationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:months-from-duration
 * Author: Zorba Team
 */
class MonthsFromDurationIterator : public NaryBaseIterator<MonthsFromDurationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MonthsFromDurationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MonthsFromDurationIterator,
    NaryBaseIterator<MonthsFromDurationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MonthsFromDurationIterator, PlanIteratorState>*)this);
  }

  MonthsFromDurationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MonthsFromDurationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MonthsFromDurationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:days-from-duration
 * Author: Zorba Team
 */
class DaysFromDurationIterator : public NaryBaseIterator<DaysFromDurationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DaysFromDurationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DaysFromDurationIterator,
    NaryBaseIterator<DaysFromDurationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DaysFromDurationIterator, PlanIteratorState>*)this);
  }

  DaysFromDurationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DaysFromDurationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DaysFromDurationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:hours-from-duration
 * Author: Zorba Team
 */
class HoursFromDurationIterator : public NaryBaseIterator<HoursFromDurationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(HoursFromDurationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HoursFromDurationIterator,
    NaryBaseIterator<HoursFromDurationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<HoursFromDurationIterator, PlanIteratorState>*)this);
  }

  HoursFromDurationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<HoursFromDurationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~HoursFromDurationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:minutes-from-duration
 * Author: Zorba Team
 */
class MinutesFromDurationIterator : public NaryBaseIterator<MinutesFromDurationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MinutesFromDurationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MinutesFromDurationIterator,
    NaryBaseIterator<MinutesFromDurationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MinutesFromDurationIterator, PlanIteratorState>*)this);
  }

  MinutesFromDurationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MinutesFromDurationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MinutesFromDurationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:seconds-from-duration
 * Author: Zorba Team
 */
class SecondsFromDurationIterator : public NaryBaseIterator<SecondsFromDurationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SecondsFromDurationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SecondsFromDurationIterator,
    NaryBaseIterator<SecondsFromDurationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SecondsFromDurationIterator, PlanIteratorState>*)this);
  }

  SecondsFromDurationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SecondsFromDurationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SecondsFromDurationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:year-from-dateTime
 * Author: Zorba Team
 */
class YearFromDatetimeIterator : public NaryBaseIterator<YearFromDatetimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(YearFromDatetimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(YearFromDatetimeIterator,
    NaryBaseIterator<YearFromDatetimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<YearFromDatetimeIterator, PlanIteratorState>*)this);
  }

  YearFromDatetimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<YearFromDatetimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~YearFromDatetimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:month-from-dateTime
 * Author: Zorba Team
 */
class MonthFromDatetimeIterator : public NaryBaseIterator<MonthFromDatetimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MonthFromDatetimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MonthFromDatetimeIterator,
    NaryBaseIterator<MonthFromDatetimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MonthFromDatetimeIterator, PlanIteratorState>*)this);
  }

  MonthFromDatetimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MonthFromDatetimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MonthFromDatetimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:day-from-dateTime
 * Author: Zorba Team
 */
class DayFromDatetimeIterator : public NaryBaseIterator<DayFromDatetimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DayFromDatetimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DayFromDatetimeIterator,
    NaryBaseIterator<DayFromDatetimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DayFromDatetimeIterator, PlanIteratorState>*)this);
  }

  DayFromDatetimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DayFromDatetimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DayFromDatetimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:hours-from-dateTime
 * Author: Zorba Team
 */
class HoursFromDatetimeIterator : public NaryBaseIterator<HoursFromDatetimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(HoursFromDatetimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HoursFromDatetimeIterator,
    NaryBaseIterator<HoursFromDatetimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<HoursFromDatetimeIterator, PlanIteratorState>*)this);
  }

  HoursFromDatetimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<HoursFromDatetimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~HoursFromDatetimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:minutes-from-dateTime
 * Author: Zorba Team
 */
class MinutesFromDatetimeIterator : public NaryBaseIterator<MinutesFromDatetimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MinutesFromDatetimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MinutesFromDatetimeIterator,
    NaryBaseIterator<MinutesFromDatetimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MinutesFromDatetimeIterator, PlanIteratorState>*)this);
  }

  MinutesFromDatetimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MinutesFromDatetimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MinutesFromDatetimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:seconds-from-dateTime
 * Author: Zorba Team
 */
class SecondsFromDatetimeIterator : public NaryBaseIterator<SecondsFromDatetimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SecondsFromDatetimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SecondsFromDatetimeIterator,
    NaryBaseIterator<SecondsFromDatetimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SecondsFromDatetimeIterator, PlanIteratorState>*)this);
  }

  SecondsFromDatetimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SecondsFromDatetimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SecondsFromDatetimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:timezone-from-dateTime
 * Author: Zorba Team
 */
class TimezoneFromDatetimeIterator : public NaryBaseIterator<TimezoneFromDatetimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TimezoneFromDatetimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TimezoneFromDatetimeIterator,
    NaryBaseIterator<TimezoneFromDatetimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<TimezoneFromDatetimeIterator, PlanIteratorState>*)this);
  }

  TimezoneFromDatetimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<TimezoneFromDatetimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~TimezoneFromDatetimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:year-from-date
 * Author: Zorba Team
 */
class YearFromDateIterator : public NaryBaseIterator<YearFromDateIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(YearFromDateIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(YearFromDateIterator,
    NaryBaseIterator<YearFromDateIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<YearFromDateIterator, PlanIteratorState>*)this);
  }

  YearFromDateIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<YearFromDateIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~YearFromDateIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:month-from-date
 * Author: Zorba Team
 */
class MonthFromDateIterator : public NaryBaseIterator<MonthFromDateIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MonthFromDateIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MonthFromDateIterator,
    NaryBaseIterator<MonthFromDateIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MonthFromDateIterator, PlanIteratorState>*)this);
  }

  MonthFromDateIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MonthFromDateIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MonthFromDateIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:day-from-date
 * Author: Zorba Team
 */
class DayFromDateIterator : public NaryBaseIterator<DayFromDateIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DayFromDateIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DayFromDateIterator,
    NaryBaseIterator<DayFromDateIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DayFromDateIterator, PlanIteratorState>*)this);
  }

  DayFromDateIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DayFromDateIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DayFromDateIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:timezone-from-date
 * Author: Zorba Team
 */
class TimezoneFromDateIterator : public NaryBaseIterator<TimezoneFromDateIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TimezoneFromDateIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TimezoneFromDateIterator,
    NaryBaseIterator<TimezoneFromDateIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<TimezoneFromDateIterator, PlanIteratorState>*)this);
  }

  TimezoneFromDateIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<TimezoneFromDateIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~TimezoneFromDateIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:hours-from-time
 * Author: Zorba Team
 */
class HoursFromTimeIterator : public NaryBaseIterator<HoursFromTimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(HoursFromTimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HoursFromTimeIterator,
    NaryBaseIterator<HoursFromTimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<HoursFromTimeIterator, PlanIteratorState>*)this);
  }

  HoursFromTimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<HoursFromTimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~HoursFromTimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:minutes-from-time
 * Author: Zorba Team
 */
class MinutesFromTimeIterator : public NaryBaseIterator<MinutesFromTimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MinutesFromTimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MinutesFromTimeIterator,
    NaryBaseIterator<MinutesFromTimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MinutesFromTimeIterator, PlanIteratorState>*)this);
  }

  MinutesFromTimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MinutesFromTimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MinutesFromTimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:seconds-from-time
 * Author: Zorba Team
 */
class SecondsFromTimeIterator : public NaryBaseIterator<SecondsFromTimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SecondsFromTimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SecondsFromTimeIterator,
    NaryBaseIterator<SecondsFromTimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SecondsFromTimeIterator, PlanIteratorState>*)this);
  }

  SecondsFromTimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SecondsFromTimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SecondsFromTimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:timezone-from-time
 * Author: Zorba Team
 */
class TimezoneFromTimeIterator : public NaryBaseIterator<TimezoneFromTimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(TimezoneFromTimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TimezoneFromTimeIterator,
    NaryBaseIterator<TimezoneFromTimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<TimezoneFromTimeIterator, PlanIteratorState>*)this);
  }

  TimezoneFromTimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<TimezoneFromTimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~TimezoneFromTimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
