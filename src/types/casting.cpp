/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#include "stdafx.h"

#include <vector>

#include "zorbatypes/numconversions.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/chartype.h"
#include "zorbatypes/URI.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"

#include "context/namespace_context.h"

#include "system/globalenv.h"

#include "store/api/item_factory.h"
#include "store/api/item.h"
#include "store/api/store.h"

#include "types/typeops.h"
#include "types/typemanagerimpl.h"
#include "types/schema/schema.h"
#include "types/casting.h"

#include "context/static_context.h"

#include "compiler/parser/query_loc.h"


namespace zorba
{

void castToUserDefinedType(
    store::Item_t& result,
    const store::Item_t& aItem,
    const XQType* aSourceType,
    const XQType* aTargetType,
    const QueryLoc& loc);


#define ATOMIC_TYPE(type) \
  GENV_TYPESYSTEM.create_atomic_type(TypeConstants::XS_##type, TypeConstants::QUANT_ONE)

#define ATOMIC_CODE_T \
  TypeConstants::atomic_type_code_t


struct ErrorInfo
{
  const XQType* theSourceType;
  const XQType* theTargetType;
};


#define TYPE_EXCEPTION( ERROR_CODE, ERROR_INFO ) \
  XQUERY_EXCEPTION( ERROR_CODE, ERROR_PARAMS( *(ERROR_INFO).theSourceType, ZED( NoCastTo_34o ), *(ERROR_INFO).theTargetType ) )


/*******************************************************************************
  Identity casting functions: target type is the same as the source one, so no
  casting is actually done.
********************************************************************************/
#define SAME_S_AND_T(type)          \
inline bool type##_##type(          \
    store::Item_t& result,          \
    const store::Item* aItem,       \
    zstring& strval,                \
    store::ItemFactory*,            \
    namespace_context *nsCtx,       \
    const ErrorInfo& aErrorInfo)    \
{                                   \
  result = (aItem);                 \
  return true;                      \
}                                   \

SAME_S_AND_T(uA)
SAME_S_AND_T(str)
SAME_S_AND_T(flt)
SAME_S_AND_T(dbl)
SAME_S_AND_T(dec)
SAME_S_AND_T(int)
SAME_S_AND_T(dur)
SAME_S_AND_T(yMD)
SAME_S_AND_T(dTD)
SAME_S_AND_T(dT)
SAME_S_AND_T(tim)
SAME_S_AND_T(dat)
SAME_S_AND_T(gYM)
SAME_S_AND_T(gYr)
SAME_S_AND_T(gMD)
SAME_S_AND_T(gDay)
SAME_S_AND_T(gMon)
SAME_S_AND_T(bool)
SAME_S_AND_T(b64)
SAME_S_AND_T(hxB)
SAME_S_AND_T(aURI)
SAME_S_AND_T(QN)
SAME_S_AND_T(NOT)
SAME_S_AND_T(uint)

#undef SAME_S_AND_T


#define T1_TO_T2(type1, type2)      \
inline bool type1##_##type2(        \
    store::Item_t& result,          \
    const store::Item* aItem,       \
    zstring& strval,                \
    store::ItemFactory* aFactory,   \
    namespace_context* nsCtx,       \
    const ErrorInfo& aErrorInfo)    \



T1_TO_T2(str, uA)
{
  return aFactory->createUntypedAtomic(result, strval);
}


T1_TO_T2(str, flt)
{
  try {
    xs_float const n(strval.c_str());
    return aFactory->createFloat(result, n);
  }
  catch ( std::invalid_argument const& ) {
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
  }
  catch ( std::range_error const& ) {
    throw XQUERY_EXCEPTION( err::FOAR0002, ERROR_PARAMS( strval ) );
  }
}


T1_TO_T2(str, dbl)
{
  try {
    xs_double const n(strval.c_str());
    return aFactory->createDouble(result, n);
  }
  catch ( std::invalid_argument const& ) {
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
  }
  catch ( std::range_error const& ) {
    throw XQUERY_EXCEPTION( err::FOAR0002, ERROR_PARAMS( strval ) );
  }
}


T1_TO_T2(str, dec)
{
  try {
    xs_decimal const n(strval.c_str());
    return aFactory->createDecimal(result, n);
  }
  catch ( std::exception const& ) {
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
  }
}


T1_TO_T2(str, int)
{
  try {
    xs_integer const n(strval.c_str());
    return aFactory->createInteger(result, n);
  }
  catch ( std::invalid_argument const& ) {
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
  }
  catch ( std::range_error const& ) {
    throw TYPE_EXCEPTION( err::FOAR0002, aErrorInfo );
  }
}


T1_TO_T2(str, dur)
{
  Duration d;
  int err;

  if (0 == (err = Duration::parseDuration(strval.c_str(), strval.size(), d)))
    return aFactory->createDuration(result, &d);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, yMD)
{
  Duration d;
  int err;

  if (0 == (err = Duration::parseYearMonthDuration(strval.c_str(), strval.size(), d)))
    return aFactory->createYearMonthDuration(result, &d);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, dTD)
{
  Duration d;
  int err;

  if (0 == (err = Duration::parseDayTimeDuration(strval.c_str(), strval.size(), d)))
    return aFactory->createDayTimeDuration(result, &d);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, dT)
{
  xs_dateTime dt;
  if (0 == DateTime::parseDateTime(strval.c_str(), strval.size(), dt))
    return aFactory->createDateTime(result, &dt);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, tim)
{
  xs_time t;
  if (0 == DateTime::parseTime(strval.c_str(), strval.size(), t))
    return aFactory->createTime(result, &t);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, dat)
{
  xs_date d;
  if (0 == DateTime::parseDate(strval.c_str(), strval.size(), d))
    return aFactory->createDate(result, &d);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, gYM)
{
  xs_gYearMonth ym;
  if (0 == DateTime::parseGYearMonth(strval.c_str(), strval.size(), ym))
    return aFactory->createGYearMonth(result, &ym);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, gYr)
{
  xs_gYear y;
  if (0 == DateTime::parseGYear(strval.c_str(), strval.size(), y))
    return aFactory->createGYear(result, &y);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, gMD)
{
  xs_gMonthDay md;
  if (0 == DateTime::parseGMonthDay(strval.c_str(), strval.size(), md))
    return aFactory->createGMonthDay(result, &md);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, gDay)
{
  xs_gDay d;
  if (0 == DateTime::parseGDay(strval.c_str(), strval.size(), d))
    return aFactory->createGDay(result, &d);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, gMon)
{
  xs_gMonth m;
  if (0 == DateTime::parseGMonth(strval.c_str(), strval.size(), m))
    return aFactory->createGMonth(result, &m);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, bool)
{
  bool lRetValue = true;
  const char* str = strval.c_str();
  zstring::size_type len = strval.size();
  zstring::size_type pos = 0;

  ascii::skip_whitespace(str, len, &pos);

  str += pos;

  if (strncmp(str, "false", 5) == 0)
  {
    lRetValue = false;
    str += 5;
  }
  else if (strncmp(str, "0", 1) == 0)
  {
    lRetValue = false;
    str += 1;
  }
  else if (strncmp(str, "true", 4) == 0)
  {
    lRetValue = true;
    str += 4;
  }
  else if (strncmp(str, "1", 1) == 0)
  {
    lRetValue = true;
    str += 1;
  }
  else
  {
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
  }

  pos = str - strval.c_str();
  ascii::skip_whitespace(strval.c_str(), len, &pos);

  if (pos != len)
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );

  return aFactory->createBoolean(result, lRetValue);
}


