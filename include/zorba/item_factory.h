#ifndef ZORBA_ITEM_FACTORY_API_H
#define ZORBA_ITEM_FACTORY_API_H

#include <zorba/api_shared_types.h>

namespace zorba {
  
  /** \brief ItemFactory to create Items.
   *
   * An instance of this class can be obtained by calling getItemFactory on the Zorba object.
   *
   * Each createXXX function of this class creates an Item of an XML Schema item.
   * If an isNull() call on an Item created by this function returns true the
   * given Item could not be created.
   */
  class ItemFactory 
  {
    public:
      /** \brief Destructor
       */
      virtual ~ItemFactory() {}

      /** \brief Creates a String Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#string]
       *
       * @param aString String representation of the String Item.
       * @return The String Item
       */
      virtual Item
      createString(const String& aString) = 0;

      /** \brief Creates an AnyURI Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#anyURI]
       *
       * @param aURI String representation of the AnyURI.
       * @return The AnyURI Item.
       */
      virtual Item
      createAnyURI(const String& aURI) = 0;

      /** \brief Creates a QName Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#QName]
       *
       * @param aNamespace String representation of the namespace.
       * @param aPrefix String representation of the prefix.
       * @param aLocalname String representation of the localname.
       *
       * @return The QName Item.
       */
      virtual Item
      createQName(const String& aNamespace, const String& aPrefix,
                  const String& aLocalname) = 0;

      /** \brief Creates a QName Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#QName]
       *
       * @param aNamespace String representation of the namespace.
       * @param aLocalname String representation of the localname.
       *
       * @return The QName Item.
       */
      virtual Item
      createQName(const String& aNamespace, const String& aLocalname) = 0;

      /** \brief Creates a NCName Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#NCName]
       *
       * @param aValue String representation of the NCName.
       * @return The NCName Item
       */
      virtual Item 
      createNCName(const String& aValue) = 0;
        
    
      /** \brief Creates a Base64Binary Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#base64Binary]
       *
       * @param aBinData a pointer to the base64 binary data.
       * @param aLength the length of the base64 binary data.
       * @return The Base64Binary Item
       */
      virtual Item 
      createBase64Binary(const char* aBinData, size_t aLength) = 0;
      
      /** \brief Creates a Boolean Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#bool]
       *
       * @param aValue bool representation of the Boolean.
       * @return The Boolean Item
       */
      virtual Item 
      createBoolean(bool aValue) = 0;
    
      /** \brief Creates a Decimal Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue unsigned long representation of the Decimal.
       * @return The Decimal Item
       */
      virtual Item 
      createDecimal (unsigned long aValue) = 0;
    
      /** \brief Creates a Decimal Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue double representation of the Decimal.
       * @return The Decimal Item
       */
      virtual Item 
      createDecimal (double aValue) = 0;

      /** \brief Creates a Decimal Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue String representation of the Decimal (e.g. 12678967.543233).
       * @return The Decimal Item
       */
      virtual Item 
      createDecimal (const String& aValue) = 0;

      /** \brief Creates an Integer Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#integer]
       *
       * @param aInteger int representation of the Integer.
       * @return The Integer Item
       */
      virtual Item
      createInteger(int aInteger) = 0;

      /** \brief Creates an Integer Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#integer]
       *
       * @param aInteger unsigned long representation of the Integer.
       * @return The Integer Item
       */
      virtual Item
      createInteger(long aInteger) = 0;

      /** \brief Creates an Integer Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#integer]
       *
       * @param aInteger String representation of the Integer.
       * @return The Integer Item
       */
      virtual Item
      createInteger(const String& aInteger) = 0;
    
      /** \brief Creates a Long Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#long]
       *
       * @param aLong long long representation of the Long.
       * @return The Long Item
       */
      virtual Item
      createLong ( long long aLong ) = 0;
    
      /** \brief Creates a Int Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#int]
       *
       * @param aInt int representation of the Int.
       * @return The NCName Item
       */
      virtual Item
      createInt ( int aInt ) = 0;
    
      /** \brief Creates a Short Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#short]
       *
       * @param aShort short representation of the Short.
       * @return The Short Item
       */
      virtual Item
      createShort ( short aShort ) = 0;
    
