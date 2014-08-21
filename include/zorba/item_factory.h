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

#ifndef ZORBA_ITEM_FACTORY_API_H
#define ZORBA_ITEM_FACTORY_API_H

#include <iostream>
#include <vector>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include <zorba/streams.h>

namespace zorba {

  /** \brief ItemFactory to create Items.
   *
   * An instance of this class can be obtained by calling getItemFactory on the Zorba object.
   *
   * Each createXXX function of this class creates an Item of an XML Schema item.
   * If an isNull() call on an Item created by one of these functions returns true the
   * Item could not be created.
   */
  class ZORBA_DLL_PUBLIC ItemFactory
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

      /** \brief Creates a streamable String Item
       *         see [http://www.w3.org/TR/xmlschema-2/#string]
       *
       * @param stream An istream from where to read the string's content.
       * @param streamReleaser A function pointer which is invoked once
       *        the StreamableStringItem is destroyed. Normally this function
       *        will delete the std::istream object passed to it.
       * @param seekable
       * @return The streamable String Item
       */
      virtual Item
      createStreamableString( std::istream &stream,
                              StreamReleaser streamReleaser,
                              bool seekable = false ) = 0;

      /** \brief Creates a streamable String Item
       *         see [http://www.w3.org/TR/xmlschema-2/#string]
       *
       * @param stream An istream from where to read the string's content.
       * @param streamReleaser A function pointer which is invoked once
       *        the StreamableStringItem is destroyed. Normally this function
       *        will delete the std::istream object passed to it.
       * @param uri The URI is intended to be used to note the origination URI
       *        (e.g., file) that data is coming from.
       * @param seekable
       * @return The streamable String Item
       */
      virtual Item
      createStreamableString( std::istream &stream,
                              StreamReleaser streamReleaser,
                              char const *uri,
                              bool seekable = false ) = 0;

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
       * @param aLocalname String representation of the localname.       *
       * @return The QName Item.
       */
      virtual Item
      createQName(const String& aNamespace, const String& aLocalname) = 0;

      /** \brief Creates a QName Item
       *         see [http://www.w3.org/TR/xmlschema-2/#QName]
       *
       * The QName is constructed by parsing the string using the notation
       * invented by James Clark (i.e. {namespace}localname).
       *
       * @param aQNameString String in the QName notation by James Clark.
       * @return The QName Item.
       */
      virtual Item
      createQName(const String& aQNameString) = 0;

      /** \brief Creates a NCName Item
       *         see [http://www.w3.org/TR/xmlschema-2/#NCName]
       *
       * @param aValue String representation of the NCName.
       * @return The NCName Item.
       */
      virtual Item
      createNCName(const String& aValue) = 0;


      /** \brief Creates a Base64Binary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#base64Binary]
       *
       * @param aData a pointer to the data.
       * @param aLength the length of the data (in bytes).
       * @param aIsBase64 If \c true, \a aData is already Base-64 encoded; if
       * \c false, \a aData is binary data that will first be Base-64 encoded.
       * @return The Base64Binary Item.
       */
      virtual Item
      createBase64Binary(const char* aData, size_t aLength, bool aIsBase64) = 0;

      /** \brief Creates a Base64Binary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#base64Binary]
       *
       * @param aStream A stream containing the Base64 encoded data.
       * The data is copied from aStream immediately.
       * @return the Base64Binary Item.
       */
      virtual Item
      createBase64Binary(std::istream& aStream) = 0;

      /** \brief Creates a streamable Base64Binary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#base64Binary]
       *
       * @param stream An istream from where to read the binary's content.
       * @param streamReleaser A function pointer which is invoked once
       *        the StreamableBase64Binary is destroyed. Normally this function
       *        will delete the std::istream object passed to it.
       * @param seekable is the given stream seekable
       * @param encoded is the contents of the given stream already base64
       *        encoded
       * @return The streamable String Item
       */
      virtual Item
      createStreamableBase64Binary(
          std::istream &stream,
          StreamReleaser streamReleaser,
          bool seekable = false,
          bool encoded = false) = 0;

      /** \brief Creates a streamable Base64Binary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#base64Binary]
       *
       * @param stream An istream from where to read the binary's content.
       * @param streamReleaser A function pointer which is invoked once
       *        the StreamableBase64Binary is destroyed. Normally this function
       *        will delete the std::istream object passed to it.
       * @param uri The URI is intended to be used to note the origination URI
       *        (e.g., file) that data is coming from.
       * @param seekable is the given stream seekable
       * @param encoded is the contents of the given stream already base64
       *        encoded
       * @return The streamable String Item
       */
      virtual Item
      createStreamableBase64Binary(
          std::istream &stream,
          StreamReleaser streamReleaser,
          char const *uri,
          bool seekable = false,
          bool encoded = false) = 0;

