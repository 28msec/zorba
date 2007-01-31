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
	:    parentid     (uint64_t)              :
	:    len          (uint32_t)              :
	:    content      (char[])                :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<text_node> tnode_h)
{
	nodeid parentid = tnode_h->get_parentid();
	char const* content = tnode_h->get_content();
	uint32_t content_length = tnode_h->get_content_length();
	off_t offset = put(ctx_p, parentid, content, content_length);
	index_p->put(tnode_h->get_nodeid().id, offset);
	return offset;
}

int nodestore::get(
	context * ctx_p,
	nodeid nid,     
	rchandle<text_node>& tnode_h)
{
	off_t offset;
	if (!index_p->get(nid.id, offset)) return ERR_NODEID_NOT_FOUND;
	nodeid parentid;
	char * content;
	uint32_t content_length;
	int k = get(ctx_p, offset, parentid, content, content_length);
	if (k<0) return k;
	tnode_h = new text_node(nid, parentid,
							string((char *)content,0,content_length));
	return k;
}

off_t nodestore::put(
	context * ctx_p,
	nodeid parent,
	char const* content,
	uint32_t len)
{
	uint32_t res = store_p->size();
	store_p->push_back(TEXT_CODE);
	put(ctx_p, (uint64_t)parent.id);
	put(ctx_p, (uint32_t)len);
	store_p->raw_copy(content, len);
	return res;
}

int nodestore::get(
	context * ctx_p,
	off_t offset0,
	nodeid & parent,
	char *& data,
	uint32_t & len)
{
	int k;
	uint64_t p;
	off_t offset = offset0;
	if (store_p->operator[](offset++)!=TEXT_CODE) return ERR_BAD_CODE;
	if ((k = get(ctx_p, offset, p)) < 0) return k; else offset += k;
	if ((k = get(ctx_p, offset, len)) < 0) return k; else offset += k;
	data = &store_p->operator[](offset);
	offset += len;
	parent.id = p;
	return (offset-offset0);
}

off_t nodestore::put(
	context * ctx_p,
	nodeid parent,
	string const& content)
{
	return put(ctx_p, parent, content.c_str(), content.length());
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
	uint32_t res = store_p->size();
	store_p->push_back(ATTR_CODE);
	put(ctx_p, (uint64_t)anode_h->get_nodeid().id);
	put(ctx_p, (uint64_t)anode_h->get_parentid().id);
	put(ctx_p, anode_h->get_name());
	put(ctx_p, anode_h->get_val());
	index_p->put(anode_h->get_nodeid().id, res);
	return res;
}

