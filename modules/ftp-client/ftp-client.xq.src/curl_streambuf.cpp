/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#include <zorba/config.h>

#include <algorithm>
#include <cstdlib>
#include <cstring>                      /* for memcpy(3) */
#include <iostream>
#include <cassert>
#ifndef WIN32
#include <cerrno>
#include <sys/time.h>
#endif /* WIN32 */

#include <curl/multi.h>

#include "curl_streambuf.h"

using namespace std;

namespace zorba {
namespace curl {

///////////////////////////////////////////////////////////////////////////////

#define ZORBA_CURL_ASSERT(expr)                         \
  do {                                                  \
    if ( CURLcode const code##__LINE__ = (expr) )       \
      throw exception( #expr, "", code##__LINE__ );     \
  } while (0)

#define ZORBA_CURLM_ASSERT(expr)                        \
  do {                                                  \
    if ( CURLMcode const code##__LINE__ = (expr) )      \
      if ( code##__LINE__ != CURLM_CALL_MULTI_PERFORM ) \
        throw exception( #expr, "", code##__LINE__ );   \
  } while (0)

exception::exception( char const *function, char const *uri, char const *msg ) :
  std::exception(), msg_( msg )
{
}

exception::exception( char const *function, char const *uri, CURLcode code ) :
  std::exception(),
  msg_( curl_easy_strerror( code ) )
{
}

exception::exception( char const *function, char const *uri, CURLMcode code ) :
  std::exception(),
  msg_( curl_multi_strerror( code ) )
{
}

exception::~exception() throw() {
  // out-of-line since it's virtual
}

const char* exception::what() const throw() {
  return msg_.c_str();
}

///////////////////////////////////////////////////////////////////////////////

CURL* create( char const *uri, io_fn_type read_fn, io_fn_type write_fn,
              void *data ) {
  //
  // Having cURL initialization wrapped by a class and using a singleton static
  // instance guarantees that cURL is initialized exactly once before use and
  // and also is cleaned-up at program termination (when destructors for static
  // objects are called).
  //
  struct curl_initializer {
    curl_initializer() {
      ZORBA_CURL_ASSERT( curl_global_init( CURL_GLOBAL_ALL ) );
    }
    ~curl_initializer() {
      curl_global_cleanup();
    }
  };
  static curl_initializer initializer;

  CURL *const curl = curl_easy_init();
  if ( !curl )
    throw exception( "curl_easy_init()", uri, "" );

  try {
    ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_URL, uri ) );
    ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_READDATA, data ) );
    ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_READFUNCTION, read_fn ) );
    ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_WRITEDATA, data ) );
    ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, write_fn ) );

    // Tells cURL to follow redirects. CURLOPT_MAXREDIRS is by default set to -1
    // thus cURL will do an infinite number of redirects.
    ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_FOLLOWLOCATION, 1 ) );

    //
    // Some servers don't like requests that are made without a user-agent
    // field, so we provide one.
    //
    //ZORBA_CURL_ASSERT(
      //curl_easy_setopt( curl, CURLOPT_USERAGENT, "libcurl-agent/1.0" )
    //);

    return curl;
  }
  catch ( ... ) {
    destroy( curl );
    throw;
  }
}

void destroy( CURL *curl ) {
  if ( curl ) {
    curl_easy_reset( curl );
    curl_easy_cleanup( curl );
  }
}

///////////////////////////////////////////////////////////////////////////////

streambuf::gbuf::~gbuf() {
  free( ptr_ );
}

///////////////////////////////////////////////////////////////////////////////

streambuf::streambuf() {
  init();
}

streambuf::streambuf( char const *uri ) {
  init();
  open( uri );
}

streambuf::streambuf( CURL *curl ) {
  init();
  curl_ = curl;
  ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_READDATA, this ) );
  ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_READFUNCTION, curl_read_callback ) );
  ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_WRITEDATA, this ) );
  ZORBA_CURL_ASSERT( curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, curl_write_callback ) );
  init_curlm();
}

streambuf::~streambuf() {
  close();
#ifdef WIN32
  closesocket( dummy_socket_ );
#endif /* WIN32 */
}

