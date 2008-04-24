/**
 *
 * @copyright
 * ========================================================================
 *  Copyright 2007 FLWOR Foundation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @author David Graf (david.graf@28msec.com)
 * @author Vinayak R. Borkar (vborky@yahoo.com)
 * @file types/casting.cpp
 *
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

namespace zorba
{

#define ATOMIC_TYPE(type) \
  GENV_TYPESYSTEM.create_atomic_type(TypeConstants::XS_##type, TypeConstants::QUANT_ONE)


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


void checkBooleanToNumericCast(
    xqpStringStore_t& lString,
    const xqtref_t& aSourceType,
    const xqtref_t& aTargetType)
{
  if (aSourceType->type_kind() != XQType::ATOMIC_TYPE_KIND || 
      aTargetType->type_kind() != XQType::ATOMIC_TYPE_KIND )
    return;

  switch(TypeOps::get_atomic_type_code(*aSourceType))
  {
  case TypeConstants::XS_BOOLEAN:
  {
    if ( TypeOps::is_subtype(*aTargetType, *ATOMIC_TYPE(DECIMAL)) ||
         TypeOps::is_subtype(*aTargetType, *ATOMIC_TYPE(FLOAT)) || 
         TypeOps::is_subtype(*aTargetType, *ATOMIC_TYPE(DOUBLE)) )
    {
      if (lString->str() == "true")
        lString = new xqpStringStore("1");
      else if (lString->str() != "1")
        lString = new xqpStringStore("0");
    }
    break;
  }
  default:
    break;
  }
}

#define SAME_S_AND_T(type)                                                     \
  inline store::Item_t type##_##type(store::Item* aItem, store::ItemFactory*, namespace_context *nsCtx)  \
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


inline store::Item_t str_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
return aFactory->createUntypedAtomic(aItem->getStringValue());
}

inline store::Item_t str_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_float n;
  if (NumConversions::strToFloat(aItem->getStringValue().getp(), n))
    return aFactory->createFloat(n);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_double n;
  if (NumConversions::strToDouble(aItem->getStringValue().getp(), n))
    return aFactory->createDouble(n);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_decimal n;
  if (NumConversions::strToDecimal(aItem->getStringValue().getp(), n))
    return aFactory->createDecimal(n);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_integer n;
  if (NumConversions::strToInteger(aItem->getStringValue().getp(), n))
    return aFactory->createInteger(n);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_dur(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  Duration_t d_t;
  if (Duration::parse_string(aItem->getStringValue().getp(), d_t))
  {
    xqp_duration d = d_t;
    return aFactory->createDuration(d);
  } else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_yMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  YearMonthDuration_t ymd_t;
  if (YearMonthDuration::parse_string(aItem->getStringValue().getp(), ymd_t))
  {
    xqp_duration d = ymd_t;
    return aFactory->createDuration(d);
  } else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_dTD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  DayTimeDuration_t dtd_t;
  if (DayTimeDuration::parse_string(aItem->getStringValue().getp(), dtd_t))
  {
    xqp_duration d = dtd_t;
    return aFactory->createDuration(d);
  } else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_dT(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_dateTime dt;
  if (0 == DateTime::parseDateTime(aItem->getStringValue().getp(), dt))
    return aFactory->createDateTime(dt);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_tim(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_time t;
  if (0 == DateTime::parseTime(aItem->getStringValue().getp(), t))
    return aFactory->createTime(t);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_dat(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_date d;
  if (0 == DateTime::parseDate(aItem->getStringValue().getp(), d))
    return aFactory->createDate(d);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_gYM(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_gYearMonth ym;
  if (0 == DateTime::parseGYearMonth(aItem->getStringValue().getp(), ym))
    return aFactory->createGYearMonth(ym);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_gYr(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_gYear y;
  if (0 == DateTime::parseGYear(aItem->getStringValue().getp(), y))
    return aFactory->createGYear(y);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_gMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_gMonthDay md;
  if (0 == DateTime::parseGMonthDay(aItem->getStringValue().getp(), md))
    return aFactory->createGMonthDay(md);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_gDay(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_gDay d;
  if (0 == DateTime::parseGDay(aItem->getStringValue().getp(), d))
    return aFactory->createGDay(d);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_gMon(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_gMonth m;
  if (0 == DateTime::parseGMonth(aItem->getStringValue().getp(), m))
    return aFactory->createGMonth(m);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
bool lRetValue = true;
xqpStringStore_t lString = aItem->getStringValue()->trim();

  if (lString->byteEqual("false", 5) || lString->byteEqual("0", 1))
    lRetValue = false;
  else if (!lString->byteEqual("true", 4) && !lString->byteEqual("1", 1))
    ZORBA_ERROR(ZorbaError::FORG0001);

return aFactory->createBoolean(lRetValue);
}

inline store::Item_t str_b64(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_base64Binary n;
  if (xqp_base64Binary::parseString(aItem->getStringValue().getp(), n))
    return aFactory->createBase64Binary(n);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_hxB(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_hexBinary n;
  if (xqp_hexBinary::parseString(aItem->getStringValue().getp(), n))
    return aFactory->createHexBinary(n);
  else
    ZORBA_ERROR(ZorbaError::FORG0001);
}

inline store::Item_t str_aURI(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
// TODO createAnyURI does not always succeed
return aFactory->createAnyURI(aItem->getStringValue());
}

inline store::Item_t str_QN(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqpStringStore *str = aItem->getStringValueP();
  int32_t idx = str->indexOf(":");
  int32_t lidx = str->lastIndexOf(":");
  if (idx != lidx)
    return 0;
  
  if (idx < 0)
    return aFactory->createQName(0,0,str);

  // TODO
  assert(false);
  return 0;
}

inline store::Item_t str_NOT(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createNOTATION(aItem->getStringValue().getp());
}

inline store::Item_t uA_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createString(aItem->getStringValue());  
}

inline store::Item_t uA_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_flt(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_dbl(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_dec(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_int(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_dur(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_dur(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_yMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_yMD(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_dTD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_dTD(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_dT(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_dT(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_tim(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_tim(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_dat(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_dat(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_gYM(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_gYM(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_gYr(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_gYr(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_gMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_gMD(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_gDay(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_gDay(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_gMon(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_gMon(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_bool(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_b64(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_b64(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_hxB(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_hxB(aItem, aFactory, nsCtx);
}

inline store::Item_t uA_aURI(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_aURI(aItem, aFactory, nsCtx);
}

inline store::Item_t flt_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t flt_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t flt_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createDouble(FloatCommons::parseFloat(aItem->getFloatValue()));
}

inline store::Item_t flt_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_decimal n;
  if (xqp_decimal::parseFloat(aItem->getFloatValue(), n))
    return aFactory->createDecimal(n);
  ZORBA_ERROR(ZorbaError::FOCA0002);
}

inline store::Item_t flt_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_integer n;
  if (xqp_integer::parseFloat(aItem->getFloatValue(), n))
    return aFactory->createInteger(n);
  ZORBA_ERROR(ZorbaError::FOCA0002);
}

inline store::Item_t flt_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createBoolean(aItem->getEBV());
}

inline store::Item_t dbl_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t dbl_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t dbl_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createFloat(FloatCommons::parseDouble(aItem->getDoubleValue()));
}

inline store::Item_t dbl_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_decimal n;
  if (xqp_decimal::parseDouble(aItem->getDoubleValue(), n))
    return aFactory->createDecimal(n);
  ZORBA_ERROR(ZorbaError::FOCA0002);
}

inline store::Item_t dbl_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  xqp_integer n;
  if (xqp_integer::parseDouble(aItem->getDoubleValue(), n))
    return aFactory->createInteger(n);
  ZORBA_ERROR(ZorbaError::FOCA0002);
}

inline store::Item_t dbl_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createBoolean(aItem->getEBV());
}

inline store::Item_t dec_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t dec_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t dec_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createFloat(xqp_float::parseDecimal(aItem->getDecimalValue()));
}

inline store::Item_t dec_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createDouble(xqp_double::parseDecimal(aItem->getDecimalValue()));
}

inline store::Item_t dec_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createInteger(xqp_integer::parseDecimal(aItem->getDecimalValue()));
}

inline store::Item_t dec_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createBoolean(aItem->getEBV());
}

inline store::Item_t int_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t int_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t int_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createFloat(xqp_float::parseInteger(aItem->getIntegerValue()));
}

inline store::Item_t int_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createDouble(xqp_double::parseInteger(aItem->getIntegerValue()));
}

inline store::Item_t int_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createDecimal(xqp_decimal::parseInteger(aItem->getIntegerValue()));
}

inline store::Item_t int_bool(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createBoolean(aItem->getEBV());
}

inline store::Item_t dur_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t dur_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t dur_yMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dur_dTD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t yMD_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t yMD_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t yMD_dur(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t yMD_dTD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dTD_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t dTD_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t dTD_dur(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dTD_yMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dT_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t dT_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t dT_tim(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dT_dat(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dT_gYM(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dT_gYr(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dT_gMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dT_gDay(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dT_gMon(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t tim_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t tim_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t dat_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t dat_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t dat_dT(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dat_gYM(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dat_gYr(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dat_gMD(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dat_gDay(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t dat_gMon(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  assert(false);
  return 0;
}

inline store::Item_t gYM_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t gYM_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t gYr_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t gYr_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t gMD_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t gMD_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t gDay_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t gDay_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t gMon_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t gMon_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t bool_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t bool_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t bool_flt(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  if (aItem->getBooleanValue())
    return aFactory->createFloat(xqp_float::parseInt(1));
  else
    return aFactory->createFloat(xqp_float::zero());
}

inline store::Item_t bool_dbl(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  if (aItem->getBooleanValue())
    return aFactory->createDouble(xqp_double::parseInt(1));
  else
    return aFactory->createDouble(xqp_double::zero());
}

inline store::Item_t bool_dec(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  if (aItem->getBooleanValue())
    return aFactory->createDecimal(xqp_decimal::parseInt(1));
  else
    return aFactory->createDecimal(xqp_decimal::zero());
}

inline store::Item_t bool_int(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  if (aItem->getBooleanValue())
    return aFactory->createInteger(xqp_integer::parseInt(1));
  else
    return aFactory->createInteger(xqp_integer::zero());
}

inline store::Item_t b64_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t b64_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t b64_hxB(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createHexBinary(xqp_hexBinary(aItem->getBase64BinaryValue()));
}

inline store::Item_t hxB_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t hxB_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t hxB_b64(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return aFactory->createBase64Binary(xqp_base64Binary(aItem->getHexBinaryValue()));
}

inline store::Item_t aURI_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t aURI_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t QN_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t QN_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
}

inline store::Item_t NOT_uA(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return str_uA(aItem, aFactory, nsCtx);
}

inline store::Item_t NOT_str(store::Item* aItem, store::ItemFactory* aFactory, namespace_context *nsCtx)
{
  return uA_str(aItem, aFactory, nsCtx);
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
                TypeConstants::atomic_type_code_t aTargetAtomicType,
                RootTypeManager& aTS,
                store::ItemFactory* aFactory)
{
  xqpStringStore_t lString = aItem->getStringValue();
  // TODO all
  assert(false);
  switch(aTargetAtomicType)
  {
  case TypeConstants::XS_NORMALIZED_STRING:
    break;
  case TypeConstants::XS_TOKEN:
    break;
  case TypeConstants::XS_LANGUAGE:
    break;
  case TypeConstants::XS_NMTOKEN:
    break;
  case TypeConstants::XS_NAME:
    break;
  case TypeConstants::XS_NCNAME:
    break;
  case TypeConstants::XS_ID:
    break;
  case TypeConstants::XS_IDREF:
    break;
  case TypeConstants::XS_ENTITY:
    break;
  default:
    assert(false);
  }
  return 0;
}

store::Item_t int_down(
                const store::Item* aItem, 
                TypeConstants::atomic_type_code_t aTargetAtomicType,
                RootTypeManager& aTS,
                store::ItemFactory* aFactory)
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
  ZORBA_ERROR(ZorbaError::FORG0001);
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


/*******************************************************************************

********************************************************************************/
#if 1
store::Item_t GenericCast::cast(
    store::Item*    aItem,
    const xqtref_t& aTargetType) const
{
  store::Item_t lResult;
  RootTypeManager& ts = GENV_TYPESYSTEM;

  xqtref_t lItemType = ts.create_named_type(aItem->getType(),
                                            TypeConstants::QUANT_ONE);

  if (TypeOps::is_subtype(*lItemType, *aTargetType)) 
  {
    return aItem;
  }
    
  lResult = stringSimpleCast(aItem, lItemType, aTargetType);
  if ( lResult == 0 ) 
  {
    ZORBA_ERROR_DESC_OSS(ZorbaError::FORG0001, 
                         "Passed item (of type " << TypeOps::toString(*lItemType)
                         << ") is not castable to passed target type (" 
                         << TypeOps::toString (*aTargetType) << ").");
  }

  return lResult;
}