T1_TO_T2(str, b64)
{
  xs_base64Binary n;
  if (xs_base64Binary::parseString(strval, n))
    return aFactory->createBase64Binary(result, n);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, hxB)
{
  xs_hexBinary n;
  if (xs_hexBinary::parseString(strval, n))
    return aFactory->createHexBinary(result, n);

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


T1_TO_T2(str, aURI)
{
  try
  {
    URI uriVal(strval);
    zstring resolvedUri = uriVal.toString();
    return aFactory->createAnyURI(result, resolvedUri);
  }
  catch (ZorbaException& e)
  {
    e.set_diagnostic( err::FORG0001 );
    throw;
  }
}


T1_TO_T2(str, QN)
{
  ascii::trim_whitespace(strval);

  zstring::size_type idx = strval.find(":");
  zstring::size_type lidx = strval.rfind(":", strval.size(), 1);

  if (idx != lidx)
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );

  zstring nsuri;
  zstring prefix;
  zstring local;

  if (idx == zstring::npos)
  {
    if (nsCtx)
    {
      nsCtx->findBinding(prefix, nsuri);
    }

    local = strval;
  }
  else
  {
    prefix = strval.substr(0, idx);

    if (!GenericCast::instance()->castableToNCName(prefix))
      throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );

    if (nsCtx)
    {
      if (!nsCtx->findBinding(prefix, nsuri))
        throw XQUERY_EXCEPTION( err::FONS0004, ERROR_PARAMS( prefix ) );
    }

    local = strval.substr(idx + 1);
  }

  if (!GenericCast::instance()->castableToNCName(local))
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );

  return aFactory->createQName(result, nsuri, prefix, local);
}


T1_TO_T2(str, NOT)
{
  ascii::trim_whitespace(strval);

  zstring uri;
  zstring prefix;
  zstring local;

  zstring::size_type pos = strval.rfind(":", strval.size(), 1);
  if (pos != zstring::npos)
  {
    prefix = strval.substr(0, pos);
    local = strval.substr(pos+1, strval.size());
  }
  else
    local = strval;

  if (!nsCtx->findBinding(prefix, uri))
    ZORBA_ERROR_DESC_OSS(err::FORG0001, "Prefix '" << prefix << "' not found in current namespace context.");

  store::Item_t qname;
  aFactory->createQName(qname, uri, prefix, local);
  return aFactory->createNOTATION(result, qname);
}


T1_TO_T2(uA, str)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return aFactory->createString(result, strval2);
}


T1_TO_T2(uA, flt)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_flt(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, dbl)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dbl(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, dec)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dec(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, int)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_int(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, dur)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dur(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, yMD)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_yMD(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, dTD)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dTD(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, dT)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dT(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, tim)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_tim(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, dat)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dat(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, gYM)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gYM(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, gYr)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gYr(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, gMD)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gMD(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, gDay)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gDay(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, gMon)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gMon(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, bool)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_bool(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, b64)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_b64(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, hxB)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_hxB(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uA, aURI)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_aURI(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(flt, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(flt, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(flt, dbl)
{
  return aFactory->createDouble(result, xs_double(aItem->getFloatValue()));
}


T1_TO_T2(flt, dec)
{
  try 
  {
    xs_decimal const n( aItem->getFloatValue() );
    return aFactory->createDecimal(result, n);
  }
  catch ( std::exception const& /*e*/ ) 
  {
    throw TYPE_EXCEPTION( err::FOCA0002, aErrorInfo );
  }
}


T1_TO_T2(flt, int)
{
  try 
  {
    return aFactory->createInteger(result, xs_integer(aItem->getFloatValue()));
  }
  catch ( std::exception const& ) 
  {
    throw TYPE_EXCEPTION( err::FOCA0002, aErrorInfo );
  }
}


T1_TO_T2(flt, bool)
{
  result = aItem->getEBV();
  return true;
}


T1_TO_T2(dbl, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dbl, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dbl, flt)
{
  return aFactory->createFloat(result, xs_float(aItem->getDoubleValue()));
}


T1_TO_T2(dbl, dec)
{
  try 
  {
    xs_decimal const n( aItem->getDoubleValue() );
    return aFactory->createDecimal(result, n);
  }
  catch ( std::exception const& ) 
  {
    throw TYPE_EXCEPTION( err::FOCA0002, aErrorInfo );
  }
}


T1_TO_T2(dbl, int)
{
  try 
  {
    return aFactory->createInteger(result, xs_integer(aItem->getDoubleValue()));
  }
  catch ( std::exception const& ) 
  {
    throw TYPE_EXCEPTION( err::FOCA0002, aErrorInfo );
  }
}


T1_TO_T2(dbl, bool)
{
  result = aItem->getEBV();
  return true;
}


T1_TO_T2(dec, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dec, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dec, flt)
{
  return aFactory->createFloat(result, xs_float(aItem->getDecimalValue()));
}


T1_TO_T2(dec, dbl)
{
  return aFactory->createDouble(result, xs_double(aItem->getDecimalValue()));
}


T1_TO_T2(dec, int)
{
  return aFactory->createInteger(result, xs_integer(aItem->getDecimalValue()));
}


T1_TO_T2(dec, bool)
{
  result = aItem->getEBV();
  return true;
}


T1_TO_T2(int, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(int, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(int, flt)
{
  return aFactory->createFloat(result, xs_float(aItem->getIntegerValue()));
}


T1_TO_T2(int, dbl)
{
  return aFactory->createDouble(result, xs_double(aItem->getIntegerValue()));
}


T1_TO_T2(int, dec)
{
  return aFactory->createDecimal(result,
                                 xs_decimal(aItem->getIntegerValue()));
}


T1_TO_T2(int, bool)
{
  result = aItem->getEBV();
  return true;
}


T1_TO_T2(dur, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dur, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dur, yMD)
{
  std::auto_ptr<Duration> dur =
  std::auto_ptr<Duration>(aItem->getDurationValue().toYearMonthDuration());
  return aFactory->createYearMonthDuration(result, dur.get());
}


T1_TO_T2(dur, dTD)
{
  std::auto_ptr<Duration> dur =
  std::auto_ptr<Duration>(aItem->getDurationValue().toDayTimeDuration());
  return aFactory->createDayTimeDuration(result, dur.get());
}


T1_TO_T2(yMD, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(yMD, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(yMD, dur)
{
  std::auto_ptr<Duration> dur =
  std::auto_ptr<Duration>(aItem->getYearMonthDurationValue().toDuration());
  return aFactory->createDuration(result, dur.get());
}


T1_TO_T2(yMD, dTD)
{
  std::auto_ptr<Duration> dur =
  std::auto_ptr<Duration>(aItem->getYearMonthDurationValue().toDayTimeDuration());
  return aFactory->createDayTimeDuration(result, dur.get());
}


T1_TO_T2(dTD, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dTD, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dTD, dur)
{
  std::auto_ptr<Duration> dur =
  std::auto_ptr<Duration>(aItem->getDayTimeDurationValue().toDuration());
  return aFactory->createDuration(result, dur.get());
}


T1_TO_T2(dTD, yMD)
{
  std::auto_ptr<Duration> dur =
  std::auto_ptr<Duration>(aItem->getDayTimeDurationValue().toYearMonthDuration());
  return aFactory->createYearMonthDuration(result, dur.get());
}


T1_TO_T2(dT, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dT, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dT, tim)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::TIME_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dT, dat)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::DATE_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dT, gYM)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GYEARMONTH_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dT, gYr)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GYEAR_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dT, gMD)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GMONTHDAY_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dT, gDay)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GDAY_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dT, gMon)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GMONTH_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(tim, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(tim, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dat, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dat, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(dat, dT)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::DATETIME_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dat, gYM)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GYEARMONTH_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dat, gYr)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GYEAR_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dat, gMD)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GMONTHDAY_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dat, gDay)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GDAY_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(dat, gMon)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GMONTH_FACET, dt);
  return aFactory->createTime(result, &dt);
}


