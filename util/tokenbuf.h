/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: tokenbuf.h,v 1.1 2006/10/09 07:08:04 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_TOKENBUF_H
#define XQP_TOKENBUF_H

#include <iostream>
#include <string>

namespace xqp {

/*______________________________________________________________________
		
		Tokenized string buffer datamodel interface.
	______________________________________________________________________*/

class tokenbuf
{
public:
	char const* txt;			// target text
	uint32_t txtlen;			// length of target text array
	char const* delimset;	// list of character deimiters
	uint32_t delimsetlen;	// length of delimset
	bool lowercase;				// true => lower-case all tokens
	bool return_delims;		// true => token,delim,token,delim,...

public:
	tokenbuf(char const* buf, char const* delimset);
	~tokenbuf();

public:	// manipulators
	void set_lowercase(bool b=true) { lowercase = b; }
	bool get_lowercase() { return lowercase; }
	void set_return_delims(bool b=true) { return_delims = b; }
	bool get_return_delims() { return return_delims; }

private:
	tokenbuf(tokenbuf const& x) { }

public:	// iterators

	class token_iterator
	{
	protected:	// state
		tokenbuf const* buf_p;
		std::string next_token;	// returned token
		std::string next_delim;	// returned delim
		std::string const* return_val_p;	// either &next_token, or &next_delim
		uint32_t cursor;				// cursor into txt
		uint32_t token_index;		// position of most recent token
		uint32_t delim_index;		// position of most recent delim
		uint32_t token_length;	// length of current token
		uint32_t delim_length;	// length of current delim
		bool token_parity;			// 0 => delim, 1 => token
	
	public:	// ctor,dtor
		token_iterator(tokenbuf const* buf_p, uint32_t offset);
		~token_iterator();
	
	public:	// iterator interface
		std::string const& operator*();
		void operator++();
	
	public:	// manipulators
		inline uint32_t get_token_pos() const { return token_index; }
		inline uint32_t get_token_len() const { return token_length; }
		inline uint32_t get_delim_pos() const { return delim_index; }
		inline uint32_t get_delim_len() const { return delim_length; }
		std::string& get_delim() { return next_delim; }	// return delim defining token

		friend bool operator!=(token_iterator const& x, token_iterator const& y);
	};

public:
	token_iterator begin();
	token_iterator end();

};



}	/* namespace xqp */
#endif	/* XQP_TOKENBUF_H */
