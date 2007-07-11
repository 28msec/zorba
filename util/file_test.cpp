/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: file_test.cpp,v 1.2 2006/10/13 06:53:30 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#include "file.h"

#include <iostream>
#include <sstream>
#include "xqp_exception.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	try {
		file e("/");
		e.do_statfs("/");
  	cout << "block size = " << e.get_block_size() << endl;
  	cout << "total blocks = " << e.get_total_blocks() << endl;
  	cout << "available blocks = " << e.get_avail_blocks() << endl;
  	cout << "total inodes = " << e.get_total_inodes() << endl;
  	cout << "available inodes = " << e.get_avail_inodes() << endl;
  	cout << "volume type = " << e.get_volume_type() << endl;
  	cout << "access = " << e.get_access() << endl;
  	cout << "has set UID = " << e.has_set_uid() << endl;
  	cout << "has truncated names = " << e.has_truncated_names() << endl;
  	cout << "is empty = " << e.is_empty() << endl;

		file f("file.cpp");
		cout << "size    = " << f.get_size() << endl;
		cout << "path    = " << f.get_path() << endl;
		cout << "type    = " << f.get_filetype() << endl;
		cout << "invalid = " << f.is_invalid() << endl;
		cout << "dir     = " << f.is_directory() << endl;
		cout << "file    = " << f.is_file() << endl;
		cout << "link    = " << f.is_link() << endl;
		cout << "volume  = " << f.is_volume() << endl;
		cout << "exists  = " << f.exists() << endl;
		cout << "size    = " << f.get_size() << endl;
		cout << "accTime = " << f.get_acctime() << endl;
		cout << "modTime = " << f.get_modtime() << endl;
		cout << "owner   = " << f.get_ownerid() << endl;
		cout << "group   = " << f.get_groupid() << endl;
		cout << "perms   = " << f.get_permissions() << endl;

		file d(".");
		if(!d.exists()) {
			cout << "testdir does not exist\n";
			return -1;
		}
		file::dir_iterator it = d.begin();
		file::dir_iterator end = d.end();
		for (; it!=end; ++it) {
			cout << *it << endl;
		}

		char* buf = new char[f.get_size()+1];
		int n = f.readfile(buf,f.get_size());
		istringstream iss(string(buf,0,n),ios::in);
		string line;
		while (!iss.eof()) {
			getline(iss,line);
			cout << line << endl;
		}
	} catch (xqp_exception& e) {
		cout << "Exception: " << e.get_msg() << endl;
	}
}

