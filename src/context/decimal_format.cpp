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

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"
#include "context/decimal_format.h"
#include "store/api/item.h"
#include "util/stl_util.h"
#include "util/utf8_util.h"
#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(DecimalFormat)

///////////////////////////////////////////////////////////////////////////////

DecimalFormat::DecimalFormat( bool is_default, const store::Item_t& qname,
                              ctor_properties_type const &properties,
                              QueryLoc const &loc ) :
  is_default_( is_default ),
  qname_( qname )
{
  for ( ctor_properties_type::size_type i = 0; i < properties.size() - 1;
        ++i ) {
    for ( ctor_properties_type::size_type j = i + 1; j < properties.size();
          ++j ) {
      if ( i == j )
        continue;
      if ( properties[i].first == properties[j].first ) {
        //
        // XQuery 3.0 4.10: It is a static error for a decimal format
        // declaration to define the same property more than once.
        //
        throw XQUERY_EXCEPTION(
          err::XQST0114,
          ERROR_PARAMS( properties[i].first ),
          ERROR_LOC( loc )
        );
      }
      if ( properties[i].second == properties[j].second ) {
        //
        // Ibid: It is a static error if, for any named or unnamed decimal
        // format, the properties representing characters used in a picture
        // string do not have distinct values.
        //
        throw XQUERY_EXCEPTION(
          err::XQST0098,
          ERROR_PARAMS(
            properties[i].second, properties[i].first, properties[j].first
          ),
          ERROR_LOC( loc )
        );
      }
    } // for ( ... j ... )
  } // for ( ... i ... )

  FOR_EACH( ctor_properties_type, property, properties )
    properties_[ property->first ] = property->second;

  struct property_attribute {
    char const *name;
    bool is_string;
    char const *default_value;
  };

  static property_attribute const attributes[] = {
    { "decimal-separator" , false, "."            },
    { "digit"             , false, "#"            },
    { "grouping-separator", false, ","            },
    { "infinity"          , true , "Infinity"     },
    { "minus-sign"        , false, "-"            },
    { "NaN"               , true , "Nan"          },
    { "pattern-separator" , false, ";"            },
    { "percent"           , false, "%"            },
    { "per-mille"         , false, "\xE2\x80\xB0" },
    { "zero-digit"        , false, "0"            },
    { 0, false, 0 }
  };

  for ( property_attribute const *attr = attributes; attr->name; ++attr ) {
    value_type &value = properties_[ attr->name ];
    if ( value.empty() )
      value = attr->default_value;
    else if ( !attr->is_string && utf8::length( value ) > 1 ) {
      //
      // Ibid: It is a static error for a decimal format declaration to specify
      // a value that is not valid for a given property.
      //
      throw XQUERY_EXCEPTION(
        err::XQST0097,
        ERROR_PARAMS( value, attr->name, ZED( XQST0097_MustBeChar ) ),
        ERROR_LOC( loc )
      );
    }
  }

  //
  // XQuery 3.0 2.1.1: zero-digit specifies the character used for the zero-
  // digit-symbol; the default value is the digit zero (0). This character must
  // be a digit (category Nd in the Unicode property database), and it must
  // have the numeric value zero.
  //
  value_type const &zero_digit = properties_[ "zero-digit" ];
  unicode::code_point const zero_digit_cp = utf8::decode( zero_digit.c_str() );
  unicode::code_point zero_cp;
  if ( !unicode::is_Nd( zero_digit_cp, &zero_cp ) || zero_digit_cp != zero_cp )
    throw XQUERY_EXCEPTION(
      err::XQST0097,
      ERROR_PARAMS( zero_digit, "zero-digit", ZED( XQST0097_MustBeZeroDigit ) ),
      ERROR_LOC( loc )
    );
}

void DecimalFormat::serialize( serialization::Archiver &ar ) {
  ar & is_default_;
  ar & qname_;
  ar & properties_;
}

///////////////////////////////////////////////////////////////////////////////

}	// namespace zorba
/* vim:set et sw=2 ts=2: */
