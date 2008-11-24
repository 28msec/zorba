#include <iostream>
#include <string.h>

#include <zorba/util/path.h>

using namespace std;
using namespace zorba;

int main (int argc, const char **argv) {

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

  return 0;
}
