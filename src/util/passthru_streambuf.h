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

#include <stdexcept>
#include <streambuf>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %passthru_streambuf is-a std::streambuf TODO
 */
class passthru_streambuf : public std::streambuf {
public:
  /**
   * Placeholder %exception class -- never thrown.
   */
  struct exception : std::exception {
  };

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
   * Clears (resets) the state.
   */
  void clear() { }

  /**
   * Gets the original streambuf.
   *
   * @return Returns said streambuf.
   */
  std::streambuf* orig_streambuf() const {
    return orig_streambuf_;
  }

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
  std::streambuf *const orig_streambuf_;

  // forbid
  passthru_streambuf( passthru_streambuf const& );
  passthru_streambuf& operator=( passthru_streambuf const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_PASSTHRU_STREAMBUF_H */
/* vim:set et sw=2 ts=2: */