int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<attribute_node>& anode_h)
{
	int k = 0;
	off_t offset = offset0;
	if (store_p->operator[](offset++)!=ATTR_CODE) return ERR_BAD_CODE;
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
	off_t offset;
	if (!index_p->get(nid.id, offset)) return ERR_NODEID_NOT_FOUND;
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
	:    elem_count (= m)   (uint32_t)        :
	:    elem_1             (element)         :
	:    elem_2             (element)         :
	:    ...                 ...              :
	:    elem_m             (element)         :
	:                                         :
	:.........................................: */

off_t nodestore::put(
	context * ctx_p,
	rchandle<element_node> enode_h)
{
	uint32_t res = store_p->size();
	store_p->push_back(ELEM_CODE);

	cout << "PUT_000\n";

	put(ctx_p, (uint64_t)enode_h->get_nodeid().id);
	cout << "PUT_001\n";
	put(ctx_p, (uint64_t)enode_h->get_parentid().id);
	cout << "PUT_002\n";
	put(ctx_p, (uint64_t)enode_h->get_docid().id);
	cout << "PUT_003\n";
	put(ctx_p, enode_h->get_name());

	cout << "PUT_100\n";

	// put namespaces

	uint32_t attr_count = enode_h->attr_count();
	cout << "PUT_101 [attr_count = " << attr_count << "]\n";
	put(ctx_p, attr_count);
	rchandle<item_iterator> attr_it_h = enode_h->attributes(ctx_p);
	if (attr_it_h==NULL) {
		cout << "attr_it == NULL\n";
	}
	else if (attr_it_h->done()) {
		cout << "attr_it == done\n";
	}
	else {
		item_iterator& attr_it = *attr_it_h;
		for (; !attr_it.done(); ++attr_it) {
			cout << "@attr\n";
			rchandle<item> i_h = *attr_it;
			if (i_h==NULL) { cout << "i_h == NULL\n"; continue; }
			rchandle<attribute_node> n_h = dynamic_cast<attribute_node*>(&*i_h);
			put(ctx_p, n_h);
		}
	}

	cout << "PUT_200\n";

	uint32_t elem_count = enode_h->elem_count();
	cout << "PUT_201 [elem_count = " << elem_count << "]\n";
	put(ctx_p, elem_count);
	rchandle<item_iterator> elem_it_h = enode_h->children(ctx_p);
	if (elem_it_h==NULL) {
		cout << "elem_it == NULL\n";
	}
	if (elem_it_h->done()) {
		cout << "elem_it == done\n";
	}
	else {
		item_iterator& child_it = *elem_it_h;
		for (; !child_it.done(); ++child_it) {
			cout << "<child>\n";
			rchandle<item> i_h = *child_it;
			if (i_h==NULL) { cout << "i_h == NULL\n"; continue; }
			rchandle<element_node> n_h = dynamic_cast<element_node*>(&*i_h);
			put(ctx_p, n_h);
		}
	}

	cout << "PUT_300\n";

	index_p->put(enode_h->get_nodeid().id, res);
	return res;
}


int nodestore::get(
	context * ctx_p,
	off_t offset0,
	rchandle<element_node>& enode_h)
{
	int k = 0;
	off_t offset = offset0;
	if (store_p->operator[](offset++)!=ELEM_CODE) return ERR_BAD_CODE;

	cout << "GET_000\n";

	uint64_t id;
	if ((k = get(ctx_p, offset, id)) < 0) return k; else offset += k;
	uint64_t parentid;
	if ((k = get(ctx_p, offset, parentid)) < 0) return k; else offset += k;
	uint64_t docid;
	if ((k = get(ctx_p, offset, docid)) < 0) return k; else offset += k;
	rchandle<QName> name_h;
	if ((k = get(ctx_p, offset, name_h)) < 0) return k; else offset += k;

	cout << "GET_100\n";

	enode_h = new element_node(id, parentid, docid, name_h);

	cout << "GET_200\n";

	uint32_t attr_count;
	rchandle<attribute_node> anode_h;
	if ((k = get(ctx_p, offset, attr_count)) < 0) return k; else offset += k;

	cout << "GET_300 [count=" << attr_count << "]\n";

	for (uint32_t i=0; i<attr_count; ++i) {
		if ((k = get(ctx_p, offset,  anode_h)) < 0) return k; else offset += k;
		enode_h->add_node(&*anode_h);
	}

	cout << "GET_400\n";

	uint32_t elem_count;
	rchandle<element_node> enode0_h;
	if ((k = get(ctx_p, offset, elem_count)) < 0) return k; else offset += k;

	cout << "GET_500 [count=" << elem_count << "]\n";

	for (uint32_t i=0; i<elem_count; ++i) {
		if ((k = get(ctx_p, offset, enode0_h)) < 0) return k; else offset += k;
		enode_h->add_node(&*enode0_h);
	}
	return (offset-offset0);
}

int nodestore::get(
	context * ctx_p,
	nodeid nid,
	rchandle<element_node>& enode_h)
{
	off_t offset;
	if (!index_p->get(nid.id, offset)) return ERR_NODEID_NOT_FOUND;
	return get(ctx_p, offset, enode_h);
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
	if (!index_p->get(nid.id, offset)) return ERR_NODEID_NOT_FOUND;

	int k = 0;
	switch (store_p->operator[](offset)) {
	case TEXT_CODE: {
		rchandle<text_node> tnode_h;
		if ((k = get(ctx_p, nid, tnode_h)) < 0) return k;
		node_h = &*tnode_h;
		break;
	}
	case ATTR_CODE: {
		rchandle<attribute_node> anode_h;
		if ((k = get(ctx_p, nid, anode_h)) < 0) return k;
		node_h = &*anode_h;
		break;
	}
	case ELEM_CODE: {
		rchandle<element_node> enode_h;
		if ((k = get(ctx_p, nid, enode_h)) < 0) return k;
		node_h = &*enode_h;
		break;
	}
	default:;
	}
	return k;
}


} /* namespace xqp */








/*
off_t nodestore::put(
	context * ctx_p,
	doc_node const* dnode)
{
	off_t res = offset;
	store[offset++] = DOC_CODE;
	store[offset++] = URI_CODE;
	put(ctx_p, dnode->get_baseuri();
	store[offset++] = URI_CODE;
	put(ctx_p, dnode->get_docuri();
	put(ctx_p, *dnode->children(ctx);
	return res;
}

off_t nodestore::put(
	context * ctx_p,
	ns_node const* nsnode)
{
	off_t res = put(ctx_p, *nsnode->node_name(ctx));
	put_prefix(ctx_p, nsnode->get_prefix());
	put_uri(ctx_p, nsnode->get_uri());
	return res;
}

off_t nodestore::put(
	context * ctx_p,
	pi_node const* pnode)
{
	off_t res = put(ctx_p, *pnode->node_name(ctx));
	put_content(ctx_p, pnode->get_target());
	put_content(ctx_p, pnode->get_content());
	return res;
}

off_t nodestore::put(
	context * ctx_p,
	binary_node const* bnode)
{
	return 0;
}

*/

  

