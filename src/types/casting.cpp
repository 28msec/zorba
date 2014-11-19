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
#include <zorba/internal/unique_ptr.h>

#include "zorbatypes/chartype.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/float.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/URI.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "context/namespace_context.h"

#include "system/globalenv.h"

#include "store/api/item_factory.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include <zorba/store_consts.h>

#include "types/typeops.h"
#include "types/typemanagerimpl.h"
#include "types/schema/schema.h"
#include "types/casting.h"

#include "context/static_context.h"

#include "compiler/parser/query_loc.h"


namespace zorba
{


#define ATOMIC_TYPE(type) \
  GENV_TYPESYSTEM.create_atomic_type(store::XS_##type, SequenceType::QUANT_ONE)


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


void throwXPTY0004Exception(const ErrorInfo& info)
{              
  if (info.theSourceType)
  {                      
    RAISE_ERROR(err::XPTY0004, info.theLoc,
    ERROR_PARAMS(*info.theSourceType, ZED(NoCastTo_34o), *info.theTargetType));
  }                                           
  else                                        
  {
    TypeManager& tm = GENV_TYPESYSTEM;
                                     
    xqtref_t sourceType =
    tm.create_builtin_atomic_type(info.theSourceTypeCode,
                                  SequenceType::QUANT_ONE);

    xqtref_t targetType =
    tm.create_builtin_atomic_type(info.theTargetTypeCode,
                                  SequenceType::QUANT_ONE);

    RAISE_ERROR(err::XPTY0004, info.theLoc,
    ERROR_PARAMS(*sourceType, ZED(NoCastTo_34o), *targetType));
  }                                           
}


void throwFOCA0002Exception(const zstring& str, const ErrorInfo& info)
{              
  if (info.theSourceType)
  {                      
    RAISE_ERROR(err::FOCA0002, info.theLoc,
    ERROR_PARAMS(ZED(FOCA0002_NoCastTo_234),
                 str,
                 info.theSourceType->toSchemaString(),
                 info.theTargetType->toSchemaString()));
  }                                           
  else                                        
  {
    TypeManager& tm = GENV_TYPESYSTEM;
                                     
    xqtref_t sourceType =
    tm.create_builtin_atomic_type(info.theSourceTypeCode,
                                  SequenceType::QUANT_ONE);

    xqtref_t targetType =
    tm.create_builtin_atomic_type(info.theTargetTypeCode,
                                  SequenceType::QUANT_ONE);

    RAISE_ERROR(err::FOCA0002, info.theLoc,
    ERROR_PARAMS(ZED(FOCA0002_NoCastTo_234),
                 str,
                 sourceType->toSchemaString(),
                 targetType->toSchemaString()));
  }                                           
}


void throwFOCA0003Exception(const zstring& str, const ErrorInfo& info)
{              
  if (info.theSourceType)
  {                      
    throw XQUERY_EXCEPTION(
      err::FOCA0003,
      ERROR_PARAMS(
        str,
        info.theSourceType->toSchemaString(),
        info.theTargetType->toSchemaString()
      ),
      ERROR_LOC( info.theLoc )
    );
  }                                           
  else                                        
  {
    TypeManager& tm = GENV_TYPESYSTEM;
                                     
    xqtref_t sourceType =
    tm.create_builtin_atomic_type(info.theSourceTypeCode,
                                  SequenceType::QUANT_ONE);

    xqtref_t targetType =
    tm.create_builtin_atomic_type(info.theTargetTypeCode,
                                  SequenceType::QUANT_ONE);

    throw XQUERY_EXCEPTION(
      err::FOCA0003,
      ERROR_PARAMS(
        str,
        sourceType->toSchemaString(),
        targetType->toSchemaString()
      ),
      ERROR_LOC( info.theLoc )
    );
  }                                           
}


void throwFORG0001Exception(const zstring& str, const ErrorInfo& info)
{              
  if (info.theTargetType)
  {                      
    RAISE_ERROR(err::FORG0001, info.theLoc,
    ERROR_PARAMS(ZED(FORG0001_NoCastTo_234),
                 str,
                 info.theSourceType->toSchemaString(),
                 info.theTargetType->toSchemaString()));
  }                                           
  else                                        
  {
    TypeManager& tm = GENV_TYPESYSTEM;

    xqtref_t sourceType =
    tm.create_builtin_atomic_type(info.theSourceTypeCode,
                                  SequenceType::QUANT_ONE);

    xqtref_t targetType =
    tm.create_builtin_atomic_type(info.theTargetTypeCode,
                                  SequenceType::QUANT_ONE);

    RAISE_ERROR(err::FORG0001, info.theLoc,
    ERROR_PARAMS(ZED(FORG0001_NoCastTo_234),
                 str,
                 sourceType->toSchemaString(),
                 targetType->toSchemaString()));
  }                                           
}

void throwFODT0001Exception(const zstring& str, const ErrorInfo& info)
{
  if (info.theTargetType)
  {
    RAISE_ERROR(err::FODT0001, info.theLoc,
    ERROR_PARAMS(ZED(FORG0001_NoCastTo_234),
                 str,
                 info.theSourceType->toSchemaString(),
                 info.theTargetType->toSchemaString()));
  }
  else
  {
    TypeManager& tm = GENV_TYPESYSTEM;

    xqtref_t sourceType =
    tm.create_builtin_atomic_type(info.theSourceTypeCode,
                                  SequenceType::QUANT_ONE);

    xqtref_t targetType =
    tm.create_builtin_atomic_type(info.theTargetTypeCode,
                                  SequenceType::QUANT_ONE);

    RAISE_ERROR(err::FODT0001, info.theLoc,
    ERROR_PARAMS(ZED(FORG0001_NoCastTo_234),
                 str,
                 sourceType->toSchemaString(),
                 targetType->toSchemaString()));
  }
}


void throwFODT0002Exception(const zstring& str, const ErrorInfo& info)
{
  if (info.theTargetType)
  {
    RAISE_ERROR(err::FODT0002, info.theLoc,
    ERROR_PARAMS(ZED(FORG0001_NoCastTo_234),
                 str,
                 info.theSourceType->toSchemaString(),
                 info.theTargetType->toSchemaString()));
  }
  else
  {
    TypeManager& tm = GENV_TYPESYSTEM;

    xqtref_t sourceType =
    tm.create_builtin_atomic_type(info.theSourceTypeCode,
                                  SequenceType::QUANT_ONE);

    xqtref_t targetType =
    tm.create_builtin_atomic_type(info.theTargetTypeCode,
                                  SequenceType::QUANT_ONE);

    RAISE_ERROR(err::FODT0002, info.theLoc,
    ERROR_PARAMS(ZED(FORG0001_NoCastTo_234),
                 str,
                 sourceType->toSchemaString(),
                 targetType->toSchemaString()));
  }
}


/*******************************************************************************
  Identity casting functions: target type is the same as the source one, so no
  casting is actually done.
********************************************************************************/
#define SAME_S_AND_T(type)    \
inline bool type##_##type(    \
    store::Item_t& result,    \
    const store::Item* aItem, \
    zstring&,                 \
    store::ItemFactory*,      \
    const namespace_context*, \
    const ErrorInfo&,         \
    bool)                     \
{                             \
  result = (aItem);           \
  return true;                \
}                             \

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
SAME_S_AND_T(uint)
SAME_S_AND_T(dTSt)

#undef SAME_S_AND_T


#define T1_TO_T2(type1, type2)      \
inline bool type1##_##type2(        \
    store::Item_t& result,          \
    const store::Item* aItem,       \
    zstring& strval,                \
    store::ItemFactory* aFactory,   \
    const namespace_context* nsCtx, \
    const ErrorInfo& errInfo,       \
    bool throw_on_error)


T1_TO_T2(str, uA)
{
  aFactory->createUntypedAtomic(result, strval);
  return true;
}


T1_TO_T2(str, flt)
{
  try 
  {
    xs_float const n(strval);
    aFactory->createFloat(result, n);
    return true;
  }
  catch (std::invalid_argument const&) 
  {
    if ( throw_on_error )
      throwFORG0001Exception(strval, errInfo);
  }
  catch (const std::range_error&)
  {
    if ( throw_on_error )
      RAISE_ERROR(err::FOAR0002, errInfo.theLoc, ERROR_PARAMS(strval));
  }
  return false;
}


