/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#include "stdafx.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/durations_dates_times/durations_dates_times.h"
#include "system/globalenv.h"



namespace zorba {

// <YearsFromDurationIterator>
SERIALIZABLE_CLASS_VERSIONS(YearsFromDurationIterator)

void YearsFromDurationIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<YearsFromDurationIterator, PlanIteratorState>*)this);
}


void YearsFromDurationIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

YearsFromDurationIterator::~YearsFromDurationIterator() {}


zstring YearsFromDurationIterator::getNameAsString() const {
  return "fn:years-from-duration";
}
// </YearsFromDurationIterator>


// <MonthsFromDurationIterator>
SERIALIZABLE_CLASS_VERSIONS(MonthsFromDurationIterator)

void MonthsFromDurationIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MonthsFromDurationIterator, PlanIteratorState>*)this);
}


void MonthsFromDurationIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MonthsFromDurationIterator::~MonthsFromDurationIterator() {}


zstring MonthsFromDurationIterator::getNameAsString() const {
  return "fn:months-from-duration";
}
// </MonthsFromDurationIterator>


// <DaysFromDurationIterator>
SERIALIZABLE_CLASS_VERSIONS(DaysFromDurationIterator)

void DaysFromDurationIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DaysFromDurationIterator, PlanIteratorState>*)this);
}


void DaysFromDurationIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DaysFromDurationIterator::~DaysFromDurationIterator() {}


zstring DaysFromDurationIterator::getNameAsString() const {
  return "fn:days-from-duration";
}
// </DaysFromDurationIterator>


// <HoursFromDurationIterator>
SERIALIZABLE_CLASS_VERSIONS(HoursFromDurationIterator)

void HoursFromDurationIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<HoursFromDurationIterator, PlanIteratorState>*)this);
}


void HoursFromDurationIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

HoursFromDurationIterator::~HoursFromDurationIterator() {}


zstring HoursFromDurationIterator::getNameAsString() const {
  return "fn:hours-from-duration";
}
// </HoursFromDurationIterator>


// <MinutesFromDurationIterator>
SERIALIZABLE_CLASS_VERSIONS(MinutesFromDurationIterator)

void MinutesFromDurationIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MinutesFromDurationIterator, PlanIteratorState>*)this);
}


void MinutesFromDurationIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MinutesFromDurationIterator::~MinutesFromDurationIterator() {}


zstring MinutesFromDurationIterator::getNameAsString() const {
  return "fn:minutes-from-duration";
}
// </MinutesFromDurationIterator>


// <SecondsFromDurationIterator>
SERIALIZABLE_CLASS_VERSIONS(SecondsFromDurationIterator)

void SecondsFromDurationIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SecondsFromDurationIterator, PlanIteratorState>*)this);
}


void SecondsFromDurationIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SecondsFromDurationIterator::~SecondsFromDurationIterator() {}


zstring SecondsFromDurationIterator::getNameAsString() const {
  return "fn:seconds-from-duration";
}
// </SecondsFromDurationIterator>


// <YearFromDatetimeIterator>
SERIALIZABLE_CLASS_VERSIONS(YearFromDatetimeIterator)

void YearFromDatetimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<YearFromDatetimeIterator, PlanIteratorState>*)this);
}


void YearFromDatetimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

YearFromDatetimeIterator::~YearFromDatetimeIterator() {}


zstring YearFromDatetimeIterator::getNameAsString() const {
  return "fn:year-from-dateTime";
}
// </YearFromDatetimeIterator>


// <MonthFromDatetimeIterator>
SERIALIZABLE_CLASS_VERSIONS(MonthFromDatetimeIterator)

void MonthFromDatetimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MonthFromDatetimeIterator, PlanIteratorState>*)this);
}


void MonthFromDatetimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MonthFromDatetimeIterator::~MonthFromDatetimeIterator() {}


zstring MonthFromDatetimeIterator::getNameAsString() const {
  return "fn:month-from-dateTime";
}
// </MonthFromDatetimeIterator>


// <DayFromDatetimeIterator>
SERIALIZABLE_CLASS_VERSIONS(DayFromDatetimeIterator)

void DayFromDatetimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DayFromDatetimeIterator, PlanIteratorState>*)this);
}


void DayFromDatetimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DayFromDatetimeIterator::~DayFromDatetimeIterator() {}


zstring DayFromDatetimeIterator::getNameAsString() const {
  return "fn:day-from-dateTime";
}
// </DayFromDatetimeIterator>


// <HoursFromDatetimeIterator>
SERIALIZABLE_CLASS_VERSIONS(HoursFromDatetimeIterator)

void HoursFromDatetimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<HoursFromDatetimeIterator, PlanIteratorState>*)this);
}


void HoursFromDatetimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

HoursFromDatetimeIterator::~HoursFromDatetimeIterator() {}


zstring HoursFromDatetimeIterator::getNameAsString() const {
  return "fn:hours-from-dateTime";
}
// </HoursFromDatetimeIterator>


// <MinutesFromDatetimeIterator>
SERIALIZABLE_CLASS_VERSIONS(MinutesFromDatetimeIterator)

void MinutesFromDatetimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MinutesFromDatetimeIterator, PlanIteratorState>*)this);
}


void MinutesFromDatetimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MinutesFromDatetimeIterator::~MinutesFromDatetimeIterator() {}


zstring MinutesFromDatetimeIterator::getNameAsString() const {
  return "fn:minutes-from-dateTime";
}
// </MinutesFromDatetimeIterator>


// <SecondsFromDatetimeIterator>
SERIALIZABLE_CLASS_VERSIONS(SecondsFromDatetimeIterator)

void SecondsFromDatetimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SecondsFromDatetimeIterator, PlanIteratorState>*)this);
}


void SecondsFromDatetimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SecondsFromDatetimeIterator::~SecondsFromDatetimeIterator() {}


zstring SecondsFromDatetimeIterator::getNameAsString() const {
  return "fn:seconds-from-dateTime";
}
// </SecondsFromDatetimeIterator>


// <TimezoneFromDatetimeIterator>
SERIALIZABLE_CLASS_VERSIONS(TimezoneFromDatetimeIterator)

void TimezoneFromDatetimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TimezoneFromDatetimeIterator, PlanIteratorState>*)this);
}


void TimezoneFromDatetimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TimezoneFromDatetimeIterator::~TimezoneFromDatetimeIterator() {}


zstring TimezoneFromDatetimeIterator::getNameAsString() const {
  return "fn:timezone-from-dateTime";
}
// </TimezoneFromDatetimeIterator>


// <YearFromDateIterator>
SERIALIZABLE_CLASS_VERSIONS(YearFromDateIterator)

void YearFromDateIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<YearFromDateIterator, PlanIteratorState>*)this);
}


void YearFromDateIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

YearFromDateIterator::~YearFromDateIterator() {}


zstring YearFromDateIterator::getNameAsString() const {
  return "fn:year-from-date";
}
// </YearFromDateIterator>


// <MonthFromDateIterator>
SERIALIZABLE_CLASS_VERSIONS(MonthFromDateIterator)

void MonthFromDateIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MonthFromDateIterator, PlanIteratorState>*)this);
}


void MonthFromDateIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MonthFromDateIterator::~MonthFromDateIterator() {}


zstring MonthFromDateIterator::getNameAsString() const {
  return "fn:month-from-date";
}
// </MonthFromDateIterator>


// <DayFromDateIterator>
SERIALIZABLE_CLASS_VERSIONS(DayFromDateIterator)

void DayFromDateIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DayFromDateIterator, PlanIteratorState>*)this);
}


void DayFromDateIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DayFromDateIterator::~DayFromDateIterator() {}


zstring DayFromDateIterator::getNameAsString() const {
  return "fn:day-from-date";
}
// </DayFromDateIterator>


// <TimezoneFromDateIterator>
SERIALIZABLE_CLASS_VERSIONS(TimezoneFromDateIterator)

void TimezoneFromDateIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TimezoneFromDateIterator, PlanIteratorState>*)this);
}


void TimezoneFromDateIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TimezoneFromDateIterator::~TimezoneFromDateIterator() {}


zstring TimezoneFromDateIterator::getNameAsString() const {
  return "fn:timezone-from-date";
}
// </TimezoneFromDateIterator>


// <HoursFromTimeIterator>
SERIALIZABLE_CLASS_VERSIONS(HoursFromTimeIterator)

void HoursFromTimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<HoursFromTimeIterator, PlanIteratorState>*)this);
}


void HoursFromTimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

HoursFromTimeIterator::~HoursFromTimeIterator() {}


zstring HoursFromTimeIterator::getNameAsString() const {
  return "fn:hours-from-time";
}
// </HoursFromTimeIterator>


// <MinutesFromTimeIterator>
SERIALIZABLE_CLASS_VERSIONS(MinutesFromTimeIterator)

void MinutesFromTimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MinutesFromTimeIterator, PlanIteratorState>*)this);
}


void MinutesFromTimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MinutesFromTimeIterator::~MinutesFromTimeIterator() {}


zstring MinutesFromTimeIterator::getNameAsString() const {
  return "fn:minutes-from-time";
}
// </MinutesFromTimeIterator>


// <SecondsFromTimeIterator>
SERIALIZABLE_CLASS_VERSIONS(SecondsFromTimeIterator)

void SecondsFromTimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SecondsFromTimeIterator, PlanIteratorState>*)this);
}


void SecondsFromTimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SecondsFromTimeIterator::~SecondsFromTimeIterator() {}


zstring SecondsFromTimeIterator::getNameAsString() const {
  return "fn:seconds-from-time";
}
// </SecondsFromTimeIterator>


// <TimezoneFromTimeIterator>
SERIALIZABLE_CLASS_VERSIONS(TimezoneFromTimeIterator)

void TimezoneFromTimeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<TimezoneFromTimeIterator, PlanIteratorState>*)this);
}


void TimezoneFromTimeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

TimezoneFromTimeIterator::~TimezoneFromTimeIterator() {}


zstring TimezoneFromTimeIterator::getNameAsString() const {
  return "fn:timezone-from-time";
}
// </TimezoneFromTimeIterator>



}


