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

#define  __STDC_LIMIT_MACROS
#include <zorba/item.h>
#include <zorba/zorba_string.h>
#include "diagnostics/xquery_diagnostics.h"
#include "api/itemfactoryimpl.h"

#include "zorbatypes/duration.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"
#include "api/unmarshaller.h"
#include "types/casting.h"

#include "store/api/item.h"


namespace zorba {
  
ItemFactoryImpl::ItemFactoryImpl()
{
  theItemFactory = GENV_ITEMFACTORY;
}


ItemFactoryImpl::~ItemFactoryImpl() 
{
}


Item ItemFactoryImpl::createString(const String& aString)
{
  zstring lString = Unmarshaller::getInternalString(aString);  
  store::Item_t lItem;
  
  theItemFactory->createString(lItem, lString);
  
  return &*lItem;
}


Item ItemFactoryImpl::createStreamableString(
    std::istream &stream,
    StreamReleaser streamReleaser,
    bool seekable)
{
  store::Item_t lItem;
  theItemFactory->createStreamableString(lItem, stream, streamReleaser, seekable);
  return &*lItem;
}


Item ItemFactoryImpl::createAnyURI(const String& aURI)
{
  zstring lString = Unmarshaller::getInternalString(aURI);
  
  store::Item_t lItem;
  theItemFactory->createAnyURI(lItem, lString);
  
  return &*lItem;
}

  
Item ItemFactoryImpl::createDate( const String& aDateValue )
{
  zstring const &lString = Unmarshaller::getInternalString( aDateValue );

  store::Item_t lItem;
  theItemFactory->createDate(lItem,  lString.c_str(), lString.size());

  return &*lItem;
}


Item ItemFactoryImpl::createDate (
      short aYear,
      short aMonth,
      short aDay )
{
  store::Item_t lItem;
  theItemFactory->createDate(lItem,  aYear, aMonth, aDay );

  return &*lItem;
}


Item ItemFactoryImpl::createQName(
    const String& aNamespace,
    const String& aPrefix,
    const String& aLocalname)
{
  zstring const &lNamespace = Unmarshaller::getInternalString( aNamespace );
  zstring const &lPrefix = Unmarshaller::getInternalString( aPrefix );
  zstring const &lLocalname = Unmarshaller::getInternalString( aLocalname );
  
  if (!GenericCast::instance()->castableToNCName(lLocalname.c_str()))
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( lLocalname, ZED( MustBeNCName ) )
    );

  if (lPrefix.size() && !GenericCast::instance()->castableToNCName(lPrefix.c_str()))
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( lPrefix, ZED( MustBeNCName ) )
    );
  
  store::Item_t lItem;
  theItemFactory->createQName(lItem, lNamespace, lPrefix, lLocalname);
  return &*lItem;
}


Item ItemFactoryImpl::createQName(
    const String& aNamespace,
    const String& aLocalname)
{
  zstring const &lNamespace = Unmarshaller::getInternalString( aNamespace );
  zstring const &lLocalname = Unmarshaller::getInternalString( aLocalname );

  if (!GenericCast::instance()->castableToNCName(lLocalname.c_str()))
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( lLocalname, ZED( MustBeNCName ) )
    );
  
  store::Item_t lItem;
  theItemFactory->createQName(lItem, lNamespace, zstring(), lLocalname);
  return &*lItem;
}
  
Item
ItemFactoryImpl::createQName(const String& aQNameString)
{
  zstring const &lQNameString = Unmarshaller::getInternalString( aQNameString );
  store::Item_t lItem;

  size_t lOpen  = lQNameString.find("{");
  size_t lClose = lQNameString.find("}");

  if (lOpen == 0 && lClose != std::string::npos) {
    zstring const &lNamespace = lQNameString.substr(1, lClose - 1);
    zstring const &lLocalname = lQNameString.substr(lClose+1);
    theItemFactory->createQName(lItem, lNamespace, zstring(), lLocalname);
    if (!GenericCast::instance()->castableToNCName(lLocalname.c_str()))
      throw XQUERY_EXCEPTION(
        err::FORG0001, ERROR_PARAMS( lLocalname, ZED( MustBeNCName ) )
      );
  }
  return &*lItem;
}

