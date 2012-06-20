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

#ifndef API_ITEM_FACTORY_H
#define API_ITEM_FACTORY_H

  /** \brief ItemFactory to create Items.
   *
   * An instance of this class can be obtained by calling getItemFactory on the Zorba object.
   *
   * Each createXXX function of this class creates an Item of an XML Schema item.
   * If an isNull() call on an Item created by one of these functions returns true the
   * Item could not be created.
   */
class ItemFactory
{

  private:
    zorba::ItemFactory* theItemFactory;
  public:
    ItemFactory(zorba::ItemFactory* aItemFactory) : theItemFactory(aItemFactory) {}
    ItemFactory(const ItemFactory& aItemFactory) : theItemFactory(aItemFactory.theItemFactory) {}

      /** \brief Creates an AnyURI Item
       *         see [http://www.w3.org/TR/xmlschema-2/#anyURI]
       *
       * @param aURI String representation of the AnyURI.
       * @return The AnyURI Item.
       */
    Item 	createAnyURI (const std::string &aURI);

      /**
      * Create a new attribute node N and place it among the
      * attributes of a given parent node. If no parent is given, N becomes the
      * root (and single node) of a new XML tree.
      *
      * @param aParent     The parent P of the new node; may be NULL.
      * @param aNodeName   The fully qualified name of the new node. The nemaspace
      *                    binding implied by this name will be added to the namespaces
      *                    of P. If the name prefix is "xml" and the local name is
      *                    "base", then the base-uri property of P will be set or
      *                    updated accordingly.
      * @param aTypeName   The fully qualified name of the new node's type.
      * @param aTypedValue The typed value of the new node.
      * @return            The new node N created by this method
      */
    Item 	createAttributeNode (Item& aParent, Item& aNodeName, Item& aTypeName, Item& aTypedValue);
#ifndef SWIGRUBY
    Item 	createAttributeNode (Item& aParent, Item& aNodeName, Item& aTypeName, std::vector< Item > aTypedValue);
#endif

      /** \brief Creates a Base64Binary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#base64Binary]
       *
       * @param aBinData a pointer to the base64 binary data.
       * @param aLength the length of the base64 binary data.
       * @return The Base64Binary Item.
       */
    Item 	createBase64Binary (const char *aBinData, size_t aLength);

      /** \brief Creates a Base64Binary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#base64Binary]
       *
       * @param aStream A stream containing the Base64 encoded data.
       * @return the Base64Binary Item.
       */
    Item 	createBase64Binary (std::istream &aStream);

      /** \brief Creates a Base64Binary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#base64Binary]
       *
       * @param aBinData the data in binary form. The data is copied from aBinData.
       * @param aLength the length of the data
       * @return the Base64Binary Item.
       */
    Item 	createBase64Binary (const unsigned char *aBinData, size_t aLength);

      /** \brief Creates a Boolean Item
       *         see [http://www.w3.org/TR/xmlschema-2/#bool]
       *
       * @param aValue bool representation of the Boolean.
       * @return The Boolean Item.
       */
    Item 	createBoolean (bool aValue);

      /** \brief Creates a Byte Item
       *         see [http://www.w3.org/TR/xmlschema-2/#byte]
       *
       * @param aByte char representation of the Byte.
       * @return The Byte Item.
       */
    Item 	createByte (char aByte);

      /**
       * Create a new comment node N and place it as the last child of a given
       * parent node. If no parent is given, N becomes the root (and single node)
       * of a new XML tree.
       *
       * @param aParent  The parent P of the new node; may be NULL.
       * @param aContent The content of the new node.
       * @return        The new node N created by this method
       */
    Item 	createCommentNode (Item &aParent, const std::string &aContent);

      /** \brief Creates a Date Item
       *         see [http://www.w3.org/TR/xmlschema-2/#date]
       *
       * @param aDate String representation of the Date (e.g. 2002-10-10).
       * @return The Date Item.
       */
    Item 	createDate (const std::string &aDate);

