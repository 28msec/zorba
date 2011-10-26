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

#include <cstring>
#include <ostream>

#include <zorba/config.h>

#include "util/utf8_util.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"


namespace zorba {

///////////////////////////////////////////////////////////
//                                                       //
//  class transcoder                                     //
//                                                       //
///////////////////////////////////////////////////////////

class ZORBA_DLL_PUBLIC transcoder : public SimpleRCObject {
protected:
  std::ostream &os;
  bool const utf16;

#ifndef ZORBA_NO_ICU
  utf8::encoded_char_type utf8_buf_;
  int utf8_buf_len_;
  int utf8_char_len_;
#endif /* ZORBA_NO_ICU */

public:
  transcoder(std::ostream& output_stream, bool in_utf16);

  transcoder& write( char const *s, std::streamsize n ) {
#ifndef ZORBA_NO_ICU
    if ( utf16 )
      write_utf16( s, n );
    else
#endif /* ZORBA_NO_ICU */
      os.write( s, n );
    return *this;
  }

  transcoder& operator<<( zstring const &s ) {
    return write( s.data(), (std::streamsize)s.size() );
  }

  transcoder& operator<<( char const *s ) {
    return write( s, (std::streamsize)std::strlen( s ) );
  }

  transcoder& operator<<( char ch ) {
#ifndef ZORBA_NO_ICU
    if ( utf16 )
      write_utf16_char(ch);
    else
#endif /* ZORBA_NO_ICU */
      os << ch;
    return *this;
  }

  // Support for manipulators (e.g. tr << flush)
  transcoder& operator<<( transcoder& (*pf)(transcoder&) ) {
    return pf( *this );
  }

  /**
   * Output a byte to the stream without transcoding it.
   *
   * @param ch the byte to be output
   */
  void verbatim( char ch ) {
    os << ch;
  }

  transcoder& flush() {
    os.flush();
    return *this;
  }

private:
#ifndef ZORBA_NO_ICU
  void write_utf16(const char* str, std::streamsize n);
  void write_utf16_char(char ch);
#endif /* ZORBA_NO_ICU */
};

} // namespace zorba
#endif /* ZORBA_TRANSCODER_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
