
%{  // start Implementation


 
  Item  ItemFactory::createAnyURI (const std::string &aURI){
    return Item(theItemFactory->createAnyURI(aURI));
  }
  
  Item  ItemFactory::createAttributeNode (Item& aParent, Item& aNodeName, Item& aTypeName, Item& aTypedValue){
    return Item( theItemFactory->createAttributeNode( aParent.theItem, aNodeName.theItem, aTypeName.theItem, aTypedValue.theItem ));
  }
  
  Item  ItemFactory::createAttributeNode (Item& aParent, Item& aNodeName, Item& aTypeName, std::vector< Item > aTypedValue){

    std::vector< zorba::Item > typedValue;
    typedValue.reserve(aTypedValue.size());
    std::vector< Item >::iterator iter;
    for(iter = aTypedValue.begin(); iter != aTypedValue.end(); iter++) {
      typedValue.push_back((*iter).theItem);
    }
    return Item( theItemFactory->createAttributeNode (aParent.theItem, aNodeName.theItem, aTypeName.theItem, typedValue ));
  }
  
  Item  ItemFactory::createBase64Binary (const char *aBinData, size_t aLength){
    return Item( theItemFactory->createBase64Binary(aBinData, aLength));
  }
  Item  ItemFactory::createBase64Binary (std::istream &aStream){
    return Item( theItemFactory->createBase64Binary(aStream));
  }
  Item  ItemFactory::createBase64Binary (const unsigned char *aBinData, size_t aLength){
    return Item( theItemFactory->createBase64Binary(aBinData, aLength));
  }
  Item  ItemFactory::createBoolean (bool aValue){
    return Item( theItemFactory->createBoolean(aValue));
  }
  Item  ItemFactory::createByte (char aByte){
    return Item( theItemFactory->createByte(aByte));
  }
  Item  ItemFactory::createCommentNode (Item &aParent, const std::string &aContent){
    zorba::String lContent = zorba::String(aContent);
    return Item( theItemFactory->createCommentNode (aParent.theItem, lContent));
  }
  Item  ItemFactory::createDate (const std::string &aDate){
    return Item( theItemFactory->createDate(aDate));
  }
  Item  ItemFactory::createDate (short aYear, short aMonth, short aDay){
    return Item( theItemFactory->createDate (aYear, aMonth, aDay));
  }
  Item  ItemFactory::createDateTime (const std::string &aDateTimeValue){
    return Item( theItemFactory->createDateTime (aDateTimeValue));
  }
  Item  ItemFactory::createDateTime (short aYear, short aMonth, short aDay, short aHour, short aMinute, double aSecond, short aTimeZone_hours){
    return Item( theItemFactory->createDateTime (aYear, aMonth, aDay, aHour, aMinute, aSecond, aTimeZone_hours));
  }
  Item  ItemFactory::createDecimal (const std::string &aValue){
    return Item( theItemFactory->createDecimal (aValue));
  }
  Item  ItemFactory::createDecimalFromDouble (double aValue){
    return Item( theItemFactory->createDecimalFromDouble (aValue));
  }
  Item  ItemFactory::createDecimalFromLong (unsigned long aValue){
    return Item( theItemFactory->createDecimalFromLong (aValue));
  }
  Item  ItemFactory::createDouble (const std::string &aValue){
    return Item( theItemFactory->createDouble (aValue));
  }
  Item  ItemFactory::createDouble (double aValue){
    return Item( theItemFactory->createDouble (aValue));
  }
  Item  ItemFactory::createDuration (const std::string &aValue){
    return Item( theItemFactory->createDuration (aValue));
  }
  Item  ItemFactory::createDuration (short aYear, short aMonths, short aDays, short aHours, short aMinutes, double aSeconds){
    return Item( theItemFactory->createDuration (aYear, aMonths, aDays, aHours, aMinutes, aSeconds));
  }
  Item  ItemFactory::createDayTimeDuration (const std::string &aValue){
    return Item( theItemFactory->createDayTimeDuration (aValue));
  }
  Item  ItemFactory::createYearMonthDuration (const std::string &aValue){
    return Item( theItemFactory->createYearMonthDuration (aValue));
  }
  Item  ItemFactory::createDocumentNode (const std::string &aBaseUri, const std::string &aDocUri){
    return Item( theItemFactory->createDocumentNode (aBaseUri, aDocUri));
  }

  Item  ItemFactory::createElementNode (Item &aParent, Item& aNodeName, Item& aTypeName, bool aHasTypedValue, bool aHasEmptyValue, std::vector< std::pair< std::string, std::string > > aNsBindings){
    std::vector< std::pair< zorba::String, zorba::String > > items;
    items.reserve(aNsBindings.size());
    std::vector< std::pair< std::string, std::string > >::iterator iter;
    for(iter = aNsBindings.begin(); iter != aNsBindings.end(); iter++) {
      std::pair< zorba::String, zorba::String > pair;
      pair.first = (*iter).first;
      pair.second = (*iter).second;
      items.push_back(pair);
    }
    return Item( theItemFactory->createElementNode (aParent.theItem, aNodeName.theItem, aTypeName.theItem, aHasTypedValue, aHasEmptyValue, items));
  }

  Item  ItemFactory::createElementNode (Item &aParent, Item& aNodeName, Item& aTypeName, bool aHasTypedValue, bool aHasEmptyValue){
    return Item( theItemFactory->createElementNode (aParent.theItem, aNodeName.theItem, aTypeName.theItem, aHasTypedValue, aHasEmptyValue, std::vector<std::pair<zorba::String, zorba::String> >()));
  }
  Item  ItemFactory::createFloat (const std::string &aValue){
    return Item( theItemFactory->createFloat (aValue));
  }
  Item  ItemFactory::createFloat (float aValue){
    return Item( theItemFactory->createFloat (aValue));
  }
  Item  ItemFactory::createGDay (const std::string &aValue){
    return Item( theItemFactory->createGDay (aValue));
  }
  Item  ItemFactory::createGDay (short aDay){
    return Item( theItemFactory->createGDay (aDay));
  }
  Item  ItemFactory::createGMonth (const std::string &aValue){
    return Item( theItemFactory->createGMonth (aValue));
  }
  Item  ItemFactory::createGMonth (short aMonth){
    return Item( theItemFactory->createGMonth (aMonth));
  }
  Item  ItemFactory::createGMonthDay (const std::string &aValue){
    return Item( theItemFactory->createGMonthDay (aValue));
  }
  Item  ItemFactory::createGMonthDay (short aMonth, short aDay){
    return Item( theItemFactory->createGMonthDay (aMonth, aDay));
  }
  Item  ItemFactory::createGYear (short aYear){
    return Item( theItemFactory->createGYear (aYear));
  }
  Item  ItemFactory::createGYear (const std::string &aValue){
    return Item( theItemFactory->createGYear (aValue));
  }
  Item  ItemFactory::createGYearMonth (const std::string &aValue){
    return Item( theItemFactory->createGYearMonth (aValue));
  }
  Item  ItemFactory::createGYearMonth (short aYear, short aMonth){
    return Item( theItemFactory->createGYearMonth (aYear, aMonth));
  }
  Item  ItemFactory::createHexBinary (const char *aHexData, size_t aSize){
    return Item( theItemFactory->createHexBinary (aHexData, aSize));
  }
  Item  ItemFactory::createInt (int aInt){
    return Item( theItemFactory->createInt (aInt));
  }
  Item  ItemFactory::createInteger (const std::string &aInteger){
    return Item( theItemFactory->createInteger (aInteger));
  }
  Item  ItemFactory::createInteger (long long aInteger){
    return Item( theItemFactory->createInteger (aInteger));
  }
  Item  ItemFactory::createLong (long long aLong){
    return Item( theItemFactory->createLong (aLong));
  }
  Item  ItemFactory::createNCName (const std::string &aValue){
    return Item( theItemFactory->createNCName (aValue));
  }
  Item  ItemFactory::createNegativeInteger (long long aValue){
    return Item( theItemFactory->createNegativeInteger (aValue));
  }
  Item  ItemFactory::createNonNegativeInteger (unsigned long long aValue){
    return Item( theItemFactory->createNonNegativeInteger (aValue));
  }
  Item  ItemFactory::createNonPositiveInteger (long long aValue){
    return Item( theItemFactory->createNonPositiveInteger (aValue));
  }
  Item  ItemFactory::createPiNode (Item &aParent, const std::string &aTarget, const std::string &aContent, const std::string &aBaseUri){
    zorba::String lTarget = zorba::String(aTarget);
    zorba::String lContent = zorba::String(aContent);
    zorba::String lBaseUri = zorba::String(aBaseUri);
    return Item( theItemFactory->createPiNode (aParent.theItem, lTarget, lContent, lBaseUri));
  }
  Item  ItemFactory::createPositiveInteger (unsigned long long aValue){
    return Item( theItemFactory->createPositiveInteger (aValue));
  }
  Item  ItemFactory::createQName (const std::string &aNamespace, const std::string &aPrefix, const std::string &aLocalname){
    return Item( theItemFactory->createQName (aNamespace, aPrefix, aLocalname));
  }
  Item  ItemFactory::createQName (const std::string &aNamespace, const std::string &aLocalname){
    return Item( theItemFactory->createQName (aNamespace, aLocalname));
  }
  Item  ItemFactory::createQName (const std::string &aQNameString){
    return Item( theItemFactory->createQName (aQNameString));
  }
  Item  ItemFactory::createShort (short aShort){
    return Item( theItemFactory->createShort (aShort));
  }
  /*
  Item  ItemFactory::createStreamableString (std::istream &stream, StreamReleaser streamReleaser, bool seekable=false){
    return Item( theItemFactory->createStreamableString (std::istream &stream, StreamReleaser streamReleaser, seekable));
  }
  */
  Item  ItemFactory::createString (const std::string &aString){
    return Item( theItemFactory->createString (aString));
  }
  Item  ItemFactory::createTextNode (Item &aParent, const std::string &aContent){
    zorba::String lContent = zorba::String(aContent);
    return Item( theItemFactory->createTextNode (aParent.theItem, lContent));
  }
  Item  ItemFactory::createTime (short aHour, short aMinute, double aSecond, short aTimeZone_hours){
    return Item( theItemFactory->createTime (aHour, aMinute, aSecond, aTimeZone_hours));
  }
  Item  ItemFactory::createTime (short aHour, short aMinute, double aSecond){
    return Item( theItemFactory->createTime (aHour, aMinute, aSecond));
  }
  Item  ItemFactory::createTime (const std::string &aValue){
    return Item( theItemFactory->createTime (aValue));
  }
  Item  ItemFactory::createUnsignedByte (const unsigned char aValue){
    return Item( theItemFactory->createUnsignedByte (aValue));
  }
  Item  ItemFactory::createUnsignedInt (unsigned int aValue){
    return Item( theItemFactory->createUnsignedInt (aValue));
  }
  Item  ItemFactory::createUnsignedLong (unsigned long long aValue){
    return Item( theItemFactory->createUnsignedLong (aValue));
  }
  Item  ItemFactory::createUnsignedShort (unsigned short aValue){
    return Item( theItemFactory->createUnsignedShort (aValue));
  }

  Item ItemFactory::createJSONNull() {
    return Item( theItemFactory->createJSONNull() );
  }

  Item ItemFactory::createJSONNumber(std::string aString) {
    return Item( theItemFactory->createJSONNumber(aString));
  }

  Item ItemFactory::createJSONObject(std::vector<std::pair<Item, Item> >& aNames) {
    std::vector< std::pair< zorba::Item, zorba::Item > > names;
    names.reserve(aNames.size());
 
    for(std::vector< std::pair< Item, Item > >::iterator iter = aNames.begin(); iter != aNames.end(); iter++) {
      std::pair< zorba::Item, zorba::Item > pair;
      pair.first = (*iter).first.theItem;
      pair.second = (*iter).second.theItem;
      names.push_back(pair);
    }
    return Item( theItemFactory->createJSONObject (names) );
  }

  Item ItemFactory::createJSONObject(std::vector<std::pair<std::string, std::string> >& aNames) {
    std::vector< std::pair< zorba::Item, zorba::Item > > names;
    names.reserve(aNames.size());
 
    for(std::vector<std::pair<std::string, std::string> >::iterator iter = aNames.begin(); iter != aNames.end(); iter++) {
      std::pair< zorba::Item, zorba::Item > pair;
      pair.first = theItemFactory->createString( (*iter).first );
      pair.second = theItemFactory->createString( (*iter).second );
      names.push_back(pair);
    }
    return Item( theItemFactory->createJSONObject (names) );
  }

  Item ItemFactory::createJSONArray(std::vector<Item>& aItems) {
    std::vector< zorba::Item > items;
    items.reserve(aItems.size());
 
    for(std::vector< Item >::iterator iter = aItems.begin(); iter != aItems.end(); iter++) {
      zorba::Item item = (*iter).theItem;
      items.push_back(item);
    }
    return Item( theItemFactory->createJSONArray (items) );
  }

  Item ItemFactory::createJSONArray(std::vector<std::string>& aItems) {
    std::vector< zorba::Item > items;
    items.reserve(aItems.size());

    for(std::vector< std::string >::iterator iter = aItems.begin(); iter != aItems.end(); iter++) {
      zorba::Item item = theItemFactory->createString(*iter);
      items.push_back(item);
    }
    return Item( theItemFactory->createJSONArray (items) );
  }

  Item
  ItemFactory::createDateTimeStamp(short aYear, short aMonth, short aDay,
                                   short aHour, short aMinute, double aSecond,
                                   short aTimeZone_hours) {
    return Item( theItemFactory->createDateTimeStamp(aYear, aMonth, aDay,
                                   aHour, aMinute, aSecond,
                                   aTimeZone_hours) );
  }
  
  Item ItemFactory::createDateTimeStamp( const std::string &aValue ) {
    return Item( theItemFactory->createDateTimeStamp(aValue) );
  }
    
%}  // end Implementation

%include "ItemFactory.h"