      /** \brief Creates a Date Item
       *         see [http://www.w3.org/TR/xmlschema-2/#date]
       *
       * @param aYear short-valued representation of the year.
       * @param aMonth short-valued representation of the month.
       * @param aDay short-valued representation of the day.
       * @return The Date Item.
       */
    Item 	createDate (short aYear, short aMonth, short aDay);

      /** \brief Creates a DateTime Item
       *         see [http://www.w3.org/TR/xmlschema-2/#dateTime]
       *
       * @param aDateTimeValue String representation of the datetime value
       *        (for example, 2002-10-10T12:00:00-05:00).
       * @return The DateTime Item.
       */
    Item 	createDateTime (const std::string &aDateTimeValue);

      /** \brief Creates a DateTime Item
       *         see [http://www.w3.org/TR/xmlschema-2/#dateTime]
       *
       * @param aYear short-valued representation of the year.
       * @param aMonth short-valued representation of the month.
       * @param aDay short-valued representation of the day.
       * @param aHour short-valued representation of the hour.
       * @param aMinute short-valued representation of the minute.
       * @param aSecond double-valued representation of the seconds and fractional seconds.
       * @param aTimeZone_hours short-valued representation of the difference in hours to UTC.
       * @return The DateTime Item.
       */
    Item 	createDateTime (short aYear, short aMonth, short aDay, short aHour, short aMinute, double aSecond, short aTimeZone_hours);

      /** \brief Creates a Decimal Item
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue String representation of the Decimal (e.g. 12678967.543233).
       * @return The Decimal Item.
       */
    Item 	createDecimal (const std::string &aValue);

      /** \brief Creates a Decimal Item
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue double representation of the Decimal.
       * @return The Decimal Item.
       */
    Item 	createDecimalFromDouble (double aValue);

      /** \brief Creates a Decimal Item
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue unsigned long representation of the Decimal.
       * @return The Decimal Item.
       */
    Item 	createDecimalFromLong (unsigned long aValue);

      /** \brief Creates a Double Item
       *         see [http://www.w3.org/TR/xmlschema-2/#double]
       *
       * @param aValue String representation of the Double.
       * @return The Double Item.
       */
    Item 	createDouble (const std::string &aValue);

      /** \brief Creates a Double Item
       *         see [http://www.w3.org/TR/xmlschema-2/#double]
       *
       * @param aValue double representation of the Double.
       * @return The Double Item.
       */
    Item 	createDouble (double aValue);

      /** \brief Creates a Duration Item
       *         see [http://www.w3.org/TR/xmlschema-2/#duration]
       *
       * @param aValue String representation of the NCName.
       * @return The Duration Item.
       */
    Item 	createDuration (const std::string &aValue);

      /** \brief Creates a Duration Item
       *         see [http://www.w3.org/TR/xmlschema-2/#duration]
       *
       * @param aYear short-valued representation of the years.
       * @param aMonths short-valued representation of the months.
       * @param aDays short-valued representation of the days.
       * @param aHours short-valued representation of the hours.
       * @param aMinutes short-valued representation of the minutes.
       * @param aSeconds double-valued representation of the seconds and fractional seconds.
       * @return The Duration Item.
       */
    Item 	createDuration (short aYear, short aMonths, short aDays, short aHours, short aMinutes, double aSeconds);

      /** \brief Creates a dayTimeDuration Item
       *         see [http://www.w3.org/TR/xpath-functions/#duration-subtypes]
       *
       * @param aValue String lexical representation of the duration.
       * @return the dayTimeDuration Item.
       */
    Item 	createDayTimeDuration (const std::string &aValue);

      /** \brief Creates a yearMonthDuration Item
       *         see [http://www.w3.org/TR/xpath-functions/#duration-subtypes]
       *
       * @param aValue String lexical representation of the duration.
       * @return the yearMonthDuration Item.
       */
    Item 	createYearMonthDuration (const std::string &aValue);