      /** \brief Creates a Boolean Item
       *         see [http://www.w3.org/TR/xmlschema-2/#bool]
       *
       * @param aValue bool representation of the Boolean.
       * @return The Boolean Item.
       */
      virtual Item
      createBoolean(bool aValue) = 0;

      /** \brief Creates a Decimal Item
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue unsigned long representation of the Decimal.
       * @return The Decimal Item.
       */
      virtual Item
      createDecimalFromLong (unsigned long aValue) = 0;

      /** \brief Creates a Decimal Item
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue double representation of the Decimal.
       * @return The Decimal Item.
       */
      virtual Item
      createDecimalFromDouble (double aValue) = 0;

      /** \brief Creates a Decimal Item
       *         see [http://www.w3.org/TR/xmlschema-2/#decimal]
       *
       * @param aValue String representation of the Decimal (e.g. 12678967.543233).
       * @return The Decimal Item.
       */
      virtual Item
      createDecimal (const String& aValue) = 0;

      /** \brief Creates an Integer Item
       *         see [http://www.w3.org/TR/xmlschema-2/#integer]
       *
       * @param aInteger unsigned long representation of the Integer.
       * @return The Integer Item.
       */
      virtual Item
      createInteger(long long aInteger) = 0;

      /** \brief Creates an Integer Item
       *         see [http://www.w3.org/TR/xmlschema-2/#integer]
       *
       * @param aInteger String representation of the Integer.
       * @return The Integer Item.
       */
      virtual Item
      createInteger(const String& aInteger) = 0;

      /** \brief Creates a Long Item
       *         see [http://www.w3.org/TR/xmlschema-2/#long]
       *
       * @param aLong long long representation of the Long.
       * @return The Long Item.
       */
      virtual Item
      createLong ( long long aLong ) = 0;

      /** \brief Creates a Int Item
       *         see [http://www.w3.org/TR/xmlschema-2/#int]
       *
       * @param aInt int representation of the Int.
       * @return The NCName Item.
       */
      virtual Item
      createInt ( int aInt ) = 0;

      /** \brief Creates a Short Item
       *         see [http://www.w3.org/TR/xmlschema-2/#short]
       *
       * @param aShort short representation of the Short.
       * @return The Short Item.
       */
      virtual Item
      createShort ( short aShort ) = 0;

      /** \brief Creates a Byte Item
       *         see [http://www.w3.org/TR/xmlschema-2/#byte]
       *
       * @param aByte char representation of the Byte.
       * @return The Byte Item.
       */
      virtual Item
      createByte ( char aByte ) = 0;

      /** \brief Creates a Date Item
       *         see [http://www.w3.org/TR/xmlschema-2/#date]
       *
       * @param aDate String representation of the Date (e.g. 2002-10-10).
       * @return The Date Item.
       */
      virtual Item
      createDate ( const String& aDate ) = 0;

      /** \brief Creates a Date Item
       *         see [http://www.w3.org/TR/xmlschema-2/#date]
       *
       * @param aYear short-valued representation of the year.
       * @param aMonth short-valued representation of the month.
       * @param aDay short-valued representation of the day.
       * @return The Date Item.
       */
      virtual Item
      createDate ( short aYear, short aMonth, short aDay ) = 0;

      /** \brief Creates a DateTime Item
       *         see [http://www.w3.org/TR/xmlschema-2/#dateTime]
       *
       * @param aYear the year.
       * @param aMonth the month [1-12].
       * @param aDay the day [1-31].
       * @param aHour the hour [0-23].
       * @param aMinute the minute [0-59].
       * @param aSecond the seconds and fractional seconds.
       * @param aTimeZone the number of seconds east of the prime meridian.
       * @return The DateTime Item.
       */
      virtual Item
      createDateTime(short aYear, short aMonth, short aDay,
                     short aHour, short aMinute, double aSecond,
                     int aTimeZone) = 0;

      /** \brief Creates a DateTime Item without setting a time zone.
       *         see [http://www.w3.org/TR/xmlschema-2/#dateTime]
       *
       * @param aYear the year.
       * @param aMonth the month [1-12].
       * @param aDay the day [1-31].
       * @param aHour the hour [0-23].
       * @param aMinute the minute [0-59].
       * @param aSecond the seconds and fractional seconds.
       * @return The DateTime Item.
       */
      virtual Item
      createDateTime(short aYear, short aMonth, short aDay,
                     short aHour, short aMinute, double aSecond) = 0;

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
       * @return The Double Item.
       */
      virtual Item
      createDouble ( double aValue ) = 0;

