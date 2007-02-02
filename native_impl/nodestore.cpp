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

#define SOURCE __FILE__ << ':' << __LINE__ << "::" << __FUNCTION__ << ": "

/*______________________________________________________________________
|  
|  Byte-aligned, depth-first, inline XML encoding.
|  
|_______________________________________________________________________*/

using namespace std;
namespace xqp {

nodestore::nodestore(
	string const& path)
:
	store_p(new fxvector<char>(path+"/store")),
	index_p(new fxhash64map<off_t>(path+"/idx_"))
{
}
 
nodestore::~nodestore()
{
}


/*
off_t nodestore::put(
	context * ctx_p,
	item_iterator & it)
{
	off_t res = *store_p->offset_p;
	for (; !it.done(); ++it) {
		rchandle<item> i_h = *it;
		node* n_p = dynamic_cast<node*>(&*i_h);
		if (n_p==NULL) continue;	//log error
		put(ctx_p, n_p);
	}
	return res;
}
*/


/*...........................................
	: integers                                :
	:.........................................: */

void nodestore::put(
	context * ctx_p,
	uint16_t key)
{
	char g = key>>8 & 0xff;
	char h = key    & 0xff;
	store_p->push_back(g);
	store_p->push_back(h);
}

int nodestore::get(
	context * ctx_p,
	off_t offset0,
	uint16_t & v)
{
	off_t offset = offset0;
	uint16_t g = (uint16_t)store_p->operator[](offset++) << 8;
	uint16_t h = (uint16_t)store_p->operator[](offset++);
	v = g|h;
	return 2;
}

void nodestore::put(
	context * ctx_p,
	uint32_t key)
{
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
	:    STRING_CODE  (char)                  :
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
	store_p->push_back(STRING_CODE);
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
	off_t offset = offset0;
	if (store_p->operator[](offset++)!=STRING_CODE) return ERR_BAD_CODE;
	if ((k = get(ctx_p, offset, len)) < 0) return k; else offset += k;
	data = &store_p->operator[](offset);
	offset += len;
	return (offset-offset0);
}


off_t nodestore::put(
	context * ctx_p,
	string const& content)
{
	return put(ctx_p, content.c_str(), content.length());
}


int nodestore::get(
	context * ctx_p,
	off_t offset,
	string & content)
{
	char * data;
	uint32_t len;
	int k = get(ctx_p, offset, data, len);
	if (k<0) return k;
	content = string(data, 0, len); 
	return k;
}



/*...........................................
	:  text nodes                             :
	:                                         :
	:    TEXT_CODE    (char)                  :
	:    nodeid       (uint64_t)              :
	:    parentid     (uint64_t)              :
	:    content      (string)                :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<text_node> tnode_h)
{
	if (tnode_h==NULL) return 0;
	uint32_t res = store_p->size();
	uint64_t id = tnode_h->get_nodeid().id;

	// inline
	store_p->push_back(TEXT_CODE);
	put(ctx_p, id);
	put(ctx_p, (uint64_t)tnode_h->get_parentid().id);
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
	off_t offset = offset0;
	char code = (*store_p)[offset++];

	// inline
	if (code!=TEXT_CODE) return ERR_BAD_CODE;
	uint64_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	uint64_t parentid;
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
	cout << SOURCE << "get(" << nid.id << ")\n";
	off_t offset;
	if (!index_p->get(nid.id, offset)) {
		cout << SOURCE << "not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, tnode_h);
}



/*...........................................
	:  qname                                  :
	:                                         :
	:    QNAME_CODE      (char)               :
	:    type            (char)               :
	:    namespace hash  (uint64_t)           :
	:    local name      (string)             :
	:    prefix          (string)             :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<QName> name_h)
{
	int k;
	off_t res = store_p->size();
	store_p->push_back(QNAME_CODE);
	store_p->push_back(name_h->get_type());
	put(ctx_p, name_h->get_namespace_hash());
	if ((k = put(ctx_p, name_h->get_name())) < 0) return k;
	if ((k = put(ctx_p, name_h->get_prefix())) < 0) return k;
	return res;
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<QName> & name_h)
{
	int k;
	uint64_t key;
	nodeid parent;

	off_t offset = offset0;
	if (store_p->operator[](offset++)!=QNAME_CODE) return ERR_BAD_CODE;

	QName::qname_type_t type = (QName::qname_type_t)store_p->operator[](offset++);
	if ((k = get(ctx_p, offset, key)) < 0) return k; else offset += k;

	char * name;
	uint32_t name_len;
	if ((k = get(ctx_p, offset, name, name_len)) < 0)
		return k;
	else
		offset += k;

	char * prefix;
	uint32_t prefix_len;
	if ((k = get(ctx_p, offset, prefix, prefix_len)) < 0)
		return k;
	else
		offset += k;

	name_h = new QName(type,
										 string((char *)prefix,0,prefix_len),
										 string((char *)name,0,name_len), key);
	return (offset-offset0);
}


/*...........................................
	:  attribute nodes                        :
	:                                         :
	:    ATTR_CODE      (char)                :
	:    nodeid         (uint64_t)            :
	:    parentid       (uint64_t)            :
	:    name           (QName)               :
	:    value          (string)              :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<attribute_node> anode_h)
{
	if (anode_h==NULL) return 0;
	uint32_t res = store_p->size();
	uint64_t id = anode_h->get_nodeid().id;

	// inline
	store_p->push_back(ATTR_CODE);
	put(ctx_p, id);
	put(ctx_p, (uint64_t)anode_h->get_parentid().id);
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
	off_t offset = offset0;
	char code = (*store_p)[offset++];

	// inline
	if (code!=ATTR_CODE) return ERR_BAD_CODE;
	uint64_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	uint64_t parentid;
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
	cout << SOURCE << "get(" << nid.id << ")\n";
	off_t offset;
	if (!index_p->get(nid.id, offset)) {
		cout << SOURCE << "not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, anode_h);
}



/*...........................................
	:  element nodes                          :
	:                                         :
	:    ELEM_CODE          (char)            :
	:    nodeid             (uint64_t)        :
	:    parentid           (uint64_t)        :
	:    docid              (uint64_t)        :
	:    name               (QName)           :
	:    attr_count (= n)   (uint32_t)        :
	:    attr_1             (attribute)       :
	:    attr_2             (attribute)       :
	:    ...                 ...              :
	:    attr_n             (attribute)       :
	:    child_count(= m)   (uint32_t)        :
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
	uint64_t id = enode_h->get_nodeid().id;

	// handle
	store_p->push_back(ELEM_CODE);
	put(ctx_p, id);
	put(ctx_p, (uint64_t)enode_h->get_parentid().id);
	put(ctx_p, (uint64_t)enode_h->get_docid().id);
	put(ctx_p, enode_h->get_name());

	// put namespaces

	// put attributes
	uint32_t attr_count = enode_h->attr_count();
	put(ctx_p, attr_count);
	rchandle<item_iterator> attr_it_h = enode_h->attributes(ctx_p);
	if (attr_it_h!=NULL) {
		for (; !attr_it_h->done(); ++(*attr_it_h)) {
			rchandle<item> i_h = **attr_it_h;
			if (i_h==NULL) { cout << SOURCE << "item == NULL\n"; continue; }
			rchandle<attribute_node> n_h = dynamic_cast<attribute_node*>(&*i_h);
			if (n_h==NULL) { cout << SOURCE << "attribute node == NULL\n"; continue; }
			n_h->put(cout,ctx_p) << endl;
			put(ctx_p, n_h);
		}
	}

	// put children
	uint32_t child_count = enode_h->child_count();
	put(ctx_p, child_count);

	rchandle<item_iterator> child_it_h = enode_h->children(ctx_p);
	if (child_it_h!=NULL) {
		for (; !child_it_h->done(); ++(*child_it_h)) {
			rchandle<item> i_h = **child_it_h;
			if (i_h==NULL) { cout << SOURCE << "item == NULL\n"; continue; }
			rchandle<node> n_h = dynamic_cast<node*>(&*i_h);
			if (n_h==NULL) { cout << SOURCE << "node == NULL\n"; continue; }

			switch (n_h->node_kind()) {
			case node::elem_kind: {
				cout << SOURCE << "PUT_elem\n";
				rchandle<element_node> en_h = dynamic_cast<element_node*>(&*n_h);
				put(ctx_p, en_h);
				break;
			}
			case node::text_kind: {
				cout << SOURCE << "PUT_text\n";
				rchandle<text_node> tn_h = dynamic_cast<text_node*>(&*n_h);
				put(ctx_p, tn_h);
				break;
			}
			case node::comment_kind: {
				// stub
				cout << SOURCE << "PUT_comment\n";
				break;
			}
			case node::pi_kind: {
				// stub
				cout << SOURCE << "PUT_pi\n";
				break;
			}
			case node::binary_kind: {
				// stub
				cout << SOURCE << "PUT_binary\n";
				break;
			}
			default: {
				cout << SOURCE << "Something seriously wrong here: illegal node_kind\n";
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
	rchandle<element_node>& enode_h)
{
	int k = 0;
	off_t offset = offset0;
	char code = (*store_p)[offset++];

	// inline
	if (code!=ELEM_CODE) return ERR_BAD_CODE;
	uint64_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	uint64_t parentid;
	if ((k = get(ctx_p, offset, parentid)) < 0) return k; else offset += k;
	uint64_t docid;
	if ((k = get(ctx_p, offset, docid)) < 0) return k; else offset += k;
	rchandle<QName> name_h;
	if ((k = get(ctx_p, offset, name_h)) < 0) return k; else offset += k;

	enode_h = new element_node(id, parentid, docid, name_h);

	uint32_t attr_count;
	rchandle<attribute_node> anode_h;
	if ((k = get(ctx_p, offset, attr_count)) < 0) return k; else offset += k;

	for (uint32_t i=0; i<attr_count; ++i) {
		if ((k = get(ctx_p, offset,  anode_h)) < 0) return k; else offset += k;
		enode_h->add_node(&*anode_h);
	}

	uint32_t child_count;
	if ((k = get(ctx_p, offset, child_count)) < 0) return k; else offset += k;

	rchandle<node> node_h;
	for (uint32_t i=0; i<child_count; ++i) {
		if ((k = get(ctx_p, offset, node_h)) < 0) return k; else offset += k;
		enode_h->add_node(&*node_h);
	}

	return (offset-offset0);
}


int nodestore::get(
	context * ctx_p,
	nodeid nid,
	rchandle<element_node>& enode_h)
{
	cout << SOURCE << "get(" << nid.id << ")\n";
	off_t offset;
	if (!index_p->get(nid.id, offset)) {
		cout << SOURCE << "not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, enode_h);
}



/*...........................................
	:  document nodes                         :
	:                                         :
	:    DOC_CODE           (char)            :
	:    nodeid             (uint64_t)        :
	:    baseuri            (string)          :
	:    docuri             (string)          :
	:    child_count(= m)   (uint32_t)        :
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
	uint64_t id = dnode_h->get_nodeid().id;

	// inline
	store_p->push_back(DOC_CODE);
	put(ctx_p, id);
	put(ctx_p, dnode_h->get_baseuri());
	put(ctx_p, dnode_h->get_docuri());

	// put namespaces

	// put children
	uint32_t child_count = dnode_h->child_count();
	put(ctx_p, child_count);

	rchandle<item_iterator> child_it_h = dnode_h->children(ctx_p);
	if (child_it_h!=NULL) {
		for (; !child_it_h->done(); ++(*child_it_h)) {
			rchandle<item> i_h = **child_it_h;
			if (i_h==NULL) { cout << SOURCE << "item == NULL\n"; continue; }
			rchandle<node> n_h = dynamic_cast<node*>(&*i_h);
			if (n_h==NULL) { cout << SOURCE << "node == NULL\n"; continue; }

			switch (n_h->node_kind()) {
			case node::elem_kind: {
				cout << SOURCE << "PUT_elem\n";
				rchandle<element_node> en_h = dynamic_cast<element_node*>(&*n_h);
				put(ctx_p, en_h);
				break;
			}
			case node::text_kind: {
				cout << SOURCE << "PUT_text\n";
				rchandle<text_node> tn_h = dynamic_cast<text_node*>(&*n_h);
				put(ctx_p, tn_h);
				break;
			}
			case node::comment_kind: {
				// stub
				cout << SOURCE << "PUT_comment\n";
				break;
			}
			case node::pi_kind: {
				// stub
				cout << SOURCE << "PUT_pi\n";
				break;
			}
			case node::binary_kind: {
				// stub
				cout << SOURCE << "PUT_binary\n";
				break;
			}
			default: {
				cout << SOURCE << "Something seriously wrong here: illegal node_kind\n";
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
	char code = (*store_p)[offset++];

	// inline
	if (code!=DOC_CODE) return ERR_BAD_CODE;
	uint64_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	string baseuri;
	if ((k = get(ctx_p, offset, baseuri)) < 0) return k; else offset += k;
	string docuri;
	if ((k = get(ctx_p, offset, docuri)) < 0) return k; else offset += k;

	dnode_h = new document_node(id, baseuri, docuri);

	uint32_t child_count;
	if ((k = get(ctx_p, offset, child_count)) < 0) return k; else offset += k;

	rchandle<node> node_h;
	for (uint32_t i=0; i<child_count; ++i) {
		if ((k = get(ctx_p, offset, node_h)) < 0) return k; else offset += k;
		dnode_h->add_node(&*node_h);
	}
	return (offset-offset0);
}


int nodestore::get(
	context * ctx_p,
	nodeid nid,
	rchandle<document_node>& dnode_h)
{
	cout << SOURCE << "get(" << nid.id << ")\n";
	off_t offset;
	if (!index_p->get(nid.id, offset)) {
		cout << SOURCE << "not found\n";
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
	if (!index_p->get(nid.id, offset)) {
		cout << SOURCE << "nid [" << nid.id << "] not found\n";
		return ERR_NODEID_NOT_FOUND;
	}
	return get(ctx_p, offset, node_h);
}


int nodestore::get(
	context * ctx_p,
	off_t offset,
	rchandle<node>& node_h)
{
	int k = 0;
	switch (store_p->operator[](offset)) {
	case TEXT_CODE: {
		rchandle<text_node> tnode_h;
		if ((k = get(ctx_p, offset, tnode_h)) < 0) return k;
		node_h = &*tnode_h;
		break;
	}
	case ATTR_CODE: {
		rchandle<attribute_node> anode_h;
		if ((k = get(ctx_p, offset, anode_h)) < 0) return k;
		node_h = &*anode_h;
		break;
	}
	case ELEM_CODE: {
		rchandle<element_node> enode_h;
		if ((k = get(ctx_p, offset, enode_h)) < 0) return k;
		node_h = &*enode_h;
		break;
	}
	default: {
		cout << SOURCE << " : code=" << store_p->operator[](offset) << endl;
	}
	}
	return k;
}


} /* namespace xqp */

