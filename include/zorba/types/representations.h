/**
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Sorin Nasoi (sorin.nasoi@ipdevel.ro), David Graf (david.graf@28msec.com)
 *
 */

#ifndef XQP_REPRESENTATIONS_H
#define XQP_REPRESENTATIONS_H

#include "util/utf8/xqpString.h"
#include "util/datetime/duration.h"
#include "util/datetime/date.h"
#include "util/datetime/datetime.h"
#include "util/datetime/time.h"

namespace xqp
{
  /*______________________________________________________________________
  |
  | The mapping of basic schema types to C++ language types.
  |_______________________________________________________________________*/

  typedef xqpString                 xqp_anyURI;
  typedef xqpString                 xqp_string;
  typedef xqpString                 xqp_normalizedString;
  typedef xqpString                 xqp_token;
  typedef xqpString                 xqp_language;
  typedef xqpString                 xqp_Name;
  typedef xqpString                 xqp_NCName;
  typedef xqpString                 xqp_ID;
  typedef xqpString                 xqp_IDREF;
  typedef xqpString                 xqp_IDREFS;
  typedef xqpString                 xqp_ENTITY;
  typedef xqpString                 xqp_ENTITIES;
  typedef xqpString                 xqp_NMTOKEN;
  typedef xqpString                 xqp_NMTOKENS;
  typedef long long                 xqp_integer;
  typedef int32_t                   xqp_int;
  typedef long                      xqp_long;
  typedef short                     xqp_short;
  typedef long double               xqp_decimal;
  typedef float                     xqp_float;
  typedef double                    xqp_double;
  typedef char                      xqp_byte;
  typedef bool                      xqp_boolean;
  typedef xqpString                 xqp_QName;
  typedef xqpString                 xqp_NOTATION;
  typedef DateTime_t                xqp_dateTime;
  typedef Date_t                    xqp_date;
  typedef Time_t                    xqp_time;
  typedef struct tm                 xqp_gYearMonth;
  typedef struct tm                 xqp_gYear;
  typedef struct tm                 xqp_gMonthDay;
  typedef struct tm                 xqp_gDay;
  typedef struct tm                 xqp_gMonth;
  typedef Duration_t                xqp_duration;
  typedef unsigned char             xqp_ubyte;
  typedef uint32_t                  xqp_uint;
  typedef unsigned long             xqp_ulong;
  typedef unsigned short            xqp_ushort;
  typedef unsigned long long        xqp_uinteger;
  typedef void*                     xqp_base64Binary;
  typedef void*                     xqp_base64Binary;
  typedef void*                     xqp_hexBinary;

  
  /*______________________________________________________________________
  |
  | Additional Mappings
  |_______________________________________________________________________*/
  
  typedef uint64_t qnamekey_t;


} /* namespace xqp */
#endif /* XQP_REPRESENTATIONS_H */
/* vim:set ts=2 sw=2: */
