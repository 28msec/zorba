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
#include "util/file.h"

#include <iostream>
#include <sstream>
#include "errors/xqp_exception.h"

using namespace std;
using namespace zorba;

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

