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
#include <cassert>
#include <iostream>
#include <limits>

#include <zorba/zorba.h>

using namespace zorba;

bool
checkType(const Item& aItem, const String& aLocalname)
{
  try {
    return (aItem.getPrefix() == "xs" && 
            aItem.getLocalName() == aLocalname && 
            aItem.getNamespace() == "http://www.w3.org/2001/XMLSchema");
  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return false;
  }
}

#define CHECK_NOT_IMPLEMENTED(object, member) \
  try { \
    object.member;\
    assert(false); \
  } catch (SystemException &e) { \
    assert (e.getErrorCode() == XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE); \
  }



int itemfactory(int argc, char* argv[]) 
{
  Zorba* lZorba = Zorba::getInstance();

  ItemFactory* lFactory = lZorba->getItemFactory();

  Item lItem;
  try {
    /** String */
    lItem = lFactory->createString("abc");
    assert ( checkType(lItem.getType(), "string") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "abc" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, isNaN() );

    lItem.close();
    assert (lItem.isNull());

    /** AnyURI */
    lItem = lFactory->createAnyURI("http://www.flworfound.org/");
    assert ( checkType(lItem.getType(), "anyURI") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "http://www.flworfound.org/");
    assert ( !lItem.getAtomizationValue().isNull() );

    /** QName */
    lItem = lFactory->createQName("http://www.flworfound.org", "flwor", "name");
    assert ( checkType(lItem.getType(), "QName") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "flwor:name" );
    assert ( lItem.getNamespace() == "http://www.flworfound.org" );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createQName("http://www.flworfound.org", "name");
    assert ( checkType(lItem.getType(), "QName") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "name" );
    assert ( lItem.getPrefix().length() == 0 );
    assert ( lItem.getPrefix().empty() );
    assert ( lItem.getNamespace() == "http://www.flworfound.org" );
    assert ( !lItem.getAtomizationValue().isNull() );

    /** NCName */
    lItem = lFactory->createNCName("ncname");
    assert ( checkType(lItem.getType(), "NCName") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "ncname" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED (lItem, getPrefix());
    CHECK_NOT_IMPLEMENTED (lItem, getLocalName());
    CHECK_NOT_IMPLEMENTED (lItem, getNamespace());
    CHECK_NOT_IMPLEMENTED (lItem, getBooleanValue() );

    /** Base64Binary */
    lItem = lFactory->createBase64Binary("", 0);
    assert ( checkType(lItem.getType(), "base64Binary") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "" );
    assert ( lItem.getStringValue().length() == 0 );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createBase64Binary("cmxjZ3R4c3JidnllcmVuZG91aWpsbXV5Z2NhamxpcmJkaWFhbmFob2VsYXVwZmJ1Z2dmanl2eHlzYmhheXFtZXR0anV2dG1q", 96);
    assert ( checkType(lItem.getType(), "base64Binary") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "cmxjZ3R4c3JidnllcmVuZG91aWpsbXV5Z2NhamxpcmJkaWFhbmFob2VsYXVwZmJ1Z2dmanl2eHlzYmhheXFtZXR0anV2dG1q" );
    assert ( lItem.getStringValue().length() == 96 );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED (lItem, getBooleanValue() );

    /** HexBinary */
    lItem = lFactory->createHexBinary("", 0);
    assert ( checkType(lItem.getType(), "hexBinary") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "" );
    assert ( lItem.getStringValue().length() == 0 );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createHexBinary("d433abfb43281793214aac", 22);
    assert ( checkType(lItem.getType(), "hexBinary") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "D433ABFB43281793214AAC" );
    assert ( lItem.getStringValue().length() == 22 );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED (lItem, getBooleanValue() );

    /** Boolean */
    lItem = lFactory->createBoolean(true);
    assert ( checkType(lItem.getType(), "boolean") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "true" );
    assert ( lItem.getEBV().getStringValue() == "true" ); 
    assert ( lItem.getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createBoolean(false);
    assert ( checkType(lItem.getType(), "boolean") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "false" );
    assert ( lItem.getEBV().getStringValue() == "false" ); 
    assert ( !lItem.getAtomizationValue().isNull() );
    assert ( ! lItem.getBooleanValue() );

    /** Decimal */
    lItem = lFactory->createDecimalFromLong(12678967);
    assert ( checkType(lItem.getType(), "decimal") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "12678967" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDecimalFromDouble(12678967.32342);
    assert ( checkType(lItem.getType(), "decimal") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "12678967.32342" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDecimal("NaN");
    assert ( lItem.isNull() );

    /** Integer */
    lItem = lFactory->createInteger(23424223);
    assert ( checkType(lItem.getType(), "integer") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "23424223" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createInteger("NaN");
    assert ( lItem.isNull() );

    /** Int */
    lItem = lFactory->createInt(23424223);
    assert ( checkType(lItem.getType(), "int") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "23424223" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    assert ( !lItem.isNaN() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Short */
    lItem = lFactory->createShort(233);
    assert ( checkType(lItem.getType(), "short") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "233" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );
    
    /** Char */
    lItem = lFactory->createByte('a');
    assert ( checkType(lItem.getType(), "byte") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "97" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Double */
    lItem = lFactory->createDouble(213123);
    assert ( checkType(lItem.getType(), "double") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "213123" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    double x = 0;
    lItem = lFactory->createDouble(static_cast<double>(x)/static_cast<double>(x));
    assert ( checkType(lItem.getType(), "double") );
    assert ( lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble(std::numeric_limits<double>::infinity());
    assert ( checkType(lItem.getType(), "double") );
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("213123");
    assert ( lItem.getStringValue() == "213123" );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("INF");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("-INF");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("-inf");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("inf");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("NAN");
    assert ( !lItem.isPosOrNegInf() );
    assert ( lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("nAn");
    assert ( !lItem.isPosOrNegInf() );
    assert ( lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    /* Float */
    lItem = lFactory->createFloat("23.42");
    assert ( checkType(lItem.getType(), "float") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "23.42" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createFloat("INF");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat("-INF");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat("-inf");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat("inf");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat("NAN");
    assert ( !lItem.isPosOrNegInf() );
    assert ( lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat("nAn");
    assert ( !lItem.isPosOrNegInf() );
    assert ( lItem.isNaN() );
    assert ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat(23.42);
    assert ( checkType(lItem.getType(), "float") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "23.4200000762939" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* NonNegativeInteger */
    lItem = lFactory->createNonNegativeInteger(32423423);
    assert ( checkType(lItem.getType(), "nonNegativeInteger") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "32423423" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* NegativeInteger */
    lItem = lFactory->createNegativeInteger(-32423423);
    assert ( checkType(lItem.getType(), "negativeInteger") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "-32423423" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createNegativeInteger(1);
    assert ( lItem.isNull() );

    /* NonPositiveInteger */
    lItem = lFactory->createNonPositiveInteger(-32423423);
    assert ( checkType(lItem.getType(), "nonPositiveInteger") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "-32423423" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createNonPositiveInteger(1);
    assert ( lItem.isNull() );

    /* PositiveInteger */
    lItem = lFactory->createPositiveInteger(32423423);
    assert ( checkType(lItem.getType(), "positiveInteger") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "32423423" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* Unsigned Byte */
    lItem = lFactory->createUnsignedByte('a');
    assert ( checkType(lItem.getType(), "unsignedByte") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "97" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );


    /* Unsigned Short */
    lItem = lFactory->createUnsignedShort(10);
    assert ( checkType(lItem.getType(), "unsignedShort") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "10" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* Unsigned Long */
    lItem = lFactory->createUnsignedLong(10);
    assert ( checkType(lItem.getType(), "unsignedLong") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "10" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* Unsigned Int */
    lItem = lFactory->createUnsignedInt(10);
    assert ( checkType(lItem.getType(), "unsignedInt") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "10" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Date*/
    lItem = lFactory->createDate("1999-05-31");
    assert ( checkType(lItem.getType(), "date") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "1999-05-31" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createDate(1999,05,31);
    assert ( checkType(lItem.getType(), "date") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "1999-05-31" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** DateTime*/
    lItem = lFactory->createDateTime("1999-05-31T01:02:03.04-01:00");
    assert ( checkType(lItem.getType(), "dateTime") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "1999-05-31T01:02:03.04-01:00" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createDateTime(1999, 05, 31, 01, 02, 3.04, -1);
    assert ( checkType(lItem.getType(), "dateTime") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "1999-05-31T01:02:03.04-01:00" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Time*/
    lItem = lFactory->createTime("08:00:00+09:00");
    assert ( checkType(lItem.getType(), "time") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "08:00:00+09:00" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createTime(8,9,10.123);
    assert ( checkType(lItem.getType(), "time") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "08:09:10.123" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createTime(17,0,0,-6);
    assert ( checkType(lItem.getType(), "time") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "17:00:00-06:00" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** GYearMonth*/
    lItem = lFactory->createGYearMonth("1976-02");
    assert ( checkType(lItem.getType(), "gYearMonth") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "1976-02" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGYearMonth(1976,02);
    assert ( checkType(lItem.getType(), "gYearMonth") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "1976-02" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** GYear*/
    lItem = lFactory->createGYear("1977");
    assert ( checkType(lItem.getType(), "gYear") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "1977" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGYear(1977);
    assert ( checkType(lItem.getType(), "gYear") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "1977" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** GMonth*/
    lItem = lFactory->createGMonth("--12Z");
    assert ( checkType(lItem.getType(), "gMonth") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "--12Z" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGMonth(11);
    assert ( checkType(lItem.getType(), "gMonth") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "--11" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );
    
    /** GMonthDay*/
    lItem = lFactory->createGMonthDay("--12-25-14:00");
    assert ( checkType(lItem.getType(), "gMonthDay") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "--12-25-14:00" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGMonthDay(12, 25);
    assert ( checkType(lItem.getType(), "gMonthDay") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "--12-25" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** GDay*/
    lItem = lFactory->createGDay("---25-14:00");
    assert ( checkType(lItem.getType(), "gDay") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "---25-14:00" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGDay(25);
    assert ( checkType(lItem.getType(), "gDay") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "---25" );
    assert ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return 1;
  }

  return 0;
}
