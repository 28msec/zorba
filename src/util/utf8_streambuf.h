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

#include <zorba/internal/streambuf.h>

#include "util/utf8_util.h"

namespace zorba {
namespace utf8 {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %utf8::streambuf is-a std::streambuf for validating UTF-8 on-the-fly.
 * To use it, replace a stream's streambuf:
 * \code
 *  istream is;
 *  // ...
 *  utf8::streambuf xbuf( is.rdbuf() );
 *  is.ios::rdbuf( &xbuf );
 * \endcode
 * Note that the %utf8::streambuf must exist for as long as it's being used by
 * the stream.  If you are replacing the streambuf for a stream you did not
 * create, you should set it back to the original streambuf:
 * \code
 *  void f( ostream &os ) {
 *    utf8::streambuf xbuf( os.rdbuf() );
 *    try {
 *      os.ios::rdbuf( &xbuf );
 *      // ...
 *      os.ios::rdbuf( xbuf.original() );
 *    }
 *    catch ( ... ) {
 *      os.ios::rdbuf( xbuf.original() );
 *      throw;
 *    }
 *  }
 * \endcode
 *
 * If an invalid UTF-8 byte sequence is read, then the stream's \c badbit is
 * set.  Hence using a %utf8::streambuf requires rigorous error-checking.
 *
 * However, if exceptions are enabled for the stream, then
 * \c ZXQD0006_INVALID_UTF8_BYTE_SEQUENCE is thrown.  (When enabling exceptions
 * for a stream you didn't create, you should set the exception mask back to
 * the original mask.)
 * \code
 *  istream is;
 *  std::ios::iostate const orig_exceptions = is.exceptions();
 *  try {
 *    is.exceptions( orig_exceptions | ios::badbit );
 *    // ...
 *    is.exceptions( orig_exceptions );
 *  }
 *  catch ( ... ) {
 *    is.exceptions( orig_exceptions );
 *    throw;
 *  }
 * \endcode
 *
 * While %utf8::streambuf does support seeking, the positions must always be on
 * the first byte of a UTF-8 character.
 */
class streambuf : public internal::proxy_streambuf {
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

  /**
   * If an invalid UTF-8 byte sequence was read, resynchronizes by skipping
   * bytes until a new UTF-8 start byte is encountered.
   */
  void resync();

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
  struct buf_type {
    encoded_char_type utf8_char_;
    size_type char_len_;
    size_type cur_len_;

    void clear();
    void throw_invalid_utf8( storage_type *buf, size_type len );
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

std::streambuf* alloc_streambuf( std::streambuf *orig );

int get_streambuf_index();

///////////////////////////////////////////////////////////////////////////////

/**
 * Attaches a utf8::streambuf to a stream.  Unlike using a
 * utf8::streambuf directly, this function will create the streambuf,
 * attach it to the stream, and manage it for the lifetime of the stream
 * automatically.
 *
 * @param ios The stream to attach the utf8::streambuf to.  If the stream
 * already has a utf8::streambuf attached to it, this function does
 * nothing.
 */
template<typename charT,class Traits> inline
void attach( std::basic_ios<charT,Traits> &ios ) {
  int const index = get_streambuf_index();
  void *&pword = ios.pword( index );
  if ( !pword ) {
    std::streambuf *const buf = alloc_streambuf( ios.rdbuf() );
    ios.rdbuf( buf );
    pword = buf;
    ios.register_callback( internal::stream_callback, index );
  }
}

/**
 * Detaches a previously attached utf8::streambuf from a stream.  The streambuf
 * is destroyed and the stream's original streambuf is restored.
 *
 * @param ios The stream to detach the utf8::streambuf from.  If the stream
 * doesn't have a utf8::streambuf attached to it, this function does nothing.
 */
template<typename charT,class Traits> inline
void detach( std::basic_ios<charT,Traits> &ios ) {
  int const index = get_streambuf_index();
  if ( streambuf *const buf = static_cast<streambuf*>( ios.pword( index ) ) ) {
    ios.pword( index ) = 0;
    ios.rdbuf( buf->original() );
    internal::dealloc_streambuf( buf );
  }
}

/**
 * Checks whether the given stream has a utf8::streambuf attached.
 *
 * @param ios The stream to check.
 * @return \c true only if a utf8::streambuf is attached.
 */
template<typename charT,class Traits> inline
bool is_attached( std::basic_ios<charT,Traits> &ios ) {
  return !!ios.pword( get_streambuf_index() );
}

/**
 * A %utf8::auto_attach is a class that attaches a utf8::streambuf to a stream
 * and automatically detaches it when the %auto_attach object is destroyed.
 * \code
 *  void f( ostream &os ) {
 *    utf8::auto_attach<ostream> const raii( os );
 *    // ...
 *  }
 * \endcode
 * A %utf8::auto_attach is useful for streams not created by you.
 *
 * @see http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization
 */
template<class StreamType>
class auto_attach {
public:
  /**
   * Constructs an %auto_attach object calling attach() on the given stream.
   *
   * @param stream The stream to attach the utf8::streambuf to.  If the stream
   * already has a utf8::streambuf attached to it, this contructor does
   * nothing.
   */
  auto_attach( StreamType &stream ) : stream_( stream ) {
    attach( stream );
  }

  /**
   * Destroys this %auto_attach object calling detach() on the previously
   * attached stream.
   */
  ~auto_attach() {
    detach( stream_ );
  }

private:
  StreamType &stream_;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A %utf8::stream is used to wrap a C++ standard I/O stream with a
 * utf8::streambuf so that encoding/decoding and the management of the
 * streambuf happens automatically.
 *
 * A %utf8::stream is useful for streams created by you.
 *
 * @tparam StreamType The I/O stream class type to wrap. It must be a concrete
 * stream class.
 */
template<class StreamType>
class stream : public StreamType {
public:
  /**
   * Constructs a %utf8::stream.
   */
  stream() :
#ifdef WIN32
# pragma warning( push )
# pragma warning( disable : 4355 )
#endif /* WIN32 */
    utf8_buf_( this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

  /**
   * Constructs a %stream.
   *
   * @tparam StreamArgType The type of the first argument of \a StreamType's
   * constructor.
   * @param stream_arg The argument to pass as the first argument to
   * \a StreamType's constructor.
   */
  template<typename StreamArgType>
  stream( StreamArgType stream_arg ) :
    StreamType( stream_arg ),
#ifdef WIN32
# pragma warning( push )
# pragma warning( disable : 4355 )
#endif /* WIN32 */
    utf8_buf_( this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

  /**
   * Constructs a %utf8::stream.
   *
   * @tparam StreamArgType The type of the first argument of \a StreamType's
   * constructor.
   * @param stream_arg The argument to pass as the first argument to
   * \a StreamType's constructor.
   * @param mode The open-mode to pass to \a StreamType's constructor.
   */
  template<typename StreamArgType>
  stream( StreamArgType stream_arg, std::ios_base::openmode mode ) :
    StreamType( stream_arg, mode ),
#ifdef WIN32
# pragma warning( push )
# pragma warning( disable : 4355 )
#endif /* WIN32 */
    utf8_buf_( this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

private:
  streambuf utf8_buf_;

  void init() {
    this->std::ios::rdbuf( &utf8_buf_ );
  }
};

///////////////////////////////////////////////////////////////////////////////

} // namespace utf8
} // namespace zorba
#endif  /* ZORBA_UTF8_STREAMBUF_H */
/* vim:set et sw=2 ts=2: */