Item ItemFactoryImpl::createNCName(const String& aValue)
{
  zstring lString = Unmarshaller::getInternalString(aValue);

  if (!GenericCast::instance()->castableToNCName(lString.c_str()))
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( lString, ZED( MustBeNCName ) )
    );
  
  store::Item_t lItem;
  theItemFactory->createNCName(lItem, lString);
  return &*lItem;
}

    
Item ItemFactoryImpl::createBase64Binary(const char* aBinData, size_t aLength)
{
  store::Item_t lItem;
  xs_base64Binary n;
  std::string lMessage;
  if (xs_base64Binary::parseString(aBinData, aLength, n, lMessage))
  {
    theItemFactory->createBase64Binary(lItem, n);
  }
  else
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0040_TYPE_ERROR, ERROR_PARAMS( lMessage )
    );
  }
  return &*lItem;
}


Item ItemFactoryImpl::createBase64Binary(const unsigned char* aBinData, size_t aLength)
{
  store::Item_t lItem;
  xs_base64Binary n;
  std::string lMessage;
  xs_base64Binary::encode(aBinData, aLength, n);
  theItemFactory->createBase64Binary(lItem, n);
  return &*lItem;
}


Item ItemFactoryImpl::createBase64Binary(std::istream& aEncodedStream)
{
  std::stringstream lSs;
  while (aEncodedStream.good()) 
  {
    lSs.put(aEncodedStream.get());
  }
  std::string lContent = lSs.str();
  return createBase64Binary(lContent.c_str(), lContent.size());
}


Item ItemFactoryImpl::createBoolean(bool aValue)
{
  store::Item_t lItem;
  theItemFactory->createBoolean(lItem, aValue);
  return &*lItem;
}
    
  
Item ItemFactoryImpl::createDecimalFromLong (unsigned long aValue)
{
  store::Item_t lItem;
  Decimal const lDecimal(aValue);
  theItemFactory->createDecimal(lItem, lDecimal);
  return &*lItem;
}
    
    
Item ItemFactoryImpl::createDecimalFromDouble (double aValue)
{
  store::Item_t lItem;
  try {
    Decimal const lDecimal(aValue);
    theItemFactory->createDecimal(lItem, lDecimal);
  }
  catch ( std::invalid_argument const& ) {
    // ignore
  }
  return &*lItem;
}


Item ItemFactoryImpl::createDecimal (const String& aValue)
{
  store::Item_t lItem;
  zstring lString = Unmarshaller::getInternalString(aValue);
  try {
    Decimal const lDecimal(lString.c_str());
    theItemFactory->createDecimal(lItem, lDecimal);
  }
  catch ( std::exception const& ) {
    // ignore
  }
  return &*lItem;
}


Item
ItemFactoryImpl::createInteger(long long aInteger)
{
  store::Item_t lItem;
  Integer const lInteger(aInteger);
  theItemFactory->createInteger(lItem, lInteger);
  return &*lItem;
}


Item
ItemFactoryImpl::createInteger(const String& aInteger)
{
  zstring const &lString = Unmarshaller::getInternalString( aInteger );
  store::Item_t lItem;
  try {
    Integer const lInteger( lString.c_str() );
    theItemFactory->createInteger(lItem, lInteger);
  }
  catch ( std::exception const& ) {
    // ignore
  }
  return &*lItem;
}
  

Item ItemFactoryImpl::createLong ( long long aLong )
{
  store::Item_t lItem;

  theItemFactory->createLong(lItem, aLong);
  return &*lItem;
}
    

Item ItemFactoryImpl::createInt ( int aInt )
{
  store::Item_t lItem;

  if ( (INT32_MIN <= aInt) && (aInt <= INT32_MAX) ) {
    theItemFactory->createInt(lItem, aInt);
  }

  return &*lItem;
}
    

Item ItemFactoryImpl::createShort ( short aShort )
{
  store::Item_t lItem;

  theItemFactory->createShort(lItem, aShort);

  return &*lItem;
}
    
  
Item ItemFactoryImpl::createByte ( char aValue )
{
  store::Item_t lItem;

  theItemFactory->createByte(lItem, aValue);

  return &*lItem;
}
    
  
Item ItemFactoryImpl::createDateTime(short aYear, short aMonth, short aDay,
                                  short aHour, short aMinute, double aSecond,
                                  short aTimezone_hours)
{
  store::Item_t lItem;
  theItemFactory->createDateTime(lItem, aYear, aMonth, aDay,
                                 aHour, aMinute, aSecond, aTimezone_hours);

  return &*lItem;
}


