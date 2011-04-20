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

#include <stdio.h>
#include <streambuf>
#include <istream>

#ifndef STRING_ITERATOR_TO_STREAMBUF_IMPL
#define STRING_ITERATOR_TO_STREAMBUF_IMPL

namespace zorba{

class StringIteratorStreamBuf : public std::streambuf
{
  std::string  buffer[2];
  int          current_buffer;
  int          last_buffer;
  std::streampos    begin_offset;
  bool         is_eof;
public:
  StringIteratorStreamBuf();
  virtual ~StringIteratorStreamBuf() {}

  virtual int underflow ( );
  virtual int pbackfail ( int c = EOF );

  virtual std::streampos seekoff ( std::streamoff off, std::ios_base::seekdir way, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );
  virtual std::streampos seekpos ( std::streampos sp, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out );

public:
  virtual bool next(std::string &next_string) = 0;
  virtual bool reset() = 0;
};

}
#endif
