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

#include <zorba/base64.h>

#include <zorba/config.h>
#include <zorba/zorbastring.h>

#include "zorbatypes/binary.h"

namespace zorba { namespace encoding {

String Base64::encode(String& aString) 
{
  std::stringstream lStream;
  lStream << aString;
  return encode(lStream);
}


String Base64::encode(std::istream& aStream) 
{
  return zorba::Base64::encode(aStream).getp();
}

// TODO: once the internal Base64 class is symmetrical
// e.a. for each encode method, there must be a decode one
//String
//Base64::decode(String& aString) {
//  return "";
//}
//
//String
//Base64::decode(std::istream& aStream) {
//  return "";
//}


} /* end namespace encoding */

} /* end namespace zorba */

