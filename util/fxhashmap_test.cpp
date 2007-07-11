/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: fxhashmap_test.cpp 746 2006-06-15 03:48:34Z paul $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#include "fxhashmap.h"
#include "tokenbuf.h"
#include "xqp_exception.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
  try {
    fxhashmap<uint64_t>* m_p;
		if (argc==1) {
			m_p = new fxhashmap<uint64_t>(.6);
		} else {
    	m_p = new fxhashmap<uint64_t>(argv[1], .6);
		}
		fxhashmap<uint64_t>& m= *m_p;

    // command loop
		string cmdline, cmd, arg1, arg2;
		uint32_t arg_count = 0;

    while (true) {
			getline(cin, cmdline);
			if (cmdline.length()==0) continue;
			
			tokenbuf tokbuf(cmdline.c_str()," ");
			tokbuf.set_lowercase(false);
			tokbuf.set_return_delims(false);

			tokenbuf::token_iterator it = tokbuf.begin();
			tokenbuf::token_iterator end = tokbuf.end();
			
			cmd = *it;
			if (it!=end) { ++it; arg1 = *it; ++arg_count; }
			if (it!=end) { ++it; arg2 = *it; ++arg_count; }

			cout << "cmd = " << cmd << endl;
			if (arg_count>0) cout << "arg1 = " << arg1 << endl;
			if (arg_count>1) cout << "arg2 = " << arg2 << endl;

      if (cmd=="quit" || cmd=="exit") {
				break;
			}
			else if (cmd=="dirsize") {
        cout << "Directory size = "<<m.dirSize()<<endl;
      }
      else if (cmd=="help") {
        cout << "dirsize     - print current directory size\n";
        cout << "help        - this help function\n";
        cout << "iter        - iterate through this hash map\n";
        cout << "load FNAME  - load a new word list, consecutive keys\n";
        cout << "put TERM    - add (term,next consecutive key) to map\n";
        cout << "size        - return the size of this map\n";
        cout << "find TERM   - find this term\n";
      }
      else if (cmd=="iter") {
        m.displayEntries();
      }
      else if (cmd=="load") {
				cout << "fname = "<<arg1<<endl;
				ifstream in(arg1.c_str(), ios::in);
        int n = m.size();
				string line;
        while (!in.eof()) {
					getline(in, line);
					cout << line << endl;
					/*
					if (line=="mechanical") {
						int a = 1;
						int b = 1/(1-a);
						cout << "b = " <<  b << endl;	// jump to line 85
					}
					*/
          m.put(line,n++);
        }
        in.close();
        cout << "Load finished\n";
      }
      else if (cmd=="put") {
        m.put(arg1,m.size()+1);
        cout <<"        => "<<m.size()<<endl;
      }
      else if (cmd=="size") {
        cout <<"size = "<<m.size()<<endl;
      }
      else if (cmd=="find") {
				uint64_t v;
        if (m.get(arg1,v)) {
        	cout << "get("<<arg1<<") = " << v << endl;
				}
				else {
        	cout << "get("<<arg1<<") = not found" << endl;
				}
      }
    }
  } catch (xqp_exception& e) {
    cout << "application exception: " << e.what() << '\t' << e.get_msg() << endl;
  }
  return 0;
}
