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
#include <zorba/options.h>

Zorba_CompilerHints::Zorba_CompilerHints()
: opt_level(ZORBA_OPT_LEVEL_O1)
{}

Zorba_SerializerOptions::Zorba_SerializerOptions()
: ser_method(ZORBA_SERIALIZATION_METHOD_HTML),
  byte_order_mark(ZORBA_BYTE_ORDER_MARK_NO),
  escape_uri_attributes(ZORBA_ESCAPE_URI_ATTRIBUTES_NO),
  include_content_type(ZORBA_INCLUDE_CONTENT_TYPE_NO),
  indent(ZORBA_INDENT_NO),
  normalization_form(ZORBA_NORMALIZATION_FORM_NONE),
  omit_xml_declaration(ZORBA_OMIT_XML_DECLARATION_NO),
  standalone(ZORBA_STANDALONE_OMIT),
  undeclare_prefixes(ZORBA_UNDECLARE_PREFIXES_NO)
{}

Zorba_CompilerHints_t Zorba_CompilerHints_default()
{
  Zorba_CompilerHints_t lDefault;
  return lDefault;
}

Zorba_SerializerOptions_t Zorba_SerializerOptions_default() 
{
  Zorba_SerializerOptions_t lDefault; 
  return lDefault;
}
