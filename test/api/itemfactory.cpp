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
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/iterator.h>
#include <zorba/diagnostic_list.h>
#pragma warning (disable: 4723)

using namespace zorba;

#define UNIT_ASSERT(x) \
  do { \
    if (! (x)) { \
      std::cerr << "assertion in file " __FILE__ << " in line " << __LINE__ << " failed" << std::endl; \
      exit(1); \
    } \
  } while (0)

    

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
    UNIT_ASSERT(false); \
  } catch (ZorbaException &e) { \
    UNIT_ASSERT (e.diagnostic() == zerr::ZSTR0040_TYPE_ERROR); \
  }


void
testMultipleFactoryInitilizations()
{
  Zorba* zorba = NULL;
  void* store = NULL;

  store = zorba::StoreManager::getStore();
  zorba = Zorba::getInstance(store);

  ItemFactory* factory = zorba->getItemFactory();
  factory->createString( "" );

  zorba->shutdown();
  zorba::StoreManager::shutdownStore(store);

  store = zorba::StoreManager::getStore();
  zorba = Zorba::getInstance(store);

  factory = zorba->getItemFactory();
  factory->createString( "" ); // <-- zorba crashes here

  zorba->shutdown();
  zorba::StoreManager::shutdownStore(store);
}

int
itemfactory(int argc, char* argv[]) 
{
  try 
  {
    testMultipleFactoryInitilizations();
  }
  catch (ZorbaException &e) 
  {
    std::cerr << e << std::endl;
    return 1;
  }

  Zorba* lZorba = Zorba::getInstance(zorba::StoreManager::getStore());

  ItemFactory* lFactory = lZorba->getItemFactory();

  Item lItem;

  try {
    /** String */
    lItem = lFactory->createString("abc");
    UNIT_ASSERT ( checkType(lItem.getType(), "string") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "abc" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem.close();
    UNIT_ASSERT (lItem.isNull());

    /** AnyURI */
    lItem = lFactory->createAnyURI("http://www.flworfound.org/");
    UNIT_ASSERT ( checkType(lItem.getType(), "anyURI") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "http://www.flworfound.org/");
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    /** QName */
    lItem = lFactory->createQName("http://www.flworfound.org", "flwor", "name");
    UNIT_ASSERT ( checkType(lItem.getType(), "QName") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "flwor:name" );
    UNIT_ASSERT ( lItem.getNamespace() == "http://www.flworfound.org" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createQName("http://www.flworfound.org", "name");
    UNIT_ASSERT ( checkType(lItem.getType(), "QName") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "name" );
    UNIT_ASSERT ( lItem.getPrefix().length() == 0 );
    UNIT_ASSERT ( lItem.getPrefix().empty() );
    UNIT_ASSERT ( lItem.getNamespace() == "http://www.flworfound.org" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    // test generating a qname from the clark notation {ns}localname
    lItem = lFactory->createQName("{http://www.flworfound.org}name");
    UNIT_ASSERT ( checkType(lItem.getType(), "QName") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "name" );
    UNIT_ASSERT ( lItem.getPrefix().length() == 0 );
    UNIT_ASSERT ( lItem.getPrefix().empty() );
    UNIT_ASSERT ( lItem.getNamespace() == "http://www.flworfound.org" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    /** NCName */
    lItem = lFactory->createNCName("ncname");
    UNIT_ASSERT ( checkType(lItem.getType(), "NCName") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "ncname" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
  try {
    lItem.getPrefix();
    UNIT_ASSERT(false);
  } catch (ZorbaException &e) {
    UNIT_ASSERT (e.diagnostic() == zerr::ZSTR0040_TYPE_ERROR);
  }
//    CHECK_NOT_IMPLEMENTED (lItem, getPrefix());
    CHECK_NOT_IMPLEMENTED (lItem, getLocalName());
    CHECK_NOT_IMPLEMENTED (lItem, getNamespace());
    CHECK_NOT_IMPLEMENTED (lItem, getBooleanValue() );

    /** Base64Binary */
    lItem = lFactory->createBase64Binary("", 0, false);
    UNIT_ASSERT ( checkType(lItem.getType(), "base64Binary") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "" );
    UNIT_ASSERT ( lItem.getStringValue().length() == 0 );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createBase64Binary("cmxjZ3R4c3JidnllcmVuZG91aWpsbXV5Z2NhamxpcmJkaWFhbmFob2VsYXVwZmJ1Z2dmanl2eHlzYmhheXFtZXR0anV2dG1q", 96, true);
    UNIT_ASSERT ( checkType(lItem.getType(), "base64Binary") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "cmxjZ3R4c3JidnllcmVuZG91aWpsbXV5Z2NhamxpcmJkaWFhbmFob2VsYXVwZmJ1Z2dmanl2eHlzYmhheXFtZXR0anV2dG1q" );
    UNIT_ASSERT ( lItem.getStringValue().length() == 96 );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED (lItem, getBooleanValue() );

    /** HexBinary */
    lItem = lFactory->createHexBinary("", 0);
    UNIT_ASSERT ( checkType(lItem.getType(), "hexBinary") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "" );
    UNIT_ASSERT ( lItem.getStringValue().length() == 0 );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createHexBinary("d433abfb43281793214aac", 22);
    UNIT_ASSERT ( checkType(lItem.getType(), "hexBinary") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "D433ABFB43281793214AAC" );
    UNIT_ASSERT ( lItem.getStringValue().length() == 22 );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED (lItem, getBooleanValue() );

    /** Boolean */
    lItem = lFactory->createBoolean(true);
    UNIT_ASSERT ( checkType(lItem.getType(), "boolean") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "true" );
    UNIT_ASSERT ( lItem.getEBV().getStringValue() == "true" ); 
    UNIT_ASSERT ( lItem.getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createBoolean(false);
    UNIT_ASSERT ( checkType(lItem.getType(), "boolean") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "false" );
    UNIT_ASSERT ( lItem.getEBV().getStringValue() == "false" ); 
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    UNIT_ASSERT ( ! lItem.getBooleanValue() );

    /** Decimal */
    lItem = lFactory->createDecimalFromLong(12678967);
    UNIT_ASSERT ( checkType(lItem.getType(), "decimal") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "12678967" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDecimalFromDouble(12678967.32342);
    UNIT_ASSERT ( checkType(lItem.getType(), "decimal") );
    UNIT_ASSERT ( lItem.isAtomic() );
    // double to decimal cast implies a rounding error => prefix check only
    UNIT_ASSERT ( strncmp(lItem.getStringValue().c_str(), "12678967.32342", 14) );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDecimal("NaN");
    UNIT_ASSERT ( lItem.isNull() );

    /** Integer */
    lItem = lFactory->createInteger(23424223);
    UNIT_ASSERT ( checkType(lItem.getType(), "integer") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "23424223" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createInteger("NaN");
    UNIT_ASSERT ( lItem.isNull() );

    /** Int */
    lItem = lFactory->createInt(23424223);
    UNIT_ASSERT ( checkType(lItem.getType(), "int") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "23424223" );
	UNIT_ASSERT ( lItem.getIntValue() == 23424223 );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    UNIT_ASSERT ( !lItem.isNaN() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Short */
    lItem = lFactory->createShort(233);
    UNIT_ASSERT ( checkType(lItem.getType(), "short") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "233" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );
    
    /** Char */
    lItem = lFactory->createByte('a');
    UNIT_ASSERT ( checkType(lItem.getType(), "byte") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "97" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Double */
    lItem = lFactory->createDouble(213123);
    UNIT_ASSERT ( checkType(lItem.getType(), "double") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "213123" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    double x = 0;
    lItem = lFactory->createDouble(static_cast<double>(x)/static_cast<double>(x));
    UNIT_ASSERT ( checkType(lItem.getType(), "double") );
    UNIT_ASSERT ( lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble(std::numeric_limits<double>::infinity());
    UNIT_ASSERT ( checkType(lItem.getType(), "double") );
    UNIT_ASSERT ( lItem.isPosOrNegInf() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("213123");
    UNIT_ASSERT ( lItem.getStringValue() == "213123" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("INF");
    UNIT_ASSERT ( lItem.isPosOrNegInf() );
    UNIT_ASSERT ( !lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("-INF");
    UNIT_ASSERT ( lItem.isPosOrNegInf() );
    UNIT_ASSERT ( !lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createDouble("NaN");
    UNIT_ASSERT ( !lItem.isPosOrNegInf() );
    UNIT_ASSERT ( lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    /* Float */
    lItem = lFactory->createFloat("23.42");
    UNIT_ASSERT ( checkType(lItem.getType(), "float") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "23.42" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createFloat("INF");
    UNIT_ASSERT ( lItem.isPosOrNegInf() );
    UNIT_ASSERT ( !lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat("-INF");
    UNIT_ASSERT ( lItem.isPosOrNegInf() );
    UNIT_ASSERT ( !lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat("NaN");
    UNIT_ASSERT ( !lItem.isPosOrNegInf() );
    UNIT_ASSERT ( lItem.isNaN() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

    lItem = lFactory->createFloat(23.42f);
    UNIT_ASSERT ( checkType(lItem.getType(), "float") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "23.42" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* NonNegativeInteger */
    lItem = lFactory->createNonNegativeInteger(32423423);
    UNIT_ASSERT ( checkType(lItem.getType(), "nonNegativeInteger") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "32423423" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* NegativeInteger */
    lItem = lFactory->createNegativeInteger(-32423423);
    UNIT_ASSERT ( checkType(lItem.getType(), "negativeInteger") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "-32423423" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createNegativeInteger(1);
    UNIT_ASSERT ( lItem.isNull() );

    /* NonPositiveInteger */
    lItem = lFactory->createNonPositiveInteger(-32423423);
    UNIT_ASSERT ( checkType(lItem.getType(), "nonPositiveInteger") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "-32423423" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createNonPositiveInteger(1);
    UNIT_ASSERT ( lItem.isNull() );

    /* PositiveInteger */
    lItem = lFactory->createPositiveInteger(32423423);
    UNIT_ASSERT ( checkType(lItem.getType(), "positiveInteger") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "32423423" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* Unsigned Byte */
    lItem = lFactory->createUnsignedByte('a');
    UNIT_ASSERT ( checkType(lItem.getType(), "unsignedByte") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "97" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );


    /* Unsigned Short */
    lItem = lFactory->createUnsignedShort(10);
    UNIT_ASSERT ( checkType(lItem.getType(), "unsignedShort") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "10" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* Unsigned Long */
    lItem = lFactory->createUnsignedLong(10);
    UNIT_ASSERT ( checkType(lItem.getType(), "unsignedLong") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "10" );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* Unsigned Int */
    lItem = lFactory->createUnsignedInt(10);
    UNIT_ASSERT ( checkType(lItem.getType(), "unsignedInt") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "10" );
	UNIT_ASSERT ( lItem.getUnsignedIntValue() == 10 );
    UNIT_ASSERT ( lItem.getEBV().getBooleanValue() );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Date*/
    lItem = lFactory->createDate("1999-05-31");
    UNIT_ASSERT ( checkType(lItem.getType(), "date") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "1999-05-31" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createDate(1999,05,31);
    UNIT_ASSERT ( checkType(lItem.getType(), "date") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "1999-05-31" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** DateTime*/
    lItem = lFactory->createDateTime("1999-05-31T01:02:03.04-01:00");
    UNIT_ASSERT ( checkType(lItem.getType(), "dateTime") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "1999-05-31T01:02:03.04-01:00" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createDateTime(1999, 05, 31, 01, 02, 3.04, -3600);
    UNIT_ASSERT ( checkType(lItem.getType(), "dateTime") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "1999-05-31T01:02:03.04-01:00" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Time*/
    lItem = lFactory->createTime("08:00:00+09:00");
    UNIT_ASSERT ( checkType(lItem.getType(), "time") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "08:00:00+09:00" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createTime(8,9,10.123);
    UNIT_ASSERT ( checkType(lItem.getType(), "time") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "08:09:10.123" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createTime(17,0,0,-21600);
    UNIT_ASSERT ( checkType(lItem.getType(), "time") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "17:00:00-06:00" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** GYearMonth*/
    lItem = lFactory->createGYearMonth("1976-02");
    UNIT_ASSERT ( checkType(lItem.getType(), "gYearMonth") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "1976-02" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGYearMonth(1976,02);
    UNIT_ASSERT ( checkType(lItem.getType(), "gYearMonth") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "1976-02" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** GYear*/
    lItem = lFactory->createGYear("1977");
    UNIT_ASSERT ( checkType(lItem.getType(), "gYear") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "1977" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGYear(1977);
    UNIT_ASSERT ( checkType(lItem.getType(), "gYear") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "1977" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** GMonth*/
    lItem = lFactory->createGMonth("--12Z");
    UNIT_ASSERT ( checkType(lItem.getType(), "gMonth") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "--12Z" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGMonth(11);
    UNIT_ASSERT ( checkType(lItem.getType(), "gMonth") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "--11" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );
    
    /** GMonthDay*/
    lItem = lFactory->createGMonthDay("--12-25-14:00");
    UNIT_ASSERT ( checkType(lItem.getType(), "gMonthDay") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "--12-25-14:00" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGMonthDay(12, 25);
    UNIT_ASSERT ( checkType(lItem.getType(), "gMonthDay") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "--12-25" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** GDay*/
    lItem = lFactory->createGDay("---25-14:00");
    UNIT_ASSERT ( checkType(lItem.getType(), "gDay") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "---25-14:00" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createGDay(25);
    UNIT_ASSERT ( checkType(lItem.getType(), "gDay") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "---25" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** String */
    lItem = lFactory->createUntypedAtomic("abc");
    UNIT_ASSERT ( checkType(lItem.getType(), "untypedAtomic") );
    UNIT_ASSERT ( lItem.isAtomic() );
    UNIT_ASSERT ( lItem.getStringValue() == "abc" );
    UNIT_ASSERT ( !lItem.getAtomizationValue().isNull() );

  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return 1;
  }

  return 0;
}
