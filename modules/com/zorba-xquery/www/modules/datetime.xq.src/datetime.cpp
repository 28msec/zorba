/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#include "datetime.h"

#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>

#include <time.h>
#include <sys/timeb.h>
#ifdef UNIX
#include <sys/time.h>
#endif

namespace zorba { namespace datetimemodule {

void
compute_date_time(
    struct ::tm&    gmtm,
    long&           timezone,
    unsigned short& millitm)
{
  int lSummerTimeShift = 0;
#if defined (WIN32)
  struct _timeb timebuffer;
  _ftime_s( &timebuffer );
  localtime_s(&gmtm, &timebuffer.time); //thread safe localtime on Windows
  lSummerTimeShift = -timebuffer.timezone * 60;
  if (gmtm.tm_isdst != 0)
    lSummerTimeShift += 3600;
#else
  struct timeb timebuffer;
  ftime( &timebuffer );
  localtime_r(&timebuffer.time, &gmtm); //thread safe localtime on Linux
  localtime_r(&timebuffer.time, &gmtm); //thread safe localtime on Linux
  lSummerTimeShift = gmtm.tm_gmtoff;
#endif

  timezone = lSummerTimeShift; // in seconds
  millitm = timebuffer.millitm;
}

/******************************************************************************
 *****************************************************************************/
zorba::ItemSequence_t
CurrentDateTimeFunction::evaluate(
  const Arguments_t& aArgs,
  const zorba::StaticContext* aSctx,
  const zorba::DynamicContext* aDctx) const
{
  struct ::tm    gmtm;
  long           lTimezone;
  unsigned short lMilliTm;

  compute_date_time(gmtm, lTimezone, lMilliTm);

  zorba::Item lDateTime = 
    Zorba::getInstance(0)->getItemFactory()->createDateTime(
      static_cast<short>(gmtm.tm_year + 1900),
      static_cast<short>(gmtm.tm_mon + 1),
      static_cast<short>(gmtm.tm_mday),
      static_cast<short>(gmtm.tm_hour),
      static_cast<short>(gmtm.tm_min),
      gmtm.tm_sec + lMilliTm/1000.0,
      static_cast<short>(lTimezone/3600)
    );

  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lDateTime));
}

/******************************************************************************
 *****************************************************************************/
zorba::ItemSequence_t
CurrentDateFunction::evaluate(
  const Arguments_t& aArgs,
  const zorba::StaticContext* aSctx,
  const zorba::DynamicContext* aDctx) const
{
  struct ::tm    gmtm;
  long           lTimezone;
  unsigned short lMilliTm;

  compute_date_time(gmtm, lTimezone, lMilliTm);

  zorba::Item lDateTime = 
    Zorba::getInstance(0)->getItemFactory()->createDate(
      static_cast<short>(gmtm.tm_year + 1900),
      static_cast<short>(gmtm.tm_mon + 1),
      static_cast<short>(gmtm.tm_mday)
    );

  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lDateTime));
}

/******************************************************************************
 *****************************************************************************/
zorba::ItemSequence_t
CurrentTimeFunction::evaluate(
  const Arguments_t& aArgs,
  const zorba::StaticContext* aSctx,
  const zorba::DynamicContext* aDctx) const
{
  struct ::tm    gmtm;
  long           lTimezone;
  unsigned short lMilliTm;

  compute_date_time(gmtm, lTimezone, lMilliTm);

  zorba::Item lDateTime = 
    Zorba::getInstance(0)->getItemFactory()->createTime(
      static_cast<short>(gmtm.tm_hour),
      static_cast<short>(gmtm.tm_min),
      gmtm.tm_sec + lMilliTm/1000.0,
      static_cast<short>(lTimezone/3600)
    );

  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lDateTime));
}

/******************************************************************************
 *****************************************************************************/

zorba::ItemSequence_t
TimestampFunction::evaluate(
  const Arguments_t& aArgs,
  const zorba::StaticContext* aSctx,
  const zorba::DynamicContext* aDctx) const
{
  zorba::Item lMillis;
#if WIN32
  time_t t0;
  time(&t0);
  lMillis = Zorba::getInstance(0)->getItemFactory()->createLong(t0*1000);
#else
  timeval tv;
  gettimeofday(&tv, 0);
  long long millis = tv.tv_sec;
  millis = millis * 1000 + tv.tv_usec/1000;
  lMillis = Zorba::getInstance(0)->getItemFactory()->createLong(millis);
#endif

  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lMillis));
}

/******************************************************************************
 *****************************************************************************/
zorba::ExternalFunction*
DateTimeModule::getExternalFunction(const zorba::String& aLocalname)
{
  zorba::ExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (aLocalname == "current-dateTime") {
      lFunc = new CurrentDateTimeFunction(this);
    } else if (aLocalname == "current-date") {
      lFunc = new CurrentDateFunction(this);
    } else if (aLocalname == "current-time") {
      lFunc = new CurrentTimeFunction(this);
    } else if (aLocalname == "timestamp") {
      lFunc = new TimestampFunction(this);
    }
  }
  return lFunc;
}

/******************************************************************************
 *****************************************************************************/
DateTimeModule::~DateTimeModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
  }
  theFunctions.clear();
}

/******************************************************************************
 *****************************************************************************/
void
DateTimeModule::destroy()
{
  if (!dynamic_cast<DateTimeModule*>(this)) {
    return;
  }
  delete this;
}

} /* namespace datetimemodule */ } /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::datetimemodule::DateTimeModule();
}
