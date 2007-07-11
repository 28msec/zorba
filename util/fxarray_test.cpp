/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: fxarray_test.cpp,v 1.1 2006/10/09 07:07:58 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation. 
 *
 *	Author: Paul Pedersen
 *
 */

#include "fxarray.h"

#include <iostream>

#include "xqp_exception.h"
#include "tokenbuf.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
  try {
		fxarray<int> * fxary_p;
		if (argc > 1) {
    	fxary_p = new fxarray<int>(argv[1], 100);
		}
		else {
    	fxary_p = new fxarray<int>(100);
		}
		fxarray<int> & fxary = *fxary_p;

		string cmdline, cmd, arg1, arg2, arg3;
		uint32_t argcount = 0;

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
			if (it!=end) { ++it; arg3 = *it; }

			cout << "cmd = " << cmd << endl;
			if (argcount>1) cout << "arg1 = " << arg1 << endl;
			if (argcount>2) cout << "arg2 = " << arg2 << endl;
			if (argcount>3) cout << "arg3 = " << arg3 << endl;
  
      if (cmd=="quit" || cmd=="exit") {
        break;
      }
      else if (cmd=="at") {
        int n = strtol(arg1.c_str(), NULL, 10);
        cout << "fxary[" << n << "] = " << fxary[n] << endl;
      }
			else if (cmd=="expand") {
        fxary.expand();
      }
      else if (cmd=="fill") {
        uint32_t n = strtol(arg1.c_str(), 0, 10);
        fxary.fill(n);
      }
      else if (cmd=="(help") {
        cout << "at n       - return the n-th element" << endl
             << "expand     - double the array" << endl
             << "fill T     - fill array with byte T" << endl
             << "help       - this help function" << endl
             << "init n m T - initialize n-th through m-th elements to T" << endl
             << "iter n m   - iterate through range [n,m)" << endl
             << "rename P   - rename the backing file to P" << endl
             << "set n T    - set the n-th element to T" << endl
             << "size       - return the array size" << endl
             << "uniq n     - set elements i in [0,n) <- i" << endl;
      }
      else if (cmd=="init") {
        uint32_t n = strtoul(arg1.c_str(), NULL, 10);
        uint32_t m = strtoul(arg2.c_str(), NULL, 10);
        int t = strtol(arg3.c_str(), NULL, 10);
        if (m > fxary.size()) {
          cout << "range out of bounds\n";
          continue;
        }
        for (uint32_t i=n; i<m; ++i) {
          fxary[i] = t;
          cout << "fxary[" << i << "] <- " << t << endl;
        }
      }
      else if (cmd=="iter") {
        int n = strtol(arg1.c_str(), NULL, 10);
        int m = strtol(arg2.c_str(), NULL, 10);
				cout << "[n,m) = ["<<n<<','<<m<<")\n";
        for (int i=n; i<m; ++i) {
          cout << "fxary[" << i << "] = " << fxary[i] << endl;
        }
      }
      else if (cmd=="rename") {
        fxary.rename_backing_file(arg1);
      }
      else if (cmd=="set") {
        int n = strtol(arg1.c_str(), NULL, 10);
        int t = strtol(arg2.c_str(), NULL, 10);
        fxary[n] = t;
        cout << "fxary[" << n << "] = " << fxary[n] << endl;
      }
      else if (cmd=="size") {
        cout << "size = " << fxary.size() << endl;
      }
      else if (cmd=="uniq") {
				cout << "fxary.size() = " << fxary.size() << endl;
        for (uint32_t i=0; i<fxary.size(); ++i) {
          cout << "fxary[" << i << "] = " << i << endl;
					fxary[i] = i;
        }
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
