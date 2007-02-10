/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: nodestore.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_NODESTORE_H
#define XQP_NODESTORE_H

#include "store_common.h"
#include "../util/fxvector.h"
#include "../util/fxhashmap.h"
#include "../util/rchandle.h"
#include "../values/qname_value.h"
#include "../values/node_values.h"
#include "namespace_pool.h"
#include "qname_pool.h"

#include <string>

namespace xqp {

class context;
class item_iterator;
class node;
class nodeid;



class nodestore : public rcobject
{
protected:
	fxvector<char>* store_p;					// binary data store
	fxhash64map<off_t>* index_p;			// map: nodeid -> off_t
	rchandle<namespace_pool> nspool_h;
	rchandle<qname_pool> qnpool_h;

public:
	nodestore(std::string const& path);
	~nodestore();

public:	
	rchandle<namespace_pool> get_namespace_pool() const
		{ return nspool_h; }
	rchandle<qname_pool> get_qname_pool() const
		{ return qnpool_h; }
	uint32_t get_eos() const
		{ return store_p->size(); }

	std::string decode_nodekind(uint32_t code);
	std::string decode_error(int code);

	bool index_put(off_t id, off_t res)
		{ return index_p->put(id, res); }
	uint32_t get_offset() const
		{ return store_p->size(); }

public:

	/*...........................................
		: integers                                :
		:.........................................:
	*/
	void put( context *, uint32_t ); 
	int get( context *, off_t, uint32_t & );
	
	void put( context *, uint64_t );
	int get( context *, off_t, uint64_t & );
	

	/*...........................................
		: strings                                 :
		:.........................................:
	*/
	off_t put( context *, char const* content, uint32_t len );
	int get( context *, off_t, char *& data, uint32_t& len );

	off_t put( context *, string const& content ); 
	int get( context *, off_t, string & content ); 


	/*...........................................
		: text nodes                              :
		:.........................................:
	*/
	off_t put( context *, rchandle<text_node> );
	int get( context *, nodeid, rchandle<text_node>& );
	int get( context *, off_t, rchandle<text_node>& );


	/*...........................................
		: qname                                   :
		:.........................................:
	*/
	off_t put( context *, rchandle<QName> );
	int get( context *, off_t, rchandle<QName> & );


	/*...........................................
		: attribute nodes                         :
		:.........................................:
	*/
	off_t put( context *, rchandle<attribute_node> );
	int get( context *, nodeid, rchandle<attribute_node> & );
	int get( context *, off_t, rchandle<attribute_node> & );


	/*...........................................
		: element nodes                           :
		:.........................................:
	*/
	off_t put( context *, rchandle<element_node> );
	int get( context *, nodeid, rchandle<element_node> & );
	int get( context *, off_t, rchandle<element_node> & );


	/*...........................................
		: document nodes                          :
		:.........................................:
	*/
	off_t put( context *, rchandle<document_node> );
	int get( context *, nodeid, rchandle<document_node> & );
	int get( context *, off_t, rchandle<document_node> & );


	/*...........................................
		: general nodes                           :
		:.........................................:
	*/
	int get( context *, nodeid, rchandle<node> & );
	int get( context *, off_t, rchandle<node> & );


};

} /* namespace xqp */
#endif /* XQP_NODE_STORE_H */

