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
#include <string.h>

#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/util/path.h>

using namespace std;
using namespace zorba;

std::string filesystempath_branch_tests[][2] = {
  { "/d1/d2/../d3/.", "/d1" },
  { "/dir", "/" }
};
#define NUM_BRANCH_TESTS 2

std::string filesystempath_path_tests[][2] = {
  { "/../d1/./././././././../..", "/" },
  { "d1/d2/../../../../d3//", "../../d3" }
};
#define NUM_PATH_TESTS 2

int test_filesystempath (int argc, char *argv[])
{
  bool final_success = true;
  for (int i = 0; i < NUM_BRANCH_TESTS; i++)
  {
    filesystem_path branch_test(filesystempath_branch_tests[i][0],
				filesystem_path::CONVERT_SLASHES);
    filesystem_path result = branch_test.branch_path();
    std::string result_path = result.get_path();
    //for Windows, CMake has a problem with '\' so we make an workaround
#if defined WIN32 && !defined UNIX
    {
      string::size_type    findpos = 0;
      while((findpos=result_path.find('\\', findpos)) != string::npos)
      {
        result_path.replace(findpos, 1, "/");
      }
    }
#endif
    bool success = result_path == filesystempath_branch_tests[i][1];
    cout << "filesystem_path branch test " << i
         << (success ? " passed" : " failed") << ": expected '"
         << filesystempath_branch_tests[i][1] << " and got '"
         << result_path << "'" << endl;
    if (!success) {
      final_success = false;
    }
  } 
  for (int i = 0; i < NUM_PATH_TESTS; i++) {
    std::string result_path =
      filesystem_path (filesystempath_path_tests[i][0]).get_path();
    bool success = result_path == filesystempath_path_tests[i][1];
    cout << "filesystem_path path test " << i
         << (success ? " passed" : " failed") << ": expected '"
         << filesystempath_path_tests[i][1] << " and got "
         << result_path << "'" << endl;
    if (!success) {
      final_success = false;
    }
  }

  return (final_success ? 0 : 1);
}