Item ItemFactoryImpl::createDateTime( const String& aDateTimeValue )
{
  zstring lString = Unmarshaller::getInternalString( aDateTimeValue );

  store::Item_t lItem;
  theItemFactory->createDateTime(lItem,  lString.c_str(), lString.size());

  return &*lItem;
}


Item ItemFactoryImpl::createDouble ( double aValue )
{
  store::Item_t lItem;
  xs_double const lDouble(aValue);
  theItemFactory->createDouble(lItem, lDouble);
  return &*lItem;
}

  
Item ItemFactoryImpl::createDouble ( const String& aValue )
{
  zstring lString = Unmarshaller::getInternalString( aValue );

  store::Item_t lItem;
  try {
    xs_double const lDouble(lString.c_str());
    theItemFactory->createDouble(lItem, lDouble);
  }
  catch ( std::exception const& ) {
    // ignore
  }
  return &*lItem;
}


Item ItemFactoryImpl::createDuration( const String& aValue )
{
  zstring const &lString = Unmarshaller::getInternalString( aValue );
  store::Item_t  lItem;
  theItemFactory->createDuration(lItem, lString.c_str(), lString.size());

  return &*lItem;
}


Item ItemFactoryImpl::createDuration(
    short aYears,
    short aMonths,
    short aDays, 
    short aHours,
    short aMinutes,
    double aSeconds )
{
  store::Item_t lItem;
  
  theItemFactory->createDuration(lItem,
                                 aYears, aMonths, aDays,
                                 aHours, aMinutes, aSeconds);
  
  return &*lItem;
}

Item ItemFactoryImpl::createDayTimeDuration( const String& aValue )
{
  zstring const &lString = Unmarshaller::getInternalString( aValue );
  store::Item_t  lItem;
  theItemFactory->createDayTimeDuration(lItem, lString.c_str(), lString.size());

  return &*lItem;
}

Item ItemFactoryImpl::createYearMonthDuration( const String& aValue )
{
  zstring const &lString = Unmarshaller::getInternalString( aValue );
  store::Item_t  lItem;
  theItemFactory->createYearMonthDuration(lItem, lString.c_str(), lString.size());

  return &*lItem;
}

Item ItemFactoryImpl::createDocumentNode( const String& aBaseUri, const String& aDocUri )
{
  store::Item_t lItem;
  zstring &lBaseUri = Unmarshaller::getInternalString( aBaseUri );
  zstring &lDocUri = Unmarshaller::getInternalString( aDocUri );
  try {
    theItemFactory->createDocumentNode(lItem, lBaseUri, lDocUri);
  }
  catch ( std::exception const& ) {
    // ignore
  }
  return &*lItem;
}

Item ItemFactoryImpl::createFloat ( const String& aValue )
{
  zstring const &lString = Unmarshaller::getInternalString( aValue );
  store::Item_t lItem;
  try {
    xs_float const lFloat(lString.c_str());
    theItemFactory->createFloat(lItem, lFloat);
  } 
  catch ( std::exception const& ) {
    // ignore
  }
  return &*lItem;
}


Item ItemFactoryImpl::createFloat ( float aValue )
{
  store::Item_t lItem;
  xs_float const lFloat(aValue);
  theItemFactory->createFloat(lItem, lFloat);
  return &*lItem;
}

  
Item ItemFactoryImpl::createHexBinary ( const char* aHexData, size_t aSize )
{
  store::Item_t lItem;
  xs_hexBinary n;
  if (xs_hexBinary::parseString(aHexData, aSize, n))
    theItemFactory->createHexBinary(lItem, n);

  return &*lItem;
}


Item ItemFactoryImpl::createNegativeInteger ( long long aValue )
{
  store::Item_t lItem;
  if (aValue < 0) {
    Integer const lInteger(aValue);
    theItemFactory->createNegativeInteger(lItem, lInteger);
  }
  return &*lItem;
}
  

Item ItemFactoryImpl::createNonNegativeInteger ( unsigned long long aValue )
{
  store::Item_t lItem;
  Integer lInteger(aValue);
  theItemFactory->createNonNegativeInteger(lItem, lInteger);
  return &*lItem;
}


Item ItemFactoryImpl::createNonPositiveInteger ( long long aValue )
{
  store::Item_t lItem;
  if (aValue < 0) {
    Integer const lInteger(aValue);
    theItemFactory->createNonPositiveInteger(lItem, lInteger);
  }
  return &*lItem;
}


