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
#if defined (WIN32)
  struct _timeb timebuffer;
  _ftime_s( &timebuffer );
  localtime_s(&gmtm, &timebuffer.time); //thread safe localtime on Windows
#else
  struct timeb timebuffer;
  ftime( &timebuffer );
  localtime_r(&timebuffer.time, &gmtm); //thread safe localtime on Linux
#endif

  int lSummerTimeShift = 0;
  if (gmtm.tm_isdst != 0)
    lSummerTimeShift = 3600;

  timezone = -timebuffer.timezone * 60 + lSummerTimeShift; // in seconds
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
      gmtm.tm_year + 1900, gmtm.tm_mon + 1, gmtm.tm_mday, gmtm.tm_hour,
      gmtm.tm_min, gmtm.tm_sec + lMilliTm/1000.0, lTimezone/3600);

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
      gmtm.tm_year + 1900, gmtm.tm_mon + 1, gmtm.tm_mday);

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
      gmtm.tm_hour, gmtm.tm_min, gmtm.tm_sec + lMilliTm/1000.0, lTimezone/3600);

  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lDateTime));
}

/******************************************************************************
 *****************************************************************************/
zorba::StatelessExternalFunction*
DateTimeModule::getExternalFunction(zorba::String aLocalname) const
{
  zorba::StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (aLocalname.equals("current-dateTime")) {
      lFunc = new CurrentDateTimeFunction(this);
    } else if (aLocalname.equals("current-date")) {
      lFunc = new CurrentDateFunction(this);
    } else if (aLocalname.equals("current-time")) {
      lFunc = new CurrentTimeFunction(this);
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
