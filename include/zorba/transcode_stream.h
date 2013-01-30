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

#include <zorba/config.h>
#include <zorba/internal/streambuf.h>
#include <zorba/internal/unique_ptr.h>

namespace zorba {
namespace transcode {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %transcode::streambuf is-a std::streambuf for transcoding character
 * encodings from/to UTF-8 on-the-fly.
 *
 * To use it, replace a stream's streambuf:
 * \code
 *  istream is;
 *  // ...
 *  transcode::streambuf tbuf( "ISO-8859-1", is.rdbuf() );
 *  is.ios::rdbuf( &tbuf );
 * \endcode
 * Note that the %transcode::streambuf must exist for as long as it's being used
 * by the stream.  If you are replacing the streabuf for a stream you did not
 * create, you should set it back to the original streambuf:
 * \code
 *  void f( ostream &os ) {
 *    transcode::streambuf tbuf( "ISO-8859-1", os.rdbuf() );
 *    try {
 *      os.ios::rdbuf( &tbuf );
 *      // ...
 *    }
 *    catch ( ... ) {
 *      os.ios::rdbuf( tbuf.orig_streambuf() );
 *      throw;
 *    }
 *    os.ios::rdbuf( tbuf.orig_streambuf() );
 *  }
 * \endcode
 * Alternatively, you may wish to use either \c attach(), \c auto_attach, or
 * \c transcode::stream instead.
 *
 * While %transcode::streambuf does support seeking, the positions are relative
 * to the original byte stream.
 */
class ZORBA_DLL_PUBLIC streambuf : public std::streambuf {
public:
  /**
   * Constructs a %transcode::streambuf.
   *
   * @param charset The name of the character encoding to convert from/to.
   * @param orig The original streambuf to read/write from/to.
   * @throws std::invalid_argument if either \a charset is not supported or
   * \a orig is null.
   */
  streambuf( char const *charset, std::streambuf *orig );

  /**
   * Destructs a %transcode::streambuf.
   */
  ~streambuf();

