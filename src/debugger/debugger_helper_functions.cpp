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