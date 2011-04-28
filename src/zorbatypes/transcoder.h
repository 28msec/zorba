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
#ifndef ZORBA_TRANSCODER_H
#define ZORBA_TRANSCODER_H

#include <ostream>

#include <zorba/config.h>
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"


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
protected:
  std::ostream  & os;

  bool            utf16;

#ifndef ZORBA_NO_UNICODE
  UConverter    * conv;
  char            buffer[10];
  int             chars_in_buffer;
  int             chars_expected;
#endif

public:
  transcoder(std::ostream& output_stream, bool in_utf16);

  ~transcoder();

  transcoder& write(const char* str, std::streamsize n)
  {
    if (utf16)
    {
      return write_utf16(str, n);
    }
    else
    {
      os.write(str, n);
      return *this;
    }
  }

  transcoder& operator<<(const zstring& str)
  {
    return write(str.c_str(), (std::streamsize)str.size());
  }

  transcoder& operator<<(const char* str)
  {
    return write(str, (std::streamsize)strlen(str));
  }

  transcoder& operator<<(const char ch)
  {
    if (utf16)
    {
      return write_utf16_char(ch);
    }
    else
    {
      os << ch;
      return *this;
    }
  }

  // Support for manipulators (e.g. tr << flush)
  transcoder& operator<<(transcoder& (*pf)(transcoder&))
  {
    return pf(*this);
  }

  /**
   * Output a byte to the stream without transcoding it.
   *
   * @param ch the byte to be output
   */
  void verbatim(const char ch)
  {
    os << ch;
  }

  transcoder& flush()
  {
    os.flush();
    return *this;
  }

private:
  transcoder& write_utf16(const char* str, std::streamsize n);

  transcoder& write_utf16_char(const char ch);
};


} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
 /* vim:set et sw=2 ts=2: */
