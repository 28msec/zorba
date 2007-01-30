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

using namespace std;
namespace xqp {

nodestore::nodestore(
	string const& path)
:
	store(path+"/store"),
	index(path+"/idx_")
{
}
 
nodestore::~nodestore()
{
}

/*...........................................
	: node store                              :
	:.........................................:
*/

/*
off_t nodestore::put(
	context & ctx,
	item_iterator & it)
{
	off_t res = *store.offset_p;
	for (; !it.done(); ++it) {
		rchandle<item> i_h = *it;
		node* n_p = dynamic_cast<node*>(&*i_h);
		if (n_p==NULL) continue;	//log error
		put(ctx, n_p);
	}
	return res;
}
*/


/*...........................................
	: integers                                :
	:.........................................:
*/

void nodestore::put(
	context & ctx,
	uint16_t key)
{
	unsigned char g = key>>8 & 0xff;
	unsigned char h = key    & 0xff;
	store.push_back(g);
	store.push_back(h);
}

int nodestore::get(
	context & ctx,
	off_t offset0,
	uint16_t & v)
{
	off_t offset = offset0;
	uint16_t g = (uint16_t)store[offset++] << 8;
	uint16_t h = (uint16_t)store[offset++];
	v = g|h;
	return 2;
}

void nodestore::put(
	context & ctx,
	uint32_t key)
{
	unsigned char e = key>>24 & 0xff;
	unsigned char f = key>>16 & 0xff;
	unsigned char g = key>>8  & 0xff;
	unsigned char h = key     & 0xff;
	store.push_back(e);
	store.push_back(f);
	store.push_back(g);
	store.push_back(h);
}

int nodestore::get(
	context & ctx,
	off_t offset0,
	uint32_t & v)
{
	off_t offset = offset0;
	uint32_t e = (uint32_t)store[offset++] << 24;
	uint32_t f = (uint32_t)store[offset++] << 16;
	uint32_t g = (uint32_t)store[offset++] << 8;
	uint32_t h = (uint32_t)store[offset++];
	v = e|f|g|h;
	return 4;
}

void nodestore::put(
	context & ctx,
	uint64_t key)
{
	unsigned char a = key>>56 & 0xff;
	unsigned char b = key>>48 & 0xff;
	unsigned char c = key>>40 & 0xff;
	unsigned char d = key>>32 & 0xff;
	unsigned char e = key>>24 & 0xff;
	unsigned char f = key>>16 & 0xff;
	unsigned char g = key>>8  & 0xff;
	unsigned char h = key     & 0xff;
	store.push_back(a);
	store.push_back(b);
	store.push_back(c);
	store.push_back(d);
	store.push_back(e);
	store.push_back(f);
	store.push_back(g);
	store.push_back(h);
}

int nodestore::get(
	context & ctx,
	off_t offset0,
	uint64_t & v)
{
	off_t offset = offset0;
	uint64_t a = (uint64_t)store[offset++] << 56;
	uint64_t b = (uint64_t)store[offset++] << 48;
	uint64_t c = (uint64_t)store[offset++] << 40;
	uint64_t d = (uint64_t)store[offset++] << 32;
	uint64_t e = (uint64_t)store[offset++] << 24;
	uint64_t f = (uint64_t)store[offset++] << 16;
	uint64_t g = (uint64_t)store[offset++] << 8;
	uint64_t h = (uint64_t)store[offset++];
	v = a|b|c|d|e|f|g|h;
	return 8;
}


/*...........................................
	: text content                            :
	:.........................................:
*/

off_t nodestore::put(
	context & ctx,
	char const* content,
	uint32_t len)
{
	uint32_t res = store.size();
	store.push_back((unsigned char)STRING_CODE);
	put(ctx,(uint32_t)len);
	store.raw_copy(content, len);
	return res;
}

int nodestore::get(
	context & ctx,
	off_t offset0,
	char *& data,
	uint32_t & len)
{
	int k;
	off_t offset = offset0;
	if (store[offset++]!=STRING_CODE) return ERR_BAD_CODE;
	if ((k = get(ctx, offset, len)) < 0) return k; else offset += k;
	data = store.front() + offset;
	offset += len;
	return (offset-offset0);
}

off_t nodestore::put(
	context & ctx,
	string const& content)
{
	return put(ctx, content.c_str(), content.length());
}

int nodestore::get(
	context & ctx,
	off_t offset,
	string & content)
{
	char * data;
	uint32_t len;
	int k = get(ctx, offset, data, len);
	if (k<0) return k;
	content = string(data, 0, len); 
	return k;
}

off_t nodestore:put(
	context & ctx,
	rchandle<text_node> tnode_h)
{
	nodeid parentid = tnode_h->get_parentid();
	char const* content = tnode_h->get_content();
	uint32_t content_length = tnode_h->get_content_length();
	off_t offset = put(ctx, parentid, content, content_length);
	index.put(tnode_h->get_nodeid(), offset);
	return offset;
}

int nodestore::get(
	context & ctx,
	nodeid id,     
	rchandle<text_node>& tnode_h)
{
	off_t offset;
	if (!index.get(id, offset)) return ERR_NODEID_NOT_FOUND;
	nodeid parentid;
	char * content;
	uint32_t content_length;
	int k = get(ctx, offset, parentid, content, content_length);
	if (k<0) return k;
	tnode_h = new text_node(id, parentid, string(content,0,content_length));
	return k;
}



off_t nodestore::put(
	context & ctx,
	nodeid const& parent,
	char const* content,
	uint32_t len)
{
	uint32_t res = store.size();
	store.push_back((unsigned char)STRING_CODE);
	put(ctx,(uint64_t)parent.id);
	put(ctx,(uint32_t)lenn);
	store.raw_copy(content, len);
	return res;
}

int nodestore::get(
	context & ctx,
	off_t offset0,
	nodeid & parent,
	char *& data,
	uint32_t & len)
{
	int k;
	uint64_t p;
	off_t offset = offset0;
	if (store[offset++]!=STRING_CODE) return ERR_BAD_CODE;
	if ((k = get(ctx, offset, p)) < 0) return k; else offset += k;
	if ((k = get(ctx, offset, len)) < 0) return k; else offset += k;
	data = store.front() + offset;
	offset += len;
	parent.id = p;
	return (offset-offset0);
}

off_t nodestore::put(
	context & ctx,
	nodeid const& parent,
	string const& content)
{
	return put(ctx, parent, content.c_str(), content.length());
}


/*...........................................
	: qname                                   :
	:.........................................:
*/

off_t nodestore::put(
	context & ctx,
	rchandle<QName> name_h)
{
	int k;
	off_t res = store.size();
	store.push_back((unsigned char)QNAME_CODE);
	store.push_back((unsigned char)name_h->get_type());
	put(ctx, name_h->get_namespace_hash());
	if ((k = put(ctx, name_h->get_name())) < 0) return k;
	if ((k = put(ctx, name_h->get_prefix())) < 0) return k;
	return res;
}

int nodestore::get(
	context & ctx,
	off_t offset0,
	rchandle<QName> & name_h)
{
	int k;
	uint64_t key;
	nodeid parent;

	off_t offset = offset0;
	if (store[offset++]!=QNAME_CODE) return ERR_BAD_CODE;

	QName::qname_type_t type = (QName::qname_type_t)store[offset++];
	if ((k = get(ctx, offset, key)) < 0) return k; else offset += k;

	char * name;
	uint32_t name_len;
	if ((k = get(ctx, offset, name, name_len)) < 0)
		return k;
	else
		offset += k;

	char * prefix;
	uint32_t prefix_len;
	if ((k = get(ctx, offset, prefix, prefix_len)) < 0)
		return k;
	else
		offset += k;

	name_h = new QName(type, string(prefix,0,prefix_len), string(name,0,name_len), key);
	return (offset-offset0);
}


/*
off_t nodestore::put(
	context & ctx,
	doc_node const* dnode)
{
	off_t res = offset;
	store[offset++] = DOC_CODE;
	store[offset++] = URI_CODE;
	put(ctx, dnode->get_baseuri();
	store[offset++] = URI_CODE;
	put(ctx, dnode->get_docuri();
	put(ctx, *dnode->children(ctx);
	return res;
}

off_t nodestore::put(
	context & ctx,
	element_node const* enode)
{
	off_t res = offset;
	store[offset++] = ELEM_CODE;
	put(ctx, enode->get_name());
	put(ctx, enode->ns_count());
	put(ctx, *enode->namespace_nodes(ctx));
	put(ctx, enode->attr_count());
	put(ctx, *enode->attributes(ctx));
	put(ctx, enode->elem_count());
	put(ctx, *enode->children(ctx));
	return res;
}


off_t nodestore::put(
	uint16_t code)
{
	store[offset++] = code;
	return offset; 
}


off_t nodestore::put(
	context & ctx,
	attribute_node const* anode)
{
	off_t res = put(ATTR_CODE)
	put(anode->get_name());
	put(anode->get_val());
	return res;
}

off_t nodestore::put(
	context & ctx,
	ns_node const* nsnode)
{
	off_t res = put(ctx, *nsnode->node_name(ctx));
	put_prefix(ctx, nsnode->get_prefix());
	put_uri(ctx, nsnode->get_uri());
	return res;
}

off_t nodestore::put(
	context & ctx,
	pi_node const* pnode)
{
	off_t res = put(ctx, *pnode->node_name(ctx));
	put_content(ctx, pnode->get_target());
	put_content(ctx, pnode->get_content());
	return res;
}

off_t nodestore::put(
	context & ctx,
	text_node const* tnode)
{
	return put_content(ctx, tnode->string_value(ctx));
}

off_t nodestore::put(
	context & ctx,
	binary_node const* bnode)
{
	return 0;
}

*/

  
} /* namespace xqp */

