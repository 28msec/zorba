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

// </TimezoneFromTimeIterator>



}


