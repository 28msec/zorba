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

#ifndef URI_H
#define URI_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba {

/**
  * @brief A helper class to do uri conversions
  *
  */
class ZORBA_DLL_PUBLIC URIHelper
{
public:
  /**
    * @brief Decodes a file:// URI to a filesystem path in native form.
    *
    * @arg uri A file:// URI.
    * @returns The filesystem path.
    */
  static String decodeFileURI(const String& uri);
  /**
    * @brief Encodes a native filesystem path to a file:// URI.
    *
    * @arg filepath The filesystem path.
    * @returns The encoded URI of the file.
    */
  static String encodeFileURI(const String& filepath);
};

} //namespace zorba

#endif // URI_H
/* vim:set et sw=2 ts=2: */
