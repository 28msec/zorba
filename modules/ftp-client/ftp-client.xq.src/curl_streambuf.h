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
#include <exception>
#include <streambuf>
#include <string>

// libcurl
#include <curl/curl.h>

// Zorba
#include <zorba/config.h>

namespace zorba {
namespace curl {

///////////////////////////////////////////////////////////////////////////////

class exception : public std::exception {
public:
  exception( char const *function, char const *uri, char const *msg = 0 );
  exception( char const *function, char const *uri, CURLcode code );
  exception( char const *function, char const *uri, CURLMcode code );
  ~exception() throw();

  virtual const char* what() const throw();

private:
  std::string msg_;
};

////////// create & destroy ///////////////////////////////////////////////////

/**
 * The signature type of cURL's write function callback.
 */
typedef size_t (*io_fn_type)( void*, size_t, size_t, void* );

/**
 * Creates a new, initialized cURL instance.
 *
 * @param read_fn The function to use for reading data locally that cURL
 * writes (uploads).
 * @param write_fn The function to use for writing data locally that cURL
 * reads (downloads).
 * @param data User data to use (usually \c this).
 * @throws exception upon failure.
 */
CURL* create( char const *uri, io_fn_type write_fn, io_fn_type read_fn,
              void *data );

/**
 * Destroys a cURL instance.
 *
 * @param instance A cURL instance.  If \c NULL, does nothing.
 */
void destroy( CURL *instance );

////////// streambuf //////////////////////////////////////////////////////////

/**
 * A curl::streambuf is-a std::streambuf for streaming the contents of URI
 * using cURL.  However, do not use this class directly.  Use uri::streambuf
 * instead.
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

protected:
  // inherited
  int_type overflow( int_type );
  std::streamsize showmanyc();
  int_type underflow();
  std::streamsize xsgetn( char_type*, std::streamsize );
  //std::streamsize xsputn( char_type const*, std::streamsize );

private:
  void curl_io( size_t* );
  static size_t curl_read_callback( void*, size_t, size_t, void* );
  void curl_write();
  static size_t curl_write_callback( void*, size_t, size_t, void* );
  void init();
  void init_curlm();

  struct gbuf {
    char *ptr_;
    size_t capacity_, len_;
    gbuf() : ptr_( 0 ), capacity_( 0 ), len_( 0 ) { }
    ~gbuf();
  };

  struct pbuf {
    char ptr_[ 4096 ];
    size_t curl_read_;

    pbuf() : curl_read_( 0 ) { }
  };

  gbuf gbuf_;
  CURL *curl_;
  CURLM *curlm_;
  int curl_running_;
  pbuf pbuf_;

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
