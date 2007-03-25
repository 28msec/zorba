/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: dom_dom_xml_handler.cpp,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *	Author: John Cowan, Paul Pedersen
 *
 */

#include "dom_xml_handler.h"
#include "dom_qname.h"
#include "dom_nodes.h"

#include "../context/common.h"
#include "../values/values.h"
#include "../util/xqp_exception.h"
#include "../util/tokenbuf.h"
#include "../util/tracer.h"
#include "../util/URI.h"

#include <iostream>
#include <string>

using namespace std;
namespace xqp {


dom_xml_handler::dom_xml_handler(
	string const& baseuri,
	string const& uri)
:
	scan_handler(),
	the_attribute_prefix(""),
	the_attribute_uri(""),
	the_attribute_name(""),
	the_element(""),
	the_PCDATA(""),
	the_PITarget(""),
	the_entity(0),
	
	the_context_node(new dom_document_node(baseuri, uri)),
	
	default_attribute_prefix("noname"),
	default_attribute_uri("http://noname"),
	default_element_prefix("noname"),
	default_element_uri("http://noname")
{
}


void dom_xml_handler::error(string const& msg) const
throw (xqp_exception)
{
	throw xqp_exception("DOM_XML_HANDLER", msg);
}


bool dom_xml_handler::find_nsuri(
	const string& prefix,
	string& uri)
{
	list_iterator<ns_entry*> it = nslist.begin();
	for (; it!=nslist.end(); ++it) {
		ns_entry* ns_p = *it;
		if (ns_p->prefix==prefix) {
			uri = ns_p->uri;
			return true;
		}
	}
	return false;
}


qnamekey_t dom_xml_handler::process_qname(
	const char* buf, int offset, int length,
	const string& default_prefix,
	const string& default_uri)
{
	string prefix("");
	string uri("");
	string name = string(buf,offset,length);

	// parse 'prefix:name'
	string::size_type n = name.find(':');
	if (n!=string::npos) {
		prefix = name.substr(0,n);
		name = name.substr(n+1);
	}

	// find uri for prefix
	if (prefix.length()>0) {
		if (!find_nsuri(prefix,uri)) {
			cout << TRACE << " : unrecognized prefix: " << prefix << endl;
			return 0;
		}
	}
	else {
  	prefix = default_prefix;
  	uri = default_uri;
	}

	// cache qname, return key
	qnamekey_t qnamekey = dom_qname::hashkey(uri,prefix,name);
	dom_qname* qn_p;
	if (!pool.get_qname(qnamekey,qn_p)) {
		qn_p = new dom_qname(uri,prefix,name);
		qnamekey = pool.put_qname(qn_p);
	}
	return qnamekey;
}


void dom_xml_handler::add_child(
  dom_node* node_p)
{
  //cout << TRACE << " : add_child("; node_p->put(cout) << ")\n";
  dom_element_node* en_p = dynamic_cast<dom_element_node*>(the_context_node);
	if (en_p) { en_p->add_child(node_p); return; }
	dom_document_node* dn_p = dynamic_cast<dom_document_node*>(the_context_node);
  if (dn_p) { dn_p->add_child(node_p); return; }
  cout << TRACE << " : bad context node\n";
}

void dom_xml_handler::add_namespace(
  dom_namespace_node* ns_p)
{
  //cout << TRACE << " : add_namespace("; ns_p->put(cout) << ")\n";
  dom_element_node* en_p = dynamic_cast<dom_element_node*>(the_context_node);
	if (en_p) { en_p->add_namespace(ns_p); return; }
  cout << TRACE << " : bad context node\n";
}


void dom_xml_handler::add_attribute(
  dom_attribute_node* at_p)
{
  //cout << TRACE << " : add_attribute("; at_p->put(cout) << ")\n";
  dom_element_node* en_p = dynamic_cast<dom_element_node*>(the_context_node);
	if (en_p) { en_p->add_attribute(at_p); return; }
  cout << TRACE << " : bad context node\n";
}

void dom_xml_handler::display_context_node() const
{
  //cout << TRACE << " : add_child("; node_p->put(cout) << ")\n";
  dom_element_node* en_p = dynamic_cast<dom_element_node*>(the_context_node);
	if (en_p) { en_p->put(cout); return; }
	dom_document_node* dn_p = dynamic_cast<dom_document_node*>(the_context_node);
  if (dn_p) { dn_p->put(cout); return; }
  cout << TRACE << " : bad context node\n";
}



// attribute without value callback
void dom_xml_handler::adup(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	if (length==0) return;
	qnamekey_t qnkey = 
	  process_qname(buf,offset,length,
	                  default_attribute_prefix,
	                  default_attribute_uri);
	attrv.push_back(attr_entry(qnkey,""));
}


// attribute name callback
void dom_xml_handler::aname(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	if (length==0) return;
	qnamekey_t qnamekey =
	  process_qname(buf,offset,length,
	                  default_attribute_prefix,
	                  default_attribute_uri);
	attrv.push_back(attr_entry(qnamekey,""));
}


// attribute value callback
void dom_xml_handler::aval(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	if (length==0) return;
	string value = string(buf,offset,length);

	// check for 'xmlns:prefix="nsuri"'
	attr_entry& ae = attrv.back();
	qnamekey_t qnamekey = ae.qnamekey;
	dom_qname* qn_p;
	if (!pool.get_qname(qnamekey,qn_p)) {
		cout << TRACE << " : pool missing QName\n";
		return;
	}
	if (qn_p->prefix()=="xmlns") {
		ns_entry* nse_p = new ns_entry(qn_p->prefix(), value);
		nslist.push_back(nse_p);
		add_namespace(new dom_namespace_node(nse_p->prefix, nse_p->uri));
		return;
	}
	ae.value = value;
}


// &ent; entity callback
void dom_xml_handler::entity(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	string s(buf,offset,length);
	unsigned short code;
  entityMap.get(s, code);
	if (code==0) return;
	ent = (char)code;
}


// serialize concatenated text node
void dom_xml_handler::flush_textbuf_as_text_node()
{
  //cout << TRACE << endl;
	if (textbuf.str().length()>0) {
		add_child(new dom_text_node(textbuf.str()));
		textbuf.str("");
	}
}


// eof callback
void dom_xml_handler::eof(const char* buf, int offset, int length)
{
	flush_textbuf_as_text_node();
}


// end tag callback
void dom_xml_handler::etag(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	if (length==0) return;

	// add last concatenated text node
	flush_textbuf_as_text_node();

	// find matching tag
	qnamekey_t qnkey = 
	  process_qname(buf,offset,length,
	                  default_element_prefix,
	                  default_element_uri);
	    
	bool matched = false;                   
	while (!node_stack.empty()) {
		elem_entry* entry_p = node_stack.top();
		dom_node* node_p = entry_p->en_p;
		
		cout << TRACE << " stack top: "; node_p->put(cout) << endl;
		
		if (matched) {
  	  the_context_node = node_p;
  	  display_context_node();
  	  break;
		}
		if (entry_p->qnamekey==qnkey) {
  		matched = true;
		}
  	node_stack.pop();
  	cout << TRACE << " stack pop\n";
		delete entry_p;
	}
	
}


// general identifier = tag callback
void dom_xml_handler::gi(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	if (length==0) return;
	
	// add accumulated text
	flush_textbuf_as_text_node();
		
	// add new element child
	qnamekey_t qnkey =
	  process_qname(buf,offset,length,
	                default_element_prefix,
	                default_element_uri);
	dom_qname* qn_p;
	if (!pool.get_qname(qnkey, qn_p)) {
		cout << TRACE << " : QName not found: " << string(buf,offset,length) << endl;
		return;
	}
	dom_element_node* elem_p;
	add_child(elem_p = new dom_element_node(qn_p, NULL));
	the_context_node = elem_p;
	display_context_node();
	elem_entry* entry_p  = new elem_entry(qnkey, elem_p);
	cout << TRACE << " : push stack: "; elem_p->put(cout) << endl;
	node_stack.push(entry_p);
}


// parsed content (tag body) callback
void dom_xml_handler::pcdata(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	if (length==0) return;
	textbuf << string(buf,offset,length);
}


// processing instruction callback
void dom_xml_handler::pi(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	string content(buf,offset,length);
	add_child(new dom_pi_node(the_PITarget,content));
	the_PITarget = "";
}


// processing instruction target callback
void dom_xml_handler::pitarget(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	the_PITarget = string(buf,offset,length);
}


// start tag close (attributes all processed) callback 
void dom_xml_handler::stagc(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	vector<attr_entry>::const_iterator it = attrv.begin();
	for (; it!=attrv.end(); ++it) {
  	attr_entry ae = *it;
		dom_qname* qn_p;
		if (!pool.get_qname(ae.qnamekey,qn_p)) {
			cout << TRACE << " : qnamekey not found: " << ae.qnamekey << endl;
			continue;
		}
		add_attribute(new dom_attribute_node(qn_p, ae.value));
	}
	attrv.clear();
}


// comment callback
void dom_xml_handler::cmnt(const char* buf, int offset, int length)
{
  //cout << TRACE << endl;
	string content(buf,offset,length);
	add_child(new dom_comment_node(content));
}


}	/* namespace xqp */
