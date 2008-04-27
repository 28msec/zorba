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
#include "util/mmfile.h"

#include <iostream>

#include "errors/xqp_exception.h"
#include "util/tokenbuf.h"

using namespace std;
using namespace zorba;

int main(int argc, char* argv[])
{
  try {
    mmfile mmf(argv[1], 10);
		string cmdline, cmd, arg1, arg2;

    // command loop
    while (true) {

			getline(cin, cmdline);
			if (cmdline.length()==0) continue;
			
			tokenbuf tokbuf(cmdline.c_str()," ");
			tokbuf.set_lowercase(false);
			tokbuf.set_return_delims(false);

			tokenbuf::token_iterator it = tokbuf.begin();
			tokenbuf::token_iterator end = tokbuf.end();
			
			cmd = *it;
			if (it!=end) { ++it; arg1 = *it; }
			if (it!=end) { ++it; arg2 = *it; }

			cout << "cmd = " << cmd << endl;
			if (arg1.length()>0) cout << "arg1 = " << arg1 << endl;
			if (arg2.length()>0) cout << "arg2 = " << arg2 << endl;
  
      if (cmd=="quit") {
        break;
      }
      if (cmd=="double") {
        mmf.expand();
      }
      else if (cmd=="fill") {
        uint32_t n = strtol(arg1.c_str(), 0, 10);
        mmf.fill(n);
      }
      else if (cmd=="help") {
        cout << "double				- double the mem-mapped array\n";
        cout << "fill VAL			- fill mem-mapped array with byte VAL\n";
        cout << "help					- this help function\n";
        cout << "rename FNAME	- rename the backing file to FNAME\n";
				cout << "size					- return size of the backing file\n";
      }
      else if (cmd=="rename") {
        mmf.rename_backing_file(arg1);
      }
      else if (cmd=="size") {
        cout << "size = " << mmf.get_eofoff() << endl;
      }
      else {
        cout << "Unrecognized command\n";
      }
    }
  } catch (xqp_exception& e) {
    cout << "Application exception: " << e.what() << '\t' << e.get_msg() << endl;
  }
  return 0;

}
