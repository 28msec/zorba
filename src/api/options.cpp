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

#include <cstring>

#include <zorba/options.h>
#include <zorba/util/transcode_stream.h>
#include <zorba/diagnostic_list.h>

#include "diagnostics/diagnostic.h"
#include "diagnostics/zorba_exception.h"
#include "util/ascii_util.h"
#include "util/stl_util.h"
#include "zorbatypes/zstring.h"

using namespace std;
using namespace zorba;

///////////////////////////////////////////////////////////////////////////////

Zorba_CompilerHints::Zorba_CompilerHints() :
  opt_level(ZORBA_OPT_LEVEL_O1),
  lib_module(false),
  for_serialization_only(false)
{
}

///////////////////////////////////////////////////////////////////////////////

inline void assign( Zorba_opaque_char_ptr &ptr, char const *value ) {
  delete[] ptr.ptr;
  ptr.ptr = ztd::new_strdup( value );
}

static void copy_from_to( Zorba_SerializerOptions const *from,
                          Zorba_SerializerOptions *to ) {
  ::memcpy( to, from, sizeof( Zorba_SerializerOptions ) );
  if ( from->encoding.ptr )
    to->encoding.ptr = ztd::new_strdup( from->encoding.ptr );
  if ( from->media_type.ptr )
    to->media_type.ptr = ztd::new_strdup( from->media_type.ptr );
  if ( from->doctype_system.ptr )
    to->doctype_system.ptr = ztd::new_strdup( from->doctype_system.ptr );
  if ( from->doctype_public.ptr )
    to->doctype_public.ptr = ztd::new_strdup( from->doctype_public.ptr );
  if ( from->cdata_section_elements.ptr )
    to->cdata_section_elements.ptr = ztd::new_strdup( from->cdata_section_elements.ptr );
  if ( from->item_separator.ptr )
    to->item_separator.ptr = ztd::new_strdup( from->item_separator.ptr );
  if ( from->version.ptr )
    to->version.ptr = ztd::new_strdup( from->version.ptr );
}

static void null_ptrs( Zorba_SerializerOptions_t *opts ) {
  opts->encoding.ptr = nullptr;
  opts->media_type.ptr = nullptr;
  opts->doctype_system.ptr = nullptr;
  opts->doctype_public.ptr = nullptr;
  opts->cdata_section_elements.ptr = nullptr;
  opts->item_separator.ptr = nullptr;
  opts->version.ptr = nullptr;
}

static bool parse_method( char const *value, Zorba_serialization_method_t *m ) {
  if ( strcmp( value, "binary" ) == 0 )
    *m = ZORBA_SERIALIZATION_METHOD_BINARY;
  else if ( strcmp( value, "html" ) == 0 )
    *m = ZORBA_SERIALIZATION_METHOD_HTML;
  else if ( strcmp( value, "json" ) == 0 )
    *m = ZORBA_SERIALIZATION_METHOD_JSON;
  else if ( strcmp( value, "json-xml-hybrid" ) == 0 )
    *m = ZORBA_SERIALIZATION_METHOD_JSON_XML_HYBRID;
  else if ( strcmp( value, "text" ) == 0 )
    *m = ZORBA_SERIALIZATION_METHOD_TEXT;
  else if ( strcmp( value, "xhtml" ) == 0 )
    *m = ZORBA_SERIALIZATION_METHOD_XHTML;
  else if ( strcmp( value, "xml" ) == 0 )
    *m = ZORBA_SERIALIZATION_METHOD_XML;
  else
    return false;
  return true;
}

template<typename EnumType>
inline bool parse_yes_no( char const *value, EnumType *e ) {
  if ( strcmp( value, "no" ) == 0 || strcmp( value, "yes" ) == 0 ) {
    *e = static_cast<EnumType>( *value == 'y' );
    return true;
  }
  return false;
}

void Zorba_SerializerOptions_init( Zorba_SerializerOptions_t *opts ) {
  opts->byte_order_mark = ZORBA_BYTE_ORDER_MARK_NO;
  opts->escape_uri_attributes = ZORBA_ESCAPE_URI_ATTRIBUTES_NO;
  opts->include_content_type = ZORBA_INCLUDE_CONTENT_TYPE_NO;
  opts->indent = ZORBA_INDENT_NO;
  opts->jsoniq_multiple_items = JSONIQ_MULTIPLE_ITEMS_YES;
  opts->jsoniq_xdm_method = ZORBA_SERIALIZATION_METHOD_XML;
  opts->normalization_form = ZORBA_NORMALIZATION_FORM_NONE;
  opts->omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_NO;
  opts->ser_method = ZORBA_SERIALIZATION_METHOD_JSON_XML_HYBRID;
  opts->standalone = ZORBA_STANDALONE_OMIT;
  opts->undeclare_prefixes = ZORBA_UNDECLARE_PREFIXES_NO;
  null_ptrs( opts );
  assign( opts->item_separator, " " );
}

