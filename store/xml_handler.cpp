/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_handler.cpp,v 1.1.1.1 2006/10/09 06:58:38 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *	Author: John Cowan, Paul Pedersen
 *
 */


#include <iostream>
#include <string>

#include "../context/context.h"
#include "../values/values.h"
#include "../util/xqp_exception.h"
#include "../util/tokenbuf.h"
#include "../util/URI.h"
#include "xml_handler.h"

using namespace std;
namespace xqp {

#define TRACE __FILE__<<':'<<__LINE__<<"::"<<__FUNCTION__
#define DELIMSET " \n,.;:?!\r\t+-_!@#$%&*()[]{}=/|\\<>'\""
#define NAME  first
#define VALUE second


xml_handler::xml_handler(
	context * _ctx_p,
	string const&  _baseuri,
	string const&  _uri,
	vector<xml_term>& _term_v)
:
	scan_handler(),
	top(0),
	qtop(0),
	ntop(0),
	the_attribute(""),
	the_element(""),
	the_PCDATA(""),
	the_PITarget(""),
	the_entity(0),
	term_pos(0),
	last_pos(0),
	uri(URI(_uri).hashkey()),
	term_v(_term_v),
	ctx_p(_ctx_p)
{
	istore_h = ctx_p->istore();
	itemstore& istore = *istore_h;

	itemref_t baseuri_ref = istore.eos();
	new(istore) xs_stringValue(istore,_baseuri);

	itemref_t uri_ref = istore.eos();
	new(istore) xs_stringValue(istore,_uri);

	ctx_p->docref() = istore.eos();
	new(istore) document_node(ctx_p,baseuri_ref,uri_ref);
}


void xml_handler::error(string const& msg) const
throw (xqp_exception)
{
	throw xqp_exception("XML_HANDLER", msg);
}


inline void xml_handler::add_term(xml_term const& term)
{
	term_v.push_back(term);
}


// attribute without value callback
void xml_handler::adup(const char* buf, int offset, int length)
{
	if (length==0) return;
	the_attribute = string(buf,offset,length);
	string prefix("");
	string name("");
	string::size_type loc = the_attribute.find(':', 0);
	if (loc!=string::npos) {
		prefix = the_attribute.substr(0,loc);
		name = the_attribute.substr(loc+1);
	}
	else {
		name = the_attribute;
	}

	// store for load on start tag close
	//rchandle<QName> qname_h = new QName(the_attribute);
	uint32_t qname_id = 0; // qnpool_h->put(the_docid,qname_h);
	attr_v.push_back(attrpair_t(qname_id,""));
}


// attribute name callback
void xml_handler::aname(const char* buf, int offset, int length)
{
	if (length==0) return;
	the_attribute = string(buf,offset,length);
}


// attribute value callback
void xml_handler::aval(const char* buf, int offset, int length)
{
#ifdef DEBUG
	cout << "@" << the_attribute << "=" << string(buf,offset,length) << endl;
#endif
	if (length==0) return;
	const char* p = &buf[offset];

	tokenbuf tokbuf(p,0,length,DELIMSET);
	tokbuf.set_lowercase();
	tokenbuf::token_iterator it = tokbuf.begin();
	tokenbuf::token_iterator end = tokbuf.end();

	// index terms
	for (; it!=end; ++it) {
		const string& term = *it;
		if (term.length()==0) continue;
		string attr_term = '@'+the_attribute+"/word::"+term;
		add_term(xml_term(attr_term,uri,term_pos++));
		string elem_attr_term = the_element+"/@"+the_attribute+"/word::"+term;
		add_term(xml_term(elem_attr_term,uri,term_pos++));
	}
	
	// store 
	itemstore& istore = *ctx_p->istore();
	itemref_t ref = istore.eos();
	new (istore) qname_value(ctx_p,the_attribute);
	attr_v.push_back(attrpair_t(ref,string(buf,offset,length)));

}


// &ent; entity callback
void xml_handler::entity(const char* buf, int offset, int length)
{
#ifdef DEBUG
cout << '&' << string(buf,offset,length) << ';' << endl;
#endif
	string s(buf,offset,length);
	unsigned short code;
  entityMap.get(s, code);
	if (code==0) return;
	ent = (char)code;
}


// serialize concatenated text node
void xml_handler::flush_textbuf_as_text_node()
{
	if (textbuf.str().length()>0) {
		new (*istore_h) text_node(ctx_p, textbuf.str());
		textbuf.str("");
	}
}


// eof callback
void xml_handler::eof(const char* buf, int offset, int length)
{
#ifdef DEBUG
cout << "===== eof =====" << endl;
#endif

	// serialize concatenated text node
	flush_textbuf_as_text_node();
}


// end tag callback
void xml_handler::etag(const char* buf, int offset, int length)
{
	if (length==0) return;
	string etag0(buf,offset,length);

	// serialize concatenated text node
	flush_textbuf_as_text_node();
	
	// clear stack to matching tag
	uint32_t etag0_id;
	int k = top;
	while (k>0) {
		uint32_t tag_id = the_id_stack[--k];
		if (tag_id==etag0_id) break;
	}
	if (k==0) return;
	top = k;
}


// general identifier = tag callback
void xml_handler::gi(const char* buf, int offset, int length)
{
	if (length==0) return;
	itemstore& istore = *istore_h;
	itemref_t qname_ref = istore.eos();
	new(istore) qname_value(ctx_p,string(buf,0,length));
	the_element = istore.eos();
	new(istore) element_node(ctx_p,qname_ref);

	// serialize concatenated text node
	flush_textbuf_as_text_node();
}


// add an index term
void xml_handler::add_term(
	string const& term,
	uint64_t uri,
	uint32_t pos)
{
	string e;			// element node
	string p;			// parent node
	string gp;		// grandparent node
	string ggp;		// great-grandparent

	if (term_indexing) {
		add_term(xml_term(term, uri, pos));
	}
	if (top>=1) {
		e = the_name_stack[top-1];
		e += "/word::"+term;
		if (e_indexing) add_term(xml_term(e, uri, pos));
	}
	if (top>=2) {
		p = the_name_stack[top-2];
		p += "/child::"+e;
		if (p_indexing) add_term(xml_term(p, uri, pos));
	}
	if (top>=3) {
		string gp = the_name_stack[top-3];
		gp += "/child::"+p;
		if (gp_indexing) add_term(xml_term(gp, uri, pos));
	}
	if (top>=4) {
		ggp = the_name_stack[top-4];
		ggp += "/child::"+gp;
		if (ggp_indexing) add_term(xml_term(ggp, uri, pos));
	}
}


// parsed content (tag body) callback
void xml_handler::pcdata(const char* buf, int offset, int length)
{
#ifdef DEBUG2
	cout << "pcata = |"<<string(buf,offset,length)<<"| ["<<length<<"]\n";
#endif

	if (length==0) return;

	// tokenize for search indexing
	tokenbuf tokbuf(buf,offset,length,DELIMSET);
	tokbuf.set_lowercase(true);
	string last("");

	tokenbuf::token_iterator it = tokbuf.begin();
	for (;it!=tokbuf.end(); ++it) {
		string const& term = *it;
#ifdef DEBUG2
		cout << "pcdata::term = "<<term<< endl<<"it.get_token_pos() = "<<it.get_token_pos()<<endl;
#endif
		if (term.length()==0) continue;
		add_term(term, uri, term_pos);
		if (bigram_indexing && last_pos>0) {
			string bigram = last+"#"+term;
			add_term(bigram, uri, last_pos);
		}
		last_pos = term_pos;
		last = term;
		++term_pos;
	}

	// concat text
	textbuf << string(buf,offset,length);
}


// processing instruction callback
void xml_handler::pi(const char* buf, int offset, int length)
{
#ifdef DEBUG
	string s(buf,offset,length);
	cout << "<?" << s << endl;
#endif
}


// processing instruction target callback
void xml_handler::pitarget(const char* buf, int offset, int length)
{
#ifdef DEBUG
	string s(buf,offset,length);
	cout << " " << s << ">" << endl;
#endif
}


// start tag close (attributes all processed) callback 
void xml_handler::stagc(const char* buf, int offset, int length)
{
#ifdef DEBUG
	cout << ">" << endl;
#endif

	// serialize: element QName
	new(*istore_h) element_node(ctx_p,buf,length);

	// serialize attribute list
	vector<attrpair_t>::const_iterator it = attr_v.begin();
	for (; it!=attr_v.end(); ++it) {
  	attrpair_t p = *it;
		//cout << "put(ATTR_CODE)\n";
		itemref_t qname_ref = p.first;
		string val = p.second;
		new (*istore_h) attribute_node(ctx_p,qname_ref,val);
	}
	attr_v.clear();
}


// comment callback
void xml_handler::cmnt(const char* buf, int offset, int length)
{
#ifdef DEBUG
	string s(buf,offset,length);
	cout << "<!--" << s << "-->" << endl;
#endif
}


}	/* namespace xqp */