      /** \brief Creates a documentNode Item
       *         see [http://www.w3.org/TR/xpath-functions/#duration-subtypes]
       *
       * @param aBaseUri String representation of the Base URI.
       * @param aDocUri String representation of the Document URI.
       * @return the documentNode Item.
       */
    Item 	createDocumentNode (const std::string &aBaseUri, const std::string &aDocUri);
#ifndef SWIGRUBY
      /**
      * @brief Creates a new element node.
      *
      * Create a new element node N and place it at the  end among the
      * children of a given parent node. If no parent is given, N becomes the
      * root (and single node) of a new XML tree.
      *
      * @param aParent        The parent P of the new node; may be NULL.
      * @param aNodeName      The fully qualified name of the new node.
      * @param aTypeName      The fully qualified name of the new node's type.
      *                       Not allowed to be NULL, use xsd:untyped instead.
      * @param aHasTypedValue Whether the node has a typed value or not (element
      *                       nodes with complex type and element-only content do
      *                       not have typed value).
      * @param aHasEmptyValue True if the typed value of the node is the empty
      *                       sequence. This is the case if the element has a
      *                       complex type with empty content.
      * @param aNsBindings    A set of namespace bindings. The namespaces property
      *                       of N will be the union of this set and the namespaces
      *                       property of P.
      * @return               The new node N created by this method
      */
    Item 	createElementNode (Item &aParent, Item &aNodeName, Item &aTypeName, bool aHasTypedValue, bool aHasEmptyValue, std::vector< std::pair< std::string, std::string > > aNsBindings);
#endif

      /**
      * @brief Creates a new element node.
      *
      * Create a new element node N and place it at the  end among the
      * children of a given parent node. If no parent is given, N becomes the
      * root (and single node) of a new XML tree.
      *
      * @param aParent        The parent P of the new node; may be NULL.
      * @param aNodeName      The fully qualified name of the new node.
      * @param aTypeName      The fully qualified name of the new node's type.
      *                       Not allowed to be NULL, use xsd:untyped instead.
      * @param aHasTypedValue Whether the node has a typed value or not (element
      *                       nodes with complex type and element-only content do
      *                       not have typed value).
      * @param aHasEmptyValue True if the typed value of the node is the empty
      *                       sequence. This is the case if the element has a
      *                       complex type with empty content.
      * @return               The new node N created by this method
      */
    Item 	createElementNode (Item &aParent, Item &aNodeName, Item &aTypeName, bool aHasTypedValue, bool aHasEmptyValue);

      /** \brief creates a float item
       *         see [http://www.w3.org/tr/xmlschema-2/#float]
       *
       * @param aValue string representation of the float.
       * @return the float item.
       */
    Item 	createFloat (const std::string &aValue);

      /** \brief creates a float item
       *         see [http://www.w3.org/tr/xmlschema-2/#float]
       *
       * @param aValue float representation of the float.
       * @return the float item.
       */
    Item 	createFloat (float aValue);

      /** \brief Creates a gDay Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gDay]
       *
       * @param aValue String representation of the gDay.
       * @return The gDay Item.
       */
    Item 	createGDay (const std::string &aValue);

      /** \brief Creates a gDay Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gDay]
       *
       * @param aDay short representation of the gDay.
       * @return The gDay Item.
       */
    Item 	createGDay (short aDay);

      /** \brief Creates a gMonth Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonth]
       *
       * @param aValue String representation of the gMonth.
       * @return The gMonth Item.
       */
    Item 	createGMonth (const std::string &aValue);

      /** \brief Creates a gMonth Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonth]
       *
       * @param aMonth short representation of the gMonth.
       * @return The gMonth Item.
       */
    Item 	createGMonth (short aMonth);

      /** \brief Creates a gMonthDay Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonthDay]
       *
       * @param aValue String representation of the gMonthDay.
       * @return The gMonthDay Item.
       */
    Item 	createGMonthDay (const std::string &aValue);

      /** \brief Creates a gMonthDay Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonthDay]
       *
       * @param aMonth short representation of the month.
       * @param aDay short representation of the day.
       * @return The gMonthDay Item.
       */
    Item 	createGMonthDay (short aMonth, short aDay);

      /** \brief Creates a gYear Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gYear]
       *
       * @param aYear short representation of the gYear.
       * @return The gYear Item.
       */
    Item 	createGYear (short aYear);

