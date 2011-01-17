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

#include <curl/curl.h>

#include "system/globalenv.h"

#ifndef ZORBA_WITH_REST
#include "zorbaerrors/error_manager.h"
#endif

#include "uri_util.h"

using namespace std;

namespace zorba {
namespace uri {

///////////////////////////////////////////////////////////////////////////////

static size_t curl_write_fn( void *ptr, size_t size, size_t nmemb,
                             void *data ) {
  char const *const char_buf = static_cast<char const*>( ptr );
  size_t const real_size = size * nmemb;
  iostream &stream = *static_cast<iostream*>( data );

  stream.write( char_buf, static_cast<streamsize>( real_size ) );
  // TODO: should check to see if write() failed
  return real_size;
}

void fetch( char const *uri, iostream &result ) {
#ifdef ZORBA_WITH_REST

  CURL *curl = curl_easy_init();
  curl_easy_setopt( curl, CURLOPT_URL, uri );
  curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, curl_write_fn );
  curl_easy_setopt( curl, CURLOPT_WRITEDATA, static_cast<void*>( &result ) );

  // Tells cURL to fail silently if the HTTP code returned >= 400.
  curl_easy_setopt( curl, CURLOPT_FAILONERROR, 1 );

  // Tells cURL to follow redirects. CURLOPT_MAXREDIRS is by default set to -1
  // thus cURL will do an infinite number of redirects.
  curl_easy_setopt( curl, CURLOPT_FOLLOWLOCATION, 1 );

#ifndef ZORBA_VERIFY_PEER_SSL_CERTIFICATE
  curl_easy_setopt( curl, CURLOPT_SSL_VERIFYPEER, 0 );
  //
  // CURLOPT_SSL_VERIFYHOST is left default, value 2, meaning verify that the
  // Common Name or Subject Alternate Name field in the certificate matches the
  // name of the server.
  //
  // tested with https://www.npr.org/rss/rss.php?id=1001
  // about using ssl certs in curl: http://curl.haxx.se/docs/sslcerts.html
#else
# ifdef WIN32
  // set the root CA certificates file path
  if ( GENV.g_curl_root_CA_certificates_path[0] )
    curl_easy_setopt(
      curl, CURLOPT_CAINFO, GENV.g_curl_root_CA_certificates_path
    );
# endif /* WIN32 */
#endif /* ZORBA_VERIFY_PEER_SSL_CERTIFICATE */

  //
  // Some servers don't like requests that are made without a user-agent field,
  // so we provide one.
  //
  curl_easy_setopt( curl, CURLOPT_USERAGENT, "libcurl-agent/1.0" );

  CURLcode const curl_code = curl_easy_perform( curl );
  if ( curl_code ) {
    //
    // Workaround for a problem in cURL: curl_easy_cleanup() fails if
    // curl_easy_perform() returned an error.
    //
    curl_easy_reset( curl );
  }
  curl_easy_cleanup( curl );
  if ( curl_code )
    throw fetch_exception( curl_easy_strerror( curl_code ) );
#else
  ZORBA_ERROR_PARAM( XQP0004_SYSTEM_NOT_SUPPORTED, "HTTP GET" , "" );
#endif /* ZORBA_WITH_REST */
}

///////////////////////////////////////////////////////////////////////////////

} // namespace uri
} // namespace zorba
/* vim:set et sw=2 ts=2: */