      /** \brief Creates a Double Item
       *         see [http://www.w3.org/TR/xmlschema-2/#double]
       *
       * @param aValue String representation of the Double.
       * @return The Double Item.
       */
      virtual Item
      createDouble ( const String& aValue ) = 0;

      /** \brief Creates a Duration Item
       *         see [http://www.w3.org/TR/xmlschema-2/#duration]
       *
       * @param aValue String representation of the NCName.
       * @return The Duration Item.
       */
      virtual Item
      createDuration( const String& aValue ) = 0;

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
      virtual Item
      createDuration ( short aYear, short aMonths, short aDays,
                       short aHours, short aMinutes, double aSeconds ) = 0;

      /** \brief Creates a dayTimeDuration Item
       *         see [http://www.w3.org/TR/xpath-functions/#duration-subtypes]
       *
       * @param aValue String lexical representation of the duration.
       * @return the dayTimeDuration Item.
       */
      virtual Item
      createDayTimeDuration( const String& aValue ) = 0;

      /** \brief Creates a yearMonthDuration Item
       *         see [http://www.w3.org/TR/xpath-functions/#duration-subtypes]
       *
       * @param aValue String lexical representation of the duration.
       * @return the yearMonthDuration Item.
       */
      virtual Item
      createYearMonthDuration( const String& aValue ) = 0;

      /** \brief Creates a documentNode Item
       *         see [http://www.w3.org/TR/xpath-functions/#duration-subtypes]
       *
       * @param aBaseUri String representation of the Base URI.
       * @param aDocUri String representation of the Document URI.
       * @return the documentNode Item.
       */
      virtual Item
      createDocumentNode( const String& aBaseUri, const String& aDocUri ) = 0;

      /** \brief creates a float item
       *         see [http://www.w3.org/tr/xmlschema-2/#float]
       *
       * @param aValue string representation of the float.
       * @return the float item.
       */
      virtual Item
      createFloat ( const String& aValue ) = 0;

      /** \brief creates a float item
       *         see [http://www.w3.org/tr/xmlschema-2/#float]
       *
       * @param aValue float representation of the float.
       * @return the float item.
       */
      virtual Item
      createFloat ( float aValue ) = 0;

      /** \brief Creates a gDay Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gDay]
       *
       * @param aValue String representation of the gDay.
       * @return The gDay Item.
       */
      virtual Item
      createGDay ( const String& aValue ) = 0;

      /** \brief Creates a gDay Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gDay]
       *
       * @param aDay short representation of the gDay.
       * @return The gDay Item.
       */
      virtual Item
      createGDay ( short aDay ) = 0;

      /** \brief Creates a gMonth Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonth]
       *
       * @param aValue String representation of the gMonth.
       * @return The gMonth Item.
       */
      virtual Item
      createGMonth ( const String& aValue ) = 0;

      /** \brief Creates a gMonth Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonth]
       *
       * @param aMonth short representation of the gMonth.
       * @return The gMonth Item.
       */
      virtual Item
      createGMonth ( short aMonth ) = 0;

      /** \brief Creates a gMonthDay Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonthDay]
       *
       * @param aValue String representation of the gMonthDay.
       * @return The gMonthDay Item.
       */
      virtual Item
      createGMonthDay ( const String& aValue ) = 0;

      /** \brief Creates a gMonthDay Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gMonthDay]
       *
       * @param aMonth short representation of the month.
       * @param aDay short representation of the day.
       * @return The gMonthDay Item.
       */
      virtual Item
      createGMonthDay ( short aMonth, short aDay ) = 0;

      /** \brief Creates a gYear Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gYear]
       *
       * @param aValue String representation of the gYear.
       * @return The gYear Item.
       */
      virtual Item
      createGYear ( const String& aValue ) = 0;

      /** \brief Creates a gYear Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gYear]
       *
       * @param aYear short representation of the gYear.
       * @return The gYear Item.
       */
      virtual Item
      createGYear ( short aYear ) = 0;

      /** \brief Creates a gYearMonth Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gYearMonth]
       *
       * @param aValue String representation of the gYearMonth.
       * @return The gYearMonth Item.
       */
      virtual Item
      createGYearMonth ( const String& aValue ) = 0;

      /** \brief Creates a gYearMonth Item
       *         see [http://www.w3.org/TR/xmlschema-2/#gYearMonth]
       *
       * @param aYear short representation of the year.
       * @param aMonth short representation of the month.
       * @return The gYearMonth Item.
       */
      virtual Item
      createGYearMonth ( short aYear, short aMonth ) = 0;

