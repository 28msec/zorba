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
const char* YearsFromDurationIterator::class_name_str = "YearsFromDurationIterator";
YearsFromDurationIterator::class_factory<YearsFromDurationIterator>
YearsFromDurationIterator::g_class_factory;

const serialization::ClassVersion 
YearsFromDurationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int YearsFromDurationIterator::class_versions_count =
sizeof(YearsFromDurationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MonthsFromDurationIterator::class_name_str = "MonthsFromDurationIterator";
MonthsFromDurationIterator::class_factory<MonthsFromDurationIterator>
MonthsFromDurationIterator::g_class_factory;

const serialization::ClassVersion 
MonthsFromDurationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MonthsFromDurationIterator::class_versions_count =
sizeof(MonthsFromDurationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* DaysFromDurationIterator::class_name_str = "DaysFromDurationIterator";
DaysFromDurationIterator::class_factory<DaysFromDurationIterator>
DaysFromDurationIterator::g_class_factory;

const serialization::ClassVersion 
DaysFromDurationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DaysFromDurationIterator::class_versions_count =
sizeof(DaysFromDurationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* HoursFromDurationIterator::class_name_str = "HoursFromDurationIterator";
HoursFromDurationIterator::class_factory<HoursFromDurationIterator>
HoursFromDurationIterator::g_class_factory;

const serialization::ClassVersion 
HoursFromDurationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int HoursFromDurationIterator::class_versions_count =
sizeof(HoursFromDurationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MinutesFromDurationIterator::class_name_str = "MinutesFromDurationIterator";
MinutesFromDurationIterator::class_factory<MinutesFromDurationIterator>
MinutesFromDurationIterator::g_class_factory;

const serialization::ClassVersion 
MinutesFromDurationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MinutesFromDurationIterator::class_versions_count =
sizeof(MinutesFromDurationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* SecondsFromDurationIterator::class_name_str = "SecondsFromDurationIterator";
SecondsFromDurationIterator::class_factory<SecondsFromDurationIterator>
SecondsFromDurationIterator::g_class_factory;

const serialization::ClassVersion 
SecondsFromDurationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SecondsFromDurationIterator::class_versions_count =
sizeof(SecondsFromDurationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* YearFromDatetimeIterator::class_name_str = "YearFromDatetimeIterator";
YearFromDatetimeIterator::class_factory<YearFromDatetimeIterator>
YearFromDatetimeIterator::g_class_factory;

const serialization::ClassVersion 
YearFromDatetimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int YearFromDatetimeIterator::class_versions_count =
sizeof(YearFromDatetimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MonthFromDatetimeIterator::class_name_str = "MonthFromDatetimeIterator";
MonthFromDatetimeIterator::class_factory<MonthFromDatetimeIterator>
MonthFromDatetimeIterator::g_class_factory;

const serialization::ClassVersion 
MonthFromDatetimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MonthFromDatetimeIterator::class_versions_count =
sizeof(MonthFromDatetimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* DayFromDatetimeIterator::class_name_str = "DayFromDatetimeIterator";
DayFromDatetimeIterator::class_factory<DayFromDatetimeIterator>
DayFromDatetimeIterator::g_class_factory;

const serialization::ClassVersion 
DayFromDatetimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DayFromDatetimeIterator::class_versions_count =
sizeof(DayFromDatetimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* HoursFromDatetimeIterator::class_name_str = "HoursFromDatetimeIterator";
HoursFromDatetimeIterator::class_factory<HoursFromDatetimeIterator>
HoursFromDatetimeIterator::g_class_factory;

const serialization::ClassVersion 
HoursFromDatetimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int HoursFromDatetimeIterator::class_versions_count =
sizeof(HoursFromDatetimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MinutesFromDatetimeIterator::class_name_str = "MinutesFromDatetimeIterator";
MinutesFromDatetimeIterator::class_factory<MinutesFromDatetimeIterator>
MinutesFromDatetimeIterator::g_class_factory;

const serialization::ClassVersion 
MinutesFromDatetimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MinutesFromDatetimeIterator::class_versions_count =
sizeof(MinutesFromDatetimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* SecondsFromDatetimeIterator::class_name_str = "SecondsFromDatetimeIterator";
SecondsFromDatetimeIterator::class_factory<SecondsFromDatetimeIterator>
SecondsFromDatetimeIterator::g_class_factory;

const serialization::ClassVersion 
SecondsFromDatetimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SecondsFromDatetimeIterator::class_versions_count =
sizeof(SecondsFromDatetimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* TimezoneFromDatetimeIterator::class_name_str = "TimezoneFromDatetimeIterator";
TimezoneFromDatetimeIterator::class_factory<TimezoneFromDatetimeIterator>
TimezoneFromDatetimeIterator::g_class_factory;

const serialization::ClassVersion 
TimezoneFromDatetimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int TimezoneFromDatetimeIterator::class_versions_count =
sizeof(TimezoneFromDatetimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* YearFromDateIterator::class_name_str = "YearFromDateIterator";
YearFromDateIterator::class_factory<YearFromDateIterator>
YearFromDateIterator::g_class_factory;

const serialization::ClassVersion 
YearFromDateIterator::class_versions[] ={{ 1, 0x000905, false}};

const int YearFromDateIterator::class_versions_count =
sizeof(YearFromDateIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MonthFromDateIterator::class_name_str = "MonthFromDateIterator";
MonthFromDateIterator::class_factory<MonthFromDateIterator>
MonthFromDateIterator::g_class_factory;

const serialization::ClassVersion 
MonthFromDateIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MonthFromDateIterator::class_versions_count =
sizeof(MonthFromDateIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* DayFromDateIterator::class_name_str = "DayFromDateIterator";
DayFromDateIterator::class_factory<DayFromDateIterator>
DayFromDateIterator::g_class_factory;

const serialization::ClassVersion 
DayFromDateIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DayFromDateIterator::class_versions_count =
sizeof(DayFromDateIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* TimezoneFromDateIterator::class_name_str = "TimezoneFromDateIterator";
TimezoneFromDateIterator::class_factory<TimezoneFromDateIterator>
TimezoneFromDateIterator::g_class_factory;

const serialization::ClassVersion 
TimezoneFromDateIterator::class_versions[] ={{ 1, 0x000905, false}};

const int TimezoneFromDateIterator::class_versions_count =
sizeof(TimezoneFromDateIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* HoursFromTimeIterator::class_name_str = "HoursFromTimeIterator";
HoursFromTimeIterator::class_factory<HoursFromTimeIterator>
HoursFromTimeIterator::g_class_factory;

const serialization::ClassVersion 
HoursFromTimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int HoursFromTimeIterator::class_versions_count =
sizeof(HoursFromTimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MinutesFromTimeIterator::class_name_str = "MinutesFromTimeIterator";
MinutesFromTimeIterator::class_factory<MinutesFromTimeIterator>
MinutesFromTimeIterator::g_class_factory;

const serialization::ClassVersion 
MinutesFromTimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MinutesFromTimeIterator::class_versions_count =
sizeof(MinutesFromTimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* SecondsFromTimeIterator::class_name_str = "SecondsFromTimeIterator";
SecondsFromTimeIterator::class_factory<SecondsFromTimeIterator>
SecondsFromTimeIterator::g_class_factory;

const serialization::ClassVersion 
SecondsFromTimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SecondsFromTimeIterator::class_versions_count =
sizeof(SecondsFromTimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* TimezoneFromTimeIterator::class_name_str = "TimezoneFromTimeIterator";
TimezoneFromTimeIterator::class_factory<TimezoneFromTimeIterator>
TimezoneFromTimeIterator::g_class_factory;

const serialization::ClassVersion 
TimezoneFromTimeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int TimezoneFromTimeIterator::class_versions_count =
sizeof(TimezoneFromTimeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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


