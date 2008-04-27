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
#include "util/hashfun.h"

#include <iostream>
#include <string>

using namespace std;
using namespace zorba;

int main(int argc, char* argv[])
{
	string line;
	unsigned key = 0;
	while (!cin.eof()) {
		getline(cin, line);
		key = hashfun::h32(line);
		cout << "h(" << line << ") = " << key << endl;
		uint64_t key1 = hashfun::h64(line);
		cout << "h64(" << line << ") = " << key1 << endl;
		uint64_t key2 = hashfun::h64(line);
		cout << "h64(" << line << ") = " << key2 << endl;
		uint32_t key3 = (uint32_t)key2;
		cout << "(unsigned)h64(" << line << ") = " << key3 << endl;
	}
}