Item ItemFactoryImpl::createPositiveInteger ( unsigned long long aValue )
{
  store::Item_t lItem;
  Integer lInteger(aValue);
  theItemFactory->createPositiveInteger(lItem, lInteger);
  return &*lItem;
}


Item ItemFactoryImpl::createGDay ( const String& aValue )
{
  zstring lString = Unmarshaller::getInternalString( aValue );
  store::Item_t lItem;

  theItemFactory->createGDay(lItem,  lString.c_str(), lString.size());
  
  return &*lItem;
}
  

Item ItemFactoryImpl::createGDay ( short aDay )
{
  store::Item_t lItem;

  theItemFactory->createGDay(lItem,  aDay );
  
  return &*lItem;
}
  
  
Item ItemFactoryImpl::createGMonth ( short aMonth )
{
  store::Item_t lItem;

  theItemFactory->createGMonth(lItem,  aMonth );
  
  return &*lItem;
}

  
Item ItemFactoryImpl::createGMonth ( const String& aValue )
{
  zstring lString = Unmarshaller::getInternalString(aValue);
  store::Item_t lItem;
  
  theItemFactory->createGMonth(lItem,  lString.c_str(), lString.size());
  
  return &*lItem;
}
  

Item ItemFactoryImpl::createGMonthDay(const String& aValue)
{
  zstring lString = Unmarshaller::getInternalString(aValue);
  store::Item_t lItem;

  theItemFactory->createGMonthDay(lItem,  lString.c_str(), lString.size());
  
  return &*lItem;
}


Item ItemFactoryImpl::createGMonthDay(short aMonth, short aDay)
{
  store::Item_t lItem;

  theItemFactory->createGMonthDay(lItem,  aMonth, aDay );
  
  return &*lItem;
}
  

Item ItemFactoryImpl::createGYear(const String& aValue)
{
  zstring lString = Unmarshaller::getInternalString(aValue);
  store::Item_t lItem;

  theItemFactory->createGYear(lItem,  lString.c_str(), lString.size() );
  
  return &*lItem;
}


Item ItemFactoryImpl::createGYear ( short aYear )
{
  store::Item_t lItem;

  theItemFactory->createGYear(lItem,  aYear );
  
  return &*lItem;
}
  

Item ItemFactoryImpl::createGYearMonth ( const String& aValue )
{
  zstring lString = Unmarshaller::getInternalString( aValue );
  store::Item_t lItem;

  theItemFactory->createGYearMonth(lItem, lString.c_str(), lString.size());
  
  return &*lItem;
}

  
Item ItemFactoryImpl::createGYearMonth ( short aYear, short aMonth )
{
  store::Item_t lItem;

  theItemFactory->createGYearMonth(lItem,  aYear, aMonth );
  
  return &*lItem;
}


Item ItemFactoryImpl::createTime ( const String& aValue )
{
  zstring lString = Unmarshaller::getInternalString( aValue );
  store::Item_t lItem;

  theItemFactory->createTime(lItem,  lString.c_str(), lString.size() );
  
  return &*lItem;
}
  

Item ItemFactoryImpl::createTime ( short aHour, short aMinute, double aSecond )
{
  store::Item_t lItem;

  theItemFactory->createTime(lItem,  aHour, aMinute, aSecond );
  
  return &*lItem;
}


Item ItemFactoryImpl::createTime(
    short aHour,
    short aMinute,
    double aSecond,
    short aTimezone_hours )
{
  store::Item_t lItem;

  theItemFactory->createTime(lItem,  aHour, aMinute, aSecond, aTimezone_hours );
  
  return &*lItem;
}
  

Item ItemFactoryImpl::createUnsignedByte(const unsigned char aValue)
{
  store::Item_t lItem;
  theItemFactory->createUnsignedByte(lItem, aValue);
  return &*lItem;
}
  

Item ItemFactoryImpl::createUnsignedInt(unsigned int aValue)
{
  store::Item_t lItem;
  
  if ( aValue <= UINT32_MAX ) {
    theItemFactory->createUnsignedInt(lItem, aValue);
  }

  return &*lItem;
}
  

Item ItemFactoryImpl::createUnsignedLong(unsigned long long aValue)
{
  store::Item_t lItem;
  theItemFactory->createUnsignedLong(lItem, aValue);
  return &*lItem;
}
  

