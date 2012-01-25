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
#include "diagnostics/util_macros.h"

#include "context/namespace_context.h"

#include "system/globalenv.h"

#include "store/api/item_factory.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/xs_type_codes.h"

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
  GENV_TYPESYSTEM.create_atomic_type(store::XS_##type, TypeConstants::QUANT_ONE)

#define ATOMIC_CODE_T \
  store::SchemaTypeCode


struct ErrorInfo
{
  const XQType          * theSourceType;
  const XQType          * theTargetType;
  store::SchemaTypeCode   theSourceTypeCode;
  store::SchemaTypeCode   theTargetTypeCode;
  const QueryLoc        & theLoc;

  ErrorInfo(
      const XQType* source,
      const XQType* target,
      const QueryLoc& loc)
    :
    theSourceType(source),
    theTargetType(target),
    theLoc(loc)
  {
    assert(source != NULL && target != NULL);
  }

  ErrorInfo(
      store::SchemaTypeCode source,
      store::SchemaTypeCode target,
      const QueryLoc& loc)
    :
    theSourceType(NULL),
    theTargetType(NULL),
    theSourceTypeCode(source),
    theTargetTypeCode(target),
    theLoc(loc)
  {
  }
};


void throwTypeException(const Diagnostic& errcode, const ErrorInfo& info)
{              
  if (info.theSourceType)
  {                      
    throw XQUERY_EXCEPTION_VAR(errcode,
    ERROR_PARAMS(*info.theSourceType, ZED(NoCastTo_34o), *info.theTargetType),
    ERROR_LOC(info.theLoc));
  }                                           
  else                                        
  {
    TypeManager& tm = GENV_TYPESYSTEM;
                                     
    xqtref_t sourceType =
    tm.create_builtin_atomic_type(info.theSourceTypeCode,
                                  TypeConstants::QUANT_ONE);

    xqtref_t targetType =
    tm.create_builtin_atomic_type(info.theTargetTypeCode,
                                  TypeConstants::QUANT_ONE);

    throw XQUERY_EXCEPTION_VAR(errcode,
    ERROR_PARAMS(*sourceType, ZED(NoCastTo_34o), *targetType),
    ERROR_LOC(info.theLoc));    
  }                                           
}


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
SAME_S_AND_T(NUL)

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
  try 
  {
    xs_float const n(strval.c_str());
    return aFactory->createFloat(result, n);
  }
  catch (std::invalid_argument const&) 
  {
    throwTypeException(err::FORG0001, aErrorInfo);
    return NULL;
  }
  catch ( std::range_error const& ) 
  {
    throw XQUERY_EXCEPTION(err::FOAR0002, ERROR_PARAMS(strval));
  }
}


T1_TO_T2(str, dbl)
{
  try 
  {
    xs_double const n(strval.c_str());
    return aFactory->createDouble(result, n);
  }
  catch (std::invalid_argument const& ) 
  {
    throwTypeException(err::FORG0001, aErrorInfo);
    return NULL;
  }
  catch (std::range_error const& ) 
  {
    throw XQUERY_EXCEPTION(err::FOAR0002, ERROR_PARAMS(strval));
  }
}


T1_TO_T2(str, dec)
{
  try 
  {
    xs_decimal const n(strval.c_str());
    return aFactory->createDecimal(result, n);
  }
  catch ( std::exception const& ) 
  {
    throwTypeException( err::FORG0001, aErrorInfo );
    return NULL;
  }
}


T1_TO_T2(str, int)
{
  try 
  {
    xs_integer const n(strval.c_str());
    return aFactory->createInteger(result, n);
  }
  catch ( std::invalid_argument const& ) 
  {
    throwTypeException( err::FORG0001, aErrorInfo );
    return NULL;
  }
  catch ( std::range_error const& ) 
  {
    throwTypeException( err::FOAR0002, aErrorInfo );
    return NULL;
  }
}


T1_TO_T2(str, dur)
{
  Duration d;
  int err;

  if (0 == (err = Duration::parseDuration(strval.c_str(), strval.size(), d)))
    return aFactory->createDuration(result, &d);

  throwTypeException(err::FORG0001, aErrorInfo);
  return NULL;
}