  /**
   * Gets the original streambuf.
   *
   * @return said streambuf.
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
  std::unique_ptr<internal::proxy_streambuf> proxy_buf_;

  // forbid
  streambuf( streambuf const& );
  streambuf& operator=( streambuf const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace transcode

namespace internal {
namespace transcode {

ZORBA_DLL_PUBLIC
std::streambuf* alloc_streambuf( char const *charset, std::streambuf *orig );

ZORBA_DLL_PUBLIC
int get_streambuf_index();

} // transcode
} // namespace internal

namespace transcode {

///////////////////////////////////////////////////////////////////////////////

/**
 * Attaches a transcode::streambuf to a stream.  Unlike using a
 * transcode::streambuf directly, this function will create the streambuf,
 * attach it to the stream, and manage it for the lifetime of the stream
 * automatically.
 *
 * @param ios The stream to attach the transcode::streambuf to.  If the stream
 * already has a transcode::streambuf attached to it, this function does
 * nothing.
 * @param charset The name of the character encoding to convert from/to.
 */
template<typename charT,typename Traits> inline
void attach( std::basic_ios<charT,Traits> &ios, char const *charset ) {
  int const index = internal::transcode::get_streambuf_index();
  void *&pword = ios.pword( index );
  if ( !pword ) {
    std::streambuf *const buf =
      internal::transcode::alloc_streambuf( charset, ios.rdbuf() );
    ios.rdbuf( buf );
    pword = buf;
    ios.register_callback( internal::stream_callback, index );
  }
}

/**
 * Detaches a previously attached transcode::streambuf from a stream.  The
 * streambuf is destroyed and the stream's original streambuf is restored.
 *
 * @param ios The stream to detach the transcode::streambuf from.  If the
 * stream doesn't have a transcode::streambuf attached to it, this function
 * does nothing.
 */
template<typename charT,typename Traits> inline
void detach( std::basic_ios<charT,Traits> &ios ) {
  int const index = internal::transcode::get_streambuf_index();
  if ( streambuf *const buf = static_cast<streambuf*>( ios.pword( index ) ) ) {
    ios.pword( index ) = 0;
    ios.rdbuf( buf->orig_streambuf() );
    internal::dealloc_streambuf( buf );
  }
}

/**
 * Checks whether the given stream has a transcode::streambuf attached.
 *
 * @param ios The stream to check.
 * @return \c true only if a transcode::streambuf is attached.
 */
template<typename charT,typename Traits> inline
bool is_attached( std::basic_ios<charT,Traits> &ios ) {
  return !!ios.pword( internal::transcode::get_streambuf_index() );
}

/**
 * Gets the original streambuf of the given iostream.
 *
 * @param ios The stream to get the original streambuf of.
 * @return the original streambuf.
 */
template<typename charT,typename Traits> inline
std::streambuf* orig_streambuf( std::basic_ios<charT,Traits> &ios ) {
  std::streambuf *const buf = ios.rdbuf();
  if ( streambuf *const tbuf = dynamic_cast<streambuf*>( buf ) )
    return tbuf->orig_streambuf();
  return buf;
}

/**
 * A %transcode::auto_attach is a class that attaches a transcode::streambuf to
 * a stream and automatically detaches it when the %auto_attach object is
 * destroyed.
 * \code
 *  void f( ostream &os ) {
 *    transcode::auto_attach<ostream> const raii( os, "ISO-8859-1" );
 *    // ...
 *  }
 * \endcode
 * A %transcode::auto_attach is useful for streams not created by you.
 *
 * @see http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization
 */
template<class StreamType>
class auto_attach {
public:
  /**
   * Constructs an %auto_attach object calling attach() on the given stream.
   *
   * @param stream The stream to attach the transcode::streambuf to.  If the
   * stream already has a transcode::streambuf attached to it, this contructor
   * does nothing.
   * @param charset The name of the character encoding to convert from/to.
   */
  auto_attach( StreamType &stream, char const *charset ) : stream_( stream ) {
    attach( stream, charset );
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
 * A %transcode::stream is used to wrap a C++ standard I/O stream with a
 * transcode::streambuf so that transcoding and the management of the streambuf
 * happens automatically.
 *
 * A %transcode::stream is useful for streams created by you.
 *
 * @tparam StreamType The I/O stream class type to wrap. It must be a concrete
 * stream class.
 */
template<class StreamType>
class stream : public StreamType {
public:
  /**
   * Constructs a %transcode::stream.
   *
   * @param charset The name of the character encoding to convert from/to.
   * @throws std::invalid_argument if \a charset is not supported.
   */
  stream( char const *charset ) :
#ifdef WIN32
# pragma warning( push )
# pragma warning( disable : 4355 )
#endif /* WIN32 */
    tbuf_( charset, this->rdbuf() )
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
   * @param charset The name of the character encoding to convert from/to.
   * @param stream_arg The argument to pass as the first argument to
   * \a StreamType's constructor.
   * @throws std::invalid_argument if \a charset is not supported.
   */
  template<typename StreamArgType>
  stream( char const *charset, StreamArgType stream_arg ) :
    StreamType( stream_arg ),
#ifdef WIN32
# pragma warning( push )
# pragma warning( disable : 4355 )
#endif /* WIN32 */
    tbuf_( charset, this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

  /**
   * Constructs a %transcode::stream.
   *
   * @tparam StreamArgType The type of the first argument of \a StreamType's
   * constructor.
   * @param charset The name of the character encoding to convert from/to.
   * @param stream_arg The argument to pass as the first argument to
   * \a StreamType's constructor.
   * @param mode The open-mode to pass to \a StreamType's constructor.
   * @throws std::invalid_argument if \a charset is not supported.
   */
  template<typename StreamArgType>
  stream( char const *charset, StreamArgType stream_arg,
          std::ios_base::openmode mode ) :
    StreamType( stream_arg, mode ),
#ifdef WIN32
# pragma warning( push )
# pragma warning( disable : 4355 )
#endif /* WIN32 */
    tbuf_( charset, this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

private:
  streambuf tbuf_;

  void init() {
    this->std::ios::rdbuf( &tbuf_ );
  }
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Checks whether it would be necessary to transcode from the given character
 * encoding to UTF-8.
 *
 * @param charset The name of the character encoding to check.
 * @return \c true only if it would be necessary to transcode from the given
 * character encoding to UTF-8.
 */
ZORBA_DLL_PUBLIC
bool is_necessary( char const *charset );

/**
 * Checks whether the given character set is supported for transcoding.
 *
 * @param charset The name of the character encoding to check.
 * @return \c true only if the character encoding is supported.
 */
ZORBA_DLL_PUBLIC
bool is_supported( char const *charset );

///////////////////////////////////////////////////////////////////////////////

} // namespace transcode
} // namespace zorba
#endif  /* ZORBA_TRANSCODE_STREAM_API_H */
/* vim:set et sw=2 ts=2: */
