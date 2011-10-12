// Interface

class ItemFactory
{

  private:
    zorba::ItemFactory* theItemFactory;
  public:
    ItemFactory(): theItemFactory(0) {}
    ItemFactory(zorba::ItemFactory* aItemFactory) : theItemFactory(aItemFactory) {}
    ItemFactory(const ItemFactory& aItemFactory) : theItemFactory(aItemFactory.theItemFactory) {}

    Item 	createAnyURI (const std::string &aURI);
    Item 	createAttributeNode (Item aParent, Item aNodeName, Item aTypeName, Item aTypedValue);
    Item 	createAttributeNode (Item aParent, Item aNodeName, Item aTypeName, std::vector< Item > aTypedValue);
    Item 	createBase64Binary (const char *aBinData, size_t aLength);
    Item 	createBase64Binary (std::istream &aStream);
    Item 	createBase64Binary (const unsigned char *aBinData, size_t aLength);
    Item 	createBoolean (bool aValue);
    Item 	createByte (char aByte);
    Item 	createDate (const std::string &aDate);
    Item 	createDate (short aYear, short aMonth, short aDay);
    Item 	createDateTime (const std::string &aDateTimeValue);
    Item 	createDateTime (short aYear, short aMonth, short aDay, short aHour, short aMinute, double aSecond, short aTimeZone_hours);
    Item 	createDecimal (const std::string &aValue);
    Item 	createDecimalFromDouble (double aValue);
    Item 	createDecimalFromLong (unsigned long aValue);
    Item 	createDouble (const std::string &aValue);
    Item 	createDouble (double aValue);
    Item 	createDuration (const std::string &aValue);
    Item 	createDuration (short aYear, short aMonths, short aDays, short aHours, short aMinutes, double aSeconds);
    //Item 	createElementNode (Item &aParent, Item aNodeName, Item aTypeName, bool aHasTypedValue, bool aHasEmptyValue, std::vector< std::pair< std::string, std::string > > aNsBindings);
    Item 	createFloat (const std::string &aValue);
    Item 	createFloat (float aValue);
    Item 	createGDay (const std::string &aValue);
    Item 	createGDay (short aDay);
    Item 	createGMonth (const std::string &aValue);
    Item 	createGMonth (short aMonth);
    Item 	createGMonthDay (const std::string &aValue);
    Item 	createGMonthDay (short aMonth, short aDay);
    Item 	createGYear (short aYear);
    Item 	createGYear (const std::string &aValue);
    Item 	createGYearMonth (const std::string &aValue);
    Item 	createGYearMonth (short aYear, short aMonth);
    Item 	createHexBinary (const char *aHexData, size_t aSize);
    Item 	createInt (int aInt);
    Item 	createInteger (const std::string &aInteger);
    Item 	createInteger (long long aInteger);
    Item 	createLong (long long aLong);
    Item 	createNCName (const std::string &aValue);
    Item 	createNegativeInteger (long long aValue);
    Item 	createNonNegativeInteger (unsigned long long aValue);
    Item 	createNonPositiveInteger (long long aValue);
    Item 	createPositiveInteger (unsigned long long aValue);
    Item 	createQName (const std::string &aNamespace, const std::string &aPrefix, const std::string &aLocalname);
    Item 	createQName (const std::string &aNamespace, const std::string &aLocalname);
    Item 	createQName (const std::string &aQNameString);
    Item 	createShort (short aShort);
    //Item 	createStreamableString (std::istream &stream, StreamReleaser streamReleaser, bool seekable=false);
    Item 	createString (const std::string &aString);
    Item 	createTextNode (Item parent, std::string content);
    Item 	createTime (short aHour, short aMinute, double aSecond, short aTimeZone_hours);
    Item 	createTime (short aHour, short aMinute, double aSecond);
    Item 	createTime (const std::string &aValue);
    Item 	createUnsignedByte (const unsigned char aValue);
    Item 	createUnsignedInt (unsigned int aValue);
    Item 	createUnsignedLong (unsigned long long aValue);
    Item 	createUnsignedShort (unsigned short aValue);
}; // class ItemFactory