T1_TO_T2(str, yMD)
{
  Duration d;
  int err;

  if (0 == (err = Duration::parseYearMonthDuration(strval.c_str(), strval.size(), d)))
    return aFactory->createYearMonthDuration(result, &d);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, dTD)
{
  Duration d;
  int err;

  if (0 == (err = Duration::parseDayTimeDuration(strval.c_str(), strval.size(), d)))
    return aFactory->createDayTimeDuration(result, &d);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, dT)
{
  xs_dateTime dt;
  if (0 == DateTime::parseDateTime(strval.c_str(), strval.size(), dt))
    return aFactory->createDateTime(result, &dt);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, tim)
{
  xs_time t;
  if (0 == DateTime::parseTime(strval.c_str(), strval.size(), t))
    return aFactory->createTime(result, &t);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, dat)
{
  xs_date d;
  if (0 == DateTime::parseDate(strval.c_str(), strval.size(), d))
    return aFactory->createDate(result, &d);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, gYM)
{
  xs_gYearMonth ym;
  if (0 == DateTime::parseGYearMonth(strval.c_str(), strval.size(), ym))
    return aFactory->createGYearMonth(result, &ym);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, gYr)
{
  xs_gYear y;
  if (0 == DateTime::parseGYear(strval.c_str(), strval.size(), y))
    return aFactory->createGYear(result, &y);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, gMD)
{
  xs_gMonthDay md;
  if (0 == DateTime::parseGMonthDay(strval.c_str(), strval.size(), md))
    return aFactory->createGMonthDay(result, &md);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, gDay)
{
  xs_gDay d;
  if (0 == DateTime::parseGDay(strval.c_str(), strval.size(), d))
    return aFactory->createGDay(result, &d);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, gMon)
{
  xs_gMonth m;
  if (0 == DateTime::parseGMonth(strval.c_str(), strval.size(), m))
    return aFactory->createGMonth(result, &m);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
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
    throwTypeException( err::FORG0001, aErrorInfo );
    return NULL;
  }

  pos = str - strval.c_str();
  ascii::skip_whitespace(strval.c_str(), len, &pos);

  if (pos != len)
    throwTypeException( err::FORG0001, aErrorInfo );

  return aFactory->createBoolean(result, lRetValue);
}


