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
#include "tiny_json/json.hpp"

namespace json{
	boost::any parse(char const * szFirst, char const * szEnd)
	{
		// 1: parse the input...

		json::stack st;
		json::grammar gr(st);

		boost::spirit::parse_info<> pi = boost::spirit::parse(szFirst, szEnd, gr, boost::spirit::space_p);
		if(!pi.full || (st.size() != 1)) {

			return boost::any();
		}

		// 2: return the result...

		return st.top();
	}
}