      /** \brief Creates a HexBinary Item
       *         see [http://www.w3.org/TR/xmlschema-2/#hexBinary]
       *
       * @param aData pointer to the data.
       * @param aSize size of the data in bytes.
       * @param aIsEncoded if \c true, the \a aData is already HexBinary
       * encoded.
       * @return The HexBinary Item.
       */
      virtual Item
      createHexBinary( const char* aData, size_t aSize,
                       bool aIsEncoded = true ) = 0;

      /** \brief Creates a negativeInteger Item
       *         see [http://www.w3.org/TR/xmlschema-2/#negativeInteger]
       *
       * @param aValue long long representation of the negativeInteger.
       * @return The negativeInteger Item.
       */
      virtual Item
      createNegativeInteger ( long long aValue ) = 0;

      /** \brief Creates a nonNegativeInteger Item
       *         see [http://www.w3.org/TR/xmlschema-2/#nonNegativeInteger]
       *
       * @param aValue unsigned long representation of the nonNegativeInteger.
       * @return The nonNegativeInteger Item.
       */
      virtual Item
      createNonNegativeInteger ( unsigned long long aValue ) = 0;

      /** \brief Creates a nonPositiveInteger Item
       *         see [http://www.w3.org/TR/xmlschema-2/#nonPositiveInteger]
       *
       * @param aValue long long representation of the NCName.
       * @return The nonPositiveInteger Item.
       */
      virtual Item
      createNonPositiveInteger ( long long aValue ) = 0;

      /** \brief Creates a positiveInteger\ Item
       *         see [http://www.w3.org/TR/xmlschema-2/#positiveInteger]
       *
       * @param aValue unsigned long representation of the positiveInteger.
       * @return The positiveInteger Item.
       */
      virtual Item
      createPositiveInteger ( unsigned long long aValue ) = 0;

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
       * @param aSecond double representation of the seconds and fractional seconds.
       * @return The Time Item.
       */
      virtual Item
      createTime ( short aHour, short aMinute, double aSecond ) = 0;

      /** \brief Creates a Time Item
       *         see [http://www.w3.org/TR/xmlschema-2/#time]
       *
       * @param aHour short representation of the hour.
       * @param aMinute short representation of the minute.
       * @param aSecond double representation of the seconds and fractional seconds.
       * @param aTimeZone the number of seconds east of the prime meridian.
       * @return The Time Item.
       */
      virtual Item
      createTime ( short aHour, short aMinute, double aSecond, int aTimeZone ) = 0;

      /** \brief Creates an Unsigned Byte Item
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedByte]
       *
       * @param aValue unsignedByte unsigned char representation of the unsigned byte.
       * @return The Unsigned Byte Item.
       */
      virtual Item
      createUnsignedByte(const unsigned char aValue) = 0;

      /** \brief Creates an unsigned int Item
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedInt]
       *
       * @param aValue unsigned int representation of the unsignedInt.
       * @return The unsignedInt Item.
       */
      virtual Item
      createUnsignedInt(unsigned int aValue) = 0;

      /** \brief Creates an unsignedLong Item
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedLong]
       *
       * @param aValue unsignedLong long long representation of the unsignedLong.
       * @return The unsignedLong Item.
       */
      virtual Item
      createUnsignedLong(unsigned long long aValue) = 0;

      /** \brief Creates a unsignedShort Item
       *         see [http://www.w3.org/TR/xmlschema-2/#unsignedShort]
       *
       * @param aValue unsigned short representation of the unsignedShort.
       * @return The unsignedShort Item.
       */
      virtual Item
      createUnsignedShort(unsigned short aValue) = 0;

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
      virtual Item
      createElementNode(Item& aParent,
                        Item aNodeName,
                        Item aTypeName,
                        bool aHasTypedValue,
                        bool aHasEmptyValue,
                        NsBindings aNsBindings) = 0;
      /**
      * Create a new attribute node N and place it among the
      * attributes of a given parent node. If no parent is given, N becomes the
      * root (and single node) of a new XML tree.
      *
      * @param aParent     The parent P of the new node; may be NULL.
      * @param aNodeName   The fully qualified name of the new node. The namespace
      *                    binding implied by this name will be added to the namespaces
      *                    of P. If the name prefix is "xml" and the local name is
      *                    "base", then the base-uri property of P will be set or
      *                    updated accordingly.
      * @param aTypeName   The fully qualified name of the new node's type.
      * @param aTypedValue The typed value of the new node.
      * @return            The new node N created by this method
      */
      virtual Item
      createAttributeNode(Item aParent,
                          Item aNodeName,
                          Item aTypeName,
                          Item aTypedValue) = 0;