      /** \brief Creates a Byte Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#byte]
       *
       * @param aByte char representation of the Byte.
       * @return The Byte Item
       */
      virtual Item
      createByte ( char value ) = 0;
    
      /** \brief Creates a Date Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#date]
       *
       * @param aDate String representation of the Date (e.g. 2002-10-10).
       * @return The Date Item
       */
      virtual Item
      createDate ( const String& aDate ) = 0;
      
      /** \brief Creates a Date Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#date]
       *
       * @param aYear String representation of the year.
       * @param aMonth String representation of the month.
       * @param aDay String representation of the day.
       * @return The Date Item
       */
      virtual Item
      createDate ( short aYear, short aMonth, short aDay ) = 0;

      /** \brief Creates a DateTime Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#dateTime]
       *
       * @param aYear short-valued representation of the year.
       * @param aMonth short-valued representation of the month.
       * @param aDay short-valued representation of the day.
       * @param aHour short-valued representation of the hour.
       * @param aMinute short-valued representation of the minute.
       * @param aSecond short-valued representation of the second.
       * @param aTimezone short-valued representation of the timezone.
       * @return The DateTime Item.
       */
      virtual Item
      createDateTime(short aYear, short aMonth, short aDay, 
                     short aHour, short aMinute, short aSecond, 
                     short aTimezone) = 0;

      /** \brief Creates a DateTime Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#dateTime]
       *
       * @param aDateTimeValue String representation of the datetime value
       *        (for example, 2002-10-10T12:00:00-05:00).
       * @return The DateTime Item.
       */
      virtual Item
      createDateTime( const String& aDateTimeValue ) = 0;

      /** \brief Creates a Double Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#double]
       *
       * @param aValue double representation of the Double.
       * @return The Double Item
       */
      virtual Item
      createDouble ( double aValue ) = 0;

      /** \brief Creates a Double Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#double]
       *
       * @param aValue String representation of the Double.
       * @return The Double Item
       */
      virtual Item
      createDouble ( const String& aValue ) = 0;
    
      /** \brief Creates a Duration Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#duration]
       *
       * @param aValue String representation of the NCName
       * @return The Duration Item
       */
      virtual Item
      createDuration( const String& aValue ) = 0;
      
      /** \brief Creates a Duration Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#duration]
       *
       * @param aYear short-valued representation of the years.
       * @param aMonth short-valued representation of the months.
       * @param aDay short-valued representation of the days.
       * @param aHour short-valued representation of the hours.
       * @param aMinute short-valued representation of the minutes.
       * @param aSecond short-valued representation of the seconds.
       * @return The Duration Item
       */
      virtual Item
      createDuration ( short aYears, short aMonths, short aDays, 
                       short aHours, short aMinutes, short aSeconds ) = 0;
    
      /** \brief Creates a Entities Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#ENTITIES]
       *
       * @param aValue String representation of the Entities.
       * @return The Entities Item
       */
      virtual Item 
      createENTITIES ( const String& aValue ) = 0;
      
      /** \brief Creates a Entity Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#ENTITY]
       *
       * @param aValue String representation of the Entity.
       * @return The Entity Item
       */
      virtual Item
      createENTITY ( const String& value ) = 0;
    
      /** \brief Creates a Float Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#float]
       *
       * @param aValue String representation of the Float.
       * @return The Float Item
       */
      virtual Item
      createFloat ( const String& aValue ) = 0;
    
      /** \brief Creates a gDay Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gDay]
       *
       * @param aValue String representation of the gDay.
       * @return The gDay Item
       */
      virtual Item
      createGDay ( const String& value ) = 0;
    
      /** \brief Creates a gDay Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gDay]
       *
       * @param aDay short representation of the gDay.
       * @return The gDay Item
       */
      virtual Item
      createGDay ( short aDay ) = 0;
    
      /** \brief Creates a gMonth Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonth]
       *
       * @param aMonth short representation of the gMonth.
       * @return The gMonth Item.
       */
      virtual Item
      createGMonth ( short& aMonth ) = 0;
    
