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

#ifndef ZORBA_ICU_STREAMBUF_H
#define ZORBA_ICU_STREAMBUF_H

#include <zorba/transcode_streambuf.h>

#include "util/utf8_util.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %icu_streambuf is-a std::streambuf for transcoding character encodings
 * from/to UTF-8 on-the-fly.
 *
 * To use it, replace a stream's streambuf:
 * \code
 *  istream is;
 *  // ...
 *  icu_streambuf xbuf( "ISO-8859-1", is.rdbuf() );
 *  is.ios::rdbuf( &xbuf );
 * \endcode
 * Note that the %icu_streambuf must exist for as long as it's being used by
 * the stream.  If you are replacing the streabuf for a stream you did not
 * create, you should set it back to the original streambuf:
 * \code
 *  void f( ostream &os ) {
 *    icu_streambuf xbuf( "ISO-8859-1", os.rdbuf() );
 *    try {
 *      os.ios::rdbuf( &xbuf );
 *      // ...
 *    }
 *    catch ( ... ) {
 *      os.ios::rdbuf( xbuf.original() );
 *      throw;
 *    }
 *  }
 * \endcode
 *
 * While %icu_streambuf does support seeking, the positions are relative to the
 * original byte stream.
 */
class icu_streambuf : public proxy_streambuf {
public:
  /**
   * Constructs an %icu_streambuf.
   *
   * @param charset The name of the character encoding to convert from/to.
   * @param orig The original streambuf to read/write from/to.
   */
  icu_streambuf( char const *charset, std::streambuf *orig );

  /**
   * Destructs an %icu_streambuf.
   */
  ~icu_streambuf();

protected:
  pos_type seekoff( off_type, std::ios_base::seekdir, std::ios_base::openmode );
  pos_type seekpos( pos_type, std::ios_base::openmode );
  std::streambuf* setbuf( char_type*, std::streamsize );
  int sync();
  int_type overflow( int_type );
  int_type underflow();
  std::streamsize xsgetn( char_type*, std::streamsize );
  std::streamsize xsputn( char_type const*, std::streamsize );

private:
  struct buf_type_base {
    UChar pivot_buf_[ 4096 ], *pivot_source_, *pivot_target_;

    buf_type_base() { reset(); }
    void reset();
  };

  struct gbuf_type : buf_type_base {
    utf8::encoded_char_type utf8_char_;
  };
  gbuf_type g_;

  typedef buf_type_base pbuf_type;
  pbuf_type p_;

  bool const no_conv_;                  // true = no conversion needed
  UConverter *const external_conv_, *const utf8_conv_;

  void clear();
  static UConverter* create_conv( char const *charset );
  void resetg();

  bool to_external( char_type const **from, char_type const *from_end,
                    char **to, char const *to_end, bool flush = false );

  bool to_utf8( char const **from, char const *from_end, char_type **to,
                char_type const *to_end, bool flush = false );

  // forbid
  icu_streambuf( icu_streambuf const& );
  icu_streambuf& operator=( icu_streambuf const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_ICU_STREAMBUF_H */
/* vim:set et sw=2 ts=2: */
