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
#include <vector>

#include "zorbatypes/numconversions.h"

#include "store/api/item.h"
#include "casting.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "zorbaerrors/error_manager.h"
#include "types/typeops.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "context/namespace_context.h"
#include "types/typeconstants.h"
#include "zorbaerrors/Assert.h"
#include "types/delegating_typemanager.h"
#include "zorbatypes/chartype.h"


namespace zorba
{

#define ATOMIC_TYPE(type) \
  GENV_TYPESYSTEM.create_atomic_type(TypeConstants::XS_##type, TypeConstants::QUANT_ONE)

#define ATOMICTYPE_T \
  TypeConstants::atomic_type_code_t

struct ErrorInfo
{
  const XQType* theSourceType;
  const XQType* theTargetType;
};

inline void throwError(XQUERY_ERROR aErrorCode, const ErrorInfo& aInfo)
{
  ZORBA_ERROR_DESC_OSS(aErrorCode, 
                       "Passed item (of type " << TypeOps::toString(*aInfo.theSourceType)
                       << ") is not castable to passed target type (" 
                       << TypeOps::toString (*aInfo.theTargetType) << ").");

};

inline xqpStringStore_t doTrim(const xqpStringStore* aStr)
{
  return aStr->trim(" \t\r\n", 4);
};

#define SAME_S_AND_T(type)                                                     \
  inline bool type##_##type(store::Item_t& result, store::Item* aItem, store::ItemFactory*, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)  \
  {                                                                            \
    result = aItem;                                                            \
    return true;                                                               \
  }                                                                            \

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

#undef SAME_S_AND_T


inline bool str_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqpStringStore_t strval = aItem->getStringValue();
  return aFactory->createUntypedAtomic(result, strval);
}

inline bool str_flt(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_float n;
  if (NumConversions::strToFloat(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createFloat(result, n);

  throwError(FORG0001, aErrorInfo);
  return false;
}

inline bool str_dbl(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_double n;
  if (NumConversions::strToDouble(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createDouble(result, n);

  throwError(FORG0001, aErrorInfo);
  return false;
}

inline bool str_dec(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_decimal n;
  if (NumConversions::strToDecimal(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createDecimal(result, n);

  throwError(FORG0001, aErrorInfo);
  return false;
}

inline bool str_int(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_integer n;
  if (NumConversions::strToInteger(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createInteger(result, n);

  throwError(FORG0001, aErrorInfo);
  return false;
}

inline bool str_dur(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  Duration_t d_t;
  if (Duration::parse_string(doTrim(aItem->getStringValue()).getp(), d_t))
  {
    xqp_duration d = d_t;
    return aFactory->createDuration(result, d);
  }

  throwError(FORG0001, aErrorInfo);
  return false;
}

inline bool str_yMD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  YearMonthDuration_t ymd_t;
  if (YearMonthDuration::parse_string(doTrim(aItem->getStringValue()).getp(), ymd_t))
  {
    xqp_duration d = ymd_t;
    return aFactory->createDuration(result, d);
  }

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_dTD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DayTimeDuration_t dtd_t;
  if (DayTimeDuration::parse_string(doTrim(aItem->getStringValue()).getp(), dtd_t))
  {
    xqp_duration d = dtd_t;
    return aFactory->createDuration(result, d);
  }

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_dT(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_dateTime dt;
  if (0 == DateTime::parseDateTime(doTrim(aItem->getStringValue()).getp(), dt))
    return aFactory->createDateTime(result, &dt);

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_tim(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_time t;
  if (0 == DateTime::parseTime(doTrim(aItem->getStringValue()).getp(), t))
    return aFactory->createTime(result, &t);

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_dat(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_date d;
  if (0 == DateTime::parseDate(doTrim(aItem->getStringValue()).getp(), d))
    return aFactory->createDate(result, &d);

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_gYM(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gYearMonth ym;
  if (0 == DateTime::parseGYearMonth(doTrim(aItem->getStringValue()).getp(), ym))
    return aFactory->createGYearMonth(result, &ym);

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_gYr(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gYear y;
  if (0 == DateTime::parseGYear(doTrim(aItem->getStringValue()).getp(), y))
    return aFactory->createGYear(result, &y);

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_gMD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gMonthDay md;
  if (0 == DateTime::parseGMonthDay(doTrim(aItem->getStringValue()).getp(), md))
    return aFactory->createGMonthDay(result, &md);

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_gDay(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gDay d;
  if (0 == DateTime::parseGDay(doTrim(aItem->getStringValue()).getp(), d))
    return aFactory->createGDay(result, &d);

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_gMon(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gMonth m;
  if (0 == DateTime::parseGMonth(doTrim(aItem->getStringValue()).getp(), m))
    return aFactory->createGMonth(result, &m);

  throwError(FORG0001, aErrorInfo);
  return false;
}


inline bool str_bool(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  bool lRetValue = true;
  xqpStringStore_t lString = doTrim(aItem->getStringValue());

  if (lString->byteEqual("false", 5) || lString->byteEqual("0", 1))
    lRetValue = false;
  else if (!lString->byteEqual("true", 4) && !lString->byteEqual("1", 1))
    throwError(FORG0001, aErrorInfo);

return aFactory->createBoolean(result, lRetValue);
}

inline bool str_b64(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_base64Binary n;
  if (xqp_base64Binary::parseString(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createBase64Binary(result, n);

  throwError(FORG0001, aErrorInfo);
  return false;
}

inline bool str_hxB(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_hexBinary n;
  if (xqp_hexBinary::parseString(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createHexBinary(result, n);

  throwError(FORG0001, aErrorInfo);
  return false;
}

inline bool str_aURI(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
// TODO createAnyURI does not always succeed
  xqpStringStore_t strval = doTrim(aItem->getStringValue());
  return aFactory->createAnyURI(result, strval);
}

inline bool str_QN(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  assert(nsCtx != 0);

  xqpString str(doTrim(aItem->getStringValue()));
  int32_t idx = str.theStrStore->indexOf(":");
  int32_t lidx = str.theStrStore->lastIndexOf(":");
  if (idx != lidx)
    throwError(FORG0001, aErrorInfo);

  xqpString lUri, lPrefix;
  
  if (idx < 0)
  {
    lPrefix = "";
    nsCtx->findBinding(lPrefix, lUri);
  } else {
    lPrefix = str.substr(0, idx);
    if (!GenericCast::instance()->castableToNCName(lPrefix.getStore()))
      throwError(FORG0001, aErrorInfo);
    if (!nsCtx->findBinding(lPrefix, lUri))
      throwError(FONS0004, aErrorInfo);
  }

  xqpString lLocal = str.substr(idx + 1);

  if (!GenericCast::instance()->castableToNCName(lLocal.getStore()))
    throwError(FORG0001, aErrorInfo);


  return aFactory->createQName(result, &*lUri.theStrStore, 
                               &*lPrefix.theStrStore, 
                               &*lLocal.theStrStore);
}

inline bool str_NOT(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqpStringStore_t strval = doTrim(aItem->getStringValue());
  return aFactory->createNOTATION(result, strval);
}

inline bool uA_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqpStringStore_t strval = aItem->getStringValue();
  return aFactory->createString(result, strval);  
}

inline bool uA_flt(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_flt(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_dbl(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dbl(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_dec(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dec(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_int(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_int(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_dur(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dur(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_yMD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_yMD(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_dTD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dTD(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_dT(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dT(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_tim(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_tim(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_dat(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dat(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_gYM(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gYM(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_gYr(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gYr(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_gMD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gMD(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_gDay(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gDay(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_gMon(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gMon(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_bool(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_bool(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_b64(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_b64(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_hxB(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_hxB(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool uA_aURI(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_aURI(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool flt_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool flt_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool flt_dbl(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createDouble(result, FloatCommons::parseFloat(aItem->getFloatValue()));
}

inline bool flt_dec(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_decimal n;
  if (xqp_decimal::parseFloat(aItem->getFloatValue(), n))
    return aFactory->createDecimal(result, n);

  throwError(FOCA0002, aErrorInfo);
  return false;
}

inline bool flt_int(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_integer n;
  if (xqp_integer::parseFloat(aItem->getFloatValue(), n))
    return aFactory->createInteger(result, n);

  throwError(FOCA0002, aErrorInfo);
  return false;
}

inline bool flt_bool(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  result = aItem->getEBV();
  return true;
}

inline bool dbl_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dbl_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dbl_flt(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createFloat(result, FloatCommons::parseDouble(aItem->getDoubleValue()));
}

inline bool dbl_dec(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_decimal n;
  if (xqp_decimal::parseDouble(aItem->getDoubleValue(), n))
    return aFactory->createDecimal(result, n);

  throwError(FOCA0002, aErrorInfo);
  return false;
}

inline bool dbl_int(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_integer n;
  if (xqp_integer::parseDouble(aItem->getDoubleValue(), n))
    return aFactory->createInteger(result, n);

  throwError(FOCA0002, aErrorInfo);
  return false;
}

inline bool dbl_bool(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  result = aItem->getEBV();
  return true;
}

inline bool dec_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dec_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dec_flt(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createFloat(result, xqp_float::parseDecimal(aItem->getDecimalValue()));
}

inline bool dec_dbl(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createDouble(result, xqp_double::parseDecimal(aItem->getDecimalValue()));
}

inline bool dec_int(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createInteger(result, xqp_integer::parseDecimal(aItem->getDecimalValue()));
}

inline bool dec_bool(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  result = aItem->getEBV();
  return true;
}

inline bool int_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool int_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool int_flt(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createFloat(result, xqp_float::parseInteger(aItem->getIntegerValue()));
}

inline bool int_dbl(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createDouble(result, xqp_double::parseInteger(aItem->getIntegerValue()));
}

inline bool int_dec(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createDecimal(result, xqp_decimal::parseInteger(aItem->getIntegerValue()));
}

inline bool int_bool(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  result = aItem->getEBV();
  return true;
}

inline bool dur_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dur_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dur_yMD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getDurationValue()->toYearMonthDuration();
  return aFactory->createDuration(result, dur);
}

inline bool dur_dTD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getDurationValue()->toDayTimeDuration();
  return aFactory->createDuration(result, dur);
}

inline bool yMD_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool yMD_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool yMD_dur(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getYearMonthDurationValue()->toDuration();
  return aFactory->createDuration(result, dur);
}

inline bool yMD_dTD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getYearMonthDurationValue()->toDayTimeDuration();
  return aFactory->createDuration(result, dur);
}

inline bool dTD_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dTD_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dTD_dur(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getDayTimeDurationValue()->toDuration();
  return aFactory->createDuration(result, dur);
}

inline bool dTD_yMD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getDayTimeDurationValue()->toYearMonthDuration();
  return aFactory->createDuration(result, dur);
}

inline bool dT_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool dT_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool dT_tim(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::TIME_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dT_dat(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::DATE_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dT_gYM(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GYEARMONTH_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dT_gYr(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GYEAR_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dT_gMD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GMONTHDAY_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dT_gDay(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GDAY_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dT_gMon(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GMONTH_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool tim_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool tim_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool dat_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool dat_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool dat_dT(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateValue()->createWithNewFacet(DateTime::DATETIME_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dat_gYM(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateValue()->createWithNewFacet(DateTime::GYEARMONTH_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dat_gYr(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateValue()->createWithNewFacet(DateTime::GYEAR_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dat_gMD(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateValue()->createWithNewFacet(DateTime::GMONTHDAY_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dat_gDay(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateValue()->createWithNewFacet(DateTime::GDAY_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool dat_gMon(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime dt;
  aItem->getDateValue()->createWithNewFacet(DateTime::GMONTH_FACET, dt);
  return aFactory->createTime(result, &dt);
}


inline bool gYM_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool gYM_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool gYr_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool gYr_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool gMD_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool gMD_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool gDay_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool gDay_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool gMon_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool gMon_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool bool_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool bool_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}


inline bool bool_flt(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  if (aItem->getBooleanValue())
    return aFactory->createFloat(result, xqp_float::parseInt(1));
  else
    return aFactory->createFloat(result, xqp_float::zero());
}


inline bool bool_dbl(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  if (aItem->getBooleanValue())
    return aFactory->createDouble(result, xqp_double::parseInt(1));
  else
    return aFactory->createDouble(result, xqp_double::zero());
}

inline bool bool_dec(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  if (aItem->getBooleanValue())
    return aFactory->createDecimal(result, xqp_decimal::parseInt(1));
  else
    return aFactory->createDecimal(result, xqp_decimal::zero());
}

inline bool bool_int(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  if (aItem->getBooleanValue())
    return aFactory->createInteger(result, xqp_integer::parseInt(1));
  else
    return aFactory->createInteger(result, xqp_integer::zero());
}

inline bool b64_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool b64_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool b64_hxB(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createHexBinary(result, xqp_hexBinary(aItem->getBase64BinaryValue()));
}

inline bool hxB_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool hxB_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool hxB_b64(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createBase64Binary(result, xqp_base64Binary(aItem->getHexBinaryValue()));
}

inline bool aURI_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool aURI_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool QN_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool QN_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool NOT_uA(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(result, aItem, aFactory, nsCtx, aErrorInfo);
}

inline bool NOT_str(store::Item_t& result, store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(result, aItem, aFactory, nsCtx, aErrorInfo);
}

const int GenericCast::theMapping[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE] = {
  -1, 1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1, 0, 9,11,10, 6, 8, 7, 2, 3,
   4, 5,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,12,13,14,15,16,17,
  18,19,20,21,22
  };

const GenericCast::CastFunc GenericCast::theCastMatrix[23][23] = {
          /*uA*/     /*str*/    /*flt*/    /*dbl*/    /*dec*/    /*int*/    /*dur*/    /*yMD*/    /*dTD*/    /*dT*/
          /*tim*/    /*dat*/    /*gYM*/    /*gYr*/    /*gMD*/    /*gDay*/   /*gMon*/   /*bool*/   /*b64*/    /*hxB*/
          /*aURI*/   /*QN*/     /*NOT*/
/*uA*/   {&uA_uA,    &uA_str,   &uA_flt,   &uA_dbl,   &uA_dec,   &uA_int,   &uA_dur,   &uA_yMD,   &uA_dTD,   &uA_dT,
          &uA_tim,   &uA_dat,   &uA_gYM,   &uA_gYr,   &uA_gMD,   &uA_gDay,  &uA_gMon,  &uA_bool,  &uA_b64,   &uA_hxB, 
          &uA_aURI,  0,         0},
/*str*/  {&str_uA,   &str_str,  &str_flt,  &str_dbl,  &str_dec,  &str_int,  &str_dur,  &str_yMD,  &str_dTD,  &str_dT,
          &str_tim,  &str_dat,  &str_gYM,  &str_gYr,  &str_gMD,  &str_gDay, &str_gMon, &str_bool, &str_b64,  &uA_hxB, 
          &str_aURI, &str_QN,   &str_NOT},
/*flt*/  {&flt_uA,   &flt_str,  &flt_flt,  &flt_dbl,  &flt_dec,  &flt_int,  0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &flt_bool, 0,         0,
          0,         0,         0},
/*dbl*/  {&dbl_uA,   &dbl_str,  &dbl_flt,  &dbl_dbl,  &dbl_dec,  &dbl_int,  0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &dbl_bool, 0,         0,
          0,         0,         0},
/*dec*/  {&dec_uA,   &dec_str,  &dec_flt,  &dec_dbl,  &dec_dec,  &dec_int,  0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &dec_bool, 0,         0,
          0,         0,         0},
/*int*/  {&int_uA,   &int_str,  &int_flt,  &int_dbl,  &int_dec,  &int_int,  0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &int_bool, 0,         0,
          0,         0,         0},
/*dur*/  {&dur_uA,   &dur_str,  0,         0,         0,         0,         &dur_dur,  &dur_yMD,  &dur_dTD,  0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0},
/*yMD*/  {&yMD_uA,   &yMD_str,  0,         0,         0,         0,         &yMD_dur,  &yMD_yMD,  &yMD_dTD,  0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0},
/*dTD*/  {&dTD_uA,   &dTD_str,  0,         0,         0,         0,         &dTD_dur,  &dTD_yMD,  &dTD_dTD,  0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0},
          /*uA*/     /*str*/    /*flt*/    /*dbl*/    /*dec*/    /*int*/    /*dur*/    /*yMD*/    /*dTD*/    /*dT*/
          /*tim*/    /*dat*/    /*gYM*/    /*gYr*/    /*gMD*/    /*gDay*/   /*gMon*/   /*bool*/   /*b64*/    /*hxB*/
          /*aURI*/   /*QN*/     /*NOT*/
/*dT*/   {&dT_uA,    &dT_str,   0,         0,         0,         0,         0,         0,         0,         &dT_dT,
          &dT_tim,   &dT_dat,   &dT_gYM,   &dT_gYr,   &dT_gMD,   &dT_gDay,  &dT_gMon,  0,         0,         0,
          0,         0,         0},
/*tim*/  {&tim_uA,   &tim_str,  0,         0,         0,         0,         0,         0,         0,         0,
          &tim_tim,  0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0},
/*dat*/  {&dat_uA,   &dat_str,  0,         0,         0,         0,         0,         0,         0,         &dat_dT,
          0,         &dat_dat,  &dat_gYM,  &dat_gYr,  &dat_gMD,  &dat_gDay, &dat_gMon, 0,         0,         0,
          0,         0,         0},
/*gYM*/  {&gYM_uA,   &gYM_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         &gYM_gYM,  0,         0,         0,         0,         0,         0,         0,
          0,         0,         0},
/*gYr*/  {&gYr_uA,   &gYr_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         &gYr_gYr,  0,         0,         0,         0,         0,         0,
          0,         0,         0},
/*gMD*/  {&gMD_uA,   &gMD_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         &gMD_gMD,  0,         0,         0,         0,         0,
          0,         0,         0},
/*gDay*/ {&gDay_uA,  &gDay_str, 0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         &gDay_gDay,0,         0,         0,         0,
          0,         0,         0},
/*gMon*/ {&gMon_uA,  &gMon_str, 0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         &gMon_gMon,0,         0,         0,
          0,         0,         0},
/*bool*/ {&bool_uA,  &bool_str, &bool_flt, &bool_dbl, &bool_dec, &bool_int, 0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         &bool_bool,0,         0,
          0,         0,         0},
/*b64*/  {&b64_uA,   &b64_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         &b64_b64,  &b64_hxB,
          0,         0,         0},
/*hxB*/  {&hxB_uA,   &hxB_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         &hxB_b64,  &hxB_hxB,
          0,         0,         0},
/*aURI*/ {&aURI_uA,  &aURI_str, 0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          &aURI_aURI,0,         0},
/*QN*/   {&QN_uA,    &QN_str,   0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         &QN_QN,    0},
/*NOT*/  {&NOT_uA,   &NOT_str,  0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         0,         0,         0,         0,         0,         0,         0,         0,
          0,         0,         &NOT_NOT}
};


bool str_down(
    store::Item_t& result,
    const store::Item* aItem, 
    RootTypeManager& aTS,
    ATOMICTYPE_T aTargetAtomicType,
    store::ItemFactory* aFactory,
    const ErrorInfo& aErrorInfo)
{
  xqpStringStore_t lString = aItem->getStringValue();

  switch(aTargetAtomicType)
  {
  case TypeConstants::XS_NORMALIZED_STRING:
    if (GenericCast::instance()->castableToNormalizedString(lString))
      return aFactory->createNormalizedString(result, lString);
    break;
  case TypeConstants::XS_TOKEN:
    if (GenericCast::instance()->castableToToken(lString))
      return aFactory->createToken(result, lString);
    break;
  case TypeConstants::XS_LANGUAGE:
    if (GenericCast::instance()->castableToLanguage(lString))
      return aFactory->createLanguage(result, lString);
    break;
  case TypeConstants::XS_NMTOKEN:
    if (GenericCast::instance()->castableToNMToken(lString))
      return aFactory->createNMTOKEN(result, lString);
    break;
  case TypeConstants::XS_NAME:
    if (GenericCast::instance()->castableToName(lString))
      return aFactory->createName(result, lString);
    break;
  case TypeConstants::XS_NCNAME:
    if (GenericCast::instance()->castableToNCName(lString))
      return aFactory->createNCName(result, lString);
    break;
  case TypeConstants::XS_ID:
    if (GenericCast::instance()->castableToNCName(lString))
      return aFactory->createID(result, lString);
    break;
  case TypeConstants::XS_IDREF:
    if (GenericCast::instance()->castableToNCName(lString))
      return aFactory->createIDREF(result, lString);
    break;
  case TypeConstants::XS_ENTITY:
    if (GenericCast::instance()->castableToNCName(lString))
      return aFactory->createENTITY(result, lString);
    break;
  default:
    assert(false);
  }

  throwError(FORG0001, aErrorInfo);
  return 0;
}


bool int_down(
    store::Item_t& result,
    const store::Item* aItem, 
    RootTypeManager& aTS,
    ATOMICTYPE_T aTargetAtomicType,
    store::ItemFactory* aFactory,
    const ErrorInfo& aErrorInfo)
{
  switch(aTargetAtomicType)
  {
  case TypeConstants::XS_NON_POSITIVE_INTEGER:
  {
    xqp_integer lInteger = aItem->getIntegerValue();
    if (lInteger <= xqp_integer::zero())
      return aFactory->createNonPositiveInteger(result, lInteger);
    break;
  }
  case TypeConstants::XS_NEGATIVE_INTEGER:
  {
    xqp_integer lInteger = aItem->getIntegerValue();
    if (lInteger < xqp_integer::zero())
      return aFactory->createNegativeInteger(result, lInteger);
    break;
  }
  case TypeConstants::XS_LONG:
  {
    xqp_long n;
    xqpStringStore_t lString = aItem->getStringValue();
    if (NumConversions::strToLongLong(lString.getp(), n))
      return aFactory->createLong(result, n);
    break;
  }
  case TypeConstants::XS_INT:
  {
    xqp_int n;
    xqpStringStore_t lString = aItem->getStringValue();
    if (NumConversions::strToInt(lString.getp(), n))
      return aFactory->createInt(result, n);
    break;
  }
  case TypeConstants::XS_SHORT:
  {
    xqp_short n;
    xqpStringStore_t lString = aItem->getStringValue();
    if (NumConversions::strToShort(lString.getp(), n))
      return aFactory->createShort(result, n);
    break;
  }
  case TypeConstants::XS_BYTE:
  {
    xqp_byte n;
    xqpStringStore_t lString = aItem->getStringValue();
    if (NumConversions::strToByte(lString.getp(), n))
      return aFactory->createByte(result, n);
    break;
  }
  case TypeConstants::XS_NON_NEGATIVE_INTEGER:
  {
    xqp_integer lInteger = aItem->getIntegerValue();
    if (lInteger >= xqp_integer::zero())
      return aFactory->createNonNegativeInteger(result, lInteger);
    break;
  }
  case TypeConstants::XS_UNSIGNED_LONG:
  {
    xqp_ulong n;
    xqpStringStore_t lString = aItem->getStringValue();
    if (NumConversions::strToULongLong(lString.getp(), n))
      return aFactory->createUnsignedLong(result, n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_INT:
  {
    xqp_uint n;
    xqpStringStore_t lString = aItem->getStringValue();
    if (NumConversions::strToUInt(lString.getp(), n))
      return aFactory->createUnsignedInt(result, n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_SHORT:
  {
    xqp_ushort n;
    xqpStringStore_t lString = aItem->getStringValue();
    if (NumConversions::strToUShort(lString.getp(), n))
      return aFactory->createUnsignedShort(result, n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_BYTE:
  {
    xqp_ubyte n;
    xqpStringStore_t lString = aItem->getStringValue();
    if (NumConversions::strToUByte(lString.getp(), n))
      return aFactory->createUnsignedByte(result, n);
    break;
  }
  case TypeConstants::XS_POSITIVE_INTEGER:
  {
    xqp_integer lInteger = aItem->getIntegerValue();
    if (lInteger > xqp_integer::zero())
      return aFactory->createPositiveInteger(result, lInteger);
    break;
  }
  default:
    assert(false);
  }
  throwError(FORG0001, aErrorInfo);
  return 0;
}


const GenericCast::DownCastFunc GenericCast::theDownCastMatrix[23] = {
/*uA*/  0, /*str*/ str_down, /*flt*/ 0, /*dbl*/ 0, /*dec*/ 0, /*int*/ int_down, /*dur*/ 0, 
/*yMD*/ 0, /*dTD*/ 0, /*dT*/  0, /*tim*/ 0, /*dat*/ 0, /*gYM*/ 0, /*gYr*/ 0, /*gMD*/ 0,
/*gDay*/0, /*gMon*/0, /*bool*/0, /*b64*/ 0, /*hxB*/ 0, /*aURI*/0, /*QN*/  0, /*NOT*/ 0
};


GenericCast* GenericCast::instance()
{
  static GenericCast aGenericCast;
  return &aGenericCast;
}

#ifndef ZORBA_NO_XMLSCHEMA
store::Item_t castUserDefinedType(store::Item* aItem,
                                  const ErrorInfo& aErrorInfo)
{
  const DelegatingTypeManager* lDelegatingTypeManager 
    = static_cast<const DelegatingTypeManager*>(aErrorInfo.theTargetType->get_manager()); 

  if ( aErrorInfo.theSourceType->type_kind() == XQType::ATOMIC_TYPE_KIND
    && (TypeOps::get_atomic_type_code(*aErrorInfo.theSourceType) 
        == TypeConstants::XS_STRING))
  {
    store::Item_t lResult;
    if (lDelegatingTypeManager->getSchema()
        ->parseUserAtomicTypes(xqpString(aItem->getStringValue()), 
                               aErrorInfo.theSourceType,
                               aErrorInfo.theTargetType,
                               lResult))
    {
      return lResult;
    }
  }

  throwError(FORG0001, aErrorInfo); 
  return 0;
}
#endif


/*******************************************************************************

********************************************************************************/
bool GenericCast::cast(
    store::Item_t& result,
    store::Item* aItem, 
    const XQType* aTargetType,
    namespace_context* aNCtx) const
{
  RootTypeManager& lTS = GENV_TYPESYSTEM;
  store::ItemFactory* lFactory = GENV_ITEMFACTORY;

  xqtref_t lSourceType = lTS.create_named_type(
                               aItem->getType(), 
                               TypeConstants::QUANT_ONE);

  ErrorInfo lErrorInfo = {&*lSourceType, aTargetType};

#ifndef ZORBA_NO_XMLSCHEMA
  if (aTargetType->type_kind() == XQType::USER_DEFINED_KIND) {
    result = castUserDefinedType(aItem, lErrorInfo);
    return result != NULL;
  }
#endif

  if (!TypeOps::is_atomic(*aTargetType))
    throwError(XPST0051, lErrorInfo);

  store::Item_t lSourceItem;
  xqtref_t lPrimitiveSourceType;
  if (TypeOps::is_atomic(*lSourceType))
  {
    lPrimitiveSourceType = TypeOps::cast_primitive_type(*lSourceType);
    lSourceItem = aItem;
  } else {
    lPrimitiveSourceType = lTS.STRING_TYPE_ONE;
    xqpStringStore_t strval = aItem->getStringValue();
    lFactory->createString(lSourceItem, strval);
  }

  ATOMICTYPE_T lPrimitiveSourceAtomicType 
    = TypeOps::get_atomic_type_code(*lPrimitiveSourceType);
  int lPrimitiveSourceMapping = theMapping[lPrimitiveSourceAtomicType];

  xqtref_t lPrimitiveTargetType = TypeOps::cast_primitive_type(*aTargetType);
  ATOMICTYPE_T lPrimitiveTargetAtomicType
    = TypeOps::get_atomic_type_code(*lPrimitiveTargetType);
  int lPrimitiveTargetMapping = theMapping[lPrimitiveTargetAtomicType];

  if ( lPrimitiveSourceAtomicType == TypeConstants::XS_NOTATION 
    || lPrimitiveTargetAtomicType == TypeConstants::XS_NOTATION)
    throwError(XPST0080, lErrorInfo);

  if ( lPrimitiveSourceAtomicType == TypeConstants::XS_ANY_ATOMIC
    || lPrimitiveTargetAtomicType == TypeConstants::XS_ANY_ATOMIC)
    throwError(XPST0080, lErrorInfo);

  CastFunc lCastFunc = theCastMatrix[lPrimitiveSourceMapping][lPrimitiveTargetMapping];

  if (lCastFunc == 0)
    throwError(XPTY0004, lErrorInfo);


  bool valid = (*lCastFunc)(result,
                                       lSourceItem, 
                                       lFactory, 
                                       aNCtx,
                                       lErrorInfo);

  if (!TypeOps::is_equal(*aTargetType, *lPrimitiveTargetType))
  {
    DownCastFunc lDownCastFunc = theDownCastMatrix[lPrimitiveTargetMapping];

    if (lDownCastFunc == 0)
      throwError(XPTY0004, lErrorInfo);

    ATOMICTYPE_T lTargetAtomicType
      = TypeOps::get_atomic_type_code(*aTargetType);
    valid = (*lDownCastFunc)(result,
                               &*result, 
                               lTS, 
                               lTargetAtomicType, 
                               lFactory,
                               lErrorInfo);
  }

  return valid;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::cast(
    store::Item_t& result,
    xqpStringStore_t& aStr,
    const XQType* aTargetType,
    namespace_context* aNCtx) const
{
  return GENV_ITEMFACTORY->createString(result, aStr)
      && cast(result, result, aTargetType, aNCtx);
}


/*******************************************************************************
  Casts a string to a qname.
********************************************************************************/
bool GenericCast::castToQName (
    store::Item_t& result,
    xqpStringStore_t& qname,
    namespace_context* aNCtx) const
{
  return GENV_ITEMFACTORY->createString(result, qname)
    && cast(result, result, &*GENV_TYPESYSTEM.QNAME_TYPE_ONE, aNCtx);
}


/*******************************************************************************
  NCName				  ::= NCNameStartChar NCNameChar* // An XML Name, minus the ":" 
  NCNameChar      ::= NameChar - ':' 
  NCNameStartChar ::= Letter | '_' 
  NameChar			  ::= Letter | Digit | '.' | '-' | '_' | ':' | CombiningChar |
                      Extender 
********************************************************************************/
bool GenericCast::castableToNCName(const xqpStringStore* str) const
{
	uint32_t	cp;

	std::vector<uint32_t> cps = str->getCodepoints();
	std::vector<uint32_t>::size_type	i, cps_size = cps.size();

	if(cps_size == 0)
		return false;

	cp = cps[0];

	if(!XQCharType::isLetter(cp) && (cp != '_'))
		return false;

	for(i=1;i<cps_size;i++)
	{
		cp = cps[i];

		if(!XQCharType::isLetter(cp) && !XQCharType::isDigit(cp) &&
			(cp != '.') && (cp != '-') && (cp != '_') &&
			!XQCharType::isCombiningChar(cp) && !XQCharType::isExtender(cp))
			return false;
	}

  return true;
}


bool GenericCast::castableToNormalizedString(const xqpStringStore *str) const
{
  uint32_t cp;
  std::vector<uint32_t> cps = str->getCodepoints();
  std::vector<uint32_t>::size_type i, sz = cps.size();

  if (sz == 0) {
    return false;
  }

  for(i = 0; i < sz; ++i) {
    cp = cps[i];
    /* do not contain the carriage return (#xD), line feed (#xA) nor tab (#x9) characters */
    if (cp == '\r' || cp == '\n' || cp == '\t') {
      return false;
    }
  }

  return true;
}


bool GenericCast::castableToToken(const xqpStringStore *str) const
{
  uint32_t cp;
  std::vector<uint32_t> cps = str->getCodepoints();
  std::vector<uint32_t>::size_type i, sz = cps.size();

  if (sz == 0) {
    return false;
  }

  bool spaceSeen = false;
  for(i = 0; i < sz; ++i) {
    cp = cps[i];
    /* do not contain the carriage return (#xD), line feed (#xA) nor tab (#x9) characters */
    if (cp == '\r' || cp == '\n' || cp == '\t') {
      return false;
    }
    if (cp == ' ') {
      /* two consecutive spaces not allowed. */
      if (spaceSeen) {
        return false;
      }
      /* no leading or trailing spaces */
      if (i == 0 || i == sz - 1) {
        return false;
      }
      spaceSeen = true;
    } else {
      spaceSeen = false;
    }
  }

  return true;
}


bool GenericCast::castableToLanguage(const xqpStringStore *str) const
{
  uint32_t cp;
  std::vector<uint32_t> cps = str->getCodepoints();
  std::vector<uint32_t>::size_type i, sz = cps.size();

  if (sz == 0) {
    return false;
  }

  /* automaton for [a-zA-Z]{1,8}(-[a-zA-Z0-9]{1,8})* */
  bool firstBlock = true;
  i = 0;
  uint32_t blkIdx = 0;
  while(i < sz) {
    cp = cps[i];
    if (cp == '-') {
      if (blkIdx == 0) {
        return false;
      }
      blkIdx = 0;
      ++i;
      continue;
    }
    if (blkIdx >= 8) {
      return false;
    }
    if (!((cp >= 'A' && cp <= 'Z') || (cp >= 'a' && cp <= 'z'))) {
      if (firstBlock) {
        return false;
      }
      if (!(cp >= '0' && cp <= '9')) {
        return false;
      }
    }
    ++i;
    ++blkIdx;
  }
  if (blkIdx == 0) {
    return false;
  }
  return true;
}


bool GenericCast::castableToNMToken(const xqpStringStore *str) const
{
  uint32_t cp;
  std::vector<uint32_t> cps = str->getCodepoints();
  std::vector<uint32_t>::size_type i, sz = cps.size();

  if (sz == 0) {
    return false;
  }

  for(i = 0; i < sz; ++i) {
    cp = cps[i];
    if (!(XQCharType::isLetter(cp)
      || XQCharType::isDigit(cp)
      || XQCharType::isExtender(cp)
      || XQCharType::isCombiningChar(cp)
      || cp == '.'
      || cp == '-'
      || cp == '_'
      || cp == ':')) {
      return false;
    }
  }

  return true;
}

bool GenericCast::castableToName(const xqpStringStore *str) const
{
  uint32_t cp;
  std::vector<uint32_t> cps = str->getCodepoints();
  std::vector<uint32_t>::size_type i, sz = cps.size();

  if (sz == 0) {
    return false;
  }

  for(i = 0; i < sz; ++i) {
    cp = cps[i];
    if (!(XQCharType::isLetter(cp)
      || cp == '_'
      || cp == ':')) {
      if (i == 0) {
        return false;
      }
      if (!(XQCharType::isDigit(cp)
        || XQCharType::isExtender(cp)
        || XQCharType::isCombiningChar(cp)
        || cp == '.'
        || cp == '-')) {
        return false;
      }
    }
  }

  return true;
}

/*******************************************************************************

********************************************************************************/
bool GenericCast::isCastable(store::Item* aItem, const XQType* aTargetType) const
{
  RootTypeManager& lTS = GENV_TYPESYSTEM;

  xqtref_t lSourceType = lTS.create_named_type(aItem->getType(), 
                                               TypeConstants::QUANT_ONE);

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
      store::Item_t temp;
      return cast(temp, aItem, aTargetType);
    }
    catch (error::ZorbaError& e)
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
    xqpStringStore_t& aStr,
    const XQType* aTargetType) const
{
  store::Item_t lItem;
  GENV_ITEMFACTORY->createString(lItem, aStr);
  return isCastable(lItem, aTargetType);
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::promote(
    store::Item_t& result,
    store::Item_t aItem,
    const XQType* aTargetType) const
{
  xqtref_t lItemType = GENV_TYPESYSTEM.create_value_type(aItem);

  if (TypeOps::is_equal (*aTargetType, *GENV_TYPESYSTEM.NONE_TYPE))
      return false;

  if (TypeOps::is_subtype(*lItemType, *aTargetType)) {
    result = aItem;
    return result != NULL;
  }

  store::Item_t lResult = 0;
  if (TypeOps::is_equal(*lItemType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
      && ! TypeOps::is_equal(*TypeOps::prime_type (*aTargetType), *GENV_TYPESYSTEM.QNAME_TYPE_ONE))
    return GenericCast::instance()->cast(result, aItem, aTargetType);
  else if (TypeOps::is_subtype(*aTargetType, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
    // Numeric Promotion to xs:float
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)) {
      return GenericCast::instance()->cast(result, aItem, &*GENV_TYPESYSTEM.FLOAT_TYPE_ONE); 
    }
  } else if (TypeOps::is_subtype(*aTargetType, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)) {
    // Numeric Promotion to xs:double
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)
     || TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
      return GenericCast::instance()->cast(result, aItem, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
    }
  } else if (TypeOps::is_subtype(*aTargetType, *GENV_TYPESYSTEM.STRING_TYPE_ONE)) {
    // URI Promotion
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) {
      return GenericCast::instance()->cast(result, aItem, &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
  }
  return false;
}


/*******************************************************************************

********************************************************************************/

#undef ATOMIC_TYPE


/* end class GenericCast */
} /* namespace zorba */
