/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xquery_driver.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "xquery_driver.h"
#include "xquery_parser.tab.h"

using namespace std;

xquery_driver::xquery_driver(
  ostream& _os,
  uint32_t initial_heapsize)
:
	trace_scanning(false),
	trace_parsing(false),
	symtab(initial_heapsize),
  os(_os),
	rename_bit(false),
	ftcontains_bit(false)
{
}

xquery_driver::~xquery_driver()
{
}
     
void xquery_driver::parse(
	string const& fname)
{
	file = fname;
	scan_begin();
	yy::xquery_parser parser(*this);
	parser.set_debug_level(trace_parsing);
	parser.parse();
	scan_end();
}
     
void xquery_driver::error(
	yy::location const& l,
	string const& m)
{
	cerr << l << ": " << m << endl;
}
     
void xquery_driver::error(
	string const& m)
{
	cerr << m << endl;
}