Item ItemFactoryImpl::createUnsignedShort(unsigned short aValue)
{
  store::Item_t lItem;
  theItemFactory->createUnsignedShort(lItem, aValue);
  return &*lItem;
}


zorba::Item ItemFactoryImpl::createElementNode(
    Item& aParent,
    Item aNodeName,
    Item aTypeName,
    bool aHasTypedValue,
    bool aHasEmptyValue,
    std::vector<std::pair<String, String> > aNsBindings)
{
  store::Item_t lItem;
  store::Item_t lNodeName = Unmarshaller::getInternalItem(aNodeName);
  store::Item_t lTypeName = Unmarshaller::getInternalItem(aTypeName);
  store::NsBindings lNsBindings;
  
  std::vector<std::pair<String, String> >::iterator lIter;
  for (lIter = aNsBindings.begin(); lIter != aNsBindings.end(); ++lIter) 
  {
    zstring lFirst = Unmarshaller::getInternalString(lIter->first);
    zstring lSecond = Unmarshaller::getInternalString(lIter->second);
    lNsBindings.push_back(std::pair<zstring, zstring>(lFirst, lSecond));
    }

  zstring lBaseUri;
  theItemFactory->createElementNode(lItem,
                                    Unmarshaller::getInternalItem(aParent),
                                    lNodeName,
                                    lTypeName,
                                    aHasTypedValue,
                                    aHasEmptyValue,
                                    lNsBindings,
                                    lBaseUri);
  return &*lItem;
}


zorba::Item ItemFactoryImpl::createAttributeNode(
    Item aParent,
    Item aNodeName,
    Item aTypeName,
    Item aTypedValue)
{
  store::Item_t lItem;
  store::Item_t lNodeName = Unmarshaller::getInternalItem(aNodeName);
  store::Item_t lTypeName = Unmarshaller::getInternalItem(aTypeName);
  store::Item_t lTypedValue = Unmarshaller::getInternalItem(aTypedValue);
  theItemFactory->createAttributeNode(lItem,
                                      Unmarshaller::getInternalItem(aParent),
                                      lNodeName,
                                      lTypeName,
                                      lTypedValue);
  return &*lItem;
}


zorba::Item ItemFactoryImpl::createAttributeNode(
    Item aParent,
    Item aNodeName,
    Item aTypeName,
    std::vector<Item> aTypedValue )
{
  store::Item_t lItem;
  store::Item_t lNodeName = Unmarshaller::getInternalItem(aNodeName);
  store::Item_t lTypeName = Unmarshaller::getInternalItem(aTypeName);
  std::vector<store::Item_t> lTypedValue;
  std::vector<Item>::iterator lIter;

  for (lIter = aTypedValue.begin(); lIter != aTypedValue.end(); ++lIter) 
  {
    lTypedValue.push_back(Unmarshaller::getInternalItem(*lIter));
  }

  theItemFactory->createAttributeNode(lItem,
                                      Unmarshaller::getInternalItem(aParent),
                                      lNodeName,
                                      lTypeName,
                                      lTypedValue);
  return &*lItem;
}


zorba::Item ItemFactoryImpl::createCommentNode(Item aParent, String aContent)
{
  store::Item_t lItem;
  zstring lContent = Unmarshaller::getInternalString(aContent);
  theItemFactory->createCommentNode(lItem,
                               Unmarshaller::getInternalItem(aParent),
                               lContent);
  return &*lItem;
}


zorba::Item ItemFactoryImpl::createPiNode(Item aParent, String aTarget, String aContent, String aBaseUri)
{
  store::Item_t lItem;
  zstring lTarget = Unmarshaller::getInternalString(aTarget);
  zstring lContent = Unmarshaller::getInternalString(aContent);
  zstring lBaseUri = Unmarshaller::getInternalString(aBaseUri);
  theItemFactory->createPiNode(lItem,
                               Unmarshaller::getInternalItem(aParent),
                               lTarget,
                               lContent,
                               lBaseUri);
  return &*lItem;
}


zorba::Item ItemFactoryImpl::createTextNode(Item parent, String content)
{
  store::Item_t lItem;
  zstring lContent = Unmarshaller::getInternalString(content);
  theItemFactory->createTextNode(lItem,
                                 Unmarshaller::getInternalItem(parent),
                                 lContent);
  return &*lItem;
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
