/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: fxcharheap_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#include "fxcharheap.h"

#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <vector>

#include "errors/xqp_exception.h"
#include "tokenbuf.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
  try {
    fxcharheap* h_p;
		if (argc>1) {
			h_p = new fxcharheap(argv[1], 65536);
		}
		else {
			h_p = new fxcharheap(65536);
		}

    vector<uint64_t> idv;
		string cmdline, cmd, arg1, arg2;
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
			if (it!=end) { ++it; arg1 = *it; ++argcount; }
			if (it!=end) { ++it; arg2 = *it; ++argcount; }

			cout << "cmd = " << cmd << endl;
			if (argcount>0) cout << "arg1 = " << arg1 << endl;
			if (argcount>1) cout << "arg2 = " << arg2 << endl;

      if (cmd=="quit" || cmd=="exit") {
				break;
			}
      else if (cmd=="cap") {
        cout << "capacity = "<<h_p->capacity()<<endl;
      }
      else if (cmd=="(help") {
        cout <<"cap         - print capacity\n";
        cout <<"help        - this help function\n";
        cout <<"iter        - run the heap iterator\n";
        cout <<"load FNAME  - load a file of strings\n";
        cout <<"size        - return the size of this heap\n";
      }
      else if (cmd=="iter") {
        unsigned k = 0;
        fxcharheap::const_iterator it = h_p->begin();
        fxcharheap::const_iterator end = h_p->end();
        for (; it!=end; ++it) {
          cout << "["<<(k++)<<"] = " << *it << endl;
        }
      }
      else if (cmd=="load") {
				ifstream in(arg1.c_str(),ios::in);
        string buf;
        while (!in.eof()) {
					getline(in,buf);
					if (buf.length()==0) continue;
					cout << "load(" << buf << ")\n"; 
          h_p->put(buf.c_str(), 0, buf.length());
        }
      }
      else if (cmd=="size") {
        cout << "size = " << h_p->size() << endl;
      }
      else {
        cout << "unrecognized command\n";
      }
    }
  } catch (xqp_exception& e) {
    cout << "Application exception: " << e.what() << '\t' << e.get_msg() << endl;
  }
  return 0;

}
