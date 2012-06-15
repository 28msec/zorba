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

#ifndef ZORBA_BASE64_STREAM_API_H
#define ZORBA_BASE64_STREAM_API_H

#include <streambuf>

#include <zorba/config.h>
#include <zorba/internal/streambuf.h>

namespace zorba {
namespace base64 {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %base64::streambuf is-a std::streambuf for encoding to and decoding from
 * Base64 on-the-fly.
 *
 * To use it, replace a stream's streambuf:
 * \code
 *  istream is;
 *  // ...
 *  base64::streambuf b64buf( is.rdbuf() );
 *  is.ios::rdbuf( &b64buf );
 * \endcode
 * Note that the %base64::streambuf must exist for as long as it's being used
 * by the stream.  If you are replacing the streabuf for a stream you did not
 * create, you should set it back to the original streambuf:
 * \code
 *  void f( ostream &os ) {
 *    base64::streambuf b64buf( os.rdbuf() );
 *    try {
 *      os.ios::rdbuf( &b64buf );
 *      // ...
 *    }
 *    catch ( ... ) {
 *      os.ios::rdbuf( b64buf.orig_streambuf() );
 *      throw;
 *    }
 *    os.ios::rdbuf( b64buf.orig_streambuf() );
 *  }
 * \endcode
 * Alternatively, you may wish to use either \c attach(), \c auto_attach, or
 * \c base64::stream instead.
 *
 * \b Note: due to the nature of Base64-encoding, when writing, you \e must
 * ensure that the streambuf is flushed (by calling either \c pubsync() on the
 * streambuf or \c flush() on the owning stream) when done.
 *
 * While %base64::streambuf does support seeking, the positions are relative
 * to the original byte stream.
 */
class ZORBA_DLL_PUBLIC streambuf : public std::streambuf {
public:
  /**
   * Constructs a %base64::streambuf.
   *
   * @param orig The original streambuf to read/write from/to.
   * @throws std::invalid_argument if is not supported or \a orig is null.
   */
  streambuf( std::streambuf *orig );

  /**
   * Destructs a %base64::streambuf.
   */
  ~streambuf();

  /**
   * Gets the original streambuf.
   *
   * @return said streambuf.
   */
  std::streambuf* orig_streambuf() const {
    return orig_buf_;
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
  int_type underflow();
  std::streamsize xsgetn( char_type*, std::streamsize );
  std::streamsize xsputn( char_type const*, std::streamsize );

private:
  std::streambuf *orig_buf_;

  char gbuf_[3];
  char pbuf_[3];
  int plen_;

  void clear();
  void resetg();
  void resetp();
  void writep();

  // forbid
  streambuf( streambuf const& );
  streambuf& operator=( streambuf const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace base64

namespace internal {
namespace base64 {

ZORBA_DLL_PUBLIC
std::streambuf* alloc_streambuf( std::streambuf *orig );

ZORBA_DLL_PUBLIC
int get_streambuf_index();

} // namespace base64
} // namespace internal

namespace base64 {

///////////////////////////////////////////////////////////////////////////////

/**
 * Attaches a base64::streambuf to a stream.  Unlike using a
 * base64::streambuf directly, this function will create the streambuf,
 * attach it to the stream, and manage it for the lifetime of the stream
 * automatically.
 *
 * @param ios The stream to attach the base64::streambuf to.  If the stream
 * already has a base64::streambuf attached to it, this function does
 * nothing.
 */
template<typename charT,typename Traits> inline
void attach( std::basic_ios<charT,Traits> &ios ) {
  int const index = internal::base64::get_streambuf_index();
  void *&pword = ios.pword( index );
  if ( !pword ) {
    std::streambuf *const buf =
      internal::base64::alloc_streambuf( ios.rdbuf() );
    ios.rdbuf( buf );
    pword = buf;
    ios.register_callback( internal::stream_callback, index );
  }
}

/**
 * Detaches a previously attached base64::streambuf from a stream.  The
 * streambuf is destroyed and the stream's original streambuf is restored.
 *
 * @param ios The stream to detach the base64::streambuf from.  If the
 * stream doesn't have a base64::streambuf attached to it, this function
 * does nothing.
 */
template<typename charT,typename Traits> inline
void detach( std::basic_ios<charT,Traits> &ios ) {
  int const index = internal::base64::get_streambuf_index();
  if ( streambuf *const buf = static_cast<streambuf*>( ios.pword( index ) ) ) {
    ios.pword( index ) = 0;
    ios.rdbuf( buf->orig_streambuf() );
    internal::dealloc_streambuf( buf );
  }
}

/**
 * Checks whether the given stream has a base64::streambuf attached.
 *
 * @param ios The stream to check.
 * @return \c true only if a base64::streambuf is attached.
 */
template<typename charT,typename Traits> inline
bool is_attached( std::basic_ios<charT,Traits> &ios ) {
  return !!ios.pword( internal::base64::get_streambuf_index() );
}

/**
 * A %base64::auto_attach is a class that attaches a base64::streambuf to
 * a stream and automatically detaches it when the %auto_attach object is
 * destroyed.
 * \code
 *  void f( ostream &os ) {
 *    base64::auto_attach<ostream> const raii( os, "ISO-8859-1" );
 *    // ...
 *  }
 * \endcode
 * A %base64::auto_attach is useful for streams not created by you.
 *
 * @see http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization
 */
template<class StreamType>
class auto_attach {
public:
  /**
   * Constructs an %auto_attach object calling attach() on the given stream.
   *
   * @param stream The stream to attach the base64::streambuf to.  If the
   * stream already has a base64::streambuf attached to it, this contructor
   * does nothing.
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
 * A %base64::stream is used to wrap a C++ standard I/O stream with a
 * base64::streambuf so that encoding/decoding and the management of the
 * streambuf happens automatically.
 *
 * A %base64::stream is useful for streams created by you.
 *
 * @tparam StreamType The I/O stream class type to wrap. It must be a concrete
 * stream class.
 */
template<class StreamType>
class stream : public StreamType {
public:
  /**
   * Constructs a %base64::stream.
   */
  stream() :
#ifdef WIN32
# pragma warning( push )
# pragma warning( disable : 4355 )
#endif /* WIN32 */
    b64buf_( this->rdbuf() )
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
    b64buf_( this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

  /**
   * Constructs a %base64::stream.
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
    b64buf_( this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

private:
  streambuf b64buf_;

  void init() {
    this->std::ios::rdbuf( &b64buf_ );
  }
};

///////////////////////////////////////////////////////////////////////////////

} // namespace base64
} // namespace zorba
#endif  /* ZORBA_BASE64_STREAM_API_H */
/* vim:set et sw=2 ts=2: */