      /** \brief Creates a gYear Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gYear]
       *
       * @param aValue String representation of the gYear.
       * @return The gYear Item.
       */
    Item 	createGYear (const std::string &aValue);

      /** \brief Creates a gYearMonth Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gYearMonth]
       *
       * @param aValue String representation of the gYearMonth.
       * @return The gYearMonth Item.
       */
    Item 	createGYearMonth (const std::string &aValue);

      /** \brief Creates a gYearMonth Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gYearMonth]
       *
       * @param aYear short representation of the year.
       * @param aMonth short representation of the month.
       * @return The gYearMonth Item.
       */
    Item 	createGYearMonth (short aYear, short aMonth);

      /** \brief Creates a HexBinary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#hexBinary]
       *
       * @param aHexData pointer to the hexdata.
       * @param aSize size of the hexdata.
       * @return The HexBinary Item.
       */
    Item 	createHexBinary (const char *aHexData, size_t aSize);

      /** \brief Creates a Int Item
       *         see [http://www.w3.org/TR/xmlschema-2/#int]
       *
       * @param aInt int representation of the Int.
       * @return The NCName Item.
       */
    Item 	createInt (int aInt);

      /** \brief Creates an Integer Item
       *         see [http://www.w3.org/TR/xmlschema-2/#integer]
       *
       * @param aInteger String representation of the Integer.
       * @return The Integer Item.
       */
    Item 	createInteger (const std::string &aInteger);

      /** \brief Creates an Integer Item
       *         see [http://www.w3.org/TR/xmlschema-2/#integer]
       *
       * @param aInteger unsigned long representation of the Integer.
       * @return The Integer Item.
       */
    Item 	createInteger (long long aInteger);

      /** \brief Creates a Long Item
       *         see [http://www.w3.org/TR/xmlschema-2/#long]
       *
       * @param aLong long long representation of the Long.
       * @return The Long Item.
       */
    Item 	createLong (long long aLong);

      /** \brief Creates a NCName Item
       *         see [http://www.w3.org/TR/xmlschema-2/#NCName]
       *
       * @param aValue String representation of the NCName.
       * @return The NCName Item.
       */
    Item 	createNCName (const std::string &aValue);

      /** \brief Creates a negativeInteger Item
       *         see [http://www.w3.org/TR/xmlschema-2/#negativeInteger]
       *
       * @param aValue long long representation of the negativeInteger.
       * @return The negativeInteger Item.
       */
    Item 	createNegativeInteger (long long aValue);

      /** \brief Creates a nonNegativeInteger Item
       *         see [http://www.w3.org/TR/xmlschema-2/#nonNegativeInteger]
       *
       * @param aValue unsigned long representation of the nonNegativeInteger.
       * @return The nonNegativeInteger Item.
       */
    Item 	createNonNegativeInteger (unsigned long long aValue);

      /** \brief Creates a nonPositiveInteger Item
       *         see [http://www.w3.org/TR/xmlschema-2/#nonPositiveInteger]
       *
       * @param aValue long long representation of the NCName.
       * @return The nonPositiveInteger Item.
       */
    Item 	createNonPositiveInteger (long long aValue);

      /**
      * Create a new Processing Instruction node N and place it among the
      * children of a given parent node. If no parent is given, N becomes the
      * root (and single node) of a new XML tree.
      *
      * @param aParent  The parent P of the new node; may be NULL.
      * @param aTarget  The Target of the new node.
      * @param aContent The Content of the new node.
      * @param aBaseUri The Base URI of the new node, may be NULL.
      * @return         The new node N created by this method
      */
    Item 	createPiNode (Item &aParent, const std::string &aTarget, const std::string &aContent, const std::string &aBaseUri);

      /** \brief Creates a positiveInteger\ Item
       *         see [http://www.w3.org/TR/xmlschema-2/#positiveInteger]
       *
       * @param aValue unsigned long representation of the positiveInteger.
       * @return The positiveInteger Item.
       */
    Item 	createPositiveInteger (unsigned long long aValue);