void streambuf::close() {
  if ( curl_ ) {
    if ( curlm_ ) {
      curl_multi_remove_handle( curlm_, curl_ );
      curl_multi_cleanup( curlm_ );
      curlm_ = 0;
    }
    destroy( curl_ );
    curl_ = 0;
  }
}

void streambuf::curl_io( size_t *len_ptr ) {
  *len_ptr = 0;
  while ( curl_running_ && !*len_ptr ) {
    fd_set fd_read, fd_write, fd_except;
    FD_ZERO( &fd_read );
    FD_ZERO( &fd_write );
    FD_ZERO( &fd_except );
    int max_fd = -1;
#ifdef WIN32
    //
    // Windows does not like a call to select where all arguments are 0, so we
    // just add a dummy socket to make the call to select happy.
    //
    FD_SET( dummy_socket_, &fd_read );
#endif /* WIN32 */
    ZORBA_CURLM_ASSERT(
      curl_multi_fdset( curlm_, &fd_read, &fd_write, &fd_except, &max_fd )
    );

    //
    // Note that the fopen.c sample code is unnecessary at best or wrong at
    // worst; see: http://curl.haxx.se/mail/lib-2011-05/0011.html
    //
    timeval timeout;
    long curl_timeout_ms;
    ZORBA_CURLM_ASSERT( curl_multi_timeout( curlm_, &curl_timeout_ms ) );
    if ( curl_timeout_ms > 0 ) {
      timeout.tv_sec  = curl_timeout_ms / 1000;
      timeout.tv_usec = curl_timeout_ms % 1000 * 1000;
    } else {
      //
      // From curl_multi_timeout(3):
      //
      //    Note: if libcurl returns a -1 timeout here, it just means that
      //    libcurl currently has no stored timeout value. You must not wait
      //    too long (more than a few seconds perhaps) before you call
      //    curl_multi_perform() again.
      //
      // So we just pick some not-too-long default.
      //
      timeout.tv_sec  = 1;
      timeout.tv_usec = 0;
    }

    switch ( select( max_fd + 1, &fd_read, &fd_write, &fd_except, &timeout ) ) {
      case -1:                          // select error
#ifdef WIN32
        char err_buf[8];
        sprintf( err_buf, "%d", WSAGetLastError() );
        throw exception( "select()", "", err_buf );
#else
        throw exception( "select()", "", strerror( errno ) );
#endif /* WIN32 */
      case 0:                           // timeout
        // no break;
      default:
        CURLMcode code;
        do {
          code = curl_multi_perform( curlm_, &curl_running_ );
        } while ( code == CURLM_CALL_MULTI_PERFORM );
        ZORBA_CURLM_ASSERT( code );
    } // switch
  } // while
}

size_t streambuf::curl_read_callback( void *ptr, size_t size, size_t nmemb,
                                      void *data ) {
  size *= nmemb;
  streambuf *const that = static_cast<streambuf*>( data );
  size_t const pbuf_len = that->pptr() - that->pbase();
  if ( size > pbuf_len )
    size = pbuf_len;
  ::memcpy( ptr, that->pbase() + that->pbuf_.curl_read_, size );
  that->pbuf_.curl_read_ += size;
  return size;
}

size_t streambuf::curl_write_callback( void *ptr, size_t size, size_t nmemb,
                                       void *data ) {
  size *= nmemb;
  streambuf *const that = static_cast<streambuf*>( data );

  size_t const gbuf_free = that->gbuf_.capacity_ - that->gbuf_.len_;
  if ( size > gbuf_free ) {
    size_t new_capacity = that->gbuf_.capacity_ + size - gbuf_free;
    if ( void *const new_buf = realloc( that->gbuf_.ptr_, new_capacity ) ) {
      that->gbuf_.ptr_ = static_cast<char*>( new_buf );
      that->gbuf_.capacity_ = new_capacity;
    } else
      throw exception( "realloc()", "" );
  }
  ::memcpy( that->gbuf_.ptr_ + that->gbuf_.len_, ptr, size );
  that->gbuf_.len_ += size;
  return size;
}

