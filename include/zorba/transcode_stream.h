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

#ifndef ZORBA_TRANSCODE_STREAM_API_H
#define ZORBA_TRANSCODE_STREAM_API_H

#include <stdexcept>
#include <streambuf>
#include <string>

#include <zorba/config.h>
#include <zorba/internal/proxy.h>
#include <zorba/internal/unique_ptr.h>

namespace zorba {

typedef internal::ztd::proxy<std::streambuf> proxy_streambuf;

///////////////////////////////////////////////////////////////////////////////

/**
 * A %transcode_streambuf is-a std::streambuf for transcoding character
 * encodings from/to UTF-8 on-the-fly.
 *
 * To use it, replace a stream's streambuf:
 * \code
 *  istream is;
 *  // ...
 *  transcode_streambuf tbuf( "ISO-8859-1", is.rdbuf() );
 *  is.ios::rdbuf( &tbuf );
 * \endcode
 * Note that the %transcode_streambuf must exist for as long as it's being used
 * by the stream.  If you are replacing the streabuf for a stream you did not
 * create, you should set it back to the original streambuf:
 * \code
 *  void f( ostream &os ) {
 *    transcode_streambuf tbuf( "ISO-8859-1", os.rdbuf() );
 *    try {
 *      os.ios::rdbuf( &tbuf );
 *      // ...
 *    }
 *    catch ( ... ) {
 *      os.ios::rdbuf( tbuf.orig_streambuf() );
 *      throw;
 *    }
 *  }
 * \endcode
 *
 * While %transcode_streambuf does support seeking, the positions are relative
 * to the original byte stream.
 */
class ZORBA_DLL_PUBLIC transcode_streambuf : public std::streambuf {
public:
  /**
   * Constructs a %transcode_streambuf.
   *
   * @param charset The name of the character encoding to convert from/to.
   * @param orig The original streambuf to read/write from/to.
   * @throws std::invalid_argument if either \a charset is not supported or
   * \a orig is null.
   */
  transcode_streambuf( char const *charset, std::streambuf *orig );

  /**
   * Destructs a %transcode_streambuf.
   */
  ~transcode_streambuf();

  /**
   * Gets the original streambuf.
   *
   * @return Returns said streambuf.
   */
  std::streambuf* orig_streambuf() const {
    return proxy_buf_->original();
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
  std::unique_ptr<proxy_streambuf> proxy_buf_;

  // forbid
  transcode_streambuf( transcode_streambuf const& );
  transcode_streambuf& operator=( transcode_streambuf const& );
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A %transcode_stream is used to wrap a C++ standard I/O stream with a
 * transcode_streambuf so that transcoding and the management of the streambuf
 * happens automatically.
 *
 * @tparam StreamType The I/O stream class type to wrap. It must be a concrete
 * stream class, i.e., ifstream, ofstream, istringstream, or ostringstream.
 */
template<class StreamType>
class transcode_stream : public StreamType {
public:
  /**
   * Constructs a %transcode_stream.
   *
   * @param charset The name of the character encoding to convert from/to.
   * @throws std::invalid_argument if \a charset is not supported.
   */
  transcode_stream( char const *charset ) :
    tbuf_( charset, this->rdbuf() )
  {
    init();
  }

  /**
   * Constructs a %transcode_stream.
   *
   * @tparam StreamArgType The type of the first argument of \a StreamType's
   * constructor.
   * @param charset The name of the character encoding to convert from/to.
   * @param stream_arg The argument to pass as the first argument to
   * \a StreamType's constructor.
   * @throws std::invalid_argument if \a charset is not supported.
   */
  template<typename StreamArgType>
  transcode_stream( char const *charset, StreamArgType stream_arg ) :
    StreamType( stream_arg ),
    tbuf_( charset, this->rdbuf() )
  {
    init();
  }

  /**
   * Constructs a %transcode_stream.
   *
   * @tparam StreamArgType The type of the first argument of \a StreamType's
   * constructor.
   * @param charset The name of the character encoding to convert from/to.
   * @param stream_arg The argument to pass as the first argument to
   * @param mode The open-mode to pass to \a StreamType's constructor.
   * \a StreamType's constructor.
   * @throws std::invalid_argument if \a charset is not supported.
   */
  template<typename StreamArgType>
  transcode_stream( char const *charset, StreamArgType stream_arg,
                    std::ios_base::openmode mode ) :
    StreamType( stream_arg, mode ),
    tbuf_( charset, this->rdbuf() )
  {
    init();
  }

private:
  transcode_streambuf tbuf_;

  void init() {
    this->std::ios::rdbuf( &tbuf_ );
  }
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_TRANSCODE_STREAM_API_H */
/* vim:set et sw=2 ts=2: */
