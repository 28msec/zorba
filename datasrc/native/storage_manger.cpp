/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *	$Id: storage_manager.cpp,v 1.3 2006/10/13 06:53:30 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "storage_manager.h"

#include <stdlib.h>
#include <string>

#include "../../util/file.h"
#include "scan_handler.h"
#include "xml_scanner.h"


using namespace std;
namespace xqp {

class storage_manager_config_parser : public scan_handler
{
protected:
	enum config_item_t {
		INIT,
		PATH,
		LG_MIN,
		LG_MAX,
		LG_BREAK
	} config_item;

	std::string path;
	uint32_t lgmin;
	uint32_t lgmax;
	uint32_t lgbreak;

public:	// ctor, dtor
	storage_manager_config_parser() : config_item(INIT) {}
	~storage_manager_config_parser() {}

public:	// callback methods
	void adup(const char* buf, int offset, int length);		 	// attribute name, no value
	void aname(const char* buf, int offset, int length);		// attribute name, with value
	void aval(const char* buf, int offset, int length);			// attribute value
	void entity(const char* buf, int offset, int length);		// entity or char ref
	void eof(const char* buf, int offset, int length);			// EOF
	void etag(const char* buf, int offset, int length);			// end tag
	void gi(const char* buf, int offset, int length);				// element name start tag 
	void pcdata(const char* buf, int offset, int length);		// character data
	void pi(const char* buf, int offset, int length);				// data part of a PI
	void pitarget(const char* buf, int offset, int length); // target part of PI 
	void stagc(const char* buf, int offset, int length);		// close of start tag
	void cmnt(const char* buf, int offset, int length);			// comment

public:	// manipulators
	std::string get_path() const { return path; }
	uint32_t get_lgmin() const { return lgmin; }
	uint32_t get_lgmax() const { return lgmax; }
	uint32_t get_lgbreak() const { return lgbreak; }

};


void storage_manager_config_parser::adup(
	const char* buf,
	int offset,
	int length)
{
}

void storage_manager_config_parser::aname(
	const char* buf,
	int offset,
	int length)
{
}

void storage_manager_config_parser::aval(
	const char* buf,
	int offset,
	int length)
{
}

void storage_manager_config_parser::entity(const char* buf,int offset,int length) { }
void storage_manager_config_parser::eof(const char* buf,int offset,int length) { }

void storage_manager_config_parser::etag(
	const char* buf,
	int offset,
	int length)
{
	config_item = INIT;
}

#define MATCH 0

void storage_manager_config_parser::gi(
	const char* buf,
	int offset,
	int length)
{
	if (strncmp(buf+offset,"path",length)==MATCH) config_item = PATH;
	else if (strncmp(buf+offset,"lgmin",length)==MATCH) config_item = LG_MIN;
	else if (strncmp(buf+offset,"lgmax",length)==MATCH) config_item = LG_MAX;
	else if (strncmp(buf+offset,"lgbreak",length)==MATCH) config_item = LG_BREAK;
}

void storage_manager_config_parser::pcdata(
	const char* buf,
	int offset,
	int length)
{
	switch (config_item) {
	case PATH: path = string(buf,offset,length); break;
	case LG_MIN: lgmin = strtoul(buf+offset,NULL,10); break;
	case LG_MAX: lgmax = strtoul(buf+offset,NULL,10); break;
	case LG_BREAK: lgbreak = strtoul(buf+offset,NULL,10); break;
	default: ;/* ignore */
	}
}

void storage_manager_config_parser::pi(const char* buf,int offset,int length) { }
void storage_manager_config_parser::pitarget(const char* buf,int offset,int length) { }
void storage_manager_config_parser::stagc(const char* buf,int offset,int length) { }
void storage_manager_config_parser::cmnt(const char* buf,int offset,int length) { }




storage_manager::storage_manager(
	const std::string& config_path)
{
	file f(config_path);
	uint32_t n = (uint32_t)f.get_size();
	char* buf = new char[n+1];
	try {
		f.readfile(buf,n);
	} catch (xqpexception& e) {
		cout << "config file i/o error: " << e.get_msg() << endl;
		return;
	}
	xml_scanner xmls = xml_scanner();
	storage_manager_config_parser* config_parser_p =
		new storage_manager_config_parser();
	xmls.scan(buf, n, dynamic_cast<scan_handler*>(config_parser_p));

	cout << "path = " << config_parser_p->get_path() << endl;
	cout << "lgmin = " << config_parser_p->get_lgmin() << endl;
	cout << "lgmax = " << config_parser_p->get_lgmax() << endl;
	cout << "lgbreak = " << config_parser_p->get_lgbreak() << endl;

}

storage_manager::~storage_manager()
{
}

int storage_manager::get(
	blockid	id,
	char*& data)
{
  return 0;
}


blockid storage_manager::put(
	const char* buf,
	uint32_t offset,
	uint32_t length)
{
	return blockid(0,0);
}



}	/* namespace xqp */