T1_TO_T2(str, b64)
{
  xs_base64Binary n;
  if (xs_base64Binary::parseString(strval, n))
    return aFactory->createBase64Binary(result, n);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


T1_TO_T2(str, hxB)
{
  xs_hexBinary n;
  if (xs_hexBinary::parseString(strval, n))
    return aFactory->createHexBinary(result, n);

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
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
    throwTypeException( err::FORG0001, aErrorInfo );

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
      throwTypeException( err::FORG0001, aErrorInfo );

    if (nsCtx)
    {
      if (!nsCtx->findBinding(prefix, nsuri))
        throw XQUERY_EXCEPTION( err::FONS0004, ERROR_PARAMS( prefix ) );
    }

    local = strval.substr(idx + 1);
  }

  if (!GenericCast::instance()->castableToNCName(local))
    throwTypeException( err::FORG0001, aErrorInfo );

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
    throwTypeException( err::FOCA0002, aErrorInfo );
    return NULL;
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
    throwTypeException( err::FOCA0002, aErrorInfo );
    return NULL;
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
    throwTypeException(err::FOCA0002, aErrorInfo);
    return NULL;
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
    throwTypeException( err::FOCA0002, aErrorInfo );
    return NULL;
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


T1_TO_T2(NUL, str)
{
  zstring val("null");
  return aFactory->createString(result, val);
}


/*******************************************************************************

********************************************************************************/
bool str_down(
    store::Item_t& result,
    const store::Item* aItem,
    ATOMIC_CODE_T aTargetAtomicType,
    store::ItemFactory* aFactory,
    const ErrorInfo& aErrorInfo)
{
  zstring strval;
  aItem->getStringValue2(strval);

  switch(aTargetAtomicType)
  {
  case store::XS_NORMALIZED_STRING:
  {
    if (GenericCast::instance()->castableToNormalizedString(strval))
      return aFactory->createNormalizedString(result, strval);
    break;
  }
  case store::XS_TOKEN:
  {
    if (GenericCast::instance()->castableToToken(strval))
      return aFactory->createToken(result, strval);
    break;
  }
  case store::XS_LANGUAGE:
  {
    if (GenericCast::instance()->castableToLanguage(strval))
      return aFactory->createLanguage(result, strval);
    break;
  }
  case store::XS_NMTOKEN:
  {
    ascii::trim_whitespace(strval);

    if (GenericCast::instance()->castableToNMToken(strval))
    {
      return aFactory->createNMTOKEN(result, strval);
    }
    break;
  }
  case store::XS_NAME:
  {
    ascii::trim_whitespace(strval);

    if (GenericCast::instance()->castableToName(strval))
    {
      return aFactory->createName(result, strval);
    }
    break;
  }
  case store::XS_NCNAME:
  {
    ascii::normalize_whitespace(strval);
    ascii::trim_whitespace(strval);

    if (GenericCast::instance()->castableToNCName(strval))
    {
      return aFactory->createNCName(result, strval);
    }
    break;
  }
  case store::XS_ID:
  {
    if (GenericCast::instance()->castableToNCName(strval))
      return aFactory->createID(result, strval);
    break;
  }
  case store::XS_IDREF:
  {
    if (GenericCast::instance()->castableToNCName(strval))
      return aFactory->createIDREF(result, strval);
    break;
  }
  case store::XS_ENTITY:
  {
    if (GenericCast::instance()->castableToNCName(strval))
      return aFactory->createENTITY(result, strval);
    break;
  }
  default:
    ZORBA_ASSERT(false);
  }

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


/*******************************************************************************

********************************************************************************/
bool int_down(
    store::Item_t& result,
    const store::Item* aItem,
    ATOMIC_CODE_T aTargetAtomicType,
    store::ItemFactory* aFactory,
    const ErrorInfo& aErrorInfo)
{
  switch(aTargetAtomicType)
  {
  case store::XS_NON_POSITIVE_INTEGER:
  {
    xs_integer const lInteger = aItem->getIntegerValue();
    if (lInteger <= xs_integer::zero())
      return aFactory->createNonPositiveInteger(result, lInteger);
    break;
  }
  case store::XS_NEGATIVE_INTEGER:
  {
    xs_integer const lInteger = aItem->getIntegerValue();
    if (lInteger < xs_integer::zero())
      return aFactory->createNegativeInteger(result, lInteger);
    break;
  }
  case store::XS_LONG:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_long const n = ztd::aton<xs_long>(lString.c_str());
      return aFactory->createLong(result, n);
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_INT:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_int const n = ztd::aton<xs_int>(lString.c_str());
      return aFactory->createInt(result, n);
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_SHORT:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_short const n = ztd::aton<xs_short>(lString.c_str());
      return aFactory->createShort(result, n);
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_BYTE:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_byte const n = ztd::aton<xs_byte>(lString.c_str());
      return aFactory->createByte(result, n);
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_NON_NEGATIVE_INTEGER:
  {
    xs_integer const lInteger = aItem->getIntegerValue();
    if (lInteger >= xs_integer::zero())
      return aFactory->createNonNegativeInteger(result, lInteger);
    break;
  }
  case store::XS_UNSIGNED_LONG:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_unsignedLong const n = ztd::aton<xs_unsignedLong>(lString.c_str());
      return aFactory->createUnsignedLong(result, n);
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_UNSIGNED_INT:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_unsignedInt const n = ztd::aton<xs_unsignedInt>(lString.c_str());
      return aFactory->createUnsignedInt(result, n);
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_UNSIGNED_SHORT:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_unsignedShort const n = ztd::aton<xs_unsignedShort>(lString.c_str());
      return aFactory->createUnsignedShort(result, n);
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_UNSIGNED_BYTE:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_unsignedByte const n = ztd::aton<xs_unsignedByte>(lString.c_str());
      return aFactory->createUnsignedByte(result, n);
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_POSITIVE_INTEGER:
  {
    xs_integer lInteger = aItem->getIntegerValue();
    if (lInteger > xs_integer::zero())
      return aFactory->createPositiveInteger(result, lInteger);
    break;
  }
  default:
    ZORBA_ASSERT (false);
  }

  throwTypeException( err::FORG0001, aErrorInfo );
  return NULL;
}


/*******************************************************************************
  For each builtin atomic type T, this array maps the typecode of T to an
  index to be used in addessing theCastingMatrix.
********************************************************************************/
const int GenericCast::theMapping[store::XS_LAST] =
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
   5,  // 28 XS_NON_NEGATIVE_INTEGER
   5,  // 29 XS_UNSIGNED_LONG
   5,  // 30 XS_UNSIGNED_INT
   5,  // 31 XS_UNSIGNED_SHORT
   5,  // 32 XS_UNSIGNED_BYTE
   5,  // 33 XS_POSITIVE_INTEGER
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
  22,  // 44 XS_NOTATION
  23   // 45 JDM_NULL
};


/*******************************************************************************

********************************************************************************/
const GenericCast::DownCastFunc GenericCast::theDownCastMatrix[24] =
{
/*uA*/  0, /*str*/ str_down, /*flt*/ 0, /*dbl*/ 0, /*dec*/ 0, /*int*/ int_down, /*dur*/ 0,
/*yMD*/ 0, /*dTD*/ 0, /*dT*/  0, /*tim*/ 0, /*dat*/ 0, /*gYM*/ 0, /*gYr*/ 0, /*gMD*/ 0,
/*gDay*/0, /*gMon*/0, /*bool*/0, /*b64*/ 0, /*hxB*/ 0, /*aURI*/0, /*QN*/  0,
/*NOT*/ 0, /*null*/0
};


/*******************************************************************************

********************************************************************************/
const GenericCast::CastFunc GenericCast::theCastMatrix[24][24] =
{
// uA        str        flt       dbl         dec        int       dur       yMD
// dTD       dT         tim       dat         gYM        gYr       gMD       gDay 
// gMon      bool       b64       hxB         aURI       QN        NOT       null
{&uA_uA,    &uA_str,   &uA_flt,  &uA_dbl ,   &uA_dec ,  &uA_int,   &uA_dur,  &uA_yMD,
 &uA_dTD,   &uA_dT,    &uA_tim,  &uA_dat,    &uA_gYM ,  &uA_gYr ,  &uA_gMD,  &uA_gDay,
 &uA_gMon, &uA_bool,   &uA_b64,  &uA_hxB,    &uA_aURI,  0,         0,        0}, // uA

{&str_uA,   &str_str,  &str_flt,  &str_dbl,  &str_dec,  &str_int,  &str_dur, &str_yMD,
 &str_dTD,  &str_dT,   &str_tim,  &str_dat,  &str_gYM,  &str_gYr,  &str_gMD, &str_gDay,
 &str_gMon, &str_bool, &str_b64,  &str_hxB,  &str_aURI, &str_QN,   &str_NOT, 0}, // str

{&flt_uA,   &flt_str,  &flt_flt,  &flt_dbl,  &flt_dec,  &flt_int,  0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         &flt_bool, 0,         0,         0,         0,         0,        0}, // flt

{&dbl_uA,   &dbl_str,  &dbl_flt,  &dbl_dbl,  &dbl_dec,  &dbl_int,  0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,  
 0,         &dbl_bool, 0,         0,         0,         0,         0,        0}, // dbl

{&dec_uA,   &dec_str,  &dec_flt,  &dec_dbl,  &dec_dec,  &dec_int,  0,        0,
 0,         0,         0,         0,         0,         0,         0,        0, 
 0,         &dec_bool, 0,         0,         0,         0,         0,        0}, // dec

{&int_uA,   &int_str,  &int_flt,  &int_dbl,  &int_dec,  &int_int,  0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0, 
 0,         &int_bool, 0,         0,         0,         0,         0,        0}, // int

{&dur_uA,   &dur_str,  0,         0,         0,         0,         &dur_dur, &dur_yMD,
 &dur_dTD,  0,         0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0}, // dur

{&yMD_uA,   &yMD_str,  0,         0,         0,         0,         &yMD_dur, &yMD_yMD,
 &yMD_dTD,  0,         0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0}, // yMD

{&dTD_uA,   &dTD_str,  0,         0,         0,         0,         &dTD_dur, &dTD_yMD,
 &dTD_dTD,  0,         0,         0,         0,         0,         0,        0,  
 0,         0,         0,         0,         0,         0,         0,        0}, // dTD

{&dT_uA,    &dT_str,   0,         0,         0,         0,         0,        0,
 0,         &dT_dT,    &dT_tim,   &dT_dat,   &dT_gYM,   &dT_gYr,   &dT_gMD,  &dT_gDay,
  &dT_gMon,  0,         0,         0,         0,         0,         0,        0}, // dT

{&tim_uA,   &tim_str,  0,         0,         0,         0,         0,        0,
 0,         0,         &tim_tim,  0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0}, // tim

{&dat_uA,   &dat_str,  0,         0,         0,         0,         0,        0,
 0,         &dat_dT,   0,         &dat_dat,  &dat_gYM,  &dat_gYr,  &dat_gMD, &dat_gDay,
 &dat_gMon, 0,         0,         0,         0,         0,         0,        0}, // dat

{&gYM_uA,   &gYM_str,  0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         &gYM_gYM,  0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0}, // gYM

{&gYr_uA,   &gYr_str,  0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         &gYr_gYr,  0,        0,  
 0,         0,         0,         0,         0,         0,         0,        0}, // gYr

{&gMD_uA,   &gMD_str,  0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         &gMD_gMD, 0,
 0,         0,         0,         0,         0,         0,         0,        0}, // gMD

{&gDay_uA,  &gDay_str, 0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         0,        &gDay_gDay,
 0,         0,         0,         0,         0,         0,         0,        0}, // gDay

{&gMon_uA,  &gMon_str, 0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,  
 &gMon_gMon,0,         0,         0,         0,         0,         0,        0}, // gMon

{&bool_uA,  &bool_str, &bool_flt, &bool_dbl, &bool_dec, &bool_int, 0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0,  
 0,         &bool_bool,0,         0,         0,         0,         0,        0}, // bool

{&b64_uA,   &b64_str,  0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0,         &b64_b64,  &b64_hxB,  0,         0,         0,        0}, // b64

{&hxB_uA,   &hxB_str,  0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0,         &hxB_b64,  &hxB_hxB,  0,         0,         0,        0}, // hxB

{&aURI_uA,  &aURI_str, 0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,  
 0,         0,         0,         0,         &aURI_aURI,0,         0,        0}, // aURI

{&QN_uA,    &QN_str,   0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         &QN_QN,    0,        0}, // QN

{&NOT_uA,   &NOT_str,  0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         &NOT_NOT, 0}, // NOT

{0,         &NUL_str,  0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,  
 0,         0,         0,         0,         0,         0,         0,        &NUL_NUL} // NUL
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
    const XQType* targetType,
    const TypeManager* tm,
    namespace_context* aNsCtx,
    const QueryLoc& loc)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;
  store::ItemFactory* lFactory = GENV_ITEMFACTORY;

  const XQType* sourceType = rtm.STRING_TYPE_ONE.getp();

  ErrorInfo lErrorInfo(sourceType, targetType, loc);

  if (!TypeOps::is_atomic(tm, *targetType))
    RAISE_ERROR(err::XPST0051, loc, ERROR_PARAMS(targetType));

#ifndef ZORBA_NO_XMLSCHEMA
  if (targetType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    store::Item_t baseItem;

    bool success = tm->getSchema()->parseUserAtomicTypes(str,
                                                         targetType,
                                                         baseItem,
                                                         aNsCtx,
                                                         loc);
    if (success)
    {
      const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(targetType);
      store::Item_t typeName = udt->get_qname();

      GENV_ITEMFACTORY->createUserTypedAtomicItem(result, baseItem, typeName);
      return true;
    }

    return false;
  }
#endif

  store::Item_t lItem;
  ATOMIC_CODE_T sourceTypeCode = store::XS_STRING;
  ATOMIC_CODE_T targetTypeCode = TypeOps::get_atomic_type_code(*targetType);
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
      throwTypeException(err::XPTY0004, lErrorInfo);

    valid = (*lCastFunc)(result,
                         lItem,
                         str,
                         lFactory,
                         aNsCtx,
                         lErrorInfo);
  }

  DownCastFunc lDownCastFunc = theDownCastMatrix[theMapping[targetTypeCode]];

  if (lDownCastFunc != 0 &&
      targetTypeCode != store::XS_STRING &&
      targetTypeCode != store::XS_INTEGER)
  {
    valid = (*lDownCastFunc)(result,
                             &*result,
                             targetTypeCode,
                             lFactory,
                             lErrorInfo);
  }

  return valid;
}


