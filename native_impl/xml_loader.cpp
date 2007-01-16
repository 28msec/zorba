/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_loader.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "xml_loader.h"

#include <string>
#include <vector>

#include "../util/file.h"
#include "../util/xqp_exception.h"
#include "xml_handler.h"
#include "xml_scanner.h"
#include "xml_term.h"


using namespace std;
namespace xqp {

void xml_loader::error(string const& msg) 
throw (xqp_exception)
{
	cout << "xml_loader::error: " << msg << endl;
	throw xqp_exception("XML_LOADER", msg);
}

void xml_loader::load_xml_file(
	string const& path,
	string const& uri,
	xml_ostream& xos)
throw (xqp_exception)
{
	file f(path);
	if (!f.exists()) error("file '"+path+"' not found");
	uint32_t n = (uint32_t)f.get_size();
	if (n>>26) error("file '"+path+"' exceeds 64MB");
	char* buf = new char[n+1];
	f.readfile(buf,n);
	vector<xml_term> termv;
	xml_scanner xmls = xml_scanner();
	xml_handler* s = new xml_handler(uri,termv,xos);
	xmls.scan(buf, n, dynamic_cast<scan_handler*>(s));
	
}


}	/* namespace xqp */

