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

#include <string.h>
#include <zorba/options.h>
#include "diagnostics/xquery_diagnostics.h"

Zorba_CompilerHints::Zorba_CompilerHints()
  :
  opt_level(ZORBA_OPT_LEVEL_O1),
  lib_module(false),
  for_serialization_only(false)
{
}


void Zorba_CompilerHints_default(Zorba_CompilerHints_t* aHints)
{
  Zorba_CompilerHints_t lDefault;
  *aHints = lDefault;
}


Zorba_SerializerOptions::Zorba_SerializerOptions()
  :
#ifdef ZORBA_WITH_JSON
  ser_method(ZORBA_SERIALIZATION_METHOD_JSONIQ),
#else
  ser_method(ZORBA_SERIALIZATION_METHOD_XML),
#endif
  byte_order_mark(ZORBA_BYTE_ORDER_MARK_NO),
  escape_uri_attributes(ZORBA_ESCAPE_URI_ATTRIBUTES_NO),
  include_content_type(ZORBA_INCLUDE_CONTENT_TYPE_NO),
  indent(ZORBA_INDENT_NO),
  normalization_form(ZORBA_NORMALIZATION_FORM_NONE),
  omit_xml_declaration(ZORBA_OMIT_XML_DECLARATION_NO),
  standalone(ZORBA_STANDALONE_OMIT),
  undeclare_prefixes(ZORBA_UNDECLARE_PREFIXES_NO),
  encoding(ZORBA_ENCODING_UTF8)
#ifdef ZORBA_WITH_JSON
  ,
    cloudscript_extensions(CLOUDSCRIPT_EXTENSIONS_NO),
    cloudscript_multiple_items(CLOUDSCRIPT_MULTIPLE_ITEMS_NO),
    cloudscript_xdm_method(ZORBA_SERIALIZATION_METHOD_XML)
#endif /* ZORBA_WITH_JSON */
{
}

Zorba_serialization_method_t convertMethodString(const char* value, const char* parameter)
{
  if (strcmp(value, "xml") == 0) return ZORBA_SERIALIZATION_METHOD_XML;
  else if (strcmp(value, "html") == 0) return ZORBA_SERIALIZATION_METHOD_HTML;
  else if (strcmp(value, "xhtml") == 0) return ZORBA_SERIALIZATION_METHOD_XHTML;
  else if (strcmp(value, "text") == 0) return ZORBA_SERIALIZATION_METHOD_TEXT;
  else if (strcmp(value, "binary") == 0) return ZORBA_SERIALIZATION_METHOD_BINARY;
#ifdef ZORBA_WITH_JSON
  else if (strcmp(value, "json") == 0) return ZORBA_SERIALIZATION_METHOD_JSON;
  else if (strcmp(value, "jsoniq") == 0) return ZORBA_SERIALIZATION_METHOD_JSONIQ;
#endif
  else
  {
    throw XQUERY_EXCEPTION
        (err::SEPM0016, ERROR_PARAMS( value, parameter, ZED( GoodValuesAreXMLEtc ) ));
  }
}