T1_TO_T2(str, dbl)
{
  try 
  {
    xs_double const n(strval);
    aFactory->createDouble(result, n);
    return true;
  }
  catch (std::invalid_argument const&)
  {
    if ( throw_on_error )
      throwFORG0001Exception(strval, errInfo);
  }
  catch (const std::range_error&)
  {
    if ( throw_on_error )
      RAISE_ERROR(err::FOAR0002, errInfo.theLoc, ERROR_PARAMS(strval));
  }
  return false;
}


T1_TO_T2(str, dec)
{
  try 
  {
    xs_decimal const n(strval);
    aFactory->createDecimal(result, n);
    return true;
  }
  catch (const std::invalid_argument&)
  {
    if ( throw_on_error )
      throwFOCA0002Exception(strval, errInfo);
  }
  catch (const std::range_error&)
  {
    if ( throw_on_error )
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, int)
{
  try 
  {
    xs_integer const n(strval);
    aFactory->createInteger(result, n);
    return true;
  }
  catch (const std::invalid_argument& ) 
  {
    if ( throw_on_error )
      throwFOCA0002Exception(strval, errInfo);
  }
  catch (const std::range_error& ) 
  {
    if ( throw_on_error )
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, uint)
{
  try 
  {
    xs_nonNegativeInteger const n(strval);
    aFactory->createNonNegativeInteger(result, n);
    return true;
  }
  catch ( std::invalid_argument const& )
  {
    if ( throw_on_error )
      throwFOCA0002Exception(strval, errInfo);
  }
  catch ( std::range_error const& )
  {
    if ( throw_on_error )
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, dur)
{
  Duration d;
  int err = Duration::parseDuration(strval.c_str(), strval.size(), d);
  if (err == 0) {
    aFactory->createDuration(result, &d);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0002Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, yMD)
{
  Duration d;
  int err = Duration::parseYearMonthDuration(strval.c_str(), strval.size(), d);
  if (err == 0) {
    aFactory->createYearMonthDuration(result, &d);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0002Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
    }
  return false;
}


T1_TO_T2(str, dTD)
{
  Duration d;
  int err = Duration::parseDayTimeDuration(strval.c_str(), strval.size(), d);
  if (err == 0) {
    aFactory->createDayTimeDuration(result, &d);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0002Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, dT)
{
  xs_dateTime dt;
  int err = DateTime::parseDateTime(strval.c_str(), strval.size(), dt);
  if (err == 0) {
    aFactory->createDateTime(result, &dt);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, dTSt)
{
  xs_dateTime dt;
  int err = DateTime::parseDateTime(strval.c_str(), strval.size(), dt);
  if (err == 0 && dt.hasTimezone()) {
    aFactory->createDateTimeStamp(result, &dt);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}
  
  
T1_TO_T2(str, tim)
{
  xs_time t;
  int err = DateTime::parseTime(strval.c_str(), strval.size(), t);
  if (err == 0) {
    aFactory->createTime(result, &t);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
    }
  return false;
}


T1_TO_T2(str, dat)
{
  xs_date d;
  int err = DateTime::parseDate(strval.c_str(), strval.size(), d);
  if (err == 0) {
    aFactory->createDate(result, &d);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, gYM)
{
  xs_gYearMonth ym;
  int err = DateTime::parseGYearMonth(strval.c_str(), strval.size(), ym);
  if (err == 0) {
    aFactory->createGYearMonth(result, &ym);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, gYr)
{
  xs_gYear y;
  int err = DateTime::parseGYear(strval.c_str(), strval.size(), y);
  if (err == 0) {
    aFactory->createGYear(result, &y);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, gMD)
{
  xs_gMonthDay md;
  int err = DateTime::parseGMonthDay(strval.c_str(), strval.size(), md);
  if (err == 0) {
    aFactory->createGMonthDay(result, &md);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, gDay)
{
  xs_gDay d;
  int err = DateTime::parseGDay(strval.c_str(), strval.size(), d);
  if (err == 0) {
    aFactory->createGDay(result, &d);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, gMon)
{
  xs_gMonth m;
  int err = DateTime::parseGMonth(strval.c_str(), strval.size(), m);
  if (err == 0) {
    aFactory->createGMonth(result, &m);
    return true;
  }
  if ( throw_on_error ) {
    if (err == 2)
      throwFODT0001Exception(strval, errInfo);
    else
      throwFORG0001Exception(strval, errInfo);
  }
  return false;
}


T1_TO_T2(str, bool)
{
  bool lRetValue = true;
  const char* str = strval.c_str();
  zstring::size_type len = strval.size();
  zstring::size_type pos = 0;

  ascii::skip_space(str, len, &pos);

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
    if ( throw_on_error )
      throwFORG0001Exception(strval, errInfo);
    return false;
  }

  pos = str - strval.c_str();
  ascii::skip_space(strval.c_str(), len, &pos);

  if (pos != len)
  {
    if ( throw_on_error )
      throwFORG0001Exception(strval, errInfo);
    return false;
  }

  aFactory->createBoolean(result, lRetValue);
  return true;
}


T1_TO_T2(str, b64)
{
  xs_base64Binary n;
  if (xs_base64Binary::parseString(strval, n))
  {
    aFactory->createBase64Binary(result, n);
    return true;
  }
  if ( throw_on_error )
    throwFORG0001Exception(strval, errInfo);
  return false;
}


T1_TO_T2(str, hxB)
{
  xs_hexBinary n;
  if (xs_hexBinary::parseString(strval, n))
  {
    aFactory->createHexBinary(result, n);
    return true;
  }
  if ( throw_on_error )
    throwFORG0001Exception(strval, errInfo);
  return false;
}


T1_TO_T2(str, aURI)
{
  try
  {
    URI uriVal(strval);
    zstring resolvedUri( uriVal.toString() );
    aFactory->createAnyURI(result, resolvedUri);
    return true;
  }
  catch (ZorbaException& e)
  {
    if ( throw_on_error ) {
      e.set_diagnostic(err::FORG0001);
      throw;
    }
  }
  return false;
}


T1_TO_T2(str, QN)
{
  ascii::trim_space(strval);

  zstring::size_type idx = strval.find(":");
  zstring::size_type lidx = strval.rfind(":", strval.size(), 1);

  if (idx != lidx) {
    if ( throw_on_error )
      throwFORG0001Exception(strval, errInfo);
    return false;
  }

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

    if (!GenericCast::castableToNCName(prefix))
    {
      if ( throw_on_error ) {
        RAISE_ERROR(err::FORG0001, errInfo.theLoc,
        ERROR_PARAMS(ZED(FORG0001_PrefixNotNCName_2), prefix));
      }
      return false;
    }

    if (nsCtx)
    {
      if (!nsCtx->findBinding(prefix, nsuri)) {
        if ( throw_on_error )
          RAISE_ERROR(err::FONS0004, errInfo.theLoc, ERROR_PARAMS(prefix));
        return false;
      }
    }

    local = strval.substr(idx + 1);
  }

  if (!GenericCast::castableToNCName(local))
  {
    if ( throw_on_error ) {
      RAISE_ERROR(err::FORG0001, errInfo.theLoc,
      ERROR_PARAMS(ZED(FORG0001_LocalNotNCName_2), local));
    }
    return false;
  }

  aFactory->createQName(result, nsuri, prefix, local);
  return true;
}


T1_TO_T2(str, NOT)
{
  ascii::trim_space(strval);

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
  {
    local = strval;
  }

  if (!nsCtx->findBinding(prefix, uri))
  {
    if ( throw_on_error ) {
      RAISE_ERROR(err::FORG0001, errInfo.theLoc, 
      ERROR_PARAMS(ZED(FORG0001_PrefixNotBound_2), prefix));
    }
    return false;
  }

  store::Item_t qname;
  aFactory->createQName(qname, uri, prefix, local);
  aFactory->createNOTATION(result, qname);
  return true;
}


T1_TO_T2(uA, str)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  aFactory->createString(result, strval2);
  return true;
}


T1_TO_T2(uA, flt)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_flt(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, dbl)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dbl(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, dec)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dec(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, int)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_int(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, dur)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dur(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, yMD)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_yMD(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, dTD)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dTD(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, dT)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dT(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, dTSt)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dTSt(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}
  
  
T1_TO_T2(uA, tim)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_tim(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, dat)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_dat(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, gYM)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gYM(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, gYr)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gYr(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, gMD)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gMD(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, gDay)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gDay(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, gMon)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_gMon(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, bool)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_bool(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, b64)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_b64(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, hxB)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_hxB(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, aURI)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_aURI(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uA, QN)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_QN(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(flt, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(flt, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(flt, dbl)
{
  aFactory->createDouble(result, xs_double(aItem->getFloatValue()));
  return true;
}


T1_TO_T2(flt, dec)
{
  try 
  {
    xs_decimal const n( aItem->getFloatValue() );
    aFactory->createDecimal(result, n);
    return true;
  }
  catch (const std::exception&) 
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(flt, int)
{
  try 
  {
    xs_integer const n( aItem->getFloatValue() );
    aFactory->createInteger(result, n);
    return true;
  }
  catch ( std::invalid_argument const& )
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  catch (const std::range_error&) 
  {
    if ( throw_on_error )
      throwFOCA0003Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(flt, bool)
{
  aFactory->createBoolean(result, aItem->getEBV());
  return true;
}


T1_TO_T2(dbl, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dbl, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dbl, flt)
{
  aFactory->createFloat(result, xs_float(aItem->getDoubleValue()));
  return true;
}


T1_TO_T2(dbl, dec)
{
  try 
  {
    xs_decimal const n( aItem->getDoubleValue() );
    aFactory->createDecimal(result, n);
    return true;
  }
  catch (const std::exception&) 
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(dbl, int)
{
  try 
  {
    xs_integer const n( aItem->getDoubleValue() );
    aFactory->createInteger(result, n);
    return true;
  }
  catch ( std::invalid_argument const& )
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  catch (const std::range_error&) 
  {
    if ( throw_on_error )
      throwFOCA0003Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(dbl, bool)
{
  aFactory->createBoolean(result, aItem->getEBV());
  return true;
}


T1_TO_T2(dec, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dec, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dec, flt)
{
  aFactory->createFloat(result, xs_float(aItem->getDecimalValue()));
  return true;
}


T1_TO_T2(dec, dbl)
{
  aFactory->createDouble(result, xs_double(aItem->getDecimalValue()));
  return true;
}


T1_TO_T2(dec, int)
{
  aFactory->createInteger(result, xs_integer(aItem->getDecimalValue()));
  return true;
}


T1_TO_T2(dec, bool)
{
  aFactory->createBoolean(result, aItem->getEBV());
  return true;
}


T1_TO_T2(int, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(int, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(int, flt)
{
  aFactory->createFloat(result, xs_float(aItem->getIntegerValue()));
  return true;
}


T1_TO_T2(int, dbl)
{
  aFactory->createDouble(result, xs_double(aItem->getIntegerValue()));
  return true;
}


T1_TO_T2(int, dec)
{
  aFactory->createDecimal(result, xs_decimal(aItem->getIntegerValue()));
  return true;
}


T1_TO_T2(int, bool)
{
  aFactory->createBoolean(result, aItem->getEBV());
  return true;
}


T1_TO_T2(dur, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dur, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dur, yMD)
{
  std::unique_ptr<Duration> dur =
  std::unique_ptr<Duration>(aItem->getDurationValue().toYearMonthDuration());
  aFactory->createYearMonthDuration(result, dur.get());
  return true;
}


T1_TO_T2(dur, dTD)
{
  std::unique_ptr<Duration> dur =
  std::unique_ptr<Duration>(aItem->getDurationValue().toDayTimeDuration());
  aFactory->createDayTimeDuration(result, dur.get());
  return true;
}


T1_TO_T2(yMD, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(yMD, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(yMD, dur)
{
  std::unique_ptr<Duration> dur =
  std::unique_ptr<Duration>(aItem->getYearMonthDurationValue().toDuration());
  aFactory->createDuration(result, dur.get());
  return true;
}


T1_TO_T2(yMD, dTD)
{
  std::unique_ptr<Duration> dur =
  std::unique_ptr<Duration>(aItem->getYearMonthDurationValue().toDayTimeDuration());
  aFactory->createDayTimeDuration(result, dur.get());
  return true;
}


T1_TO_T2(dTD, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dTD, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dTD, dur)
{
  std::unique_ptr<Duration> dur =
  std::unique_ptr<Duration>(aItem->getDayTimeDurationValue().toDuration());
  aFactory->createDuration(result, dur.get());
  return true;
}


T1_TO_T2(dTD, yMD)
{
  std::unique_ptr<Duration> dur =
  std::unique_ptr<Duration>(aItem->getDayTimeDurationValue().toYearMonthDuration());
  aFactory->createYearMonthDuration(result, dur.get());
  return true;
}


T1_TO_T2(dT, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dT, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dT, tim)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::TIME_FACET, dt);
  aFactory->createTime(result, &dt);
  return true;
}


T1_TO_T2(dT, dat)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::DATE_FACET, dt);
  aFactory->createDate(result, &dt);
  return true;
}


T1_TO_T2(dT, gYM)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GYEARMONTH_FACET, dt);
  aFactory->createGYearMonth(result, &dt);
  return true;
}


T1_TO_T2(dT, gYr)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GYEAR_FACET, dt);
  aFactory->createGYear(result, &dt);
  return true;
}


T1_TO_T2(dT, gMD)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GMONTHDAY_FACET, dt);
  aFactory->createGMonthDay(result, &dt);
  return true;
}


T1_TO_T2(dT, gDay)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GDAY_FACET, dt);
  aFactory->createGDay(result, &dt);
  return true;
}


T1_TO_T2(dT, gMon)
{
  DateTime dt;
  aItem->getDateTimeValue().createWithNewFacet(DateTime::GMONTH_FACET, dt);
  aFactory->createGMonth(result, &dt);
  return true;
}


T1_TO_T2(tim, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(tim, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dat, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dat, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(dat, dT)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::DATETIME_FACET, dt);
  aFactory->createDateTime(result, &dt);
  return true;
}


T1_TO_T2(dT, dTSt)
{
  xs_dateTime const dt( aItem->getDateTimeValue() );
  if (dt.hasTimezone() )
  {
    aFactory->createDateTimeStamp(result, &dt);
    return true;
  }
  if ( throw_on_error )
    throwFORG0001Exception(dt.toString(), errInfo);
  return false;
}
  
  
T1_TO_T2(dat, gYM)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GYEARMONTH_FACET, dt);
  aFactory->createGYearMonth(result, &dt);
  return true;
}


T1_TO_T2(dat, gYr)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GYEAR_FACET, dt);
  aFactory->createGYear(result, &dt);
  return true;
}


T1_TO_T2(dat, gMD)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GMONTHDAY_FACET, dt);
  aFactory->createGMonthDay(result, &dt);
  return true;
}


T1_TO_T2(dat, gDay)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GDAY_FACET, dt);
  aFactory->createGDay(result, &dt);
  return true;
}


T1_TO_T2(dat, gMon)
{
  DateTime dt;
  aItem->getDateValue().createWithNewFacet(DateTime::GMONTH_FACET, dt);
  aFactory->createGMonth(result, &dt);
  return true;
}


T1_TO_T2(gYM, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gYM, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gYr, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gYr, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gMD, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gMD, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gDay, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gDay, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gMon, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(gMon, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(bool, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(bool, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(bool, flt)
{
  if (aItem->getBooleanValue())
    aFactory->createFloat(result, numeric_consts<xs_float>::one());
  else
    aFactory->createFloat(result, numeric_consts<xs_float>::zero());
  return true;
}


T1_TO_T2(bool, dbl)
{
  if (aItem->getBooleanValue())
    aFactory->createDouble(result, numeric_consts<xs_double>::one());
  else
    aFactory->createDouble(result, numeric_consts<xs_double>::zero());
  return true;
}


T1_TO_T2(bool, dec)
{
  if (aItem->getBooleanValue())
    aFactory->createDecimal(result, numeric_consts<xs_decimal>::one());
  else
    aFactory->createDecimal(result, numeric_consts<xs_decimal>::zero());
  return true;
}


T1_TO_T2(bool, int)
{
  if (aItem->getBooleanValue())
    aFactory->createInteger(result, numeric_consts<xs_integer>::one());
  else
    aFactory->createInteger(result, numeric_consts<xs_integer>::zero());
  return true;
}


T1_TO_T2(b64, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(b64, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(b64, hxB)
{
  size_t s;
  char const *const c = aItem->getBase64BinaryValue(s);
  xs_base64Binary tmp( c, s, aItem->isEncoded() );
  aFactory->createHexBinary(result, xs_hexBinary(tmp));
  return true;
}


T1_TO_T2(hxB, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(hxB, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(hxB, b64)
{
  size_t s;
  char const *const c = aItem->getHexBinaryValue(s);
  xs_hexBinary tmp( c, s, aItem->isEncoded() );
  aFactory->createBase64Binary(result, xs_base64Binary(tmp));
  return true;
}


T1_TO_T2(aURI, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(aURI, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(QN, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(QN, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(NOT, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(NOT, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uint, uA)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_uA(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uint, str)
{
  return uA_str(result, aItem, strval, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(uint, flt)
{
  aFactory->createFloat(result, xs_float(aItem->getUnsignedIntegerValue()));
  return true;
}


T1_TO_T2(uint, dbl)
{
  aFactory->createDouble(result, xs_double(aItem->getUnsignedIntegerValue()));
  return true;
}


T1_TO_T2(uint, dec)
{
  aFactory->createDecimal(result, xs_decimal(aItem->getUnsignedIntegerValue()));
  return true;
}


T1_TO_T2(uint, bool)
{
  aFactory->createBoolean(result, aItem->getEBV());
  return true;
}


T1_TO_T2(uA, uint)
{
  zstring strval2;
  aItem->getStringValue2(strval2);
  return str_int(result, aItem, strval2, aFactory, nsCtx, errInfo, throw_on_error);
}


T1_TO_T2(flt, uint)
{
  try 
  {
    xs_nonNegativeInteger const n(aItem->getFloatValue());
    aFactory->createNonNegativeInteger(result, n);
    return true;
  }
  catch (const std::exception& ) 
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(int, uint)
{
  try 
  {
    xs_nonNegativeInteger const n(aItem->getIntegerValue());
    aFactory->createNonNegativeInteger(result, n);
    return true;
  }
  catch ( std::invalid_argument const& ) 
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  catch ( std::range_error const& ) 
  {
    if ( throw_on_error )
      throwFORG0001Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(uint, int)
{
  try 
  {
    xs_integer const n(aItem->getIntegerValue());
    aFactory->createInteger(result, n);
    return true;
  }
  catch (const std::exception& ) 
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(dbl, uint)
{
  try 
  {
    xs_nonNegativeInteger const n(aItem->getDoubleValue());
    aFactory->createInteger(result, n);
    return true;
  }
  catch (const std::exception& ) 
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(dec, uint)
{
  try
  {
    xs_nonNegativeInteger const n(aItem->getDecimalValue());
    aFactory->createNonNegativeInteger(result, n);
    return true;
  }
  catch ( const std::exception& ) 
  {
    if ( throw_on_error )
      throwFOCA0002Exception(aItem->getStringValue(), errInfo);
  }
  return false;
}


T1_TO_T2(bool, uint)
{
  xs_nonNegativeInteger const &i = aItem->getBooleanValue() ?
    numeric_consts<xs_nonNegativeInteger>::one() :
    numeric_consts<xs_nonNegativeInteger>::zero();
  aFactory->createNonNegativeInteger(result, i );
  return true;
}


T1_TO_T2(NUL, str)
{
  zstring val("null");
  aFactory->createString(result, val);
  return true;
}

T1_TO_T2(NUL, uA)
{
  zstring val("null");
  return str_uA(result, aItem, val, aFactory, nsCtx, errInfo, throw_on_error);
}

/*******************************************************************************

********************************************************************************/
bool str_down(
    store::Item_t& result,
    const store::Item* aItem,
    store::SchemaTypeCode aTargetAtomicType,
    store::ItemFactory* factory,
    const ErrorInfo& errInfo,
    bool throw_on_error)
{
  zstring strval;
  aItem->getStringValue2(strval);

  switch(aTargetAtomicType)
  {
  case store::XS_NORMALIZED_STRING:
  {
    char ch;
    zstring::size_type sz = strval.size();

    for (zstring::size_type i = 0; i < sz; ++i)
    {
      ch = strval[i];
      // do not contain the carriage return (#xD), line feed (#xA) nor tab (#x9)
      // characters
      if (ch == '\r' || ch == '\n' || ch == '\t')
      {
        strval[i] = ' ';
      }
    }
    
    factory->createNormalizedString(result, strval);
    return true;
  }
  case store::XS_TOKEN:
  {
    char ch;
    zstring::size_type sz = strval.size();

    ascii::trim_space(strval);

    bool spaceSeen = false;

    for (zstring::size_type i = 0; i < sz; ++i)
    {
      ch = strval[i];

      if (ch == '\r' || ch == '\n' || ch == '\t')
      {
        strval[i] = ' ';
        ch = ' ';
      }

      if (ch == ' ')
      {
        if (spaceSeen)
        {
          strval.erase(i, 1);
          --i;
          --sz;
        }

        spaceSeen = true;
      }
      else
      {
        spaceSeen = false;
      }
    }

    factory->createToken(result, strval);
    return true;
  }
  case store::XS_LANGUAGE:
  {
    if (GenericCast::instance()->castableToLanguage(strval))
    {
      factory->createLanguage(result, strval);
      return true;
    }
    break;
  }
  case store::XS_NMTOKEN:
  {
    ascii::trim_space(strval);

    if (GenericCast::instance()->castableToNMToken(strval))
    {
      factory->createNMTOKEN(result, strval);
      return true;
    }
    break;
  }
  case store::XS_NAME:
  {
    ascii::trim_space(strval);

    if (GenericCast::instance()->castableToName(strval))
    {
      factory->createName(result, strval);
      return true;
    }
    break;
  }
  case store::XS_NCNAME:
  {
    ascii::normalize_space(strval);
    ascii::trim_space(strval);

    if (GenericCast::castableToNCName(strval))
    {
      factory->createNCName(result, strval);
      return true;
    }
    break;
  }
  case store::XS_ID:
  {
    if (GenericCast::castableToNCName(strval))
    {
      factory->createID(result, strval);
      return true;
    }
    break;
  }
  case store::XS_IDREF:
  {
    if (GenericCast::castableToNCName(strval))
    {
      factory->createIDREF(result, strval);
      return true;
    }
    break;
  }
  case store::XS_ENTITY:
  {
    if (GenericCast::castableToNCName(strval))
    {
      factory->createENTITY(result, strval);
      return true;
    }
    break;
  }
  default:
    ZORBA_ASSERT(false);
  }

  if ( throw_on_error )
    throwFORG0001Exception(strval, errInfo);
  return false;
}


/*******************************************************************************

********************************************************************************/
bool int_down(
    store::Item_t& result,
    const store::Item* aItem,
    store::SchemaTypeCode aTargetAtomicType,
    store::ItemFactory* factory,
    const ErrorInfo& errInfo,
    bool throw_on_error)
{
  switch(aTargetAtomicType)
  {
  case store::XS_NON_POSITIVE_INTEGER:
  {
    xs_integer const lInteger = aItem->getIntegerValue();

    if (lInteger.sign() <= 0)
    {
      factory->createNonPositiveInteger(result, lInteger);
      return true;
    }

    break;
  }
  case store::XS_NEGATIVE_INTEGER:
  {
    xs_integer const lInteger = aItem->getIntegerValue();

    if (lInteger.sign() < 0)
    {
      factory->createNegativeInteger(result, lInteger);
      return true;
    }

    break;
  }
  case store::XS_LONG:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_long const n = ztd::aton<xs_long>(lString.c_str());
      factory->createLong(result, n);
      return true;
    }
    catch (std::exception const&) 
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
      factory->createInt(result, n);
      return true;
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
      factory->createShort(result, n);
      return true;
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
      factory->createByte(result, n);
      return true;
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_NON_NEGATIVE_INTEGER:
  {
    const xs_decimal d = aItem->getDecimalValue();
    if (d.sign() >= 0)
    {
      try 
      {
        xs_nonNegativeInteger const i(d);
        factory->createNonNegativeInteger(result, i);
        return true;
      }
      catch ( std::exception const& ) 
      {
        // ignore
      }
    }
    break;
  }
  case store::XS_UNSIGNED_LONG:
  {
    zstring lString;
    aItem->getStringValue2(lString);
    try 
    {
      xs_unsignedLong const n = ztd::aton<xs_unsignedLong>(lString.c_str());
      factory->createUnsignedLong(result, n);
      return true;
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
      factory->createUnsignedInt(result, n);
      return true;
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
      factory->createUnsignedShort(result, n);
      return true;
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
      factory->createUnsignedByte(result, n);
      return true;
    }
    catch ( std::exception const& ) 
    {
      // ignore
    }
    break;
  }
  case store::XS_POSITIVE_INTEGER:
  {
    try
    {
      xs_positiveInteger const n = aItem->getUnsignedIntegerValue();
      factory->createPositiveInteger(result, n);
      return true;
    }
    catch ( std::exception const& )
    {
      // ignore
    }
    break;
  }
  default:
    ZORBA_ASSERT(false);
  }

  if ( throw_on_error )
    throwFORG0001Exception(aItem->getStringValue(), errInfo);
  return false;
}


/*******************************************************************************
  For each builtin atomic type T, this array maps the typecode of T to an
  index to be used in addessing theCastMatrix.
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
  22,  // 44 XS_NOTATION
  24,  // 45 JS_NULL
  25,  // 46 XS_DATETIME_STAMP
};


/*******************************************************************************

********************************************************************************/
const GenericCast::DownCastFunc GenericCast::theDownCastMatrix[26] =
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
/*null*/  0,
/*dtSt*/  0,
};


/*******************************************************************************

********************************************************************************/
const GenericCast::CastFunc GenericCast::theCastMatrix[26][26] =
{
// uA        str        flt       dbl         dec        int       dur       yMD
// dTD       dT         tim       dat         gYM        gYr       gMD       gDay 
// gMon      bool       b64       hxB         aURI       QN        NOT       uint
// null      dTSt

{&uA_uA,    &uA_str,   &uA_flt,  &uA_dbl ,   &uA_dec ,  &uA_int,   &uA_dur,  &uA_yMD,
 &uA_dTD,   &uA_dT,    &uA_tim,  &uA_dat,    &uA_gYM ,  &uA_gYr ,  &uA_gMD,  &uA_gDay,
 &uA_gMon,  &uA_bool,  &uA_b64,  &uA_hxB,    &uA_aURI,  &uA_QN,    0,        &uA_uint,
 0,         &uA_dTSt}, // uA

{&str_uA,   &str_str,  &str_flt,  &str_dbl,  &str_dec,  &str_int,  &str_dur, &str_yMD,
 &str_dTD,  &str_dT,   &str_tim,  &str_dat,  &str_gYM,  &str_gYr,  &str_gMD, &str_gDay,
 &str_gMon, &str_bool, &str_b64,  &str_hxB,  &str_aURI, &str_QN,   &str_NOT, &str_uint,
 0,         &str_dTSt}, // str

{&flt_uA,   &flt_str,  &flt_flt,  &flt_dbl,  &flt_dec,  &flt_int,  0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         &flt_bool, 0,         0,         0,         0,         0,        &flt_uint,
 0,         0}, // flt

{&dbl_uA,   &dbl_str,  &dbl_flt,  &dbl_dbl,  &dbl_dec,  &dbl_int,  0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,  
 0,         &dbl_bool, 0,         0,         0,         0,         0,        &dbl_uint,
 0,         0}, // dbl

{&dec_uA,   &dec_str,  &dec_flt,  &dec_dbl,  &dec_dec,  &dec_int,  0,        0,
 0,         0,         0,         0,         0,         0,         0,        0, 
 0,         &dec_bool, 0,         0,         0,         0,         0,        &dec_uint,
 0,         0}, // dec

{&int_uA,   &int_str,  &int_flt,  &int_dbl,  &int_dec,  &int_int,  0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0, 
 0,         &int_bool, 0,         0,         0,         0,         0,        &int_uint,
 0,         0}, // int

{&dur_uA,   &dur_str,  0,         0,         0,         0,         &dur_dur, &dur_yMD,
 &dur_dTD,  0,         0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0}, // dur

{&yMD_uA,   &yMD_str,  0,         0,         0,         0,         &yMD_dur, &yMD_yMD,
 &yMD_dTD,  0,         0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0}, // yMD

{&dTD_uA,   &dTD_str,  0,         0,         0,         0,         &dTD_dur, &dTD_yMD,
 &dTD_dTD,  0,         0,         0,         0,         0,         0,        0,  
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0}, // dTD

{&dT_uA,    &dT_str,   0,         0,         0,         0,         0,        0,
 0,         &dT_dT,    &dT_tim,   &dT_dat,   &dT_gYM,   &dT_gYr,   &dT_gMD,  &dT_gDay,
 &dT_gMon,  0,         0,         0,         0,         0,         0,        0,
 0,         &dT_dTSt}, // dT

{&tim_uA,   &tim_str,  0,         0,         0,         0,         0,        0,
 0,         0,         &tim_tim,  0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0}, // tim

{&dat_uA,   &dat_str,  0,         0,         0,         0,         0,        0,
 0,         &dat_dT,   0,         &dat_dat,  &dat_gYM,  &dat_gYr,  &dat_gMD, &dat_gDay,
 &dat_gMon, 0,         0,         0,         0,         0,         0,        0,
 0,         0}, // dat

{&gYM_uA,   &gYM_str,  0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         &gYM_gYM,  0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0}, // gYM

{&gYr_uA,   &gYr_str,  0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         &gYr_gYr,  0,        0,  
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0}, // gYr

{&gMD_uA,   &gMD_str,  0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         &gMD_gMD, 0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0}, // gMD

{&gDay_uA,  &gDay_str, 0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         0,        &gDay_gDay,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0}, // gDay

{&gMon_uA,  &gMon_str, 0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,  
 &gMon_gMon,0,         0,         0,         0,         0,         0,        0,
 0,         0}, // gMon

{&bool_uA,  &bool_str, &bool_flt, &bool_dbl, &bool_dec, &bool_int, 0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0,  
 0,         &bool_bool,0,         0,         0,         0,         0,        &bool_uint,
 0,         0}, // bool

{&b64_uA,   &b64_str,  0,         0,         0,         0,         0,        0, 
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0,         &b64_b64,  &b64_hxB,  0,         0,         0,        0,
 0,         0}, // b64

{&hxB_uA,   &hxB_str,  0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0,         &hxB_b64,  &hxB_hxB,  0,         0,         0,        0,
 0,         0}, // hxB

{&aURI_uA,  &aURI_str, 0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,  
 0,         0,         0,         0,         &aURI_aURI,0,         0,        0,
 0,         0}, // aURI

{&QN_uA,    &QN_str,   0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         &QN_QN,    0,        0,
 0,         0}, // QN

{&NOT_uA,   &NOT_str,  0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         &NOT_NOT, 0,
 0,         0}, // NOT

{&uint_uA,  &uint_str, &uint_flt, &uint_dbl, &uint_dec, &uint_int, 0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,
 0,         &uint_bool,0,         0,         0,         0,         0,        &uint_uint,
 0,         0},

{&NUL_uA,   &NUL_str,  0,         0,         0,         0,         0,        0,
 0,         0,         0,         0,         0,         0,         0,        0,  
 0,         0,         0,         0,         0,         0,         0,        0,
 &NUL_NUL,  0}, // Nul

{&dT_uA,    &dT_str,   0,         0,         0,         0,         0,        0,
 0,         &dT_dTSt,    &dT_tim,   &dT_dat,   &dT_gYM,   &dT_gYr,   &dT_gMD,  &dT_gDay,
 &dT_gMon,  0,         0,         0,         0,         0,         0,        0,
 0,         &dTSt_dTSt}, // dTS
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
bool GenericCast::castToSimple(
    store::Item_t& item,
    const xqtref_t& targetType,
    const namespace_context* nsCtx,
    std::vector<store::Item_t>& resultList,
    TypeManager* tm,
    const QueryLoc& loc)
{
  const TypeManager* ttm = targetType->get_manager();

  if (ttm != tm && ttm != &GENV_TYPESYSTEM && !TypeOps::is_in_scope(tm, *targetType))
  {
    RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(ZED(BadType_23o), targetType, ZED(NotAmongInScopeSchemaTypes)));
  }

  if (targetType->isAtomicAny())
  {
    store::Item_t atomicResult;
    bool res = castToAtomic(atomicResult, item, targetType, tm, nsCtx, loc);

    if (res == false)
    {
      return false;
    }
    else
    {
      csize s = resultList.size();
      resultList.resize(s+1);
      resultList[s].transfer(atomicResult);
      
      return true;
    }
  }
  else if (targetType->type_kind() == XQType::USER_DEFINED_KIND)
  {
#ifndef ZORBA_NO_XMLSCHEMA
    tm->initializeSchema();

    Schema* schema = tm->getSchema();

    const UserDefinedXQType* udt =
    static_cast<const UserDefinedXQType*>(targetType.getp());

    ZORBA_ASSERT(udt->isList() || udt->isUnion());

    if (udt->isList())
    {
      store::SchemaTypeCode itemTypeCode = item->getTypeCode();
      zstring textValue = item->getStringValue();

      if (itemTypeCode != store::XS_STRING &&
          itemTypeCode != store::XS_UNTYPED_ATOMIC)
      {
        xqtref_t sourceType = tm->create_value_type(item);

        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(*sourceType, ZED(NoCastTo_34o), *targetType));
      }

      return schema->parseUserListTypes(textValue, targetType, resultList, nsCtx, loc, true);
    }
    else
    {
      std::vector<xqtref_t> memberTypes = udt->getUnionItemTypes();

      for (csize i = 0; i < memberTypes.size(); ++i)
      {
        if (TypeOps::is_subtype(tm, item.getp(), *memberTypes[i], loc))
        {
          store::Item_t tmp = item;
          resultList.clear();

          ZORBA_ASSERT(castToSimple(tmp, memberTypes[i], nsCtx, resultList, tm, loc));
          return true;
        }
      }

      for (csize i = 0; i < memberTypes.size(); ++i)
      {
        try
        {
          store::Item_t tmp = item;
          resultList.clear();

          bool success = castToSimple(tmp, memberTypes[i], nsCtx, resultList, tm, loc);

          if (success)
          {
            // to do: must validate before returning
            return true;
          }
        }
        catch(ZorbaException const&)
        {
        }
      }

      xqtref_t sourceType = tm->create_value_type(item);

      RAISE_ERROR(err::FORG0001, loc,
      ERROR_PARAMS(ZED(FORG0001_NoCastTo_234),
                   item->getStringValue(),
                   sourceType->toSchemaString(),
                   udt->toSchemaString()));
    } // union
#endif // ZORBA_NO_XMLSCHEMA
  } // list or union
  else
  {
    ZORBA_ASSERT(false); // simple types should be only atomic or user defined
  }
}


/*******************************************************************************
  Executes the string casting of the passed string to an item of the passed
  target type.
********************************************************************************/
bool GenericCast::castStringToAtomic(
    store::Item_t& result,
    zstring& str,
    const XQType* targetType,
    const TypeManager* tm,
    const namespace_context* nsCtx,
    const QueryLoc& loc,
    bool throw_on_error)
{
  if (!targetType->isAtomicOne())
  {
    if ( throw_on_error )
    {
      RAISE_ERROR(err::XPST0051, loc,
      ERROR_PARAMS(ZED(XPST0051_Atomic_2), targetType));
    }
    return false;
  }

#ifndef ZORBA_NO_XMLSCHEMA
  if (targetType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    store::Item_t baseItem;

    bool success = tm->getSchema()->parseUserAtomicTypes(str,
                                                         targetType,
                                                         baseItem,
                                                         nsCtx,
                                                         loc,
                                                         true);
    if (success)
    {
      const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(targetType);
      store::Item_t typeName = udt->getQName();

      GENV_ITEMFACTORY->createUserTypedAtomicItem(result, baseItem, typeName);
      return true;
    }

    return false;
  }
#endif

  return castStringToBuiltinAtomic(result,
                                   str,
                                   targetType,
                                   tm,
                                   nsCtx,
                                   loc,
                                   throw_on_error);
}


/*******************************************************************************
  Executes the string casting of the passed string to an item of the passed
  target type.
********************************************************************************/
bool GenericCast::castStringToBuiltinAtomic(
    store::Item_t& result,
    zstring& str,
    const XQType* targetType,
    const TypeManager* tm,
    const namespace_context* nsCtx,
    const QueryLoc& loc,
    bool throw_on_error)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;
  store::ItemFactory* factory = GENV_ITEMFACTORY;

  const XQType* sourceType = rtm.STRING_TYPE_ONE.getp();

  ErrorInfo errInfo(sourceType, targetType, loc);

  if (!targetType->isAtomicOne())
  {
    if ( throw_on_error )
    {
      RAISE_ERROR(err::XPST0051, loc,
      ERROR_PARAMS(ZED(XPST0051_Atomic_2), targetType));
    }
    return false;
  }

  ZORBA_ASSERT(targetType->type_kind() == XQType::ATOMIC_TYPE_KIND);

  store::Item_t item;
  store::SchemaTypeCode sourceTypeCode = store::XS_STRING;
  store::SchemaTypeCode targetTypeCode = TypeOps::get_atomic_type_code(*targetType);

  if (theMapping[sourceTypeCode] == theMapping[targetTypeCode])
  {
    factory->createString(result, str);
  }
  else
  {
    CastFunc castFunc = theCastMatrix[theMapping[sourceTypeCode]]
                                      [theMapping[targetTypeCode]];
    if (castFunc == 0)
    {
      if ( throw_on_error )
        throwXPTY0004Exception(errInfo);

      return false;
    }

    if ( !(*castFunc)(result, item, str, factory, nsCtx, errInfo, throw_on_error) )
      return false;
  }

  DownCastFunc downCastFunc = theDownCastMatrix[theMapping[targetTypeCode]];

  if (downCastFunc != 0 &&
      targetTypeCode != store::XS_STRING &&
      targetTypeCode != store::XS_INTEGER)
  {
    return (*downCastFunc)(result,
                           &*result,
                           targetTypeCode,
                           factory,
                           errInfo,
                           throw_on_error);
  }

  return true;
}


/*******************************************************************************
  Cast a given atomic item SI to an atomic item TI of a given atomic type TT.
  No casting is done if TI and TT are exactly the same type. If the cast is
  not allowed, the method raises an error. If the cast
  is not possible, the method may raise an error or return false (TODO fix 
  this!). Otherwise, it returns true.
********************************************************************************/
bool GenericCast::castToAtomic(
    store::Item_t&       result,
    store::Item_t&       item,
    const XQType*        targetType,
    const TypeManager*   tm,
    const namespace_context* nsCtx,
    const QueryLoc&      loc,
    bool throw_on_error)
{
  ZORBA_ASSERT(item->isAtomic());

  if (!targetType->isAtomicOne())
  {
    if ( throw_on_error )
    {
      RAISE_ERROR(err::XPST0051, loc,
      ERROR_PARAMS(ZED(XPST0051_Atomic_2), targetType));
    }
    return false;
  }

  store::SchemaTypeCode targetTypeCode;

  if (targetType->type_kind() == XQType::ATOMIC_TYPE_KIND)
  {
    targetTypeCode = TypeOps::get_atomic_type_code(*targetType);

    return castToBuiltinAtomic(result, item, targetTypeCode, nsCtx, loc, throw_on_error);
  }
  else
  {
    assert(targetType->type_kind() == XQType::USER_DEFINED_KIND);

    const UserDefinedXQType* udt =
      static_cast<const UserDefinedXQType*>(targetType);

    xqtref_t baseTargetType = udt->getBaseBuiltinType();
    targetTypeCode = TypeOps::get_atomic_type_code(*baseTargetType);

    if (targetTypeCode == store::XS_NOTATION)
    {
      zstring stringValue;
      item->getStringValue2(stringValue);

      return castStringToAtomic(result, stringValue, targetType, tm, nsCtx, loc, throw_on_error);
    }

    if ( !castToBuiltinAtomic(result, item, targetTypeCode, nsCtx, loc, throw_on_error) )
      return false;

    const TypeManager* tm = targetType->get_manager();
    Schema* schema = tm->getSchema();

    zstring stringValue;
    result->getStringValue2(stringValue);

    store::Item_t baseItem;

    bool valid = 
    schema->parseUserAtomicTypes(stringValue, targetType, baseItem, nsCtx, loc, true);

    if (valid)
    {
      store::Item_t typeName = udt->getQName();
      GENV_ITEMFACTORY->createUserTypedAtomicItem(result, baseItem, typeName);
    }

    return valid;
  }
  return true;
}


/*******************************************************************************
  Cast a given atomic item SI to an atomic item TI of a given builtin atomic
  type TT. No casting is done if TI and TT are exactly the same type. If the
  cast is not allowed or is not possible, the method raises an error. Otherwise,
  it returns true.
********************************************************************************/
bool GenericCast::castToBuiltinAtomic(
    store::Item_t& result,
    store::Item_t& item,
    store::SchemaTypeCode targetTypeCode,
    const namespace_context* nsCtx,
    const QueryLoc& loc,
    bool throw_on_error)
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  zstring stringValue;

  store::SchemaTypeCode sourceTypeCode = item->getTypeCode();

  if (sourceTypeCode == targetTypeCode)
  {
    result.transfer(item);
    return true;
  }

  ErrorInfo errInfo(sourceTypeCode, targetTypeCode, loc);

  if (targetTypeCode == store::XS_NOTATION ||
      targetTypeCode == store::XS_ANY_ATOMIC)
  {
    if (throw_on_error)
      RAISE_ERROR(err::XPST0080, loc, ERROR_PARAMS(errInfo.theTargetTypeCode));

    return false;
  }

  if (sourceTypeCode == store::XS_ANY_ATOMIC)
  {
    if (throw_on_error)
      throwXPTY0004Exception(errInfo);

    return false;
  }

  CastFunc castFunc = theCastMatrix[theMapping[sourceTypeCode]]
                                   [theMapping[targetTypeCode]];
  if (castFunc == 0)
  {
    if (throw_on_error)
      throwXPTY0004Exception(errInfo);

    return false;
  }

  if (theMapping[sourceTypeCode] == theMapping[store::XS_STRING])
  {
    item->getStringValue2(stringValue);
  }

  if (!(*castFunc)(result, item, stringValue, factory, nsCtx, errInfo, throw_on_error))
    return false;

  DownCastFunc downCastFunc = theDownCastMatrix[theMapping[targetTypeCode]];

  if (downCastFunc != 0 &&
      targetTypeCode != store::XS_STRING &&
      targetTypeCode != store::XS_INTEGER)
  {
    return (*downCastFunc)(result,
                           &*result,
                           targetTypeCode,
                           factory,
                           errInfo,
                           throw_on_error);
  }

  return true;
}


/*******************************************************************************
  Casts an atomic item to a qname, if possible.
********************************************************************************/
bool GenericCast::castToQName(
    store::Item_t& result,
    const store::Item_t& item,
    const namespace_context* nsCtx,
    bool isAttrName,
    const TypeManager* tm,
    const QueryLoc& loc)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t sourceType = tm->create_named_type(item->getType(),
                                              SequenceType::QUANT_ONE,
                                              loc,
                                              true);

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

  ErrorInfo errInfo(sourceType.getp(), rtm.QNAME_TYPE_ONE.getp(), loc);

  zstring strval;
  item->getStringValue2(strval);

  ascii::trim_space(strval);

  zstring::size_type idx = strval.find(":");
  zstring::size_type lidx = strval.rfind(":", strval.size(), 1);

  if (idx != lidx)
    throwFORG0001Exception(strval, errInfo);

  zstring nsuri;
  zstring prefix;
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

    if (!GenericCast::castableToNCName(prefix))
    {
      RAISE_ERROR(err::FORG0001, errInfo.theLoc,
      ERROR_PARAMS(ZED(FORG0001_PrefixNotNCName_2), prefix));
    }

    if (nsCtx)
    {
      if (!nsCtx->findBinding(prefix, nsuri))
        RAISE_ERROR(err::FONS0004, errInfo.theLoc, ERROR_PARAMS(prefix));
    }

    local = strval.substr(idx + 1);
  }

  if (!GenericCast::castableToNCName(local))
  {
    RAISE_ERROR(err::FORG0001, errInfo.theLoc,
    ERROR_PARAMS(ZED(FORG0001_LocalNotNCName_2), local));
  }

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

    if (!XQCharType::isLetter(cp) && !XQCharType::isDigit(cp) &&
        (cp != '.') && (cp != '-') && (cp != '_') &&
        !XQCharType::isCombiningChar(cp) && !XQCharType::isExtender(cp))
      return false;
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
    const XQType* targetType,
    TypeManager* tm,
    const namespace_context* nsCtx)
{
#ifndef ZORBA_NO_XMLSCHEMA
  if (targetType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(targetType);
    if (!udt->isComplex())
    {
      tm->initializeSchema();

      return isCastableUserSimpleTypes(aItem->getStringValue(), targetType, tm, nsCtx);
    }
  }
#endif // ZORBA_NO_XMLSCHEMA

  xqtref_t lSourceType = tm->create_named_type(aItem->getType(),
                                               SequenceType::QUANT_ONE,
                                               QueryLoc::null,
                                               true);

  TypeConstants::castable_t lIsCastable = TypeOps::castability(*lSourceType,
                                                               *targetType);
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
      return castToAtomic(temp, temp, targetType, tm, NULL, QueryLoc::null, false);
    }
    catch (ZorbaException const&)
    {
      ZORBA_ASSERT(0);
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
    const XQType* targetType,
    TypeManager* tm,
    const namespace_context* nsCtx)
{
#ifndef ZORBA_NO_XMLSCHEMA
  if (targetType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(targetType);
    if (!udt->isComplex())
    {
      tm->initializeSchema();

      return isCastableUserSimpleTypes(str, targetType, tm, nsCtx);
    }
  }
#endif // ZORBA_NO_XMLSCHEMA

  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t lSourceType = rtm.STRING_TYPE_ONE;

  ZORBA_ASSERT(targetType->type_kind() == XQType::ATOMIC_TYPE_KIND);

  TypeConstants::castable_t lIsCastable =
  TypeOps::castability(*lSourceType, *targetType);

  switch(lIsCastable)
  {
  case TypeConstants::NOT_CASTABLE:
    return false;
  case TypeConstants::CASTABLE:
    return true;
  case TypeConstants::MAYBE_CASTABLE:
  {
    try
    {
      store::Item_t dummy;
      zstring copyStr = str;
      return castStringToBuiltinAtomic(dummy,
                                       copyStr,
                                       targetType,
                                       tm,
                                       NULL,
                                       QueryLoc::null,
                                       false);
    }
    catch (ZorbaException const&)
    {
      ZORBA_ASSERT(0);
    }
  }
  break;
  }

  return false;
}


/*******************************************************************************
  user defined simple types, i.e. Atomic, List or Union Types
*******************************************************************************/
bool GenericCast::isCastableUserSimpleTypes(
    const zstring& textValue,
    const XQType* targetType,
    TypeManager* tm,
    const namespace_context* nsCtx)
{
  ZORBA_ASSERT(targetType->type_kind() == XQType::USER_DEFINED_KIND);

  const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(targetType);

  ZORBA_ASSERT(udt->isAtomicAny() || udt->isList() || udt->isUnion());

  switch ( udt->getUDTKind() )
  {
  case XQType::ATOMIC_UDT:
    return isCastableUserAtomicTypes(textValue, udt, tm, nsCtx);
    break;

  case XQType::LIST_UDT:
    return isCastableUserListTypes(textValue, udt, tm, nsCtx);
    break;

  case XQType::UNION_UDT:
    return isCastableUserUnionTypes(textValue, udt, tm, nsCtx);
    break;

  case XQType::COMPLEX_UDT:
  default:
    ZORBA_ASSERT( false);
    break;
  }

  return false;;
}


/*******************************************************************************
  user defined atomic types
*******************************************************************************/
bool GenericCast::isCastableUserAtomicTypes(
    const zstring& textValue,
    const UserDefinedXQType* targetType,
    TypeManager* tm,
    const namespace_context* nsCtx)
{
  xqtref_t baseTargetType = targetType->getBaseBuiltinType();
  store::SchemaTypeCode targetTypeCode = TypeOps::get_atomic_type_code(*baseTargetType);

  store::Item_t result;
  if (targetTypeCode == store::XS_NOTATION)
  {
    zstring stringValue(textValue);
    return castStringToAtomic(result, stringValue, targetType, tm, nsCtx, QueryLoc::null, false);
  }

  {
    store::Item_t item;
    zstring stringValue(textValue);
    GENV_ITEMFACTORY->createString(item, stringValue);
    if ( !castToBuiltinAtomic(result, item, targetTypeCode, nsCtx, QueryLoc::null, false) )
      return false;
  }

  try
  {
    Schema* schema = targetType->get_manager()->getSchema();
    zstring stringValue(textValue);
    store::Item_t baseItem;
    return schema->parseUserAtomicTypes(stringValue, targetType, baseItem, nsCtx, QueryLoc::null, true);
  }
  catch (const ZorbaException&)
  {
    /*
     * Exceptions are raised from Xerces code in case the value is not valid for the type,
     * there are no alternative methods to validate without throwing
     */
    return false;
  }
}


/*******************************************************************************
  user defined list types
*******************************************************************************/
bool GenericCast::isCastableUserListTypes(
    const zstring& textValue,
    const UserDefinedXQType* targetType,
    TypeManager* tm,
    const namespace_context* nsCtx)
{
  assert(targetType->isList());

  bool hasResult = true;
  const XQType* listItemType = targetType->getListItemType();

  //split text into atoms
  std::vector<zstring> atomicTextValues;
  splitToAtomicTextValues(textValue, atomicTextValues);

  if (atomicTextValues.empty())
  {
    return false;
  }

  for (csize i = 0; i < atomicTextValues.size(); ++i)
  {
    bool res = isCastable(atomicTextValues[i], listItemType, tm, nsCtx);
    hasResult = hasResult && res;
  }

  return hasResult;
}


/*******************************************************************************
  user defined union types
*******************************************************************************/
bool GenericCast::isCastableUserUnionTypes(
    const zstring& textValue,
    const UserDefinedXQType* targetType,
    TypeManager* tm,
    const namespace_context* nsCtx)
{
  ZORBA_ASSERT(targetType->isUnion());

  std::vector<xqtref_t> unionItemTypes = targetType->getUnionItemTypes();

  for (csize i = 0; i < unionItemTypes.size(); ++i)
  {
    if (isCastable(textValue, unionItemTypes[i].getp(), tm, nsCtx))
      return true;
  }
  
  return false;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::promote(
    store::Item_t& result,
    store::Item_t& item,
    const XQType* targetType,
    const namespace_context* nsCtx,
    const TypeManager* tm,
    const QueryLoc& loc)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  assert(item->isAtomic());

  // If the target type is a builtin atomic type
  if (targetType->type_kind() == XQType::ATOMIC_TYPE_KIND)
  {
    return promote(result, 
                   item,
                   static_cast<const AtomicXQType*>(targetType)->get_type_code(),
                   nsCtx,
                   tm,
                   loc);
  }

  if (targetType->type_kind() == XQType::NONE_KIND)
      return false;

  xqtref_t itemType = tm->create_value_type(item);

  if (TypeOps::is_subtype(tm, *itemType, *targetType))
  {
    result.transfer(item);
    return result != NULL;
  }

  // untyped --> target type
  if (TypeOps::is_equal(tm, *itemType, *rtm.UNTYPED_ATOMIC_TYPE_ONE) &&
      ! TypeOps::is_equal(tm, *TypeOps::prime_type(tm, *targetType), *rtm.QNAME_TYPE_ONE))
  {
    return castToAtomic(result, item, targetType, tm, nsCtx, loc);
  }

    // Decimal/Float --> xs:double
  else if (TypeOps::is_subtype(tm, *targetType, *rtm.DOUBLE_TYPE_ONE))
  {
    store::SchemaTypeCode itemTypeCode = item->getTypeCode();

    if (TypeOps::is_subtype(itemTypeCode, store::XS_DECIMAL) ||
        TypeOps::is_subtype(itemTypeCode, store::XS_FLOAT))
    {
      return castToAtomic(result, item, targetType, tm, NULL, loc);
    }
  }

  // decimal --> xs:float
  else if (TypeOps::is_subtype(tm, *targetType, *rtm.FLOAT_TYPE_ONE))
  {
    store::SchemaTypeCode itemTypeCode = item->getTypeCode();

    if (TypeOps::is_subtype(itemTypeCode, store::XS_DECIMAL))
    {
      return castToAtomic(result, item, targetType, tm, NULL, loc);
    }
  }

  // URI --> xs:String
  else if (TypeOps::is_subtype(tm, *targetType, *rtm.STRING_TYPE_ONE))
  {
    store::SchemaTypeCode itemTypeCode = item->getTypeCode();

    if (TypeOps::is_subtype(itemTypeCode, store::XS_ANY_URI))
    {
      return castToBuiltinAtomic(result, item, store::XS_STRING, NULL, loc);
    }
  }

  return false;
}


/*******************************************************************************

*******************************************************************************/
void GenericCast::splitToAtomicTextValues(
    const zstring& textValue,
    std::vector<zstring>& atomicTextValues)
{
  zstring normalizedTextValue;
  utf8::normalize_space(textValue, &normalizedTextValue);

  size_t start = 0;
  size_t i = 0;

  while (std::string::npos != (i = normalizedTextValue.find_first_of(" \n\r\t", start))) 
  {
    atomicTextValues.push_back(normalizedTextValue.substr(start, i - start));
    start = i+1;
  }

  size_t size = normalizedTextValue.size();

  if ( start < size )
  {
    atomicTextValues.push_back(normalizedTextValue.substr(start, size));
  }
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::promote(
    store::Item_t& result,
    store::Item_t& item,
    store::SchemaTypeCode targetType,
    const namespace_context* nsCtx,
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

  if (TypeOps::is_subtype(itemType, store::XS_UNTYPED_ATOMIC))
  {
    if (TypeOps::is_subtype(targetType, store::XS_QNAME) ||
        TypeOps::is_subtype(targetType, store::XS_NOTATION))
    {
      return false;
    }

    // untyped --> target type
    return castToBuiltinAtomic(result, item, targetType, NULL, loc);
  }
  else if (TypeOps::is_subtype(targetType, store::XS_DOUBLE))
  {
    // Decimal/Float --> xs:double
    if (TypeOps::is_subtype(itemType, store::XS_DECIMAL) ||
        TypeOps::is_subtype(itemType, store::XS_FLOAT))
    {
      return castToBuiltinAtomic(result, item, targetType, NULL, loc);
    }
  }
  else if (TypeOps::is_subtype(targetType, store::XS_FLOAT))
  {
    // decimal --> xs:float
    if (TypeOps::is_subtype(itemType, store::XS_DECIMAL))
    {
      return castToBuiltinAtomic(result, item, targetType, NULL, loc);
    }
  }
  else if (TypeOps::is_subtype(targetType, store::XS_STRING))
  {
    // URI --> xs:String Promotion
    if (TypeOps::is_subtype(itemType, store::XS_ANY_URI))
    {
      return castToBuiltinAtomic(result, item, store::XS_STRING, NULL, loc);
    }
  }

  return false;
}


#undef ATOMIC_TYPE


/* end class GenericCast */
} // namespace zorba
/* vim:set et sw=2 ts=2: */