T1_TO_T2(gYM, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gYM, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gYr, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gYr, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gMD, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gMD, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gDay, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gDay, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gMon, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(gMon, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(bool, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(bool, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(bool, flt)
{
  if (aItem->getBooleanValue())
    return aFactory->createFloat(result, xs_float::one());
  else
    return aFactory->createFloat(result, xs_float::zero());
}


T1_TO_T2(bool, dbl)
{
  if (aItem->getBooleanValue())
    return aFactory->createDouble(result, xs_double::one());
  else
    return aFactory->createDouble(result, xs_double::zero());
}


T1_TO_T2(bool, dec)
{
  if (aItem->getBooleanValue())
    return aFactory->createDecimal(result, xs_decimal::one());
  else
    return aFactory->createDecimal(result, xs_decimal::zero());
}


T1_TO_T2(bool, int)
{
  if (aItem->getBooleanValue())
    return aFactory->createInteger(result, xs_integer::one());
  else
    return aFactory->createInteger(result, xs_integer::zero());
}


T1_TO_T2(b64, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(b64, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(b64, hxB)
{
  return aFactory->createHexBinary(result, xs_hexBinary(aItem->getBase64BinaryValue()));
}


T1_TO_T2(hxB, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(hxB, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(hxB, b64)
{
  return aFactory->createBase64Binary(result,
                                      xs_base64Binary(aItem->getHexBinaryValue()));
}


T1_TO_T2(aURI, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(aURI, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(QN, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(QN, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(NOT, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(NOT, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}

T1_TO_T2(uint, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uint, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(uint, flt)
{
  return aFactory->createFloat(
    result, xs_float(aItem->getUnsignedIntegerValue())
  );
}


T1_TO_T2(uint, dbl)
{
  return aFactory->createDouble(
    result, xs_double(aItem->getUnsignedIntegerValue())
  );
}


T1_TO_T2(uint, dec)
{
  return aFactory->createDecimal(
    result, xs_decimal(aItem->getUnsignedIntegerValue())
  );
}


T1_TO_T2(uint, bool)
{
  result = aItem->getEBV();
  return true;
}


T1_TO_T2(uA, uint)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_int(result, aItem, strval2, aFactory, nsCtx, aErrorInfo);
}


T1_TO_T2(flt, uint)
{
  try 
  {
    xs_nonNegativeInteger const n(aItem->getFloatValue());
    return aFactory->createNonNegativeInteger(result, n);
  }
  catch ( std::exception const& ) 
  {
    throw TYPE_EXCEPTION( err::FOCA0002, aErrorInfo );
  }
}


T1_TO_T2(int, uint)
{
  try 
  {
    xs_nonNegativeInteger const n(aItem->getIntegerValue());
    return aFactory->createNonNegativeInteger(result, n);
  }
  catch ( std::exception const& ) 
  {
    throw TYPE_EXCEPTION( err::FOCA0002, aErrorInfo );
  }
}


T1_TO_T2(uint, int)
{
  try 
  {
    xs_integer const n(aItem->getIntegerValue());
    return aFactory->createInteger(result, n);
  }
  catch ( std::exception const& ) 
  {
    throw TYPE_EXCEPTION( err::FOCA0002, aErrorInfo );
  }
}


T1_TO_T2(dbl, uint)
{
  try 
  {
    xs_nonNegativeInteger const n(aItem->getDoubleValue());
    return aFactory->createInteger(result, n);
  }
  catch ( std::exception const& ) 
  {
    throw TYPE_EXCEPTION( err::FOCA0002, aErrorInfo );
  }
}


T1_TO_T2(dec, uint)
{
  xs_nonNegativeInteger const n(aItem->getDecimalValue());
  return aFactory->createNonNegativeInteger(result, n);
}


T1_TO_T2(bool, uint)
{
  if (aItem->getBooleanValue())
    return aFactory->createNonNegativeInteger(
      result, xs_nonNegativeInteger::one()
    );
  else
    return aFactory->createNonNegativeInteger(
      result, xs_nonNegativeInteger::zero()
    );
}


T1_TO_T2(str, uint)
{
  try {
    xs_nonNegativeInteger const n(strval.c_str());
    return aFactory->createNonNegativeInteger(result, n);
  }
  catch ( std::invalid_argument const& ) {
    throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
  }
  catch ( std::range_error const& ) {
    throw TYPE_EXCEPTION( err::FOAR0002, aErrorInfo );
  }
}

/*******************************************************************************

********************************************************************************/
bool str_down(
    store::Item_t& result,
    const store::Item* aItem,
    RootTypeManager& aTS,
    ATOMIC_CODE_T aTargetAtomicType,
    store::ItemFactory* aFactory,
    const ErrorInfo& aErrorInfo)
{
  zstring strval;
  aItem->getStringValue2(strval);

  switch(aTargetAtomicType)
  {
  case TypeConstants::XS_NORMALIZED_STRING:
  {
    if (GenericCast::instance()->castableToNormalizedString(strval))
      return aFactory->createNormalizedString(result, strval);
    break;
  }
  case TypeConstants::XS_TOKEN:
  {
    if (GenericCast::instance()->castableToToken(strval))
      return aFactory->createToken(result, strval);
    break;
  }
  case TypeConstants::XS_LANGUAGE:
  {
    if (GenericCast::instance()->castableToLanguage(strval))
      return aFactory->createLanguage(result, strval);
    break;
  }
  case TypeConstants::XS_NMTOKEN:
  {
    ascii::trim_whitespace(strval);

    if (GenericCast::instance()->castableToNMToken(strval))
    {
      return aFactory->createNMTOKEN(result, strval);
    }
    break;
  }
  case TypeConstants::XS_NAME:
  {
    ascii::trim_whitespace(strval);

    if (GenericCast::instance()->castableToName(strval))
    {
      return aFactory->createName(result, strval);
    }
    break;
  }
  case TypeConstants::XS_NCNAME:
  {
    ascii::normalize_whitespace(strval);
    ascii::trim_whitespace(strval);

    if (GenericCast::instance()->castableToNCName(strval))
    {
      return aFactory->createNCName(result, strval);
    }
    break;
  }
  case TypeConstants::XS_ID:
  {
    if (GenericCast::instance()->castableToNCName(strval))
      return aFactory->createID(result, strval);
    break;
  }
  case TypeConstants::XS_IDREF:
  {
    if (GenericCast::instance()->castableToNCName(strval))
      return aFactory->createIDREF(result, strval);
    break;
  }
  case TypeConstants::XS_ENTITY:
  {
    if (GenericCast::instance()->castableToNCName(strval))
      return aFactory->createENTITY(result, strval);
    break;
  }
  default:
    ZORBA_ASSERT(false);
  }

  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


/*******************************************************************************

********************************************************************************/
bool int_down(
    store::Item_t& result,
    const store::Item* aItem,
    RootTypeManager& aTS,
    ATOMIC_CODE_T aTargetAtomicType,
    store::ItemFactory* aFactory,
    const ErrorInfo& aErrorInfo)
{
  switch(aTargetAtomicType)
  {
  case TypeConstants::XS_NON_POSITIVE_INTEGER:
  {
    xs_integer const lInteger = aItem->getIntegerValue();
    if (lInteger.sign() <= 0)
      return aFactory->createNonPositiveInteger(result, lInteger);
    break;
  }
  case TypeConstants::XS_NEGATIVE_INTEGER:
  {
    xs_integer const lInteger = aItem->getIntegerValue();
    if (lInteger.sign() < 0)
      return aFactory->createNegativeInteger(result, lInteger);
    break;
  }
  case TypeConstants::XS_LONG:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try {
      xs_long const n = ztd::aton<xs_long>(lString.c_str());
      return aFactory->createLong(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
    break;
  }
  case TypeConstants::XS_INT:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try {
      xs_int const n = ztd::aton<xs_int>(lString.c_str());
      return aFactory->createInt(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
    break;
  }
  case TypeConstants::XS_SHORT:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try {
      xs_short const n = ztd::aton<xs_short>(lString.c_str());
      return aFactory->createShort(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
    break;
  }
  case TypeConstants::XS_BYTE:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try {
      xs_byte const n = ztd::aton<xs_byte>(lString.c_str());
      return aFactory->createByte(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
    break;
  }
  case TypeConstants::XS_NON_NEGATIVE_INTEGER:
  {
    xs_decimal const d = aItem->getDecimalValue();
    if (d.sign() >= 0)
      try {
        xs_nonNegativeInteger const i(d);
        return aFactory->createNonNegativeInteger(result, i);
      }
      catch ( std::exception const& ) {
        // ignore
      }
    break;
  }
  case TypeConstants::XS_UNSIGNED_LONG:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try {
      xs_unsignedLong const n = ztd::aton<xs_unsignedLong>(lString.c_str());
      return aFactory->createUnsignedLong(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
    break;
  }
  case TypeConstants::XS_UNSIGNED_INT:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try {
      xs_unsignedInt const n = ztd::aton<xs_unsignedInt>(lString.c_str());
      return aFactory->createUnsignedInt(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
    break;
  }
  case TypeConstants::XS_UNSIGNED_SHORT:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try {
      xs_unsignedShort const n = ztd::aton<xs_unsignedShort>(lString.c_str());
      return aFactory->createUnsignedShort(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
    break;
  }
  case TypeConstants::XS_UNSIGNED_BYTE:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try {
      xs_unsignedByte const n = ztd::aton<xs_unsignedByte>(lString.c_str());
      return aFactory->createUnsignedByte(result, n);
    }
    catch ( std::exception const& ) {
      // ignore
    }
    break;
  }
  case TypeConstants::XS_POSITIVE_INTEGER:
  {
    xs_positiveInteger const i = aItem->getUnsignedIntegerValue();
    if (i.sign() > 0)
      return aFactory->createPositiveInteger(result, i);
    break;
  }
  default:
    ZORBA_ASSERT (false);
  }
  throw TYPE_EXCEPTION( err::FORG0001, aErrorInfo );
}


/*******************************************************************************
  For each builtin atomic type T, this array maps the typecode of T to an
  index to be used in addessing theCastingMatrix.
********************************************************************************/
const int GenericCast::theMapping[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE] =
{
  -1,  //  0 XS_ANY_ATOMIC
   1,  //  1 XS_STRING
   1,  //  2 XS_NORMALIZED_STRING
   1,  //  3 XS_TOKEN
   1,  //  4 XS_LANGUAGE
   1,  //  5 XS_NMTOKEN
   1,  //  6 XS_NAME
   1,  //  7 XS_NCNAME
   1,  //  8 XS_ID
   1,  //  9 XS_IDREF
   1,  // 10 XS_ENTITY
   0,  // 11 XS_UNTYPED_ATOMIC
   9,  // 12 XS_DATETIME
  11,  // 13 XS_DATE
  10,  // 14 XS_TIME
   6,  // 15 XS_DURATION
   8,  // 16 XS_DT_DURATION
   7,  // 17 XS_YM_DURATION
   2,  // 18 XS_FLOAT
   3,  // 19 XS_DOUBLE
   4,  // 20 XS_DECIMAL
   5,  // 21 XS_INTEGER
   5,  // 22 XS_NON_POSITIVE_INTEGER
   5,  // 23 XS_NEGATIVE_INTEGER
   5,  // 24 XS_LONG
   5,  // 25 XS_INT
   5,  // 26 XS_SHORT
   5,  // 27 XS_BYTE
  23,  // 28 XS_NON_NEGATIVE_INTEGER
  23,  // 29 XS_UNSIGNED_LONG
  23,  // 30 XS_UNSIGNED_INT
  23,  // 31 XS_UNSIGNED_SHORT
  23,  // 32 XS_UNSIGNED_BYTE
  23,  // 33 XS_POSITIVE_INTEGER
  12,  // 34 XS_GYEAR_MONTH
  13,  // 35 XS_GYEAR
  14,  // 36 XS_GMONTH_DAY
  15,  // 37 XS_GDAY
  16,  // 38 XS_GMONTH
  17,  // 39 XS_BOOLEAN
  18,  // 40 XS_BASE64BINARY
  19,  // 41 XS_HEXBINARY
  20,  // 42 XS_ANY_URI
  21,  // 43 XS_QNAME
  22   // 44 XS_NOTATION
};


/*******************************************************************************

********************************************************************************/
const GenericCast::DownCastFunc GenericCast::theDownCastMatrix[24] =
{
/*uA*/    0,
/*str*/   str_down,
/*flt*/   0,
/*dbl*/   0,
/*dec*/   0,
/*int*/   int_down,
/*dur*/   0,
/*yMD*/   0,
/*dTD*/   0,
/*dT*/    0,
/*tim*/   0,
/*dat*/   0,
/*gYM*/   0,
/*gYr*/   0,
/*gMD*/   0,
/*gDay*/  0,
/*gMon*/  0,
/*bool*/  0,
/*b64*/   0,
/*hxB*/   0,
/*aURI*/  0,
/*QN*/    0,
/*NOT*/   0,
/*uint*/  int_down,
};


/*******************************************************************************

********************************************************************************/
const GenericCast::CastFunc GenericCast::theCastMatrix[24][24] =
{
          /*uA*/     /*str*/    /*flt*/    /*dbl*/    /*dec*/    /*int*/    /*dur*/    /*yMD*/    /*dTD*/    /*dT*/
          /*tim*/    /*dat*/    /*gYM*/    /*gYr*/    /*gMD*/    /*gDay*/   /*gMon*/   /*bool*/   /*b64*/    /*hxB*/
          /*aURI*/   /*QN*/     /*NOT*/    /*uint*/

/*uA*/   {&uA_uA,    &uA_str,   &uA_flt,   &uA_dbl,   &uA_dec,   &uA_int,   &uA_dur,   &uA_yMD,   &uA_dTD,   &uA_dT,
          &uA_tim,   &uA_dat,   &uA_gYM,   &uA_gYr,   &uA_gMD,   &uA_gDay,  &uA_gMon,  &uA_bool,  &uA_b64,   &uA_hxB,
          &uA_aURI,  0,         0,         &uA_uint},

/*str*/  {&str_uA,   &str_str,  &str_flt,  &str_dbl,  &str_dec,  &str_int,  &str_dur,  &str_yMD,  &str_dTD,  &str_dT,
          &str_tim,  &str_dat,  &str_gYM,  &str_gYr,  &str_gMD,  &str_gDay, &str_gMon, &str_bool, &str_b64,  &str_hxB,
          &str_aURI, &str_QN,   &str_NOT,  &str_uint},

/*flt*/  {&flt_uA,   &flt_str,  &flt_flt,  &flt_dbl,  &flt_dec,  &flt_int,  0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &flt_bool, 0,         0,
          0,         0,         0,         &flt_uint},

/*dbl*/  {&dbl_uA,   &dbl_str,  &dbl_flt,  &dbl_dbl,  &dbl_dec,  &dbl_int,  0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &dbl_bool, 0,         0,
          0,         0,         0,         &dbl_uint},

/*dec*/  {&dec_uA,   &dec_str,  &dec_flt,  &dec_dbl,  &dec_dec,  &dec_int,  0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &dec_bool, 0,         0,
          0,         0,         0,         &dec_uint},

          /*uA*/     /*str*/    /*flt*/    /*dbl*/    /*dec*/    /*int*/    /*dur*/    /*yMD*/    /*dTD*/    /*dT*/
          /*tim*/    /*dat*/    /*gYM*/    /*gYr*/    /*gMD*/    /*gDay*/   /*gMon*/   /*bool*/   /*b64*/    /*hxB*/
          /*aURI*/   /*QN*/     /*NOT*/    /*uint*/

/*int*/  {&int_uA,   &int_str,  &int_flt,  &int_dbl,  &int_dec,  &int_int,  0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &int_bool, 0,         0,
          0,         0,         0,         &int_uint},

/*dur*/  {&dur_uA,   &dur_str,  0,         0,         0,         0,         &dur_dur,  &dur_yMD,  &dur_dTD,  0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0},

/*yMD*/  {&yMD_uA,   &yMD_str,  0,         0,         0,         0,         &yMD_dur,  &yMD_yMD,  &yMD_dTD,  0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0},

/*dTD*/  {&dTD_uA,   &dTD_str,  0,         0,         0,         0,         &dTD_dur,  &dTD_yMD,  &dTD_dTD,  0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0},

/*dT*/   {&dT_uA,    &dT_str,   0,         0,         0,         0,         0,         0,         0,         &dT_dT,
          &dT_tim,   &dT_dat,   &dT_gYM,   &dT_gYr,   &dT_gMD,   &dT_gDay,  &dT_gMon,  0,         0,         0,
          0,         0,         0,         0},

          /*uA*/     /*str*/    /*flt*/    /*dbl*/    /*dec*/    /*int*/    /*dur*/    /*yMD*/    /*dTD*/    /*dT*/
          /*tim*/    /*dat*/    /*gYM*/    /*gYr*/    /*gMD*/    /*gDay*/   /*gMon*/   /*bool*/   /*b64*/    /*hxB*/
          /*aURI*/   /*QN*/     /*NOT*/    /*uint*/

/*tim*/  {&tim_uA,   &tim_str,  0,         0,         0,         0,         0,         0,         0,         0,
          &tim_tim,  0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0},

/*dat*/  {&dat_uA,   &dat_str,  0,         0,         0,         0,         0,         0,         0,         &dat_dT,
          0,         &dat_dat,  &dat_gYM,  &dat_gYr,  &dat_gMD,  &dat_gDay, &dat_gMon, 0,         0,         0,
          0,         0,         0,         0},

/*gYM*/  {&gYM_uA,   &gYM_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         &gYM_gYM,  0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0},

/*gYr*/  {&gYr_uA,   &gYr_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         &gYr_gYr,  0,         0,         0,         0,         0,         0,
          0,         0,         0,         0},

/*gMD*/  {&gMD_uA,   &gMD_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         &gMD_gMD,  0,         0,         0,         0,         0,
          0,         0,         0,         0},

          /*uA*/     /*str*/    /*flt*/    /*dbl*/    /*dec*/    /*int*/    /*dur*/    /*yMD*/    /*dTD*/    /*dT*/
          /*tim*/    /*dat*/    /*gYM*/    /*gYr*/    /*gMD*/    /*gDay*/   /*gMon*/   /*bool*/   /*b64*/    /*hxB*/
          /*aURI*/   /*QN*/     /*NOT*/    /*uint*/

/*gDay*/ {&gDay_uA,  &gDay_str, 0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         &gDay_gDay,0,         0,         0,         0,
          0,         0,         0,         0},

/*gMon*/ {&gMon_uA,  &gMon_str, 0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         &gMon_gMon,0,         0,         0,
          0,         0,         0,         0},

/*bool*/ {&bool_uA,  &bool_str, &bool_flt, &bool_dbl, &bool_dec, &bool_int, 0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &bool_bool,0,         0,
          0,         0,         0,         &bool_uint},

/*b64*/  {&b64_uA,   &b64_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         &b64_b64,  &b64_hxB,
          0,         0,         0,         0},

/*hxB*/  {&hxB_uA,   &hxB_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         &hxB_b64,  &hxB_hxB,
          0,         0,         0,         0},

          /*uA*/     /*str*/    /*flt*/    /*dbl*/    /*dec*/    /*int*/    /*dur*/    /*yMD*/    /*dTD*/    /*dT*/
          /*tim*/    /*dat*/    /*gYM*/    /*gYr*/    /*gMD*/    /*gDay*/   /*gMon*/   /*bool*/   /*b64*/    /*hxB*/
          /*aURI*/   /*QN*/     /*NOT*/    /*uint*/

/*aURI*/ {&aURI_uA,  &aURI_str, 0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          &aURI_aURI,0,         0,         0},

/*QN*/   {&QN_uA,    &QN_str,   0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         &QN_QN,    0,         0},

/*NOT*/  {&NOT_uA,   &NOT_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         &NOT_NOT,  0},

/*uint*/ {&uint_uA,  &uint_str, &uint_flt, &uint_dbl, &uint_dec, &uint_int, 0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &uint_bool,0,         0,
          0,         0,         0,         &uint_uint},
};



/*******************************************************************************

********************************************************************************/
GenericCast* GenericCast::instance()
{
  static GenericCast aGenericCast;
  return &aGenericCast;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::castToAtomic(
    store::Item_t& result,
    zstring& str,
    const XQType* aTargetType,
    const TypeManager* tm,
    namespace_context* aNsCtx,
    const QueryLoc& loc)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;
  store::ItemFactory* lFactory = GENV_ITEMFACTORY;

  const XQType* sourceType = rtm.STRING_TYPE_ONE.getp();

  ErrorInfo lErrorInfo = {&*sourceType, aTargetType};

  if (!TypeOps::is_atomic(tm, *aTargetType))
    throw XQUERY_EXCEPTION( err::XPST0051, ERROR_PARAMS( aTargetType ) );

#ifndef ZORBA_NO_XMLSCHEMA
  if (aTargetType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    store::Item_t baseItem;

    bool success = tm->getSchema()->parseUserAtomicTypes(str,
                                                         aTargetType,
                                                         baseItem,
                                                         aNsCtx,
                                                         loc);
    if (success)
    {
      const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(aTargetType);
      store::Item_t typeName = udt->get_qname();

      GENV_ITEMFACTORY->createUserTypedAtomicItem(result, baseItem, typeName);
      return true;
    }

    return false;
  }
#endif

  store::Item_t lItem;
  ATOMIC_CODE_T sourceTypeCode = TypeConstants::XS_STRING;
  ATOMIC_CODE_T targetTypeCode = TypeOps::get_atomic_type_code(*aTargetType);
  bool valid = true;

  if (theMapping[sourceTypeCode] == theMapping[targetTypeCode])
  {
    lFactory->createString(result, str);
  }
  else
  {
    CastFunc lCastFunc = theCastMatrix[theMapping[sourceTypeCode]]
                                      [theMapping[targetTypeCode]];
    if (lCastFunc == 0)
      throw TYPE_EXCEPTION( err::XPTY0004, lErrorInfo );

    valid = (*lCastFunc)(result,
                         lItem,
                         str,
                         lFactory,
                         aNsCtx,
                         lErrorInfo);
  }

  DownCastFunc lDownCastFunc = theDownCastMatrix[theMapping[targetTypeCode]];

  if (lDownCastFunc != 0 &&
      targetTypeCode != TypeConstants::XS_STRING &&
      targetTypeCode != TypeConstants::XS_INTEGER)
  {
    valid = (*lDownCastFunc)(result,
                             &*result,
                             rtm,
                             targetTypeCode,
                             lFactory,
                             lErrorInfo);
  }

  return valid;
}


/*******************************************************************************
  Cast, if possible, a given item SI to an atomic item TI of a given type TT.
  If I1 is not
********************************************************************************/
bool GenericCast::castToAtomic(
    store::Item_t&       result,
    store::Item_t&       aItem,
    const XQType*        aTargetType,
    const TypeManager*   tm,
    namespace_context*   aNCtx,
    const QueryLoc&      loc)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;
  store::ItemFactory* lFactory = GENV_ITEMFACTORY;

  xqtref_t lSourceType = tm->create_named_type(aItem->getType(),
                                               TypeConstants::QUANT_ONE,
                                               QueryLoc::null,
                                               err::XPTY0004);

  ZORBA_ASSERT(aItem->isAtomic());
  ZORBA_ASSERT(lSourceType != NULL);
  ZORBA_ASSERT(TypeOps::is_atomic(tm, *lSourceType));

  // std::cout << "-castToAtomic: " << aItem.getp()->getStringValue()->c_str()
  //           << " srcType: " << lSourceType->get_qname()->getLocalName()->c_str()
  //           << " @ " << lSourceType->get_qname()->getNamespace()->c_str() << "\n";
  // std::cout << "\t\t  tgtType: " << aTargetType->get_qname()->getLocalName()->c_str()
  //           << " @ " << aTargetType->get_qname()->getNamespace()->c_str() << "\n";

  ErrorInfo lErrorInfo = {&*lSourceType, aTargetType};

  if (!TypeOps::is_atomic(tm, *aTargetType))
    throw XQUERY_EXCEPTION(err::XPST0051, ERROR_PARAMS(aTargetType));

#ifndef ZORBA_NO_XMLSCHEMA
  if (aTargetType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    castToUserDefinedType(result, aItem, lSourceType.getp(), aTargetType, loc);
    return result != NULL;
  }
#endif // ZORBA_NO_XMLSCHEMA

  zstring sourceString;
  ATOMIC_CODE_T lSourceTypeCode;
  ATOMIC_CODE_T lTargetTypeCode = TypeOps::get_atomic_type_code(*aTargetType);

  lSourceType = lSourceType->getBaseBuiltinType();

  ZORBA_ASSERT(TypeOps::is_builtin_atomic(tm, *lSourceType));

  lSourceTypeCode = TypeOps::get_atomic_type_code(*lSourceType);

  if (lSourceTypeCode == lTargetTypeCode)
  {
    result.transfer(aItem);
    return true;
  }

  if (theMapping[lSourceTypeCode] == theMapping[TypeConstants::XS_STRING])
  {
    aItem->getStringValue2(sourceString);
  }

  if (lTargetTypeCode == TypeConstants::XS_NOTATION ||
      lTargetTypeCode == TypeConstants::XS_ANY_ATOMIC)
  {
    throw XQUERY_EXCEPTION(err::XPST0080,
                           ERROR_PARAMS(*lErrorInfo.theTargetType),
                           ERROR_LOC(loc));
  }

  if (lSourceTypeCode == TypeConstants::XS_ANY_ATOMIC)
    throw TYPE_EXCEPTION(err::XPTY0004, lErrorInfo);

  if (lTargetTypeCode == TypeConstants::XS_NCNAME &&
      lSourceTypeCode != TypeConstants::XS_STRING &&
      lSourceTypeCode != TypeConstants::XS_NCNAME &&
      lSourceTypeCode != TypeConstants::XS_UNTYPED_ATOMIC)
    throw TYPE_EXCEPTION(err::XPTY0004, lErrorInfo);

  CastFunc lCastFunc = theCastMatrix[theMapping[lSourceTypeCode]]
                                    [theMapping[lTargetTypeCode]];
  if (lCastFunc == 0)
    throw TYPE_EXCEPTION(err::XPTY0004, lErrorInfo);

  bool valid = (*lCastFunc)(result,
                            aItem,
                            sourceString,
                            lFactory,
                            aNCtx,
                            lErrorInfo);

  DownCastFunc lDownCastFunc = theDownCastMatrix[theMapping[lTargetTypeCode]];

  if (lDownCastFunc != 0 &&
      lTargetTypeCode != TypeConstants::XS_STRING &&
      lTargetTypeCode != TypeConstants::XS_INTEGER)
  {
    valid = (*lDownCastFunc)(result,
                             &*result,
                             rtm,
                             lTargetTypeCode,
                             lFactory,
                             lErrorInfo);
  }

  return valid;
}


/*******************************************************************************

********************************************************************************/
void castToUserDefinedType(
    store::Item_t& result,
    const store::Item_t& aItem,
    const XQType* aSourceType,
    const XQType* aTargetType,
    const QueryLoc& loc)
{
  ErrorInfo lErrorInfo = {aSourceType, aTargetType};

  // std::cout << "-castToUserDefinedType: " << aItem.getp()->getStringValue()->c_str()
  //           << " srcType: " << aSourceType->get_qname()->getLocalName()->c_str()
  //           << " @ " << aSourceType->get_qname()->getNamespace()->c_str() << "\n";
  // std::cout << "\t\t           tgtType: "
  //           << aTargetType->get_qname()->getLocalName()->c_str() << " @ "
  //           << aTargetType->get_qname()->getNamespace()->c_str() << "\n";

  const TypeManager* lTypeManager = aTargetType->get_manager();
  Schema* schema = lTypeManager->getSchema();

  if (aSourceType->type_kind() != XQType::ATOMIC_TYPE_KIND ||
      (TypeOps::get_atomic_type_code(*aSourceType) != TypeConstants::XS_STRING))
  {
    throw TYPE_EXCEPTION( err::FORG0001, lErrorInfo );
  }

  const UserDefinedXQType* udt =
    static_cast<const UserDefinedXQType*>(aTargetType);

  switch ( udt->getTypeCategory() )
  {
  case UserDefinedXQType::ATOMIC_TYPE:
  {
    zstring strValue;
    aItem->getStringValue2(strValue);

    store::Item_t baseItem;
    bool hasResult = schema->parseUserAtomicTypes(strValue,
                                                  aTargetType,
                                                  baseItem,
                                                  NULL,
                                                  loc);

    if ( hasResult )
    {
      store::Item_t typeName = udt->get_qname();
      GENV_ITEMFACTORY->createUserTypedAtomicItem(result, baseItem, typeName);
      return;
    }
  }
  break;

  case UserDefinedXQType::LIST_TYPE:
  case UserDefinedXQType::UNION_TYPE:
  case UserDefinedXQType::COMPLEX_TYPE:
  default:
    ZORBA_ASSERT( false);
    break;
  }

  result = NULL;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::castToSimple(
    zstring& str,
    const xqtref_t& aTargetType,
    std::vector<store::Item_t>& aResultList,
    const TypeManager* tm,
    const QueryLoc& loc)
{
  //std::cout << "-castToSimple: " << aStr.c_str() << " tgtType: " << aTargetType->get_qname()->getLocalName()->c_str() << " @ " << aTargetType->get_qname()->getNamespace()->c_str() << "\n";

  return tm->getSchema()->parseUserSimpleTypes(str, aTargetType, aResultList, loc);
}


/*******************************************************************************
  Casts an atomic item to a qname, if possible.
********************************************************************************/
bool GenericCast::castToQName(
    store::Item_t& result,
    const store::Item_t& item,
    namespace_context* nsCtx,
    bool isAttrName,
    const TypeManager* tm,
    const QueryLoc& loc)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t sourceType = tm->create_named_type(item->getType(),
                                              TypeConstants::QUANT_ONE,
                                              loc,
                                              err::XPTY0004);

  ZORBA_ASSERT(item->isAtomic());
  ZORBA_ASSERT(sourceType != NULL);

  if (TypeOps::is_subtype(tm, *sourceType, *rtm.QNAME_TYPE_ONE))
  {
    result = item;
    return true;
  }
  else if (!TypeOps::is_subtype(tm, *sourceType, *rtm.STRING_TYPE_ONE) &&
           !TypeOps::is_equal(tm, *sourceType, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
  {
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS(
        ZED( BadType_23o ), *sourceType,
        ZED( NoCastTo_45o ), "QName"
      ),
      ERROR_LOC( loc )
    );
  }

  ErrorInfo errorInfo = { sourceType.getp(), rtm.QNAME_TYPE_ONE.getp() };

  zstring strval;
  item->getStringValue2(strval);
  ascii::trim_whitespace(strval);

  zstring::size_type idx = strval.find(":");
  zstring::size_type lidx = strval.rfind(":", strval.size(), 1);
  if (idx != lidx)
    throw TYPE_EXCEPTION( err::FORG0001, errorInfo );

  zstring prefix;
  zstring nsuri;
  zstring local;

  if (idx == zstring::npos)
  {
    if (nsCtx && !isAttrName)
    {
      nsCtx->findBinding(prefix, nsuri);
    }

    local = strval;
  }
  else
  {
    prefix = strval.substr(0, idx);

    if (!GenericCast::instance()->castableToNCName(prefix))
      throw TYPE_EXCEPTION( err::FORG0001, errorInfo );

    if (nsCtx)
    {
      if (!nsCtx->findBinding(prefix, nsuri))
        throw XQUERY_EXCEPTION( err::FONS0004, ERROR_PARAMS( prefix ) );
    }

    local = strval.substr(idx + 1);
  }

  if (!GenericCast::instance()->castableToNCName(local.c_str()))
    throw TYPE_EXCEPTION( err::FORG0001, errorInfo );

  return GENV_ITEMFACTORY->createQName(result, nsuri, prefix, local);
}


/*******************************************************************************
  NCName          ::= NCNameStartChar NCNameChar* // An XML Name, minus the ":"
  NCNameChar      ::= NameChar - ':'
  NCNameStartChar ::= Letter | '_'
  NameChar        ::= Letter | Digit | '.' | '-' | '_' | ':' | CombiningChar |
                      Extender
********************************************************************************/
bool GenericCast::castableToNCName(const zstring& str)
{
  std::vector<uint32_t> cps;

  utf8::to_codepoints(str, &cps);

  std::vector<uint32_t>::size_type i;
  std::vector<uint32_t>::size_type cps_size = cps.size();

  if (cps_size == 0)
    return false;

  uint32_t cp = cps[0];

  if(!XQCharType::isLetter(cp) && (cp != '_'))
    return false;

  for (i = 1; i < cps_size; i++)
  {
    cp = cps[i];

    if(!XQCharType::isLetter(cp) && !XQCharType::isDigit(cp) &&
      (cp != '.') && (cp != '-') && (cp != '_') &&
      !XQCharType::isCombiningChar(cp) && !XQCharType::isExtender(cp))
      return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::castableToNormalizedString(const zstring& str)
{
  char ch;
  zstring::size_type  sz = str.size();

  if (sz == 0)
    return true;

  for (zstring::size_type i = 0; i < sz; ++i)
  {
    ch = str[i];
    // do not contain the carriage return (#xD), line feed (#xA) nor tab (#x9)
    // characters
    if (ch == '\r' || ch == '\n' || ch == '\t')
    {
      return false;
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::castableToToken(const zstring& str)
{
  char ch;
  zstring::size_type sz = str.size();

  if (sz == 0)
    return true;

  bool spaceSeen = false;

  for (zstring::size_type i = 0; i < sz; ++i)
  {
    ch = str[i];

    // do not contain the carriage return (#xD), line feed (#xA) nor tab (#x9)
    // characters */
    if (ch == '\r' || ch == '\n' || ch == '\t')
    {
      return false;
    }

    if (ch == ' ')
    {
      /* two consecutive spaces not allowed. */
      if (spaceSeen)
        return false;

      /* no leading or trailing spaces */
      if (i == 0 || i == sz - 1)
        return false;

      spaceSeen = true;
    }
    else
    {
      spaceSeen = false;
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::castableToLanguage(const zstring& str)
{
  char ch;
  zstring::size_type i = 0;
  zstring::size_type sz = str.size();

  if (sz == 0)
    return false;

  /* automation for [a-zA-Z]{1,8}(-[a-zA-Z0-9]{1,8})* */
  bool firstBlock = true;
  i = 0;
  uint32_t blkIdx = 0;

  while (i < sz)
  {
    ch = str[i];

    if (ch == '-')
    {
      if (blkIdx == 0)
      {
        return false;
      }

      blkIdx = 0;
      firstBlock = false;
      ++i;
      continue;
    }

    if (blkIdx >= 8)
    {
      return false;
    }

    if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
    {
      if (firstBlock)
      {
        return false;
      }
      if (!(ch >= '0' && ch <= '9'))
      {
        return false;
      }
    }

    ++i;
    ++blkIdx;
  }

  if (blkIdx == 0)
  {
    return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::castableToNMToken(const zstring& str)
{
  uint32_t cp;
  std::vector<uint32_t> cps;

  utf8::to_codepoints(str, &cps);

  std::vector<uint32_t>::size_type i;
  std::vector<uint32_t>::size_type sz = cps.size();

  if (sz == 0)
    return false;

  for (i = 0; i < sz; ++i)
  {
    cp = cps[i];
    if (!(XQCharType::isLetter(cp)
      || XQCharType::isDigit(cp)
      || XQCharType::isExtender(cp)
      || XQCharType::isCombiningChar(cp)
      || cp == '.'
      || cp == '-'
      || cp == '_'
      || cp == ':'))
    {
      return false;
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::castableToName(const zstring& str)
{
  uint32_t cp;
  std::vector<uint32_t> cps;

  utf8::to_codepoints(str, &cps);

  std::vector<uint32_t>::size_type i;
  std::vector<uint32_t>::size_type sz = cps.size();

  if (sz == 0)
    return false;

  for (i = 0; i < sz; ++i)
  {
    cp = cps[i];
    if (!(XQCharType::isLetter(cp) || cp == '_' || cp == ':') )
    {
      if (i == 0)
      {
        return false;
      }

      if (!(XQCharType::isDigit(cp)
        || XQCharType::isExtender(cp)
        || XQCharType::isCombiningChar(cp)
        || cp == '.'
        || cp == '-'))
      {
        return false;
      }
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::isCastable(
    const store::Item_t& aItem,
    const XQType* aTargetType,
    const TypeManager* tm)
{
#ifndef ZORBA_NO_XMLSCHEMA
  if (aTargetType->type_kind() == XQType::USER_DEFINED_KIND )
  {
    const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(aTargetType);
    if (!udt->isComplex())
    {
      return tm->getSchema()->
             isCastableUserSimpleTypes(aItem->getStringValue(),
                                       udt->getBaseType().getp());
    }
  }
#endif // ZORBA_NO_XMLSCHEMA

  xqtref_t lSourceType = tm->create_named_type(aItem->getType(),
                                               TypeConstants::QUANT_ONE,
                                               QueryLoc::null,
                                               err::XPTY0004);

  TypeConstants::castable_t lIsCastable = TypeOps::castability(*lSourceType,
                                                               *aTargetType);
  switch(lIsCastable)
  {
  case TypeConstants::NOT_CASTABLE:
    return false;
    break;
  case TypeConstants::CASTABLE:
    return true;
    break;
  case TypeConstants::MAYBE_CASTABLE:
  {
    try
    {
      store::Item_t temp = aItem;
      return castToAtomic(temp, temp, aTargetType, tm, NULL, QueryLoc::null);
    }
    catch (ZorbaException const&)
    {
      return false;
    }
  }
  break;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::isCastable(
    const zstring& str,
    const XQType* aTargetType,
    const TypeManager* tm)
{
#ifndef ZORBA_NO_XMLSCHEMA
  if (aTargetType->type_kind() == XQType::USER_DEFINED_KIND )
  {
    const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(aTargetType);
    if (!udt->isComplex())
    {
      return tm->getSchema()->
             isCastableUserSimpleTypes(str,
                                       udt->getBaseType().getp());
    }
  }
#endif // ZORBA_NO_XMLSCHEMA

  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t lSourceType = rtm.STRING_TYPE_ONE;

  TypeConstants::castable_t lIsCastable = TypeOps::castability(*lSourceType,
                                                               *aTargetType);
  switch(lIsCastable)
  {
  case TypeConstants::NOT_CASTABLE:
    return false;
    break;
  case TypeConstants::CASTABLE:
    return true;
    break;
  case TypeConstants::MAYBE_CASTABLE:
  {
    try
    {
      store::Item_t dummy;
      zstring copyStr = str;
      return castToAtomic(dummy, copyStr, aTargetType, tm, NULL, QueryLoc::null);
    }
    catch (ZorbaException const&)
    {
      return false;
    }
  }
  break;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::promote(
    store::Item_t& result,
    store::Item_t& aItem,
    const XQType* aTargetType,
    const TypeManager* tm,
    const QueryLoc& loc)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t lItemType = tm->create_value_type(aItem);

  if (TypeOps::is_equal(tm, *aTargetType, *rtm.NONE_TYPE))
      return false;

  if (TypeOps::is_subtype(tm, *lItemType, *aTargetType))
  {
    result.transfer(aItem);
    return result != NULL;
  }

  if (TypeOps::is_equal(tm, *lItemType, *rtm.UNTYPED_ATOMIC_TYPE_ONE) &&
      ! TypeOps::is_equal(tm, *TypeOps::prime_type(tm, *aTargetType), *rtm.QNAME_TYPE_ONE))
  {
    return GenericCast::castToAtomic(result, aItem, aTargetType, tm, NULL, loc);
  }
  else if (TypeOps::is_subtype(tm, *aTargetType, *rtm.FLOAT_TYPE_ONE))
  {
    // decimal --> xs:float
    if (TypeOps::is_subtype(tm, *lItemType, *rtm.DECIMAL_TYPE_ONE))
    {
      return GenericCast::castToAtomic(result, aItem, aTargetType, tm, NULL, loc);
    }
  }
  else if (TypeOps::is_subtype(tm, *aTargetType, *rtm.DOUBLE_TYPE_ONE))
  {
    // Decimal/Float --> xs:double
    if (TypeOps::is_subtype(tm, *lItemType, *rtm.DECIMAL_TYPE_ONE) ||
        TypeOps::is_subtype(tm, *lItemType, *rtm.FLOAT_TYPE_ONE))
    {
      return GenericCast::castToAtomic(result, aItem, aTargetType, tm, NULL, loc);
    }
  }
  else if (TypeOps::is_subtype(tm, *aTargetType, *rtm.STRING_TYPE_ONE))
  {
    // URI --> xs:String Promotion
    if (TypeOps::is_subtype(tm, *lItemType, *rtm.ANY_URI_TYPE_ONE))
    {
      return GenericCast::castToAtomic(result, aItem, &*rtm.STRING_TYPE_ONE, tm, NULL, loc);
    }
  }

  return false;
}


#undef ATOMIC_TYPE


/* end class GenericCast */
} // namespace zorba
/* vim:set et sw=2 ts=2: */
