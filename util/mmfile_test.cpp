/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: mmfile_test.cpp,v 1.1 2006/10/09 07:07:58 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "mmfile.h"

#include <iostream>

#include "xqpexception.h"
#include "tokenbuf.h"

using namespace std;
using namespace xqp;

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
  } catch (xqpexception& e) {
    cout << "Application exception: " << e.what() << '\t' << e.get_msg() << endl;
  }
  return 0;

}
