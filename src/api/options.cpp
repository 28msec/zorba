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
#include <string.h>
#include <zorba/options.h>

Zorba_CompilerHints::Zorba_CompilerHints()
: opt_level(ZORBA_OPT_LEVEL_O1)
{}

Zorba_SerializerOptions::Zorba_SerializerOptions()
: ser_method(ZORBA_SERIALIZATION_METHOD_XML),
  byte_order_mark(ZORBA_BYTE_ORDER_MARK_NO),
  escape_uri_attributes(ZORBA_ESCAPE_URI_ATTRIBUTES_NO),
  include_content_type(ZORBA_INCLUDE_CONTENT_TYPE_NO),
  indent(ZORBA_INDENT_NO),
  normalization_form(ZORBA_NORMALIZATION_FORM_NONE),
  omit_xml_declaration(ZORBA_OMIT_XML_DECLARATION_NO),
  standalone(ZORBA_STANDALONE_OMIT),
  undeclare_prefixes(ZORBA_UNDECLARE_PREFIXES_NO)
{}
  
void Zorba_SerializerOptions::SetSerializerOption(const char* parameter, const char* value)
{
  if (parameter == NULL || value == NULL)
    return;
  
  if (strcmp(parameter, "method") == 0)
  {
    if (strcmp(value, "xml") == 0) ser_method = ZORBA_SERIALIZATION_METHOD_XML; 
    else if (strcmp(value, "html") == 0) ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
    else if (strcmp(value, "xhtml") == 0) ser_method = ZORBA_SERIALIZATION_METHOD_XHTML;
    else if (strcmp(value, "text") == 0) ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
    else
    {
      ; // TODO signal errors for incorrect values?
    }
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
  else if (strcmp(parameter, "doctype-system") == 0)
  {
    doctype_system = value;
  }
  else if (strcmp(parameter, "doctype-public") == 0)
  {
    doctype_public = value;
  }
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

Zorba_CompilerHints_t Zorba_CompilerHints_default()
{
  Zorba_CompilerHints_t lDefault;
  return lDefault;
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

