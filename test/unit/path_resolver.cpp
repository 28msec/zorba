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

#include <zorba/util/path.h>
#include <zorba/zorbastring.h>
#include <iostream>

using namespace zorba;
using namespace std;

// Test cases are here as an array of arrays. Each case comprises
// three Strings: the input path; the base (for relative paths); and
// the expected result.

#ifdef WIN32

String path_resolver_tests[][3] = {
  { "C:\\path\\to\\file.xx", "", "C:\\path\\to\\file.xx" },
  { "path\\to\\file.xx", "C:\\base", "C:\\base\\path\\to\\file.xx" },
  { "file:///C:/path/to/file.xx", "", "C:\\path\\to\\file.xx" },
  { "file://localhost/C:/path/to/file.xx", "", "C:\\path\\to\\file.xx" },
};

#define NUM_PATH_RESOLVER_TESTS 4

#else /* WIN32 */

String path_resolver_tests[][3] = {
  { "/path/to/file.xx", "", "/path/to/file.xx" },
  { "path/to/file.xx", "/base", "/base/path/to/file.xx" },
  { "file:///path/to/file.xx", "", "/path/to/file.xx" },
    { "file://localhost/path/to/file.xx", "", "/path/to/file.xx" }
};

#define NUM_PATH_RESOLVER_TESTS 4

#endif /* WIN32 */

/**
 * "main"
 */
int path_resolver(int argc, char* argv[]) {
  for (int i = 0; i < NUM_PATH_RESOLVER_TESTS; i++) {
    String *testcase/*[3]*/ = path_resolver_tests[i];
    String res = filesystem_path::normalize_path(testcase[0], testcase[1]);
    if (res != testcase[2]) {
      cout << "Path resolver test " << i << " failed: expected '"
           << testcase[2] << "' but got '" << res << "'" << endl;
      return 1;
    }
  }
  return 0;
}