void Zorba_SerializerOptions::SetSerializerOption(
    const char* parameter,
    const char* value)
{
  if (parameter == NULL || value == NULL)
    return;

  if (strcmp(parameter, "method") == 0)
  {
    ser_method = convertMethodString(value, parameter);
  }
  else if (strcmp(parameter, "byte-order-mark") == 0)
  {
    if (strcmp(value, "yes") == 0) byte_order_mark = ZORBA_BYTE_ORDER_MARK_YES;
    else if (strcmp(value, "no") == 0) byte_order_mark = ZORBA_BYTE_ORDER_MARK_NO;
  }
  else if (strcmp(parameter, "include-content-type") == 0)
  {
    if (strcmp(value, "yes") == 0) include_content_type = ZORBA_INCLUDE_CONTENT_TYPE_YES;
    else if (strcmp(value, "no") == 0) include_content_type = ZORBA_INCLUDE_CONTENT_TYPE_NO;
  }
  else if (strcmp(parameter, "indent") == 0)
  {
    if (strcmp(value, "yes") == 0) indent = ZORBA_INDENT_YES;
    else if (strcmp(value, "no") == 0) indent= ZORBA_INDENT_NO;
  }
  else if (strcmp(parameter, "omit-xml-declaration") == 0)
  {
    if (strcmp(value, "yes") == 0) omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    else if (strcmp(value, "no") == 0) omit_xml_declaration= ZORBA_OMIT_XML_DECLARATION_NO;
  }
  else if (strcmp(parameter, "standalone") == 0)
  {
    if (strcmp(value, "yes") == 0) standalone = ZORBA_STANDALONE_YES;
    else if (strcmp(value, "no") == 0) standalone= ZORBA_STANDALONE_NO;
    else if (strcmp(value, "omit") == 0) standalone= ZORBA_STANDALONE_OMIT;
  }
  else if (strcmp(parameter, "undeclare-prefixes") == 0)
  {
    if (strcmp(value, "yes") == 0) undeclare_prefixes = ZORBA_UNDECLARE_PREFIXES_YES;
    else if (strcmp(value, "no") == 0) undeclare_prefixes = ZORBA_UNDECLARE_PREFIXES_NO;
  }
  else if (strcmp(parameter, "encoding") == 0)
  {
    if (strcmp(value, "UTF-8") == 0) encoding = ZORBA_ENCODING_UTF8;
    else if (strcmp(value, "utf-8") == 0) encoding = ZORBA_ENCODING_UTF8;
    else if (strcmp(value, "utf-16") == 0) encoding = ZORBA_ENCODING_UTF16;
    else if (strcmp(value, "UTF-16") == 0) encoding = ZORBA_ENCODING_UTF16;
  }
  else if (strcmp(parameter, "media-type") == 0)
  {
    media_type = value;
  }
  else if (strcmp(parameter, "doctype-system") == 0)
  {
    doctype_system = value;
  }
  else if (strcmp(parameter, "doctype-public") == 0)
  {
    doctype_public = value;
  }
  else if (strcmp(parameter, "cdata-section-elements") == 0)
  {
    cdata_section_elements = value;
  }
  else if (strcmp(parameter, "version") == 0)
  {
    version = value;
  }
#ifdef ZORBA_WITH_JSON
  else if (strcmp(parameter, "jsoniq-extensions") == 0)
  {
    if (strcmp(value, "yes") == 0) cloudscript_extensions = CLOUDSCRIPT_EXTENSIONS_YES;
    else if (strcmp(value, "no") == 0) cloudscript_extensions = CLOUDSCRIPT_EXTENSIONS_NO;
  }
  else if (strcmp(parameter, "cloudscript-multiple-items") == 0)
  {
    if (strcmp(value, "no") == 0)
      cloudscript_multiple_items = CLOUDSCRIPT_MULTIPLE_ITEMS_NO;
    else if (strcmp(value, "array") == 0)
      cloudscript_multiple_items = CLOUDSCRIPT_MULTIPLE_ITEMS_ARRAY;
    else if (strcmp(value, "appended") == 0)
      cloudscript_multiple_items = CLOUDSCRIPT_MULTIPLE_ITEMS_APPENDED;
  }
  else if (strcmp(parameter, "cloudscript-xdm-node-output-method") == 0)
  {
    cloudscript_xdm_method = convertMethodString(value, parameter);
  }
#endif /* ZORBA_WITH_JSON */
}


Zorba_SerializerOptions_t Zorba_SerializerOptions::SerializerOptionsFromStringParams(const std::vector<std::pair<std::string, std::string> >& params)
{
  Zorba_SerializerOptions_t opt;

  for (
    std::vector<std::pair<std::string, std::string> >::const_iterator iter = params.begin();
    iter != params.end();
    ++iter)
  {
    opt.SetSerializerOption(iter->first.c_str(), iter->second.c_str());
  }

  return opt;
}


Zorba_SerializerOptions_t* Zorba_SerializerOptions_default()
{
  Zorba_SerializerOptions_t* lDefault = new Zorba_SerializerOptions();
  return lDefault;
}


void Zorba_SerializerOptions_free(Zorba_SerializerOptions_t* serializerOptions)
{
  delete serializerOptions;
}


void Zorba_SerializerOptions_set(Zorba_SerializerOptions_t* serializerOptions, const char* parameter, const char* value)
{
  if (serializerOptions == NULL || parameter == NULL || value == NULL)
    return;

  serializerOptions->SetSerializerOption(parameter, value);
}
/* vim:set et sw=2 ts=2: */
