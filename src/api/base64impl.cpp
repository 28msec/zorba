/*
 * Copyright 2006-2009 The FLWOR Foundation.
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

#include <sstream> 
#include <zorba/base64.h>
#include <zorba/diagnostic_list.h>

#include <zorba/config.h>
#include <zorba/zorba_string.h>

#include "diagnostics/dict.h"
#include "diagnostics/xquery_exception.h"
#include "util/base64_util.h"

#define CATCH_BASE64_EXCEPTION()                                            \
  catch ( base64::exception const &e ) {                                    \
    throw XQUERY_EXCEPTION(                                                 \
      err::FORG0001, ERROR_PARAMS( e.invalid_char(), ZED( Base64BadChar ) ) \
    );                                                                      \
  }                                                                         \
  catch ( std::invalid_argument const& ) {                                  \
    throw XQUERY_EXCEPTION(                                                 \
      err::FORG0001, ERROR_PARAMS( "", ZED( Base64Multiple4 ) )             \
    );                                                                      \
  }

namespace zorba {
namespace encoding {

String Base64::encode(const String& aString) 
{
  String result;
  base64::encode( aString.data(), aString.size(), &result );
  return result;
}


String Base64::encode(std::istream& aStream) 
{
  String result;
  base64::encode( aStream, &result );
  return result;
}


String Base64::decode(const String& aString)
{
  try {
    String result;
    base64::decode( aString.data(), aString.size(), &result );
    return result;
  }
  CATCH_BASE64_EXCEPTION()
}


String Base64::decode(std::istream& aStream)
{
  try {
    String result;
    base64::decode( aStream, &result );
    return result;
  }
  CATCH_BASE64_EXCEPTION()
}


} // namespace encoding
} // namespace zorba
/* vim:set et sw=2 ts=2: */
