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

#include <cctype>

#include "ascii_util.h"

namespace zorba {
namespace ascii {

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


bool is_whitespace( char const *s ) {
  for ( ; *s; ++s )
    if ( !isspace( *s ) )
      return false;
  return true;
}


void skip_whitespace(const char* str, size_type str_len, size_type *pos)
{
  size_type i = *pos;
  for ( ; i < str_len; ++i )
  {
    if (!isspace(str[i]))
      break;
  }
  *pos = i;
}


char* ltoa( long n, char *buf ) {
  //
  // See: Brian W. Kernighan, Dennis M. Ritchie. "The C Programming Language,
  // 2nd ed."  Addison-Wesley, Reading, MA, 1988. pp. 63-64.
  //
  bool const is_neg = n < 0;
  if ( is_neg ) n = -n;
  char *s = buf;
  do {                                  // generate digits in reverse
    *s++ = n % 10 + '0';
  } while ( n /= 10 );
  if ( is_neg ) *s++ = '-';
  *s = '\0';

  for ( char *t = buf; t < s; ++t ) {   // now reverse the string
    char const temp = *--s; *s = *t; *t = temp;
  }
  return buf;
}

} // namespace ascii
} // namespace zorba

/* vim:set et sw=2 ts=2: */