/*******************************************************************************
  Cast, if possible, a given atomic item SI to an atomic item TI of a given 
  type TT. If the cast is not allowed, the method raises an error. If the cast
  is not possible, the method may raise an error or return false (TODO fix 
  this!). Otherwise, it returns true.
********************************************************************************/
bool GenericCast::castToAtomic(
    store::Item_t&       result,
    store::Item_t&       aItem,
    const XQType*        targetType,
    const TypeManager*   tm,
    namespace_context*   nsCtx,
    const QueryLoc&      loc)
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;

  ZORBA_ASSERT(aItem->isAtomic());

  xqtref_t sourceType = tm->create_named_type(aItem->getType(),
                                              TypeConstants::QUANT_ONE,
                                              QueryLoc::null,
                                              err::XPTY0004);
  ZORBA_ASSERT(sourceType != NULL);
  assert(TypeOps::is_atomic(tm, *sourceType));

  // std::cout << "-castToAtomic: " << aItem.getp()->getStringValue()->c_str()
  //           << " srcType: " << sourceType->get_qname()->getLocalName()->c_str()
  //           << " @ " << sourceType->get_qname()->getNamespace()->c_str() << "\n";
  // std::cout << "\t\t  tgtType: " << aTargetType->get_qname()->getLocalName()->c_str()
  //           << " @ " << aTargetType->get_qname()->getNamespace()->c_str() << "\n";

  ErrorInfo errorInfo(sourceType.getp(), targetType, loc);

  if (!TypeOps::is_atomic(tm, *targetType))
    RAISE_ERROR(err::XPST0051, loc, ERROR_PARAMS(targetType));

