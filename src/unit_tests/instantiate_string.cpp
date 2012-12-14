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
#include <cassert>
#include <string>

#include "util/utf8_string.h"
#include "zorbatypes/zstring.h"

using namespace std;
using namespace zorba;

/**
 * Instantiates all member functions common to all string representations.
 */
template<class StringType>
static void instantiate_common() {
  typename StringType::allocator_type a;
  typename StringType::value_type c = 0;
  typename StringType::pointer cs = 0;
  typename StringType::const_pointer csc = 0;
  typename StringType::iterator i = 0;
  typename StringType::std_string ss;

  StringType s1, s2;
  StringType const sc;

  { StringType s( cs ); }
  { StringType s( cs, 1 ); }

  s1 = s2;
  s1 = ss;
  s1 = cs;
  s1 = csc;
  s1 = c;

  s1.capacity();
  s1.empty();
  s1.get_allocator();
  s1.length();
  s1.size();

  s1.at( 0 );
  sc.at( 0 );
  s1[ 0 ];
  sc[ 0 ];

  s1.append( s2 );
  s1.append( s2, 0, 1 );
  s1.append( ss );
  s1.append( ss, 0, 1 );
  s1.append( cs );
  s1.append( cs, 1 );
  s1.append( csc );
  s1.append( csc, 1 );
  s1.append( 1, c );
  s1.push_back( c );
  s1 += s2;
  s1 += ss;
  s1 += cs;
  s1 += csc;
  s1 += c;

  s1.assign( s2 );
  s1.assign( s2, 0, 1 );
  s1.assign( ss );
  s1.assign( ss, 0, 1 );
  s1.assign( cs );
  s1.assign( cs, 1 );
  s1.assign( csc );
  s1.assign( csc, 1 );
  s1.assign( 1, c );
  s1.assign( i, i );

  s1.compare( s2 );
  s1.compare( ss );
  s1.compare( cs );
  s1.compare( csc );
  s1.compare( 0, 1, s2 );
  s1.compare( 0, 1, ss );
  s1.compare( 0, 1, cs );
  s1.compare( 0, 1, csc );
  s1.compare( 0, 1, s2, 0, 1 );
  s1.compare( 0, 1, ss, 0, 1 );
  s1.compare( 0, 1, cs, 1 );
  s1.compare( 0, 1, csc, 1 );

  s1.clear();
  s1.erase();
  s1.erase( i );
  s1.erase( i, i );

  s1.find( s2 );
  s1.find( ss );
  s1.find( cs );
  s1.find( cs, 0, 1 );
  s1.find( csc );
  s1.find( csc, 0, 1 );
  s1.find( c );

  s1.rfind( s2 );
  s1.rfind( ss );
  s1.rfind( cs );
  s1.rfind( cs, 0, 1 );
  s1.rfind( csc );
  s1.rfind( csc, 0, 1 );
  s1.rfind( c );

  s1.find_first_of( s2 );
  s1.find_first_of( ss );
  s1.find_first_of( cs );
  s1.find_first_of( cs, 0, 1 );
  s1.find_first_of( csc );
  s1.find_first_of( csc, 0, 1 );
  s1.find_first_of( c );

  s1.find_first_not_of( s2 );
  s1.find_first_not_of( ss );
  s1.find_first_not_of( cs );
  s1.find_first_not_of( cs, 0, 1 );
  s1.find_first_not_of( csc );
  s1.find_first_not_of( csc, 0, 1 );
  s1.find_first_not_of( c );

  s1.find_last_of( s2 );
  s1.find_last_of( ss );
  s1.find_last_of( cs );
  s1.find_last_of( cs, 0, 1 );
  s1.find_last_of( csc );
  s1.find_last_of( csc, 0, 1 );
  s1.find_last_of( c );

  s1.find_last_not_of( s2 );
  s1.find_last_not_of( ss );
  s1.find_last_not_of( cs );
  s1.find_last_not_of( cs, 0, 1 );
  s1.find_last_not_of( csc );
  s1.find_last_not_of( csc, 0, 1 );
  s1.find_last_not_of( c );

  s1.insert( 0, s2 );
  s1.insert( 0, s2, 0, 0 );
  s1.insert( 0, cs );
  s1.insert( 0, cs, 1 );
  s1.insert( 0, csc );
  s1.insert( 0, csc, 1 );
  s1.insert( 1, 1, c );
  s1.insert( i, c );
  s1.insert( i, 1, c );
  s1.insert( 0, i, i );

  s1.replace( 0, 1, s2 );
  s1.replace( 0, 1, s2, 0, 1 );
  s1.replace( 0, 1, cs );
  s1.replace( 0, 1, cs, 0 );
  s1.replace( 0, 1, csc );
  s1.replace( 0, 1, csc, 0 );
  s1.replace( 0, 1, 1, c );
  s1.replace( i, i, s2 );
  s1.replace( i, i, cs );
  s1.replace( i, i, cs, 1 );
  s1.replace( i, i, csc );
  s1.replace( i, i, csc, 1 );
  s1.replace( i, i, 1, c );

  s1.begin();
  s1.end();
  s1.rbegin();
  s1.rend();

  sc.begin();
  sc.end();
  sc.rbegin();
  sc.rend();

  s1.c_str();
  s1.copy( 0, 0 );
  s1.data();
  s1.reserve( 100 );
  s1.resize( 100 );
  s1.str();
  s1.substr();
  s1.swap( s2 );

  (void)(s1 == s2);
  (void)(s1 == ss);
  (void)(ss == s1);
  (void)(s1 == cs);
  (void)(s1 == csc);
  (void)(cs == s1);
  (void)(csc == s1);

  (void)(s1 != s2);
  (void)(s1 != ss);
  (void)(ss != s1);
  (void)(s1 != cs);
  (void)(s1 != csc);
  (void)(cs != s1);
  (void)(csc != s1);

  (void)(s1 < s2);
  (void)(s1 < ss);
  (void)(ss < s1);
  (void)(s1 < cs);
  (void)(s1 < csc);
  (void)(cs < s1);
  (void)(csc < s1);

  (void)(s1 <= s2);
  (void)(s1 <= ss);
  (void)(ss <= s1);
  (void)(s1 <= cs);
  (void)(s1 <= csc);
  (void)(cs <= s1);
  (void)(csc <= s1);

  (void)(s1 > s2);
  (void)(s1 > ss);
  (void)(ss > s1);
  (void)(s1 > cs);
  (void)(s1 > csc);
  (void)(cs > s1);
  (void)(csc > s1);

  (void)(s1 >= s2);
  (void)(s1 >= ss);
  (void)(ss >= s1);
  (void)(s1 >= cs);
  (void)(s1 >= csc);
  (void)(cs >= s1);
  (void)(csc >= s1);

  (void)(s1 + s1);
  (void)(s1 + ss);
  (void)(ss + s1);
  (void)(s1 + cs);
  (void)(s1 + csc);
  (void)(cs + s1);
  (void)(csc + s1);
  (void)(s1 + c);
  (void)(c + s1);

  cout << s1;
}