      /** \brief Creates a gMonth Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonth]
       *
       * @param aValue String representation of the gMonth.
       * @return The gMonth Item
       */
      virtual Item
      createGMonth ( const String& aValue ) = 0;
    
      /** \brief Creates a gMonthDay Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonthDay]
       *
       * @param aValue String representation of the gMonthDay.
       * @return The gMonthDay Item
       */
      virtual Item
      createGMonthDay ( const String& aValue ) = 0;
    
      /** \brief Creates a gMonthDay Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonthDay]
       *
       * @param aMonth short representation of the month.
       * @param aDay short representation of the day.
       * @return The gMonthDay Item
       */
      virtual Item
      createGMonthDay ( short month, short day ) = 0;
    
      /** \brief Creates a gYear Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gYear]
       *
       * @param aValue String representation of the gYear.
       * @return The gYear Item
       */
      virtual Item
      createGYear ( const String& value ) = 0;
    
      /** \brief Creates a gYear Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gYear]
       *
       * @param aYear short representation of the gYear.
       * @return The gYear Item
       */
      virtual Item
      createGYear ( short year ) = 0;
    
      /** \brief Creates a gYearMonth Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gYearMonth]
       *
       * @param aValue String representation of the gYearMonth.
       * @return The gYearMonth Item
       */
      virtual Item
      createGYearMonth ( const String& value ) = 0;
    
      /** \brief Creates a gYearMonth Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#gYearMonth]
       *
       * @param aYear short representation of the year.
       * @param aMonth short representation of the month.
       * @return The gYearMonth Item
       */
      virtual Item
      createGYearMonth ( short year, short month ) = 0;
    
      /** \brief Creates a HexBinary Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#hexBinary]
       *
       * @param aHexData pointer to the hexdata.
       * @param aSize size of the hexdata.
       * @return The HexBinary Item
       */
      virtual Item
      createHexBinary ( const char* aHexData, size_t aSize ) = 0;
    
      /** \brief Creates an ID Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#ID]
       *
       * @param aValue String representation of the ID.
       * @return The ID Item
       */
      virtual Item
      createID ( const String& aValue ) = 0;
    
      /** \brief Creates an IDREF  Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#IDREF]
       *
       * @param aValue String representation of the IDREF.
       * @return The IDREF Item
       */
      virtual Item
      createIDREF ( const String& aValue ) = 0;
    
      /** \brief Creates a IDREFS Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#IDREFS]
       *
       * @param aValue String representation of the IDREFS.
       * @return The IDREFS Item
       */
      virtual Item
      createIDREFS ( const String& aValue ) = 0;
    
      /** \brief Creates a Lanugage Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#language]
       *
       * @param aValue String representation of the language.
       * @return The Language Item
       */
      virtual Item
      createLanguage ( const String& aValue ) = 0;
    
      /** \brief Creates a NMToken Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#NMToken]
       *
       * @param aValue String representation of the NMToken.
       * @return The NMToken Item
       */
      virtual Item
      createNMTOKEN ( const String& aValue ) = 0;
    
      /** \brief Creates a NMTokens Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#NMTokens]
       *
       * @param aValue String representation of the NMTokens.
       * @return The NMTokens Item
       */
      virtual Item
      createNMTOKENS ( const String& aValue ) = 0;
    
      /** \brief Creates a Notation Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#NOTATION]
       *
       * @param aValue String representation of the NCName
       * @return The Notation Item
       */
      virtual Item
      createNOTATION ( const String& aValue ) = 0;
    
      /** \brief Creates a Name Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#Name]
       *
       * @param aValue String representation of the Name.
       * @return The Name Item
       */
      virtual Item
      createName ( const String& aValue ) = 0;
    
      /** \brief Creates a negativeInteger Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#negativeInteger]
       *
       * @param aValue String representation of the negativeInteger.
       * @return The negativeInteger Item
       */
      virtual Item
      createNegativeInteger ( const String& aValue ) = 0;
    
      /** \brief Creates a negativeInteger Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#negativeInteger]
       *
       * @param aValue long representation of the negativeInteger.
       * @return The negativeInteger Item
       */
      virtual Item
      createNegativeInteger ( long aValue ) = 0;

