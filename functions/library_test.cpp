/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: function_library_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: Paul Pedersen
 *
 */

#include "library.h"
#include "functions/Numerics.h"

using namespace std;
using namespace xqp;

signature op_add_sig;
op_numeric_add op_add;

int main(int argc, char* argv[])
{
	library lib;



	lib.put(
		functab_entry(
			new QName("fn1"),fn1,1,1,{ item() },item()));
	
}

