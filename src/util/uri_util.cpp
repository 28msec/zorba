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

#include <algorithm>                    /* for lower_bound() */
#include <cstring>
#include <fstream>

#include <zorba/config.h>

#ifdef ZORBA_WITH_REST
#include <curl/curl.h>
#endif

#ifdef WIN32
#include "system/globalenv.h"
#endif /* WIN32 */

#ifndef ZORBA_WITH_REST
#include "zorbaerrors/error_manager.h"
#endif
#include "zorbatypes/zstring.h"

#include "fs_util.h"
#include "less.h"
#include "uri_util.h"

using namespace std;

namespace zorba {
namespace uri {

///////////////////////////////////////////////////////////////////////////////

// This MUST be sorted.
char const *const scheme_string[] = {
  "#none",
  "#unknown",
  "file",
  "ftp",
  "http",
  "https",
  "mailto"
};

///////////////////////////////////////////////////////////////////////////////

ZORBA_DLL_PUBLIC extern signed char const hex2dec[] = {          
  /*       0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F */
  /* 0 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 1 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 2 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 3 */  0, 1, 2, 3,  4, 5, 6, 7,  8, 9,-1,-1, -1,-1,-1,-1,
    
  /* 4 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 5 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 6 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 7 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  
  /* 8 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* 9 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* A */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* B */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,

  /* C */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* D */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* E */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
  /* F */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1
};

/**
 * Characters that need not be percent-encoded (%xx) in URIs.  See RFC 3986.
 */
ZORBA_DLL_PUBLIC extern char const uri_safe[256] = {
  /*      0 1 2 3  4 5 6 7  8 9 A B  C D E F   */
  /* 0 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
  /* 1 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,

  /*        ! " #  $ % & '  ( ) * +  , - . /   */
  /* 2 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,1,1,0,

  /*      0 1 2 3  4 5 6 7  8 9 : ;  < = > ?   */
  /* 3 */ 1,1,1,1, 1,1,1,1, 1,1,0,0, 0,0,0,0,

  /*      @ A B C  D E F G  H I J K  L M N O   */
  /* 4 */ 0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,

  /*      P Q R S  T U V W  X Y Z [  \ ] ^ _   */
  /* 5 */ 1,1,1,1, 1,1,1,1, 1,1,1,0, 0,0,0,1,

  /*      ` a b c  d e f g  h i j k  l m n o   */
  /* 6 */ 0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,

  /*      p q r s  t u v w  x y z {  | } ~     */
  /* 7 */ 1,1,1,1, 1,1,1,1, 1,1,1,0, 0,0,1,0,
};

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
  //
  // Having cURL initialization wrapped by a class and using a singleton static
  // instance guarantees that cURL is initialized exactly once before use and
  // and also is cleaned-up at program termination (when destructors for static
  // objects are called).
  //
  struct curl_initializer {
    curl_initializer() {
      if ( CURLcode curl_code = curl_global_init( CURL_GLOBAL_ALL ) )
        throw fetch_exception( curl_easy_strerror( curl_code ) );
    }
    ~curl_initializer() {
      curl_global_cleanup();
    }
  };
  static curl_initializer initializer;

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

void fetch_to_path_impl( char const *uri, char *path, bool *is_temp ) {
#ifdef ZORBA_WITH_FILE_ACCESS
  zstring zpath;
  bool temp = false;
  switch ( get_scheme( uri ) ) {
    case file:
    case none:
      zpath = fs::get_normalized_path( uri );
      break;
    default:
      fs::get_temp_file( &zpath );
      fstream stream( zpath.c_str() );
      fetch( uri, stream );
      temp = true;
      break;
  }
  ::strncpy( path, zpath.c_str(), MAX_PATH );
  path[ MAX_PATH - 1 ] = '\0';
  if ( is_temp )
    *is_temp = temp;
#else
  ZORBA_ERROR( XQP0017_FILE_ACCESS_DISABLED );
#endif /* ZORBA_WITH_FILE_ACCESS */
}

scheme get_scheme( char const *uri, char const **ppcolon ) {
  if ( char const *const pcolon = ::strchr( uri, ':' ) ) {
    static char const *const *const begin = scheme_string;
    static char const *const *const end =
      scheme_string + sizeof( scheme_string ) / sizeof( char* );

    if ( ppcolon )
      *ppcolon = pcolon;
    zstring const sname( uri, pcolon - uri );
    char const *const s = sname.c_str();
    char const *const *const entry =
      ::lower_bound( begin, end, s, less<char const*>() );
    return entry != end && ::strcmp( s, *entry ) == 0 ?
      static_cast<scheme>( entry - begin ) : unknown;
  }
  return none;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace uri
} // namespace zorba
/* vim:set et sw=2 ts=2: */
