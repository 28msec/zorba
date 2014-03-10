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

#ifndef ZORBA_HEXBINARY_STREAM_API_H
#define ZORBA_HEXBINARY_STREAM_API_H

#include <streambuf>

#include <zorba/config.h>
#include <zorba/internal/cxx_util.h>
#include <zorba/internal/streambuf.h>

namespace zorba {
namespace hexbinary {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %hexbinary::streambuf is-a std::streambuf for encoding to and decoding
 * from HexBinary on-the-fly.
 *
 * To use it, replace a stream's streambuf:
 * \code
 *  istream is;
 *  // ...
 *  hexbinary::streambuf hb_buf( is.rdbuf() );
 *  is.ios::rdbuf( &hb_buf );
 * \endcode
 * Note that the %hexbinary::streambuf must exist for as long as it's being
 * used by the stream.  If you are replacing the streabuf for a stream you did
 * not create, you should set it back to the original streambuf:
 * \code
 *  void f( ostream &os ) {
 *    hexbinary::streambuf hb_buf( os.rdbuf() );
 *    try {
 *      os.ios::rdbuf( &hb_buf );
 *      // ...
 *    }
 *    catch ( ... ) {
 *      os.ios::rdbuf( hb_buf.orig_streambuf() );
 *      throw;
 *    }
 *    os.ios::rdbuf( hb_buf.orig_streambuf() );
 *  }
 * \endcode
 * Alternatively, you may wish to use either \c attach(), \c auto_attach, or
 * \c hexbinary::stream instead.
 *
 * While %hexbinary::streambuf does support seeking, the positions are relative
 * to the original byte stream.
 */
class ZORBA_DLL_PUBLIC streambuf : public std::streambuf {
public:
  /**
   * Constructs a %hexbinary::streambuf.
   *
   * @param orig The original streambuf to read/write from/to.
   * @throws std::invalid_argument if is not supported or \a orig is null.
   */
  streambuf( std::streambuf *orig );

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
  int_type overflow( int_type );
  int_type pbackfail( int_type );
  int_type underflow();
  std::streamsize xsgetn( char_type*, std::streamsize );
  std::streamsize xsputn( char_type const*, std::streamsize );

private:
  std::streambuf *const orig_buf_;
  char gbuf_[2];

  void clear();

