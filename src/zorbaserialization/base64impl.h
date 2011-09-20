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
#ifndef ZORBA_BASE64_IMPLEMENTATION
#define ZORBA_BASE64_IMPLEMENTATION

#include <stdlib.h>

namespace zorba{
  namespace serialization{

class Base64Impl
{
public:
  static const char base64chars[];
public:
  static size_t Encode(const unsigned char *datain, size_t datalen,
			    char *dataout);///pre-allocated at the right size
  static size_t  Decode(const unsigned char *datain, size_t datalen,
			  unsigned char *dataout);
protected:
  static unsigned char getChar6BitIndex(char c);
};

}}
#endif
/* vim:set et sw=2 ts=2: */
