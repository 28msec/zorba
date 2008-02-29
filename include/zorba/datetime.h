#ifndef ZORBA_DATETIME_H
#define ZORBA_DATETIME_H

// TODO can we remove boost includes from headers?
//      otherwise a user would need development header for writing
//      his apps
#include <boost/date_time/posix_time/posix_time.hpp>

#include <zorba/timezone.h>

namespace xqp
{

  class DateTime : public SimpleRCObject
  {
    public:
      virtual ~DateTime() { };

      DateTime(bool negative, boost::posix_time::ptime t) : is_negative(negative), the_date_time(t) { };
      DateTime(const Date_t& d_t, const Time_t& t_t);

      /**
       *  Returns 0 on success
       */
      static int 
      parse_string(const xqpString& s, DateTime_t& dt_t);

      /**
       *  The function will use the absolute values of all int parameters. TimeZone may be NULL
       */
      static int 
      createDateTime(bool is_negative, int years, int months, int days,
                     int hours, int minutes, int seconds, int fractional_seconds,
                     TimeZone_t& tz_t, DateTime_t& dt_t);

      /**
       *  The function will use the absolute values of all int parameters. TimeZone is a reference
       */
      static int 
      createDateTime(bool is_negative, int years, int months, int days,
                     int hours, int minutes, int seconds, int fractional_seconds,
                     const TimeZone& tz, DateTime_t& dt_t);

      bool 
      operator<(const DateTime& dt) const;
      
      bool 
      operator==(const DateTime& dt) const;

      DayTimeDuration_t
      operator-(const DateTime& dt) const;
      
      int 
      compare(const DateTime& dt) const;

      xqpString 
      toString() const;

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

      Date_t
      getDate() const;

      Time_t
      getTime() const;

    protected:
      DateTime& 
      operator=(const DateTime_t& dt_t);

      bool 
      is_negative;
      
      boost::posix_time::ptime the_date_time; 
      TimeZone                 the_time_zone; 
  };

  DateTime_t operator+(const DateTime& dt, const Duration& d);

} /* namespace xqp */

#endif
