/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: token_iterator.cpp,v 1.1 2006/10/09 07:08:04 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "util/tokenbuf.h"

using namespace std;
namespace xqp {


tokenbuf::tokenbuf(
	char const* _txt,
	char const* _delimset)
:
	txt(_txt),											// target text
	txtlen(strlen(txt)),						// length of target text array
	delimset(_delimset),						// list of character delimiters
	delimsetlen(strlen(delimset)),	// length of delimset
	lower_case(false),							// true => return lower-case tokens
	return_delims(false)						// true => return: token,delim,token,delim,...
{
}


tokenbuf::tokenbuf(
	char const* _txt,
	uint32_t		_offset,
	uint32_t		_length,
	char const* _delimset)
:
	txt(_txt+_offset),							// target text
	delimset(_delimset),						// list of character delimiters
	delimsetlen(strlen(delimset)),	// length of delimset
	lower_case(false),							// true => return lower-case tokens
	return_delims(false)						// true => return: token,delim,token,delim,...
{
	txtlen = strlen(txt) < _length ? strlen(txt) : _length;
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
	buf_p(_buf_p),					// parent tokenbuf
	next_token(""),					// returned token
	next_delim(""),					// returned delimiter
	return_val_p(NULL),			// either &next_token or &next_delim
	cursor(offset),					// cursor into buf_p->txt
	token_index(offset),		// position of current token
	delim_index(offset),		// position of current delimiter
	token_length(0),				// length of current token
	delim_length(0),				// length of current delimiter
	token_parity(false)			// 0 => delim, 1 => token
{
	if (!buf_p->return_delims && offset < buf_p->get_txtlen()) {
		cursor += strspn(buf_p->txt+offset,buf_p->delimset);
		// (i.e.) scan past leading delims for 'begin()' iterator, not 'end()'
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
		token_parity = !token_parity;
		if (!token_parity) return_val_p = &next_delim;
	}

	// find the next token
  next_token.clear();
	char c = ' ';
	bool match = false;
	token_index = cursor;
  for (; cursor<buf_p->txtlen; ++cursor) {
		c = buf_p->txt[cursor];
    if (buf_p->lower_case && 'A'<=c && c<='Z') c |= 0x20;
		match = false;
    for (uint32_t i=0; i<buf_p->delimsetlen; ++i) {
			// check:  Exist(d in D) ( d==c )
      if (c==buf_p->delimset[i]) { match = true; break; }
    }
		if (match) { ++cursor;  break; } 	// must maintain invariant on 'cursor'
    next_token += c;
  }
	token_length = cursor - token_index - 1;

	// find the next delim
	next_delim.clear();
	if (match) next_delim += c;
	delim_index = cursor-1;
  for (; cursor<buf_p->txtlen; ++cursor) {
    c = buf_p->txt[cursor];
    match = false;
    for (uint32_t i=0; i<buf_p->delimsetlen; ++i) {
			// check:  Exists(d in D) ( d==c )
     	if (c==buf_p->delimset[i]) { match = true; break; }
   	}
    if (!match) break;
		next_delim += c;
  }
	delim_length = cursor - delim_index;
  return_val_p = &next_token;
}

/*
#define iter_state \
	cout << "x.("<<x.cursor<<','<<x.token_index<<','<<x.delim_index<<")\n"; \
	cout << "y.("<<y.cursor<<','<<y.token_index<<','<<y.delim_index<<")\n"; 
*/

bool operator!=(
	tokenbuf::token_iterator const& x,
	tokenbuf::token_iterator const& y)
{
	if (x.buf_p != y.buf_p)   { return true; }
	if (x.cursor != y.cursor) { return true; }
	if (x.token_index != y.token_index) { return true; }
	if (x.delim_index != y.delim_index) { return true; }
	return false;
}

bool operator==(
	tokenbuf::token_iterator const& x,
	tokenbuf::token_iterator const& y)
{
	if (x.buf_p != y.buf_p)   { return false; }
	if (x.cursor != y.cursor) { return false; }
	if (x.token_index != y.token_index) { return false; }
	if (x.delim_index != y.delim_index) { return false; }
	return true;
}


}	/* namespace xqp */

