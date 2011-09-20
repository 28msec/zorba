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

#include <zorba/config.h>
#include <zorba/zorba_string.h>

#include "zorbatypes/binary.h"


namespace zorba {
namespace encoding {

String Base64::encode(const String& aString) 
{
  std::stringstream lStream;
  lStream << aString;

  return encode(lStream);
}


String Base64::encode(std::istream& aStream) 
{
  return zorba::Base64::encode(aStream).str();
}


String Base64::decode(const String& aString)
{
  std::stringstream lStream;
  lStream << aString;
  return decode(lStream);
}


String Base64::decode(std::istream& aStream)
{
  return zorba::Base64::decode(aStream).str();
}


} /* end namespace encoding */
} /* end namespace zorba */
/* vim:set et sw=2 ts=2: */
