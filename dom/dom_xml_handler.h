/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: dom_xml_handler.h,v 1.1.1.1 2006/10/09 06:58:39 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *	Author: John Cowan,Paul Pedersen
 *
 */
 
/*______________________________________________________________________
|  
|	Code derived from the 'tagsoup' HTML parser,
|	written by John Cowan (cowan@ccil.org).
|_______________________________________________________________________*/


#ifndef XQP_DOM_XML_HANDLER_H
#define XQP_DOM_XML_HANDLER_H

#include "dom_namepool.h"
#include "store/scan_handler.h"
#include "util/list.h"
#include "util/rchandle.h"
#include "util/URI.h"

#include <string>
#include <stack>
#include <ostream>
#include <sstream>
#include <utility>

namespace xqp {

class zorba;
class dom_node;
class dom_namespace_node;
class dom_attribute_node;
class dom_qname;
class dom_element_node;

struct ns_entry
{
	std::string prefix;
	std::string uri;

	ns_entry(const std::string& _prefix, const std::string& _uri)
		: prefix(_prefix), uri(_uri) {}
};


struct elem_entry
{
	qnamekey_t qnamekey;
	dom_element_node* en_p;
	list<ns_entry*> ns_list;

	elem_entry(
		qnamekey_t _qnamekey,
		dom_element_node* _en_p)
	:
		qnamekey(_qnamekey),
		en_p(_en_p)
	{}

	void push_back(ns_entry* nse_p) { ns_list.push_back(nse_p); }

};


struct attr_entry
{
	qnamekey_t qnamekey;
	std::string value;

	attr_entry(qnamekey_t _qnamekey, const std::string& _value)
		: qnamekey(_qnamekey), value(_value) {}
};


class dom_xml_handler : public scan_handler
{
protected:  // state
	std::stack<elem_entry*> node_stack;		// parser element node stack
	list<ns_entry*> nslist;								// in-scope namespaces list
	std::vector<attr_entry> attrv;				// attribute (qname,value) accumulator
	dom_namepool pool;										// qname pool
	char* the_baseuri;										// document base URI
  std::string the_attribute_prefix;			// most recent attribute prefix
  std::string the_attribute_uri; 				// most recent attribute namespace URI
  std::string the_attribute_name;				// most recent attribute localname
  std::string the_element;							// most recent element tag
	std::string	the_PCDATA;								// most recent PCDATA
  std::string	the_PITarget;							// most recent PITarget
  uint16_t the_entity;									// most recent entity 
	ostringstream textbuf;								// text accumulator
	dom_node* the_context_node;
	
	std::string default_attribute_prefix;
	std::string default_attribute_uri;
	std::string default_element_prefix;
	std::string default_element_uri;

public:		// ctor, dtor
	dom_xml_handler(
		std::string const& baseuri,					// document base URI
		std::string const& uri);						// document URI

	~dom_xml_handler() {}

protected:
//daniel	void error(std::string const& msg) const throw (xqp_exception);

public:	
	void flush_textbuf_as_text_node();
	bool find_nsuri(const std::string& prefix, std::string& uri);
	
	qnamekey_t process_qname(
  	const char* buf, int offset, int length,
  	const std::string& default_prefix,
  	const std::string& default_uri);
  	
  void add_namespace(dom_namespace_node*);
  void add_attribute(dom_attribute_node*);
  void add_child(dom_node*);

	dom_node* context_node() const { return the_context_node; }
	void display_context_node() const;
	uint16_t entity() { return the_entity; }

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
#endif	/* XQP_DOM_XML_HANDLER_H */
