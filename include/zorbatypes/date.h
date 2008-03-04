#ifndef ZORBA_DATE_H
#define ZORBA_DATE_H

// TODO can we remove boost includes from headers?
//      otherwise a user would need development header for writing
//      his apps
#include <boost/date_time/gregorian/gregorian.hpp>

#include <zorbatypes/timezone.h>

namespace zorba
{

  /**
   *  date has the form: '-'? yyyy '-' mm '-' dd zzzzzz?
   *
   */
  class Date : public SimpleRCObject
  {
    public:
      virtual ~Date() { };

      /**
       *  Returns 0 on success
       */
      static int 
      parse_string(const xqpString& s, Date_t& d_t);

      /**
       *  Returns 0 on success
       */
      static int 
      createDate(int a_year, int a_month, int a_day, Date_t& d_t);

      /**
       *  Returns 0 on success
       */
      static int 
      createDate(int a_year, int a_month, int a_day, const TimeZone& tz, Date_t& d_t);

      bool 
      operator<(const Date& d) const;
      
      bool
      operator==(const Date& d) const;

      int
      compare(const Date& d) const;

      DateTime_t 
      toDateTime() const;
      
      xqpString 
      toString() const;

      int 
      getYear() const;
      
      int 
      getMonth() const;
      
      int 
      getDay() const;
      
      TimeZone 
      getTimezone() const;

      DateTime_t
      normalize(const long tz_seconds);

    protected:
      Date() : year(1), month(1), day(1) { };
      
      Date& 
      operator=(const Date_t& d_t);

      int year; // the year carries the sign of the date, year may not be 0
      int month;
      int day;

      TimeZone the_time_zone;
  };

  Date_t 
  operator+(const Date& d, const Duration& dur);

} /* namespace zorba */

#endif
