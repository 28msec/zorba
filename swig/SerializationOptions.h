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

class SerializationOptions
{
friend class Item;

public:
  typedef enum 
  {
    ZORBA_SERIALIZATION_METHOD_XML,
    ZORBA_SERIALIZATION_METHOD_HTML,
    ZORBA_SERIALIZATION_METHOD_XHTML,
    ZORBA_SERIALIZATION_METHOD_TEXT,
    ZORBA_SERIALIZATION_METHOD_BINARY
  } SerializationMethod;

  typedef enum 
  {
    ZORBA_BYTE_ORDER_MARK_YES,
    ZORBA_BYTE_ORDER_MARK_NO
  } ByteOrderMark;


  typedef enum 
  {
    ZORBA_ESCAPE_URI_ATTRIBUTES_YES,
    ZORBA_ESCAPE_URI_ATTRIBUTES_NO
  } EscapeUriAttributes;

  typedef enum {
    ZORBA_INCLUDE_CONTENT_TYPE_YES,
    ZORBA_INCLUDE_CONTENT_TYPE_NO
  } IncludeContentType;

  typedef enum {
    ZORBA_INDENT_YES,
    ZORBA_INDENT_NO
  } Indent;

  typedef enum {
    ZORBA_NORMALIZATION_FORM_NFC,
    ZORBA_NORMALIZATION_FORM_NFD,
    ZORBA_NORMALIZATION_FORM_NFKC,
    ZORBA_NORMALIZATION_FORM_NFKD,
    ZORBA_NORMALIZATION_FORM_FULLY_normalized,
    ZORBA_NORMALIZATION_FORM_NONE
  } NormalizationForm;

  typedef enum {
    ZORBA_OMIT_XML_DECLARATION_YES,
    ZORBA_OMIT_XML_DECLARATION_NO
  } OmitXMLDeclaration;

  typedef enum {
    ZORBA_STANDALONE_YES,
    ZORBA_STANDALONE_NO,
    ZORBA_STANDALONE_OMIT
  } Standalone;

  typedef enum {
    ZORBA_UNDECLARE_PREFIXES_YES,
    ZORBA_UNDECLARE_PREFIXES_NO
  } UndeclarePrefixes;


private:
  Zorba_SerializerOptions_t lOptions;
  
public:
  /*
   * Default values:
   *   - serialization method: XML
   *   - byte order mark: NO
   *   - esacpe uri attributes: NO
   *   - include content type: NO
   *   - indent: NO
   *   - normalization form: none
   *   - omit xml declaration: NO
   *   - standalone: omit
   *   - undeclare prefixes: NO
   */


  void setSerializationMethod ( SerializationMethod aSerializationMethod );
  void setByteOrderMark ( ByteOrderMark aByteOrderMark );
  void setEscapeUriAttributes ( EscapeUriAttributes aEscapeUriAttributes );
  void setIncludeContentType ( IncludeContentType aIncludeContentType );
  void setIndent ( Indent aIndent );
  void setNormalizationForm ( NormalizationForm aNormalizationForm );
  void setOmitXMLDeclaration ( OmitXMLDeclaration aOmitXMLDeclaration );
  void setStandalone ( Standalone aStandalone );
  void setUndeclarePrefixes ( UndeclarePrefixes aUndeclarePrefixes );
  void setSerializerOption(const std::string &parameter, const std::string &value);

}; // class SerializationOptions

#endif
