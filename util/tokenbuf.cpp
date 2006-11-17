/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: token_iterator.cpp,v 1.1 2006/10/09 07:08:04 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "tokenbuf.h"


using namespace std;
namespace xqp {


tokenbuf::tokenbuf(
	char const* _txt,
	char const* _delimset)
:
	txt(_txt),
	txtlen(strlen(txt)),
	delimset(_delimset),
	delimsetlen(strlen(delimset)),
	lowercase(false)
{
}


tokenbuf::~tokenbuf()
{
}


tokenbuf::token_iterator tokenbuf::begin()
{
	return tokenbuf::token_iterator(this,0);
}


tokenbuf::token_iterator tokenbuf::end()
{
	return tokenbuf::token_iterator(this,txtlen);
}


tokenbuf::token_iterator::token_iterator(
	tokenbuf const* _buf_p,
	uint32_t offset)
:
	buf_p(_buf_p),
	next_token(""),
	next_delim(""),
	return_val_p(NULL),
	cursor(offset),
	token_index(offset),
	delim_index(offset),
	token_length(0),
	delim_length(0),
	token_parity(false)
{
	if (!buf_p->return_delims) {
		// scan past leading delims
		cursor += strspn(buf_p->txt+offset,buf_p->delimset);
	}
	++(*this);
}


tokenbuf::token_iterator::~token_iterator()
{}


string const& tokenbuf::token_iterator::operator*()
{
	return *return_val_p;
}


void tokenbuf::token_iterator::operator++()
{
	if (buf_p->return_delims) {
		token_parity = ~token_parity;
		if (!token_parity) return_val_p = &next_delim;
	}

	// find the next token
  next_token.clear();
	char c = ' ';
	bool match = false;
	token_index = cursor;
  for (; cursor<buf_p->txtlen; ++cursor) {
		c = buf_p->txt[cursor];
		cout << "c = " << c << endl;	//XXX DEBUG
    if (buf_p->lowercase && 'A'<=c && c<='Z') c |= 0x20;
		match = false;
    for (uint32_t i=0; i<buf_p->delimsetlen; ++i) {
			// { Exist(d in D) : d==c }
      if (c==buf_p->delimset[i]) { match = true; break; }
    }
		if (match) { ++cursor;  break; } 	// must! maintain invariant on 'cursor'
    next_token += c;
  }
	token_length = cursor - token_index - 1;
	cout << "token_length = " << token_length << endl;	//XXX DEBUG

	// find the next delim
	next_delim.clear();
	if (match) next_delim += c;
	delim_index = cursor-1;
  for (; cursor<buf_p->txtlen; ++cursor) {
    c = buf_p->txt[cursor];
		cout << "c = " << c << endl;	//XXX DEBUG
    match = false;
    for (uint32_t i=0; i<buf_p->delimsetlen; ++i) {
			// { Exists(d in D) : d==c }
     	if (c==buf_p->delimset[i]) { match = true; break; }
   	}
    if (!match) break;
		next_delim += c;
  }
	delim_length = cursor - delim_index;
	cout << "delim_length = " << delim_length << endl;	//XXX DEBUG
  return_val_p = &next_token;
}


bool operator!=(
	tokenbuf::token_iterator const& x,
	tokenbuf::token_iterator const& y)
{
	if (x.buf_p != y.buf_p) return true;
	if (x.cursor != y.cursor) return true;
	return false;
}


}	/* namespace xqp */