#else

store::Item_t GenericCast::cast(store::Item* aItem, const xqtref_t& aTargetType) const
{
  if (!TypeOps::is_atomic(*aTargetType))
    ZORBA_ERROR(ZorbaError::XPST0051);

  RootTypeManager& lTS = GENV_TYPESYSTEM;
  store::ItemFactory* lFactory = GENV_ITEMFACTORY;

  xqtref_t lSourceType = lTS.create_named_type(
                               aItem->getType(), 
                               TypeConstants::QUANT_ONE);

  xqtref_t lPrimitiveSourceType = TypeOps::cast_primitive_type(*lSourceType);
  TypeConstants::atomic_type_code_t lPrimitiveSourceAtomicType 
    = TypeOps::get_atomic_type_code(*lPrimitiveSourceType);
  int lPrimitiveSourceMapping = theMapping[lPrimitiveSourceAtomicType];

  xqtref_t lPrimitiveTargetType = TypeOps::cast_primitive_type(*aTargetType);
  TypeConstants::atomic_type_code_t lPrimitiveTargetAtomicType
    = TypeOps::get_atomic_type_code(*lPrimitiveTargetType);
  int lPrimitiveTargetMapping = theMapping[lPrimitiveTargetAtomicType];

  if ( lPrimitiveSourceAtomicType == TypeConstants::XS_NOTATION 
    || lPrimitiveTargetAtomicType == TypeConstants::XS_NOTATION)
    ZORBA_ERROR(ZorbaError::XPST0080);

  if ( lPrimitiveSourceAtomicType == TypeConstants::XS_ANY_ATOMIC
    || lPrimitiveTargetAtomicType == TypeConstants::XS_ANY_ATOMIC)
    ZORBA_ERROR(ZorbaError::XPST0080);

  CastFunc lCastFunc = theCastMatrix[lPrimitiveSourceMapping][lPrimitiveTargetMapping];

  if (lCastFunc == 0)
    ZORBA_ERROR(ZorbaError::XPTY0004);

  store::Item_t lResult = (*lCastFunc)(aItem, lFactory, NULL); 

  if (!TypeOps::is_equal(*aTargetType, *lPrimitiveTargetType))
  {
    DownCastFunc lDownCastFunc = theDownCastMatrix[lPrimitiveTargetMapping];

    if (lDownCastFunc == 0)
      ZORBA_ERROR(ZorbaError::XPTY0004);

    TypeConstants::atomic_type_code_t lTargetAtomicType
      = TypeOps::get_atomic_type_code(*aTargetType);
    lResult = (*lDownCastFunc)(&*lResult, lTargetAtomicType, lTS, lFactory);
  }

  return lResult;
}

