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

int main (int argc, const char **argv) 
{

  // initialize and deinitialize zorba in order to avoid
  // valgrind showing still reachables
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba * engine = zorba::Zorba::getInstance(store);     

  if (strcmp (argv [1], "--branch-path") == 0) 
  {
    filesystem_path   branch_test(argv [2], filesystem_path::CONVERT_SLASHES);
    filesystem_path   result = branch_test.branch_path();
    std::string result_path;
    result_path = result.get_path();
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
    cout << result_path << endl;
  } else if (strcmp (argv [1], "--path") == 0) {
    cout << filesystem_path (argv [2]).get_path () << endl;
  }

  engine->shutdown(); 
  zorba::StoreManager::shutdownStore(store);

  return 0;
}
