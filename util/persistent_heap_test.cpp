/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: persistent_heap_unittest.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 Paul Pedersen.  All Rights Reserved.
 *
 */

#include "persistent_heap.h"

#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <vector>

#include "Exception.h"
#include "tokenbuf.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
  try {
    persistent_heap h(argv[1]);
    vector<uint64_t> idv;
		string cmdline;
		string cmd, arg1, arg2;
    
    // check metadata
    cout << "h.size() = " << h.size() << endl;
    cout << "h.capacity() = " << h.capacity() << endl;

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

      if (cmd=="(quit" || cmd=="(exit") break;

      else if (cmd=="(capacity") {
        cout << "Capacity = "<<h.capacity()<<endl;
      }
      else if (cmd=="(help") {
        cout <<"(capacity)           - print capacity\n";
        cout <<"(help)               - this help function\n";
        cout <<"(iter)               - run the heap iterator\n";
        cout <<"(b_iter START COUNT) - run the heap iterator\n";
        cout <<"(load fname)         - load a file of strings\n";
        cout <<"(size)               - return the size of this heap\n";
      }
      else if (cmd=="(iter") {
        unsigned k = 0;
        persistent_heap::const_iterator it = h.iterator();
        for (; !it.done(); ++it) {
          cout << "["<<(k++)<<"] = " << *it << endl;
        }
      }
      else if (cmd=="(b_iter") {
        int start = strtol(arg1.c_str(), NULL, 10);
        int count = strtol(arg2.c_str(), NULL, 10);
        cout << "(start,count) = (" << start << ',' << count << ")\n";
        persistent_heap::const_bounded_iterator it = h.bounded_iterator(start,count);
        for (int k=0; !it.done(); ++it,++k) {
          cout << "heap["<<k<<"] = " << *it << endl;
        }
      }
      else if (cmd=="(load") {
				ifstream in(arg1.c_str(),ios::in);
        string buf;
        while (!in.eof()) {
					getline(in,buf);
					cout << buf << endl;
          h.put(buf.c_str(), 0, buf.length());
        }
        cout << "_____________Load finished______________\n";
      }
      else if (cmd=="(size") {
        cout << "size = " << h.size() << endl;
      }
      else {
        cout << "Unrecognized command\n";
      }
    }
  } catch (Exception& e) {
    cout << "Application exception: " << e.what() << '\t' << e.getMsg() << endl;
  }
  return 0;

}
