/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: hashmap_test.cpp,v 1.2 2006/10/11 00:13:43 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation. 
 *	Author: Paul Pedersen
 *
 */

#include "hashmap.h"

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

#include "xqp_exception.h"
#include "tokenbuf.h"

using namespace std;
using namespace xqp;


void handle_cmd(
	hashmap<uint32_t>& m,
	const string& cmdline)
{
	string cmd, arg1, arg2;
	uint32_t arg_count = 0;

	tokenbuf tokbuf(cmdline.c_str()," )");
	tokbuf.set_lowercase(false);
	tokbuf.set_return_delims(false);

	tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();
			
	cmd = *it;
	if (it!=end) { ++it; arg1 = *it; ++arg_count; }
	if (it!=end) { ++it; arg2 = *it; ++arg_count; }

	cout << "cmd = " << cmd << endl;
	cout << "arg1 = " << arg1 << endl;
	cout << "arg2 = " << arg2 << endl;
	
	if (cmd=="(quit" || cmd=="(exit") {
		exit(0);
	}
	else if (cmd=="(alloc") {
		cout << "Allocated size = " << m.tabSize() << endl;
	}
	else if (cmd=="(dump") {
		cout << "Hash table dump:\n";
		m.displayEntries();
	}
	else if (cmd=="(get") {
		if (arg_count < 1) {
			cerr << "Expecting one arg: key\n";
			return;
		}
		uint32_t x;
		if (m.get(arg1.c_str(),x)) {
			cout << arg1 << " => " << x << endl; 
		} else {
			cout << arg1 << " => Not found\n";
		}
	}
	else if (cmd=="(help") {
		cout << "(alloc)					- print allocated size\n";
		cout << "(dump)						- dump hash table\n";
		cout << "(get key)				- get hash value for a given key\n";
		cout << "(hash value)			- hash a given value\n";
		cout << "(help)						- this help function\n";
		cout << "(iter)						- iterate across hash entry keys\n";
		cout << "(put key value)	- map a (key,value) pair\n";
		cout << "(redir fname)		-	redirect command input to file fname\n";
		cout << "(size)						- return the number of map entries\n";
		cout << "(tsize)					- return the array size of this map\n";
	}
	else if (cmd=="(hash ") {
		if (arg_count < 1) {
			cerr << "Expecting one arg: value\n";
			return;
		}
		uint32_t h  = m.h(arg1); 
		cout << " h = " << h << endl; 
	}
	else if (cmd=="(put") {
		if (arg_count < 2) {
			cerr << "Expecting two args: key value\n";
			return;
		}
		uint32_t n = strtoul(arg2.c_str(),NULL,10);
		m.put(arg1,n);
		cout << arg1 << " => " << n << endl; 
	}
	else if (cmd=="(redir") {
		if (arg_count < 1) {
			cerr << "Expecting one arg: fname\n";
			return;
		}
		ifstream in(arg1.c_str(),ios::in);
		string line;
		while (!in.eof()) {
			getline(in,line);
			handle_cmd(m,line);
		}
	}
	else if (cmd=="(iter")	{
		vector<hashmap<uint32_t>::entry>::const_iterator it = m.begin();
		vector<hashmap<uint32_t>::entry>::const_iterator end = m.end();
		for (; it!=end; ++it) {
			hashmap<uint32_t>::entry e = *it;
			cout << e.key <<  endl;
		}
	}
	else if (cmd=="(size") {
		cout << "Size = " << m.size() << endl;
	}
	else if (cmd=="(tsize") {
		cout << "Table size = " << m.tabSize() << endl;
	}
	else {
		cerr << "Unrecognized command\n";
	}
}


int main(int argc, char* argv[])
{
	try {
		hashmap<uint32_t> m(64, .6);
		string cmdline;
		
		while (true) {
			getline(cin, cmdline);
			if (cmdline.length()==0) continue;
			handle_cmd(m,cmdline);
		}
	} catch (xqp_exception& e) {
		cout << "Application exception: " << e.what() << '\t' << e.get_msg() << endl;
	}

	return 0;
}