#endif


/*******************************************************************************

********************************************************************************/
store::Item_t GenericCast::cast(
    const xqpString& aStr,
    const xqtref_t& aTargetType) const
{
  store::Item_t lItem = GENV_ITEMFACTORY->createString(aStr.getStore());
  store::Item_t lResult = cast(lItem, aTargetType);
  return lResult;
}


/*******************************************************************************
  Casts a string to a qname.
  Raises Zorba errors.
  @param isExplicit true when called from the translator
  @param isCast true when this is a cast, false when this is a castable
  TODO: return 0 instead of throwing an error code, let the caller decide on the error
********************************************************************************/
store::Item_t GenericCast::castToQName (
    xqpStringStore_t qname,
    bool isCast,
    bool isExplicit,
    namespace_context* aNCtx) const
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;

  ZorbaError::ErrorCode code = (isExplicit ?
                                (isCast ? ZorbaError::FONS0004 : ZorbaError::XPST0003) :
                                ZorbaError::XQDY0074);

  xqpString lNamespace, lPrefix, lLocal;

  // whitespace normalization for target type (xs:QName)
  if (isExplicit && isCast)
    qname = qname->trim ();

  int32_t lIndex = qname->indexOf(":");
  if (lIndex < 0) {
    if (castableToNCName(qname)) {
      aNCtx->findBinding ("", lNamespace);
      lLocal = &*qname;
    }
    else ZORBA_ERROR(code);
  } else if (lIndex == 0) {
    ZORBA_ERROR (code);
  } else {
    lPrefix = qname->str().substr(0, lIndex);
    lLocal = qname->str().substr(lIndex + 1);

    if (!castableToNCName(lPrefix.getStore()) ||
        !castableToNCName(lLocal.getStore()))
      ZORBA_ERROR(code);
    
    // namespace resolution
    // raise XPST0081 (isCast false) or FONS0004 (isCast true) if namespace unknown
    assert (aNCtx != 0);
    if (! aNCtx->findBinding(lPrefix, lNamespace))
      ZORBA_ERROR (isCast ? ZorbaError::FONS0004 : ZorbaError::XPST0081);
  }

  return factory->createQName(lNamespace.getStore(),
                              lPrefix.getStore(),
                              lLocal.getStore());
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


