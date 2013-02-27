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

#include "zorbamisc/config/platform.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "store/api/copymode.h"

#include "store_defs.h"
#include "simple_store.h"
#include "simple_item_factory.h"
#include "atomic_items.h"
#include "node_items.h"
#include "node_iterators.h"
#include "simple_temp_seq.h"
#include "simple_pul.h"
#include "qname_pool.h"
#include "string_pool.h"
#include "node_factory.h"
#include "tree_id.h"

#ifdef ZORBA_WITH_JSON
#  include "json_items.h"
#endif

#include "util/ascii_util.h"
#include "util/stream_util.h"


namespace zorba { namespace simplestore {


BasicItemFactory::BasicItemFactory(UriPool* uriPool, QNamePool* qnPool)
  :
  theUriPool(uriPool),
  theQNamePool(qnPool),
  theTrueItem(new BooleanItem(store::XS_BOOLEAN, true)),
  theFalseItem(new BooleanItem(store::XS_BOOLEAN, false))
#ifdef ZORBA_WITH_JSON
  ,theNullItem(new json::JSONNull())
#endif
{
}


BasicItemFactory::~BasicItemFactory()
{
  theFalseItem = NULL;
  theTrueItem  = NULL;
  theQNamePool = NULL;
  theUriPool   = NULL;
}


bool BasicItemFactory::createUserTypedAtomicItem(
    store::Item_t& result,
    store::Item_t& baseItem,
    store::Item_t& typeName)
{
  result = new UserTypedAtomicItem(baseItem, typeName);
  return true;
}


bool BasicItemFactory::createQName(
    store::Item_t& result,
    const zstring& ns,
    const zstring& pre,
    const zstring& local)
{
  result = theQNamePool->insert(ns, pre, local);
  return true;
}


bool BasicItemFactory::createQName(
    store::Item_t& result,
    const char*    ns,
    const char*    pre,
    const char*    ln)
{
  result = theQNamePool->insert(ns, pre, ln);
  return true;
}



bool BasicItemFactory::createAnyURI(store::Item_t& result, zstring& value)
{
  zstring str = value;
  theUriPool->insert(str);
  result =  new AnyUriItem(store::XS_ANY_URI, str);
  return true;
}


bool BasicItemFactory::createAnyURI(store::Item_t& result, const char* value)
{
  zstring str;
  theUriPool->insertc(value, str);
  result = new AnyUriItem(store::XS_ANY_URI, str);
  return true;
}


bool BasicItemFactory::createStructuralAnyURI(
    store::Item_t& result,
    zstring& value)
{
  result =  new StructuralAnyUriItem(store::XS_ANY_URI, value);
  return true;
}


bool BasicItemFactory::createStructuralAnyURI(
    store::Item_t& result,
    ulong collectionId,
    const TreeId& treeId,
    store::StoreConsts::NodeKind nodeKind,
    const OrdPath& ordPath)
{
  ZORBA_FATAL(nodeKind,"Unexpected node kind");

  result = new StructuralAnyUriItem(store::XS_ANY_URI,
                                    collectionId, treeId, nodeKind, ordPath);
  return true;
}


bool BasicItemFactory::createString(store::Item_t& result, zstring& value)
{
  result = new StringItem(store::XS_STRING, value);
  return true;
}


bool BasicItemFactory::createStreamableString(
    store::Item_t& result,
    std::istream& stream,
    StreamReleaser streamReleaser,
    bool seekable) 
{
  result = new StreamableStringItem(store::XS_STRING, stream, streamReleaser, seekable);
  return true;
}

bool BasicItemFactory::createStreamableString(
    store::Item_t& result,
    std::istream& stream,
    StreamReleaser streamReleaser,
    char const *uri,
    bool seekable) 
{
  result = new StreamableStringItem(store::XS_STRING, stream, streamReleaser, seekable);
  set_uri( stream, uri );
  return true;
}

bool BasicItemFactory::createSharedStreamableString(
    store::Item_t& result,
    store::Item_t& streamable_dependent)
{
  result = new StreamableStringItem(store::XS_STRING, streamable_dependent);
  return true;
}


bool BasicItemFactory::createNormalizedString(store::Item_t& result, zstring& value)
{
  result = new NormalizedStringItem(store::XS_NORMALIZED_STRING, value);
  return true;
}


bool BasicItemFactory::createToken(store::Item_t& result, zstring& value )
{
  result = new TokenItem(store::XS_TOKEN, value);
  return true;
}


bool BasicItemFactory::createLanguage(store::Item_t& result, zstring& value )
{
  result = new LanguageItem(store::XS_LANGUAGE, value);
  return true;
}


bool BasicItemFactory::createNMTOKEN(store::Item_t& result, zstring& value )
{
  result = new NMTOKENItem(store::XS_NMTOKEN, value);
  return true;
}


bool BasicItemFactory::createNMTOKENS(store::Item_t& result, zstring& value )
{
  // split value string into tokens
  std::vector<zstring> atomicTextValues;
  splitToAtomicTextValues(value, atomicTextValues);

  //create VectorItem with all tokens
  std::vector<store::Item_t> typedValues;
  for (csize i = 0; i < atomicTextValues.size(); ++i)
  {
    store::Item_t resultItem;
    if (createNMTOKEN(resultItem, atomicTextValues[i]))
    {
      typedValues.push_back(resultItem.getp());
    }
  }

  result = new ItemVector(typedValues);
  return true;
}


bool BasicItemFactory::createName(store::Item_t& result, zstring& value)
{
  result = new NameItem(store::XS_NAME, value);
  return true;
}


bool BasicItemFactory::createNCName(store::Item_t& result, zstring& value )
{
  result = new NCNameItem(store::XS_NCNAME, value);
  return true;
}


bool BasicItemFactory::createID(store::Item_t& result, zstring& value )
{
  result = new IDItem(store::XS_ID, value);
  return true;
}


bool BasicItemFactory::createIDREF(store::Item_t& result, zstring& value)
{
  result = new IDREFItem(store::XS_IDREF, value);
  return true;
}


bool BasicItemFactory::createIDREFS(store::Item_t& result, zstring& value )
{
  // split value string into tokens
  std::vector<zstring> atomicTextValues;
  splitToAtomicTextValues(value, atomicTextValues);

  //create VectorItem with all tokens
  std::vector<store::Item_t> typedValues;
  for (csize i = 0; i < atomicTextValues.size(); i++)
  {
    store::Item_t resultItem;
    if (createIDREF(resultItem, atomicTextValues[i]))
    {
      typedValues.push_back(resultItem.getp());
    }
  }

  result = new ItemVector(typedValues);
  return true;
}


bool BasicItemFactory::createENTITY(store::Item_t& result, zstring& value )
{
  result = new ENTITYItem(store::XS_ENTITY, value);
  return true;
}


bool BasicItemFactory::createENTITIES(store::Item_t& result, zstring& value)
{
  // split value string into tokens
  std::vector<zstring> atomicTextValues;
  splitToAtomicTextValues(value, atomicTextValues);

  //create VectorItem with all tokens
  std::vector<store::Item_t> typedValues;
  for (csize i = 0; i < atomicTextValues.size(); i++)
  {
    store::Item_t resultItem;
    if (createENTITY(resultItem, atomicTextValues[i]))
    {
      typedValues.push_back(resultItem.getp());
    }
  }

  result = new ItemVector(typedValues);
  return true;
}


bool BasicItemFactory::createUntypedAtomic(store::Item_t& result, zstring& value)
{
  result = new UntypedAtomicItem(store::XS_UNTYPED_ATOMIC, value);
  return true;
}


bool BasicItemFactory::createDouble(
    store::Item_t& result,
    const xs_double& value)
{
  result = new DoubleItem(store::XS_DOUBLE, value);
  return true;
}


bool BasicItemFactory::createFloat(store::Item_t& result,  const xs_float& value)
{
  result = new FloatItem(store::XS_FLOAT, value);
  return true;
}


bool BasicItemFactory::createDecimal(store::Item_t& result, const xs_decimal& value)
{
  result = new DecimalItem(store::XS_DECIMAL, value);
  return true;
}


bool BasicItemFactory::createInteger(store::Item_t& result, const xs_integer& value)
{
  result = new IntegerItemImpl(store::XS_INTEGER, value);
  return true;
}


bool BasicItemFactory::createNonPositiveInteger(
    store::Item_t& result,
    const xs_integer& value)
{
  ZORBA_ASSERT(value.sign() <= 0);
  result = new NonPositiveIntegerItem(store::XS_NON_POSITIVE_INTEGER, value);
  return true;
}


bool BasicItemFactory::createNegativeInteger(
    store::Item_t& result,
    const xs_integer& value)
{
  ZORBA_ASSERT(value.sign() < 0);
  result = new NegativeIntegerItem(store::XS_NEGATIVE_INTEGER, value);
  return true;
}


bool BasicItemFactory::createNonNegativeInteger(
    store::Item_t& result,
    const xs_nonNegativeInteger& value )
{
  result = new NonNegativeIntegerItem(store::XS_NON_NEGATIVE_INTEGER, value);
  return true;
}



bool BasicItemFactory::createPositiveInteger(
    store::Item_t& result,
    const xs_positiveInteger& value)
{
  ZORBA_ASSERT(value.sign() > 0);
  result = new PositiveIntegerItem(store::XS_POSITIVE_INTEGER,value);
  return true;
}


bool BasicItemFactory::createLong(store::Item_t& result,  xs_long value)
{
  result = new LongItem(store::XS_LONG, value);
  return true;
}


bool BasicItemFactory::createInt(store::Item_t& result,  xs_int value)
{
  result = new IntItem(store::XS_INT, value);
  return true;
}


bool BasicItemFactory::createShort(store::Item_t& result,  xs_short value)
{
  result = new ShortItem(store::XS_SHORT, value);
  return true;
}


bool BasicItemFactory::createByte(store::Item_t& result,  xs_byte value)
{
  result = new ByteItem(store::XS_BYTE, value);
  return true;
}


bool BasicItemFactory::createUnsignedLong(
    store::Item_t& result,
    xs_unsignedLong value)
{
  result = new UnsignedLongItem(store::XS_UNSIGNED_LONG, value);
  return true;
}


bool BasicItemFactory::createUnsignedInt(
   store::Item_t& result,
   xs_unsignedInt value)
{
  result = new UnsignedIntItem(store::XS_UNSIGNED_INT, value);
  return true;
}


bool BasicItemFactory::createUnsignedShort(
    store::Item_t& result,
    xs_unsignedShort value)
{
  result = new UnsignedShortItem(store::XS_UNSIGNED_SHORT, value);
  return true;
}


bool BasicItemFactory::createUnsignedByte(
    store::Item_t& result,
    xs_unsignedByte value)
{
  result = new UnsignedByteItem(store::XS_UNSIGNED_BYTE, value);
  return true;
}


bool BasicItemFactory::createBoolean(store::Item_t& result, xs_boolean value)
{
  result = (value ? theTrueItem : theFalseItem);
  return true;
}


bool BasicItemFactory::createDateTime(store::Item_t& result, const xs_dateTime* value)
{
  result = new DateTimeItem(store::XS_DATETIME, value);
  return true;
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    const xs_date* date,
    const xs_time* time)
{
  std::auto_ptr<DateTimeItem> dtin(new DateTimeItem(store::XS_DATETIME));
  int err = DateTime::createDateTime(date, time, dtin->theValue);
  if (err == 0)
  {
    result = dtin.get();
    dtin.release();
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    short   year,
    short   month,
    short   day,
    short   hour,
    short   minute,
    double  second)
{
  DateTime dt;
  TimeZone tz;

  if (DateTime::createDateTime(year, month, day, hour, minute, second, &tz, dt) == 0)
  {
    result = new DateTimeItem(store::XS_DATETIME, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    short   year ,
    short   month,
    short   day,
    short   hour,
    short   minute,
    double  second,
    short   timeZone_hours)
{
  DateTime dt;
  TimeZone tz(timeZone_hours);

  if (DateTime::createDateTime(year, month, day, hour, minute, second, &tz, dt) == 0)
  {
    result = new DateTimeItem(store::XS_DATETIME, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  DateTime dt;

  if (DateTime::parseDateTime(str, strlen, dt) == 0)
  {
    result = new DateTimeItem(store::XS_DATETIME, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    const store::Item_t& date,
    const store::Item_t& time)
{
  if (date.isNull() || time.isNull())
  {
    result = NULL;
    return false;
  }
  else
  {
    const xs_date& d = date->getDateValue();
    const xs_time& t = time->getTimeValue();
    if (! createDateTime( result, &d, &t))
      throw XQUERY_EXCEPTION(err::FORG0008, ERROR_PARAMS(d, t));

    return true;
  }
}


bool BasicItemFactory::createDateTimeStamp(store::Item_t& result, const xs_dateTime* value)
{
  if( value->hasTimezone() )
  {
    result = new DateTimeItem(store::XS_DATETIME, value);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}
  
  
bool BasicItemFactory::createDateTimeStamp(
                                      store::Item_t& result,
                                      const xs_date* date,
                                      const xs_time* time)
{
  std::auto_ptr<DateTimeItem> dtin(new DateTimeItem(store::XS_DATETIME_STAMP));
  int err = DateTime::createDateTime(date, time, dtin->theValue);
  if (err == 0 && time->hasTimezone())
  {
    result = dtin.get();
    dtin.release();
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}
  
  
bool BasicItemFactory::createDateTimeStamp(
                                      store::Item_t& result,
                                      short   year ,
                                      short   month,
                                      short   day,
                                      short   hour,
                                      short   minute,
                                      double  second,
                                      short   timeZone_hours)
{
  DateTime dt;
  TimeZone tz(timeZone_hours);
    
  if (DateTime::createDateTime(year, month, day, hour, minute, second, &tz, dt) == 0)
  {
    result = new DateTimeItem(store::XS_DATETIME_STAMP, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}
  
  
bool BasicItemFactory::createDateTimeStamp(
                                      store::Item_t& result,
                                      const char* str,
                                      ulong strlen)
{
  DateTime dt;
    
  if (DateTime::parseDateTime(str, strlen, dt) == 0 && dt.hasTimezone())
  {
    result = new DateTimeItem(store::XS_DATETIME_STAMP, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}
  
  
bool BasicItemFactory::createDateTimeStamp(
                                      store::Item_t& result,
                                      const store::Item_t& date,
                                      const store::Item_t& time)
{
  if ( time.isNull() )
  {
    throw XQUERY_EXCEPTION(err::FORG0001);
  }
  else if (date.isNull() || time.isNull())
  {
    result = NULL;
    return false;
  }
  else
  {
    const xs_date& d = date->getDateValue();
    const xs_time& t = time->getTimeValue();
    if (! createDateTimeStamp( result, &d, &t))
      throw XQUERY_EXCEPTION(err::FORG0008, ERROR_PARAMS(d, t));
      
    return true;
  }
}
  
  
bool BasicItemFactory::createDate(store::Item_t& result, const xs_date* value)
{
  result = new DateTimeItem(store::XS_DATE, value);
  return true;
}


bool BasicItemFactory::createDate(
    store::Item_t& result,
    short year,
    short month,
    short day )
{
  DateTime dt;
  TimeZone tz;

  if (DateTime::createDate(year, month, day, &tz, dt) == 0)
  {
    result = new DateTimeItem(store::XS_DATE, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDate(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  DateTime dt;

  if (DateTime::parseDate(str, strlen, dt) == 0)
  {
    result = new DateTimeItem(store::XS_DATE, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createTime(store::Item_t& result, const xs_time* value)
{
  result = new DateTimeItem(store::XS_TIME, value);
  return true;
}


bool BasicItemFactory::createTime(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  DateTime dt;

  if (DateTime::parseTime(str, strlen, dt) == 0)
  {
    result = new DateTimeItem(store::XS_TIME, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createTime(
    store::Item_t& result,
    short          hour,
    short          minute,
    double         second)
{
  DateTime dt;
  TimeZone tz;

  if( DateTime::createTime(hour, minute, second, &tz, dt) == 0 )
  {
    result = new DateTimeItem(store::XS_TIME, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createTime(
    store::Item_t& result,
    short          hour,
    short          minute,
    double         second,
    short          timeZone_hours)
{
  DateTime dt;
  TimeZone tz(timeZone_hours);

  if(DateTime::createTime(hour, minute, second, &tz, dt) == 0)
  {
    result = new DateTimeItem(store::XS_TIME, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGDay(store::Item_t& result, const xs_gDay* value)
{
  result = new DateTimeItem(store::XS_GDAY, value);
  return true;
}


bool BasicItemFactory::createGDay(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  DateTime dt;

  if (DateTime::parseGDay(str, strlen, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GDAY, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGDay(store::Item_t& result,  short day)
{
  DateTime dt;

  if (DateTime::createGDay(day, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GDAY, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGMonth(store::Item_t& result, const xs_gMonth* value)
{
  result = new DateTimeItem(store::XS_GMONTH, value);
  return true;
}


bool BasicItemFactory::createGMonth(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  DateTime dt;

  if (DateTime::parseGMonth(str, strlen, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GMONTH, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGMonth(store::Item_t& result, short month)
{
  DateTime dt;

  if(DateTime::createGMonth(month, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GMONTH, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGMonthDay(
    store::Item_t& result,
    const xs_gMonthDay* value)
{
  result = new DateTimeItem(store::XS_GMONTH_DAY, value);
  return true;
}


bool BasicItemFactory::createGMonthDay(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  DateTime dt;

  if (DateTime::parseGMonthDay(str, strlen, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GMONTH_DAY, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGMonthDay(store::Item_t& result, short month, short day)
{
  DateTime dt;

  if (DateTime::createGMonthDay(month, day, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GMONTH_DAY, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYear(store::Item_t& result, const xs_gYear* value)
{
  result = new DateTimeItem(store::XS_GYEAR, value);
  return true;
}


bool BasicItemFactory::createGYear(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  DateTime dt;

  if (DateTime::parseGYear(str, strlen, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GYEAR, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYear(store::Item_t& result,  short year)
{
  DateTime dt;

  if(DateTime::createGYear(year, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GYEAR, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYearMonth(
    store::Item_t& result,
    const xs_gYearMonth* value)
{
  result = new DateTimeItem(store::XS_GYEAR_MONTH, value);
  return true;
}


bool BasicItemFactory::createGYearMonth(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  DateTime dt;

  if (DateTime::parseGYearMonth(str, strlen, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GYEAR_MONTH, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYearMonth(
    store::Item_t& result,
    short year,
    short month)
{
  DateTime dt;

  if (DateTime::createGYearMonth(year, month, dt) == 0)
  {
    result = new DateTimeItem(store::XS_GYEAR_MONTH, &dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDuration(
    store::Item_t& result,
    xs_duration* value)
{
  result = new DurationItem(store::XS_DURATION, value);
  return true;
}


bool BasicItemFactory::createDuration(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  Duration d;
  if (Duration::parseDuration(str, strlen, d) == 0)
  {
    result = new DurationItem(store::XS_DURATION, &d);
    return true;
  }

  result = NULL;
  return false;
}


bool BasicItemFactory::createDuration(
    store::Item_t& result,
    short   years,
    short   months,
    short   days,
    short   hours,
    short   minutes,
    double  seconds)
{
  Duration d(Duration::DURATION_FACET, years, months, days, hours, minutes, seconds);
  result = new DurationItem(store::XS_DURATION, &d);
  return true;
}


bool BasicItemFactory::createYearMonthDuration(
    store::Item_t& result,
    xs_yearMonthDuration* value )
{
  result = new DurationItem(store::XS_YM_DURATION, value);
  return true;
}

bool BasicItemFactory::createYearMonthDuration(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  Duration d;
  if (Duration::parseYearMonthDuration(str, strlen, d) == 0)
  {
    result = new DurationItem(store::XS_YM_DURATION, &d);
    return true;
  }

  result = NULL;
  return false;
}


bool BasicItemFactory::createDayTimeDuration(
    store::Item_t& result,
    xs_dayTimeDuration* value)
{
  result = new DurationItem(store::XS_DT_DURATION, value);
  return true;
}


bool BasicItemFactory::createDayTimeDuration(
    store::Item_t& result,
    const char* str,
    ulong strlen)
{
  Duration d;
  if (Duration::parseDayTimeDuration(str, strlen, d) == 0)
  {
    result = new DurationItem(store::XS_DT_DURATION, &d);
    return true;
  }

  result = NULL;
  return false;
}


bool BasicItemFactory::createBase64Binary(
    store::Item_t& result,
    xs_base64Binary value)
{
  const std::vector<char>& data = value.getData();
  result = new Base64BinaryItem(store::XS_BASE64BINARY,
                                data.size() != 0 ? &data[0] : 0,
                                data.size(),
                                true);
  return true;
}

bool BasicItemFactory::createBase64Binary(
    store::Item_t& result,
    const char* value,
    size_t size,
    bool encoded)
{
  result = new Base64BinaryItem(store::XS_BASE64BINARY, value, size, encoded);
  return true;
}


bool BasicItemFactory::createStreamableBase64Binary(
    store::Item_t& result,
    std::istream& aStream,
    StreamReleaser aReleaser,
    bool seekable,
    bool encoded)
{
  result = new StreamableBase64BinaryItem(store::XS_BASE64BINARY,
                                          aStream,
                                          aReleaser,
                                          seekable,
                                          encoded);
  return true;
}


bool BasicItemFactory::createStreamableBase64Binary(
    store::Item_t& result,
    std::istream& aStream,
    StreamReleaser aReleaser,
    char const *uri,
    bool seekable,
    bool encoded)
{
  result = new StreamableBase64BinaryItem(store::XS_BASE64BINARY,
                                          aStream,
                                          aReleaser,
                                          seekable,
                                          encoded);
  set_uri( aStream, uri );
  return true;
}


bool BasicItemFactory::createHexBinary(store::Item_t& result,  xs_hexBinary value)
{
  result = new HexBinaryItem(store::XS_HEXBINARY, value);
  return true;
}


bool BasicItemFactory::createNOTATION(
    store::Item_t& result,
    zstring& ns,
    zstring& prefix,
    zstring& local)
{
  result = new NotationItem(store::XS_NOTATION, ns, prefix, local);
  return true;
}


bool BasicItemFactory::createNOTATION(store::Item_t& result, zstring& str)
{
  zstring nsuri;
  zstring prefix;
  zstring local;

  ascii::trim_whitespace(str);
  zstring::size_type pos = str.rfind(":", str.size(), 1);

  if (pos != zstring::npos)
  {
    nsuri = str.substr(0, pos);
    local = str.substr(pos+1, str.size());
  }
  else
    local = str;

  result = new NotationItem(store::XS_NOTATION, nsuri, prefix, local);
  return true;
}


bool BasicItemFactory::createNOTATION(store::Item_t& result, store::Item_t& qname)
{
  result = new NotationItem(store::XS_NOTATION, qname);
  return true;
}


/*******************************************************************************
  Create a new document node N and make it the root (and single node) of a new
  XML tree.

  baseUri       : The base-uri property of N. It may be NULL.
  docUri        : The document-uri property of N. It may be NULL.
********************************************************************************/
bool BasicItemFactory::createDocumentNode(
    store::Item_t& result,
    zstring& baseUri,
    zstring& docUri)
{
  XmlTree* xmlTree = NULL;
  DocumentNode* n = NULL;

  try
  {
    xmlTree = GET_STORE().getNodeFactory().createXmlTree();

    n = GET_STORE().getNodeFactory().createDocumentNode(xmlTree, baseUri, docUri);
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new element node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a new XML
  tree.

  parent        : The parent P of the new element node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos == current number of P's children, then N is appended
                  to the list of children.
  nodeName      : The node-name property of N.
  typeName      : The type-name property of N.
                  Not allowed to be NULL, use xsd:untyped instead.
  haveTypedValue: Whether the node has a typed value or not (element nodes with
                  complex type and element-only content do not have typed value).
  haveEmptyValue: True if the typed value of the node is the empty sequence.
                  This is the case if the element has a complex type with empty
                  content.
  isId          :
  isIdRefs      :
  localBindings : A set S1 of namespace bindings. The namespaces property of N
                  is set to S1, plus the ns binding implied by N's qname, plus
                  all the ns bindings of P that are not overwritten by S1 or the
                  ns binding implied by N's qname. Note: when called from an
                  element constructor iterator, S1 is the set of ns bindings
                  defined by ns decalration attrs that appear inside the
                  constructor expr itself.
  baseUri       : The base-uri property of N. It may be NULL, in which case,
                  the base-uri property of N is the same as that of P. If P
                  is NULL, then baseUri will NOT be null (see
                  runtime/core/constructors.cpp).

  The haveTypedValue and haveEmptyValue properties are actually a function of
  the node's type. However, since the store stores only the name of the type
  and does not know anything about the definition of that type, the caller
  of this method must provide the value for these two properties, which are
  needed to implement the getTypedValue() method.
********************************************************************************/
bool BasicItemFactory::createElementNode(
    store::Item_t&              result,
    store::Item*                parent,
    ulong                       pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    bool                        haveTypedValue,
    bool                        haveEmptyValue,
    const store::NsBindings&    localBindings,
    zstring&                    baseUri,
    bool                        isInSubstitutionGroup)
{
  XmlTree* xmlTree = NULL;
  ElementNode* n = NULL;

  if ( typeName == NULL )
    throw ZORBA_EXCEPTION(zerr::ZAPI0014_INVALID_ARGUMENT,
    ERROR_PARAMS("null", ZED( NotAllowedForTypeName)));

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();

    n = GET_STORE().getNodeFactory().createElementNode(
                        xmlTree,
                        pnode,
                        false,
                        pos,
                        nodeName,
                        typeName,
                        haveTypedValue,
                        haveEmptyValue,
                        isInSubstitutionGroup,
                        &localBindings,
                        baseUri);
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new element node N and place it as the last child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a new XML
  tree. 

  Note: This method should be used only while constructing a new xml tree. More
  specifically, it should not be used if the parent node had a child/attribute
  that was deleted some time before the invcation of this method (see comment
  in method XmlNode::XmlNode).

  parent        : The parent P of the new element node; may be NULL.
  nodeName      : The node-name property of N.
  typeName      : The type-name property of N.
                  Not allowed to be NULL, use xsd:untyped instead.
  haveTypedValue: Whether the node has a typed value or not (element nodes with
                  complex type and element-only content do not have typed value).
  haveEmptyValue: True if the typed value of the node is the empty sequence.
                  This is the case if the element has a complex type with empty
                  content.
  isId          :
  isIdRefs      :
  localBindings : A set S1 of namespace bindings. The namespaces property of N
                  is set to S1, plus the ns binding implied by N's qname, plus
                  all the ns bindings of P that are not overwritten by S1 or the
                  ns binding implied by N's qname. Note: when called from an
                  element constructor iterator, S1 is the set of ns bindings
                  defined by ns decalration attrs that appear inside the
                  constructor expr itself.
  baseUri       : The base-uri property of N. It may be NULL, in which case,
                  the base-uri property of N is the same as that of P. If P
                  is NULL, then baseUri will NOT be null (see
                  runtime/core/constructors.cpp).

  The haveTypedValue and haveEmptyValue properties are actually a function of
  the node's type. However, since the store stores only the name of the type
  and does not know anything about the definition of that type, the caller
  of this method must provide the value for these two properties, which are
  needed to implement the getTypedValue() method.
********************************************************************************/
bool BasicItemFactory::createElementNode(
    store::Item_t&              result,
    store::Item*                parent,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    bool                        haveTypedValue,
    bool                        haveEmptyValue,
    const store::NsBindings&    localBindings,
    zstring&                    baseUri,
    bool                        isInSubstitutionGroup)
{
  XmlTree* xmlTree = NULL;
  ElementNode* n = NULL;

  if ( typeName == NULL )
    throw ZORBA_EXCEPTION(
      zerr::ZAPI0014_INVALID_ARGUMENT,
      ERROR_PARAMS( "null", ZED( NotAllowedForTypeName ) )
    );

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();

    n = GET_STORE().getNodeFactory().createElementNode(
                        xmlTree,
                        pnode,
                        true,
                        0,
                        nodeName,
                        typeName,
                        haveTypedValue,
                        haveEmptyValue,
                        isInSubstitutionGroup,
                        &localBindings,
                        baseUri);
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new attribute node N and place it as the pos-th attribute of a given
  parent node. If no parent is given, N becomes the root (and single node) of a
  new XML tree.

  parent        : The parent P of the new attribute node; may be NULL.
  pos           : The position, among the attributes of P, that N will occupy.
                  If pos == current number of P's attributes, then N is appended
                  to the list of attributes.
  nodeName      : The node-name property of N.
  typeName      : The type-name property of N.
  typedValue    : The typed-value property of N, for the case where the
                  typed-value is a single atomic value.
********************************************************************************/
bool BasicItemFactory::createAttributeNode(
    store::Item_t&  result,
    store::Item*    parent,
    ulong           pos,
    store::Item_t&  nodeName,
    store::Item_t&  typeName,
    store::Item_t&  typedValue)
{
  XmlTree* xmlTree = NULL;
  AttributeNode* n = NULL;

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode);

  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();
    }
    else
    {
      pnode->checkUniqueAttr(nodeName.getp());
    }

    n = GET_STORE().getNodeFactory().createAttributeNode(
                          xmlTree,
                          pnode,
                          false,
                          pos,
                          nodeName,
                          typeName,
                          typedValue,
                          false,     // isListValue
                          false);    // hidden
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new attribute node N and place it as the last attribute of a given
  parent node. If no parent is given, N becomes the root (and single node) of a
  new XML tree.

  Note: This method should be used only while constructing a new xml tree. More
  specifically, it should not be used if the parent node had a child/attribute
  that was deleted some time before the invcation of this method (see comment
  in method XmlNode::XmlNode).

  parent        : The parent P of the new attribute node; may be NULL.
  nodeName      : The node-name property of N.
  typeName      : The type-name property of N.
  typedValue    : The typed-value property of N, for the case where the
                  typed-value is a single atomic value.
********************************************************************************/
bool BasicItemFactory::createAttributeNode(
    store::Item_t&  result,
    store::Item*    parent,
    store::Item_t&  nodeName,
    store::Item_t&  typeName,
    store::Item_t&  typedValue)
{
  XmlTree* xmlTree = NULL;
  AttributeNode* n = NULL;

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode);

  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();
    }
    else
    {
      pnode->checkUniqueAttr(nodeName.getp());
    }

    n = GET_STORE().getNodeFactory().createAttributeNode(
                          xmlTree,
                          pnode,
                          true,
                          0,
                          nodeName,
                          typeName,
                          typedValue,
                          false,     // isListValue
                          false);    // hidden
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new attribute node N and place it as the pos-th attribute of a given
  parent node. If no parent is given, N becomes the root (and single node) of a
  new XML tree.

  parent        : The parent P of the new attribute node; may be NULL.
  pos           : The position, among the attributes of P, that N will occupy.
                  If pos == current number of P's attributes, then N is appended
                  to the list of attributes.
  nodeName      : The node-name property of N.
  typeName      : The type-name property of N.
  typedValueV   : The typed-value property of N, for the case where the
                  typed-value is a sequence of atomic values.
********************************************************************************/
bool BasicItemFactory::createAttributeNode(
    store::Item_t&              result,
    store::Item*                parent,
    ulong                       pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    std::vector<store::Item_t>& typedValueV)
{
  XmlTree* xmlTree = NULL;
  AttributeNode* node = NULL;

  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();
    }
    else
    {
      pnode->checkUniqueAttr(nodeName.getp());
    }

    store::Item_t typedValue = new ItemVector(typedValueV);

    node = GET_STORE().getNodeFactory().createAttributeNode(
                             xmlTree,
                             pnode,
                             false,
                             pos,
                             nodeName,
                             typeName,
                             typedValue,
                             true,     // isListValue
                             false);   // hidden
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = node;
  return node != NULL;
}


/*******************************************************************************
  Create a new attribute node N and place it as the last attribute of a given
  parent node. If no parent is given, N becomes the root (and single node) of a
  new XML tree.

  Note: This method should be used only while constructing a new xml tree. More
  specifically, it should not be used if the parent node had a child/attribute
  that was deleted some time before the invcation of this method (see comment
  in method XmlNode::XmlNode).

  parent        : The parent P of the new attribute node; may be NULL.
  pos           : The position, among the attributes of P, that N will occupy.
                  If pos == current number of P's attributes, then N is appended
                  to the list of attributes.
  nodeName      : The node-name property of N.
  typeName      : The type-name property of N.
  typedValueV   : The typed-value property of N, for the case where the
                  typed-value is a sequence of atomic values.
********************************************************************************/
bool BasicItemFactory::createAttributeNode(
    store::Item_t&              result,
    store::Item*                parent,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    std::vector<store::Item_t>& typedValueV)
{
  XmlTree* xmlTree = NULL;
  AttributeNode* node = NULL;

  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();
    }
    else
    {
      pnode->checkUniqueAttr(nodeName.getp());
    }

    store::Item_t typedValue = new ItemVector(typedValueV);

    node = GET_STORE().getNodeFactory().createAttributeNode(
                             xmlTree,
                             pnode,
                             true,
                             0,
                             nodeName,
                             typeName,
                             typedValue,
                             true,     // isListValue
                             false);   // hidden
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = node;
  return node != NULL;
}


/*******************************************************************************
  Create a new text node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree. If N is going to be placed next to an existing text node T,
  then no new text node is actually created, but instead the givan content
  is concatanated with the content of T.

  parent        : The parent P of the new text node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos == current number of P's children, then N is appended
                  to the list of children.
  content       : The content property of N.
********************************************************************************/
bool BasicItemFactory::createTextNode(
    store::Item_t&  result,
    store::Item*    parent,
    ulong           pos,
    zstring&        content)
{
  NodeFactory& factory = GET_NODE_FACTORY();
  XmlTree* xmlTree = NULL;
  TextNode* n = NULL;

  InternalNode* pnode = static_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = factory.createXmlTree();

      n = factory.createTextNode(xmlTree, pnode, false, pos, content);
    }
    else
    {
      csize numChildren = pnode->numChildren();

      XmlNode* lsib = (pos > 0 ? pnode->getChild(pos-1) : NULL);
      XmlNode* rsib = (pos + 1 < numChildren ? pnode->getChild(pos) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == store::StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);

        ZORBA_ASSERT(!textSibling->isTyped());

        zstring content2;
        content2.reserve(textSibling->getText().size() + content.size());
        content2 = textSibling->getText();
        content2 += content;

        textSibling->setText(content2);

        result = lsib;
        return result != NULL;
      }
      else if (rsib != NULL && rsib->getNodeKind() == store::StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(rsib);

        ZORBA_ASSERT(!textSibling->isTyped());

        zstring content2;
        content2.take(content);
        content2 += textSibling->getText();
        textSibling->setText(content2);

        result = rsib;
        return result != NULL;
      }
      else
      {
        n = factory.createTextNode(xmlTree, pnode, false, pos, content);
      }
    }
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new text node N and place it as the last child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree. If N is going to be placed next to an existing text node T,
  then no new text node is actually created, but instead the givan content
  is concatanated with the content of T.

  Note: This method should be used only while constructing a new xml tree. More
  specifically, it should not be used if the parent node had a child/attribute
  that was deleted some time before the invcation of this method (see comment
  in method XmlNode::XmlNode).

  parent        : The parent P of the new text node; may be NULL.
  content       : The content property of N.
********************************************************************************/
bool BasicItemFactory::createTextNode(
    store::Item_t&  result,
    store::Item*    parent,
    zstring&        content)
{
  NodeFactory& factory = GET_NODE_FACTORY();
  XmlTree* xmlTree = NULL;
  TextNode* n = NULL;

  InternalNode* pnode = static_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = factory.createXmlTree();

      n = factory.createTextNode(xmlTree, pnode, false, 0, content);
    }
    else
    {
      csize pos = pnode->numChildren();

      XmlNode* lsib = ( pos > 0 ? pnode->getChild(pos-1) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == store::StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);

        ZORBA_ASSERT(!textSibling->isTyped());

        zstring content2;
        content2.reserve(textSibling->getText().size() + content.size());
        content2 = textSibling->getText();
        content2 += content;

        textSibling->setText(content2);

        result = lsib;
        return result != NULL;
      }
      else
      {
        n = factory.createTextNode(xmlTree, pnode, true, 0, content);
      }
    }
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new text node N to store the typed value of a given element node P
  (the parent of N) that has simple type or complex type with simple content.

  The typed value of P consists of a single atomic value.

  P is not allowed to have any other text or element children.

  parent        : The parent P of the new text node; must not be NULL.
  content       : The typed value of P.
********************************************************************************/
bool BasicItemFactory::createTextNode(
    store::Item_t&    result,
    store::Item*      parent,
    store::Item_t&    content)
{
  assert(parent != NULL);
  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  // Note: the TextNode constructor asserts that the parent has 0 children
  result = GET_NODE_FACTORY().createTextNode(pnode, content, false);
  return true;
}


/*******************************************************************************
  Create a new text node N to store the typed value of a given element node P
  (the parent of N) that has simple type or complex type with simple content.

  The typed value of P is a list of atomic values.

  P is not allowed to have any other text or element children.

  parent        : The parent P of the new text node; must not be NULL.
  content       : The typed value of P.
********************************************************************************/
bool BasicItemFactory::createTextNode(
    store::Item_t&              result,
    store::Item*                parent,
    std::vector<store::Item_t>& content)
{
  assert(parent != NULL);
  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  store::Item_t typedValue = new ItemVector(content);
  result = GET_NODE_FACTORY().createTextNode(pnode, typedValue, true);
  return true;
}


/*******************************************************************************
  Create a new pi node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree.

  parent        : The parent P of the new pi node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos == current number of P's children, then N is appended
                  to the list of children.
  target        : The target property of N.
  content       : The content property of N.
  baseUri       : The base-uri property of N.
********************************************************************************/
bool BasicItemFactory::createPiNode(
    store::Item_t& result,
    store::Item*   parent,
    ulong          pos,
    zstring&       target,
    zstring&       content,
    zstring&       baseUri)
{
  XmlTree* xmlTree = NULL;
  PiNode* n = NULL;

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_NODE_FACTORY().createXmlTree();

    n = GET_NODE_FACTORY().createPiNode(xmlTree, pnode, false, pos, target, content);
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new pi node N and place it as the last child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree.

  Note: This method should be used only while constructing a new xml tree. More
  specifically, it should not be used if the parent node had a child/attribute
  that was deleted some time before the invcation of this method (see comment
  in method XmlNode::XmlNode).

  parent        : The parent P of the new pi node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos == current number of P's children, then N is appended
                  to the list of children.
  target        : The target property of N.
  content       : The content property of N.
  baseUri       : The base-uri property of N.
********************************************************************************/
bool BasicItemFactory::createPiNode(
    store::Item_t& result,
    store::Item*   parent,
    zstring&       target,
    zstring&       content,
    zstring&       baseUri)
{
  XmlTree* xmlTree = NULL;
  PiNode* n = NULL;

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_NODE_FACTORY().createXmlTree();

    n = GET_NODE_FACTORY().createPiNode(xmlTree, pnode, true, 0, target, content);
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new comment node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree.

  parent        : The parent P of the new comment node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos == current number of P's children, then N is appended
                  to the list of children.
  content       : The content property of N.
********************************************************************************/
bool BasicItemFactory::createCommentNode(
    store::Item_t& result,
    store::Item*   parent,
    ulong          pos,
    zstring&       content)
{
  XmlTree* xmlTree = NULL;
  CommentNode* n = NULL;

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_NODE_FACTORY().createXmlTree();

    n = GET_NODE_FACTORY().createCommentNode(xmlTree, pnode, false, pos, content);
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new comment node N and place it as the last child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree.

  Note: This method should be used only while constructing a new xml tree. More
  specifically, it should not be used if the parent node had a child/attribute
  that was deleted some time before the invcation of this method (see comment
  in method XmlNode::XmlNode).

  parent        : The parent P of the new comment node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos == current number of P's children, then N is appended
                  to the list of children.
  content       : The content property of N.
********************************************************************************/
bool BasicItemFactory::createCommentNode(
    store::Item_t& result,
    store::Item*   parent,
    zstring&       content)
{
  XmlTree* xmlTree = NULL;
  CommentNode* n = NULL;

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_NODE_FACTORY().createXmlTree();

    n = GET_NODE_FACTORY().createCommentNode(xmlTree, pnode, true, 0, content);
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************

********************************************************************************/
store::PUL* BasicItemFactory::createPendingUpdateList()
{
  return new PULImpl();
}

#if 0
/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createTuple(
        store::Item_t& result,
        std::vector<store::TupleField>& fields)
{
  result = new TupleItem(fields);
  return true;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createTuple(
        store::Item_t& result,
        store::Item *inTuple,
        std::vector<int>& permutation)
{
  ZORBA_ASSERT(inTuple->isTuple());
  std::vector<zorba::store::TupleField> newFields;
  int n = permutation.size();
  for(int i = 0; i <= n; ++i) {
    newFields.push_back(inTuple->getTupleField(permutation[i]));
  }
  result = new TupleItem(newFields);
  return true;
}
#endif

/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createError(
    store::Item_t& result,
    ZorbaException* inError)
{
  result = new ErrorItem(inError);
  return true;
}


void BasicItemFactory::splitToAtomicTextValues(
    zstring& textValue,
    std::vector<zstring>& atomicTextValues)
{
  ascii::normalize_whitespace(textValue);

  zstring::size_type start = 0;
  zstring::size_type i = 0;

  while (i < textValue.size())
  {
    if (isspace(textValue[i]))
    {
      atomicTextValues.push_back(textValue.substr(start, i - start));
      start = i+1;
    }
    i++;
  }

  if ( start < (i-1) )
    atomicTextValues.push_back(textValue.substr(start, i-start));
}


#ifdef ZORBA_WITH_JSON
/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createJSONNull(store::Item_t& result)
{
  result = theNullItem;
  return true;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createJSONNumber(
    store::Item_t& result,
    store::Item_t& string)
{
  zstring s = string->getStringValue();
  return createJSONNumber(result, s);
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createJSONNumber(
    store::Item_t& result,
    zstring& string)
{
  try
  {
    bool dot = (strchr(string.c_str(), 46) != NULL);
    bool e   = (strpbrk(string.c_str(), "eE") != NULL);
    if (!e)
    {
      if (!dot)
      {
        // xs:integer
        xs_integer i = Integer(string.c_str());
        return createInteger(result, i);
      }
      else
      {
        // xs:decimal
        xs_decimal d = Decimal(string.c_str());
        return createDecimal(result, d);
      }
    }
    else
    {
      // xs:double
      xs_double d = FloatImpl<double>(string.c_str());
      return createDouble(result, d);
    }
  }
  catch (std::exception& e)
  {
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createJSONArray(
    store::Item_t& result,
    const std::vector<store::Iterator_t>& sources,
    const std::vector<store::CopyMode>& copyModes)
{
  result = new json::SimpleJSONArray();

  json::JSONArray* array = static_cast<json::JSONArray*>(result.getp());

  store::Item_t item;

  csize numSources = sources.size();
  for (csize i = 0; i < numSources; ++i)
  {
    store::Iterator* source = sources[i].getp();
    const store::CopyMode& copymode = copyModes[i];

    while (source->next(item))
    {
      if (copymode.theDoCopy && (item->isStructuredItem()))
        item = item->copy(NULL, copymode);
      
      array->push_back(item);
    }
  }

  return true;
}


bool BasicItemFactory::createJSONArray(
    store::Item_t& result,
    store::Item_t& item1,
    store::Item_t& item2,
    const store::Iterator_t& source,
    const store::CopyMode& copymode)
{
  result = new json::SimpleJSONArray();

  json::SimpleJSONArray* array = static_cast<json::SimpleJSONArray*>(result.getp());

  array->push_back(item1);
  array->push_back(item2);
  
  store::Item_t item;

  while (source->next(item))
  {
    if (copymode.theDoCopy && (item->isNode() || item->isJSONItem()))
      item = item->copy(NULL, copymode);
      
    array->push_back(item);
  }

  return true;
}


bool BasicItemFactory::createJSONArray(
    store::Item_t& result,
    const std::vector<store::Item_t>& items)
{
  result = new json::SimpleJSONArray();

  json::JSONArray* array = static_cast<json::JSONArray*>(result.getp());

  std::vector<store::Item_t>::const_iterator ite = items.begin();
  std::vector<store::Item_t>::const_iterator end = items.end();
  for (; ite != end; ++ite)
  {
    array->push_back(*ite);
  }
  return true;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createJSONObject(
    store::Item_t& result, 
    const std::vector<store::Iterator_t>& sources,
    const std::vector<store::CopyMode>& copyModes,
    bool accumulate)
{
  result = new json::SimpleJSONObject();

  json::JSONObject* obj = static_cast<json::JSONObject*>(result.getp());

  store::Item_t objItem;
  store::Item_t keyItem;
  store::Item_t valueItem;

  csize numSources = sources.size();
  for (csize i = 0; i < numSources; ++i)
  {
    store::Iterator* source = sources[i].getp();
    const store::CopyMode& copymode = copyModes[i];

    while (source->next(objItem))
    {
      assert(objItem->isJSONObject());

      json::SimpleJSONObject* sourceObj = 
      static_cast<json::SimpleJSONObject*>(objItem.getp());

      store::Iterator_t sourceKeys = sourceObj->getObjectKeys();

      sourceKeys->open();

      while (sourceKeys->next(keyItem))
      {
        valueItem = objItem->getObjectValue(keyItem);
        if (copymode.theDoCopy &&
            (valueItem->isJSONArray() ||
             valueItem->isJSONObject() ||
             valueItem->isNode()))
        {
          valueItem = valueItem->copy(NULL, copymode);
        }
        
        if (!obj->add(keyItem, valueItem, accumulate))
        {
          RAISE_ERROR_NO_LOC(jerr::JNDY0003,
          ERROR_PARAMS(keyItem->getStringValue()));
        }
      }

      sourceKeys->close();
    }
  }

  return true;
}


bool BasicItemFactory::createJSONObject(
    store::Item_t& result,
    const std::vector<store::Item_t>& names,
    const std::vector<store::Item_t>& values)
{
  result = new json::SimpleJSONObject();

  json::JSONObject* obj = static_cast<json::JSONObject*>(result.getp());

  assert(names.size() == values.size());

  csize numPairs = names.size();
  for (csize i = 0; i < numPairs; ++i)
  {
    if (!obj->add(names[i], values[i], false))
    {
      RAISE_ERROR_NO_LOC(jerr::JNDY0003, ERROR_PARAMS(names[i]->getStringValue()));
    }
  }

  return true;
}


#endif

} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
