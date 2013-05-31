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

#include <cstring>

#include "util/fs_util.h"

using namespace std;
using namespace zorba;

struct test {
  char const *input;
  char const *expected;
};

///////////////////////////////////////////////////////////////////////////////

static int failures;

static bool assert_true( int no, char const *expr, int line, bool result ) {
  if ( !result ) {
    cout << '#' << no << " FAILED, line " << line << ": " << expr << endl;
    ++failures;
  }
  return result;
}

static void print_exception( int no, char const *expr, int line,
                             std::exception const &e ) {
  assert_true( no, expr, line, false );
  cout << "+ exception: " << e.what() << endl;
}

#define ASSERT_TRUE( NO, EXPR ) assert_true( NO, #EXPR, __LINE__, !!(EXPR) )

#define ASSERT_NO_EXCEPTION( NO, EXPR ) \
  try { EXPR; } \
  catch ( exception const &e ) { print_exception( NO, #EXPR, __LINE__, e ); } \
  catch ( ... ) { assert_true( NO, #EXPR, __LINE__, false ); }

#define ASSERT_EXCEPTION( NO, EXPR, EXCEPTION ) \
  try { EXPR; assert_true( NO, #EXPR, __LINE__, false ); } \
  catch ( EXCEPTION const& ) { } \
  catch ( ... ) { assert_true( NO, #EXPR, __LINE__, false ); }

///////////////////////////////////////////////////////////////////////////////}

void test_base_name( int no, char const *path, char const *expected ) {
  ASSERT_TRUE( no, ::strcmp( fs::base_name( path ), expected ) == 0 );
}

void test_base_name( int no, string const &path, string const &expected ) {
  ASSERT_TRUE( no, fs::base_name( path ) == expected );
}

void test_dir_name( int no, char const *path, char const *expected ) {
  ASSERT_TRUE( no, fs::dir_name( path ) == expected );
}

void test_dir_name( int no, string const &path, string const &expected ) {
  ASSERT_TRUE( no, fs::dir_name( path ) == expected );
}

void test_get_normalized_path( int no, char const *path,
                               char const *expected ) {
  ASSERT_TRUE( no, fs::get_normalized_path( path ) == expected );
}

///////////////////////////////////////////////////////////////////////////////}

static test const base_name_tests[] = {
#ifndef WIN32
  /* 0 */ { "/a/b", "b" },
  /* 1 */ { "/a"  , "a" },
  /* 2 */ { "/"   , "/" },
  /* 3 */ { "a/b" , "b" },
  /* 4 */ { "a"   , "a" },
#else
  /* 0 */ { "C:\\a\\b", "b"    },
  /* 1 */ { "C:\\a"   , "a"    },
  /* 2 */ { "C:\\"    , "C:\\" },
  /* 3 */ { "a\\b"    , "b"    },
  /* 4 */ { "a"       , "a"    },
#endif /* WIN32 */
  { 0, 0 }
};

static test const dir_name_tests[] = {
#ifndef WIN32
  /* 0 */ { "/a/b", "/a" },
  /* 1 */ { "/a"  , "/"  },
  /* 2 */ { "/"   , "/"  },
  /* 3 */ { "a/b" , "a"  },
  /* 4 */ { "a"   , "."  },
#else
  /* 0 */ { "C:\\a\\b", "C:\\a" },
  /* 1 */ { "C:\\a"   , "C:\\"  },
  /* 2 */ { "C"\\"    , "C:\\"  },
  /* 3 */ { "a\\b"    , "a"     },
  /* 4 */ { "a"       , "."     },
#endif /* WIN32 */
  { 0, 0 }
};

static test get_normalized_path_tests[] = {
#ifndef WIN32
  /*  0 */ { "/a//b"                , "/a/b" },
  /*  1 */ { "/a///b"               , "/a/b" },
  /*  2 */ { "/a/./b"               , "/a/b" },
  /*  3 */ { "/a/././b"             , "/a/b" },
  /*  4 */ { "/a/b/."               , "/a/b" },
  /*  5 */ { "/a/../b"              , "/b"   },
  /*  6 */ { "/a/b/../../c"         , "/c"   },
  /*  7 */ { "/a/b/../c/../d"       , "/a/d" },
  /*  8 */ { "/a/b/.."              , "/a"   },
  /*  9 */ { "file:///a/b"          , "/a/b" },
  /* 10 */ { "file://localhost/a/b" , "/a/b" },
  /* 11 */ { "\\a\\b"               , "/a/b" },
#else
  /*  0 */ { "C:\\a\\\\b"                 , "C:\\a\\b" },
  /*  1 */ { "C:\\a\\\\\\b"               , "C:\\a\\b" },
  /*  2 */ { "C:\\a\\.\\b"                , "C:\\a\\b" },
  /*  3 */ { "C:\\a\\.\\.\\b"             , "C:\\a\\b" },
  /*  4 */ { "C:\\a\\b\\."                , "C:\\a\\b" },
  /*  5 */ { "C:\\a\\..\\b"               , "C:\\b"    },
  /*  6 */ { "C:\\a\\b\\..\\..\\c"        , "C:\\c"    },
  /*  7 */ { "C:\\a\\b\\..\\c\\..\\d"     , "C:\\a\\d" },
  /*  8 */ { "C:\\a\\b\\.."               , "C:\\a"    },
  /*  9 */ { "file:///C%3A/a/b"           , "C:\\a\\b" },
  /* 10 */ { "file://localhost/C%3A/a/b"  , "C:\\a\\b" },
  /* 11 */ { "C:/a/b"                     , "C:\\a\\b" },
#endif /* WIN32 */
  { 0, 0 }
};

namespace zorba {
namespace UnitTests {

int test_fs_util( int, char*[] ) {
  int test_no = 0;

  for ( test const *t = base_name_tests; t->input; ++t, ++test_no ) {
    test_base_name( test_no, t->input, t->expected );
    test_base_name( test_no, string( t->input ), string( t->expected ) );
  }

  test_no = 0;
  for ( test const *t = dir_name_tests; t->input; ++t, ++test_no ) {
    test_dir_name( test_no, t->input, t->expected );
    test_dir_name( test_no, string( t->input ), string( t->expected ) );
  }

  test_no = 0;
  for ( test const *t = get_normalized_path_tests; t->input; ++t, ++test_no )
    test_get_normalized_path( test_no, t->input, t->expected );

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba

/* vim:set et sw=2 ts=2: */