#ifndef ZORBA_NO_XMLSCHEMA
  if (targetType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    castToUserDefinedType(result, aItem, sourceType.getp(), targetType, loc);
    return result != NULL;
  }
#endif // ZORBA_NO_XMLSCHEMA

  sourceType = sourceType->getBaseBuiltinType();

  zstring sourceString;
  ATOMIC_CODE_T sourceTypeCode = TypeOps::get_atomic_type_code(*sourceType);
  ATOMIC_CODE_T targetTypeCode = TypeOps::get_atomic_type_code(*targetType);

  if (sourceTypeCode == targetTypeCode)
  {
    result.transfer(aItem);
    return true;
  }

  if (targetTypeCode == store::XS_NOTATION ||
      targetTypeCode == store::XS_ANY_ATOMIC)
  {
    RAISE_ERROR(err::XPST0080, loc, ERROR_PARAMS(*errorInfo.theTargetType));
  }

  if (sourceTypeCode == store::XS_ANY_ATOMIC)
    throwTypeException(err::XPTY0004, errorInfo);

  if (targetTypeCode == store::XS_NCNAME &&
      sourceTypeCode != store::XS_STRING &&
      sourceTypeCode != store::XS_NCNAME &&
      sourceTypeCode != store::XS_UNTYPED_ATOMIC)
    throwTypeException(err::XPTY0004, errorInfo);

  if (targetTypeCode == store::JDM_NULL)
    throwTypeException(err::XPTY0004, errorInfo);

  CastFunc castFunc = theCastMatrix[theMapping[sourceTypeCode]]
                                    [theMapping[targetTypeCode]];
  if (castFunc == 0)
    throwTypeException(err::XPTY0004, errorInfo);

  if (theMapping[sourceTypeCode] == theMapping[store::XS_STRING])
  {
    aItem->getStringValue2(sourceString);
  }

  bool valid = (*castFunc)(result,
                           aItem,
                           sourceString,
                           factory,
                           nsCtx,
                           errorInfo);

  DownCastFunc downCastFunc = theDownCastMatrix[theMapping[targetTypeCode]];

  if (downCastFunc != 0 &&
      targetTypeCode != store::XS_STRING &&
      targetTypeCode != store::XS_INTEGER)
  {
    valid = (*downCastFunc)(result,
                            &*result,
                            targetTypeCode,
                            factory,
                            errorInfo);
  }

  assert(valid);
  return valid;
}