/**
 * Instantiates additional member functions that are not supported by buf_rep.
 */
template<class StringType>
static void instantiate_not_buf() {
  typename StringType::allocator_type a;
  typename StringType::pointer cs = 0;
  typename StringType::const_pointer csc = 0;
  typename StringType::std_string ss;
  typename StringType::value_type c = 0;
  typename StringType::iterator i = 0;

  StringType s1;

  { StringType s( ss ); }
  { StringType s( ss, 1 ); }
  { StringType s( cs ); }
  { StringType s( cs, 1 ); }
  { StringType s( csc ); }
  { StringType s( csc, 1 ); }
  { StringType s( a ); }
  { StringType s( 1, c ); }
  { StringType s( s1 ); }
  { StringType s( s1, 1 ); }
  { StringType s( s1, 1, 1, a ); }
  { StringType s( i, i ); }
}

template<class StringType>
static void instantiate_utf8_string() {
  typedef utf8_string<StringType> ustring;

  StringType s;
  typename ustring::storage_type b = 0;
  typename ustring::value_type c = 0;
  typename ustring::storage_pointer cs = 0;
  typename ustring::const_storage_pointer csc = 0;
  typename ustring::iterator i;
  typename ustring::std_string ss;

  ustring u1( s );
  ustring const uc( s );

  u1 = u1;
  u1 = s;
  u1 = ss;
  u1 = cs;
  u1 = csc;
  u1 = b;
  u1 = c;

  u1.bytes();
  u1.capacity();
  u1.empty();
  u1.get_allocator();
  u1.length();
  u1.size();

  u1.at( 0 );
  uc.at( 0 );
  u1[0];
  uc[0];

  u1.append( u1 );
  u1.append( s );
  u1.append( u1, 0, 1 );
  u1.append( s, 0, 1 );
  u1.append( ss );
  u1.append( ss, 0, 1 );
  u1.append( cs );
  u1.append( cs, 1 );
  u1.append( csc );
  u1.append( csc, 1 );
  u1.append( 1, b );
  u1.append( 1, c );
  u1.push_back( b );
  u1.push_back( c );
  u1 += u1;
  u1 += s;
  u1 += ss;
  u1 += cs;
  u1 += csc;
  u1 += b;
  u1 += c;

  u1.assign( u1 );
  u1.assign( s );
  u1.assign( u1, 0, 1 );
  u1.assign( s, 0, 1 );
  u1.assign( ss );
  u1.assign( ss, 0, 0 );
  u1.assign( cs );
  u1.assign( cs, 1 );
  u1.assign( csc );
  u1.assign( csc, 1 );
  u1.assign( 1, b );
  u1.assign( 1, c );

  u1.compare( u1 );
  u1.compare( s );
  u1.compare( ss );
  u1.compare( cs );
  u1.compare( csc );
  u1.compare( 0, 1, u1 );
  u1.compare( 0, 1, s );
  u1.compare( 0, 1, ss );
  u1.compare( 0, 1, cs );
  u1.compare( 0, 1, csc );
  u1.compare( 0, 1, u1, 0, 1 );
  u1.compare( 0, 1, s, 0, 1 );
  u1.compare( 0, 1, ss, 0, 1 );
  u1.compare( 0, 1, cs, 1 );
  u1.compare( 0, 1, csc, 1 );

  u1.clear();
  u1.erase();
  u1.erase( i );
  u1.erase( i, i );

  u1.find( s );
  u1.find( ss );
  u1.find( cs );
  u1.find( cs, 0, 1 );
  u1.find( csc );
  u1.find( csc, 0, 1 );
  u1.find( b );
  u1.find( c );

  u1.rfind( s );
  u1.rfind( ss );
  u1.rfind( cs );
  u1.rfind( cs, 0, 1 );
  u1.rfind( csc );
  u1.rfind( csc, 0, 1 );
  u1.rfind( b );
  u1.rfind( c );

  u1.find_first_of( u1 );
  u1.find_first_of( s );
  u1.find_first_of( ss );
  u1.find_first_of( cs );
  u1.find_first_of( cs, 0, 1 );
  u1.find_first_of( csc );
  u1.find_first_of( csc, 0, 1 );
  u1.find_first_of( b );
  u1.find_first_of( c );

  u1.find_first_not_of( u1 );
  u1.find_first_not_of( s );
  u1.find_first_not_of( ss );
  u1.find_first_not_of( cs );
  u1.find_first_not_of( cs, 0, 1 );
  u1.find_first_not_of( csc );
  u1.find_first_not_of( csc, 0, 1 );
  u1.find_first_not_of( b );
  u1.find_first_not_of( c );

  u1.find_last_of( u1 );
  u1.find_last_of( s );
  u1.find_last_of( ss );
  u1.find_last_of( cs );
  u1.find_last_of( cs, 0, 1 );
  u1.find_last_of( csc );
  u1.find_last_of( csc, 0, 1 );
  u1.find_last_of( b );
  u1.find_last_of( c );

  u1.find_last_not_of( u1 );
  u1.find_last_not_of( s );
  u1.find_last_not_of( ss );
  u1.find_last_not_of( cs );
  u1.find_last_not_of( cs, 0, 1 );
  u1.find_last_not_of( csc );
  u1.find_last_not_of( csc, 0, 1 );
  u1.find_last_not_of( b );
  u1.find_last_not_of( c );

  u1.insert( 0, u1 );
  u1.insert( 0, s );
  u1.insert( 0, u1, 0, 0 );
  u1.insert( 0, s, 0, 0 );
  u1.insert( 0, cs );
  u1.insert( 0, cs, 1 );
  u1.insert( 0, csc );
  u1.insert( 0, csc, 1 );
  u1.insert( 1, 1, b );
  u1.insert( 1, 1, c );
  u1.insert( i, b );
  u1.insert( i, c );
  u1.insert( i, 1, b );
  u1.insert( i, 1, c );

  u1.replace( 0, 1, u1 );
  u1.replace( 0, 1, s );
  u1.replace( 0, 1, u1, 0, 1 );
  u1.replace( 0, 1, s, 0, 1 );
  u1.replace( 0, 1, cs );
  u1.replace( 0, 1, cs, 0, 1 );
  u1.replace( 0, 1, csc );
  u1.replace( 0, 1, csc, 0, 1 );
  u1.replace( 0, 1, 1, c );
  u1.replace( i, i, u1 );
  u1.replace( i, i, s );
  u1.replace( i, i, cs );
  u1.replace( i, i, cs, 1 );
  u1.replace( i, i, csc );
  u1.replace( i, i, csc, 1 );
  u1.replace( i, i, 1, c );

  u1.begin();
  u1.end();
  u1.rbegin();
  u1.rend();
  uc.begin();
  uc.end();
  uc.rbegin();
  uc.rend();

  u1.c_str();
  u1.copy( 0, 0 );
  u1.data();
  u1.reserve( 100 );
  u1.resize( 100 );
  u1.str();
  u1.substr();
  u1.swap( s );
  u1.swap( u1 );

  (void)(u1 == s);
  (void)(u1 == ss);
  (void)(ss == u1);
  (void)(u1 == cs);
  (void)(u1 == csc);
  (void)(cs == u1);
  (void)(csc == u1);

  (void)(u1 != s);
  (void)(u1 != ss);
  (void)(ss != u1);
  (void)(u1 != cs);
  (void)(u1 != csc);
  (void)(cs != u1);
  (void)(csc != u1);

  (void)(u1 < s);
  (void)(u1 < ss);
  (void)(ss < u1);
  (void)(u1 < cs);
  (void)(u1 < csc);
  (void)(cs < u1);
  (void)(csc < u1);

  (void)(u1 <= s);
  (void)(u1 <= ss);
  (void)(ss <= u1);
  (void)(u1 <= cs);
  (void)(u1 <= csc);
  (void)(cs <= u1);
  (void)(csc <= u1);

  (void)(u1 > s);
  (void)(u1 > ss);
  (void)(ss > u1);
  (void)(u1 > cs);
  (void)(u1 > csc);
  (void)(cs > u1);
  (void)(csc > u1);

  (void)(u1 >= s);
  (void)(u1 >= ss);
  (void)(ss >= u1);
  (void)(u1 >= cs);
  (void)(u1 >= csc);
  (void)(cs >= u1);
  (void)(csc >= u1);

  (void)(u1 + u1);
  (void)(u1 + s);
  (void)(s + u1);
  (void)(u1 + ss);
  (void)(ss + u1);
  (void)(u1 + cs);
  (void)(u1 + csc);
  (void)(cs + u1);
  (void)(csc + u1);
  (void)(u1 + c);
  (void)(c + u1);
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_string_instantiate( int, char*[] ) {
  return 0;                             // don't actually call anything

  instantiate_common<zstring>();
  instantiate_common<zstring_b>();
  instantiate_common<zstring_p>();

  instantiate_not_buf<zstring>();
  instantiate_not_buf<zstring_p>();

  string s;
  zstring z;
  utf8_string<string> uss( s );
  utf8_string<zstring> uz( z );
  uss = uz;

  instantiate_utf8_string<zstring>();
  //instantiate_utf8_string<zstring_b>();
  instantiate_utf8_string<zstring_p>();
  instantiate_utf8_string<string>();

  return 0;
}

} // namespace UnitTests
} // namespace zorba

/* vim:set et sw=2 ts=2: */
