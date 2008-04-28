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
#include "errors/error_manager.h"
#include "types/typeops.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "context/namespace_context.h"
#include "types/typeconstants.h"
#include "util/Assert.h"
#include "types/delegating_typemanager.h"


namespace zorba
{

#define ATOMIC_TYPE(type) \
  GENV_TYPESYSTEM.create_atomic_type(TypeConstants::XS_##type, TypeConstants::QUANT_ONE)

#define ATOMICTYPE_T \
  TypeConstants::atomic_type_code_t

typedef struct
{
	unsigned short	left, right;
} CodePointRange_t;


static const CodePointRange_t	base_char_range[] = 
{
	{0x0041,0x005A}, {0x0061,0x007A}, {0x00C0,0x00D6}, {0x00D8,0x00F6}, {0x00F8,0x00FF}, {0x0100,0x0131}, 
  {0x0134,0x013E}, {0x0141,0x0148}, {0x014A,0x017E}, {0x0180,0x01C3}, {0x01CD,0x01F0}, {0x01F4,0x01F5}, 
  {0x01FA,0x0217}, {0x0250,0x02A8}, {0x02BB,0x02C1}, {0x0386,0x0386}, {0x0388,0x038A}, {0x038C,0x038C}, 
  {0x038E,0x03A1}, {0x03A3,0x03CE}, {0x03D0,0x03D6}, {0x03DA,0x03DA}, {0x03DC,0x03DC}, {0x03DE,0x03DE}, 
  {0x03E0,0x03E0}, {0x03E2,0x03F3}, {0x0401,0x040C}, {0x040E,0x044F}, {0x0451,0x045C}, {0x045E,0x0481}, 
	{0x0490,0x04C4}, {0x04C7,0x04C8}, {0x04CB,0x04CC}, {0x04D0,0x04EB}, {0x04EE,0x04F5}, {0x04F8,0x04F9}, 
  {0x0531,0x0556}, {0x0559,0x0559}, {0x0561,0x0586}, {0x05D0,0x05EA}, {0x05F0,0x05F2}, {0x0621,0x063A}, 
  {0x0641,0x064A}, {0x0671,0x06B7}, {0x06BA,0x06BE}, {0x06C0,0x06CE}, {0x06D0,0x06D3}, {0x06D5,0x06D5}, 
  {0x06E5,0x06E6}, {0x0905,0x0939}, {0x093D,0x093D}, {0x0958,0x0961}, {0x0985,0x098C}, {0x098F,0x0990}, 
  {0x0993,0x09A8}, {0x09AA,0x09B0}, {0x09B2,0x09B2}, {0x09B6,0x09B9}, {0x09DC,0x09DD}, {0x09DF,0x09E1}, 
	{0x09F0,0x09F1}, {0x0A05,0x0A0A}, {0x0A0F,0x0A10}, {0x0A13,0x0A28}, {0x0A2A,0x0A30}, {0x0A32,0x0A33}, 
  {0x0A35,0x0A36}, {0x0A38,0x0A39}, {0x0A59,0x0A5C}, {0x0A5E,0x0A5E}, {0x0A72,0x0A74}, {0x0A85,0x0A8B}, 
  {0x0A8D,0x0A8D}, {0x0A8F,0x0A91}, {0x0A93,0x0AA8}, {0x0AAA,0x0AB0}, {0x0AB2,0x0AB3}, {0x0AB5,0x0AB9}, 
  {0x0ABD,0x0ABD}, {0x0AE0,0x0AE0}, {0x0B05,0x0B0C}, {0x0B0F,0x0B10}, {0x0B13,0x0B28}, {0x0B2A,0x0B30}, 
  {0x0B32,0x0B33}, {0x0B36,0x0B39}, {0x0B3D,0x0B3D}, {0x0B5C,0x0B5D}, {0x0B5F,0x0B61}, {0x0B85,0x0B8A}, 
	{0x0B8E,0x0B90}, {0x0B92,0x0B95}, {0x0B99,0x0B9A}, {0x0B9C,0x0B9C}, {0x0B9E,0x0B9F}, {0x0BA3,0x0BA4}, 
  {0x0BA8,0x0BAA}, {0x0BAE,0x0BB5}, {0x0BB7,0x0BB9}, {0x0C05,0x0C0C}, {0x0C0E,0x0C10}, {0x0C12,0x0C28}, 
  {0x0C2A,0x0C33}, {0x0C35,0x0C39}, {0x0C60,0x0C61}, {0x0C85,0x0C8C}, {0x0C8E,0x0C90}, {0x0C92,0x0CA8}, 
  {0x0CAA,0x0CB3}, {0x0CB5,0x0CB9}, {0x0CDE,0x0CDE}, {0x0CE0,0x0CE1}, {0x0D05,0x0D0C}, {0x0D0E,0x0D10}, 
  {0x0D12,0x0D28}, {0x0D2A,0x0D39}, {0x0D60,0x0D61}, {0x0E01,0x0E2E}, {0x0E30,0x0E30}, {0x0E32,0x0E33}, 
	{0x0E40,0x0E45}, {0x0E81,0x0E82}, {0x0E84,0x0E84}, {0x0E87,0x0E88}, {0x0E8A,0x0E8A}, {0x0E8D,0x0E8D}, 
  {0x0E94,0x0E97}, {0x0E99,0x0E9F}, {0x0EA1,0x0EA3}, {0x0EA5,0x0EA5}, {0x0EA7,0x0EA7}, {0x0EAA,0x0EAB}, 
  {0x0EAD,0x0EAE}, {0x0EB0,0x0EB0}, {0x0EB2,0x0EB3}, {0x0EBD,0x0EBD}, {0x0EC0,0x0EC4}, {0x0F40,0x0F47}, 
  {0x0F49,0x0F69}, {0x10A0,0x10C5}, {0x10D0,0x10F6}, {0x1100,0x1100}, {0x1102,0x1103}, {0x1105,0x1107}, 
  {0x1109,0x1109}, {0x110B,0x110C}, {0x110E,0x1112}, {0x113C,0x113C}, {0x113E,0x113E}, {0x1140,0x1140}, 
  {0x114C,0x114C}, {0x114E,0x114E}, {0x1150,0x1150}, {0x1154,0x1155}, {0x1159,0x1159}, {0x115F,0x1161}, 
	{0x1163,0x1163}, {0x1165,0x1165}, {0x1167,0x1167}, {0x1169,0x1169}, {0x116D,0x116E}, {0x1172,0x1173}, 
	{0x1175,0x1175}, {0x119E,0x119E}, {0x11A8,0x11A8}, {0x11AB,0x11AB}, {0x11AE,0x11AF}, {0x11B7,0x11B8},
  {0x11BA,0x11BA}, {0x11BC,0x11C2}, {0x11EB,0x11EB}, {0x11F0,0x11F0}, {0x11F9,0x11F9}, {0x1E00,0x1E9B}, 
  {0x1EA0,0x1EF9}, {0x1F00,0x1F15}, {0x1F18,0x1F1D}, {0x1F20,0x1F45}, {0x1F48,0x1F4D}, {0x1F50,0x1F57}, 
  {0x1F59,0x1F59}, {0x1F5B,0x1F5B}, {0x1F5D,0x1F5D}, {0x1F5F,0x1F7D}, {0x1F80,0x1FB4}, {0x1FB6,0x1FBC}, 
  {0x1FBE,0x1FBE}, {0x1FC2,0x1FC4}, {0x1FC6,0x1FCC}, {0x1FD0,0x1FD3}, {0x1FD6,0x1FDB}, {0x1FE0,0x1FEC}, 
  {0x1FF2,0x1FF4}, {0x1FF6,0x1FFC}, {0x2126,0x2126}, {0x212A,0x212B}, {0x212E,0x212E}, {0x2180,0x2182}, 
  {0x3041,0x3094}, {0x30A1,0x30FA}, {0x3105,0x312C}, {0xAC00,0xD7A3}
};


static const CodePointRange_t	ideographic_range[] = 
{
	{0x4E00,0x9FA5} , {0x3007, 0x3007} , {0x3021,0x3029}
};


static const CodePointRange_t	combining_char_range[] = 
{
	{0x0300,0x0345}, {0x0360,0x0361}, {0x0483,0x0486}, {0x0591,0x05A1}, {0x05A3,0x05B9}, {0x05BB,0x05BD},  
  {0x05BF,0x05BF}, {0x05C1,0x05C2}, {0x05C4,0x05C4}, {0x064B,0x0652}, {0x0670,0x0670}, {0x06D6,0x06DC}, 
  {0x06DD,0x06DF}, {0x06E0,0x06E4}, {0x06E7,0x06E8}, {0x06EA,0x06ED}, {0x0901,0x0903}, {0x093C,0x093C}, 
  {0x093E,0x094C}, {0x094D,0x094D}, {0x0951,0x0954}, {0x0962,0x0963}, {0x0981,0x0983}, {0x09BC,0x09BC},
  {0x09BE,0x09BE}, {0x09BF,0x09BF}, {0x09C0,0x09C4}, {0x09C7,0x09C8}, {0x09CB,0x09CD}, {0x09D7,0x09D7}, 
	{0x09E2,0x09E3}, {0x0A02,0x0A02}, {0x0A3C,0x0A3C}, {0x0A3E,0x0A3E}, {0x0A3F,0x0A3F}, {0x0A40,0x0A42},
  {0x0A47,0x0A48}, {0x0A4B,0x0A4D}, {0x0A70,0x0A71}, {0x0A81,0x0A83}, {0x0ABC,0x0ABC}, {0x0ABE,0x0AC5},
  {0x0AC7,0x0AC9}, {0x0ACB,0x0ACD}, {0x0B01,0x0B03}, {0x0B3C,0x0B3C}, {0x0B3E,0x0B43}, {0x0B47,0x0B48},  
  {0x0B4B,0x0B4D}, {0x0B56,0x0B57}, {0x0B82,0x0B83}, {0x0BBE,0x0BC2}, {0x0BC6,0x0BC8}, {0x0BCA,0x0BCD},  
  {0x0BD7,0x0BD7}, {0x0C01,0x0C03}, {0x0C3E,0x0C44}, {0x0C46,0x0C48}, {0x0C4A,0x0C4D}, {0x0C55,0x0C56},  
	{0x0C82,0x0C83}, {0x0CBE,0x0CC4}, {0x0CC6,0x0CC8}, {0x0CCA,0x0CCD}, {0x0CD5,0x0CD6}, {0x0D02,0x0D03},  
  {0x0D3E,0x0D43}, {0x0D46,0x0D48}, {0x0D4A,0x0D4D}, {0x0D57,0x0D57}, {0x0E31,0x0E31}, {0x0E34,0x0E3A},  
  {0x0E47,0x0E4E}, {0x0EB1,0x0EB1}, {0x0EB4,0x0EB9}, {0x0EBB,0x0EBC}, {0x0EC8,0x0ECD}, {0x0F18,0x0F19},  
  {0x0F35,0x0F35}, {0x0F37,0x0F37}, {0x0F39,0x0F39}, {0x0F3E,0x0F3E}, {0x0F3F,0x0F3F}, {0x0F71,0x0F84},  
  {0x0F86,0x0F8B}, {0x0F90,0x0F95}, {0x0F97,0x0F97}, {0x0F99,0x0FAD}, {0x0FB1,0x0FB7}, {0x0FB9,0x0FB9},
	{0x20D0,0x20DC}, {0x20E1,0x20E1}, {0x302A,0x302F}, {0x3099,0x3099}, {0x309A,0x309A} 
};


static const CodePointRange_t	digit_range[] = 
{
	{0x0030,0x0039}, {0x0660,0x0669}, {0x06F0,0x06F9}, {0x0966,0x096F}, {0x09E6,0x09EF}, {0x0A66,0x0A6F},  
  {0x0AE6,0x0AEF}, {0x0B66,0x0B6F}, {0x0BE7,0x0BEF}, {0x0C66,0x0C6F}, {0x0CE6,0x0CEF}, {0x0D66,0x0D6F},  
  {0x0E50,0x0E59}, {0x0ED0,0x0ED9}, {0x0F20,0x0F29}
};


static const CodePointRange_t	extender_range[] = 
{
	{0x00B7,0x00B7}, {0x02D0,0x02D0}, {0x02D1,0x02D1}, {0x0387,0x0387}, {0x0640,0x0640}, {0x0E46,0x0E46},
  {0x0EC6,0x0EC6}, {0x3005,0x3005}, {0x3031,0x3035}, {0x309D,0x309E}, {0x30FC,0x30FE}
};

struct ErrorInfo
{
  const XQType* theSourceType;
  const XQType* theTargetType;
};

inline void throwError(ZorbaError::ErrorCode aErrorCode, const ErrorInfo& aInfo)
{
  ZORBA_ERROR_DESC_OSS(aErrorCode, 
                       "Passed item (of type " << TypeOps::toString(*aInfo.theSourceType)
                       << ") is not castable to passed target type (" 
                       << TypeOps::toString (*aInfo.theTargetType) << ").");

};

inline xqpStringStore_t doTrim(xqpStringStore_t aStr)
{
  return aStr->trim(" \t\r\n", 4);
};

#define SAME_S_AND_T(type)                                                     \
  inline store::Item_t type##_##type(store::Item* aItem, store::ItemFactory*, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)  \
  {                                                                            \
    return aItem;                                                              \
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


inline store::Item_t str_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createUntypedAtomic(aItem->getStringValue());
}

inline store::Item_t str_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_float n;
  if (NumConversions::strToFloat(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createFloat(n);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_double n;
  if (NumConversions::strToDouble(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createDouble(n);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_decimal n;
  if (NumConversions::strToDecimal(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createDecimal(n);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_integer n;
  if (NumConversions::strToInteger(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createInteger(n);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_dur(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  Duration_t d_t;
  if (Duration::parse_string(doTrim(aItem->getStringValue()).getp(), d_t))
  {
    xqp_duration d = d_t;
    return aFactory->createDuration(d);
  }

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_yMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  YearMonthDuration_t ymd_t;
  if (YearMonthDuration::parse_string(doTrim(aItem->getStringValue()).getp(), ymd_t))
  {
    xqp_duration d = ymd_t;
    return aFactory->createDuration(d);
  }

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_dTD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DayTimeDuration_t dtd_t;
  if (DayTimeDuration::parse_string(doTrim(aItem->getStringValue()).getp(), dtd_t))
  {
    xqp_duration d = dtd_t;
    return aFactory->createDuration(d);
  }

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_dT(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_dateTime dt;
  if (0 == DateTime::parseDateTime(doTrim(aItem->getStringValue()).getp(), dt))
    return aFactory->createDateTime(dt);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_tim(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_time t;
  if (0 == DateTime::parseTime(doTrim(aItem->getStringValue()).getp(), t))
    return aFactory->createTime(t);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_dat(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_date d;
  if (0 == DateTime::parseDate(doTrim(aItem->getStringValue()).getp(), d))
    return aFactory->createDate(d);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_gYM(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gYearMonth ym;
  if (0 == DateTime::parseGYearMonth(doTrim(aItem->getStringValue()).getp(), ym))
    return aFactory->createGYearMonth(ym);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_gYr(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gYear y;
  if (0 == DateTime::parseGYear(doTrim(aItem->getStringValue()).getp(), y))
    return aFactory->createGYear(y);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_gMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gMonthDay md;
  if (0 == DateTime::parseGMonthDay(doTrim(aItem->getStringValue()).getp(), md))
    return aFactory->createGMonthDay(md);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_gDay(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gDay d;
  if (0 == DateTime::parseGDay(doTrim(aItem->getStringValue()).getp(), d))
    return aFactory->createGDay(d);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_gMon(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_gMonth m;
  if (0 == DateTime::parseGMonth(doTrim(aItem->getStringValue()).getp(), m))
    return aFactory->createGMonth(m);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  bool lRetValue = true;
  xqpStringStore_t lString = doTrim(aItem->getStringValue());

  if (lString->byteEqual("false", 5) || lString->byteEqual("0", 1))
    lRetValue = false;
  else if (!lString->byteEqual("true", 4) && !lString->byteEqual("1", 1))
    throwError(ZorbaError::FORG0001, aErrorInfo);

return aFactory->createBoolean(lRetValue);
}

inline store::Item_t str_b64(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_base64Binary n;
  if (xqp_base64Binary::parseString(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createBase64Binary(n);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_hxB(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_hexBinary n;
  if (xqp_hexBinary::parseString(doTrim(aItem->getStringValue()).getp(), n))
    return aFactory->createHexBinary(n);

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

inline store::Item_t str_aURI(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
// TODO createAnyURI does not always succeed
return aFactory->createAnyURI(doTrim(aItem->getStringValue()));
}

inline store::Item_t str_QN(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  assert(nsCtx != 0);

  xqpString str(doTrim(aItem->getStringValue()));
  int32_t idx = str.theStrStore->indexOf(":");
  int32_t lidx = str.theStrStore->lastIndexOf(":");
  if (idx != lidx)
    throwError(ZorbaError::FORG0001, aErrorInfo);

  xqpString lUri, lPrefix;
  
  if (idx < 0)
  {
    lPrefix = "";
    nsCtx->findBinding(lPrefix, lUri);
  } else {
    lPrefix = str.substr(0, idx);
    if (!GenericCast::instance()->castableToNCName(lPrefix.getStore()))
      throwError(ZorbaError::FORG0001, aErrorInfo);
    if (!nsCtx->findBinding(lPrefix, lUri))
      throwError(ZorbaError::FONS0004, aErrorInfo);
  }

  xqpString lLocal = str.substr(idx + 1);

  if (!GenericCast::instance()->castableToNCName(lLocal.getStore()))
    throwError(ZorbaError::FORG0001, aErrorInfo);


  return aFactory->createQName(&*lUri.theStrStore, 
                               &*lPrefix.theStrStore, 
                               &*lLocal.theStrStore);
}

inline store::Item_t str_NOT(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createNOTATION(doTrim(aItem->getStringValue()).getp());
}

inline store::Item_t uA_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createString(aItem->getStringValue());  
}

inline store::Item_t uA_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_flt(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dbl(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dec(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_int(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_dur(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dur(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_yMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_yMD(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_dTD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dTD(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_dT(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dT(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_tim(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_tim(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_dat(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_dat(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_gYM(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gYM(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_gYr(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gYr(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_gMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gMD(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_gDay(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gDay(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_gMon(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_gMon(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_bool(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_b64(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_b64(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_hxB(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_hxB(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t uA_aURI(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_aURI(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t flt_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t flt_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t flt_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createDouble(FloatCommons::parseFloat(aItem->getFloatValue()));
}

inline store::Item_t flt_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_decimal n;
  if (xqp_decimal::parseFloat(aItem->getFloatValue(), n))
    return aFactory->createDecimal(n);

  throwError(ZorbaError::FOCA0002, aErrorInfo);
  return 0;
}

inline store::Item_t flt_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_integer n;
  if (xqp_integer::parseFloat(aItem->getFloatValue(), n))
    return aFactory->createInteger(n);

  throwError(ZorbaError::FOCA0002, aErrorInfo);
  return 0;
}

inline store::Item_t flt_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aItem->getEBV();
}

inline store::Item_t dbl_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dbl_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dbl_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createFloat(FloatCommons::parseDouble(aItem->getDoubleValue()));
}

inline store::Item_t dbl_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_decimal n;
  if (xqp_decimal::parseDouble(aItem->getDoubleValue(), n))
    return aFactory->createDecimal(n);

  throwError(ZorbaError::FOCA0002, aErrorInfo);
  return 0;
}

inline store::Item_t dbl_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_integer n;
  if (xqp_integer::parseDouble(aItem->getDoubleValue(), n))
    return aFactory->createInteger(n);

  throwError(ZorbaError::FOCA0002, aErrorInfo);
  return 0;
}

inline store::Item_t dbl_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aItem->getEBV();
}

inline store::Item_t dec_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dec_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dec_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createFloat(xqp_float::parseDecimal(aItem->getDecimalValue()));
}

inline store::Item_t dec_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createDouble(xqp_double::parseDecimal(aItem->getDecimalValue()));
}

inline store::Item_t dec_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createInteger(xqp_integer::parseDecimal(aItem->getDecimalValue()));
}

inline store::Item_t dec_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aItem->getEBV();
}

inline store::Item_t int_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t int_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t int_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createFloat(xqp_float::parseInteger(aItem->getIntegerValue()));
}

inline store::Item_t int_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createDouble(xqp_double::parseInteger(aItem->getIntegerValue()));
}

inline store::Item_t int_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createDecimal(xqp_decimal::parseInteger(aItem->getIntegerValue()));
}

inline store::Item_t int_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aItem->getEBV();
}

inline store::Item_t dur_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dur_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dur_yMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getDurationValue()->toYearMonthDuration();
  return aFactory->createDuration(dur);
}

inline store::Item_t dur_dTD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getDurationValue()->toDayTimeDuration();
  return aFactory->createDuration(dur);
}

inline store::Item_t yMD_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t yMD_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t yMD_dur(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getYearMonthDurationValue()->toDuration();
  return aFactory->createDuration(dur);
}

inline store::Item_t yMD_dTD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getYearMonthDurationValue()->toDayTimeDuration();
  return aFactory->createDuration(dur);
}

inline store::Item_t dTD_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dTD_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dTD_dur(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getDayTimeDurationValue()->toDuration();
  return aFactory->createDuration(dur);
}

inline store::Item_t dTD_yMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  xqp_duration dur = aItem->getDayTimeDurationValue()->toYearMonthDuration();
  return aFactory->createDuration(dur);
}

inline store::Item_t dT_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dT_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dT_tim(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::TIME_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dT_dat(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::DATE_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dT_gYM(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GYEARMONTH_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dT_gYr(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GYEAR_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dT_gMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GMONTHDAY_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dT_gDay(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GDAY_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dT_gMon(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateTimeValue()->createWithNewFacet(DateTime::GMONTH_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t tim_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t tim_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dat_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dat_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t dat_dT(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateValue()->createWithNewFacet(DateTime::DATETIME_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dat_gYM(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateValue()->createWithNewFacet(DateTime::GYEARMONTH_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dat_gYr(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateValue()->createWithNewFacet(DateTime::GYEAR_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dat_gMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateValue()->createWithNewFacet(DateTime::GMONTHDAY_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dat_gDay(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateValue()->createWithNewFacet(DateTime::GDAY_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t dat_gMon(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  DateTime_t dt_t;
  aItem->getDateValue()->createWithNewFacet(DateTime::GMONTH_FACET, dt_t);
  return aFactory->createTime(dt_t);
}

inline store::Item_t gYM_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gYM_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gYr_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gYr_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gMD_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gMD_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gDay_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gDay_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gMon_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t gMon_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t bool_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t bool_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t bool_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  if (aItem->getBooleanValue())
    return aFactory->createFloat(xqp_float::parseInt(1));
  else
    return aFactory->createFloat(xqp_float::zero());
}

inline store::Item_t bool_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  if (aItem->getBooleanValue())
    return aFactory->createDouble(xqp_double::parseInt(1));
  else
    return aFactory->createDouble(xqp_double::zero());
}

inline store::Item_t bool_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  if (aItem->getBooleanValue())
    return aFactory->createDecimal(xqp_decimal::parseInt(1));
  else
    return aFactory->createDecimal(xqp_decimal::zero());
}

inline store::Item_t bool_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  if (aItem->getBooleanValue())
    return aFactory->createInteger(xqp_integer::parseInt(1));
  else
    return aFactory->createInteger(xqp_integer::zero());
}

inline store::Item_t b64_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t b64_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t b64_hxB(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createHexBinary(xqp_hexBinary(aItem->getBase64BinaryValue()));
}

inline store::Item_t hxB_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t hxB_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t hxB_b64(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return aFactory->createBase64Binary(xqp_base64Binary(aItem->getHexBinaryValue()));
}

inline store::Item_t aURI_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t aURI_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t QN_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t QN_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t NOT_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return str_uA(aItem, aFactory, nsCtx, aErrorInfo);
}

inline store::Item_t NOT_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx, const ErrorInfo& aErrorInfo)
{
  return uA_str(aItem, aFactory, nsCtx, aErrorInfo);
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

store::Item_t str_down(
                const store::Item* aItem, 
                RootTypeManager& aTS,
                ATOMICTYPE_T aTargetAtomicType,
                store::ItemFactory* aFactory,
                const ErrorInfo& aErrorInfo)
{
  xqpStringStore_t lString = aItem->getStringValue();
  xqpString str(lString);

  switch(aTargetAtomicType)
  {
  case TypeConstants::XS_NORMALIZED_STRING:
    if (GenericCast::instance()->castableToNormalizedString(lString))
      return aFactory->createNormalizedString(str);
    break;
  case TypeConstants::XS_TOKEN:
    if (GenericCast::instance()->castableToToken(lString))
      return aFactory->createToken(str);
    break;
  case TypeConstants::XS_LANGUAGE:
    if (GenericCast::instance()->castableToLanguage(lString))
      return aFactory->createLanguage(str);
    break;
  case TypeConstants::XS_NMTOKEN:
    if (GenericCast::instance()->castableToNMToken(lString))
      return aFactory->createNMTOKEN(str);
    break;
  case TypeConstants::XS_NAME:
    if (GenericCast::instance()->castableToName(lString))
      return aFactory->createName(str);
    break;
  case TypeConstants::XS_NCNAME:
    if (GenericCast::instance()->castableToNCName(lString))
      return aFactory->createNCName(lString);
    break;
  case TypeConstants::XS_ID:
    if (GenericCast::instance()->castableToNCName(lString))
      return aFactory->createID(str);
    break;
  case TypeConstants::XS_IDREF:
    if (GenericCast::instance()->castableToNCName(lString))
      return aFactory->createIDREF(str);
    break;
  case TypeConstants::XS_ENTITY:
    if (GenericCast::instance()->castableToNCName(lString))
      return aFactory->createENTITY(str);
    break;
  default:
    assert(false);
  }

  throwError(ZorbaError::FORG0001, aErrorInfo);
  return 0;
}

store::Item_t int_down(
                const store::Item* aItem, 
                RootTypeManager& aTS,
                ATOMICTYPE_T aTargetAtomicType,
                store::ItemFactory* aFactory,
                const ErrorInfo& aErrorInfo)
{
  xqp_integer lInteger = aItem->getIntegerValue();
  xqpStringStore_t lString = aItem->getStringValue();

  switch(aTargetAtomicType)
  {
  case TypeConstants::XS_NON_POSITIVE_INTEGER:
  {
    if (lInteger <= xqp_integer::zero())
      return aFactory->createNonPositiveInteger(lInteger);
    break;
  }
  case TypeConstants::XS_NEGATIVE_INTEGER:
  {
    if (lInteger < xqp_integer::zero())
      return aFactory->createNegativeInteger(lInteger);
    break;
  }
  case TypeConstants::XS_LONG:
  {
    xqp_long n;
    if (NumConversions::strToLongLong(lString.getp(), n))
      return aFactory->createLong(n);
    break;
  }
  case TypeConstants::XS_INT:
  {
    xqp_int n;
    if (NumConversions::strToInt(lString.getp(), n))
      return aFactory->createInt(n);
    break;
  }
  case TypeConstants::XS_SHORT:
  {
    xqp_short n;
    if (NumConversions::strToShort(lString.getp(), n))
      return aFactory->createShort(n);
    break;
  }
  case TypeConstants::XS_BYTE:
  {
    xqp_byte n;
    if (NumConversions::strToByte(lString.getp(), n))
      return aFactory->createByte(n);
    break;
  }
  case TypeConstants::XS_NON_NEGATIVE_INTEGER:
  {
    if (lInteger >= xqp_integer::zero())
      return aFactory->createNonNegativeInteger(lInteger);
    break;
  }
  case TypeConstants::XS_UNSIGNED_LONG:
  {
    xqp_ulong n;
    if (NumConversions::strToULongLong(lString.getp(), n))
      return aFactory->createUnsignedLong(n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_INT:
  {
    xqp_uint n;
    if (NumConversions::strToUInt(lString.getp(), n))
      return aFactory->createUnsignedInt(n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_SHORT:
  {
    xqp_ushort n;
    if (NumConversions::strToUShort(lString.getp(), n))
      return aFactory->createUnsignedShort(n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_BYTE:
  {
    xqp_ubyte n;
    if (NumConversions::strToUByte(lString.getp(), n))
      return aFactory->createUnsignedByte(n);
    break;
  }
  case TypeConstants::XS_POSITIVE_INTEGER:
  {
    if (lInteger > xqp_integer::zero())
      return aFactory->createPositiveInteger(lInteger);
    break;
  }
  default:
    assert(false);
  }
  throwError(ZorbaError::FORG0001, aErrorInfo);
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

  throwError(ZorbaError::FORG0001, aErrorInfo); 
  return 0;
}
#endif


/*******************************************************************************

********************************************************************************/
store::Item_t GenericCast::cast(store::Item* aItem, 
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
  if (aTargetType->type_kind() == XQType::USER_DEFINED_KIND)
    return castUserDefinedType(aItem, lErrorInfo);
#endif

  if (!TypeOps::is_atomic(*aTargetType))
    throwError(ZorbaError::XPST0051, lErrorInfo);

  store::Item_t lSourceItem;
  xqtref_t lPrimitiveSourceType;
  if (TypeOps::is_atomic(*lSourceType))
  {
    lPrimitiveSourceType = TypeOps::cast_primitive_type(*lSourceType);
    lSourceItem = aItem;
  } else {
    lPrimitiveSourceType = lTS.STRING_TYPE_ONE;
    lSourceItem = lFactory->createString(aItem->getStringValue());
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
    throwError(ZorbaError::XPST0080, lErrorInfo);

  if ( lPrimitiveSourceAtomicType == TypeConstants::XS_ANY_ATOMIC
    || lPrimitiveTargetAtomicType == TypeConstants::XS_ANY_ATOMIC)
    throwError(ZorbaError::XPST0080, lErrorInfo);

  CastFunc lCastFunc = theCastMatrix[lPrimitiveSourceMapping][lPrimitiveTargetMapping];

  if (lCastFunc == 0)
    throwError(ZorbaError::XPTY0004, lErrorInfo);


  store::Item_t lResult = (*lCastFunc)(lSourceItem, 
                                       lFactory, 
                                       aNCtx,
                                       lErrorInfo);

  if (!TypeOps::is_equal(*aTargetType, *lPrimitiveTargetType))
  {
    DownCastFunc lDownCastFunc = theDownCastMatrix[lPrimitiveTargetMapping];

    if (lDownCastFunc == 0)
      throwError(ZorbaError::XPTY0004, lErrorInfo);

    ATOMICTYPE_T lTargetAtomicType
      = TypeOps::get_atomic_type_code(*aTargetType);
    lResult = (*lDownCastFunc)(&*lResult, 
                               lTS, 
                               lTargetAtomicType, 
                               lFactory,
                               lErrorInfo);
  }

  return lResult;
}


/*******************************************************************************

********************************************************************************/
store::Item_t GenericCast::cast(
    const xqpString& aStr,
    const XQType* aTargetType,
    namespace_context* aNCtx) const
{
  store::Item_t lItem = GENV_ITEMFACTORY->createString(aStr.getStore());
  store::Item_t lResult = cast(lItem, aTargetType, aNCtx);
  return lResult;
}


/*******************************************************************************
  Casts a string to a qname.
  Raises Zorba errors.
  @param isExplicit true when called from the translator
  @param isCast true when this is a cast, false when this is a castable
********************************************************************************/
store::Item_t GenericCast::castToQName (
    xqpStringStore_t qname,
    namespace_context* aNCtx) const
{
  store::Item_t lItem = GENV_ITEMFACTORY->createString(&*qname);
  return cast(lItem, &*GENV_TYPESYSTEM.QNAME_TYPE_ONE, aNCtx);
}

/*
NCName				  ::=    NCNameStartChar NCNameChar* // An XML Name, minus the ":" 
NCNameChar      ::=    NameChar - ':' 
NCNameStartChar ::=    Letter | '_' 
NameChar			  ::=    Letter | Digit | '.' | '-' | '_' | ':' | CombiningChar | Extender 
*/
bool GenericCast::castableToNCName(const xqpStringStore* str) const
{
	uint32_t	cp;

	std::vector<uint32_t> cps = str->getCodepoints();
	std::vector<uint32_t>::size_type	i, cps_size = cps.size();

	if(cps_size == 0)
		return false;

	cp = cps[0];
	//NCNameStartChar  ::=    Letter | '_' 
	if(!isLetter(cp) && (cp != '_'))
		return false;

	for(i=1;i<cps_size;i++)
	{
		cp = cps[i];
		//NCNameChar ::=    NameChar - ':'
		//NameChar	 ::=    Letter | Digit | '.' | '-' | '_' | ':' | CombiningChar | Extender
		if(!isLetter(cp) && !isDigit(cp) &&
			(cp != '.') && (cp != '-') && (cp != '_') &&
			!isCombiningChar(cp) && !isExtender(cp))
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
    if (!(GenericCast::instance()->isLetter(cp)
      || GenericCast::instance()->isDigit(cp)
      || GenericCast::instance()->isExtender(cp)
      || GenericCast::instance()->isCombiningChar(cp)
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
    if (!(GenericCast::instance()->isLetter(cp)
      || cp == '_'
      || cp == ':')) {
      if (i == 0) {
        return false;
      }
      if (!(GenericCast::instance()->isDigit(cp)
        || GenericCast::instance()->isExtender(cp)
        || GenericCast::instance()->isCombiningChar(cp)
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
bool GenericCast::isCastable(store::Item_t aItem, const XQType* aTargetType) const
{
  
  RootTypeManager& lTS = GENV_TYPESYSTEM;

  xqtref_t lSourceType = lTS.create_named_type(
                               aItem->getType(), 
                               TypeConstants::QUANT_ONE);

  TypeConstants::castable_t lIsCastable = TypeOps::castability(*lSourceType, *aTargetType);
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
    try {
      cast(aItem, aTargetType);
      return true;
    } catch (error::ZorbaError& e) {
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
    const xqpString& aStr,
    const XQType* aTargetType) const
{
  store::Item_t lItem = GENV_ITEMFACTORY->createString(aStr.getStore());
  return isCastable(lItem, aTargetType);
}


/*******************************************************************************

********************************************************************************/
store::Item_t GenericCast::promote(
    store::Item_t aItem,
    const XQType* aTargetType) const
{
  xqtref_t lItemType = GENV_TYPESYSTEM.create_value_type(aItem);

  if (TypeOps::is_equal (*aTargetType, *GENV_TYPESYSTEM.NONE_TYPE))
      return NULL;

  if (TypeOps::is_subtype(*lItemType, *aTargetType))
    return aItem;

  store::Item_t lResult = 0;
  if (TypeOps::is_equal(*lItemType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
      && ! TypeOps::is_equal(*TypeOps::prime_type (*aTargetType), *GENV_TYPESYSTEM.QNAME_TYPE_ONE))
    lResult = GenericCast::instance()->cast(aItem, aTargetType);
  else if (TypeOps::is_subtype(*aTargetType, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
    // Numeric Promotion to xs:float
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)) {
      lResult = GenericCast::instance()->cast(aItem, &*GENV_TYPESYSTEM.FLOAT_TYPE_ONE); 
    }
  } else if (TypeOps::is_subtype(*aTargetType, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)) {
    // Numeric Promotion to xs:double
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)
     || TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
      lResult = GenericCast::instance()->cast(aItem, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
    }
  } else if (TypeOps::is_subtype(*aTargetType, *GENV_TYPESYSTEM.STRING_TYPE_ONE)) {
    // URI Promotion
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) {
      lResult = GenericCast::instance()->cast(aItem, &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
  }
  return lResult;
}


/*******************************************************************************

********************************************************************************/

#undef ATOMIC_TYPE


/*
Letter         ::=    BaseChar | Ideographic  
BaseChar       ::=    [#x0041-#x005A] | [#x0061-#x007A] | [#x00C0-#x00D6] | [#x00D8-#x00F6] 
  | [#x00F8-#x00FF] | [#x0100-#x0131] | [#x0134-#x013E] | [#x0141-#x0148] | [#x014A-#x017E] 
  | [#x0180-#x01C3] | [#x01CD-#x01F0] | [#x01F4-#x01F5] | [#x01FA-#x0217] | [#x0250-#x02A8] 
  | [#x02BB-#x02C1] | #x0386 | [#x0388-#x038A] | #x038C | [#x038E-#x03A1] | [#x03A3-#x03CE] 
  | [#x03D0-#x03D6] | #x03DA | #x03DC | #x03DE | #x03E0 | [#x03E2-#x03F3] | [#x0401-#x040C] 
  | [#x040E-#x044F] | [#x0451-#x045C] | [#x045E-#x0481] | [#x0490-#x04C4] | [#x04C7-#x04C8] 
  | [#x04CB-#x04CC] | [#x04D0-#x04EB] | [#x04EE-#x04F5] | [#x04F8-#x04F9] | [#x0531-#x0556] 
  | #x0559 | [#x0561-#x0586] | [#x05D0-#x05EA] | [#x05F0-#x05F2] | [#x0621-#x063A] 
  | [#x0641-#x064A] | [#x0671-#x06B7] | [#x06BA-#x06BE] | [#x06C0-#x06CE] | [#x06D0-#x06D3] 
  | #x06D5 | [#x06E5-#x06E6] | [#x0905-#x0939] | #x093D | [#x0958-#x0961] | [#x0985-#x098C] 
  | [#x098F-#x0990] | [#x0993-#x09A8] | [#x09AA-#x09B0] | #x09B2 | [#x09B6-#x09B9] 
  | [#x09DC-#x09DD] | [#x09DF-#x09E1] | [#x09F0-#x09F1] | [#x0A05-#x0A0A] | [#x0A0F-#x0A10] 
  | [#x0A13-#x0A28] | [#x0A2A-#x0A30] | [#x0A32-#x0A33] | [#x0A35-#x0A36] | [#x0A38-#x0A39] 
  | [#x0A59-#x0A5C] | #x0A5E | [#x0A72-#x0A74] | [#x0A85-#x0A8B] | #x0A8D | [#x0A8F-#x0A91] 
  | [#x0A93-#x0AA8] | [#x0AAA-#x0AB0] | [#x0AB2-#x0AB3] | [#x0AB5-#x0AB9] | #x0ABD | #x0AE0 
  | [#x0B05-#x0B0C] | [#x0B0F-#x0B10] | [#x0B13-#x0B28] | [#x0B2A-#x0B30] | [#x0B32-#x0B33] 
  | [#x0B36-#x0B39] | #x0B3D | [#x0B5C-#x0B5D] | [#x0B5F-#x0B61] | [#x0B85-#x0B8A] 
  | [#x0B8E-#x0B90] | [#x0B92-#x0B95] | [#x0B99-#x0B9A] | #x0B9C | [#x0B9E-#x0B9F] 
  | [#x0BA3-#x0BA4] | [#x0BA8-#x0BAA] | [#x0BAE-#x0BB5] | [#x0BB7-#x0BB9] | [#x0C05-#x0C0C] 
  | [#x0C0E-#x0C10] | [#x0C12-#x0C28] | [#x0C2A-#x0C33] | [#x0C35-#x0C39] | [#x0C60-#x0C61] 
  | [#x0C85-#x0C8C] | [#x0C8E-#x0C90] | [#x0C92-#x0CA8] | [#x0CAA-#x0CB3] | [#x0CB5-#x0CB9] 
  | #x0CDE | [#x0CE0-#x0CE1] | [#x0D05-#x0D0C] | [#x0D0E-#x0D10] | [#x0D12-#x0D28] 
  | [#x0D2A-#x0D39] | [#x0D60-#x0D61] | [#x0E01-#x0E2E] | #x0E30 | [#x0E32-#x0E33] 
  | [#x0E40-#x0E45] | [#x0E81-#x0E82] | #x0E84 | [#x0E87-#x0E88] | #x0E8A | #x0E8D 
  | [#x0E94-#x0E97] | [#x0E99-#x0E9F] | [#x0EA1-#x0EA3] | #x0EA5 | #x0EA7 | [#x0EAA-#x0EAB] 
  | [#x0EAD-#x0EAE] | #x0EB0 | [#x0EB2-#x0EB3] | #x0EBD | [#x0EC0-#x0EC4] | [#x0F40-#x0F47] 
  | [#x0F49-#x0F69] | [#x10A0-#x10C5] | [#x10D0-#x10F6] | #x1100 | [#x1102-#x1103] 
  | [#x1105-#x1107] | #x1109 | [#x110B-#x110C] | [#x110E-#x1112] | #x113C | #x113E | #x1140 
  | #x114C | #x114E | #x1150 | [#x1154-#x1155] | #x1159 | [#x115F-#x1161] | #x1163 | #x1165 
  | #x1167 | #x1169 | [#x116D-#x116E] | [#x1172-#x1173] | #x1175 | #x119E | #x11A8 | #x11AB 
  | [#x11AE-#x11AF] | [#x11B7-#x11B8] | #x11BA | [#x11BC-#x11C2] | #x11EB | #x11F0 | #x11F9 
  | [#x1E00-#x1E9B] | [#x1EA0-#x1EF9] | [#x1F00-#x1F15] | [#x1F18-#x1F1D] | [#x1F20-#x1F45] 
  | [#x1F48-#x1F4D] | [#x1F50-#x1F57] | #x1F59 | #x1F5B | #x1F5D | [#x1F5F-#x1F7D] 
  | [#x1F80-#x1FB4] | [#x1FB6-#x1FBC] | #x1FBE | [#x1FC2-#x1FC4] | [#x1FC6-#x1FCC] 
  | [#x1FD0-#x1FD3] | [#x1FD6-#x1FDB] | [#x1FE0-#x1FEC] | [#x1FF2-#x1FF4] | [#x1FF6-#x1FFC] 
  | #x2126 | [#x212A-#x212B] | #x212E | [#x2180-#x2182] | [#x3041-#x3094] | [#x30A1-#x30FA] 
  | [#x3105-#x312C] | [#xAC00-#xD7A3]  
Ideographic    ::=    [#x4E00-#x9FA5] | #x3007 | [#x3021-#x3029] 
*/
bool GenericCast::isLetter(uint32_t cp) 
{
	return isBaseChar(cp) || isIdeographic(cp);
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::isBaseChar(uint32_t cp) 
{
	unsigned int	i;
	for(i=0;i<sizeof(base_char_range)/sizeof(CodePointRange_t);i++)
	{
    if(cp < base_char_range[i].left)
      return false;
		if(cp <= base_char_range[i].right)
			return true;
	}

	return false;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::isIdeographic(uint32_t cp)
{
	unsigned int	i;
	for(i=0;i<sizeof(ideographic_range)/sizeof(CodePointRange_t);i++)
	{
    if(cp < ideographic_range[i].left)
      return false;
		if(cp <= ideographic_range[i].right)
			return true;
	}

	return false;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::isDigit(uint32_t cp)
{
	unsigned int	i;
	for(i=0;i<sizeof(digit_range)/sizeof(CodePointRange_t);i++)
	{
    if(cp < digit_range[i].left)
      return false;
		if(cp <= digit_range[i].right)
			return true;
	}

	return false;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::isCombiningChar(uint32_t cp)
{
	unsigned int i;
	for(i = 0; i < sizeof(combining_char_range)/sizeof(CodePointRange_t); i++)
	{
    if(cp < combining_char_range[i].left)
      return false;
		if(cp <= combining_char_range[i].right)
			return true;
	}

	return false;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::isExtender(uint32_t cp)
{
	unsigned int	i;
	for(i=0;i<sizeof(extender_range)/sizeof(CodePointRange_t);i++)
	{
    if(cp < extender_range[i].left)
      return false;
		if(cp <= extender_range[i].right)
			return true;
	}

	return false;
}


/* end class GenericCast */
} /* namespace zorba */
