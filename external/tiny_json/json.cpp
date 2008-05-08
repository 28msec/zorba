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