/*******************************************************************************
  Cast, if possible, a given atomic item SI to an atomic item TI of a given 
  type TT. If the cast is not allowed, the method raises an error. If the cast
  is not possible, the method may raise an error or return false (TODO fix 
  this!). Otherwise, it returns true.
********************************************************************************/
bool GenericCast::castToAtomic(
    store::Item_t&        result,
    store::Item_t&        item,
    store::SchemaTypeCode targetType,
    const TypeManager*    tm,
    namespace_context*    nsCtx,
    const QueryLoc&       loc)
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  zstring sourceString;

  store::SchemaTypeCode sourceType = item->getTypeCode();

  if (sourceType == targetType)
  {
    result.transfer(item);
    return true;
  }

  ErrorInfo errorInfo(sourceType, targetType, loc);

  if (targetType == store::XS_NOTATION ||
      targetType == store::XS_ANY_ATOMIC)
  {
    RAISE_ERROR(err::XPST0080, loc, ERROR_PARAMS(*errorInfo.theTargetType));
  }

  if (sourceType == store::XS_ANY_ATOMIC)
  {
    throwTypeException(err::XPTY0004, errorInfo);
  }

  if (targetType == store::XS_NCNAME &&
      sourceType != store::XS_STRING &&
      sourceType != store::XS_NCNAME &&
      sourceType != store::XS_UNTYPED_ATOMIC)
  {
    throwTypeException(err::XPTY0004, errorInfo);
  }

  CastFunc castFunc = theCastMatrix[theMapping[sourceType]]
                                    [theMapping[targetType]];
  if (castFunc == 0)
  {
    throwTypeException(err::XPTY0004, errorInfo);
  }

  if (theMapping[sourceType] == theMapping[store::XS_STRING])
  {
    item->getStringValue2(sourceString);
  }

  bool valid = (*castFunc)(result,
                           item,
                           sourceString,
                           factory,
                           nsCtx,
                           errorInfo);

  DownCastFunc downCastFunc = theDownCastMatrix[theMapping[targetType]];

  if (downCastFunc != 0 &&
      targetType != store::XS_STRING &&
      targetType != store::XS_INTEGER)
  {
    valid = (*downCastFunc)(result,
                            &*result,
                            targetType,
                            factory,
                            errorInfo);
  }

  assert(valid);
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
  ErrorInfo lErrorInfo(aSourceType, aTargetType, loc);

  // std::cout << "-castToUserDefinedType: " << aItem.getp()->getStringValue()->c_str()
  //           << " srcType: " << aSourceType->get_qname()->getLocalName()->c_str()
  //           << " @ " << aSourceType->get_qname()->getNamespace()->c_str() << "\n";
  // std::cout << "\t\t           tgtType: "
  //           << aTargetType->get_qname()->getLocalName()->c_str() << " @ "
  //           << aTargetType->get_qname()->getNamespace()->c_str() << "\n";

  const TypeManager* lTypeManager = aTargetType->get_manager();
  Schema* schema = lTypeManager->getSchema();

  if (aSourceType->type_kind() != XQType::ATOMIC_TYPE_KIND ||
      (TypeOps::get_atomic_type_code(*aSourceType) != store::XS_STRING))
  {
    throwTypeException(err::FORG0001, lErrorInfo);
  }

  const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(aTargetType);

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
    if (hasResult)
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
    RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(ZED(BadType_23o), *sourceType, ZED(NoCastTo_45o), "QName"));
  }

  ErrorInfo errorInfo(sourceType.getp(), rtm.QNAME_TYPE_ONE.getp(), loc);

  zstring strval;
  item->getStringValue2(strval);
  ascii::trim_whitespace(strval);

  zstring::size_type idx = strval.find(":");
  zstring::size_type lidx = strval.rfind(":", strval.size(), 1);
  if (idx != lidx)
    throwTypeException(err::FORG0001, errorInfo);

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
      throwTypeException(err::FORG0001, errorInfo);

    if (nsCtx)
    {
      if (!nsCtx->findBinding(prefix, nsuri))
        throw XQUERY_EXCEPTION(err::FONS0004, ERROR_PARAMS(prefix));
    }

    local = strval.substr(idx + 1);
  }

  if (!GenericCast::instance()->castableToNCName(local.c_str()))
    throwTypeException(err::FORG0001, errorInfo );

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
    // untyped --> target type
    return castToAtomic(result, aItem, aTargetType, tm, NULL, loc);
  }
  else if (TypeOps::is_subtype(tm, *aTargetType, *rtm.FLOAT_TYPE_ONE))
  {
    // decimal --> xs:float
    if (TypeOps::is_subtype(tm, *lItemType, *rtm.DECIMAL_TYPE_ONE))
    {
      return castToAtomic(result, aItem, aTargetType, tm, NULL, loc);
    }
  }
  else if (TypeOps::is_subtype(tm, *aTargetType, *rtm.DOUBLE_TYPE_ONE))
  {
    // Decimal/Float --> xs:double
    if (TypeOps::is_subtype(tm, *lItemType, *rtm.DECIMAL_TYPE_ONE) ||
        TypeOps::is_subtype(tm, *lItemType, *rtm.FLOAT_TYPE_ONE))
    {
      return castToAtomic(result, aItem, aTargetType, tm, NULL, loc);
    }
  }
  else if (TypeOps::is_subtype(tm, *aTargetType, *rtm.STRING_TYPE_ONE))
  {
    // URI --> xs:String Promotion
    if (TypeOps::is_subtype(tm, *lItemType, *rtm.ANY_URI_TYPE_ONE))
    {
      return castToAtomic(result, aItem, &*rtm.STRING_TYPE_ONE, tm, NULL, loc);
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::promote(
    store::Item_t& result,
    store::Item_t& item,
    store::SchemaTypeCode targetType,
    const TypeManager* tm,
    const QueryLoc& loc)
{
  assert(item->isAtomic());

  store::SchemaTypeCode itemType = item->getTypeCode();

  if (TypeOps::is_subtype(itemType, targetType))
  {
    result.transfer(item);
    return result != NULL;
  }

  if (TypeOps::is_subtype(itemType, store::XS_UNTYPED_ATOMIC) &&
      ! TypeOps::is_subtype(targetType, store::XS_QNAME))
  {
    // untyped --> target type
    return castToAtomic(result, item, targetType, tm, NULL, loc);
  }
  else if (TypeOps::is_subtype(targetType, store::XS_FLOAT))
  {
    // decimal --> xs:float
    if (TypeOps::is_subtype(itemType, store::XS_DECIMAL))
    {
      return castToAtomic(result, item, targetType, tm, NULL, loc);
    }
  }
  else if (TypeOps::is_subtype(targetType, store::XS_DOUBLE))
  {
    // Decimal/Float --> xs:double
    if (TypeOps::is_subtype(itemType, store::XS_DECIMAL) ||
        TypeOps::is_subtype(itemType, store::XS_FLOAT))
    {
      return castToAtomic(result, item, targetType, tm, NULL, loc);
    }
  }
  else if (TypeOps::is_subtype(targetType, store::XS_STRING))
  {
    // URI --> xs:String Promotion
    if (TypeOps::is_subtype(itemType, store::XS_ANY_URI))
    {
      return castToAtomic(result, item, store::XS_STRING, tm, NULL, loc);
    }
  }

  return false;
}


#undef ATOMIC_TYPE


/* end class GenericCast */
} // namespace zorba
/* vim:set et sw=2 ts=2: */
