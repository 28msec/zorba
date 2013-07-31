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
#include <zorba/diagnostic_list.h>
#include <zorba/util/hexbinary_util.h>

#include <zorba/config.h>
#include <zorba/zorba_string.h>

#include "diagnostics/dict.h"
#include "diagnostics/xquery_exception.h"
#include "util/hexbinary_util.h"
#define CATCH_HEXBINARY_EXCEPTION()                                     \
  catch (hexbinary::exception const &e)                                 \
  {                                                                     \
    throw XQUERY_EXCEPTION(err::FORG0001,                               \
    ERROR_PARAMS(ZED(FORG0001_BadHexDigit_2),  e.invalid_char()));    \
  }                                                                     \
  catch (std::invalid_argument const&)                                  \
  {                                                                     \
    throw XQUERY_EXCEPTION(err::FORG0001,                               \
    ERROR_PARAMS(ZED(FORG0001_HexBinaryMustBeEven)));                       \
  }

using namespace std;

namespace zorba {
namespace hexbinary {

///////////////////////////////////////////////////////////////////////////////

String encode(String const &aString ) {
  String result;
  encode( aString.data(), aString.size(), &result );
  return result;
}

String encode( istream& aStream ) {
  String result;
  encode( aStream, &result );
  return result;
}


String decode( String const &aString ) {
  try {
    String result;
    decode( aString.data(), aString.size(), &result, dopt_ignore_ws );
    return result;
  }
  CATCH_HEXBINARY_EXCEPTION()
}


String decode( istream &aStream ) {
  try {
    String result;
    decode( aStream, &result, dopt_ignore_ws );
    return result;
  }
  CATCH_HEXBINARY_EXCEPTION()
}

///////////////////////////////////////////////////////////////////////////////

} // namespace hexbinary
} // namespace zorba
/* vim:set et sw=2 ts=2: */
