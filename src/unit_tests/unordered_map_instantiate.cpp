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

#include <iostream>

#include "util/unordered_map.h"

using namespace std;

static void instantiate() {
  return;

  typedef unordered_map<string,int> map_type;

  map_type m;
  map_type m2( m );
  m = m2;
  map_type const cm;

  map_type::iterator i;
  map_type::const_iterator ci;

  m.begin();
  m.cbegin();
  m.end();
  m.cend();

  m.begin( 0 );
  m.cbegin( 0 );
  m.end( 0 );
  m.cend( 0 );

  m.clear();
  m.erase( i );
  m.erase( ci );
  m.erase( ci, ci );
  m.erase( "x" );

  m.insert( make_pair( "a", 1 ) );
  m.insert( ci, make_pair( "a", 1 ) );

  m.rehash( 41 );
  m.swap( m2 );

  m.at( "x" );
  cm.at( "x" );

  m[ "b" ] = 2;

  m.count( "x" );
  m.find( "x" );
  cm.find( "x" );
  m.equal_range( "x" );
  cm.equal_range( "x" );

  m.bucket( "x" );
  m.bucket_count();
  m.bucket_size( 0 );
  m.max_bucket_count();

  m.empty();
  m.get_allocator();
  m.hash_function();
  m.key_eq();
  m.load_factor();
  m.max_load_factor();
  m.max_size();
  m.size();
}
/* vim:set et sw=2 ts=2: */
