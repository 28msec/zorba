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

#ifndef ZORBA_PASSTHRU_STREAMBUF_H
#define ZORBA_PASSTHRU_STREAMBUF_H

//#include <zorba/transcode_streambuf.h>
//#include <util/transcode_streambuf.h>
#include <zorba/transcode_stream.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %passthru_streambuf is-a std::streambuf TODO
 */
class passthru_streambuf : public proxy_streambuf {
public:
  /**
   * Constructs an %passthru_streambuf.
   *
   * @param charset The name of the character encoding to convert from/to.
   * @param orig The original streambuf to read/write from/to.
   */
  passthru_streambuf( char const *charset, std::streambuf *orig );

  /**
   * Destructs an %passthru_streambuf.
   */
  ~passthru_streambuf();

  /**
   * Checks whether the given character set is supported for transcoding.
   *
   * @param charset The name of the character encoding to check.
   * @return \c true only if the character encoding is supported.
   */
  static bool is_supported( char const *charset );
  static bool is_necessary( char const *cc_charset );

  typedef std::streambuf::char_type char_type;
  typedef std::streambuf::int_type int_type;
  typedef std::streambuf::off_type off_type;
  typedef std::streambuf::pos_type pos_type;
  typedef std::streambuf::traits_type traits_type;

protected:
  void imbue( std::locale const& );
  pos_type seekoff( off_type, std::ios_base::seekdir, std::ios_base::openmode );
  pos_type seekpos( pos_type, std::ios_base::openmode );
  std::streambuf* setbuf( char_type*, std::streamsize );
  std::streamsize showmanyc();
  int sync();
  int_type overflow( int_type );
  int_type pbackfail( int_type );
  int_type uflow();
  int_type underflow();
  std::streamsize xsgetn( char_type*, std::streamsize );
  std::streamsize xsputn( char_type const*, std::streamsize );

private:
  // forbid
  passthru_streambuf( passthru_streambuf const& );
  passthru_streambuf& operator=( passthru_streambuf const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_PASSTHRU_STREAMBUF_H */
/* vim:set et sw=2 ts=2: */