      virtual Item
        createAttributeNode(Item aParent,
        Item aNodeName,
        Item aTypeName,
        std::vector<Item> aTypedValue) = 0;

      /**
       * Create a new comment node N and place it as the last child of a given
       * parent node. If no parent is given, N becomes the root (and single node)
       * of a new XML tree.
       *
       * @param aParent  The parent P of the new node; may be NULL.
       * @param aContent The content of the new node.
       * @return        The new node N created by this method
       */
      virtual Item createCommentNode (
            Item   aParent,
            String &aContent) = 0;

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
      virtual Item createPiNode (
        Item   aParent,
        String &aTarget,
        String &aContent,
        String &aBaseUri)=0;

      /**
      * Create a new text node N and place it among the
      * children of a given parent node. If no parent is given, N becomes the
      * root (and single node) of a new XML tree.
      *
      * @param parent  The parent P of the new node; may be NULL.
      * @param content The content of the new node.
      * @return        The new node N created by this method
      */
      virtual Item createTextNode(
        Item   parent,
        String content) = 0;

      /** \brief Creates a UntypedAtomic Item
       *
       * @param value String representation of the UntypedAtomic Item.
       * @return The UntypedAtomic Item
       */
      virtual Item createUntypedAtomic(const String& value) = 0;

      /**
       * Create a JSON null item.
       */
      virtual Item createJSONNull() = 0;

      /**
       * Create a JSON Object containing the specified JSON Pairs.
       *
       * @param aNames A vector containing the name and value of each pair.
       */
      virtual Item createJSONObject(std::vector<std::pair<Item, Item> >& aNames) = 0;

      /**
       * Create a JSON Array containing the specified items.
       *
       * @param aItems A std::vector<Item> containing Items which may
       * be stored in a JSON Array (namely JSON Arrays, JSON Objects,
       * JSON nulls, valid JSON numeric types, or xs:strings).
       */
      virtual Item createJSONArray(std::vector<Item>& aItems) = 0;

      /**
      * @brief Assigns a simple typed value to an element node.
      *
      * Creates a simple typed value for an element. Note that this may only
      * be done once per element. This method should only be used during
      * creation of a new tree. Using this method to modify elements after
      * processing has begun has undefined results.
      *
      *
      * @param aElement       The element for the typed value; may not be NULL.
      * @param aTypedValue    The typed value for the element.
      */
      virtual void
      assignElementTypedValue(Item& aElement,
                              Item aTypedValue) = 0;
      /**
      * @brief Assigns a simple typed value to an element node.
      *
      * Creates a simple typed value for an element. Note that this may only
      * be done once per element. This method should only be used during
      * creation of a new tree. Using this method to modify elements after
      * processing has begun has undefined results.
      *
      *
      * @param aElement       The element for the typed value; may not be NULL.
      * @param aTypedValue    The typed value for the element.
      */
      virtual void
      assignElementTypedValue(Item& aElement,
                              std::vector<Item>& aTypedValue) = 0;

      /**
       * Create an atomic item having a user-defined atomic type.
       *
       * @param aBaseItem the base item of the item to create.
       * @param aTypeName the name of the type of the item to create.
       *
       * @return a new atomic item having the given user-defined atomic type.
       */
      virtual Item
      createUserTypedAtomicItem(Item& aBaseItem, Item& aTypeName) = 0;

      /** \brief Creates a DateTimeStamp Item
       *         see [www.w3.org/TR/xmlschema11-2/#dateTimeStamp]
       *
       * @param aYear short-valued representation of the year.
       * @param aMonth short-valued representation of the month.
       * @param aDay short-valued representation of the day.
       * @param aHour short-valued representation of the hour.
       * @param aMinute short-valued representation of the minute.
       * @param aSecond double-valued representation of the seconds and fractional seconds.
       * @param aTimeZone the number of seconds east of the prime meridian.
       * @return The DateTimeStamp Item.
       */
      virtual Item
      createDateTimeStamp(short aYear, short aMonth, short aDay,
                          short aHour, short aMinute, double aSecond,
                          int aTimeZone) = 0;

      /** \brief Creates a DateTimeStamp Item
       *         see [www.w3.org/TR/xmlschema11-2/#dateTimeStamp]
       *
       * @param aDateTimeStampValue String representation of the datetimeStamp value
       *        (for example, 2002-10-10T12:00:00-05:00).
       * @return The DateTimeStamp Item.
       */
      virtual Item
      createDateTimeStamp( const String& aDateTimeStampValue ) = 0;
    
  }; // class ItemFactory

} // namespace zorba
#endif
/* vim:set et sw=2 ts=2: */
