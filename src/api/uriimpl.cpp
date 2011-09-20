/*
 * Copyright 2006-2010 The FLWOR Foundation.
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

#include <zorba/util/uri.h>
#include <zorba/zorba_string.h>

#include <zorbatypes/URI.h>
#include <zorbatypes/zstring.h>

#include <api/unmarshaller.h>

namespace zorba {

String URIHelper::decodeFileURI(const String& uri)
{
  zstring lURI = Unmarshaller::getInternalString(uri);
  zstring lFileURI;
  URI::decode_file_URI(lURI, lFileURI);
  return Unmarshaller::newString(lFileURI);
}

String URIHelper::encodeFileURI(const String &fileUri)
{
  zstring lFileUri = Unmarshaller::getInternalString(fileUri);
  zstring lUri;
  URI::encode_file_URI(lFileUri, lUri);
  return Unmarshaller::newString(lUri);
}

} //namespace zorba
/* vim:set et sw=2 ts=2: */
