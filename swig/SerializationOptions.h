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

#ifndef API_SERIALIZATION_OPTIONS_H
#define API_SERIALIZATION_OPTIONS_H

  /** \brief This class defines a set of values used to define the way a serialization can be made over Items or Collections
   *         collections.
   *
   * Default values:
   *   - Serialization method: XML
   *   - Byte order mark: NO
   *   - Escape uri attributes: NO
   *   - Include content type: NO
   *   - Indent: NO
   *   - Normalization form: none
   *   - Omit xml declaration: NO
   *   - Standalone: omit
   *   - Undeclare prefixes: NO
   */
class SerializationOptions
{
friend class Item;

public:
  typedef enum 
  {
    ZORBA_API_SERIALIZATION_METHOD_XML,
    ZORBA_API_SERIALIZATION_METHOD_HTML,
    ZORBA_API_SERIALIZATION_METHOD_XHTML,
    ZORBA_API_SERIALIZATION_METHOD_TEXT,
    ZORBA_API_SERIALIZATION_METHOD_BINARY
  } SerializationMethod;

  typedef enum 
  {
    ZORBA_API_BYTE_ORDER_MARK_YES,
    ZORBA_API_BYTE_ORDER_MARK_NO
  } ByteOrderMark;


  typedef enum 
  {
    ZORBA_API_ESCAPE_URI_ATTRIBUTES_YES,
    ZORBA_API_ESCAPE_URI_ATTRIBUTES_NO
  } EscapeUriAttributes;

  typedef enum {
    ZORBA_API_INCLUDE_CONTENT_TYPE_YES,
    ZORBA_API_INCLUDE_CONTENT_TYPE_NO
  } IncludeContentType;

  typedef enum {
    ZORBA_API_INDENT_YES,
    ZORBA_API_INDENT_NO
  } Indent;

  typedef enum {
    ZORBA_API_NORMALIZATION_FORM_NFC,
    ZORBA_API_NORMALIZATION_FORM_NFD,
    ZORBA_API_NORMALIZATION_FORM_NFKC,
    ZORBA_API_NORMALIZATION_FORM_NFKD,
    ZORBA_API_NORMALIZATION_FORM_FULLY_normalized,
    ZORBA_API_NORMALIZATION_FORM_NONE
  } NormalizationForm;

  typedef enum {
    ZORBA_API_OMIT_XML_DECLARATION_YES,
    ZORBA_API_OMIT_XML_DECLARATION_NO
  } OmitXMLDeclaration;

  typedef enum {
    ZORBA_API_STANDALONE_YES,
    ZORBA_API_STANDALONE_NO,
    ZORBA_API_STANDALONE_OMIT
  } Standalone;

  typedef enum {
    ZORBA_API_UNDECLARE_PREFIXES_YES,
    ZORBA_API_UNDECLARE_PREFIXES_NO
  } UndeclarePrefixes;


private:
  Zorba_SerializerOptions_t lOptions;
  
public:

  /* /brief Set the serialization method used
  */
  void setSerializationMethod ( SerializationMethod aSerializationMethod );

  /* /brief Set the byte order mark used
  */
  void setByteOrderMark ( ByteOrderMark aByteOrderMark );

  /* /brief Set the escape uri attributes used
  */
  void setEscapeUriAttributes ( EscapeUriAttributes aEscapeUriAttributes );

  /* /brief Set the include content type used
  */
  void setIncludeContentType ( IncludeContentType aIncludeContentType );

  /* /brief Set the identation used
  */
  void setIndent ( Indent aIndent );

  /* /brief Set the normalization form used
  */
  void setNormalizationForm ( NormalizationForm aNormalizationForm );

  /* /brief Set if XML declaration is omited
  */
  void setOmitXMLDeclaration ( OmitXMLDeclaration aOmitXMLDeclaration );

  /* /brief Set the standalone option
  */
  void setStandalone ( Standalone aStandalone );

  /* /brief Set the undeclared prefixes
  */
  void setUndeclarePrefixes ( UndeclarePrefixes aUndeclarePrefixes );

  /** /brief Set the serialization options given a string parameter and a string value
   * 
   * @param parameter The parameter to be changed
   * @param value The value to be assigned in a string form
   */
  void setSerializerOption(const std::string &parameter, const std::string &value);

}; // class SerializationOptions

#endif