/*******************************************************************************

********************************************************************************/
bool GenericCast::isCastable(
    store::Item_t aItem,
    const xqtref_t& aTargetType) const
{
  store::Item_t lItem;
  RootTypeManager& ts = GENV_TYPESYSTEM;

  xqtref_t lItemType = ts.create_named_type(aItem->getType(), TypeConstants::QUANT_ONE);

  if (TypeOps::is_subtype(*lItemType, *aTargetType))
  {
    // Item is castable if target type is a supertype
    return true;  
  }

  if (TypeOps::castability(*lItemType, *aTargetType) == TypeConstants::NOT_CASTABLE) {
    return false;
  }
  
  // Most simple implementation: Check if string cast works
  try {
    lItem = stringSimpleCast(aItem, lItemType, aTargetType);
  } catch (error::ZorbaError) {
    return false;
  }

  return lItem != 0;
}


/*******************************************************************************

********************************************************************************/
bool GenericCast::isCastable(
    const xqpString& aStr,
    const xqtref_t& aTargetType) const
{
  store::Item_t lItem = GENV_ITEMFACTORY->createString(aStr.getStore());
  return isCastable(lItem, aTargetType);
}


/*******************************************************************************

********************************************************************************/
store::Item_t GenericCast::promote(
    store::Item_t aItem,
    const xqtref_t& aTargetType) const
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
      lResult = GenericCast::instance()->cast(aItem, GENV_TYPESYSTEM.FLOAT_TYPE_ONE); 
    }
  } else if (TypeOps::is_subtype(*aTargetType, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)) {
    // Numeric Promotion to xs:double
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)
     || TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
      lResult = GenericCast::instance()->cast(aItem, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
    }
  } else if (TypeOps::is_subtype(*aTargetType, *GENV_TYPESYSTEM.STRING_TYPE_ONE)) {
    // URI Promotion
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) {
      lResult = GenericCast::instance()->cast(aItem, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
  }
  return lResult;
}


