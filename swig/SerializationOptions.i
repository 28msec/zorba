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
      case SerializationMethod::ZORBA_SERIALIZATION_METHOD_HTML:
        lOptions.ser_method = Zorba_serialization_method_t::ZORBA_SERIALIZATION_METHOD_HTML;
        break;
      case SerializationMethod::ZORBA_SERIALIZATION_METHOD_XHTML:
        lOptions.ser_method = Zorba_serialization_method_t::ZORBA_SERIALIZATION_METHOD_XHTML;
        break;
      case SerializationMethod::ZORBA_SERIALIZATION_METHOD_TEXT:
        lOptions.ser_method = Zorba_serialization_method_t::ZORBA_SERIALIZATION_METHOD_TEXT;
        break;
      case SerializationMethod::ZORBA_SERIALIZATION_METHOD_BINARY:
        lOptions.ser_method = Zorba_serialization_method_t::ZORBA_SERIALIZATION_METHOD_BINARY;
        break;
      case SerializationMethod::ZORBA_SERIALIZATION_METHOD_XML:
      default:
        lOptions.ser_method = Zorba_serialization_method_t::ZORBA_SERIALIZATION_METHOD_XML;
        break;
    }
  }
  void SerializationOptions::setByteOrderMark ( ByteOrderMark aByteOrderMark ) {
    if (aByteOrderMark == ByteOrderMark::ZORBA_BYTE_ORDER_MARK_YES) {
      lOptions.byte_order_mark = Zorba_byte_order_mark_t::ZORBA_BYTE_ORDER_MARK_YES;
    } else {
      lOptions.byte_order_mark = Zorba_byte_order_mark_t::ZORBA_BYTE_ORDER_MARK_NO;
    }
  }
  void SerializationOptions::setEscapeUriAttributes ( EscapeUriAttributes aEscapeUriAttributes ) {
    if (aEscapeUriAttributes == EscapeUriAttributes::ZORBA_ESCAPE_URI_ATTRIBUTES_YES) {
      lOptions.escape_uri_attributes = Zorba_escape_uri_attributes_t::ZORBA_ESCAPE_URI_ATTRIBUTES_YES;
    } else {
      lOptions.escape_uri_attributes = Zorba_escape_uri_attributes_t::ZORBA_ESCAPE_URI_ATTRIBUTES_NO;
    }
  }
  void SerializationOptions::setIncludeContentType ( IncludeContentType aIncludeContentType ) {
    if (aIncludeContentType == IncludeContentType::ZORBA_INCLUDE_CONTENT_TYPE_YES) {
      lOptions.include_content_type = Zorba_include_content_type_t::ZORBA_INCLUDE_CONTENT_TYPE_YES;
    } else {
      lOptions.include_content_type = Zorba_include_content_type_t::ZORBA_INCLUDE_CONTENT_TYPE_NO;
    }
  }
  void SerializationOptions::setIndent ( Indent aIndent ) {
    if (aIndent == Indent::ZORBA_INDENT_YES) {
      lOptions.indent = Zorba_indent_t::ZORBA_INDENT_YES;
    } else {
      lOptions.indent = Zorba_indent_t::ZORBA_INDENT_NO;
    }
  }
  void SerializationOptions::setNormalizationForm ( NormalizationForm aNormalizationForm ) {
    switch (aNormalizationForm) {
      case NormalizationForm::ZORBA_NORMALIZATION_FORM_NFC:
        lOptions.normalization_form = Zorba_normalization_form_t::ZORBA_NORMALIZATION_FORM_NFC;
        break;
      case NormalizationForm::ZORBA_NORMALIZATION_FORM_NFD:
        lOptions.normalization_form = Zorba_normalization_form_t::ZORBA_NORMALIZATION_FORM_NFD;
        break;
      case NormalizationForm::ZORBA_NORMALIZATION_FORM_NFKC:
        lOptions.normalization_form = Zorba_normalization_form_t::ZORBA_NORMALIZATION_FORM_NFKC;
        break;
      case NormalizationForm::ZORBA_NORMALIZATION_FORM_NFKD:
        lOptions.normalization_form = Zorba_normalization_form_t::ZORBA_NORMALIZATION_FORM_NFKD;
        break;
      case NormalizationForm::ZORBA_NORMALIZATION_FORM_FULLY_normalized:
        lOptions.normalization_form = Zorba_normalization_form_t::ZORBA_NORMALIZATION_FORM_FULLY_normalized;
        break;
      case NormalizationForm::ZORBA_NORMALIZATION_FORM_NONE:
      default:
        lOptions.normalization_form = Zorba_normalization_form_t::ZORBA_NORMALIZATION_FORM_NONE;
        break;
    }
  }
  void SerializationOptions::setOmitXMLDeclaration ( OmitXMLDeclaration aOmitXMLDeclaration ) {
    if (aOmitXMLDeclaration == OmitXMLDeclaration::ZORBA_OMIT_XML_DECLARATION_YES) {
      lOptions.omit_xml_declaration = Zorba_omit_xml_declaration_t::ZORBA_OMIT_XML_DECLARATION_YES;
    } else {
      lOptions.omit_xml_declaration = Zorba_omit_xml_declaration_t::ZORBA_OMIT_XML_DECLARATION_NO;
    }
  }
  void SerializationOptions::setStandalone ( Standalone aStandalone ) {
    switch (aStandalone) {
      case Standalone::ZORBA_STANDALONE_YES:
        lOptions.standalone = Zorba_standalone_t::ZORBA_STANDALONE_YES;
        break;
      case Standalone::ZORBA_STANDALONE_NO:
        lOptions.standalone = Zorba_standalone_t::ZORBA_STANDALONE_NO;
        break;
      case Standalone::ZORBA_STANDALONE_OMIT:
      default:
        lOptions.standalone = Zorba_standalone_t::ZORBA_STANDALONE_OMIT;
        break;
    }
  }
  void SerializationOptions::setUndeclarePrefixes ( UndeclarePrefixes aUndeclarePrefixes ) {
    if (aUndeclarePrefixes == UndeclarePrefixes::ZORBA_UNDECLARE_PREFIXES_YES) {
      lOptions.undeclare_prefixes = Zorba_undeclare_prefixes_t::ZORBA_UNDECLARE_PREFIXES_YES;
    } else {
      lOptions.undeclare_prefixes = Zorba_undeclare_prefixes_t::ZORBA_UNDECLARE_PREFIXES_NO;
    }
  }

  void SerializationOptions::setSerializerOption(const std::string &parameter, const std::string &value) {
    lOptions.SetSerializerOption(parameter.c_str(), value.c_str());
  }
  
%}  // end Implementation

%include "SerializationOptions.h"
