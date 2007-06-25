/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: functions.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "function.h"
#include "signature.h"
#include "runtime/zorba.h"
#include "zorba/zorba_qname.h"
#include "types/sequence_type.h"

using namespace std;
using namespace xqp;

class testfun : public function
{
public:
	testfun(const signature& sig) : function(sig) {}
	~testfun() {}

public:
	iterator_t operator()(zorba*,vector<iterator_t>&) const { return NULL; }
	sequence_type_t type_check(signature& sig) const { return xs_untypedValue; }
	bool validate_args(vector<iterator_t>& arglist) const { return true; }

};


int main(int argc, char* argv[])
{
	qname* fname_p = new zorba_qname(0,"prefix","localname");
	cout << "fname = "; fname_p->put(NULL,cout) << endl;
	signature sig(fname_p,xs_string);
	testfun f(sig);
}