/*******************************************************************************

********************************************************************************/
store::Item_t GenericCast::stringSimpleCast(
    const store::Item* aSourceItem,
    const xqtref_t&    aSourceType,
    const xqtref_t&    aTargetType) const
{
    switch (aTargetType->type_kind())
    {
    case XQType::ATOMIC_TYPE_KIND:
    case XQType::ANY_SIMPLE_TYPE_KIND:
    case XQType::ANY_TYPE_KIND:
    case XQType::EMPTY_KIND:
    case XQType::NODE_TYPE_KIND:
    case XQType::ITEM_KIND:
    case XQType::NONE_KIND:
        return stringSimpleCastBuiltIn(aSourceItem, aSourceType, aTargetType);

    case XQType::USER_DEFINED_KIND:
        // TODO parsing of user defined types    
        if (aSourceType->type_kind() == XQType::ATOMIC_TYPE_KIND && 
            TypeOps::get_atomic_type_code(*aSourceType) == TypeConstants::XS_STRING &&
            aTargetType->type_kind() == XQType::USER_DEFINED_KIND )
        {
            //    store::Item_t result;
            //    if ( delegatingTypeManager->getSchema()->parseUserAtomicTypes(textValue, aSourceType, aTargetType, result) )
            //    {
            //        return result;
            //    }
        }
        return 0;
    default:
        ZORBA_ASSERT(false);
    }
    return 0;
}

