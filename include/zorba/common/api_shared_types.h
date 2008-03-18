#ifndef ZORBA_SHARED_TYPES_INCL_H
#define ZORBA_SHARED_TYPES_INCL_H

#include <zorba/rchandle.h>

namespace zorba {

  // TODO put xqpString here

  namespace store {
    class Item;
    typedef rchandle<store::Item> Item_t;
    class ItemSequence;
    typedef rchandle<ItemSequence>              ItemSequence_t;
    class XmlDataManager;
    typedef rchandle<XmlDataManager> XmlDataManager_t;
  }

  class Iterator;
  typedef rchandle<Iterator> Iterator_t;

  /* numerics */
  template <class Object> class FloatImpl;
  class Integer;

  /* stuff needed for the external functions */
  class StatelessExternalFunction;

  /* datetime stuff */
  class DateTime;
  class DayTimeDuration;
  class Decimal;
  class Duration;
  class TimeZone;
  class YearMonthDuration;
  class GYearMonth;
  class GYear;
  class GMonthDay;
  class GDay;
  class GMonth;
  class ResultIterator;
  typedef rchandle<ResultIterator>		        ResultIterator_t;

  /* context stuff */
  class DynamicQueryContext;
  class StaticQueryContext;

  /* Error stuff */
  class AlertList;
  class ZorbaAlertsManager;
  class ZorbaError;

  /* numerics */
  typedef FloatImpl<double> Double;
  typedef FloatImpl<float>  Float;

  /* stuff needed for the external functions */
  typedef rchandle<StatelessExternalFunction> StatelessExternalFunction_t;

  /* datetime stuff */
  typedef rchandle<DateTime> DateTime_t;
  typedef rchandle<TimeZone> TimeZone_t;
  typedef rchandle<DayTimeDuration> DayTimeDuration_t;
  typedef rchandle<YearMonthDuration> YearMonthDuration_t;
  typedef rchandle<Duration> Duration_t;
  typedef rchandle<GYearMonth> GYearMonth_t;
  typedef rchandle<GYear> GYear_t;
  typedef rchandle<GMonthDay> GMonthDay_t;
  typedef rchandle<GDay> GDay_t;
  typedef rchandle<GMonth> GMonth_t;

  /* context stuff */
  typedef rchandle<DynamicQueryContext> DynamicQueryContext_t;
  typedef rchandle<StaticQueryContext>  StaticQueryContext_t;

  /* query and result stuff */
  class XQuery;
  class XQueryTreePlans;
  typedef rchandle<XQuery> XQuery_t;
  typedef rchandle<XQueryTreePlans> XQueryTreePlans_t;

  class ResultIterator;
  typedef rchandle<ResultIterator> ResultIterator_t;
    
  /* Error stuff */
  typedef rchandle<AlertList>		AlertList_t;
  typedef rchandle<ZorbaAlertsManager>		ZorbaAlertsManager_t;
  typedef rchandle<ZorbaError> ZorbaError_t;
} /* namespace zorba */
#endif
