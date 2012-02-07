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

#include <exception>
#include <istream>
#include <streambuf>
#include <string>
#include <curl/curl.h>

namespace zorba {

namespace http_client {
  class InformDataRead;
}

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
   * In case we already have a curl object, which was set up somewhere else, we
   * take it here as an arument. This takes ownership over the object.
   */
  streambuf( CURL* aCurl );

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
   * Provide a InformDataRead that will get callbacks about read events.
   */
  void setInformer( http_client::InformDataRead *aInformer ) {
    theInformer = aInformer;
  }

  /**
   * Specify whether this streambuf has memory ownership over the
   * InformDataRead it has been passed. You can use this if, for example,
   * the lifetime of the streambuf will extend past the lifetime of the
   * object which created the InformDataRead.
   */
  void setOwnInformer( bool aOwnInformer ) {
    theOwnInformer = aOwnInformer;
  }

  int multi_perform();

protected:
  // inherited
  std::streamsize showmanyc();
  int_type underflow();

private:
  void curl_read();
  static size_t curl_write_callback( void*, size_t, size_t, void* );

  void init();
  void init_curlm();

  char *buf_;
  std::streamsize buf_capacity_;
  std::streamoff buf_len_;

  CURL *curl_;
  CURLM *curlm_;
  int curl_running_;
  http_client::InformDataRead *theInformer;
  bool theOwnInformer;

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