  // forbid
  streambuf( streambuf const& );
  streambuf& operator=( streambuf const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace hexbinary

namespace internal {
namespace hexbinary {

ZORBA_DLL_PUBLIC
std::streambuf* alloc_streambuf( std::streambuf *orig );

ZORBA_DLL_PUBLIC
int get_streambuf_index();

} // namespace hexbinary
} // namespace internal

namespace hexbinary {

///////////////////////////////////////////////////////////////////////////////

/**
 * Attaches a hexbinary::streambuf to a stream.  Unlike using a
 * hexbinary::streambuf directly, this function will create the streambuf,
 * attach it to the stream, and manage it for the lifetime of the stream
 * automatically.
 *
 * @param ios The stream to attach the hexbinary::streambuf to.  If the stream
 * already has a hexbinary::streambuf attached to it, this function does
 * nothing.
 * @return \c true only if a hexbinary::streambuf was attached.
 */
template<typename charT,class Traits> inline
bool attach( std::basic_ios<charT,Traits> &ios ) {
  int const index = internal::hexbinary::get_streambuf_index();
  void *&pword = ios.pword( index );
  if ( !pword ) {
    std::streambuf *const buf =
      internal::hexbinary::alloc_streambuf( ios.rdbuf() );
    ios.rdbuf( buf );
    pword = buf;
    ios.register_callback( internal::stream_callback, index );
    return true;
  }
  return false;
}

/**
 * Detaches a previously attached hexbinary::streambuf from a stream.  The
 * streambuf is destroyed and the stream's original streambuf is restored.
 *
 * @param ios The stream to detach the hexbinary::streambuf from.  If the
 * stream doesn't have a hexbinary::streambuf attached to it, this function
 * does nothing.
 * @return \c true only if a hexbinary::streambuf was detached.
 */
template<typename charT,class Traits> inline
bool detach( std::basic_ios<charT,Traits> &ios ) {
  int const index = internal::hexbinary::get_streambuf_index();
  if ( streambuf *const buf = static_cast<streambuf*>( ios.pword( index ) ) ) {
    ios.pword( index ) = nullptr;
    ios.rdbuf( buf->orig_streambuf() );
    internal::dealloc_streambuf( buf );
    return true;
  }
  return false;
}

/**
 * Checks whether the given stream has a hexbinary::streambuf attached.
 *
 * @param ios The stream to check.
 * @return \c true only if a hexbinary::streambuf is attached.
 */
template<typename charT,class Traits> inline
bool is_attached( std::basic_ios<charT,Traits> &ios ) {
  return !!ios.pword( internal::hexbinary::get_streambuf_index() );
}

/**
 * A %hexbinary::auto_attach is a class that attaches a hexbinary::streambuf to
 * a stream and automatically detaches it when the %auto_attach object is
 * destroyed.
 * \code
 *  void f( ostream &os ) {
 *    hexbinary::auto_attach<ostream> const raii( os );
 *    // ...
 *  }
 * \endcode
 * A %hexbinary::auto_attach is useful for streams not created by you.
 *
 * @see http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization
 */
template<class StreamType>
class auto_attach {
public:
  /**
   * Default constructor; does nothing.
   */
  auto_attach() : stream_( nullptr ) {
  }

  /**
   * Constructs an %auto_attach object calling attach() on the given stream.
   *
   * @param stream The stream to attach the hexbinary::streambuf to.  If the
   * stream already has a hexbinary::streambuf attached to it, this contructor
   * does nothing.
   */
  auto_attach( StreamType &stream ) : stream_( &stream ) {
    attach( stream );
  }

  /**
   * Copy constructor that takes ownership of the stream.
   *
   * @param from The %auto_attach to take ownership from.
   */
  auto_attach( auto_attach &from ) : stream_( from.stream_ ) {
    from.stream_ = nullptr;
  }

  /**
   * Destroys this %auto_attach object calling detach() on the previously
   * attached stream.
   */
  ~auto_attach() {
    detach();
  }

  /**
   * Assignment operator that takes ownership of the stream.
   *
   * @param from The %auto_attach to take ownership from.
   * @return \c *this.
   */
  auto_attach& operator=( auto_attach &from ) {
    if ( &from != this ) {
      stream_ = from.stream_;
      from.stream_ = nullptr;
    }
    return *this;
  }

  /**
   * Calls hexbinary::attach() on the given stream.
   *
   * @param stream The stream to attach the hexbinary::streambuf to.  If the
   * stream already has a hexbinary::streambuf attached to it, this contructor
   * does nothing.
   * @return \c true only if a hexbinary::streambuf was attached.
   */
  bool attach( StreamType &stream ) {
    if ( hexbinary::attach( stream ) ) {
      stream_ = &stream;
      return true;
    }
    return false;
  }

  /**
   * Calls hexbinary::detach().
   */
  void detach() {
    if ( stream_ ) {
      hexbinary::detach( *stream_ );
      stream_ = nullptr;
    }
  }

private:
  StreamType *stream_;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A %hexbinary::stream is used to wrap a C++ standard I/O stream with a
 * hexbinary::streambuf so that encoding/decoding and the management of the
 * streambuf happens automatically.
 *
 * A %hexbinary::stream is useful for streams created by you.
 *
 * @tparam StreamType The I/O stream class type to wrap. It must be a concrete
 * stream class.
 */
template<class StreamType>
class stream : public StreamType {
public:
  /**
   * Constructs a %hexbinary::stream.
   *
   * Do not use this constructor when StreamType is std::ostream; see
   * http://llvm.org/bugs/show_bug.cgi?id=15337
   */
  stream() :
#ifdef WIN32
# pragma warning( push )
# pragma warning( disable : 4355 )
#endif /* WIN32 */
    hb_buf_( this->rdbuf() )
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
    hb_buf_( this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

  /**
   * Constructs a %hexbinary::stream.
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
    hb_buf_( this->rdbuf() )
#ifdef WIN32
# pragma warning( pop )
#endif /* WIN32 */
  {
    init();
  }

private:
  streambuf hb_buf_;

  void init() {
    this->std::ios::rdbuf( &hb_buf_ );
  }
};

///////////////////////////////////////////////////////////////////////////////

} // namespace hexbinary
} // namespace zorba
#endif  /* ZORBA_HEXBINARY_STREAM_API_H */
/* vim:set et sw=2 ts=2: */
