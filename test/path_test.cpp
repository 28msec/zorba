#include <iostream>
#include <string.h>
#include "util/path.h"

using namespace std;
using namespace zorba;

int main (int argc, const char **argv) {
  if (strcmp (argv [1], "--branch-path") == 0) {
    cout << filesystem_path (argv [2]).branch_path ().get_path () << endl;
  } else if (strcmp (argv [1], "--path") == 0) {
    cout << filesystem_path (argv [2]).get_path () << endl;
  }
}
