#ifndef ZORBA_REPRESENTATIONS_H
#define ZORBA_REPRESENTATIONS_H

#include <zorbatypes/xqpstring.h>
#include <zorbatypes/duration.h>
#include <zorbatypes/date.h>
#include <zorbatypes/datetime.h>
#include <zorbatypes/zorba_time.h>
#include <zorbatypes/gregorian.h>
#include <zorbatypes/integer.h>
#include <zorbatypes/decimal.h>
#include <zorbatypes/floatimpl.h>

namespace zorba
{
  /*______________________________________________________________________
  |
  | The mapping of basic schema types to C++ language types.
  |_______________________________________________________________________*/
  typedef xqpString           xqp_anyURI;
  typedef xqpString           xqp_string;
  typedef xqpString           xqp_normalizedString;
  typedef xqpString           xqp_token;
  typedef xqpString           xqp_language;
  typedef xqpString           xqp_Name;
  typedef xqpString           xqp_NCName;
  typedef xqpString           xqp_ID;
  typedef xqpString           xqp_IDREF;
  typedef xqpString           xqp_IDREFS;
  typedef xqpString           xqp_ENTITY;
  typedef xqpString           xqp_ENTITIES;
  typedef xqpString           xqp_NMTOKEN;
  typedef xqpString           xqp_NMTOKENS;
  typedef Integer             xqp_integer;
  typedef int32_t             xqp_int;
  typedef long long           xqp_long;
  typedef short               xqp_short;
  typedef Decimal             xqp_decimal;
  typedef Float               xqp_float;
  typedef Double              xqp_double;
  typedef char                xqp_byte;
  typedef bool                xqp_boolean;
  typedef xqpString           xqp_QName;
  typedef xqpString           xqp_NOTATION;
  typedef DateTime_t          xqp_dateTime;
  typedef Date_t              xqp_date;
  typedef Time_t              xqp_time;
  typedef GYearMonth_t        xqp_gYearMonth;
  typedef GYear_t             xqp_gYear;
  typedef GMonthDay_t         xqp_gMonthDay;
  typedef GDay_t              xqp_gDay;
  typedef GMonth_t            xqp_gMonth;
  typedef DurationBase_t      xqp_duration;
  typedef DayTimeDuration_t   xqp_dayTimeDuration;
  typedef YearMonthDuration_t xqp_yearMonthDuration;
  typedef unsigned char       xqp_ubyte;
  typedef uint32_t            xqp_uint;
  typedef unsigned long long  xqp_ulong;
  typedef unsigned short      xqp_ushort;
  typedef Integer             xqp_uinteger;
  typedef void*               xqp_base64Binary;
  typedef void*               xqp_base64Binary;
  typedef void*               xqp_hexBinary;

} /* namespace zorba */
#endif /* ZORBA_REPRESENTATIONS_H */
