#ifndef ZORBA_TIMEZONE_H
#define ZORBA_TIMEZONE_H

// TODO remove boost here
#include <boost/date_time/posix_time/posix_time.hpp>
#include <zorba/common/api_shared_types.h>
#include <zorba/xqpstring.h>

namespace xqp
{

  class TimeZone : public SimpleRCObject
  {
    public:
      virtual ~TimeZone() { };

      TimeZone() : the_time_zone(boost::posix_time::not_a_date_time) { };
      TimeZone(boost::posix_time::time_duration t) : the_time_zone(t) { };
      TimeZone(short hours);

      static bool
      parse_string(const xqpString& s, TimeZone_t& tz_t);

      /**
       *  Returns 0 on success.
       */
      static int
      createTimeZone(int hours, int minutes, int seconds, TimeZone_t& tz_t);

      bool
      operator<(const TimeZone& t) const;
      
      bool
      operator==(const TimeZone& t) const;
      
      int
      compare(const TimeZone& t) const;

      xqpString
      toString() const;

      virtual bool
      is_negative() const;

      virtual bool
      is_not_a_date_time() const;

      virtual long
      getHours() const;

      virtual long
      getMinutes() const;

      virtual long
      getSeconds() const;

      virtual long
      getFractionalSeconds() const;


    protected:
      TimeZone& operator=(const TimeZone_t& t_t);

      boost::posix_time::time_duration the_time_zone;
  };

} /* namespace xqp */
#endif
