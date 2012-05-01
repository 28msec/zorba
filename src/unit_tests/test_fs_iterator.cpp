/*
 * Copyright 2006-2010 The FLWOR Foundation.
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

#include <iostream>
#include <zorba/zorba_exception.h>

#include "util/fs_util.h"

using namespace std;
using namespace zorba;

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_fs_iterator( int argc, char *argv[] ) {
  int result = 0;
  try {
#ifndef WIN32
    fs::iterator dir_iter( "/" );
#else
    fs::iterator dir_iter( "C:\\" );
#endif /* WIN32 */
    while ( dir_iter.next() )
      cout << dir_iter.entry_name() << " (" << dir_iter.entry_type() << ')' << endl;
  }
  catch ( ZorbaException const &e ) {
    cerr << e << endl;
    result = 2;
  }

  return result;
}

} // namespace UnitTests
} // namespace zorba

/* vim:set et sw=2 ts=2: */
