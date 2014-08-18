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

#include <cstdlib>                      /* for strtoul(3) */
#include <cstring>

#include "xml_util.h"

using namespace std;

namespace zorba {
namespace xml {

///////////////////////////////////////////////////////////////////////////////

char const *const version_string_of[] = {
  "1.0",
  "1.1"
};

///////////////////////////////////////////////////////////////////////////////

bool is_NameChar( unicode::code_point c ) {
  //
  // It's faster to duplicate the code so the common cases are always tested
  // first.
  //
  return  (c >= 'a' && c <= 'z')
      ||  (c >= 'A' && c <= 'Z')
      ||  (c >= '0' && c <= '9')
      ||   c == '_'
      ||   c == '-'
      ||   c == '.'
      ||   c == 0x0000B7
      ||  (c >= 0x0000C0 && c <= 0x0000D6)
      ||  (c >= 0x0000D8 && c <= 0x0000F6)
      ||  (c >= 0x0000F8 && c <= 0x0002FF)
      ||  (c >= 0x000300 && c <= 0x00036F)
      ||  (c >= 0x000370 && c <= 0x00037D)
      ||  (c >= 0x00037F && c <= 0x001FFF)
      ||  (c >= 0x00200C && c <= 0x00200D)
      ||  (c >= 0x00203F && c <= 0x002040)
      ||  (c >= 0x002070 && c <= 0x00218F)
      ||  (c >= 0x002C00 && c <= 0x002FEF)
      ||  (c >= 0x003001 && c <= 0x00D7FF)
      ||  (c >= 0x00F900 && c <= 0x00FDCF)
      ||  (c >= 0x00FDF0 && c <= 0x00FFFD)
      ||  (c >= 0x010000 && c <= 0x10FFFF);
}

bool is_NameStartChar( unicode::code_point c ) {
  return  (c >= 'a' && c <= 'z')
      ||  (c >= 'A' && c <= 'Z')
      ||   c == '_'
      ||  (c >= 0x0000C0 && c <= 0x0000D6)
      ||  (c >= 0x0000D8 && c <= 0x0000F6)
      ||  (c >= 0x0000F8 && c <= 0x0002FF)
      ||  (c >= 0x000370 && c <= 0x00037D)
      ||  (c >= 0x00037F && c <= 0x001FFF)
      ||  (c >= 0x00200C && c <= 0x00200D)
      ||  (c >= 0x002070 && c <= 0x00218F)
      ||  (c >= 0x002C00 && c <= 0x002FEF)
      ||  (c >= 0x003001 && c <= 0x00D7FF)
      ||  (c >= 0x00F900 && c <= 0x00FDCF)
      ||  (c >= 0x00FDF0 && c <= 0x00FFFD)
      ||  (c >= 0x010000 && c <= 0x10FFFF);
}

///////////////////////////////////////////////////////////////////////////////

int parse_entity( char const *s, unicode::code_point *c ) {
  char const *const s0 = s;
  if ( *s == '&' && !*++s )
    return -1;
  unsigned long n = 0;
  if ( *s == '#' ) {
    if ( !*++s )
      return -1;
    int base = 10;
    if ( *s == 'x' ) {
      if ( !*++s )
        return -1;
      base = 16;
    }

    //
    // Disallow things that strtoul() normally allows:
    // * leading '0' (for octal)
    // * leading '+' or '-'
    //
    while ( *s == '0' )
      ++s;
    if ( !*s || *s == '+' || *s == '-' )
      return -1;

    n = ::strtoul( s, const_cast<char**>( &s ), base );
    if ( !unicode::is_valid( n ) || *s != ';' )
      return -1;
    ++s;
  } else {
    static char const amp [] = "amp;";
    static char const apos[] = "apos;";
    static char const gt  [] = "gt;";
    static char const lt  [] = "lt;";
    static char const quot[] = "quot;";

    struct entity {
      char const *name;
      int len;
      char equiv;
    };
    static entity const entities[] = {
      { amp , sizeof( amp  ) - 1, '&'  },
      { lt  , sizeof( lt   ) - 1, '<'  },
      { gt  , sizeof( gt   ) - 1, '>'  },
      { apos, sizeof( apos ) - 1, '\'' },
      { quot, sizeof( quot ) - 1, '"'  },
      { 0, 0, 0 }
    };

    for ( entity const *e = entities; e->name; ++e )
      if ( ::strncmp( s, e->name, e->len ) == 0 ) {
        n = e->equiv;
        s += e->len;
        break;
      }

    if ( !n )
      return -1;
  }
  *c = n;
  return s - s0;
}

///////////////////////////////////////////////////////////////////////////////

ostream& serialize( ostream &os, char const *s, bool attr ) {
  utf8::encoded_char_type ec;

  while ( true ) {
    unicode::code_point const cp = utf8::next_char( s );
    if ( !cp )
      break;

    if (cp >= 0x10000 && cp <= 0x10FFFF)
    {
      ascii::itoa_buf_type cp_buf;
      os << "&#" << ascii::itoa(cp, cp_buf) << ';';
    }
    /*
       In addition, the non-whitespace control characters #x1 through #x1F and
       #x7F through #x9F in text nodes and attribute nodes MUST be output as
       character references.
     */
    else if ((cp >= 0x01 && cp <= 0x1F)
        ||
        (cp >= 0x7F && cp <= 0x9F))
    {
      if ((!attr) && (cp == 0xA || cp == 0x9))
        os.write( ec, utf8::encode( cp, ec ) );
      else
      {
        char buf[3];
        toHexString(cp, buf);
        os << "&#x" << buf << ";";
      }
    }
    else
    {
      switch (cp)
      {
        case '<':
          os << "&lt;";
          break;
        case '>':
          os << "&gt;";
          break;
        case '"':
          if (attr)
            os << "&quot;";
          else
            os.write( ec, utf8::encode( cp, ec ) );
          break;
        case '&':
          os << "&amp;";
          break;
        default:
          os.write( ec, utf8::encode( cp, ec ) );
          break;
      }
    }
  }
  return os;
}

///////////////////////////////////////////////////////////////////////////////
void toHexString(unsigned char ch, char result[])
{
  static const char hex[] =
  { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

  if ((ch >> 4) > 0)
  {
    result[0] = hex[ch >> 4];
    result[1]= hex[ch & 0xF];
    result[2] = '\0';
  }
  else
  {
    result[0]= hex[ch & 0xF];
    result[1] = '\0';
  }
}


} // namespace xml
} // namespace zorba
/* vim:set et sw=2 ts=2: */
