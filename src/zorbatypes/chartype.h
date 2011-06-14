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
#pragma once
#ifndef ZORBA_XML_CHAR_TYPE
#define ZORBA_XML_CHAR_TYPE

#include <zorba/config.h>
#include "common/common.h"

namespace zorba{

class   XQCharType
{
public:
  static bool isLetter(uint32_t cp);
  static bool isBaseChar(uint32_t cp);
  static bool isIdeographic(uint32_t cp);
  static bool isDigit(uint32_t cp);
  static bool isCombiningChar(uint32_t cp);
  static bool isExtender(uint32_t cp);
  static bool isNameChar(uint32_t cp);
};

}//end namespace zorba
#endif
/* vim:set et sw=2 ts=2: */
