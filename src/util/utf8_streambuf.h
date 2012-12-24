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

#ifndef ZORBA_UTF8_STREAMBUF_H
#define ZORBA_UTF8_STREAMBUF_H

#include <unicode/ucnv.h>
#include <zorba/transcode_stream.h>

#include "util/utf8_util.h"

namespace zorba {
namespace utf8 {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %utf8::streambuf is-a std::streambuf for validating UTF-8 on-the-fly.
 *
 * To use it, replace a stream's streambuf:
 * \code
 *  istream is;
 *  // ...
 *  utf8::streambuf xbuf( "ISO-8859-1", is.rdbuf() );
 *  is.ios::rdbuf( &xbuf );
 * \endcode
 * Note that the %utf8::streambuf must exist for as long as it's being used by
 * the stream.  If you are replacing the streambuf for a stream you did not
 * create, you should set it back to the original streambuf:
 * \code
 *  void f( ostream &os ) {
 *    utf8::streambuf xbuf( "ISO-8859-1", os.rdbuf() );
 *    try {
 *      os.ios::rdbuf( &xbuf );
 *      // ...
 *    }
 *    catch ( ... ) {
 *      os.ios::rdbuf( xbuf.original() );
 *      throw;
 *    }
 *    os.ios::rdbuf( xbuf.original() );
 *  }
 * \endcode
 *
 * While %utf8::streambuf does support seeking, the positions are relative to
 * the original byte stream.
 */
class streambuf : public proxy_streambuf {
public:
  /**
   * Constructs a %streambuf.
   *
   * @param orig The original streambuf to read/write from/to.
   * @param validate_put If \c true, characters written are validated;
   * if \c false, characters are written without validation, i.e., it's assumed
   * that you're writing valid UTF-8.
   * @throws std::invalid_argument if \a orig is \c null.
   */
  streambuf( std::streambuf *orig, bool validate_put = false );

protected:
  pos_type seekoff( off_type, std::ios_base::seekdir, std::ios_base::openmode );
  pos_type seekpos( pos_type, std::ios_base::openmode );
  std::streambuf* setbuf( char_type*, std::streamsize );
  std::streamsize showmanyc();
  int sync();
  int_type overflow( int_type );
  int_type uflow();
  int_type underflow();
  std::streamsize xsgetn( char_type*, std::streamsize );
  std::streamsize xsputn( char_type const*, std::streamsize );

private:
  struct buf_type {
    encoded_char_type utf8_char_;
    size_type char_len_;
    size_type cur_len_;

    void validate( storage_type, bool bump = true );
  };

  buf_type gbuf_, pbuf_;
  bool const validate_put_;

  void clear();

  // forbid
  streambuf( streambuf const& );
  streambuf& operator=( streambuf const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace utf8
} // namespace zorba
#endif  /* ZORBA_UTF8_STREAMBUF_H */
/* vim:set et sw=2 ts=2: */
