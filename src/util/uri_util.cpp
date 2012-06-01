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
#include "stdafx.h"

#include <algorithm>                    /* for lower_bound() */
#include <cstring>
#include <fstream>

#include <zorba/config.h>

#ifdef WIN32
#include "system/globalenv.h"
#endif /* WIN32 */

#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/zstring.h"

#include "fs_util.h"
#include "less.h"
#include "uri_util.h"
#include "http_util.h"

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

extern signed char const hex2dec[] = {          
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
extern char const uri_safe[256] = {
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
      HttpStream lHttpStream(uri);
      lHttpStream.init();
      lHttpStream.getStream().get(*stream.rdbuf(), EOF);
      //fetch( uri, stream );
      temp = true;
      break;
  }
  ::strncpy( path, zpath.c_str(), MAX_PATH );
  path[ MAX_PATH - 1 ] = '\0';
  if ( is_temp )
    *is_temp = temp;
#else
  throw ZORBA_EXCEPTION( zerr::ZXQP0017_FILE_ACCESS_DISABLED );
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