store::Item_t GenericCast::stringSimpleCastBuiltIn(
    const store::Item* aSourceItem,
    const xqtref_t&    aSourceType, 
    const xqtref_t& aTargetType) const
{
  if (aSourceType->type_kind() == XQType::ATOMIC_TYPE_KIND && 
      aTargetType->type_kind() == XQType::ATOMIC_TYPE_KIND &&
      TypeOps::castability(*aSourceType, *aTargetType) == TypeConstants::NOT_CASTABLE )
  {
    // http://www.w3.org/TR/xpath-functions/#casting
    ZORBA_ERROR_DESC_OSS(ZorbaError::XPTY0004,
                         "Passed item (of type " << TypeOps::toString(*aSourceType) 
                         << ") is not castable to passed target type ("  
                         << TypeOps::toString (*aTargetType) << ").");
    return 0;
  }

  RootTypeManager& ts = GENV_TYPESYSTEM;
  store::ItemFactory* factory = GENV_ITEMFACTORY;

  xqpStringStore_t lString = aSourceItem->getStringValue();

  switch(TypeOps::get_atomic_type_code(*aTargetType))
  {
  case TypeConstants::XS_ANY_ATOMIC:
  case TypeConstants::XS_STRING:
  case TypeConstants::XS_NORMALIZED_STRING:
  case TypeConstants::XS_UNTYPED_ATOMIC:
    break;
  default:
    lString = lString->trim(" \n\r\t",4);
    break;
  }
  
  // check if boolean "true/false" to numeric types is required
  checkBooleanToNumericCast(lString, aSourceType, aTargetType);

  switch(TypeOps::get_atomic_type_code(*aTargetType))
  {
  case TypeConstants::XS_ANY_ATOMIC:
    return factory->createUntypedAtomic(lString);

  case TypeConstants::XS_STRING:
    return factory->createString(lString);

  case TypeConstants::XS_NORMALIZED_STRING:
    return factory->createNormalizedString(lString.getp());

  case TypeConstants::XS_TOKEN:
    return factory->createToken(lString.getp());

  case TypeConstants::XS_LANGUAGE:
    return factory->createLanguage(lString.getp());

  case TypeConstants::XS_NMTOKEN:
    return factory->createNMTOKEN(lString.getp());

  case TypeConstants::XS_NAME:
    return factory->createName(lString.getp());

  case TypeConstants::XS_ID:
    return factory->createID(lString.getp());

  case TypeConstants::XS_IDREF:
    return factory->createIDREF(lString.getp());

  case TypeConstants::XS_ENTITY:
    return factory->createENTITY(lString.getp());

  case TypeConstants::XS_UNTYPED_ATOMIC:
    return factory->createUntypedAtomic(lString);

  case TypeConstants::XS_DATETIME:
  {
    xqp_dateTime dt;
    if (0 == DateTime::parseDateTime(lString.getp(), dt))
      return factory->createDateTime(dt);
    break;
  }
  case TypeConstants::XS_DATE:
  {
    xqp_date d;
    if (0 == DateTime::parseDate(lString.getp(), d))
      return factory->createDate(d);
    break;
  }
  case TypeConstants::XS_TIME:
  {
    xqp_time t;
    if (0 == DateTime::parseTime(lString.getp(), t))
      return factory->createTime(t);
    break;
  }
  case TypeConstants::XS_DURATION:
  {
    Duration_t d_t;
    if (Duration::parse_string(lString.getp(), d_t))
    {
      xqp_duration d = d_t;
      return factory->createDuration(d);
    }
    break;
  }
  case TypeConstants::XS_DT_DURATION:
  {
    DayTimeDuration_t dtd_t;
    if (DayTimeDuration::parse_string(lString.getp(), dtd_t))
    {
      xqp_duration d = dtd_t;
      return factory->createDuration(d);
    }
    break;
  }
  case TypeConstants::XS_YM_DURATION:
  {
    YearMonthDuration_t ymd_t;
    if (YearMonthDuration::parse_string(lString.getp(), ymd_t))
    {
      xqp_duration d = ymd_t;
      return factory->createDuration(d);
    }
    break;
  }
  case TypeConstants::XS_GYEAR_MONTH:
  {
    xqp_gYearMonth ym;
    if (0 == DateTime::parseGYearMonth(lString.getp(), ym))
      return factory->createGYearMonth(ym);
    break;
  }
  case TypeConstants::XS_GYEAR:
  {
    xqp_gYear y;
    if (0 == DateTime::parseGYear(lString.getp(), y))
      return factory->createGYear(y);
    break;
  }
  case TypeConstants::XS_GMONTH_DAY:
  {
    xqp_gMonthDay md;
    if (0 == DateTime::parseGMonthDay(lString.getp(), md))
      return factory->createGMonthDay(md);
    break;
  }
  case TypeConstants::XS_GDAY:
  {
    xqp_gDay d;
    if (0 == DateTime::parseGDay(lString.getp(), d))
      return factory->createGDay(d);
    break;
  }
  case TypeConstants::XS_GMONTH:
  {
    xqp_gMonth m;
    if (0 == DateTime::parseGMonth(lString.getp(), m))
      return factory->createGMonth(m);
    break;
  }
  case TypeConstants::XS_FLOAT:
  {
    xqp_float n;
    if (NumConversions::strToFloat(lString.getp(), n))
      return factory->createFloat(n);
    break;
  }
  case TypeConstants::XS_DOUBLE:
  {
    xqp_double n;
    if (NumConversions::strToDouble(lString.getp(), n))
      return factory->createDouble(n);
    break;
  }
  case TypeConstants::XS_DECIMAL:
  {
    xqp_decimal n;
    if (NumConversions::strToDecimal(lString.getp(), n))
      return factory->createDecimal(n);
    break;
  }
  case TypeConstants::XS_INTEGER:
  {
    xqp_integer n;
    if (NumConversions::strToInteger(lString.getp(), n))
      return factory->createInteger(n);
    break;
  }
  case TypeConstants::XS_NON_POSITIVE_INTEGER:
  {
    xqp_integer n;
    if (NumConversions::strToInteger(lString.getp(), n))
      return factory->createNonPositiveInteger(n);
    break;
  }
  case TypeConstants::XS_NEGATIVE_INTEGER:
  {
    xqp_integer n;
    if (NumConversions::strToInteger(lString.getp(), n) && n < xqp_integer::parseInt(0))
      return factory->createNegativeInteger(n);
    break;
  }
  case TypeConstants::XS_LONG:
  {
    xqp_long n;
    if (NumConversions::strToLongLong(lString.getp(), n))
      return factory->createLong(n);
    break;
  }
  case TypeConstants::XS_INT:
  {
    xqp_int n;
    if (NumConversions::strToInt(lString.getp(), n))
      return factory->createInt(n);
    break;
  }
  case TypeConstants::XS_SHORT:
  {
    xqp_short n;
    if (NumConversions::strToShort(lString.getp(), n))
      return factory->createShort(n);
    break;
  }
  case TypeConstants::XS_BYTE:
  {
    xqp_byte n;
    if (NumConversions::strToByte(lString.getp(), n))
      return factory->createByte(n);
    break;
  }
  case TypeConstants::XS_NON_NEGATIVE_INTEGER:
  {
    xqp_uinteger n;
    if (NumConversions::strToUInteger(lString.getp(), n))
      return factory->createNonNegativeInteger(n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_LONG:
  {
    xqp_ulong n;
    if (NumConversions::strToULongLong(lString.getp(), n))
      return factory->createUnsignedLong(n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_INT:
  {
    xqp_uint n;
    if (NumConversions::strToUInt(lString.getp(), n))
      return factory->createUnsignedInt(n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_SHORT:
  {
    xqp_ushort n;
    if (NumConversions::strToUShort(lString.getp(), n))
      return factory->createUnsignedShort(n);
    break;
  }
  case TypeConstants::XS_UNSIGNED_BYTE:
  {
    xqp_ubyte n;
    if (NumConversions::strToUByte(lString.getp(), n))
      return factory->createUnsignedByte(n);
    break;
  }
  case TypeConstants::XS_POSITIVE_INTEGER:
  {
    xqp_integer n;
    if (NumConversions::strToInteger(lString.getp(), n) && n > xqp_integer::parseInt(0))
      return factory->createPositiveInteger(n);
    break;
  }
  case TypeConstants::XS_BOOLEAN:
  {
    return castToBoolean(aSourceItem, aSourceType);
  }
  case TypeConstants::XS_BASE64BINARY:
  {
    if (TypeOps::is_subtype(*aSourceType, *ATOMIC_TYPE(HEXBINARY)))
      return factory->createBase64Binary(xqp_base64Binary(aSourceItem->getHexBinaryValue()));
    else {
      xqp_base64Binary n;
      // This is a hack, but will be removed anyway
      if (xqp_base64Binary::parseString(xqpString(&*lString),n))
        return factory->createBase64Binary(n);
    }
    break;
  }
  case TypeConstants::XS_HEXBINARY:
  {
    if (TypeOps::is_subtype(*aSourceType, *ATOMIC_TYPE(BASE64BINARY)))
      return factory->createHexBinary(xqp_hexBinary(aSourceItem->getBase64BinaryValue()));
    else {
      xqp_hexBinary n;
      // This is a hack, but will be removed anyway
      if (xqp_hexBinary::parseString(xqpString(&*lString), n))
        return factory->createHexBinary(n);
    }
    break;
  }
  case TypeConstants::XS_ANY_URI:
    return factory->createAnyURI(lString);
    
  case TypeConstants::XS_NCNAME:
  {
    if (!TypeOps::is_subtype(*aSourceType, *ts.STRING_TYPE_ONE) &&
        !TypeOps::is_subtype(*aSourceType, *ts.UNTYPED_ATOMIC_TYPE_ONE))
    {
      ZORBA_ERROR_DESC( ZorbaError::XPTY0004, "Cannot cast " + lString ->str()
                  + " to an NCName because its type is " + aSourceType->toString());
    }

    if (castableToNCName(lString))
    {
      return factory->createNCName(lString);
    }
    else
    {
      ZORBA_ERROR_PARAM_OSS( ZorbaError::XQDY0041, "Cannot cast " << lString << " to an NCName", ""); 
    }
    break;
  }
  case TypeConstants::XS_QNAME:
  {
    if (! TypeOps::is_subtype(*aSourceType, *ts.QNAME_TYPE_ONE)
        && ! TypeOps::is_subtype (*aSourceType, *ts.STRING_TYPE_ONE)
        && ! TypeOps::is_subtype (*aSourceType, *ts.UNTYPED_ATOMIC_TYPE_ONE))
      return NULL;
    // Explicit XQuery casts and castable expressions are translated
    // into treat and instance of expressions (or resolved in-place
    // in the case of string literals), so they never arrive here.
    return castToQName (lString, true, false);
  }

  case TypeConstants::XS_NOTATION:
    return factory->createNOTATION(lString.getp());
  
  default:
    return 0;
  }
  return 0;
}

store::Item_t GenericCast::castToBoolean(
    const store::Item* aSourceItem,
    const xqtref_t& aSourceType) const
{
  bool lRetValue = true;

#ifndef NDEBUG
  if (TypeOps::is_equal(*aSourceType, *ATOMIC_TYPE(BOOLEAN)))
  {
    assert(false); // is already handled by Generic::cast
  }
  else
#endif
  if (TypeOps::is_subtype(*aSourceType, *ATOMIC_TYPE(FLOAT)))
  {
    return aSourceItem->getEBV();
    //store::Item_t lFloatItem = GENV_ITEMFACTORY->createFloat(0);
    //if (lFloatItem->equals(aSourceItem))
    //  lRetValue = false;
    // TODO check NaN
    
  }
  else if (TypeOps::is_subtype(*aSourceType, *ATOMIC_TYPE(DOUBLE)))
  {
    return aSourceItem->getEBV();
    //store::Item_t lDoubleItem = GENV_ITEMFACTORY->createDouble(0);
    //if (lDoubleItem->equals(aSourceItem))
    //  lRetValue = false;
    
    // TODO check NaN
  }
  else if (TypeOps::is_subtype(*aSourceType, *ATOMIC_TYPE(DECIMAL)))
  {
    return aSourceItem->getEBV();
    //store::Item_t lDecimalItem = GENV_ITEMFACTORY->createDecimal(0);
    //if (lDecimalItem->equals(aSourceItem))
    //  lRetValue = false;
    
    // TODO check NaN
    
  }
  else if (TypeOps::is_subtype(*aSourceType, *ATOMIC_TYPE(INTEGER)))
  {
    return aSourceItem->getEBV();
    //store::Item_t lIntegerItem = GENV_ITEMFACTORY->createInteger(0);
    //if (lIntegerItem->equals(aSourceItem))
    //  lRetValue = false;

    // TODO check NAN
  }
  else if (TypeOps::is_equal(*aSourceType, *ATOMIC_TYPE(STRING))
           || TypeOps::is_equal(*aSourceType, *ATOMIC_TYPE(UNTYPED_ATOMIC)))
  {
    xqpStringStore_t lString = aSourceItem->getStringValue()->trim();

    if (lString->byteEqual("false", 5) || lString->byteEqual("0", 1))
      lRetValue = false;
    else if (!lString->byteEqual("true", 4) && !lString->byteEqual("1", 1))
    {
      ZORBA_ERROR_DESC( ZorbaError::FORG0001,  "String cannot be cast to boolean");
    }
    
  }

  return GENV_ITEMFACTORY->createBoolean(lRetValue);
}
#undef ATOMIC_TYPE


/*
Letter    ::=    BaseChar | Ideographic  
BaseChar    ::=    [#x0041-#x005A] | [#x0061-#x007A] | [#x00C0-#x00D6] | [#x00D8-#x00F6] | [#x00F8-#x00FF] | [#x0100-#x0131] | [#x0134-#x013E] | [#x0141-#x0148] | [#x014A-#x017E] | [#x0180-#x01C3] | [#x01CD-#x01F0] | [#x01F4-#x01F5] | [#x01FA-#x0217] | [#x0250-#x02A8] | [#x02BB-#x02C1] | #x0386 | [#x0388-#x038A] | #x038C | [#x038E-#x03A1] | [#x03A3-#x03CE] | [#x03D0-#x03D6] | #x03DA | #x03DC | #x03DE | #x03E0 | [#x03E2-#x03F3] | [#x0401-#x040C] | [#x040E-#x044F] | [#x0451-#x045C] | [#x045E-#x0481] | [#x0490-#x04C4] | [#x04C7-#x04C8] | [#x04CB-#x04CC] | [#x04D0-#x04EB] | [#x04EE-#x04F5] | [#x04F8-#x04F9] | [#x0531-#x0556] | #x0559 | [#x0561-#x0586] | [#x05D0-#x05EA] | [#x05F0-#x05F2] | [#x0621-#x063A] | [#x0641-#x064A] | [#x0671-#x06B7] | [#x06BA-#x06BE] | [#x06C0-#x06CE] | [#x06D0-#x06D3] | #x06D5 | [#x06E5-#x06E6] | [#x0905-#x0939] | #x093D | [#x0958-#x0961] | [#x0985-#x098C] | [#x098F-#x0990] | [#x0993-#x09A8] | [#x09AA-#x09B0] | #x09B2 | [#x09B6-#x09B9] | [#x09DC-#x09DD] | [#x09DF-#x09E1] | [#x09F0-#x09F1] | [#x0A05-#x0A0A] | [#x0A0F-#x0A10] | [#x0A13-#x0A28] | [#x0A2A-#x0A30] | [#x0A32-#x0A33] | [#x0A35-#x0A36] | [#x0A38-#x0A39] | [#x0A59-#x0A5C] | #x0A5E | [#x0A72-#x0A74] | [#x0A85-#x0A8B] | #x0A8D | [#x0A8F-#x0A91] | [#x0A93-#x0AA8] | [#x0AAA-#x0AB0] | [#x0AB2-#x0AB3] | [#x0AB5-#x0AB9] | #x0ABD | #x0AE0 | [#x0B05-#x0B0C] | [#x0B0F-#x0B10] | [#x0B13-#x0B28] | [#x0B2A-#x0B30] | [#x0B32-#x0B33] | [#x0B36-#x0B39] | #x0B3D | [#x0B5C-#x0B5D] | [#x0B5F-#x0B61] | [#x0B85-#x0B8A] | [#x0B8E-#x0B90] | [#x0B92-#x0B95] | [#x0B99-#x0B9A] | #x0B9C | [#x0B9E-#x0B9F] | [#x0BA3-#x0BA4] | [#x0BA8-#x0BAA] | [#x0BAE-#x0BB5] | [#x0BB7-#x0BB9] | [#x0C05-#x0C0C] | [#x0C0E-#x0C10] | [#x0C12-#x0C28] | [#x0C2A-#x0C33] | [#x0C35-#x0C39] | [#x0C60-#x0C61] | [#x0C85-#x0C8C] | [#x0C8E-#x0C90] | [#x0C92-#x0CA8] | [#x0CAA-#x0CB3] | [#x0CB5-#x0CB9] | #x0CDE | [#x0CE0-#x0CE1] | [#x0D05-#x0D0C] | [#x0D0E-#x0D10] | [#x0D12-#x0D28] | [#x0D2A-#x0D39] | [#x0D60-#x0D61] | [#x0E01-#x0E2E] | #x0E30 | [#x0E32-#x0E33] | [#x0E40-#x0E45] | [#x0E81-#x0E82] | #x0E84 | [#x0E87-#x0E88] | #x0E8A | #x0E8D | [#x0E94-#x0E97] | [#x0E99-#x0E9F] | [#x0EA1-#x0EA3] | #x0EA5 | #x0EA7 | [#x0EAA-#x0EAB] | [#x0EAD-#x0EAE] | #x0EB0 | [#x0EB2-#x0EB3] | #x0EBD | [#x0EC0-#x0EC4] | [#x0F40-#x0F47] | [#x0F49-#x0F69] | [#x10A0-#x10C5] | [#x10D0-#x10F6] | #x1100 | [#x1102-#x1103] | [#x1105-#x1107] | #x1109 | [#x110B-#x110C] | [#x110E-#x1112] | #x113C | #x113E | #x1140 | #x114C | #x114E | #x1150 | [#x1154-#x1155] | #x1159 | [#x115F-#x1161] | #x1163 | #x1165 | #x1167 | #x1169 | [#x116D-#x116E] | [#x1172-#x1173] | #x1175 | #x119E | #x11A8 | #x11AB | [#x11AE-#x11AF] | [#x11B7-#x11B8] | #x11BA | [#x11BC-#x11C2] | #x11EB | #x11F0 | #x11F9 | [#x1E00-#x1E9B] | [#x1EA0-#x1EF9] | [#x1F00-#x1F15] | [#x1F18-#x1F1D] | [#x1F20-#x1F45] | [#x1F48-#x1F4D] | [#x1F50-#x1F57] | #x1F59 | #x1F5B | #x1F5D | [#x1F5F-#x1F7D] | [#x1F80-#x1FB4] | [#x1FB6-#x1FBC] | #x1FBE | [#x1FC2-#x1FC4] | [#x1FC6-#x1FCC] | [#x1FD0-#x1FD3] | [#x1FD6-#x1FDB] | [#x1FE0-#x1FEC] | [#x1FF2-#x1FF4] | [#x1FF6-#x1FFC] | #x2126 | [#x212A-#x212B] | #x212E | [#x2180-#x2182] | [#x3041-#x3094] | [#x30A1-#x30FA] | [#x3105-#x312C] | [#xAC00-#xD7A3]  
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
