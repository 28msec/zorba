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
#pragma once
#ifndef ZORBA_CURL_UTIL_H
#define ZORBA_CURL_UTIL_H

// standard
#include <cstdlib>
#include <exception>
#include <streambuf>
#include <string>
#ifdef WIN32
#include <windows.h>
#endif /* WIN32 */

// libcurl
#include <curl/curl.h>

// Zorba
#include <zorba/util/fs_util.h>

namespace zorba {
namespace curl {

///////////////////////////////////////////////////////////////////////////////

/**
 * If defined, all calls to cURL wrapped by either ZORBA_CURL_ASSERT() or
 * ZORBA_CURLM_ASSERT() will be printed to standard error.
 */
//#define ZORBA_TRACE_LIBCURL_CALLS 1

#ifdef ZORBA_TRACE_LIBCURL_CALLS
# define ZORBA_CURL_ECHO(CURL_FN) \
  std::cerr << zorba::fs::base_name( __FILE__ ) << ':' << __LINE__ << ": " << #CURL_FN << std::endl
#else
# define ZORBA_CURL_ECHO(CURL_FN) (void)0
#endif /* ZORBA_TRACE_LIBCURL_CALLS */

#define ZORBA_CURL_ASSERT(EXPR)                                   \
  do {                                                            \
    ZORBA_CURL_ECHO( EXPR );                                      \
    if ( CURLcode const code##__LINE__ = (EXPR) )                 \
      throw zorba::curl::exception( #EXPR, "", code##__LINE__ );  \
  } while (0)

#define ZORBA_CURLM_ASSERT(EXPR)                                    \
  do {                                                              \
    ZORBA_CURL_ECHO( EXPR );                                        \
    if ( CURLMcode const code##__LINE__ = (EXPR) )                  \
      if ( code##__LINE__ != CURLM_CALL_MULTI_PERFORM )             \
        throw zorba::curl::exception( #EXPR, "", code##__LINE__ );  \
  } while (0)

////////// exception //////////////////////////////////////////////////////////

class exception : public std::exception {
public:
  exception( char const *function, char const *uri, char const *msg = 0 );
  exception( char const *function, char const *uri, CURLcode code );
  exception( char const *function, char const *uri, CURLMcode code );
  ~exception() throw();

  CURLcode curl_code() const {
    return curl_code_;
  }

  CURLMcode curlm_code() const {
    return curlm_code_;
  }

  // inherited
  virtual const char* what() const throw();

private:
  CURLcode curl_code_;
  CURLMcode curlm_code_;
  std::string msg_;
};

////////// streambuf //////////////////////////////////////////////////////////

/**
 * A curl::streambuf is-a std::streambuf for streaming the contents of URI
 * using cURL.
 */
class streambuf : public std::streambuf {
public:
  /**
   * Constructs a %streambuf.
   */
  streambuf();

  /**
   * Constructs a %streambuf and opens a connection to the server hosting the
   * given URI for subsequent streaming.
   *
   * @param uri The URI to stream.
   */
  streambuf( char const *uri );

  /**
   * Constructs a %streambuf using an existing CURL object.
   *
   * @param curl The CURL object to use.  This %streambuf takes ownership of
   * it.
   */
  streambuf( CURL *curl );

  /**
   * Destroys a %streambuf.
   */
  ~streambuf();

  /**
   * Opens a connection to the server hosting the given URI for subsequent
   * streaming.
   *
   * @param uri The URI to stream.
   * @throws exception upon failure.
   */
  void open( char const *uri );

  /**
   * Tests whether the buffer is open.
   *
   * @return Returns \c true only if the buffer is open.
   */
  bool is_open() const {
    return !!curl_;
  }

  /**
   * Closes this %streambuf.
   */
  void close();

  /**
   * Gets the CURL object in use.
   *
   * @return Return said CURL object.
   */
  CURL* curl() const {
    return curl_;
  }

  /**
   * Gets the CURLM object in use.
   *
   * @return Return said CURLM object.
   */
  CURLM* curlm() const {
    return curlm_;
  }

  /**
   * Resets all options on the CURL object in use.
   */
  void curl_reset() {
    curl_init();
  }

  /**
   * Sets/clears CURL verbose mode.
   *
   * @param verbose If \c true, sets verbose mode; otherwise clears it.
   */
  void curl_verbose( bool verbose );

protected:
  // inherited
  std::streamsize showmanyc();
  int_type underflow();
  std::streamsize xsgetn( char_type*, std::streamsize );

private:
  void curl_create();
  void curl_destroy();
  void curl_init();
  void curlm_init();
  void curl_io( size_t* );
  void curl_write();
  static size_t curl_write_callback( void*, size_t, size_t, void* );
  void init();

  struct gbuf {
    char *ptr_;
    size_t capacity_, len_;
    gbuf() : ptr_( 0 ), capacity_( 0 ), len_( 0 ) { }
    ~gbuf() { free( ptr_ ); }
  };

  CURL *curl_;
  CURLM *curlm_;
  int curl_running_;
  gbuf gbuf_;
  bool verbose_;

  // forbid
  streambuf( streambuf const& );
  streambuf& operator=( streambuf const& );
#ifdef WIN32
  SOCKET dummy_socket_;
#endif /* WIN32 */
};

///////////////////////////////////////////////////////////////////////////////

} // namespace curl
} // namespace zorba
#endif /* ZORBA_CURL_UTIL_H */
/* vim:set et sw=2 ts=2: */
