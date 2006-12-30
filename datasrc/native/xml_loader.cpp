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

#include "../../util/xqpexception.h"
#include "xml_scanner.h"


using namespace std;
namespace xqp {

void xml_loader::error(std::string const& msg) 
throw (xqpexception)
{
	cout << "xml_loader::error: " << msg << endl;
	throw xqpexception("XML_LOADER", msg);
}

void xml_loader::load_xml_file(
	std::string const& path,
	std::string const& uri,
	xml_ostream& xos)
throw (xqpexception)
{
	file f(path);
	if (!f.exists()) error("file '"+path+"' not found");
	uint32_t n = (uint32_t)g.get_size();
	if (n>>26) error("file '"+path+"' exceeds 64MB");
	char* buf = new buf[n+1];
	f.readfile(buf,n);
	vector<string>
	xml_scanner xmls = xml_scanner();
	xml_handler* s = new xml_handler(uri,termv,xos);
	xmls.scan(buf, n, dynamic_cast<scan_handler*>(s));
	
}






}	/* namespace xqp */
