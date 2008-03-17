#ifndef ZORBA_DATETIME_H
#define ZORBA_DATETIME_H

// TODO can we remove boost includes from headers?
//      otherwise a user would need development header for writing
//      his apps
#include <boost/date_time/posix_time/posix_time.hpp>
#include <zorbatypes/timezone.h>
#include <zorbatypes/duration.h>

#include <zorba/rchandle.h>

namespace zorba
{
  
  class DateTime;
  typedef rchandle<DateTime> DateTime_t;

  class DateTime : public SimpleRCObject
  {
    public:
      virtual ~DateTime() { };

      DateTime(boost::posix_time::ptime t); // TODO: remove/rewrite this function
      DateTime(const Date_t& d_t, const Time_t& t_t);
      
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

      bool 
      operator<(const DateTime& dt) const;
      
      bool 
      operator==(const DateTime& dt) const;

      DurationBase_t
      operator-(const DateTime& dt) const;
      
      int 
      compare(const DateTime& dt) const;

      xqpString 
      toString() const;
      
      Date_t
      getDate() const;

      Time_t
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
      
      DateTime_t
      normalize(const long tz_seconds);

      DateTime_t normalizeTimeZone(int tz_seconds) const;
      DateTime_t normalizeTimeZone() const;
      DateTime_t adjustToTimeZone(int tz_seconds) const;
      DateTime_t adjustToTimeZone(const DurationBase_t& db_t) const;
      
      static const int FRAC_SECONDS_UPPER_LIMIT; // = 1000000, maximum 6 digits

  protected:
      DurationBase_t toDayTimeDuration() const;
      DateTime();
      DateTime& operator=(const DateTime_t& dt_t);
      static int parse_date(std::string& ss, unsigned int& position, int& year, int& month, int& day);
      static int parse_time(std::string& ss, unsigned int& position, int& hour, int& minute, int& seconds, int& frac_seconds);
      
      // fractional seconds have 6 digits. 0.1 seconds are represented as 100000, 0.01 seconds as 10000, etc.
      // Only year may be negative, all other must be positive
      
      typedef enum {
        YEAR_DATA = 0,
        MONTH_DATA = 1,
        DAY_DATA = 2,
        HOUR_DATA = 3,
        MINUTE_DATA = 4,
        SECONDS_DATA = 5,
        FRACSECONDS_DATA = 6
      } DATA_TYPE;
      
      typedef enum {
        DATETIME_FACET = 0,
        DATE_FACET,
        TIME_FACET
        // TODO
      } FACET_TYPE;
      
      FACET_TYPE facet;
      int data[7];
      
      TimeZone                 the_time_zone;
  };

  DateTime_t operator+(const DateTime& dt, const Duration& d);
  DateTime_t operator-(const DateTime& dt, const Duration& d);

} /* namespace xqp */

#endif
