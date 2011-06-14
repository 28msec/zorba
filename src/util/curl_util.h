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
#pragma once
#ifndef ZORBA_CURL_UTIL_H
#define ZORBA_CURL_UTIL_H

#include <zorba/config.h>

#ifdef ZORBA_WITH_REST

#include <istream>
#include <streambuf>
#include <curl/curl.h>

#include "error_util.h"

namespace zorba {
namespace curl {

////////// create & destroy ///////////////////////////////////////////////////

/**
 * The signature type of cURL's write function callback.
 */
typedef size_t (*write_fn_t)( void*, size_t, size_t, void* );

/**
 * Creates a new, initialized cURL instance.
 *
 * @throws exception upon failure.
 */
CURL* create( char const *uri, write_fn_t fn, void *data );

/**
 * Destroys a cURL instance.
 *
 * @param instance A cURL instance.  If \c NULL, does nothing.
 */
void destroy( CURL *instance );

////////// exceptions /////////////////////////////////////////////////////////

/**
 * A curl::exception is-an os_error::exception for reporting run-time errors
 * while using cURL.
 */
class exception : public os_error::exception {
public:
  exception( char const *function, char const *uri, char const *msg = 0 );
  exception( char const *function, char const *uri, CURLcode code );
  exception( char const *function, char const *uri, CURLMcode code );
};

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

protected:
  // inherited
  std::streamsize showmanyc();
  int_type underflow();

private:
  void curl_read();
  static size_t curl_write_callback( void*, size_t, size_t, void* );

  void init();

  char *buf_;
  std::streamsize buf_capacity_;
  std::streamoff buf_len_;

  CURL *curl_;
  CURLM *curlm_;
  int curl_running_;

  // forbid
  streambuf( streambuf const& );
  streambuf& operator=( streambuf const& );
};

////////// istream ////////////////////////////////////////////////////////////

/**
 * A curl::istream is-a std::istream for streaming the contents of a URI using
 * cURL.  However, do not use this class directly.  Use uri::istream instead.
 */
class istream : private streambuf, public std::istream {
  //
  // We use private inheritance from steambuf rather than have a streambuf data
  // member because we want the streambuf to be constructed before passing it
  // to istream's constructor.
  //
public:
  istream() : std::istream( this ) { }
  istream( char const *uri ) : streambuf( uri ), std::istream( this ) { }

  using streambuf::open;
  using streambuf::is_open;
  using streambuf::close;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace curl
} // namespace zorba
#endif /* ZORBA_WITH_REST */
#endif /* ZORBA_CURL_UTIL_H */
