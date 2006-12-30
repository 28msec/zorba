/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_handler.h,v 1.1.1.1 2006/10/09 06:58:39 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

 
/*______________________________________________________________________
|  
|	Code inspired by the 'tagsoup' HTML parser,
|	written by John Cowan (cowan@ccil.org).
|_______________________________________________________________________*/


#ifndef XQP_XML_HANDLER_H
#define XQP_XML_HANDLER_H

#include <string>
#include <stack>
#include <ostream>
#include <utility>

#include "../../util/rchandle.h"
#include "../../util/URI.h"

#include "scan_handler.h"
#include "xml_ostream.h"
#include "xml_term.h"

namespace xqp {

class xml_handler : public scan_handler
{
  
public:    // types
  typedef pair<std::string,std::string> attrpair_t;
  typedef std::vector<attrpair_t>::const_iterator attrpair_it_t;

protected:  // state
	static const uint32_t STACK_CAPACITY = 65536;
	std::string the_stack[STACK_CAPACITY];

	uint32_t top;
  std::string the_attribute;			// most recent attribute
  std::string the_element;				// most recent element tag
	std::string	the_PCDATA;					// most recent PCDATA
  std::string	the_PITarget;				// most recent PITarget
  uint16_t the_entity;						// most recent entity 

	uint32_t term_pos;							// current term position
	uint32_t last_pos;							// last term position, for delta-coding
	uint64_t uri;										// current URI hash
	std::vector<xml_term>& term_v;	// index terms accumulator
	std::vector<attrpair_t> attr_v;	// attr @a=v accumulator

	// indexing switches
	bool term_indexing;							// index terms
	bool bigram_indexing;						// index term bigrams
	bool e_indexing;								// index elements
	bool p_indexing;								// index     c/word::t
	bool gp_indexing;								// index   b/c/word::t
	bool ggp_indexing;							// index a/b/c/word::t

	xml_ostream& xos;

public:	// ctor, dtor
	xml_handler(
		uint64_t uri,
	  std::vector<xml_term>&,				// accumulate terms here
	  xml_ostream&);								// accumulate document here

	~xml_handler() {}

protected:
	void error(std::string const& msg) const throw (xqpexception);

public:	

	void add_term(xml_term const&);
	void add_term(std::string const& term, uint64_t uri, uint32_t pos);

	uint32_t get_term_position() const { return term_pos; }
	uint32_t short get_entity() { return the_entity; }

public:	// callback methods

	//  Report an attribute name with no value.
	void adup(const char* buf, int offset, int length);

	//  Report an attribute name, a value will follow;
	void aname(const char* buf, int offset, int length);

	//  Report an attribute value.
	void aval(const char* buf, int offset, int length);

	//  Report and entity reference or character reference.
	void entity(const char* buf, int offset, int length);

	//  Report EOF.
	void eof(const char* buf, int offset, int length);

	//  Report end tag.
	void etag(const char* buf, int offset, int length);

	//  Report general identifier (element type name) of a start tag.
	void gi(const char* buf, int offset, int length);

	//  Report character data.
	void pcdata(const char* buf, int offset, int length);

	//  Report the data part of a processing instruction.
	void pi(const char* buf, int offset, int length);

	//  Report the target part of a processing instruction.
	void pitarget(const char* buf, int offset, int length);

	//  Report the close of a start tag.
	void stagc(const char* buf, int offset, int length);

	//  Report a comment.
	void cmnt(const char* buf, int offset, int length);

	void handle_pcdata(const char*, int, int);

};

}	/* namespace xqp */
#endif	/* XQP_XML_HANDLER_H */