void Zorba_SerializerOptions_free( Zorba_SerializerOptions_t *opts ) {
  delete[] opts->encoding.ptr;
  delete[] opts->media_type.ptr;
  delete[] opts->doctype_system.ptr;
  delete[] opts->doctype_public.ptr;
  delete[] opts->cdata_section_elements.ptr;
  delete[] opts->item_separator.ptr;
  delete[] opts->version.ptr;
  null_ptrs( opts );
}

Zorba_opt_bool_t Zorba_SerializerOptions_set( Zorba_SerializerOptions_t *opts,
                                              char const *option,
                                              char const *value ) {
  if ( !opts || !option || !value )
    return false;

  if ( strcmp( option, "byte-order-mark" ) == 0 )
    return parse_yes_no( value, &opts->byte_order_mark );

  if ( strcmp( option, "cdata-section-elements" ) == 0 ) {
    assign( opts->cdata_section_elements, value );
    return true;
  }

  if ( strcmp( option, "doctype-public" ) == 0 ) {
    assign( opts->doctype_public, value );
    return true;
  }

  if ( strcmp( option, "doctype-system" ) == 0 ) {
    assign( opts->doctype_system, value );
    return true;
  }

  if ( strcmp( option, "encoding" ) == 0 ) {
    if ( !transcode::is_supported( value ) )
      return false;
    zstring temp( value );
    ascii::to_upper( temp );
    assign( opts->encoding, temp.c_str() );
    return true;
  }

  if ( strcmp( option, "include-content-type" ) == 0 )
    return parse_yes_no( value, &opts->include_content_type );

  if ( strcmp( option, "indent" ) == 0 )
    return parse_yes_no( value, &opts->indent );

  if ( strcmp( option, "item-separator" ) == 0 ) {
    assign( opts->item_separator, value );
    return true;
  }

  if ( strcmp( option, "jsoniq-multiple-items" ) == 0 )
    return parse_yes_no( value, &opts->jsoniq_multiple_items );

  if ( strcmp( option, "jsoniq-xdm-node-output-method" ) == 0 )
    return parse_method( value, &opts->jsoniq_xdm_method );

  if ( strcmp( option, "media-type" ) == 0 ) {
    assign( opts->media_type, value );
    return true;
  }

  if ( strcmp( option, "method" ) == 0 )
    return parse_method( value, &opts->ser_method );

  if ( strcmp( option, "omit-xml-declaration" ) == 0 )
    return parse_yes_no( value, &opts->omit_xml_declaration );

  if ( strcmp( option, "standalone" ) == 0 ) {
    if ( parse_yes_no( value, &opts->standalone ) )
      return true;
    if ( strcmp( value, "omit" ) != 0 )
      return false;
    opts->standalone = ZORBA_STANDALONE_OMIT;
    return true;
  }

  if ( strcmp( option, "undeclare-prefixes" ) == 0 )
    return parse_yes_no( value, &opts->undeclare_prefixes );

  if ( strcmp( option, "version" ) == 0 ) {
    assign( opts->version, value );
    return true;
  }

  return false;
}

Zorba_SerializerOptions::
Zorba_SerializerOptions( Zorba_SerializerOptions const &that ) {
  if ( &that != this )
    copy_from_to( &that, this );
  else
    Zorba_SerializerOptions_init( this );
}

Zorba_SerializerOptions&
Zorba_SerializerOptions::operator=( Zorba_SerializerOptions const &that ) {
  if ( &that != this ) {
    Zorba_SerializerOptions_free( this );
    copy_from_to( &that, this );
  }
  return *this;
}

void Zorba_SerializerOptions::set( char const *option, char const *value ) {
  if ( !Zorba_SerializerOptions_set( this, option, value ) )
    throw ZORBA_EXCEPTION( err::SEPM0016, ERROR_PARAMS( value, option ) );
}

void Zorba_SerializerOptions::
set( std::vector<string_pair> const &option_values ) {
  FOR_EACH( std::vector<string_pair>, i, option_values )
    set( i->first.c_str(), i->second.c_str() );
}

/* vim:set et sw=2 ts=2: */
