#ifndef ZORBA_DATETIME_H
#define ZORBA_DATETIME_H

#include "zorbatypes/timezone.h"
#include "zorbatypes/duration.h"
#include "util/rchandle.h"

namespace zorba
{
  
  class DateTime;
  typedef rchandle<DateTime> DateTime_t;
  
  class InvalidTimezoneException : public std::exception
  {
  };
  

  class DateTime : public SimpleRCObject
  {
    public:
      virtual ~DateTime() { };
      
      /**
       *  Returns 0 on success
       */
      static int 
      parseDateTime(const xqpString& s, DateTime_t& dt_t);
      
      /**
       *  Returns 0 on success
       */
      static int
      parseDate(const xqpString& s, DateTime_t& dt_t);
      
      /**
       *  Returns 0 on success
       */
      static int
      parseTime(const xqpString& s, DateTime_t& dt_t);
      
      /**
       *  Returns 0 on success
       */
      static int 
      parseGYearMonth(const xqpString& s, DateTime_t& dt_t);

      /**
       *  Returns 0 on success
       */
      static int 
      parseGYear(const xqpString& s, DateTime_t& dt_t);

      /**
       *  Returns 0 on success
       */
      static int 
      parseGMonth(const xqpString& s, DateTime_t& dt_t);

      /**
       *  Returns 0 on success
       */
      static int 
      parseGMonthDay(const xqpString& s, DateTime_t& dt_t);

      /**
       *  Returns 0 on success
       */
      static int 
      parseGDay(const xqpString& s, DateTime_t& dt_t);
      
      /**
       *  Returns 0 on success
       *  Returns 2 if both the Date and the Time have a timezone, and they differ (FORG0008)
       */
      static int
      createDateTime(const DateTime_t& date_t, const DateTime_t& time_t, DateTime_t& result_t);
      
      /**
       *  The function will use the absolute values of all int parameters except years. No TimeZone.
       */
      static int
      createDateTime(int years, int months, int days,
                     int hours, int minutes, int seconds, int fractional_seconds, DateTime_t& dt_t);
      
      /**
       *  The function will use the absolute values of all int parameters except years. TimeZone may be NULL
       */
      static int
      createDateTime(int years, int months, int days,
                     int hours, int minutes, int seconds, int fractional_seconds,
                     TimeZone_t& tz_t, DateTime_t& dt_t);

      /**
       *  The function will use the absolute values of all int parameters except years. TimeZone is a reference
       */
      static int
      createDateTime(int years, int months, int days,
                         int hours, int minutes, int seconds, int fractional_seconds,
                         const TimeZone& tz, DateTime_t& dt_t);

      /**
       *  Throws InvalidTimezoneException if the given timezone is not valid.
       */
      DurationBase_t
      subtractDateTime(const DateTime& dt, int implicit_timezone_seconds) const;
      
      DateTime_t 
      addDuration(const Duration& d, bool adjust_facet = true) const;
      
      DateTime_t 
      subtractDuration(const Duration& d, bool adjust_facet = true) const;
      
      /**
       *  Returns -1 if the DateTime is less than the given DateTime
       *  Returns 0 if the DateTimes are equal
       *  Returns 1 if the DateTime is greater than the given DateTime
       *
       *  Throws InvalidTimezoneException if the given timezone is not valid.
       *
       */
      int 
      compare(const DateTime& dt, int timezone_seconds) const;

      xqpString 
      toString() const;
      
      DateTime_t
      getDate() const;

      DateTime_t
      getTime() const;
      
      int 
      getYear() const;
      
      int 
      getMonth() const;
      int 
      getDay() const;
      
      int 
      getHours() const;
      
      int 
      getMinutes() const;
      
      double 
      getSeconds() const;
      
      TimeZone
      getTimezone() const;
      
      /**
       *  Throws InvalidTimezoneException if the given timezone is not valid.
       */
      DateTime_t normalizeTimeZone(int tz_seconds) const;
      
      /**
       *  Throws InvalidTimezoneException if the given timezone is not valid.
       */
      DateTime_t adjustToTimeZone(int tz_seconds) const;
      
      /**
       *  Throws InvalidTimezoneException if the given timezone is not valid.
       */
      DateTime_t adjustToTimeZone(const DurationBase_t& db_t) const;
      
    public:
      typedef enum {
        DATETIME_FACET = 0,
        DATE_FACET = 1,
        TIME_FACET = 2,
        GYEARMONTH_FACET = 3,
        GYEAR_FACET = 4,
        GMONTH_FACET = 5,
        GMONTHDAY_FACET = 6,
        GDAY_FACET = 7        
      } FACET_TYPE;

      // fractional seconds have 6 digits. 0.1 seconds are represented as 100000, 0.01 seconds as 10000, etc.
      static const int FRAC_SECONDS_UPPER_LIMIT; // = 1000000, maximum 6 digits
      
      
      FACET_TYPE getFacet() const { return facet; };
      
      
    protected:
      DurationBase_t toDayTimeDuration() const;
      DateTime();
      DateTime& operator=(const DateTime_t& dt_t);
      void adjustToFacet();
      void setFacet(FACET_TYPE a_facet);
      static int parse_date(std::string& ss, unsigned int& position, int& year, int& month, int& day);
      static int parse_time(std::string& ss, unsigned int& position, int& hour, int& minute, int& seconds, int& frac_seconds);
      
      // Only year may be negative, all other must be positive
      // The year gives the sign of DateTime, Date, etc
      
      typedef enum {
        YEAR_DATA = 0,
        MONTH_DATA = 1,
        DAY_DATA = 2,
        HOUR_DATA = 3,
        MINUTE_DATA = 4,
        SECONDS_DATA = 5,
        FRACSECONDS_DATA = 6
      } DATA_TYPE;
      
      FACET_TYPE facet;
      int data[7];
      
      TimeZone the_time_zone;
  };

} /* namespace xqp */

#endif
