/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: persistent_charheap_unittest.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 Paul Pedersen.  All Rights Reserved.
 *
 */

#include "persistent_charheap.h"

#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <vector>

#include "xqpexception.h"
#include "tokenbuf.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
  try {
    persistent_charheap heap(argv[1]);
    vector<uint64_t> idv;
		string cmdline;
		string cmd, arg1, arg2;
    
    // check metadata
    cout << "heap.size() = " << heap.size() << endl;
    cout << "heap.capacity() = " << heap.capacity() << endl;

    // command loop
    while (true) {
			getline(cin, cmdline);
			if (cmdline.length()==0) continue;
			
			tokenbuf tokbuf(cmdline.c_str()," )");
			tokbuf.set_lowercase(false);
			tokbuf.set_return_delims(false);

			tokenbuf::token_iterator it = tokbuf.begin();
			tokenbuf::token_iterator end = tokbuf.end();
			
			cmd = *it;
			if (it!=end) { ++it; arg1 = *it; }
			if (it!=end) { ++it; arg2 = *it; }

			cout << "cmd = " << cmd << endl;
			cout << "arg1 = " << arg1 << endl;
			cout << "arg2 = " << arg2 << endl;

      if (cmd=="(quit" || cmd=="(exit") {
				break;
			}
      else if (cmd=="(capacity") {
        cout << "Capacity = "<<heap.capacity()<<endl;
      }
      else if (cmd=="(help") {
        cout <<"(capacity)           - print capacity\n";
        cout <<"(help)               - this help function\n";
        cout <<"(iter)               - run the heap iterator\n";
        cout <<"(load fname)         - load a file of strings\n";
        cout <<"(size)               - return the size of this heap\n";
      }
      else if (cmd=="(iter") {
        unsigned k = 0;
        persistent_charheap::const_iterator it = heap.begin();
        persistent_charheap::const_iterator end = heap.end();
        for (; it!=end; ++it) {
          cout << "["<<(k++)<<"] = " << *it << endl;
        }
      }
      else if (cmd=="(load") {
				ifstream in(arg1.c_str(),ios::in);
        string buf;
        while (!in.eof()) {
					getline(in,buf);
					cout << buf << endl;
          heap.put(buf.c_str(), 0, buf.length());
        }
        cout << "_____________Load finished______________\n";
      }
      else if (cmd=="(size") {
        cout << "size = " << heap.size() << endl;
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
