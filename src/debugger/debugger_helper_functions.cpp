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
#include "debugger_helper_functions.h"
#include "zorbatypes/xqpstring.h"

#include <string>

using namespace std;

zorba::xqpString zorba::debugger_helper_functions::deascapeString( xqpString str )
{
	string st = str.c_str();
	string::size_type pos;
	while ((pos = st.find("\\\\")) != string::npos) {
		st.replace(pos, 2, "\\");
	}
	return st;
}
