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

#include "stdafx.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/durations_dates_times/durations_dates_times.h"
#include "system/globalenv.h"



namespace zorba {

// <YearsFromDurationIterator>
YearsFromDurationIterator::class_factory<YearsFromDurationIterator>
YearsFromDurationIterator::g_class_factory;


void YearsFromDurationIterator::accept(PlanIterVisitor& v) const {
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
MonthsFromDurationIterator::class_factory<MonthsFromDurationIterator>
MonthsFromDurationIterator::g_class_factory;


void MonthsFromDurationIterator::accept(PlanIterVisitor& v) const {
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
DaysFromDurationIterator::class_factory<DaysFromDurationIterator>
DaysFromDurationIterator::g_class_factory;


void DaysFromDurationIterator::accept(PlanIterVisitor& v) const {
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
HoursFromDurationIterator::class_factory<HoursFromDurationIterator>
HoursFromDurationIterator::g_class_factory;


void HoursFromDurationIterator::accept(PlanIterVisitor& v) const {
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
MinutesFromDurationIterator::class_factory<MinutesFromDurationIterator>
MinutesFromDurationIterator::g_class_factory;


void MinutesFromDurationIterator::accept(PlanIterVisitor& v) const {
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
SecondsFromDurationIterator::class_factory<SecondsFromDurationIterator>
SecondsFromDurationIterator::g_class_factory;


void SecondsFromDurationIterator::accept(PlanIterVisitor& v) const {
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
YearFromDatetimeIterator::class_factory<YearFromDatetimeIterator>
YearFromDatetimeIterator::g_class_factory;


void YearFromDatetimeIterator::accept(PlanIterVisitor& v) const {
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
MonthFromDatetimeIterator::class_factory<MonthFromDatetimeIterator>
MonthFromDatetimeIterator::g_class_factory;


void MonthFromDatetimeIterator::accept(PlanIterVisitor& v) const {
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
DayFromDatetimeIterator::class_factory<DayFromDatetimeIterator>
DayFromDatetimeIterator::g_class_factory;


void DayFromDatetimeIterator::accept(PlanIterVisitor& v) const {
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
HoursFromDatetimeIterator::class_factory<HoursFromDatetimeIterator>
HoursFromDatetimeIterator::g_class_factory;


void HoursFromDatetimeIterator::accept(PlanIterVisitor& v) const {
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
MinutesFromDatetimeIterator::class_factory<MinutesFromDatetimeIterator>
MinutesFromDatetimeIterator::g_class_factory;


void MinutesFromDatetimeIterator::accept(PlanIterVisitor& v) const {
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
SecondsFromDatetimeIterator::class_factory<SecondsFromDatetimeIterator>
SecondsFromDatetimeIterator::g_class_factory;


void SecondsFromDatetimeIterator::accept(PlanIterVisitor& v) const {
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
TimezoneFromDatetimeIterator::class_factory<TimezoneFromDatetimeIterator>
TimezoneFromDatetimeIterator::g_class_factory;


void TimezoneFromDatetimeIterator::accept(PlanIterVisitor& v) const {
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
YearFromDateIterator::class_factory<YearFromDateIterator>
YearFromDateIterator::g_class_factory;


void YearFromDateIterator::accept(PlanIterVisitor& v) const {
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
MonthFromDateIterator::class_factory<MonthFromDateIterator>
MonthFromDateIterator::g_class_factory;


void MonthFromDateIterator::accept(PlanIterVisitor& v) const {
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
DayFromDateIterator::class_factory<DayFromDateIterator>
DayFromDateIterator::g_class_factory;


void DayFromDateIterator::accept(PlanIterVisitor& v) const {
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
TimezoneFromDateIterator::class_factory<TimezoneFromDateIterator>
TimezoneFromDateIterator::g_class_factory;


void TimezoneFromDateIterator::accept(PlanIterVisitor& v) const {
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
HoursFromTimeIterator::class_factory<HoursFromTimeIterator>
HoursFromTimeIterator::g_class_factory;


void HoursFromTimeIterator::accept(PlanIterVisitor& v) const {
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
MinutesFromTimeIterator::class_factory<MinutesFromTimeIterator>
MinutesFromTimeIterator::g_class_factory;


void MinutesFromTimeIterator::accept(PlanIterVisitor& v) const {
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
SecondsFromTimeIterator::class_factory<SecondsFromTimeIterator>
SecondsFromTimeIterator::g_class_factory;


void SecondsFromTimeIterator::accept(PlanIterVisitor& v) const {
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
TimezoneFromTimeIterator::class_factory<TimezoneFromTimeIterator>
TimezoneFromTimeIterator::g_class_factory;


void TimezoneFromTimeIterator::accept(PlanIterVisitor& v) const {
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


