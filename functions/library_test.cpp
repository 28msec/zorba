/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: function_library_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: Paul Pedersen
 *
 */

#include "function_library.h"
#include "../types/base_types.h"
#include "../types/sequence_types.h"
#include "../values/values.h"
#include "../values/qname_value.h"

using namespace std;
using namespace xqp;

rchandle<item_iterator> fn1(context * ctx_p)
{
}


int main(int argc, char* argv[])
{
	function_library lib;

	lib.put(
		functab_entry(
			new QName("fn1"),fn1,1,1,{ item() },item()));
	
}


public:
	void put(rchandle<funtab_entry>);
	rchandle<funtab_entry> get(std::string const&);

};


} /* namespace xqp */
#endif /* XQP_FUNCTION_LIBRARY_H */

