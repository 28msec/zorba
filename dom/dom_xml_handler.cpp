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
	string const&  _baseuri,
	string const&  _uri)
:
	scan_handler(),
	the_attribute_prefix(""),
	the_attribute_uri(""),
	the_attribute_name(""),
	the_element(""),
	the_PCDATA(""),
	the_PITarget(""),
	the_entity(0)
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
	const char* buf, int offset, int length)
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
		if(!find_nsuri(prefix,uri)) {
			cout << TRACE << " : unrecognized prefix: " << prefix << endl;
			return 0;
		}
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



// attribute without value callback
void dom_xml_handler::adup(const char* buf, int offset, int length)
{
	if (length==0) return;
	qnamekey_t qnkey = process_qname(buf,offset,length);
	attrv.push_back(attr_entry(qnkey,""));
}


// attribute name callback
void dom_xml_handler::aname(const char* buf, int offset, int length)
{
	if (length==0) return;
	qnamekey_t qnamekey = process_qname(buf,offset,length);
	attrv.push_back(attr_entry(qnamekey,""));
}


// attribute value callback
void dom_xml_handler::aval(const char* buf, int offset, int length)
{
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
		ns_entry* nse_p = new /*delete on etag*/
												ns_entry(qn_p->prefix(), value);
		nslist.push_back(nse_p);
		dom_namespace_node* ns_p = new dom_namespace_node(nse_p->prefix, nse_p->uri);
		the_context_node->get_nsv().push_back(ns_p);
		return;
	}
		
	ae.value = value;
}


// &ent; entity callback
void dom_xml_handler::entity(const char* buf, int offset, int length)
{
	string s(buf,offset,length);
	unsigned short code;
  entityMap.get(s, code);
	if (code==0) return;
	ent = (char)code;
}


// serialize concatenated text node
void dom_xml_handler::flush_textbuf_as_text_node()
{
	if (textbuf.str().length()>0) {
		dom_text_node* tn_p =
			new /* delete external */
				dom_text_node(textbuf.str());

		the_context_node->get_childv().push_back(tn_p);
		textbuf.str(""); // clear accumulator
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
	if (length==0) return;

	// add last concatenated text node
	flush_textbuf_as_text_node();

	// find matching tag
	qnamekey_t qnkey = process_qname(buf,offset,length);
	stack<elem_entry*> recover_stack;
	while (!node_stack.empty()) {
		elem_entry* e_p = node_stack.top();
		node_stack.pop();
		if (e_p->qnamekey==qnkey) {
			the_context_node = e_p->en_p;
			delete e_p;
			break;
		}
		else {
			recover_stack.push(e_p);
		}
	}

	while (!recover_stack.empty()) {
		elem_entry* e_p = recover_stack.top();
		recover_stack.pop();
		node_stack.push(e_p);
	}
}


// general identifier = tag callback
void dom_xml_handler::gi(const char* buf, int offset, int length)
{
	if (length==0) return;
	qnamekey_t qnkey = process_qname(buf,offset,length);
	dom_qname* qn_p;
	if (!pool.get_qname(qnkey, qn_p)) {
		cout << TRACE << " : QName not found: " << string(buf,offset,length) << endl;
		return;
	}
	the_context_node = new dom_element_node(qn_p, NULL);
	elem_entry* e_p  = new /* delete when popped */
												elem_entry(qnkey, the_context_node);
	node_stack.push(e_p);
	flush_textbuf_as_text_node();
}


// parsed content (tag body) callback
void dom_xml_handler::pcdata(const char* buf, int offset, int length)
{
	if (length==0) return;
	textbuf << string(buf,offset,length);
}


// processing instruction callback
void dom_xml_handler::pi(const char* buf, int offset, int length)
{
	string content(buf,offset,length);
	dom_pi_node* pn_p = new dom_pi_node(the_PITarget,content);
	the_context_node->get_childv().push_back(pn_p);
	the_PITarget = "";
}


// processing instruction target callback
void dom_xml_handler::pitarget(const char* buf, int offset, int length)
{
	the_PITarget = string(buf,offset,length);
}


// start tag close (attributes all processed) callback 
void dom_xml_handler::stagc(const char* buf, int offset, int length)
{
	vector<attr_entry>::const_iterator it = attrv.begin();
	for (; it!=attrv.end(); ++it) {
  	attr_entry ae = *it;
		dom_qname* qn_p;
		if (!pool.get_qname(ae.qnamekey,qn_p)) {
			cout << TRACE << " : qnamekey not found: " << ae.qnamekey << endl;
			continue;
		}
		dom_attribute_node* an_p = new dom_attribute_node(qn_p, ae.value);
		the_context_node->get_attrv().push_back(an_p);
	}
	attrv.clear();
}


// comment callback
void dom_xml_handler::cmnt(const char* buf, int offset, int length)
{
	string content(buf,offset,length);
	dom_comment_node* cn_p = new dom_comment_node(content);
	the_context_node->get_childv().push_back(cn_p);
}


}	/* namespace xqp */