    /** \brief Creates a QName Item
       *         see [http://www.w3.org/TR/xmlschema-2/#QName]
       *
       * @param aNamespace String representation of the namespace.
       * @param aPrefix String representation of the prefix.
       * @param aLocalname String representation of the localname.
       *
       * @return The QName Item.
       */
    Item 	createQName (const std::string &aNamespace, const std::string &aPrefix, const std::string &aLocalname);

      /** \brief Creates a QName Item
       *         see [http://www.w3.org/TR/xmlschema-2/#QName]
       *
       * @param aNamespace String representation of the namespace.
       * @param aLocalname String representation of the localname.       *
       * @return The QName Item.
       */
    Item 	createQName (const std::string &aNamespace, const std::string &aLocalname);

      /** \brief Creates a QName Item
       *         see [http://www.w3.org/TR/xmlschema-2/#QName]
       *
       * The QName is constructed by parsing the string using the notation
       * invented by James Clark (i.e. {namespace}localname).
       *
       * @param aQNameString String in the QName notation by James Clark.
       * @return The QName Item.
       */
    Item 	createQName (const std::string &aQNameString);

      /** \brief Creates a Short Item
       *         see [http://www.w3.org/TR/xmlschema-2/#short]
       *
       * @param aShort short representation of the Short.
       * @return The Short Item.
       */
    Item 	createShort (short aShort);
    //Item 	createStreamableString (std::istream &stream, StreamReleaser streamReleaser, bool seekable=false);

      /** \brief Creates a String Item
       *         see [http://www.w3.org/TR/xmlschema-2/#string]
       *
       * @param aString String representation of the String Item.
       * @return The String Item
       */
    Item 	createString (const std::string &aString);

      /**
      * Create a new text node N and place it among the
      * children of a given parent node. If no parent is given, N becomes the
      * root (and single node) of a new XML tree.
      *
      * @param aParent  The parent P of the new node; may be NULL.
      * @param aContent The content of the new node.
      * @return        The new node N created by this method
      */
    Item 	createTextNode (Item &aParent, const std::string &aContent);

      /** \brief Creates a Time Item
       *         see [http://www.w3.org/TR/xmlschema-2/#time]
       *
       * @param aHour short representation of the hour.
       * @param aMinute short representation of the minute.
       * @param aSecond double representation of the seconds and fractional seconds.
       * @param aTimeZone_hours short representation of the timezone difference in hours to UTC.
       * @return The Time Item.
       */
    Item 	createTime (short aHour, short aMinute, double aSecond, short aTimeZone_hours);

      /** \brief Creates a Time Item
       *         see [http://www.w3.org/TR/xmlschema-2/#time]
       *
       * @param aHour short representation of the hour.
       * @param aMinute short representation of the minute.
       * @param aSecond double representation of the seconds and fractional seconds.
       * @return The Time Item.
       */
    Item 	createTime (short aHour, short aMinute, double aSecond);

      /** \brief Creates a Time Item
       *         see [http://www.w3.org/TR/xmlschema-2/#time]
       *
       * @param aValue String representation of the Time.
       * @return The Time Item
       */
    Item 	createTime (const std::string &aValue);

      /** \brief Creates an Unsigned Byte Item
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedByte]
       *
       * @param aValue unsignedByte unsigned char representation of the unsigned byte.
       * @return The Unsigned Byte Item.
       */
    Item 	createUnsignedByte (const unsigned char aValue);

      /** \brief Creates an unsigned int Item
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedInt]
       *
       * @param aValue unsigned int representation of the unsignedInt.
       * @return The unsignedInt Item.
       */
    Item 	createUnsignedInt (unsigned int aValue);

      /** \brief Creates an unsignedLong Item
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedLong]
       *
       * @param aValue unsignedLong long long representation of the unsignedLong.
       * @return The unsignedLong Item.
       */
    Item 	createUnsignedLong (unsigned long long aValue);

      /** \brief Creates a unsignedShort Item
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedShort]
       *
       * @param aValue unsigned short representation of the unsignedShort.
       * @return The unsignedShort Item.
       */
    Item 	createUnsignedShort (unsigned short aValue);
}; // class ItemFactory

#endif