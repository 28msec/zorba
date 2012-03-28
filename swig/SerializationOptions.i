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

%{  // start Implementation

  void SerializationOptions::setSerializationMethod ( SerializationMethod aSerializationMethod ) {
    switch (aSerializationMethod) {
      case ZORBA_API_SERIALIZATION_METHOD_HTML:
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
        break;
      case ZORBA_API_SERIALIZATION_METHOD_XHTML:
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XHTML;
        break;
      case ZORBA_API_SERIALIZATION_METHOD_TEXT:
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
        break;
      case ZORBA_API_SERIALIZATION_METHOD_BINARY:
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_BINARY;
        break;
      case ZORBA_API_SERIALIZATION_METHOD_XML:
      default:
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
        break;
    }
  }
  void SerializationOptions::setByteOrderMark ( ByteOrderMark aByteOrderMark ) {
    if (aByteOrderMark == ZORBA_API_BYTE_ORDER_MARK_YES) {
      lOptions.byte_order_mark = ZORBA_BYTE_ORDER_MARK_YES;
    } else {
      lOptions.byte_order_mark = ZORBA_BYTE_ORDER_MARK_NO;
    }
  }
  void SerializationOptions::setEscapeUriAttributes ( EscapeUriAttributes aEscapeUriAttributes ) {
    if (aEscapeUriAttributes == ZORBA_API_ESCAPE_URI_ATTRIBUTES_YES) {
      lOptions.escape_uri_attributes = ZORBA_ESCAPE_URI_ATTRIBUTES_YES;
    } else {
      lOptions.escape_uri_attributes = ZORBA_ESCAPE_URI_ATTRIBUTES_NO;
    }
  }
  void SerializationOptions::setIncludeContentType ( IncludeContentType aIncludeContentType ) {
    if (aIncludeContentType == ZORBA_API_INCLUDE_CONTENT_TYPE_YES) {
      lOptions.include_content_type = ZORBA_INCLUDE_CONTENT_TYPE_YES;
    } else {
      lOptions.include_content_type = ZORBA_INCLUDE_CONTENT_TYPE_NO;
    }
  }
  void SerializationOptions::setIndent ( Indent aIndent ) {
    if (aIndent == ZORBA_API_INDENT_YES) {
      lOptions.indent = ZORBA_INDENT_YES;
    } else {
      lOptions.indent = ZORBA_INDENT_NO;
    }
  }
  void SerializationOptions::setNormalizationForm ( NormalizationForm aNormalizationForm ) {
    switch (aNormalizationForm) {
      case ZORBA_API_NORMALIZATION_FORM_NFC:
        lOptions.normalization_form = ZORBA_NORMALIZATION_FORM_NFC;
        break;
      case ZORBA_API_NORMALIZATION_FORM_NFD:
        lOptions.normalization_form = ZORBA_NORMALIZATION_FORM_NFD;
        break;
      case ZORBA_API_NORMALIZATION_FORM_NFKC:
        lOptions.normalization_form = ZORBA_NORMALIZATION_FORM_NFKC;
        break;
      case ZORBA_API_NORMALIZATION_FORM_NFKD:
        lOptions.normalization_form = ZORBA_NORMALIZATION_FORM_NFKD;
        break;
      case ZORBA_API_NORMALIZATION_FORM_FULLY_normalized:
        lOptions.normalization_form = ZORBA_NORMALIZATION_FORM_FULLY_normalized;
        break;
      case ZORBA_API_NORMALIZATION_FORM_NONE:
      default:
        lOptions.normalization_form = ZORBA_NORMALIZATION_FORM_NONE;
        break;
    }
  }
  void SerializationOptions::setOmitXMLDeclaration ( OmitXMLDeclaration aOmitXMLDeclaration ) {
    if (aOmitXMLDeclaration == ZORBA_API_OMIT_XML_DECLARATION_YES) {
      lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    } else {
      lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_NO;
    }
  }
  void SerializationOptions::setStandalone ( Standalone aStandalone ) {
    switch (aStandalone) {
      case ZORBA_API_STANDALONE_YES:
        lOptions.standalone = ZORBA_STANDALONE_YES;
        break;
      case ZORBA_API_STANDALONE_NO:
        lOptions.standalone = ZORBA_STANDALONE_NO;
        break;
      case ZORBA_API_STANDALONE_OMIT:
      default:
        lOptions.standalone = ZORBA_STANDALONE_OMIT;
        break;
    }
  }
  void SerializationOptions::setUndeclarePrefixes ( UndeclarePrefixes aUndeclarePrefixes ) {
    if (aUndeclarePrefixes == ZORBA_API_UNDECLARE_PREFIXES_YES) {
      lOptions.undeclare_prefixes = ZORBA_UNDECLARE_PREFIXES_YES;
    } else {
      lOptions.undeclare_prefixes = ZORBA_UNDECLARE_PREFIXES_NO;
    }
  }

  void SerializationOptions::setSerializerOption(const std::string &parameter, const std::string &value) {
    lOptions.SetSerializerOption(parameter.c_str(), value.c_str());
  }
  
%}  // end Implementation

%include "SerializationOptions.h"
