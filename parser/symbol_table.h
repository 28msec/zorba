/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: symbol_table.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 */

#ifndef XQP_SYMBOL_TABLE_H
#define XQP_SYMBOL_TABLE_H

#include "util/fxcharheap.h"
#ifndef _WIN32_WCE
	#include <sys/types.h>
#else
	#include <windows.h>
	#include <types.h>
#endif

namespace xqp {

class symbol_table
{
protected:	// state
	fxcharheap heap;

public:			// ctor,dtor
	symbol_table(uint32_t initial_heapsize=1024);
	~symbol_table();

public:			// table interface
	off_t put(char const* text, uint32_t length);
	off_t put_ncname(char const* text, uint32_t length);
	off_t put_qname(char const* text, uint32_t length);
	off_t put_uri(char const* text, uint32_t length);
	off_t put_varname(char const* text, uint32_t length);
	off_t put_entityref(char const* text, uint32_t length);
	off_t put_charref(char const* text, uint32_t length);
	off_t put_stringlit(char const* text, uint32_t length);

	std::string get(off_t id);
	uint32_t size() const;

	long double decimalval(char const* text, uint32_t length);
	double doubleval(char const* text, uint32_t length);
	int intval(char const* text, uint32_t length);

};

}	/* namespace xqp */
#endif	/* XQP_SYMBOL_TABLE */

