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
#ifndef TRANSCODER_H
#define TRANSCODER_H

#include <ostream>

#include <zorba/config.h>
#include "zorbatypes/rchandle.h"

struct UConverter;
typedef struct UConverter UConverter;

namespace zorba
{

///////////////////////////////////////////////////////////
//                                                       //
//  class transcoder                                     //
//                                                       //
///////////////////////////////////////////////////////////

class ZORBA_DLL_PUBLIC transcoder : public SimpleRCObject
{
public:
  transcoder(std::ostream& output_stream);

  virtual ~transcoder() { } ;

  /**
   * Output a byte to the stream without transcoding it.
   *
   * @param ch the byte to be output
   */
  void verbatim(const char ch);

  virtual transcoder& operator<<(const char* str)
  {
    os << str;
    return *this;
  }

  virtual transcoder& operator<<(const char ch)
  {
    os << ch;
    return *this;
  }

  virtual transcoder& flush()
  {
    os.flush();
    return *this;
  }

  // Support for manipulators (e.g. tr << flush)
  transcoder& operator<<(transcoder& (*pf)(transcoder&))
  {
    return pf(*this);
  }

protected:
  std::ostream& os;
};

#ifndef ZORBA_NO_UNICODE
class ZORBA_DLL_PUBLIC utf8_to_utf16_transcoder : public transcoder
{
public:
  utf8_to_utf16_transcoder(std::ostream& output_stream);

  virtual ~utf8_to_utf16_transcoder();

  virtual utf8_to_utf16_transcoder& operator<<(const char* str);
  virtual utf8_to_utf16_transcoder& operator<<(const char ch);
  utf8_to_utf16_transcoder& operator<<(utf8_to_utf16_transcoder& (*pf)(utf8_to_utf16_transcoder&))
  {
    return pf(*this);
  }

protected:
  UConverter *conv;
  char buffer[10];
  int chars_in_buffer;
  int chars_expected;
};

// Flush manipulator (e.g. tr << flush)
template<class T> T& flush(T& tr)
{
  return tr.flush();
}

#endif//#ifndef ZORBA_NO_UNICODE


} /* namespace zorba */
#endif
