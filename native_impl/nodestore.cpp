/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: nodestore.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "nodestore.h"

#include "../context/context.h"
#include "../runtime/iterator.h"
#include "../util/rchandle.h"
#include "../values/node_values.h"

#include <string>

#define TRACE "++"<<__FILE__<<':'<<__LINE__<<"::"<< __FUNCTION__

/*______________________________________________________________________
|  
|  32bit-aligned, depth-first, inline XML encoding.
|_______________________________________________________________________*/

using namespace std;
namespace xqp {

nodestore::nodestore(
	string const& datapath)
:
	store_p(new fxvector<char>(			datapath+"store")),
	index_p(new fxhash64map<off_t>(	datapath+"idx_")),
	nspool_h(new namespace_pool(		datapath+"nspool/"))
{
	qnpool_h = new qname_pool(datapath+"qnpool/", nspool_h);
}
 
nodestore::~nodestore()
{
}


string decode_nodekind(uint32_t code)
{
	switch (code) {
	 case STRING_CODE:	return "STRING";
	 case TEXT_CODE:		return "TEXT";
	 case QNAME_CODE:		return "QNAME";
	 case ATTR_CODE:		return "ATTR";
	 case ELEM_CODE:		return "ELEM";
	 case DOC_CODE:			return "DOC";
	 case COMMENT_CODE: return "COMMENT";
	 case PI_CODE:			return "PI";
	 case BINARY_CODE:	return "BINARY";
	 default: return "??";
	}
}


/*...........................................
	: integers                                :
	:.........................................: */

void nodestore::put(
	context * ctx_p,
	uint32_t key)
{

#ifdef DEBUG
cout << TRACE << ": put_32(" << key << ")\n";
#endif

	char e = key>>24 & 0xff;
	char f = key>>16 & 0xff;
	char g = key>>8  & 0xff;
	char h = key     & 0xff;
	store_p->push_back(e);
	store_p->push_back(f);
	store_p->push_back(g);
	store_p->push_back(h);
}

int nodestore::get(
	context * ctx_p,
	off_t offset0,
	uint32_t & v)
{
	off_t offset = offset0;
	uint32_t e = (uint32_t)store_p->operator[](offset++) << 24;
	uint32_t f = (uint32_t)store_p->operator[](offset++) << 16;
	uint32_t g = (uint32_t)store_p->operator[](offset++) << 8;
	uint32_t h = (uint32_t)store_p->operator[](offset++);
	v = e|f|g|h;
	return 4;
}

void nodestore::put(
	context * ctx_p,
	uint64_t key)
{

#ifdef DEBUG
cout << TRACE << ": put_64(" << key << ")\n";
#endif

	char a = key>>56 & 0xff;
	char b = key>>48 & 0xff;
	char c = key>>40 & 0xff;
	char d = key>>32 & 0xff;
	char e = key>>24 & 0xff;
	char f = key>>16 & 0xff;
	char g = key>>8  & 0xff;
	char h = key     & 0xff;
	store_p->push_back(a);
	store_p->push_back(b);
	store_p->push_back(c);
	store_p->push_back(d);
	store_p->push_back(e);
	store_p->push_back(f);
	store_p->push_back(g);
	store_p->push_back(h);
}

int nodestore::get(
	context * ctx_p,
	off_t offset0,
	uint64_t & v)
{
	off_t offset = offset0;
	uint64_t a = (uint64_t)store_p->operator[](offset++) << 56;
	uint64_t b = (uint64_t)store_p->operator[](offset++) << 48;
	uint64_t c = (uint64_t)store_p->operator[](offset++) << 40;
	uint64_t d = (uint64_t)store_p->operator[](offset++) << 32;
	uint64_t e = (uint64_t)store_p->operator[](offset++) << 24;
	uint64_t f = (uint64_t)store_p->operator[](offset++) << 16;
	uint64_t g = (uint64_t)store_p->operator[](offset++) << 8;
	uint64_t h = (uint64_t)store_p->operator[](offset++);
	v = a|b|c|d|e|f|g|h;
	return 8;
}



/*...........................................
	:  strings                                :
	:                                         :
	:    STRING_CODE  (uint32_t)              :
	:    len          (uint32_t)              :
	:    content      (char[])                :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	char const* content,
	uint32_t len)
{
	uint32_t res = store_p->size();

#ifdef DEBUG
cout << TRACE << ": put_char[](res=" << res << ")\n";
#endif

	put(ctx_p,STRING_CODE);
	put(ctx_p,(uint32_t)len);
	store_p->raw_copy(content, len);
	return res;
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	char *& data,
	uint32_t & len)
{
	int k;

#ifdef DEBUG
cout << TRACE << ": get_char[](offset=" << offset0 << ")\n";
#endif

	off_t offset = offset0;
	uint32_t code;
	if ((k = get(ctx_p, offset, code)) < 0) return k; else offset += k;
	if (code!=STRING_CODE) return ERR_BAD_CODE;
	if ((k = get(ctx_p, offset, len)) < 0) return k; else offset += k;
	data = &store_p->operator[](offset);
	offset += len;
	return (offset-offset0);
}


off_t nodestore::put(
	context * ctx_p,
	string const& content)
{

#ifdef DEBUG
cout << TRACE << ": put_str(" << content << ")\n";
#endif

	return put(ctx_p, content.c_str(), content.length());
}


int nodestore::get(
	context * ctx_p,
	off_t offset,
	string & content)
{
	int k = 0;

#ifdef DEBUG
cout << TRACE << ": get_string(offset=" << offset << ")\n";
#endif

	char * data;
	uint32_t len;
	if ((k = get(ctx_p, offset, data, len)) < 0) return k; 
	content = string(data, 0, len); 
	return k;
}



/*...........................................
	:  text nodes                             :
	:                                         :
	:    TEXT_CODE    (uint32_t)              :
	:    nodeid       (uint32_t)              :
	:    parentid     (uint32_t)              :
	:    content      (string)                :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<text_node> tnode_h)
{
	if (tnode_h==NULL) return 0;
	uint32_t res = store_p->size();

#ifdef DEBUG
cout << TRACE << ": put_text(res=" << res << ")\n";
#endif

	uint32_t id = tnode_h->get_nodeid().id;

	put(ctx_p, TEXT_CODE);
	put(ctx_p, id);
	put(ctx_p, tnode_h->get_parentid().id);
	put(ctx_p, tnode_h->get_content());

	index_p->put(id, res);
	return res;
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<text_node>& tnode_h)
{
	int k = 0;

#ifdef DEBUG
cout << TRACE << ": get_text(offset=" << offset0 << ")\n";
#endif

	off_t offset = offset0;

	uint32_t code;
	if ((k = get(ctx_p, offset, code)) < 0) return k; else offset += k;
	if (code!=TEXT_CODE) return ERR_BAD_CODE;
	uint32_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	uint32_t parentid;
	if ((k = get(ctx_p, offset, parentid)) < 0) return k; else offset += k;
	string content;
	if ((k = get(ctx_p, offset, content)) < 0) return k; else offset += k;

	tnode_h = new text_node(id, parentid, content);
	return (offset-offset0);
}


int nodestore::get(
	context * ctx_p,
	nodeid nid,
	rchandle<text_node>& tnode_h)
{

#ifdef DEBUG
cout << TRACE << ": get_text(id=" << nid.id << ")\n";
#endif

	off_t offset;
	if (!index_p->get(nid.id, offset)) {
		cout << TRACE << ": not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, tnode_h);
}



/*...........................................
	:  qname                                  :
	:                                         :
	:    QNAME_CODE      (uint32_t)           :
	:    qname_id        (uint32_t)           :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<QName> qname_h)
{
	off_t res = store_p->size();

#ifdef DEBUG
cout << TRACE << ": put_QName(res=" << res << ")\n";
#endif

	put(ctx_p,QNAME_CODE);
	uint32_t qname_id = qnpool_h->put(ctx_p->context_docid(),qname_h);
	put(ctx_p,qname_id);
	return res;
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<QName> & name_h)
{
	int k;

#ifdef DEBUG
cout << TRACE << ": get_QName(offset=" << offset0 << ")\n";
#endif

	uint32_t qname_id;
	off_t offset = offset0;

	uint32_t code;
	if ((k = get(ctx_p,offset,code)) < 0) return k; else offset += k;
	if (code!=QNAME_CODE) return ERR_BAD_CODE;
	if ((k = get(ctx_p,offset,qname_id)) < 0) return k; else offset += k;

	name_h = qnpool_h->get(qname_id); 
	return (offset-offset0);
}



/*...........................................
	:  attribute nodes                        :
	:                                         :
	:    ATTR_CODE      (uint32_t)            :
	:    nodeid         (uint32_t)            :
	:    parentid       (uint32_t)            :
	:    qname_id       (uint32_t)            :
	:    value          (string)              :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<attribute_node> anode_h)
{
	if (anode_h==NULL) return 0;
	uint32_t res = store_p->size();

#ifdef DEBUG
cout << TRACE << ": put_attr(res=" << res << ")\n";
#endif

	uint32_t id = anode_h->get_nodeid().id;
	uint32_t parentid = anode_h->get_parentid().id;

	put(ctx_p, ATTR_CODE);
	put(ctx_p, id);
	put(ctx_p, parentid);
	put(ctx_p, anode_h->get_name());
	put(ctx_p, anode_h->get_val());

	index_p->put(id, res);
	return res;
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<attribute_node>& anode_h)
{
	int k = 0;

#ifdef DEBUG
cout << TRACE << ": get_attr(offset=" << offset0 << ")\n";
#endif

	off_t offset = offset0;

	uint32_t code;
	if ((k = get(ctx_p, offset, code)) < 0) return k; else offset += k;
	if (code!=ATTR_CODE) return ERR_BAD_CODE;
	uint32_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	uint32_t parentid;
	if ((k = get(ctx_p, offset, parentid)) < 0) return k; else offset += k;
	rchandle<QName> name_h;
	if ((k = get(ctx_p, offset, name_h)) < 0) return k; else offset += k;
	string value;
	if ((k = get(ctx_p, offset, value)) < 0) return k; else offset += k;

	anode_h = new attribute_node(id, parentid, name_h, value);
	return (offset-offset0);
}


int nodestore::get(
	context * ctx_p,
	nodeid nid,
	rchandle<attribute_node>& anode_h)
{

#ifdef DEBUG
cout << TRACE << ": get_attr(id=" << nid.id << ")\n";
#endif

	off_t offset;
	if (!index_p->get(nid.id, offset)) {
		cout << TRACE << ": not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, anode_h);
}



/*...........................................
	:  element nodes                          :
	:                                         :
	:    ELEM_CODE          (uint32_t)        :
	:    docid              (uint32_t)        :
	:    nodeid             (uint32_t)        :
	:    parentid           (uint32_t)        :
	:    qname_id           (uint32_t)        :
	:    ns_id              (uint32_t)        :
	:    attr_1             (attribute_node)  :
	:    attr_2             (attribute_node)  :
	:    ...                 ...              :
	:    attr_n             (attribute_node)  :
	:    child_1            (node)            :
	:    child_2            (node)            :
	:    ...                 ...              :
	:    child_m            (node)            :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<element_node> enode_h)
{
	if (enode_h==NULL) return 0;
	uint32_t res = store_p->size();

#ifdef DEBUG
cout << TRACE << ": put_elem(res=" << res << ")\n";
#endif

	uint32_t docid = ctx_p->context_docid();
	uint32_t id = enode_h->get_nodeid().id;
	uint32_t parentid = enode_h->get_parentid().id;
	uint32_t nsid = ctx_p->get_in_scope_ns(enode_h);
	uint32_t qnameid = qnpool_h->put(docid,enode_h->get_name());

	put(ctx_p, ELEM_CODE);
	put(ctx_p, docid);
	put(ctx_p, id);
	put(ctx_p, parentid);
	put(ctx_p, qnameid);
	put(ctx_p, nsid);

	// put attributes
	rchandle<item_iterator> attr_it_h = enode_h->attributes(ctx_p);
	if (attr_it_h!=NULL) {
		for (; !attr_it_h->done(); ++(*attr_it_h)) {
			rchandle<item> i_h = **attr_it_h;
			if (i_h==NULL) { cout << TRACE << ": item == NULL\n"; continue; }
			rchandle<attribute_node> n_h = dynamic_cast<attribute_node*>(&*i_h);
			if (n_h==NULL) { cout << TRACE << ": attribute node == NULL\n"; continue; }
			cout << TRACE << ": "; n_h->put(cout,ctx_p) << endl;
			put(ctx_p, n_h);
		}
	}

	// put children
	rchandle<item_iterator> child_it_h = enode_h->children(ctx_p);
	if (child_it_h!=NULL) {
		for (; !child_it_h->done(); ++(*child_it_h)) {
			rchandle<item> i_h = **child_it_h;
			if (i_h==NULL) { cout << TRACE << ": item == NULL\n"; continue; }
			rchandle<node> n_h = dynamic_cast<node*>(&*i_h);
			if (n_h==NULL) { cout << TRACE << ": node == NULL\n"; continue; }

			switch (n_h->node_kind()) {
			case node::elem_kind: {
				cout << TRACE << ": PUT_elem\n";
				rchandle<element_node> en_h = dynamic_cast<element_node*>(&*n_h);
				put(ctx_p, en_h);
				break;
			}
			case node::text_kind: {
				cout << TRACE << ": PUT_text\n";
				rchandle<text_node> tn_h = dynamic_cast<text_node*>(&*n_h);
				put(ctx_p, tn_h);
				break;
			}
			case node::comment_kind: {
				// stub
				cout << TRACE << ": PUT_comment\n";
				break;
			}
			case node::pi_kind: {
				// stub
				cout << TRACE << ": PUT_pi\n";
				break;
			}
			case node::binary_kind: {
				// stub
				cout << TRACE << ": PUT_binary\n";
				break;
			}
			default: {
				cout << TRACE << ": Something seriously wrong here: illegal node_kind\n";
				continue; }
			}
		}
	}

	index_p->put(id, res);
	return res;
}


inline bool _valid_child(uint32_t code)
{
	if (code==ELEM_CODE) return true;
	if (code==TEXT_CODE) return true;
	if (code==COMMENT_CODE) return true;
	if (code==PI_CODE) return true;
	if (code==BINARY_CODE) return true;
	return false;
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<element_node>& enode_h)
{
	int k = 0;
	off_t offset = offset0;

#ifdef DEBUG
cout << TRACE << ": get_elem(offset=" << offset0 << ")\n";
#endif

	uint32_t code;
	if ((k = get(ctx_p, offset, code)) < 0) return k; else offset += k;
	if (code!=ELEM_CODE) return ERR_BAD_CODE;
	uint32_t docid;
	if ((k = get(ctx_p, offset, docid)) < 0) return k; else offset += k;
	uint32_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	uint32_t parentid;
	if ((k = get(ctx_p, offset, parentid)) < 0) return k; else offset += k;
	uint32_t qnameid;
	if ((k = get(ctx_p, offset, qnameid)) < 0) return k; else offset += k;
	rchandle<QName> qname_h = qnpool_h->get(qnameid);
	uint32_t nsid;
	if ((k = get(ctx_p, offset, nsid)) < 0) return k; else offset += k;

	enode_h = new element_node(id, parentid, docid, qname_h);

	// attributes
	rchandle<attribute_node> attr_node_h;
	for (;;) {
		if ((k = get(ctx_p, offset, code)) < 0) return k;
		if (code==ATTR_CODE) {
			if ((k = get(ctx_p, offset, attr_node_h)) < 0) return k; else offset += k;
			enode_h->add_node(&*attr_node_h);
		}
		else {
			cout << TRACE << ": terminate attributes on: "
						<< decode_nodekind(code) << endl;
			break;
		}
	}

	// children
	rchandle<node> node_h;
	for (;;) {
		if ((k = get(ctx_p, offset, code)) < 0) return k;
		if (_valid_child(code)) {
			if ((k = get(ctx_p, offset, node_h)) < 0) return k; else offset += k;
			enode_h->add_node(&*node_h);
		}
		else {
			cout << TRACE << ": terminate children on: "
						<< decode_nodekind(code) << endl;
			break;
		}
	}

	return (offset-offset0);
}


int nodestore::get(
	context * ctx_p,
	nodeid nid,
	rchandle<element_node>& enode_h)
{

#ifdef DEBUG
cout << TRACE << ": get_elem(id=" << nid.id << ")\n";
#endif

	off_t offset;
	if (!index_p->get(nid.id, offset)) {
		cout << TRACE << ": not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, enode_h);
}



/*...........................................
	:  document nodes                         :
	:                                         :
	:    DOC_CODE           (uint32_t)        :
	:    docid              (uint32_t)        :
	:    nodeid             (uint32_t)        :
	:    ns_id              (uint32_t)        :
	:    baseuri            (string)          :
	:    docuri             (string)          :
	:    child_1            (node)            :
	:    child_2            (node)            :
	:    ...                 ...              :
	:    child_m            (node)            :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<document_node> dnode_h)
{
	if (dnode_h==NULL) return 0;
	uint32_t res = store_p->size();

#ifdef DEBUG
cout << TRACE << ": put_doc(res=" << res << ")\n";
#endif

	uint32_t docid = ctx_p->context_docid();
	uint32_t id = dnode_h->get_nodeid().id;
	uint32_t nsid = ctx_p->get_in_scope_ns(dnode_h);

	put(ctx_p, DOC_CODE);
	put(ctx_p, docid);
	put(ctx_p, id);
	put(ctx_p, nsid);
	put(ctx_p, dnode_h->get_baseuri());
	put(ctx_p, dnode_h->get_docuri());

	// put children
	rchandle<item_iterator> child_it_h = dnode_h->children(ctx_p);
	if (child_it_h!=NULL) {
		for (; !child_it_h->done(); ++(*child_it_h)) {
			rchandle<item> i_h = **child_it_h;
			if (i_h==NULL) { cout << TRACE << ": item == NULL\n"; continue; }
			rchandle<node> n_h = dynamic_cast<node*>(&*i_h);
			if (n_h==NULL) { cout << TRACE << ": node == NULL\n"; continue; }

			switch (n_h->node_kind()) {
			case node::elem_kind: {
				cout << TRACE << ": PUT_elem\n";
				rchandle<element_node> en_h = dynamic_cast<element_node*>(&*n_h);
				put(ctx_p, en_h);
				break;
			}
			case node::text_kind: {
				cout << TRACE << ": PUT_text\n";
				rchandle<text_node> tn_h = dynamic_cast<text_node*>(&*n_h);
				put(ctx_p, tn_h);
				break;
			}
			case node::comment_kind: {
				// stub
				cout << TRACE << ": PUT_comment\n";
				break;
			}
			case node::pi_kind: {
				// stub
				cout << TRACE << ": PUT_pi\n";
				break;
			}
			case node::binary_kind: {
				// stub
				cout << TRACE << ": PUT_binary\n";
				break;
			}
			default: {
				cout << TRACE << ": Something seriously wrong here: illegal node_kind\n";
				continue; }
			}
		}
	}

	index_p->put(id, res);
	return res;
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<document_node>& dnode_h)
{
	int k = 0;
	off_t offset = offset0;

#ifdef DEBUG
cout << TRACE << ": get_doc(offset=" << offset0 << ")\n";
#endif

	uint32_t code;
	if ((k = get(ctx_p, offset, code)) < 0) return k; else offset += k;
	if (code!=DOC_CODE) return ERR_BAD_CODE;
	uint32_t docid;
	if ((k = get(ctx_p, offset, docid)) < 0) return k; else offset += k;
	uint32_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	uint32_t nsid;
	if ((k = get(ctx_p, offset, nsid)) < 0) return k; else offset += k;
	string baseuri;
	if ((k = get(ctx_p, offset, baseuri)) < 0) return k; else offset += k;
	string docuri;
	if ((k = get(ctx_p, offset, docuri)) < 0) return k; else offset += k;

	dnode_h = new document_node(id, docid, baseuri, docuri);

	// children
	rchandle<node> node_h;
	for (;;) {
		if ((k = get(ctx_p, offset, code)) < 0) return k;
		if (_valid_child(code)) {
			if ((k = get(ctx_p, offset, node_h)) < 0) return k; else offset += k;
			dnode_h->add_node(&*node_h);
		}
		else {
			break;
		}
	}
	return (offset-offset0);
}


int nodestore::get(
	context * ctx_p,
	nodeid nid,
	rchandle<document_node>& dnode_h)
{

#ifdef DEBUG
cout << TRACE << ": get_doc(id=" << nid.id << ")\n";
#endif

	off_t offset;
	if (!index_p->get(nid.id, offset)) {
		cout << TRACE << ": not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, dnode_h);
}



/*...........................................
	:  general nodes                          :
	:                                         :
	:.........................................:*/

int nodestore::get(
	context * ctx_p,
	nodeid nid,
	rchandle<node>& node_h)
{
	off_t offset;

#ifdef DEBUG
cout << TRACE << ": get_node(id=" << nid.id << ")\n";
#endif

	if (!index_p->get(nid.id, offset)) {
		cout << TRACE << ": nid [" << nid.id << "] not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, node_h);
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<node>& node_h)
{
	int k = 0;
	off_t offset = offset0;

#ifdef DEBUG
cout << TRACE << ": get_node(offset=" << offset0 << ")\n";
#endif

	uint32_t code;
	if ((k=get(ctx_p, offset, code)) < 0) return k;

	switch (code) {
	case TEXT_CODE: {
		cout << TRACE << " [TEXT]\n";
		rchandle<text_node> tnode_h;
		if ((k = get(ctx_p, offset, tnode_h)) < 0) return k;
		node_h = &*tnode_h;
		break;
	}
	case ATTR_CODE: {
		cout << TRACE << " [ATTR]\n";
		rchandle<attribute_node> anode_h;
		if ((k = get(ctx_p, offset, anode_h)) < 0) {
			cout << TRACE<<" [ATTR] error: "<<k<<"\n";
			return k;
		}
		node_h = &*anode_h;
		if (node_h==NULL) {
			cout << TRACE<<": node_h"<<(node_h==NULL?"==":"!=")<<"NULL\n";
		}
		break;
	}
	case ELEM_CODE: {
		cout << TRACE << " [ELEM]\n";
		rchandle<element_node> enode_h;
		if ((k = get(ctx_p, offset, enode_h)) < 0) return k;
		node_h = &*enode_h;
		break;
	}
	default: {
		cout << TRACE << ": code=" << store_p->operator[](offset) << endl;
	}
	}
	return k;
}


} /* namespace xqp */

