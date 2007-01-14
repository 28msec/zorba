/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: storage_manger_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "storage_manager.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	storage_manager storemgr("store_config.xml");
	cout << "done\n";
}
