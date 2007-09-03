/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: scan_handler.cpp,v 1.1.1.1 2006/10/09 06:58:35 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

/*_______________________________________________________________________
|
|	Derived from the 'tagsoup' Java scanner.
|	Licensed under the Academic Free License (AFL) 3.0.
|	Original author: John Cowan (cowan@ccil.org).
|________________________________________________________________________*/


#include "scan_handler.h"

#include <iostream>
#include <string>
#include "../util/hashmap.h"

using namespace std;
namespace xqp {

// static initializers
bool scan_handler::static_init = false;
hashmap<unsigned short> scan_handler::entityMap(4096,0.6f);

scan_handler::scan_handler()
{
	if (!static_init) {
		static_init = true;
		for (unsigned i=0; i<947; ++i) {
			entityMap.put(entities[i].name, entities[i].codepoint);
		}
	}
}

void scan_handler::adup(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);;
	cout << "adup: " << (length>0?s:"") << endl;
}

void scan_handler::aname(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "aname: " << (length>0?s:"") << endl;
}

void scan_handler::aval(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "aval: " << (length>0?s:"") << endl;
}

void scan_handler::entity(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "entity: " << (length>0?s:"") << endl;
	unsigned short code;
  entityMap.get(s, code);
	ent = (char)code;
}

void scan_handler::eof(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "eof" << endl;
}

void scan_handler::etag(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "etag: " << (length>0?s:"") << endl;
}

void scan_handler::gi(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "gi: " << (length>0?s:"") << endl;
}

void scan_handler::pcdata(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "pcdata: " << (length>0?s:"") << endl;
}

void scan_handler::pi(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "pi: " << (length>0?s:"") << endl;
}

void scan_handler::pitarget(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "pitarget: " << (length>0?s:"") << endl;
}

void scan_handler::stagc(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "stagc: " << (length>0?s:"") << endl;
}

void scan_handler::cmnt(
	const char* buf,
	int offset,
	int length)
{
	string s(buf,offset,length);
	cout << "cmnt: " << (length>0?s:"") << endl;
}

unsigned short scan_handler::getEntity()
{
	return ent;
}

}	/* namespace xqp */