      /** \brief Creates a nonNegativeInteger Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#nonNegativeInteger]
       *
       * @param aValue String representation of the nonNegativeInteger.
       * @return The nonNegativeInteger Item
       */
      virtual Item
      createNonNegativeInteger ( const String& aValue ) = 0;
    
      /** \brief Creates a nonNegativeInteger Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#nonNegativeInteger]
       *
       * @param aValue unsigned long representation of the nonNegativeInteger.
       * @return The nonNegativeInteger Item
       */
      virtual Item
      createNonNegativeInteger ( unsigned long aValue ) = 0;

      /** \brief Creates a nonPositiveInteger Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#nonPositiveInteger]
       *
       * @param aValue String representation of the NCName
       * @return The nonPositiveInteger Item
       */
      virtual Item
      createNonPositiveInteger ( const String& aValue ) = 0;
    
      /** \brief Creates a nonPositiveInteger Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#nonPositiveInteger]
       *
       * @param aValue long representation of the NCName
       * @return The nonPositiveInteger Item
       */
      virtual Item
      createNonPositiveInteger ( long aValue ) = 0;

      /** \brief Creates a normalizedString Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#normalizedString]
       *
       * @param aValue String representation of the normalized string.
       * @return The normalizedString Item
       */
      virtual Item
      createNormalizedString ( const String& aValue ) = 0;
    
      /** \brief Creates a positiveInteger\ Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#positiveInteger]
       *
       * @param aValue String representation of the positiveInteger.
       * @return The positiveInteger Item
       */
      virtual Item
      createPositiveInteger ( const String& aValue ) = 0;
    
      /** \brief Creates a positiveInteger\ Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#positiveInteger]
       *
       * @param aValue unsigned long representation of the positiveInteger.
       * @return The positiveInteger Item
       */
      virtual Item
      createPositiveInteger ( unsigned long aValue ) = 0;

      /** \brief Creates a Time Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#time]
       *
       * @param aValue String representation of the Time.
       * @return The Time Item
       */
      virtual Item
      createTime ( const String& aValue ) = 0;
    
      /** \brief Creates a Time Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#time]
       *
       * @param aHour short representation of the hour.
       * @param aMinute short representation of the minute.
       * @param aSecond short representation of the second.
       * @return The Time Item
       */
      virtual Item
      createTime ( short aHour, short aMinute, short aSecond ) = 0;
    
      /** \brief Creates a Time Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#time]
       *
       * @param aHour short representation of the hour.
       * @param aMinute short representation of the minute.
       * @param aSecond short representation of the second.
       * @param aTimezone short representation of the timezone difference in hours to UTC.
       * @return The Time Item
       */
      virtual Item
      createTime ( short aHour, short aMinute, short aSecond, short aTimezone ) = 0;
    
      /** \brief Creates a Token Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#token]
       *
       * @param aValue String representation of the token.
       * @return The Token Item
       */
      virtual Item
      createToken ( const String& aValue ) = 0;
    
      /** \brief Creates an Unsigned Byte Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedByte]
       *
       * @param aValue unsignedByte char representation of the unsigned byte
       * @return The Unsigned Byte Item
       */
      virtual Item
      createUnsignedByte(const char aValue) = 0;
    
      /** \brief Creates an unsigned int Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedInt]
       *
       * @param aValue unsigned int representation of the unsignedInt.
       * @return The unsignedInt Item
       */
      virtual Item
      createUnsignedInt(unsigned int aValue) = 0;
    
      /** \brief Creates an unsignedLong Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedLong]
       *
       * @param aValue unsignedLong long representation of the unsignedLong.
       * @return The unsignedLong Item
       */
      virtual Item
      createUnsignedLong(unsigned long aValue) = 0;
    
      /** \brief Creates a unsignedShort Item 
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedShort]
       *
       * @param aValue unsigned short representation of the unsignedShort.
       * @return The unsignedShort Item
       */
      virtual Item
      createUnsignedShort(unsigned short aValue) = 0;
    
    
  }; /* class ItemFactory */

} /* namespace zorba */
#endif