void streambuf::init() {
  curl_ = 0;
  curlm_ = 0;
  curl_running_ = 0;
#ifdef WIN32
  dummy_socket_ = socket( AF_INET, SOCK_DGRAM, 0 );
  if ( dummy_socket_ == CURL_SOCKET_BAD || dummy_socket_ == INVALID_SOCKET )
    throw exception( "socket()", "" );
#endif /* WIN32 */
}

void streambuf::init_curlm() {
  //
  // Lie about cURL running initially so the while-loop in curl_io() will run
  // at least once.
  //
  curl_running_ = 1;

  //
  // Set the "get" pointer to the end (gptr() == egptr()) so a call to
  // underflow() and initial data read will be triggered.
  //
  gbuf_.len_ = gbuf_.capacity_;
  setg( gbuf_.ptr_, gbuf_.ptr_ + gbuf_.len_, gbuf_.ptr_ + gbuf_.len_ );

  setp( pbuf_.ptr_, pbuf_.ptr_ + sizeof pbuf_.ptr_ );

  //
  // Clean-up has to be done here with try/catch (as opposed to relying on the
  // destructor) because open() can be called from the constructor.  If an
  // exception is thrown, the constructor will not have completed, hence the
  // object will not have been fully constructed; therefore the destructor will
  // not be called.
  //
  try {
    if ( !(curlm_ = curl_multi_init()) )
      throw exception( "curl_multi_init()", "" );
    try {
      ZORBA_CURLM_ASSERT( curl_multi_add_handle( curlm_, curl_ ) );
    }
    catch ( ... ) {
      curl_multi_cleanup( curlm_ );
      curlm_ = 0;
      throw;
    }
  }
  catch ( ... ) {
    destroy( curl_ );
    curl_ = 0;
    throw;
  }
}

void streambuf::open( char const *uri ) {
  curl_ = create( uri, curl_read_callback, curl_write_callback, this );
  init_curlm();
}

streambuf::int_type streambuf::overflow( int_type c ) {
  bool const is_eof = traits_type::eq_int_type( c, traits_type::eof() );
  if ( !is_eof ) {
    *pptr() = traits_type::to_char_type( c );
    pbump( 1 );
  }
  if ( pptr() == epptr() || (is_eof && pptr() > pbase()) ) {
    curl_io( &pbuf_.curl_read_ );
    setp( pbuf_.ptr_, pbuf_.ptr_ + sizeof pbuf_.ptr_ );
  }
  return c;
}

streamsize streambuf::showmanyc() {
  return egptr() - gptr();
}

streambuf::int_type streambuf::underflow() {
  while ( true ) {
    if ( gptr() < egptr() )
      return traits_type::to_int_type( *gptr() );
    curl_io( &gbuf_.len_ );
    if ( !gbuf_.len_ )
      return traits_type::eof();
    setg( gbuf_.ptr_, gbuf_.ptr_, gbuf_.ptr_ + gbuf_.len_ );
  }
}

streamsize streambuf::xsgetn( char_type *to, streamsize size ) {
  streamsize return_size = 0;

  if ( streamsize const gsize = egptr() - gptr() ) {
    streamsize const n = min( gsize, size );
    traits_type::copy( to, gptr(), static_cast<size_t>( n ) );
    gbump( static_cast<int>( n ) );
    to += n;
    size -= n, return_size += n;
  }

  while ( size > 0 ) {
    streamsize const get = min( (streamsize)gbuf_.capacity_, size );
    curl_io( &gbuf_.len_ );
    if ( !gbuf_.len_ )
      break;
    setg( gbuf_.ptr_, gbuf_.ptr_, gbuf_.ptr_ + gbuf_.len_ );
    streamsize const n = min( (streamsize)gbuf_.len_, size );
    traits_type::copy( to, gptr(), n );
    gbump( static_cast<int>( n ) );
    to += n;
    size -= n, return_size += n;
  }
  return return_size;
}

#if 0
streamsize streambuf::xsputn( char_type const *from, streamsize size ) {
  streamsize return_size = 0;

  if ( streamsize psize = epptr() - pptr() ) {
    streamsize const n = min( psize, size );
    // TODO
  }

  return return_size;
}
#endif

///////////////////////////////////////////////////////////////////////////////

} // namespace curl
} // namespace zorba
/* vim:set et sw=2 ts=2: */
